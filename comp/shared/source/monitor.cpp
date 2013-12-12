#include "stdafx.h"
#include "Monitor.h"
#include "Lock.h"
#include "MyDebug.h"
#include <process.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static tstring FileToDir( const tstring& );

// function objects for comparisons
struct DirCompare
{
    DirCompare( const tstring& strDir )
        :   m_strDir( strDir ) {}
    bool operator()( CMonitorDirPtr& pDir )
    {
        return ( m_strDir == pDir->Dir() );
    }
    tstring m_strDir;
};

struct FileCompare
{
    FileCompare( const tstring& strFile )
        :   m_strFile( strFile ) {}
    bool operator()( const CMonitorFilePtr& pFile )
    {
        return ( m_strFile == pFile->FileName() );
    }
    tstring m_strFile;
};

struct RegKeyCompare
{
    RegKeyCompare( HKEY hKey, const tstring strSubKey )
        :   m_hKey(hKey), m_strSubKey( strSubKey ) {}
    bool operator()( const CMonitorRegKeyPtr& pRegKey )
    {
        bool rc = false;
        if ( m_hKey == pRegKey->m_hBaseKey )
        {
            rc = ( m_strSubKey == pRegKey->m_strKey );
        }
        return rc;
    }
    const HKEY      m_hKey;
    const tstring   m_strSubKey;
};


tstring
FileToDir(
    const tstring&  strFile )
{
    tstring strDir;
    tstring::size_type pos = strFile.find_last_of( _T('\\') );
    if ( pos != tstring::npos )
    {
    }
    else
    {
        pos = strFile.find_first_of( _T(':') );
        if ( pos != tstring::npos )
        {
            pos++;
        }
    }

    if ( pos != tstring::npos )
    {
        strDir = strFile.substr( 0, pos );
    }
    return strDir;                
}

//---------------------------------------------------------------------------
//  CMonitorFile
//---------------------------------------------------------------------------
CMonitorFile::CMonitorFile(
    const tstring&              strFile,
    const CMonitorNotifyPtr&    pNotify )
    :   m_strFile( strFile ),
        m_pNotify( pNotify )
{
    GetFileTime( m_ft );
}

CMonitorFile::~CMonitorFile()
{
}

const tstring&
CMonitorFile::FileName() const
{
    return m_strFile;
}

bool
CMonitorFile::GetFileTime(
    FILETIME&   ft )
{
    bool rc = false;

    HANDLE hFile = ::CreateFile(
        m_strFile.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL );
    if ( hFile != INVALID_HANDLE_VALUE )
    {
        BY_HANDLE_FILE_INFORMATION bhfi;
        if ( ::GetFileInformationByHandle( hFile, &bhfi ) )
        {
            ft = bhfi.ftLastWriteTime;
            rc = true;
        }
        ::CloseHandle( hFile );
    }
    return rc;
}

bool
CMonitorFile::CheckNotify()
{
    bool rc = false;

    FILETIME ft;
    GetFileTime( ft );
    if ( ::CompareFileTime( &ft, &m_ft ) > 0 )
    {
//        ATLTRACE( _T("File %s has changed...notifying\n"), m_strFile.c_str() );
        if ( m_pNotify.IsValid() )
        {
            m_pNotify->Notify();
        }
        rc = true;
    }
    m_ft = ft;
    return rc;
}


//---------------------------------------------------------------------------
//  CMonitorDir
//---------------------------------------------------------------------------
CMonitorDir::CMonitorDir(
    const tstring&  strDir )
    :   m_strDir( strDir )
{
    m_hNotification = ::FindFirstChangeNotification(
        m_strDir.c_str(),
        FALSE,
        FILE_NOTIFY_CHANGE_LAST_WRITE );
}

CMonitorDir::~CMonitorDir()
{
	m_files.clear();
    ::FindCloseChangeNotification( m_hNotification );
}

void
CMonitorDir::AddFile(
    const tstring&              strFile,
    const CMonitorNotifyPtr&    pNotify )
{
//    ATLTRACE( _T("Monitoring file %s\n"), strFile.c_str() );
    m_files.push_back( new CMonitorFile( strFile, pNotify ) );
}

void
CMonitorDir::RemoveFile(
    const tstring&   strFile )
{
    vector<CMonitorFilePtr>::iterator iter = find_if(
        m_files.begin(),
        m_files.end(),
        FileCompare( strFile ) );
    if ( iter != m_files.end() )
    {
//        ATLTRACE( _T("Stopped monitoring file %s\n"), strFile.c_str() );
        m_files.erase( iter );
    }
    else
    {
//        ATLTRACE( _T("Not monitoring file %s\n"), strFile.c_str() );
    }
}
    
void
CMonitorDir::Notify()
{
    for ( UINT i = 0; i < m_files.size(); i++ )
    {
        m_files[i]->CheckNotify();
    }
    ::FindNextChangeNotification( m_hNotification );
}

ULONG
CMonitorDir::NumFiles() const
{
    return m_files.size();
}

HANDLE
CMonitorDir::NotificationHandle() const
{
    return m_hNotification;
}

