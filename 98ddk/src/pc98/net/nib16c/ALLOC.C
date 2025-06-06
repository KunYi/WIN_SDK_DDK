/*------------------------------------------------------------------------
 Copyright (c) 1990-1994  Microsoft Corporation

 COPYRIGHT(C) NEC CORPORATION 1994-1998 NEC CONFIDENTIAL AND PROPRIETARY
------------------------------------------------------------------------*/
/*++

Module Name:

    alloc.c

Abstract:

    This file contains the code for allocating and freeing adapter
    resources for the National Semiconductor SONIC Ethernet controller.
    This driver conforms to the NDIS 3.0/3.1 interface.

Environment:

    Kernel Mode - Or whatever is the equivalent.

--*/

#include <ndis.h>


#include <efilter.h>
#include <sonichrd.h>
#include <sonicsft.h>

#ifdef NDIS_WIN
    #pragma LCODE
#endif


STATIC
PNDIS_BUFFER
AllocateFlushBuffer(
    IN PSONIC_ADAPTER Adapter,
    IN PVOID VirtualAddress,
    IN ULONG Length
    );


//
// Use the alloc_text pragma to specify the driver initialization routines
// (they can be paged out).
//

#ifdef ALLOC_PRAGMA
#pragma alloc_text(init,AllocateAdapterMemory)
#pragma alloc_text(init,AllocateFlushBuffer)
#endif



STATIC
PNDIS_BUFFER
AllocateFlushBuffer(
    IN PSONIC_ADAPTER Adapter,
    IN PVOID VirtualAddress,
    IN ULONG Length
    )

/*++

Routine Description:

    Allocates an NDIS_BUFFER for the specified address and length.
    This function is intended to create NDIS_BUFFERs for flushing.

Arguments:

    Adapter - The adapter the buffer is for. It must have a
        FlushBufferPoolHandle that points to a valid buffer pool.

    VirtualAddress - A pointer to the buffer to describe.

    Length - The length of the buffer.

Return Value:

    The NDIS_BUFFER if one was allocated.
    NULL if an NDIS_BUFFER could not be allocated.

--*/

{
    PNDIS_BUFFER ReturnBuffer;
    NDIS_STATUS Status;

    NdisAllocateBuffer(
        &Status,
        &ReturnBuffer,
        Adapter->FlushBufferPoolHandle,
        VirtualAddress,
        Length
        );

    if (Status != NDIS_STATUS_SUCCESS) {
        ReturnBuffer = (PNDIS_BUFFER)NULL;
    }


    return ReturnBuffer;
}

extern
BOOLEAN
AllocateAdapterMemory(
    IN PSONIC_ADAPTER Adapter
    )

/*++

Routine Description:

    This routine allocates memory for:

    - Transmit ring entries

    - Receive ring entries

    - Receive buffers

    - Adapter buffers for use if user transmit buffers don't meet hardware
      contraints

    - Structures to map transmit ring entries back to the packets.

Arguments:

    Adapter - The adapter to allocate memory for.

Return Value:

    Returns FALSE if some memory needed for the adapter could not
    be allocated. It does NOT call DeleteAdapterMemory in this
    case.

--*/

