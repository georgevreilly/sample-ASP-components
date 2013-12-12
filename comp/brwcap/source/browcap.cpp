// BrowCap.cpp : Implementation of CBrowserCap
#include "stdafx.h"
#include "BrwCap.h"
#include "BrowCap.h"
#include "CapMap.h"

static const DISPID FIRST_DYNAMIC_DISPID = 10000;

/////////////////////////////////////////////////////////////////////////////
// CBrowserCap

CBrowserCap::CBrowserCap()
{
    if ( _Module.CapMap() )
    {
        _Module.CapMap()->StartMonitor();
    }
}

CBrowserCap::~CBrowserCap()
{
    if ( _Module.CapMap() )
    {
        _Module.CapMap()->StopMonitor();
    }
}

STDMETHODIMP CBrowserCap::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IBrowserCap,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP
CBrowserCap::Invoke(
    DISPID      dispidMember,
    REFIID      riid,
    LCID        lcid,
    WORD        wFlags,
    DISPPARAMS* pdispparams,
    VARIANT*    pvarResult,
    EXCEPINFO*  pexcepinfo,
    UINT*       puArgErr )
{
    USES_CONVERSION;
    HRESULT rc;

    if ( dispidMember >= FIRST_DYNAMIC_DISPID )
    {
        UINT idx = dispidMember - FIRST_DYNAMIC_DISPID;
        CLock l(m_dispList);
        if ( idx < m_dispList.size() )
        {
            // invoke stuff here
            DISPPARAMS dp;
            VARIANT vt;
            ::VariantClear( &vt );
            vt.vt = VT_BSTR;
            vt.bstrVal = T2BSTR( m_dispList[ idx ].c_str() );
            dp.rgvarg = &vt;
            dp.cArgs = 1;
            dp.cNamedArgs = 0;
            dp.rgdispidNamedArgs = 0;
            
            rc = IDispatchImpl<IBrowserCap, &IID_IBrowserCap, &LIBID_BRWCAPLib>::Invoke(
                DISPID_VALUE,
                riid,
                lcid,
                wFlags,
                &dp,
                pvarResult,
                pexcepinfo,
                puArgErr );
            ::VariantClear( &vt );
        }
        else
        {
            rc = E_FAIL;
        }
    }
    else
    {
        rc = IDispatchImpl<IBrowserCap, &IID_IBrowserCap, &LIBID_BRWCAPLib>::Invoke(
            dispidMember,
            riid,
            lcid,
            wFlags,
            pdispparams,
            pvarResult,
            pexcepinfo,
            puArgErr );
    }
    return rc;
}

STDMETHODIMP
CBrowserCap::GetIDsOfNames(
    REFIID      riid,
    LPOLESTR*   rgszNames,
    UINT        cNames,
    LCID        lcid,
    DISPID*     rgdispid )
{
    // first get the disp IDs of the known methods
    HRESULT rc = IDispatchImpl<IBrowserCap, &IID_IBrowserCap, &LIBID_BRWCAPLib>::GetIDsOfNames(
        riid,
        rgszNames,
        cNames,
        lcid,
        rgdispid );
    if ( rc == DISP_E_UNKNOWNNAME )
    {
        // now dynamically generate IDs for any other method
        // this allows a client to say browsercap.Cookies instead of
        // browsercap( "Cookies" )
        rc = S_OK;
        for ( UINT i = 0; i < cNames; i++ )
        {
            if ( rgdispid[ i ] == DISPID_UNKNOWN )
            {
                if ( ( rgdispid[i] = DispatchID( rgszNames[ i ] ) ) != DISPID_UNKNOWN )
                {
                }
                else
                {
                    rc = DISP_E_UNKNOWNNAME;
                }
            }
        }
    }
    return rc;
}

STDMETHODIMP CBrowserCap::get_Value(BSTR bstrName, VARIANT * pVal)
{
	USES_CONVERSION;

	SCODE rc = E_FAIL;

	try
	{
        CComPtr<IRequest> pRequest = GetRequest();
        if ( pRequest != NULL )
        {
            tstring strBrowser;

        	CComPtr<IDispatch> piDispUserAgent;
        	_variant_t			vtUserAgent;

        	HRESULT hr = pRequest->get_Item(L"HTTP_USER_AGENT", &piDispUserAgent);
        	if ( !FAILED( hr ) )
        	{
        		vtUserAgent = piDispUserAgent;
        		vtUserAgent.ChangeType( VT_BSTR );
        	}
	        else
	        {
                ATLTRACE( _T("Couldn't get user agent\n") );
		        vtUserAgent = L"unknown";
	        }

        	strBrowser = OLE2T( static_cast<_bstr_t>(vtUserAgent) );

			_variant_t vt;
			vt.Attach( *pVal );

			vt = _Module.CapMap()->LookUp( strBrowser.c_str(), OLE2T(bstrName) );

			*pVal = vt.Detach();
			rc = S_OK;
		}
	    else
	    {
		    ATLTRACE( _T("Couldn't get request object\n") );
	    }
    }
	catch ( ... )
	{
		ATLTRACE( _T("Unknown exception caught\n") );
	}
	return rc;
}

IRequest*
CBrowserCap::GetRequest()
{
    IRequest* pRequest = NULL;

    CComPtr<IObjectContext> pObjContext;

    if ( !FAILED( ::GetObjectContext( &pObjContext ) ) )
    {
        CComPtr<IGetContextProperties> pProps;
        if ( !FAILED( pObjContext->QueryInterface( IID_IGetContextProperties, (void**)&pProps ) ) )
        {
            CComBSTR bstrRequest = "Request";
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
    }
    return pRequest;
}

DISPID
CBrowserCap::DispatchID(
    LPOLESTR    szName )
{
    USES_CONVERSION;

    static const tstring strOnStartPage = _T("OnStartPage");
    static const tstring strOnEndPage = _T("OnEndPage");

    DISPID dispid = DISPID_UNKNOWN;

    tstring strName = OLE2T( szName );
    if ( ( strName != strOnStartPage ) && ( strName != strOnEndPage ) )
    {
        CLock l( m_dispList );
        TSafeVector<tstring>::iterator iter = find( m_dispList.begin(), m_dispList.end(), strName );
        if ( iter == m_dispList.end() )
        {
            ATLTRACE( _T( "DISPID allocated: %s: %ld\n" ),
                strName.c_str(), m_dispList.size() + FIRST_DYNAMIC_DISPID );
            dispid = FIRST_DYNAMIC_DISPID + m_dispList.size();
            m_dispList.push_back( strName );
        }
        else
        {
            dispid = ( iter - m_dispList.begin() ) + FIRST_DYNAMIC_DISPID;
        }
    }
    return dispid;
}

