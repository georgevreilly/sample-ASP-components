# Microsoft Developer Studio Generated NMAKE File, Based on textfmt.dsp
!IF "$(CFG)" == ""
CFG=TextFmt - Win32 Release
!MESSAGE No configuration specified. Defaulting to TextFmt - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TextFmt - Win32 Release" && "$(CFG)" !=\
 "TextFmt - Win32 Debug" && "$(CFG)" != "TextFmt - Win32 Unicode Release" &&\
 "$(CFG)" != "TextFmt - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "textfmt.mak" CFG="TextFmt - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TextFmt - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TextFmt - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TextFmt - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TextFmt - Win32 Unicode Debug" (based on\
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

!IF  "$(CFG)" == "TextFmt - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\CTextFmt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextFmt.obj"
	-@erase "$(INTDIR)\textfmt.pch"
	-@erase "$(INTDIR)\TextFmt.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\textfmt.dll"
	-@erase "$(OUTDIR)\textfmt.exp"
	-@erase "$(OUTDIR)\textfmt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\textfmt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TextFmt.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\textfmt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\textfmt.pdb" /machine:I386 /def:".\TextFmt.def"\
 /out:"$(OUTDIR)\textfmt.dll" /implib:"$(OUTDIR)\textfmt.lib" 
DEF_FILE= \
	".\TextFmt.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\CTextFmt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextFmt.obj" \
	"$(INTDIR)\TextFmt.res"

"$(OUTDIR)\textfmt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\textfmt.dll
InputPath=.\Release\textfmt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\CTextFmt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextFmt.obj"
	-@erase "$(INTDIR)\textfmt.pch"
	-@erase "$(INTDIR)\TextFmt.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\textfmt.dll"
	-@erase "$(OUTDIR)\textfmt.exp"
	-@erase "$(OUTDIR)\textfmt.ilk"
	-@erase "$(OUTDIR)\textfmt.lib"
	-@erase "$(OUTDIR)\textfmt.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\textfmt.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TextFmt.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\textfmt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\textfmt.pdb" /debug /machine:I386\
 /def:".\TextFmt.def" /out:"$(OUTDIR)\textfmt.dll"\
 /implib:"$(OUTDIR)\textfmt.lib" 
DEF_FILE= \
	".\TextFmt.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\CTextFmt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextFmt.obj" \
	"$(INTDIR)\TextFmt.res"

"$(OUTDIR)\textfmt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\textfmt.dll
InputPath=.\Debug\textfmt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\CTextFmt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextFmt.obj"
	-@erase "$(INTDIR)\textfmt.pch"
	-@erase "$(INTDIR)\TextFmt.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\textfmt.dll"
	-@erase "$(OUTDIR)\textfmt.exp"
	-@erase "$(OUTDIR)\textfmt.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\textfmt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TextFmt.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\textfmt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\textfmt.pdb" /machine:I386 /def:".\TextFmt.def"\
 /out:"$(OUTDIR)\textfmt.dll" /implib:"$(OUTDIR)\textfmt.lib" 
DEF_FILE= \
	".\TextFmt.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\CTextFmt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextFmt.obj" \
	"$(INTDIR)\TextFmt.res"

"$(OUTDIR)\textfmt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\textfmt.dll
InputPath=.\ReleaseU\textfmt.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\textfmt.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\context.obj"
	-@erase "$(INTDIR)\CTextFmt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextFmt.obj"
	-@erase "$(INTDIR)\textfmt.pch"
	-@erase "$(INTDIR)\TextFmt.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\textfmt.dll"
	-@erase "$(OUTDIR)\textfmt.exp"
	-@erase "$(OUTDIR)\textfmt.ilk"
	-@erase "$(OUTDIR)\textfmt.lib"
	-@erase "$(OUTDIR)\textfmt.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\textfmt.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TextFmt.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\textfmt.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mtx.lib mtxguid.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\textfmt.pdb" /debug /machine:I386\
 /def:".\TextFmt.def" /out:"$(OUTDIR)\textfmt.dll"\
 /implib:"$(OUTDIR)\textfmt.lib" 
DEF_FILE= \
	".\TextFmt.def"
LINK32_OBJS= \
	"$(INTDIR)\context.obj" \
	"$(INTDIR)\CTextFmt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextFmt.obj" \
	"$(INTDIR)\TextFmt.res"

"$(OUTDIR)\textfmt.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\textfmt.dll
InputPath=.\DebugU\textfmt.dll
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


!IF "$(CFG)" == "TextFmt - Win32 Release" || "$(CFG)" ==\
 "TextFmt - Win32 Debug" || "$(CFG)" == "TextFmt - Win32 Unicode Release" ||\
 "$(CFG)" == "TextFmt - Win32 Unicode Debug"
SOURCE=.\context.cpp

!IF  "$(CFG)" == "TextFmt - Win32 Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

DEP_CPP_CONTE=\
	".\context.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

DEP_CPP_CONTE=\
	".\context.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\context.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch"


!ENDIF 

SOURCE=.\CTextFmt.cpp

!IF  "$(CFG)" == "TextFmt - Win32 Release"

DEP_CPP_CTEXT=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	

"$(INTDIR)\CTextFmt.obj" : $(SOURCE) $(DEP_CPP_CTEXT) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

DEP_CPP_CTEXT=\
	".\context.h"\
	".\CTextFmt.h"\
	".\TextFmt.h"\
	

"$(INTDIR)\CTextFmt.obj" : $(SOURCE) $(DEP_CPP_CTEXT) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

DEP_CPP_CTEXT=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	

"$(INTDIR)\CTextFmt.obj" : $(SOURCE) $(DEP_CPP_CTEXT) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

DEP_CPP_CTEXT=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	

"$(INTDIR)\CTextFmt.obj" : $(SOURCE) $(DEP_CPP_CTEXT) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "TextFmt - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\textfmt.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\textfmt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\textfmt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\textfmt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\textfmt.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\textfmt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\textfmt.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\textfmt.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TextFmt.cpp

!IF  "$(CFG)" == "TextFmt - Win32 Release"

DEP_CPP_TEXTF=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	".\TextFmt_i.c"\
	

"$(INTDIR)\TextFmt.obj" : $(SOURCE) $(DEP_CPP_TEXTF) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h" ".\TextFmt_i.c"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

DEP_CPP_TEXTF=\
	".\context.h"\
	".\CTextFmt.h"\
	".\TextFmt.h"\
	".\TextFmt_i.c"\
	

"$(INTDIR)\TextFmt.obj" : $(SOURCE) $(DEP_CPP_TEXTF) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt_i.c" ".\TextFmt.h"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

DEP_CPP_TEXTF=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	".\TextFmt_i.c"\
	

"$(INTDIR)\TextFmt.obj" : $(SOURCE) $(DEP_CPP_TEXTF) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h" ".\TextFmt_i.c"


!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

DEP_CPP_TEXTF=\
	".\context.h"\
	".\CTextFmt.h"\
	".\StdAfx.h"\
	".\TextFmt.h"\
	".\TextFmt_i.c"\
	

"$(INTDIR)\TextFmt.obj" : $(SOURCE) $(DEP_CPP_TEXTF) "$(INTDIR)"\
 "$(INTDIR)\textfmt.pch" ".\TextFmt.h" ".\TextFmt_i.c"


!ENDIF 

SOURCE=.\TextFmt.idl

!IF  "$(CFG)" == "TextFmt - Win32 Release"

InputPath=.\TextFmt.idl

"TextFmt.tlb"	"TextFmt.h"	"TextFmt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl TextFmt.idl

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Debug"

InputPath=.\TextFmt.idl

"TextFmt.tlb"	"TextFmt.h"	"TextFmt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl TextFmt.idl

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Release"

InputPath=.\TextFmt.idl

"TextFmt.tlb"	"TextFmt.h"	"TextFmt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl TextFmt.idl

!ELSEIF  "$(CFG)" == "TextFmt - Win32 Unicode Debug"

InputPath=.\TextFmt.idl

"TextFmt.tlb"	"TextFmt.h"	"TextFmt_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl TextFmt.idl

!ENDIF 

SOURCE=.\TextFmt.rc
DEP_RSC_TEXTFM=\
	".\TextFmt.tlb"\
	

"$(INTDIR)\TextFmt.res" : $(SOURCE) $(DEP_RSC_TEXTFM) "$(INTDIR)"\
 ".\TextFmt.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

