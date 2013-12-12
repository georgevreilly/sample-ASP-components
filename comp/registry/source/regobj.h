// RegObj.h : Declaration of the CRegObj

#ifndef __REGOBJ_H__
#define __REGOBJ_H__

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Reg

class CRegObj : 
    public CComDualImpl<IRegObj, &IID_IRegObj, &LIBID_RegistryAccess>,
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CRegObj, &CLSID_CRegObj>
{
public:
    CRegObj();
    ~CRegObj();

BEGIN_COM_MAP(CRegObj)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IRegObj)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CRegObj) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation.  The default is to support it

DECLARE_REGISTRY(CRegObj,
                 _T("IISSample.RegistryAccess.1"),
                 _T("IISSample.RegistryAccess"),
                 IDS_REGOBJ_DESC,
                 THREADFLAGS_BOTH)
// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRegObj
public:
    STDMETHOD(Get)(
        BSTR bstrRegFullKeyValueName,
        VARIANT* pvtRetVal);

    STDMETHOD(GetExpand)(
        BSTR bstrRegFullKeyValueName,
        VARIANT* pvtRetVal);

    STDMETHOD(Set)(
        BSTR bstrRegFullKeyValueName,
        VARIANT vtValue,
        VARIANT_BOOL fFlush);

    STDMETHOD(SetExpand)(
        BSTR bstrRegFullKeyValueName,
        BSTR bstrValue,
        VARIANT_BOOL fFlush);

    STDMETHOD(DeleteKey)(
        BSTR bstrRegFullKeyname,
        VARIANT_BOOL fFlush);

    STDMETHOD(DeleteValue)(
        BSTR bstrRegFullKeyValueName,
        VARIANT_BOOL fFlush);

    STDMETHOD(CopyKey)(
        BSTR bstrRegFullKeynameSource,
        BSTR bstrRegFullKeynameDest,
        VARIANT_BOOL fFlush);

    STDMETHOD(ExpandString)(
        BSTR  bstr,
        BSTR* pbstrRetVal);

    STDMETHOD(KeyExists)(
        BSTR bstrRegFullKeyname,
        VARIANT_BOOL* pfRetVal);

    STDMETHOD(ValueType)(
        BSTR bstrRegFullKeyValueName,
        BSTR* pbstrRetVal);

    STDMETHOD(SubKeys)(
        BSTR bstrRegFullKeyname,
        VARIANT* pvtRetVal);

    STDMETHOD(Values)(
        BSTR bstrRegFullKeyname,
        VARIANT* pvtRetVal);
};


/////////////////////////////////////////////////////////////////////////////
// Misc utility functions

HRESULT
GetValue(
    BSTR     bstrRegFullKeyValueName,
    VARIANT* pvtRetVal,
    BOOL     fExpand);

HRESULT
ReportError(
    DWORD dwErr);

HRESULT
ReportError(
    HRESULT hr);

LPTSTR
TcsNDup(
    BSTR bstr,
    int ctc = -1);

HRESULT
VariantResolveDispatch(
    VARIANT* pVarIn,
    VARIANT* pVarOut);

#endif // __REGOBJ_H__
