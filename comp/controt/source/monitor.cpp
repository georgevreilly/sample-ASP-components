#include "stdafx.h"
#include "Monitor.h"
#include "Lock.h"

static tstring FileToDir( const tstring& );

struct DirCompare
{
    DirCompare( const tstring& strDir )
        :   m_strDir( strDir ) {}
    bool operator()( const CMonitorDirPtr& pDir )
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
        ATLTRACE( _T("File %s has changed...notifying\n"), m_strFile.c_str() );
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
    ::FindCloseChangeNotification( m_hNotification );
}

void
CMonitorDir::AddFile(
    const tstring&              strFile,
    const CMonitorNotifyPtr&    pNotify )
{
    ATLTRACE( _T("Monitoring file %s\n"), strFile.c_str() );
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
        ATLTRACE( _T("Stopped monitoring file %s\n"), strFile.c_str() );
        m_files.erase( iter );
    }
    else
    {
        ATLTRACE( _T("Not monitoring file %s\n"), strFile.c_str() );
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

UINT
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
        ATLTRACE( _T("Request to monitor new directory: %s\n"), strDir.c_str() );
        pDir = new CMonitorDir( strDir );
        m_newDirs.push_back( pDir );
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
    CLock l(m_cs);
    tstring strFile( szFile );
    tstring strDir = FileToDir( strFile );

    vector<CMonitorDirPtr>::iterator iter = find_if(
        m_dirs.begin(),
        m_dirs.end(),
        DirCompare( strDir ) );
    if ( iter != m_dirs.end() )
    {
        if ( (*iter).IsValid() )
        {
            (*iter)->RemoveFile( strFile );
            ::SetEvent( m_hevtBreak );
        }
    }
    else
    {
        ATLTRACE( _T("Not monitorying file %s\n"), szFile );
    }
}

void
CMonitor::StopAllMonitoring()
{
    m_cs.Lock();
    if ( m_bRunning )
    {
        m_bQuit = true;
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
    m_bQuit = false;
    m_hevtBreak = ::CreateEvent(
        NULL,
        FALSE,  // auto event
        FALSE,
        _T("") );

    if ( m_hevtBreak != NULL )
    {
        DWORD dwThreadID;

        m_hThread = ::CreateThread(
            NULL,
            8192,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(ThreadFunc),
            this,
            0,
            &dwThreadID );
        if ( m_hThread != NULL )
        {
            m_bRunning = true;
            ATLTRACE( _T("Started monitor thread\n") );
            rc = true;
        }
    }
    return rc;
}

DWORD
CMonitor::DoMonitoring()
{
    HANDLE* phEvt = NULL;
    
    while ( 1 )
    {
        if ( phEvt == NULL )
        {
            CLock l(m_cs);
            // add any new directories to monitor
            if ( m_newDirs.size() > 0 )
            {
                m_dirs.insert( m_dirs.end(), m_newDirs.begin(), m_newDirs.end() );
                m_newDirs.clear();
            }
            // quit if there are no directories to monitor
            if ( m_dirs.size() == 0 )
            {
                m_bRunning = false;
                ATLTRACE( _T("No files to watch...stopping monitoring thread\n") );
                return 0;
            }
        
            // now create the array of event handles
            phEvt = new HANDLE[ m_dirs.size() + 1 ];
            phEvt[ 0 ] = m_hevtBreak;
            for ( UINT i = 0; i < m_dirs.size(); i++ )
            {
                phEvt[i+1] = m_dirs[i]->NotificationHandle();
            }
        }

        DWORD dw = ::WaitForMultipleObjects(
            m_dirs.size() + 1,
            phEvt,
            FALSE,
            INFINITE );
        if ( ( dw >= WAIT_OBJECT_0 ) && ( dw <= ( WAIT_OBJECT_0 - m_dirs.size() ) ) )
        {
            CLock l(m_cs);
            
            if ( m_bQuit )
            {
                m_dirs.clear();
                m_newDirs.clear();
            }

            if ( dw != WAIT_OBJECT_0 )
            {
                // a file has changed
                m_dirs[ dw - ( WAIT_OBJECT_0 + 1 ) ]->Notify();
            }

            bool regen = false;

            // remove any directories with no files
            UINT numDirs = m_dirs.size();
            for ( UINT i = 0; i < numDirs; )
            {
                if ( m_dirs[i]->NumFiles() == 0 )
                {
                    regen = true;
                    ATLTRACE( _T("No longer monitoring director: %s\n"), m_dirs[i]->Dir().c_str() );
                    m_dirs.erase( m_dirs.begin() + i );
                    numDirs--;
                }
                else
                {
                    i++;
                }
            }
            if ( ( m_newDirs.size() > 0 ) || ( regen == true ) || ( m_bQuit == true ) )
            {
                delete[] phEvt;
                phEvt = NULL;
            }
        }   // end if object signaled
    }   // end infinite while
}


DWORD
CMonitor::ThreadFunc(
    CMonitor* pMon )
{
    DWORD rc;
    if ( pMon )
    {
        rc = pMon->DoMonitoring();
    }
    return rc;
}
