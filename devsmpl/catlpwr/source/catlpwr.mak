# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=CATLPwr - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CATLPwr - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CATLPwr - Win32 Release" && "$(CFG)" !=\
 "CATLPwr - Win32 Debug" && "$(CFG)" != "CATLPwr - Win32 Unicode Release" &&\
 "$(CFG)" != "CATLPwr - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "catlpwr.mak" CFG="CATLPwr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CATLPwr - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLPwr - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLPwr - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLPwr - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "CATLPwr - Win32 Unicode Debug"
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "CATLPwr - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\catlpwr.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLPwr.obj"
	-@erase "$(INTDIR)\catlpwr.pch"
	-@erase "$(INTDIR)\CATLPwr.res"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\catlpwr.dll"
	-@erase "$(OUTDIR)\catlpwr.exp"
	-@erase "$(OUTDIR)\catlpwr.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLPwr.h"
	-@erase ".\CATLPwr.tlb"
	-@erase ".\CATLPwr_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlpwr.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLPwr.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlpwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/catlpwr.pdb" /machine:I386 /def:".\CATLPwr.def"\
 /out:"$(OUTDIR)/catlpwr.dll" /implib:"$(OUTDIR)/catlpwr.lib" 
DEF_FILE= \
	".\CATLPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLPwr.obj" \
	"$(INTDIR)\CATLPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlpwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetPath=.\Release\catlpwr.dll
InputPath=.\Release\catlpwr.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\catlpwr.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLPwr.obj"
	-@erase "$(INTDIR)\catlpwr.pch"
	-@erase "$(INTDIR)\CATLPwr.res"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\catlpwr.dll"
	-@erase "$(OUTDIR)\catlpwr.exp"
	-@erase "$(OUTDIR)\catlpwr.ilk"
	-@erase "$(OUTDIR)\catlpwr.lib"
	-@erase "$(OUTDIR)\catlpwr.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLPwr.h"
	-@erase ".\CATLPwr.tlb"
	-@erase ".\CATLPwr_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlpwr.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLPwr.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlpwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/catlpwr.pdb" /debug /machine:I386 /def:".\CATLPwr.def"\
 /out:"$(OUTDIR)/catlpwr.dll" /implib:"$(OUTDIR)/catlpwr.lib" 
DEF_FILE= \
	".\CATLPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLPwr.obj" \
	"$(INTDIR)\CATLPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlpwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetPath=.\Debug\catlpwr.dll
InputPath=.\Debug\catlpwr.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Unicode Release"
# PROP BASE Intermediate_Dir "Unicode Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Target_Dir ""
OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\catlpwr.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLPwr.obj"
	-@erase "$(INTDIR)\catlpwr.pch"
	-@erase "$(INTDIR)\CATLPwr.res"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\catlpwr.dll"
	-@erase "$(OUTDIR)\catlpwr.exp"
	-@erase "$(OUTDIR)\catlpwr.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLPwr.h"
	-@erase ".\CATLPwr.tlb"
	-@erase ".\CATLPwr_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlpwr.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLPwr.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlpwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/catlpwr.pdb" /machine:I386 /def:".\CATLPwr.def"\
 /out:"$(OUTDIR)/catlpwr.dll" /implib:"$(OUTDIR)/catlpwr.lib" 
DEF_FILE= \
	".\CATLPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLPwr.obj" \
	"$(INTDIR)\CATLPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlpwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\catlpwr.dll
InputPath=.\ReleaseU\catlpwr.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Unicode Debug"
# PROP BASE Intermediate_Dir "Unicode Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Dir ""
OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\catlpwr.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLPwr.obj"
	-@erase "$(INTDIR)\catlpwr.pch"
	-@erase "$(INTDIR)\CATLPwr.res"
	-@erase "$(INTDIR)\Power.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\catlpwr.dll"
	-@erase "$(OUTDIR)\catlpwr.exp"
	-@erase "$(OUTDIR)\catlpwr.ilk"
	-@erase "$(OUTDIR)\catlpwr.lib"
	-@erase "$(OUTDIR)\catlpwr.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLPwr.h"
	-@erase ".\CATLPwr.tlb"
	-@erase ".\CATLPwr_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlpwr.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLPwr.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlpwr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/catlpwr.pdb" /debug /machine:I386 /def:".\CATLPwr.def"\
 /out:"$(OUTDIR)/catlpwr.dll" /implib:"$(OUTDIR)/catlpwr.lib" 
