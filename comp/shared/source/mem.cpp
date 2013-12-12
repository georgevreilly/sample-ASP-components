/*++

   Copyright    (c)    1997    Microsoft Corporation

   Module  Name :

       mem.cpp

   Abstract:
		A new and delete operator that will throw excecptions

   Author:

       Neil Allain    ( a-neilal )     August-1997 

   Revision History:

--*/

#include "stdafx.h"

#ifdef _DEBUG
#include "mydebug.h"

static CRITICAL_SECTION s_cs;
static bool s_bDebugStarted = false;
static long s_lNumBlocks = 0;

struct CLock
{
	CLock( CRITICAL_SECTION& cs )
		:	m_rcs( cs )
	{
		if ( s_bDebugStarted )
		{
			::EnterCriticalSection( &m_rcs );
		}
	}
	~CLock()
	{
		if ( s_bDebugStarted )
		{
			::LeaveCriticalSection( &m_rcs );
		}
	}
	CRITICAL_SECTION&	m_rcs;
};


struct MemHeader
{
	size_t		size;
	const char*	szFile;
	long		lLine;
	MemHeader*	pNext;
	MemHeader*	pPrev;
};

static MemHeader* s_pAllocatedMem = NULL;

static void DumpBlocks();

void
DumpBlocks()
{
	CLock l(s_cs);
	ATLTRACE( _T("%d blocks not freed\n"), s_lNumBlocks );
	MemHeader* pmh = s_pAllocatedMem;
	while ( pmh != NULL )
	{
		if ( pmh->szFile )
		{
			ATLTRACE( _T("Mem block: %s:%d size: %d\n"), pmh->szFile, pmh->lLine, pmh->size );
		}
		else
		{
			ATLTRACE( _T("Mem block: size: %d\n"), pmh->size );
		}
		pmh = pmh->pNext;
	}
}

void
DebugStart()
{
	::InitializeCriticalSection( &s_cs );
	s_bDebugStarted = true;
}

void
DebugStop()
{
	DumpBlocks();
	::DeleteCriticalSection( &s_cs );
	s_bDebugStarted = false;
}


void* __cdecl operator new( size_t s, const char* file, long line ) _THROW1(alloc_err)
{
	BYTE* p = reinterpret_cast<BYTE*>(malloc( s + sizeof( MemHeader ) ));
	if ( p )
	{
        InterlockedIncrement( &s_lNumBlocks );
		MemHeader* pmh = reinterpret_cast<MemHeader*>(p);
		pmh->size = s;
		pmh->szFile = file;
		pmh->lLine = line;
		CLock l(s_cs);
		pmh->pNext = s_pAllocatedMem;
		if ( s_pAllocatedMem )
		{
			s_pAllocatedMem->pPrev = pmh;
		}
		s_pAllocatedMem = pmh;
	}
	else
	{
		throw alloc_err();
	}

	return ( p + sizeof( MemHeader ) );
}

void *__cdecl operator new(size_t s) _THROW1(alloc_err)
{
	BYTE* p = reinterpret_cast<BYTE*>(malloc( s + sizeof( MemHeader ) ));
	if ( p )
	{
        InterlockedIncrement( &s_lNumBlocks );
		MemHeader* pmh = reinterpret_cast<MemHeader*>(p);
		pmh->size = s;
		pmh->szFile = NULL;
		pmh->lLine = 0;
		pmh->pPrev = NULL;
		CLock l(s_cs);
		pmh->pNext = s_pAllocatedMem;
		if ( s_pAllocatedMem )
		{
			s_pAllocatedMem->pPrev = pmh;
		}
		s_pAllocatedMem = pmh;
	}
	else
	{
		throw alloc_err();
	}
	return ( p + sizeof( MemHeader ) );
}

void __cdecl operator delete(void *p) _THROW0()
{
	if ( p )
	{
		BYTE* pb = reinterpret_cast<BYTE*>(p);
		MemHeader* pmh = reinterpret_cast<MemHeader*>(pb - sizeof( MemHeader ) );

		CLock l(s_cs);
		// sanity check--make sure it exists in the list of memory blocks
		MemHeader* pcur = s_pAllocatedMem;
		while ( ( pcur != NULL ) && ( pcur != pmh ) )
		{
			pcur = pcur->pNext;
		}
		if ( pcur )
		{
			// found it--remove it
			if ( pcur == s_pAllocatedMem )
			{
				s_pAllocatedMem = pcur->pNext;
				if ( s_pAllocatedMem )
				{
					s_pAllocatedMem->pPrev = NULL;
				}
			}
			else
			{
				_ASSERT( pcur->pPrev );
				pcur->pPrev->pNext = pcur->pNext;
				if ( pcur->pNext )
				{
					pcur->pNext->pPrev = pcur->pPrev;
				}
			}
            InterlockedDecrement( &s_lNumBlocks );
			if ( s_bDebugStarted )
			{
			}
			else
			{
				if ( pcur->szFile )
				{
					ATLTRACE( _T("Releasing: %s:%d, size: %d\n"), pcur->szFile, pcur->lLine, pcur->size );
				}
				else
				{
					ATLTRACE( _T("Releasing: size: %d\n"), pmh->size );
				}
				ATLTRACE( _T("%d Blocks not freed\n"), s_lNumBlocks );
			}
			// free it
			free( pcur );
		}
		else
		{
			// wasn't allocated here!
			_ASSERT(0);
			free( pb );
		}
	}
}

#else

// release memory management
void __cdecl operator delete(void *p) _THROW0()
{
	if ( p )
	{
		free( p );
	}
}

void *__cdecl operator new(size_t s) _THROW1(alloc_err)
{
	void* p = malloc( s );
	if ( p )
	{
	}
	else
	{
		throw alloc_err();
	}
	return p;
}
#endif
