// AeObjectContext.cpp : Implementation of CAeObjectContext
#include "stdafx.h"
#include "AspEnv.h"
#include "AeObjectContext.h"
#include "AeServer.h"
#include "AeResponse.h"
#include "AeRequest.h"

extern "C"
{

HRESULT __cdecl GetObjectContext(
	IObjectContext**	ppInstanceContext )
{
#if 1
	HRESULT rc = E_FAIL;
	if ( ppInstanceContext )
	{
		CComObject<CAeObjectContext>* pObjCxt;
		rc = CComObject<CAeObjectContext>::CreateInstance( &pObjCxt );
		if ( SUCCEEDED( rc ) )
		{
			rc = pObjCxt->QueryInterface( IID_IObjectContext, (void**)ppInstanceContext );
		}
		else
		{
			*ppInstanceContext = NULL;
		}
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
#else
	HRESULT rc = _Module.GetClassObject(
		CLSID_AeObjectContext,
		IID_IObjectContext,
		(void**)ppInstanceContext );
	return rc;
#endif
}

}
/////////////////////////////////////////////////////////////////////////////
// CAeObjectContext
void
CAeObjectContext::InitializeClass()
{
}

CAeObjectContext::CAeObjectContext()
{
	CComObject<CAeServer>* pAeServer;
	if ( SUCCEEDED( CComObject<CAeServer>::CreateInstance( &pAeServer ) ) )
	{
		IServer* pServer;
		if ( SUCCEEDED ( pAeServer->QueryInterface( IID_IServer, (void**)(&pServer) ) ) )
		{
			m_pServer.Attach( pServer );
		}
	}

	CComObject<CAeResponse>* pAeResponse;
	if ( SUCCEEDED( CComObject<CAeResponse>::CreateInstance( &pAeResponse ) ) )
	{
		IResponse* pResponse;
		if ( SUCCEEDED ( pAeResponse->QueryInterface( IID_IResponse, (void**)(&pResponse) ) ) )
		{
			m_pResponse.Attach( pResponse );
		}
	}

	CComObject<CAeRequest>* pAeRequest;
	if ( SUCCEEDED( CComObject<CAeRequest>::CreateInstance( &pAeRequest ) ) )
	{
		IRequest* pRequest;
		if ( SUCCEEDED ( pAeRequest->QueryInterface( IID_IRequest, (void**)(&pRequest) ) ) )
		{
			m_pRequest.Attach( pRequest );
		}
	}


#if 0
	if ( !FAILED( m_pServer.CreateInstance( CLSID_AeServer ) ) )
	{
	}
	else
	{
		ATLTRACE( _T("Couldn't create server object\n") );
	}

	if ( !FAILED( m_pResponse.CreateInstance( CLSID_AeResponse ) ) )
	{
	}
	else
	{
		ATLTRACE( _T("Couldn't create response object\n") );
	}
#endif
}

STDMETHODIMP CAeObjectContext::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAeObjectContext,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// IObjectContext - note, none of these are implemented
STDMETHODIMP
CAeObjectContext::CreateInstance( 
	/* [in] */ REFCLSID,
	/* [in] */ REFIID,
	/* [retval][iid_is][out] */ LPVOID __RPC_FAR * )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeObjectContext::SetComplete()
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeObjectContext::SetAbort()
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeObjectContext::EnableCommit()
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeObjectContext::DisableCommit()
{
	return E_NOTIMPL;
}

STDMETHODIMP_(BOOL)
CAeObjectContext::IsInTransaction()
{
	return FALSE;
}

STDMETHODIMP_(BOOL)
CAeObjectContext::IsSecurityEnabled()
{
	return FALSE;
}

STDMETHODIMP
CAeObjectContext::IsCallerInRole( 
	/* [in] */ BSTR,
	/* [retval][out] */ BOOL __RPC_FAR *)
{
	return E_NOTIMPL;
}

// IGetContextProperties - note only GetProperty is implemented
STDMETHODIMP
CAeObjectContext::Count(
	/* [retval][out] */ long __RPC_FAR * )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeObjectContext::GetProperty( 
	/* [in] */ BSTR name,
	/* [retval][out] */ VARIANT *pProperty)
{
	HRESULT rc = E_FAIL;

	if ( pProperty )
	{
		pProperty->vt = VT_DISPATCH;
		V_DISPATCH(pProperty) = NULL;
		if ( ( wcsicmp( name, L"server" ) == 0 ) &&
			( m_pServer != NULL ) )
		{
			m_pServer.AddRef();
			V_DISPATCH(pProperty) = m_pServer;
			rc = S_OK;
		}
		else if ( ( wcsicmp( name, L"response" ) == 0 ) &&
			( m_pResponse != NULL ) )
		{
			m_pResponse.AddRef();
			V_DISPATCH(pProperty) = m_pResponse;
			rc = S_OK;
		}
		else if ( ( wcsicmp( name, L"request" ) == 0 ) &&
			( m_pRequest != NULL ) )
		{
			m_pRequest.AddRef();
			V_DISPATCH( pProperty ) = m_pRequest;
			rc = S_OK;
		}
		else
		{
			ATLTRACE( _T("Property not found\n") );
		}
	}
	else
	{
		rc = E_POINTER;
	}

	return rc;
}

STDMETHODIMP
CAeObjectContext::EnumNames(
	/* [retval][out] */ IEnumNames __RPC_FAR *__RPC_FAR *ppenum)
{
	return E_NOTIMPL;
}
