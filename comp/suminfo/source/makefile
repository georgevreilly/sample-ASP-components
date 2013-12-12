OBJECT = SumInfo

SHARED_H = context.h
SHARED_S = context.cpp

all: ansi

ansi ansi-r:
    - del Release\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Release MinDependency" all

ansi-d:
    - del Debug\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Debug" all

unicode unicode-r:
    - del ReleaseU\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Release MinDependency" all

unicode-d:
    - del DebugU\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Debug" all

clean: delsrc
    - @rmdir /s /q Debug ReleaseMinDependency DebugU ReleaseUMinDependency


delsrc:
    - @del dlldata.c $(OBJECT).h $(OBJECT)_i.c $(OBJECT)_p.c $(OBJECT).tlb $(OBJECT).aps $(OBJECT).plg

cpyshared:
    @for %%i in ( $(SHARED_H) ) do \
        @copy ..\..\shared\inc\%%i .
    @for %%i in ( $(SHARED_S) ) do \
        @copy ..\..\shared\source\%%i .

delshared:
    @for %%i in ( $(SHARED_H) ) do \
        @del %%i
    @for %%i in ( $(SHARED_S) ) do \
        @del %%i

