//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright 2005 OSR, Open Systems Resources, Inc. All rights Reserved.
// 
// Module Name:
// 
//     irclass_ioctl.h
// 
// Abstract:
// 
//    This module contains the IOCTL definitions for the 
//    WDF IRCLASS class driver
//
//  
// Author:
//
// Revision History:
//      
#ifndef __IRCLASS_IOCTL_H__
#define __IRCLASS_IOCTL_H__

#if (NTDDI_VERSION >= NTDDI_VISTA)

// disable warnings
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) // nameless struct/union

#define FILE_DEVICE_IRCLASS     0x0F60

//
// This value is defined in wdm.h, but user mode code shouldn't include wdm.h,
// so we define this here.
//
#ifndef MAXIMUM_FILENAME_LENGTH
#define MAXIMUM_FILENAME_LENGTH         256
#endif 

/*++
    
    IOCTL_IR_GET_DEVCAPS

    Returns device capabilities.  For legacy devices, the Capabilities 
    registry entry can be used to populate this structure.  For new devices, 
    the implementation is left as an exercise for the reader.

    The capabilities structure gets rev'ed when new capabilities are
    added to the class driver.  The class driver sends the largest possible
    structure size to the port driver.  The port driver populates the 
    capabilties structure, including the ProtocolVersion member.  The
    class driver then uses the ProtocolVersion member to decide which
    version of IR_DEV_CAPS the port driver has filled in.

    Used in IR DDI Versions: V1, V2
    
    V1: port driver must set ProtocolVersion to 0x100 and fill in 
    required members of IR_DEV_CAPS_V1 structure.
    
    V2: port driver must set ProtocolVersion to 0x200 and fill in
    required members of IR_DEV_CAPS_V2 structure

    Parameters:

    lpOutBuffer      - pointer to caller-allocated IR_DEV_CAPS_V2 structure

    nOutBufferSize   - sizeof (IR_DEV_CAPS_V2)

--*/

#define IOCTL_IR_GET_DEV_CAPS           CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 1,                    \
                                                 METHOD_BUFFERED,      \
                                                 FILE_READ_ACCESS)

//
// IR_DEV_CAPS - This is the older version of teh IR_DEV_CAPS
// structure.  This is here for historical reasons.  New drivers should
// use the full IR_DEV_CAPS_V2 structure.
//
typedef struct _IR_DEV_CAPS {

    //
    // Protocol version.  Must be 100 (1.0) if using the IR_DEV_CAPS
    // structure.  
    //
    /* out */ ULONG_PTR ProtocolVersion;
    
    //
    // Number of transmit ports - 0-32
    //
    /* out */ ULONG_PTR NumTransmitPorts;

    //
    // Number of receive ports - 0-32 (for snowflake, 
    // this would be one.  For beanbag, this would be 
    // two (one for learning, one for normal)
    //
    /* out */ ULONG_PTR NumReceivePorts;    

    //
    // Bitmask identifying which receivers are 
    // learning receivers - low bit is the first 
    // receiver, second-low bit is the second receiver, 
    // etc	
    //
    /* out */ ULONG_PTR LearningReceiverMask; 

    //
    // Flags
    //
    /* out */ ULONG_PTR DevCapsFlags; 

}IR_DEV_CAPS, *PIR_DEV_CAPS;

typedef IR_DEV_CAPS IR_DEV_CAPS_V1, *PIR_DEV_CAPS_V1;

#define DEV_CAPS_PROTOCOL_VERSION        0x100
#define DEV_CAPS_PROTOCOL_VERSION_V1     0x100

//
// Valid capabilities bits for protocol V1
//
#define DEV_CAPS_SUPPORTS_LEGACY_SIGNING 0x1
#define DEV_CAPS_HAS_UNIQUE_SERIAL       0x2
#define DEV_CAPS_CAN_FLASH_RECEIVER_LED  0x4
#define DEV_CAPS_IS_LEGACY               0x8

#define V1_DEV_CAPS_VALID_BITS           0xf


