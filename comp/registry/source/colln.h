// Colln.h : Declaration of the SubKeys and Values Collection objects

#ifndef __COLLN_H__
#define __COLLN_H__

#include "resource.h"       // main symbols

// disable warning messages about truncating extremly long identifiers
#pragma warning (disable : 4786)
#include <map>

// Needed for STL on Visual C++ 5.0
#if _MSC_VER>=1100
using namespace std;
#endif


///////////////////////////////////////////////////////////////////////////
// Helper classes

// an enumerator of VARIANTs
typedef CComObject <CComEnum <IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
                    _Copy <VARIANT> > >   CEnumVariant;


// An STL function object that case-insensitively compares BSTRs
struct bstricomp {
    bool
    operator()(
        BSTR bstr1, 
        BSTR bstr2) const
    {return wcsicmp(bstr1, bstr2) < 0;}
};


// An STL map of BSTRs to CComVariant*s
typedef map< BSTR, CComVariant*, bstricomp, allocator<CComVariant*> >
        CNameValueMap;


///////////////////////////////////////////////////////////////////////////
// class CRegSubKeysCollection

class CRegSubKeysCollection :
    public IDispatchImpl<IRegSubKeysCollection, &IID_IRegSubKeysCollection,
                         &LIBID_RegistryAccess>, 
    public ISupportErrorInfo,
    public CComObjectRoot
{
public:
    BEGIN_COM_MAP(CRegSubKeysCollection)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IRegSubKeysCollection)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CRegSubKeysCollection)

    CRegSubKeysCollection()
        : m_VarVect(NULL),
          m_nSize(0)
    {
        TRACE1("CRegSubKeysCollection, %p\n", this);
    }

    ~CRegSubKeysCollection()
    {
        TRACE1("~CRegSubKeysCollection, %p\n", this);
        delete [] m_VarVect;
    }

// IRegSubKeysCollection methods
    STDMETHOD(get_Item)(
        VARIANT  vtIndex,
        VARIANT* pvtRetVal);

    STDMETHOD(get_Count)(
        long* plRetVal);

    STDMETHOD(get__NewEnum)(
        IUnknown** punkRetVal);

// ISupportErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(
        REFIID riid)
    {
        return (InlineIsEqualGUID(IID_IRegSubKeysCollection, riid)
                ? S_OK : S_FALSE);
    }

// helpers
    HRESULT
    Init(
        BSTR bstrRegFullKeyname);

protected:
// internal data
    CNameValueMap   m_nvmap;
    CComVariant*    m_VarVect;
    int             m_nSize;
};



///////////////////////////////////////////////////////////////////////////
// class CRegValue

class CRegValue :
    public IDispatchImpl<IRegValue, &IID_IRegValue,
                         &LIBID_RegistryAccess>, 
    public ISupportErrorInfo,
    public CComObjectRoot
{
public:
    BEGIN_COM_MAP(CRegValue)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IRegValue)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CRegValue)

    CRegValue()
    {
        TRACE1("CRegValue, %p\n", this);
    }

    ~CRegValue()
    {
        TRACE1("~CRegValue, %p\n", this);
    }

// IRegValue methods
    STDMETHOD(get_Name)(
        BSTR* pbstrRetVal);

    STDMETHOD(get_Value)(
        VARIANT* pvtRetVal);

// ISupportErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(
        REFIID riid)
    {
        return (InlineIsEqualGUID(IID_IRegValue, riid)
                ? S_OK : S_FALSE);
    }

protected:
    friend class CRegValuesCollection;

// internal data
    CComBSTR    m_bstrName;
    CComVariant m_vtValue;
};


///////////////////////////////////////////////////////////////////////////
// class CRegValuesCollection

class CRegValuesCollection :
    public IDispatchImpl<IRegValuesCollection, &IID_IRegValuesCollection,
                         &LIBID_RegistryAccess>, 
    public ISupportErrorInfo,
    public CComObjectRoot
{
public:
    BEGIN_COM_MAP(CRegValuesCollection)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IRegValuesCollection)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CRegValuesCollection)

    CRegValuesCollection()
        : m_VarVect(NULL),
          m_nSize(0)
    {
        TRACE1("CRegValuesCollection, %p\n", this);
    }

    ~CRegValuesCollection()
    {
        TRACE1("~CRegValuesCollection, %p\n", this);
        delete [] m_VarVect;
    }

// IRegValuesCollection methods
    STDMETHOD(get_Item)(
        VARIANT  vtIndex,
        VARIANT* pvtRetVal);

    STDMETHOD(get_Count)(
        long* plRetVal);

    STDMETHOD(get__NewEnum)(
        IUnknown** punkRetVal);

// ISupportErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(
        REFIID riid)
    {
        return (InlineIsEqualGUID(IID_IRegValuesCollection, riid)
                ? S_OK : S_FALSE);
    }

// helpers
    HRESULT
    Init(
        BSTR bstrRegFullKeyname);

protected:
// internal data
    CNameValueMap   m_nvmap;
    CComVariant*    m_VarVect;
    int             m_nSize;
};

#endif // __COLLN_H__
