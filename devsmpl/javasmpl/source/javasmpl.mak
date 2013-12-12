# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Java Virtual Machine Java Workspace" 0x0809

!IF "$(CFG)" == ""
CFG=JavaSmpl - Java Virtual Machine Debug
!MESSAGE No configuration specified.  Defaulting to JavaSmpl - Java Virtual\
 Machine Debug.
!ENDIF 

!IF "$(CFG)" != "JavaSmpl - Java Virtual Machine Release" && "$(CFG)" !=\
 "JavaSmpl - Java Virtual Machine Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "JavaSmpl.mak" CFG="JavaSmpl - Java Virtual Machine Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "JavaSmpl - Java Virtual Machine Release" (based on\
 "Java Virtual Machine Java Workspace")
!MESSAGE "JavaSmpl - Java Virtual Machine Debug" (based on\
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
# PROP Target_Last_Scanned "JavaSmpl - Java Virtual Machine Debug"
JAVA=jvc.exe

!IF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Release"

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

ALL : "$(OUTDIR)\JavaSmpl.class"

CLEAN : 
	-@erase "$(INTDIR)\JavaSmpl.class"

# ADD BASE JAVA /O
# ADD JAVA /O

!ELSEIF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Debug"

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

ALL : "$(OUTDIR)\JavaSmpl.class"

CLEAN : 
	-@erase "$(INTDIR)\JavaSmpl.class"

# ADD BASE JAVA /g
# ADD JAVA /g

!ENDIF 

################################################################################
# Begin Target

# Name "JavaSmpl - Java Virtual Machine Release"
# Name "JavaSmpl - Java Virtual Machine Debug"

!IF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Release"

!ELSEIF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\JavaSmpl.java

!IF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Release"


"$(INTDIR)\JavaSmpl.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "JavaSmpl - Java Virtual Machine Debug"


"$(INTDIR)\JavaSmpl.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
