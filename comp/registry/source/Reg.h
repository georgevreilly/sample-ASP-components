/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Sep 15 16:24:18 1997
 */
/* Compiler settings for Reg.idl:
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

#ifndef __Reg_h__
#define __Reg_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRegObj_FWD_DEFINED__
#define __IRegObj_FWD_DEFINED__
typedef interface IRegObj IRegObj;
#endif 	/* __IRegObj_FWD_DEFINED__ */


#ifndef __IRegSubKeysCollection_FWD_DEFINED__
#define __IRegSubKeysCollection_FWD_DEFINED__
typedef interface IRegSubKeysCollection IRegSubKeysCollection;
#endif 	/* __IRegSubKeysCollection_FWD_DEFINED__ */


#ifndef __IRegValue_FWD_DEFINED__
#define __IRegValue_FWD_DEFINED__
typedef interface IRegValue IRegValue;
#endif 	/* __IRegValue_FWD_DEFINED__ */


#ifndef __IRegValuesCollection_FWD_DEFINED__
#define __IRegValuesCollection_FWD_DEFINED__
typedef interface IRegValuesCollection IRegValuesCollection;
#endif 	/* __IRegValuesCollection_FWD_DEFINED__ */


#ifndef __IRegObj_FWD_DEFINED__
#define __IRegObj_FWD_DEFINED__
typedef interface IRegObj IRegObj;
#endif 	/* __IRegObj_FWD_DEFINED__ */


#ifndef __IRegSubKeysCollection_FWD_DEFINED__
#define __IRegSubKeysCollection_FWD_DEFINED__
typedef interface IRegSubKeysCollection IRegSubKeysCollection;
#endif 	/* __IRegSubKeysCollection_FWD_DEFINED__ */


#ifndef __IRegValue_FWD_DEFINED__
#define __IRegValue_FWD_DEFINED__
typedef interface IRegValue IRegValue;
#endif 	/* __IRegValue_FWD_DEFINED__ */


#ifndef __IRegValuesCollection_FWD_DEFINED__
#define __IRegValuesCollection_FWD_DEFINED__
typedef interface IRegValuesCollection IRegValuesCollection;
#endif 	/* __IRegValuesCollection_FWD_DEFINED__ */


#ifndef __CRegObj_FWD_DEFINED__
#define __CRegObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRegObj CRegObj;
#else
typedef struct CRegObj CRegObj;
#endif /* __cplusplus */

#endif 	/* __CRegObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IRegObj_INTERFACE_DEFINED__
#define __IRegObj_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRegObj
 * at Mon Sep 15 16:24:18 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][version][object] */ 