//
// IR_DEV_CAPS_V2 - This is the full capabilties structure.  Drivers 
// should use this version whenever possible.  The port
// driver must set ProtocolVersion to 0x200 (2.00) if using this
// strucutre.
//
// 
// IR_DEV_CAPS_V2 is an extension of IR_DEV_CAPS_V1.  This is expressed
// differently between C and C++.
//
#ifdef __cplusplus

typedef struct _IR_DEV_CAPS_V2 :
    public IR_DEV_CAPS_V1 {
    
#else

typedef struct _IR_DEV_CAPS_V2 {
    IR_DEV_CAPS_V1;
    
#endif

    //
    // Bitmask with supported wake protocols
    //
    /* out */ ULONG_PTR WakeProtocols;

    //
    // PNP ID for affiliated tuner.  Only valid if
    // DEV_CAPS_V2_ATTACHED_TO_TUNER is set.
    //
    /* out */ WCHAR TunerPnpId[MAXIMUM_FILENAME_LENGTH] ;
    
} IR_DEV_CAPS_V2, *PIR_DEV_CAPS_V2;

#define DEV_CAPS_PROTOCOL_VERSION_V2        0x200

//
// Valid capabilities bits for protocol V2
//

#define V2_DEV_CAPS_SUPPORTS_WAKE             0x10        
#define V2_DEV_CAPS_MULTIPLE_WAKE             0x20
#define V2_DEV_CAPS_PROGRAMMABLE_WAKE         0x40
#define V2_DEV_CAPS_VOLATILE_WAKE_PATTERN     0x80           

#define V2_DEV_CAPS_LEARNING_ONLY             0x100
#define V2_DEV_CAPS_NARROW_BPF                0x200
#define V2_DEV_CAPS_NO_SWDECODE_INPUT         0x400
#define V2_DEV_CAPS_HWDECODE_INPUT            0x800

#define V2_DEV_CAPS_EMULATOR_V1               0x1000
#define V2_DEV_CAPS_EMULATOR_V2               0x2000
#define V2_DEV_CAPS_ATTACHED_TO_TUNER         0x4000

#define V2_DEV_CAPS_VALID_BITS                0x7fff

//
// Wake protocols
//
#define V2_WAKE_PROTOCOL_RC6                 0x1
#define V2_WAKE_PROTOCOL_QP                  0x2
#define V2_WAKE_PROTOCOL_SAMSUNG             0x4
#define V2_WAKE_PROTOCOL_DONTCARE            0x8

#define V2_VALID_WAKE_PROTOCOLS              0xf

/*++

    IOCTL_IR_GET_EMITTERS

    Gets attached emitters and returns the information in a bitmask.  
    Information returned in lpOutBuffer.

    Used in IR DDI Versions: V1, V2
    
    Parameters:

    lpOutBuffer      - pointer to caller-allocated buffer sizeof(ULONG)

    nOutBufferSize   - sizeof(ULONG)

--*/
#define IOCTL_IR_GET_EMITTERS           CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 2,                    \
                                                 METHOD_BUFFERED,      \
                                                 FILE_READ_ACCESS)


/*++

    IOCTL_IR_FLASH_RECEIVER

    Flash an LED on the given receiver.  Used to tell the user where to point 
    their remote, so a given "receiver box" with multiple receiver parts only 
    needs one LED to flash.

    Used in IR DDI Versions: V1, V2
    
    Parameters:

    lpInBuffer      - pointer to caller-allocated buffer sizeof(ULONG) with 
                      bitmask of receivers to flash

    nInBufferSize   - sizeof(ULONG)

--*/
#define IOCTL_IR_FLASH_RECEIVER           CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 3,                      \
                                                 METHOD_BUFFERED,        \
                                                 FILE_WRITE_ACCESS)


