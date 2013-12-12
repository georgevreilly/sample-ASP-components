// RegObj.cpp : Implementation of CRegObj

// George V. Reilly  a-georgr@microsoft.com georger@microcrafts.com  Nov/Dec 96

#include "stdafx.h"
#include "Reg.h"
#include "HKey.h"

//
// ctor.  Parse "[\\computername\]HKEY_xxx\foo\...\bar\quux" into
// "\\computername" (optional), HKEY_xxx, "\foo\...\bar", and "quux" and
// set the error code.
//

CNamedHKey::CNamedHKey(
    BSTR          bstrRegFullKeyValueName,
    SPLITKEYVALUE skv /* =KEYANDVALUE */)
    : m_skv(skv)
{
    m_hk = m_hkNonRemote = NULL;
    m_bstrRegFullKeyValueName = bstrRegFullKeyValueName;
    m_ptszComputername = m_ptszKeyname = m_ptszValuename = NULL;
    m_lErr = ERROR_SUCCESS;

    if (bstrRegFullKeyValueName == NULL)
    {
        _Cleanup(ERROR_INVALID_DATA);
        return;
    }

    // check for leading "\\computername\"
    if (bstrRegFullKeyValueName[0] == L'\\'
        &&  bstrRegFullKeyValueName[1] == L'\\')
    {
        BSTR bstrHKey = wcschr(bstrRegFullKeyValueName + 2, L'\\');

        // no '\' terminating computername or zero-length computername?
        if (bstrHKey == NULL  ||  bstrHKey == bstrRegFullKeyValueName + 2)
        {
            _Cleanup(ERROR_INVALID_DATA);
            return;
        }

        m_ptszComputername = TcsNDup(bstrRegFullKeyValueName,
                                     bstrHKey - bstrRegFullKeyValueName);
        if (m_ptszComputername == NULL)
        {
            _Cleanup(ERROR_OUTOFMEMORY);
            return;
        }
        bstrRegFullKeyValueName = bstrHKey + 1;
    }

    // Parse out the leading HKEY_xxx
    if ((m_hkNonRemote = _ParseHKeyRoot(bstrRegFullKeyValueName)) == NULL)
    {
        _Cleanup(ERROR_INVALID_HANDLE);
        return;
    }

    if (m_skv == KEYONLY)
    {
        // do not split into Key\Value pair
        m_ptszKeyname = TcsNDup(bstrRegFullKeyValueName);
        m_ptszValuename = NULL;
    }
    else if (m_skv == KEYANDVALUE)
    {
        // Look for last '\' to split off Valuename
        BSTR bstrValue = wcsrchr(bstrRegFullKeyValueName, L'\\');
        
        // Have name of form "HKLM\foo"; i.e., only one component?
        if (bstrValue == NULL)
        {
            m_ptszKeyname = TcsNDup(OLESTR(""));
            m_ptszValuename = TcsNDup(bstrRegFullKeyValueName);
        }
        else
        {
            m_ptszKeyname = TcsNDup(bstrRegFullKeyValueName,
                                    bstrValue - bstrRegFullKeyValueName);
            m_ptszValuename = TcsNDup(bstrValue + 1);
        }

        if (m_ptszValuename == NULL)
        {
            _Cleanup(ERROR_OUTOFMEMORY);
            return;
        }
    }
    else
    {
        _Cleanup(ERROR_INVALID_DATA);
        return;
    }
    
    if (m_ptszKeyname == NULL)
    {
        _Cleanup(ERROR_OUTOFMEMORY);
        return;
    }

    // Open the key on a remote registry?
    if (m_ptszComputername == NULL)
    {
        m_hk = m_hkNonRemote;
        m_hkNonRemote = NULL;
    }
    else
    {
        m_lErr = ::RegConnectRegistry(m_ptszComputername,
                                      m_hkNonRemote, &m_hk);
        
        if (m_lErr != ERROR_SUCCESS)
            _Cleanup(m_lErr);
    }
    
    // At this point, if m_hk == NULL, there's been an error.
    // Otherwise, m_hk is the key we'll use.
    //   If m_hkNonRemote != NULL, it's one of the predefined
    //     constants, HKEY_CLASSES_ROOT ... HKEY_DYN_DATA
    //     and m_hk refers to a key on a remote registry.
    //   else HKEY_CLASSES_ROOT <= m_hk <= HKEY_DYN_DATA.

    TRACE(_T("computer = `%s', keyname = `%s'\n")
          _T("\tvaluename = `%s', hk = %x, hkNonRemote = %x, ")
          _T("split = %d, err = %x\n"),
          m_ptszComputername, m_ptszKeyname,
          m_ptszValuename, (UINT) m_hk, (UINT) m_hkNonRemote,
          (int) m_skv, m_lErr);
}



