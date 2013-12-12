# Microsoft Developer Studio Generated NMAKE File, Based on PageCnt.dsp
!IF "$(CFG)" == ""
CFG=PgCnt - Win32 Release
!MESSAGE No configuration specified. Defaulting to PgCnt - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "PgCnt - Win32 Release" && "$(CFG)" != "PgCnt - Win32 Debug" &&\
 "$(CFG)" != "PgCnt - Win32 Unicode Release" && "$(CFG)" !=\
 "PgCnt - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PageCnt.mak" CFG="PgCnt - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PgCnt - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PgCnt - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PgCnt - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PgCnt - Win32 Unicode Debug" (based on\
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

!IF  "$(CFG)" == "PgCnt - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ccm.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\monitor.obj"
	-@erase "$(INTDIR)\Page.obj"
	-@erase "$(INTDIR)\PageCnt.pch"
	-@erase "$(INTDIR)\PgCnt.obj"
	-@erase "$(INTDIR)\PgCnt.res"
	-@erase "$(INTDIR)\PgCntObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\PageCnt.dll"
	-@erase "$(OUTDIR)\PageCnt.exp"
	-@erase "$(OUTDIR)\PageCnt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\PageCnt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PgCnt.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PageCnt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\PageCnt.pdb" /machine:I386 /def:".\PgCnt.def"\
 /out:"$(OUTDIR)\PageCnt.dll" /implib:"$(OUTDIR)\PageCnt.lib" 
DEF_FILE= \
	".\PgCnt.def"
LINK32_OBJS= \
	"$(INTDIR)\ccm.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\monitor.obj" \
	"$(INTDIR)\Page.obj" \
	"$(INTDIR)\PgCnt.obj" \
	"$(INTDIR)\PgCnt.res" \
	"$(INTDIR)\PgCntObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PageCnt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\PageCnt.dll
InputPath=.\Release\PageCnt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ccm.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\monitor.obj"
	-@erase "$(INTDIR)\Page.obj"
	-@erase "$(INTDIR)\PageCnt.pch"
	-@erase "$(INTDIR)\PgCnt.obj"
	-@erase "$(INTDIR)\PgCnt.res"
	-@erase "$(INTDIR)\PgCntObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\PageCnt.dll"
	-@erase "$(OUTDIR)\PageCnt.ilk"
	-@erase "$(OUTDIR)\PageCount.exp"
	-@erase "$(OUTDIR)\PageCount.lib"
	-@erase "$(OUTDIR)\PageCount.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\PageCnt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PgCnt.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PageCnt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\PageCount.pdb" /debug /machine:I386\
 /def:".\PgCnt.def" /out:"$(OUTDIR)\PageCnt.dll"\
 /implib:"$(OUTDIR)\PageCount.lib" 
DEF_FILE= \
	".\PgCnt.def"
LINK32_OBJS= \
	"$(INTDIR)\ccm.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\monitor.obj" \
	"$(INTDIR)\Page.obj" \
	"$(INTDIR)\PgCnt.obj" \
	"$(INTDIR)\PgCnt.res" \
	"$(INTDIR)\PgCntObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PageCnt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\PageCnt.dll
InputPath=.\Debug\PageCnt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ccm.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\monitor.obj"
	-@erase "$(INTDIR)\Page.obj"
	-@erase "$(INTDIR)\PageCnt.pch"
	-@erase "$(INTDIR)\PgCnt.obj"
	-@erase "$(INTDIR)\PgCnt.res"
	-@erase "$(INTDIR)\PgCntObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\PageCnt.dll"
	-@erase "$(OUTDIR)\PageCnt.exp"
	-@erase "$(OUTDIR)\PageCnt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PageCnt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PgCnt.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PageCnt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\PageCnt.pdb" /machine:I386 /def:".\PgCnt.def"\
 /out:"$(OUTDIR)\PageCnt.dll" /implib:"$(OUTDIR)\PageCnt.lib" 
DEF_FILE= \
	".\PgCnt.def"
LINK32_OBJS= \
	"$(INTDIR)\ccm.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\monitor.obj" \
	"$(INTDIR)\Page.obj" \
	"$(INTDIR)\PgCnt.obj" \
	"$(INTDIR)\PgCnt.res" \
	"$(INTDIR)\PgCntObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PageCnt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\PageCnt.dll
InputPath=.\ReleaseU\PageCnt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PageCnt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ccm.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\monitor.obj"
	-@erase "$(INTDIR)\Page.obj"
	-@erase "$(INTDIR)\PageCnt.pch"
	-@erase "$(INTDIR)\PgCnt.obj"
	-@erase "$(INTDIR)\PgCnt.res"
	-@erase "$(INTDIR)\PgCntObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\PageCnt.dll"
	-@erase "$(OUTDIR)\PageCnt.exp"
	-@erase "$(OUTDIR)\PageCnt.ilk"
	-@erase "$(OUTDIR)\PageCnt.lib"
	-@erase "$(OUTDIR)\PageCnt.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PageCnt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PgCnt.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PageCnt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\PageCnt.pdb" /debug /machine:I386\
 /def:".\PgCnt.def" /out:"$(OUTDIR)\PageCnt.dll" /implib:"$(OUTDIR)\PageCnt.lib"\
 
DEF_FILE= \
	".\PgCnt.def"
LINK32_OBJS= \
	"$(INTDIR)\ccm.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\monitor.obj" \
	"$(INTDIR)\Page.obj" \
	"$(INTDIR)\PgCnt.obj" \
	"$(INTDIR)\PgCnt.res" \
	"$(INTDIR)\PgCntObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PageCnt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\PageCnt.dll
InputPath=.\DebugU\PageCnt.dll
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


!IF "$(CFG)" == "PgCnt - Win32 Release" || "$(CFG)" == "PgCnt - Win32 Debug" ||\
 "$(CFG)" == "PgCnt - Win32 Unicode Release" || "$(CFG)" ==\
 "PgCnt - Win32 Unicode Debug"
SOURCE=.\ccm.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_CCM_C=\
	".\ccm.h"\
	".\critsec.h"\
	".\debug.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_CCM_C=\
	".\mystring.h"\
	

"$(INTDIR)\ccm.obj" : $(SOURCE) $(DEP_CPP_CCM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_CCM_C=\
	".\ccm.h"\
	".\critsec.h"\
	".\debug.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ccm.obj" : $(SOURCE) $(DEP_CPP_CCM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_CCM_C=\
	".\ccm.h"\
	".\critsec.h"\
	".\debug.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ccm.obj" : $(SOURCE) $(DEP_CPP_CCM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_CCM_C=\
	".\ccm.h"\
	".\critsec.h"\
	".\debug.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ccm.obj" : $(SOURCE) $(DEP_CPP_CCM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\context.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_CONTE=\
	".\mystring.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\debug.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_DEBUG=\
	".\mystring.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\mem.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_MEM_C=\
	".\mystring.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\monitor.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_MONIT=\
	".\mystring.h"\
	

"$(INTDIR)\monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\Page.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_PAGE_=\
	".\debug.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_PAGE_=\
	".\mystring.h"\
	

"$(INTDIR)\Page.obj" : $(SOURCE) $(DEP_CPP_PAGE_) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_PAGE_=\
	".\debug.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Page.obj" : $(SOURCE) $(DEP_CPP_PAGE_) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_PAGE_=\
	".\debug.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Page.obj" : $(SOURCE) $(DEP_CPP_PAGE_) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_PAGE_=\
	".\debug.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Page.obj" : $(SOURCE) $(DEP_CPP_PAGE_) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch"


!ENDIF 

SOURCE=.\PgCnt.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_PGCNT=\
	".\ccm.h"\
	".\debug.h"\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_PGCNT=\
	".\mystring.h"\
	".\PgCnt.h"\
	".\PgCnt_i.c"\
	

"$(INTDIR)\PgCnt.obj" : $(SOURCE) $(DEP_CPP_PGCNT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt_i.c" ".\PgCnt.h"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_PGCNT=\
	".\ccm.h"\
	".\debug.h"\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNT=\
	".\PgCnt.h"\
	".\PgCnt_i.c"\
	

"$(INTDIR)\PgCnt.obj" : $(SOURCE) $(DEP_CPP_PGCNT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h" ".\PgCnt_i.c"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_PGCNT=\
	".\ccm.h"\
	".\debug.h"\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNT=\
	".\PgCnt.h"\
	".\PgCnt_i.c"\
	

"$(INTDIR)\PgCnt.obj" : $(SOURCE) $(DEP_CPP_PGCNT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h" ".\PgCnt_i.c"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_PGCNT=\
	".\ccm.h"\
	".\debug.h"\
	".\lock.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNT=\
	".\PgCnt.h"\
	".\PgCnt_i.c"\
	

"$(INTDIR)\PgCnt.obj" : $(SOURCE) $(DEP_CPP_PGCNT) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h" ".\PgCnt_i.c"


!ENDIF 

SOURCE=.\PgCnt.idl

!IF  "$(CFG)" == "PgCnt - Win32 Release"

InputPath=.\PgCnt.idl

"PgCnt.tlb"	"PgCnt.h"	"PgCnt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PgCnt.idl

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

InputPath=.\PgCnt.idl

"PgCnt.tlb"	"PgCnt.h"	"PgCnt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PgCnt.idl

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

InputPath=.\PgCnt.idl

"PgCnt.tlb"	"PgCnt.h"	"PgCnt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PgCnt.idl

!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

InputPath=.\PgCnt.idl

"PgCnt.tlb"	"PgCnt.h"	"PgCnt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PgCnt.idl

!ENDIF 

SOURCE=.\PgCnt.rc
NODEP_RSC_PGCNT_=\
	".\PgCnt.tlb"\
	

"$(INTDIR)\PgCnt.res" : $(SOURCE) "$(INTDIR)" ".\PgCnt.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PgCntObj.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_PGCNTO=\
	".\ccm.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_PGCNTO=\
	".\mystring.h"\
	".\PgCnt.h"\
	

"$(INTDIR)\PgCntObj.obj" : $(SOURCE) $(DEP_CPP_PGCNTO) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_PGCNTO=\
	".\ccm.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNTO=\
	".\PgCnt.h"\
	

"$(INTDIR)\PgCntObj.obj" : $(SOURCE) $(DEP_CPP_PGCNTO) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_PGCNTO=\
	".\ccm.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNTO=\
	".\PgCnt.h"\
	

"$(INTDIR)\PgCntObj.obj" : $(SOURCE) $(DEP_CPP_PGCNTO) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h"


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_PGCNTO=\
	".\ccm.h"\
	".\monitor.h"\
	".\mydebug.h"\
	".\Page.h"\
	".\PgCntObj.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_PGCNTO=\
	".\PgCnt.h"\
	

"$(INTDIR)\PgCntObj.obj" : $(SOURCE) $(DEP_CPP_PGCNTO) "$(INTDIR)"\
 "$(INTDIR)\PageCnt.pch" ".\PgCnt.h"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "PgCnt - Win32 Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_STDAF=\
	".\mystring.h"\
	".\myvector.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\PageCnt.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PageCnt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Debug"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\PageCnt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PageCnt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PageCnt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PageCnt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PgCnt - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\PageCnt.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PageCnt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

