/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Sep 15 16:24:18 1997
 */
/* Compiler settings for Reg.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "Reg.h"

#define TYPE_FORMAT_STRING_SIZE   1133                              
#define PROC_FORMAT_STRING_SIZE   167                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRegObj, ver. 1.2,
   GUID={0x9C3558B4,0x4175,0x11D0,{0x92,0x6E,0x00,0xAA,0x00,0xB9,0x1D,0x12}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Get_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[820],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[34],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M0;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    BSTR bstrRegFullKeyValuename;
    VARIANT __RPC_FAR *pvtRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M0;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Get(
       (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
       bstrRegFullKeyValuename,
       pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[820] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[820] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[24] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[34] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_GetExpand_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[830] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[830] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[10] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[840],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_GetExpand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M1;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    BSTR bstrRegFullKeyValuename;
    VARIANT __RPC_FAR *pvtRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[10] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[830],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M1;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetExpand(
             (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
             bstrRegFullKeyValuename,
             pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[830] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[840] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Set_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [in] */ VARIANT vtValue,
    /* [optional][in] */ VARIANT_BOOL fFlush)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 11U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[854] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&vtValue,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[868] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[854] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&vtValue,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[868] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fFlush;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[20] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_Set_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    void __RPC_FAR *_p_vtValue;
    BSTR bstrRegFullKeyValuename;
    VARIANT_BOOL fFlush;
    VARIANT vtValue;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    _p_vtValue = &vtValue;
    MIDL_memset(
               _p_vtValue,
               0,
               sizeof( VARIANT  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[20] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[854],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_vtValue,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[868],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        fFlush = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Set(
       (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
       bstrRegFullKeyValuename,
       vtValue,
       fFlush);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[854] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&vtValue,
                            &__MIDL_TypeFormatString.Format[868] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_SetExpand_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [in] */ BSTR bstrValue,
    /* [optional][in] */ VARIANT_BOOL fFlush)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 11U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[878] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrValue,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[888] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[878] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrValue,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[888] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fFlush;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[32] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_SetExpand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    void __RPC_FAR *_p_bstrValue;
    BSTR bstrRegFullKeyValuename;
    BSTR bstrValue;
    VARIANT_BOOL fFlush;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    _p_bstrValue = &bstrValue;
    MIDL_memset(
               _p_bstrValue,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[32] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[878],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrValue,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[888],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        fFlush = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetExpand(
             (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
             bstrRegFullKeyValuename,
             bstrValue,
             fFlush);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[878] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrValue,
                            &__MIDL_TypeFormatString.Format[888] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_DeleteKey_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [optional][in] */ VARIANT_BOOL fFlush)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fFlush;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[44] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_DeleteKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyname;
    BSTR bstrRegFullKeyname;
    VARIANT_BOOL fFlush;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyname = &bstrRegFullKeyname;
    MIDL_memset(
               _p_bstrRegFullKeyname,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[44] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyname,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        fFlush = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> DeleteKey(
             (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
             bstrRegFullKeyname,
             fFlush);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                            &__MIDL_TypeFormatString.Format[898] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_DeleteValue_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [optional][in] */ VARIANT_BOOL fFlush)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[908] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[908] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fFlush;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[52] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_DeleteValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    BSTR bstrRegFullKeyValuename;
    VARIANT_BOOL fFlush;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[52] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[908],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        fFlush = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> DeleteValue(
               (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
               bstrRegFullKeyValuename,
               fFlush);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[908] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_CopyKey_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeynameSource,
    /* [in] */ BSTR bstrRegFullKeynameDest,
    /* [optional][in] */ VARIANT_BOOL fFlush)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 11U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeynameSource,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[918] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeynameDest,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[928] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeynameSource,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[918] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeynameDest,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[928] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fFlush;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_CopyKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeynameDest;
    void __RPC_FAR *_p_bstrRegFullKeynameSource;
    BSTR bstrRegFullKeynameDest;
    BSTR bstrRegFullKeynameSource;
    VARIANT_BOOL fFlush;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeynameSource = &bstrRegFullKeynameSource;
    MIDL_memset(
               _p_bstrRegFullKeynameSource,
               0,
               sizeof( BSTR  ));
    _p_bstrRegFullKeynameDest = &bstrRegFullKeynameDest;
    MIDL_memset(
               _p_bstrRegFullKeynameDest,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeynameSource,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[918],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeynameDest,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[928],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        fFlush = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> CopyKey(
           (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
           bstrRegFullKeynameSource,
           bstrRegFullKeynameDest,
           fFlush);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeynameSource,
                            &__MIDL_TypeFormatString.Format[918] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeynameDest,
                            &__MIDL_TypeFormatString.Format[928] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_ExpandString_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstr,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstr,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[938] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstr,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[938] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[72] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pbstrRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[952],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[948],
                         ( void __RPC_FAR * )pbstrRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_ExpandString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR _M2;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstr;
    BSTR bstr;
    BSTR __RPC_FAR *pbstrRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstr = &bstr;
    MIDL_memset(
               _p_bstr,
               0,
               sizeof( BSTR  ));
    pbstrRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[72] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstr,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[938],
                                  (unsigned char)0 );
        
        pbstrRetVal = &_M2;
        MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ExpandString(
                (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
                bstr,
                pbstrRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pbstrRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[952] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pbstrRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[952] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstr,
                            &__MIDL_TypeFormatString.Format[938] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pbstrRetVal,
                        &__MIDL_TypeFormatString.Format[948] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_KeyExists_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pfRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[962] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[962] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[82] );
            
            *pfRetVal = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer += 2;
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[972],
                         ( void __RPC_FAR * )pfRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_KeyExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT_BOOL _M3;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyname;
    BSTR bstrRegFullKeyname;
    VARIANT_BOOL __RPC_FAR *pfRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyname = &bstrRegFullKeyname;
    MIDL_memset(
               _p_bstrRegFullKeyname,
               0,
               sizeof( BSTR  ));
    pfRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[82] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyname,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[962],
                                  (unsigned char)0 );
        
        pfRetVal = &_M3;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> KeyExists(
             (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
             bstrRegFullKeyname,
             pfRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *pfRetVal;
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                            &__MIDL_TypeFormatString.Format[962] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_ValueType_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyValuename,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[976] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[976] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[92] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pbstrRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[990],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[986],
                         ( void __RPC_FAR * )pbstrRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_ValueType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR _M4;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyValuename;
    BSTR bstrRegFullKeyValuename;
    BSTR __RPC_FAR *pbstrRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyValuename = &bstrRegFullKeyValuename;
    MIDL_memset(
               _p_bstrRegFullKeyValuename,
               0,
               sizeof( BSTR  ));
    pbstrRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[92] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyValuename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[976],
                                  (unsigned char)0 );
        
        pbstrRetVal = &_M4;
        MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ValueType(
             (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
             bstrRegFullKeyValuename,
             pbstrRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pbstrRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[990] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pbstrRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[990] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyValuename,
                            &__MIDL_TypeFormatString.Format[976] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pbstrRetVal,
                        &__MIDL_TypeFormatString.Format[986] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_SubKeys_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1000] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1000] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[102] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_SubKeys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M5;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyname;
    BSTR bstrRegFullKeyname;
    VARIANT __RPC_FAR *pvtRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyname = &bstrRegFullKeyname;
    MIDL_memset(
               _p_bstrRegFullKeyname,
               0,
               sizeof( BSTR  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[102] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyname,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1000],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M5;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SubKeys(
           (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
           bstrRegFullKeyname,
           pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                            &__MIDL_TypeFormatString.Format[1000] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[1010] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegObj_Values_Proxy( 
    IRegObj __RPC_FAR * This,
    /* [in] */ BSTR bstrRegFullKeyname,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1024] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1024] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[112] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1038],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1034],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegObj_Values_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M6;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_bstrRegFullKeyname;
    BSTR bstrRegFullKeyname;
    VARIANT __RPC_FAR *pvtRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_bstrRegFullKeyname = &bstrRegFullKeyname;
    MIDL_memset(
               _p_bstrRegFullKeyname,
               0,
               sizeof( BSTR  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[112] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_bstrRegFullKeyname,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1024],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M6;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegObj *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Values(
          (IRegObj *) ((CStdStubBuffer *)This)->pvServerObject,
          bstrRegFullKeyname,
          pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1038] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1038] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&bstrRegFullKeyname,
                            &__MIDL_TypeFormatString.Format[1024] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[1034] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(19) _IRegObjProxyVtbl = 
{
    &IID_IRegObj,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IRegObj_Get_Proxy ,
    IRegObj_GetExpand_Proxy ,
    IRegObj_Set_Proxy ,
    IRegObj_SetExpand_Proxy ,
    IRegObj_DeleteKey_Proxy ,
    IRegObj_DeleteValue_Proxy ,
    IRegObj_CopyKey_Proxy ,
    IRegObj_ExpandString_Proxy ,
    IRegObj_KeyExists_Proxy ,
    IRegObj_ValueType_Proxy ,
    IRegObj_SubKeys_Proxy ,
    IRegObj_Values_Proxy
};


static const PRPC_STUB_FUNCTION IRegObj_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IRegObj_Get_Stub,
    IRegObj_GetExpand_Stub,
    IRegObj_Set_Stub,
    IRegObj_SetExpand_Stub,
    IRegObj_DeleteKey_Stub,
    IRegObj_DeleteValue_Stub,
    IRegObj_CopyKey_Stub,
    IRegObj_ExpandString_Stub,
    IRegObj_KeyExists_Stub,
    IRegObj_ValueType_Stub,
    IRegObj_SubKeys_Stub,
    IRegObj_Values_Stub
};

CInterfaceStubVtbl _IRegObjStubVtbl =
{
    &IID_IRegObj,
    0,
    19,
    &IRegObj_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRegSubKeysCollection, ver. 1.0,
   GUID={0x12709b00,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get_Item_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [in] */ VARIANT vtIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&vtIndex,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1048] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&vtIndex,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1048] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[122] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1058],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegSubKeysCollection_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M7;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_vtIndex;
    VARIANT __RPC_FAR *pvtRetVal;
    VARIANT vtIndex;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_vtIndex = &vtIndex;
    MIDL_memset(
               _p_vtIndex,
               0,
               sizeof( VARIANT  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[122] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_vtIndex,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1048],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M7;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Item(
            (IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject,
            vtIndex,
            pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&vtIndex,
                            &__MIDL_TypeFormatString.Format[1048] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[1058] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get_Count_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
            
            *plRetVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1072],
                         ( void __RPC_FAR * )plRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegSubKeysCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M8;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *plRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    plRetVal = 0;
    RpcTryFinally
        {
        plRetVal = &_M8;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Count((IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject,plRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *plRetVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IRegSubKeysCollection_get__NewEnum_Proxy( 
    IRegSubKeysCollection __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *punkRetVal = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&punkRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1076],
                         ( void __RPC_FAR * )punkRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegSubKeysCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IUnknown __RPC_FAR *_M9;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IUnknown __RPC_FAR *__RPC_FAR *punkRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    punkRetVal = 0;
    RpcTryFinally
        {
        punkRetVal = &_M9;
        _M9 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get__NewEnum((IRegSubKeysCollection *) ((CStdStubBuffer *)This)->pvServerObject,punkRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)punkRetVal,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)punkRetVal,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)punkRetVal,
                        &__MIDL_TypeFormatString.Format[1076] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(10) _IRegSubKeysCollectionProxyVtbl = 
{
    &IID_IRegSubKeysCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IRegSubKeysCollection_get_Item_Proxy ,
    IRegSubKeysCollection_get_Count_Proxy ,
    IRegSubKeysCollection_get__NewEnum_Proxy
};


static const PRPC_STUB_FUNCTION IRegSubKeysCollection_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IRegSubKeysCollection_get_Item_Stub,
    IRegSubKeysCollection_get_Count_Stub,
    IRegSubKeysCollection_get__NewEnum_Stub
};

CInterfaceStubVtbl _IRegSubKeysCollectionStubVtbl =
{
    &IID_IRegSubKeysCollection,
    0,
    10,
    &IRegSubKeysCollection_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRegValue, ver. 1.0,
   GUID={0x12709b01,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValue_get_Name_Proxy( 
    IRegValue __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[144] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pbstrRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1084],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1080],
                         ( void __RPC_FAR * )pbstrRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegValue_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR _M10;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    BSTR __RPC_FAR *pbstrRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pbstrRetVal = 0;
    RpcTryFinally
        {
        pbstrRetVal = &_M10;
        MIDL_memset(
               pbstrRetVal,
               0,
               sizeof( BSTR  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegValue *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Name((IRegValue *) ((CStdStubBuffer *)This)->pvServerObject,pbstrRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pbstrRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1084] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pbstrRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1084] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pbstrRetVal,
                        &__MIDL_TypeFormatString.Format[1080] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValue_get_Value_Proxy( 
    IRegValue __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[150] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1098],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1094],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegValue_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M11;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT __RPC_FAR *pvtRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pvtRetVal = 0;
    RpcTryFinally
        {
        pvtRetVal = &_M11;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegValue *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Value((IRegValue *) ((CStdStubBuffer *)This)->pvServerObject,pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1098] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1098] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[1094] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(9) _IRegValueProxyVtbl = 
{
    &IID_IRegValue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IRegValue_get_Name_Proxy ,
    IRegValue_get_Value_Proxy
};


static const PRPC_STUB_FUNCTION IRegValue_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IRegValue_get_Name_Stub,
    IRegValue_get_Value_Stub
};

CInterfaceStubVtbl _IRegValueStubVtbl =
{
    &IID_IRegValue,
    0,
    9,
    &IRegValue_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRegValuesCollection, ver. 1.0,
   GUID={0x12709b02,0xbdc0,0x11d0,{0x8b,0x43,0x00,0xc0,0xf0,0x0a,0xe3,0x5a}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get_Item_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [in] */ VARIANT vtIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&vtIndex,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1108] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&vtIndex,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1108] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[156] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pvtRetVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1122],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1118],
                         ( void __RPC_FAR * )pvtRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegValuesCollection_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT _M12;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_vtIndex;
    VARIANT __RPC_FAR *pvtRetVal;
    VARIANT vtIndex;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_vtIndex = &vtIndex;
    MIDL_memset(
               _p_vtIndex,
               0,
               sizeof( VARIANT  ));
    pvtRetVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[156] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_vtIndex,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1108],
                                  (unsigned char)0 );
        
        pvtRetVal = &_M12;
        MIDL_memset(
               pvtRetVal,
               0,
               sizeof( VARIANT  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Item(
            (IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject,
            vtIndex,
            pvtRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pvtRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1122] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pvtRetVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1122] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&vtIndex,
                            &__MIDL_TypeFormatString.Format[1108] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pvtRetVal,
                        &__MIDL_TypeFormatString.Format[1118] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get_Count_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
            
            *plRetVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1072],
                         ( void __RPC_FAR * )plRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegValuesCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M13;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *plRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    plRetVal = 0;
    RpcTryFinally
        {
        plRetVal = &_M13;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Count((IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject,plRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *plRetVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IRegValuesCollection_get__NewEnum_Proxy( 
    IRegValuesCollection __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *punkRetVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *punkRetVal = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&punkRetVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1076],
                         ( void __RPC_FAR * )punkRetVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IRegValuesCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IUnknown __RPC_FAR *_M14;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IUnknown __RPC_FAR *__RPC_FAR *punkRetVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    punkRetVal = 0;
    RpcTryFinally
        {
        punkRetVal = &_M14;
        _M14 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get__NewEnum((IRegValuesCollection *) ((CStdStubBuffer *)This)->pvServerObject,punkRetVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)punkRetVal,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)punkRetVal,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1076] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)punkRetVal,
                        &__MIDL_TypeFormatString.Format[1076] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x301004b, /* MIDL Version 3.1.75 */
    0,
    UserMarshalRoutines,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

CINTERFACE_PROXY_VTABLE(10) _IRegValuesCollectionProxyVtbl = 
{
    &IID_IRegValuesCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IRegValuesCollection_get_Item_Proxy ,
    IRegValuesCollection_get_Count_Proxy ,
    IRegValuesCollection_get__NewEnum_Proxy
};


static const PRPC_STUB_FUNCTION IRegValuesCollection_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IRegValuesCollection_get_Item_Stub,
    IRegValuesCollection_get_Count_Stub,
    IRegValuesCollection_get__NewEnum_Stub
};

CInterfaceStubVtbl _IRegValuesCollectionStubVtbl =
{
    &IID_IRegValuesCollection,
    0,
    10,
    &IRegValuesCollection_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  2 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */
/*  4 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  6 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */
/*  8 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 10 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 12 */	NdrFcShort( 0x33e ),	/* Type Offset=830 */
/* 14 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 16 */	NdrFcShort( 0x348 ),	/* Type Offset=840 */
/* 18 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 20 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 22 */	NdrFcShort( 0x356 ),	/* Type Offset=854 */
/* 24 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x4,		/* x86, MIPS & PPC Stack size = 4 */
#else
			0x4,		/* Alpha Stack size = 4 */
#endif
/* 26 */	NdrFcShort( 0x364 ),	/* Type Offset=868 */
/* 28 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 30 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 32 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 34 */	NdrFcShort( 0x36e ),	/* Type Offset=878 */
/* 36 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 38 */	NdrFcShort( 0x378 ),	/* Type Offset=888 */
/* 40 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 42 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 44 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 46 */	NdrFcShort( 0x382 ),	/* Type Offset=898 */
/* 48 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 50 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 52 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 54 */	NdrFcShort( 0x38c ),	/* Type Offset=908 */
/* 56 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 58 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 60 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 62 */	NdrFcShort( 0x396 ),	/* Type Offset=918 */
/* 64 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 66 */	NdrFcShort( 0x3a0 ),	/* Type Offset=928 */
/* 68 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 70 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 72 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 74 */	NdrFcShort( 0x3aa ),	/* Type Offset=938 */
/* 76 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 78 */	NdrFcShort( 0x3b4 ),	/* Type Offset=948 */
/* 80 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 82 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 84 */	NdrFcShort( 0x3c2 ),	/* Type Offset=962 */
/* 86 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 88 */	NdrFcShort( 0x3cc ),	/* Type Offset=972 */
/* 90 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 92 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 94 */	NdrFcShort( 0x3d0 ),	/* Type Offset=976 */
/* 96 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 98 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */
/* 100 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 102 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 104 */	NdrFcShort( 0x3e8 ),	/* Type Offset=1000 */
/* 106 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 108 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 110 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 112 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 114 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */
/* 116 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 118 */	NdrFcShort( 0x40a ),	/* Type Offset=1034 */
/* 120 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 122 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x4,		/* x86, MIPS & PPC Stack size = 4 */
#else
			0x4,		/* Alpha Stack size = 4 */
#endif
/* 124 */	NdrFcShort( 0x418 ),	/* Type Offset=1048 */
/* 126 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 128 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */
/* 130 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 132 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 134 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */
/* 136 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 138 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 140 */	NdrFcShort( 0x434 ),	/* Type Offset=1076 */
/* 142 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 144 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 146 */	NdrFcShort( 0x438 ),	/* Type Offset=1080 */
/* 148 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 150 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 152 */	NdrFcShort( 0x446 ),	/* Type Offset=1094 */
/* 154 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 156 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x4,		/* x86, MIPS & PPC Stack size = 4 */
#else
			0x4,		/* Alpha Stack size = 4 */
#endif
/* 158 */	NdrFcShort( 0x454 ),	/* Type Offset=1108 */
/* 160 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 162 */	NdrFcShort( 0x45e ),	/* Type Offset=1118 */
/* 164 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x12, 0x0,	/* FC_UP */
/*  2 */	NdrFcShort( 0xc ),	/* Offset= 12 (14) */
/*  4 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  6 */	NdrFcShort( 0x2 ),	/* 2 */
/*  8 */	0x9,		/* 9 */
			0x0,		/*  */
/* 10 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 12 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 14 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (4) */
/* 20 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 22 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 24 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x4 ),	/* 4 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (0) */
/* 34 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 36 */	NdrFcShort( 0x310 ),	/* Offset= 784 (820) */
/* 38 */	
			0x13, 0x0,	/* FC_OP */
/* 40 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (800) */
/* 42 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 44 */	0x6,		/* 6 */
			0x0,		/*  */
/* 46 */	NdrFcShort( 0xfffffff8 ),	/* -8 */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	NdrFcShort( 0x10 ),	/* 16 */
/* 52 */	NdrFcShort( 0x29 ),	/* 41 */
/* 54 */	NdrFcLong( 0x3 ),	/* 3 */
/* 58 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32702) */
/* 60 */	NdrFcLong( 0x11 ),	/* 17 */
/* 64 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-32702) */
/* 66 */	NdrFcLong( 0x2 ),	/* 2 */
/* 70 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32692) */
/* 72 */	NdrFcLong( 0x4 ),	/* 4 */
/* 76 */	NdrFcShort( 0xffff800a ),	/* Offset= -32758 (-32682) */
/* 78 */	NdrFcLong( 0x5 ),	/* 5 */
/* 82 */	NdrFcShort( 0xffff800c ),	/* Offset= -32756 (-32674) */
/* 84 */	NdrFcLong( 0xb ),	/* 11 */
/* 88 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32674) */
/* 90 */	NdrFcLong( 0xa ),	/* 10 */
/* 94 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32666) */
/* 96 */	NdrFcLong( 0x6 ),	/* 6 */
/* 100 */	NdrFcShort( 0xca ),	/* Offset= 202 (302) */
/* 102 */	NdrFcLong( 0x7 ),	/* 7 */
/* 106 */	NdrFcShort( 0xffff800c ),	/* Offset= -32756 (-32650) */
/* 108 */	NdrFcLong( 0x8 ),	/* 8 */
/* 112 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (308) */
/* 114 */	NdrFcLong( 0xd ),	/* 13 */
/* 118 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (312) */
/* 120 */	NdrFcLong( 0x9 ),	/* 9 */
/* 124 */	NdrFcShort( 0xce ),	/* Offset= 206 (330) */
/* 126 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 130 */	NdrFcShort( 0xda ),	/* Offset= 218 (348) */
/* 132 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 136 */	NdrFcShort( 0x258 ),	/* Offset= 600 (736) */
/* 138 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 142 */	NdrFcShort( 0x256 ),	/* Offset= 598 (740) */
/* 144 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 148 */	NdrFcShort( 0x254 ),	/* Offset= 596 (744) */
/* 150 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 154 */	NdrFcShort( 0x252 ),	/* Offset= 594 (748) */
/* 156 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 160 */	NdrFcShort( 0x250 ),	/* Offset= 592 (752) */
/* 162 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 166 */	NdrFcShort( 0x23e ),	/* Offset= 574 (740) */
/* 168 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 172 */	NdrFcShort( 0x23c ),	/* Offset= 572 (744) */
/* 174 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 178 */	NdrFcShort( 0x242 ),	/* Offset= 578 (756) */
/* 180 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 184 */	NdrFcShort( 0x238 ),	/* Offset= 568 (752) */
/* 186 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 190 */	NdrFcShort( 0x23a ),	/* Offset= 570 (760) */
/* 192 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 196 */	NdrFcShort( 0x238 ),	/* Offset= 568 (764) */
/* 198 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 202 */	NdrFcShort( 0x236 ),	/* Offset= 566 (768) */
/* 204 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 208 */	NdrFcShort( 0x234 ),	/* Offset= 564 (772) */
/* 210 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 214 */	NdrFcShort( 0x232 ),	/* Offset= 562 (776) */
/* 216 */	NdrFcLong( 0x10 ),	/* 16 */
/* 220 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-32546) */
/* 222 */	NdrFcLong( 0x12 ),	/* 18 */
/* 226 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32536) */
/* 228 */	NdrFcLong( 0x13 ),	/* 19 */
/* 232 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32528) */
/* 234 */	NdrFcLong( 0x16 ),	/* 22 */
/* 238 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32522) */
/* 240 */	NdrFcLong( 0x17 ),	/* 23 */
/* 244 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32516) */
/* 246 */	NdrFcLong( 0xe ),	/* 14 */
/* 250 */	NdrFcShort( 0x216 ),	/* Offset= 534 (784) */
/* 252 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 256 */	NdrFcShort( 0x21c ),	/* Offset= 540 (796) */
/* 258 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 262 */	NdrFcShort( 0x1da ),	/* Offset= 474 (736) */
/* 264 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 268 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (740) */
/* 270 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 274 */	NdrFcShort( 0x1d6 ),	/* Offset= 470 (744) */
/* 276 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 280 */	NdrFcShort( 0x1d0 ),	/* Offset= 464 (744) */
/* 282 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 286 */	NdrFcShort( 0x1ca ),	/* Offset= 458 (744) */
/* 288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* Offset= 0 (292) */
/* 294 */	NdrFcLong( 0x1 ),	/* 1 */
/* 298 */	NdrFcShort( 0x0 ),	/* Offset= 0 (298) */
/* 300 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (299) */
/* 302 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 306 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 308 */	
			0x13, 0x0,	/* FC_OP */
/* 310 */	NdrFcShort( 0xfffffed8 ),	/* Offset= -296 (14) */
/* 312 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 324 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 326 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 328 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 330 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 332 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 342 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 344 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 346 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 348 */	
			0x13, 0x0,	/* FC_OP */
/* 350 */	NdrFcShort( 0x170 ),	/* Offset= 368 (718) */
/* 352 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 358 */	NdrFcLong( 0x8 ),	/* 8 */
/* 362 */	NdrFcShort( 0x4c ),	/* Offset= 76 (438) */
/* 364 */	NdrFcLong( 0xd ),	/* 13 */
/* 368 */	NdrFcShort( 0x6c ),	/* Offset= 108 (476) */
/* 370 */	NdrFcLong( 0x9 ),	/* 9 */
/* 374 */	NdrFcShort( 0x88 ),	/* Offset= 136 (510) */
/* 376 */	NdrFcLong( 0xc ),	/* 12 */
/* 380 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (556) */
/* 382 */	NdrFcLong( 0x10 ),	/* 16 */
/* 386 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (586) */
/* 388 */	NdrFcLong( 0x2 ),	/* 2 */
/* 392 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (616) */
/* 394 */	NdrFcLong( 0x3 ),	/* 3 */
/* 398 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (646) */
/* 400 */	NdrFcLong( 0x14 ),	/* 20 */
/* 404 */	NdrFcShort( 0x110 ),	/* Offset= 272 (676) */
/* 406 */	NdrFcShort( 0x0 ),	/* Offset= 0 (406) */
/* 408 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 410 */	NdrFcShort( 0x4 ),	/* 4 */
/* 412 */	0x18,		/* 24 */
			0x0,		/*  */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 418 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 420 */	NdrFcShort( 0x4 ),	/* 4 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x1 ),	/* 1 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	0x13, 0x0,	/* FC_OP */
/* 432 */	NdrFcShort( 0xfffffe5e ),	/* Offset= -418 (14) */
/* 434 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 436 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 438 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 442 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 444 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 448 */	NdrFcShort( 0x4 ),	/* 4 */
/* 450 */	0x11, 0x0,	/* FC_RP */
/* 452 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (408) */
/* 454 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 456 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 458 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	0x18,		/* 24 */
			0x0,		/*  */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 470 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 472 */	NdrFcShort( 0xffffff60 ),	/* Offset= -160 (312) */
/* 474 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 476 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x6 ),	/* Offset= 6 (488) */
/* 484 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 488 */	
			0x11, 0x0,	/* FC_RP */
/* 490 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (458) */
/* 492 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	0x18,		/* 24 */
			0x0,		/*  */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 504 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 506 */	NdrFcShort( 0xffffff50 ),	/* Offset= -176 (330) */
/* 508 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 510 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x6 ),	/* Offset= 6 (522) */
/* 518 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x11, 0x0,	/* FC_RP */
/* 524 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (492) */
/* 526 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 528 */	NdrFcShort( 0x4 ),	/* 4 */
/* 530 */	0x18,		/* 24 */
			0x0,		/*  */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 536 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 538 */	NdrFcShort( 0x4 ),	/* 4 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* 1 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	0x13, 0x0,	/* FC_OP */
/* 550 */	NdrFcShort( 0xfa ),	/* Offset= 250 (800) */
/* 552 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 556 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 560 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 562 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 564 */	NdrFcShort( 0x4 ),	/* 4 */
/* 566 */	NdrFcShort( 0x4 ),	/* 4 */
/* 568 */	0x11, 0x0,	/* FC_RP */
/* 570 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (526) */
/* 572 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 574 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 576 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 578 */	NdrFcShort( 0x1 ),	/* 1 */
/* 580 */	0x19,		/* 25 */
			0x0,		/*  */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 586 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 592 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 594 */	NdrFcShort( 0x4 ),	/* 4 */
/* 596 */	NdrFcShort( 0x4 ),	/* 4 */
/* 598 */	0x13, 0x0,	/* FC_OP */
/* 600 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (576) */
/* 602 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 604 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 606 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 608 */	NdrFcShort( 0x2 ),	/* 2 */
/* 610 */	0x19,		/* 25 */
			0x0,		/*  */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 616 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 620 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 622 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 624 */	NdrFcShort( 0x4 ),	/* 4 */
/* 626 */	NdrFcShort( 0x4 ),	/* 4 */
/* 628 */	0x13, 0x0,	/* FC_OP */
/* 630 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (606) */
/* 632 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 634 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 636 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 638 */	NdrFcShort( 0x4 ),	/* 4 */
/* 640 */	0x19,		/* 25 */
			0x0,		/*  */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 646 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 652 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 654 */	NdrFcShort( 0x4 ),	/* 4 */
/* 656 */	NdrFcShort( 0x4 ),	/* 4 */
/* 658 */	0x13, 0x0,	/* FC_OP */
/* 660 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (636) */
/* 662 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 664 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 666 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 670 */	0x19,		/* 25 */
			0x0,		/*  */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 676 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 682 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 684 */	NdrFcShort( 0x4 ),	/* 4 */
/* 686 */	NdrFcShort( 0x4 ),	/* 4 */
/* 688 */	0x13, 0x0,	/* FC_OP */
/* 690 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (666) */
/* 692 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 694 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 696 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 700 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 702 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 704 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	0x6,		/* 6 */
			0x0,		/*  */
/* 710 */	NdrFcShort( 0xffffffe8 ),	/* -24 */
/* 712 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (696) */
/* 716 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 718 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 720 */	NdrFcShort( 0x18 ),	/* 24 */
/* 722 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (704) */
/* 724 */	NdrFcShort( 0x0 ),	/* Offset= 0 (724) */
/* 726 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 728 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 730 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 732 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffe83 ),	/* Offset= -381 (352) */
			0x5b,		/* FC_END */
/* 736 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 738 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 740 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 742 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 744 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 746 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 748 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 750 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 752 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 754 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 756 */	
			0x13, 0x0,	/* FC_OP */
/* 758 */	NdrFcShort( 0xfffffe38 ),	/* Offset= -456 (302) */
/* 760 */	
			0x13, 0x10,	/* FC_OP */
/* 762 */	NdrFcShort( 0xfffffe3a ),	/* Offset= -454 (308) */
/* 764 */	
			0x13, 0x10,	/* FC_OP */
/* 766 */	NdrFcShort( 0xfffffe3a ),	/* Offset= -454 (312) */
/* 768 */	
			0x13, 0x10,	/* FC_OP */
/* 770 */	NdrFcShort( 0xfffffe48 ),	/* Offset= -440 (330) */
/* 772 */	
			0x13, 0x10,	/* FC_OP */
/* 774 */	NdrFcShort( 0xfffffe56 ),	/* Offset= -426 (348) */
/* 776 */	
			0x13, 0x10,	/* FC_OP */
/* 778 */	NdrFcShort( 0x2 ),	/* Offset= 2 (780) */
/* 780 */	
			0x13, 0x0,	/* FC_OP */
/* 782 */	NdrFcShort( 0xfffffcf2 ),	/* Offset= -782 (0) */
/* 784 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 786 */	NdrFcShort( 0x10 ),	/* 16 */
/* 788 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 790 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 792 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 794 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 796 */	
			0x13, 0x0,	/* FC_OP */
/* 798 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (784) */
/* 800 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 802 */	NdrFcShort( 0x20 ),	/* 32 */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x0 ),	/* Offset= 0 (806) */
/* 808 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 810 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 812 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 814 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 816 */	NdrFcShort( 0xfffffcfa ),	/* Offset= -774 (42) */
/* 818 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 820 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 822 */	NdrFcShort( 0x1 ),	/* 1 */
/* 824 */	NdrFcShort( 0x10 ),	/* 16 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0xfffffcea ),	/* Offset= -790 (38) */
/* 830 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0xfffffcba ),	/* Offset= -838 (0) */
/* 840 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 842 */	NdrFcShort( 0x2 ),	/* Offset= 2 (844) */
/* 844 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 846 */	NdrFcShort( 0x1 ),	/* 1 */
/* 848 */	NdrFcShort( 0x10 ),	/* 16 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0xfffffcd2 ),	/* Offset= -814 (38) */
/* 854 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0xfffffca2 ),	/* Offset= -862 (0) */
/* 864 */	
			0x12, 0x0,	/* FC_UP */
/* 866 */	NdrFcShort( 0xffffffbe ),	/* Offset= -66 (800) */
/* 868 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 870 */	NdrFcShort( 0x1 ),	/* 1 */
/* 872 */	NdrFcShort( 0x10 ),	/* 16 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (864) */
/* 878 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x4 ),	/* 4 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0xfffffc8a ),	/* Offset= -886 (0) */
/* 888 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0xfffffc80 ),	/* Offset= -896 (0) */
/* 898 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0xfffffc76 ),	/* Offset= -906 (0) */
/* 908 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x4 ),	/* 4 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0xfffffc6c ),	/* Offset= -916 (0) */
/* 918 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x4 ),	/* 4 */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0xfffffc62 ),	/* Offset= -926 (0) */
/* 928 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x4 ),	/* 4 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0xfffffc58 ),	/* Offset= -936 (0) */
/* 938 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x4 ),	/* 4 */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0xfffffc4e ),	/* Offset= -946 (0) */
/* 948 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 950 */	NdrFcShort( 0x2 ),	/* Offset= 2 (952) */
/* 952 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x4 ),	/* 4 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0xfffffd74 ),	/* Offset= -652 (308) */
/* 962 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x4 ),	/* 4 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0xfffffc36 ),	/* Offset= -970 (0) */
/* 972 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 974 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 976 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x4 ),	/* 4 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0xfffffc28 ),	/* Offset= -984 (0) */
/* 986 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 988 */	NdrFcShort( 0x2 ),	/* Offset= 2 (990) */
/* 990 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x4 ),	/* 4 */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0xfffffd4e ),	/* Offset= -690 (308) */
/* 1000 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0xfffffc10 ),	/* Offset= -1008 (0) */
/* 1010 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1012 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1014) */
/* 1014 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1016 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1018 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0xfffffc28 ),	/* Offset= -984 (38) */
/* 1024 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0xfffffbf8 ),	/* Offset= -1032 (0) */
/* 1034 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1036 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1038) */
/* 1038 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1040 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1042 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0xfffffc10 ),	/* Offset= -1008 (38) */
/* 1048 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1052 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0xffffff40 ),	/* Offset= -192 (864) */
/* 1058 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1060 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1062) */
/* 1062 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1064 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1066 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0xfffffbf8 ),	/* Offset= -1032 (38) */
/* 1072 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1074 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1076 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 1078 */	NdrFcShort( 0xfffffd02 ),	/* Offset= -766 (312) */
/* 1080 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1082 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1084) */
/* 1084 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0xfffffcf0 ),	/* Offset= -784 (308) */
/* 1094 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1096 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1098) */
/* 1098 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1100 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1102 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0xfffffbd4 ),	/* Offset= -1068 (38) */
/* 1108 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1110 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1112 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0xffffff04 ),	/* Offset= -252 (864) */
/* 1118 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1122) */
/* 1122 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1124 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1126 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0xfffffbbc ),	/* Offset= -1092 (38) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _Reg_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRegSubKeysCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRegValueProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRegValuesCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRegObjProxyVtbl,
    0
};

const CInterfaceStubVtbl * _Reg_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRegSubKeysCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IRegValueStubVtbl,
    ( CInterfaceStubVtbl *) &_IRegValuesCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IRegObjStubVtbl,
    0
};

PCInterfaceName const _Reg_InterfaceNamesList[] = 
{
    "IRegSubKeysCollection",
    "IRegValue",
    "IRegValuesCollection",
    "IRegObj",
    0
};

const IID *  _Reg_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _Reg_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Reg, pIID, n)

int __stdcall _Reg_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _Reg, 4, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _Reg, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _Reg, 4, *pIndex )
    
}

const ExtendedProxyFileInfo Reg_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Reg_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Reg_StubVtblList,
    (const PCInterfaceName * ) & _Reg_InterfaceNamesList,
    (const IID ** ) & _Reg_BaseIIDList,
    & _Reg_IID_Lookup, 
    4,
    1
};
