<html>

<head>
<title>Testing SumInfo</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing SumInfo</h1>

<a href=SumInfo.asp>View Compact Format</a>
<BR>
<%
Set SumInfos = Server.CreateObject("IISSample.SummaryInfos")
SumInfos.Style = 1
SumInfos.SetFileSpec ".", "*.doc"
SumInfos.Write
%>

</body>
</html>

