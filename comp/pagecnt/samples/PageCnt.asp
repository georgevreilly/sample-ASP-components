<HTML>
<HEAD><TITLE>Page Counter Example</TITLE></HEAD> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

This is a very simple demonstration of the Page Counter Object.

<%
 Set MyPageCount = Server.CreateObject("IISSample.PageCounter")
 MyPageCount.PageHit
 HitMe = MyPageCount.Hits

 if HitMe = 1000000 then
%>

<p>
You are the lucky <b>1,000,000th</b> Customer!!! <BR>

<% else %>

<p>
Sorry, you are only customer #<%=HitMe%> <BR>

<% end if %>

</BODY>
</HTML>
