#pragma once

#ifndef _MONITOR_H_
#define _MONITOR_H_

#include "RefCount.h"
#include "RefPtr.h"

class CMonitorNotify : public CRefCounter
{
public:
    virtual void    Notify() = 0;
};

typedef TRefPtr<CMonitorNotify> CMonitorNotifyPtr;

class CMonitorFile : public CRefCounter
{
public:
                            CMonitorFile( const tstring&, const CMonitorNotifyPtr& );
            bool            CheckNotify();
            const tstring&  FileName() const;

private:
    virtual                 ~CMonitorFile();
            bool            GetFileTime( FILETIME& );


    FILETIME            m_ft;
    const tstring       m_strFile;
    CMonitorNotifyPtr   m_pNotify;
};

typedef TRefPtr<CMonitorFile> CMonitorFilePtr;

class CMonitorDir : public CRefCounter
{
public:
                            CMonitorDir( const tstring& );
            void            AddFile( const tstring&, const CMonitorNotifyPtr& );
            void            RemoveFile( const tstring& );
            void            Notify();
            UINT            NumFiles() const;
            HANDLE          NotificationHandle() const;
            const tstring&  Dir() const;
private:
    virtual                 ~CMonitorDir();

    const tstring           m_strDir;
    vector<CMonitorFilePtr> m_files;
    HANDLE                  m_hNotification;

};

typedef TRefPtr<CMonitorDir> CMonitorDirPtr;

class CMonitor
{
public:
                        CMonitor();
                        ~CMonitor();
            void        MonitorFile( LPCTSTR, const CMonitorNotifyPtr& );
            void        StopMonitoringFile( LPCTSTR );
            void        StopAllMonitoring();

private:
    static  DWORD       ThreadFunc( CMonitor* );
            bool        StartUp();
            DWORD       DoMonitoring();
            HANDLE*     CreateHandleArray();

    vector<CMonitorDirPtr>  m_dirs;
    vector<CMonitorDirPtr>  m_newDirs;
    CComAutoCriticalSection m_cs;
    HANDLE                  m_hevtBreak;
    HANDLE                  m_hThread;
    volatile bool           m_bQuit;
    volatile bool           m_bRunning;
};

#endif // ! _MONITOR_H_