// Method.cpp: implementation of the CMethod class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AspTest.h"
#include "Method.h"
#include "utility.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Conversion
// the following stuff is for converting strings into a varaint
// (based on a string type and a string value).
// adding a new conversion is a 3 step process,
//	1) declare the conversion function
//	2) add an entry to the conversion map
//	3) define the converion function
// Note that some conversion functions handle both the by val
// by ref VARIANT types.  However, this isn't necessary.
// If you simply want more strings recognized (LPLONG for
// instance), you can use the already existing conversion
// functions.

// this macro simply turns a VARTYPE into a by-ref VARTYPE
#define REF(x) x | VT_BYREF

// this is to declare conversion function with a common signature
#define DECLARE_CONVERSION_FUNC(x) static bool Convert##x( const CString&, VARIANT& );
// this macro this the header for defining a conversion fucntion
#define DEFINE_CONVERSION_FUNC(x) bool Convert##x( const CString& strVal, VARIANT& vt )

// the macro begins the conversion map
#define BEGIN_CONVERSION_MAP() \
static ConversionEntry _ConversionMap[] = {

// this is one entry into the conversion map
#define CONVERSION_ENTRY( x, y, z ) \
{ x, y, z },

// this macro ends the conversion map
#define END_CONVERSION_MAP() \
{ VT_EMPTY, NULL, NULL } };

// function pointer for a conversion function
typedef bool (*ConversionFunc)( const CString&, VARIANTARG& );

// a struct to hold information for one conversion map entry
struct ConversionEntry
{
	VARTYPE			vt;
	LPCTSTR			szType;
	ConversionFunc	Convert;
};

// defining signatures for conversion functions
DECLARE_CONVERSION_FUNC( UI1 )
DECLARE_CONVERSION_FUNC( I2 )
DECLARE_CONVERSION_FUNC( I4 )
DECLARE_CONVERSION_FUNC( BSTR )
DECLARE_CONVERSION_FUNC( BOOL )
DECLARE_CONVERSION_FUNC( VARIANT )

BEGIN_CONVERSION_MAP()
CONVERSION_ENTRY( VT_UI1, _T("unsigned char"), ConvertUI1 )
CONVERSION_ENTRY( VT_UI1, _T("BYTE"), ConvertUI1 )
CONVERSION_ENTRY( VT_I2, _T("short"), ConvertI2 )
CONVERSION_ENTRY( VT_I4, _T("int"), ConvertI4 )
CONVERSION_ENTRY( VT_I4, _T("long"), ConvertI4 )
CONVERSION_ENTRY( VT_BSTR, _T("BSTR"), ConvertBSTR )
CONVERSION_ENTRY( VT_BOOL, _T("BOOL"), ConvertBOOL )
CONVERSION_ENTRY( REF(VT_UI1), _T("unsigned char*"), ConvertUI1 )
CONVERSION_ENTRY( REF(VT_UI1), _T("BYTE*"), ConvertUI1 )
CONVERSION_ENTRY( REF(VT_I2), _T("short*"), ConvertI2 )
CONVERSION_ENTRY( REF(VT_I4), _T("int*"), ConvertI4 )
CONVERSION_ENTRY( REF(VT_I4), _T("long*"), ConvertI4 )
CONVERSION_ENTRY( REF(VT_BSTR), _T("BSTR*"), ConvertBSTR )
CONVERSION_ENTRY( REF(VT_BOOL), _T("BOOL*"), ConvertBOOL )
CONVERSION_ENTRY( REF(VT_VARIANT), _T("VARIANT*"), ConvertVARIANT )
END_CONVERSION_MAP()

// functions which use the conversion map
static VARTYPE	StringToType( const CString& );
static bool		StringToVal( const CString&, VARIANT& );

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMethod::CMethod(
	LPCTSTR	szIniFile,
	LPCTSTR	szName )
	:	m_strIniFile( szIniFile ),
		m_strName( szName ),
		m_bstrName( szName )
{
}

CMethod::CMethod(
	CMethod& mtd )
	:	m_strIniFile( mtd.m_strIniFile ),
		m_strName( mtd.m_strName ),
		m_bstrName( mtd.m_bstrName ),
		m_wInvokeFlags( mtd.m_wInvokeFlags )
{
	// copy the variantarg list
	CopyVariantList( m_params, mtd.m_params );
}

CMethod::~CMethod()
{
	DeleteVariantList( m_params );
}

