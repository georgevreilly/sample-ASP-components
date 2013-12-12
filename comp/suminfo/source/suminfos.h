// SumInfos.h : Declaration of the CSumInfos
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//

#ifndef __SUMINFOS_H_
#define __SUMINFOS_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "SumObj.h"

typedef struct tagFILE_ENTRY
{
    BSTR    bstrFileName;
    VARIANT v;
} FILE_ENTRY;

/////////////////////////////////////////////////////////////////////////////
// CSumInfos
class ATL_NO_VTABLE CSumInfos : 
    public CSumInfoBase,
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSumInfos, &CLSID_SumInfos>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISumInfos, &IID_ISumInfos, &LIBID_SummaryInfo>
{
    friend class CSumInfosEnum;

public:
	CSumInfos()
	{ 
        m_bstrFileSpec = NULL;
        m_rgFiles = NULL;
        m_nFiles = 0;
	}

    virtual ~CSumInfos()
    {
        if (m_rgFiles != NULL)
        {
            while(m_nFiles > 0)
            {
                VariantClear(&m_rgFiles[m_nFiles-1].v);
                SysFreeString(m_rgFiles[m_nFiles-1].bstrFileName);
                m_nFiles--;
            }
            free(m_rgFiles);
        }
        SysFreeString(m_bstrFileSpec);
    }

public:

DECLARE_REGISTRY_RESOURCEID(IDR_SUMINFOS)
DECLARE_OBJECT_DESCRIPTION("ASP Summary Information File Enumerator Object 1.0")

BEGIN_COM_MAP(CSumInfos)
	COM_INTERFACE_ENTRY(ISumInfos)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ISumInfos
public:
	STDMETHOD(Write)();
	STDMETHOD(get_Style)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Style)(/*[in]*/ long newVal);
	STDMETHOD(SetFileSpec)(BSTR Path, BSTR FileSpec);
	STDMETHOD(_NewEnum)(/*[out,retval]*/IUnknown** pRet);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ ISumInfo* *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);

private:
    BSTR m_bstrFileSpec;        // current filespec.

protected:
	FILE_ENTRY* m_rgFiles;
	long m_nFiles;

};

#endif //__SUMINFOS_H_
