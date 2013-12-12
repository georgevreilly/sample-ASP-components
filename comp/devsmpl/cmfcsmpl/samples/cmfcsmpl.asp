<HTML>

<HEAD>
<TITLE>Testing CMFCSmpl</TITLE> 
</HEAD> 

<H1>Testing CMFCSmpl</H1>

<% Set myobj = Server.CreateObject("IISSample.C++MFCSimple") %>
myProperty Value = <%= myobj.myProperty %><BR>

<% newvalue = "Simple" %>
Set myProperty to <%= newvalue %>
<% myobj.myProperty = newvalue %><BR>
myProperty Value is now: <%= myobj.myProperty %><BR>

<% mystring = "My String" %>
Call myMethod with <%= mystring %>: <%= myobj.myMethod(mystring) %><BR>

</HTML>
