# Microsoft Developer Studio Generated NMAKE File, Based on suminfo.dsp
!IF "$(CFG)" == ""
CFG=SumInfo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SumInfo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SumInfo - Win32 Debug" && "$(CFG)" !=\
 "SumInfo - Win32 Unicode Debug" && "$(CFG)" !=\
 "SumInfo - Win32 Release MinSize" && "$(CFG)" !=\
 "SumInfo - Win32 Release MinDependency" && "$(CFG)" !=\
 "SumInfo - Win32 Unicode Release MinSize" && "$(CFG)" !=\
 "SumInfo - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "suminfo.mak" CFG="SumInfo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SumInfo - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SumInfo - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SumInfo - Win32 Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SumInfo - Win32 Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SumInfo - Win32 Unicode Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SumInfo - Win32 Unicode Release MinDependency" (based on\
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

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.ilk"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OUTDIR)\suminfo.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /Fp"$(INTDIR)\suminfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\suminfo.pdb" /debug /machine:I386\
 /def:".\SumInfo.def" /out:"$(OUTDIR)\suminfo.dll"\
 /implib:"$(OUTDIR)\suminfo.lib" /pdbtype:sept 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\suminfo.dll
InputPath=.\Debug\suminfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.ilk"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OUTDIR)\suminfo.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\suminfo.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\suminfo.pdb" /debug /machine:I386\
 /def:".\SumInfo.def" /out:"$(OUTDIR)\suminfo.dll"\
 /implib:"$(OUTDIR)\suminfo.lib" /pdbtype:sept 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\suminfo.dll
InputPath=.\DebugU\suminfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_ATL_DLL" /Fp"$(INTDIR)\suminfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\suminfo.pdb" /machine:I386 /def:".\SumInfo.def"\
 /out:"$(OUTDIR)\suminfo.dll" /implib:"$(OUTDIR)\suminfo.lib" 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\suminfo.dll
InputPath=.\ReleaseMinSize\suminfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\suminfo.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\suminfo.pdb" /machine:I386 /def:".\SumInfo.def"\
 /out:"$(OUTDIR)\suminfo.dll" /implib:"$(OUTDIR)\suminfo.lib" 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\suminfo.dll
InputPath=.\ReleaseMinDependency\suminfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\suminfo.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\suminfo.pdb" /machine:I386 /def:".\SumInfo.def"\
 /out:"$(OUTDIR)\suminfo.dll" /implib:"$(OUTDIR)\suminfo.lib" 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\suminfo.dll
InputPath=.\ReleaseUMinSize\suminfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\suminfo.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SumBase.obj"
	-@erase "$(INTDIR)\SumEnum.obj"
	-@erase "$(INTDIR)\SumInfo.obj"
	-@erase "$(INTDIR)\suminfo.pch"
	-@erase "$(INTDIR)\SumInfo.res"
	-@erase "$(INTDIR)\SumInfos.obj"
	-@erase "$(INTDIR)\SumObj.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\suminfo.dll"
	-@erase "$(OUTDIR)\suminfo.exp"
	-@erase "$(OUTDIR)\suminfo.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\suminfo.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SumInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\suminfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\suminfo.pdb" /machine:I386 /def:".\SumInfo.def"\
 /out:"$(OUTDIR)\suminfo.dll" /implib:"$(OUTDIR)\suminfo.lib" 
DEF_FILE= \
	".\SumInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SumBase.obj" \
	"$(INTDIR)\SumEnum.obj" \
	"$(INTDIR)\SumInfo.obj" \
	"$(INTDIR)\SumInfo.res" \
	"$(INTDIR)\SumInfos.obj" \
	"$(INTDIR)\SumObj.obj"

"$(OUTDIR)\suminfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\suminfo.dll
InputPath=.\ReleaseUMinDependency\suminfo.dll
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


!IF "$(CFG)" == "SumInfo - Win32 Debug" || "$(CFG)" ==\
 "SumInfo - Win32 Unicode Debug" || "$(CFG)" ==\
 "SumInfo - Win32 Release MinSize" || "$(CFG)" ==\
 "SumInfo - Win32 Release MinDependency" || "$(CFG)" ==\
 "SumInfo - Win32 Unicode Release MinSize" || "$(CFG)" ==\
 "SumInfo - Win32 Unicode Release MinDependency"
SOURCE=..\..\devsmpl\catlpwr\source\context.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	"..\..\devsmpl\catlpwr\source\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	"..\..\devsmpl\catlpwr\source\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	"..\..\devsmpl\catlpwr\source\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	"..\..\devsmpl\catlpwr\source\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_CONTE=\
	"..\..\devsmpl\catlpwr\source\context.h"\
	"..\..\devsmpl\catlpwr\source\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\suminfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\suminfo.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /Fp"$(INTDIR)\suminfo.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\suminfo.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\suminfo.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\suminfo.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\suminfo.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SumBase.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_SUMBA=\
	".\context.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_SUMBA=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_SUMBA=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_SUMBA=\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_SUMBA=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_SUMBA=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	

"$(INTDIR)\SumBase.obj" : $(SOURCE) $(DEP_CPP_SUMBA) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ENDIF 

SOURCE=.\SumEnum.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_SUMEN=\
	".\context.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_SUMEN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_SUMEN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_SUMEN=\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_SUMEN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_SUMEN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumEnum.obj" : $(SOURCE) $(DEP_CPP_SUMEN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ENDIF 

SOURCE=.\SumInfo.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_SUMIN=\
	".\context.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo_i.c" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_SUMIN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h" ".\SumInfo_i.c"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_SUMIN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h" ".\SumInfo_i.c"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_SUMIN=\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h" ".\SumInfo_i.c"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_SUMIN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h" ".\SumInfo_i.c"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_SUMIN=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfo_i.c"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfo.obj" : $(SOURCE) $(DEP_CPP_SUMIN) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h" ".\SumInfo_i.c"


!ENDIF 

SOURCE=.\SumInfo.idl

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

InputPath=.\SumInfo.idl

".\SumInfo.tlb"	".\SumInfo.h"	".\SumInfo_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /Oicf /h "SumInfo.h" /iid "SumInfo_i.c" "SumInfo.idl"

!ENDIF 

SOURCE=.\SumInfo.rc
DEP_RSC_SUMINF=\
	".\SumInfo.rgs"\
	".\SumInfo.tlb"\
	".\SumInfos.rgs"\
	

"$(INTDIR)\SumInfo.res" : $(SOURCE) $(DEP_RSC_SUMINF) "$(INTDIR)"\
 ".\SumInfo.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\SumInfos.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_SUMINFO=\
	".\context.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_SUMINFO=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_SUMINFO=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_SUMINFO=\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_SUMINFO=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_SUMINFO=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumEnum.h"\
	".\SumInfo.h"\
	".\SumInfos.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumInfos.obj" : $(SOURCE) $(DEP_CPP_SUMINFO) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ENDIF 

SOURCE=.\SumObj.cpp

!IF  "$(CFG)" == "SumInfo - Win32 Debug"

DEP_CPP_SUMOB=\
	".\context.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Debug"

DEP_CPP_SUMOB=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinSize"

DEP_CPP_SUMOB=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Release MinDependency"

DEP_CPP_SUMOB=\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinSize"

DEP_CPP_SUMOB=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ELSEIF  "$(CFG)" == "SumInfo - Win32 Unicode Release MinDependency"

DEP_CPP_SUMOB=\
	".\context.h"\
	".\StdAfx.h"\
	".\SumBase.h"\
	".\SumInfo.h"\
	".\SumObj.h"\
	

"$(INTDIR)\SumObj.obj" : $(SOURCE) $(DEP_CPP_SUMOB) "$(INTDIR)"\
 "$(INTDIR)\suminfo.pch" ".\SumInfo.h"


!ENDIF 


!ENDIF 

