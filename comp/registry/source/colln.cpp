// Colln.cpp : Implementation of the SubKeys and Values Collection objects

// George V. Reilly  a-georgr@microsoft.com  georger@microcrafts.com  Apr 97

#include "stdafx.h"
#include "Reg.h"
#include "HKey.h"
#include "Colln.h"




///////////////////////////////////////////////////////////////////////////
// class CRegSubKeysCollection

//
// Return the indexed item from the collection.  The index can be an integer,
// 1 <= index <= Count, or a string, where string is the name of one of the
// subkeys (for compatibility with the Values collection).
//
// In VBScript, all of the following are legal:
//      Set Subkeys = reg.SubKeys(strKeyName)
//      SubKeys.Item(1)
//      SubKeys(1)
//      SubKeys.Item("foobar")
//      SubKeys("foobar")
//      For Each k in Subkeys
//          Subkeys(k) ' == k
//

STDMETHODIMP
CRegSubKeysCollection::get_Item(
    /* [in] */  VARIANT  vtIndex,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE0("CRegSubKeysCollection::get_Item\n");

    if (pvtRetVal == NULL)
        return ::ReportError(E_POINTER);

    VariantInit(pvtRetVal);

    CComVariant vtIndex2;

    // VBScript can call us with a VARIANT that isn't a simple type,
    // such as VT_VARIANT|VT_BYREF.  This resolves it to a simple type.
    HRESULT hr = VariantResolveDispatch(&vtIndex, &vtIndex2);

    if (FAILED(hr))
        return ::ReportError(hr);

    switch (V_VT(&vtIndex2))
    {
    case VT_BSTR:
      {
        BSTR bstrIndex = V_BSTR(&vtIndex2);
        CNameValueMap::iterator i = m_nvmap.find(bstrIndex);

        if (i == m_nvmap.end())
            return ::ReportError(E_INVALIDARG);
        else
        {
            // KeyColl.Item("subkeyname") == "subkeyname"
            CComVariant* pBstrVt = (*i).second;
            VariantCopy(pvtRetVal, pBstrVt);
        }

        break;
      }
        
    case VT_UI1: case VT_UI2: case VT_UI4:
    case VT_I1:  case VT_I2:
        if (FAILED(hr = VariantChangeType(&vtIndex2, &vtIndex2, 0, VT_I4)))
            return ::ReportError(hr);

        // fallthru to VT_I4

    case VT_I4:
      {
        INT iIndex = V_I4(&vtIndex2);

        // use 1-based index, VB like
        if (iIndex < 1  ||  iIndex > m_nSize)
            return ::ReportError(E_INVALIDARG);

        VariantCopy(pvtRetVal, &m_VarVect[iIndex-1]);
        break;
      }

    default:
        return ::ReportError(E_INVALIDARG);
    }

    return S_OK;
}



//
// Return the number of elements in the collection
//

STDMETHODIMP
CRegSubKeysCollection::get_Count(
    /* [out] */ long* plRetVal)
{
    TRACE1("CRegSubKeysCollection::get_Count = %ld\n", m_nSize);

    if (plRetVal == NULL)
        return ::ReportError(E_POINTER);

    *plRetVal = m_nSize;

    return S_OK;
}



//
// Return an enumeration of the collection
//

STDMETHODIMP
CRegSubKeysCollection::get__NewEnum(
    /* [out] */ IUnknown** punkRetVal)
{
    TRACE0("CRegSubKeysCollection::get__NewEnum\n");

    if (punkRetVal == NULL)
        return ::ReportError(E_POINTER);

    *punkRetVal = NULL;

    CEnumVariant* p = NULL;
    ATLTRY(p = new CEnumVariant);

    HRESULT hr = (p == NULL)  ?  E_OUTOFMEMORY  :  p->FinalConstruct();

    if (SUCCEEDED(hr))
        hr = p->Init(&m_VarVect[0], &m_VarVect[m_nSize], NULL, AtlFlagCopy);
    
    if (SUCCEEDED(hr))
        hr = p->QueryInterface(IID_IEnumVARIANT, (void**) punkRetVal);

    if (FAILED(hr))
    {
        delete p;
        return ::ReportError(hr);
    }

    return S_OK;
}



//
// Initialize the collection with an array of subkey names.  In addition, we
// also create a case-insensitive map of names to names.  Not very useful
// sounding, admittedly, but it does allow us to index the collection with
// strings and it makes this collection compatible with CRegValuesCollection.
//

