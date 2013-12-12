// RegObj.cpp : Implementation of CRegObj

// George V. Reilly  a-georgr@microsoft.com georger@microcrafts.com  Nov/Dec 96

#include "stdafx.h"
#include "Reg.h"
#include "RegObj.h"
#include "HKey.h"
#include "Colln.h"

//
// forward declaration of some utility functions and classes
//

LPCTSTR _RegType2String(DWORD dwRegValueType);



/////////////////////////////////////////////////////////////////////////////
// CRegObj Public Methods

//
// Get a key's value as a string or a number.  REG_EXPAND_SZ strings
// _will_not_ be expanded.
//

STDMETHODIMP
CRegObj::Get(
    /* [in] */  BSTR     bstrRegFullKeyValueName,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE(_T("Get(%ls)\n"), bstrRegFullKeyValueName);

    return ::GetValue(bstrRegFullKeyValueName, pvtRetVal, FALSE);
}



//
// Get a key's value as a string or a number.  REG_EXPAND_SZ strings
// _will_ be expanded; e.g., %SystemRoot%\foo.ini => d:\winnt\foo.ini
//

STDMETHODIMP
CRegObj::GetExpand(
    /* [in] */  BSTR     bstrRegFullKeyValueName,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE(_T("GetExpand(%ls)\n"), bstrRegFullKeyValueName);

    return ::GetValue(bstrRegFullKeyValueName, pvtRetVal, TRUE);
}



//
// Set a key's value as a string or a number
//

