// PgCntObj.h : Declaration of the CPgCntObj


#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "ccm.h"            // Central Counter Manager Definition


/////////////////////////////////////////////////////////////////////////////
// PgCnt

class CPgCntObj : 
    public CComDualImpl<IPgCntObj, &IID_IPgCntObj, &LIBID_PageCounter>, 
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CPgCntObj,&CLSID_CPgCntObj>
{
public:
    CPgCntObj()
    { 
    }

    ~CPgCntObj() {}

BEGIN_COM_MAP(CPgCntObj)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IPgCntObj)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CPgCntObj) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation.  The default is to support it

    DECLARE_REGISTRY(CPgCntObj, _T("IISSample.PageCounter.1"),
                     _T("IISSample.PageCounter"), IDS_PGCNTOBJ_DESC,
                     THREADFLAGS_BOTH)

// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// for free-threaded marshalling
DECLARE_GET_CONTROLLING_UNKNOWN()
	HRESULT FinalCountruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p );
	}
	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}


// IPgCntObj
public:

    //Custom Component Methods
	STDMETHOD(PageHit)(LONG* plNumHits);
    STDMETHOD (Hits)  (BSTR bstrURL, LONG* plNumHits);
    STDMETHOD (Reset) (BSTR bstrURL);

private:

    bool GetPathInfo( CComVariant& rvt );
	CComPtr<IUnknown>	m_pUnkMarshaler;
};
