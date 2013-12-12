// Power.h : header file
//

#include <asptlb.h>


/////////////////////////////////////////////////////////////////////////////
// CPower command target

class CPower : public CCmdTarget
{
    DECLARE_DYNCREATE(CPower)

    CPower();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CPower)
    public:
    virtual void OnFinalRelease();
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CPower();

    // Generated message map functions
    //{{AFX_MSG(CPower)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
    DECLARE_OLECREATE(CPower)

    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CPower)
    afx_msg BSTR GetMyProperty();
    afx_msg void SetMyProperty(LPCTSTR lpszNewValue);
    afx_msg BSTR GetMyPowerProperty();
    afx_msg BSTR MyMethod(LPCTSTR ptszIn);
    afx_msg long MyPowerMethod();
    afx_msg long OnStartPage(LPDISPATCH pdisp);
    afx_msg long OnEndPage();
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()

    void _ReleaseInterfaces();

// Member data
    BOOL                m_fOnStartPageCalled;   // OnStartPage successful?
    CString             m_strMyProperty;        // myProperty

    IResponse*          m_piResponse;           // Response Object
    IRequest*           m_piRequest;            // Request Object
    IServer*            m_piServer;             // Server Object
    ISessionObject*     m_piSession;            // Session Object
    IApplicationObject* m_piApplication;        // Application Object
};

/////////////////////////////////////////////////////////////////////////////
