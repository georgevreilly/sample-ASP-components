// NextLink.h : Declaration of the CNextLink

#ifndef __NEXTLINK_H_
#define __NEXTLINK_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "LinkFile.h"
#include "lock.h"

/////////////////////////////////////////////////////////////////////////////
// CNextLink
class ATL_NO_VTABLE CNextLink : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNextLink, &CLSID_NextLink>,
	public ISupportErrorInfo,
	public IDispatchImpl<INextLink, &IID_INextLink, &LIBID_NXTLNKLib>
{
public:
	CNextLink()
	{ 
	}

public:

DECLARE_REGISTRY_RESOURCEID(IDR_NEXTLINK)

BEGIN_COM_MAP(CNextLink)
	COM_INTERFACE_ENTRY(INextLink)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INextLink
public:
	STDMETHOD(get_About)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetListIndex)(BSTR bstrLinkFile, /*[out, retval]*/ int *pVal);
	STDMETHOD(get_GetListCount)(BSTR bstrLinkFile, /*[out, retval]*/ int *pVal);
	STDMETHOD(get_GetNthDescription)(BSTR bstrLinkFile, int nIndex, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetNthURL)(BSTR bstrLinkFile, int nIndex, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetPreviousDescription)(BSTR bstrLinkFile, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetPreviousURL)(BSTR bstrLinkFile, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetNextDescription)(BSTR bstrLinkFile, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_GetNextURL)(BSTR, /*[out, retval]*/ BSTR *pVal);

private:
    CLinkFilePtr            LinkFile( BSTR );
	CLinkFilePtr            LinkFile( BSTR, CComPtr<IServer>& );
    IGetContextProperties*  GetContextProperties();
    IRequest*               GetRequest( CComPtr<IGetContextProperties>& );
    IServer*                GetServer( CComPtr<IGetContextProperties>& );
    bool                    GetPage( CComPtr<IRequest>&, tstring& );
    bool                    GetFileAndPage( BSTR, CLinkFilePtr&, tstring& );

	typedef TSafeMap<tstring,CLinkFilePtr>	LinkFileMapT;

	static LinkFileMapT		s_linkFileMap;

};

#endif //__NEXTLINK_H_