/*++

    IOCTL_IR_RESET_DEVICE
    
    Resets the given device.  When a device is reset, all pending transmit and 
    receive IOCTLs are cancelled by the class driver

    Used in IR DDI Versions: V1, V2

    Parameters:

--*/
#define IOCTL_IR_RESET_DEVICE           CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 4,                    \
                                                 METHOD_BUFFERED,      \
                                                 FILE_WRITE_ACCESS)


/*++

    IOCTL_IR_TRANSMIT


    Transmits the given IR stream on the given port(s) at the given carrier 
    frequency. On legacy devices, this maintains the pre-existing carrier 
    frequency, port masks, and sample period values.  (ie. it gets the old 
    values, changes them, transmits, and then changes them back.)

    This IOCTL is synchronous.  It does not return until the IR has actually 
    been transmitted.

    Used in IR DDI Versions: V1, V2
    
    Parameters:

    lpInBuffer      - pointer to caller-allocated IR_TRANSMIT_PARAMS structure

    nInBufferSize   - sizeof(IR_TRANSMIT_PARAMS)

    lpOutBuffer     - pointer to caller-allocated IR_TRANSMIT_CHUNCK that contains
                      the data to be transmitted

    nOutBufferSize  - size of caller-allocated buffer. 

--*/
#define IOCTL_IR_TRANSMIT           CTL_CODE(FILE_DEVICE_IRCLASS,    \
                                                 5,                  \
                                                 METHOD_IN_DIRECT,  \
                                                 FILE_WRITE_ACCESS)


typedef struct _IR_TRANSMIT_PARAMS {

    //
    // Bitmask containing ports to transmit on.
    //
    /* in */ ULONG_PTR TransmitPortMask;

    //
    // Carrier period to use.  If zero, Flags 
    // needs to define DC mode or pulse mode.
    //
    /* in */ ULONG_PTR CarrierPeriod;

    //
    // Flags 
    //
    /* in */ ULONG_PTR Flags;

    //
    // If pulse mode is set, this contains the length of pulse
    // to use.
    //
    /* in */ ULONG_PTR PulseSize;
    
} IR_TRANSMIT_PARAMS, *PIR_TRANSMIT_PARAMS;

#define TRANSMIT_FLAGS_PULSE_MODE 0x0001
#define TRANSMIT_FLAGS_DC_MODE    0x0002

typedef struct _IR_TRANSMIT_CHUNK {

    //
    // offset, in bytes, from Data member of this buffer to next 
    //   IR_TRANSMIT_CHUNK (or zero if no more chunks in buffer)
    //
    ULONG_PTR    OffsetToNextChunk;

    //
    // number of times to serially repeat "ByteCount" bytes of data
    //
    ULONG_PTR    RepeatCount;   

    //
    // count of data bytes to be sent
    //
    ULONG_PTR    ByteCount;         

    //
    // First byte of "ByteCount" bytes of data. 
    //   Note: Each chunk is filled to integral ULONG_PTR boundary
    //
    LONG        Data[1];

} IR_TRANSMIT_CHUNK, *PIR_TRANSMIT_CHUNK;


/*++

    IOCTL_IR_RECEIVE

    Receives IR.  Does not return until IR is available.  If there is no more IR 
    data available than space in the buffer, IrReceiveParms->DataEnd is set to 
    TRUE.  The provided timeout is used to define the end of a keypress.  So, 
    once the driver starts receiving IR from the hardware, it will continue to 
    add it to the buffer until the specified time passes with no IR.

    Used in IR DDI Versions: V1, V2

    Parameters:

    lpOutBuffer      - pointer to caller-allocated IR_RECEIVE_PARAMS structure

    nOutBufferSize   - sizeof(IR_RECEIVE_PARAMS)

--*/
#define IOCTL_IR_RECEIVE           CTL_CODE(FILE_DEVICE_IRCLASS,    \
                                                 6,                 \
                                                 METHOD_OUT_DIRECT,  \
                                                 FILE_READ_ACCESS)

