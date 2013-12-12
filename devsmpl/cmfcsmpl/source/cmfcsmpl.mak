# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=CMFCSmpl - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CMFCSmpl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CMFCSmpl - Win32 Release" && "$(CFG)" !=\
 "CMFCSmpl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "CMFCSmpl.mak" CFG="CMFCSmpl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CMFCSmpl - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CMFCSmpl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "CMFCSmpl - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"

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

ALL : "$(OUTDIR)\CMFCSmpl.dll" "$(OUTDIR)\CMFCSmpl.tlb"\
 "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CMFCSmpl.obj"
	-@erase "$(INTDIR)\CMFCSmpl.pch"
	-@erase "$(INTDIR)\CMFCSmpl.res"
	-@erase "$(INTDIR)\CMFCSmpl.tlb"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\CMFCSmpl.dll"
	-@erase "$(OUTDIR)\CMFCSmpl.exp"
	-@erase "$(OUTDIR)\CMFCSmpl.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCSmpl.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CMFCSmpl.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CMFCSmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/CMFCSmpl.pdb" /machine:I386 /def:".\CMFCSmpl.def"\
 /out:"$(OUTDIR)/CMFCSmpl.dll" /implib:"$(OUTDIR)/CMFCSmpl.lib" 
DEF_FILE= \
	".\CMFCSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CMFCSmpl.obj" \
	"$(INTDIR)\CMFCSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CMFCSmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetPath=.\Release\CMFCSmpl.dll
InputPath=.\Release\CMFCSmpl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"

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

ALL : "$(OUTDIR)\CMFCSmpl.dll" "$(OUTDIR)\CMFCSmpl.tlb"\
 "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CMFCSmpl.obj"
	-@erase "$(INTDIR)\CMFCSmpl.pch"
	-@erase "$(INTDIR)\CMFCSmpl.res"
	-@erase "$(INTDIR)\CMFCSmpl.tlb"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\CMFCSmpl.dll"
	-@erase "$(OUTDIR)\CMFCSmpl.exp"
	-@erase "$(OUTDIR)\CMFCSmpl.ilk"
	-@erase "$(OUTDIR)\CMFCSmpl.lib"
	-@erase "$(OUTDIR)\CMFCSmpl.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCSmpl.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CMFCSmpl.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CMFCSmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/CMFCSmpl.pdb" /debug /machine:I386 /def:".\CMFCSmpl.def"\
 /out:"$(OUTDIR)/CMFCSmpl.dll" /implib:"$(OUTDIR)/CMFCSmpl.lib" 
DEF_FILE= \
	".\CMFCSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CMFCSmpl.obj" \
	"$(INTDIR)\CMFCSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CMFCSmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetPath=.\Debug\CMFCSmpl.dll
InputPath=.\Debug\CMFCSmpl.dll
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

# Name "CMFCSmpl - Win32 Release"
# Name "CMFCSmpl - Win32 Debug"

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCSmpl.cpp
DEP_CPP_CMFCS=\
	".\CMFCSmpl.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CMFCSmpl.obj" : $(SOURCE) $(DEP_CPP_CMFCS) "$(INTDIR)"\
 "$(INTDIR)\CMFCSmpl.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCSmpl.def

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"

!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCSmpl.odl

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"


"$(OUTDIR)\CMFCSmpl.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)/CMFCSmpl.tlb" /win32 $(SOURCE)


!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"


"$(OUTDIR)\CMFCSmpl.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)/CMFCSmpl.tlb" /win32 $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCSmpl.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CMFCSmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/CMFCSmpl.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CMFCSmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMFCSmpl.rc
DEP_RSC_CMFCSM=\
	".\res\CMFCSmpl.rc2"\
	

!IF  "$(CFG)" == "CMFCSmpl - Win32 Release"


"$(INTDIR)\CMFCSmpl.res" : $(SOURCE) $(DEP_RSC_CMFCSM) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/CMFCSmpl.res" /i "Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "CMFCSmpl - Win32 Debug"


"$(INTDIR)\CMFCSmpl.res" : $(SOURCE) $(DEP_RSC_CMFCSM) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/CMFCSmpl.res" /i "Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Simple.cpp
DEP_CPP_SIMPL=\
	".\CMFCSmpl.h"\
	".\Simple.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Simple.obj" : $(SOURCE) $(DEP_CPP_SIMPL) "$(INTDIR)"\
 "$(INTDIR)\CMFCSmpl.pch"


# End Source File
# End Target
# End Project
################################################################################
