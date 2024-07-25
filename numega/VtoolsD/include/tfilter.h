/*++

Copyright (c) 1990  Microsoft Corporation

Module Name:

    tfilter.h

Abstract:

    Header file for the address filtering library for NDIS MAC's.

Author:

    Anthony V. Ercolano (tonye) creation-date 3-Aug-1990

Environment:

    Runs in the context of a single MAC driver.

Notes:

    None.

Revision History:

    Adam Barr (adamba) 19-Mar-1991

        - Modified for Token-Ring

--*/

#ifndef _TR_FILTER_DEFS_
#define _TR_FILTER_DEFS_

#define TR_LENGTH_OF_FUNCTIONAL 4
#define TR_LENGTH_OF_ADDRESS 6


//
// Only the low 32 bits of the functional/group address
// are needed since the upper 16 bits is always c0-00.
//
typedef ULONG TR_FUNCTIONAL_ADDRESS;
typedef ULONG TR_GROUP_ADDRESS;



//
//
#define TR_IS_NOT_DIRECTED(Address, Result) \
{ \
    PUCHAR _A = Address; \
    PBOOLEAN _R = Result; \
    *_R = (BOOLEAN)(_A[0] & ((UCHAR)0x80));\
}

//
//
#define TR_IS_FUNCTIONAL(Address, Result) \
{ \
    PUCHAR _A = Address; \
    PBOOLEAN _R = Result; \
    *_R = (BOOLEAN)(((_A[0] & ((UCHAR)0x80)) &&\
                     !(_A[2] & ((UCHAR)0x80)))?(TRUE):(FALSE)); \
}

//
//
#define TR_IS_GROUP(Address, Result) \
{ \
    PUCHAR _A = Address; \
    PBOOLEAN _R = Result; \
    *_R = (BOOLEAN)((_A[0] & _A[2] & ((UCHAR)0x80))?(TRUE):(FALSE)); \
}

//
//
#define TR_IS_SOURCE_ROUTING(Address, Result) \
{ \
    PUCHAR _A = Address; \
    PBOOLEAN _R = Result; \
    *_R = (BOOLEAN)(_A[0] >> 7);\
}


//
// Check whether an address is broadcast.
//
#define TR_IS_BROADCAST(Address, Result) \
{ \
    PUCHAR _A = Address; \
    PBOOLEAN _R = Result; \
    *_R = (BOOLEAN)(((((_A[0] == ((UCHAR)0xff)) && \
                       (_A[1] == ((UCHAR)0xff))) || \
                      ((_A[0] == ((UCHAR)0xc0)) && \
                       (_A[1] == ((UCHAR)0x00)))) && \
                     (_A[2] == ((UCHAR)0xff)) && \
                     (_A[3] == ((UCHAR)0xff)) && \
                     (_A[4] == ((UCHAR)0xff)) && \
                     (_A[5] == ((UCHAR)0xff)))?(TRUE):(FALSE)); \
}


//
// This macro will compare network addresses.
//
//  A - Is a network address.
//
//  B - Is a network address.
//
//  Result - The result of comparing two network address.
//
//  Result < 0 Implies the B address is greater.
//  Result > 0 Implies the A element is greater.
//  Result = 0 Implies equality.
//
// Note that this is an arbitrary ordering.  There is not
// defined relation on network addresses.  This is ad-hoc!
//
//
#define TR_COMPARE_NETWORK_ADDRESSES(A, B, Result) \
{ \
    PCHAR _A = (PCHAR)A; \
    PCHAR _B = (PCHAR)B; \
    INT _LocalResult = 0; \
    UINT _i; \
    for ( \
        _i = 0; \
        _i <= 5 && !_LocalResult; \
        _i++ \
        ) { \
        _LocalResult = _A[_i] - _B[_i]; \
    } \
    *Result = _LocalResult; \
}


//
// This macro is used to copy from one network address to
// another.
//
#define TR_COPY_NETWORK_ADDRESS(D, S) \
{ \
    PCHAR _D = (PCHAR) (D); \
    PCHAR _S = (PCHAR) (S); \
    _D[0] = _S[0]; \
    _D[1] = _S[1]; \
    _D[2] = _S[2]; \
    _D[3] = _S[3]; \
    _D[4] = _S[4]; \
    _D[5] = _S[5]; \
}


