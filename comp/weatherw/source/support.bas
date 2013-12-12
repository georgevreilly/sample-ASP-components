Attribute VB_Name = "Support"
Option Explicit

Type LoopResults  'data type to hold results of loop command
    TempInside As Double
    TempOutside As Double
    WindSpeed As Integer
    WindDirection As Integer
    Barometer As Double
    HumidityInside As Integer
    HumidityOutside As Integer
    Rain As Double
    LastUpdate As Variant
End Type
Sub Main()
    MainSupport
End Sub
Sub MainSupport()
  
  Dim WeatherWiz As New WeatherWizardIII
  
  If WeatherWiz.GetWeatherData = False Then
    Debug.Print "The weather is currently unavailable. Bummer dude."
    Debug.Print WeatherWiz.ErrorText
  Else
    Debug.Print "The weather conditions are:"
    Debug.Print ""
    Debug.Print "Temperature Units.....", WeatherWiz.TempUnits
    Debug.Print "Inside Temperature....", WeatherWiz.TempInside
    Debug.Print "Outside Temperature...", WeatherWiz.TempOutside
    Debug.Print "Windchill Temperature.", WeatherWiz.TempOutsideWindChill
    Debug.Print ""
    
    WeatherWiz.TempUnits = "C"
    Debug.Print "Temperature Units.....", WeatherWiz.TempUnits
    Debug.Print "Inside Temperature....", WeatherWiz.TempInside
    Debug.Print "Outside Temperature...", WeatherWiz.TempOutside
    Debug.Print "Windchill Temperature.", WeatherWiz.TempOutsideWindChill
    Debug.Print ""
    Debug.Print ""
    Debug.Print "Wind Speed Units......", WeatherWiz.WindSpeedUnits
    Debug.Print "Wind Speed............", WeatherWiz.WindSpeed
    Debug.Print ""
    
    WeatherWiz.WindSpeedUnits = "Knots"
    Debug.Print "Wind Speed Units......", WeatherWiz.WindSpeedUnits
    Debug.Print "Wind Speed............", WeatherWiz.WindSpeed
    Debug.Print ""
    
    WeatherWiz.WindSpeedUnits = "KPH"
    Debug.Print "Wind Speed Units......", WeatherWiz.WindSpeedUnits
    Debug.Print "Wind Speed............", WeatherWiz.WindSpeed
    Debug.Print ""
    
    WeatherWiz.WindSpeedUnits = "MPS"
    Debug.Print "Wind Speed Units......", WeatherWiz.WindSpeedUnits
    Debug.Print "Wind Speed............", WeatherWiz.WindSpeed
    Debug.Print ""
    Debug.Print ""
    Debug.Print "Wind Direction........", WeatherWiz.WindDirection; ""

  End If

End Sub
