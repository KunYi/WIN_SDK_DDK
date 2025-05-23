/****************************************************************************
*                                                                           *
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY     *
* KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR     *
* PURPOSE.                                                                  *
*                                                                           *
* Copyright (C) 1993-95  Microsoft Corporation.  All Rights Reserved.       *
*                                                                           *
****************************************************************************/

/*****************************************************************************
 *
 *  Title:      DBT.H - Equates for WM_DEVICECHANGE and BroadcastSystemMessage
 *
 *  Version:    4.00
 *
 *****************************************************************************/

#ifndef _DBT_H
#define	_DBT_H

/*
 * BroadcastSpecialMessage constants.
 */
#define WM_DEVICECHANGE		0x0219

/* XLATOFF */
#ifdef	IS_32
#define	DBTFAR
#else
#define	DBTFAR	far
#endif
/* XLATON */

/*
 * Broadcast message and receipient flags.
 *
 * Note that there is a third "flag". If the wParam has:
 *
 * bit 15 on:	lparam is a pointer and bit 14 is meaningfull.
 * bit 15 off:	lparam is just a UNLONG data type.
 *
 * bit 14 on:	lparam is a pointer to an ASCIIZ string.
 * bit 14 off:	lparam is a pointer to a binary struture starting with
 *		a dword describing the length of the structure.
 */
#define BSF_QUERY		0x00000001
#define BSF_IGNORECURRENTTASK	0x00000002	/* Meaningless for VxDs */
#define BSF_FLUSHDISK		0x00000004	/* Shouldn't be used by VxDs */
#define BSF_NOHANG              0x00000008
#define BSF_POSTMESSAGE		0x00000010
#define BSF_FORCEIFHUNG         0x00000020
#define BSF_NOTIMEOUTIFNOTHUNG  0x00000040
#define	BSF_MSGSRV32ISOK	0x80000000	/* Called synchronously from PM API */
#define	BSF_MSGSRV32ISOK_BIT	31		/* Called synchronously from PM API */

#define BSM_ALLCOMPONENTS	0x00000000
#define BSM_VXDS                0x00000001
#define BSM_NETDRIVER           0x00000002
#define BSM_INSTALLABLEDRIVERS  0x00000004
#define BSM_APPLICATIONS        0x00000008

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_APPYBEGIN
 * lParam  = (not used)
 *
 *	'Appy-time is now available.  This message is itself sent
 *	at 'Appy-time.
 *
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_APPYEND
 * lParam  = (not used)
 *
 *	'Appy-time is no longer available.  This message is *NOT* sent
 *	at 'Appy-time.  (It cannot be, because 'Appy-time is gone.)
 *
 * NOTE!  It is possible for DBT_APPYBEGIN and DBT_APPYEND to be sent
 * multiple times during a single Windows session.  Each appearance of
 * 'Appy-time is bracketed by these two messages, but 'Appy-time may
 * momentarily become unavailable during otherwise normal Windows
 * processing.  The current status of 'Appy-time availability can always
 * be obtained from a call to _SHELL_QueryAppyTimeAvailable.
 */
#define DBT_APPYBEGIN			0x0000
#define DBT_APPYEND			0x0001

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_DEVNODES_CHANGED
 * lParam  = 0
 *
 *	send when configmg finished a process tree batch. Some devnodes
 *	may have been added or removed. This is used by ring3 people which
 *	need to be refreshed whenever any devnode changed occur (like
 *	device manager). People specific to certain devices should use
 *	DBT_DEVICE* instead.
 */

#define DBT_DEVNODES_CHANGED            0x0007

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_QUERYCHANGECONFIG
 * lParam  = 0
 *
 *      sent to ask if a config change is allowed
 */

#define DBT_QUERYCHANGECONFIG           0x0017

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_CONFIGCHANGED
 * lParam  = 0
 *
 *      sent when a config has changed
 */

#define DBT_CONFIGCHANGED               0x0018

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_CONFIGCHANGECANCELED
 * lParam  = 0
 *
 *      someone cancelled the config change
 */

#define DBT_CONFIGCHANGECANCELED        0x0019

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_MONITORCHANGE
 * lParam  = new resolution to use (LOWORD=x, HIWORD=y)
 *           if 0, use the default res for current config
 *
 *      this message is sent when the display monitor has changed
 *      and the system should change the display mode to match it.
 */

