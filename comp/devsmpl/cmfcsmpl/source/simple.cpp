// Simple.cpp : implementation file
//

#include "stdafx.h"
#include "CMFCSmpl.h"
#include "Simple.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimple

IMPLEMENT_DYNCREATE(CSimple, CCmdTarget)

CSimple::CSimple()
    : m_strMyProperty(_T("C++ MFC Simple Component"))
{
    EnableAutomation();
    
    // To keep the application running as long as an OLE automation 
    //  object is active, the constructor calls AfxOleLockApp.
    
    AfxOleLockApp();
}

CSimple::~CSimple()
{
    // To terminate the application when all objects created with
    //  with OLE automation, the destructor calls AfxOleUnlockApp.
    
    AfxOleUnlockApp();
}


void CSimple::OnFinalRelease()
{
    // When the last reference for an automation object is released
    // OnFinalRelease is called.  The base class will automatically
    // deletes the object.  Add additional cleanup required for your
    // object before calling the base class.

    CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CSimple, CCmdTarget)
    //{{AFX_MSG_MAP(CSimple)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSimple, CCmdTarget)
    //{{AFX_DISPATCH_MAP(CSimple)
    DISP_PROPERTY_EX(CSimple, "MyProperty", GetMyProperty, SetMyProperty, VT_BSTR)
    DISP_FUNCTION(CSimple, "MyMethod", MyMethod, VT_BSTR, VTS_BSTR)
    //}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISimple to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E9759CC6-698C-11D0-8AE3-00C0F00AE35A}
static const IID IID_ISimple =
{ 0xe9759cc6, 0x698c, 0x11d0, { 0x8a, 0xe3, 0x0, 0xc0, 0xf0, 0xa, 0xe3, 0x5a } };

BEGIN_INTERFACE_MAP(CSimple, CCmdTarget)
    INTERFACE_PART(CSimple, IID_ISimple, Dispatch)
END_INTERFACE_MAP()

// {E9759CC7-698C-11D0-8AE3-00C0F00AE35A}
IMPLEMENT_OLECREATE(CSimple, "IISSample.C++MFCSimple", 0xe9759cc7, 0x698c, 0x11d0, 0x8a, 0xe3, 0x0, 0xc0, 0xf0, 0xa, 0xe3, 0x5a)

/////////////////////////////////////////////////////////////////////////////
// CSimple message handlers

// Convert argument to uppercase
BSTR CSimple::MyMethod(LPCTSTR ptszIn) 
{
    CString strResult = ptszIn;
    strResult.MakeUpper();

    return strResult.AllocSysString();
}

// Get the value of myProperty
BSTR CSimple::GetMyProperty() 
{
    CString strResult = m_strMyProperty;

    return strResult.AllocSysString();
}

// Set the value of myProperty
void CSimple::SetMyProperty(LPCTSTR lpszNewValue) 
{
    m_strMyProperty = lpszNewValue;
}
