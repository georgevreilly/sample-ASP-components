// SumEnum.h: Definition of the SumInfosEnum class
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUMINFOSENUM_H__BED0D195_9B2F_11D0_A139_080036006703__INCLUDED_)
#define AFX_SUMINFOSENUM_H__BED0D195_9B2F_11D0_A139_080036006703__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "resource.h"       // main symbols
#include "suminfos.h"
/////////////////////////////////////////////////////////////////////////////
// SumInfosEnum

class CSumInfos;

class CSumInfosEnum : 
	public IEnumVARIANT,
	public CComObjectRoot
{
friend class CSumInfos;
public:
    CSumInfosEnum() 
    {         
        InitializeCriticalSection(&m_cs);
    }
	~CSumInfosEnum() 
    {
        DeleteCriticalSection(&m_cs);
    }


BEGIN_COM_MAP(CSumInfosEnum)
	COM_INTERFACE_ENTRY(IEnumVARIANT)
END_COM_MAP()

DECLARE_NOT_AGGREGATABLE(CSumInfosEnum) 

// IEnumVARIANT
public:
	STDMETHOD(Next)(ULONG celt, VARIANT* rgelt, ULONG* pceltFetched);
	STDMETHOD(Skip)(ULONG celt);
	STDMETHOD(Reset)(void);
	STDMETHOD(Clone)(IEnumVARIANT** ppEnum);

private:
    CRITICAL_SECTION m_cs;      // Critical section
	CSumInfos* m_pSumInfos;
    long m_nCurItem ;
	BOOL Init(CSumInfos* pSumInfos);
};

#endif // !defined(AFX_SUMINFOSENUM_H__BED0D195_9B2F_11D0_A139_080036006703__INCLUDED_)