//
// dtor
//

CNamedHKey::~CNamedHKey()
{
    _Cleanup(ERROR_SUCCESS);
}



//
// Compare two CNamedHKeys for equality.  Can't just compare
// m_bstrRegFullKeyValueName, because one might say HKLM and the other
// might say HKEY_LOCAL_MACHINE.  Also, keys to remote registries
// might be different.
//

BOOL
CNamedHKey::operator==(
    const CNamedHKey& rnhk) const
{
    if (m_hkNonRemote != rnhk.m_hkNonRemote)
        return FALSE;

    if (m_hkNonRemote == NULL)
        if (m_hk != rnhk.m_hk)
            return FALSE;

    if (m_ptszComputername != NULL  ||  rnhk.m_ptszComputername != NULL)
    {
        if (m_ptszComputername == NULL)
            return FALSE;
        if (rnhk.m_ptszComputername == NULL)
            return FALSE;
        if (_tcsicmp(m_ptszComputername, rnhk.m_ptszComputername) != 0)
            return FALSE;
    }

    return ((_tcsicmp(m_ptszKeyname, rnhk.m_ptszKeyname) == 0)
            && (_tcsicmp(m_ptszValuename, rnhk.m_ptszValuename) == 0)
            && (m_skv  == rnhk.m_skv)
            && (m_lErr == rnhk.m_lErr));
}



//
// Clean up any resources we've allocated
//

LONG
CNamedHKey::_Cleanup(
    LONG lErr)
{
    m_lErr = lErr;

    // did we open a key on a remote registry?  see note in ctor
    if (m_hkNonRemote != NULL)
        ::RegCloseKey(m_hk);

    m_hk = m_hkNonRemote = NULL;

    m_bstrRegFullKeyValueName = NULL;
    delete [] m_ptszComputername;
    delete [] m_ptszKeyname;
    delete [] m_ptszValuename;
    m_ptszComputername = m_ptszKeyname = m_ptszValuename = NULL;

    return m_lErr;
}



//
// Extract HKEY_xxx from the string and update the string
//

HKEY
CNamedHKey::_ParseHKeyRoot(
    BSTR& rbstrRegFullKeyValueName)
{
// Used to initialize aKeyNamesMap
#define NAMED_HKEY(hkShort, hkLong)              \
    { L ## #hkShort ## L"\\",  sizeof(#hkShort), \
      L ## #hkLong ## L"\\",   sizeof(#hkLong),  \
      hkLong                                     \
    }

    static const struct {
        LPCWSTR pwszShortName;
        int     cwcShortName;
        LPCWSTR pwszLongName;
        int     cwcLongName;
        HKEY    hk;
    } aKeyNamesMap[] = {
        NAMED_HKEY(HKCR, HKEY_CLASSES_ROOT),
        NAMED_HKEY(HKCU, HKEY_CURRENT_USER),
        NAMED_HKEY(HKLM, HKEY_LOCAL_MACHINE),
        NAMED_HKEY(HKU,  HKEY_USERS),
        NAMED_HKEY(HKPD, HKEY_PERFORMANCE_DATA),
        NAMED_HKEY(HKCC, HKEY_CURRENT_CONFIG),
        NAMED_HKEY(HKDD, HKEY_DYN_DATA),
    };

    for (int i = ARRAYSIZE(aKeyNamesMap);  --i >= 0;  )
    {
        // cwc includes the trailing '\'
        int cwc = aKeyNamesMap[i].cwcShortName;
        int nCmp = _wcsnicmp(rbstrRegFullKeyValueName,
                             aKeyNamesMap[i].pwszShortName, cwc);

        if (nCmp != 0)
        {
            cwc = aKeyNamesMap[i].cwcLongName;
            nCmp = _wcsnicmp(rbstrRegFullKeyValueName,
                             aKeyNamesMap[i].pwszLongName, cwc);
        }

        if (nCmp == 0)
        {
            ASSERT(rbstrRegFullKeyValueName[cwc-1] == L'\\');

            // modify the string to point past the "HKEY_xxx\"
            rbstrRegFullKeyValueName += cwc;

            if (wcslen(rbstrRegFullKeyValueName) == 0)
                return NULL;    // root only; too dangerous; probably a mistake
            else
                return aKeyNamesMap[i].hk;
        }
    }

    return NULL;
}