HRESULT
CRegSubKeysCollection::Init(
    BSTR bstrRegFullKeyname)
{
    TRACE1("CRegSubKeysCollection::Init(%ls)\n", bstrRegFullKeyname);

    if (m_VarVect != NULL)
        delete [] m_VarVect;

    m_VarVect = NULL;
    m_nSize = 0;
    m_nvmap.clear();

    CNamedHKey nhkRoot(bstrRegFullKeyname, CNamedHKey::KEYONLY);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk;
    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_READ))
        return hk.ReportError();

    DWORD dwMaxKeySize = 0;
    DWORD dwNumKeys = 0;

    if (!hk.QueryInfoKey(NULL, NULL, &dwNumKeys, &dwMaxKeySize, NULL,
                         NULL, NULL, NULL, NULL, NULL))
        return hk.ReportError();

    m_nSize = dwNumKeys;
    ATLTRY(m_VarVect = new CComVariant[m_nSize]);
    if (m_VarVect == NULL)
        return ::ReportError(E_OUTOFMEMORY);

    LPTSTR ptszBuf = (LPTSTR) _alloca(++dwMaxKeySize * sizeof(TCHAR));

    for (DWORD i = 0;  i < dwNumKeys;  ++i)
    {
        DWORD dwKeySize = dwMaxKeySize;

        if (!hk.EnumKey(i, ptszBuf, &dwKeySize, NULL, NULL, NULL))
            *ptszBuf = _T('\0');
        m_VarVect[i] = ptszBuf;

        ASSERT(V_VT(&m_VarVect[i]) == VT_BSTR);
        m_nvmap[V_BSTR(&m_VarVect[i])] = &m_VarVect[i];
    }

    return S_OK;
}



///////////////////////////////////////////////////////////////////////////
// class CRegValue
//    The CRegValuesCollection contains an array of these objects.  They
// need to be full-fledged objects, unlike the CRegSubKeysCollection, because
// they have two properties, Name and Value.  Name is the default property
// so that using an item as a subscript into the collection will work:
//      Set Values = reg.Values(strKeyName)
//      For Each v in Values
//          Values(v) ' == v.Name


//
// Returns the name of a collection element
//

STDMETHODIMP
CRegValue::get_Name(
    /* [out] */ BSTR* pbstrRetVal)
{
    TRACE1("CRegValue::get_Name(%ls)\n", (BSTR) m_bstrName);

    if (pbstrRetVal == NULL)
        return ::ReportError(E_POINTER);

    *pbstrRetVal = m_bstrName.Copy();

    return S_OK;
}



//
// Returns the value of a CRegValuesCollection element
//

STDMETHODIMP
CRegValue::get_Value(
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE0("CRegValue::get_Value\n");

    if (pvtRetVal == NULL)
        return ::ReportError(E_POINTER);

    VariantInit(pvtRetVal);
    VariantCopy(pvtRetVal, &m_vtValue);

    return S_OK;
}



///////////////////////////////////////////////////////////////////////////
// class CRegValuesCollection

//
// Return the indexed item from the collection.  The index can be an integer,
// 1 <= index <= Count, or a string, where string is the name of one of the
// subkeys.  The item returned is an IRegValue object, which has two
// properties, Name and Value.
//
// In VBScript, all of the following are legal:
//      Set Values = reg.Values(strKeyName)
//      Values.Item(1)
//      Values(1)
//      Values.Item("foobar")
//      Values("foobar")
//      For Each v in Values
//          Values(v) ' == v.Name
//

STDMETHODIMP
CRegValuesCollection::get_Item(
    /* [in] */  VARIANT  vtIndex,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE0("CRegValuesCollection::get_Item\n");

    if (pvtRetVal == NULL)
        return ::ReportError(E_POINTER);

    VariantInit(pvtRetVal);

    CComVariant vtIndex2;

    // VBScript can call us with a VARIANT that isn't a simple type,
    // such as VT_VARIANT|VT_BYREF.  This resolves it to a simple type.
    HRESULT hr = VariantResolveDispatch(&vtIndex, &vtIndex2);

    if (FAILED(hr))
        return ::ReportError(hr);

    switch (V_VT(&vtIndex2))
    {
    case VT_BSTR:
      {
        BSTR bstrIndex = V_BSTR(&vtIndex2);
        CNameValueMap::iterator i = m_nvmap.find(bstrIndex);

        if (i == m_nvmap.end())
            return ::ReportError(E_INVALIDARG);
        else
        {
            CComVariant* pDispVt = (*i).second;
            VariantCopy(pvtRetVal, pDispVt);
        }

        break;
      }
        
    case VT_UI1: case VT_UI2: case VT_UI4:
    case VT_I1:  case VT_I2:
        if (FAILED(hr = VariantChangeType(&vtIndex2, &vtIndex2, 0, VT_I4)))
            return ::ReportError(hr);

        // fallthru to VT_I4

    case VT_I4:
      {
        INT iIndex = V_I4(&vtIndex2);

        // use 1-based index, VB like
        if (iIndex < 1  ||  iIndex > m_nSize)
            return ::ReportError(E_INVALIDARG);

        VariantCopy(pvtRetVal, &m_VarVect[iIndex-1]);
        break;
      }

    default:
        return ::ReportError(E_INVALIDARG);
    }

    return S_OK;
}



