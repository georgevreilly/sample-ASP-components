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

You must install the latest Java Virtual Machine (see below) on each
IIS server where you want to run the component.  You must also install
the ASP Java type library (see below) and run reg.bat (see below).


Usage
======

To use the Text Format component, simply call Server.CreateObject and
then call the method WrapTextFromFile to invoke the formatter.


File List
=========

File            Description
----            -----------

ReadMe.txt      this file
TextFmt.java    The Java source code for the text format component
TextFmt.mak     The Java makefile for the text format component
TextFmt.dsp     The Visual J++ 1.1 project file for the text format component
reg.bat         A batch file which should be used to register the component


..\..\Classes

TextFmt.class   Pre-compiled Java binary
Context.class	Support class Java binary
reg.bat	        installs and registers the pre-compiled .class file


Sample ASP
==========

See the Samples directory.  You must copy the samples to a virtual
directory (it need not be a virtual root) on an IIS Server before they
will work.


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
Microsoft OLE DB ActiveX Data Objects Library, and the Microsoft
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
