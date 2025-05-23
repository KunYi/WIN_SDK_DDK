/*------------------------------------------------------------------------
 Copyright (c) 1990-1994  Microsoft Corporation

 COPYRIGHT(C) NEC CORPORATION 1994-1998 NEC CONFIDENTIAL AND PROPRIETARY
------------------------------------------------------------------------*/
/*++

Module Name:

    transfer.c

Abstract:

    This file contains the code to implement the MacTransferData
    API for the NDIS 3.0/3.1 interface.

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

extern
NDIS_STATUS
SonicTransferData(
    IN NDIS_HANDLE MacBindingHandle,
    IN NDIS_HANDLE MacReceiveContext,
    IN UINT ByteOffset,
    IN UINT BytesToTransfer,
    OUT PNDIS_PACKET Packet,
    OUT PUINT BytesTransferred
    )

/*++

Routine Description:

    A protocol calls the SonicTransferData request (indirectly via
    NdisTransferData) from within its Receive event handler
    to instruct the MAC to copy the contents of the received packet
    a specified paqcket buffer.

Arguments:

    MacBindingHandle - The context value returned by the MAC when the
    adapter was opened.  In reality this is a pointer to SONIC_OPEN.

    MacReceiveContext - The context value passed by the MAC on its call
    to NdisIndicateReceive.  The MAC can use this value to determine
    which packet, on which adapter, is being received.

    ByteOffset - An unsigned integer specifying the offset within the
    received packet at which the copy is to begin.  If the entire packet
    is to be copied, ByteOffset must be zero.

    BytesToTransfer - An unsigned integer specifying the number of bytes
    to copy.  It is legal to transfer zero bytes; this has no effect.  If
    the sum of ByteOffset and BytesToTransfer is greater than the size
    of the received packet, then the remainder of the packet (starting from
    ByteOffset) is transferred, and the trailing portion of the receive
    buffer is not modified.

    Packet - A pointer to a descriptor for the packet storage into which
    the MAC is to copy the received packet.

    BytesTransfered - A pointer to an unsigned integer.  The MAC writes
    the actual number of bytes transferred into this location.  This value
    is not valid if the return status is STATUS_PENDING.

Return Value:

    The function value is the status of the operation.


--*/

{

    PSONIC_ADAPTER Adapter;

    NDIS_STATUS StatusToReturn;

    Adapter = PSONIC_ADAPTER_FROM_BINDING_HANDLE(MacBindingHandle);

    Adapter->References++;

    if (!Adapter->ResetInProgress) {

        PSONIC_OPEN Open = PSONIC_OPEN_FROM_BINDING_HANDLE(MacBindingHandle);

        if (!Open->BindingShuttingDown) {

            Open->References++;

            //
            // Determine if this was a loopback packet.
            //

            if (MacReceiveContext == (NDIS_HANDLE)NULL) {

                NdisCopyFromPacketToPacket(
                    Packet,
                    0,
                    BytesToTransfer,
                    Adapter->CurrentLoopbackPacket,
                    ByteOffset + 14,
                    BytesTransferred
                    );

            } else {

		SonicCopyFromBufferToPacket(
		    Adapter,
		    (SONIC_PHYSICAL_ADDRESS)((ULONG)MacReceiveContext + ByteOffset),
		    BytesToTransfer,
		    Packet,
		    0,
		    BytesTransferred
		    );
            }

            Open->References--;
            StatusToReturn = NDIS_STATUS_SUCCESS;

        } else {

            StatusToReturn = NDIS_STATUS_REQUEST_ABORTED;

        }

    } else {

        StatusToReturn = NDIS_STATUS_RESET_IN_PROGRESS;

    }

    SONIC_DO_DEFERRED(Adapter);
    return StatusToReturn;
}
