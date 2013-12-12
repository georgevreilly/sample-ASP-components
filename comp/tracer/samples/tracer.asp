<html>

<head>
<title>Testing Tracer</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing Tracer</h1>

<% Set trcr = Server.CreateObject( "IISSample.Tracer" ) %>
<% Set brwcap = Server.CreateObject( "MSWC.BrowserType" ) %>
<% trcr.Name = "BrowseCap Trace" %>
<% trcr.TimerStart %>

Browser capabilities:<BR>

Browser: <% =brwcap.browser %><BR>
Version: <% =brwcap.Version %><BR>
Major Version: <% =brwcap.majorver %><BR>
Minor Version: <%=brwcap.minorver%><BR>
frames: <%=brwcap.frames%><BR>

<% trcr.TimerSplit "split 1" %>

tables: <%=brwcap.tables%><BR>
cookies: <%=brwcap.cookies%><BR>
backgroundsounds: <%=brwcap.backgroundsounds%><BR>
vbscript: <%=brwcap.vbscript%><BR>

<% trcr.TimerTotal "Total 1" %>

javascript: <%=brwcap.javascript%><BR>
javaapplets: <%=brwcap.javaapplets%><BR>
ActiveXControls: <%=brwcap.ActiveXControls%><BR>
Win16: <%=brwcap.Win16%><BR>
beta: <%=brwcap.beta%><BR>

<% trcr.TimerSplit "split 2" %>

AK: <%=brwcap.AK%><BR>
SK: <%=brwcap.SK%><BR>
AOL: <%=brwcap.AOL%><BR>
Crawler: <%=brwcap.Crawler%><BR>
parent: <%=brwcap.parent%><BR>
platform: <%=brwcap.platform%><BR>

<% trcr.Trace "Done" %>

<% trcr.TimerStop %>

</body>
</html>