//---------------------------------------------------------------------------
//
//	Read the section under the method's name in the .ini file (given at
//	contstruction), forming the needed arguments to invoke this method.
//
//---------------------------------------------------------------------------
bool	// true if initialization was successful
CMethod::Initialize()
{
	bool rc = false;

	// reset the state
	DeleteVariantList( m_params );
	m_wInvokeFlags = 0;

	// get the type of method (method/get/put)
	CString strType = GetProfileString(
		m_strIniFile,
		m_strName,
		_T("type") );
	if ( strType.CompareNoCase( _T("Get") ) == 0 )
	{
		m_wInvokeFlags = DISPATCH_PROPERTYGET;
	}
	else if ( strType.CompareNoCase( _T("Put") ) == 0 )
	{
		m_wInvokeFlags = DISPATCH_PROPERTYPUT;
	}
	else
	{
		m_wInvokeFlags = DISPATCH_METHOD;
	}

	// now get a list of all paramters
	DWORD dwSize = 256;
	bool bDone = false;
	while ( !bDone )
	{
		LPTSTR szValue = (LPTSTR)_alloca( dwSize * sizeof( _TCHAR ) );
		DWORD dwRetSize = ::GetPrivateProfileSection(
			m_strName,
			szValue,
			dwSize,
			m_strIniFile );
		if ( dwRetSize < ( dwSize - 2 ) )
		{
			// got it
			bDone = true;

			// for each parameter, create a variant containing the appropriate
			// argument
			while ( *szValue != _T('\0') )
			{
				ParseParam( szValue );
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
	return rc;
}

//---------------------------------------------------------------------------
//
//	Invoke the method on the given object
//
//---------------------------------------------------------------------------
HRESULT
CMethod::Invoke(
	IDispatch*	pDisp )
{
	HRESULT rc = E_FAIL;
	if ( pDisp )
	{
		// get the dispatch ID
		vector<VARIANTARG>	vargs;
		CopyVariantList(vargs, m_params);
		DISPPARAMS dp;
		dp.cArgs = vargs.size();
		dp.rgvarg = &(vargs[0]);
		dp.cNamedArgs = 0;
		dp.rgdispidNamedArgs = NULL;
		DISPID did = GetDispID(pDisp);

		VARIANT vtRes;
		::VariantInit( &vtRes );
		EXCEPINFO ei;
		UINT argErr;
		rc = pDisp->Invoke(
			did,
			IID_NULL,
			LOCALE_USER_DEFAULT,
			m_wInvokeFlags,
			&dp,
			&vtRes,
			&ei,
			&argErr );

		// print out results if you want here

		// cleanup
		::VariantClear( &vtRes );
		DeleteVariantList(vargs);
	}
	return rc;
}

//---------------------------------------------------------------------------
//
//	Get the dispatch ID of this method
//
//---------------------------------------------------------------------------
DISPID
CMethod::GetDispID(
	IDispatch*	pDisp ) const
{
	DISPID did = DISP_E_UNKNOWNNAME;

	BSTR bstrTemp = m_bstrName;

	pDisp->GetIDsOfNames(
		IID_NULL,
		&bstrTemp,
		1,
		LOCALE_USER_DEFAULT,
		&did );

	return did;
}

//---------------------------------------------------------------------------
//
//	Parse one line from the method's section.  This should consist of a
//	parameter type (BSTR, long, etc), and a value ( example : BSTR="Hello" ).
//	For a property's return value it should have the word return.
//	(example : LONG=return).
//
//---------------------------------------------------------------------------
bool
CMethod::ParseParam(
	LPCTSTR	szParam )
{
	bool rc = false;

	CString strParam = szParam;
	int pos = strParam.Find( _T('=') );
	if ( pos != -1 )
	{
		CString strType = strParam.Left( pos );
		strType.TrimRight();
		VARIANT vt;
		vt.vt = StringToType( strType );
		if ( vt.vt != VT_EMPTY )
		{
			CString strVal = strParam.Right( strParam.GetLength() - (pos+1) );
			strVal.TrimLeft();
			if ( strVal.CompareNoCase( _T("return") ) != 0 )
			{
				if ( StringToVal( strVal, vt ) )
				{
					rc = true;
					m_params.push_back( vt );
				}
			
			}
			else
			{
				// this is the return value
			}
		}
	}
	return rc;
}

//---------------------------------------------------------------------------
//
//	Convert a string into the corresponding VARTYPE.  Note that the string
//	should contain no extra spaces ( BSTR * will not work, BSTR* will).  If
//	the string couldn't be converted, VT_EMPTY is returned.  Refer to the
//	conversion map at the top of this file to see supported types.
//
//---------------------------------------------------------------------------
VARTYPE
StringToType(
	const CString&	strType )
{
	VARTYPE rc = VT_EMPTY;
	
	ConversionEntry* pEntry = _ConversionMap;
	while ( ( rc == VT_EMPTY ) && ( pEntry->szType != NULL ) )
	{
		if ( strType.CompareNoCase( pEntry->szType ) != 0 )
		{
			// no match, keep going
			pEntry++;
		}
		else
		{
			// matched type, set the variant type
			rc = pEntry->vt;
		}
	}
	return rc;
}

//---------------------------------------------------------------------------
//
//	Convert a string into a variant value of the type indicated in the second
//	parameter.  The result is returne in the second paramter as well.  If
//	The type is a VT_BYREF (a pointer) the value could be "NULL" (to represent
//	a out parameter).  Refer to the conversion map at the top of this file
//	to see supported types.
//
//---------------------------------------------------------------------------
bool	// true on success
StringToVal(
	const CString&	strVal,
	VARIANT&		vt )
{
	bool rc = false;
	
	// strip off any quotes on the value string
	CString strNewVal = strVal;
	if ( strNewVal.GetAt( 0 ) == _T('"') )
	{
		strNewVal = strNewVal.Right( strNewVal.GetLength() - 1 );
	}
	if ( strNewVal.GetAt( strNewVal.GetLength() - 1 ) == _T('"') )
	{
		strNewVal = strNewVal.Left( strNewVal.GetLength() - 1 );
	}

	bool bDone = false;
	ConversionEntry* pEntry = _ConversionMap;
	while ( !bDone && ( pEntry->Convert != NULL ) )
	{
		if ( vt.vt != pEntry->vt )
		{
			// keep going
			pEntry++;
		}
		else
		{
			// use this conversion function
			rc = pEntry->Convert( strNewVal, vt );
			bDone = true;
		}
	}
	return rc;
}

// definition of conversion functions
DEFINE_CONVERSION_FUNC( UI1 )
{
	bool rc = true;
	BYTE b = atoi( strVal );

	if ( vt.vt & VT_BYREF )
	{
		// it's a pointer to a BYTE
		vt.pbVal = (BYTE*)malloc(sizeof(BYTE));
		*(vt.pbVal) = b;
	}
	else
	{
		vt.bVal = b;
	}
	return rc;
}

DEFINE_CONVERSION_FUNC( I2 )
{
	bool rc = true;
	short s = atoi( strVal );

	if ( vt.vt & VT_BYREF )
	{
		// it's a pointer to a short
		vt.piVal = (short*)malloc(sizeof(short));
		*(vt.piVal) = s;
	}
	else
	{
		vt.iVal = s;
	}
	return rc;
}

DEFINE_CONVERSION_FUNC( I4 )
{
	bool rc = true;
	long l = atol( strVal );

	if ( vt.vt & VT_BYREF )
	{
		// it's a pointer to a long
		vt.plVal = (long*)malloc( sizeof(long) );
		*(vt.plVal) = l;
	}
	else
	{
		vt.lVal = l;
	}
	return rc;
}

DEFINE_CONVERSION_FUNC( BSTR )
{
	bool rc = true;
	if ( vt.vt & VT_BYREF )
	{
		// its a pointer to a BSTR
		vt.pbstrVal = (BSTR*)malloc( sizeof(BSTR));
		if ( strVal.CompareNoCase( _T("NULL") ) == 0 )
		{
			(*vt.pbstrVal) = NULL;
		}
		else
		{
			(*vt.pbstrVal) = strVal.AllocSysString();
		}
	}
	else
	{
		vt.bstrVal = strVal.AllocSysString();
	}
	return rc;
}

DEFINE_CONVERSION_FUNC( BOOL )
{
	bool rc = true;
	VARIANT_BOOL b;
	if ( strVal.CompareNoCase( _T( "true" ) ) == 0 )
	{
		b = VARIANT_TRUE;
	}
	else
	{
		b = VARIANT_FALSE;
	}

	if ( vt.vt & VT_BYREF )
	{
		// it's a pointer to a BOOL
		vt.pboolVal = (VARIANT_BOOL*)malloc( sizeof( VARIANT_BOOL ) );
		(*vt.pboolVal) = b;
	}
	else
	{
		vt.boolVal = b;
	}
	return rc;
}

// a VARIANT value excepts to have it's explicity define in parens before the
// value itself (just like a typecast).
DEFINE_CONVERSION_FUNC( VARIANT )
{
	bool rc = false;
	if ( vt.vt & VT_BYREF )
	{
		vt.pvarVal = (VARIANT*)malloc( sizeof( VARIANT ) );
		::VariantInit( vt.pvarVal );
		if ( strVal.GetAt( 0 ) == _T('(') )
		{
			CString strTemp = strVal.Right( strVal.GetLength() - 1 );
			int pos = strTemp.Find( _T(')') );
			if ( pos != -1 )
			{
				// seperate the type and the value
				CString strType = strTemp.Left( pos );
				strType.TrimLeft();
				strType.TrimRight();
				CString strVal2 = strTemp.Right( strTemp.GetLength() - (pos+1) );
				strVal2.TrimLeft();
				strVal2.TrimRight();
				vt.pvarVal->vt = StringToType( strType );
				if ( vt.pvarVal->vt != VT_EMPTY )
				{
					rc = StringToVal( strVal2, *(vt.pvarVal) );
				}
			}
		}
		else
		{
			// couldn't determine the type, just assume empty
		}
	}
	else
	{
		rc = false;
	}
	return rc;
}