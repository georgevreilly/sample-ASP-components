/*++

   Copyright    (c)    1997    Microsoft Corporation

   Module  Name :

       MyString.h

   Abstract:
		A lightweight string class which supports UNICODE/MCBS.

   Author:

       Neil Allain    ( a-neilal )     August-1997 

   Revision History:

--*/

#include "stdafx.h"
#include "MyString.h"
#include "MyDebug.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


BaseStringBuffer::BaseStringBuffer(
	LPCTSTR	inString )
{
	if ( inString )
	{
		m_length = _tcsclen( inString );
	}
	else
	{
		m_length = 0;
	}
	m_bufferSize = m_length + 1;
	m_pString = new _TCHAR[ m_bufferSize ];
	if ( inString )
	{
		_tcscpy( m_pString, inString );
	}
	else
	{
		m_pString[0] = _T('\0');
	}
}

BaseStringBuffer::BaseStringBuffer(
	size_t	bufferSize )
{
	if ( bufferSize <= 0 )
	{
		bufferSize = 1;
	}
	
	m_length=0;
	m_bufferSize = bufferSize;
	m_pString = new _TCHAR[ m_bufferSize ];
	_ASSERT( m_pString );
	m_pString[0] = '\0';
}
	
BaseStringBuffer::BaseStringBuffer(
	LPCTSTR	s1,
	LPCTSTR	s2
)
{
	m_length = _tcsclen( s1 ) + _tcsclen( s2 );
	m_bufferSize = m_length + 1;
	m_pString = new _TCHAR[ m_bufferSize ];
	_ASSERT( m_pString );
	_tcscpy( m_pString, s1 );
	_tcscat( m_pString, s2 );
}

BaseStringBuffer::~BaseStringBuffer()
{
	delete[] m_pString;
}

HRESULT
BaseStringBuffer::copy(
	LPCTSTR	str
)
{
	HRESULT rc;
	size_t len = _tcsclen( str );
	rc = growBuffer( len + 1 );
	_ASSERT( m_pString );
	rc = S_OK;
	_tcscpy( m_pString, str );
	m_length = len;
	return rc;
}

HRESULT
BaseStringBuffer::concatenate(
	LPCTSTR	str
)
{
	HRESULT rc;
	size_t len = _tcsclen( str );
	rc = growBuffer( m_length + len + 1 );
	_ASSERT( m_pString );
	rc = S_OK;
	_tcscat( m_pString, str );
	m_length = m_length + len;
	return rc;
}

HRESULT
BaseStringBuffer::concatenate(
	_TCHAR	c
)
{
	HRESULT rc;
	_TCHAR sz[2];
	sz[0] = c;
	sz[1] = _T('\0');
	rc = growBuffer( m_length + 2 );
	_ASSERT( m_pString );
	rc = S_OK;
	_tcscat( m_pString, sz );
	m_length += 1;
	return rc;
}

HRESULT
BaseStringBuffer::growBuffer(
	size_t	inMinSize )
{
	HRESULT rc = E_OUTOFMEMORY;
	if ( m_bufferSize < inMinSize )
	{
		LPTSTR newStringP = new _TCHAR[ inMinSize ];
		_ASSERT( newStringP );
		if ( newStringP )
		{
			if ( m_pString )
			{
				_tcscpy( newStringP, m_pString );
				delete[] m_pString;
			}
			m_pString = newStringP;
			m_bufferSize = inMinSize;
			rc = S_OK;
		}
		else
		{
			delete m_pString;
			m_pString = NULL;
			m_bufferSize = 0;
			m_length = 0;
		}
		
	}
	return rc;
}

BaseStringBuffer::size_type
BaseStringBuffer::find_last_of(
	_TCHAR c) const
{
	size_type pos = npos;
	LPTSTR p = _tcsrchr(m_pString,c);
	if ( p != NULL )
	{
		pos = p - m_pString;
	}
	return pos;
}

BaseStringBuffer::size_type
BaseStringBuffer::find_first_of(
	_TCHAR c) const
{
	size_type pos = npos;
	_ASSERT( m_pString );
	LPTSTR p = _tcschr(m_pString,c);
	if ( p != NULL )
	{
		pos = p - m_pString;
	}
	return pos;
}

