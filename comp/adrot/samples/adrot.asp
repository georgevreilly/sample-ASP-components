<html>

<head>
<title>Testing AdRotator</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing AdRotator</h1>


<%
  Set adRot = Server.CreateObject("IISSample.AdRotator.1")
  adRot.TargetFrame = "target_frame"
  adRot.Border=1
  adRot.Clickable=TRUE
%>
<%=adRot.GetAdvertisment("ads.txt")%>
</body>
</html>

