// LinkFile.cpp: implementation of the CLinkFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NxtLnk.h"
#include "LinkFile.h"

extern CMonitor* g_pMonitor;

//--------------------------------------------------------------------
//  CLinkNotify
//--------------------------------------------------------------------
CLinkNotify::CLinkNotify()
    :   m_isNotified(0)
{
}

void
CLinkNotify::Notify()
{
    ::InterlockedExchange( &m_isNotified, 1 );
}

bool
CLinkNotify::IsNotified()
{
    return ( ::InterlockedExchange( &m_isNotified, 0 ) ? true : false );
}

//---------------------------------------------------------------------
//  CLinkFile
//---------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLinkFile::CLinkFile(
	const tstring&	strFile )
{
    m_pNotify = new CLinkNotify;

    m_strFile = strFile;
    g_pMonitor->MonitorFile( m_strFile.c_str(), m_pNotify );
    LoadFile();
}

CLinkFile::~CLinkFile()
{
    if ( g_pMonitor )
    {
        g_pMonitor->StopMonitoringFile( m_strFile.c_str() );
    }
}

int
CLinkFile::LinkIndex(
	const tstring&	strPage )
{
	int rc = 0;
	for ( int i = 0; i < m_links.size(); i++ )
	{
		if ( m_links[i]->IsEqual( strPage ) )
		{
			rc = i+1;
			i = m_links.size();
		}
	}
	return rc;
}

CLinkPtr
CLinkFile::Link(
	int	nIndex )
{
	CLinkPtr pLink = NULL;

	if ( nIndex > m_links.size() )
	{
		pLink = m_links.back();
	}
	else if ( nIndex < 1 )
	{
		pLink = m_links[0];
	}
	else
	{
		pLink = m_links[nIndex-1];
	}
	return pLink;
}

CLinkPtr
CLinkFile::NextLink(
	const tstring&	strPage )
{
	CLinkPtr pLink;
	int nIndex = LinkIndex( strPage );
	if ( nIndex > 0 )
	{
		pLink = Link( nIndex + 1 );
	}
	else
	{
		pLink = m_links.back();
	}

	return pLink;
}

CLinkPtr
CLinkFile::PreviousLink(
	const tstring&	strPage )
{
	CLinkPtr pLink;
	int nIndex = LinkIndex( strPage );
	pLink = Link( nIndex - 1 );

	return pLink;
}

//---------------------------------------------------------------------------
//
//  Refresh will check to see if the cached information is out of date with
//  the ini file.  If so, the cached will be purged
//
//---------------------------------------------------------------------------
bool
CLinkFile::Refresh()
{
    bool rc = false;
    if ( m_pNotify->IsNotified() )
    {
        LoadFile();
        rc = true;
    }
    return rc;
}

bool
CLinkFile::LoadFile()
{
	USES_CONVERSION;

    bool rc = false;

    m_links.clear();

	// parse the file for the links
	tfstream fs( T2CA( m_strFile.c_str() ) );
	if ( fs.is_open() )
	{
		while ( !fs.eof() )
		{
			tstring strLine;
			getline( fs, strLine );
			if ( strLine != _T("") )
			{
				tstringstream ss( strLine );
				tstring strURL = _T(""), strDesc = _T("");
				ss >> strURL;
				while ( !ss.eof() )
				{
					tstring strTemp;
					ss >> strTemp;
					strDesc += strTemp + _T(' ');
				}
				CLinkPtr pLink = new CLink( strURL, strDesc );
				m_links.push_back( pLink );
			}
		}
        rc = true;
	}
    return rc;
}
