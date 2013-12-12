// SumInfosEnum.cpp : Implementation of CSumInfosEnum
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
// This class implements IEnumVARIANT and is used by CSumInfos to
// implement Automation collection support (so For Each...Next) 
// works.
//

#include "stdafx.h"
#include "SumInfo.h"
#include "SumEnum.h"

/////////////////////////////////////////////////////////////////////////////
//
// CSumInfosEnum
//
BOOL CSumInfosEnum::Init(CSumInfos* pSumInfos)
{
    m_pSumInfos = pSumInfos;
    m_nCurItem = 1;
    return TRUE;
}

// IEnumVARIANT members
//
HRESULT CSumInfosEnum::Next(ULONG celt, VARIANT* rgelt, ULONG* pceltFetched)
{
    if (m_pSumInfos == NULL) 
        return ResultFromScode(E_UNEXPECTED);

    HRESULT hr;
    ULONG   l ;


    // pceltFetched can legally == 0
    //                                           
    if (pceltFetched != NULL)
        *pceltFetched = 0;
    else 
        if (celt > 1)
        {   
            return ResultFromScode(E_INVALIDARG);   
        }

    for (l=0; l < celt; l++)
        VariantInit(&rgelt[l]);

    EnterCriticalSection(&m_cs);

    VARIANT vIndex;
    VariantInit(&vIndex);
    vIndex.vt=VT_UI4;
    ISumInfo* pSumInfo;
    // Retrieve the next celt elements.
    for (l = 0 ; m_nCurItem <= m_pSumInfos->m_nFiles && celt != 0 ; l++)
    {   
        celt-- ;
        vIndex.lVal = m_nCurItem++;  // 1 based index
        hr = m_pSumInfos->get_Item(vIndex, &pSumInfo);
        if (FAILED(hr))
        {
            LeaveCriticalSection(&m_cs);
            return hr;
        }

        rgelt[l].vt = VT_DISPATCH;
        pSumInfo->QueryInterface(IID_IDispatch, (void**)&rgelt[l].pdispVal);
        pSumInfo->Release();
        if (pceltFetched != NULL)
            (*pceltFetched)++ ;
    }
    
    if (celt != 0)
    {
        hr = S_FALSE ;
    }
    

    LeaveCriticalSection(&m_cs);
    return hr;
}


HRESULT CSumInfosEnum::Skip(ULONG celt)
{
    if (m_pSumInfos == NULL) 
        return ResultFromScode(E_UNEXPECTED);

    EnterCriticalSection(&m_cs);
    while (m_nCurItem <= m_pSumInfos->m_nFiles && celt--)
        m_nCurItem++ ;
    LeaveCriticalSection(&m_cs);
    
    return (celt == 0 ? S_OK : S_FALSE) ;
}


HRESULT CSumInfosEnum::Reset(void)
{
    m_nCurItem = 0;
    return S_OK;
}

HRESULT CSumInfosEnum::Clone(IEnumVARIANT** ppEnum)
{
    *ppEnum = NULL;
    if (m_pSumInfos == NULL) 
        return ResultFromScode(E_UNEXPECTED);

    IUnknown* punk = NULL;
    HRESULT hr = m_pSumInfos->_NewEnum(&punk);
    if (SUCCEEDED(hr))
    {
        hr = punk->QueryInterface(IID_IEnumVARIANT, (void**)ppEnum);
        punk->Release();
    }

    return hr;
}



