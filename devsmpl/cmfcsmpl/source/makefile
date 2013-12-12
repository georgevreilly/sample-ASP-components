OBJECT = CMFCSmpl

all: ansi

ansi ansi-r:
    - del Release\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Release" \
	all

ansi-d:
    - del Debug\regsvr32.trg
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
	CFG="$(OBJECT) - Win32 Debug" \
	all

clean: delsrc
    - @rmdir /s /q Debug Release


delsrc:
    - @del $(OBJECT).clw $(OBJECT).ncb

