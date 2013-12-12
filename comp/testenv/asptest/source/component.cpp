// Component.cpp: implementation of the CComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AspTest.h"
#include "Component.h"
#include "Method.h"
#include "utility.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComponent::CComponent(
	CString&	strIniFile )
	:	m_strIniFile( strIniFile )
{
}

CComponent::CComponent(
	CComponent& cmp )
	:	m_strIniFile( cmp.m_strIniFile ),
		m_strProgID( cmp.m_strProgID ),
		m_scope( cmp.m_scope )
{
	// copy all of the methods
	for ( int i = 0; i < cmp.m_methods.size(); i++ )
	{
		CMethod* pMethod = new CMethod( *(cmp.m_methods[i]) );
		m_methods.push_back( pMethod );
	}

	// for application scoped components, we copy over the object
	// pointer as well
	if ( m_scope == scope_Application )
	{
		m_pObj = cmp.m_pObj;
	}
}

CComponent::~CComponent()
{
	DeleteList( m_methods );
}

//---------------------------------------------------------------------------
//
//	Read the associated .ini file and build (or rebuild) description of this
//	component and the methods to invoke on it.
//
//---------------------------------------------------------------------------
bool
CComponent::Initialize()
{
	bool rc = false;
	
	// clear out any old list of methods
	DeleteList( m_methods );
	m_scope = scope_Page;
	if ( m_pObj != NULL )
	{
		m_pObj.Release();
	}

	// first get the class information
	m_strProgID = GetProfileString(
		m_strIniFile,
		_T("class"),
		_T("ProgID") );

	// determine the scope of the object
	CString strScope = GetProfileString(
		m_strIniFile,
		_T("class"),
		_T("scope") );
	if ( strScope.CompareNoCase( _T("application") ) == 0 )
	{
		m_scope = scope_Application;
	}
	else if ( strScope.CompareNoCase( _T("session") ) == 0 )
	{
		m_scope = scope_Session;
	}
	else
	{
		m_scope = scope_Page;
	}

	// now get a list of all methods
	DWORD dwSize = 256;
	bool bDone = false;
	while ( !bDone )
	{
		LPTSTR szValue = (LPTSTR)_alloca( dwSize * sizeof( _TCHAR ) );
		DWORD dwRetSize = ::GetPrivateProfileSectionNames(
			szValue,
			dwSize,
			m_strIniFile );
		if ( dwRetSize < ( dwSize - 2 ) )
		{
			// got it
			bDone = true;

			// now for each section, create a new method description
			while ( *szValue != _T('\0') )
			{
				if ( IsMethod( szValue ) )
				{
					CMethod* pMethod = new CMethod( m_strIniFile, szValue );
					if ( pMethod->Initialize() )
					{
						// okay save it away
						m_methods.push_back( pMethod );
					}
					else
					{
						// invalid method
						delete pMethod;
					}
				}
				// move to the next string
				int len = _tcslen( szValue );
				szValue += len + 1;
			}
			rc = true;
		}
		else
		{
			// increase size and try again
			dwSize = dwSize << 1;
		}
	}
	
	// if this isn't a page-level object, we need an instance to test
	if ( rc && ( m_scope != scope_Page ) )
	{
		if ( !FAILED( m_pObj.CreateInstance( m_strProgID ) ) )
		{
		}
		else
		{
			rc = false;
		}
	}

	return rc;
}

//---------------------------------------------------------------------------
//
//	Run the test methods on this component
//
//---------------------------------------------------------------------------
void
CComponent::Test()
{
	if ( m_scope == scope_Page )
	{
		IDispatchPtr pObj;
		if ( !FAILED( pObj.CreateInstance( m_strProgID ) ) )
		{
			Test( pObj );
		}
	}
	else
	{
		Test( m_pObj );
	}
}

//---------------------------------------------------------------------------
//
//	Start Test is called once before any calls to test are made
//
//---------------------------------------------------------------------------
void
CComponent::StartTest()
{
	if ( m_scope == scope_Session )
	{
		// create the object
		if ( !FAILED( m_pObj.CreateInstance( m_strProgID ) ) )
		{
		}
		else
		{
			ASSERT(0);
		}
	}
}

//---------------------------------------------------------------------------
//
//	EndTest is called once after all testing is done
//
//---------------------------------------------------------------------------
void
CComponent::EndTest()
{
	// release any application or session scoped objects
	if ( m_pObj != NULL )
	{
		m_pObj.Release();
	}
}

//---------------------------------------------------------------------------
//
//	Invoke each of the methods on the given dispatch object
//
//---------------------------------------------------------------------------
void
CComponent::Test(
	IDispatch*	pDisp )
{
	if ( pDisp )
	{
		vector<CMethod*>::iterator iter;
		for ( iter = m_methods.begin(); iter != m_methods.end(); ++iter )
		{
			if ( (*iter) != NULL )
			{
				(*iter)->Invoke( pDisp );
			}
		}
	}
}

//---------------------------------------------------------------------------
//
//	Determine is the string is a valid method name. (We filter out section
//	names that we know aren't methods, and assume everything else is a
//	method.
//
//---------------------------------------------------------------------------
bool
CComponent::IsMethod(
	LPCTSTR	szName )
{
	bool rc = true;

	if ( _tcscmp( _T("class"), szName ) != 0 )
	{
	}
	else
	{
		rc = false;
	}
	return rc;
}
