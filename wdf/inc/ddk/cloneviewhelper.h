

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* Compiler settings for cloneviewhelper.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __cloneviewhelper_h__
#define __cloneviewhelper_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICloneViewHelper_FWD_DEFINED__
#define __ICloneViewHelper_FWD_DEFINED__
typedef interface ICloneViewHelper ICloneViewHelper;
#endif 	/* __ICloneViewHelper_FWD_DEFINED__ */


#ifndef __IViewHelper_FWD_DEFINED__
#define __IViewHelper_FWD_DEFINED__
typedef interface IViewHelper IViewHelper;
#endif 	/* __IViewHelper_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_cloneviewhelper_0000_0000 */
/* [local] */ 

#define GETCONNECTEDIDS_TARGET 0
#define GETCONNECTEDIDS_SOURCE 1
#define S_INIT 2
// 0 == TMM's passed in configuration was applied
#define SETCONFIGURATION_STATUS_APPLIED 0
// 1 == TMM's passed in configuration was applied, with additional proprietary IHV settings
#define SETCONFIGURATION_STATUS_ADDITIONAL 1
// 2 == TMM's passed in configuration was overridden and IHV's own settings were applied
#define SETCONFIGURATION_STATUS_OVERRIDDEN 2

// Topology Data

typedef struct tagSources
{
    ULONG sourceId;
    int numTargets;
    ULONG aTargets[1];
} Sources;

typedef struct tagAdapter
{
    WCHAR AdapterName[128];
    int numSources;
    Sources sources[1];
} Adapter;

typedef struct tagAdapters
{
    int numAdapters;
    Adapter adapter[1];
} Adapters;

// Display Mode Data

typedef struct tagDisplayMode
{
    WCHAR DeviceName[32];
    DEVMODEW devMode;
} DisplayMode;

typedef struct tagDisplayModes
{
    int numDisplayModes;
    DisplayMode displayMode[1];
} DisplayModes;



extern RPC_IF_HANDLE __MIDL_itf_cloneviewhelper_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cloneviewhelper_0000_0000_v0_0_s_ifspec;

#ifndef __ICloneViewHelper_INTERFACE_DEFINED__
#define __ICloneViewHelper_INTERFACE_DEFINED__

/* interface ICloneViewHelper */
/* [unique][helpstring][nonextensible][uuid][object] */ 


EXTERN_C const IID IID_ICloneViewHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F6A3D4C4-5632-4D83-B0A1-FB88712B1EB7")
    ICloneViewHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectedIDs( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulID,
            /* [in] */ ULONG ulFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveTopology( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulTargetID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveTopology( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [in] */ ULONG ulCount,
            /* [in] */ __RPC__in ULONG *pulTargetID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ BOOL fFinalCall) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICloneViewHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICloneViewHelper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICloneViewHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICloneViewHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectedIDs )( 
            __RPC__in ICloneViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulID,
            /* [in] */ ULONG ulFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveTopology )( 
            __RPC__in ICloneViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulTargetID);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveTopology )( 
            __RPC__in ICloneViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [in] */ ULONG ulCount,
            /* [in] */ __RPC__in ULONG *pulTargetID);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ICloneViewHelper * This,
            /* [in] */ BOOL fFinalCall);
        
        END_INTERFACE
    } ICloneViewHelperVtbl;

    interface ICloneViewHelper
    {
        CONST_VTBL struct ICloneViewHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICloneViewHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICloneViewHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICloneViewHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICloneViewHelper_GetConnectedIDs(This,wszAdaptorName,pulCount,pulID,ulFlags)	\
    ( (This)->lpVtbl -> GetConnectedIDs(This,wszAdaptorName,pulCount,pulID,ulFlags) ) 

#define ICloneViewHelper_GetActiveTopology(This,wszAdaptorName,ulSourceID,pulCount,pulTargetID)	\
    ( (This)->lpVtbl -> GetActiveTopology(This,wszAdaptorName,ulSourceID,pulCount,pulTargetID) ) 

#define ICloneViewHelper_SetActiveTopology(This,wszAdaptorName,ulSourceID,ulCount,pulTargetID)	\
    ( (This)->lpVtbl -> SetActiveTopology(This,wszAdaptorName,ulSourceID,ulCount,pulTargetID) ) 

#define ICloneViewHelper_Commit(This,fFinalCall)	\
    ( (This)->lpVtbl -> Commit(This,fFinalCall) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICloneViewHelper_INTERFACE_DEFINED__ */


#ifndef __IViewHelper_INTERFACE_DEFINED__
#define __IViewHelper_INTERFACE_DEFINED__

/* interface IViewHelper */
/* [unique][helpstring][nonextensible][uuid][object] */ 


EXTERN_C const IID IID_IViewHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E85CCEF5-AAAA-47f0-B5E3-61F7AECDC4C1")
    IViewHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectedIDs( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulID,
            /* [in] */ ULONG ulFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveTopology( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulTargetID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveTopology( 
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [in] */ ULONG ulCount,
            /* [in] */ __RPC__in ULONG *pulTargetID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfiguration( 
            /* [in] */ __RPC__in_opt IStream *pIStream,
            /* [out] */ __RPC__out ULONG *pulStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProceedOnNewConfiguration( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IViewHelper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IViewHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IViewHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectedIDs )( 
            __RPC__in IViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulID,
            /* [in] */ ULONG ulFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveTopology )( 
            __RPC__in IViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [out][in] */ __RPC__inout ULONG *pulCount,
            /* [out][in] */ __RPC__inout ULONG *pulTargetID);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveTopology )( 
            __RPC__in IViewHelper * This,
            /* [in] */ __RPC__in LPCWSTR wszAdaptorName,
            /* [in] */ ULONG ulSourceID,
            /* [in] */ ULONG ulCount,
            /* [in] */ __RPC__in ULONG *pulTargetID);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IViewHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetConfiguration )( 
            __RPC__in IViewHelper * This,
            /* [in] */ __RPC__in_opt IStream *pIStream,
            /* [out] */ __RPC__out ULONG *pulStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetProceedOnNewConfiguration )( 
            __RPC__in IViewHelper * This);
        
        END_INTERFACE
    } IViewHelperVtbl;

    interface IViewHelper
    {
        CONST_VTBL struct IViewHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IViewHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IViewHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IViewHelper_GetConnectedIDs(This,wszAdaptorName,pulCount,pulID,ulFlags)	\
    ( (This)->lpVtbl -> GetConnectedIDs(This,wszAdaptorName,pulCount,pulID,ulFlags) ) 

#define IViewHelper_GetActiveTopology(This,wszAdaptorName,ulSourceID,pulCount,pulTargetID)	\
    ( (This)->lpVtbl -> GetActiveTopology(This,wszAdaptorName,ulSourceID,pulCount,pulTargetID) ) 

#define IViewHelper_SetActiveTopology(This,wszAdaptorName,ulSourceID,ulCount,pulTargetID)	\
    ( (This)->lpVtbl -> SetActiveTopology(This,wszAdaptorName,ulSourceID,ulCount,pulTargetID) ) 

#define IViewHelper_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#define IViewHelper_SetConfiguration(This,pIStream,pulStatus)	\
    ( (This)->lpVtbl -> SetConfiguration(This,pIStream,pulStatus) ) 

#define IViewHelper_GetProceedOnNewConfiguration(This)	\
    ( (This)->lpVtbl -> GetProceedOnNewConfiguration(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewHelper_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