const tstring&
CMonitorDir::Dir() const
{
    return m_strDir;
}

//---------------------------------------------------------------------------
//  CMonitorRegKey
//---------------------------------------------------------------------------
CMonitorRegKey::CMonitorRegKey(
    HKEY                        hBaseKey,
    const tstring&              strKey,
    const CMonitorNotifyPtr&    pNotify )
    :   m_hEvt(NULL),
        m_hKey(NULL),
        m_pNotify( pNotify ),
        m_strKey( strKey ),
        m_hBaseKey( hBaseKey )
{
    LONG l = ::RegOpenKeyEx(
        hBaseKey,
        strKey.c_str(),
        0,
        KEY_NOTIFY,
        &m_hKey );
    if ( l == ERROR_SUCCESS )
    {
        m_hEvt = ::CreateEvent(
            NULL,
            TRUE,
            FALSE,
            NULL );
        if ( m_hEvt != NULL )
        {
            // ask for notification when the key changes
            l = ::RegNotifyChangeKeyValue(
                m_hKey,
                FALSE,
                REG_NOTIFY_CHANGE_LAST_SET,
                m_hEvt,
                TRUE );
            if ( l == ERROR_SUCCESS )
            {
                // okay
            }
            else
            {
                ATLTRACE( _T("Couldn't get reg key notification\n") );
            }
        }
        else
        {
            ATLTRACE( _T("Couldn't create event\n") );
        }
    }
    else
    {
        ATLTRACE( _T("Couldn't open subkey: %s\n"), strKey.c_str() );
    }
}

CMonitorRegKey::~CMonitorRegKey()
{
    ::RegCloseKey( m_hKey );
    ::CloseHandle( m_hEvt );
}

void
CMonitorRegKey::Notify()
{
    if ( m_pNotify.IsValid() )
    {
        m_pNotify->Notify();
    }
    ::ResetEvent( m_hEvt );
    ::RegNotifyChangeKeyValue(
        m_hKey,
        FALSE,
        REG_NOTIFY_CHANGE_LAST_SET,
        m_hEvt,
        TRUE );
}

HANDLE
CMonitorRegKey::NotificationHandle() const
{
    return m_hEvt;
}

//---------------------------------------------------------------------------
//  CMonitor
//---------------------------------------------------------------------------

CMonitor::CMonitor()
    :   m_hevtBreak( INVALID_HANDLE_VALUE ),
        m_hThread( INVALID_HANDLE_VALUE ),
        m_bRunning( false )
{
}

CMonitor::~CMonitor()
{
    StopAllMonitoring();
    if ( m_hevtBreak != INVALID_HANDLE_VALUE )
    {
        ::CloseHandle( m_hevtBreak );
    }
}

void
CMonitor::MonitorFile(
    LPCTSTR                     szFile,
    const CMonitorNotifyPtr&    pMonNotify )
{
    CLock l(m_cs);

    tstring strFile( szFile );
    tstring strDir = FileToDir( strFile );
    
    CMonitorDirPtr pDir;
    vector<CMonitorDirPtr>::iterator iter = find_if(
        m_dirs.begin(),
        m_dirs.end(),
        DirCompare( strDir ) );
    if ( iter == m_dirs.end() )
    {
//        ATLTRACE( _T("Request to monitor new directory: %s\n"), strDir.c_str() );
        pDir = new CMonitorDir( strDir );
        m_dirs.push_back( pDir );
    }
    else
    {
        pDir = (*iter);
    }

    if ( pDir.IsValid() )
    {
        pDir->AddFile( strFile, pMonNotify );
        if ( !m_bRunning )
        {
            StartUp();
        }
        else
        {
            ::SetEvent( m_hevtBreak );
        }
    }
}

void
CMonitor::StopMonitoringFile(
    LPCTSTR szFile )
{
    tstring strFile( szFile );
    tstring strDir = FileToDir( strFile );

    CLock l(m_cs);

    vector<CMonitorDirPtr>::iterator iter = find_if(
        m_dirs.begin(),
        m_dirs.end(),
        DirCompare( strDir ) );
    if ( iter != m_dirs.end() )
    {
        if ( (*iter).IsValid() )
        {
            (*iter)->RemoveFile( strFile );
            if ( (*iter)->NumFiles() == 0 )
            {
                // no more files to monitor in this directory, remove it
                m_dirs.erase(iter);
                ::SetEvent( m_hevtBreak );
            }
        }
    }
    else
    {
//        ATLTRACE( _T("Not monitorying file %s\n"), szFile );
    }
}

void
CMonitor::MonitorRegKey(
    HKEY                        hBaseKey,
    LPCTSTR                     szSubKey,
    const CMonitorNotifyPtr&    pNotify )
{
    tstring strSubKey = szSubKey;

//    ATLTRACE( _T( "Request to monitor new key: %s\n"), szSubKey );

    CLock l(m_cs);

    if ( find_if(
            m_regKeys.begin(),
            m_regKeys.end(),
            RegKeyCompare( hBaseKey, szSubKey ) )
        == m_regKeys.end() )
    {
        // not already begin monitored, add a new one
        CMonitorRegKeyPtr pRegKey = new CMonitorRegKey( hBaseKey, szSubKey, pNotify );
        m_regKeys.push_back(pRegKey);

        // either start the monitoring thread or, inform it of a new key to monitor
        if ( !m_bRunning )
        {
            StartUp();
        }
        else
        {
            ::SetEvent( m_hevtBreak );
        }
    }
}