#define DBT_MONITORCHANGE               0x001B

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_SHELLLOGGEDON
 * lParam  = 0
 *
 *	The shell has finished login on: VxD can now do Shell_EXEC.
 */

#define	DBT_SHELLLOGGEDON		0x0020

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_CONFIGMGAPI
 * lParam  = CONFIGMG API Packet
 *
 *	CONFIGMG ring 3 call.
 */
#define	DBT_CONFIGMGAPI32		0x0022

/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_VOLLOCK*
 * lParam  = pointer to VolLockBroadcast structure described below
 *
 *	Messages issued by IFSMGR for volume locking purposes on WM_DEVICECHANGE.
 *	All these messages pass a pointer to a struct which has no pointers.
 */

#define DBT_VOLLOCKQUERYLOCK	0x8041
#define DBT_VOLLOCKLOCKTAKEN	0x8042
#define DBT_VOLLOCKLOCKFAILED	0x8043
#define DBT_VOLLOCKQUERYUNLOCK	0x8044
#define DBT_VOLLOCKLOCKRELEASED	0x8045
#define DBT_VOLLOCKUNLOCKFAILED	0x8046

/*
 * Device broadcast header
 */
 
struct _DEV_BROADCAST_HDR {	/* */
    DWORD	dbch_size;
    DWORD	dbch_devicetype;
    DWORD       dbch_reserved;
};

typedef struct 	_DEV_BROADCAST_HDR	DEV_BROADCAST_HDR;
typedef		DEV_BROADCAST_HDR	DBTFAR *PDEV_BROADCAST_HDR;

/*
 * Structure for volume lock broadcast
 */
 
typedef struct VolLockBroadcast VolLockBroadcast;
typedef VolLockBroadcast *pVolLockBroadcast;
struct VolLockBroadcast {
	struct	_DEV_BROADCAST_HDR vlb_dbh;
	DWORD	vlb_owner;		// thread on which lock request is being issued
	BYTE	vlb_perms;		// lock permission flags defined below
	BYTE	vlb_lockType;	// type of lock
	BYTE	vlb_drive;		// drive on which lock is issued
	BYTE	vlb_flags;		// miscellaneous flags
};

/*
 * Values for vlb_perms
 */
#define LOCKP_ALLOW_WRITES		0x01	// Bit 0 set - allow writes
#define LOCKP_FAIL_WRITES		0x00	// Bit 0 clear - fail writes
#define LOCKP_FAIL_MEM_MAPPING	0x02	// Bit 1 set - fail memory mappings
#define LOCKP_ALLOW_MEM_MAPPING	0x00	// Bit 1 clear - allow memory mappings
#define LOCKP_USER_MASK			0x03	// Mask for user lock flags
#define LOCKP_LOCK_FOR_FORMAT	0x04	// Level 0 lock for format

/*
 * Values for vlb_flags
 */
#define LOCKF_LOGICAL_LOCK		0x00	// Bit 0 clear - logical lock
#define LOCKF_PHYSICAL_LOCK		0x01	// Bit 0 set - physical lock


/*
 * Message = WM_DEVICECHANGE
 * wParam  = DBT_NODISKSPACE
 * lParam  = drive number of drive that is out of disk space (1-based)
 *
 * Message issued by IFS manager when it detects that a drive is run out of
 * free space.
 */

#define DBT_NO_DISK_SPACE		0x0047


#define DBT_CONFIGMGPRIVATE	0x7FFF

/*
 * The following messages are for WM_DEVICECHANGE. The immediate list
 * is for the wParam. ALL THESE MESSAGES PASS A POINTER TO A STRUCT
 * STARTING WITH A DWORD SIZE AND HAVING NO POINTER IN THE STRUCT.
 *
 */
#define DBT_DEVICEARRIVAL		0x8000	// system detected a new device
#define DBT_DEVICEQUERYREMOVE		0x8001	// wants to remove, may fail
#define DBT_DEVICEQUERYREMOVEFAILED	0x8002  // removal aborted         
#define DBT_DEVICEREMOVEPENDING		0x8003  // about to remove, still avail.
#define DBT_DEVICEREMOVECOMPLETE	0x8004  // device is gone
#define DBT_DEVICETYPESPECIFIC		0x8005  // type specific event

