/*++

Copyright (C) 1997, Logitech Inc.

Module Name:
    UsbScan.h

Abstract:
    Interface with UsbScan kernel driver

Environment:
    User and kernel mode use

Notes:
    Interface definition for USB still image driver.

--*/

#if (NTDDI_VERSION >= NTDDI_WIN2K)

#ifndef _USBSCAN_H_
#define _USBSCAN_H_
#pragma pack(push,8)

#ifndef MAX_NUM_PIPES
 #define MAX_NUM_PIPES   8
#endif

#define BULKIN_FLAG 0x80

typedef struct _DRV_VERSION {
    __out     unsigned    major;
    __out     unsigned    minor;
    __out     unsigned    internal;
} DRV_VERSION, *PDRV_VERSION;

typedef struct _IO_BLOCK {
    __in                    unsigned uOffset;
    __in                    unsigned uLength;
    __inout_bcount(uLength) PUCHAR   pbyData;
    __in                    unsigned uIndex;
} IO_BLOCK, *PIO_BLOCK;

typedef struct _IO_BLOCK_EX {
    __in                    unsigned uOffset;
    __in                    unsigned uLength;
    __inout_bcount(uLength) PUCHAR   pbyData;
    __in                    unsigned uIndex;

    //
    // Following two fields are described in sec. 9.3.1,2 USB specification
    //
    __in      UCHAR       bRequest;               // Specific request
    __in      UCHAR       bmRequestType;          // Bitmap - charateristics of request
    __in      UCHAR       fTransferDirectionIn;   // TRUE - Device-->Host; FALSE - Host-->Device

} IO_BLOCK_EX, *PIO_BLOCK_EX;


typedef struct _CHANNEL_INFO {
    __out     unsigned    EventChannelSize;
    __out     unsigned    uReadDataAlignment;
    __out     unsigned    uWriteDataAlignment;
} CHANNEL_INFO, *PCHANNEL_INFO;

typedef enum {
    EVENT_PIPE,
    READ_DATA_PIPE,
    WRITE_DATA_PIPE,
    ALL_PIPE
} PIPE_TYPE;


typedef struct _USBSCAN_GET_DESCRIPTOR {
    __in      UCHAR   DescriptorType;             // high byte of wValue field in USB spec.
    __in      UCHAR   Index;                      // low byte of wValue field in USB spec.
    __in      USHORT  LanguageId;                 // wIndex field in USB spec.
} USBSCAN_GET_DESCRIPTOR, *PUSBSCAN_GET_DESCRIPTOR;


//
// The device descriptor structure reports information define in the hardware.
// If there is enough space to copy the strings, it will be done otherwise
// only the three first fields:
//
//   USHORT usVendorId;
//   USHORT usProductId;
//   USHORT usBcdDevice;
//
// will contain valid data.  Remember: The strings are UNICODE format.
//

typedef struct _DEVICE_DESCRIPTOR {
    __out     USHORT   usVendorId;
    __out     USHORT   usProductId;
    __out     USHORT   usBcdDevice;
    __out     USHORT   usLanguageId;
} DEVICE_DESCRIPTOR, *PDEVICE_DESCRIPTOR;

typedef enum _RAW_PIPE_TYPE {
    USBSCAN_PIPE_CONTROL,
    USBSCAN_PIPE_ISOCHRONOUS,
    USBSCAN_PIPE_BULK,
    USBSCAN_PIPE_INTERRUPT
} RAW_PIPE_TYPE;

typedef struct _USBSCAN_PIPE_INFORMATION {
    USHORT          MaximumPacketSize;  // Maximum packet size for this pipe
    UCHAR           EndpointAddress;    // 8 bit USB endpoint address (includes direction)
    UCHAR           Interval;           // Polling interval in ms if interrupt pipe
    RAW_PIPE_TYPE   PipeType;           // PipeType identifies type of transfer valid for this pipe
} USBSCAN_PIPE_INFORMATION, *PUSBSCAN_PIPE_INFORMATION;

typedef struct _USBSCAN_PIPE_CONFIGURATION {
    __out                       ULONG                    NumberOfPipes;
    __out_ecount(NumberOfPipes) USBSCAN_PIPE_INFORMATION PipeInfo[MAX_NUM_PIPES];
} USBSCAN_PIPE_CONFIGURATION, *PUSBSCAN_PIPE_CONFIGURATION;

#if (NTDDI_VERSION >= NTDDI_WINXP)
typedef struct _USBSCAN_TIMEOUT {
    ULONG           TimeoutRead;
    ULONG           TimeoutWrite;
    ULONG           TimeoutEvent;
} USBSCAN_TIMEOUT, *PUSBSCAN_TIMEOUT;
#endif // (NTDDI_VERSION >= NTDDI_WINXP)

#define FILE_DEVICE_USB_SCAN    0x8000
#define IOCTL_INDEX             0x0800

#define IOCTL_GET_VERSION               CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX,   METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_CANCEL_IO                 CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+1, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_WAIT_ON_DEVICE_EVENT      CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+2, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_READ_REGISTERS            CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+3, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_WRITE_REGISTERS           CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+4, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_GET_CHANNEL_ALIGN_RQST    CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+5, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_GET_DEVICE_DESCRIPTOR     CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+6, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_RESET_PIPE                CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+7, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_GET_USB_DESCRIPTOR        CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+8, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_SEND_USB_REQUEST          CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+9, METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_GET_PIPE_CONFIGURATION    CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+10,METHOD_BUFFERED,FILE_ANY_ACCESS)

#if (NTDDI_VERSION >= NTDDI_WINXP)
#define IOCTL_SET_TIMEOUT               CTL_CODE(FILE_DEVICE_USB_SCAN,IOCTL_INDEX+11,METHOD_BUFFERED,FILE_ANY_ACCESS)
#endif // (NTDDI_VERSION >= NTDDI_WINXP)

//
// Temporary to avoid breaking LOGISCAN code
//
#define ALL ALL_PIPE
#define IOCTL_ABORT_PIPE        IOCTL_CANCEL_IO
//
//
#pragma pack(pop)
#endif // _USBSCAN_H_

#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

