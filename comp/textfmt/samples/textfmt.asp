<html><head>
<title>Text Formatter Server Component</title></head>
<BODY bgcolor="#FFFFFF" LINK="#000080" VLINK="#808080">
<% If Request.Form = "" Then %>

        <BR><B><FONT SIZE=4 FACE=Arial>
            Text Formatter Server Component, Version 1.0</FONT></B>
        <HR>

        <FONT FACE=Arial SIZE=2>
        <P>
        This application lets you edit some text files that are
        stored on the server.

        <FORM METHOD=Post ACTION="<%=Request.ServerVariables("SCRIPT_NAME")%>">

        <P>
        I would like to view the 
        <SELECT NAME=lang SIZE=1>
                <OPTION VALUE=VB   SELECTED> VB
                <OPTION VALUE=Java>          Java
                <OPTION VALUE=C++>           C++
        </SELECT>
        implementation.

        <P>
        Which file would you like to edit?
        <SELECT NAME=File SIZE=2>
                <OPTION VALUE=Intro.txt SELECTED> Introduction
                <OPTION VALUE=legal.txt> Legal
        </SELECT>

        <P>
        Edit the result in a text area
        <INPUT NAME=Width  SIZE=3 VALUE=50> columns wide and
        <INPUT NAME=Height SIZE=3 VALUE=10> rows high.

        <P>
        <INPUT TYPE=Submit>

        </FORM>
        </FONT>

<% Else %>

        <% On Error Resume Next %>

        <%
                Select Case Request("LANG")
                Case "VB"
                        ver = ""
                
                Case "C++"
                        ver = ".C++"
                
                Case "Java"
                        ver = ".Java"
                End Select

                Set TextWrap = Server.CreateObject("IISSample.TextFmt" & ver)

                Response.Write TextWrap.About
        %>

        <HR>
        <FORM>
            <!--NOTE: Do NOT indent the call to WrapTextFromFile!-->
        <TEXTAREA
             NAME="BookText"
             ROWS=<% =Request("Height")%>
             COLS=<% =Request("Width") %>>
<% TextWrap.WrapTextFromFile basename(Request.ServerVariables("Path_Translated")) & Request("File"), Request("Width") %>
        </TEXTAREA>
        </FORM>

        <%
        If Err Then
           Response.Write "<H2>Error: The server could not retrieve the " &_
                          "file you requested.  The response was: """ &_
                          Err.Description & """."
        End If
        %>
<% End If %>


<%
' Will raise an error if string contains no '\' characters.
'
Function basename(s)
        i = len(s)
        Do While mid(s, i, 1) <> "\"
                i = i - 1
        Loop

        basename = Left(s, i)
End Function
%>
</body></html>
