// SumObj.h : Declaration of the CSumInfo
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//

#ifndef __SUMINFO_H_
#define __SUMINFO_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "sumbase.h"

// Category 
#define PIDDSI_CATEGORY     0x00000002 //VT_LPSTR 
//PresentationTarget 
#define PIDDSI_PRESFORMAT   0x00000003 //VT_LPSTR 
// Bytes 
#define PIDDSI_BYTECOUNT    0x00000004 //VT_I4 
// Lines 
#define PIDDSI_LINECOUNT    0x00000005 //VT_I4 
// Paragraphs 
#define PIDDSI_PARCOUNT     0x00000006 //VT_I4 
// Slides 
#define PIDDSI_SLIDECOUNT   0x00000007 //VT_I4 
// Notes 
#define PIDDSI_NOTECOUNT    0x00000008 //VT_I4 
// HiddenSlides 
#define PIDDSI_HIDDENCOUNT  0x00000009 //VT_I4 
// MMClips 
#define PIDDSI_MMCLIPCOUNT  0x0000000A //VT_I4 
// ScaleCrop 
#define PIDDSI_SCALE        0x0000000B //VT_BOOL 
//HeadingPairs 
#define PIDDSI_HEADINGPAIR  0x0000000C //VT_VARIANT | VT_VECTOR 
//TitlesofParts 
#define PIDDSI_DOCPARTS     0x0000000D //VT_LPSTR | VT_VECTOR 
//Manager 
#define PIDDSI_MANAGER      0x0000000E //VT_LPSTR 
//Company 
#define PIDDSI_COMPANY      0x0000000F //VT_LPSTR 
//LinksUpTo Date 
#define PIDDSI_LINKSDIRTY   0x00000010 //VT_BOOL 

/////////////////////////////////////////////////////////////////////////////
// CSumInfo
class ATL_NO_VTABLE CSumInfo : 
    public CSumInfoBase,
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSumInfo, &CLSID_SumInfo>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISumInfo, &IID_ISumInfo, &LIBID_SummaryInfo>
{
public:
    CSumInfo()
	{ 
        m_bstrFileName = NULL;
        memset(m_rgPropVarSI, 0, sizeof(m_rgPropVarSI));
        memset(m_rgPropVarDSI, 0, sizeof(m_rgPropVarDSI));
	}

    virtual ~CSumInfo()
    {
        FreePropVariantArray(sizeof(m_rgPropVarSI)/sizeof(m_rgPropVarSI[0]), m_rgPropVarSI);
        FreePropVariantArray(sizeof(m_rgPropVarDSI)/sizeof(m_rgPropVarDSI[0]), m_rgPropVarDSI);
        SysFreeString(m_bstrFileName);
    }

public:

DECLARE_REGISTRY_RESOURCEID(IDR_SUMINFO)
DECLARE_OBJECT_DESCRIPTION("ASP Summary Information Object 1.0")

BEGIN_COM_MAP(CSumInfo)
	COM_INTERFACE_ENTRY(ISumInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ISumInfo
public:
	STDMETHOD(get_LinksUpToDate)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Company)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Manager)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_TitlesOfParts)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_HeadingPairs)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_ScaleCrop)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_MMClips)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_HiddenSlides)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Notes)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Slides)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Paragraphs)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Lines)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Bytes)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_PresentationTarget)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Category)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_ThumbNail)(/*[out, retval]*/ LPUNKNOWN *pVal);
	STDMETHOD(get_CharCount)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_WordCount)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_PageCount)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_LastSaveTime)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_CreateTime)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_LastPrinted)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_EditTime)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_RevNumber)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_LastSavedBy)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Template)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Comments)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Keywords)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Application)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Subject)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Author)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Title)(/*[out, retval]*/ VARIANT* pVal);
	STDMETHOD(get_URL)(/*[out, retval]*/ VARIANT* pVal);
	STDMETHOD(get_Style)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Style)(/*[in]*/ long newVal);
	STDMETHOD(Write)();
	STDMETHOD(SetFile)(/*[in]*/BSTR FileName);
private:
    BSTR m_bstrFileName;        // current file name

    // SummaryInformation properties
    PROPVARIANT m_rgPropVarSI[PIDSI_DOC_SECURITY - PID_FIRST_USABLE + 1];

    // DocumentSummaryInformation properties
    PROPVARIANT m_rgPropVarDSI[PIDDSI_LINKSDIRTY - PID_FIRST_USABLE + 1];

    void WriteNormalPart(CContext&, VARIANT* pv, WCHAR* wszName, BOOL* pfComma);
    
 };

#endif //__SUMINFO_H_
