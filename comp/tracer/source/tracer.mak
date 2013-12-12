# Microsoft Developer Studio Generated NMAKE File, Based on tracer.dsp
!IF "$(CFG)" == ""
CFG=Tracer - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Tracer - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Tracer - Win32 Debug" && "$(CFG)" !=\
 "Tracer - Win32 Unicode Debug" && "$(CFG)" != "Tracer - Win32 Release MinSize"\
 && "$(CFG)" != "Tracer - Win32 Release MinDependency" && "$(CFG)" !=\
 "Tracer - Win32 Unicode Release MinSize" && "$(CFG)" !=\
 "Tracer - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tracer.mak" CFG="Tracer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tracer - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Tracer - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Tracer - Win32 Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Tracer - Win32 Release MinDependency" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Tracer - Win32 Unicode Release MinSize" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Tracer - Win32 Unicode Release MinDependency" (based on\
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

!IF  "$(CFG)" == "Tracer - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.ilk"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OUTDIR)\tracer.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /Fp"$(INTDIR)\tracer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib\
 odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\tracer.pdb" /debug /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" /pdbtype:sept 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\tracer.dll
InputPath=.\Debug\tracer.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.ilk"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OUTDIR)\tracer.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\tracer.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\tracer.pdb" /debug /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" /pdbtype:sept 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\tracer.dll
InputPath=.\DebugU\tracer.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tracer.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\tracer.pdb" /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\tracer.dll
InputPath=.\ReleaseMinSize\tracer.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tracer.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\tracer.pdb" /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\tracer.dll
InputPath=.\ReleaseMinDependency\tracer.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tracer.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseUMinSize/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\tracer.pdb" /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\tracer.dll
InputPath=.\ReleaseUMinSize\tracer.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\tracer.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TraceObj.obj"
	-@erase "$(INTDIR)\Tracer.obj"
	-@erase "$(INTDIR)\tracer.pch"
	-@erase "$(INTDIR)\Tracer.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\tracer.dll"
	-@erase "$(OUTDIR)\tracer.exp"
	-@erase "$(OUTDIR)\tracer.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL"\
 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT"\
 /Fp"$(INTDIR)\tracer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\ReleaseUMinDependency/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracer.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\tracer.pdb" /machine:I386 /def:".\Tracer.def"\
 /out:"$(OUTDIR)\tracer.dll" /implib:"$(OUTDIR)\tracer.lib" 
DEF_FILE= \
	".\Tracer.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TraceObj.obj" \
	"$(INTDIR)\Tracer.obj" \
	"$(INTDIR)\Tracer.res"

"$(OUTDIR)\tracer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\tracer.dll
InputPath=.\ReleaseUMinDependency\tracer.dll
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


!IF "$(CFG)" == "Tracer - Win32 Debug" || "$(CFG)" ==\
 "Tracer - Win32 Unicode Debug" || "$(CFG)" == "Tracer - Win32 Release MinSize"\
 || "$(CFG)" == "Tracer - Win32 Release MinDependency" || "$(CFG)" ==\
 "Tracer - Win32 Unicode Release MinSize" || "$(CFG)" ==\
 "Tracer - Win32 Unicode Release MinDependency"
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tracer - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\tracer.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\tracer.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tracer.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tracer.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT"\
 /Fp"$(INTDIR)\tracer.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT"\
 /Fp"$(INTDIR)\tracer.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tracer.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TraceObj.cpp
DEP_CPP_TRACE=\
	".\StdAfx.h"\
	".\TraceObj.h"\
	
NODEP_CPP_TRACE=\
	".\Tracer.h"\
	

"$(INTDIR)\TraceObj.obj" : $(SOURCE) $(DEP_CPP_TRACE) "$(INTDIR)"\
 "$(INTDIR)\tracer.pch" ".\Tracer.h"


SOURCE=.\Tracer.cpp
DEP_CPP_TRACER=\
	".\StdAfx.h"\
	".\TraceObj.h"\
	
NODEP_CPP_TRACER=\
	".\Tracer.h"\
	".\Tracer_i.c"\
	

"$(INTDIR)\Tracer.obj" : $(SOURCE) $(DEP_CPP_TRACER) "$(INTDIR)"\
 "$(INTDIR)\tracer.pch" ".\Tracer.h" ".\Tracer_i.c"


SOURCE=.\Tracer.idl

!IF  "$(CFG)" == "Tracer - Win32 Debug"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Debug"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinSize"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ELSEIF  "$(CFG)" == "Tracer - Win32 Release MinDependency"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinSize"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ELSEIF  "$(CFG)" == "Tracer - Win32 Unicode Release MinDependency"

InputPath=.\Tracer.idl

".\Tracer.tlb"	".\Tracer.h"	".\Tracer_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oicf /h "Tracer.h" /iid "Tracer_i.c" "Tracer.idl"

!ENDIF 

SOURCE=.\Tracer.rc
DEP_RSC_TRACER_=\
	".\Tracer.rgs"\
	
NODEP_RSC_TRACER_=\
	".\Tracer.tlb"\
	

"$(INTDIR)\Tracer.res" : $(SOURCE) $(DEP_RSC_TRACER_) "$(INTDIR)"\
 ".\Tracer.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

