#pragma once
#ifndef _UTILTITY_H_
#define _UTILTITY_H_

CString	GetProfileString( LPCTSTR, LPCTSTR, LPCTSTR, LPCTSTR = NULL );
void CopyRef( VARIANTARG& varg );

template< class T >
void
DeleteList( T& list )
{
	T::iterator iter = list.begin();
	while ( iter != list.end() )
	{
		delete (*iter);
		iter++;
	}
	list.erase( list.begin(), list.end() );
}

// properly clear a vector of variantargs
template< class T >
void
DeleteVariantList( T& list )
{
	T::iterator iter = list.begin();
	while ( iter != list.end() )
	{
		if ( (*iter).vt & VT_BYREF )
		{
			free((*iter).byref);
		}
		::VariantClear( &(*iter) );
		++iter;
	}
	list.erase( list.begin(), list.end() );
}

template< class T1, class T2 >
void
CopyVariantList( T1& dest, T2& src )
{
	DeleteVariantList( dest );

	T1::iterator iter = src.begin();
	while ( iter != src.end() )
	{
		VARIANTARG varg;
		::VariantInit( &varg );
		::VariantCopy( &(*iter), &varg );
		if ( varg.vt & VT_BYREF )
		{
			CopyRef( varg );
		}
		dest.push_back( varg );
		iter++;
	}
}


#endif