// SumBase.h: interface for the CSumInfoBase class.
//
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
// This class provides some utility functions that are shared between
// CSumInfo and CSumInfos.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUMINFOBASE_H__92E239FD_B4E8_11D0_A13E_080036006703__INCLUDED_)
#define AFX_SUMINFOBASE_H__92E239FD_B4E8_11D0_A13E_080036006703__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <asptlb.h>         // Active Server Pages Definitions
#include "context.h"

class CSumInfoBase  
{
public:
    enum 
    {
        STYLE_DEFAULT = 0,
        STYLE_FULL,
        STYLE_DEBUG = -1
    };

    CSumInfoBase()
    {
        InitializeCriticalSection(&m_cs);
        m_lStyle = STYLE_DEFAULT; // default
    }

	virtual ~CSumInfoBase()
    {
        DeleteCriticalSection(&m_cs);
    }

protected:
	long m_lStyle;
    CRITICAL_SECTION m_cs;      // Critical section
	void PropVarToVar(VARIANT* pvarOut, PROPVARIANT* pPropVarIn, BOOL fEditTime = FALSE);
	void WriteResponsePropVar(CContext&, PROPVARIANT* pPropVar, BOOL fEditTime = FALSE);
	void WriteResponseString(CContext&, WCHAR* wsz);
	void WriteResponseString(CContext&, CHAR* sz);

};

#endif // !defined(AFX_SUMINFOBASE_H__92E239FD_B4E8_11D0_A13E_080036006703__INCLUDED_)
