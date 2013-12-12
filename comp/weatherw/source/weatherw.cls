VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "WeatherWizardIII"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
' Add Wind Chill, Units, and history
' High and low inside and outside temperatures
' High Wind Speed
' High and low Wind Chill

Option Explicit

Dim gCommPort As Integer
Dim gCRCFile As String
Dim gWindSpeedUnits As String
Dim gTempUnits As String
Dim gError As String

Dim CRCData(0 To 255) As Integer  'lookup table for CRC checking
Dim LoopData As LoopResults       'contains results of loop command
Public Function GetWeatherData() As Boolean
    
    Dim CommConnection As New MSComm
    
    If CRCReadFile = True Then
        Call CommInit(CommConnection)
    Else
        gError = "Error in CRCReadFile"
        GetWeatherData = False
        Exit Function
    End If
    
    If CommGetLoopData(CommConnection) Then
        GetWeatherData = True
    Else
        gError = "Error in CommGetLoopData"
        GetWeatherData = False
    End If
    
    Call CommClose(CommConnection)
                    
End Function
Private Sub CommInit(CommConnection As MSComm)

    CommConnection.CommPort = CommPort
    
    ' 2400 baud, no parity, 8 data, and 1 stop bit.
    CommConnection.Settings = "2400,N,8,1"
    
    ' Tell the control to read entire buffer when Input
    ' is used.
    CommConnection.InputLen = 0
    
    ' Open the port.
    CommConnection.PortOpen = True
        
End Sub
Private Function CommGetLoopData(CommConnection As MSComm) As Boolean

    ' Buffer to hold Comm command
    Dim CommCommand As Variant
    
    ' Buffer to hold input string
    Dim LoopInput As String
    
    Dim PauseTime As Integer, Start As Variant
    
    Dim CRCError As Long
    
    CommCommand = "LOOP" + Chr$(255) + Chr$(255) + Chr$(13)
    CommConnection.Output = CommCommand
    
    PauseTime = 5   ' Set duration.
    Start = Timer   ' Set start time.
    
    Do
        DoEvents        ' Yield to other processes.
    Loop Until CommConnection.InBufferCount >= 19 Or _
               Timer > Start + PauseTime
      
    If CommConnection.InBufferCount < 19 Then
        CommGetLoopData = False
        Exit Function
    End If
    
    ' Read the loop data.
    LoopInput = CommConnection.Input
    
    CRCError = CRCCalc(Mid(LoopInput, 3, 17))   'crc test
    
    ' If CRCError <> 0 Then        'test for bad crc
    '     Exit Sub
    ' End If
        
     'Store weather data in variable LoopData
    LoopData.TempInside = 0.1 * (LoopInputDecode(Mid(LoopInput, 3, 2)))
    LoopData.TempOutside = 0.1 * (LoopInputDecode(Mid(LoopInput, 5, 2)))
    LoopData.WindSpeed = LoopInputDecode(Mid(LoopInput, 7, 1))
    LoopData.WindDirection = LoopInputDecode(Mid(LoopInput, 8, 2))
    LoopData.Barometer = 0.001 * (LoopInputDecode(Mid(LoopInput, 10, 2)))
    LoopData.HumidityInside = LoopInputDecode(Mid(LoopInput, 12, 1))
    LoopData.HumidityOutside = LoopInputDecode(Mid(LoopInput, 13, 1))
    LoopData.Rain = 0.01 * LoopInputDecode(Mid(LoopInput, 14, 2))
    LoopData.LastUpdate = Time
    
    CommGetLoopData = True
    
End Function
Private Sub CommClose(CommConnection As MSComm)
    
    ' Close the serial port.
    CommConnection.PortOpen = False

End Sub
Private Function CRCCalc(LoopInput As String) As Long

    Dim Accum As Long, AccumHigh As Long, AccumLow As Long, CRCTable As Long
    Dim Position As Integer, CombinedValue As Integer
    
    ' Used to calculate CRC value of data returned from "Loop" command
    Accum = 0
 
    For Position = 1 To Len(LoopInput)
        AccumHigh = (Accum And 65280) / 256
        CombinedValue = CInt(AccumHigh) Xor Asc(Mid(LoopInput, Position, 1))
        CRCTable = UnsignedInt(CRCData(CombinedValue))
        AccumLow = (Accum And 255) * 256
        Accum = AccumLow Xor CRCTable
    Next
        
    CRCCalc = Accum

End Function
Private Function CRCReadFile() As Boolean
   
   Dim CRCFileNumber As Integer
   Dim FilePosition As Long
   
    If Dir(CRCFile) = "" Then  'test to see whether data file is in current directory
        CRCReadFile = False
        Exit Function
    End If
    
    CRCFileNumber = FreeFile
    Open CRCFile For Binary Access Read Lock Read As #CRCFileNumber

    For FilePosition = 0 To 255
        Get #1, (1 + FilePosition * 2), CRCData(FilePosition)  ' read data file into array
    Next
    
    Close #CRCFileNumber
    
    CRCReadFile = True
 
