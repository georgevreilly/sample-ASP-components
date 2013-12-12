<html>

<head>
<title>Testing htmlTble</title> 
</head> 

<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">

<h1>Testing htmlTable</h1>


<%
  Set Conn = Server.CreateObject("ADODB.Connection")
  Conn.Open "FILEDSN=NWind.dsn"

  SQL = "SELECT ProductName, UnitPrice, UnitsInStock, UnitsOnOrder " & _
        "  FROM Products" & _
        " ORDER BY ProductName"

  Set RS = Conn.Execute(SQL,numRows)

  Set oHtmlTable = Server.CreateObject("IISSample.htmlTbl") ' uses the ProgId
  oHtmlTable.Borders = True
  oHtmlTable.Caption = "<b>Product Information</b>"
  oHtmlTable.CaptionStyle = "align=left"
  oHtmlTable.AutoFormat(RS)
%>

</body>
</html>

