<html>

<head>
<title>Testing NextLink</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing NextLink</h1>

page3
<%
  Set nextLink = Server.CreateObject("IISSample.NextLink.1")
%>
<p>
<a href=<%=nextLink.GetNextURL("NextLink.txt")%>>Next</a>
<p>
<a href=<%=nextLink.GetPreviousURL("NextLink.txt")%>>Previous</a>
</body>
</html>