STDMETHODIMP
CRegObj::Set(
    /* [in] */            BSTR    bstrRegFullKeyValueName,
    /* [in] */            VARIANT vtValue,
    /* [in, optional] */  VARIANT_BOOL fFlush)
{
    TRACE(_T("Set(%ls), %u\n"), bstrRegFullKeyValueName, fFlush);

    if (bstrRegFullKeyValueName == NULL)
        return ::ReportError(E_POINTER);
    
    CNamedHKey nhkRoot(bstrRegFullKeyValueName);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    // Build the data for SetValue

    DWORD dwType = 0, dwCount = 0, dwDisposition;
    LPBYTE pbData = NULL;
    HRESULT hr;
    USES_CONVERSION;    // needed by OLE2T
    SAFEARRAY* psa = NULL;
    LONG lLBound = 0, lUBound = 0;

    CComVariant vtValue2;

    // VBScript can call us with a VARIANT that isn't a simple type,
    // such as VT_VARIANT|VT_BYREF.  This resolves it to a simple type.
    if (FAILED(hr = VariantResolveDispatch(&vtValue, &vtValue2)))
        return ::ReportError(hr);

    switch (V_VT(&vtValue2))
    {
    //
    // REG_SZ
    //

    case VT_BSTR:
        dwCount = (wcslen(V_BSTR(&vtValue2)) + 1) * sizeof(TCHAR);
        pbData  = (BYTE*) OLE2T(V_BSTR(&vtValue2));
        dwType  = REG_SZ;
        break;

        
    //
    // REG_DWORD
    //

    case VT_I1:  case VT_I2:  case VT_I4:
    case VT_UI1: case VT_UI2:
        // Coerce all integral types to VT_UI4, which is the same as REG_DWORD
        if (FAILED(hr = VariantChangeType(&vtValue2, &vtValue2, 0, VT_UI4)))
            return ::ReportError(hr);

        // fallthru to VT_UI4

    case VT_UI4:
        dwCount = sizeof(DWORD);
        pbData  = (BYTE*) &V_UI4(&vtValue2);
        dwType  = REG_DWORD;
        break;


    //
    // REG_MULTI_SZ
    //

    case VT_ARRAY | VT_BSTR:
      {
        TRACE0("An Array of BSTRs!\n");

        psa = V_ARRAY(&vtValue2);

        if (SafeArrayGetDim(psa) != 1)
            return ::ReportError(E_INVALIDARG); // accept vectors only
        if (FAILED(hr = SafeArrayGetLBound(psa, 1, &lLBound)))
            return ::ReportError(hr);
        if (FAILED(hr = SafeArrayGetUBound(psa, 1, &lUBound)))
            return ::ReportError(hr);

        dwCount = sizeof(TCHAR); // for trailing _T('\0')

        for (LONG i = lLBound;  i <= lUBound;  ++i)
        {
            CComBSTR bstr;
            
            if (FAILED(hr = SafeArrayGetElement(psa, &i, (void*) &bstr)))
                return ::ReportError(hr);

            dwCount += (wcslen(bstr) + 1) * sizeof(TCHAR);
        }

        dwType = REG_MULTI_SZ;
        pbData = (LPBYTE) _alloca(dwCount);
        LPTSTR ptsz = reinterpret_cast<LPTSTR> (pbData);

        for (i = lLBound;  i <= lUBound;  ++i)
        {
            CComBSTR bstr;
            
            if (FAILED(hr = SafeArrayGetElement(psa, &i, (void*) &bstr)))
                return ::ReportError(hr);

            _tcscpy(ptsz, OLE2T(bstr));
            ptsz += _tcslen(ptsz) + 1;
        }

        *ptsz++ = _T('\0');
        ASSERT((LPBYTE) ptsz == pbData + dwCount);

        break;
      }


    //
    // REG_BINARY
    //

    case VT_ARRAY | VT_UI1:
      {
        TRACE0("An Array of BYTES!\n");

        psa = V_ARRAY(&vtValue2);

        if (SafeArrayGetDim(psa) != 1)
            return ::ReportError(E_INVALIDARG); // accept vectors only
        if (FAILED(hr = SafeArrayGetLBound(psa, 1, &lLBound)))
            return ::ReportError(hr);
        if (FAILED(hr = SafeArrayGetUBound(psa, 1, &lUBound)))
            return ::ReportError(hr);

        dwType  = REG_BINARY;
        dwCount = lUBound - lLBound + 1;
        pbData  = (LPBYTE) _alloca(dwCount);
        LPBYTE pb2 = pbData;

        for (LONG i = lLBound;  i <= lUBound;  ++i)
        {
            if (FAILED(hr = SafeArrayGetElement(psa, &i, (void*) pb2)))
                return ::ReportError(hr);
            ++pb2;
        }

        ASSERT(pb2 == pbData + dwCount);

        break;
      }
        

    //
    // REG_BINARY or REG_MULTI_SZ?
    //

    case VT_ARRAY | VT_VARIANT:
      {
        TRACE0("An Array of Variants!\n");
        psa = V_ARRAY(&vtValue2);

        if (SafeArrayGetDim(psa) != 1)
            return ::ReportError(E_INVALIDARG); // accept vectors only
        if (FAILED(hr = SafeArrayGetLBound(psa, 1, &lLBound)))
            return ::ReportError(hr);
        if (FAILED(hr = SafeArrayGetUBound(psa, 1, &lUBound)))
            return ::ReportError(hr);

        VARTYPE vtType = VT_EMPTY;
        
        for (LONG i = lLBound;  i <= lUBound;  ++i)
        {
            CComVariant vt, vt2;

            if (FAILED(hr = SafeArrayGetElement(psa, &i, (void*) &vt)))
                return ::ReportError(hr);
            if (FAILED(hr = VariantResolveDispatch(&vt, &vt2)))
                return ::ReportError(hr);

            if (i == lLBound)
            {
                vtType = V_VT(&vt2);
                if (vtType == VT_BSTR)
                    dwCount = sizeof(TCHAR); // for trailing _T('\0')
            }
            else if (V_VT(&vt2) != vtType)
                return ::ReportError(DISP_E_TYPEMISMATCH);

            switch (vtType)
            {
            case VT_BSTR:
                dwCount += (wcslen(V_BSTR(&vt2)) + 1) * sizeof(TCHAR);
                dwType  = REG_MULTI_SZ;
                break;

            case VT_I1:  case VT_I2:  case VT_I4:
            case VT_UI1: case VT_UI2:
                if (FAILED(hr = VariantChangeType(&vt2, &vt2, 0, VT_UI4)))
                    return ::ReportError(hr);

                // fallthru to VT_UI4

            case VT_UI4:
                if (V_UI4(&vt2) > 255)
                    return ::ReportError(E_INVALIDARG);
                dwCount++;
                dwType = REG_BINARY;
                break;

            default:
                // Cannot handle array of this type
                return ::ReportError(E_NOTIMPL);
            }
        }

        pbData = (LPBYTE) _alloca(dwCount);

        LPBYTE pb2  = pbData;
        LPTSTR ptsz = reinterpret_cast<LPTSTR> (pbData);

        for (i = lLBound;  i <= lUBound;  ++i)
        {
            CComVariant vt, vt2;
            if (FAILED(hr = SafeArrayGetElement(psa, &i, (void*) &vt)))
                return ::ReportError(hr);
            if (FAILED(hr = VariantResolveDispatch(&vt, &vt2)))
                return ::ReportError(hr);

            switch (dwType)
            {
            case REG_MULTI_SZ:
                _tcscpy(ptsz, OLE2T(V_BSTR(&vt2)));
                ptsz += _tcslen(ptsz) + 1;
                break;

            case REG_BINARY:
                *pb2++ = V_UI1(&vt2);
                break;

            default:
                ASSERT(FALSE);
            }
        }

        if (dwType == REG_MULTI_SZ)
        {
            *ptsz++ = _T('\0');
            ASSERT((LPBYTE) ptsz == pbData + dwCount);
            TRACE2("Variant Array of Strings (%ld..%ld)\n", lLBound, lUBound);
        }
        else if (dwType == REG_BINARY)
        {
            ASSERT(pb2 == pbData + dwCount);
            TRACE2("Variant Array of Bytes (%ld..%ld)\n", lLBound, lUBound);
        }

        break;
      }


    //
    // Not implemented
    //

    default:
        return ::ReportError(E_NOTIMPL);   // Cannot yet handle this data type
    }


#ifdef _DEBUG
    if (dwType == REG_SZ)
        TRACE(_T("value = `%s'.\n"), (LPCTSTR) pbData);
    else if (dwType == REG_DWORD)
        TRACE(_T("value = %ld, %luU, 0x%lx.\n"),
              (LONG)  *(DWORD*) pbData,
              (ULONG) *(DWORD*) pbData,
              (ULONG) *(DWORD*) pbData);
    else if (dwType == REG_MULTI_SZ)
        TRACE0("value = {Array of strings}\n");
    else if (dwType == REG_BINARY)
        TRACE0("value = {Array of bytes}\n");
#endif

    CHKey hk(fFlush);

    if (! hk.CreateKey(nhkRoot, nhkRoot.Keyname(), NULL,
                       REG_OPTION_NON_VOLATILE, KEY_READ | KEY_WRITE,
                       NULL, &dwDisposition))
        return hk.ReportError();

    // TODO: Perhaps we should check to see if the value exists
    // and if it has the same type; if not, complain to the user
    
    if (! hk.SetValue(nhkRoot.Valuename(), dwType, pbData, dwCount))
        return hk.ReportError();

    return S_OK;
}



