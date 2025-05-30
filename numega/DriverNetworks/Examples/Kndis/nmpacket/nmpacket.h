// NmPacket.h
//
//=============================================================================
//
// Compuware Corporation
// NuMega Lab
// 9 Townsend West
// Nashua, NH 03060  USA
//
// Copyright (c) 2001 Compuware Corporation. All Rights Reserved.
// Unpublished - rights reserved under the Copyright laws of the
// United States.
//
//=============================================================================
// Generated by DriverWizard version DriverStudio 2.0.0 (Build 4409)
// Requires Compuware's DriverWorks classes
//

#ifndef __NmPacket_h__
#define __NmPacket_h__

#include "kndis.h"

#include "KNdisProtocolDriver.h"
#include "NmPacketControlDevice.h"
#include "NmPacketDevice.h"
   
#define EOL "\n"

class NmPacket : public KDriver
{
	SAFE_DESTRUCTORS
public:
	// Member functions
	virtual  VOID Unload(VOID);
	virtual  NTSTATUS DriverEntry(PUNICODE_STRING RegistryPath);

	// This function is required by the KNdisProtocol framework. 
	// Should be generated by the wizard.
	NDIS_HANDLE GetProtocolHandle(KNdisProtocolBinding*) { return m_Protocol; }

protected:
	// Protocol instance we register
	KNdisProtocol	m_Protocol;

	// Control Device instance
	NmPacketControlDevice* m_pControlDevice;

	// Service/control device name
	static WCHAR sm_wszServiceName[];
};



#endif			// __NmPacket_h__
