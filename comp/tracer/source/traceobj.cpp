// TraceObj.cpp : Implementation of CTracer
#include "stdafx.h"
#include "Tracer.h"
#include "TraceObj.h"

/////////////////////////////////////////////////////////////////////////////
// CTracer

CTracer::CTracer()
	:	m_szName( NULL )
{
	::timeBeginPeriod(1);
	::GetLocalTime( &m_st );
	m_dwTimeStart = ::timeGetTime();
	m_dwTimeSplit = 0;
}

CTracer::~CTracer()
{
	delete m_szName;
	::timeEndPeriod(1);
}

STDMETHODIMP CTracer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITracer,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CTracer::get_Name(BSTR * pVal)
{
	HRESULT rc = E_FAIL;

	if ( pVal )
	{
		USES_CONVERSION;
		if ( *pVal )
		{
			::SysFreeString( *pVal );
		}
		*pVal = T2BSTR( m_szName );
		if ( *pVal != NULL )
		{
			rc = S_OK;
		}
		else
		{
			rc = E_OUTOFMEMORY;
		}
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

STDMETHODIMP CTracer::put_Name(BSTR newVal)
{
	HRESULT rc = E_FAIL;

	if ( newVal )
	{
		USES_CONVERSION;

		delete[] m_szName;
		m_szName = NULL;
		LPTSTR szTemp = OLE2T( newVal );
		m_szName = new _TCHAR[ _tcslen( szTemp ) + 1 ];
		if ( m_szName )
		{
			_tcscpy( m_szName, szTemp );
			rc = S_OK;
		}
		else
		{
			rc = E_OUTOFMEMORY;
		}
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

STDMETHODIMP CTracer::TimerStart()
{
	HRESULT rc;
	::GetLocalTime( &m_st );
	m_dwTimeStart = ::timeGetTime();
	m_dwTimeSplit = 0;
	rc = WriteLine( m_st, _T("Timer Start") );

	return rc;
}

STDMETHODIMP CTracer::TimerStop()
{
	HRESULT rc;

	DWORD dwNewMark = ::timeGetTime() - m_dwTimeStart;
	SYSTEMTIME st;
	UpdateTime( st, dwNewMark );

	rc = WriteTime( st, _T("Timer Stop"), dwNewMark );

	return rc;
}

STDMETHODIMP CTracer::TimerTotal(BSTR bstrLabel)
{
	HRESULT rc;

	DWORD dwNewMark = ::timeGetTime() - m_dwTimeStart;
	SYSTEMTIME st;
	UpdateTime( st, dwNewMark );

	if ( bstrLabel )
	{
		USES_CONVERSION;
		LPCTSTR szLabel = OLE2T( bstrLabel );
		rc = WriteTime( st, szLabel, dwNewMark );
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

STDMETHODIMP CTracer::TimerSplit(BSTR bstrLabel)
{
	HRESULT rc;

	DWORD dwNewMark = ::timeGetTime() - m_dwTimeStart;
	SYSTEMTIME st;
	UpdateTime( st, dwNewMark );

	if ( bstrLabel )
	{
		USES_CONVERSION;
		LPCTSTR szLabel = OLE2T( bstrLabel );
		rc = WriteTime( st, szLabel, dwNewMark - m_dwTimeSplit );
		m_dwTimeSplit = dwNewMark;
	}
	else
	{
		rc = E_POINTER;
	}

	return rc;
}

STDMETHODIMP CTracer::Trace(BSTR bstrTrace)
{
	DWORD dwNewMark = ::timeGetTime() - m_dwTimeStart;
	SYSTEMTIME st;
	UpdateTime( st, dwNewMark );

	HRESULT rc = E_FAIL;
	if ( bstrTrace )
	{
		USES_CONVERSION;
		LPCTSTR szTrace = OLE2T( bstrTrace );
		rc = WriteLine( st, szTrace );
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

// helper methods

//---------------------------------------------------------------------------
//
//	WriteLine
//
//	Write out a line (to the debug window) containing the timer name, the
//	time of day, and the given string
//
//---------------------------------------------------------------------------
HRESULT
CTracer::WriteLine(
	SYSTEMTIME&	rst,
	LPCTSTR		pStr )
{
	HRESULT rc = E_FAIL;

	if ( pStr )
	{
		if ( m_szName )
		{
			const int kBufferSize = 1024;
			_TCHAR szBuffer[kBufferSize];
			_tcscpy( szBuffer, m_szName );
			_tcscat( szBuffer, _T(", ") );
			int len = _tcslen( szBuffer );
			LPTSTR pEnd = szBuffer + len;
			::GetTimeFormat(
				LOCALE_SYSTEM_DEFAULT,
				0,
				&rst,
				_T("HH':'mm':'ss"),
				pEnd,
				kBufferSize - len );

			// now tack on the number of milliseconds
			_TCHAR szMS[15];
			::wsprintf( szMS, _T(".%4.4d, "), rst.wMilliseconds );
			_tcscat( szBuffer, szMS );

			// now tack on the desired trace and newline
			_tcscat( szBuffer, pStr );
			_tcscat( szBuffer, _T("\n") );

			// now output it
			::OutputDebugString( szBuffer );
			rc = S_OK;
		}
		else
		{
			rc = E_OUTOFMEMORY;
		}

	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

//---------------------------------------------------------------------------
//
//	WriteTime
//
//	Ouput a line with a label and a given number of msec
//
//---------------------------------------------------------------------------
HRESULT
CTracer::WriteTime(
	SYSTEMTIME&	rst,
	LPCTSTR		pStr,
	DWORD		dwTime )
{
	HRESULT rc = E_FAIL;
	if ( pStr )
	{
		int len = _tcslen( pStr ) + 40;
		LPTSTR szTime = (LPTSTR)_alloca( sizeof( _TCHAR ) * len );
		if ( szTime )
		{
			// change the time to sec.msec
			DWORD dwSec = 0;
			while ( dwTime >= 1000 )
			{
				++dwSec;
				dwTime -= 1000;
			}
			::wsprintf( szTime, _T("%s, %d.%4.4d sec"), pStr, dwSec, dwTime );
			rc = WriteLine( rst, szTime );
		}
		else
		{
			rc = E_OUTOFMEMORY;
		}
	}
	else
	{
		rc = E_POINTER;
	}
	return rc;
}

//---------------------------------------------------------------------------
//
//	UpdateTime
//
//	Update the system time struct by the given number of milliseconds.  This
//	method of updating time is bound to drift from the true time, but this
//	drift shouldn't be noticable over the duration that the timer is
//	typically used.
//
//---------------------------------------------------------------------------
void
CTracer::UpdateTime(
	SYSTEMTIME&	rst,
	DWORD		dwms )
{
	const DWORD kHourMS = 60 /*min*/ * 60 /*sec*/ * 1000 /*msec*/;
	const DWORD kMinMS = 60 /*sec*/ * 1000 /*msec*/;
	const DWORD kSecMS = 1000 /*msec*/;
	
	rst = m_st;
	while ( dwms >= kHourMS )
	{
		dwms -= kHourMS;
		IncHour(rst);
	}

	while ( dwms >= kMinMS )
	{
		dwms -= kMinMS;
		IncMinute(rst);
	}

	while ( dwms >= kSecMS )
	{
		dwms -= kSecMS;
		IncSecond(rst);
	}

	rst.wMilliseconds += (WORD)dwms;
	if ( rst.wMilliseconds >= kSecMS )
	{
		rst.wMilliseconds -= kSecMS;
		IncSecond(rst);
	}
}


void
CTracer::IncHour(
	SYSTEMTIME&	rst )
{
	if ( ++rst.wHour < 24 )
	{
	}
	else
	{
		rst.wHour -= 24;
	}
}

void
CTracer::IncMinute(
	SYSTEMTIME&	rst)
{
	if ( ++rst.wMinute < 60 )
	{
	}
	else
	{
		rst.wMinute -= 60;
		IncHour(rst);
	}
}

void
CTracer::IncSecond(
	SYSTEMTIME&	rst )
{
	if ( ++rst.wSecond < 60 )
	{
	}
	else
	{
		rst.wSecond -= 60;
		IncMinute(rst);
	}
}
