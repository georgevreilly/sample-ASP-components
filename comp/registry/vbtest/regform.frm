VERSION 5.00
Begin VB.Form RegForm 
   Caption         =   "RegObj Demo"
   ClientHeight    =   7245
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10545
   LinkTopic       =   "Form1"
   ScaleHeight     =   7245
   ScaleWidth      =   10545
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox ValueType 
      Height          =   375
      Left            =   2400
      TabIndex        =   11
      Text            =   "?"
      Top             =   5160
      Width           =   1215
   End
   Begin VB.ListBox LB_Value 
      Height          =   1230
      Left            =   360
      TabIndex        =   9
      Top             =   5760
      Width           =   9975
   End
   Begin VB.TextBox CountSubKeys 
      Height          =   375
      Left            =   2400
      TabIndex        =   8
      Text            =   "0"
      Top             =   1440
      Width           =   1215
   End
   Begin VB.TextBox CountValues 
      Height          =   375
      Left            =   2400
      TabIndex        =   7
      Text            =   "0"
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox KeyName 
      Height          =   495
      Left            =   360
      TabIndex        =   6
      Top             =   120
      Width           =   9975
   End
   Begin VB.ListBox LB_EnumValues 
      Height          =   1230
      Left            =   360
      TabIndex        =   3
      Top             =   3840
      Width           =   9975
   End
   Begin VB.ListBox LB_EnumSubkeys 
      Height          =   1230
      Left            =   360
      TabIndex        =   2
      Top             =   1920
      Width           =   9975
   End
   Begin VB.CommandButton ValBtn 
      Caption         =   "Value"
      Height          =   495
      Left            =   5640
      TabIndex        =   1
      Top             =   720
      Width           =   2775
   End
   Begin VB.CommandButton EnumBtn 
      Caption         =   "Enumerate SubKeys && Values"
      Height          =   495
      Left            =   2280
      TabIndex        =   0
      Top             =   720
      Width           =   2655
   End
   Begin VB.Label Label3 
      Caption         =   "Value"
      Height          =   375
      Left            =   360
      TabIndex        =   10
      Top             =   5280
      Width           =   1935
   End
   Begin VB.Label Label2 
      Caption         =   "Values"
      Height          =   375
      Left            =   360
      TabIndex        =   5
      Top             =   3360
      Width           =   1935
   End
   Begin VB.Label Label1 
      Caption         =   "SubKeys"
      Height          =   375
      Left            =   360
      TabIndex        =   4
      Top             =   1440
      Width           =   2055
   End
End
Attribute VB_Name = "RegForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim strLastKey As String

Private Sub EnumBtn_Click()
    On Error GoTo err
    
    Dim oReg As Object
    Dim strKey As String
    
    strKey = KeyName.Text
    strLastKey = strKey
    If Right(strLastKey, 1) <> "\" Then
        strLastKey = strLastKey & "\"
    End If
        
    Set oReg = CreateObject("IISSample.RegistryAccess")
    
    LB_EnumSubkeys.Clear
    LB_EnumValues.Clear
    
    Set SubKeys = oReg.SubKeys(strKey)
    CountSubKeys.Text = SubKeys.Count
    For Each k In SubKeys
        LB_EnumSubkeys.AddItem k
    Next
    
    Set Values = oReg.Values(strKey)
    CountValues.Text = Values.Count
    For Each v In Values
        LB_EnumValues.AddItem v
    Next
    
    Exit Sub

err:
    errStr = err.Number & err.Description
    MsgBox (errStr)
End Sub

Private Sub Form_Load()
    ValueType.Text = "?"
    KeyName.Text = "HKLM\System\CurrentControlSet\Services\W3SVC"
    strLastKey = KeyName.Text
End Sub

Private Sub LB_EnumSubkeys_Click()
    If LB_EnumSubkeys.ListIndex > -1 Then
        KeyName.Text = strLastKey & LB_EnumSubkeys.List(LB_EnumSubkeys.ListIndex)
    End If
End Sub

Private Sub LB_EnumValues_Click()
    If LB_EnumValues.ListIndex > -1 Then
        KeyName.Text = strLastKey & LB_EnumValues.List(LB_EnumValues.ListIndex)
    End If
End Sub

Private Sub ValBtn_Click()
    'On Error GoTo err
    
    Dim oReg As Object
    Dim oValue
    Dim strKey As String
    
    strKey = KeyName.Text
        
    Set oReg = CreateObject("IISSample.RegistryAccess")
    oValue = oReg.Get(strKey)
    
    LB_Value.Clear
    ValueType.Text = TypeName(oValue)
    
    If IsArray(oValue) Then
        For i = LBound(oValue) To UBound(oValue)
            LB_Value.AddItem oValue(i)
        Next
    Else
        LB_Value.AddItem oValue
    End If
    
    Exit Sub

err:
    errStr = err.Number & err.Description
    MsgBox (errStr)
End Sub
