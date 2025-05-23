;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\unknwnbase.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __unknwnbase_h__
  __unknwnbase_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IUnknown_FWD_DEFINED__
    __IUnknown_FWD_DEFINED__ equ <>
    ;IUnknown typedef IUnknown
    
  endif
  ifndef __AsyncIUnknown_FWD_DEFINED__
    __AsyncIUnknown_FWD_DEFINED__ equ <>
    ;AsyncIUnknown typedef AsyncIUnknown
    
  endif
  ifndef __IClassFactory_FWD_DEFINED__
    __IClassFactory_FWD_DEFINED__ equ <>
    ;IClassFactory typedef IClassFactory
    
  endif
  include wtypesbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if (_MSC_VER ge 1020)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwnbase_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUnknown_INTERFACE_DEFINED__
      __IUnknown_INTERFACE_DEFINED__ equ <>
      LPUNKNOWN typedef ptr IUnknown
      if (_MSC_VER ge 1100) and Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        externdef IID_IUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUnknownVtbl>
            STD_METHOD QueryInterface, :ptr IUnknown, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IUnknown
            STD_METHOD Release, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IUnknownVtbl ends
          IUnknown struct
            lpVtbl POINTER ?
          IUnknown ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IUnknown_QueryInterface_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown, :REFIID, :ptr ptr
        IUnknown_QueryInterface_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IUnknown_AddRef_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        IUnknown_AddRef_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IUnknown_Release_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        IUnknown_Release_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwnbase_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __AsyncIUnknown_INTERFACE_DEFINED__
      __AsyncIUnknown_INTERFACE_DEFINED__ equ <>
      externdef IID_AsyncIUnknown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        AsyncIUnknownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <AsyncIUnknownVtbl>
          STD_METHOD QueryInterface, :ptr AsyncIUnknown, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr AsyncIUnknown
          STD_METHOD Release, :ptr AsyncIUnknown
          STD_METHOD Begin_QueryInterface, :ptr AsyncIUnknown, :REFIID
          STD_METHOD Finish_QueryInterface, :ptr AsyncIUnknown, :ptr ptr
          STD_METHOD Begin_AddRef, :ptr AsyncIUnknown
          STD_METHOD Finish_AddRef, :ptr AsyncIUnknown
          STD_METHOD Begin_Release, :ptr AsyncIUnknown
          STD_METHOD Finish_Release, :ptr AsyncIUnknown
          ??Interface equ <>
          END_INTERFACE
        AsyncIUnknownVtbl ends
        AsyncIUnknown struct
          lpVtbl POINTER ?
        AsyncIUnknown ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwnbase_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IClassFactory_INTERFACE_DEFINED__
      __IClassFactory_INTERFACE_DEFINED__ equ <>
      LPCLASSFACTORY typedef ptr IClassFactory
      externdef IID_IClassFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IClassFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IClassFactoryVtbl>
          STD_METHOD QueryInterface, :ptr IClassFactory, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IClassFactory
          STD_METHOD Release, :ptr IClassFactory
          STD_METHOD CreateInstance, :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
          STD_METHOD LockServer, :ptr IClassFactory, :BOOL
          ??Interface equ <>
          END_INTERFACE
        IClassFactoryVtbl ends
        IClassFactory struct
          lpVtbl POINTER ?
        IClassFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IClassFactory_RemoteCreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
      IClassFactory_RemoteCreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      IClassFactory_RemoteLockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
      IClassFactory_RemoteLockServer_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  externdef __MIDL_itf_unknwnbase_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_unknwnbase_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
  IClassFactory_CreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
  IClassFactory_CreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
  IClassFactory_LockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  IClassFactory_LockServer_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  ifdef __cplusplus
    ;[...]
  endif
endif

