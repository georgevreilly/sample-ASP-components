// Power.cpp : Implementation of CCATLPwrApp and DLL registration.

#include "stdafx.h"
#include "CATLPwr.h"
#include "Power.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CPower::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IPower,
    };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

// Ctor
CPower::CPower()
    : m_bstrMyProperty(OLESTR("C++ ATL Power Component")),
      m_fOnStartPageCalled(FALSE)
{}

// Get function for myProperty
STDMETHODIMP CPower::get_myProperty(BSTR* pbstrOutValue)
{
    if (pbstrOutValue == NULL)
        return E_POINTER;

    // Get Value from Property
    *pbstrOutValue = m_bstrMyProperty.Copy();
    
    return S_OK;
}

// Put function for myProperty
STDMETHODIMP CPower::put_myProperty(BSTR bstrInValue)
{
    if (bstrInValue == NULL)
        return E_POINTER;

    m_bstrMyProperty = bstrInValue;

    return S_OK;
}

// Basic Method which Converts bstrIn to Upper Case
STDMETHODIMP CPower::myMethod(BSTR bstrIn, BSTR* pbstrOut)  
{
    if (bstrIn == NULL || pbstrOut == NULL)
        return E_POINTER;

    // Create a temporary CComBSTR
    CComBSTR bstrTemp(bstrIn);

    if (!bstrTemp)
        return E_OUTOFMEMORY;

    // Make string uppercase   
    wcsupr(bstrTemp);  
    
    // Return m_str member of bstrTemp
    *pbstrOut = bstrTemp.Detach();

    return S_OK;
}


///////////// ASP-Specific Component Methods ////////////////

// Get Function Returns the Name of the Current Script
STDMETHODIMP CPower::get_myPowerProperty(BSTR* pbstrOutValue)
{
    // Make sure OnStartPage has been called for this object
    if (!m_fOnStartPageCalled)
      return E_FAIL;

    // Double-check that pointers to built-in objects have been initialized
    if (!m_piRequest)
        return E_NOINTERFACE;

    // Do we have somewhere valid to store the return value?
    if (pbstrOutValue == NULL)
        return E_POINTER;

    // Initialize the return value
    *pbstrOutValue = NULL;

    // Get the ServerVariables Collection
    CComPtr<IRequestDictionary> piServerVariables;
    HRESULT hr = m_piRequest->get_ServerVariables(&piServerVariables);

    if (FAILED(hr))
        return hr;

    // Get the SCRIPT_NAME item from the ServerVariables collection
    CComVariant vtIn(OLESTR("SCRIPT_NAME")), vtOut;
    hr = piServerVariables->get_Item(vtIn, &vtOut);

    if (FAILED(hr))
        return hr;

    // Get the SCRIPT_NAME item from the ServerVariables collection
    // vtOut Contains an IDispatch Pointer.  To fetch the value
    // for SCRIPT_NAME, you must get the Default Value for the 
    // Object stored in vtOut using VariantChangeType.
    hr = VariantChangeType(&vtOut, &vtOut, 0, VT_BSTR);

    // Copy and return SCRIPT_NAME
    if (SUCCEEDED(hr))
        *pbstrOutValue = ::SysAllocString(V_BSTR(&vtOut));
    
    return hr;
}

// ASP-specific Power Method
STDMETHODIMP CPower::myPowerMethod()  
{
    // Make sure OnStartPage has been called for this object
    if (!m_fOnStartPageCalled)
      return E_FAIL;

    // Double-check that pointers to built-in objects have been initialized
    if (!m_piRequest || !m_piResponse)
        return E_NOINTERFACE;

    // Get the ServerVariables Collection
    CComPtr<IRequestDictionary> piServerVariables;
    HRESULT hr = m_piRequest->get_ServerVariables(&piServerVariables);

    if (FAILED(hr))
        return hr;

    // Get the HTTP_USER_AGENT item from the ServerVariables collection
    CComVariant vtIn(OLESTR("HTTP_USER_AGENT")), vtOut;
    hr = piServerVariables->get_Item(vtIn, &vtOut);

    if (FAILED(hr))
        return hr;

    // vtOut Contains an IDispatch Pointer.  To fetch the value
    // for HTTP_USER_AGENT, you must get the Default Value for the 
    // Object stored in vtOut using VariantChangeType.
    hr = VariantChangeType(&vtOut, &vtOut, 0, VT_BSTR);

    if (SUCCEEDED(hr))
    { 
        // Look for "MSIE" in HTTP_USER_AGENT string
        if (wcsstr(vtOut.bstrVal, L"MSIE") != NULL)
            m_piResponse->Write(CComVariant(
                OLESTR("You are using a very powerful browser."))); 
        else
            m_piResponse->Write(CComVariant(
                OLESTR("Try Internet Explorer today!")));
    }
        
    return hr;
}


///////////// Standard Server-Side Component Methods ////////////////

//
// This optional method is called by ASP whenever a page containing a
// CATLPwr object is loaded by the user's browser.  Note that
// OnStartPage is not called for application-level objects.  If the
// object is created by a method other than a call to
// Server.CreateObject or <OBJECT RUNAT=SERVER ...>, then OnStartPage
// might not be called.  If you rely on interfaces obtained through
// IScriptingContext in OnStartPage, you should always check that
// those interfaces are correctly initialized in the routines that use
// them.
//
STDMETHODIMP CPower::OnStartPage(IUnknown* piUnk)  
{
    if (piUnk == NULL)
        return E_POINTER;

    // Get the IScriptingContext Interface
    CComQIPtr<IScriptingContext, &IID_IScriptingContext> pContext(piUnk);

    if (!pContext)
        return E_NOINTERFACE;

    // Get Request Object Pointer
    HRESULT hr = pContext->get_Request(&m_piRequest);
    
    // Get Response Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Response(&m_piResponse);
    
    // The remaining pointers to built-in objects are not used in this
    // sample, but are left in for completeness.
    
    // Get Application Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Application(&m_piApplication);
    
    // Get Session Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Session(&m_piSession);
    
    // Get Server Object Pointer
    if (SUCCEEDED(hr))
        hr = pContext->get_Server(&m_piServer);
    
    if (SUCCEEDED(hr))
        m_fOnStartPageCalled = TRUE;
    else
    {
        // Release all pointers upon failure
        m_piRequest.Release();
        m_piResponse.Release();
        m_piApplication.Release();
        m_piSession.Release();
        m_piServer.Release();
    }

    return hr;
}

//
// This optional method is called by ASP whenever a page containing a
// CATLPwr object is unloaded by the user's browser.  You should release
// any interfaces obtained in OnStartPage here, as they will not be valid
// outside the scope of OnStartPage/OnEndPage.
//
STDMETHODIMP CPower::OnEndPage()  
{
    m_fOnStartPageCalled = FALSE;

    m_piRequest.Release();
    m_piResponse.Release();
    m_piApplication.Release();
    m_piSession.Release();
    m_piServer.Release();

    return S_OK;
}
