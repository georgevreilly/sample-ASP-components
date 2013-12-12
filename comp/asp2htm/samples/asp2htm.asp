<html>

<head>
<title>Testing Asp2Htm</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing Asp2Htm</h1>


<% Set h = Server.CreateObject("IISSample.Asp2Htm") %>

<%=h.URL( "http://localhost/default.asp" )%><BR>

<% if h.GetData() = false then %>

Improperly formed URL!

<% else %>

<%=h.Title()%><BR>

<%=h.Host()%><BR>

<%=h.Port()%><BR>

<%h.WriteToFile( "c:\temp\temp.html" ) %>
<% end if %>
</body>
</html>

