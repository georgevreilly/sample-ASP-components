package IISSample;

import java.net.URL;
import java.net.URLConnection;
import java.net.MalformedURLException;

import java.io.*;
import java.io.IOException;
import java.io.InputStream;

//
//
// Asp2Htm
//
//

class Asp2Htm 
{
	URL myURL = null;
	URLConnection myURLConnection = null;
    String sData = "<no data>";
    String sTitle = "<no title>";
    String sBody = "<no body>";
    boolean fGottenData = false;

	public void URL(String tempURL)
	{
		
		try
		{
			myURL = new URL(tempURL);
		}
		catch (MalformedURLException e)
		{
		}
		
		try
		{
			myURLConnection = myURL.openConnection();
		}
		catch (IOException e)
		{
		}
	
	}

    public String Title()
    {
        GetData();

        return sTitle;
    }
    
    public String Body()
    {
        GetData();

        return sBody;
    }
    
	public String File()
	{
		return myURL.getFile();
	}

	public String Host()
	{
		return myURL.getHost();
	}

	public int Port()
	{
		return myURL.getPort();
	}

	public String Protocol()
	{
		return myURL.getProtocol();
	}

	public String Ref()
	{
		return myURL.getRef();
	}

	public String ContentEncoding()
	{
		return myURLConnection.getContentEncoding();
	}

	public int ContentLength()
	{
		return myURLConnection.getContentLength();
	}

	public String ContentType()
	{
		return myURLConnection.getContentType();
	}

	public long Date()
	{
		return myURLConnection.getDate();
	}
	
	public long Expiration()
	{
		return myURLConnection.getExpiration();
	}
	
	public String LastModified()
	{
		return myURLConnection.getHeaderField("Last-Modified");
	}
	
	public String Server()
	{
		return myURLConnection.getHeaderField("Server");
	}

	public boolean GetData()
	{
        if (fGottenData)
            return true;

		// REVIEW: this could be large
		int cb =  ContentLength();

		if (cb < 0)
			cb = 16000; // no Content-Length specified, so guess

		byte bt[]= new byte[cb];
		InputStream inStream = null;
		String st = new String();

		try
		{
			inStream = myURLConnection.getInputStream();
		}
		catch (IOException e)
		{
            return false;
		}

		try
		{
			do
			{
				cb = inStream.read(bt);
				if (cb > 0)
				{
					String stBuff =  new String(bt, 0);
					st = st.concat(stBuff.substring(0, cb));
				}
			} while (cb > 0);
		}
		catch (IOException e)
		{
            return false;
		}

        sData = st.toLowerCase();
        
		int iHtml = sData.indexOf("<html>");
		if ( iHtml >= 0 )
		{
			int iEndHtml = sData.indexOf("</html>");
			if ( iEndHtml > 0 )
			{
				sData = sData.substring(iHtml,iEndHtml + 7);
				st = st.substring(iHtml,iEndHtml + 7);
			}
		}

        int iHead = sData.indexOf("<head>");
        int iEndHead = -1;

        if (iHead >= 0)
        {
            int iTitle = sData.indexOf("<title>", iHead);

            if (iTitle > 0)
            {
                int iEndTitle = sData.indexOf("</title>", iTitle);

                if (iEndTitle > 0)
                {
                    iEndHead = sData.indexOf("</head>", iEndTitle);
                    sTitle = st.substring(iTitle + 7, iEndTitle);
                }
            }
        }
                
        int iBody = sData.indexOf("<body");

        if (iBody >= 0)
        {
            int iEndBody = sData.indexOf("</body>", iBody);

            if (iEndBody > 0)
                sBody = st.substring(iBody + 6, iEndBody);
            else
                sBody = st.substring(iBody + 6);
        }
        else
        {
            if (iEndHead > 0)
                sBody = st.substring(iEndHead + 7);
        }

        sData = st;
        fGottenData = true;

		return true;
	}

	public boolean WriteToFile(String sFileName)
    {
        if (!GetData())
            return false;
        
		File outFile = new File(sFileName);
        FileOutputStream outStream = null;

		try
        {
			outStream = new FileOutputStream(outFile);
        }
		catch (IOException ioe)
        {
			System.out.println("Could not open output file: " + sFileName);
			return false;
		}

        PrintStream prStream = null;

		prStream = new PrintStream(outStream);

        prStream.print(sData);
        prStream.close();
        
        return true;
	}
}