//
// Set a registry key's value as REG_EXPAND_SZ; e.g., %SystemRoot%\foo.ini
//

STDMETHODIMP
CRegObj::SetExpand(
    /* [in] */            BSTR    bstrRegFullKeyValueName,
    /* [in] */            BSTR    bstrValue,
    /* [in, optional] */  VARIANT_BOOL fFlush)
{
    TRACE(_T("SetExpand(%ls), %u\n"), bstrRegFullKeyValueName, fFlush);

    if (bstrRegFullKeyValueName == NULL  ||  bstrValue == NULL)
        return ::ReportError(E_POINTER);
    
    CNamedHKey nhkRoot(bstrRegFullKeyValueName);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk(fFlush);
    DWORD dwDisposition;

    if (! hk.CreateKey(nhkRoot, nhkRoot.Keyname(), NULL,
                       REG_OPTION_NON_VOLATILE, KEY_READ | KEY_WRITE,
                       NULL, &dwDisposition))
        return hk.ReportError();

    // Set up the data for SetValue
    USES_CONVERSION;    // needed by OLE2T
    DWORD dwCount = (wcslen(bstrValue) + 1) * sizeof(TCHAR);
    LPBYTE pbData = (BYTE*) OLE2T(bstrValue);

    TRACE(_T("\tvalue = `%s'.\n"), (LPCTSTR) pbData);

    if (! hk.SetValue(nhkRoot.Valuename(), REG_EXPAND_SZ, pbData, dwCount))
        return hk.ReportError();

    return S_OK;
}



//
// Delete a registry key and all of its subkeys and values
//

STDMETHODIMP
CRegObj::DeleteKey(
    /* [in] */            BSTR    bstrRegFullKeyname,
    /* [in, optional] */  VARIANT_BOOL fFlush)
{
    TRACE(_T("DeleteKey(%ls), %u\n"), bstrRegFullKeyname, fFlush);

    if (bstrRegFullKeyname == NULL)
        return ::ReportError(E_POINTER);
    
    CNamedHKey nhkRoot(bstrRegFullKeyname);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk(fFlush);

    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_ALL_ACCESS))
        return hk.ReportError();

    // Recursively delete all of the subkeys and values
    LONG l = RecurseDeleteKey(hk, nhkRoot.Valuename());

    return (l != ERROR_SUCCESS)  ?  ::ReportError(l)  :  S_OK;
}



