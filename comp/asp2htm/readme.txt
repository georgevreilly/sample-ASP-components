               Asp2Htm Component
               =================


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

The Asp2Htm Component is an Active Server Pages component that
connects to a given URL and downloads it.  One possible use of
this is to translate your own ASP pages into HTML pages (to
save on the runtime costs of ASP)

Installation
============

You must install the latest Java Virtual Machine (see below) on
each IIS server where you want to run the component.  You must
also have the windows scripting host to execute the example
script provided.


File List
=========

File             Description
----             -----------

.\Source

 Asp2Htm.java   the source code for the Asp2Htm component
 Makefile		a makefile that can be used with nmake
 Asp2Htm.dsp    the Developer Studio project file

.\Samples

 Asp2Htm.asp	A ASP page for using Asp2Htm

.\Classes

 Asp2Htm.class  Pre-compiled Java binary
 reg.bat        a batch file to register and copy the class to the
                correct folder


Build Notes
===========

Please download the latest Java VM from http://www.microsoft.com/java
You should get the latest Java SDK from there too.  You will need to
install the new Java VM on each IIS server where you run the component.

To build this, you must first teach the Java compiler about the
ASP type library and the Microsoft Transaction Server Type Library.
Use Tools|Java Type Library Wizard and convert them.
You only need to do this once.

To compile the component, run "nmake", then run reg.bat to register
and move the class file.


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

Version 1.0 Beta 1: May 1997
---------------------
First release.


Version 2.0 Beta 2: September 1997
-------------------------
first release for IIS 4.0

