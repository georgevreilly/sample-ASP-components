// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__A0B6D564_2F7D_11D1_8AF8_00C0F00910F9__INCLUDED_)
#define AFX_STDAFX_H__A0B6D564_2F7D_11D1_8AF8_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define STRICT


#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED

#pragma warning( disable : 4786 )

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

#include <mtx.h>
#include <asptlb.h>
#include <comdef.h>

#include <algorithm>
#include <map>
using namespace std;

#include "mydebug.h"
#include "mystring.h"
#include "myvector.h"


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A0B6D564_2F7D_11D1_8AF8_00C0F00910F9__INCLUDED)
