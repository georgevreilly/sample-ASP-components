                      Document Summary Information Component
                      ======================================


Table of Contents
=================

    Overview
    Installation
    File List
    Sample ASP
    Build Notes
    Support
    Data Format
    Discussion of the Design
    Change Notes


Overview
========

The Summary Information Component is an Active Server Pages component that
displays the properties of a document (or directory of documents)


Installation
============

In order to use this component you must register it.  This will allow Active
Server Pages (ASP) Scripting Languages and other languages to make use of
the component.  ASP uses either the Server.CreateObject("ObjectName") syntax
or the <object id="myName" progid="ObjectName" runat="server"> syntax to
gain access to an object.  New objects can be made ready for use by
installing a new component.  Note: One component may contain more than one
object definition.

The following directions are to help you register the component for use:
 1. Use the Start menu, Programs option to start a Command Prompt
 2. Type the following:
	cd \InetPub\ASPSamp\Components\SumInfo\DLL\i386
 3. Type:
	regsvr32 SumInfo.dll
Note: you must register the component on each IIS server where you intend
to use it.

If you have trouble registering components, you may be using the wrong
version of RegSvr32.exe.  Please use the version installed by default in
the directory <InstallDir>\ASP\Cmpnts.  On Windows NT, the default
installation directory is \winnt\System32\Inetsrv.  On Windows 95, it is
\Program Files\WebSvr\System.

(If you rebuild the source code, the makefile will automatically reregister
the component for you.)

The following directions are to help you test the registered component:
 1. Use the Windows Explorer to copy all of the Sample files from 
    \InetPub\ASPSamp\Components\SumInfo\Samples to \InetPub\ASPSamp\Samples.

 2. In your browser, open http://localhost/ASPSamp/Samples/SumInfo.asp
You must copy the sample files to a virtual directory; if you attempt to
examine them with a browser in the SumInfo\Samples directory, ASP will not
execute the script.


File List
=========

File             Description
----             -----------

.\Source

 ASPSum.idl
 SumBase.cpp     ) Base class for both CSumInfo and CSumInfos
 SumBase.h	
 SumEnum.cpp     ) An enumeration interface for CSumInfos
 SumEnum.h
 SumInfo.cpp     ) Gathers and displays info about a document
 SumInfo.h
 SumInfos.cpp    ) a collection of SumInfo objects
 SumInfos.h
 ASPSum.cpp      )
 ASPSum.def      )
 ASPSum.dsp      )
 ASPSum.rc  	 )
 ASPSum.def      } Generated by the ATL COM AppWizard
 Resource.h      )
 StdAfx.cpp      )
 StdAfx.h        )

 context.cpp	) shared support classes
 context.h	)

.\Samples

 SumInfo.asp     ) an ASP for testing the summary info component

 .\Samples\docs

 ASPSumInfo.doc  ) a test document

Samples
=======

You will need to copy the sample files to a virtual directory on an
IIS Server.  The sample will display the properties of in document that lives in

Build Notes
===========

This sample requires Microsoft Visual C++ 5.0 or newer and ATL version
2.1 installed with it.

If you get an error about "don't know how to make asptlb.h", you will
need to copy <InstallDir>\ASP\Cmpnts\AspTlb.h to your include
directory.

Finally you must have the lastest version of MS Transaction Server
installed (part of IIS 4.0).  Add the include path and library path
of MTX before any system directories under Tools:Options....  So your
include path might look like this: c:\program files\mts\include;
c:program files\devstudio\vc\include;... (depending on where you have
installed MTX).  If you intend to build from the command line, you
must edit vcvars32.bat accordingly as well.

You can build this component with nmake at the command line.  Read
Makefile for more details.  You can also build it in Microsoft
Developer Studio, using the SumInfo.dsp project.

The component can be built as ANSI or Unicode.  If you intend to
run it on Windows 95, build it as ANSI.  If you build it as a
Unicode DLL, all data files will need to be in Unicode format.


Support
=======

This component is not officially supported by Microsoft Corporation.
Peer support is available on the Active Server Pages mailing list or on
the microsoft.public.inetserver.iis.activeserverpages newsgroup.

To subscribe to the Active Server Pages mailing list, send mail to
listserv@listserv.msn.com with

subscribe ActiveServerPages [firstname lastname]

in the body of the message, and then follow the directions carefully.
(firstname and lastname are optional.)

You can reach the newsgroup through msnews.microsoft.com and other NNTP
servers.


Data Format
===========


Discussion of the Design
========================

Change Notes
============

Version 1.0 Beta 1: May 1997
----------------------------


Version 2.0 Beta 2: September 1997
----------------------------------

* Updated for IIS4.0
* Using IObjectContext instead of IScriptingContext.
