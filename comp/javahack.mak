all:
    copy htmltbl\source\htmltbl.jav			    htmlTbl\Source\htmlTbl.java
    copy htmltbl\classes\htmltbl.cla            htmlTbl\Classes\htmlTbl.class
    copy textfmt\source\java\textfmt.jav        TextFmt\Source\Java\TextFmt.java
    copy textfmt\classes\textfmt.cla            TextFmt\Classes\TextFmt.class
    copy devsmpl\JavaSmpl\Source\javasmpl.jav   devsmpl\JavaSmpl\Source\JavaSmpl.java
    copy devsmpl\JavaPwr\Source\javapwr.jav     devsmpl\JavaPwr\Source\JavaPwr.java
	copy Asp2Htm\source\test.jav                Asp2Htm\source\test.java
	copy Asp2Htm\source\Asp2Htm.jav             Asp2Htm\source\Asp2Htm.java
	copy Asp2Htm\classes\Asp2Htm.cla	    	Asp2Htm\classes\Asp2Htm.class
    $(MAKE) -$(MAKEFLAGS) -f Makefile all

clean:
    del htmlTbl\Source\htmlTbl.java
    del htmlTbl\Classes\htmlTbl.class
    del TextFmt\Source\Java\TextFmt.java
    del TextFmt\Classes\TextFmt.class
    del devsmpl\JavaSmpl\Source\JavaSmpl.java
    del devsmpl\JavaPwr\Source\JavaPwr.java
	del Asp2Htm\source\test.java
	del Asp2Htm\source\Asp2Htm.java
	del Asp2Htm\classes\Asp2Htm.class
    $(MAKE) -$(MAKEFLAGS) -f Makefile clean
