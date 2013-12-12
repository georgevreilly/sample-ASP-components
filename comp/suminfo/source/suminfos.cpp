// SumInfos.cpp : Implementation of CSumInfos
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
// CSumInfos implements CLSID_SumInfos (IISSample.SumInfos.1)
// This class represents a collection of CSumInfo objects.
//

#include "stdafx.h"
#include "SumInfo.h"
#include "SumInfos.h"
#include "SumEnum.h"

/////////////////////////////////////////////////////////////////////////////
// CSumInfos

STDMETHODIMP CSumInfos::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_ISumInfos,
    };
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}


STDMETHODIMP CSumInfos::get_Count(long * pVal)
{
    *pVal = m_nFiles;

	return S_OK;
}

STDMETHODIMP CSumInfos::get_Item(VARIANT Index, ISumInfo** ppVal)
{
    *ppVal = NULL;

	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response ) ) )
	{
		return E_FAIL;
	}

    HRESULT hr = VariantChangeType(&Index, &Index, 0, VT_I4);
    if (m_lStyle == CSumInfo::STYLE_DEBUG)
    {
        WriteResponseString(cxt, L"In get_Item ");
        if (cxt.Response()) cxt.Response()->Write(Index);
        WriteResponseString(cxt,L"...<br>");
    }

    // Indicies are always 1 based in VB
    if (FAILED(hr) || Index.lVal < 1 || Index.lVal > m_nFiles)
    {
        return Error(IDS_E_BADINDEX);
    }

    EnterCriticalSection(&m_cs);
    // If we don't already have this guy, get him.
    if (m_rgFiles[Index.lVal-1].v.vt != VT_UNKNOWN || m_rgFiles[Index.lVal-1].v.punkVal == NULL)
    {
        ISumInfo* pSI=NULL;
        CComObject<CSumInfo>* p = new CComObject<CSumInfo>;
        p->FinalConstruct();
    	p->QueryInterface(IID_ISumInfo, (void**)&pSI);
        _ASSERTE(pSI);

        if (m_lStyle == CSumInfo::STYLE_DEBUG)
            WriteResponseString(cxt, L"SettingFile...<br>");

        hr = pSI->SetFile(m_rgFiles[Index.lVal-1].bstrFileName);
        if (FAILED(hr))
        {
            pSI->Release();
            LeaveCriticalSection(&m_cs);
            return hr;
        }

        // store a punk in our table
        VariantClear(&m_rgFiles[Index.lVal-1].v);
        m_rgFiles[Index.lVal-1].v.vt = VT_UNKNOWN;
    	pSI->QueryInterface(IID_IUnknown, (void**)&m_rgFiles[Index.lVal-1].v.punkVal);
        pSI->Release();
    }

    _ASSERTE(m_rgFiles[Index.lVal-1].v.punkVal);

    // This has the double effect of incrementing the ref count and doing the
    // needed "cast" to ISumInfo.
    hr = m_rgFiles[Index.lVal-1].v.punkVal->QueryInterface(IID_ISumInfo, (void**)ppVal);

    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt,L"Exiting get_Item...<br>");

    LeaveCriticalSection(&m_cs);

	return hr;
}


STDMETHODIMP CSumInfos::_NewEnum(IUnknown ** ppRet)
{
    *ppRet = NULL;
    HRESULT hr = S_OK;

	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response ) ) )
	{
		return E_FAIL;
	}

    // For each _NewEnum invocation we create a new
    // enum object and give it the filespec. It then does all the dirty
    // work.
    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt, L"In _NewEnum...<br>");

    CComObject<CSumInfosEnum>* p = new CComObject<CSumInfosEnum>;
    _ASSERTE(p!=NULL);
    p->FinalConstruct();
    p->Init(this);

    hr = p->QueryInterface(IID_IUnknown, (void**)ppRet);
    if (FAILED(hr))
    {
        if (m_lStyle == CSumInfo::STYLE_DEBUG)
            WriteResponseString(cxt, L"QI Failed in _NewEnum...<br>");
        delete p;
    }
    
    return hr;
}

