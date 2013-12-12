VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END

Attribute VB_Name = "VB4Simple"
Attribute VB_Creatable = True
Attribute VB_Exposed = True
Option Explicit

Dim gsmyProperty As String

Private Sub Class_Initialize()
    
    gsmyProperty = "Visual Basic 4 Simple Component"
    
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

