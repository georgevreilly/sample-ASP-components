OBJECT = NxtLnk

all: ansi

ansi ansi-r: cpyshared
    - del ReleaseMinDependency\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Release MinDependency" all

ansi-d: cpyshared
    - del Debug\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Debug" all

unicode unicode-r: cpyshared
    - del ReleaseUMinDependency\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Release MinDependency" all

unicode-d: cpyshared
    - del DebugU\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Debug" all

clean: delsrc
    - @rmdir /s /q Debug ReleaseMinDependency DebugU ReleaseUMinDependency


delsrc:
    - @del dlldata.c $(OBJECT).h $(OBJECT)_i.c $(OBJECT)_p.c $(OBJECT).tlb

cpyshared:
    - copy ..\..\shared\inc\*.* .
    - copy ..\..\shared\source\*.* .
