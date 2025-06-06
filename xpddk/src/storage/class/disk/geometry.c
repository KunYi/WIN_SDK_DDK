/*++

Copyright (C) Microsoft Corporation, 1991 - 1999

Module Name:

    geometry.c

Abstract:

    SCSI disk class driver - this module contains all the code for generating 
    disk geometries.

Environment:

    kernel mode only

Notes:

Revision History:

--*/


#include "disk.h"
#include "ntddstor.h"

#if defined (_X86_)

DISK_GEOMETRY_SOURCE
DiskUpdateGeometry(
    IN PFUNCTIONAL_DEVICE_EXTENSION DeviceExtension
    );

NTSTATUS
DiskUpdateRemovableGeometry (
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    );

VOID
DiskScanBusDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE BusKey
    );

NTSTATUS
DiskSaveBusDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE TargetKey,
    IN ULONG DiskNumber
    );

NTSTATUS
DiskSaveGeometryDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE HardwareKey
    );

NTSTATUS
DiskGetPortGeometry(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    OUT PDISK_GEOMETRY Geometry
    );

typedef struct _DISK_DETECT_INFO {
    BOOLEAN Initialized;
    ULONG Style;
    ULONG Signature;
    ULONG MbrCheckSum;
    PDEVICE_OBJECT Device;
    CM_INT13_DRIVE_PARAMETER DriveParameters;
} DISK_DETECT_INFO, *PDISK_DETECT_INFO;

//
// Information about the disk geometries collected and saved into the registry 
// by NTDETECT.COM or the system firmware.
//

PDISK_DETECT_INFO DetectInfoList = NULL;
ULONG DetectInfoCount = 0;
ULONG DetectInfoUsedCount = 0;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DiskSaveDetectInfo)
#pragma alloc_text(INIT, DiskScanBusDetectInfo)
#pragma alloc_text(INIT, DiskSaveBusDetectInfo)
#pragma alloc_text(INIT, DiskSaveGeometryDetectInfo)

#pragma alloc_text(PAGE, DiskUpdateGeometry)
#pragma alloc_text(PAGE, DiskUpdateRemovableGeometry)
#pragma alloc_text(PAGE, DiskGetPortGeometry)
#pragma alloc_text(PAGE, DiskGetDetectInfo)
#pragma alloc_text(PAGE, DiskReadSignature)
#endif



NTSTATUS
DiskSaveDetectInfo(
    PDRIVER_OBJECT DriverObject
    )
/*++

Routine Description:

    This routine saves away the firmware information about the disks which has 
    been saved in the registry.  It generates a list (DetectInfoList) which 
    contains the disk geometries, signatures & checksums of all drives which 
    were examined by NtDetect.  This list is later used to assign geometries 
    to disks as they are initialized.

Arguments:

    DriverObject - the driver being initialized.  This is used to get to the 
                   hardware database.
    
Return Value:

    status.
    
--*/        
    
{
    OBJECT_ATTRIBUTES objectAttributes;
    HANDLE hardwareKey;

    UNICODE_STRING unicodeString;
    HANDLE busKey;

    NTSTATUS status;

    PAGED_CODE();

    InitializeObjectAttributes(
        &objectAttributes,
        DriverObject->HardwareDatabase,
        OBJ_CASE_INSENSITIVE,
        NULL,
        NULL);

    //
    // Create the hardware base key.
    //

    status = ZwOpenKey(&hardwareKey, KEY_READ, &objectAttributes);

    if(!NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveDetectInfo: Cannot open hardware data. "
                       "Name: %wZ\n", 
                    DriverObject->HardwareDatabase));
        return status;
    }

    status = DiskSaveGeometryDetectInfo(DriverObject, hardwareKey);

    if(!NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveDetectInfo: Can't query configuration data "
                       "(%#08lx)\n",
                    status));
        ZwClose(hardwareKey);
        return status;
    }

    //
    // Open EISA bus key.
    //

    RtlInitUnicodeString(&unicodeString, L"EisaAdapter");
    InitializeObjectAttributes(&objectAttributes,
                               &unicodeString,
                               OBJ_CASE_INSENSITIVE,
                               hardwareKey,
                               NULL);

    status = ZwOpenKey(&busKey,
                       KEY_READ,
                       &objectAttributes);

    if(NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveDetectInfo: Opened EisaAdapter key\n"));
        DiskScanBusDetectInfo(DriverObject, busKey);
        ZwClose(busKey);
    }

    //
    // Open MultiFunction bus key.
    // 

    RtlInitUnicodeString(&unicodeString, L"MultifunctionAdapter");
    InitializeObjectAttributes(&objectAttributes,
                               &unicodeString,
                               OBJ_CASE_INSENSITIVE,
                               hardwareKey,
                               NULL);

    status = ZwOpenKey(&busKey,
                       KEY_READ,
                       &objectAttributes);

    if(NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveDetectInfo: Opened MultifunctionAdapter key\n"));
        DiskScanBusDetectInfo(DriverObject, busKey);
        ZwClose(busKey);
    }

    ZwClose(hardwareKey);

    return STATUS_SUCCESS;
}


