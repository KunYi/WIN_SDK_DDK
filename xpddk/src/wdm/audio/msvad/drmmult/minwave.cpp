/*++

Copyright (c) 1997-2000  Microsoft Corporation All Rights Reserved

Module Name:

    minwave.cpp

Abstract:

    Implementation of wavecyclic miniport.

--*/

#include <msvad.h>
#include <common.h>
#include "drmmult.h"
#include "minwave.h"
#include "wavtable.h"

#pragma code_seg("PAGE")

//=============================================================================
// CMiniportWaveCyclic
//=============================================================================

//=============================================================================
NTSTATUS
CreateMiniportWaveCyclicMSVAD
( 
    OUT PUNKNOWN *              Unknown,
    IN  REFCLSID,
    IN  PUNKNOWN                UnknownOuter OPTIONAL,
    IN  POOL_TYPE               PoolType 
)
/*++

Routine Description:

  Create the wavecyclic miniport.

Arguments:

  Unknown - 

  RefClsId -

  UnknownOuter -

  PoolType -

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(Unknown);

    STD_CREATE_BODY(CMiniportWaveCyclic, Unknown, UnknownOuter, PoolType);
}

//=============================================================================
CMiniportWaveCyclic::~CMiniportWaveCyclic
( 
    void 
)
/*++

Routine Description:

  Destructor for wavecyclic miniport

Arguments:

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    if (m_pDrmPort)
    {
        m_pDrmPort->Release();
    }

    DPF_ENTER(("[CMiniportWaveCyclic::~CMiniportWaveCyclic]"));
} // ~CMiniportWaveCyclic


//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclic::DataRangeIntersection
( 
    IN  ULONG                       PinId,
    IN  PKSDATARANGE                ClientDataRange,
    IN  PKSDATARANGE                MyDataRange,
    IN  ULONG                       OutputBufferLength,
    OUT PVOID                       ResultantFormat,
    OUT PULONG                      ResultantFormatLength 
)
/*++

Routine Description:

  The DataRangeIntersection function determines the highest quality 
  intersection of two data ranges.

Arguments:

  PinId -           Pin for which data intersection is being determined. 

  ClientDataRange - Pointer to KSDATARANGE structure which contains the data 
                    range submitted by client in the data range intersection 
                    property request. 

  MyDataRange -         Pin's data range to be compared with client's data 
                        range. In this case we actually ignore our own data 
                        range, because we know that we only support one range.

  OutputBufferLength -  Size of the buffer pointed to by the resultant format 
                        parameter. 

  ResultantFormat -     Pointer to value where the resultant format should be 
                        returned. 

  ResultantFormatLength -   Actual length of the resultant format placed in 
                            ResultantFormat. This should be less than or equal 
                            to OutputBufferLength. 

  Return Value:

    NT status code.

--*/
{
    PAGED_CODE();

    // This driver only supports PCM formats.
    // Portcls will handle the request for us.
    //

    return STATUS_NOT_IMPLEMENTED;
} // DataRangeIntersection

