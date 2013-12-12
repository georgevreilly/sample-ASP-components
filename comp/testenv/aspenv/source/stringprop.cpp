// StringProp.cpp : Implementation of CStringProp
#include "stdafx.h"
#include "AspEnv.h"
#include "StringProp.h"

/////////////////////////////////////////////////////////////////////////////
// CStringProp

STDMETHODIMP CStringProp::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IStringProp,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CStringProp::CStringProp()
	:	m_bstr( L"(none)" )
{
}

STDMETHODIMP CStringProp::get_Value(BSTR * pVal)
{
	HRESULT rc = S_OK;
	if ( pVal )
	{
		*pVal = m_bstr.copy();
	}
	else
	{
		rc = E_POINTER;
	}
	return S_OK;
}

void
CStringProp::SetValue(
	BSTR	bstr )
{
	m_bstr = bstr;
}

void
CStringProp::SetValue(
	LPCTSTR	sz )
{
	m_bstr = sz;
}
