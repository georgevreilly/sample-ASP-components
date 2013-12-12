	
// TraceObj.h : Declaration of the CTracer

#ifndef __TRACER_H_
#define __TRACER_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions

/////////////////////////////////////////////////////////////////////////////
// CTracer
class ATL_NO_VTABLE CTracer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CTracer, &CLSID_Tracer>,
	public ISupportErrorInfo,
	public IDispatchImpl<ITracer, &IID_ITracer, &LIBID_Tracer>
{
public:
	CTracer();
	~CTracer();

DECLARE_REGISTRY_RESOURCEID(IDR_TRACER)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CTracer)
	COM_INTERFACE_ENTRY(ITracer)
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

// ITracer
public:
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
	STDMETHOD(TimerStart)();
	STDMETHOD(TimerStop)();
	STDMETHOD(Trace)(BSTR bstrTrace);
	STDMETHOD(TimerSplit)(BSTR bstrLabel);
	STDMETHOD(TimerTotal)(BSTR bstrLabel);

private:
	void		UpdateTime( SYSTEMTIME&, DWORD );
	HRESULT		WriteLine( SYSTEMTIME&, LPCTSTR );
	HRESULT		WriteTime( SYSTEMTIME&, LPCTSTR, DWORD );

	static void	IncHour( SYSTEMTIME& );
	static void	IncMinute( SYSTEMTIME& );
	static void	IncSecond( SYSTEMTIME& );

	LPTSTR		m_szName;
	DWORD		m_dwTimeStart;
	DWORD		m_dwTimeSplit;
	SYSTEMTIME	m_st;
};

#endif //__TRACER_H_