VOID
DiskCleanupDetectInfo(
    IN PDRIVER_OBJECT DriverObject
    )
/*++

Routine Description:
    
    This routine will cleanup the data structure built by DiskSaveDetectInfo.
    
Arguments:

    DriverObject - a pointer to the kernel object for this driver.
    
Return Value:

    none
    
--*/            

{
    if(DetectInfoList != NULL) {
        ExFreePool(DetectInfoList);
        DetectInfoList = NULL;
    }
    return;
}


NTSTATUS
DiskSaveGeometryDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE HardwareKey
    )
{
    UNICODE_STRING unicodeString;
    PKEY_VALUE_FULL_INFORMATION keyData;
    ULONG length;

    PCM_FULL_RESOURCE_DESCRIPTOR fullDescriptor;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR partialDescriptor;

    PCM_INT13_DRIVE_PARAMETER driveParameters;
    ULONG numberOfDrives;

    ULONG i;

    NTSTATUS status;

    PAGED_CODE();

    //
    // Get disk BIOS geometry information.
    //

    RtlInitUnicodeString(&unicodeString, L"Configuration Data");

    keyData = ExAllocatePoolWithTag(PagedPool,
                                    VALUE_BUFFER_SIZE,
                                    DISK_TAG_UPDATE_GEOM);
                                   
    if(keyData == NULL) {
        DebugPrint((1, "DiskSaveGeometryDetectInfo: Can't allocate config "
                       "data buffer\n"));
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    status = ZwQueryValueKey(HardwareKey,
                             &unicodeString,
                             KeyValueFullInformation,
                             keyData,
                             VALUE_BUFFER_SIZE,
                             &length);

    if(!NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveGeometryDetectInfo: Can't query configuration "
                       "data (%#08lx)\n",
                    status));
        ExFreePool(keyData);
        return status;
    }

    //
    // Extract the resource list out of the key data.
    // 

    fullDescriptor = (PCM_FULL_RESOURCE_DESCRIPTOR)
                      (((PUCHAR) keyData) + keyData->DataOffset);
    partialDescriptor = 
        fullDescriptor->PartialResourceList.PartialDescriptors;
    length = partialDescriptor->u.DeviceSpecificData.DataSize;

    if((keyData->DataLength < sizeof(CM_FULL_RESOURCE_DESCRIPTOR)) ||
       (fullDescriptor->PartialResourceList.Count == 0) ||
       (partialDescriptor->Type != CmResourceTypeDeviceSpecific) ||
       (length < sizeof(ULONG))) {

        DebugPrint((1, "DiskSaveGeometryDetectInfo: BIOS header data too small "
                       "or invalid\n"));
        ExFreePool(keyData);
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Point to the BIOS data.  THe BIOS data is located after the first 
    // partial Resource list which should be device specific data.
    //

    {
        PUCHAR buffer = (PUCHAR) keyData;
        buffer += keyData->DataOffset;
        buffer += sizeof(CM_FULL_RESOURCE_DESCRIPTOR);
        driveParameters = (PCM_INT13_DRIVE_PARAMETER) buffer;
    }

    numberOfDrives = length / sizeof(CM_INT13_DRIVE_PARAMETER);

    //
    // Allocate our detect info list now that we know how many entries there 
    // are going to be.  No other routine allocates detect info and this is 
    // done out of DriverEntry so we don't need to synchronize it's creation.
    //

    length = sizeof(DISK_DETECT_INFO) * numberOfDrives;
    DetectInfoList = ExAllocatePoolWithTag(PagedPool,
                                           length,
                                           DISK_TAG_UPDATE_GEOM);

    if(DetectInfoList == NULL) {
        DebugPrint((1, "DiskSaveGeometryDetectInfo: Couldn't allocate %x bytes "
                       "for DetectInfoList\n", 
                    length));

        ExFreePool(keyData);
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    DetectInfoCount = numberOfDrives;

    RtlZeroMemory(DetectInfoList, length);

    //
    // Copy the information out of the key data and into the list we've 
    // allocated.
    //

    for(i = 0; i < numberOfDrives; i++) {
        DetectInfoList[i].DriveParameters = driveParameters[i];
    }

    ExFreePool(keyData);
    return STATUS_SUCCESS;
}


VOID
DiskScanBusDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE BusKey
    )
