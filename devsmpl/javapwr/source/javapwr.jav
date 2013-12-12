/*
 *
 * JavaPwr
 *
 */

import com.ms.com.*;
import asp.*;

class JavaPwr 
{
    private IRequest           m_objRequest = null;
    private IResponse          m_objResponse = null;
    private IServer            m_objServer = null;
    private ISessionObject     m_objSession = null;
    private IApplicationObject m_objApplication = null;
    private static final int   E_NOINTERFACE  = 0x80004002;

    // This optional method is called by ASP whenever a page containing a
    // JavaPwr object is loaded by the user's browser.  Note that
    // OnStartPage is not called for application-level objects.  If the
    // object is created by a method other than a call to
    // Server.CreateObject or <OBJECT RUNAT=SERVER ...>, then OnStartPage
    // might not be called.  If you rely on interfaces obtained through
    // IScriptingContext in OnStartPage, you should always check that those
    // interfaces are correctly initialized in the routines that use them.
    public void OnStartPage(IScriptingContext objScriptContext)
    {
        m_objRequest     = objScriptContext.getRequest();
        m_objResponse    = objScriptContext.getResponse();

        // The remaining pointers to built-in objects are not used in this
        // sample, but are left in for completeness.
        m_objServer      = objScriptContext.getServer();
        m_objSession     = objScriptContext.getSession();
        m_objApplication = objScriptContext.getApplication();
    }
    
    // This optional method is called by ASP whenever a page containing a
    // JavaPwr object is unloaded by the user's browser.  You should
    // release any interfaces obtained in OnStartPage here, as they will
    // not be valid outside the scope of OnStartPage/OnEndPage.
    public void OnEndPage()
    {
        m_objRequest     = null;
        m_objResponse    = null;
        m_objServer      = null;
        m_objSession     = null;
        m_objApplication = null;
    }

    public String myProperty = "Java Power Component";

    String myMethod(String strIn)
    {
        return strIn.toUpperCase();
    }

    // Get the name of the current script
    String myPowerProperty()
        throws ComFailException
    {
        if (m_objRequest == null)
            throw new ComFailException(E_NOINTERFACE);

        IRequestDictionary serverVariables = m_objRequest.getServerVariables();
        Variant v = serverVariables.getItem(new Variant("SCRIPT_NAME"));
        return v.toString();
    }

    // Write one message if the user's browser is MS Internet Explorer;
    // another for any other browser
    void myPowerMethod()
        throws ComFailException
    {
        if (m_objRequest == null || m_objResponse == null)
            throw new ComFailException(E_NOINTERFACE);

        IRequestDictionary serverVariables = m_objRequest.getServerVariables();
        Variant v = serverVariables.getItem(new Variant("HTTP_USER_AGENT"));
        Variant v2 = new Variant();

        if (v.toString().indexOf("MSIE") > 0)
        {
            v2.putString("You are using a very powerful browser!");
        }
        else
        {
            v2.putString("Try Internet Explorer today!");
        }
        m_objResponse.Write(v2);
    }
}
