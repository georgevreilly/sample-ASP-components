# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=CMFCPwr - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CMFCPwr - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CMFCPwr - Win32 Release" && "$(CFG)" !=\
 "CMFCPwr - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "CMFCPwr.mak" CFG="CMFCPwr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CMFCPwr - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CMFCPwr - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "CMFCPwr - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CMFCPwr.dll" "$(OUTDIR)\CMFCPwr.tlb" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CMFCPwr.obj"
	-@erase "$(INTDIR)\CMFCPwr.pch"
	-@erase "$(INTDIR)\CMFCPwr.res"
	-@erase "$(INTDIR)\CMFCPwr.tlb"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\CMFCPwr.dll"
	-@erase "$(OUTDIR)\CMFCPwr.exp"
	-@erase "$(OUTDIR)\CMFCPwr.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCPwr.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CMFCPwr.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CMFCPwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/CMFCPwr.pdb" /machine:I386 /def:".\CMFCPwr.def"\
 /out:"$(OUTDIR)/CMFCPwr.dll" /implib:"$(OUTDIR)/CMFCPwr.lib" 
DEF_FILE= \
	".\CMFCPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CMFCPwr.obj" \
	"$(INTDIR)\CMFCPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CMFCPwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetPath=.\Release\CMFCPwr.dll
InputPath=.\Release\CMFCPwr.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CMFCPwr.dll" "$(OUTDIR)\CMFCPwr.tlb" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CMFCPwr.obj"
	-@erase "$(INTDIR)\CMFCPwr.pch"
	-@erase "$(INTDIR)\CMFCPwr.res"
	-@erase "$(INTDIR)\CMFCPwr.tlb"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\CMFCPwr.dll"
	-@erase "$(OUTDIR)\CMFCPwr.exp"
	-@erase "$(OUTDIR)\CMFCPwr.ilk"
	-@erase "$(OUTDIR)\CMFCPwr.lib"
	-@erase "$(OUTDIR)\CMFCPwr.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCPwr.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CMFCPwr.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CMFCPwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/CMFCPwr.pdb" /debug /machine:I386 /def:".\CMFCPwr.def"\
 /out:"$(OUTDIR)/CMFCPwr.dll" /implib:"$(OUTDIR)/CMFCPwr.lib" 
DEF_FILE= \
	".\CMFCPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CMFCPwr.obj" \
	"$(INTDIR)\CMFCPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CMFCPwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetPath=.\Debug\CMFCPwr.dll
InputPath=.\Debug\CMFCPwr.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "CMFCPwr - Win32 Release"
# Name "CMFCPwr - Win32 Debug"

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCPwr.cpp
DEP_CPP_CMFCP=\
	".\CMFCPwr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CMFCPwr.obj" : $(SOURCE) $(DEP_CPP_CMFCP) "$(INTDIR)"\
 "$(INTDIR)\CMFCPwr.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCPwr.def

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCPwr.odl

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"


"$(OUTDIR)\CMFCPwr.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)/CMFCPwr.tlb" /win32 $(SOURCE)


!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"


"$(OUTDIR)\CMFCPwr.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)/CMFCPwr.tlb" /win32 $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCPwr.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CMFCPwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCPwr.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CMFCPwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCPwr.rc
DEP_RSC_CMFCPW=\
	".\res\CMFCPwr.rc2"\
	

!IF  "$(CFG)" == "CMFCPwr - Win32 Release"


"$(INTDIR)\CMFCPwr.res" : $(SOURCE) $(DEP_RSC_CMFCPW) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/CMFCPwr.res" /i "Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "CMFCPwr - Win32 Debug"


"$(INTDIR)\CMFCPwr.res" : $(SOURCE) $(DEP_RSC_CMFCPW) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/CMFCPwr.res" /i "Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Power.cpp
DEP_CPP_POWER=\
	".\CMFCPwr.h"\
	".\Power.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\asptlb.h"\
	

"$(INTDIR)\Power.obj" : $(SOURCE) $(DEP_CPP_POWER) "$(INTDIR)"\
 "$(INTDIR)\CMFCPwr.pch"


# End Source File
# End Target
# End Project
################################################################################
