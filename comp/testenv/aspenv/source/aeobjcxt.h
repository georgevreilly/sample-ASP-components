// AeObjectContext.h : Declaration of the CAeObjectContext

#ifndef __AEOBJECTCONTEXT_H_
#define __AEOBJECTCONTEXT_H_

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAeObjectContext
class ATL_NO_VTABLE CAeObjectContext : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAeObjectContext, &CLSID_AeObjectContext>,
	public ISupportErrorInfo,
	public IDispatchImpl<IAeObjectContext, &IID_IAeObjectContext, &LIBID_ASPENVLib>,
	public IObjectContext,
	public IGetContextProperties
{
public:
	CAeObjectContext();

DECLARE_REGISTRY_RESOURCEID(IDR_AEOBJECTCONTEXT)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CAeObjectContext)
	COM_INTERFACE_ENTRY(IAeObjectContext)
	COM_INTERFACE_ENTRY(IObjectContext)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	COM_INTERFACE_ENTRY(IGetContextProperties)
END_COM_MAP()

// Free-threaded marshaling
	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}
	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}
	CComPtr<IUnknown> m_pUnkMarshaler;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


public:
// IObjectContext - note, none of these are implemented
	STDMETHOD(CreateInstance)( 
		/* [in] */ REFCLSID,
		/* [in] */ REFIID,
		/* [retval][iid_is][out] */ LPVOID __RPC_FAR *);
	STDMETHOD(SetComplete)();
	STDMETHOD(SetAbort)();
	STDMETHOD(EnableCommit)();
	STDMETHOD(DisableCommit)();
	STDMETHOD_(BOOL, IsInTransaction)();
	STDMETHOD_(BOOL, IsSecurityEnabled)();
	STDMETHOD(IsCallerInRole)( 
		/* [in] */ BSTR,
		/* [retval][out] */ BOOL __RPC_FAR *);

// IGetContextProperties - note only GetProperty is implemented
	STDMETHOD(Count)( 
		/* [retval][out] */ long __RPC_FAR *);
	STDMETHOD(GetProperty)( 
		/* [in] */ BSTR name,
		/* [retval][out] */ VARIANT __RPC_FAR *);
	STDMETHOD(EnumNames)( 
		/* [retval][out] */ IEnumNames __RPC_FAR *__RPC_FAR *);

// CAeObjectContext
	static void InitializeClass();

private:
	_COM_SMARTPTR_TYPEDEF(IServer, IID_IServer);
	_COM_SMARTPTR_TYPEDEF(IResponse, IID_IResponse);
	_COM_SMARTPTR_TYPEDEF(IRequest, IID_IRequest);

	IServerPtr		m_pServer;
	IResponsePtr	m_pResponse;
	IRequestPtr		m_pRequest;
};

#endif //__AEOBJECTCONTEXT_H_
