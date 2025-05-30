/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/* This file is a subset of the files: sdv_wdm.h, sdv_ntddk.h,
   sdv_ntifs.h, sdv_csq and sdv_wdmsec.h.  It is used when we compile
   the slic rules, so that no matter whether they are stated in term
   of function foo or function sdv_foo, they will work correctly.
*/

#define ExAcquireFastMutex sdv_ExAcquireFastMutex
#define ExAllocatePool sdv_ExAllocatePool
#define ExAllocatePoolWithTag sdv_ExAllocatePoolWithTag
#define ExAllocatePoolWithQuota sdv_ExAllocatePoolWithQuota
#define ExAllocatePoolWithQuotaTag sdv_ExAllocatePoolWithQuotaTag
#define ExFreePool sdv_ExFreePool
#define ExInitializeFastMutex sdv_ExInitializeFastMutex
#define ExInterlockedInsertHeadList sdv_ExInterlockedInsertHeadList
#define ExInterlockedInsertTailList sdv_ExInterlockedInsertTailList
#define ExInterlockedPushEntryList sdv_ExInterlockedPushEntryList
#define ExReleaseFastMutex sdv_ExReleaseFastMutex
#define ExTryToAcquireFastMutex sdv_ExTryToAcquireFastMutex
#define HalQuerySystemInformation sdv_HalQuerySystemInformation
#define InitializeObjectAttributes sdv_InitializeObjectAttributes
#define InterlockedDecrement sdv_InterlockedDecrement
#define InterlockedIncrement sdv_InterlockedIncrement
#define IoAcquireRemoveLock sdv_IoAcquireRemoveLock
#define IoAdjustPagingPathCount sdv_IoAdjustPagingPathCount
#define IoAllocateAdapterChannel sdv_IoAllocateAdapterChannel
#define IoAssignArcName sdv_IoAssignArcName
#define IoCallDriver sdv_IoCallDriver
#define IoCompleteRequest sdv_IoCompleteRequest
#define IoCopyCurrentIrpStackLocationToNext sdv_IoCopyCurrentIrpStackLocationToNext
#define IoCreateDeviceSecure sdv_IoCreateDeviceSecure
#define IoCsqInitialize sdv_IoCsqInitialize
#define IoCsqInitializeEx sdv_IoCsqInitializeEx
#define IoCsqInsertIrp sdv_IoCsqInsertIrp
#define IoCsqInsertIrpEx sdv_IoCsqInsertIrpEx
#define IoCsqRemoveIrp sdv_IoCsqRemoveIrp
#define IoCsqRemoveNextIrp sdv_IoCsqRemoveNextIrp
#define IoDeassignArcName sdv_IoDeassignArcName
#define IoFlushAdapterBuffers sdv_IoFlushAdapterBuffers
#define IoFreeAdapterChannel sdv_IoFreeAdapterChannel
#define IoFreeMapRegisters sdv_IoFreeMapRegisters
#define IoGetCurrentIrpStackLocation sdv_IoGetCurrentIrpStackLocation
#define IoGetFunctionCodeFromCtlCode sdv_IoGetFunctionCodeFromCtlCode
#define IoGetNextIrpStackLocation sdv_IoGetNextIrpStackLocation
#define IoGetRemainingStackSize sdv_IoGetRemainingStackSize
#define IoInitializeDpcRequest sdv_IoInitializeDpcRequest
#define IoInitializeRemoveLock sdv_IoInitializeRemoveLock
#define IoIsErrorUserInduced sdv_IoIsErrorUserInduced
#define IoMapTransfer sdv_IoMapTransfer
#define IoMarkIrpPending sdv_IoMarkIrpPending
#define IoReleaseRemoveLock sdv_IoReleaseRemoveLock
#define IoReleaseRemoveLockAndWait sdv_IoReleaseRemoveLockAndWait
#define IoRequestDpc sdv_IoRequestDpc
#define IoSetCancelRoutine sdv_IoSetCancelRoutine
#define IoSetCompletionRoutine sdv_IoSetCompletionRoutine
#define IoSetCompletionRoutineEx sdv_IoSetCompletionRoutineEx
#define IoSetNextIrpStackLocation sdv_IoSetNextIrpStackLocation
#define IoSizeOfIrp sdv_IoSizeOfIrp
#define IoSizeofWorkItem sdv_IoSizeofWorkItem
#define IoSkipCurrentIrpStackLocation sdv_IoSkipCurrentIrpStackLocation
#define IoWMIDeviceObjectToProviderId sdv_IoWMIDeviceObjectToProviderId
#define KeAcquireSpinLock sdv_KeAcquireSpinLock
#define KeAcquireSpinLockAtDpcLevel sdv_KeAcquireSpinLockAtDpcLevel
#define KeEnterCriticalRegion sdv_KeEnterCriticalRegion
#define KeFlushIoBuffers sdv_KeFlushIoBuffers
#define KeGetCurrentIrql sdv_KeGetCurrentIrql
#define KeLeaveCriticalRegion sdv_KeLeaveCriticalRegion
#define KeLowerIrql sdv_KeLowerIrql
#define KeRaiseIrql sdv_KeRaiseIrql
#define KeRaiseIrqlToDpcLevel sdv_KeRaiseIrqlToDpcLevel
#define KeRaiseIrqlToSynchLevel sdv_KeRaiseIrqlToSynchLevel
#define KeReleaseSpinLock sdv_KeReleaseSpinLock
#define KeReleaseSpinLockFromDpcLevel sdv_KeReleaseSpinLockFromDpcLevel
#define KeWaitForMutexObject sdv_KeWaitForMutexObject
#define KeWaitForSingleObject sdv_KeWaitForSingleObject
#define KeWaitForMultipleObjects sdv_KeWaitForMultipleObjects
#define MmGetSystemAddressForMdl sdv_MmGetSystemAddressForMdl
#define MmGetSystemAddressForMdlSafe sdv_MmGetSystemAddressForMdlSafe
#define MmLockPagableCodeSection sdv_MmLockPagableCodeSection
#define ObDereferenceObject sdv_ObDereferenceObject
#define ObReferenceObject sdv_ObReferenceObject
#define PoCallDriver sdv_PoCallDriver
#define RtlMoveMemory sdv_RtlMoveMemory
#define KeTryToAcquireSpinLockAtDpcLevel sdv_KeTryToAcquireSpinLockAtDpcLevel
#define ExReleaseResourceLite sdv_ExReleaseResourceLite
