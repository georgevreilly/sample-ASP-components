/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Jun 27 12:30:38 1997
 */
/* Compiler settings for PgCnt.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __PgCnt_h__
#define __PgCnt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPgCntObj_FWD_DEFINED__
#define __IPgCntObj_FWD_DEFINED__
typedef interface IPgCntObj IPgCntObj;
#endif 	/* __IPgCntObj_FWD_DEFINED__ */


#ifndef __CPgCntObj_FWD_DEFINED__
#define __CPgCntObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class CPgCntObj CPgCntObj;
#else
typedef struct CPgCntObj CPgCntObj;
#endif /* __cplusplus */

#endif 	/* __CPgCntObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPgCntObj_INTERFACE_DEFINED__
#define __IPgCntObj_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPgCntObj
 * at Fri Jun 27 12:30:38 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IPgCntObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("4B0BAE82-567A-11D0-9607-444553540000")
    IPgCntObj : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnStartPage( 
            /* [in] */ IUnknown __RPC_FAR *piUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEndPage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hits( 
            /* [optional][in] */ BSTR bstrURL,
            /* [retval][out] */ LONG __RPC_FAR *plNumHits) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [optional][in] */ BSTR bstrURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPgCntObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPgCntObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPgCntObj __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPgCntObj __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPgCntObj __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPgCntObj __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPgCntObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPgCntObj __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnStartPage )( 
            IPgCntObj __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *piUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEndPage )( 
            IPgCntObj __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hits )( 
            IPgCntObj __RPC_FAR * This,
            /* [optional][in] */ BSTR bstrURL,
            /* [retval][out] */ LONG __RPC_FAR *plNumHits);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPgCntObj __RPC_FAR * This,
            /* [optional][in] */ BSTR bstrURL);
        
        END_INTERFACE
    } IPgCntObjVtbl;

    interface IPgCntObj
    {
        CONST_VTBL struct IPgCntObjVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPgCntObj_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPgCntObj_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPgCntObj_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPgCntObj_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPgCntObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPgCntObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPgCntObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPgCntObj_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)

#define IPgCntObj_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)

#define IPgCntObj_Hits(This,bstrURL,plNumHits)	\
    (This)->lpVtbl -> Hits(This,bstrURL,plNumHits)

#define IPgCntObj_Reset(This,bstrURL)	\
    (This)->lpVtbl -> Reset(This,bstrURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPgCntObj_OnStartPage_Proxy( 
    IPgCntObj __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *piUnk);


void __RPC_STUB IPgCntObj_OnStartPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPgCntObj_OnEndPage_Proxy( 
    IPgCntObj __RPC_FAR * This);


void __RPC_STUB IPgCntObj_OnEndPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPgCntObj_Hits_Proxy( 
    IPgCntObj __RPC_FAR * This,
    /* [optional][in] */ BSTR bstrURL,
    /* [retval][out] */ LONG __RPC_FAR *plNumHits);


void __RPC_STUB IPgCntObj_Hits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPgCntObj_Reset_Proxy( 
    IPgCntObj __RPC_FAR * This,
    /* [optional][in] */ BSTR bstrURL);


void __RPC_STUB IPgCntObj_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPgCntObj_INTERFACE_DEFINED__ */



#ifndef __PageCntTypeLibrary_LIBRARY_DEFINED__
#define __PageCntTypeLibrary_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: PageCntTypeLibrary
 * at Fri Jun 27 12:30:38 1997
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_PageCntTypeLibrary;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_CPgCntObj;

class DECLSPEC_UUID("4B0BAE86-567A-11D0-9607-444553540000")
CPgCntObj;
#endif
#endif /* __PageCntTypeLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
