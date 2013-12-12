                      Text Format Component
                      =====================



Table of Contents
=================

    Overview
    Installation
    Usage
    File List
    Sample ASP
    Build Notes
    Support
    Change Notes


Overview
========

The Text Format Component is an Active Server Pages component that
can be used to format text files for use in <TEXTAREA> controls
on older browsers which do not wrap <TEXTAREA> controls for you.


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
	cd \InetPub\ASPSamp\Components\TextFmt\DLL\vb\i386
 3. Type:
	regsvr32 TextFmt.dll
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
    \InetPub\ASPSamp\Components\TextFmt\Samples to \InetPub\ASPSamp\Samples.
 2. In your browser, open http://localhost/ASPSamp/Samples/TextFmt.asp
You must copy the sample file to a virtual directory; if you attempt to
examine it with a browser in the TextFmt\Samples directory, ASP will not
execute the script.


Usage
======

To use the Text Format component, simply call Server.CreateObject and
then call the method WrapTextFromFile to invoke the formatter.


File List
=========

File            Description
----            -----------

ReadMe.txt      this file
TextFmt.cls     The Visual Basic 5.0 source code for the text format component
TextFmt.vbp     The Visual Basic 5.0 project file for the text format component


Sample ASP
==========

See the Samples directory.  You must copy the samples to a virtual
directory (it need not be a virtual root) on an IIS Server before they
will work.


Build Notes
===========

This sample requires Visual Basic 5.0.
Follow these steps to build a project:

1) Open the TextFmt.vbp file in Visual Basic.
2) From the File menu, select 'Make TextFmt.dll...' and provide a dll name.

This procedure will build and register the component.


Support
=======

This component is not officially supported by Microsoft Corporation.
Peer support is available on the Active Server Pages mailing list or on
the microsoft.public.inetserver.iis.activeserverpages newsgroup.

To subscribe to the Active Server Pages mailing list, send mail to
listserv@listserv.msn.com with

subscribe Denali [firstname lastname]

in the body of the message, and then follow the directions carefully.
(firstname and lastname are optional.)

You can reach the newsgroup through msnews.microsoft.com and other NNTP
servers.


Change Notes
============

Beta 1: February 1997
---------------------

First release.


Beta 2: March 1997
------------------

No changes.
