
Regps.dll: dlldata.obj Reg_p.obj Reg_i.obj
	link /dll /out:Regps.dll /def:Regps.def /entry:DllMain dlldata.obj Reg_p.obj Reg_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del Regps.dll
	@del Regps.lib
	@del Regps.exp
	@del dlldata.obj
	@del Reg_p.obj
	@del Reg_i.obj
