// BrwCap.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//		To build a separate proxy/stub DLL, 
//		run nmake -f BrwCapps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "BrwCap.h"

#include "BrwCap_i.c"
#include <initguid.h>
#include "BrowCap.h"
#include "CapMap.h"
#include "Monitor.h"

CBrwCapModule _Module;
CMonitor*   g_pMonitor = NULL;

/////////////////////////////////////////////////////////////////////////////
//  CPgCntModule methods
//
CBrwCapModule::CBrwCapModule()
    :   m_pMonitor(NULL)
{
}


void
CBrwCapModule::Init(
    _ATL_OBJMAP_ENTRY*  p,
    HINSTANCE           h )
{
    CComModule::Init(p,h);
    m_pMonitor = new CMonitor();
    m_pCapMap = new CCapMap();
}

void
CBrwCapModule::Term()
{
    delete m_pMonitor;
    m_pMonitor = NULL;
    delete m_pCapMap;
    m_pCapMap = NULL;
    CComModule::Term();
}

CMonitor*
CBrwCapModule::Monitor()
{
    return m_pMonitor;
}

CCapMap*
CBrwCapModule::CapMap()
{
    return m_pCapMap;
}


BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_BrowserCap, CBrowserCap)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		_Module.Init(ObjectMap, hInstance);
		DisableThreadLibraryCalls(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
    {
        ATLTRACE( _T("BrwCap.dll unloading\n") );
		_Module.Term();
    }
	return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
	return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	_Module.UnregisterServer();
	return S_OK;
}


