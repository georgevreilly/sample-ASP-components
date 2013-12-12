OBJECT = JavaSmpl

all: javahack
    jvc $(OBJECT).java

release:
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
        CFG="$(OBJECT) - Java Virtual Machine Release" \
        .\$(OBJECT).class

debug:
    $(MAKE) -$(MAKEFLAGS) -f $(OBJECT).mak \
        CFG="$(OBJECT) - Java Virtual Machine Debug" \
        .\$(OBJECT).class

clean: delsrc
    - @del *.class


delsrc:
    - @del $(OBJECT).ncb

cpyshared:
javahack:
    - @ren javasmpl.java temp
    - @ren temp JavaSmpl.java