//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclic::GetDescription
( 
    OUT PPCFILTER_DESCRIPTOR * OutFilterDescriptor 
)
/*++

Routine Description:

  The GetDescription function gets a pointer to a filter description. 
  It provides a location to deposit a pointer in miniport's description 
  structure. This is the placeholder for the FromNode or ToNode fields in 
  connections which describe connections to the filter's pins. 

Arguments:

  OutFilterDescriptor - Pointer to the filter description. 

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(OutFilterDescriptor);

    return 
        CMiniportWaveCyclicMSVAD::GetDescription(OutFilterDescriptor);
} // GetDescription

//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclic::Init
( 
    IN  PUNKNOWN                UnknownAdapter_,
    IN  PRESOURCELIST           ResourceList_,
    IN  PPORTWAVECYCLIC         Port_ 
)
/*++

Routine Description:

  The Init function initializes the miniport. Callers of this function 
  should run at IRQL PASSIVE_LEVEL

Arguments:

  UnknownAdapter - A pointer to the Iuknown interface of the adapter object. 

  ResourceList - Pointer to the resource list to be supplied to the miniport 
                 during initialization. The port driver is free to examine the 
                 contents of the ResourceList. The port driver will not be 
                 modify the ResourceList contents. 

  Port - Pointer to the topology port object that is linked with this miniport. 

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(UnknownAdapter_);
    ASSERT(Port_);

    NTSTATUS                    ntStatus;

    DPF_ENTER(("[CMiniportWaveCyclic::Init]"));

    m_MaxOutputStreams      = MAX_OUTPUT_STREAMS;
    m_MaxInputStreams       = MAX_INPUT_STREAMS;
    m_MaxTotalStreams       = MAX_TOTAL_STREAMS;

    m_MinChannels           = MIN_CHANNELS;
    m_MaxChannelsPcm        = MAX_CHANNELS_PCM;

    m_MinBitsPerSamplePcm   = MIN_BITS_PER_SAMPLE_PCM;
    m_MaxBitsPerSamplePcm   = MAX_BITS_PER_SAMPLE_PCM;
    m_MinSampleRatePcm      = MIN_SAMPLE_RATE;
    m_MaxSampleRatePcm      = MAX_SAMPLE_RATE;

    m_ulMixDrmContentId     = 0;
    RtlZeroMemory(&m_MixDrmRights, sizeof(m_MixDrmRights));

    ntStatus =
        CMiniportWaveCyclicMSVAD::Init
        (
            UnknownAdapter_,
            ResourceList_,
            Port_
        );
    if (NT_SUCCESS(ntStatus))
    {
        // Set filter descriptor.
        m_FilterDescriptor = &MiniportFilterDescriptor;

        m_fCaptureAllocated = FALSE;
        RtlZeroMemory
        (
            m_pStream, 
            MAX_INPUT_STREAMS * sizeof(PCMiniportWaveCyclicStream)
        );

        if (!NT_SUCCESS(
            Port_->QueryInterface(IID_IDrmPort, (PVOID *) &m_pDrmPort)))
        {
            m_pDrmPort = NULL;
        }
    }

    return ntStatus;
} // Init

//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclic::NewStream
( 
    OUT PMINIPORTWAVECYCLICSTREAM * OutStream,
    IN  PUNKNOWN                OuterUnknown,
    IN  POOL_TYPE               PoolType,
    IN  ULONG                   Pin,
    IN  BOOLEAN                 Capture,
    IN  PKSDATAFORMAT           DataFormat,
    OUT PDMACHANNEL *           OutDmaChannel,
    OUT PSERVICEGROUP *         OutServiceGroup 
)
/*++

Routine Description:

  The NewStream function creates a new instance of a logical stream 
  associated with a specified physical channel. Callers of NewStream should 
  run at IRQL PASSIVE_LEVEL.

Arguments:

  OutStream -

  OuterUnknown -

  PoolType - 

  Pin - 

  Capture - 

  DataFormat -

  OutDmaChannel -

  OutServiceGroup -

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(OutStream);
    ASSERT(DataFormat);
    ASSERT(OutDmaChannel);
    ASSERT(OutServiceGroup);

    DPF_ENTER(("[CMiniportWaveCyclic::NewStream]"));

    NTSTATUS                    ntStatus = STATUS_SUCCESS;
    PCMiniportWaveCyclicStream  stream = NULL;
    ULONG                       streamIndex;

    // MSVAD supports one capture stream.
    //
    if (Capture)
    {
        if (m_fCaptureAllocated)
        {
            DPF(D_TERSE, ("[Only one capture stream supported]"));
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        }
    }
    // This version supports multiple playback streams.
    //
    else
    {
        for (streamIndex = 0; streamIndex < m_MaxInputStreams; streamIndex++)
        {
            if (!m_pStream[streamIndex])
            {
                break;
            }
        }
        if (streamIndex == m_MaxInputStreams)
        {
            DPF(D_TERSE, ("[All render streams are in use]"));            
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        }
    }

    // Determine if the format is valid.
    //
    if (NT_SUCCESS(ntStatus))
    {
        ntStatus = ValidateFormat(DataFormat);
    }

    // Instantiate a stream. Stream must be in
    // NonPagedPool because of file saving.
    //
    if (NT_SUCCESS(ntStatus))
    {
        stream = new (NonPagedPool, MSVAD_POOLTAG) 
            CMiniportWaveCyclicStream(OuterUnknown);

        if (stream)
        {
            stream->AddRef();

            ntStatus = 
                stream->Init
                ( 
                    this,
                    Pin,
                    Capture,
                    DataFormat
                );
        }
        else
        {
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        }
    }

    if (NT_SUCCESS(ntStatus))
    {
        if (Capture)
        {
            m_fCaptureAllocated = TRUE;
        }
        else
        {
            m_pStream[streamIndex] = stream;
        }

        *OutStream = PMINIPORTWAVECYCLICSTREAM(stream);
        (*OutStream)->AddRef();
        
        *OutDmaChannel = PDMACHANNEL(stream);
        (*OutDmaChannel)->AddRef();

        *OutServiceGroup = m_ServiceGroup;
        (*OutServiceGroup)->AddRef();

        // The stream, the DMA channel, and the service group have
        // references now for the caller.  The caller expects these
        // references to be there.
    }

    // This is our private reference to the stream.  The caller has
    // its own, so we can release in any case.
    //
    if (stream)
    {
        stream->Release();
    }
    
    return ntStatus;
} // NewStream

//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclic::NonDelegatingQueryInterface
( 
    IN  REFIID  Interface,
    OUT PVOID * Object 
)
/*++

Routine Description:

  QueryInterface

Arguments:

  Interface - GUID

  Object - interface pointer to be returned.

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(Object);

    if (IsEqualGUIDAligned(Interface, IID_IUnknown))
    {
        *Object = PVOID(PUNKNOWN(PMINIPORTWAVECYCLIC(this)));
    }
    else if (IsEqualGUIDAligned(Interface, IID_IMiniport))
    {
        *Object = PVOID(PMINIPORT(this));
    }
    else if (IsEqualGUIDAligned(Interface, IID_IMiniportWaveCyclic))
    {
        *Object = PVOID(PMINIPORTWAVECYCLIC(this));
    }
    else
    {
        *Object = NULL;
    }

    if (*Object)
    {
        // We reference the interface for the caller.

        PUNKNOWN(*Object)->AddRef();
        return STATUS_SUCCESS;
    }

    return STATUS_INVALID_PARAMETER;
} // NonDelegatingQueryInterface

//=============================================================================
NTSTATUS
CMiniportWaveCyclic::UpdateDrmRights
(
    void
)
/*++

Routine Description:

  Updates the mixed DrmRights. This is done by creating an array of existing
  content ids and asking DrmPort to create a new contend id with a mixed
  DrmRights structure.
  The new DrmRights structure should be enforced, if everything goes well.

Arguments:

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    DPF_ENTER(("[CMiniportWaveCyclic::UpdateDrmRights]"));
    
    NTSTATUS                    ntStatus;
    ULONG                       ulContentIndex = 0;
    ULONG                       ulContentIds[MAX_INPUT_STREAMS];
    ULONG                       ulMixDrmContentId = 0;
    BOOL                        fCreatedContentId = FALSE;
    DRMRIGHTS                   MixDrmRights = {FALSE, 0, FALSE};

    // This function only runs if IID_DrmPort is implemented in Wave port.
    //
    if (!m_pDrmPort)
    {
        return STATUS_UNSUCCESSFUL;
    }

    // Create an array of all StreamIds.
    //
    for (ULONG i = 0; i < MAX_INPUT_STREAMS; i++)
    {
        if (m_pStream[i])
        {
            ulContentIds[ulContentIndex] = m_pStream[i]->m_ulContentId;
            ulContentIndex++;
        }
    }

    // Create the new contentId.
    //
    if (ulContentIndex)
    {
        ntStatus = 
            m_pDrmPort->CreateContentMixed
            (
                ulContentIds,
                ulContentIndex,
                &ulMixDrmContentId
            );
        if (NT_SUCCESS(ntStatus))
        {
            fCreatedContentId = TRUE;
            ntStatus = 
                m_pDrmPort->GetContentRights
                (
                    ulMixDrmContentId, 
                    &MixDrmRights
                );
        }
    }

    // If successful, destroy the old ContentId and update global rights.
    //
    if (NT_SUCCESS(ntStatus))
    {
        m_pDrmPort->DestroyContent(m_ulMixDrmContentId);
        m_ulMixDrmContentId = ulMixDrmContentId;
        RtlCopyMemory(&m_MixDrmRights, &MixDrmRights, sizeof(m_MixDrmRights));

        // At this point the driver should enforce the new DrmRights.
        // MSVAD does not have loopback capture caps and does not support
        // S/PDIF out, therefore the new MixedRights is ignored.

        // MSVAD handles DrmRights per stream basis, and stops writing 
        // the stream to disk, if CopyProtect = TRUE.
        //
    } 

    // Cleanup if failed
    // 
    if (!NT_SUCCESS(ntStatus) && fCreatedContentId)
    {
        m_pDrmPort->DestroyContent(ulMixDrmContentId);
    }

    return ntStatus;
} // UpdateDrmRights

//=============================================================================
// CMiniportWaveStreamCyclicSimple
//=============================================================================

//=============================================================================
CMiniportWaveCyclicStream::~CMiniportWaveCyclicStream
( 
    void 
)
/*++

Routine Description:

  Destructor for wavecyclicstream 

Arguments:

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    DPF_ENTER(("[CMiniportWaveCyclicStream::~CMiniportWaveCyclicStream]"));

    if (NULL != m_pMiniportLocal)
    {
        // Tell the Miniport that the slot is freed now.
        //
        if (m_fCapture)
        {
            m_pMiniportLocal->m_fCaptureAllocated = FALSE;
        }
        else
        {
            for (ULONG i = 0; i < m_pMiniportLocal->m_MaxInputStreams; i++)
            {
                if (this == m_pMiniportLocal->m_pStream[i])
                {
                    m_pMiniportLocal->m_pStream[i] = NULL;
                    break;
                }
            }

            // Tell the wave miniport to update mixed drm rights.
            //
            m_pMiniportLocal->UpdateDrmRights();
        }
    }
} // ~CMiniportWaveCyclicStream

//=============================================================================
NTSTATUS
CMiniportWaveCyclicStream::Init
( 
    IN PCMiniportWaveCyclic         Miniport_,
    IN ULONG                        Pin_,
    IN BOOLEAN                      Capture_,
    IN PKSDATAFORMAT                DataFormat_
)
/*++

Routine Description:

  Initializes the stream object. Allocate a DMA buffer, timer and DPC

Arguments:

  Miniport_ -

  Pin_ -

  Capture_ -

  DataFormat -

  DmaChannel_ -

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    m_pMiniportLocal = Miniport_;
    m_ulContentId = 0;

    return 
        CMiniportWaveCyclicStreamMSVAD::Init
        (
            Miniport_,
            Pin_,
            Capture_,
            DataFormat_
        );
} // Init

//=============================================================================
STDMETHODIMP_(NTSTATUS)
CMiniportWaveCyclicStream::NonDelegatingQueryInterface
( 
    IN  REFIID  Interface,
    OUT PVOID * Object 
)
/*++

Routine Description:

  QueryInterface

Arguments:

  Interface - GUID

  Object - interface pointer to be returned

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    ASSERT(Object);

    if (IsEqualGUIDAligned(Interface, IID_IUnknown))
    {
        *Object = PVOID(PUNKNOWN(PMINIPORTWAVECYCLICSTREAM(this)));
    }
    else if (IsEqualGUIDAligned(Interface, IID_IMiniportWaveCyclicStream))
    {
        *Object = PVOID(PMINIPORTWAVECYCLICSTREAM(this));
    }
    else if (IsEqualGUIDAligned(Interface, IID_IDmaChannel))
    {
        *Object = PVOID(PDMACHANNEL(this));
    }
    else if (IsEqualGUIDAligned(Interface, IID_IDrmAudioStream))
    {
        *Object = (PVOID)(PDRMAUDIOSTREAM)this;
    }
    else
    {
        *Object = NULL;
    }

    if (*Object)
    {
        PUNKNOWN(*Object)->AddRef();
        return STATUS_SUCCESS;
    }

    return STATUS_INVALID_PARAMETER;
} // NonDelegatingQueryInterface

//=============================================================================
STDMETHODIMP_(NTSTATUS) 
CMiniportWaveCyclicStream::SetContentId
(
    IN  ULONG                   contentId,
    IN  PCDRMRIGHTS             drmRights
)
/*++

Routine Description:

  Sets DRM content Id for this stream. Also updates the Mixed content Id.

Arguments:

  contentId - new content id

  drmRights - rights for this stream.

Return Value:

  NT status code.

--*/
{
    PAGED_CODE();

    DPF_ENTER(("[CMiniportWaveCyclicStream::SetContentId]"));

    NTSTATUS    ntStatus;
    ULONG       ulOldContentId = contentId;

    m_ulContentId = contentId;

    // Miniport should create a mixed DrmRights.
    //
    ntStatus = m_pMiniportLocal->UpdateDrmRights();

    // Restore the old content Id.
    //
    if (!NT_SUCCESS(ntStatus))
    {
        m_ulContentId = ulOldContentId;
    }

    // MSVAD rights each stream seperately to disk. If the rights for this
    // stream indicates that the stream is CopyProtected, stop writing to disk.
    //
    m_SaveData.Disable(drmRights->CopyProtect);
    
    return ntStatus;
} // SetContentId

#pragma code_seg()


