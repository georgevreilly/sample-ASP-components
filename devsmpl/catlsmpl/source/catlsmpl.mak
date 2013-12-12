# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=CATLSmpl - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CATLSmpl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CATLSmpl - Win32 Release" && "$(CFG)" !=\
 "CATLSmpl - Win32 Debug" && "$(CFG)" != "CATLSmpl - Win32 Unicode Release" &&\
 "$(CFG)" != "CATLSmpl - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "catlsmpl.mak" CFG="CATLSmpl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CATLSmpl - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLSmpl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLSmpl - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CATLSmpl - Win32 Unicode Debug" (based on\
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
# PROP Target_Last_Scanned "CATLSmpl - Win32 Unicode Debug"
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"

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

ALL : "$(OUTDIR)\catlsmpl.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLSmpl.obj"
	-@erase "$(INTDIR)\catlsmpl.pch"
	-@erase "$(INTDIR)\CATLSmpl.res"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\catlsmpl.dll"
	-@erase "$(OUTDIR)\catlsmpl.exp"
	-@erase "$(OUTDIR)\catlsmpl.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLSmpl.h"
	-@erase ".\CATLSmpl.tlb"
	-@erase ".\CATLSmpl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlsmpl.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLSmpl.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlsmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/catlsmpl.pdb" /machine:I386 /def:".\CATLSmpl.def"\
 /out:"$(OUTDIR)/catlsmpl.dll" /implib:"$(OUTDIR)/catlsmpl.lib" 
DEF_FILE= \
	".\CATLSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLSmpl.obj" \
	"$(INTDIR)\CATLSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlsmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetPath=.\Release\catlsmpl.dll
InputPath=.\Release\catlsmpl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"

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

ALL : "$(OUTDIR)\catlsmpl.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLSmpl.obj"
	-@erase "$(INTDIR)\catlsmpl.pch"
	-@erase "$(INTDIR)\CATLSmpl.res"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\catlsmpl.dll"
	-@erase "$(OUTDIR)\catlsmpl.exp"
	-@erase "$(OUTDIR)\catlsmpl.ilk"
	-@erase "$(OUTDIR)\catlsmpl.lib"
	-@erase "$(OUTDIR)\catlsmpl.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLSmpl.h"
	-@erase ".\CATLSmpl.tlb"
	-@erase ".\CATLSmpl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlsmpl.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLSmpl.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlsmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/catlsmpl.pdb" /debug /machine:I386 /def:".\CATLSmpl.def"\
 /out:"$(OUTDIR)/catlsmpl.dll" /implib:"$(OUTDIR)/catlsmpl.lib" 
DEF_FILE= \
	".\CATLSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLSmpl.obj" \
	"$(INTDIR)\CATLSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlsmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetPath=.\Debug\catlsmpl.dll
InputPath=.\Debug\catlsmpl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"

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

ALL : "$(OUTDIR)\catlsmpl.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLSmpl.obj"
	-@erase "$(INTDIR)\catlsmpl.pch"
	-@erase "$(INTDIR)\CATLSmpl.res"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\catlsmpl.dll"
	-@erase "$(OUTDIR)\catlsmpl.exp"
	-@erase "$(OUTDIR)\catlsmpl.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLSmpl.h"
	-@erase ".\CATLSmpl.tlb"
	-@erase ".\CATLSmpl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlsmpl.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLSmpl.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlsmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/catlsmpl.pdb" /machine:I386 /def:".\CATLSmpl.def"\
 /out:"$(OUTDIR)/catlsmpl.dll" /implib:"$(OUTDIR)/catlsmpl.lib" 
DEF_FILE= \
	".\CATLSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLSmpl.obj" \
	"$(INTDIR)\CATLSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlsmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\catlsmpl.dll
InputPath=.\ReleaseU\catlsmpl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"

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

ALL : "$(OUTDIR)\catlsmpl.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\CATLSmpl.obj"
	-@erase "$(INTDIR)\catlsmpl.pch"
	-@erase "$(INTDIR)\CATLSmpl.res"
	-@erase "$(INTDIR)\Simple.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\catlsmpl.dll"
	-@erase "$(OUTDIR)\catlsmpl.exp"
	-@erase "$(OUTDIR)\catlsmpl.ilk"
	-@erase "$(OUTDIR)\catlsmpl.lib"
	-@erase "$(OUTDIR)\catlsmpl.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\CATLSmpl.h"
	-@erase ".\CATLSmpl.tlb"
	-@erase ".\CATLSmpl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlsmpl.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CATLSmpl.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/catlsmpl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/catlsmpl.pdb" /debug /machine:I386 /def:".\CATLSmpl.def"\
 /out:"$(OUTDIR)/catlsmpl.dll" /implib:"$(OUTDIR)/catlsmpl.lib" 