EXTERN_C const IID IID_IRegObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("9C3558B4-4175-11D0-926E-00AA00B91D12")
    IRegObj : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetExpand( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [in] */ VARIANT vtValue,
            /* [optional][in] */ VARIANT_BOOL fFlush) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExpand( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [in] */ BSTR bstrValue,
            /* [optional][in] */ VARIANT_BOOL fFlush) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteKey( 
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [optional][in] */ VARIANT_BOOL fFlush) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteValue( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [optional][in] */ VARIANT_BOOL fFlush) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyKey( 
            /* [in] */ BSTR bstrRegFullKeynameSource,
            /* [in] */ BSTR bstrRegFullKeynameDest,
            /* [optional][in] */ VARIANT_BOOL fFlush) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExpandString( 
            /* [in] */ BSTR bstr,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE KeyExists( 
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ValueType( 
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubKeys( 
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Values( 
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegObj __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegObj __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegObj __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExpand )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Set )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [in] */ VARIANT vtValue,
            /* [optional][in] */ VARIANT_BOOL fFlush);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExpand )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [in] */ BSTR bstrValue,
            /* [optional][in] */ VARIANT_BOOL fFlush);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteKey )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [optional][in] */ VARIANT_BOOL fFlush);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteValue )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [optional][in] */ VARIANT_BOOL fFlush);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyKey )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeynameSource,
            /* [in] */ BSTR bstrRegFullKeynameDest,
            /* [optional][in] */ VARIANT_BOOL fFlush);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExpandString )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstr,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *KeyExists )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValueType )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyValuename,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SubKeys )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Values )( 
            IRegObj __RPC_FAR * This,
            /* [in] */ BSTR bstrRegFullKeyname,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        END_INTERFACE
    } IRegObjVtbl;

    interface IRegObj
    {
        CONST_VTBL struct IRegObjVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegObj_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegObj_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegObj_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegObj_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegObj_Get(This,bstrRegFullKeyValuename,pvtRetVal)	\
    (This)->lpVtbl -> Get(This,bstrRegFullKeyValuename,pvtRetVal)

#define IRegObj_GetExpand(This,bstrRegFullKeyValuename,pvtRetVal)	\
    (This)->lpVtbl -> GetExpand(This,bstrRegFullKeyValuename,pvtRetVal)

#define IRegObj_Set(This,bstrRegFullKeyValuename,vtValue,fFlush)	\
    (This)->lpVtbl -> Set(This,bstrRegFullKeyValuename,vtValue,fFlush)

#define IRegObj_SetExpand(This,bstrRegFullKeyValuename,bstrValue,fFlush)	\
    (This)->lpVtbl -> SetExpand(This,bstrRegFullKeyValuename,bstrValue,fFlush)

#define IRegObj_DeleteKey(This,bstrRegFullKeyname,fFlush)	\
    (This)->lpVtbl -> DeleteKey(This,bstrRegFullKeyname,fFlush)

#define IRegObj_DeleteValue(This,bstrRegFullKeyValuename,fFlush)	\
    (This)->lpVtbl -> DeleteValue(This,bstrRegFullKeyValuename,fFlush)

#define IRegObj_CopyKey(This,bstrRegFullKeynameSource,bstrRegFullKeynameDest,fFlush)	\
    (This)->lpVtbl -> CopyKey(This,bstrRegFullKeynameSource,bstrRegFullKeynameDest,fFlush)

#define IRegObj_ExpandString(This,bstr,pbstrRetVal)	\
    (This)->lpVtbl -> ExpandString(This,bstr,pbstrRetVal)

#define IRegObj_KeyExists(This,bstrRegFullKeyname,pfRetVal)	\
    (This)->lpVtbl -> KeyExists(This,bstrRegFullKeyname,pfRetVal)

#define IRegObj_ValueType(This,bstrRegFullKeyValuename,pbstrRetVal)	\
    (This)->lpVtbl -> ValueType(This,bstrRegFullKeyValuename,pbstrRetVal)

#define IRegObj_SubKeys(This,bstrRegFullKeyname,pvtRetVal)	\
    (This)->lpVtbl -> SubKeys(This,bstrRegFullKeyname,pvtRetVal)

#define IRegObj_Values(This,bstrRegFullKeyname,pvtRetVal)	\
    (This)->lpVtbl -> Values(This,bstrRegFullKeyname,pvtRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Get_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegObj_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_GetExpand_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegObj_GetExpand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Set_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [in] */ VARIANT vtValue,
    /* [optional][in] */ VARIANT_BOOL fFlush);


void __RPC_STUB IRegObj_Set_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_SetExpand_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [in] */ BSTR bstrValue,
    /* [optional][in] */ VARIANT_BOOL fFlush);


void __RPC_STUB IRegObj_SetExpand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_DeleteKey_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [optional][in] */ VARIANT_BOOL fFlush);


void __RPC_STUB IRegObj_DeleteKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_DeleteValue_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [optional][in] */ VARIANT_BOOL fFlush);


void __RPC_STUB IRegObj_DeleteValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_CopyKey_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeynameSource,
    /* [in] */ BSTR bstrRegFullKeynameDest,
    /* [optional][in] */ VARIANT_BOOL fFlush);


void __RPC_STUB IRegObj_CopyKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_ExpandString_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstr,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);


void __RPC_STUB IRegObj_ExpandString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_KeyExists_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfRetVal);


void __RPC_STUB IRegObj_KeyExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_ValueType_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);


void __RPC_STUB IRegObj_ValueType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_SubKeys_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegObj_SubKeys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Values_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegObj_Values_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegObj_INTERFACE_DEFINED__ */


#ifndef __IRegSubKeysCollection_INTERFACE_DEFINED__
#define __IRegSubKeysCollection_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRegSubKeysCollection
 * at Mon Sep 15 16:24:18 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][version][object] */ 



