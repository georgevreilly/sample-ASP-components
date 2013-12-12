# Microsoft Developer Studio Generated NMAKE File, Based on NxtLnk.dsp
!IF "$(CFG)" == ""
CFG=NxtLnk - Win32 Debug
!MESSAGE No configuration specified. Defaulting to NxtLnk - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "NxtLnk - Win32 Debug" && "$(CFG)" !=\
 "NxtLnk - Win32 Unicode Debug" && "$(CFG)" != "NxtLnk - Win32 Release MinSize"\
 && "$(CFG)" != "NxtLnk - Win32 Release MinDependency" && "$(CFG)" !=\
 "NxtLnk - Win32 Unicode Release MinSize" && "$(CFG)" !=\
 "NxtLnk - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NxtLnk.mak" CFG="NxtLnk - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NxtLnk - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NxtLnk - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NxtLnk - Win32 Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NxtLnk - Win32 Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NxtLnk - Win32 Unicode Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NxtLnk - Win32 Unicode Release MinDependency" (based on\
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

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.ilk"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OUTDIR)\NxtLnk.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\NxtLnk.pdb" /debug /machine:I386\
 /def:".\NxtLnk.def" /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\NxtLnk.dll
InputPath=.\Debug\NxtLnk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.ilk"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OUTDIR)\NxtLnk.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\NxtLnk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\NxtLnk.pdb" /debug /machine:I386\
 /def:".\NxtLnk.def" /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\NxtLnk.dll
InputPath=.\DebugU\NxtLnk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\NxtLnk.pdb" /machine:I386 /def:".\NxtLnk.def"\
 /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib" 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\NxtLnk.dll
InputPath=.\ReleaseMinSize\NxtLnk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\NxtLnk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\NxtLnk.pdb" /machine:I386 /def:".\NxtLnk.def"\
 /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib" 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\NxtLnk.dll
InputPath=.\ReleaseMinDependency\NxtLnk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\NxtLnk.pdb" /machine:I386 /def:".\NxtLnk.def"\
 /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib" 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\NxtLnk.dll
InputPath=.\ReleaseUMinSize\NxtLnk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\NxtLnk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Link.obj"
	-@erase "$(INTDIR)\LinkFile.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\NextLink.obj"
	-@erase "$(INTDIR)\NxtLnk.obj"
	-@erase "$(INTDIR)\NxtLnk.pch"
	-@erase "$(INTDIR)\NxtLnk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\NxtLnk.dll"
	-@erase "$(OUTDIR)\NxtLnk.exp"
	-@erase "$(OUTDIR)\NxtLnk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\NxtLnk.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NxtLnk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NxtLnk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\NxtLnk.pdb" /machine:I386 /def:".\NxtLnk.def"\
 /out:"$(OUTDIR)\NxtLnk.dll" /implib:"$(OUTDIR)\NxtLnk.lib" 
DEF_FILE= \
	".\NxtLnk.def"
LINK32_OBJS= \
	"$(INTDIR)\Link.obj" \
	"$(INTDIR)\LinkFile.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\NextLink.obj" \
	"$(INTDIR)\NxtLnk.obj" \
	"$(INTDIR)\NxtLnk.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\NxtLnk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\NxtLnk.dll
InputPath=.\ReleaseUMinDependency\NxtLnk.dll
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


!IF "$(CFG)" == "NxtLnk - Win32 Debug" || "$(CFG)" ==\
 "NxtLnk - Win32 Unicode Debug" || "$(CFG)" == "NxtLnk - Win32 Release MinSize"\
 || "$(CFG)" == "NxtLnk - Win32 Release MinDependency" || "$(CFG)" ==\
 "NxtLnk - Win32 Unicode Release MinSize" || "$(CFG)" ==\
 "NxtLnk - Win32 Unicode Release MinDependency"
SOURCE=.\Link.cpp

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINK_=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINK_=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

DEP_CPP_LINK_=\
	".\Link.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINK_=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\Link.obj" : $(SOURCE) $(DEP_CPP_LINK_) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ENDIF 

SOURCE=.\LinkFile.cpp

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\Monitor.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\Monitor.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\Monitor.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINKF=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINKF=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

DEP_CPP_LINKF=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_LINKF=\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\LinkFile.obj" : $(SOURCE) $(DEP_CPP_LINKF) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ENDIF 

SOURCE=.\Monitor.cpp

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch"


!ENDIF 

SOURCE=.\NextLink.cpp

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_NEXTL=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_NEXTL=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

DEP_CPP_NEXTL=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	
NODEP_CPP_NEXTL=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NextLink.obj" : $(SOURCE) $(DEP_CPP_NEXTL) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h"


!ENDIF 

SOURCE=.\NxtLnk.cpp

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h" ".\NxtLnk_i.c"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h" ".\NxtLnk_i.c"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h" ".\NxtLnk_i.c"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	
NODEP_CPP_NXTLN=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk_i.c" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	
NODEP_CPP_NXTLN=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk_i.c" ".\NxtLnk.h"


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

DEP_CPP_NXTLN=\
	".\Link.h"\
	".\LinkFile.h"\
	".\NextLink.h"\
	".\NxtLnk.h"\
	".\NxtLnk_i.c"\
	
NODEP_CPP_NXTLN=\
	"..\..\inc\lock.h"\
	"..\..\inc\refcount.h"\
	"..\..\inc\refptr.h"\
	

"$(INTDIR)\NxtLnk.obj" : $(SOURCE) $(DEP_CPP_NXTLN) "$(INTDIR)"\
 "$(INTDIR)\NxtLnk.pch" ".\NxtLnk.h" ".\NxtLnk_i.c"


!ENDIF 

SOURCE=.\NxtLnk.idl

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

InputPath=.\NxtLnk.idl

".\NxtLnk.tlb"	".\NxtLnk.h"	".\NxtLnk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "NxtLnk.h" /iid "NxtLnk_i.c" "NxtLnk.idl"

!ENDIF 

SOURCE=.\NxtLnk.rc
DEP_RSC_NXTLNK=\
	".\NextLink.rgs"\
	".\NxtLnk.tlb"\
	

"$(INTDIR)\NxtLnk.res" : $(SOURCE) $(DEP_RSC_NXTLNK) "$(INTDIR)" ".\NxtLnk.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "NxtLnk - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\NxtLnk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\NxtLnk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\NxtLnk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NxtLnk - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\NxtLnk.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NxtLnk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

