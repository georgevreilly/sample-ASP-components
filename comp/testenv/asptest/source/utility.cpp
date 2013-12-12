#include "stdafx.h"
#include "utility.h"

static LPCTSTR	s_szDefault = _T("(default)");


//---------------------------------------------------------------------------
//
//	Get a string from the associated Ini file
//
//---------------------------------------------------------------------------
CString		// the string from the ini file
GetProfileString(
	LPCTSTR szFile,
	LPCTSTR	szSection,				// the section name
	LPCTSTR	szKey,					// the key name
	LPCTSTR	szDefault /*=NULL*/ )	// the default value
{
	if ( szDefault == NULL )
	{
		szDefault = s_szDefault;
	} 

	CString strRet = szDefault;

	ASSERT( szSection && szKey && szFile );
	if ( szSection && szKey && szFile )
	{
		DWORD dwSize = 256;
		bool bDone = false;
		while ( !bDone )
		{
			LPTSTR szValue = (LPTSTR)_alloca( dwSize * sizeof( _TCHAR ) );
			DWORD dwRetSize = ::GetPrivateProfileString(
				szSection,
				szKey,
				szDefault,
				szValue,
				dwSize,
				szFile );
			if ( dwRetSize < ( dwSize - 2 ) )
			{
				// got it
				bDone = true;
				strRet = szValue;
			}
			else
			{
				// increase size and try again
				dwSize = dwSize << 1;
			}
		}
	}

	return strRet;
}


// duplicate any byref values of a variant (this is done after a copy
// to keep the VARIANTARGs from sharing anything
void
CopyRef( VARIANTARG& varg )
{
	if ( varg.vt & VT_BYREF )
	{
		size_t s=0;
		VARTYPE vt = varg.vt & (~VT_BYREF);
		switch ( vt )
		{
		case VT_UI1:
			s = sizeof( BYTE );
		break;

		case VT_I2:
			s = sizeof(short);
		break;

		case VT_I4:
			s = sizeof(long);
		break;

		case VT_R4:
			s = sizeof(float);
		break;

		case VT_R8:
			s = sizeof(double);
		break;

		case VT_BSTR:
			s = sizeof(BSTR);
		break;

		case VT_VARIANT:
			s = sizeof(VARIANT);
		break;

		default:
			// usupported ref type
			ASSERT(0);
		break;
		}

		if ( s > 0 )
		{
			void* pRef = malloc( s );
			if ( vt == VT_BSTR )
			{
				BSTR* pbstr = (BSTR*)pRef;
				*pbstr = ::SysAllocString( *varg.pbstrVal );
			}
			else if ( vt == VT_VARIANT )
			{
				::VariantCopy( (VARIANT*)pRef, varg.pvarVal );
			}
			else
			{
				memcpy(pRef,varg.byref,s);
			}

			// don't need to free the current ref, since it's acutally owned by
			// someone else
			varg.byref = pRef;
		}
	}
}


