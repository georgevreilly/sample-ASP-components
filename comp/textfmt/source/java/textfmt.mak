# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Java Virtual Machine Java Workspace" 0x0809

!IF "$(CFG)" == ""
CFG=TextFmt - Java Virtual Machine Debug
!MESSAGE No configuration specified.  Defaulting to TextFmt - Java Virtual\
 Machine Debug.
!ENDIF 

!IF "$(CFG)" != "TextFmt - Java Virtual Machine Release" && "$(CFG)" !=\
 "TextFmt - Java Virtual Machine Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "TextFmt.mak" CFG="TextFmt - Java Virtual Machine Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TextFmt - Java Virtual Machine Release" (based on\
 "Java Virtual Machine Java Workspace")
!MESSAGE "TextFmt - Java Virtual Machine Debug" (based on\
 "Java Virtual Machine Java Workspace")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
JAVA=jvc.exe

!IF  "$(CFG)" == "TextFmt - Java Virtual Machine Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir ""
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\TextFmt.class"

CLEAN : 
	-@erase "$(INTDIR)\TextFmt.class"

# ADD BASE JAVA /O
# ADD JAVA /O

!ELSEIF  "$(CFG)" == "TextFmt - Java Virtual Machine Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir ""
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\TextFmt.class"

CLEAN : 
	-@erase "$(INTDIR)\TextFmt.class"

# ADD BASE JAVA /g
# ADD JAVA /g

!ENDIF 

################################################################################
# Begin Target

# Name "TextFmt - Java Virtual Machine Release"
# Name "TextFmt - Java Virtual Machine Debug"

!IF  "$(CFG)" == "TextFmt - Java Virtual Machine Release"

!ELSEIF  "$(CFG)" == "TextFmt - Java Virtual Machine Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\TextFmt.java

!IF  "$(CFG)" == "TextFmt - Java Virtual Machine Release"


"$(INTDIR)\TextFmt.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "TextFmt - Java Virtual Machine Debug"


"$(INTDIR)\TextFmt.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
