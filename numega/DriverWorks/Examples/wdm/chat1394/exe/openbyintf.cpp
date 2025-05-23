// OpenByIntf.cpp - open device by device interface
//=============================================================================
//
// Compuware Corporation
// NuMega Lab
// 9 Townsend West
// Nashua, NH 03060  USA
//
// Copyright (c) 1998 Compuware Corporation. All Rights Reserved.
// Unpublished - rights reserved under the Copyright laws of the
// United States.
//
//=============================================================================

#define NOCRYPT			// prevent attempt to include missing files
#define _INC_EXCPT		// prevent excpt.h from being included

#include <stdlib.h>
#include <windows.h>
#include <winioctl.h>
#include "devintf.h"	// DriverWorks

// OpenByInterface
//
// Opens the nth device found with the given interface class

HANDLE OpenByInterface(
		GUID* pClassGuid,	// points to the GUID that identifies the interface class
		DWORD instance,		// specifies which instance of the enumerated devices to open
		PDWORD pError,		// address of variable to receive error status
		BOOL bOverlapped	// indicates whether to open the file for overlapped access or not
		)
{
	HANDLE hDev;
	CDeviceInterfaceClass DevClass(pClassGuid, pError);

	if (*pError != ERROR_SUCCESS)
		return INVALID_HANDLE_VALUE;

	CDeviceInterface DevInterface(&DevClass, instance, pError);

	if (*pError != ERROR_SUCCESS)
		return INVALID_HANDLE_VALUE;

	hDev = CreateFile(
		DevInterface.DevicePath(),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | ((bOverlapped) ? FILE_FLAG_OVERLAPPED : 0),
		NULL
		);

	if (hDev == INVALID_HANDLE_VALUE)
		*pError = GetLastError();

	return hDev;
}

