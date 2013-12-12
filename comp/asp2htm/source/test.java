package IISSample;

import java.io.*;
//
//
// Test
//
//

class Test 
{
	public static void main(String args[])
	{
		try
		{
			Asp2Htm nwTest = new Asp2Htm();

			nwTest.URL("http://joseg2");
			nwTest.GetData();
			nwTest.WriteToFile("f:/inetpub/wwwroot/temp.html");

			if (true) {
				System.out.println(nwTest.File());
				System.out.println(nwTest.Host());
				System.out.println(nwTest.Port());
				System.out.println(nwTest.Protocol());
				System.out.println(nwTest.ContentEncoding());
	//			System.out.println(nwTest.ContentLength());
				System.out.println(nwTest.ContentType());
				System.out.println(nwTest.Date());
				System.out.println(nwTest.Expiration());
				System.out.println(nwTest.LastModified());
				System.out.println(nwTest.Server());
			}
			if (false) {
				String stbody = nwTest.Body();
				System.out.println(stbody);
				System.out.println(stbody.length());
				System.out.println("That's All");
			}

        
			System.out.println("Title = " + nwTest.Title());
			System.out.println("\n\nBody = " + nwTest.Body());

			try
			{
				System.in.read();
			}
			catch (IOException e)
			{
				// ignore
			}
		}
		catch( Throwable t )
		{
			t.printStackTrace();
		}
	}
}

