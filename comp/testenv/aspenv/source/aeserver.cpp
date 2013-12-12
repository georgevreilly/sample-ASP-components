// AeServer.cpp : Implementation of CAeServer
#include "stdafx.h"
#include "AspEnv.h"
#include "AeServer.h"

/////////////////////////////////////////////////////////////////////////////
// CAeServer
CIniFile	CAeServer::s_iniFile;

void
CAeServer::InitializeClass()
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

CAeServer::CAeServer()
	:	m_bstrMapPathBase(L"")
{
}

STDMETHODIMP CAeServer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAeServer,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// IServer methods
STDMETHODIMP
CAeServer::get_ScriptTimeout(
	long FAR*	plTimeoutSeconds )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeServer::put_ScriptTimeout(
	long lTimeoutSeconds )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeServer::CreateObject(
	BSTR				bstrProgID,
	IDispatch * FAR*	ppDispObject )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeServer::HTMLEncode(
	BSTR		bstrIn,
	BSTR FAR*	pbstrEncoded )
{
	return E_NOTIMPL;
}

STDMETHODIMP
CAeServer::MapPath(
	BSTR		bstrLogicalPath,
	BSTR FAR*	pbstrPhysicalPath )
{
	HRESULT rc = E_FAIL;

	try
	{
		if ( pbstrPhysicalPath != NULL )
		{
			if ( m_bstrMapPathBase == _bstr_t(L"") )
			{
				String strMapPathBase = s_iniFile.GetString( "Server", "MapPathBase" );
				if ( strMapPathBase.find_last_of( _T('\\') ) != (strMapPathBase.length()-1) )
				{
					// last char isn't a whack, append it
					strMapPathBase = strMapPathBase + _T('\\');
				}
				m_bstrMapPathBase = strMapPathBase.c_str();
			}
			_bstr_t bstrRet = m_bstrMapPathBase + bstrLogicalPath;
			*pbstrPhysicalPath = bstrRet.copy();
			rc = S_OK;
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
CAeServer::URLEncode(
	BSTR		bstrIn,
	BSTR FAR*	pbstrEncoded )
{
	return E_NOTIMPL;
}