{

    //
    // Pointer to a transmit ring entry.  Used while initializing
    // the TDA.
    //
    PSONIC_TRANSMIT_DESCRIPTOR CurrentTransmitDescriptor;

    //
    // Pointer to a receive buffer. Used while allocated the
    // RBAs.
    //
    PVOID * CurrentReceiveBuffer;

    //
    // Pointer to a receive descriptor. Used while initialing
    // the RDA.
    //
    PSONIC_RECEIVE_DESCRIPTOR CurrentReceiveDescriptor;

    //
    // Used for determining physical addresses.
    //
    SONIC_PHYSICAL_ADDRESS SonicPhysicalAdr;

    //
    // Used for NDIS allocation routines that return an NDIS_PHYSICAL_ADDRESS
    //
    NDIS_PHYSICAL_ADDRESS NdisPhysicalAdr;

    //
    // Simple iteration variable.
    //
    UINT i;

    //
    // Used to flush buffers that only need to be flushed once.
    //
    PNDIS_BUFFER FlushBuffer;

    //
    // The size of the buffer pool needed.
    //
    UINT PoolBuffersNeeded;

    //
    // Holds the result of calls to SONIC_ALLOC_MEMORY
    //
    NDIS_STATUS AllocStatus;

    //
    // We need some NDIS_BUFFERs to describe memory that we
    // allocate (generally either to flush the buffer, or
    // because we need its physical address). To do this
    // we need a buffer pool, so we have to determine how
    // many buffers we need.
    //
    PoolBuffersNeeded =
        1 +                                 // for CamDescriptorArea
        1 +                                 // for ReceiveResourceArea
        1 +                                 // for BlankBuffer
        SONIC_NUMBER_OF_SMALL_BUFFERS +
        SONIC_NUMBER_OF_MEDIUM_BUFFERS +
        SONIC_NUMBER_OF_LARGE_BUFFERS;

    NdisAllocateBufferPool(
        &AllocStatus,
        &Adapter->FlushBufferPoolHandle,
        PoolBuffersNeeded
        );

    if (AllocStatus != NDIS_STATUS_SUCCESS) {
       return FALSE;
    }



    //
    // Allocate the transmit ring descriptors.
    //

    SonicAllocLocalMemory(
        Adapter,
        sizeof(SONIC_TRANSMIT_DESCRIPTOR)*
            Adapter->NumberOfTransmitDescriptors,
        FALSE,                                           // non-cached
        (PVOID *)&Adapter->TransmitDescriptorArea,
        &Adapter->TransmitDescriptorAreaPhysical
        );

    if (Adapter->TransmitDescriptorArea == NULL) {
        return FALSE;
    }

    if (NdisGetPhysicalAddressHigh(Adapter->TransmitDescriptorAreaPhysical) != 0) {
        return FALSE;
    }



    //
    // Clean the above memory
    //

    SonicMemoryBankset(Adapter,
        NdisGetPhysicalAddressLow(Adapter->TransmitDescriptorAreaPhysical));

    SONIC_ZERO_MEMORY(
        Adapter->TransmitDescriptorArea,
        (sizeof(SONIC_TRANSMIT_DESCRIPTOR)*Adapter->NumberOfTransmitDescriptors)
        );


    //
    // We have the transmit ring descriptors.  Initialize the Link
    // fields.
    //

    for (
        i = 0, CurrentTransmitDescriptor = Adapter->TransmitDescriptorArea;
        i < Adapter->NumberOfTransmitDescriptors;
        i++,CurrentTransmitDescriptor++
        ) {

        SonicPhysicalAdr = NdisGetPhysicalAddressLow(Adapter->TransmitDescriptorAreaPhysical) +
                             (i * sizeof(SONIC_TRANSMIT_DESCRIPTOR));

        if (i == 0) {

            Adapter->TransmitDescriptorArea[Adapter->NumberOfTransmitDescriptors-1].Link = SonicPhysicalAdr;

        } else {

            (CurrentTransmitDescriptor-1)->Link = SonicPhysicalAdr;

        }

    }


    //
    // Allocate the ring to packet structure.
    //

    SONIC_ALLOC_MEMORY(
        &AllocStatus,
        &Adapter->DescriptorToPacket,
        sizeof(SONIC_DESCRIPTOR_TO_PACKET)
            *Adapter->NumberOfTransmitDescriptors
        );

    if (AllocStatus != NDIS_STATUS_SUCCESS) {
        return FALSE;
    }


    //
    // We have to do this now. The PrevLinkPointer field is used
    // to point to where the Link field of the previous transmit
    // descriptor is; it is normally set when the previous
    // transmit descriptor is filled. For the very first packet
    // transmitted there will have been no previous transmit
    // descriptor, so we fill it in ourselves. We use the
    // Link field of the last transmit descriptor (the actual
    // location used doesn't really matter, as long as it is
    // a valid address).
    //

    Adapter->DescriptorToPacket->PrevLinkPointer =
                    &(Adapter->TransmitDescriptorArea[
                        Adapter->NumberOfTransmitDescriptors-1].Link);


    //
    // Allocate the receive resource area and the
    // CAM descriptor area. These are allocated together
    // since they must have the same high 16 bits in
    // their addresses.
    //

    SonicAllocLocalMemory(
        Adapter,
        (sizeof(SONIC_RECEIVE_RESOURCE)*Adapter->NumberOfReceiveBuffers) +
            sizeof(SONIC_CAM_DESCRIPTOR_AREA),
        TRUE,                                              // cached
        (PVOID *)&Adapter->ReceiveResourceArea,
        &Adapter->ReceiveResourceAreaPhysical
        );


    if (Adapter->ReceiveResourceArea == NULL) {
        return FALSE;
    }

    if (NdisGetPhysicalAddressHigh(Adapter->ReceiveResourceAreaPhysical) != 0) {
        return FALSE;
    }


    //
    // The CAM Descriptor Area is immediately after the RRA.
    //

    Adapter->CamDescriptorArea = (PSONIC_CAM_DESCRIPTOR_AREA)
            (Adapter->ReceiveResourceArea + Adapter->NumberOfReceiveBuffers);

    Adapter->CamDescriptorAreaPhysical =
        NdisGetPhysicalAddressLow(Adapter->ReceiveResourceAreaPhysical) +
            ((PUCHAR)Adapter->CamDescriptorArea -
             (PUCHAR)Adapter->ReceiveResourceArea);


    //
    // Allocate the NDIS_BUFFER to flush the CAM Descriptor Area.
    //
    SonicMemoryBankset(Adapter,
        NdisGetPhysicalAddressLow(Adapter->ReceiveResourceAreaPhysical));

    Adapter->CamDescriptorAreaFlushBuffer = AllocateFlushBuffer(
                                            Adapter,
                                            Adapter->CamDescriptorArea,
                                            sizeof(SONIC_CAM_DESCRIPTOR_AREA)
                                            );

    if (!Adapter->CamDescriptorAreaFlushBuffer) {
        return FALSE;
    }

    SONIC_ZERO_MEMORY(
        Adapter->CamDescriptorArea,
        sizeof(SONIC_CAM_DESCRIPTOR_AREA)
        );

    SONIC_FLUSH_WRITE_BUFFER(Adapter->CamDescriptorAreaFlushBuffer);

    //
    // Allocate the array to hold pointers to the RBAs.
    //

    SONIC_ALLOC_MEMORY(
        &AllocStatus,
        &Adapter->ReceiveBufferArea,
        sizeof(PVOID) * Adapter->NumberOfReceiveBuffers
        );

    if (AllocStatus != NDIS_STATUS_SUCCESS) {
        return FALSE;
    }

    //
    // We have the receive buffer pointers. Allocate the buffer
    // for each entry and zero them.
    //
    // For each receive buffer, the Physical address and length
    // will be in Adapter->ReceiveResourceArea[i], while the
    // virtual address will be in Adapter->ReceiveBufferArea[i].
    //

    for (
        i = 0, CurrentReceiveBuffer = Adapter->ReceiveBufferArea;
        i < Adapter->NumberOfReceiveBuffers;
        i++,CurrentReceiveBuffer++
        ) {

        SonicAllocLocalMemory(
            Adapter,
            SONIC_SIZE_OF_RECEIVE_BUFFERS,
            FALSE,                                // non-cached
            CurrentReceiveBuffer,
            &NdisPhysicalAdr
        );

        if (*CurrentReceiveBuffer == NULL) {
            return FALSE;
        }

        if (NdisGetPhysicalAddressHigh(NdisPhysicalAdr) != 0) {
            return FALSE;
        }

        SonicMemoryBankset(Adapter,NdisGetPhysicalAddressLow(NdisPhysicalAdr));

        SONIC_ZERO_MEMORY(
            *CurrentReceiveBuffer,
            SONIC_SIZE_OF_RECEIVE_BUFFERS
            );

        SonicMemoryBankset(Adapter,
                NdisGetPhysicalAddressLow(Adapter->ReceiveResourceAreaPhysical));

        SONIC_SET_RECEIVE_RESOURCE_ADDRESS(
            &Adapter->ReceiveResourceArea[i],
            NdisGetPhysicalAddressLow(NdisPhysicalAdr)
            );

        SONIC_SET_RECEIVE_RESOURCE_LENGTH(
            &Adapter->ReceiveResourceArea[i],
            SONIC_SIZE_OF_RECEIVE_BUFFERS
            );


    }

    //
    // The Receive Resource Area is set up, we can flush
    // it now since it does not change.
    //

    FlushBuffer = AllocateFlushBuffer(
            Adapter,
            (PVOID)Adapter->ReceiveResourceArea,
            (sizeof(SONIC_RECEIVE_RESOURCE)*Adapter->NumberOfReceiveBuffers)
        );

    if (!FlushBuffer) {
        return FALSE;
    }

    SONIC_FLUSH_WRITE_BUFFER(FlushBuffer);

    NdisFreeBuffer(FlushBuffer);

    //
    // Allocate memory to hold the receive descriptor pointers.
    //

    SonicAllocLocalMemory(
        Adapter,
        sizeof(SONIC_RECEIVE_DESCRIPTOR) *
            Adapter->NumberOfReceiveDescriptors,
        FALSE,                                             // non-cached
        (PVOID *)&Adapter->ReceiveDescriptorArea,
        &Adapter->ReceiveDescriptorAreaPhysical
        );


    if (Adapter->ReceiveDescriptorArea == NULL) {

        return FALSE;

    }

    if (NdisGetPhysicalAddressHigh(Adapter->ReceiveDescriptorAreaPhysical) != 0) {

        return FALSE;

    }



    //
    // Clean the above memory
    //

    SonicMemoryBankset(Adapter,
        NdisGetPhysicalAddressLow(Adapter->ReceiveDescriptorAreaPhysical));

    SONIC_ZERO_MEMORY(
        Adapter->ReceiveDescriptorArea,
        (sizeof(SONIC_RECEIVE_DESCRIPTOR)*Adapter->NumberOfReceiveDescriptors)
        );


    //
    // Now set up the Link fields in the receive descriptors.
    //

    for (
        i = 0, CurrentReceiveDescriptor = Adapter->ReceiveDescriptorArea;
        i < Adapter->NumberOfReceiveDescriptors;
        i++,CurrentReceiveDescriptor++
        ) {

        //
        // belongs to SONIC.
        //

        CurrentReceiveDescriptor->InUse = SONIC_OWNED_BY_SONIC;

        SonicPhysicalAdr = NdisGetPhysicalAddressLow(Adapter->ReceiveDescriptorAreaPhysical) +
                        (i * sizeof(SONIC_RECEIVE_DESCRIPTOR));

        if (i == 0) {

            Adapter->ReceiveDescriptorArea[
                Adapter->NumberOfReceiveDescriptors-1].Link =
                        SonicPhysicalAdr | SONIC_END_OF_LIST;

        } else {

            Adapter->ReceiveDescriptorArea[i-1].Link = SonicPhysicalAdr;

        }

    }


    //
    // Allocate the array of buffer descriptors.
    //

    SONIC_ALLOC_MEMORY(
        &AllocStatus,
        &Adapter->SonicBuffers,
        sizeof(SONIC_BUFFER_DESCRIPTOR)*
           (SONIC_NUMBER_OF_SMALL_BUFFERS +
            SONIC_NUMBER_OF_MEDIUM_BUFFERS +
            SONIC_NUMBER_OF_LARGE_BUFFERS)
        );

    if (AllocStatus != NDIS_STATUS_SUCCESS) {
        return FALSE;
    }

    //
    // Zero the memory of all the descriptors so that we can
    // know which buffers wern't allocated incase we can't allocate
    // them all.
    //
    SONIC_ZERO_MEMORY(
        Adapter->SonicBuffers,
        sizeof(SONIC_BUFFER_DESCRIPTOR)*
         (SONIC_NUMBER_OF_SMALL_BUFFERS +
          SONIC_NUMBER_OF_MEDIUM_BUFFERS +
          SONIC_NUMBER_OF_LARGE_BUFFERS)
        );


    //
    // Allocate space for the small sonic buffers and fill in the
    // buffer descriptors.
    //

    Adapter->SonicBufferListHeads[0] = -1;
    Adapter->SonicBufferListHeads[1] = 0;

    SonicAllocLocalMemory(
        Adapter,
        SONIC_SMALL_BUFFER_SIZE * SONIC_NUMBER_OF_SMALL_BUFFERS,
        TRUE,                 // cached
        &Adapter->SmallSonicBuffers,
        &NdisPhysicalAdr
        );

    if (NdisGetPhysicalAddressHigh(NdisPhysicalAdr) != 0) {
        return FALSE;
    }


    if (Adapter->SmallSonicBuffers == NULL) {
        return FALSE;
    }

    SonicMemoryBankset(Adapter,NdisGetPhysicalAddressLow(NdisPhysicalAdr));

    for (
        i = 0;
        i < SONIC_NUMBER_OF_SMALL_BUFFERS;
        i++
        ) {

        Adapter->SonicBuffers[i].VirtualSonicBuffer = (PVOID)
            ((PUCHAR)Adapter->SmallSonicBuffers +
            (i * SONIC_SMALL_BUFFER_SIZE));

        NdisSetPhysicalAddressHigh(
            Adapter->SonicBuffers[i].PhysicalSonicBuffer,
            0);

        NdisSetPhysicalAddressLow(
            Adapter->SonicBuffers[i].PhysicalSonicBuffer,
            NdisGetPhysicalAddressLow(NdisPhysicalAdr) +
            (i * SONIC_SMALL_BUFFER_SIZE));

        Adapter->SonicBuffers[i].FlushBuffer =
            AllocateFlushBuffer(
                Adapter,
                Adapter->SonicBuffers[i].VirtualSonicBuffer,
                SONIC_SMALL_BUFFER_SIZE
            );

        if (!Adapter->SonicBuffers[i].FlushBuffer) {
            return FALSE;
        }

        Adapter->SonicBuffers[i].Next = i+1;

    }

    //
    // Make sure that the last buffer correctly terminates the free list.
    //

    Adapter->SonicBuffers[i-1].Next = -1;

    //
    // Do the medium buffers now.
    //

    Adapter->SonicBufferListHeads[2] = i;

    SonicAllocLocalMemory(
        Adapter,
        SONIC_MEDIUM_BUFFER_SIZE * SONIC_NUMBER_OF_MEDIUM_BUFFERS,
        TRUE,                 // cached
        &Adapter->MediumSonicBuffers,
        &NdisPhysicalAdr
        );


    if (Adapter->MediumSonicBuffers == NULL) {
        return FALSE;
    }

    if (NdisGetPhysicalAddressHigh(NdisPhysicalAdr) != 0) {
        return FALSE;
    }

    SonicMemoryBankset(Adapter,NdisGetPhysicalAddressLow(NdisPhysicalAdr));


    for (
        ;
        i < SONIC_NUMBER_OF_SMALL_BUFFERS + SONIC_NUMBER_OF_MEDIUM_BUFFERS;
        i++
        ) {

        Adapter->SonicBuffers[i].VirtualSonicBuffer = (PVOID)
            ((PUCHAR)Adapter->MediumSonicBuffers +
            ((i - SONIC_NUMBER_OF_SMALL_BUFFERS) * SONIC_MEDIUM_BUFFER_SIZE));

        NdisSetPhysicalAddressHigh(
            Adapter->SonicBuffers[i].PhysicalSonicBuffer,
            0);

        NdisSetPhysicalAddressLow(
            Adapter->SonicBuffers[i].PhysicalSonicBuffer,
            NdisGetPhysicalAddressLow(NdisPhysicalAdr) +
            ((i - SONIC_NUMBER_OF_SMALL_BUFFERS) * SONIC_MEDIUM_BUFFER_SIZE));


        Adapter->SonicBuffers[i].FlushBuffer =
            AllocateFlushBuffer(
                Adapter,
                Adapter->SonicBuffers[i].VirtualSonicBuffer,
                SONIC_MEDIUM_BUFFER_SIZE
            );

        if (!Adapter->SonicBuffers[i].FlushBuffer) {
            return FALSE;
        }


        Adapter->SonicBuffers[i].Next = i+1;

    }

    //
    // Make sure that the last buffer correctly terminates the free list.
    //

    Adapter->SonicBuffers[i-1].Next = -1;

    //
    // Now do the large buffers; note that they have one
    // Physical address per buffer.
    //

    Adapter->SonicBufferListHeads[3] = i;

    for (
        ;
        i < SONIC_NUMBER_OF_SMALL_BUFFERS +
            SONIC_NUMBER_OF_MEDIUM_BUFFERS +
            SONIC_NUMBER_OF_LARGE_BUFFERS;
        i++
        ) {


        SonicAllocLocalMemory(
            Adapter,
            SONIC_LARGE_BUFFER_SIZE,
            TRUE,                // cached
            (PVOID *)&Adapter->SonicBuffers[i].VirtualSonicBuffer,
            &Adapter->SonicBuffers[i].PhysicalSonicBuffer
        );

        if (Adapter->SonicBuffers[i].VirtualSonicBuffer == NULL) {
            return FALSE;
        }

        if (NdisGetPhysicalAddressHigh(Adapter->SonicBuffers[i].PhysicalSonicBuffer) != 0) {
            return FALSE;
        }


        SonicMemoryBankset(Adapter,
                NdisGetPhysicalAddressLow(Adapter->SonicBuffers[i].
                PhysicalSonicBuffer));

        Adapter->SonicBuffers[i].FlushBuffer =
            AllocateFlushBuffer(
                Adapter,
                Adapter->SonicBuffers[i].VirtualSonicBuffer,
                SONIC_LARGE_BUFFER_SIZE
            );

        if (!Adapter->SonicBuffers[i].FlushBuffer) {
            return FALSE;
        }


        Adapter->SonicBuffers[i].Next = i+1;

    }

    //
    // Make sure that the last buffer correctly terminates the free list.
    //

    Adapter->SonicBuffers[i-1].Next = -1;


    //
    // Allocate the BlankBuffer
    //

    SonicAllocLocalMemory(
        Adapter,
        SONIC_SMALL_BUFFER_SIZE,
        TRUE,                                       // cached
        (PVOID *)&Adapter->BlankBuffer,
        &Adapter->BlankBufferAddress
        );

    if (Adapter->BlankBuffer == NULL) {
        return FALSE;
    }

    if (NdisGetPhysicalAddressHigh(Adapter->BlankBufferAddress) != 0) {
        return FALSE;
    }

    SonicMemoryBankset(Adapter,
            NdisGetPhysicalAddressLow(Adapter->BlankBufferAddress));

    for (i=0; i < SONIC_SMALL_BUFFER_SIZE; i++) {

        Adapter->BlankBuffer[i] = ' ';

    }


    //
    // Flush the blank buffer now, it never changes.
    //

    FlushBuffer = AllocateFlushBuffer(
                Adapter,
                Adapter->BlankBuffer,
                SONIC_SMALL_BUFFER_SIZE
            );

    if (!FlushBuffer) {
        return FALSE;
    }

    SONIC_FLUSH_WRITE_BUFFER(FlushBuffer);

    //
    // We are done with the FlushBuffer.
    //

    NdisFreeBuffer(FlushBuffer);


    return TRUE;

}