//
// Remove a named value from a registry key
//

STDMETHODIMP
CRegObj::DeleteValue(
    /* [in] */            BSTR    bstrRegFullKeyValueName,
    /* [in, optional] */  VARIANT_BOOL fFlush)
{
    TRACE(_T("DeleteValue(%ls), %u\n"), bstrRegFullKeyValueName, fFlush);

    if (bstrRegFullKeyValueName == NULL)
        return ::ReportError(E_POINTER);
    
    CNamedHKey nhkRoot(bstrRegFullKeyValueName);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk(fFlush);

    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_ALL_ACCESS))
        return hk.ReportError();

    if (! hk.DeleteValue(nhkRoot.Valuename()))
        return hk.ReportError();

    return S_OK;
}



//
// Copy a registry key and all subkeys and values
//

STDMETHODIMP
CRegObj::CopyKey(
    /* [in] */            BSTR    bstrRegFullKeynameSource,
    /* [in] */            BSTR    bstrRegFullKeynameDest,
    /* [in, optional] */  VARIANT_BOOL fFlush)
{
    TRACE(_T("CopyKey(%ls, %ls), %u\n"),
          bstrRegFullKeynameSource, bstrRegFullKeynameDest, fFlush);

    if (bstrRegFullKeynameSource == NULL  ||  bstrRegFullKeynameDest == NULL)
        return ::ReportError(E_POINTER);
    
    CNamedHKey nhkSourceRoot(bstrRegFullKeynameSource, CNamedHKey::KEYONLY);
    if (!nhkSourceRoot)
        return nhkSourceRoot.ReportError();

    CNamedHKey nhkDestRoot(bstrRegFullKeynameDest, CNamedHKey::KEYONLY);
    if (!nhkDestRoot)
        return nhkDestRoot.ReportError();

    // Is SourceRoot the same as DestRoot? If so, do nothing and return success
    if (nhkSourceRoot == nhkDestRoot)
        return S_OK;

    // Create keys to kick off RecurseCopyKey
    CHKey hkSource;
    if (! hkSource.OpenKey(nhkSourceRoot, nhkSourceRoot.Keyname(),
                           KEY_ALL_ACCESS))
        return hkSource.ReportError();

    CKeyClass kcSource(hkSource);
    if (!kcSource)
        return kcSource.ReportError();

    DWORD dwDisposition;
    CHKey hkDest(fFlush);

    if (! hkDest.CreateKey(nhkDestRoot, nhkDestRoot.Keyname(),
                           kcSource.ClassName(), REG_OPTION_NON_VOLATILE,
                           KEY_READ | KEY_WRITE, NULL, &dwDisposition))
        return hkDest.ReportError();

    // Recursively copy the keys
    LONG l = RecurseCopyKey(hkSource, hkDest, _T(""));

    return (l != ERROR_SUCCESS)  ?  ::ReportError(l)  :  S_OK;
}



//
// Expand a string containing environment variables
//

STDMETHODIMP
CRegObj::ExpandString(
    /* [in] */  BSTR  bstr,
    /* [out] */ BSTR* pbstrRetVal)
{
    TRACE(_T("ExpandString(%ls)\n"), bstr);

    if (bstr == NULL  ||  pbstrRetVal == NULL)
        return ::ReportError(E_POINTER);

    USES_CONVERSION;    // needed by OLE2CT
    LPCTSTR ptsz = OLE2CT(bstr);
    
    // Find out how many TCHARs expansion will take
    DWORD dwCount = ::ExpandEnvironmentStrings(ptsz, NULL, 0);

    // Allocate temporary memory
    LPTSTR ptszExpanded = (LPTSTR) _alloca(dwCount * sizeof(TCHAR));

    // Get the expanded string
    ::ExpandEnvironmentStrings(ptsz, ptszExpanded, dwCount);

    // Copy to the return value pointer
    *pbstrRetVal = T2BSTR(ptszExpanded);
    
    return S_OK;
}



//
// Is key already present in the registry?
//

STDMETHODIMP
CRegObj::KeyExists(
    /* [in] */  BSTR     bstrRegFullKeyname,
    /* [out] */ VARIANT_BOOL* pfRetVal)
{
    TRACE(_T("KeyExists(%ls)\n"), bstrRegFullKeyname);

    if (bstrRegFullKeyname == NULL  ||  pfRetVal == NULL)
        return ::ReportError(E_POINTER);

    *pfRetVal = FALSE;

    CNamedHKey nhkRoot(bstrRegFullKeyname, CNamedHKey::KEYONLY);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk;

    // TODO: think about checking for other access permissions; e.g., write
    *pfRetVal = hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_READ);

    return S_OK;
}



