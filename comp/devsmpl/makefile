
# I need to get the makefiles working for VB samples as well - Murali 1/17/97

#===============================================================
!IF "$(PROCESSOR_ARCHITECTURE)"=="x86"
#===============================================================

SAMPLES= CATLSmpl CATLPwr JavaSmpl JavaPwr

#===============================================================
!ELSE
#===============================================================

SAMPLES= 

#===============================================================
!ENDIF
#===============================================================


all:
    for %%i in ($(SAMPLES) ) do \
        cd %%i\Source & $(MAKE) cpyshared & $(MAKE) -$(MAKEFLAGS) all & cd ..\..

clean:
    for %%i in ($(SAMPLES)) do \
        cd %%i\Source & $(MAKE) -$(MAKEFLAGS) clean & cd ..\..
