
#===============================================================
!IF "$(PROCESSOR_ARCHITECTURE)"=="x86"
#===============================================================

CANDY = Registry ContRot PageCnt PermChk HtmlTbl SumInfo Asp2Htm Tracer
TEXTFMT_CANDY = TextFmt
SAMPLE_DIRS = devsmpl

#===============================================================
!ELSE
#===============================================================

# only registry need to be built for non-x86 platforms
CANDY = Registry
TEXTFMT_CANDY = 

#===============================================================
!ENDIF
#===============================================================

all:
	for %%i in ( $(SAMPLE_DIRS)) do \
		cd %%i & $(MAKE) -$(MAKEFLAGS) all & cd ..
    for %%i in ( $(CANDY)) do \
        cd %%i\Source & $(MAKE) cpyshared & $(MAKE) -$(MAKEFLAGS) all & cd ..\..
# TextFmt component has special paths - release it separately
    for %%i in ( $(TEXTFMT_CANDY)) do \
	for %%j in (c java) do \
		cd %%i\Source\%%j & $(MAKE) cpyshared & $(MAKE) -$(MAKEFLAGS) all & cd ..\..\..

clean:
	for %%i in ( $(SAMPLE_DIRS)) do \
		cd %%i & $(MAKE) -$(MAKEFLAGS) clean & cd ..
    for %%i in ( $(CANDY)) do \
        cd %%i\Source & $(MAKE) -$(MAKEFLAGS) clean & cd ..\..
    for %%i in ( $(TEXTFMT_CANDY)) do \
	for %%j in (c java) do \
	    cd %%i\Source\%%j & $(MAKE) -$(MAKEFLAGS) clean & cd ..\..\..
