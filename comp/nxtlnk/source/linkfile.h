// LinkFile.h: interface for the CLinkFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKFILE_H__253413CE_E71F_11D0_8A84_00C0F00910F9__INCLUDED_)
#define AFX_LINKFILE_H__253413CE_E71F_11D0_8A84_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RefCount.h"
#include "RefPtr.h"
#include "Link.h"
#include "Monitor.h"

class CLinkNotify : public CMonitorNotify
{
public:
                    CLinkNotify();
    virtual void    Notify();
            bool    IsNotified();
private:
    long            m_isNotified;
};

DECLARE_REFPTR( CLinkNotify,CMonitorNotify )

class CLinkFile : public CRefCounter, public CComAutoCriticalSection
{
public:
	CLinkFile( const tstring& strFile );

	int			LinkIndex( const tstring& strPage );
	CLinkPtr	Link( int nIndex );
	CLinkPtr	NextLink( const tstring& strPage );
	CLinkPtr	PreviousLink( const tstring& strPage );
	int			NumLinks(){ return m_links.size(); }
    bool        Refresh();

private:
    bool        LoadFile();
	virtual     ~CLinkFile();

	vector< CLinkPtr >		m_links;
    tstring                 m_strFile;
    CLinkNotifyPtr          m_pNotify;
};

typedef TRefPtr< CLinkFile > CLinkFilePtr;

#endif // !defined(AFX_LINKFILE_H__253413CE_E71F_11D0_8A84_00C0F00910F9__INCLUDED_)