LPTSTR
BaseStringBuffer::substr(
	size_type b,
	size_type e ) const
{
	LPTSTR pStr = NULL;
	_ASSERT( m_pString );
	if ( m_pString )
	{
		LPCTSTR pB = m_pString + b;
		pStr = new _TCHAR[e-b+1];
		_ASSERT( pStr );
		if ( pStr )
		{
			_tcsnccpy( pStr, pB, e-b );
			pStr[e-b] = _T('\0');
		}
	}
	return pStr;
}

String::String()
{
	Set( new StringBuffer(_T("") ) );
}

String::String(
	const String&	str
)	:	TRefPtr< StringBuffer >( str )
{
}

String::String(
	LPCTSTR		str
)	:	TRefPtr< StringBuffer >( new StringBuffer( str ) )
{
}

String&
String::operator=(
	const String&	str
)
{
	Set( const_cast< StringBuffer* >(str.Get()) );
	return *this;
}

String&
String::operator=(
	LPCTSTR		str
)
{
	Set( new StringBuffer( str ) );
	return *this;
}

String&
String::operator=(
	StringBuffer*	pBuf
)
{
	Set( pBuf );
	return *this;
}

String&
String::operator+=(
	const String&	str
)
{
	StringBuffer* pb = new StringBuffer( c_str(), str.c_str() );
	Set( pb );
	return *this;
}

String&
String::operator+=(
	LPCTSTR		str
)
{
	StringBuffer* pb = new StringBuffer( c_str(), str );
	Set( pb );
	return *this;
}

String
String::operator+(
	const String&	str
) const
{
	StringBuffer* pb = new StringBuffer( c_str(), str.c_str() );
	String s;
	s.Set( pb );
	return s;
}

String
String::operator+(
	LPCTSTR		str
) const
{
	StringBuffer* pb = new StringBuffer( c_str(), str );
	String s;
	s.Set( pb );
	return s;
}

String
String::operator+(
	_TCHAR	c
) const
{
	StringBuffer* pb = new StringBuffer( c_str() );
	if ( pb )
	{
		pb->concatenate( c );
	}
	String s( pb );
	return s;
}

bool
String::operator==(
	const String&	str
) const
{
	return ( _tcscmp( c_str(), str.c_str() ) != 0 ) ? false : true;
}

bool
String::operator==(
	LPCTSTR		str
) const
{
	return ( _tcscmp( c_str(), str ) != 0 ) ? false : true;
}

bool
String::operator<(
	const String&	str
) const
{
	return ( _tcscmp( c_str(), str.c_str() ) < 0 ) ? true : false;
}

bool
String::operator<(
	LPCTSTR		str
) const
{
	return ( _tcscmp( c_str(), str ) < 0 ) ? true : false;
}

int
String::compare(
	size_t			b,
	size_t			e,
	const String&	str
) const
{
	return _tcsncmp( c_str() + b, str.c_str(), e - b );
}

size_t
String::find(
	_TCHAR	c
) const
{
	size_t pos = npos;
	LPCTSTR p = _tcschr( c_str(), c );
	if ( p != NULL )
	{
		pos = p - c_str();
	}
	return pos;
}

String
String::fromInt16(
	SHORT	i
)
{
	_TCHAR buf[256];
	_stprintf( buf, _T("%d"), (LONG)i);
	return String(buf);
}

String
String::fromInt32(
	LONG	i
)
{
	_TCHAR buf[256];
	_stprintf( buf, _T("%d"), i);
	return String(buf);
}

String
String::fromFloat(
	float	f
)
{
	_TCHAR buf[256];
	_stprintf( buf, _T("%g"), f );
	return String(buf);
}

String
String::fromDouble(
	double	d
)
{
	_TCHAR buf[256];
	_stprintf( buf, _T("%g"), d );
	return String(buf);
}

String
operator+(
LPCTSTR			lhs,
const String&	rhs )
{
	return String( new StringBuffer(lhs,rhs.c_str()) );
}
