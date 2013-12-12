// WorkThread.h: interface for the CWorkThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKTHREAD_H__17562C85_261C_11D1_8AE5_00C0F00910F9__INCLUDED_)
#define AFX_WORKTHREAD_H__17562C85_261C_11D1_8AE5_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Component.h"
//---------------------------------------------------------------------------
//
//	CWorkStatus is an abstract base class.  a work status object is supplied
//	to the work thread upon construction.  The work thread will use it to
//	notify it's owner about changes in it's state.
//
//---------------------------------------------------------------------------
class CWorkStatus
{
public:
	virtual			~CWorkStatus(){};
	virtual	void	Done() = 0;
};

class CWorkThread  
{
public:
	CWorkThread( CComponent&, CWorkStatus*, UINT );
	virtual ~CWorkThread();

	void	Start();
	void	Quit();

private:

	DWORD	DoWork();

	static unsigned __stdcall	ThreadFunc( void* pwt );

	HANDLE			m_hevtBreak;
	HANDLE			m_hThread;
	CComponent		m_cmp;
	CWorkStatus*	m_pWorkStatus;
	UINT			m_uIterations;
};

#endif // !defined(AFX_WORKTHREAD_H__17562C85_261C_11D1_8AE5_00C0F00910F9__INCLUDED_)