/*++

Routine Description:

    The routine queries the registry to determine which disks are visible to
    the BIOS.  If a disk is visable to the BIOS then the geometry information
    is updated with the disk's signature and MBR checksum.

Arguments:

    DriverObject - the object for this driver.
    BusKey - handle to the bus key to be enumerated.

Return Value:

    status
    
--*/
{
    ULONG busNumber;

    NTSTATUS status;

    for(busNumber = 0; ; busNumber++) {

        WCHAR buffer[32];
        UNICODE_STRING unicodeString;

        OBJECT_ATTRIBUTES objectAttributes;

        HANDLE spareKey;
        HANDLE adapterKey;

        ULONG adapterNumber;

        DebugPrint((1, "DiskScanBusDetectInfo: Scanning bus %d\n", busNumber));

        //
        // Open controller name key.
        //

        swprintf(buffer, L"%d", busNumber);
        RtlInitUnicodeString(&unicodeString, buffer);

        InitializeObjectAttributes(&objectAttributes,
                                   &unicodeString,
                                   OBJ_CASE_INSENSITIVE,
                                   BusKey,
                                   NULL);

        status = ZwOpenKey(&spareKey, KEY_READ, &objectAttributes);

        if(!NT_SUCCESS(status)) {
            DebugPrint((1, "DiskScanBusDetectInfo: Error %#08lx opening bus "
                           "key %#x\n", 
                        status, busNumber));
            break;
        }

        //
        // Open up a controller ordinal key.
        //

        RtlInitUnicodeString(&unicodeString, L"DiskController");
        InitializeObjectAttributes(&objectAttributes,
                                   &unicodeString,
                                   OBJ_CASE_INSENSITIVE,
                                   spareKey,
                                   NULL);

        status = ZwOpenKey(&adapterKey, KEY_READ, &objectAttributes);
        ZwClose(spareKey);

        if(!NT_SUCCESS(status)) {
            DebugPrint((1, "DiskScanBusDetectInfo: Error %#08lx opening "
                           "DiskController key\n", 
                           status));
            continue;
        }

        for(adapterNumber = 0; ; adapterNumber++) {

            HANDLE diskKey;
            ULONG diskNumber;
            
            //
            // Open disk key.
            //

            DebugPrint((1, "DiskScanBusDetectInfo: Scanning disk key "
                           "%d\\DiskController\\%d\\DiskPeripheral\n",
                           busNumber, adapterNumber));

            swprintf(buffer, L"%d\\DiskPeripheral", adapterNumber);
            RtlInitUnicodeString(&unicodeString, buffer);

            InitializeObjectAttributes(&objectAttributes,
                                       &unicodeString,
                                       OBJ_CASE_INSENSITIVE,
                                       adapterKey,
                                       NULL);

            status = ZwOpenKey(&diskKey, KEY_READ, &objectAttributes);

            if(!NT_SUCCESS(status)) {
                DebugPrint((1, "DiskScanBusDetectInfo: Error %#08lx opening "
                               "disk key\n",
                               status));
                break;
            }

            for(diskNumber = 0; ; diskNumber++) {

                HANDLE targetKey;

                DebugPrint((1, "DiskScanBusDetectInfo: Scanning target key "
                               "%d\\DiskController\\%d\\DiskPeripheral\\%d\n",
                               busNumber, adapterNumber, diskNumber));

                swprintf(buffer, L"%d", diskNumber);
                RtlInitUnicodeString(&unicodeString, buffer);

                InitializeObjectAttributes(&objectAttributes,
                                           &unicodeString,
                                           OBJ_CASE_INSENSITIVE,
                                           diskKey,
                                           NULL);

                status = ZwOpenKey(&targetKey, KEY_READ, &objectAttributes);

                if(!NT_SUCCESS(status)) {
                    DebugPrint((1, "DiskScanBusDetectInfo: Error %#08lx "
                                   "opening target key\n", 
                                status));
                    break;
                }

                status = DiskSaveBusDetectInfo(DriverObject, 
                                               targetKey,
                                               diskNumber);

                ZwClose(targetKey);
            }

            ZwClose(diskKey);
        }
        ZwClose(adapterKey);
    }
    return;
}


NTSTATUS
DiskSaveBusDetectInfo(
    IN PDRIVER_OBJECT DriverObject,
    IN HANDLE TargetKey,
    IN ULONG DiskNumber
    )
