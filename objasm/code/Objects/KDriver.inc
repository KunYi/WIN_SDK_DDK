;;
;; Purpose: Implement NuMega DriverWorks
;; Website: https://steward-fu.github.io/website/index.htm
;;

    .data
pMyDriverInst PKDriver NULL

Object KDriver, KDriverID, Primer
    RedefineMethod Done
    RedefineMethod Init

    StaticMethod DriverInit, PDRIVER_OBJECT, PUNICODE_STRING
    StaticMethod DriverObject
    StaticMethod DriverInstance

    VirtualAbstract AddDevice, PDEVICE_OBJECT
    VirtualAbstract DriverEntry, PUNICODE_STRING
    VirtualAbstract DriverIrpDispatch, PIRP

    VirtualMethod Unload
    VirtualMethod SetDeviceInstance, PKDevice
    VirtualMethod SetUpDispatchCalls

    DefineVariable m_pMyDriver, PDRIVER_OBJECT, NULL
    DefineVariable m_pMyDeviceInst, PKDevice, NULL
ObjectEnd

Method KDriver.Init, uses esi
    D $OfsCStr("KDriver.Init(this:0x%x)"), pSelf

    push pSelf
    pop pMyDriverInst
MethodEnd

Method KDriver.Done, uses esi
    D $OfsCStr("KDriver.Done(this:0x%x)"), pSelf

    SetObject esi
    Destroy [esi].m_pMyDeviceInst
MethodEnd

Method KDriver.DriverInstance, uses esi
    D $OfsCStr("KDevice.DriverInstance()")

    mov eax, pMyDriverInst
MethodEnd

Method KDriver.DriverObject, uses esi
    D $OfsCStr("KDevice.DriverObject()")

    SetObject esi
    mov eax, [esi].m_pMyDriver
MethodEnd

Method KDriver.SetUpDispatchCalls, uses esi
    D $OfsCStr("KDriver.SetUpDispatchCalls()")

    SetObject esi
    mov eax, [esi].m_pMyDriver
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_PNP    * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_CREATE * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_READ   * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_WRITE  * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_CLOSE  * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).MajorFunction[IRP_MJ_DEVICE_CONTROL * (sizeof PVOID)], offset DriverIrpDispatch
    mov (DRIVER_OBJECT PTR [eax]).DriverUnload, offset UnloadDispatch
    mov eax, (DRIVER_OBJECT PTR [eax]).DriverExtension

    if WDK_TYPE eq WDK_WDM
        mov (DRIVER_EXTENSION PTR [eax]).AddDevice, offset AddDeviceDispatch
    endif
MethodEnd

Method KDriver.DriverInit, uses esi, pMyDriver : PDRIVER_OBJECT, pMyRegistry : PUNICODE_STRING
    D $OfsCStr("KDriver.DriverInit(MyDriver:0x%x)"), pMyDriver

    SetObject esi, KDriver, pMyDriverInst
    push pMyDriver
    pop [esi].m_pMyDriver
    OCall esi.SetUpDispatchCalls
    OCall esi.DriverEntry, pMyRegistry
MethodEnd

Method KDriver.SetDeviceInstance, uses esi, pMyDeviceInst : PKDevice
    D $OfsCStr("KDriver.SetDeviceInstance(0x%x)"), pMyDeviceInst

    SetObject esi
    push pMyDeviceInst
    pop [esi].m_pMyDeviceInst
MethodEnd

Method KDriver.Unload, uses esi
    D $OfsCStr("KDriver.Unload")
MethodEnd

AddDeviceDispatch proc uses esi, pMyDriver : PDRIVER_OBJECT, pPhyDevice : PDEVICE_OBJECT
    D $OfsCStr("AddDeviceDispatch()")

    OCall pMyDriverInst::KDriver.AddDevice, pPhyDevice
    OCall pMyDriverInst::KDriver.SetDeviceInstance, eax

    mov eax, pMyDriver
    mov eax, (DRIVER_OBJECT ptr [eax]).DeviceObject
    and (DEVICE_OBJECT ptr [eax]).Flags, not DO_DEVICE_INITIALIZING
    mov eax, STATUS_SUCCESS
    ret
AddDeviceDispatch endp

DriverIrpDispatch proc uses esi, pMyDevice : PDEVICE_OBJECT, pMyIrp : PIRP
    D $OfsCStr("DriverIrpDispatch()")

    OCall pMyDriverInst::KDriver.DriverIrpDispatch, pMyIrp
    ret
DriverIrpDispatch endp

UnloadDispatch proc uses esi, pMyDriver : PDRIVER_OBJECT
    D $OfsCStr("UnloadDispatch()")

    OCall pMyDriverInst::KDriver.Unload
    Destroy pMyDriverInst
    ret
UnloadDispatch endp
