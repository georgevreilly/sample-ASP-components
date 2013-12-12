// CTextFmt.cpp : Implementation of CTextFmtApp and DLL registration.

#include "stdafx.h"
#include "TextFmt.h"
#include "CTextFmt.h"
#include <algorithm>
#include <functional>

#if _MSC_VER>=1100
using namespace std;
#endif

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CTextFmt::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_ITextFmt,
    };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

//------------------------------------------------------------------------
//                   ABOUT
//------------------------------------------------------------------------

STDMETHODIMP CTextFmt::About(BSTR *pstrAbout)
    {
    *pstrAbout = SysAllocString(
        L"<BR><B><FONT SIZE=4 FACE=Arial>"
        L"Text Formatter Server Component, Version 2.0<BR></FONT></B>"
        L"<FONT SIZE=3 FACE=Arial>C++ edition<BR></FONT>");
    return S_OK;
    }



//------------------------------------------------------------------------
//                   WriteLn
//------------------------------------------------------------------------

void CTextFmt::WriteLn(CContext& rcxt, const char *szText)
    {
    if (*szText != '\0')            // don't bother doing this for blank lines
        {
        // Convert sz to Unicode, and store in strText.
        CComBSTR strText = szText,
                 strEncoded;

        rcxt.Server()->HTMLEncode(strText, &strEncoded);
        rcxt.Response()->Write(CComVariant(strEncoded));
        }

    rcxt.Response()->Write(CComVariant(L"\r\n"));
    }



//------------------------------------------------------------------------
//                   WrapTextFromFile
//------------------------------------------------------------------------

HRESULT CTextFmt::WrapTextFromFile(BSTR strFile, int cchColumnWidth)
    {
    // These variables **must** be declared here, to avoid C++ errors
    
    HANDLE hInputFile;      // open file handle of strFile
    HANDLE hFileMap;        // handle for file mapping
    void *  pvData;         // virtual address of mapped file contents
    USES_CONVERSION;        // for OLE2T

	// get the current object context
	CContext cxt;
	if ( FAILED( cxt.Init( CContext::get_Server | CContext::get_Response ) ) )
	{
		return E_FAIL;
	}

    // Open the file for reading -- raise an Exception if the file
    // cannot be read.
    hInputFile = CreateFile(
                            OLE2T(strFile), 
                            GENERIC_READ,
                            0,          // Open for exclusive access
                            NULL,       // Security descriptor
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING,
                            NULL        // File handle with attributes to copy
                            );

    if (hInputFile == INVALID_HANDLE_VALUE)
        goto LError;

    hFileMap = CreateFileMapping(
                                hInputFile,
                                NULL,       // Security attributes
                                PAGE_READONLY,
                                0,          // ) Set to size of file
                                0,          // ) being mapped
                                NULL        // Unnamed map
                                );

    if (hFileMap == INVALID_HANDLE_VALUE)
        {
        CloseHandle(hInputFile);
        goto LError;
        }

    pvData = MapViewOfFile(
                        hFileMap,
                        FILE_MAP_READ,
                        0, 0,           // Beginning offset to view
                        0               // view entire file
                        );

    if (pvData == NULL)
        {
        CloseHandle(hFileMap);
        CloseHandle(hInputFile);
        goto LError;
        }

		// we go down one level in scope so the above goto's don't interfere
		// with initialization of variables below
		{
		/* pchStart & pchEnd can (and do) serve as STL iterators
		 */
		char *pchStart = static_cast<char *>(pvData);
		char *pchEnd = pchStart + GetFileSize(hInputFile, NULL);

		// Create default buffer which is the size of the width
		// of the text area + some padding for overflow words
		char *szOutputLine = static_cast<char *>(_alloca(cchColumnWidth + 35));
		szOutputLine[0] = '\0';

		do
			{
			// locate the beginning of the next word.
			char *pchWordBegin = find_if(pchStart, pchEnd, not1(ptr_fun(isspace)));

			// Count the number of newlines processed.  If a
			// sequence of "n" newlines are found, then output
			// "n-1" blank lines.  (The first newline will be
			// the closure of the last non-empty line of text.)
			int cNewLines = count(pchStart, pchWordBegin, '\n') - 1;
			while (cNewLines-- > 0)
				{
				if (szOutputLine[0] != '\0')
					{
					WriteLn(cxt, szOutputLine);  // send the remainder of the buffer
					szOutputLine[0] = '\0';
					}

				WriteLn(cxt, "");
				}

			// pchWordBegin points to the beginning of the word.
			// Find the end of the word, which is going to
			// either be the occurrence of the first whitespace,
			// or the end of string.
			char *pchWordEnd = find_if(pchWordBegin, pchEnd, isspace);
			int   cchWord = pchWordEnd - pchWordBegin;

			// see if the word will fit
			if (strlen(szOutputLine) + cchWord > cchColumnWidth)
				{
				// There is no room on this line, so flush strOutputLine
				WriteLn(cxt, szOutputLine);
				szOutputLine[0] = '\0';
				}

			// append the word to szOutputLine, and a blank space.
			strncat(szOutputLine, pchWordBegin, cchWord);
			strcat(szOutputLine, " ");

			// Reset pchStart to the end of the word to restart
			pchStart = pchWordEnd;
			} while (pchStart < pchEnd);

		// If we got here, we ran into EOF.  However, there still may be
		// some text in strOutputLine. If there is, then flush it.
		if (szOutputLine[0] != '\0')
			WriteLn(cxt, szOutputLine);

		UnmapViewOfFile(pvData);
		CloseHandle(hFileMap);
		CloseHandle(hInputFile);
		}
    return S_OK;

LError:
    TCHAR szError[256];
    wsprintf(szError, _T("Cannot open \"%ls\".  Error Code %#x"),
             strFile, GetLastError());
    Error(szError);
    return DISP_E_EXCEPTION;
    }
