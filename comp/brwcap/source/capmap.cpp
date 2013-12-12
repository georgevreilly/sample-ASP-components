// CapMap.cpp: implementation of the CCapMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BrwCap.h"
#include "CapMap.h"

// compare names to templates, *, ?, [, ], not legal filename characters
static bool
match(
    LPCTSTR pattern,
    LPCTSTR name)
{
    LPTSTR rp;
    _TCHAR tc;

    if (*pattern == '*')
    {
        ++pattern;

        do
        {
            if (match(pattern, name) == true)
            {
                return true;
            }
        } while (*name++ != '\0');
    }
    else if (*name == '\0')
    {
        return *pattern == '\0';
    }
    else if (*pattern == '[' && (rp = _tcschr(pattern, ']')) != NULL)
    {
        while (*++pattern != ']')
        {
            if ((tc = *pattern) == *name
                    || (pattern[1] == '-'
                    && (*(pattern += 2) >= *name && tc <= *name)))
            {
                return match(rp + 1, ++name);
            }
        }

        return false;
    }
    else if (*pattern == '?')
    {
        return match(++pattern, ++name);
    }
    else if (tolower(*pattern) == tolower(*name))
    {
        return match(++pattern, ++name);
    }

    return false;
}

//---------------------------------------------------------------------
//  CCapNotify
//---------------------------------------------------------------------
CCapNotify::CCapNotify()
    :   m_isNotified(0)
{
}

void
CCapNotify::Notify()
{
    ::InterlockedExchange( &m_isNotified, 1 );
}

bool
CCapNotify::IsNotified()
{
    return ( ::InterlockedExchange( &m_isNotified, 0 ) ? true : false );
}


//---------------------------------------------------------------------
//  CCapMap
//---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCapMap::CCapMap()
{
	const tstring cszIniFile = _T("Browscap.ini");

	// get the path to the inifile containing the browser cap info
	_TCHAR szModule[ _MAX_PATH ];
	::GetModuleFileName(_Module.GetModuleInstance(), szModule, sizeof(szModule));

	// remove the filename and tack on the ini file name
	_TCHAR* pch = szModule + lstrlen(szModule) - 1;
	while (pch != szModule && *pch != _T('\\'))
	{
		pch = ::CharPrev(szModule, pch);
	}
	*(pch+1) = _T('\0');

	m_strIniFile = szModule + cszIniFile;
    ATLTRACE( _T("Using browser cap file: %s\n"), m_strIniFile.c_str() );

    // start monitoring the file
    m_pSink = new CCapNotify();
}

CCapMap::~CCapMap()
{
}

void
CCapMap::StartMonitor()
{
    if ( _Module.Monitor() )
    {
        _Module.Monitor()->MonitorFile( m_strIniFile.c_str(), m_pSink );
    }
    else
    {
        ATLTRACE( _T("Monitor not available\n") );
    }
}

void
CCapMap::StopMonitor()
{
    if ( _Module.Monitor() )
    {
        _Module.Monitor()->StopMonitoringFile( m_strIniFile.c_str() );
    }
}

_variant_t
CCapMap::LookUp(
	const tstring& szBrowser,
	const tstring& szName )
{
	static const tstring strHyphen = _T("-");

    Refresh();

    tstring strKey = szBrowser + strHyphen + szName;
    m_rw.EnterReader();
	CacheMapT::iterator iter = m_cache.find( strKey );
	if ( iter == m_cache.end() )
	{
        m_rw.ExitReader();
		// this value wasn't in the map before, look it up from the ini file
		_TCHAR szValue[ MaxValueSize ];

		if ( GetPrivateProfileString(
			szBrowser.c_str(),	// section
			szName.c_str(),		// key
			_T(""),				// default
			szValue,			// return buffer
			MaxValueSize,	// size of return buffer
			m_strIniFile.c_str() ) == 0 )
		{
			// didn't find it, now try all 
			vector< tstring >	browserList;
			GetMatchingProfiles( szBrowser, browserList );
			for ( int i = 0; i < browserList.size(); i++ )
			{
				if ( GetPrivateProfileString(
					browserList[i].c_str(),
					szName.c_str(),
					_T(""),
					szValue,
					MaxValueSize,
					m_strIniFile.c_str() ) > 0 )
				{
					// found it, set the value in the map
					i = browserList.size();
				}
			}
		}

        CacheMapT::value_type ins(strKey,StringToVariant(szValue));
        m_rw.EnterWriter();
        pair<CacheMapT::iterator, bool> insResult = m_cache.insert( ins );
        m_rw.ExitWriter();
        iter = insResult.first;
	}
    else
    {
        m_rw.ExitReader();
    }

	return (*iter).second;
}

