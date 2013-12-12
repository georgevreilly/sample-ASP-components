# Microsoft Developer Studio Generated NMAKE File, Based on permchk.dsp
!IF "$(CFG)" == ""
CFG=PermChk - Win32 Release
!MESSAGE No configuration specified. Defaulting to PermChk - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "PermChk - Win32 Release" && "$(CFG)" !=\
 "PermChk - Win32 Debug" && "$(CFG)" != "PermChk - Win32 Unicode Release" &&\
 "$(CFG)" != "PermChk - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "permchk.mak" CFG="PermChk - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PermChk - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PermChk - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PermChk - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PermChk - Win32 Unicode Debug" (based on\
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

!IF  "$(CFG)" == "PermChk - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChkObj.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\PermChk.obj"
	-@erase "$(INTDIR)\permchk.pch"
	-@erase "$(INTDIR)\PermChk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\permchk.dll"
	-@erase "$(OUTDIR)\permchk.exp"
	-@erase "$(OUTDIR)\permchk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\permchk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PermChk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\permchk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\permchk.pdb" /machine:I386 /def:".\PermChk.def"\
 /out:"$(OUTDIR)\permchk.dll" /implib:"$(OUTDIR)\permchk.lib" 
DEF_FILE= \
	".\PermChk.def"
LINK32_OBJS= \
	"$(INTDIR)\ChkObj.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\PermChk.obj" \
	"$(INTDIR)\PermChk.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\util.obj"

"$(OUTDIR)\permchk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\permchk.dll
InputPath=.\Release\permchk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChkObj.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\PermChk.obj"
	-@erase "$(INTDIR)\permchk.pch"
	-@erase "$(INTDIR)\PermChk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\permchk.dll"
	-@erase "$(OUTDIR)\permchk.exp"
	-@erase "$(OUTDIR)\permchk.ilk"
	-@erase "$(OUTDIR)\permchk.lib"
	-@erase "$(OUTDIR)\permchk.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\permchk.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PermChk.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\permchk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\permchk.pdb" /debug /machine:I386\
 /def:".\PermChk.def" /out:"$(OUTDIR)\permchk.dll"\
 /implib:"$(OUTDIR)\permchk.lib" 
DEF_FILE= \
	".\PermChk.def"
LINK32_OBJS= \
	"$(INTDIR)\ChkObj.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\PermChk.obj" \
	"$(INTDIR)\PermChk.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\util.obj"

"$(OUTDIR)\permchk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\permchk.dll
InputPath=.\Debug\permchk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChkObj.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\PermChk.obj"
	-@erase "$(INTDIR)\permchk.pch"
	-@erase "$(INTDIR)\PermChk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\permchk.dll"
	-@erase "$(OUTDIR)\permchk.exp"
	-@erase "$(OUTDIR)\permchk.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\permchk.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PermChk.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\permchk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\permchk.pdb" /machine:I386 /def:".\PermChk.def"\
 /out:"$(OUTDIR)\permchk.dll" /implib:"$(OUTDIR)\permchk.lib" 
DEF_FILE= \
	".\PermChk.def"
LINK32_OBJS= \
	"$(INTDIR)\ChkObj.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\PermChk.obj" \
	"$(INTDIR)\PermChk.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\util.obj"

"$(OUTDIR)\permchk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\permchk.dll
InputPath=.\ReleaseU\permchk.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\permchk.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChkObj.obj"
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\PermChk.obj"
	-@erase "$(INTDIR)\permchk.pch"
	-@erase "$(INTDIR)\PermChk.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\permchk.dll"
	-@erase "$(OUTDIR)\permchk.exp"
	-@erase "$(OUTDIR)\permchk.ilk"
	-@erase "$(OUTDIR)\permchk.lib"
	-@erase "$(OUTDIR)\permchk.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\permchk.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PermChk.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\permchk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\permchk.pdb" /debug /machine:I386\
 /def:".\PermChk.def" /out:"$(OUTDIR)\permchk.dll"\
 /implib:"$(OUTDIR)\permchk.lib" 
DEF_FILE= \
	".\PermChk.def"
LINK32_OBJS= \
	"$(INTDIR)\ChkObj.obj" \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\PermChk.obj" \
	"$(INTDIR)\PermChk.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\util.obj"

"$(OUTDIR)\permchk.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\permchk.dll
InputPath=.\DebugU\permchk.dll
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


!IF "$(CFG)" == "PermChk - Win32 Release" || "$(CFG)" ==\
 "PermChk - Win32 Debug" || "$(CFG)" == "PermChk - Win32 Unicode Release" ||\
 "$(CFG)" == "PermChk - Win32 Unicode Debug"
SOURCE=.\ChkObj.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"

DEP_CPP_CHKOB=\
	".\ChkObj.h"\
	".\context.h"\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\ChkObj.obj" : $(SOURCE) $(DEP_CPP_CHKOB) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_CHKOB=\
	".\ChkObj.h"\
	".\context.h"\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\ChkObj.obj" : $(SOURCE) $(DEP_CPP_CHKOB) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_CHKOB=\
	".\ChkObj.h"\
	".\context.h"\
	".\mydebug.h"\
	".\PermChk.h"\
	".\StdAfx.h"\
	".\util.h"\
	

