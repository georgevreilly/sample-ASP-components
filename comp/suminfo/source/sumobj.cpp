// SumObj.cpp : Implementation of CSumInfo
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
// CSumInfo implements CLSID_SumInfo (IISSample.SummaryInfo.1)
// This class represents a single file.
//

#include "stdafx.h"
#include "SumInfo.h"
#include "SumObj.h"

/////////////////////////////////////////////////////////////////////////////
// CSumInfo


STDMETHODIMP CSumInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_ISumInfo,
    };
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}


// SetFile does the work of opening the file, using
// the propset interfaces to extract the properties,
// and then holding on to them.
//
STDMETHODIMP CSumInfo::SetFile(BSTR FileName)
{
	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response | CContext::get_Server ) ) )
	{
		return E_FAIL;
	}

    CComPtr<IStorage> spStg;
    CComPtr<IPropertySetStorage> spPropSetStg;
    HRESULT hr;

    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt, L"In OpenFile<br>");

    // Prevent more than one client from changing the file
    // at the stame time.
    EnterCriticalSection(&m_cs);

    // Clear old info up front in case of error
    if (m_bstrFileName)
    {
        SysFreeString(m_bstrFileName);
        m_bstrFileName = NULL;
    }
    FreePropVariantArray(sizeof(m_rgPropVarSI)/sizeof(m_rgPropVarSI[0]), m_rgPropVarSI);
    memset(m_rgPropVarSI, 0, sizeof(m_rgPropVarSI));
    FreePropVariantArray(sizeof(m_rgPropVarDSI)/sizeof(m_rgPropVarDSI[0]), m_rgPropVarDSI);
    memset(m_rgPropVarDSI, 0, sizeof(m_rgPropVarDSI));

    BSTR bstrFullPath = NULL;
    if (cxt.Server())
    {
        hr = cxt.Server()->MapPath(FileName, &bstrFullPath);
        if (FAILED(hr))
        {
            LeaveCriticalSection(&m_cs);
            return Error(IDS_E_MAPPATH, IID_IServer, hr);
        }
    }
    else
        bstrFullPath = SysAllocString(FileName);

    // Open the file.
    hr = StgOpenStorage(bstrFullPath,
                        NULL,
                        STGM_READ | 
                        STGM_SHARE_DENY_WRITE |
                        STGM_DIRECT ,
                        NULL,
                        0,
                        &spStg);
    SysFreeString(bstrFullPath);
    if (SUCCEEDED(hr))
    {
        hr = spStg->QueryInterface(IID_IPropertySetStorage, (void**)&spPropSetStg);
        if (FAILED(hr))
        {
            LeaveCriticalSection(&m_cs);
            return Error(IDS_E_UNEXPECTED, IID_IPropertySetStorage, hr);
        }

        if (m_lStyle == CSumInfo::STYLE_DEBUG)
            WriteResponseString(cxt, L"Opened DocFile!<br>");

        // Array of propspecs for summaryinfo props
        PROPSPEC    rgPropSpec[50]; // 50 is more than either suminfo or docsuminfo
        memset(rgPropSpec, 0, sizeof(rgPropSpec));

        // Use IPropertySetStorage to extract the summary info
        IPropertyStorage* pPropStg=NULL;
        hr = spPropSetStg->Open(FMTID_SummaryInformation,
                            STGM_READ |
                            STGM_SHARE_EXCLUSIVE, &pPropStg);
        if (SUCCEEDED(hr))
        {
            for (ULONG i = PIDSI_TITLE ; i <= PIDSI_DOC_SECURITY ; i++)
            {
                rgPropSpec[i-PID_FIRST_USABLE].ulKind = PRSPEC_PROPID;
                rgPropSpec[i-PID_FIRST_USABLE].propid = i;
            }

            hr = pPropStg->ReadMultiple(sizeof(m_rgPropVarSI)/sizeof(m_rgPropVarSI[0]), rgPropSpec, m_rgPropVarSI);
            if (FAILED(hr))
            {
                LeaveCriticalSection(&m_cs);
                return Error(IDS_E_READMULTIPLE, IID_IPropertyStorage, hr);
            }

            // Close SumInfo
            pPropStg->Release();
            pPropStg = NULL;

            // Use IPropertySetStorage to extract the document summary info props

            hr = spPropSetStg->Open(FMTID_DocSummaryInformation,
                                STGM_READ |
                                STGM_SHARE_EXCLUSIVE, &pPropStg);
            if (SUCCEEDED(hr))
            {
                for (i = PIDDSI_CATEGORY ; i <= PIDDSI_LINKSDIRTY ; i++)
                {
                    rgPropSpec[i-PID_FIRST_USABLE].ulKind = PRSPEC_PROPID;
                    rgPropSpec[i-PID_FIRST_USABLE].propid = i;
                }

                hr = pPropStg->ReadMultiple(sizeof(m_rgPropVarDSI)/sizeof(m_rgPropVarDSI[0]), rgPropSpec, m_rgPropVarDSI);
                if (FAILED(hr))
                {
                    LeaveCriticalSection(&m_cs);
                    return Error(IDS_E_READMULTIPLE, IID_IPropertyStorage, hr);
                }
                // Close DocSumInfo
                pPropStg->Release();
                pPropStg = NULL;
            }
            else
            {
                // Must not be a Office 95 DocFile
            }
        }
        else
        {
            // Must not be a Office Docfile
        }

        // Use the IStorage::Stat function to get the 
        // accessed and created times if they weren't in the properties
        STATSTG statstg;
        hr = spStg->Stat(&statstg, STATFLAG_NONAME);
        if (SUCCEEDED(hr))
        {
            if (m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE].vt == VT_EMPTY)
            {
                m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE].vt = VT_FILETIME;
                m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE].filetime = statstg.mtime;
            }
            if (m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE].vt == VT_EMPTY)
            {
                m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE].vt = VT_FILETIME;
                m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE].filetime = statstg.ctime;
            }
        }
    }
    else
    {
        // Not a docfile. Use Win32 means to get what we can
        HANDLE h = CreateFileW( bstrFullPath, 
                                GENERIC_READ,
                                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
        if (h != INVALID_HANDLE_VALUE)
        {
            BY_HANDLE_FILE_INFORMATION file_info;
            if (GetFileInformationByHandle(h, &file_info))
            {
                m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE].vt = VT_FILETIME;
                m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE].filetime = file_info.ftCreationTime;

                m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE].vt = VT_FILETIME;
                m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE].filetime = file_info.ftLastWriteTime;

                m_rgPropVarDSI[PIDDSI_BYTECOUNT-PID_FIRST_USABLE].vt = VT_I4;
                m_rgPropVarDSI[PIDDSI_BYTECOUNT-PID_FIRST_USABLE].lVal = file_info.nFileSizeLow;
            }
            CloseHandle(h);
        }

    }


    m_bstrFileName = SysAllocString(FileName);
    LeaveCriticalSection(&m_cs);

    if (m_lStyle == CSumInfo::STYLE_DEBUG)
        WriteResponseString(cxt, L"Done with SetFile!<br>");

    return S_OK;
}