/*++

Routine Description:

    This routine will transfer the firmware/ntdetect reported information 
    in the specified target key into the appropriate entry in the 
    DetectInfoList.

Arguments:

    DriverObject - the object for this driver.
    
    TargetKey - the key for the disk being saved.    

    DiskNumber - the ordinal of the entry in the DiskPeripheral tree for this 
                 entry

Return Value:

    status    

--*/
{
    PDISK_DETECT_INFO diskInfo;

    UNICODE_STRING unicodeString;

    PKEY_VALUE_FULL_INFORMATION keyData;
    ULONG length;

    NTSTATUS status;

    PAGED_CODE();

    diskInfo = &(DetectInfoList[DiskNumber]);

    if(diskInfo->Initialized) {

        ASSERT(FALSE);
        DebugPrint((1, "DiskSaveBusDetectInfo: disk entry %#x already has a "
                        "signature of %#08lx and mbr checksum of %#08lx\n", 
                        DiskNumber,
                        diskInfo->Signature,
                        diskInfo->MbrCheckSum));
        return STATUS_UNSUCCESSFUL;
    }

    RtlInitUnicodeString(&unicodeString, L"Identifier");

    keyData = ExAllocatePoolWithTag(PagedPool,
                                    VALUE_BUFFER_SIZE,
                                    DISK_TAG_UPDATE_GEOM);

    if(keyData == NULL) {
        DebugPrint((1, "DiskSaveBusDetectInfo: Couldn't allocate space for "
                       "registry data\n"));
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    //
    // Get disk peripheral identifier.
    //

    status = ZwQueryValueKey(TargetKey,
                             &unicodeString,
                             KeyValueFullInformation,
                             keyData,
                             VALUE_BUFFER_SIZE,
                             &length);

    if(!NT_SUCCESS(status)) {
        DebugPrint((1, "DiskSaveBusDetectInfo: Error %#08lx getting "
                       "Identifier\n",
                    status));
        ExFreePool(keyData);
        return status;

    } else if (keyData->DataLength < 9*sizeof(WCHAR)) {

        //
        // the data is too short to use (we subtract 9 chars in normal path)
        //
        DebugPrint((1, "DiskSaveBusDetectInfo: Saved data was invalid, "
                    "not enough data in registry!\n"));
        ExFreePool(keyData);
        return STATUS_UNSUCCESSFUL;
        
    } else {

        UNICODE_STRING identifier;
        ULONG value;

        //
        // Complete unicode string.
        //
    
        identifier.Buffer = (PWSTR) ((PUCHAR)keyData + keyData->DataOffset);
        identifier.Length = (USHORT) keyData->DataLength;
        identifier.MaximumLength = (USHORT) keyData->DataLength;
    
        //
        // Get the first value out of the identifier - this will be the MBR 
        // checksum.
        //
    
        status = RtlUnicodeStringToInteger(&identifier, 16, &value);
    
        if(!NT_SUCCESS(status)) {
            DebugPrint((1, "DiskSaveBusDetectInfo: Error %#08lx converting "
                           "identifier %wZ into MBR xsum\n", 
                           status,
                           &identifier));
            ExFreePool(keyData);
            return status;
        }
    
        diskInfo->MbrCheckSum = value;
    
        //
        // Shift the string over to get the disk signature
        //
    
        identifier.Buffer += 9;
        identifier.Length -= 9 * sizeof(WCHAR);
        identifier.MaximumLength -= 9 * sizeof(WCHAR);
    
        status = RtlUnicodeStringToInteger(&identifier, 16, &value);
    
        if(!NT_SUCCESS(status)) {
            DebugPrint((1, "DiskSaveBusDetectInfo: Error %#08lx converting "
                           "identifier %wZ into disk signature\n", 
                           status,
                           &identifier));
            ExFreePool(keyData);
            value = 0;
        }

        diskInfo->Signature = value;
    }

    //
    // Here is where we would save away the extended int13 data.
    //

    //
    // Mark this entry as initialized so we can make sure not to do it again.
    //

    diskInfo->Initialized = TRUE;


    return STATUS_SUCCESS;
}


DISK_GEOMETRY_SOURCE
DiskUpdateGeometry(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    )
/*++

Routine Description:

    This routine checks the DetectInfoList saved away during disk driver init
    to see if any geometry information was reported for this drive.  If the 
    geometry data exists (determined by matching non-zero signatures or 
    non-zero MBR checksums) then it will be saved in the RealGeometry member
    of the disk data block.

    ClassReadDriveCapacity MUST be called after calling this routine to update
    the cylinder count based on the size of the disk and the presence of any 
    disk management software.

Arguments:

    DeviceExtension - Supplies a pointer to the device information for disk.

Return Value:

    Inidicates whether the "RealGeometry" in the data block is now valid.

--*/

{
    PDISK_DATA diskData = FdoExtension->CommonExtension.DriverData;

    ULONG i;
    PDISK_DETECT_INFO diskInfo;

    BOOLEAN found = FALSE;

    NTSTATUS status;

    PAGED_CODE();


    ASSERT(FdoExtension->CommonExtension.IsFdo);
    ASSERT((FdoExtension->DeviceObject->Characteristics & FILE_REMOVABLE_MEDIA) == 0);

    //
    // If we've already set a non-default geometry for this drive then there's 
    // no need to try and update again.
    //

    if(diskData->GeometrySource != DiskGeometryUnknown) {
        return diskData->GeometrySource;
    }

    //
    // Scan through the saved detect info to see if we can find a match 
    // for this device.
    //

    for(i = 0; i < DetectInfoCount; i++) {

        ASSERT(DetectInfoList != NULL);

        diskInfo = &(DetectInfoList[i]);

        if((diskData->Mbr.Signature != 0) && 
           (diskData->Mbr.Signature == diskInfo->Signature)) { 
            DebugPrint((1, "DiskUpdateGeometry: found match for signature "
                           "%#08lx\n",
                        diskData->Mbr.Signature));
            found = TRUE;
            break;
        } else if((diskData->Mbr.Signature == 0) && 
                  (diskData->Mbr.MbrCheckSum != 0) &&
                  (diskData->Mbr.MbrCheckSum == diskInfo->MbrCheckSum)) {
            DebugPrint((1, "DiskUpdateGeometry: found match for xsum %#08lx\n",
                        diskData->Mbr.MbrCheckSum));
            found = TRUE;
            break;
        }
    }

    if(found) {

        ULONG cylinders;
        ULONG sectorsPerTrack;
        ULONG tracksPerCylinder;

        ULONG sectors;
        ULONG length;

        //
        // Point to the array of drive parameters.
        //
        
        cylinders = diskInfo->DriveParameters.MaxCylinders + 1;
        sectorsPerTrack = diskInfo->DriveParameters.SectorsPerTrack;
        tracksPerCylinder = diskInfo->DriveParameters.MaxHeads + 1;

        //
        // Since the BIOS may not report the full drive, recalculate the drive
        // size based on the volume size and the BIOS values for tracks per
        // cylinder and sectors per track..
        //
    
        length = tracksPerCylinder * sectorsPerTrack;
    
        if (length == 0) {
    
            //
            // The BIOS information is bogus.
            //
    
            DebugPrint((1, "DiskUpdateGeometry: H (%d) or S(%d) is zero\n",
                        tracksPerCylinder, sectorsPerTrack));
            return FALSE;
        }
    
        //
        // since we are copying the structure RealGeometry here, we should
        // really initialize all the fields, especially since a zero'd
        // BytesPerSector field would cause a trap in xHalReadPartitionTable()
        //

        diskData->RealGeometry = FdoExtension->DiskGeometry;
        
        //
        // Save the geometry information away in the disk data block and 
        // set the bit indicating that we found a valid one.
        //

        diskData->RealGeometry.SectorsPerTrack = sectorsPerTrack;
        diskData->RealGeometry.TracksPerCylinder = tracksPerCylinder;
        diskData->RealGeometry.Cylinders.QuadPart = (LONGLONG)cylinders;

        DebugPrint((1, "DiskUpdateGeometry: BIOS spt %#x, #heads %#x, "
                       "#cylinders %#x\n",
                   sectorsPerTrack, tracksPerCylinder, cylinders));

        diskData->GeometrySource = DiskGeometryFromBios;
        diskInfo->Device = FdoExtension->DeviceObject;

    } else {
    
       DebugPrint((1, "DiskUpdateGeometry: no match found for signature %#08lx\n", diskData->Mbr.Signature));
    }

    if(diskData->GeometrySource == DiskGeometryUnknown) {

        //
        // We couldn't find a geometry from the BIOS.  Check with the port 
        // driver and see if it can provide one.
        //

        status = DiskGetPortGeometry(FdoExtension, &(diskData->RealGeometry));

        if(NT_SUCCESS(status)) {

            //
            // Check the geometry to make sure it's valid.
            //

            if((diskData->RealGeometry.TracksPerCylinder * 
                diskData->RealGeometry.SectorsPerTrack) != 0) {

                diskData->GeometrySource = DiskGeometryFromPort;
                DebugPrint((1, "DiskUpdateGeometry: using Port geometry for disk %#p\n", FdoExtension));
                
                if (diskData->RealGeometry.BytesPerSector == 0) {
                    
                    DebugPrint((0, "DiskDriverReinit: Port driver failed to "
                                "set BytesPerSector in the RealGeometry\n"));
                    diskData->RealGeometry.BytesPerSector =
                        FdoExtension->DiskGeometry.BytesPerSector;
                    if (diskData->RealGeometry.BytesPerSector == 0) {
                        ASSERT(!"BytesPerSector is still zero!");
                    }

                }
            }
        }
    }

    //
    // If we came up with a "real" geometry for this drive then set it in the 
    // device extension.
    //

    if(diskData->GeometrySource != DiskGeometryUnknown) {
        FdoExtension->DiskGeometry = diskData->RealGeometry;

        //
        // Increment the count of used geometry entries.
        //

        InterlockedIncrement(&DetectInfoUsedCount);
    }

    return diskData->GeometrySource;
}


NTSTATUS
DiskUpdateRemovableGeometry (
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    )

/*++

Routine Description:

    This routine updates the geometry of the disk.  It will query the port 
    driver to see if it can provide any geometry info.  If not it will use 
    the current head & sector count.
    
    Based on these values & the capacity of the drive as reported by 
    ClassReadDriveCapacity it will determine a new cylinder count for the 
    device.

Arguments:

    Fdo - Supplies the functional device object whos size needs to be updated.

Return Value:

    Returns the status of the opertion.

--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = &(FdoExtension->CommonExtension);
    PDISK_DATA diskData = commonExtension->DriverData;
    PDISK_GEOMETRY geometry = &(diskData->RealGeometry);

    NTSTATUS status;

    PAGED_CODE();

    ASSERT_FDO(commonExtension->DeviceObject);
    if (FdoExtension->DeviceDescriptor) {
        ASSERT(FdoExtension->DeviceDescriptor->RemovableMedia);
    }
    ASSERT(TEST_FLAG(FdoExtension->DeviceObject->Characteristics,
                     FILE_REMOVABLE_MEDIA));

    //
    // Attempt to determine the disk geometry.  First we'll check with the 
    // port driver to see what it suggests for a value.
    //

    status = DiskGetPortGeometry(FdoExtension, geometry);

    if(NT_SUCCESS(status) && 
       ((geometry->TracksPerCylinder * geometry->SectorsPerTrack) != 0)) {

        FdoExtension->DiskGeometry = (*geometry);
    }

    return status;
}


NTSTATUS
DiskGetPortGeometry(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    OUT PDISK_GEOMETRY Geometry
    )
/*++

Routine Description:

    This routine will query the port driver for disk geometry.  Some port 
    drivers (in particular IDEPORT) may be able to provide geometry for the 
    device.
    
Arguments:

    FdoExtension - the device object for the disk.
    
    Geometry - a structure to save the geometry information into (if any is 
               available)
               
Return Value:
    
    STATUS_SUCCESS if geometry information can be provided or 
    error status indicating why it can't.
    
--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = &(FdoExtension->CommonExtension);
    PIRP irp;
    PIO_STACK_LOCATION irpStack;
    KEVENT event;

    NTSTATUS status;

    PAGED_CODE();

    //
    // Build an irp to send IOCTL_DISK_GET_DRIVE_GEOMETRY to the lower driver.
    //

    irp = IoAllocateIrp(commonExtension->LowerDeviceObject->StackSize, FALSE);

    if(irp == NULL) {
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    irpStack = IoGetNextIrpStackLocation(irp);

    irpStack->MajorFunction = IRP_MJ_DEVICE_CONTROL;

    irpStack->Parameters.DeviceIoControl.IoControlCode = 
        IOCTL_DISK_GET_DRIVE_GEOMETRY;
    irpStack->Parameters.DeviceIoControl.OutputBufferLength = 
        sizeof(DISK_GEOMETRY);

    irp->AssociatedIrp.SystemBuffer = Geometry;

    KeInitializeEvent(&event, SynchronizationEvent, FALSE);

    IoSetCompletionRoutine(irp, 
                           ClassSignalCompletion,
                           &event,
                           TRUE,
                           TRUE,
                           TRUE);

    status = IoCallDriver(commonExtension->LowerDeviceObject, irp);
    KeWaitForSingleObject(&event, Executive, KernelMode, FALSE, NULL);

    ASSERT((status == STATUS_PENDING) || (status == irp->IoStatus.Status));
    status = irp->IoStatus.Status;

    IoFreeIrp(irp);

    return status;
}



NTSTATUS
DiskReadDriveCapacity(
    IN PDEVICE_OBJECT Fdo
    )
/*++

Routine Description:

    This routine is used by disk.sys as a wrapper for the classpnp API 
    ClassReadDriveCapacity.  It will perform some additional operations to 
    attempt to determine drive geometry before it calls the classpnp version 
    of the routine.
    
    For fixed disks this involves calling DiskUpdateGeometry which will check 
    various sources (the BIOS, the port driver) for geometry information.
    
Arguments:

    Fdo - a pointer to the device object to be checked.    

Return Value:

    status of ClassReadDriveCapacity.
    
--*/        

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PDISK_DATA diskData = fdoExtension->CommonExtension.DriverData;
    DISK_GEOMETRY_SOURCE diskGeometrySource = DiskGeometryUnknown;
    NTSTATUS status;

    ASSERT_FDO(Fdo);

    if (TEST_FLAG(Fdo->Characteristics, FILE_REMOVABLE_MEDIA)) {
        DiskUpdateRemovableGeometry(fdoExtension);
    } else {
        diskGeometrySource = DiskUpdateGeometry(fdoExtension);
    }

    status = ClassReadDriveCapacity(Fdo);

    return status;
}