//
// Return the type of a registry value
//

STDMETHODIMP
CRegObj::ValueType(
    /* [in] */  BSTR  bstrRegFullKeyValueName,
    /* [out] */ BSTR* pbstrRetVal)
{
    TRACE(_T("ValueType(%ls)\n"), bstrRegFullKeyValueName);

    if (bstrRegFullKeyValueName == NULL  ||  pbstrRetVal == NULL)
        return ::ReportError(E_POINTER);

    CNamedHKey nhkRoot(bstrRegFullKeyValueName);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk;
    
    // if the key doesn't exist, it's an error
    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_READ))
        return hk.ReportError();

    DWORD dwType = 0;

    // if the value doesn't exist, _RegType2String will return ""
    if (! hk.QueryValue(nhkRoot.Valuename(), &dwType, NULL, NULL))
        dwType = (DWORD) -1;    // out-of-band value

    LPCTSTR ptszValueType = _RegType2String(dwType);
    *pbstrRetVal = T2BSTR(ptszValueType);

    TRACE1("type is \"%ls\".\n", *pbstrRetVal);

    return S_OK;
}



//
// Return a collection of a key's subkeys
//

STDMETHODIMP
CRegObj::SubKeys(
    /* [in] */  BSTR     bstrRegFullKeyname,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE(_T("SubKeys(%ls)\n"), bstrRegFullKeyname);

    if (bstrRegFullKeyname == NULL  ||  pvtRetVal == NULL)
        return ::ReportError(E_POINTER);

    VariantInit(pvtRetVal);

    // Create a collection object
	CComObject<CRegSubKeysCollection>* pColl = NULL;
    ATLTRY(pColl = new CComObject<CRegSubKeysCollection>);
    if (pColl == NULL)
        return ::ReportError(E_OUTOFMEMORY);

	HRESULT hr = pColl->Init(bstrRegFullKeyname);

    // Return an IDispatch variant, which points to the IDispatch
    // interface on the collection object.  The callee will Release
    // the interface, destroying the object, when it clears pvtRetVal.
    
    if (FAILED(hr))
        return ::ReportError(hr);

    // Have to use a raw pointer here.  A CCom[QI]Ptr would Release
    // as soon as it goes out of scope at the end of this block.
    IDispatch* pDisp = NULL;
    pColl->QueryInterface(IID_IDispatch, (void**) &pDisp);
    ASSERT(pDisp != NULL);
    
    V_VT(pvtRetVal) = VT_DISPATCH;
    V_DISPATCH(pvtRetVal) = pDisp;

	return S_OK; 
}



//
// Return a collection of a key's values
//

STDMETHODIMP
CRegObj::Values(
    /* [in] */  BSTR     bstrRegFullKeyname,
    /* [out] */ VARIANT* pvtRetVal)
{
    TRACE(_T("Values(%ls)\n"), bstrRegFullKeyname);

    if (bstrRegFullKeyname == NULL  ||  pvtRetVal == NULL)
        return ::ReportError(E_POINTER);

    VariantInit(pvtRetVal);

    // Create a collection object
	CComObject<CRegValuesCollection>* pColl = NULL;
	ATLTRY(pColl = new CComObject<CRegValuesCollection>);
    if (pColl == NULL)
        return ::ReportError(E_OUTOFMEMORY);

	HRESULT hr = pColl->Init(bstrRegFullKeyname);

    // Return an IDispatch variant, which points to the IDispatch
    // interface on the collection object.  The callee will Release
    // the interface, destroying the object, when it clears pvtRetVal.
    
    if (FAILED(hr))
        return ::ReportError(hr);

    // Have to use a raw pointer here.  A CCom[QI]Ptr would Release
    // as soon as it goes out of scope at the end of this block.
    IDispatch* pDisp = NULL;
    pColl->QueryInterface(IID_IDispatch, (void**) &pDisp);
    ASSERT(pDisp != NULL);
    
    V_VT(pvtRetVal) = VT_DISPATCH;
    V_DISPATCH(pvtRetVal) = pDisp;

	return S_OK; 
}



//
// ctor
//

CRegObj::CRegObj()
{
    TRACE0("CRegObj::CRegObj\n");
}



//
// dtor
//

