<HTML>

<HEAD>
<TITLE>Registry Access Component Sample Script</TITLE> 
</HEAD> 
<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">
<H1>Registry Access Component</H1>

This Active Server Pages script demonstrates some of the capabilities
of the registry access component.  You will find it much more edifying
if you also read the source for this page.  Note that using your
browser's View Source command on this page will not show you the
script itself, it will show you the output of the script.

<p>
First, we create an instance of the registry component.

<%
 ' Set to a large value so that we can step through this in DevStudio.
 ' It's not needed if we're not interactively debugging this page.
 Server.ScriptTimeout = 600 ' seconds
 Set reg = Server.CreateObject("IISSample.RegistryAccess")
%>



<h2>Reading the Registry</h2>

In this part of the script, we examine some values in the registry.

<%
 ' Get various values
 env = "HKEY_CURRENT_USER\Environment\"
 temp = env & "TEMP"
 tmp = env & "tmp"

 ' Get a string value
 tempDir = Reg.Get(temp)

 ' Get and expand the same string value
 tempDirExpand = Reg.GetExpand(temp)

%>

<p>
Your temporary directory is <% = tempDir %> (<% = tempDirExpand %>).<br>

<h2>Modifying the Registry</h2>

If you get an error at this point, then you do not have privileges to
modify the registry.  You must grant this .ASP file
Administrator privileges or you must make the IUSR_<i>machinename</i>
account an administrator (not recommended).  See the accompanying
documentation for more details.

<p>

<%
 ' Check setting different types
 MyCompany = "HKEY_LOCAL_MACHINE\Software\MyRegistryTest"

 ' set a numeric value and flush the changes to the registry to
 ' disk before continuing
 Reg.Set MyCompany & "\MyNumber", 12345, TRUE

 ' set a string value but do not force the registry to flush the write
 Reg.Set MyCompany & "\MyString", "hello, world", FALSE

 ' set an expandable string value
 MyPath = MyCompany & "\MyPath"
 Reg.SetExpand MyPath, "%windir%;%SystemRoot%\System32"

 ' check to see if the Get+ExpandString combo is the same as GetExpand
 Path = Reg.Get(MyPath)
 ExpandString = Reg.ExpandString(Path)
 PathExpand = Reg.GetExpand(MyPath)

 ' Check the value type on MyPath (should be "REG_EXPAND_SZ")
 TypeBefore = Reg.ValueType(MyPath)

 ' Now delete the MyPath value and check its value again (should be "")
 Reg.DeleteValue(MyPath)
 TypeAfter = Reg.ValueType(MyPath)

 ' Create a sub-subkey.  Note that we don't need to create the
 ' intermediate keys.
 Reg.Set MyCompany & "\foo\bar\quux", "subsubkey"
 quux = Reg.Get(MyCompany & "\foo\bar\quux")

 ' Blow away the test key and its values
 Reg.DeleteKey MyCompany
%>

Path = <% = Path %> <br>
PathExpand = <% = PathExpand %> <br>
ExpandString = <% = ExpandString %> <br>
TypeBefore = "<% = TypeBefore %>" <br>
TypeAfter = "<% = TypeAfter %>" <br>
quux = <% = quux %> <br>

<p>
Now let's copy some keys and then delete them.

<%
 MyTest = "hklm\Software\MyTest"
 Response.Write("Target directory, MyTest, is " & MyTest)

 Reg.CopyKey "HKLM\Software\Clients", MyTest

 ' If you comment out the DeleteKey below, you can examine the registry
 ' with regedt32 to see that the CopyKey really does work.

 ' Check to see if the key exists before and after deleting it.
 KeyExistsBefore = Reg.KeyExists(MyTest)
 Reg.DeleteKey MyTest
 KeyExistsAfter = Reg.KeyExists(MyTest)
%>

<p>
KeyExistsBeforeDelete = <% = KeyExistsBefore %> <br>
KeyExistsAfterDelete = <% = KeyExistsAfter %> <br>



<h2>Remote registries</h2>

This script does not demonstrate accessing a registry on a remote
machine, because it cannot possibly guess the name of a suitable
server on your network.




<%
 ' Destroy the object (doesn't unload the DLL)
  Set reg = Nothing
%>
</body>
</HTML>