VOID
DiskDriverReinitialization(
    IN PDRIVER_OBJECT DriverObject,
    IN PVOID Nothing,
    IN ULONG Count
    )
/*++

Routine Description:

    This routine will scan through the current list of disks and attempt to 
    match them to any remaining geometry information.  This will only be done 
    on the first call to the routine.

    Note: This routine assumes that the system will not be adding or removing
          devices during this phase of the init process.  This is very likely
          a bad assumption but it greatly simplifies the code.

Arguments:

    DriverObject - a pointer to the object for the disk driver.
    
    Nothing - unused
    
    Count - an indication of how many times this routine has been called.
    
Return Value:

    none

--*/

{
    PDEVICE_OBJECT deviceObject;
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
    PDISK_DATA diskData;

    ULONG unmatchedDiskCount;
    PDEVICE_OBJECT unmatchedDisk = NULL;

    ULONG i;
    PDISK_DETECT_INFO diskInfo = NULL;

    if(Count != 1) {
        DebugPrint((1, "DiskDriverReinitialization: ignoring call %d\n", 
                    Count));
        return;
    }

    //
    // Check to see how many entries in the detect info list have been matched.
    // If there's only one remaining we'll see if we can find a disk to go with
    // it.
    //

    if(DetectInfoCount == 0) {
        DebugPrint((1, "DiskDriverReinitialization: no detect info saved\n"));
        return;
    }

    if((DetectInfoCount - DetectInfoUsedCount) != 1) {
        DebugPrint((1, "DiskDriverReinitialization: %d of %d geometry entries "
                       "used - will not attempt match\n"));
        return;
    }

    //
    // Scan through the list of disks and see if any of them are missing
    // geometry information.  If there is only one such disk we'll try to 
    // match it to the unmatched geometry.
    //
    
    
    //
    // ISSUE-2000/5/24-henrygab - figure out if there's a way to keep
    //                            removals from happening while doing this.
    //

    for(deviceObject = DriverObject->DeviceObject, unmatchedDiskCount = 0;
        deviceObject != NULL;
        deviceObject = deviceObject->NextDevice) {

        //
        // Make sure this is a disk and not a partition.
        //

        fdoExtension = deviceObject->DeviceExtension;
        if(fdoExtension->CommonExtension.IsFdo == FALSE) {
            DebugPrint((1, "DiskDriverReinit: DO %#p is not an FDO\n", 
                           deviceObject));
            continue;
        }

        //
        // If the geometry for this one is already known then skip it.
        //

        diskData = fdoExtension->CommonExtension.DriverData;
        if(diskData->GeometrySource != DiskGeometryUnknown) {
            DebugPrint((1, "DiskDriverReinit: FDO %#p has a geometry\n", 
                           deviceObject));
            continue;
        }

        DebugPrint((1, "DiskDriverReinit: FDO %#p has no geometry\n",
                       deviceObject));

        //
        // Mark this one as using the default.  It's past the time when disk
        // might blunder across the geometry info.  If we set the geometry 
        // from the bios we'll reset this field down below.
        //

        diskData->GeometrySource = DiskGeometryFromDefault;

        //
        // As long as we've only got one unmatched disk we're fine.
        //

        unmatchedDiskCount++;
        if(unmatchedDiskCount > 1) {
            ASSERT(unmatchedDisk != NULL);
            DebugPrint((1, "DiskDriverReinit: FDO %#p also has no geometry\n",
                           unmatchedDisk));
            unmatchedDisk = NULL;
            break;
        }

        unmatchedDisk = deviceObject;
    }

    //
    // If there's more or less than one ungeometried disk then we can't do 
    // anything about the geometry.
    //

    if(unmatchedDiskCount != 1) {
        DebugPrint((1, "DiskDriverReinit: Unable to match geometry\n"));
        return;

    }

    fdoExtension = unmatchedDisk->DeviceExtension;
    diskData = fdoExtension->CommonExtension.DriverData;

    DebugPrint((1, "DiskDriverReinit: Found possible match\n"));

    //
    // Find the geometry which wasn't assigned.
    //

    for(i = 0; i < DetectInfoCount; i++) {
        if(DetectInfoList[i].Device == NULL) {
            diskInfo = &(DetectInfoList[i]);
            break;
        }
    }

    ASSERT(diskInfo != NULL);

    {
        //
        // Save the geometry information away in the disk data block and 
        // set the bit indicating that we found a valid one.
        //

        ULONG cylinders;
        ULONG sectorsPerTrack;
        ULONG tracksPerCylinder;

        ULONG sectors;
        ULONG length;

        //
        // Point to the array of drive parameters.
        //
        
        cylinders = diskInfo->DriveParameters.MaxCylinders + 1;
        sectorsPerTrack = diskInfo->DriveParameters.SectorsPerTrack;
        tracksPerCylinder = diskInfo->DriveParameters.MaxHeads + 1;

        //
        // Since the BIOS may not report the full drive, recalculate the drive
        // size based on the volume size and the BIOS values for tracks per
        // cylinder and sectors per track..
        //
    
        length = tracksPerCylinder * sectorsPerTrack;
    
        if (length == 0) {
    
            //
            // The BIOS information is bogus.
            //
    
            DebugPrint((1, "DiskDriverReinit: H (%d) or S(%d) is zero\n",
                        tracksPerCylinder, sectorsPerTrack));
            return;
        }
    
        //
        // since we are copying the structure RealGeometry here, we should
        // really initialize all the fields, especially since a zero'd
        // BytesPerSector field would cause a trap in xHalReadPartitionTable()
        //
        
        diskData->RealGeometry = fdoExtension->DiskGeometry;
        
        //
        // Save the geometry information away in the disk data block and 
        // set the bit indicating that we found a valid one.
        //
    
        diskData->RealGeometry.SectorsPerTrack = sectorsPerTrack;
        diskData->RealGeometry.TracksPerCylinder = tracksPerCylinder;
        diskData->RealGeometry.Cylinders.QuadPart = (LONGLONG)cylinders;

        DebugPrint((1, "DiskDriverReinit: BIOS spt %#x, #heads %#x, "
                       "#cylinders %#x\n",
                   sectorsPerTrack, tracksPerCylinder, cylinders));

        diskData->GeometrySource = DiskGeometryGuessedFromBios;
        diskInfo->Device = unmatchedDisk;

        //
        // Now copy the geometry over to the fdo extension and call 
        // classpnp to redetermine the disk size and cylinder count.
        //

        fdoExtension->DiskGeometry = diskData->RealGeometry;
        
        //
        // BUGBUG - why not call DiskReadDriveCapacity()?
        //

        ClassReadDriveCapacity(unmatchedDisk);

        if (diskData->RealGeometry.BytesPerSector == 0) {

            //
            // if the BytesPerSector field is set to zero for a disk
            // listed in the bios, then the system will bugcheck in
            // xHalReadPartitionTable().  assert here since it is
            // easier to determine what is happening this way.
            //

            ASSERT(!"RealGeometry not set to non-zero bps\n");
        }
    }

    return;
}


