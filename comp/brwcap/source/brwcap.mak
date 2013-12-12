# Microsoft Developer Studio Generated NMAKE File, Based on brwcap.dsp
!IF "$(CFG)" == ""
CFG=BrwCap - Win32 Debug
!MESSAGE No configuration specified. Defaulting to BrwCap - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "BrwCap - Win32 Debug" && "$(CFG)" !=\
 "BrwCap - Win32 Unicode Debug" && "$(CFG)" != "BrwCap - Win32 Release MinSize"\
 && "$(CFG)" != "BrwCap - Win32 Release MinDependency" && "$(CFG)" !=\
 "BrwCap - Win32 Unicode Release MinSize" && "$(CFG)" !=\
 "BrwCap - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "brwcap.mak" CFG="BrwCap - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BrwCap - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BrwCap - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BrwCap - Win32 Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BrwCap - Win32 Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BrwCap - Win32 Unicode Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BrwCap - Win32 Unicode Release MinDependency" (based on\
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

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.ilk"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OUTDIR)\brwcap.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\brwcap.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\brwcap.pdb" /debug /machine:I386\
 /def:".\BrwCap.def" /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\brwcap.dll
InputPath=.\Debug\brwcap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.ilk"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OUTDIR)\brwcap.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\brwcap.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\brwcap.pdb" /debug /machine:I386\
 /def:".\BrwCap.def" /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib"\
 /pdbtype:sept 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\brwcap.dll
InputPath=.\DebugU\brwcap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\brwcap.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\brwcap.pdb" /machine:I386 /def:".\BrwCap.def"\
 /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib" 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\brwcap.dll
InputPath=.\ReleaseMinSize\brwcap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\brwcap.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\brwcap.pdb" /machine:I386 /def:".\BrwCap.def"\
 /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib" 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\brwcap.dll
InputPath=.\ReleaseMinDependency\brwcap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\brwcap.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\brwcap.pdb" /machine:I386 /def:".\BrwCap.def"\
 /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib" 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\brwcap.dll
InputPath=.\ReleaseUMinSize\brwcap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\brwcap.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BrowCap.obj"
	-@erase "$(INTDIR)\BrwCap.obj"
	-@erase "$(INTDIR)\brwcap.pch"
	-@erase "$(INTDIR)\BrwCap.res"
	-@erase "$(INTDIR)\CapMap.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\rdwrt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\brwcap.dll"
	-@erase "$(OUTDIR)\brwcap.exp"
	-@erase "$(OUTDIR)\brwcap.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\brwcap.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\BrwCap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\brwcap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\brwcap.pdb" /machine:I386 /def:".\BrwCap.def"\
 /out:"$(OUTDIR)\brwcap.dll" /implib:"$(OUTDIR)\brwcap.lib" 
DEF_FILE= \
	".\BrwCap.def"
LINK32_OBJS= \
	"$(INTDIR)\BrowCap.obj" \
	"$(INTDIR)\BrwCap.obj" \
	"$(INTDIR)\BrwCap.res" \
	"$(INTDIR)\CapMap.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\rdwrt.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\brwcap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\brwcap.dll
InputPath=.\ReleaseUMinDependency\brwcap.dll
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


!IF "$(CFG)" == "BrwCap - Win32 Debug" || "$(CFG)" ==\
 "BrwCap - Win32 Unicode Debug" || "$(CFG)" == "BrwCap - Win32 Release MinSize"\
 || "$(CFG)" == "BrwCap - Win32 Release MinDependency" || "$(CFG)" ==\
 "BrwCap - Win32 Unicode Release MinSize" || "$(CFG)" ==\
 "BrwCap - Win32 Unicode Release MinDependency"
SOURCE=.\BrowCap.cpp

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_BROWC=\
	".\ReadWrite.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

DEP_CPP_BROWC=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_BROWC=\
	".\ReadWrite.h"\
	

"$(INTDIR)\BrowCap.obj" : $(SOURCE) $(DEP_CPP_BROWC) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ENDIF 

SOURCE=.\BrwCap.cpp

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap_i.c" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_BRWCA=\
	".\ReadWrite.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h" ".\BrwCap_i.c"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h" ".\BrwCap_i.c"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h" ".\BrwCap_i.c"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h" ".\BrwCap_i.c"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

DEP_CPP_BRWCA=\
	".\BrowCap.h"\
	".\BrwCap.h"\
	".\BrwCap_i.c"\
	".\CapMap.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_BRWCA=\
	".\ReadWrite.h"\
	

"$(INTDIR)\BrwCap.obj" : $(SOURCE) $(DEP_CPP_BRWCA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h" ".\BrwCap_i.c"


!ENDIF 

SOURCE=.\BrwCap.idl

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

InputPath=.\BrwCap.idl

".\BrwCap.tlb"	".\BrwCap.h"	".\BrwCap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "BrwCap.h" /iid "BrwCap_i.c" "BrwCap.idl"

!ENDIF 

SOURCE=.\BrwCap.rc
DEP_RSC_BRWCAP=\
	".\BrowCap.rgs"\
	".\BrwCap.tlb"\
	

"$(INTDIR)\BrwCap.res" : $(SOURCE) $(DEP_RSC_BRWCAP) "$(INTDIR)" ".\BrwCap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CapMap.cpp

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_CAPMA=\
	".\ReadWrite.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\rdwrt.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

DEP_CPP_CAPMA=\
	".\BrwCap.h"\
	".\CapMap.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	
NODEP_CPP_CAPMA=\
	".\ReadWrite.h"\
	

"$(INTDIR)\CapMap.obj" : $(SOURCE) $(DEP_CPP_CAPMA) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch" ".\BrwCap.h"


!ENDIF 

SOURCE=.\Monitor.cpp

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\RefCount.h"\
	".\RefPtr.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ENDIF 

SOURCE=.\rdwrt.cpp

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

DEP_CPP_RDWRT=\
	".\rdwrt.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\rdwrt.obj" : $(SOURCE) $(DEP_CPP_RDWRT) "$(INTDIR)"\
 "$(INTDIR)\brwcap.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "BrwCap - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\brwcap.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\brwcap.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\brwcap.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\brwcap.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\brwcap.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BrwCap - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\brwcap.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\brwcap.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