End Function
Private Function LoopInputDecode(Value As String) As Integer

    Dim temp As Integer
    
    'Decode raw data bytes from "loop" command to numeric value
    ' NOTE
    ' Low bit is left char in value
    ' High bit is right char in value

    If Len(Value) = 1 Then
        LoopInputDecode = Val("&H" + Hex(Asc(Value)))
    ElseIf Len(Value) = 2 Then
        temp = Asc(Left((Value), 1))
        If temp < 16 Then
            LoopInputDecode = Val("&H" + Hex(Asc(Right(Value, 1))) + "0" + Hex(temp))
        Else
            LoopInputDecode = Val("&H" + Hex(Asc(Right(Value, 1))) + Hex(temp))
        End If
    End If

End Function
Function UnsignedInt(INTGR As Integer) As Long

    'Used to convert a long integer value to
    'an unsigned integer data type ; used in the CRC check

    If INTGR < 0 Then
        UnsignedInt = INTGR + 65536
    Else
        UnsignedInt = INTGR
    End If

End Function
Public Property Get CommPort() As Variant

    If gCommPort = 0 Then
        CommPort = 1
    Else
        CommPort = gCommPort
    End If
    
End Property
Public Property Let CommPort(ByVal vNewValue As Variant)

    gCommPort = vNewValue
    
End Property
Public Property Get CRCFile() As Variant

    If gCRCFile = "" Then
        CRCFile = "CRC.dat"
    Else
        CRCFile = gCRCFile
    End If
    
End Property
Public Property Let CRCFile(ByVal vNewValue As Variant)

    gCRCFile = vNewValue

End Property
Public Property Get TempInside() As Variant

    Select Case TempUnits
      Case "F"
        TempInside = LoopData.TempInside
      Case "C"
        TempInside = FahrenheitToCelcius(LoopData.TempInside)
    End Select
    
End Property
Public Property Get TempOutside() As Variant

    Select Case TempUnits
      Case "F"
        TempOutside = LoopData.TempOutside
      Case "C"
        TempOutside = FahrenheitToCelcius(LoopData.TempOutside)
    End Select
    
End Property
Public Property Get WindSpeed() As Variant

    Select Case UCase(WindSpeedUnits)
      Case "MPH"
        WindSpeed = LoopData.WindSpeed
      Case "KNOTS"
        WindSpeed = Int(LoopData.WindSpeed / 1.15 * 10) / 10
      Case "KPH"
        WindSpeed = Int(LoopData.WindSpeed * 1.609344 * 10) / 10
      Case "MPS"  ' Meters per second
        WindSpeed = Int(LoopData.WindSpeed * 0.44704 * 10) / 10
    End Select
            
End Property
Public Property Get WindDirection() As Variant

    WindDirection = LoopData.WindDirection
    
End Property
Public Property Get WindSpeedUnits() As Variant

    If gWindSpeedUnits = "" Then
        WindSpeedUnits = "MPH"
    Else
        WindSpeedUnits = gWindSpeedUnits
    End If
    
End Property
Public Property Let WindSpeedUnits(ByVal vNewValue As Variant)

    gWindSpeedUnits = vNewValue
    
End Property
Public Property Get TempOutsideWindChill() As Variant

    Dim WindChillTable1 As Variant, WindChillTable2 As Variant
    Dim Index As Integer, TmpWindSpeed As Integer
    Dim CF As Double, Chill As Double
    Dim D As Integer
    
    If LoopData.TempOutside > 200 Or _
       LoopData.TempOutside < -100 Then
        TempOutsideWindChill = Null
        Exit Property
    End If
    
    If LoopData.TempOutside < 91.4 Then
        
        If LoopData.WindSpeed > 50 Then
            TmpWindSpeed = 50
        Else
            TmpWindSpeed = LoopData.WindSpeed
        End If
    
        WindChillTable1 = Array(156, 151, 146, 141, 133, 123, 110, 87, 61, 14, 0)
        WindChillTable2 = Array(0, 16, 16, 16, 25, 33, 41, 74, 82, 152, 0)
        
        Index = 10 - TmpWindSpeed / 5
        
        CF = WindChillTable1(Index) + _
          (WindChillTable2(Index) / 16#) * (TmpWindSpeed Mod 5)
        
        Chill = CF * ((LoopData.TempOutside - 91.4) / 256#) + LoopData.TempOutside
        
    Else
        Chill = LoopData.TempOutside
    End If
    
    ' Convert to the nearest tenth of a degree
    
    D = Chill * 10 + 0.5
    
    ' Chill = Chill / 10#
    
    Select Case TempUnits
      Case "F"
        TempOutsideWindChill = Int(Chill * 10) / 10
      Case "C"
        TempOutsideWindChill = FahrenheitToCelcius(Chill)
    End Select
    
End Property
Public Property Get TempUnits() As Variant

    If gTempUnits = "" Then
        TempUnits = "F"
    Else
        TempUnits = gTempUnits
    End If
    
End Property
Public Property Let TempUnits(ByVal vNewValue As Variant)

    gTempUnits = vNewValue
    
End Property
Public Property Get ErrorText() As Variant

    ErrorText = gError
    
End Property
Public Function LastUpdate() As Variant

    LastUpdate = LoopData.LastUpdate

End Function
Public Function FahrenheitToCelcius(Fahrenheit As Variant) As Single

    FahrenheitToCelcius = Int((5# / 9#) * (Fahrenheit - 32#) * 10) / 10
    
End Function
