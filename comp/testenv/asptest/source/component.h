// Component.h: interface for the CComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENT_H__E52738A3_335E_11D1_8AFB_00C0F00910F9__INCLUDED_)
#define AFX_COMPONENT_H__E52738A3_335E_11D1_8AFB_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMethod;

class CComponent  
{
public:
	typedef enum {
		scope_Page,
		scope_Session,
		scope_Application
	} ScopeT;

	CComponent( CString& strIniFile );
	CComponent( CComponent& );
	virtual ~CComponent();

	bool			Initialize();
	void			StartTest();
	void			EndTest();
	void			Test();
	ScopeT			Scope() const { return m_scope; }
	const CString&	ProgID() const { return m_strProgID; }

private:
	// helper methods
	static bool		IsMethod( LPCTSTR );
	void			Test( IDispatch* );

	const CString		m_strIniFile;
	CString				m_strProgID;
	ScopeT				m_scope;
	vector<CMethod*>	m_methods;
	
	IDispatchPtr		m_pObj;
};

#endif // !defined(AFX_COMPONENT_H__E52738A3_335E_11D1_8AFB_00C0F00910F9__INCLUDED_)
