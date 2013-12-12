# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Reg - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Reg - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Reg - Win32 Release" && "$(CFG)" != "Reg - Win32 Debug" &&\
 "$(CFG)" != "Reg - Win32 Unicode Release" && "$(CFG)" !=\
 "Reg - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Reg.mak" CFG="Reg - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Reg - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Reg - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Reg - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Reg - Win32 Unicode Debug" (based on\
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
# PROP Target_Last_Scanned "Reg - Win32 Unicode Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Reg - Win32 Release"

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

ALL : "$(OUTDIR)\Reg.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\colln.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\HKey.obj"
	-@erase "$(INTDIR)\Reg.obj"
	-@erase "$(INTDIR)\Reg.pch"
	-@erase "$(INTDIR)\Reg.res"
	-@erase "$(INTDIR)\RegObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\Reg.dll"
	-@erase "$(OUTDIR)\Reg.exp"
	-@erase "$(OUTDIR)\Reg.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\Reg.h"
	-@erase ".\Reg.tlb"
	-@erase ".\Reg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/Reg.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Reg.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Reg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/Reg.pdb" /machine:I386 /def:".\Reg.def"\
 /out:"$(OUTDIR)/Reg.dll" /implib:"$(OUTDIR)/Reg.lib" 
DEF_FILE= \
	".\Reg.def"
LINK32_OBJS= \
	"$(INTDIR)\colln.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\HKey.obj" \
	"$(INTDIR)\Reg.obj" \
	"$(INTDIR)\Reg.res" \
	"$(INTDIR)\RegObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Reg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetPath=.\Release\Reg.dll
InputPath=.\Release\Reg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"

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

ALL : "$(OUTDIR)\Reg.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\colln.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\HKey.obj"
	-@erase "$(INTDIR)\Reg.obj"
	-@erase "$(INTDIR)\Reg.pch"
	-@erase "$(INTDIR)\Reg.res"
	-@erase "$(INTDIR)\RegObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Reg.dll"
	-@erase "$(OUTDIR)\Reg.exp"
	-@erase "$(OUTDIR)\Reg.ilk"
	-@erase "$(OUTDIR)\Reg.lib"
	-@erase "$(OUTDIR)\Reg.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\Reg.h"
	-@erase ".\Reg.tlb"
	-@erase ".\Reg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/Reg.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Reg.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Reg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/Reg.pdb" /debug /machine:I386 /def:".\Reg.def"\
 /out:"$(OUTDIR)/Reg.dll" /implib:"$(OUTDIR)/Reg.lib" 
DEF_FILE= \
	".\Reg.def"
LINK32_OBJS= \
	"$(INTDIR)\colln.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\HKey.obj" \
	"$(INTDIR)\Reg.obj" \
	"$(INTDIR)\Reg.res" \
	"$(INTDIR)\RegObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Reg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetPath=.\Debug\Reg.dll
InputPath=.\Debug\Reg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"

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

ALL : "$(OUTDIR)\Reg.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\colln.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\HKey.obj"
	-@erase "$(INTDIR)\Reg.obj"
	-@erase "$(INTDIR)\Reg.pch"
	-@erase "$(INTDIR)\Reg.res"
	-@erase "$(INTDIR)\RegObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\Reg.dll"
	-@erase "$(OUTDIR)\Reg.exp"
	-@erase "$(OUTDIR)\Reg.lib"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\Reg.h"
	-@erase ".\Reg.tlb"
	-@erase ".\Reg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/Reg.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Reg.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Reg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/Reg.pdb" /machine:I386 /def:".\Reg.def"\
 /out:"$(OUTDIR)/Reg.dll" /implib:"$(OUTDIR)/Reg.lib" 
DEF_FILE= \
	".\Reg.def"
LINK32_OBJS= \
	"$(INTDIR)\colln.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\HKey.obj" \
	"$(INTDIR)\Reg.obj" \
	"$(INTDIR)\Reg.res" \
	"$(INTDIR)\RegObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Reg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\Reg.dll
InputPath=.\ReleaseU\Reg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   regsvr32 /s /c "$(TargetPath)"
   echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"

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

ALL : "$(OUTDIR)\Reg.dll" "$(OUTDIR)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\colln.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\HKey.obj"
	-@erase "$(INTDIR)\Reg.obj"
	-@erase "$(INTDIR)\Reg.pch"
	-@erase "$(INTDIR)\Reg.res"
	-@erase "$(INTDIR)\RegObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Reg.dll"
	-@erase "$(OUTDIR)\Reg.exp"
	-@erase "$(OUTDIR)\Reg.ilk"
	-@erase "$(OUTDIR)\Reg.lib"
	-@erase "$(OUTDIR)\Reg.pdb"
	-@erase "$(OUTDIR)\regsvr32.trg"
	-@erase ".\Reg.h"
	-@erase ".\Reg.tlb"
	-@erase ".\Reg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/Reg.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Reg.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Reg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/Reg.pdb" /debug /machine:I386 /def:".\Reg.def"\
 /out:"$(OUTDIR)/Reg.dll" /implib:"$(OUTDIR)/Reg.lib" 
DEF_FILE= \
	".\Reg.def"
LINK32_OBJS= \
	"$(INTDIR)\colln.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\HKey.obj" \
	"$(INTDIR)\Reg.obj" \
	"$(INTDIR)\Reg.res" \
	"$(INTDIR)\RegObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Reg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\DebugU
TargetPath=.\DebugU\Reg.dll
InputPath=.\DebugU\Reg.dll
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

# Name "Reg - Win32 Release"
# Name "Reg - Win32 Debug"
# Name "Reg - Win32 Unicode Release"
# Name "Reg - Win32 Unicode Debug"

!IF  "$(CFG)" == "Reg - Win32 Release"

!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\debug.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/Reg.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Reg.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)/Reg.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Reg.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/Reg.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Reg.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)/Reg.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Reg.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Reg.cpp
DEP_CPP_REG_C=\
	".\debug.h"\
	".\Reg.h"\
	".\Reg_i.c"\
	".\RegObj.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\Reg.obj" : $(SOURCE) $(DEP_CPP_REG_C) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h" ".\Reg_i.c"


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\Reg.obj" : $(SOURCE) $(DEP_CPP_REG_C) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h" ".\Reg_i.c"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\Reg.obj" : $(SOURCE) $(DEP_CPP_REG_C) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h" ".\Reg_i.c"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\Reg.obj" : $(SOURCE) $(DEP_CPP_REG_C) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h" ".\Reg_i.c"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Reg.def

