// Power.cpp : implementation file
//

#include "stdafx.h"
#include "CMFCPwr.h"
#include <initguid.h>
#include "Power.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPower

IMPLEMENT_DYNCREATE(CPower, CCmdTarget)

CPower::CPower()
    : m_fOnStartPageCalled(FALSE),
      m_strMyProperty(_T("C++ MFC Power Component")),
      m_piResponse(NULL),
      m_piRequest(NULL),
      m_piServer(NULL),
      m_piSession(NULL),
      m_piApplication(NULL)
{
    EnableAutomation();
    
    // To keep the application running as long as an OLE automation 
    //  object is active, the constructor calls AfxOleLockApp.
    
    AfxOleLockApp();
}

CPower::~CPower()
{
    // To terminate the application when all objects created with
    //  with OLE automation, the destructor calls AfxOleUnlockApp.
    
    AfxOleUnlockApp();
}


void CPower::OnFinalRelease()
{
    // When the last reference for an automation object is released
    // OnFinalRelease is called.  The base class will automatically
    // deletes the object.  Add additional cleanup required for your
    // object before calling the base class.

    // Just in case OnEndPage didn't get called for some reason
    _ReleaseInterfaces();

    CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CPower, CCmdTarget)
    //{{AFX_MSG_MAP(CPower)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPower, CCmdTarget)
    //{{AFX_DISPATCH_MAP(CPower)
    DISP_PROPERTY_EX(CPower, "MyProperty", GetMyProperty, SetMyProperty, VT_BSTR)
    DISP_PROPERTY_EX(CPower, "MyPowerProperty", GetMyPowerProperty, SetNotSupported, VT_BSTR)
    DISP_FUNCTION(CPower, "MyMethod", MyMethod, VT_BSTR, VTS_BSTR)
    DISP_FUNCTION(CPower, "MyPowerMethod", MyPowerMethod, VT_I4, VTS_NONE)
    DISP_FUNCTION(CPower, "OnStartPage", OnStartPage, VT_I4, VTS_DISPATCH)
    DISP_FUNCTION(CPower, "OnEndPage", OnEndPage, VT_I4, VTS_NONE)
    //}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPower to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {1A8AA7C6-69B2-11D0-8AE4-00C0F00AE35A}
static const IID IID_IPower =
{ 0x1a8aa7c6, 0x69b2, 0x11d0, { 0x8a, 0xe4, 0x0, 0xc0, 0xf0, 0xa, 0xe3, 0x5a } };

BEGIN_INTERFACE_MAP(CPower, CCmdTarget)
    INTERFACE_PART(CPower, IID_IPower, Dispatch)
END_INTERFACE_MAP()

// {1A8AA7C7-69B2-11D0-8AE4-00C0F00AE35A}
IMPLEMENT_OLECREATE(CPower, "IISSample.C++MFCPower", 0x1a8aa7c7, 0x69b2, 0x11d0, 0x8a, 0xe4, 0x0, 0xc0, 0xf0, 0xa, 0xe3, 0x5a)

/////////////////////////////////////////////////////////////////////////////
// CPower message handlers

// Get the value of myProperty
BSTR CPower::GetMyProperty() 
{
    CString strResult = m_strMyProperty;

    return strResult.AllocSysString();
}

// Set the value of myProperty
void CPower::SetMyProperty(LPCTSTR lpszNewValue) 
{
    m_strMyProperty = lpszNewValue;
}

// Convert ptszIn to uppercase
BSTR CPower::MyMethod(LPCTSTR ptszIn) 
{
    CString strResult = ptszIn;
    strResult.MakeUpper();

    return strResult.AllocSysString();
}

// Get Function Returns the Name of the Current Script
BSTR CPower::GetMyPowerProperty() 
{
    // Make sure OnStartPage has been called for this object
    if (!m_fOnStartPageCalled)
        return NULL;

    // Get the SCRIPT_NAME from IRequest
    IRequestDictionary* IReq = NULL;
    
    // Get the ServerVariables Collection
    HRESULT hr = m_piRequest->get_ServerVariables(&IReq);

    if (FAILED(hr))
        return NULL;

    COleVariant vtIn("SCRIPT_NAME");
    COleVariant vtOut((LPCTSTR) NULL, VT_BSTR); // empty string

    // Get the SCRIPT_NAME Item
    hr = IReq->get_Item(vtIn, &vtOut);

    // Release IRequestDictionary Interface
    IReq->Release();

    if (FAILED(hr))
        return NULL;

    // vtOut Contains an IDispatch Pointer.  To fetch the value
    // for SCRIPT_NAME, you must get the Default Value for the 
    // Object stored in vtOut using ChangeType.
    vtOut.ChangeType(VT_BSTR);

    TRACE("The script is '%S'\n", vtOut.bstrVal);

    // return a copy of the string
    return ::SysAllocString(V_BSTR(&vtOut));
}