extern
VOID
DeleteAdapterMemory(
    IN PSONIC_ADAPTER Adapter
    )

/*++

Routine Description:

    This routine deallocates memory for:

    - Transmit ring entries

    - Receive ring entries

    - Receive buffers

    - Adapter buffers for use if user transmit buffers don't meet hardware
      contraints

    - Structures to map transmit ring entries back to the packets.

Arguments:

    Adapter - The adapter to deallocate memory for.

Return Value:

    None.

--*/

{

// Already freed at the end of the function.
//    if (Adapter->FlushBufferPoolHandle) {
//
//        NdisFreeBufferPool(Adapter->FlushBufferPoolHandle);
//
//    }

    if (Adapter->TransmitDescriptorArea) {

        SonicFreeLocalMemory(
            Adapter,
            sizeof(SONIC_TRANSMIT_DESCRIPTOR)*
                Adapter->NumberOfTransmitDescriptors,
            FALSE,
            Adapter->TransmitDescriptorArea,
            NdisGetPhysicalAddressLow(Adapter->TransmitDescriptorAreaPhysical)
        );

    }

    if (Adapter->CamDescriptorAreaFlushBuffer) {

        NdisFreeBuffer(Adapter->CamDescriptorAreaFlushBuffer);

    }

    if (Adapter->ReceiveBufferArea) {

        UINT i;
        NDIS_PHYSICAL_ADDRESS PhysicalAddr;

        for (
            i = 0;
            i < Adapter->NumberOfReceiveBuffers;
            i++
            ) {

            if (Adapter->ReceiveBufferArea[i]) {

                NdisSetPhysicalAddressHigh(PhysicalAddr, 0);
                NdisSetPhysicalAddressLow(
                    PhysicalAddr,
                    SONIC_GET_RECEIVE_RESOURCE_ADDRESS(&Adapter->ReceiveResourceArea[i]));

                SonicFreeLocalMemory(
                    Adapter,
                    SONIC_SIZE_OF_RECEIVE_BUFFERS,
                    FALSE,
                    Adapter->ReceiveBufferArea[i],
                    NdisGetPhysicalAddressLow(PhysicalAddr)
                );

            } else {

                break;

            }

        }

        SONIC_FREE_MEMORY(Adapter->ReceiveBufferArea,
            sizeof(PVOID) * Adapter->NumberOfReceiveBuffers);

    }

    if (Adapter->ReceiveResourceArea) {

        SonicFreeLocalMemory(
            Adapter,
            (sizeof(SONIC_RECEIVE_RESOURCE)*Adapter->NumberOfReceiveBuffers) +
                sizeof(SONIC_CAM_DESCRIPTOR_AREA),
            TRUE,
            Adapter->ReceiveResourceArea,
            NdisGetPhysicalAddressLow(Adapter->ReceiveResourceAreaPhysical)
        );

    }

    if (Adapter->ReceiveDescriptorArea) {

        SonicFreeLocalMemory(
            Adapter,
            sizeof(SONIC_RECEIVE_DESCRIPTOR) *
                Adapter->NumberOfReceiveDescriptors,
            FALSE,
            Adapter->ReceiveDescriptorArea,
            NdisGetPhysicalAddressLow(Adapter->ReceiveDescriptorAreaPhysical)
        );

    }

    if (Adapter->DescriptorToPacket) {

        SONIC_FREE_MEMORY(Adapter->DescriptorToPacket,
            sizeof(SONIC_DESCRIPTOR_TO_PACKET)
            *Adapter->NumberOfTransmitDescriptors);

    }


    if (Adapter->SmallSonicBuffers) {

        SonicFreeLocalMemory(
            Adapter,
            SONIC_SMALL_BUFFER_SIZE * SONIC_NUMBER_OF_SMALL_BUFFERS,
            TRUE,
            Adapter->SmallSonicBuffers,
            NdisGetPhysicalAddressLow(Adapter->SonicBuffers[0].PhysicalSonicBuffer)
        );

    }

    if (Adapter->MediumSonicBuffers) {

        SonicFreeLocalMemory(
            Adapter,
            SONIC_MEDIUM_BUFFER_SIZE * SONIC_NUMBER_OF_MEDIUM_BUFFERS,
            TRUE,
            Adapter->MediumSonicBuffers,
            NdisGetPhysicalAddressLow(Adapter->SonicBuffers[SONIC_NUMBER_OF_SMALL_BUFFERS].PhysicalSonicBuffer)
        );

    }

    if (Adapter->SonicBuffers) {

        UINT i;

        //
        // First free the large buffers.
        //

        for (
            i = SONIC_NUMBER_OF_SMALL_BUFFERS +
                SONIC_NUMBER_OF_MEDIUM_BUFFERS;
            i < SONIC_NUMBER_OF_SMALL_BUFFERS +
                SONIC_NUMBER_OF_MEDIUM_BUFFERS +
                SONIC_NUMBER_OF_LARGE_BUFFERS;
            i++) {

            if (Adapter->SonicBuffers[i].VirtualSonicBuffer) {

                SonicFreeLocalMemory(
                    Adapter,
                    SONIC_LARGE_BUFFER_SIZE,
                    TRUE,
                    Adapter->SonicBuffers[i].VirtualSonicBuffer,
                    NdisGetPhysicalAddressLow(Adapter->SonicBuffers[i].PhysicalSonicBuffer)
                );

            } else {

                break;

            }

        }

        //
        // Now free the flush buffers.
        //

        for (
            i = 0;
            i < SONIC_NUMBER_OF_SMALL_BUFFERS +
                SONIC_NUMBER_OF_MEDIUM_BUFFERS +
                SONIC_NUMBER_OF_LARGE_BUFFERS;
            i++) {

            if (Adapter->SonicBuffers[i].FlushBuffer) {
                NdisFreeBuffer(Adapter->SonicBuffers[i].FlushBuffer);
            }

        }

        SONIC_FREE_MEMORY(Adapter->SonicBuffers,
            sizeof(SONIC_BUFFER_DESCRIPTOR)*
              (SONIC_NUMBER_OF_SMALL_BUFFERS +
               SONIC_NUMBER_OF_MEDIUM_BUFFERS +
               SONIC_NUMBER_OF_LARGE_BUFFERS)
            );

    }


    if (Adapter->BlankBuffer) {

        SonicFreeLocalMemory(
            Adapter,
            SONIC_SMALL_BUFFER_SIZE,
            TRUE,
            Adapter->BlankBuffer,
            NdisGetPhysicalAddressLow(Adapter->BlankBufferAddress)
        );

    }


    if (Adapter->FlushBufferPoolHandle) {

        NdisFreeBufferPool(Adapter->FlushBufferPoolHandle);

    }

}
