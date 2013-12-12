			 HTML Table Component
			 ====================


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

The HTML Table Component is an Active Server Pages component that
converts the data stored in an ADO Recordset into an HTML Table.


Installation
============

You must install the latest Java Virtual Machine (see below) on
each IIS server where you want to run the component.  You must
also install the ASP and ADO Java type libraries (see below) and
run reg.bat (see below).

You must set up a new data source name for the sample to look at.
If you have the NorthWind sample database (available with Access,
Visual Basic, etc), go to Control Panels | ODBC | File DSN.
Select Add and Microsoft Access Driver (*.mdb).  Name the DSN
NWind.dsn.  After that point it to the nwind.mdb (Configure |
Select).

File List
=========

File             Description
----             -----------

.\Source

 htmlTbl.java    the source code for the HTML Table component
 Makefile        a makefile that can be used with nmake
 htmlTbl.mak     the Developer Studio makefile
 htmlTbl.dsp     the Developer Studio project file
 reg.bat	 installs and registers the compiled .class file

.\Samples

 htmlTbl.asp     Demonstrates the use of the HTML Table object

.\Classes

 htmlTbl.class   Pre-compiled Java binary
 Context.class	 support class Java binary
 reg.bat	 installs and registers the pre-compiled .class file


Samples
=======

You must copy the sample to a virtual directory (it need not be a
virtual root) on an IIS Server before it will work.


Build Notes
===========

Please download the latest Java VM from http://www.microsoft.com/java
You should get the latest Java SDK from there too.  You will need to
install the new Java VM on each IIS server where you run the component.

You must install the latest version of IIS4.0.  As part of IIS4.0, you
must install Microsoft Transaction Server.

To build this, you must first teach the Java compiler about the ASP, ADO
and MTS type libraries.  Use Tools|Java Type Library Wizard and
convert the Microsoft Active Server Pages Object Library, the
Microsoft ActiveX Data Objects Library, and the Microsoft
Transaction Server Type Library respectively.  You only need to do this
once.

To compile the component, run "nmake".  You must then register it by
using reg.bat.  Note that the call to javareg in reg.bat is needed
only once.


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

Version 1.0 Beta 1: February 1997
---------------------------------

First release.


Version 1.0 Beta 2: March 1997
------------------------------

* Better comments and minor style tweaks


Version 2.0 Beta 3: September 1997
----------------------------------

* Updated for IIS4.0
* Using IObjectContext instead of IScriptingContext.