// Write one message if the browser is the Internet Explorer and a different
// one if it's anything else
long CPower::MyPowerMethod() 
{
    // Make sure OnStartPage has been called for this object
    if (!m_fOnStartPageCalled)
        return E_FAIL;

    // Get the ServerVariables Collection
    IRequestDictionary* IReq = NULL;
    HRESULT hr = m_piRequest->get_ServerVariables(&IReq);

    if (FAILED(hr))
        return hr;

    COleVariant vtIn("HTTP_USER_AGENT");
    COleVariant vtOut((LPCTSTR) NULL, VT_BSTR); // empty string

    // Get the HTTP_USER_AGENT Item
    hr = IReq->get_Item(vtIn, &vtOut);

    // Release IRequestDictionary Interface
    IReq->Release();

    if (FAILED(hr))
        return hr;

    // vtOut Contains an IDispatch Pointer.  To fetch the value
    // for HTTP_USER_AGENT, you must get the Default Value for the 
    // Object stored in vtOut using ChangeType.
    vtOut.ChangeType(VT_BSTR);

    // Look for "MSIE" in HTTP_USER_AGENT string
    if (wcsstr(vtOut.bstrVal, L"MSIE") != NULL)
        m_piResponse->Write(COleVariant(
            "You are using a very powerful browser.")); 
    else
        m_piResponse->Write(COleVariant(
            "Try Internet Explorer today!"));

    return S_OK;
}

// This optional method is called by ASP whenever a page containing a
// CMFCPwr object is loaded by the user's browser.  Note that
// OnStartPage is not called for application-level objects.  If the
// object is created by a method other than a call to
// Server.CreateObject or <OBJECT RUNAT=SERVER ...>, then OnStartPage
// might not be called.  If you rely on interfaces obtained through
// IScriptingContext in OnStartPage, you should always check that
// those interfaces are correctly initialized in the routines that use
// them.
long CPower::OnStartPage(LPDISPATCH pdisp) 
{
    if (pdisp == NULL)
      return E_POINTER;

    IScriptingContext *pContext = NULL;
    HRESULT hr;
    
    // Get the IScriptingContext Interface
    hr = pdisp->QueryInterface(IID_IScriptingContext, (void**) &pContext);

    // Get Request Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Request(&m_piRequest);

    // Get Response Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Response(&m_piResponse);
    
    // The remaining object pointers are not used in this example, but
    // are left in for completeness.
    
    // Get Server Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Server(&m_piServer);
    
    // Get Session Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Session(&m_piSession);

    // Get Application Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Application(&m_piApplication);


    if (SUCCEEDED(hr))
        m_fOnStartPageCalled = TRUE;
    else    // Release all pointers upon failure
        _ReleaseInterfaces();

    // this interface is no longer needed
    pContext->Release();

    return hr;
}

// This optional method is called by ASP whenever a page containing a
// CMFCPwr object is unloaded by the user's browser.  You should release
// any interfaces obtained in OnStartPage here, as they will not be valid
// outside the scope of OnStartPage/OnEndPage.
long CPower::OnEndPage() 
{
    _ReleaseInterfaces();

    return S_OK;
}

// Release all interfaces
void CPower::_ReleaseInterfaces() 
{
    m_fOnStartPageCalled = FALSE;

    if (m_piRequest != NULL)
        m_piRequest->Release();

    if (m_piResponse != NULL)
        m_piResponse->Release();

    if (m_piServer != NULL)
        m_piServer->Release();

    if (m_piSession != NULL)
        m_piSession->Release();

    if (m_piApplication != NULL)
        m_piApplication->Release();

    m_piResponse = NULL;
    m_piRequest = NULL;
    m_piServer = NULL;
    m_piSession = NULL;
    m_piApplication = NULL;
}
