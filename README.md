Sample ASP and ISAPI Components
===============================

From October 1996 to May 1997, I wrote a number of sample components
for the then-new [Active Server Pages](http://en.wikipedia.org/wiki/Active_Server_Pages)
(Classic ASP).
I worked for MicroCrafts, a consulting company in Redmond, WA;
the samples were written for Microsoft's
[Internet Information Server](http://en.wikipedia.org/wiki/Internet_Information_Services)
(IIS) team.
Most of the components used Microsoft's new
[Active Template Library](http://en.wikipedia.org/wiki/Active_Template_Library) (ATL),
a C++ library for COM.

This work had two important consequences for me:
Microsoft recruited me to join the IIS development team
to work on improving ASP performance for IIS 3,
and Wrox Press invited me to write
[Beginning ATL COM Programming](http://www.amazon.com/gp/product/1861000111/ref=as_li_qf_sp_asin_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=1861000111&linkCode=as2&tag=georgvreill-20)
I was originally supposed to be the sole author of the book,
but I was a slow writer and I was caught up in the IIS 4 deathmarch,
so Wrox brought in three more co-authors to complete the book.
A fourth co-author was brought in for the second edition,
[Beginning ATL 3 COM Programming](http://www.amazon.com/gp/product/1861001207/ref=as_li_qf_sp_asin_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=1861001207&linkCode=as2&tag=georgvreill-20).
As for IIS, I spent seven years on the team,
where in addition to leading the performance team,
I also worked on the
[http.sys](http://www.microsoft.com/technet/prodtechnol/WindowsServer2003/Library/IIS/a2a45c42-38bc-464c-a097-d7a202092a54.mspx?mfr=true)
kernel driver that was released in Windows Server 2003 (IIS 6).

For many years, these components could be found at
[http://www.georgevreilly.com/sample-ASP-components.html](http://www.georgevreilly.com/sample-ASP-components.html).
I'm making them available now at Github.

/George V. Reilly, 2013/12/12


Original README
===============

(lightly edited)

Cookie Munger
-------------

2002/09/14. I have added the Cookie Munger sample ISAPI filter as a separate file.
It is no longer included in recent copies of the Platform SDK.

Sample ASP Components
---------------------

In the Spring of 1997, I wrote an article on
[Developing Active Server Components with ATL](http://msdn.microsoft.com/workshop/server/asp/comp.asp).
At the end, I make reference to several sample components
that supposedly live at the [Windows Download Site](http://www.microsoft.com/windows/downloads/default.asp).
Most of those components were pulled from the site many months ago,
because they were marked as Beta components.
Actually, no problems had been reported with them in a very long time, that I know of.
I've been trying, without success, to get them reposted,
since I get occasional requests for them.
I've gotten sick of the delays in the bureaucracy,
so I'm posting them here on my personal website.

Microsoft doesn't support any of these components, and neither do I.
If you do find problems with the components, feel free to tell me about them;
however, I don't guarantee to do anything about those problems.

The components:

* Ad Rotator.
* ASP to HTML Converter.
* Browser Capabilities.
* Content Rotator.
* Simple Developer Samples in ATL, MFC, Java, VB4, and VB5.
* HTML Table.
* Next Link.
* Page Counter.
* Permission Checker.
* Registry.
* Summary Info.
* Text Formatter.
* Tracer.
* Weather.

Someday soon I will update the article to deal with IIS 4.0 and beyond.
In the meantime, you could do worse than read

* [Beginning ATL 3 COM Programming](http://www.amazon.com/gp/product/1861001207/ref=as_li_qf_sp_asin_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=1861001207&linkCode=as2&tag=georgvreill-20),
  Grimes, Stockton, Templeman, Watson, Reilly; Wrox Press; 1999.
* [Developing ASP Components](http://www.amazon.com/gp/product/1565927508/ref=as_li_qf_sp_asin_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=1565927508&linkCode=as2&tag=georgvreill-20),
  Shelley Powers, O'Reilly & Associates, 1999.
* [Programming Distributed Applications with COM+ and Microsoft Visual Basic](http://www.amazon.com/gp/product/073561010X/ref=as_li_qf_sp_asin_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=073561010X&linkCode=as2&tag=georgvreill-20),
  Ted Pattison, Microsoft Press, 2000.

George Reilly, 3rd June 1999.