!IF  "$(CFG)" == "Reg - Win32 Release"

!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Reg.rc
DEP_RSC_REG_R=\
	".\Reg.tlb"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\Reg.res" : $(SOURCE) $(DEP_RSC_REG_R) "$(INTDIR)" ".\Reg.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\Reg.res" : $(SOURCE) $(DEP_RSC_REG_R) "$(INTDIR)" ".\Reg.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\Reg.res" : $(SOURCE) $(DEP_RSC_REG_R) "$(INTDIR)" ".\Reg.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\Reg.res" : $(SOURCE) $(DEP_RSC_REG_R) "$(INTDIR)" ".\Reg.tlb"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Reg.idl

!IF  "$(CFG)" == "Reg - Win32 Release"

# Begin Custom Build
InputPath=.\Reg.idl

BuildCmds= \
	midl Reg.idl \
	

"Reg.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"

# Begin Custom Build
InputPath=.\Reg.idl

BuildCmds= \
	midl Reg.idl \
	

"Reg.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"

# Begin Custom Build
InputPath=.\Reg.idl

BuildCmds= \
	midl Reg.idl \
	

"Reg.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"

# Begin Custom Build
InputPath=.\Reg.idl

BuildCmds= \
	midl Reg.idl \
	

"Reg.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Reg_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\RegObj.cpp
DEP_CPP_REGOB=\
	".\Colln.h"\
	".\debug.h"\
	".\HKey.h"\
	".\Reg.h"\
	".\RegObj.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\RegObj.obj" : $(SOURCE) $(DEP_CPP_REGOB) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\RegObj.obj" : $(SOURCE) $(DEP_CPP_REGOB) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\RegObj.obj" : $(SOURCE) $(DEP_CPP_REGOB) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\RegObj.obj" : $(SOURCE) $(DEP_CPP_REGOB) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\HKey.cpp
DEP_CPP_HKEY_=\
	".\debug.h"\
	".\HKey.h"\
	".\Reg.h"\
	".\RegObj.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\HKey.obj" : $(SOURCE) $(DEP_CPP_HKEY_) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\HKey.obj" : $(SOURCE) $(DEP_CPP_HKEY_) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\HKey.obj" : $(SOURCE) $(DEP_CPP_HKEY_) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\HKey.obj" : $(SOURCE) $(DEP_CPP_HKEY_) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Debug.cpp
DEP_CPP_DEBUG=\
	".\debug.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch"


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Colln.cpp
DEP_CPP_COLLN=\
	".\Colln.h"\
	".\debug.h"\
	".\HKey.h"\
	".\Reg.h"\
	".\RegObj.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Reg - Win32 Release"


"$(INTDIR)\colln.obj" : $(SOURCE) $(DEP_CPP_COLLN) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Debug"


"$(INTDIR)\colln.obj" : $(SOURCE) $(DEP_CPP_COLLN) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Release"


"$(INTDIR)\colln.obj" : $(SOURCE) $(DEP_CPP_COLLN) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ELSEIF  "$(CFG)" == "Reg - Win32 Unicode Debug"


"$(INTDIR)\colln.obj" : $(SOURCE) $(DEP_CPP_COLLN) "$(INTDIR)"\
 "$(INTDIR)\Reg.pch" ".\Reg.h"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
