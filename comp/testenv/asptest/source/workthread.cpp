// WorkThread.cpp: implementation of the CWorkThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorkThread.h"
#include <process.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static long s_calls = 0;

CWorkThread::CWorkThread(
	CComponent&		cmp,
	CWorkStatus*	pws,
	UINT			uIterations )
	:	m_cmp( cmp ),
		m_pWorkStatus( pws ),
		m_uIterations( uIterations )
{
	m_hevtBreak = ::CreateEvent(
		NULL,
		TRUE,
		FALSE,
		NULL );
}

CWorkThread::~CWorkThread()
{
	::CloseHandle( m_hevtBreak );
}

void
CWorkThread::Start()
{
	unsigned id;
	m_hThread = (HANDLE)_beginthreadex(
		NULL,
		4096,
		ThreadFunc,
		this,
		0,
		&id );
}

void
CWorkThread::Quit()
{
	::SetEvent( m_hevtBreak );
}

DWORD
CWorkThread::DoWork()
{
	UINT uCurrentIteration = 0;
	bool bDone = false;

	m_cmp.StartTest();

	while ( !bDone )
	{
		if ( ::WaitForSingleObject( m_hevtBreak, 0 ) == WAIT_TIMEOUT )
		{
			m_cmp.Test();
			uCurrentIteration++;
			// zero iterations means to work until told to stop
			if ( ( m_uIterations != 0 ) && ( uCurrentIteration >= m_uIterations ) )
			{
				bDone = true;
			}
		}	
		else
		{
			bDone = true;
		}
//		::Sleep(2);
	}

	m_cmp.EndTest();

	if ( m_pWorkStatus )
	{
		m_pWorkStatus->Done();
	}

	::CloseHandle( m_hThread );
	m_hThread = NULL;
	return 0;
}

unsigned __stdcall
CWorkThread::ThreadFunc(
	void*	pwt )
{
	unsigned rc = 0;
	if ( !FAILED(::CoInitializeEx( NULL, COINIT_MULTITHREADED )) )
	{
		if ( pwt != NULL )
		{
			CWorkThread* p = (CWorkThread*)pwt;
			rc = p->DoWork();
		}
		::CoUninitialize();
	}
	else
	{
		TRACE( "Couldn't init COM\n" );
	}
	return rc;
}

