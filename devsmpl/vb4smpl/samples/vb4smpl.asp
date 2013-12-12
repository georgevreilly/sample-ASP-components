<HTML>

<HEAD>
<TITLE>Testing VB4Smpl</TITLE> 
</HEAD> 

<H1>Testing VB4Smpl</H1>

<% Set myobj = Server.CreateObject("IISSample.VB4Simple") %>
myProperty Value = <%= myobj.myProperty %><BR>

<% newvalue = "Simple" %>
Set myProperty to <%= newvalue %>
<% myobj.myProperty = newvalue %><BR>
myProperty Value is now: <%= myobj.myProperty %><BR>

<% mystring = "My String" %>
Call myMethod with <%= mystring %>: <%= myobj.myMethod(mystring) %><BR>

</HTML>
