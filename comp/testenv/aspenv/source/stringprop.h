	
// StringProp.h : Declaration of the CStringProp

#ifndef __STRINGPROP_H_
#define __STRINGPROP_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStringProp
class ATL_NO_VTABLE CStringProp : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CStringProp, &CLSID_StringProp>,
	public ISupportErrorInfo,
	public IDispatchImpl<IStringProp, &IID_IStringProp, &LIBID_ASPENVLib>
{
public:
	CStringProp();

DECLARE_REGISTRY_RESOURCEID(IDR_STRINGPROP)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CStringProp)
	COM_INTERFACE_ENTRY(IStringProp)
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

// IStringProp
public:
	STDMETHOD(get_Value)(/*[out, retval]*/ BSTR *pVal);

// CStringProp
public:
	void SetValue( BSTR bstr );
	void SetValue( LPCTSTR sz );

private:
	_bstr_t	m_bstr;
};

#endif //__STRINGPROP_H_