typedef struct _IR_RECEIVE_PARAMS {

    //
    // Does this receive represent a data end event?
    //
    /* out */ ULONG_PTR DataEnd;

    //
    // Size of the data buffer
    //
    /* in */  ULONG_PTR ByteCount;

    //
    // The data buffer itself.
    //
    /* out */ LONG     Data[1];

}IR_RECEIVE_PARAMS, *PIR_RECEIVE_PARAMS;


/*++

    IOCTL_IR_PRIORITY_RECEIVE

    This request is sent from CIRClass and receives Run Length Coded (RLC) IR 
    data when the device is running in Priority Receive mode. If the device is 
    not already in Priority Receive mode, initiated by having previously 
    received an IOCTL_ENTER_PRIORITY_RECEIVE, the CIR Port driver fails this 
    request immediately. If in Priority Receive mode, the request will remain 
    pending until one of two events occurs:
    
    1) The data buffer provided in the request has been completely filled with 
    data.
    
    2) An IR timeout occurs. The length of time required for the IR timeout was
    specified when entering Priority Receive mode.
    
    While in Priority Receive mode and processing IOCTL_IR_PRIORITY_RECEIVE 
    requests, IOCTL_IR_RECEIVE requests remain pending and are not filled with 
    IR data.

    Used in IR DDI Versions: V1, V2

    Parameters:

    lpOutBuffer      - pointer to caller-allocated IR_PRIORITY_RECEIVE_PARAMS structure

    nOutBufferSize   - sizeof(IR_PRIORITY_RECEIVE_PARAMS)

--*/
#define IOCTL_IR_PRIORITY_RECEIVE           CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 8,                   \
                                                 METHOD_OUT_DIRECT,    \
                                                 FILE_READ_ACCESS)

typedef struct _IR_PRIORITY_RECEIVE_PARAMS {

    //
    // Does this receive represent a data end event?
    //
    /* out */ ULONG_PTR DataEnd;

    //
    // Size of the data buffer
    //
    /* in */  ULONG_PTR ByteCount;

    //
    // Carrier frequency (only valid if DataEnd != 0)
    //
    /* out */ ULONG_PTR CarrierFrequency;

    //
    // The data buffer itself.
    //
    /* in */  LONG     Data[1];

}IR_PRIORITY_RECEIVE_PARAMS, *PIR_PRIORITY_RECEIVE_PARAMS;

/*++

    IOCTL_IR_HANDSHAKE

    This IOCTL is sent from CIRClass before creating the HID child device to 
    represent the port. This IOCTL is to be completed synchronously by the 
    port as an indication that it is prepared to return RLC IR data to the 
    class driver. 

    Used in IR DDI Versions: V1, V2

    Parameters:

--*/
#define IOCTL_IR_HANDSHAKE             CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 9,                   \
                                                 METHOD_BUFFERED,     \
                                                 FILE_ANY_ACCESS)
/*++

    IOCTL_IR_ENTER_PRIORITY_RECEIVE

    This request is sent to prepare the port to enter Priority Receive mode. 
    While the device is in Priority Receive mode, all IOCTL_IR_RECEIVE requests 
    should be starved and IOCTL_IR_PRIORITY_RECEIVE requests should be 
    completed.

    Used in IR DDI Versions: V1, V2

    Parameters:

    lpOutBuffer      - pointer to caller-allocated IOCTL_IR_ENTER_PRIORITY_RECEIVE_PARAMS structure

    nOutBufferSize   - sizeof(IOCTL_IR_ENTER_PRIORITY_RECEIVE_PARAMS)

--*/
#define IOCTL_IR_ENTER_PRIORITY_RECEIVE        CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 10,                  \
                                                 METHOD_BUFFERED,     \
                                                 FILE_WRITE_ACCESS)

typedef struct _IOCTL_IR_ENTER_PRIORITY_RECEIVE_PARAMS {

    //
    // Index of the receiver to use
    //
    /* in */ ULONG_PTR  Receiver;
    
    //
    // Timeout value, in micsec.  Used to define 
    // the end of a given sample.
    //
    /* in */ ULONG_PTR  TimeOut;
    
}IOCTL_IR_ENTER_PRIORITY_RECEIVE_PARAMS, *PIOCTL_IR_ENTER_PRIORITY_RECEIVE_PARAMS;


