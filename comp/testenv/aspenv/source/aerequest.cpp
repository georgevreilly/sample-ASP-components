// AeRequest.cpp : Implementation of CAeRequest
#include "stdafx.h"
#include "AspEnv.h"
#include "AeRequest.h"


/////////////////////////////////////////////////////////////////////////////
// CAeRequest
CIniFile	CAeRequest::s_iniFile;

void
CAeRequest::InitializeClass()
{
	// get the path to the inifile containing the browser cap info
	_TCHAR szModule[ _MAX_PATH ];
	::GetModuleFileName(_Module.GetModuleInstance(), szModule, sizeof(szModule));

	// remove the filename and tack on the ini file name
	_TCHAR* pch = _tcsrchr(szModule, '\\');
	if (pch == NULL)
	{
		// the path should have at least one backslash
		_ASSERT(0);
		pch = szModule;
	}
	*(pch+1) = _T('\0');

	_tcscat( szModule, _T("AspEnv.ini") );
	s_iniFile.Open( szModule );
}

STDMETHODIMP CAeRequest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRequest,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CAeRequest::CAeRequest()
{
}

// IRequest Methods

//---------------------------------------------------------------------------
//
//	Right now, I know of only one value I'm interested in: the HTTP_USER_AGENT.
//	So, this method is optimized for that, but it can retrieve any value.
//
//----------------------------------------------------------------------------
STDMETHODIMP
CAeRequest::get_Item(
	BSTR		bstrVar,
	IDispatch**	ppObjReturn)
{
	HRESULT rc = E_FAIL;

	try
	{
		if ( ppObjReturn && bstrVar )
		{
			USES_CONVERSION;
			// look it up in the ini file
			LPCTSTR szItem = OLE2T(bstrVar);
			*ppObjReturn = GetItem( szItem );
			if ( *ppObjReturn )
			{
				rc = S_OK;
			}
		}
		else
		{
			rc = E_POINTER;
		}
	}
	catch ( _com_error& ce )
	{
		rc = ce.Error();
	}
	catch ( ... )
	{
		rc = E_FAIL;
	}
	return rc;	
}

STDMETHODIMP
CAeRequest::get_QueryString(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeRequest::get_Form(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeRequest::get_Body(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeRequest::get_ServerVariables(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeRequest::get_ClientCertificate(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeRequest::get_Cookies(
	IRequestDictionary**	ppDictReturn)
{
	return E_NOTIMPL;
}

//---------------------------------------------------------------------------
//
//	Lookup the item in the ini file, and turn it into a dispatch object
//
//---------------------------------------------------------------------------
IDispatch*
CAeRequest::GetItem(
	LPCTSTR	szItem )
{
	IDispatch* pDisp = NULL;

	USES_CONVERSION;

	String strLookUp = _T("Item.");
	strLookUp += szItem;
	String strVal = s_iniFile.GetString( _T("request"), strLookUp.c_str() );
	CComObject<CStringProp>* pProp;
	if ( SUCCEEDED ( CComObject<CStringProp>::CreateInstance( &pProp ) ) )
	{
		pProp->AddRef();
		pProp->SetValue( strVal.c_str() );
	}
	return pProp;
}