CRegObj::~CRegObj()
{
    TRACE0("CRegObj::~CRegObj\n");
}



//
// ATL Wizard generates this function
//

STDMETHODIMP
CRegObj::InterfaceSupportsErrorInfo(
    REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IRegObj,
    };

    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i], riid))
            return S_OK;
    }
    return S_FALSE;
}



//
// Do the actual work of Get and GetExpand; i.e., get a key's value as a
// string or a number and expand REG_EXPAND_SZ strings according to fExpand.
//

HRESULT
GetValue(
    BSTR     bstrRegFullKeyValueName,
    VARIANT* pvtRetVal,
    BOOL     fExpand)
{
    if (bstrRegFullKeyValueName == NULL  ||  pvtRetVal == NULL)
        return ::ReportError(E_POINTER);
    
    VariantInit(pvtRetVal);

    CNamedHKey nhkRoot(bstrRegFullKeyValueName);

    if (!nhkRoot)
        return nhkRoot.ReportError();

    CHKey hk;
    
    if (! hk.OpenKey(nhkRoot, nhkRoot.Keyname(), KEY_READ))
        return hk.ReportError();

    // find out how many bytes the data occupies
    DWORD dwType = 0, dwCount = 0;

    if (! hk.QueryValue(nhkRoot.Valuename(), &dwType, NULL, &dwCount))
        return hk.ReportError();

    // make temporary space for the data
    LPBYTE pbData = (LPBYTE) _alloca(dwCount);

    // now get the data
    if (! hk.QueryValue(nhkRoot.Valuename(), &dwType, pbData, &dwCount))
        return hk.ReportError();

    switch (dwType)
    {
    case REG_EXPAND_SZ:
        if (fExpand)
        {
            // How many TCHARs is the expanded string?
            dwCount = ::ExpandEnvironmentStrings((LPCTSTR) pbData, NULL, 0);
            LPTSTR ptszExpanded = (LPTSTR) _alloca(dwCount * sizeof(TCHAR));
            ::ExpandEnvironmentStrings((LPCTSTR)pbData, ptszExpanded, dwCount);

            // Use the expanded string
            pbData = (LPBYTE) ptszExpanded;
        }

        // fallthru
        
    case REG_SZ:
        V_VT(pvtRetVal) = VT_BSTR;
        V_BSTR(pvtRetVal) = T2BSTR((LPCTSTR) pbData);
        TRACE(_T("\t%s value = `%ls'.\n"),
              _RegType2String(dwType), V_BSTR(pvtRetVal));
        break;

    case REG_DWORD:
        // VB doesn't have unsigned types, so we coerce DWORDs to I4,
        // which has the same size
        V_VT(pvtRetVal) = VT_I4;
        V_I4(pvtRetVal) = *(INT*) pbData;
        TRACE(_T("\tvalue = %ld, %luU, 0x%lx.\n"),
              (LONG)  V_I4(pvtRetVal),
              (ULONG) V_I4(pvtRetVal),
              (ULONG) V_I4(pvtRetVal));
        break;

    case REG_MULTI_SZ:
      {
        ULONG   cStrings = 0;
        LPCTSTR ptsz     = reinterpret_cast<LPCTSTR> (pbData);
        LPCTSTR ptszEnd  = reinterpret_cast<LPCTSTR> (pbData + dwCount);

        // Data is a series of nul-terminated strings terminated by two nuls.
        // Figure out how many values we have
        while (*ptsz != _T('\0')  &&  ptsz < ptszEnd)
        {
            ++cStrings;
            ptsz += _tcslen(ptsz) + 1; // skip string and trailing \0
        }

        // Create a SAFEARRAY to hold the return result.  The array
        // has to be of VARIANTs, not BSTRs, as you might expect, because
        // VBScript will not accept an array of BSTRs (although VB5 will).
        SAFEARRAYBOUND rgsabound[1] = {{cStrings, 0L}};
        SAFEARRAY*     psa = SafeArrayCreate(VT_VARIANT, 1, rgsabound);

        if (psa == NULL)
            return ::ReportError(E_OUTOFMEMORY);

        TRACE(_T("\tString[%u] = {...}\n"), cStrings);

        // now stuff the values into the array
        LONG i = 0;
        ptsz   = reinterpret_cast<LPCTSTR> (pbData);

        while (*ptsz != _T('\0')  &&  ptsz < ptszEnd)
        {
            // Stuff the string into a BSTR VARIANT
            CComVariant vt = T2BSTR(ptsz);
            ASSERT(V_VT(&vt) == VT_BSTR);
            HRESULT hr = SafeArrayPutElement(psa, &i, (void*) &vt);
            if (FAILED(hr))
                ::ReportError(hr);
            ++i;
            ptsz += _tcslen(ptsz) + 1; // skip string and trailing \0
        }

        V_VT(pvtRetVal) = VT_ARRAY | VT_VARIANT;
        V_ARRAY(pvtRetVal) = psa;

        break;
      }

    case REG_BINARY:
      {
        // Create a SAFEARRAY to hold the return result.  The array
        // has to be of VARIANTs, not VT_UI1s, as you might expect, because
        // VBScript will not accept an array of bytes (although VB5 will).
	// Note: an alternative would be to return the data in a
	// BSTR.  This would certainly be more compact than an
	// array of VARIANTs, but the client might not be able to
	// treat a BSTR as an array.

        SAFEARRAYBOUND rgsabound[1] = {{dwCount, 0L}};
        SAFEARRAY*     psa = SafeArrayCreate(VT_VARIANT, 1, rgsabound);

        if (psa == NULL)
            return ::ReportError(E_OUTOFMEMORY);

        TRACE(_T("\tByte[%u] = {...}\n"), dwCount);

        // now stuff the values into the array
        for (LONG i = 0;  i < dwCount;  ++i)
        {
            // Stuff the byte into a UI1 VARIANT
            CComVariant vt(pbData[i]);
            ASSERT(V_VT(&vt) == VT_UI1);
            HRESULT hr = SafeArrayPutElement(psa, &i, (void*) &vt);
            if (FAILED(hr))
                ::ReportError(hr);
        }

        V_VT(pvtRetVal) = VT_ARRAY | VT_VARIANT;
        V_ARRAY(pvtRetVal) = psa;

        break;
      }

    default:
        TRACE(_T("\tunsupported variant type: %d\n"), V_VT(pvtRetVal));
        return ::ReportError(E_NOTIMPL); // Cannot yet handle this data type
    }

    return S_OK;
}