//
//UINT
//TR_QUERY_FILTER_CLASSES(
//    IN PTR_FILTER Filter
//    )
//
// This macro returns the currently enabled filter classes.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_FILTER_CLASSES(Filter) ((Filter)->CombinedPacketFilter)


//
//UINT
//TR_QUERY_PACKET_FILTER(
//    IN PTR_FILTER Filter,
//    IN NDIS_HANDLE NdisFilterHandle
//    )
//
// This macro returns the currently enabled filter classes for a specific
// open instance.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_PACKET_FILTER(Filter, NdisFilterHandle) \
       (((PBINDING_INFO)NdisFilterHandle)->PacketFilters)



//
//UINT
//TR_QUERY_FILTER_ADDRESSES(
//    IN PTR_FILTER Filter
//    )
//
// This macro returns the currently enabled functional address.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_FILTER_ADDRESSES(Filter) ((Filter)->CombinedFunctionalAddress)



//
//UINT
//TR_QUERY_FILTER_GROUP(
//    IN PTR_FILTER Filter
//    )
//
// This macro returns the currently enabled Group address.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_FILTER_Group(Filter) ((Filter)->GroupAddress)



//
//UINT
//TR_QUERY_FILTER_BINDING_ADDRESS(
//    IN PTR_FILTER Filter
//    IN NDIS_HANDLE NdisFilterHandle,
//    )
//
// This macro returns the currently desired functional addresses
// for the specified binding.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_FILTER_BINDING_ADDRESS(Filter, NdisFilterHandle) \
                    (((PBINDING_INFO)NdisFilterHandle)->FunctionalAddress)




//
//BOOLEAN
//TR_QUERY_FILTER_BINDING_GROUP(
//    IN PTR_FILTER Filter
//    IN NDIS_HANDLE NdisFilterHandle,
//    )
//
// This macro returns TRUE if the specified binding is using the
// current group address.
//
// NOTE: THIS MACRO ASSUMES THAT THE FILTER LOCK IS HELD.
//
#define TR_QUERY_FILTER_BINDING_GROUP(Filter, NdisFilterHandle) \
                    (((PBINDING_INFO)NdisFilterHandle)->UsingGroupAddress)


//
// An action routine type.  The routines are called
// when a filter type is set for the first time or
// no more bindings require a particular type of filter.
//
// NOTE: THIS ROUTINE SHOULD ASSUME THAT THE LOCK IS ACQUIRED.
//
typedef
NDIS_STATUS
(*TR_FILTER_CHANGE)(
    IN UINT OldFilterClasses,
    IN UINT NewFilterClasses,
    IN NDIS_HANDLE MacBindingHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN BOOLEAN Set
    );

//
// This action routine is called when the functional address
// for the card has changed. It is passed the old functional
// address as well as the new one.
//
// NOTE: THIS ROUTINE SHOULD ASSUME THAT THE LOCK IS ACQUIRED.
//
typedef
NDIS_STATUS
(*TR_ADDRESS_CHANGE)(
    IN TR_FUNCTIONAL_ADDRESS OldFunctionalAddress,
    IN TR_FUNCTIONAL_ADDRESS NewFunctionalAddress,
    IN NDIS_HANDLE MacBindingHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN BOOLEAN Set
    );


//
// This action routine is called when the group address
// for the card has changed. It is passed the old group
// address as well as the new one.
//
// NOTE: THIS ROUTINE SHOULD ASSUME THAT THE LOCK IS ACQUIRED.
//
typedef
NDIS_STATUS
(*TR_GROUP_CHANGE)(
    IN TR_GROUP_ADDRESS OldGroupAddress,
    IN TR_GROUP_ADDRESS NewGroupAddress,
    IN NDIS_HANDLE MacBindingHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN BOOLEAN Set
    );



//
// This action routine is called when the mac requests a close for
// a particular binding *WHILE THE BINDING IS BEING INDICATED TO
// THE PROTOCOL*.  The filtering package can't get rid of the open
// right away.  So this routine will be called as soon as the
// NdisIndicateReceive returns.
//
// NOTE: THIS ROUTINE SHOULD ASSUME THAT THE LOCK IS ACQUIRED.
//
typedef
VOID
(*TR_DEFERRED_CLOSE)(
    IN NDIS_HANDLE MacBindingHandle
    );


