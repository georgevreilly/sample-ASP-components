/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Sep 15 16:24:18 1997
 */
/* Compiler settings for Reg.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IRegObj = {0x9C3558B4,0x4175,0x11D0,{0x92,0x6E,0x00,0xAA,0x00,0xB9,0x1D,0x12}};


const IID IID_IRegSubKeysCollection = {0x12709b00,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}};


const IID IID_IRegValue = {0x12709b01,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}};


const IID IID_IRegValuesCollection = {0x12709b02,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}};


const IID LIBID_RegistryAccess = {0x9C3558B2,0x4175,0x11D0,{0x92,0x6E,0x00,0xAA,0x00,0xB9,0x1D,0x12}};


const CLSID CLSID_CRegObj = {0x9C3558B8,0x4175,0x11D0,{0x92,0x6E,0x00,0xAA,0x00,0xB9,0x1D,0x12}};


#ifdef __cplusplus
}
#endif

