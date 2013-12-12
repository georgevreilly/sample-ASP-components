OBJECT = Asp2Htm

all:
    for %%i in ( $(OBJECT)) do \
        jvc %%i.java

release:
    for %%i in ( $(OBJECT)) do \
        jvc %%i.java

debug:
    for %%i in ( $(OBJECT)) do \
        jvc /g %%i.java

clean: delsrc
    - @del IISSample\*.class


delsrc:
    - @del $(OBJECT).ncb

cpyshared:
