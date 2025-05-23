// vbusioctl.h
//
// Define control codes for Vbus driver
//

#ifndef __VBUSIOCTL__H__
#define __VBUSIOCTL__H__

#define VBUS_IOCTL_ADD_DEVICE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define VBUS_IOCTL_DELETE_DEVICE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif // __VBUSIOCTL__H__