void
CMonitor::StopMonitoringRegKey(
    HKEY    hBaseKey,
    LPCTSTR szSubKey )
{
    tstring strSubKey = szSubKey;

    CLock l(m_cs);

    vector<CMonitorRegKeyPtr>::iterator iter = find_if(
        m_regKeys.begin(),
        m_regKeys.end(),
        RegKeyCompare( hBaseKey, szSubKey ) );
    if ( iter != m_regKeys.end() )
    {
//        ATLTRACE( _T( "Stopping monitoring of key: %s\n"), szSubKey );
        m_regKeys.erase( iter );
        ::SetEvent( m_hevtBreak );
    }
    else
    {
//        ATLTRACE( _T("Not monitoring key: %s\n"), szSubKey );
    }
}

void
CMonitor::StopAllMonitoring()
{
    m_cs.Lock();
    if ( m_bRunning )
    {
// clear all types of nodes here
        m_regKeys.clear();
        m_dirs.clear();
        ::SetEvent( m_hevtBreak );
        m_cs.Unlock();
        ::WaitForSingleObject( m_hThread, INFINITE );
    }
    else
    {
        m_cs.Unlock();
    }
}


bool
CMonitor::StartUp()
{
    bool rc = false;

    if ( m_hevtBreak == INVALID_HANDLE_VALUE )
    {
        m_hevtBreak = ::CreateEvent(
            NULL,
            FALSE,  // auto event
            FALSE,
            NULL );
    }

    if ( m_hevtBreak != NULL )
    {
        unsigned int iThreadID;

        m_hThread = (HANDLE)_beginthreadex(
            NULL,
            8192,
            reinterpret_cast<unsigned int (__stdcall*)(void*)>(ThreadFunc),
            this,
            0,
            &iThreadID );
        if ( m_hThread != NULL )
        {
            m_bRunning = true;
//            ATLTRACE( _T("Started monitor thread\n") );
            rc = true;
        }
    }
    return rc;
}

DWORD
CMonitor::DoMonitoring()
{
    HANDLE* phEvt = NULL;
    vector<CMonitorNodePtr> nodes;

    while ( 1 )
    {
        if ( phEvt == NULL )
        {
            CLock l(m_cs);
            
            // build the complete list of monitored nodes
            nodes.clear();
            nodes.insert( nodes.end(), m_dirs.begin(), m_dirs.end() );
            nodes.insert( nodes.end(), m_regKeys.begin(), m_regKeys.end() );
// insert other types of nodes to monitor here

            // quit if there are no nodes to monitor
            if ( nodes.size() == 0 )
            {
                m_bRunning = false;
//                ATLTRACE( _T("Nothing to watch...stopping monitoring thread\n") );
                return 0;
            }
            
            // now create the array of event handles
            phEvt = new HANDLE[ nodes.size() + 1 ];
            phEvt[ 0 ] = m_hevtBreak;
            for ( UINT i = 0; i < nodes.size(); i++ )
            {
                phEvt[i+1] = nodes[i]->NotificationHandle();
            }
        }

        DWORD dw = ::WaitForMultipleObjects(
            nodes.size() + 1,
            phEvt,
            FALSE,
            INFINITE );
        if ( ( dw >= WAIT_OBJECT_0 ) && ( dw <= ( nodes.size() - WAIT_OBJECT_0 ) ) )
        {
            CLock l(m_cs);
            
            if ( dw != WAIT_OBJECT_0 )
            {
                // a monitored item has changed
                nodes[ dw - ( WAIT_OBJECT_0 + 1 ) ]->Notify();
            }
            else
            {
                // there was a manual break, and a node was probably added or
                // removed, the vector of nodes needs to be regenerated
                nodes.clear();
                delete[] phEvt;
                phEvt = NULL;
            }

        }
        else if ( dw == WAIT_FAILED )
        {
            // something's wrong, we'll just clean up and exit
            DWORD err = ::GetLastError();
            ATLTRACE( _T("CMonitor: WaitForMultipleObjects error: 0x%x\n"), err );
            ATLTRACE( _T( "CMonitor: abandoning wait thread\n") );
            nodes.clear();
            delete[] phEvt;
            CLock l(m_cs);
            m_bRunning = false;
            m_dirs.clear();
            m_regKeys.clear();
            phEvt = NULL;
        }
    }   // end infinite while
}


DWORD
CMonitor::ThreadFunc(
    CMonitor* pMon )
{
    DWORD rc = -1;
	try
	{
		if ( pMon )
		{
			rc = pMon->DoMonitoring();
		}
	}
	catch( ... )
	{
	}

	_endthreadex(rc);
    return rc;
}
