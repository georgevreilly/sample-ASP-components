// BrowCap.h : Declaration of the CBrowserCap

#ifndef __BROWSERCAP_H_
#define __BROWSERCAP_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "Lock.h"

/////////////////////////////////////////////////////////////////////////////
// CBrowserCap
class ATL_NO_VTABLE CBrowserCap : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CBrowserCap, &CLSID_BrowserCap>,
	public ISupportErrorInfo,
	public IDispatchImpl<IBrowserCap, &IID_IBrowserCap, &LIBID_BRWCAPLib>
{
public:
	CBrowserCap();
    ~CBrowserCap();

public:

DECLARE_REGISTRY_RESOURCEID(IDR_BROWSERCAP)

BEGIN_COM_MAP(CBrowserCap)
	COM_INTERFACE_ENTRY(IBrowserCap)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
// IDispatch Methods
    STDMETHOD(Invoke)(DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*);
    STDMETHOD(GetIDsOfNames)( REFIID, LPOLESTR*, UINT, LCID, DISPID* );

// IBrowserCap
    //Active Server Pages Methods
	STDMETHOD(get_Value)(BSTR, /*[out, retval]*/ VARIANT *pVal);

private:
    IRequest*               GetRequest();
    DISPID                  DispatchID( LPOLESTR );

    TSafeVector<tstring>    m_dispList;
};

#endif //__BROWSERCAP_H_
