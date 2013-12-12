// Method.h: interface for the CMethod class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_METHOD_H__E52738A4_335E_11D1_8AFB_00C0F00910F9__INCLUDED_)
#define AFX_METHOD_H__E52738A4_335E_11D1_8AFB_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMethod  
{
public:
	CMethod( LPCTSTR, LPCTSTR );
	CMethod( CMethod& );
	virtual ~CMethod();

	bool	Initialize();
	HRESULT	Invoke( IDispatch* pDisp );

private:
	bool			ParseParam( LPCTSTR );
	DISPID			GetDispID( IDispatch* pDisp ) const;

	const CString		m_strIniFile;
	const CString		m_strName;
	const _bstr_t		m_bstrName;
	vector<VARIANTARG>	m_params;
	WORD				m_wInvokeFlags;
};

#endif // !defined(AFX_METHOD_H__E52738A4_335E_11D1_8AFB_00C0F00910F9__INCLUDED_)
