# Microsoft Developer Studio Generated NMAKE File, Based on controt.dsp
!IF "$(CFG)" == ""
CFG=ContRot - Win32 Release
!MESSAGE No configuration specified. Defaulting to ContRot - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ContRot - Win32 Release" && "$(CFG)" !=\
 "ContRot - Win32 Debug" && "$(CFG)" != "ContRot - Win32 Unicode Release" &&\
 "$(CFG)" != "ContRot - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "controt.mak" CFG="ContRot - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ContRot - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ContRot - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ContRot - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ContRot - Win32 Unicode Debug" (based on\
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

!IF  "$(CFG)" == "ContRot - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\ContRot.obj"
	-@erase "$(INTDIR)\controt.pch"
	-@erase "$(INTDIR)\ContRot.res"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\controt.dll"
	-@erase "$(OUTDIR)\controt.exp"
	-@erase "$(OUTDIR)\controt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\controt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ContRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\controt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\controt.pdb" /machine:I386 /def:".\ContRot.def"\
 /out:"$(OUTDIR)\controt.dll" /implib:"$(OUTDIR)\controt.lib" 
DEF_FILE= \
	".\ContRot.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\ContRot.obj" \
	"$(INTDIR)\ContRot.res" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\controt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\controt.dll
InputPath=.\Release\controt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\ContRot.obj"
	-@erase "$(INTDIR)\controt.pch"
	-@erase "$(INTDIR)\ContRot.res"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\controt.dll"
	-@erase "$(OUTDIR)\controt.exp"
	-@erase "$(OUTDIR)\controt.ilk"
	-@erase "$(OUTDIR)\controt.lib"
	-@erase "$(OUTDIR)\controt.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\controt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ContRot.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\controt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\controt.pdb" /debug /machine:I386\
 /def:".\ContRot.def" /out:"$(OUTDIR)\controt.dll"\
 /implib:"$(OUTDIR)\controt.lib" 
DEF_FILE= \
	".\ContRot.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\ContRot.obj" \
	"$(INTDIR)\ContRot.res" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\controt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\controt.dll
InputPath=.\Debug\controt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\ContRot.obj"
	-@erase "$(INTDIR)\controt.pch"
	-@erase "$(INTDIR)\ContRot.res"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\controt.dll"
	-@erase "$(OUTDIR)\controt.exp"
	-@erase "$(OUTDIR)\controt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\controt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ContRot.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\controt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\controt.pdb" /machine:I386 /def:".\ContRot.def"\
 /out:"$(OUTDIR)\controt.dll" /implib:"$(OUTDIR)\controt.lib" 
DEF_FILE= \
	".\ContRot.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\ContRot.obj" \
	"$(INTDIR)\ContRot.res" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\controt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\controt.dll
InputPath=.\ReleaseU\controt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\controt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\ContRot.obj"
	-@erase "$(INTDIR)\controt.pch"
	-@erase "$(INTDIR)\ContRot.res"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\RotObj.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\controt.dll"
	-@erase "$(OUTDIR)\controt.exp"
	-@erase "$(OUTDIR)\controt.ilk"
	-@erase "$(OUTDIR)\controt.lib"
	-@erase "$(OUTDIR)\controt.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\controt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ContRot.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\controt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\controt.pdb" /debug /machine:I386\
 /def:".\ContRot.def" /out:"$(OUTDIR)\controt.dll"\
 /implib:"$(OUTDIR)\controt.lib" 
DEF_FILE= \
	".\ContRot.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\ContRot.obj" \
	"$(INTDIR)\ContRot.res" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\RotObj.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\controt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\controt.dll
InputPath=.\DebugU\controt.dll
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


!IF "$(CFG)" == "ContRot - Win32 Release" || "$(CFG)" ==\
 "ContRot - Win32 Debug" || "$(CFG)" == "ContRot - Win32 Unicode Release" ||\
 "$(CFG)" == "ContRot - Win32 Unicode Debug"
SOURCE=.\context.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_CONTE=\
	".\mystring.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ENDIF 

SOURCE=.\ContRot.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_CONTR=\
	".\context.h"\
	".\ContRot.h"\
	".\ContRot_i.c"\
	".\debug.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	
NODEP_CPP_CONTR=\
	".\mystring.h"\
	

"$(INTDIR)\ContRot.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h" ".\ContRot_i.c"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_CONTR=\
	".\context.h"\
	".\ContRot.h"\
	".\ContRot_i.c"\
	".\debug.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ContRot.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h" ".\ContRot_i.c"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_CONTR=\
	".\context.h"\
	".\ContRot.h"\
	".\ContRot_i.c"\
	".\debug.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ContRot.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h" ".\ContRot_i.c"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_CONTR=\
	".\context.h"\
	".\ContRot.h"\
	".\ContRot_i.c"\
	".\debug.h"\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ContRot.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h" ".\ContRot_i.c"


!ENDIF 

SOURCE=.\ContRot.idl

!IF  "$(CFG)" == "ContRot - Win32 Release"

InputPath=.\ContRot.idl

"ContRot.tlb"	"ContRot.h"	"ContRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl ContRot.idl

!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

InputPath=.\ContRot.idl

"ContRot.tlb"	"ContRot.h"	"ContRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl ContRot.idl

!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

InputPath=.\ContRot.idl

"ContRot.tlb"	"ContRot.h"	"ContRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl ContRot.idl

!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

InputPath=.\ContRot.idl

"ContRot.tlb"	"ContRot.h"	"ContRot_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl ContRot.idl

!ENDIF 

SOURCE=.\ContRot.rc
DEP_RSC_CONTRO=\
	".\ContRot.tlb"\
	

"$(INTDIR)\ContRot.res" : $(SOURCE) $(DEP_RSC_CONTRO) "$(INTDIR)"\
 ".\ContRot.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\debug.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_DEBUG=\
	".\mystring.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_DEBUG=\
	".\debug.h"\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\debug.obj" : $(SOURCE) $(DEP_CPP_DEBUG) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ENDIF 

SOURCE=.\mem.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_MEM_C=\
	".\mystring.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_MEM_C=\
	".\mydebug.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\mem.obj" : $(SOURCE) $(DEP_CPP_MEM_C) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ENDIF 

SOURCE=.\Monitor.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	
NODEP_CPP_MONIT=\
	".\mystring.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_MONIT=\
	".\lock.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\controt.pch"


!ENDIF 

SOURCE=.\RotObj.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_ROTOB=\
	".\context.h"\
	".\ContRot.h"\
	".\debug.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	
NODEP_CPP_ROTOB=\
	".\mystring.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_ROTOB=\
	".\context.h"\
	".\ContRot.h"\
	".\debug.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_ROTOB=\
	".\context.h"\
	".\ContRot.h"\
	".\debug.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h"


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_ROTOB=\
	".\context.h"\
	".\ContRot.h"\
	".\debug.h"\
	".\Monitor.h"\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\RotObj.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RotObj.obj" : $(SOURCE) $(DEP_CPP_ROTOB) "$(INTDIR)"\
 "$(INTDIR)\controt.pch" ".\ContRot.h"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ContRot - Win32 Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\refcount.h"\
	".\refptr.h"\
	".\StdAfx.h"\
	
NODEP_CPP_STDAF=\
	".\mystring.h"\
	".\myvector.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\controt.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\controt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ContRot - Win32 Debug"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\controt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\controt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\controt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\controt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ContRot - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\mydebug.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\controt.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\controt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

