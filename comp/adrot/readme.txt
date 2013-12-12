               AdRotator Component
               ==============


Table of Contents
=================

    Overview
    Installation
    File List
    Sample ASP
    Build Notes
    Support
    Change Notes


Overview
========

The AdRotator Component is an Active Server Pages component that
will randomly change ads shown on a page each time it is viewed.

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
	cd \InetPub\ASPSamp\Components\AdRot\DLL\i386
 3. Type:
	regsvr32 AdRot.dll
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
 1. Use the Windows Explorer to copy all of the Sample files except
    global.asa from \InetPub\ASPSamp\Components\AdRot\Samples
    to \InetPub\ASPSamp\Samples.
 2. Copy global.asa to \InetPub\ASPSamp.  (Note: global.asa *must* be in a
    virtual root directory; the other files need not be.)
 3. In your browser, open http://localhost/ASPSamp/Components/AdRot/Samples/AdRot.asp
You must copy the sample files to a virtual directory; if you attempt to
examine them with a browser in the ContRot\Samples directory, ASP will not
execute the script.



File List
=========

File             Description
----             -----------

.\Source
 AdDesc.h
 AdDesc.cpp
 AdFile.h
 AdFile.cpp
 Resource.h
 RotObj.h
 RotObj.cpp
 StdAfx.h
 StdAfx.cpp
 AdRot.cpp
 AdRot.idl
 AdRot.rgs
 AdRot.dsp
 AdRot.rc
 AdRot.mak
 Makefile		a makefile that can be used with nmake
 
.\Samples

 AdRot.asp      Demonstrates the use of the AdRotator object

.\dll\i386
 AdRot.dll		The AdRototar binary

Samples
=======

You must copy the sample to a virtual directory (it need not be a
virtual root) on an IIS Server before it will work.


Build Notes
===========

To compile the component you will need the latest version of Visual C++ installed.
Running "nmake" from the command-line will build and register the component for
you.  


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


Change Notes
============

Beta 1: May 1997
---------------------

First release.
