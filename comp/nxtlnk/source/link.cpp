// Link.cpp: implementation of the CLink class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NxtLnk.h"
#include "Link.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLink::CLink(
	const tstring&	strLink,
	const tstring&	strDesc )
	:	m_strLink( strLink ),
		m_strDesc( strDesc )
{
	m_urlType = UrlType( m_strLink );
}

CLink::~CLink()
{
}

bool
CLink::IsEqual(
	const tstring&	strLink ) const
{
	bool rc = false;

	switch ( m_urlType )
	{
		case urlType_LocalAbsolute:
		{
			rc = ( strLink == m_strLink );
		} break;

		case urlType_Relative:
		{
			tstring strRel=strLink;
			tstring::size_type p = strLink.find_last_of( _T('/') );
			if ( p != tstring::npos )
			{
				strRel = strLink.substr( p + 1, strLink.length() );
			}
			else
			{
				p = strLink.find_last_of( _T('\\') );
				if ( p != tstring::npos )
				{
					strRel = strLink.substr( p + 1, strLink.length() );
				}
			}
			if ( strRel == m_strLink )
			{
				rc = true;
			}
		} break;

		case urlType_Absolute:
		default:
		{
		} break;
	}
	return rc;
}

int
CLink::UrlType(
	const tstring&	strUrl )
{
	int urlType;

	const tstring slashSlash = _T("//");
	const tstring bslashBslash = _T("\\\\");

	if ( ( strUrl.compare( 0, 2, slashSlash ) == 0 ) ||
		( strUrl.compare( 0, 2, bslashBslash ) == 0 ) )
	{
		urlType = urlType_Absolute;
	}
	else if ( ( strUrl[0] == _T('\\') ) || ( strUrl[0] == _T('/') ) )
	{
		urlType = urlType_LocalAbsolute;
	}
	else
	{
		if ( strUrl.find( _T(':') ) != tstring::npos )
		{
			urlType = urlType_Absolute;
		}
		else
		{
			urlType = urlType_Relative;
		}
	}

	return urlType;
}

