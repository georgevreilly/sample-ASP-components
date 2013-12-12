// lock.h : locking classes for BrowserCap

#pragma once

#ifndef _LOCK_H_
#define _LOCK_H_



// a stack-based auto-lock template
template< class T >
class TLock
{
public:

	TLock( T& t )
		:	m_t( t )
	{
		m_t.Lock();
	}
	~TLock()
	{
		m_t.Unlock();
	}
private:
	T&	m_t;
};

typedef TLock<CComAutoCriticalSection>	CLock;

#endif
