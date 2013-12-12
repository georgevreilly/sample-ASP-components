/*
 *
 * JavaPwr
 *
 */

package IISSample;

import com.ms.com.*;
import com.ms.asp.*;
import com.ms.mtx.*;

class Context
{
	// initialization flags
	public static final int	get_Server		= 0x0001;
	public static final int	get_Response	= 0x0002;
	public static final int	get_Request		= 0x0004;
	public static final int	get_Session		= 0x0008;
	public static final int	get_Application	= 0x0010;

	public	IRequest			Request		= null;
	public	IResponse			Response	= null;
	public	ISessionObject		Session		= null;
	public	IServer				Server		= null;
	public	IApplicationObject	Application	= null;

	boolean	Init( int nFlags )
	{
		boolean rc = false;

		IGetContextProperties icp = (IGetContextProperties)MTx.GetObjectContext();
		if ( icp != null )
		{
			rc = true;
			if ( ( nFlags & get_Server ) == get_Server )
			{
				Server = (IServer)(icp.GetProperty("Server").getDispatch());
				if ( Server != null )
				{
				}
				else
				{
					rc = false;
				}
			}
			if ( ( nFlags & get_Response ) == get_Response )
			{	
				Response = (IResponse)(icp.GetProperty("Response").getDispatch());
				if ( Response != null )
				{
				}
				else
				{
					rc = false;
				}
			}
			if ( ( nFlags & get_Request ) == get_Request )
			{
				Request = (IRequest)(icp.GetProperty("Request").getDispatch());
				if ( Request != null )
				{
				}
				else
				{
					rc = false;
				}
			}
			if ( ( nFlags & get_Session ) == get_Session )
			{
				Session = (ISessionObject)(icp.GetProperty("Session").getDispatch());
				if ( Session != null )
				{
				}
				else
				{
					rc = false;
				}
			}
			if ( ( nFlags & get_Application ) == get_Application )
			{
				Application = (IApplicationObject)(icp.GetProperty("Application").getDispatch());
				if ( Application != null )
				{
				}
				else
				{
					rc = false;
				}
			}
		}
		return rc;
	}
};


class JavaPwr 
{
    private static final int   E_NOINTERFACE  = 0x80004002;

    public String myProperty = "Java Power Component";

    public String myMethod(String strIn)
    {
        return strIn.toUpperCase();
    }

    // Get the name of the current script
    public String myPowerProperty()
        throws ComFailException
    {
		Context cxt = new Context();
		if ( cxt.Init( Context.get_Request ) == false )
		{
            throw new ComFailException(E_NOINTERFACE);
		}

        IRequestDictionary serverVariables = cxt.Request.getServerVariables();
        Variant v = serverVariables.getItem(new Variant("SCRIPT_NAME"));
        return v.toString();
    }

    // Write one message if the user's browser is MS Internet Explorer;
    // another for any other browser
    public void myPowerMethod()
        throws ComFailException
    {
		Context cxt = new Context();
		if ( cxt.Init( Context.get_Request | Context.get_Response ) == false )
		{
            throw new ComFailException(E_NOINTERFACE);
		}

        IRequestDictionary serverVariables = cxt.Request.getServerVariables();
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
        cxt.Response.Write(v2);
    }
}
