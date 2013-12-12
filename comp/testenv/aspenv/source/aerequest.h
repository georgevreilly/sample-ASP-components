	
// AeRequest.h : Declaration of the CAeRequest

#ifndef __AEREQUEST_H_
#define __AEREQUEST_H_

#include "resource.h"       // main symbols
#include "IniFile.h"
#include "StringProp.h"

/////////////////////////////////////////////////////////////////////////////
// CAeRequest
class ATL_NO_VTABLE CAeRequest : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAeRequest, &CLSID_AeRequest>,
	public ISupportErrorInfo,
	public IDispatchImpl<IRequest, &IID_IRequest, &LIBID_ASPENVLib>
{
public:
	CAeRequest();

DECLARE_REGISTRY_RESOURCEID(IDR_AEREQUEST)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CAeRequest)
	COM_INTERFACE_ENTRY(IRequest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

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

// IRequest
public:
    STDMETHOD(get_Item)(BSTR bstrVar, IDispatch** ppObjReturn);
    STDMETHOD(get_QueryString)(IRequestDictionary** ppDictReturn);
    STDMETHOD(get_Form)(IRequestDictionary** ppDictReturn);
    STDMETHOD(get_Body)(IRequestDictionary** ppDictReturn);
    STDMETHOD(get_ServerVariables)(IRequestDictionary** ppDictReturn);
    STDMETHOD(get_ClientCertificate)(IRequestDictionary** ppDictReturn);
    STDMETHOD(get_Cookies)(IRequestDictionary** ppDictReturn);

// CAeRequest
	static void InitializeClass();

private:
	_COM_SMARTPTR_TYPEDEF(IStringProp, IID_IStringProp);

	IDispatch*		GetItem( LPCTSTR );
	static CIniFile	s_iniFile;
};

#endif //__AEREQUEST_H_
