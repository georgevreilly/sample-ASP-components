#pragma once

#ifndef _INIFILE_H_
#define _INIFILE_H_

#include "rdwrt.h"

class CIniFile
{
public:
	bool	Open( const String& );
	void	Close();

	String	GetString( LPCTSTR, LPCTSTR, LPCTSTR = NULL );

private:
	typedef map< String, String >	CacheMapT;

	String	GetStringFromFile( LPCTSTR, LPCTSTR, LPCTSTR );

	String		m_strFile;
	CacheMapT	m_cache;
	CReadWrite	m_rw;
};

#endif
