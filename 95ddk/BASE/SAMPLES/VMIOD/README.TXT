*****************************************************************************
*                                                                           *
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY     *
* KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR     *
* PURPOSE.                                                                  *
*                                                                           *
* Copyright (C) 1993-95  Microsoft Corporation.  All Rights Reserved.       *
*                                                                           *
*****************************************************************************

VMIOD

This VxD displays data going in and out of a specified I/O port.
You have to have a secondary monitor on your system to use this
VxD. To install this, you need to put the following lines in
the [386Enh] section of your SYSTEM.INI file:

DebugMono=TRUE
VMIOD_Port=nnnn
device=vmiod.vxd

where nnnn is the hex I/O port number to monitor. 

The technique use will only work for UNTRAPPED I/O ports. Most of
the hardware devices that Windows knows about (keyboard, timer,
video) are trapped ports, and thus can not be monitored by this
VxD. But for a simple demonstration of this program, try 3F5, a
floppy controller port. This port was untrapped in the retail 
release of Windows 3.0 and 3.1.