//
// Set the Error Info.  It's up to the calling application to
// decide what to do with it.  By default, Denali/VBScript will
// print the error number (and message, if there is one) and
// abort the page.
//

static HRESULT
ReportError(
    HRESULT hr,
    DWORD   dwErr)
{
    HLOCAL pMsgBuf = NULL;

    // If there's a message associated with this error, report that
    if (::FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, dwErr,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &pMsgBuf, 0, NULL)
        > 0)
    {
        AtlReportError(CLSID_CRegObj, (LPCTSTR) pMsgBuf, IID_IRegObj, hr);
    }

    // TODO: add some error messages to the string resources and
    // return those, if FormatMessage doesn't return anything (not
    // all system errors have associated error messages).
    
    // Free the buffer, which was allocated by FormatMessage
    if (pMsgBuf != NULL)
        ::LocalFree(pMsgBuf);

    return hr;
}



//
// Report a Win32 error code
//

HRESULT
ReportError(
    DWORD dwErr)
{
    return ::ReportError(HRESULT_FROM_WIN32(dwErr), dwErr);
}



//
// Report an HRESULT error
//

HRESULT
ReportError(
    HRESULT hr)
{
    return ::ReportError(hr, (DWORD) hr);
}



//
// Copy several characters from a BSTR and return them as a LPTSTR
//

LPTSTR
TcsNDup(
    BSTR bstr,
    int  ctc /* =-1 */)
{
    ASSERT(bstr != NULL);
    
    if (ctc == -1)
        ctc = wcslen(bstr);
    
    LPTSTR ptsz = NULL;
    ATLTRY(ptsz = new TCHAR [ctc + 1]);
    if (ptsz == NULL)
        return NULL;

#if defined(_UNICODE) || defined(OLE2ANSI)
    wcsncpy(ptsz, bstr, ctc);
#else
    ptsz[0] = '\0';
    WideCharToMultiByte(CP_ACP, 0, bstr, ctc, ptsz, ctc, NULL, NULL);
#endif
    ptsz[ctc] = _T('\0');

    return ptsz;
}



//
// Return the type of a registry value as a string; "" for unknown types
//

