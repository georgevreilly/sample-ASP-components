#include "stdafx.h"
#include "IniFile.h"

bool
CIniFile::Open(
	const String&	strFile )
{
	m_strFile = strFile;
	return true;
}

void
CIniFile::Close()
{
	m_strFile = "";
}

String
CIniFile::GetString(
	LPCTSTR	szSection,
	LPCTSTR	szKey,
	LPCTSTR	szDefault	/* = NULL */ )
{
	// first look it up in the map
	String strValue;
	if ( szSection && szKey )
	{
		String strKey = szSection;
		strKey += szKey;

		CReader rdr( m_rw );	// reading the cache
		CacheMapT::iterator iter = m_cache.find( strKey );
		if ( iter != m_cache.end() )
		{
			strValue = (*iter).second;
		}
		else
		{
			rdr.Exit();	// no longer reading the cache
			strValue = GetStringFromFile( szSection, szKey, szDefault );
			CWriter wtr( m_rw );	// writing to the cache
			m_cache.insert( pair<String,String>(strKey,strValue) );
		}
	}
	return strValue;
}

String
CIniFile::GetStringFromFile(
	LPCTSTR	szSection,
	LPCTSTR	szKey,
	LPCTSTR	szDefault )
{
	String strValue;
	if ( szDefault )
	{
		strValue = szDefault;
	}
	else
	{
		strValue = "";
	}

	if ( szSection && szKey )
	{
		bool done = false;
		DWORD bufSize = 256;
		do
		{
			LPTSTR szTemp = (LPTSTR)( _alloca( bufSize ) );
			DWORD dw = ::GetPrivateProfileString(
				szSection,
				szKey,
				strValue.c_str(),
				szTemp,
				bufSize,
				m_strFile.c_str() );
			if ( dw < ( bufSize - 2 ) )
			{
				// got the string
				strValue = szTemp;
				done = true;
			}
			else
			{
				// not enough room in the string
				bufSize = bufSize << 1;
			}
		} while ( !done );
	}
	return strValue;
}

