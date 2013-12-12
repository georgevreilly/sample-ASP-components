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
#pragma once
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

//==========================================================================================
//	Dependencies
//==========================================================================================
#include <string.h>
#include "RefPtr.h"
#include "RefCount.h"

//==========================================================================================
//	Classes
//==========================================================================================

class BaseStringBuffer
{
// interface
public:
	typedef size_t size_type;
	enum {
		npos = -1
	};

	BaseStringBuffer( LPCTSTR	inString );
	BaseStringBuffer( LPCTSTR s1, LPCTSTR s2 );
	BaseStringBuffer( size_t	bufferSize );
	~BaseStringBuffer();
	
	LPTSTR		c_str()
		{ _ASSERT( m_pString ); return m_pString; }
	LPCTSTR		c_str() const
		{ _ASSERT( m_pString ); return m_pString; }
	size_t		length() const
		{ return m_length; }
	size_t		bufferSize() const
		{ return m_bufferSize; }
	HRESULT		copy( LPCTSTR );
	HRESULT		concatenate( LPCTSTR );
	HRESULT		concatenate( _TCHAR );

	size_type	find_last_of(_TCHAR c) const;
	size_type	find_first_of(_TCHAR c) const;
	LPTSTR		substr( size_type b, size_type e ) const;

// implementation
protected:
	
	HRESULT	growBuffer( size_t inMinSize );
	size_t	m_bufferSize;
	size_t	m_length;
	LPTSTR	m_pString;
};

class StringBuffer : public BaseStringBuffer, public CRefCounter
{
public:
	StringBuffer( LPCTSTR inString ) : BaseStringBuffer( inString ){};
	StringBuffer( size_t bufferSize ) : BaseStringBuffer( bufferSize ){};
	StringBuffer( LPCTSTR s1, LPCTSTR s2 ) : BaseStringBuffer( s1, s2 ){};

private:
	~StringBuffer(){};
};

class String : public TRefPtr< StringBuffer >
{
public:

	typedef BaseStringBuffer::size_type size_type;
	enum {
		npos = BaseStringBuffer::npos
	};

							String();
							String( const String& );
							String( LPCTSTR );
							String( StringBuffer* pT ){ Set( pT ); }
				String&		operator=( StringBuffer* );
				String&		operator=( const String& );
				String&		operator=( LPCTSTR );
				String&		operator+=( const String& );
				String&		operator+=( LPCTSTR );
				String		operator+( const String& ) const;
				String		operator+( LPCTSTR ) const;
				String		operator+( _TCHAR ) const;
				bool		operator==( const String& ) const;
				bool		operator==( LPCTSTR ) const;
				bool		operator!=( const String& s ) const { return !( *this == s ); }
				bool		operator!=( LPCTSTR s ) const { return !( *this == s ); }
				bool		operator<( const String& ) const;
				bool		operator<( LPCTSTR ) const;
				int			compare( const String& s) const { return _tcscmp( c_str(), s.c_str() ); }
				int			compare( LPCTSTR s ) const { return _tcscmp( c_str(), s ); }
				int			compare( size_t, size_t, const String& ) const;
				size_t		find( _TCHAR ) const;
				LPCTSTR		c_str() const { return m_pT->c_str(); };
				LPTSTR		c_str(){ return m_pT->c_str(); }
				size_t		length() const { return m_pT->length(); }
				size_t		size() const { return length(); }
				size_t		bufferSize() const { return m_pT->bufferSize(); }
				_TCHAR		operator[](size_t s) const { return c_str()[s]; }
				_TCHAR		charAt( size_t s ) const { return c_str()[ s ]; }
				SHORT		toInt16() const { return (SHORT)_ttoi(c_str()); }
				LONG		toInt32() const { return _ttol(c_str()); }
				ULONG		toUInt32() const { return (ULONG)_ttol(c_str()); }
				float		toFloat() const { USES_CONVERSION; return (float)atof(T2CA(c_str())); }
				double		toDouble() const { USES_CONVERSION; return atof(T2CA(c_str())); }
				
				size_type	find_last_of(_TCHAR c) const
				{
					return m_pT->find_last_of(c);
				}
				size_type	find_first_of(_TCHAR c) const
				{
					return m_pT->find_first_of(c);
				}
				String		substr( size_type b, size_type e ) const
				{
					LPTSTR pStr = m_pT->substr(b,e);
					String s( pStr );
					delete[] pStr;
					return s;
				}

	static		String		fromInt16( SHORT );
	static		String		fromInt32( LONG );
	static		String		fromFloat( float );
	static		String		fromDouble( double );
			
private:
			StringBuffer&	operator*(){ return *m_pT; }
			StringBuffer*	operator->(){ return m_pT; }
};

String operator+( LPCTSTR lhs, const String& rhs );

#endif // !_MYSTRING_H_
