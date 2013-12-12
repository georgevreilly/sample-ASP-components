<%
 Server.ScriptTimeout = 600 ' seconds
 Set reg = Server.CreateObject("IISSample.RegistryAccess")
%>

<%
Sub EchoSubkeys(strKeyName)

    Response.Write "<h1>Get subkeys of " & strKeyName & "</h1>"

    Set Subkeys = reg.SubKeys(strKeyName)

    Response.Write "<b># subkeys = " & Subkeys.Count & "</b><br>"

    For Each k in Subkeys
        Response.Write k & "<br>"
    Next

    Response.Write "<b>Items</b><br>"

    For i = 1 to Subkeys.Count
        Response.Write Subkeys.Item(i) & "<br>"
    Next

    Response.Write "<b>Named subscripts</b><br>"

    For Each k in Subkeys
        Response.Write Subkeys(k) & "<br>"
    Next

    Response.Write "<b>Implicit subscripts</b><br>"

    Response.Write Subkeys("Virtual Roots") & "<br>"
    Response.Write Subkeys(1) & "<br>"

    ' Response.Write "<b>Invalid indexes</b><br>"
    ' Response.Write Subkeys("asdfasdVirtual Roots") & "<br>"
    ' Response.Write Subkeys(17) & "<br>"

End Sub
%>

<%
Sub EchoValues(strKeyName)

    Response.Write "<h1>Get values of " & strKeyName & "</h1>"

    Set Values = reg.Values(strKeyName)

    Response.Write "<b># subkeys = " & Values.Count & "</b><br>"

    Response.Write  "<table>Values Collection"
    Response.Write  "<TR><TH align=left>Name</TH>" & _
		        "<TH align=left>Value</TH></TR>"
      For Each k in Values
        Response.Write "<TR><TD>" & k.Name  & "</TD>" & _
		           "<TD>" & k.Value & "</TD></TR>"
      Next
    Response.Write  "</table>"

    Response.Write "<b>Default Values</b><br>"

    For Each k in Values
        Response.Write k & "<br>"
    Next

    Response.Write "<b>Items</b><br>"

    For i = 1 to Values.Count
        Response.Write Values.Item(i) & " = " & Values.Item(i).Value & "<br>"
    Next

    Response.Write "<b>Named subscripts</b><br>"

    For Each k in Values
        Response.Write Values(k) & " = " & Values(k).Value & "<br>"
    Next

    Response.Write "<b>Implicit subscripts</b><br>"

    Response.Write Values(1) & "<br>"

    ' Response.Write "<b>Invalid indexes</b><br>"
    ' Response.Write Subkeys("asdfasdVirtual Roots") & "<br>"
    ' Response.Write Subkeys(117) & "<br>"

End Sub
%>

Hello.<br>

<%
 w3Params = "HKLM\SYSTEM\CurrentControlSet\Services\W3SVC\Parameters"

 EchoSubkeys w3Params

 EchoValues w3Params

 Set reg = Nothing
%>

Goodbye.<br>
