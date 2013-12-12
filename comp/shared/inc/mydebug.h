#pragma once
#ifndef _MYDEBUG_H_
#define _MYDEBUG_H_

class alloc_err
{
};

#define THROW_IF_NULL(x) if ( x ) {} else throw alloc_err()

#ifdef _DEBUG
#define THIS_FILE __FILE__
#define DEBUG_NEW	new(THIS_FILE, __LINE__)
#define DEBUG_START		DebugStart()
#define DEBUG_STOP		DebugStop()

void* __cdecl operator new( size_t s, const char* file, long line ) _THROW1(alloc_err);
void	DebugStart();
void	DebugStop();

#else
#define DEBUG_NEW	new
#define	DEBUG_START
#define	DEBUG_STOP
#endif


#endif
