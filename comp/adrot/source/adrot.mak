# Microsoft Developer Studio Generated NMAKE File, Based on AdRot.dsp
!IF "$(CFG)" == ""
CFG=AdRot - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AdRot - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AdRot - Win32 Debug" && "$(CFG)" !=\
 "AdRot - Win32 Unicode Debug" && "$(CFG)" != "AdRot - Win32 Release MinSize" &&\
 "$(CFG)" != "AdRot - Win32 Release MinDependency" && "$(CFG)" !=\
 "AdRot - Win32 Unicode Release MinSize" && "$(CFG)" !=\
 "AdRot - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AdRot.mak" CFG="AdRot - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AdRot - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AdRot - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AdRot - Win32 Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AdRot - Win32 Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AdRot - Win32 Unicode Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AdRot - Win32 Unicode Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AdRot - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.ilk"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OUTDIR)\AdRot.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\AdRot.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\AdRot.pdb" /debug /machine:I386\
 /def:".\AdRot.def" /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\AdRot.dll
InputPath=.\Debug\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.ilk"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OUTDIR)\AdRot.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\AdRot.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\AdRot.pdb" /debug /machine:I386\
 /def:".\AdRot.def" /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\AdRot.dll
InputPath=.\DebugU\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\AdRot.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\AdRot.pdb" /machine:I386 /def:".\AdRot.def"\
 /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib" 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\AdRot.dll
InputPath=.\ReleaseMinSize\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\AdRot.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\AdRot.pdb" /machine:I386 /def:".\AdRot.def"\
 /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib" 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\AdRot.dll
InputPath=.\ReleaseMinDependency\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\AdRot.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\AdRot.pdb" /machine:I386 /def:".\AdRot.def"\
 /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib" 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\AdRot.dll
InputPath=.\ReleaseUMinSize\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\AdRot.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AdDesc.obj"
	-@erase "$(INTDIR)\AdFile.obj"
	-@erase "$(INTDIR)\AdRot.obj"
	-@erase "$(INTDIR)\AdRot.pch"
	-@erase "$(INTDIR)\AdRot.res"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\AdRot.dll"
	-@erase "$(OUTDIR)\AdRot.exp"
	-@erase "$(OUTDIR)\AdRot.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\AdRot.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AdRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AdRot.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\AdRot.pdb" /machine:I386 /def:".\AdRot.def"\
 /out:"$(OUTDIR)\AdRot.dll" /implib:"$(OUTDIR)\AdRot.lib" 
DEF_FILE= \
	".\AdRot.def"
LINK32_OBJS= \
	"$(INTDIR)\AdDesc.obj" \
	"$(INTDIR)\AdFile.obj" \
	"$(INTDIR)\AdRot.obj" \
	"$(INTDIR)\AdRot.res" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AdRot.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\AdRot.dll
InputPath=.\ReleaseUMinDependency\AdRot.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "AdRot - Win32 Debug" || "$(CFG)" ==\
 "AdRot - Win32 Unicode Debug" || "$(CFG)" == "AdRot - Win32 Release MinSize" ||\
 "$(CFG)" == "AdRot - Win32 Release MinDependency" || "$(CFG)" ==\
 "AdRot - Win32 Unicode Release MinSize" || "$(CFG)" ==\
 "AdRot - Win32 Unicode Release MinDependency"
SOURCE=.\AdDesc.cpp

!IF  "$(CFG)" == "AdRot - Win32 Debug"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADDES=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADDES=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

DEP_CPP_ADDES=\
	".\AdDesc.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADDES=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdDesc.obj" : $(SOURCE) $(DEP_CPP_ADDES) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ENDIF 

SOURCE=.\AdFile.cpp

!IF  "$(CFG)" == "AdRot - Win32 Debug"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADFIL=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADFIL=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

DEP_CPP_ADFIL=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	
NODEP_CPP_ADFIL=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdFile.obj" : $(SOURCE) $(DEP_CPP_ADFIL) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ENDIF 

SOURCE=.\AdRot.cpp

!IF  "$(CFG)" == "AdRot - Win32 Debug"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h" ".\AdRot_i.c"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h" ".\AdRot_i.c"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\RotObj.h"\
	
NODEP_CPP_ADROT=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot_i.c" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\RotObj.h"\
	
NODEP_CPP_ADROT=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h" ".\AdRot_i.c"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h" ".\AdRot_i.c"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

DEP_CPP_ADROT=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\AdRot_i.c"\
	".\RotObj.h"\
	
NODEP_CPP_ADROT=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\AdRot.obj" : $(SOURCE) $(DEP_CPP_ADROT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h" ".\AdRot_i.c"


!ENDIF 

SOURCE=.\AdRot.idl

!IF  "$(CFG)" == "AdRot - Win32 Debug"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

InputPath=.\AdRot.idl

".\AdRot.tlb"	".\AdRot.h"	".\AdRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "AdRot.h" /iid "AdRot_i.c" "AdRot.idl"

!ENDIF 

SOURCE=.\AdRot.rc
DEP_RSC_ADROT_=\
	".\adrot.rgs"\
	".\AdRot.tlb"\
	

"$(INTDIR)\AdRot.res" : $(SOURCE) $(DEP_RSC_ADROT_) "$(INTDIR)" ".\AdRot.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Monitor.cpp

!IF  "$(CFG)" == "AdRot - Win32 Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch"


!ENDIF 

SOURCE=.\RotObj.cpp

!IF  "$(CFG)" == "AdRot - Win32 Debug"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdRot.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\RotObj.h"\
	
NODEP_CPP_ROTOB=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\RotObj.h"\
	
NODEP_CPP_ROTOB=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

DEP_CPP_ROTOB=\
	".\AdDesc.h"\
	".\AdFile.h"\
	".\AdRot.h"\
	".\RotObj.h"\
	
NODEP_CPP_ROTOB=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\AdRot.pch" ".\AdRot.h"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "AdRot - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\AdRot.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\AdRot.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\AdRot.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AdRot - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\AdRot.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\AdRot.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AdRot - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\AdRot.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AdRot.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