"$(INTDIR)\ChkObj.obj" : $(SOURCE) $(DEP_CPP_CHKOB) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_CHKOB=\
	".\ChkObj.h"\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\ChkObj.obj" : $(SOURCE) $(DEP_CPP_CHKOB) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ENDIF 

SOURCE=..\..\pagecnt\source\context.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"

DEP_CPP_CONTE=\
	"..\..\pagecnt\source\context.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_CONTE=\
	"..\..\pagecnt\source\context.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_CONTE=\
	"..\..\pagecnt\source\context.h"\
	"..\..\pagecnt\source\mydebug.h"\
	"..\..\pagecnt\source\mystring.h"\
	"..\..\pagecnt\source\myvector.h"\
	"..\..\pagecnt\source\refcount.h"\
	"..\..\pagecnt\source\refptr.h"\
	"..\..\pagecnt\source\StdAfx.h"\
	"..\..\pagecnt\source\strmap.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_CONTE=\
	"..\..\pagecnt\source\context.h"\
	"..\..\pagecnt\source\mydebug.h"\
	"..\..\pagecnt\source\mystring.h"\
	"..\..\pagecnt\source\myvector.h"\
	"..\..\pagecnt\source\refcount.h"\
	"..\..\pagecnt\source\refptr.h"\
	"..\..\pagecnt\source\StdAfx.h"\
	"..\..\pagecnt\source\strmap.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\pagecnt\source\mem.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"


"$(INTDIR)\mem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_MEM_C=\
	"..\..\pagecnt\source\mydebug.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_MEM_C=\
	"..\..\pagecnt\source\mydebug.h"\
	"..\..\pagecnt\source\mystring.h"\
	"..\..\pagecnt\source\myvector.h"\
	"..\..\pagecnt\source\refcount.h"\
	"..\..\pagecnt\source\refptr.h"\
	"..\..\pagecnt\source\StdAfx.h"\
	"..\..\pagecnt\source\strmap.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_MEM_C=\
	"..\..\pagecnt\source\mydebug.h"\
	"..\..\pagecnt\source\mystring.h"\
	"..\..\pagecnt\source\myvector.h"\
	"..\..\pagecnt\source\refcount.h"\
	"..\..\pagecnt\source\refptr.h"\
	"..\..\pagecnt\source\StdAfx.h"\
	"..\..\pagecnt\source\strmap.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\PermChk.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"

DEP_CPP_PERMC=\
	".\ChkObj.h"\
	".\PermChk.h"\
	".\PermChk_i.c"\
	

"$(INTDIR)\PermChk.obj" : $(SOURCE) $(DEP_CPP_PERMC) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk_i.c" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_PERMC=\
	".\ChkObj.h"\
	".\PermChk.h"\
	".\PermChk_i.c"\
	

"$(INTDIR)\PermChk.obj" : $(SOURCE) $(DEP_CPP_PERMC) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h" ".\PermChk_i.c"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_PERMC=\
	".\ChkObj.h"\
	".\mydebug.h"\
	".\PermChk.h"\
	".\PermChk_i.c"\
	".\StdAfx.h"\
	

"$(INTDIR)\PermChk.obj" : $(SOURCE) $(DEP_CPP_PERMC) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h" ".\PermChk_i.c"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_PERMC=\
	".\ChkObj.h"\
	".\PermChk.h"\
	".\PermChk_i.c"\
	

"$(INTDIR)\PermChk.obj" : $(SOURCE) $(DEP_CPP_PERMC) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk_i.c" ".\PermChk.h"


!ENDIF 

SOURCE=.\PermChk.idl

!IF  "$(CFG)" == "PermChk - Win32 Release"

InputPath=.\PermChk.idl

"PermChk.tlb"	"PermChk.h"	"PermChk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PermChk.idl

!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

InputPath=.\PermChk.idl

"PermChk.tlb"	"PermChk.h"	"PermChk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PermChk.idl

!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

InputPath=.\PermChk.idl

"PermChk.tlb"	"PermChk.h"	"PermChk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PermChk.idl

!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

InputPath=.\PermChk.idl

"PermChk.tlb"	"PermChk.h"	"PermChk_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl PermChk.idl

!ENDIF 

SOURCE=.\PermChk.rc
DEP_RSC_PERMCH=\
	".\PermChk.tlb"\
	

"$(INTDIR)\PermChk.res" : $(SOURCE) $(DEP_RSC_PERMCH) "$(INTDIR)"\
 ".\PermChk.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\permchk.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\permchk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\permchk.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\permchk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\permchk.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\permchk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\permchk.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\permchk.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\util.cpp

!IF  "$(CFG)" == "PermChk - Win32 Release"

DEP_CPP_UTIL_=\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Debug"

DEP_CPP_UTIL_=\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Release"

DEP_CPP_UTIL_=\
	".\mydebug.h"\
	".\PermChk.h"\
	".\StdAfx.h"\
	".\util.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ELSEIF  "$(CFG)" == "PermChk - Win32 Unicode Debug"

DEP_CPP_UTIL_=\
	".\PermChk.h"\
	".\util.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"\
 "$(INTDIR)\permchk.pch" ".\PermChk.h"


!ENDIF 


!ENDIF 

