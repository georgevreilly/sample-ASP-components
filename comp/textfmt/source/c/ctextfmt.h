// CTextFmt.h : Declaration of the CTextFmt


#include <asptlb.h>
#include "resource.h"       // main symbols
#include "Context.h"

/////////////////////////////////////////////////////////////////////////////
// TextFmt

class CTextFmt : 
    public CComDualImpl<ITextFmt, &IID_ITextFmt, &LIBID_TextFormatter>, 
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CTextFmt,&CLSID_CTextFmt>
{
public:
    CTextFmt() {}
BEGIN_COM_MAP(CTextFmt)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ITextFmt)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CTextFmt) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation.  The default is to support it

DECLARE_REGISTRY(CTextFmt, _T("IISSample.TextFmt.C++"),
                 _T("IISSample.TextFmt.C++"), IDS_CTEXTFMT_DESC,
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

// ITextFmt
public:
    STDMETHOD(About)(BSTR *);
    STDMETHOD(WrapTextFromFile)(BSTR, int);

private:
    void WriteLn(CContext&, const char* szText);
	CComPtr<IUnknown>	m_pUnkMarshaler;
};
