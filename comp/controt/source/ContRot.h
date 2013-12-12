/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Aug 04 14:26:10 1997
 */
/* Compiler settings for ContRot.idl:
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

#ifndef __ContRot_h__
#define __ContRot_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IContentRotator_FWD_DEFINED__
#define __IContentRotator_FWD_DEFINED__
typedef interface IContentRotator IContentRotator;
#endif 	/* __IContentRotator_FWD_DEFINED__ */


#ifndef __CContentRotator_FWD_DEFINED__
#define __CContentRotator_FWD_DEFINED__

#ifdef __cplusplus
typedef class CContentRotator CContentRotator;
#else
typedef struct CContentRotator CContentRotator;
#endif /* __cplusplus */

#endif 	/* __CContentRotator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IContentRotator_INTERFACE_DEFINED__
#define __IContentRotator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IContentRotator
 * at Mon Aug 04 14:26:10 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IContentRotator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("E7EFF394-2E8A-11D0-B69A-00C0F00AE35A")
    IContentRotator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseContent( 
            /* [in] */ BSTR bstrDataFile,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllContent( 
            /* [in] */ BSTR bstrDataFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContentRotatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IContentRotator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IContentRotator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IContentRotator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChooseContent )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ BSTR bstrDataFile,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllContent )( 
            IContentRotator __RPC_FAR * This,
            /* [in] */ BSTR bstrDataFile);
        
        END_INTERFACE
    } IContentRotatorVtbl;

    interface IContentRotator
    {
        CONST_VTBL struct IContentRotatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContentRotator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContentRotator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContentRotator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContentRotator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IContentRotator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IContentRotator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IContentRotator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IContentRotator_ChooseContent(This,bstrDataFile,pbstrRetVal)	\
    (This)->lpVtbl -> ChooseContent(This,bstrDataFile,pbstrRetVal)

#define IContentRotator_GetAllContent(This,bstrDataFile)	\
    (This)->lpVtbl -> GetAllContent(This,bstrDataFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContentRotator_ChooseContent_Proxy( 
    IContentRotator __RPC_FAR * This,
    /* [in] */ BSTR bstrDataFile,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);


void __RPC_STUB IContentRotator_ChooseContent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContentRotator_GetAllContent_Proxy( 
    IContentRotator __RPC_FAR * This,
    /* [in] */ BSTR bstrDataFile);


void __RPC_STUB IContentRotator_GetAllContent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContentRotator_INTERFACE_DEFINED__ */



#ifndef __ContRotTypeLibrary_LIBRARY_DEFINED__
#define __ContRotTypeLibrary_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: ContRotTypeLibrary
 * at Mon Aug 04 14:26:10 1997
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_ContRotTypeLibrary;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_CContentRotator;

class DECLSPEC_UUID("E7EFF398-2E8A-11D0-B69A-00C0F00AE35A")
CContentRotator;
#endif
#endif /* __ContRotTypeLibrary_LIBRARY_DEFINED__ */

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
