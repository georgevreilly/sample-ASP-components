/*
 *
 * TextFmt
 *
 */

package IISSample;

import java.io.*;
import com.ms.com.*;
import com.ms.mtx.*;
import com.ms.asp.*;

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


class TextFmt 
    {
    private static final int DISP_E_EXCEPTION = 0x80020009;

    public String About()
        {
            return "<BR><B><FONT SIZE=4 FACE=Arial>" +
                "Text Formatter Server Component, Version 2.0<BR></FONT></B>" +
                "<FONT SIZE=3 FACE=Arial>Java edition<BR></FONT>";
        }

    // Send a line using Response.Write
    private void WriteLn(Context cxt, StringBuffer sb)
        {
        Variant varText = new Variant();
        if (sb == null)
            varText.putString("\r\n");
        else
            {
            sb.append("\r\n");
            varText.putString(cxt.Server.HTMLEncode(sb.toString()));
            }

        cxt.Response.Write(varText);
        }

    public void WrapTextFromFile(String strFile, int cchColumnWidth)
            throws ComFailException
        {
        FileInputStream fsInput = null; // place this var in scope for finally
		Context cxt = new Context();
		if ( cxt.Init( Context.get_Server | Context.get_Response ) == false )
		{
			// defaults to E_FAIL
			throw new ComFailException();
		}

        try
            {
            fsInput = new FileInputStream(strFile);
            DataInputStream dsInput = new DataInputStream(fsInput);

            // Loop through each line in the file, and break the line into
            // words, where our definition of word is a block of text separated
            // by pace characters.  Note: this function ONLY breaks at spaces
            // (not tabs or other esoteric whitespace)
            StringBuffer sbOutputLine = new StringBuffer(cchColumnWidth + 35);
            String strInputLine;

            while ((strInputLine = dsInput.readLine()) != null)
                {
                // trim spaces at the beginning, and add a space at the end
                // - this will make parsing easier
                strInputLine = strInputLine.trim() + " ";

                // This function's semantics is that blank lines are always
                // reproduced in the text box as is, and are wrapped.  When
                // we see a blank line, then we immediately flush the output
                // buffer, then write a blank line.
                if (strInputLine.equals(" "))
                    {
                    if (sbOutputLine.length() > 0)
                        {
                        WriteLn(cxt, sbOutputLine);  // send the rest of the buffer
                        sbOutputLine.setLength(0);
                        }

                    WriteLn(cxt, null);
                    continue;
                    }

                // Loop through each word of input text.  To do this, iStart
                // points to the beginning of the word, and iEnd points to
                // the first whitespace character that marks the end of the
                // word.  (The extra space we supplied insures that "iEnd" is
                // always in range of strInputLine)
                int iStart = 0;
                int iEnd, cchWord;
                do
                    {
                    iEnd = strInputLine.indexOf(' ', iStart);
                    cchWord = iEnd - iStart;

                    // See if the word will fit on this line. It will if
                    // there is enough room to append this word (do not
                    // compensate for the blank space because it appears at
                    // the end of the string.)
                    ///
                    if (sbOutputLine.length() + cchWord > cchColumnWidth)
                        {
                        // There is no room on this line, so flush sbOutputLine
                        WriteLn(cxt, sbOutputLine);
                        sbOutputLine.setLength(0);
                        }

                    // Now append the word to the output line.  We know that
                    // the word will fit unless the word itself is too long,
                    // in which case the programmer is out of luck. (we just
                    // let the text area scroll for this case.)  Copy cchWord
                    // characterss + 1, which will copy the trailing blank.
                    sbOutputLine.append(strInputLine.substring(iStart,++iEnd));

                    // "iEnd" points to the first non-blank character past
                    // the word - however, there may be sequences of more
                    // blanks, so skip past these as well.
                    while (iEnd < strInputLine.length()
                           && strInputLine.charAt(iEnd) == ' ')
                        ++iEnd;

                    iStart = iEnd;
                    } while (iStart < strInputLine.length());
                }

                // If we got here, we ran into EOF.  However, there still may
                // be some text in sbOutputLine. If there is, then flush it.
                if (sbOutputLine.length() > 0)
                    WriteLn(cxt, sbOutputLine);
            }
        catch (IOException e)
            {
            throw new ComFailException(DISP_E_EXCEPTION, e.toString());
            }
        finally
            {
            // Close the file always - note that closing a file can throw an
            // exception (unlikely but possible), so we need another
            // try/catch in the finally clause.  Also, fsInput will be NULL
            // if the finally clause is executed after a FileNotFound
            // exception was raised.
            try
                {
                if (fsInput != null)
                    fsInput.close();
                }
            catch (IOException e)
                {
                throw new ComFailException(DISP_E_EXCEPTION, e.toString());
                }
            }
        }
    };