STDMETHODIMP CSumInfos::SetFileSpec(BSTR Path, BSTR FileSpec)
{
	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response | CContext::get_Server ) ) )
	{
		return E_FAIL;
	}

    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt, L"In SetFileSpec...<br>");

    HRESULT hr;

	CComBSTR bstrPath = Path;
	// ensure the path ends in a trailing whack
	if ( ( bstrPath.Length() > 0 ) &&
		( bstrPath.m_str[ bstrPath.Length() - 1 ] != L'\\' ) )
	{
		bstrPath.Append( L"\\" );
	}
	
    EnterCriticalSection(&m_cs);
    // Clear old data
    if (m_rgFiles != NULL)
    {
        while(m_nFiles > 0)
        {
            if (m_lStyle == CSumInfo::STYLE_DEBUG)
            {
                TCHAR sz[128];
                wsprintf(sz, _T("Clearing file info (m_nFiles == %u)...<br>"), m_nFiles);
                WriteResponseString(cxt, sz);
            }
            VariantClear(&m_rgFiles[m_nFiles-1].v);
            SysFreeString(m_rgFiles[m_nFiles-1].bstrFileName);
            m_nFiles--;
        }
        if (m_lStyle == CSumInfo::STYLE_DEBUG)
            WriteResponseString(cxt, L"Freeing m_rgFiles<br>");
        free(m_rgFiles);
        m_rgFiles = NULL;
        m_nFiles = 0;
    }

    // Do a FindFirst/FindNext into an array of filenames/VARIANT*. Then
    // when ever a Item or IEnum::Next call comes in we fill in the
    // VARIANT* as needed.
    //
    HANDLE hFirst;
    WIN32_FIND_DATAW find_data;

    CComBSTR bstrFullPath;
    if (cxt.Server())
    {
        if (m_lStyle == CSumInfo::STYLE_DEBUG)
            WriteResponseString(cxt, L"Calling MapPath<br>");
        hr = cxt.Server()->MapPath(bstrPath, &bstrFullPath);
        if (FAILED(hr))
        {
            LeaveCriticalSection(&m_cs);
            return Error(IDS_E_MAPPATH, IID_IServer, hr);
        }
    }
    else
    {
        bstrFullPath = bstrPath;
    }

     // MapPath does not put the trailing \ on
    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt, L"Appending \\<br>");
    int n = SysStringLen(bstrFullPath);
    if (n > 1 && bstrFullPath[n-1] != '\\')
        bstrFullPath.Append(L"\\");

   if (m_lStyle == CSumInfo::STYLE_DEBUG)
    {
        WriteResponseString(cxt, bstrPath);
        WriteResponseString(cxt, L", ");
        WriteResponseString(cxt, FileSpec);
        WriteResponseString(cxt, L"<br>");
    }

    // Now for each filespec (separated by semi-colons) enumerate
    //
    WCHAR seps[] = L" ;";
    WCHAR* token = NULL;
    CComBSTR bstrFileSpecCopy(FileSpec);

    token = wcstok(bstrFileSpecCopy, seps);
    while(token != NULL)
    {
        // Append "\\?\" to the filespec and call the Wide version to turn off path parsing
        //
    #if 0
        CComBSTR bstrSpec(L"\\\\?\\");
    #else
        CComBSTR bstrSpec(L"");
    #endif
        bstrSpec.Append(bstrFullPath);
        bstrSpec.Append(token);
        if (m_lStyle == CSumInfo::STYLE_DEBUG)
        {
            WriteResponseString(cxt, bstrSpec);
            WriteResponseString(cxt, L"<br>");
        }

        hFirst = FindFirstFileW(bstrSpec, &find_data);
        if (hFirst == INVALID_HANDLE_VALUE)
        {
            DWORD err = GetLastError();
            if (err != ERROR_FILE_NOT_FOUND)
            {
                LeaveCriticalSection(&m_cs);
                hr =  HRESULT_FROM_WIN32(err);
                return Error(IDS_E_BADFILESPEC, GUID_NULL, hr);
            }
            token = wcstok(NULL, seps);
            continue;
        }

        do
        {
            if (find_data.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY || 
                find_data.dwFileAttributes == FILE_ATTRIBUTE_HIDDEN ||
                find_data.dwFileAttributes == FILE_ATTRIBUTE_OFFLINE ||
                find_data.dwFileAttributes == FILE_ATTRIBUTE_SYSTEM ||
                find_data.dwFileAttributes == FILE_ATTRIBUTE_TEMPORARY
                )
                continue;

            m_rgFiles = (FILE_ENTRY*)realloc(m_rgFiles, sizeof(FILE_ENTRY)*(m_nFiles+1));
            if (m_rgFiles == NULL)
            {
                LeaveCriticalSection(&m_cs);
                return Error(L"Out of memory", GUID_NULL, E_OUTOFMEMORY);
            }

            CComBSTR bstr(bstrPath);
            bstr.Append(find_data.cFileName);
            m_rgFiles[m_nFiles].bstrFileName = bstr;
            bstr.Detach();
            VariantInit(&m_rgFiles[m_nFiles].v);

            if (m_lStyle == CSumInfo::STYLE_DEBUG)
            {
                WriteResponseString(cxt, L"FindFile: "); WriteResponseString(cxt, m_rgFiles[m_nFiles].bstrFileName);
                WriteResponseString(cxt, L"<br>");
            }

            m_nFiles++;
        }
        while (FindNextFileW(hFirst, &find_data));
        FindClose(hFirst);

        token = wcstok(NULL, seps);
    } // while(token != NULL)

    if (m_lStyle == CSumInfo::STYLE_DEBUG)
    {
        TCHAR sz[128];
        wsprintf(sz, _T("Exiting SetFileSpec (m_nFiles == %u)..."), m_nFiles);
        WriteResponseString(cxt, sz);
    }

    LeaveCriticalSection(&m_cs);
    return S_OK;
}

STDMETHODIMP CSumInfos::get_Style(long * pVal)
{
    *pVal = m_lStyle;

	return S_OK;
}

STDMETHODIMP CSumInfos::put_Style(long newVal)
{
    m_lStyle = newVal;

	return S_OK;
}

// Output the entire collection as HTML
//
STDMETHODIMP CSumInfos::Write()
{
    ISumInfo* psi = NULL;
    HRESULT hr;
    LONG    lStyle;
    VARIANT v;

	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response | CContext::get_Server ) ) )
	{
		return E_FAIL;
	}

    VariantInit(&v);
    v.vt = VT_I4;
    // Start at 1 because get_Item indexes by one.
    for (v.lVal = 1 ; v.lVal <= m_nFiles ; v.lVal++)
    {
        psi=NULL;
        hr = get_Item(v, &psi);
        if (SUCCEEDED(hr))
        {
            psi->get_Style(&lStyle);    // Save away style
            psi->put_Style(m_lStyle);
            psi->Write();
            WriteResponseString(cxt, L"<br>");
            psi->put_Style(lStyle);     // Reset style
            psi->Release();
        }
    }
	return S_OK;
}

