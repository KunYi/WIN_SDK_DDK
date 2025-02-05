unit main;
 
interface
uses
    DDDK;
     
const
    DEV_NAME = '\Device\MyDriver';
    SYM_NAME = '\DosDevices\MyDriver';

    METHOD_BUFFERED = 0;
    METHOD_IN_DIRECT = 1;
    METHOD_OUT_DIRECT = 2;
    METHOD_NEITHER = 3;
    FILE_ANY_ACCESS = 0;
    FILE_DEVICE_UNKNOWN = $22;

    IOCTL_GET = (FILE_DEVICE_UNKNOWN shl 16) or (FILE_ANY_ACCESS shl 14) or ($800 shl 2) or (METHOD_NEITHER);
    IOCTL_SET = (FILE_DEVICE_UNKNOWN shl 16) or (FILE_ANY_ACCESS shl 14) or ($801 shl 2) or (METHOD_NEITHER);
 
function __DriverEntry(pMyDriver : PDRIVER_OBJECT; pMyRegistry : PUNICODE_STRING) : NTSTATUS; stdcall;
 
implementation
var
    szBuffer : array[0..255] of char;
     
procedure IrpFileCreate(myDevice : WDFDEVICE; myRequest : WDFREQUEST; myFileObject : WDFFILEOBJECT); stdcall;
begin
    DbgPrint('IRP_MJ_CREATE', []);
    WdfRequestComplete(myRequest, STATUS_SUCCESS);
end;
 
procedure IrpFileClose(myFileObject : WDFFILEOBJECT); stdcall;
begin
    DbgPrint('IRP_MJ_CLOSE', []);
end;
 
procedure IrpIOCTL(myQueue : WDFQUEUE; myRequest : WDFREQUEST; myOutLen : ULONG; myInLen : ULONG; myCode : ULONG); stdcall;
var
    len : ULONG;
    buf : Pointer;
    mem : WDFMEMORY;
 
begin
    if myCode = IOCTL_SET then begin
        DbgPrint('IOCTL_SET', []);
        WdfRequestRetrieveUnsafeUserInputBuffer(myRequest, myInLen, @buf, @len);
        WdfRequestProbeAndLockUserBufferForRead(myRequest, buf, len, @mem);
        buf := WdfMemoryGetBuffer(mem, Nil);
        memcpy(@szBuffer, buf, myInLen);
        DbgPrint('Buffer: %s, Length:%d', [@szBuffer, myInLen]);
        WdfRequestSetInformation(myRequest, myInLen);
    end else if myCode = IOCTL_GET then begin
        DbgPrint('IOCTL_GET', []);
        WdfRequestRetrieveUnsafeUserOutputBuffer(myRequest, myOutLen, @buf, @len);
        WdfRequestProbeAndLockUserBufferForWrite(myRequest, buf, len, @mem);
        buf := WdfMemoryGetBuffer(mem, Nil);
        memcpy(buf, @szBuffer, myOutLen);
        len := strlen(@szBuffer);
        WdfRequestSetInformation(myRequest, len);
    end;
    WdfRequestComplete(myRequest, STATUS_SUCCESS);
end;
 
function AddDevice(pMyDriver : WDFDRIVER; pMyDeviceInit : PWDFDEVICE_INIT) : NTSTATUS; stdcall;
var
    device : WDFDEVICE;
    io_cfg : WDF_IO_QUEUE_CONFIG;
    file_cfg : WDF_FILEOBJECT_CONFIG;
    szDevName : UNICODE_STRING;
    szSymName : UNICODE_STRING;
 
begin
    WdfDeviceInitSetIoType(pMyDeviceInit, WdfDeviceIoBuffered);
    WDF_FILEOBJECT_CONFIG_INIT(@file_cfg, @IrpFileCreate, @IrpFileClose, Nil);
    WdfDeviceInitSetFileObjectConfig(pMyDeviceInit, @file_cfg, WDF_NO_OBJECT_ATTRIBUTES);
     
    RtlInitUnicodeString(@szDevName, DEV_NAME);
    RtlInitUnicodeString(@szSymName, SYM_NAME);
    WdfDeviceInitAssignName(pMyDeviceInit, @szDevName);
    WdfDeviceCreate(@pMyDeviceInit, WDF_NO_OBJECT_ATTRIBUTES, @device);
    WdfDeviceCreateSymbolicLink(device, @szSymName);
     
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(@io_cfg, WdfIoQueueDispatchSequential);
    io_cfg.EvtIoDeviceControl := @IrpIOCTL;
    Result := WdfIoQueueCreate(device, @io_cfg, WDF_NO_OBJECT_ATTRIBUTES, WDF_NO_HANDLE);
end;
 
function __DriverEntry(pMyDriver : PDRIVER_OBJECT; pMyRegistry : PUNICODE_STRING) : NTSTATUS; stdcall;
var
    config : WDF_DRIVER_CONFIG;

begin
    WDF_DRIVER_CONFIG_INIT(@config, AddDevice);
    WdfDriverCreate(pMyDriver, pMyRegistry, WDF_NO_OBJECT_ATTRIBUTES, @config, WDF_NO_HANDLE);
    Result := STATUS_SUCCESS;
end;
end.
