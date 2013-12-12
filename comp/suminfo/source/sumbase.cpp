// SumInfoBase.cpp: implementation of the CSumInfoBase class.
//
// Copyright (C) 1996 Microsoft Corporation
// All rights reserved.
//
// ckindel  4/3/97 Wrote it.
//
//
// This class provides some utility functions that are shared between
// CSumInfo and CSumInfos.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SumInfo.h"
#include "SumBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


typedef struct _ulargeint
   {
      union
      {
         struct
         {
            DWORD dw;
            DWORD dwh;
         };
         struct
         {
            WORD w0;
            WORD w1;
            WORD w2;
            WORD w3;

         };
      };
   } ULInt;


//
// Function: ULIntDivide
//
// Purpose: To divide a ULInt with a USHORT and
//          stick the result in the 1st param
//

VOID ULIntDivide(ULInt FAR *lpULInt, USHORT div)
{
   ULInt ulOut, ulIn, r;

   ulIn = *lpULInt;

   ulOut.w3 = ulIn.w3/div;
   r.w3     = ulIn.w3%div;

   ulOut.w2 = (ulIn.w2 + r.w3*65536)/div;
   r.w2     = (ulIn.w2 + r.w3*65536)%div;

   ulOut.w1 = (ulIn.w1 + r.w2*65536)/div;
   r.w1     = (ulIn.w1 + r.w2*65536)%div;

   ulOut.w0 = (ulIn.w0 + r.w1*65536)/div;
   r.w0     = (ulIn.w0 + r.w1*65536)%div;


   *lpULInt = ulOut;
}

// Convert a number in units of 100ns into number of minutes.
//
// Parameters:
//
//     lptime - on input: contains a number expressed in 100ns.
//              on output: contains the equivalent number of minutes.
//
// Return value:
//
//     None.
//
VOID Convert100nsToMin(LPFILETIME lpTime)
{
   ULInt ul;

   ul.dw = lpTime->dwLowDateTime;
   ul.dwh = lpTime->dwHighDateTime;
   ULIntDivide(&ul, 1000);    // These two calls converts to
   ULIntDivide(&ul, 10000);   // seconds
   ULIntDivide(&ul, 60); // Convert to minutes
   lpTime->dwLowDateTime = ul.dw;
   lpTime->dwHighDateTime = ul.dwh;
}

// Convert a PROPVARIANT to a VARIANT
//
void CSumInfoBase::PropVarToVar(VARIANT * pVarOut, PROPVARIANT * pPropVarIn, BOOL fEditTime /*= FALSE*/)
{
    USES_CONVERSION;

    switch (pPropVarIn->vt)
    {
        case VT_EMPTY:
            if (m_lStyle == CSumInfoBase::STYLE_DEBUG)
            {
                pVarOut->vt = VT_BSTR;
                pVarOut->bstrVal = SysAllocString(L"!!!EMPTY!!!");
            }
            else
                pVarOut->vt = VT_EMPTY;
        break;

        case VT_LPSTR:
            pVarOut->vt = VT_BSTR;
            pVarOut->bstrVal = SysAllocString(A2W(pPropVarIn->pszVal));
        break;

        case VT_FILETIME:
        {
            // VariantChangeType cannot coerce VT_FILETIMEs. Use the
            // NLS API to format the date/time
            //
            FILETIME filetime;
            SYSTEMTIME systemtime;
            WCHAR wsz[128];

            // Convert to local time
            // TODO: Figure out if we can get the real user's timezone
            // (via the HTTP request).
            FileTimeToLocalFileTime(&pPropVarIn->filetime, &filetime);

            if (!fEditTime)
            {
                FileTimeToSystemTime(&filetime, &systemtime);
                if (systemtime.wYear <= 1700) 
                    FileTimeToSystemTime(&pPropVarIn->filetime, &systemtime);

                if (GetDateFormatW(LOCALE_USER_DEFAULT,
                            DATE_LONGDATE, 
                            &systemtime, 
                            NULL, 
                            wsz, 
                            sizeof(wsz)/sizeof(wsz[0])))
                {
                    WCHAR wsz2[128];
                    if (GetTimeFormatW(LOCALE_USER_DEFAULT,
                                0, 
                                &systemtime, 
                                NULL, 
                                wsz2, 
                                sizeof(wsz2)/sizeof(wsz2[0])))
                    {
                        lstrcatW(wsz, L", ");
                        lstrcatW(wsz, wsz2);
                    }
                }
                else
                    *wsz = '\0';

            }
            else
            {
                // If GetDateFormat fails it means we are dealing
                // with PIDSI_EDITTIME which is special.
                //
                filetime = pPropVarIn->filetime;
                Convert100nsToMin(&filetime);
              
                ULONG ul = max(1,filetime.dwLowDateTime);
                wsprintfW(wsz, L"%lu Minutes", ul);
            }
            pVarOut->vt = VT_BSTR;
            pVarOut->bstrVal = SysAllocString(wsz);
        }
        break;

        default:
        {
            if (!SUCCEEDED(VariantChangeType(pVarOut, (VARIANT*)pPropVarIn, 0, pPropVarIn->vt)))
            {
                pVarOut->vt = VT_BSTR;
                pVarOut->bstrVal = SysAllocString(L"!!!Variant coersion failed!!!!");
            }
        }
    }
}

// Helper to write a string to the response object.
//
void CSumInfoBase::WriteResponseString(
	CContext&	rcxt,
	WCHAR*		wsz)
{
    if (wsz == NULL)
        return ;

    VARIANT vtMessage;
    VariantInit(&vtMessage);
    V_VT(&vtMessage) = VT_BSTR;
    V_BSTR(&vtMessage) = SysAllocString(wsz);
    if (rcxt.Response())
    {
        rcxt.Response()->Write(vtMessage);
        if (m_lStyle == STYLE_DEBUG)
            rcxt.Response()->Flush();
    }
    VariantClear(&vtMessage);
}

// Helper to write a (char*) string to the response object.
//
void CSumInfoBase::WriteResponseString(
	CContext&	rcxt,
	char*		sz)
{
    USES_CONVERSION;
    WriteResponseString(rcxt, A2W(sz));
}

// Helper to write a PROPVARIANT to the response object.
//
void CSumInfoBase::WriteResponsePropVar(
	CContext&		rcxt,
	PROPVARIANT*	pPropVar,
	BOOL			fEditTime /*= FALSE*/)
{
    VARIANT v;
    VariantInit(&v);
    PropVarToVar(&v, pPropVar, fEditTime);

	if ( rcxt.Response() )
	{
		if (SUCCEEDED(VariantChangeType(&v, &v, 0, VT_BSTR)))
			rcxt.Response()->Write(v);
		else
			WriteResponseString(rcxt, L"!!!Variant coersion failed!!!!");

		VariantClear(&v);
	}
}

