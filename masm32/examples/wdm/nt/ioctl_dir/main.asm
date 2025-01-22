.386p
.model flat, stdcall
option casemap:none
    
include c:\masm32\include\w2k\ntstatus.inc
include c:\masm32\include\w2k\ntddk.inc
include c:\masm32\include\w2k\ntoskrnl.inc
include c:\masm32\include\w2k\ntddkbd.inc
include c:\masm32\include\wxp\wdm.inc
include c:\masm32\Macros\Strings.mac

includelib c:\masm32\lib\wxp\i386\ntoskrnl.lib
     
public DriverEntry
    
MyDeviceExtension struct
    szBuffer byte 255 dup(?)
    pNextDev PDEVICE_OBJECT ?
MyDeviceExtension ends
 
IOCTL_GET equ CTL_CODE(FILE_DEVICE_UNKNOWN, 800h, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)
IOCTL_SET equ CTL_CODE(FILE_DEVICE_UNKNOWN, 801h, METHOD_IN_DIRECT, FILE_ANY_ACCESS)
    
.const
MSG_GET byte "IOCTL_GET",0
MSG_SET byte "IOCTL_SET",0
 
.code
IrpOpenClose proc pMyDevice : PDEVICE_OBJECT, pIrp : PIRP
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
 
IrpIOCTL proc uses esi edi pMyDevice : PDEVICE_OBJECT, pIrp : PIRP
    local len: dword
 
    and len, 0
    mov eax, pMyDevice
    mov eax, (DEVICE_OBJECT ptr [eax]).DeviceExtension
    lea edi, (MyDeviceExtension ptr [eax]).szBuffer
 
    IoGetCurrentIrpStackLocation pIrp
    mov eax, (IO_STACK_LOCATION ptr [eax]).Parameters.DeviceIoControl.IoControlCode
    .if eax == IOCTL_GET
        invoke DbgPrint, offset MSG_GET
    
        mov eax, pIrp
        MmGetSystemAddressForMdlSafe (_IRP ptr [eax]).MdlAddress, LowPagePriority
        mov esi, eax

        invoke strcpy, esi, edi
        invoke strlen, edi
        mov len, eax
    .elseif eax == IOCTL_SET
        invoke DbgPrint, offset MSG_SET
    
        IoGetCurrentIrpStackLocation pIrp
        push (IO_STACK_LOCATION ptr [eax]).Parameters.DeviceIoControl.InputBufferLength 
        pop len

        mov eax, pIrp
        push (_IRP ptr [eax]).AssociatedIrp.SystemBuffer
        pop esi

        invoke memcpy, edi, esi, len
        invoke DbgPrint, $CTA0("Buffer: %s, Length: %d"), edi, len
    .endif
 
    mov eax, pIrp
    mov (_IRP ptr [eax]).IoStatus.Status, STATUS_SUCCESS
    push len
    pop (_IRP ptr [eax]).IoStatus.Information
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
        invoke IoCreateSymbolicLink, addr szSymName, addr szDevName
    .endif
    ret
DriverEntry endp
end DriverEntry
.end
