// CapMap.h: interface for the CCapMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAPMAP_H__2AE59261_E295_11D0_8A81_00C0F00910F9__INCLUDED_)
#define AFX_CAPMAP_H__2AE59261_E295_11D0_8A81_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Monitor.h"
#include "RdWrt.h"

class CCapNotify : public CMonitorNotify
{
public:
                    CCapNotify();
    virtual void    Notify();
            bool    IsNotified();
private:
    long            m_isNotified;
};

DECLARE_REFPTR( CCapNotify,CMonitorNotify )


// The capabilites map is a singleton object (only one instance will exsist).
// It provides each BrowserCap object with access to the stored capabilites
// while storing it in a central location (increasing the benifit of caching
// and decreasing memory requirements)

class CCapMap
{
public:
            	CCapMap();
	            ~CCapMap();

	_variant_t	LookUp( const tstring& szBrowser, const tstring& szName );
    void        StartMonitor();
    void        StopMonitor();

private:
	enum {
		MaxValueSize = 1024
	};

    bool    Refresh();
	void    GetMatchingProfiles( const tstring& strBrowser, vector< tstring >& matchedProfiles ) const;
	void    GetMatchingProfiles( const tstring& strBrowser, const vector< tstring >& allProfiles, vector< tstring >& matchProfiles ) const;
	void    GetAllProfiles( vector< tstring >& profiles ) const;
	_variant_t StringToVariant( LPCTSTR szValue ) const;

	typedef map<tstring, _variant_t>	CacheMapT;

	CacheMapT				m_cache;
    CReadWrite              m_rw;
	tstring					m_strIniFile;
    CCapNotifyPtr           m_pSink;
};

#endif // !defined(AFX_CAPMAP_H__2AE59261_E295_11D0_8A81_00C0F00910F9__INCLUDED_)