//
// Return the number of elements in the collection
//

STDMETHODIMP
CRegValuesCollection::get_Count(
    /* [out] */ long* plRetVal)
{
    TRACE1("CRegValuesCollection::get_Count = %ld\n", m_nSize);

    if (plRetVal == NULL)
        return ::ReportError(E_POINTER);

    *plRetVal = m_nSize;

    return S_OK;
}



//
// Return an enumeration of the collection
//

STDMETHODIMP
CRegValuesCollection::get__NewEnum(
    /* [out] */ IUnknown** punkRetVal)
{
    TRACE0("CRegValuesCollection::get__NewEnum\n");

    if (punkRetVal == NULL)
        return ::ReportError(E_POINTER);

    *punkRetVal = NULL;

    CEnumVariant* p = NULL;
    ATLTRY(p = new CEnumVariant);

    HRESULT hr = (p == NULL)  ?  E_OUTOFMEMORY  :  p->FinalConstruct();

    if (SUCCEEDED(hr))
        hr = p->Init(&m_VarVect[0], &m_VarVect[m_nSize], NULL, AtlFlagCopy);
    
    if (SUCCEEDED(hr))
        hr = p->QueryInterface(IID_IEnumVARIANT, (void**) punkRetVal);

    if (FAILED(hr))
    {
        delete p;
        return ::ReportError(hr);
    }

    return S_OK;
}



//
// Initialize the collection with an array of value objects.  In addition,
// we also create a case-insensitive map of names to value objects.  This
// allows us to index the collection with strings.
//

HRESULT
CRegValuesCollection::Init(
    BSTR bstrRegFullKeyname)
{
    TRACE1("CRegValuesCollection::Init(%ls)\n", bstrRegFullKeyname);

    if (m_VarVect != NULL)
        delete [] m_VarVect;

    m_VarVect = NULL;
    m_nSize = 0;
    m_nvmap.clear();

    CNamedHKey nhkRoot(bstrRegFullKeyname, CNamedHKey::KEYONLY);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk;
    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_READ))
        return hk.ReportError();

    DWORD dwMaxValSize  = 0;
    DWORD dwNumValues = 0;

    if (!hk.QueryInfoKey(NULL, NULL, NULL, NULL, NULL,
                         &dwNumValues, &dwMaxValSize, NULL, NULL, NULL))
        return hk.ReportError();

    m_nSize = dwNumValues;
    ATLTRY(m_VarVect = new CComVariant[m_nSize]);
    if (m_VarVect == NULL)
        return ::ReportError(E_OUTOFMEMORY);

    LPTSTR ptszBuf = (LPTSTR) _alloca(++dwMaxValSize * sizeof(TCHAR));

    for (DWORD i = 0;  i < dwNumValues;  ++i)
    {
        DWORD dwValueSize = dwMaxValSize;

        if (hk.EnumValue(i, ptszBuf, &dwValueSize, NULL, NULL, NULL))
        {
            CComObject<CRegValue>* prv = NULL;
            HRESULT hr = CComObject<CRegValue>::CreateInstance(&prv);

            if (FAILED(hr))
                return ::ReportError(hr);

            CComBSTR bstrRegFullKeyValuename(bstrRegFullKeyname);
            bstrRegFullKeyValuename += OLESTR("\\");
            bstrRegFullKeyValuename += ptszBuf;

            CNamedHKey nhk(bstrRegFullKeyValuename);
            ASSERT(!!nhk);

            hr = ::GetValue(bstrRegFullKeyValuename, &prv->m_vtValue, TRUE);
            ASSERT(SUCCEEDED(hr));

            prv->m_bstrName = nhk.Valuename();

            IDispatch* pDisp = NULL;
            prv->QueryInterface(IID_IDispatch, (void**) &pDisp);
            ASSERT(pDisp != NULL);
            
            V_VT(&m_VarVect[i]) = VT_DISPATCH;
            V_DISPATCH(&m_VarVect[i]) = pDisp;

            m_nvmap[prv->m_bstrName] = &m_VarVect[i];
        }
    }

    return S_OK;
}
