VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "TextFmt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Option Explicit

Dim c_strNL As String * 2


Public Function About() As String
  About = "<BR><B><FONT SIZE=4 FACE=Arial>" & _
        "Text Formatter Server Component, Version 2.0<BR></FONT></B>" & _
        "<FONT SIZE=3 FACE=Arial>Visual Basic edition<BR></FONT>"
End Function


Public Sub WrapTextFromFile(ByVal strFile As String, ByVal cchColumnWidth As Integer)

    ' Input and output buffers
    '
    Dim strOutputLine   As String
    Dim strInputLine    As String
    
    ' Cache the Response and Server objects that we use.
    '
    Dim objResponse As Response
    Dim objServer   As Server
    Dim objContext  As ObjectContext
    Set objContext = GetObjectContext()
    Set objResponse = objContext("Response")
    Set objServer = objContext("Server")
    
    ' Open the file, exceptions will automatically propogate to the caller
    '    (Contrast to C++ & JAVA where we must explicitly propagate
    '     these exceptions)
    '
    Dim fdInput As Integer
    fdInput = FreeFile
    Open strFile For Input Access Read As fdInput
    
    ' Loop through each line in the file, and break the line into
    ' words, where our definition of word is a block of text separated
    ' by pace characters.  Note: this function ONLY breaks at spaces
    ' (not tabs or other esoteric whitespace)
    '
    Do While Not EOF(fdInput)
        '
        ' Read a line of text and trim at the left, then add a space at
        ' the end - this will make subsequent parsing easier.
        '
        Line Input #fdInput, strInputLine
        strInputLine = LTrim(strInputLine) & " "
        
        '
        ' This function's semantics is that blank lines are always
        ' reproduced in the text box as is, and are wrapped.
        ' When we see a blank line, then we immediately flush the output
        ' buffer, then write a blank line.
        '
        If strInputLine = " " Then
            If strOutputLine <> "" Then
                objResponse.Write objServer.HTMLEncode(strOutputLine) & c_strNL
                strOutputLine = ""
            End If
            
            objResponse.Write c_strNL
            GoTo LReadNext          ' Emulate C/C++ "Continue"
        End If
        
        '
        ' Loop through each word of input text.  To do this, iStart
        ' points to the beginning of the word, and iEnd points to the first
        ' whitespace character that marks the end of the word.  (The extra
        ' space we supplied insures that "iEnd" is always in range of
        ' strInputLine)
        '
        Dim iStart As Integer, iEnd As Integer, cchWord As Integer
    
        iStart = 1
        Do
            iEnd = InStr(iStart, strInputLine, " ")
            cchWord = iEnd - iStart
            
            ' See if the word will fit on this line. It will if there
            ' is enough room to append this word (do not compensate for
            ' the blank space because it appears at the end of the string.)
            '
            If Len(strOutputLine) + cchWord > cchColumnWidth Then
                '
                ' There is no room on this line, so flush strOutputLine
                '
                objResponse.Write objServer.HTMLEncode(strOutputLine) & c_strNL
                strOutputLine = ""
            End If
            
            ' Now append the word to the output line.  We know that the
            ' word will fit unless the word itself is too long, in which case
            ' the programmer is out of luck. (we just let the text area scroll
            ' for this case.)  Copy cchWord characterss + 1, which will copy
            ' the trailing blank.
            '
            strOutputLine = strOutputLine & Mid(strInputLine, iStart, cchWord + 1)
            
            ' "iEnd" points to the first non-blank character past the word -
            ' however, there may be sequences of more blanks, so skip past
            ' these as well.
            '
            ' NOTE: With short curcuit operators, this loop
            ' can be expressed more succinctly as:
            '
            '     DO WHILE iEnd < len(strInputLine)
            '              AND mid(strInputLine, iEnd, 1) = " "
            '         iEnd = iEnd + 1
            '     LOOP
            '
            ' but VB does not have such nice things YET.
            Do
                If iEnd > Len(strInputLine) Then Exit Do
                If Mid(strInputLine, iEnd, 1) <> " " Then Exit Do
                iEnd = iEnd + 1
            Loop
        
            ' Go back to get the next word.  iEnd now points to the
            ' beginning of the next word.
            '
            iStart = iEnd
        Loop While iStart <= Len(strInputLine)
LReadNext:
    Loop
    
    ' If we got here, we ran into EOF.  However, there still may be some
    ' text in strOutputLine. If there is, then flush it.
    '
    If strOutputLine <> "" Then
        objResponse.Write objServer.HTMLEncode(strOutputLine) & c_strNL
    End If
End Sub


Private Sub Class_Initialize()
    c_strNL = Chr(13) & Chr(10)
End Sub
