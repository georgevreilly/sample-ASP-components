	
// AeServer.h : Declaration of the CAeServer

#ifndef __AESERVER_H_
#define __AESERVER_H_

#include "resource.h"       // main symbols
#include "IniFile.h"

/////////////////////////////////////////////////////////////////////////////
// CAeServer
class ATL_NO_VTABLE CAeServer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAeServer, &CLSID_AeServer>,
	public ISupportErrorInfo,
	public IDispatchImpl<IServer, &IID_IServer, &LIBID_ASPENVLib>
{
public:
DECLARE_REGISTRY_RESOURCEID(IDR_AESERVER)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CAeServer)
//	COM_INTERFACE_ENTRY2(IDispatch, IAeServer)
	COM_INTERFACE_ENTRY(IServer)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

// free threaded marshaling
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
// IServer
    STDMETHOD(get_ScriptTimeout)(long FAR* plTimeoutSeconds);
    STDMETHOD(put_ScriptTimeout)(long lTimeoutSeconds);
    STDMETHOD(CreateObject)(BSTR bstrProgID, IDispatch * FAR* ppDispObject);
    STDMETHOD(HTMLEncode)(BSTR bstrIn, BSTR FAR* pbstrEncoded);
    STDMETHOD(MapPath)(BSTR bstrLogicalPath, BSTR FAR* pbstrPhysicalPath);
    STDMETHOD(URLEncode)(BSTR bstrIn, BSTR FAR* pbstrEncoded);

// CAeServer
	static void InitializeClass();
	CAeServer();
	
private:
	static CIniFile	s_iniFile;
	_bstr_t			m_bstrMapPathBase;
};

#endif //__AESERVER_H_
