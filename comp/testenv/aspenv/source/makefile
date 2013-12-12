OBJECT = AspEnv
SHARED_H = myvector.h mystring.h mydebug.h monitor.h lock.h refcount.h refptr.h rdwrt.h
SHARED_S = mystring.cpp mem.cpp monitor.cpp rdwrt.cpp

all: ansi

ansi ansi-r:
    - del ReleaseMinDependency\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Release MinDependency" \
	$(OBJECT).tlb all

ansi-d:
    - del Debug\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Debug" \
	$(OBJECT).tlb all

unicode unicode-r:
    - del ReleaseU\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Release MinDependency" \
	$(OBJECT).tlb all

unicode-d:
    - del DebugU\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Unicode Debug" \
	$(OBJECT).tlb all

clean:
    - @rmdir /s /q Debug ReleaseMinDependency DebugU ReleaseUDependency
    - @del $(OBJECT).h $(OBJECT)_i.c $(OBJECT)_p.c $(OBJECT).aps $(OBJECT).tlb $(OBJECT).plg

cpyshared:
    @for %%i in ( $(SHARED_H) ) do \
        @copy ..\..\..\shared\inc\%%i .
    @for %%i in ( $(SHARED_S) ) do \
        @copy ..\..\..\shared\source\%%i .

delshared:
    @for %%i in ( $(SHARED_H) ) do \
        @del %%i
    @for %%i in ( $(SHARED_S) ) do \
        @del %%i