void
CSumInfo::WriteNormalPart(
	CContext&	rcxt,
	VARIANT*	pv,
	WCHAR*		wszName,
	BOOL*		pfComma)
{
    if (pv->vt != VT_EMPTY)
    {
        if (pv->vt == VT_BSTR && *pv->bstrVal == '\0')
            return;

        if (*pfComma == FALSE)
            *pfComma = TRUE;
        else
            WriteResponseString(rcxt, L", ");
        WriteResponseString(rcxt, L" <b>");
        WriteResponseString(rcxt, wszName);
        WriteResponseString(rcxt, L":</b>&nbsp;"); 
        rcxt.Response()->Write(*pv); 
    }
}
                             

STDMETHODIMP CSumInfo::Write()
{
	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Response ) ) )
	{
		return E_FAIL;
	}

    if (m_lStyle == STYLE_DEBUG)
    {
        WriteResponseString(cxt,L"In Write!<br>");
    }

    VARIANT v, vURL;
    VariantInit(&v);
    VariantInit(&vURL);

	get_URL(&vURL); 
    WriteResponseString(cxt,L"<b><a href=\""); cxt.Response()->Write(vURL); WriteResponseString(cxt,L"\">"); 

    get_Title(&v); 
    if (v.vt != VT_EMPTY)
    {
        // We have to do some gunk here because sometimes titles are
        // blank (with spaces).

        // First strip whitespace
        BSTR bstr;
        bstr = SysAllocString(v.bstrVal);
        WCHAR* pS=v.bstrVal;
        WCHAR* pD=bstr;
        // Strip leading whitespace
        while(*pS && *pS == L' ')
        {
            pS++;
        }
        // Copy meat
        while (*pS)
        {
            *pD = *pS;
            pD++;
            pS++;
        }
        *pD = L'\0';
        // Strip trailing whitespace
        pD--;
        while(*pD == L' ')
        {
            *pD = L'\0';
            pD--;
        }

        SysFreeString(v.bstrVal);
        v.bstrVal = bstr;

        // Check if emtpy
        if (!*v.bstrVal)
            goto lblURL;

        cxt.Response()->Write(v); 
        VariantClear(&v);
        WriteResponseString(cxt,L"</a></b>&nbsp;&nbsp;(");
        WCHAR* p = wcsrchr(vURL.bstrVal, L'\\');
        if (p == NULL)
            p = wcsrchr(vURL.bstrVal, L'/');
        if (p != NULL)
        {
            WriteResponseString(cxt,p+1);
        }
        else
            cxt.Response()->Write(vURL);
        WriteResponseString(cxt,L")<br>");
    }
    else
    {
lblURL:
        // If the title is empty then use the URL.
        WCHAR* p = wcsrchr(vURL.bstrVal, L'\\');
        if (p == NULL)
            p = wcsrchr(vURL.bstrVal, L'/');
        if (p != NULL)
        {
            WriteResponseString(cxt,p+1);
        }
        else
            cxt.Response()->Write(vURL);
        WriteResponseString(cxt,L"</a></b><br>");
    }

    VariantClear(&vURL);

    switch (m_lStyle)
    {
        case CSumInfo::STYLE_DEBUG:
        {
            WriteResponseString(cxt, L"<ul style=\"margin-left:10px\">");
            WriteResponseString(cxt, L"<li>FileName: ");
            WriteResponseString(cxt, m_bstrFileName);
            WriteResponseString(cxt, L"<li>Title: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_TITLE-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Subject: ");  
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_SUBJECT-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Author: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_AUTHOR-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Keywords: "); 
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_KEYWORDS-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Comments: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_COMMENTS-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Template: ");    
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_TEMPLATE-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Last Saved By: ");  
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_LASTAUTHOR-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Rev Number: ");   
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_REVNUMBER-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Edit Time: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_EDITTIME-PID_FIRST_USABLE], TRUE);
            WriteResponseString(cxt, L"<li>Last Printed: "); 
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_LASTPRINTED-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Create Time: ");  
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Last Save Time: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Page Count: ");   
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_PAGECOUNT-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Word Count: ");   
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_WORDCOUNT-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Char Count: ");   
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_CHARCOUNT-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Thumb Nail: ");   
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_THUMBNAIL-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Application Name: ");
            WriteResponsePropVar(cxt, &m_rgPropVarSI[PIDSI_APPNAME-PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Category: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_CATEGORY     -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>PresentationTarget: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_PRESFORMAT   -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Bytes: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_BYTECOUNT    -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Lines: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_LINECOUNT    -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Paragraphs: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_PARCOUNT     -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Slides: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_SLIDECOUNT   -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Notes: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_NOTECOUNT    -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>HiddenSlides: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_HIDDENCOUNT  -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>MMClips: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_MMCLIPCOUNT  -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>ScaleCrop: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_SCALE        -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>HeadingPairs: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_HEADINGPAIR  -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>TitlesofParts: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_DOCPARTS     -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Manager: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_MANAGER      -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>Company: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_COMPANY      -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"<li>LinksUpTo Date: ");
            WriteResponsePropVar(cxt, &m_rgPropVarDSI[PIDDSI_LINKSDIRTY   -PID_FIRST_USABLE]);
            WriteResponseString(cxt, L"</ul>");
            WriteResponseString(cxt, L"Done with Write!<br>");
        }
        break;

        case CSumInfo::STYLE_DEFAULT:
        {
            BOOL fComma = FALSE;
	        get_Subject(&v); WriteNormalPart(cxt, &v, L"Subject", &fComma); VariantClear(&v);

            get_Author(&v); WriteNormalPart(cxt, &v, L"Author", &fComma); VariantClear(&v);
/*
            get_Manager(&v); 
*/
            get_Company(&v); WriteNormalPart(cxt, &v, L"Company", &fComma); VariantClear(&v);

            get_Category(&v); WriteNormalPart(cxt, &v, L"Category", &fComma); VariantClear(&v);
	        get_Keywords(&v);  WriteNormalPart(cxt, &v, L"Keywords", &fComma); VariantClear(&v);
	        get_Comments(&v);  WriteNormalPart(cxt, &v, L"Comments", &fComma); VariantClear(&v);
            get_Application(&v);  WriteNormalPart(cxt, &v, L"Application", &fComma); VariantClear(&v);
/*
            get_Template(&v); 
            get_PresentationTarget(&v); 
*/
            get_CreateTime(&v);  WriteNormalPart(cxt, &v, L"Created", &fComma); VariantClear(&v);
	        get_LastSaveTime(&v);  WriteNormalPart(cxt, &v, L"Modified", &fComma); VariantClear(&v);
/*
	        get_LastPrinted(&v); 
	        get_LastSavedBy(&v); 
            get_RevNumber(&v); 
	        get_EditTime(&v); 
            get_PageCount(&v);
            if (v.vt != VT_EMPTY)
            {
	            WriteResponseString(L" <b>Pages:</b>&nbsp;"); cxt.Response()->Write(v);
                VariantClear(&v);
    
            }
            else 
            {
                VariantClear(&v);
                get_Slides(&v);
                WriteResponseString(L" <b>Slides:</b>&nbsp;"); cxt.Response()->Write(v);
    
            }

            get_Paragraphs(&v); 
            get_Lines(&v); 
	        get_WordCount(&v); 
            get_CharCount(&v); 
            get_ByteCount(&v); 
            get_Notes(&v); 
            get_HiddenSlides(&v); 
            get_MMClips(&v); 
*/
            WriteResponseString(cxt, L"<br>");
        }
        break;

        case CSumInfo::STYLE_FULL:
        {
            WriteResponseString(cxt, L"<table border=\"0\" cellspacing=\"1\" width=\"95%\">");
	        get_Subject(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Subject:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_Author(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Author:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Manager(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Manager:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Company(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Company:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Category(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Category:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_Keywords(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Keywords:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_Comments(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Comments:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Application(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Application:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Template(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Template:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_PresentationTarget(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Presentation Target:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_CreateTime(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Created:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_LastSaveTime(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Modified:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_LastPrinted(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Printed:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_LastSavedBy(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Last Saved By:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_RevNumber(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Revision Number:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

	        get_EditTime(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Total Editing Time:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }


            get_PageCount(&v);
            if (v.vt != VT_EMPTY)
            {
	            WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Pages:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }
            else 
            {
                VariantClear(&v);
                get_Slides(&v);
                if (v.vt != VT_EMPTY)
                {
                    WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Slides:</b></td><td align=left>"); cxt.Response()->Write(v);
                    WriteResponseString(cxt, L"</td></tr>\n");
                }
                VariantClear(&v);
            }
            get_Paragraphs(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Paragraphs:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_Lines(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Lines:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }
	
            get_WordCount(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Words:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }

            get_CharCount(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Characters:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
    
            }
            if (v.vt != VT_EMPTY)
            {
                get_Bytes(&v); 
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Bytes:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
    
            }
            get_Notes(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Notes:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }
            get_HiddenSlides(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Hidden Slides:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }
            get_MMClips(&v); 
            if (v.vt != VT_EMPTY)
            {
                WriteResponseString(cxt, L"<tr><td width=25% align=right><b>Multimedia Clips:</b></td><td align=left>"); cxt.Response()->Write(v);
                WriteResponseString(cxt, L"</td></tr>\n");
                VariantClear(&v);
            }
/*
            get_LinksUpToDate(&v); 
            WriteResponseString(L"<tr><td width=25% align=right><b>LinksUpToDate:</b></td><td align=left>"); cxt.Response()->Write(v);
            WriteResponseString(L"</td></tr>\n");
            VariantClear(&v);
            get_TitlesOfParts(&v); 
            WriteResponseString(L"<tr><td width=25% align=right><b>TitlesOfParts:</b></td><td align=left>"); cxt.Response()->Write(v);
            WriteResponseString(L"</td></tr>\n");
            VariantClear(&v);

            get_HeadingPairs(&v); 
            WriteResponseString(L"<tr><td width=25% align=right><b>HeadingPairs:</b></td><td align=left>"); cxt.Response()->Write(v);
            WriteResponseString(L"</td></tr>\n");
            VariantClear(&v);

            get_ScaleCrop(&v); 
            WriteResponseString(L"<tr><td width=25% align=right><b>ScaleCrop:</b></td><td align=left>"); cxt.Response()->Write(v);
            WriteResponseString(L"</td></tr>\n");
            VariantClear(&v);
*/
           
            WriteResponseString(cxt, L"</table>");
	        
            //get_ThumbNail(/*[out, retval] LPUNKNOWN *pVal*/);

        }
        break;

        default:
            WriteResponseString(cxt, L"!!!Unsupported style!!!<br>");
    }

    return S_OK;
}


STDMETHODIMP CSumInfo::get_Style(long * pVal)
{
    *pVal = m_lStyle;

    return S_OK;
}

STDMETHODIMP CSumInfo::put_Style(long newVal)
{
    m_lStyle = newVal;

    return S_OK;
}

STDMETHODIMP CSumInfo::get_URL(VARIANT *pVal)
{
    pVal->vt = VT_BSTR;
    pVal->bstrVal = SysAllocString(m_bstrFileName);
    return S_OK;
}


STDMETHODIMP CSumInfo::get_Title(VARIANT *pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_TITLE-PID_FIRST_USABLE]);
    return S_OK;
}


STDMETHODIMP CSumInfo::get_Author(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_AUTHOR-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_Subject(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_SUBJECT-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_Application(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_APPNAME-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_Keywords(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_KEYWORDS-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_Comments(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_COMMENTS-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_Template(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_TEMPLATE-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_LastSavedBy(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_LASTAUTHOR-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_RevNumber(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_REVNUMBER-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_EditTime(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_EDITTIME-PID_FIRST_USABLE], TRUE);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_LastPrinted(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_LASTPRINTED-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_CreateTime(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_CREATE_DTM-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_LastSaveTime(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_LASTSAVE_DTM-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_PageCount(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_PAGECOUNT-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_WordCount(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_WORDCOUNT-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_CharCount(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarSI[PIDSI_CHARCOUNT-PID_FIRST_USABLE]);
    return S_OK;
}

STDMETHODIMP CSumInfo::get_ThumbNail(LPUNKNOWN * pVal)
{
    *pVal = NULL;
    // TODO: Add your implementation code here
    return E_NOTIMPL;
}

STDMETHODIMP CSumInfo::get_Category(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_CATEGORY     -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_PresentationTarget(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_PRESFORMAT-PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Bytes(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_BYTECOUNT-PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Lines(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_LINECOUNT   -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Paragraphs(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_PARCOUNT     -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Slides(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_SLIDECOUNT-PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Notes(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_NOTECOUNT-PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_HiddenSlides(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_HIDDENCOUNT    -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_MMClips(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_MMCLIPCOUNT     -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_ScaleCrop(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_SCALE    -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_HeadingPairs(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_HEADINGPAIR    -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_TitlesOfParts(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_DOCPARTS     -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Manager(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_MANAGER    -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_Company(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_COMPANY     -PID_FIRST_USABLE]);
	return S_OK;
}

STDMETHODIMP CSumInfo::get_LinksUpToDate(VARIANT * pVal)
{
    PropVarToVar(pVal, &m_rgPropVarDSI[PIDDSI_LINKSDIRTY     -PID_FIRST_USABLE]);
	return S_OK;
}