//
// The binding info is threaded on two lists.  When
// the binding is free it is on a single freelist.
//
// When the binding is being used it is on a doubly linked
// index list.
//
typedef struct _BINDING_INFO {
    NDIS_HANDLE MacBindingHandle;
    NDIS_HANDLE NdisBindingContext;
    UINT PacketFilters;
    TR_FUNCTIONAL_ADDRESS FunctionalAddress;
    struct _BINDING_INFO *NextOpen;
    struct _BINDING_INFO *PrevOpen;
    UINT References;
    UCHAR FilterIndex;
    BOOLEAN UsingGroupAddress;
    BOOLEAN ReceivedAPacket;
} BINDING_INFO,*PBINDING_INFO;

//
// An opaque type that contains a filter database.
// The MAC need not know how it is structured.
//
typedef struct _TR_FILTER {

    //
    // Spin lock used to protect the filter from multiple accesses.
    //
    PNDIS_SPIN_LOCK Lock;

    //
    // ORing together of all the FunctionalAddresses.
    //
    TR_FUNCTIONAL_ADDRESS CombinedFunctionalAddress;

    //
    // Current group address in use.
    //
    TR_FUNCTIONAL_ADDRESS GroupAddress;

    //
    // Reference count on group address;
    //
    UINT GroupReferences;

    //
    // Combination of all the filters of all the open bindings.
    //
    UINT CombinedPacketFilter;

    //
    // Pointer to list of current opens.
    //
    PBINDING_INFO OpenList;

    //
    // Address of the adapter associated with this filter.
    //
    PUCHAR AdapterAddress[TR_LENGTH_OF_ADDRESS];

    //
    // Action routines to be invoked on notable changes in the filter.
    //
    TR_ADDRESS_CHANGE AddressChangeAction;
    TR_GROUP_CHANGE GroupChangeAction;
    TR_FILTER_CHANGE FilterChangeAction;
    TR_DEFERRED_CLOSE CloseAction;

    //
    // Bit mask of opens that are available.
    //
    ULONG FreeBindingMask;

} TR_FILTER,*PTR_FILTER;

BOOLEAN NDIS_API
TrCreateFilter(
    IN TR_ADDRESS_CHANGE AddressChangeAction,
    IN TR_GROUP_CHANGE GroupChangeAction,
    IN TR_FILTER_CHANGE FilterChangeAction,
    IN TR_DEFERRED_CLOSE CloseAction,
    IN PUCHAR AdapterAddress,
    IN PNDIS_SPIN_LOCK Lock,
    OUT PTR_FILTER *Filter
    );

VOID NDIS_API
TrDeleteFilter(
    IN PTR_FILTER Filter
    );

BOOLEAN NDIS_API
TrNoteFilterOpenAdapter(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE MacBindingHandle,
    IN NDIS_HANDLE NdisBindingContext,
    OUT PNDIS_HANDLE NdisFilterHandle
    );

NDIS_STATUS NDIS_API
TrDeleteFilterOpenAdapter(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE NdisFilterHandle,
    IN PNDIS_REQUEST NdisRequest
    );

NDIS_STATUS NDIS_API
TrChangeFunctionalAddress(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE NdisFilterHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN CHAR FunctionalAddressArray[TR_LENGTH_OF_FUNCTIONAL],
    IN BOOLEAN Set
    );

NDIS_STATUS NDIS_API
TrChangeGroupAddress(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE NdisFilterHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN CHAR GroupAddressArray[TR_LENGTH_OF_FUNCTIONAL],
    IN BOOLEAN Set
    );

BOOLEAN NDIS_API
TrShouldAddressLoopBack(
    IN PTR_FILTER Filter,
    IN CHAR DestinationAddress[TR_LENGTH_OF_ADDRESS],
    IN CHAR SourceAddress[TR_LENGTH_OF_ADDRESS]
    );

NDIS_STATUS NDIS_API
TrFilterAdjust(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE NdisFilterHandle,
    IN PNDIS_REQUEST NdisRequest,
    IN UINT FilterClasses,
    IN BOOLEAN Set
    );

VOID NDIS_API
TrFilterIndicateReceive(
    IN PTR_FILTER Filter,
    IN NDIS_HANDLE MacReceiveContext,
    IN PVOID HeaderBuffer,
    IN UINT HeaderBufferSize,
    IN PVOID LookaheadBuffer,
    IN UINT LookaheadBufferSize,
    IN UINT PacketSize
    );

VOID NDIS_API
TrFilterIndicateReceiveComplete(
    IN PTR_FILTER Filter
    );
#endif // _TR_FILTER_DEFS_
