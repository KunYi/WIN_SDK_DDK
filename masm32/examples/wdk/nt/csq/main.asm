.386p
.model flat, stdcall
option casemap : none
 
include c:\masm32\include\w2k\hal.inc
include c:\masm32\include\w2k\ntstatus.inc
include c:\masm32\include\w2k\ntddk.inc
include c:\masm32\include\w2k\ntoskrnl.inc
include c:\masm32\include\w2k\ntddkbd.inc
include c:\masm32\include\wxp\csq.inc
include c:\masm32\Macros\Strings.mac

includelib c:\masm32\lib\w2k\hal.lib
includelib c:\masm32\lib\w2k\ntoskrnl.lib
includelib c:\masm32\lib\wxp\i386\csq.lib
 
public DriverEntry
 
MyDeviceExtension struct
    dpc KDPC <>
    csq IO_CSQ <>
    timer KTIMER <>
    queue LIST_ENTRY <>
    locker KSPIN_LOCK <>
    pNextDev PDEVICE_OBJECT ?
MyDeviceExtension ends
 
IOCTL_QUEUE   equ CTL_CODE(FILE_DEVICE_UNKNOWN, 800h, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PROCESS equ CTL_CODE(FILE_DEVICE_UNKNOWN, 801h, METHOD_BUFFERED, FILE_ANY_ACCESS)
 
.const
MSG_QUEUE   byte "IOCTL_QUEUE",0
MSG_PROCESS byte "IOCTL_PROCESS",0
 
.code
CsqInsertIrp proc uses esi ebx ecx pCsqInfo : PIO_CSQ, pIrp : PIRP
    invoke DbgPrint, $CTA0("CsqInsertIrp")
     
    ; CONTAINING_RECORD 
    mov eax, pCsqInfo
    sub eax, MyDeviceExtension.csq
    mov esi, eax
    lea ebx, (MyDeviceExtension ptr [esi]).queue
    mov ecx, pIrp
    lea ecx, (_IRP ptr [ecx]).Tail.Overlay.ListEntry
    InsertTailList ebx, ecx
    ret
CsqInsertIrp endp
 
CsqRemoveIrp proc pCsqInfo : PIO_CSQ, pIrp : PIRP
    invoke DbgPrint, $CTA0("CsqRemoveIrp")

    mov eax, pIrp
    lea eax, (_IRP ptr [eax]).Tail.Overlay.ListEntry
    RemoveEntryList eax
    ret
CsqRemoveIrp endp
 
CsqCompleteCanceledIrp proc pCsqInfo : PIO_CSQ, pIrp : PIRP
    invoke DbgPrint, $CTA0("CsqCompleteCanceledIrp")
     
    mov eax, pIrp
    mov (_IRP ptr [eax]).IoStatus.Status, STATUS_CANCELLED
    and (_IRP ptr [eax]).IoStatus.Information, 0
    fastcall IofCompleteRequest, eax, IO_NO_INCREMENT
    ret
CsqCompleteCanceledIrp endp
 
CsqPeekNextIrp proc uses esi ebx pCsqInfo : PIO_CSQ, pIrp : PIRP, pPeekContext : PVOID
    local nextIrp : PTR _IRP
    local listHead : PTR LIST_ENTRY
    local nextEntry : PTR LIST_ENTRY
    local irpStack : PIO_STACK_LOCATION
     
    invoke DbgPrint, $CTA0("CsqPeekNextIrp")
    mov nextIrp, NULL
     
    ; CONTAINING_RECORD 
    mov eax, pCsqInfo
    sub eax, MyDeviceExtension.csq
    mov esi, eax
    lea eax, (MyDeviceExtension ptr [esi]).queue
    mov listHead, eax
     
    mov eax, pIrp
    .if eax == NULL
        mov eax, listHead
        push (LIST_ENTRY ptr [eax]).Flink
        pop nextEntry 
    .elseif
        mov eax, pIrp
        push (_IRP ptr [eax]).Tail.Overlay.ListEntry.Flink
        pop nextEntry 
    .endif
     
    mov eax, nextEntry
    mov ebx, listHead
    .while eax != ebx
        ; nextIrp = CONTAINING_RECORD(nextEntry, IRP, Tail.Overlay.ListEntry)
        mov eax, nextEntry
        sub eax, _IRP.Tail.Overlay.ListEntry
        mov nextIrp, eax
 
        IoGetCurrentIrpStackLocation nextIrp
        mov irpStack, eax
         
        mov eax, pPeekContext
        .if eax == NULL
            .break
        .endif

        mov eax, irpStack
        mov eax, (IO_STACK_LOCATION ptr [eax]).FileObject
        mov ebx, pPeekContext
        .if eax == ebx
            .break
        .endif

        mov nextIrp, NULL
        mov eax, nextEntry
        mov eax, (LIST_ENTRY ptr [eax]).Flink
        mov nextEntry, eax
         
        mov eax, nextEntry
        mov ebx, listHead
    .endw
    mov eax, nextIrp
    ret
CsqPeekNextIrp endp
 
CsqAcquireLock proc uses esi ecx pCsqInfo : PIO_CSQ, pIrql : PKIRQL
    invoke DbgPrint, $CTA0("CsqAcquireLock")
     
    ; CONTAINING_RECORD 
    mov eax, pCsqInfo
    sub eax, MyDeviceExtension.csq
    mov esi, eax
    lea ecx, (MyDeviceExtension ptr [esi]).locker
    fastcall KfAcquireSpinLock, ecx
    mov ecx, pIrql
    mov [ecx], al
    ret
CsqAcquireLock endp
 
CsqReleaseLock proc uses esi ecx edx pCsqInfo : PIO_CSQ, Irql : KIRQL
    ; CONTAINING_RECORD 
    mov eax, pCsqInfo
    sub eax, MyDeviceExtension.csq
    mov esi, eax
    lea ecx, (MyDeviceExtension PTR [esi]).locker

    mov dl, Irql
    .if dl == DISPATCH_LEVEL
        fastcall KefReleaseSpinLockFromDpcLevel, ecx
        push eax
        invoke DbgPrint, $CTA0("CsqReleaseLock at DPC level\n")
        pop eax
    .else
        and edx, 0ffh
        fastcall KfReleaseSpinLock, ecx, edx
        push eax
        invoke DbgPrint, $CTA0("CsqReleaseLock at Passive level\n")
        pop eax
    .endif
    ret
CsqReleaseLock endp
 
OnTimer proc uses esi edi ebx pDpc : PKDPC, pContext : PVOID, pArg1 : PVOID, PArg2 : PVOID
    mov eax, pContext
    mov esi, (DEVICE_OBJECT ptr [eax]).DeviceExtension
    lea edi, (MyDeviceExtension ptr [esi]).queue

    IsListEmpty edi
    .if eax == TRUE
        invoke KeCancelTimer, addr (MyDeviceExtension ptr [esi]).timer
        invoke DbgPrint, $CTA0("Finish")
    .else
        RemoveHeadList edi
     
        ; CONTAINING_RECORD 
        sub eax, _IRP.Tail.Overlay.ListEntry
        mov bl, (_IRP PTR [eax]).Cancel
 
        .if bl != TRUE
            mov (_IRP PTR [eax]).IoStatus.Status, STATUS_SUCCESS
            and (_IRP PTR [eax]).IoStatus.Information, 0
            fastcall IofCompleteRequest, eax, IO_NO_INCREMENT
            mov eax, STATUS_SUCCESS
            invoke DbgPrint, $CTA0("Complete Irp")
        .else
            mov (_IRP PTR [eax]).CancelRoutine, NULL
            mov (_IRP PTR [eax]).IoStatus.Status, STATUS_CANCELLED
            and (_IRP PTR [eax]).IoStatus.Information, 0
            fastcall IofCompleteRequest, eax, IO_NO_INCREMENT
            mov eax, STATUS_CANCELLED
            invoke DbgPrint, $CTA0("Cancel Irp")
        .endif
    .endif
    ret
OnTimer endp
 
IrpOpenClose proc pMyDevie : PDEVICE_OBJECT, pIrp : PIRP
    IoGetCurrentIrpStackLocation pIrp
    movzx eax, (IO_STACK_LOCATION ptr [eax]).MajorFunction

    .if eax == IRP_MJ_CREATE
        invoke DbgPrint, $CTA0("IRP_MJ_CREATE")
    .elseif eax == IRP_MJ_CLOSE
        invoke DbgPrint, $CTA0("IRP_MJ_CLOSE")
    .endif
 
    mov eax, pIrp
    and (_IRP ptr [eax]).IoStatus.Information, 0
    mov (_IRP ptr [eax]).IoStatus.Status, STATUS_SUCCESS
    fastcall IofCompleteRequest, pIrp, IO_NO_INCREMENT
    mov eax, STATUS_SUCCESS
    ret
IrpOpenClose endp
 
IrpIOCTL proc uses esi ebx pMyDevice : PDEVICE_OBJECT, pIrp : PIRP
    local period : LARGE_INTEGER
 
    mov eax, pMyDevice
    push (DEVICE_OBJECT ptr [eax]).DeviceExtension
    pop esi
 
    IoGetCurrentIrpStackLocation pIrp
    mov eax, (IO_STACK_LOCATION ptr [eax]).Parameters.DeviceIoControl.IoControlCode
    .if eax == IOCTL_QUEUE
        invoke DbgPrint, offset MSG_QUEUE
         
        lea ebx, (MyDeviceExtension ptr [esi]).csq
        invoke IoCsqInsertIrp, ebx, pIrp, NULL
        mov eax, STATUS_PENDING
        ret
    .elseif eax == IOCTL_PROCESS
        invoke DbgPrint, offset MSG_PROCESS

        or period.HighPart, -1
        mov period.LowPart, -10000000
        invoke KeSetTimerEx, addr (MyDeviceExtension ptr [esi]).timer, period.LowPart, period.HighPart, 1000, addr (MyDeviceExtension ptr [esi]).dpc
    .endif
 
    mov eax, pIrp
    mov (_IRP ptr [eax]).IoStatus.Status, STATUS_SUCCESS
    and (_IRP ptr [eax]).IoStatus.Information, 0
    fastcall IofCompleteRequest, pIrp, IO_NO_INCREMENT
    mov eax, STATUS_SUCCESS
    ret
IrpIOCTL endp
 
Unload proc pMyDriver : PDRIVER_OBJECT
    local szSymName : UNICODE_STRING

    invoke RtlInitUnicodeString, addr szSymName, $CTW0("\\DosDevices\\MyDriver")
    invoke IoDeleteSymbolicLink, addr szSymName
                        
    mov eax, pMyDriver
    invoke IoDeleteDevice, (DRIVER_OBJECT ptr [eax]).DeviceObject
    ret
Unload endp
         
DriverEntry proc pMyDriver : PDRIVER_OBJECT, pMyRegistry : PUNICODE_STRING
    local pMyDevice : PDEVICE_OBJECT
    local szDevName : UNICODE_STRING
    local szSymName : UNICODE_STRING
             
    mov eax, pMyDriver
    mov (DRIVER_OBJECT ptr [eax]).MajorFunction[IRP_MJ_CREATE * (sizeof PVOID)], offset IrpOpenClose
    mov (DRIVER_OBJECT ptr [eax]).MajorFunction[IRP_MJ_CLOSE    * (sizeof PVOID)], offset IrpOpenClose
    mov (DRIVER_OBJECT ptr [eax]).MajorFunction[IRP_MJ_DEVICE_CONTROL * (sizeof PVOID)], offset IrpIOCTL
    mov (DRIVER_OBJECT ptr [eax]).DriverUnload, offset Unload
             
    invoke RtlInitUnicodeString, addr szDevName, $CTW0("\\Device\\MyDriver")
    invoke RtlInitUnicodeString, addr szSymName, $CTW0("\\DosDevices\\MyDriver")

    invoke IoCreateDevice, pMyDriver, sizeof MyDeviceExtension, addr szDevName, FILE_DEVICE_UNKNOWN, 0, FALSE, addr pMyDevice
    .if eax == STATUS_SUCCESS
        mov eax, pMyDevice
        or (DEVICE_OBJECT ptr [eax]).Flags, DO_BUFFERED_IO
        and (DEVICE_OBJECT ptr [eax]).Flags, not DO_DEVICE_INITIALIZING
             
        mov eax, pMyDevice
        mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
        lea eax, (MyDeviceExtension ptr [eax]).queue
        InitializeListHead eax
 
        mov eax, pMyDevice
        mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
        lea eax, (MyDeviceExtension ptr [eax]).locker
        invoke KeInitializeSpinLock, eax
 
        mov eax, pMyDevice
        mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
        invoke KeInitializeTimer, addr (MyDeviceExtension ptr [eax]).timer
 
        mov eax, pMyDevice
        mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
        invoke KeInitializeDpc, addr (MyDeviceExtension ptr [eax]).dpc, offset OnTimer, pMyDevice
 
        mov eax, pMyDevice
        mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
        lea eax, (MyDeviceExtension ptr [eax]).csq
        invoke IoCsqInitialize, eax, offset CsqInsertIrp, offset CsqRemoveIrp, offset CsqPeekNextIrp, offset CsqAcquireLock, offset CsqReleaseLock, offset CsqCompleteCanceledIrp
        invoke IoCreateSymbolicLink, addr szSymName, addr szDevName
    .endif
    ret
DriverEntry endp
end DriverEntry
.end
