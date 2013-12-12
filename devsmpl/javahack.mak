all:
    copy JavaSmpl\Source\javasmpl.jav  JavaSmpl\Source\JavaSmpl.java
    copy JavaPwr\Source\javapwr.jav    JavaPwr\Source\JavaPwr.java
    $(MAKE) -$(MAKEFLAGS) -f Makefile all

clean:
    del JavaSmpl\Source\JavaSmpl.java
    del JavaPwr\Source\JavaPwr.java
    $(MAKE) -$(MAKEFLAGS) -f Makefile clean