static LPCTSTR
_RegType2String(
    DWORD dwRegValueType)
{
#define CASE_TYPE(R)    \
    case R:             \
        return _T(#R)

    switch (dwRegValueType)
    {
        CASE_TYPE(REG_NONE);
        CASE_TYPE(REG_SZ);
        CASE_TYPE(REG_EXPAND_SZ);
        CASE_TYPE(REG_BINARY);
        CASE_TYPE(REG_DWORD);
        CASE_TYPE(REG_DWORD_BIG_ENDIAN);
        CASE_TYPE(REG_LINK);
        CASE_TYPE(REG_MULTI_SZ);
        CASE_TYPE(REG_RESOURCE_LIST);
        CASE_TYPE(REG_FULL_RESOURCE_DESCRIPTOR);
        CASE_TYPE(REG_RESOURCE_REQUIREMENTS_LIST);
    default:
        return _T("");
    }
}



// 
// VariantResolveDispatch
//   Convert an IDispatch VARIANT to a (non-Dispatch) VARIANT by
//   invoking its default property until the object that remains
//   is not an IDispatch.  If the original VARIANT is not an IDispatch
//   then the behavior is identical to VariantCopyInd(), with the
//   exception that arrays are copied.
// 
// Parameters:
//   pVarOut       - if successful, the return value is placed here
//   pVarIn        - the variant to copy
//   GUID& riidObj - the calling interface (for error reporting)
//   nObjID        - the Object's name from the resource file
// 
//   pVarOut need not be initialized.  Since pVarOut is a new
//   variant, the caller must VariantClear this object.
// 
// Returns:
//   The result of calling IDispatch::Invoke.  (either NOERROR or
//   the error resulting from the call to Invoke)   may also return
//   E_OUTOFMEMORY if an allocation fails
// 
//   This function always calls Exception() if an error occurs -
//   this is because we need to call Exception() if an IDispatch
//   method raises an exception.  Instead of having the client
//   worry about whether we called Exception() on its behalf or
//   not, we always raise the exception.
// 

HRESULT
VariantResolveDispatch(
    VARIANT* pVarIn,
    VARIANT* pVarOut)
{
    ASSERT(pVarIn != NULL  &&  pVarOut != NULL);
    
    VariantInit(pVarOut);

    HRESULT hrCopy;
    
    if (V_VT(pVarIn) & VT_BYREF)
        hrCopy = VariantCopyInd(pVarOut, pVarIn);
    else
        hrCopy = VariantCopy(pVarOut, pVarIn);
    
    if (FAILED(hrCopy))
        return ::ReportError(hrCopy);
    
    // Follow the IDispatch chain.
    while (V_VT(pVarOut) == VT_DISPATCH)
    {
        VARIANT     varResolved;        // value of IDispatch::Invoke
        DISPPARAMS  dispParamsNoArgs = {NULL, NULL, 0, 0}; 
        EXCEPINFO   ExcepInfo;
        HRESULT     hrInvoke;
        
        // If the variant is equal to Nothing, then it can be argued
        // with certainty that it does not have a default property!
        // hence we return DISP_E_MEMBERNOTFOUND for this case.
        if (V_DISPATCH(pVarOut) == NULL)
            hrInvoke = DISP_E_MEMBERNOTFOUND;
        else
        {
            VariantInit(&varResolved);
            hrInvoke = V_DISPATCH(pVarOut)->Invoke(
                DISPID_VALUE,
                IID_NULL,
                LOCALE_SYSTEM_DEFAULT,
                DISPATCH_PROPERTYGET | DISPATCH_METHOD,
                &dispParamsNoArgs,
                &varResolved,
                &ExcepInfo,
                NULL);
        }
        
        if (FAILED(hrInvoke))
        {
            if (hrInvoke != DISP_E_EXCEPTION)
                hrInvoke = ::ReportError(hrInvoke);
            // for DISP_E_EXCEPTION, SetErrorInfo has already been called
            
            VariantClear(pVarOut);
            return hrInvoke;
        }
        
        // The correct code to restart the loop is:
        //
        //      VariantClear(pVar)
        //      VariantCopy(pVar, &varResolved);
        //      VariantClear(&varResolved);
        //
        // however, the same affect can be achieved by:
        //
        //      VariantClear(pVar)
        //      *pVar = varResolved;
        //      VariantInit(&varResolved)
        //
        // this avoids a copy.  The equivalence rests in the fact that
        // *pVar will contain the pointers of varResolved, after we
        // trash varResolved (WITHOUT releasing strings or dispatch
        // pointers), so the net ref count is unchanged. For strings,
        // there is still only one pointer to the string.
        //
        // NOTE: the next iteration of the loop will do the VariantInit.
        
        VariantClear(pVarOut);
        *pVarOut = varResolved;
    }
    
    return S_OK;
}