NTSTATUS
DiskGetDetectInfo(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    OUT PDISK_DETECTION_INFO DetectInfo
    )
/*++

Routine Description:

    Get the Int13 information from the BIOS DetectInfoList.

Arguments:

    FdoExtension - Supplies a pointer to the FDO extension that we want to
            obtain the detect information for.

    DetectInfo - A buffer where the detect information will be copied to.

Return Value:

    NTSTATUS code.

--*/
{
    ULONG i;
    BOOLEAN found;
    PDISK_DETECT_INFO diskInfo;
    PDISK_DATA diskData = FdoExtension->CommonExtension.DriverData;

    PAGED_CODE ();

    ASSERT(FdoExtension->CommonExtension.IsFdo);

    //
    // Fail for non-fixed drives.
    //
    
    if (TEST_FLAG (FdoExtension->DeviceObject->Characteristics, FILE_REMOVABLE_MEDIA)) {
        return STATUS_NOT_SUPPORTED;
    }

    //
    // There is no GPT detection info, so fail this.
    //
    
    if (diskData->PartitionStyle == PARTITION_STYLE_GPT) {
        return STATUS_NOT_SUPPORTED;
    }

    for(i = 0; i < DetectInfoCount; i++) {

        
        ASSERT(DetectInfoList != NULL);

        diskInfo = &(DetectInfoList[i]);

        if((diskData->Mbr.Signature != 0) && 
           (diskData->Mbr.Signature == diskInfo->Signature)) { 
            DebugPrint((1, "DiskGetDetectInfo: found match for signature "
                           "%#08lx\n",
                        diskData->Mbr.Signature));
            found = TRUE;
            break;
        } else if((diskData->Mbr.Signature == 0) && 
                  (diskData->Mbr.MbrCheckSum != 0) &&
                  (diskData->Mbr.MbrCheckSum == diskInfo->MbrCheckSum)) {
            DebugPrint((1, "DiskGetDetectInfo: found match for xsum %#08lx\n",
                        diskData->Mbr.MbrCheckSum));
            found = TRUE;
            break;
        }
    }

    if ( found ) {
        DetectInfo->DetectionType = DetectInt13;
        DetectInfo->Int13.DriveSelect = diskInfo->DriveParameters.DriveSelect;
        DetectInfo->Int13.MaxCylinders = diskInfo->DriveParameters.MaxCylinders;
        DetectInfo->Int13.SectorsPerTrack = diskInfo->DriveParameters.SectorsPerTrack;
        DetectInfo->Int13.MaxHeads = diskInfo->DriveParameters.MaxHeads;
        DetectInfo->Int13.NumberDrives = diskInfo->DriveParameters.NumberDrives;
        RtlZeroMemory (&DetectInfo->ExInt13, sizeof (DetectInfo->ExInt13));
    }

    return (found ? STATUS_SUCCESS : STATUS_UNSUCCESSFUL);
}