/*++

    IOCTL_IR_EXIT_PRIORITY_RECEIVE
    
    This request is sent to end Priority Receive mode. Upon receipt of the 
    request, the port should abort any outstanding IOCTL_IR_PRIORITY_RECEIVE 
    requests and fail any future IOCTL_IR_PRIORITY_RECEIVE requests (before 
    receiving a new IOCTL_IR_ENTER_PRIORITY_RECEIVE request). As a result of 
    receiving this IOCTL, the CIR Port driver is responsible for restoring the 
    device to the state that it was in before receipt of the 
    IOCTL_IR_ENTER_PRIORITY_RECEIVE.

    Used in IR DDI Versions: V1, V2

    Parameters:

--*/
#define IOCTL_IR_EXIT_PRIORITY_RECEIVE         CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 11,                  \
                                                 METHOD_BUFFERED,     \
                                                 FILE_WRITE_ACCESS)

/*++

    IOCTL_IR_USER_OPEN

    This IOCTL is sent from the class driver when a user has indirectly opened 
    the port driver through IRCLASS. This IOCTL is informational only, allowing 
    the port to do any initialization or bookkeeping required to handle 
    requests not directly originating from IRCLASS. 

    Used in IR DDI Versions: V1, V2

    Parameters:

--*/
#define IOCTL_IR_USER_OPEN             CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 12,                  \
                                                 METHOD_BUFFERED,     \
                                                 FILE_WRITE_ACCESS)


/*++

    IOCTL_IR_USER_CLOSE

    This IOCTL is sent from IRCLASS when a user has indirectly closed the port 
    driver. This IOCTL is informational only, allowing the port to do any 
    cleanup required when closed by a user. 

    Used in IR DDI Versions: V1, V2

    Parameters:

--*/
#define IOCTL_IR_USER_CLOSE            CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 13,                  \
                                                 METHOD_BUFFERED,     \
                                                 FILE_WRITE_ACCESS)
                                                 
/*++

    IOCTL_IR_SET_WAKE_PATTERN

    This IOCTL is sent from IRCLASS to configure the wake pattern.  This is
    done dynamically in response to user input, so it could be done at any
    time.

    Used in IR DDI Versions: V2 only

    Parameters:

    lpInBuffer      - pointer to caller-allocated IR_SET_WAKE_PATTERN_PARAMS structure

    nInBufferSize   - sizeof(IR_SET_WAKE_PATTERN_PARAMS)

--*/
#define IOCTL_IR_SET_WAKE_PATTERN      CTL_CODE(FILE_DEVICE_IRCLASS,  \
                                                 14,                  \
                                                 METHOD_BUFFERED,     \
                                                 FILE_WRITE_ACCESS)

typedef struct _IOCTL_IR_SET_WAKE_PATTERN_PARAMS {

    //
    // Protocol to wake on.  One of the V2_WAKE_PROTOCOL_* values.
    //
    /* in */ ULONG Protocol;

    //
    // Key code to wake on.  WAKE_CODE_ALL_KEYS to wake on all keys.  See
    // WAKE_KEY_* for valid values.
    //
    /* in */ ULONG Payload;

    //
    // Address to wake on.  The device may ignore this, but we tell them 
    // anyway.
    //
    /* in */ ULONG Address;
} IR_SET_WAKE_PATTERN_PARAMS, *PIR_SET_WAKE_PATTERN_PARAMS;

//
// Valid wake keys.  A good implementation will be able to wake on all key
// codes but this is not required.
//
#define WAKE_KEY_POWER_TOGGLE   0x0C
#define WAKE_KEY_DISCRETE_ON    0x29
#define WAKE_KEY_ALL_KEYS       0xffff

//re-enable warnings
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
// #pragma warning(default:4214)
#endif


#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#endif // __IRCLASS_IOCTL_H__