DEF_FILE= \
	".\CATLPwr.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLPwr.obj" \
	"$(INTDIR)\CATLPwr.res" \
	"$(INTDIR)\Power.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlpwr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\DebugU
TargetPath=.\DebugU\catlpwr.dll
InputPath=.\DebugU\catlpwr.dll
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

# Name "CATLPwr - Win32 Release"
# Name "CATLPwr - Win32 Debug"
# Name "CATLPwr - Win32 Unicode Release"
# Name "CATLPwr - Win32 Unicode Debug"

!IF  "$(CFG)" == "CATLPwr - Win32 Release"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	{$(INCLUDE)}"\atlimpl.cpp"\
	

!IF  "$(CFG)" == "CATLPwr - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlpwr.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlpwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlpwr.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlpwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlpwr.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlpwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlpwr.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlpwr.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLPwr.cpp
DEP_CPP_CATLP=\
	".\CATLPwr.h"\
	".\CATLPwr_i.c"\
	".\Power.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\asptlb.h"\
	

!IF  "$(CFG)" == "CATLPwr - Win32 Release"


"$(INTDIR)\CATLPwr.obj" : $(SOURCE) $(DEP_CPP_CATLP) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h" ".\CATLPwr_i.c"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"


"$(INTDIR)\CATLPwr.obj" : $(SOURCE) $(DEP_CPP_CATLP) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h" ".\CATLPwr_i.c"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"


"$(INTDIR)\CATLPwr.obj" : $(SOURCE) $(DEP_CPP_CATLP) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h" ".\CATLPwr_i.c"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"


"$(INTDIR)\CATLPwr.obj" : $(SOURCE) $(DEP_CPP_CATLP) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h" ".\CATLPwr_i.c"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLPwr.def

!IF  "$(CFG)" == "CATLPwr - Win32 Release"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLPwr.rc
DEP_RSC_CATLPW=\
	".\CATLPwr.tlb"\
	

!IF  "$(CFG)" == "CATLPwr - Win32 Release"


"$(INTDIR)\CATLPwr.res" : $(SOURCE) $(DEP_RSC_CATLPW) "$(INTDIR)"\
 ".\CATLPwr.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"


"$(INTDIR)\CATLPwr.res" : $(SOURCE) $(DEP_RSC_CATLPW) "$(INTDIR)"\
 ".\CATLPwr.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"


"$(INTDIR)\CATLPwr.res" : $(SOURCE) $(DEP_RSC_CATLPW) "$(INTDIR)"\
 ".\CATLPwr.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"


"$(INTDIR)\CATLPwr.res" : $(SOURCE) $(DEP_RSC_CATLPW) "$(INTDIR)"\
 ".\CATLPwr.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLPwr.idl

!IF  "$(CFG)" == "CATLPwr - Win32 Release"

# Begin Custom Build
InputPath=.\CATLPwr.idl

BuildCmds= \
	midl CATLPwr.idl \
	

"CATLPwr.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"

# Begin Custom Build
InputPath=.\CATLPwr.idl

BuildCmds= \
	midl CATLPwr.idl \
	

"CATLPwr.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"

# Begin Custom Build
InputPath=.\CATLPwr.idl

BuildCmds= \
	midl CATLPwr.idl \
	

"CATLPwr.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"

# Begin Custom Build
InputPath=.\CATLPwr.idl

BuildCmds= \
	midl CATLPwr.idl \
	

"CATLPwr.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLPwr_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Power.cpp
DEP_CPP_POWER=\
	".\CATLPwr.h"\
	".\Power.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\asptlb.h"\
	

!IF  "$(CFG)" == "CATLPwr - Win32 Release"


"$(INTDIR)\Power.obj" : $(SOURCE) $(DEP_CPP_POWER) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Debug"


"$(INTDIR)\Power.obj" : $(SOURCE) $(DEP_CPP_POWER) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Release"


"$(INTDIR)\Power.obj" : $(SOURCE) $(DEP_CPP_POWER) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h"


!ELSEIF  "$(CFG)" == "CATLPwr - Win32 Unicode Debug"


"$(INTDIR)\Power.obj" : $(SOURCE) $(DEP_CPP_POWER) "$(INTDIR)"\
 "$(INTDIR)\catlpwr.pch" ".\CATLPwr.h"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