DEF_FILE= \
	".\CATLSmpl.def"
LINK32_OBJS= \
	"$(INTDIR)\CATLSmpl.obj" \
	"$(INTDIR)\CATLSmpl.res" \
	"$(INTDIR)\Simple.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\catlsmpl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\DebugU
TargetPath=.\DebugU\catlsmpl.dll
InputPath=.\DebugU\catlsmpl.dll
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

# Name "CATLSmpl - Win32 Release"
# Name "CATLSmpl - Win32 Debug"
# Name "CATLSmpl - Win32 Unicode Release"
# Name "CATLSmpl - Win32 Unicode Debug"

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	{$(INCLUDE)}"\atlimpl.cpp"\
	

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlsmpl.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlsmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/catlsmpl.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlsmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlsmpl.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlsmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/catlsmpl.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\catlsmpl.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLSmpl.cpp
DEP_CPP_CATLS=\
	".\CATLSmpl.h"\
	".\CATLSmpl_i.c"\
	".\Simple.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"


"$(INTDIR)\CATLSmpl.obj" : $(SOURCE) $(DEP_CPP_CATLS) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h" ".\CATLSmpl_i.c"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"


"$(INTDIR)\CATLSmpl.obj" : $(SOURCE) $(DEP_CPP_CATLS) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h" ".\CATLSmpl_i.c"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"


"$(INTDIR)\CATLSmpl.obj" : $(SOURCE) $(DEP_CPP_CATLS) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h" ".\CATLSmpl_i.c"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"


"$(INTDIR)\CATLSmpl.obj" : $(SOURCE) $(DEP_CPP_CATLS) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h" ".\CATLSmpl_i.c"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLSmpl.def

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLSmpl.rc
DEP_RSC_CATLSM=\
	".\CATLSmpl.tlb"\
	

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"


"$(INTDIR)\CATLSmpl.res" : $(SOURCE) $(DEP_RSC_CATLSM) "$(INTDIR)"\
 ".\CATLSmpl.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"


"$(INTDIR)\CATLSmpl.res" : $(SOURCE) $(DEP_RSC_CATLSM) "$(INTDIR)"\
 ".\CATLSmpl.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"


"$(INTDIR)\CATLSmpl.res" : $(SOURCE) $(DEP_RSC_CATLSM) "$(INTDIR)"\
 ".\CATLSmpl.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"


"$(INTDIR)\CATLSmpl.res" : $(SOURCE) $(DEP_RSC_CATLSM) "$(INTDIR)"\
 ".\CATLSmpl.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CATLSmpl.idl

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"

# Begin Custom Build
InputPath=.\CATLSmpl.idl

BuildCmds= \
	midl CATLSmpl.idl \
	

"CATLSmpl.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"

# Begin Custom Build
InputPath=.\CATLSmpl.idl

BuildCmds= \
	midl CATLSmpl.idl \
	

"CATLSmpl.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"

# Begin Custom Build
InputPath=.\CATLSmpl.idl

BuildCmds= \
	midl CATLSmpl.idl \
	

"CATLSmpl.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"

# Begin Custom Build
InputPath=.\CATLSmpl.idl

BuildCmds= \
	midl CATLSmpl.idl \
	

"CATLSmpl.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"CATLSmpl_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Simple.cpp
DEP_CPP_SIMPL=\
	".\CATLSmpl.h"\
	".\Simple.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CATLSmpl - Win32 Release"


"$(INTDIR)\Simple.obj" : $(SOURCE) $(DEP_CPP_SIMPL) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Debug"


"$(INTDIR)\Simple.obj" : $(SOURCE) $(DEP_CPP_SIMPL) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Release"


"$(INTDIR)\Simple.obj" : $(SOURCE) $(DEP_CPP_SIMPL) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h"


!ELSEIF  "$(CFG)" == "CATLSmpl - Win32 Unicode Debug"


"$(INTDIR)\Simple.obj" : $(SOURCE) $(DEP_CPP_SIMPL) "$(INTDIR)"\
 "$(INTDIR)\catlsmpl.pch" ".\CATLSmpl.h"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
