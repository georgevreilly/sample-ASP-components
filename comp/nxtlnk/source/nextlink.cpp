// NextLink.cpp : Implementation of CNextLink
#include "stdafx.h"
#include "NxtLnk.h"
#include "NextLink.h"

CNextLink::LinkFileMapT	CNextLink::s_linkFileMap;

/////////////////////////////////////////////////////////////////////////////
// CNextLink

STDMETHODIMP CNextLink::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INextLink,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

#if 0
STDMETHODIMP CNextLink::OnStartPage (IUnknown* pUnk)  
{
	USES_CONVERSION;

	if(!pUnk)
		return E_POINTER;

	CComPtr<IScriptingContext> spContext;
	HRESULT hr;

	// Get the IScriptingContext Interface
	hr = pUnk->QueryInterface(IID_IScriptingContext, (void **)&spContext);
	if(FAILED(hr))
		return hr;

	// Get Request Object Pointer
	hr = spContext->get_Request(&m_piRequest);
	if(FAILED(hr))
	{
		spContext.Release();
		return hr;
	}

	// Get Response Object Pointer
	hr = spContext->get_Response(&m_piResponse);
	if(FAILED(hr))
	{
		m_piRequest.Release();
		return hr;
	}
	
	// Get Server Object Pointer
	hr = spContext->get_Server(&m_piServer);
	if(FAILED(hr))
	{
		m_piRequest.Release();
		m_piResponse.Release();
		return hr;
	}
	
	// Get Session Object Pointer
	hr = spContext->get_Session(&m_piSession);
	if(FAILED(hr))
	{
		m_piRequest.Release();
		m_piResponse.Release();
		m_piServer.Release();
		return hr;
	}

	// Get Application Object Pointer
	hr = spContext->get_Application(&m_piApplication);
	if(FAILED(hr))
	{
		m_piRequest.Release();
		m_piResponse.Release();
		m_piServer.Release();
		m_piSession.Release();
		return hr;
	}

	CComPtr<IDispatch> piPathInfo;
	hr = m_piRequest->get_Item( L"PATH_INFO", &piPathInfo );
	if ( !FAILED(hr) )
	{
		CComVariant vt = piPathInfo;
		hr = vt.ChangeType( VT_BSTR );
		if ( !FAILED( hr ) )
		{
			m_strPage = OLE2T(vt.bstrVal);
		}
	}
	m_bOnStartPageCalled = TRUE;
	return S_OK;
}

STDMETHODIMP CNextLink::OnEndPage ()  
{
	m_bOnStartPageCalled = FALSE;
	m_strPage = _T("");

	// Release all interfaces
	m_piRequest.Release();
	m_piResponse.Release();
	m_piServer.Release();
	m_piSession.Release();
	m_piApplication.Release();

	return S_OK;
}

#endif

STDMETHODIMP CNextLink::get_GetNextURL(BSTR bstrLinkFile, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr    pLinkFile;
        tstring         strPage;
		if ( GetFileAndPage( bstrLinkFile, pLinkFile, strPage ) )
		{
            CLock l( *pLinkFile );
			CLinkPtr pLink = pLinkFile->NextLink( strPage );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Link().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}
	return rc;
}

STDMETHODIMP CNextLink::get_GetNextDescription(BSTR bstrLinkFile, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr    pLinkFile;
        tstring         strPage;
        if ( GetFileAndPage( bstrLinkFile, pLinkFile, strPage ) )
		{
            CLock l(*pLinkFile);
			CLinkPtr pLink = pLinkFile->NextLink( strPage );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Desc().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}
	return rc;
}