EXTERN_C const IID IID_IRegSubKeysCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("12709b00-bdc0-11d0-8b43-00c0f00ae35a")
    IRegSubKeysCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT vtIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegSubKeysCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegSubKeysCollection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegSubKeysCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [in] */ VARIANT vtIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IRegSubKeysCollection __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal);
        
        END_INTERFACE
    } IRegSubKeysCollectionVtbl;

    interface IRegSubKeysCollection
    {
        CONST_VTBL struct IRegSubKeysCollectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegSubKeysCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegSubKeysCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegSubKeysCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegSubKeysCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegSubKeysCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegSubKeysCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegSubKeysCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegSubKeysCollection_get_Item(This,vtIndex,pvtRetVal)	\
    (This)->lpVtbl -> get_Item(This,vtIndex,pvtRetVal)

#define IRegSubKeysCollection_get_Count(This,plRetVal)	\
    (This)->lpVtbl -> get_Count(This,plRetVal)

#define IRegSubKeysCollection_get__NewEnum(This,punkRetVal)	\
    (This)->lpVtbl -> get__NewEnum(This,punkRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get_Item_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [in] */ VARIANT vtIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegSubKeysCollection_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get_Count_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IRegSubKeysCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get__NewEnum_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal);


void __RPC_STUB IRegSubKeysCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegSubKeysCollection_INTERFACE_DEFINED__ */


#ifndef __IRegValue_INTERFACE_DEFINED__
#define __IRegValue_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRegValue
 * at Mon Sep 15 16:24:18 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][version][object] */ 



EXTERN_C const IID IID_IRegValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("12709b01-bdc0-11d0-8b43-00c0f00ae35a")
    IRegValue : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegValue __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegValue __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegValue __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegValue __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegValue __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegValue __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegValue __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRegValue __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IRegValue __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        END_INTERFACE
    } IRegValueVtbl;

    interface IRegValue
    {
        CONST_VTBL struct IRegValueVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegValue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegValue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegValue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegValue_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegValue_get_Name(This,pbstrRetVal)	\
    (This)->lpVtbl -> get_Name(This,pbstrRetVal)

#define IRegValue_get_Value(This,pvtRetVal)	\
    (This)->lpVtbl -> get_Value(This,pvtRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValue_get_Name_Proxy( 
    IRegValue __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal);


void __RPC_STUB IRegValue_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValue_get_Value_Proxy( 
    IRegValue __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegValue_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegValue_INTERFACE_DEFINED__ */


#ifndef __IRegValuesCollection_INTERFACE_DEFINED__
#define __IRegValuesCollection_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRegValuesCollection
 * at Mon Sep 15 16:24:18 1997
 * using MIDL 3.01.75
 ****************************************/
/* [oleautomation][unique][helpstring][dual][uuid][version][object] */ 



EXTERN_C const IID IID_IRegValuesCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("12709b02-bdc0-11d0-8b43-00c0f00ae35a")
    IRegValuesCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT vtIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegValuesCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegValuesCollection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegValuesCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [in] */ VARIANT vtIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IRegValuesCollection __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal);
        
        END_INTERFACE
    } IRegValuesCollectionVtbl;

    interface IRegValuesCollection
    {
        CONST_VTBL struct IRegValuesCollectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegValuesCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegValuesCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegValuesCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegValuesCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegValuesCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegValuesCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegValuesCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegValuesCollection_get_Item(This,vtIndex,pvtRetVal)	\
    (This)->lpVtbl -> get_Item(This,vtIndex,pvtRetVal)

#define IRegValuesCollection_get_Count(This,plRetVal)	\
    (This)->lpVtbl -> get_Count(This,plRetVal)

#define IRegValuesCollection_get__NewEnum(This,punkRetVal)	\
    (This)->lpVtbl -> get__NewEnum(This,punkRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get_Item_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [in] */ VARIANT vtIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal);


void __RPC_STUB IRegValuesCollection_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get_Count_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IRegValuesCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get__NewEnum_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal);


void __RPC_STUB IRegValuesCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegValuesCollection_INTERFACE_DEFINED__ */



#ifndef __RegistryAccess_LIBRARY_DEFINED__
#define __RegistryAccess_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: RegistryAccess
 * at Mon Sep 15 16:24:18 1997
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 







EXTERN_C const IID LIBID_RegistryAccess;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_CRegObj;

class DECLSPEC_UUID("9C3558B8-4175-11D0-926E-00AA00B91D12")
CRegObj;
#endif
#endif /* __RegistryAccess_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
