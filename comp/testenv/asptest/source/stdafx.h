// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__DFBE270D_304A_11D1_8AFA_00C0F00910F9__INCLUDED_)
#define AFX_STDAFX_H__DFBE270D_304A_11D1_8AFA_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT 0x0400	// need for CoInitalizeEx

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC OLE automation classes
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <comdef.h>
#include <malloc.h>
#include <vector>
using namespace std;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__DFBE270D_304A_11D1_8AFA_00C0F00910F9__INCLUDED_)
