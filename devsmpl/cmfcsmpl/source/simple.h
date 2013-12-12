// Simple.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSimple command target

class CSimple : public CCmdTarget
{
    DECLARE_DYNCREATE(CSimple)

    CSimple();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSimple)
    public:
    virtual void OnFinalRelease();
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CSimple();

    // Generated message map functions
    //{{AFX_MSG(CSimple)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
    DECLARE_OLECREATE(CSimple)

    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CSimple)
    afx_msg BSTR GetMyProperty();
    afx_msg void SetMyProperty(LPCTSTR lpszNewValue);
    afx_msg BSTR MyMethod(LPCTSTR ptszIn);
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()

// Member data
    CString m_strMyProperty;
};

/////////////////////////////////////////////////////////////////////////////
