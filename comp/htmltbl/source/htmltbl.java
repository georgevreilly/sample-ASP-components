/*
 * htmlTbl
 *
 * output an HTML-formatted table from database inputs
 *
 * Copyright    (c)    1997    Microsoft Corporation
 */

package IISSample;

import com.ms.com.*;
import com.ms.mtx.*;
import com.ms.asp.*;
import stdole2.*;

import java.io.*;
import msado15.*;   // Microsoft OLE DB ActiveX Data Objects 1.0 Library

// Context is a class to retrieve and use server intrinsics.  This replaces
// the OnStartPage and OnEndPage methods formerly required for objects that
// need access to the instrinsics.

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


/*
 * htmlTbl is a simple java class for outputting HTML tables
 */

class htmlTbl 
{
    public boolean	Borders = true;
    public boolean	HeadingRow = true;
    public String	Caption = "";
    public String	CaptionStyle = "";

    public void AutoFormat(_Recordset r) throws ComFailException
    {
        try
        {
			Context cxt = new Context();
			if ( ! cxt.Init( Context.get_Response ) )
			{
				throw new ComFailException();
			}

            Variant idx = new Variant();
            
            // if empty result set, return a useful message
            if (r.getEOF())
            {
                Variant x = new Variant();
                x.putString("<h2>?EOF on result set</h2>");
                cxt.Response.Write(x);
                return;
            }
            
            String obuf = "<table";

            if (Borders)
                obuf += " border=1";
            obuf += ">\n";

            // <caption> is an Internet Explorer-specific extension to
            // HTML tables
            if (Caption != "")
            {
                obuf += "<caption";
                if (CaptionStyle != "")
                    obuf += " " + CaptionStyle;
                obuf += ">" + Caption + "</caption>\n";
            }
            
            // Conditionally put out headers
            if (HeadingRow)
            {
                Fields f = r.getFields();
                int end = f.getCount();
                obuf += "\n<tr>\n";

                for (int i = 0; i < end; i++)
                {
                    idx.putInt(i);
                    String fname = f.getItem(idx).getName();

                    obuf += "\t<th>";
                    if (fname == "")
                        obuf += "&nbsp;";
                    else
                        obuf += fname;
                    obuf += "</th>\n";
                }
                obuf += "</tr>\n";
            }
            
            // Put out each row of the table
            while (!r.getEOF())
            {
                Fields f = r.getFields();
                int end = f.getCount();
                obuf += "\n<tr>\n";

                for (int i = 0; i < end; i++)
                {
                    idx.putInt(i);
                    Variant fv = f.getItem(idx).getValue();

                    obuf += "\t<td>";
                    String tmp = fv.toString();
                    if (tmp == "")
                        obuf += "&nbsp;";
                    else
                        obuf += tmp;
                    obuf += "</td>\n";
                }
                obuf += "</tr>\n";
                r.MoveNext();
            }

            obuf += "\n</table>\n\n";
            
            Variant x = new Variant();
            x.putString(obuf);
            cxt.Response.Write(x);
        }
        catch (Throwable t)
        {
			Context cxt = new Context();
			if ( cxt.Init( Context.get_Response ) )
			{
	            Variant x = new Variant();
	            x.putString("<h2>Error: " + t.toString() + "</h2>");
	            cxt.Response.Write(x);
			}
        }
    }
}
