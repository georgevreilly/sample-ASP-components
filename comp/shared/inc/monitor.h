#pragma once

#ifndef _MONITOR_H_
#define _MONITOR_H_

#include "RefCount.h"
#include "RefPtr.h"

// a client supplies it's own derviation of CMonitorNotify to the monitor.
// the notify method is called when the monitored object has changed
class CMonitorNotify : public CRefCounter
{
public:
    virtual void    Notify() = 0;
};

typedef TRefPtr<CMonitorNotify> CMonitorNotifyPtr;

// the base object of anything that can be monitored
class CMonitorNode : public CRefCounter
{
public:
    virtual void    Notify() = 0;
    virtual HANDLE  NotificationHandle() const = 0;
};

typedef TRefPtr<CMonitorNode> CMonitorNodePtr;

// since we can only monitor directories, the file class,
// preserves information about each file in a particular
// directory
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

// an implementaiton of CMonitorNode's interface for montioring directories
class CMonitorDir : public CMonitorNode
{
public:
                            CMonitorDir( const tstring& );

        // CMonitorNode interface
    virtual void            Notify();
    virtual HANDLE          NotificationHandle() const;

            void            AddFile( const tstring&, const CMonitorNotifyPtr& );
            void            RemoveFile( const tstring& );
            const tstring&  Dir() const;
            ULONG           NumFiles() const;
private:
    virtual                 ~CMonitorDir();

    const tstring				m_strDir;
    vector<CMonitorFilePtr>	m_files;
    HANDLE						m_hNotification;

};

DECLARE_REFPTR(CMonitorDir,CMonitorNode);


// an implementation of CMonitorNode's interface for monitoring a registry key
class CMonitorRegKey : public CMonitorNode
{
public:
                            CMonitorRegKey( HKEY, const tstring&, const CMonitorNotifyPtr& );

        // CMonitorNode interface
    virtual void            Notify();
    virtual HANDLE          NotificationHandle() const;

        // CMonitorRegKey interface
    const tstring&          m_strKey;
    const HKEY              m_hBaseKey;

private:
    virtual                 ~CMonitorRegKey();

    HKEY                    m_hKey;
    HANDLE                  m_hEvt;
    CMonitorNotifyPtr       m_pNotify;
};

DECLARE_REFPTR(CMonitorRegKey, CMonitorNode);

// the main monitoring object
class CMonitor
{
public:
                        CMonitor();
                        ~CMonitor();
            void        MonitorFile( LPCTSTR, const CMonitorNotifyPtr& );
            void        StopMonitoringFile( LPCTSTR );
            void        MonitorRegKey( HKEY, LPCTSTR, const CMonitorNotifyPtr& );
            void        StopMonitoringRegKey( HKEY, LPCTSTR );
            void        StopAllMonitoring();

private:
    static  DWORD       ThreadFunc( CMonitor* );
            bool        StartUp();
            DWORD       DoMonitoring();

    vector<CMonitorDirPtr>		m_dirs;
    vector<CMonitorRegKeyPtr>	m_regKeys;

    CComAutoCriticalSection     m_cs;
    HANDLE                      m_hevtBreak;
    HANDLE                      m_hThread;
    volatile bool               m_bRunning;
};

#endif // ! _MONITOR_H_