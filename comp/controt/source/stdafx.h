// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma once
#ifndef _STDAFX_H_
#define _STDAFX_H_

#define STRICT
#define WIN32_EXTRA_LEAN
#define _WIN32_WINNT 0x400 // needed for MB_SERVICE_NOTIFICATION
#include <windows.h>
#include <atlbase.h>
#include <mtx.h>

//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CContRotModule : public CComModule
{
public:
	LONG	Lock();
	LONG	Unlock();

private:
	CComAutoCriticalSection	m_cs;
};

extern CContRotModule _Module;

#include <algorithm>
using namespace std;

#include <atlcom.h>
#include <string>
#include <vector>
#include "mydebug.h"

typedef basic_string<_TCHAR> tstring;

#define ARRAYSIZE(a)	(sizeof(a)/sizeof(*(a)))

#endif	// !_STDAFX_H_