STDMETHODIMP CNextLink::get_GetPreviousURL(BSTR bstrLinkFile, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr    pLinkFile;
        tstring         strPage;
        if ( GetFileAndPage( bstrLinkFile, pLinkFile, strPage ) )
		{
            CLock l(*pLinkFile);
			CLinkPtr pLink = pLinkFile->PreviousLink( strPage );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Link().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}

STDMETHODIMP CNextLink::get_GetPreviousDescription(BSTR bstrLinkFile, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr    pLinkFile;
        tstring         strPage;
        if ( GetFileAndPage( bstrLinkFile, pLinkFile, strPage ) )
		{
            CLock l( *pLinkFile );
			CLinkPtr pLink = pLinkFile->PreviousLink( strPage );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Desc().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}

STDMETHODIMP CNextLink::get_GetNthURL(BSTR bstrLinkFile, int nIndex, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr pLinkFile = LinkFile( bstrLinkFile );
		if ( pLinkFile.IsValid() )
		{
            CLock l(*pLinkFile);
			CLinkPtr pLink = pLinkFile->Link( nIndex );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Link().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}

STDMETHODIMP CNextLink::get_GetNthDescription(BSTR bstrLinkFile, int nIndex, BSTR * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CComBSTR bstrLink;
		bstrLink.Attach( *pVal );

		CLinkFilePtr pLinkFile = LinkFile( bstrLinkFile );
		if ( pLinkFile.IsValid() )
		{
            CLock l(*pLinkFile);
			CLinkPtr pLink = pLinkFile->Link( nIndex );
			if ( pLink.IsValid() )
			{
				bstrLink = T2BSTR( pLink->Desc().c_str() );
				rc = S_OK;
			}
		}

		*pVal = bstrLink.Detach();
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}

STDMETHODIMP CNextLink::get_GetListCount(BSTR bstrLinkFile, int * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CLinkFilePtr pLinkFile = LinkFile( bstrLinkFile );
		if ( pLinkFile.IsValid() )
		{
            CLock l(*pLinkFile);
			*pVal = pLinkFile->NumLinks();
			rc = S_OK;
		}
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}


STDMETHODIMP CNextLink::get_GetListIndex(BSTR bstrLinkFile, int * pVal)
{
	SCODE rc = E_FAIL;

	try
	{
		CLinkFilePtr    pLinkFile;
        tstring         strPage;
        if ( GetFileAndPage( bstrLinkFile, pLinkFile, strPage ) )
		{
            CLock l(*pLinkFile);
			*pVal = pLinkFile->LinkIndex( strPage );
			rc = S_OK;
		}
	}
	catch ( ... )
	{
		ATLTRACE( _T("Unknown error\n") );
	}

	return rc;
}

STDMETHODIMP CNextLink::get_About(BSTR * pVal)
{
	USES_CONVERSION;

#ifdef _DEBUG
	LPCTSTR	szVersion = _T("Debug");
#else
	LPCTSTR	szVersion = _T("Release");
#endif
	const int kAboutSize = 1024;
	_TCHAR	szAboutFmt[kAboutSize];
	_TCHAR	szBuffer[ kAboutSize + sizeof(__DATE__) + sizeof(__TIME__) + sizeof(szVersion) ];
	
	CComBSTR bstrAbout;
	bstrAbout.Attach( *pVal );

	::LoadString( _Module.GetResourceInstance(), IDS_ABOUT_FMT, szAboutFmt, kAboutSize );
	_stprintf(szBuffer, szAboutFmt, szVersion, __DATE__, __TIME__);

	bstrAbout = T2BSTR( szBuffer );

	*pVal = bstrAbout.Detach();

	return S_OK;
}

IGetContextProperties*
CNextLink::GetContextProperties()
{
    IGetContextProperties* pCxtProps = NULL;

    CComPtr<IObjectContext> pObjContext;

    if ( !FAILED( ::GetObjectContext( &pObjContext ) ) )
    {
        pObjContext->QueryInterface( IID_IGetContextProperties, (void**)&pCxtProps );
    }
    return pCxtProps;
}

IRequest*
CNextLink::GetRequest(
    CComPtr<IGetContextProperties>& pProps )
{
    static const CComBSTR bstrRequest = "Request";
    IRequest* pRequest = NULL;

    if ( pProps != NULL )
    {
        CComVariant vt;
        if ( !FAILED( pProps->GetProperty( bstrRequest, &vt ) ) )
        {
            if ( V_VT(&vt) == VT_DISPATCH )
            {
                IDispatch* pDispatch = V_DISPATCH(&vt);
                if ( pDispatch )
                {
                    pDispatch->QueryInterface( IID_IRequest, (void**)&pRequest );
                }
            }
        }
        else
        {
            ATLTRACE( _T("Couldn't get request property\n") );
        }
    }
    return pRequest;
}

IServer*
CNextLink::GetServer(
    CComPtr<IGetContextProperties>& pProps )
{
    static const CComBSTR bstrServer = "Server";
    IServer* pServer = NULL;

    if ( pProps != NULL )
    {
        CComVariant vt;
        if ( !FAILED( pProps->GetProperty( bstrServer, &vt ) ) )
        {
            if ( V_VT(&vt) == VT_DISPATCH )
            {
                IDispatch* pDispatch = V_DISPATCH(&vt);
                if ( pDispatch )
                {
                    pDispatch->QueryInterface( IID_IServer, (void**)&pServer );
                }
            }
        }
        else
        {
            ATLTRACE( _T("Couldn't get server property\n") );
        }
    }
    return pServer;
}

bool
CNextLink::GetPage(
    CComPtr<IRequest>&  pRequest,
    tstring&            strPage )
{
    USES_CONVERSION;

    bool rc = false;
    if ( pRequest != NULL )
    {
	    CComPtr<IDispatch> piPathInfo;
	    HRESULT hr = pRequest->get_Item( L"PATH_INFO", &piPathInfo );
	    if ( !FAILED(hr) )
	    {
		    CComVariant vt = piPathInfo;
		    hr = vt.ChangeType( VT_BSTR );
		    if ( !FAILED( hr ) )
		    {
			    strPage = OLE2T(vt.bstrVal);
                rc = true;
		    }
	    }
    }
    return rc;
}

CLinkFilePtr
CNextLink::LinkFile(
	BSTR                bstrFile,
    CComPtr<IServer>&   pServer )
{
	USES_CONVERSION;
	
	CLinkFilePtr pLinkFile;

    if ( pServer != NULL )
    {
	    BSTR bstrPath = SysAllocString(L"");
	    HRESULT hr = pServer->MapPath( bstrFile, &bstrPath );
	    if ( !FAILED( hr ) )
	    {
		    CLock l( s_linkFileMap );
		    tstring strFile = OLE2T(bstrPath);
		    CLinkFilePtr& rpLinkFile = s_linkFileMap[strFile];
		    if ( !rpLinkFile.IsValid() )
		    {
			    rpLinkFile = new CLinkFile( strFile );
		    }
            else
            {
                // make sure the file is up to date
                CLock l( *rpLinkFile );
                rpLinkFile->Refresh();
            }
		    pLinkFile = rpLinkFile;
	    }
    }
	return pLinkFile;
}

CLinkFilePtr
CNextLink::LinkFile(
	BSTR    bstrFile )
{
    CLinkFilePtr pLinkFile;

    CComPtr<IGetContextProperties> pProps = GetContextProperties();
    if ( pProps != NULL )
    {
        CComPtr<IServer> pServer = GetServer( pProps );
        if ( pServer != NULL )
        {
            pLinkFile = LinkFile( bstrFile, pServer );
        }
    }
    return pLinkFile;
}

bool
CNextLink::GetFileAndPage(
    BSTR            bstrFile,
    CLinkFilePtr&   pLinkFile,
    tstring&        strPage )
{
    bool rc = false;

    CComPtr<IGetContextProperties> pProps = GetContextProperties();
    if ( pProps != NULL )
    {
        CComPtr<IServer> pServer = GetServer( pProps );
        if ( pServer != NULL )
        {
            pLinkFile = LinkFile( bstrFile, pServer );

            if ( pLinkFile.IsValid() )
            {
                // now continue on to get the page
                CComPtr<IRequest> pRequest = GetRequest( pProps );
                if ( pRequest != NULL )
                {
                    rc = GetPage( pRequest, strPage );
                }
            }
        }
    }

    return rc;
}