#define DBT_DEVTYP_OEM			0x00000000  // oem-defined device type
#define DBT_DEVTYP_DEVNODE		0x00000001  // devnode number
#define DBT_DEVTYP_VOLUME		0x00000002  // logical volume
#define DBT_DEVTYP_PORT			0x00000003  // serial, parallel
#define DBT_DEVTYP_NET			0x00000004  // network resource

struct _DEV_BROADCAST_HEADER { /* */
    DWORD	dbcd_size;
    DWORD	dbcd_devicetype;
    DWORD       dbcd_reserved;
};

struct _DEV_BROADCAST_OEM {	/* */
    DWORD	dbco_size;
    DWORD	dbco_devicetype;
    DWORD       dbco_reserved;
    DWORD	dbco_identifier;
    DWORD	dbco_suppfunc;
};

typedef struct 	_DEV_BROADCAST_OEM	DEV_BROADCAST_OEM;
typedef		DEV_BROADCAST_OEM	DBTFAR *PDEV_BROADCAST_OEM;

struct _DEV_BROADCAST_DEVNODE { /* */
    DWORD	dbcd_size;
    DWORD	dbcd_devicetype;
    DWORD       dbcd_reserved;
    DWORD	dbcd_devnode;
};

typedef struct 	_DEV_BROADCAST_DEVNODE	DEV_BROADCAST_DEVNODE;
typedef		DEV_BROADCAST_DEVNODE	DBTFAR *PDEV_BROADCAST_DEVNODE;

struct _DEV_BROADCAST_VOLUME { /* */
    DWORD	dbcv_size;
    DWORD	dbcv_devicetype;
    DWORD       dbcv_reserved;
    DWORD	dbcv_unitmask;
    WORD	dbcv_flags;
};

typedef struct 	_DEV_BROADCAST_VOLUME	DEV_BROADCAST_VOLUME;
typedef		DEV_BROADCAST_VOLUME	DBTFAR *PDEV_BROADCAST_VOLUME;

#define DBTF_MEDIA	0x0001		// media comings and goings
#define DBTF_NET	0x0002		// network volume

struct _DEV_BROADCAST_PORT { /* */
    DWORD	dbcp_size;
    DWORD	dbcp_devicetype;
    DWORD       dbcp_reserved;
    char	dbcp_name[1];
};

typedef struct 	_DEV_BROADCAST_PORT	DEV_BROADCAST_PORT;
typedef		DEV_BROADCAST_PORT	DBTFAR *PDEV_BROADCAST_PORT;

struct _DEV_BROADCAST_NET { /* */
    DWORD	dbcn_size;
    DWORD	dbcn_devicetype;
    DWORD       dbcn_reserved;
    DWORD	dbcn_resource;
    DWORD	dbcn_flags;
};

typedef struct 	_DEV_BROADCAST_NET	DEV_BROADCAST_NET;
typedef		DEV_BROADCAST_NET	DBTFAR *PDEV_BROADCAST_NET;

#define DBTF_RESOURCE	0x00000001	// network resource
#define DBTF_XPORT	    0x00000002	// new transport coming or going
#define DBTF_SLOWNET    0x00000004  // new incoming transport is slow
					// (dbcn_resource undefined for now)

#define	DBT_VPOWERDAPI	0x8100		// VPOWERD API for Win95

/*
 *  User-defined message types all use wParam = 0xFFFF with the
 *  lParam a pointer to the structure below.
 *
 *  dbud_dbh - DEV_BROADCAST_HEADER must be filled in as usual.
 *
 *  dbud_szName contains a case-sensitive ASCIIZ name which names the
 *  message.  The message name consists of the vendor name, a backslash,
 *  then arbitrary user-defined ASCIIZ text.  For example:
 *
 *	"WidgetWare\QueryScannerShutdown"
 *	"WidgetWare\Video Q39S\AdapterReady"
 *
 *  After the ASCIIZ name, arbitrary information may be provided.
 *  Make sure that dbud_dbh.dbch_size is big enough to encompass
 *  all the data.  And remember that nothing in the structure may
 *  contain pointers.
 */

#define DBT_USERDEFINED	0xFFFF

struct _DEV_BROADCAST_USERDEFINED { /* */
    struct _DEV_BROADCAST_HDR dbud_dbh;
    char	dbud_szName[1];	    /* ASCIIZ name */
/*  BYTE	dbud_rgbUserDefined[];*/ /* User-defined contents */
};

#endif	// _DBT_H
