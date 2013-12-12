<html>

<%
	application.lock

	if IsEmpty(application("CWWeather")) then
		Set CWWeather = Server.CreateObject("CWWeatherMonitor.ClassCWWeatherServer")
		set application("CWWeather") = CWWeather
	else
		set CWWeather = application("CWWeather")
	end if
	application.unlock

	CWWeather.CommPort = 1
	CWWeather.CrcFile = "c:\ni\crc.dat"
%>

<BODY TEXT="#000000" BGCOLOR="#FFFFFF" LINK="#0000EE" VLINK="#551A8B" ALINK="#FF0000">

<head><title>Real Time Weather Data</title></head>
<h3>Davis Intruments Weather Wizard III</h3>

</BODY>
<font face="courier new">
The weather conditions are:<br>
Last Updated..........<%= CWWeather.LastUpdate %><br>
<br>
Outside Temperature...<%= CWWeather.TempOutside %> F<br>
Windchill Temperature.<%= CWWeather.TempOutsideWindChill %> F<br>
Wind Speed............<%= CWWeather.WindSpeed %> MPH<br>
Wind Direction........<%= CWWeather.WindDirection %> Degrees<br>


</font>
</html>
