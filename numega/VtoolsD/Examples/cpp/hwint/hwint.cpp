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

// HWINT.CPP - main module for "hour chime" example
// Copyright (c) 1995 Compuware Corporation
//
// This example VxD implements an hourly chime. It is designed to illustrate
// the usage of the VtoolsD class library for handling hardware interrupts.
// 
// There are many ways to implement a program that beeps on the hour, 
// and, of course, it is something you can do without a VxD. In this
// example, a handler for the Real Time Clock interrupt checks the current
// hour and minute, and on the hour causes a bell to sound. This is 
// a special case of a very common situation in VxD programming: An
// interrupt handler performs port I/O to check for a certain condition,
// and when that condition is detected, the VxD performs some action. 
//
// To implement the program in C++, we have chosen to create two classes
// in addition to the class that supports the driver itself. These are:
//
//	RTCInterrupt		Real time clock interrupt (see rtcint.cpp)
//	BellEvent		Event to sound bell (see bellevt.cpp)
//
// The skeleton of the main module for this VxD was generated by Compuware's
// QuickVxD utility.
//
// ***********************************************************************
//
// Device preliminaries for main module

#define DEVICE_MAIN
#include "HWINT.h"
Declare_Virtual_Device(HWINT)
#undef DEVICE_MAIN

//
// ***********************************************************************
//
// Static data

VOID TickHandler(VOID);		// Forward declaration for callback 
				// on RTC interrupt
BYTE TargetHour;		// Next hour to ring bell
BYTE HourMode;			// 12 or 24 hour setting of RTC
RTCInterrupt* pRTCInterrupt=0;	// Pointer to our RTCInterrupt object

//
// ***************************** CODE ************************************
//

// Function
// 	HwintDevice::OnSystemExit - Handler for SYSTEM_EXIT control message
//
// Input
//	hSysVM		Handle of system virtual machine
//
// Remarks
//	This routine deletes the RTCInterrupt object.
//	
VOID HwintDevice::OnSystemExit(VMHANDLE hSysVM)
{
	if (pRTCInterrupt) delete pRTCInterrupt;
}


// Function
// 	TickHandler - RTC interrupt callback function
//
// Remarks
//	Class RTCInterrupt calls this function immediately
//	when a RTC interrupt occurs. This routine may only
//	call VMM/VxD services that are available at interrupt
//	level. 
//
//	For this reason, we cannot call the routine to sound the
//	chime directly. Instead, we create an instance of our
//	BellEvent class. When the handler for this event runs,
//	it will be safe to call VSD_Bell.
//
VOID TickHandler(VOID)
{
// Get current hour and minutes. RTC registers contain the current
// time; they are coded in BCD (binary coded decimal).

	BYTE hour = BCDtoInt(RTCInterrupt::ReadRegister(HOUR));

// If we are on the target hour, bump the target hour and
// schedule the bell event.

	if (hour == TargetHour) 
	{
		TargetHour = (TargetHour + 1) % HourMode;
		(new BellEvent())->call();
	}
}