//---------------------------------------------------------------------------
//
//  Refresh will check to see if the cached information is out of date with
//  the ini file.  If so, the cached will be purged
//
//---------------------------------------------------------------------------
bool
CCapMap::Refresh()
{
    bool rc = false;
    if ( m_pSink->IsNotified() )
    {
        m_rw.EnterWriter();
        m_cache.clear();
        m_rw.ExitWriter();
        rc = true;
    }
    return rc;
}


// GetMatchingProfiles will find all profiles that match the given profile
// or that are parents to the profile (including the default)
void
CCapMap::GetMatchingProfiles(
	const tstring&		strBrowser,
	vector<tstring>&	matchedProfiles ) const
{
	vector< tstring >	allProfiles;
	GetAllProfiles( allProfiles );

	GetMatchingProfiles( strBrowser, allProfiles, matchedProfiles );
}

void
CCapMap::GetMatchingProfiles(
	const tstring&			strBrowser,
	const vector<tstring>&	allProfiles,
	vector<tstring>&		matchedProfiles ) const
{
	vector<tstring> unmatchedProfiles;

	for ( int i = 0; i < allProfiles.size(); i++ )
	{
//        ATLTRACE( _T("Matching %s with %s..."), allProfiles[i].c_str(), strBrowser.c_str() );
        if ( match( allProfiles[i].c_str(), strBrowser.c_str() ) )
        {
//            ATLTRACE( _T("success.\n") );
            matchedProfiles.push_back( allProfiles[i] );
        }
        else
        {
//            ATLTRACE( _T("failure.\n") );
            unmatchedProfiles.push_back( allProfiles[i] );
        }
	}

	// get the parents of all matched profiles--parent profiles aren't wildcard-matched
	vector<tstring> parentProfiles;
	for ( i = 0; i < matchedProfiles.size(); i++ )
	{
		// if there is a parent for this profile, add it and repeat the process
		// for the parent
		_TCHAR szValue[ MaxValueSize ];
		szValue[0] = _T('x');
		tstring strTemp = matchedProfiles[i].c_str();

		while ( szValue[0] != _T('\0') )
		{
			if ( GetPrivateProfileString(
				strTemp.c_str(),			// section
				_T("parent"),		// key
				_T(""),				// default
				szValue,			// return buffer
				MaxValueSize,		// size of return buffer
				m_strIniFile.c_str() ) > 0 )
			{
				strTemp = szValue;
				vector<tstring>::iterator iter = find(
					unmatchedProfiles.begin(),
					unmatchedProfiles.end(),
					strTemp );
				if ( iter != unmatchedProfiles.end() )
				{
					unmatchedProfiles.erase( iter );
					parentProfiles.push_back( strTemp );
				}
				else
				{
					// we've already added this profile, which means we've already
					// added, or soon will add it's parents, so we won't do the
					// work twice
					szValue[0] = _T('\0');
				}
			}
		}
	}
	matchedProfiles.insert( matchedProfiles.end(), parentProfiles.begin(), parentProfiles.end() );

	matchedProfiles.push_back( _T("Default Browser Capability Settings") );
}

// Get all of the browser capability profile headings and return them in the
// given string
void
CCapMap::GetAllProfiles(
	vector<tstring>&	profiles ) const
{
	// first get all of the profiles sections into a buffer
	DWORD	dwSize = 1024;
	LPTSTR	szBuffer = new _TCHAR[dwSize];
	
	while ( GetPrivateProfileSectionNames(
		szBuffer, dwSize, m_strIniFile.c_str() ) == ( dwSize-2 ) )
	{
		// reallocate the buffer and try again
		delete[] szBuffer;
		dwSize = dwSize << 1;
		szBuffer = new _TCHAR[ dwSize ];
	}

	LPTSTR szSave = szBuffer;
	// now put all of these into a vector of tstrings
	while( *szBuffer != _T('\0') )
	{
		profiles.push_back( szBuffer );
		
		// advance to the beginning of the next string
		while ( *szBuffer != _T('\0') )
		{
			szBuffer = CharNext( szBuffer );
		}
		// now advance once more to get to the next string
		szBuffer++;
	}
	delete[] szSave;
}


_variant_t
CCapMap::StringToVariant(
	LPCTSTR	szValue ) const
{
	USES_CONVERSION;

	_variant_t retValue;

	if ( _tcscmp( szValue, _T("") ) == 0 )
	{
		retValue = L"unknown";
	}
	else if ( szValue[0] == _T('#') )
	{
		// its a number
		// TODO handle this properly
		retValue = _ttol(szValue+1);
	}
    else if ( _tcsncicmp( szValue, _T("TRUE"), 5 ) == 0 )
    {
        retValue = true;
    }
    else if ( _tcsncicmp( szValue, _T("FALSE"), 6 ) == 0 )
    {
        retValue = false;
    }
	else
	{
		retValue = T2CW(szValue);
	}

	return retValue;
}

