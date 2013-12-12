//---------------------------------------------------------------------------
//	StrMap.h
//
//	Template class for a map of strings to something
//---------------------------------------------------------------------------
#pragma once
#ifndef _STRMAP_H_
#define _STRMAP_H_

#include "MyString.h"
#include <utility>
#include <algorithm>
#include "myvector.h"

template< class T >
struct StringPairEqual
{
	StringPairEqual( const String& str)
		:	m_rstr( str ) {}
	bool	operator()(
		const pair<String, T>& rhs )
	{
		return ( m_rstr == rhs.first );
	}
private:
	const String&	m_rstr;
};

template< class T >
struct StringPairCompare
{
	int operator()(
		const pair<String, T>&	lhs,
		const pair<String, T>&	rhs )
	{
		return lhs.first.compare( rhs.first );
	}
};

// template function--finds the first element n for which cmp(val,vec[n]) is true and
// cmp(val,vec[n-1]) is false
template< class T, class Compare >
TVector<T>::iterator
binary_find(
	TVector<T>&	vec,
	const T&	val,
	Compare&	cmp )
{
	TVector<T>::iterator iter = vec.begin();

	if ( vec.size() > 0 )
	{
		size_t top = vec.size() - 1;
		size_t bot = 0;
		size_t mid = top >> 1;

		while ( top != bot )
		{
			int c = cmp( val, vec[mid] );
			if ( c > 0 )
			{
				// val > vec[mid]
				bot = mid + 1;
				mid = ( top + bot ) >> 1;
			}
			else if ( c < 0 )
			{
				// val < vec[mid]
				top = mid;
				mid = ( top + bot ) >> 1;
			}
			else
			{
				// val == vec[mid]
				top = bot = mid;
			}
		}
		iter = vec.begin() + mid;
		if ( cmp( val, vec[mid] ) > 0 )
		{
			iter++;
		}
	}
	
	return iter;
}

template< class T >
class TStringMap
{
public:
	typedef String								key_type;
	typedef	T									referent_type;
	typedef pair<key_type,referent_type>	value_type;
	typedef TVector<value_type>					vector_type;
	typedef vector_type::reference				reference;
	typedef vector_type::iterator				iterator;
	typedef vector_type::const_iterator			const_iterator;

#if 0
	class iterator
	{
	public:
					iterator();

		iterator&	operator++();
		iterator	operator++(int);
		iterator&	operator--();
		iterator	operator--(int);
		bool		operator==( const iterator& ) const;
		bool		operator!=( const iterator& ) const;
		reference	operator*() const;

	private:
		explicit	iterator( const vector_type::iterator& );
		vector_type::iterator	  m_iter;
		friend dwvector;
		friend const_iterator;
	};					

	class const_iterator
	{
	public:
						const_iterator();
						const_iterator( const iterator& );

		const_iterator&	operator++();
		const_iterator	operator++(int);
		const_iterator&	operator--();
		const_iterator	operator--(int);
		bool			operator==( const const_iterator& ) const;
		bool			operator!=( const const_iterator& ) const;
		const_reference	operator*() const;

	private:
		explicit		const_iterator( const vector_type::const_iterator& );
		vector_type::const_iterator	m_iter;
		friend dwvector;
	};

    typedef	reverse_bidirectional_iterator<iterator,
		value_type, reference, value_type*,
		difference_type>					reverse_iterator;

    typedef	reverse_bidirectional_iterator<const_iterator,
		value_type, const_reference, const value_type*,
		difference_type>					const_reverse_iterator;
#endif	// if 0

	TStringMap(){};
	~TStringMap(){};

	iterator				begin() { return m_vec.begin(); }
	const_iterator			begin() const { return m_vec.begin(); }
	iterator				end() {return m_vec.end();}
	const_iterator			end() const {return m_vec.end();}
	iterator				find( const String& );
	pair<iterator, bool>	insert(const value_type& x);

	referent_type& 			operator[]( const String& );

	void					clear(){ m_vec.clear(); }
	size_t					size() const { return m_vec.size(); }
private:
	vector_type				m_vec;
};

#if 0
template<class T>
inline
TStringMap<T>::iterator
TStringMap<T>::begin()
{
	return m_vec.begin();
}

template<class T>
inline
TStringMap<T>::const_iterator
TStringMap<T>::begin()
const
{
	return m_vec.begin();
}

template<class T>
inline
TStringMap<T>::iterator
TStringMap<T>::end()
{
	return m_vec.end();
}

template<class T>
inline
TStringMap<T>::const_iterator
TStringMap<T>::end()
const
{
	return m_vec.end();
}

#endif

template<class T>
inline
TStringMap<T>::iterator
TStringMap<T>::find(
	const String& str )
{
	value_type vt(str,T());
	iterator iter = binary_find( m_vec, vt, StringPairCompare<T>() );
	StringPairEqual<T> spe(str);
	if ( ( iter != m_vec.end() ) && spe(*iter) )
	{
	}
	else
	{
		iter = m_vec.end();
	}
	return iter;
}

template<class T>
inline
pair< TStringMap<T>::iterator, bool >
TStringMap<T>::insert(
	const TStringMap<T>::value_type&	val )
{
	bool inserted = false;
	iterator iter = binary_find( m_vec, val, StringPairCompare<T>() );
	StringPairEqual<T> spe(val.first);
	if ( ( iter != m_vec.end() ) && spe(*iter) )
	{
	}
	else
	{
		inserted = true;
		iter = m_vec.insert( iter, val );
	}
	return pair<TStringMap<T>::iterator, bool>( iter, inserted );
}

template<class T>
inline
T&
TStringMap<T>::operator[](
	const String&	s )
{
	value_type vt(s,T());
	iterator iter = binary_find( m_vec, vt, StringPairCompare<T>() );
	StringPairEqual<T> spe(s);
	if ( ( iter != m_vec.end() ) && spe(*iter) )
	{
	}
	else
	{
		iter = m_vec.insert( iter, vt );
	}
	return (*iter).second;
}

// a lockable map template
template< class T >
class TSafeStringMap : public TStringMap<T>, public CComAutoCriticalSection
{
};
		
#endif	// !_STRMAP_H_