//
// ctor: get the key's class name
//

CKeyClass::CKeyClass(
    CHKey& hk)
    : m_ptszClass(NULL),
      m_lErr(ERROR_SUCCESS)
{
    DWORD ctc = 0;

    if (! hk.QueryInfoKey(NULL, &ctc, NULL, NULL, NULL, 
                          NULL, NULL, NULL, NULL, NULL))
    {
        m_lErr = hk.Error();
    }
    else
    {
        ATLTRY(m_ptszClass = new TCHAR [++ctc]);
        if (m_ptszClass == NULL)
        {
            m_lErr = ERROR_OUTOFMEMORY;
            return;
        }

        *m_ptszClass = _T('\0');

        if (! hk.QueryInfoKey(m_ptszClass, &ctc, NULL, NULL, NULL, 
                              NULL, NULL, NULL, NULL, NULL))
        {
            delete [] m_ptszClass;
            m_ptszClass= NULL;
            m_lErr = hk.Error();
        }
    }
}



//
// Recursively copy keys and values
//

LONG
RecurseCopyKey(
    CHKey&  rhkSourceParent,
    CHKey&  rhkDestParent,
    LPCTSTR ptszKeyname,
    int     nLevels /* =0 */)
{
    ASSERT(ptszKeyname != NULL);

    //TRACE(_T("%*sRecurseCopyKey(%s)\n"), 4 * nLevels, _T(""),   ptszKeyname);

    CHKey hkSource;

    if (! hkSource.OpenKey(rhkSourceParent, ptszKeyname, KEY_ALL_ACCESS))
        return hkSource.Error();

    CKeyClass kcSource(hkSource);
    if (!kcSource)
        return kcSource.ReportError();

    CHKey hkDest;
    DWORD dwDisposition;

    if (! hkDest.CreateKey(rhkDestParent, ptszKeyname,
                           kcSource.ClassName(), REG_OPTION_NON_VOLATILE,
                           KEY_READ | KEY_WRITE, NULL, &dwDisposition))
        return hkDest.Error();

    // TODO: copy security information from rhkSourceParent to rhkDestParent
    // when I figure out how Reg{Get,Set}KeySecurity works

    DWORD    cSubkeys = 0;             // number of subkeys
    DWORD    ctcMaxSubkeyLen = 0;      // longest subkey name length  
    DWORD    ctcMaxClassLen = 0;       // longest class string len of subkeys
    DWORD    cValues = 0;              // number of value entries 
    DWORD    ctcMaxValueNameLen = 0;   // longest value name length 
    DWORD    cbMaxValueLen = 0;        // longest value data length 
    DWORD    cbSecurityDescriptor = 0; // security descriptor length 
    FILETIME ftLastWriteTime;

    if (! hkSource.QueryInfoKey(NULL, NULL,
                                &cSubkeys, &ctcMaxSubkeyLen, &ctcMaxClassLen,
                                &cValues, &ctcMaxValueNameLen, &cbMaxValueLen,
                                &cbSecurityDescriptor, &ftLastWriteTime))
        return hkSource.Error();

    // allocate temporary buffers
    
    DWORD  ctcSubkeyName  = ++ctcMaxSubkeyLen;
    LPTSTR ptszSubkeyName = (LPTSTR) _alloca(ctcSubkeyName * sizeof(TCHAR));

    DWORD  ctcValueName  = ++ctcMaxValueNameLen;
    LPTSTR ptszValueName = (LPTSTR) _alloca(ctcValueName * sizeof(TCHAR));

    DWORD  ctcSubkeyClass  = ++ctcMaxClassLen;
    LPTSTR ptszSubkeyClass = (LPTSTR) _alloca(ctcSubkeyClass * sizeof(TCHAR));

    DWORD  cbValueData = cbMaxValueLen;
    LPBYTE pbValueData = (LPBYTE) _alloca(cbValueData);

    LPBYTE pbSecurityDescriptor = (LPBYTE) _alloca(cbSecurityDescriptor);
    LONG   l = ERROR_SUCCESS;
    DWORD  i, dwType;


    // Recursively copy all subkeys
    
    for (i = 0;  i < cSubkeys;  ++i)
    {
        if (! hkSource.EnumKey(i, ptszSubkeyName, &ctcSubkeyName,
                               ptszSubkeyClass, &ctcSubkeyClass,
                               &ftLastWriteTime))
            return hkSource.Error();

        if ((l = RecurseCopyKey(hkSource, hkDest, ptszSubkeyName, nLevels+1))
                != ERROR_SUCCESS)
            return l;
        
        // Reinitialize for next iteration
        ctcSubkeyName  = ctcMaxSubkeyLen;
        ctcSubkeyClass = ctcMaxClassLen;
    }


    // copy all the values
    
    for (i = 0;  i < cValues;  ++i)
    {
        if (! hkSource.EnumValue(i, ptszValueName, &ctcValueName,
                                 &dwType, pbValueData, &cbValueData))
            return hkSource.Error();

#if 0 //#ifdef _DEBUG
        TRACE(_T("%*s `%s' : (%d bytes) : "),
              4 * nLevels + 4, _T(""),   ptszValueName, cbValueData);
        
        switch (dwType)
        {
        case REG_SZ:
            TRACE(_T("REG_SZ: `%s'\n"), (LPCTSTR) pbValueData);
            break;
            
        case REG_EXPAND_SZ:
            TRACE(_T("REG_EXPAND_SZ: `%s'\n"), (LPCTSTR) pbValueData);
            break;
            
        case REG_DWORD:
            TRACE(_T("REG_DWORD: %ld, %luU, 0x%lx.\n"),
                  (LONG)  *(UINT*) pbValueData,
                  (ULONG) *(UINT*) pbValueData,
                  (ULONG) *(UINT*) pbValueData);
            break;
            
        default:
            TRACE(_T("%s\n"), RegType2String(dwType));
            break;
        }
#endif

        if (! hkDest.SetValue(ptszValueName, dwType, pbValueData, cbValueData))
            return hkDest.Error();
        
        // Reinitialize for next iteration
        ctcValueName = ctcMaxValueNameLen;
        cbValueData  = cbMaxValueLen;
    }

    return l;
}



