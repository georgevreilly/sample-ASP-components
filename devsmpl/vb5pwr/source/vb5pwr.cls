VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END

Attribute VB_Name = "VB5Power"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Dim gsmyProperty As String

Dim gmyRequest As Request, _
    gmyResponse As Response, _
    gmyServer As Server, _
    gmySession As Session, _
    gmyApplication As Application
    
Private Sub Class_Initialize()
    
    gsmyProperty = "Visual Basic 5 Power Component"
    
End Sub

Public Property Get myProperty() As String
    
    myProperty = gsmyProperty
    
End Property

Public Property Let myProperty(ByVal sNewValue As String)
    
    gsmyProperty = sNewValue
    
End Property

Public Function myMethod(ByVal myString As String) As String

    myMethod = UCase(myString)
    
End Function

' This optional method is called by ASP whenever a page containing a
' VB5Pwr object is loaded by the user's browser.  Note that
' OnStartPage is not called for application-level objects.  If the
' object is created by a method other than a call to
' Server.CreateObject or <OBJECT RUNAT=SERVER ...>, then OnStartPage
' might not be called.  If you rely on interfaces obtained through
' IScriptingContext in OnStartPage, you should always check that those
' interfaces are correctly initialized in the routines that use them.
' VB will do this under the covers for you.
Public Function OnStartPage(myScriptingContext As ScriptingContext)
    
    Set gmyRequest = myScriptingContext.Request
    Set gmyResponse = myScriptingContext.Response
    Set gmyServer = myScriptingContext.Server
    Set gmySession = myScriptingContext.Session
    Set gmyApplication = myScriptingContext.Application
    
End Function

' This optional method is called by ASP whenever a page containing a
' VB5Pwr object is unloaded by the user's browser.  You should
' release any interfaces obtained in OnStartPage here, as they will
' not be valid outside the scope of OnStartPage/OnEndPage.
Public Function OnEndPage()
    
    Set gmyRequest = Nothing
    Set gmyResponse = Nothing
    Set gmyServer = Nothing
    Set gmySession = Nothing
    Set gmyApplication = Nothing
    
End Function

Public Function myPowerMethod()

    If InStr(gmyRequest.ServerVariables("HTTP_USER_AGENT"), "MSIE") > 0 Then
        gmyResponse.Write "You are using a very powerful browser."
    Else
        gmyResponse.Write "Try Internet Explorer today!"
    End If
    
End Function

Public Property Get myPowerProperty() As String
    
    myPowerProperty = gmyRequest("SCRIPT_NAME")
    
End Property
