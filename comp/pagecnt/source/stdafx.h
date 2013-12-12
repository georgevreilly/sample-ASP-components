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
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CMonitor;
class CPgCntModule : public CComModule
{
public:
                CPgCntModule();

    // CComModule methods
    LONG        Lock();
    LONG        Unlock();

    // CPgCntModule methods
    CMonitor*   Monitor();

private:
    CComAutoCriticalSection m_cs;
    CMonitor*               m_pMonitor;
};

extern CPgCntModule _Module;
#include <atlcom.h>
#include <mtx.h>

#include <algorithm>
using namespace std;

#include <vector>
#include <string>
#include "mydebug.h"

typedef basic_string<_TCHAR> tstring;

#define ARRAYSIZE(a)	(sizeof(a)/sizeof(*(a)))

#endif  // !_STDAFX_H_