//
// RecurseDeleteKey is necessary because on NT RegDeleteKey
// doesn't work if the specified key has subkeys
//

LONG
RecurseDeleteKey(
    CHKey&  rhkParent,
    LPCTSTR ptszKeyname,
    int     nLevels /* =0 */)
{
    ASSERT(ptszKeyname != NULL);

    //TRACE(_T("%*sRecurseDeleteKey(%s)\n"), 4 * nLevels, _T(""),  ptszKeyname);

    CHKey hk;

    if (! hk.OpenKey(rhkParent, ptszKeyname, KEY_ALL_ACCESS))
        return hk.ReportError();

    FILETIME ftLastWriteTime;
    DWORD    ctcMaxSubkeyLen = 0;      // longest subkey name length  

    if (! hk.QueryInfoKey(NULL, NULL, NULL, &ctcMaxSubkeyLen, NULL,
                          NULL, NULL, NULL, NULL, &ftLastWriteTime))
        return hk.Error();

    DWORD  ctcSubkeyName  = ++ctcMaxSubkeyLen;
    LPTSTR ptszSubkeyName = (LPTSTR) _alloca(ctcSubkeyName * sizeof(TCHAR));

    while (hk.EnumKey(0, ptszSubkeyName, &ctcSubkeyName,
                      NULL, NULL, &ftLastWriteTime))
    {
        LONG l = RecurseDeleteKey(hk, ptszSubkeyName, nLevels + 1);

        if (l != ERROR_SUCCESS)
            return l;

        ctcSubkeyName  = ctcMaxSubkeyLen;
    }

    rhkParent.DeleteKey(ptszKeyname);

    return rhkParent.Error();
}
