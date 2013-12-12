#ifndef __HKEY_H__
#define __HKEY_H__

#include "RegObj.h"

/////////////////////////////////////////////////////////////////////////////
// CHKey: a wrapper class for HKEY.
// It does a few useful things:
// * the HKEY is automatically closed in the dtor, thereby making returning
//   errors from functions that use this class much simpler.
// * The return value from Win32 registry function is checked and remembered
// * ReportError becomes trivial

class CHKey
{
public:
    CHKey(
        BOOL fFlush = FALSE)
        : m_hk(NULL),
          m_lErr(ERROR_SUCCESS),
          m_fFlush(fFlush)
    {}
    
    ~CHKey()
    {
        if (m_hk != NULL)
            CloseKey();
    }
    
    // Cast `this' to an HKEY
    operator HKEY() const
    {return m_hk;}

    LONG
    Error() const
    {return m_lErr;}

    BOOL
    CreateKey(
        HKEY       hKeyParent,
        LPCTSTR    ptszKeyName,
        LPTSTR     ptszClass,
        DWORD      dwOptions,
        REGSAM     samDesired,
        LPSECURITY_ATTRIBUTES pSecAttr,
        LPDWORD    pdwDisposition)
    {
        m_lErr = ::RegCreateKeyEx(hKeyParent, ptszKeyName, 0,
                                  ptszClass, dwOptions, samDesired,
                                  pSecAttr, &m_hk, pdwDisposition);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    OpenKey(
        HKEY    hKeyParent,
        LPCTSTR ptszKeyName,
        REGSAM  samDesired)
    {
        m_lErr = ::RegOpenKeyEx(hKeyParent, ptszKeyName, 0, samDesired, &m_hk);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    CloseKey()
    {
        if (m_fFlush)
            FlushKey();
        m_lErr = ::RegCloseKey(m_hk);
        m_hk = NULL;
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    FlushKey()
    {
        m_lErr = ::RegFlushKey(m_hk);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    DeleteKey(
        LPCTSTR ptszKeyName)
    {
        m_lErr = ::RegDeleteKey(m_hk, ptszKeyName);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    DeleteValue(
        LPCTSTR ptszValueName)
    {
        m_lErr = ::RegDeleteValue(m_hk, ptszValueName);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    QueryValue(
        LPCTSTR ptszValueName,
        LPDWORD pdwType,
        LPBYTE  pbData,
        LPDWORD pcbData)
    {
        m_lErr = ::RegQueryValueEx(m_hk, ptszValueName, NULL, pdwType,
                                   pbData, pcbData);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    SetValue(
        LPCTSTR     ptszValueName,
        DWORD       dwType,
        CONST BYTE* pbData,
        DWORD       cbData)
    {
        m_lErr = ::RegSetValueEx(m_hk, ptszValueName, NULL, dwType,
                                 pbData, cbData);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    QueryInfoKey(
        LPTSTR    ptszClass,
        LPDWORD   pctcClass, 
        LPDWORD   pcSubkeys,
        LPDWORD   pctcMaxSubkeyLen,
        LPDWORD   pctcMaxClassLen,
        LPDWORD   pcValues,
        LPDWORD   pctcMaxValueNameLen,
        LPDWORD   pcbMaxValueLen,
        LPDWORD   pcbSecurityDescriptor,
        PFILETIME pftLastWriteTime)
    {
        m_lErr= ::RegQueryInfoKey(m_hk, ptszClass, pctcClass, NULL, pcSubkeys,
                                  pctcMaxSubkeyLen, pctcMaxClassLen, pcValues,
                                  pctcMaxValueNameLen, pcbMaxValueLen,
                                  pcbSecurityDescriptor, pftLastWriteTime);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    EnumKey(
        DWORD     dwIndex,
        LPTSTR    ptszName,
        LPDWORD   pctcName,
        LPTSTR    ptszClass,
        LPDWORD   pctcClass,
        PFILETIME pftLastWriteTime)
    {
        m_lErr = ::RegEnumKeyEx(m_hk, dwIndex, ptszName, pctcName, NULL,
                                ptszClass, pctcClass, pftLastWriteTime);
        return m_lErr == ERROR_SUCCESS;
    }

    BOOL
    EnumValue(
        DWORD     dwIndex,
        LPTSTR    ptszValueName,
        LPDWORD   pctcValueName,
        LPDWORD   pdwType,
        LPBYTE    pbValueData,
        LPDWORD   pcbValueData)
    {
        m_lErr = ::RegEnumValue(m_hk, dwIndex, ptszValueName, pctcValueName,
                                NULL, pdwType, pbValueData, pcbValueData);
        return m_lErr == ERROR_SUCCESS;
    }

    HRESULT
    ReportError() const
    {return m_lErr == ERROR_SUCCESS  ?  S_OK  :   ::ReportError(m_lErr);}
    
private:
    // private, unimplemented copy ctor, and op= to prevent
    // compiler synthesizing them
    CHKey(const CHKey&);
    CHKey& operator=(const CHKey&);

    HKEY        m_hk;
    LONG        m_lErr;
    const BOOL  m_fFlush;
};



/////////////////////////////////////////////////////////////////////////////
// CNamedHKey: turns a FullKeyValueName string into an HKEY

class CNamedHKey
{
public:
    enum SPLITKEYVALUE {
        KEYONLY = 1,
        KEYANDVALUE = 2
    };

    CNamedHKey(
        BSTR          bstrRegFullKeyValueName,
        SPLITKEYVALUE skv = KEYANDVALUE);

    ~CNamedHKey();

    LPCTSTR
    Computername() const
    {return m_ptszComputername;}

    LPCTSTR
    Keyname() const
    {return m_ptszKeyname;}

    LPCTSTR
    Valuename() const
    {return m_ptszValuename;}

    HRESULT
    ReportError() const
    {return m_lErr == ERROR_SUCCESS  ?  S_OK  :   ::ReportError(m_lErr);}

    // Cast `this' to an HKEY
    operator HKEY() const
    {return m_hk;}

    // Is `this' a valid object?
    BOOL
    operator!()
    {return m_lErr != ERROR_SUCCESS;}

    BOOL
    operator==(
        const CNamedHKey& rnhk) const;
    
protected:
    // private, unimplemented default ctor, copy ctor, and op= to prevent
    // compiler synthesizing them
    CNamedHKey();
    CNamedHKey(const CNamedHKey&);
    CNamedHKey& operator=(const CNamedHKey&);

    LONG
    _Cleanup(
        LONG lErr);

    HKEY
    _ParseHKeyRoot(
        BSTR& rbstrRegFullKeyValueName);
    
    HKEY                m_hk;
    HKEY                m_hkNonRemote;
    BSTR                m_bstrRegFullKeyValueName;
    LPTSTR              m_ptszComputername;
    LPTSTR              m_ptszKeyname;
    LPTSTR              m_ptszValuename;
    const SPLITKEYVALUE m_skv;
    LONG                m_lErr;
};



/////////////////////////////////////////////////////////////////////////////
// CKeyClass : encapsulates the classname of a key.  The classname is a
// little-known property of a key that is not displayed by RegEdt32.

class CKeyClass
{
public:
    CKeyClass(
        CHKey& hk);

    ~CKeyClass()
    {delete [] m_ptszClass;}

    LPTSTR
    ClassName()
    {return m_ptszClass;}

    // Is `this' a valid object?
    BOOL
    operator!()
    {return m_ptszClass == NULL;}

    HRESULT
    ReportError() const
    {return m_lErr == ERROR_SUCCESS  ?  S_OK  :   ::ReportError(m_lErr);}

private:
    LPTSTR  m_ptszClass;
    LONG    m_lErr;
};



/////////////////////////////////////////////////////////////////////////////
// Misc utility functions

LONG    RecurseDeleteKey(CHKey& rhkParent, LPCTSTR ptszKeyname, int nLevels=0);
LONG    RecurseCopyKey(CHKey& rhkSourceParent, CHKey& rhkDestParent,
                       LPCTSTR ptszKeyname, int nLevels=0);

#endif // __HKEY_H__