NTSTATUS
DiskReadSignature(
    IN PDEVICE_OBJECT Fdo
    )

/*++

Routine Description:

    Read the disks signature from the drive. The signature can be either
    a MBR signature or a GPT/EFI signature.

    The low-level signature reading is done by IoReadDiskSignature().

Arguments:

    Fdo - Pointer to the FDO of a disk to read the signature for.
    
Return Value:

    NTSTATUS code.

--*/


{
    NTSTATUS Status;
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PDISK_DATA diskData = fdoExtension->CommonExtension.DriverData;
    DISK_SIGNATURE Signature;

    PAGED_CODE ();
    
    Status = IoReadDiskSignature (Fdo,
                                  fdoExtension->DiskGeometry.BytesPerSector,
                                  &Signature);

    if (!NT_SUCCESS (Status)) {
        return Status;
    }
    
    if (Signature.PartitionStyle == PARTITION_STYLE_GPT) {
        diskData->PartitionStyle = PARTITION_STYLE_GPT;
        diskData->Efi.DiskId = Signature.Gpt.DiskId;
    } else if (Signature.PartitionStyle == PARTITION_STYLE_MBR) {
        diskData->PartitionStyle = PARTITION_STYLE_MBR;
        diskData->Mbr.Signature = Signature.Mbr.Signature;
        diskData->Mbr.MbrCheckSum = Signature.Mbr.CheckSum;
    } else {
        ASSERT (FALSE);
        Status = STATUS_UNSUCCESSFUL;
    }

    return Status;
}

#endif // defined(_X86_)


