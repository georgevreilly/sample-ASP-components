/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Aug 04 14:26:10 1997
 */
/* Compiler settings for ContRot.idl:
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

const IID IID_IContentRotator = {0xE7EFF394,0x2E8A,0x11D0,{0xB6,0x9A,0x00,0xC0,0xF0,0x0A,0xE3,0x5A}};


const IID LIBID_ContRotTypeLibrary = {0xE7EFF392,0x2E8A,0x11D0,{0xB6,0x9A,0x00,0xC0,0xF0,0x0A,0xE3,0x5A}};


const CLSID CLSID_CContentRotator = {0xE7EFF398,0x2E8A,0x11D0,{0xB6,0x9A,0x00,0xC0,0xF0,0x0A,0xE3,0x5A}};


#ifdef __cplusplus
}
#endif

