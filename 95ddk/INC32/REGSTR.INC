;****************************************************************************
;                                                                           *
; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY     *
; KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       *
; IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR     *
; PURPOSE.                                                                  *
;                                                                           *
; Copyright (C) 1993-95  Microsoft Corporation.  All Rights Reserved.       *
;                                                                           *
;****************************************************************************

ifndef _INC_REGSTR
_INC_REGSTR	EQU	1
REGSTR_KEY_CLASS	EQU	<"Class">
REGSTR_KEY_CONFIG	EQU	<"Config">
REGSTR_KEY_ENUM	EQU	<"Enum">
REGSTR_KEY_ROOTENUM	EQU	<"Root">
REGSTR_KEY_BIOSENUM	EQU	<"BIOS">
REGSTR_KEY_PCMCIAENUM	EQU	<"PCMCIA">
REGSTR_KEY_PCIENUM	EQU	<"PCI">
ifndef NEC_98
REGSTR_KEY_ISAENUM	EQU	<"ISAPnP">
REGSTR_KEY_EISAENUM	EQU	<"EISA">
else
REGSTR_KEY_ISAENUM	EQU	<"C98PnP">
REGSTR_KEY_EISAENUM	EQU	<"NESA">
endif
REGSTR_KEY_LOGCONFIG	EQU	<"LogConfig">
REGSTR_KEY_SYSTEMBOARD	EQU	<"*PNP0C01">
REGSTR_KEY_APM	EQU	<"*PNP0C05">
REGSTR_KEY_INIUPDATE	EQU	<"IniUpdate">
REG_KEY_INSTDEV	EQU	<"Installed">
REGSTR_KEY_DOSOPTCDROM	EQU	<"CD-ROM">
REGSTR_KEY_DOSOPTMOUSE	EQU	<"MOUSE">
REGSTR_DEFAULT_INSTANCE	EQU	<"0000">
REGSTR_PATH_MOTHERBOARD	EQU	<REGSTR_KEY_SYSTEMBOARD"\\"REGSTR_DEFAULT_INSTANCE>
REGSTR_PATH_SETUP	EQU	<"Software\Microsoft\Windows\CurrentVersion">
REGSTR_PATH_PIFCONVERT	EQU	<"Software\Microsoft\Windows\CurrentVersion\PIFConvert">
REGSTR_PATH_MSDOSOPTS	EQU	<"Software\Microsoft\Windows\CurrentVersion\MS-DOSOptions">
REGSTR_PATH_MSDOSEMU	EQU	<"Software\Microsoft\Windows\CurrentVersion\MS-DOS Emulation">
REGSTR_PATH_NEWDOSBOX	EQU	<"Software\Microsoft\Windows\CurrentVersion\MS-DOS Emulation\AppCompat">
REGSTR_PATH_RUNONCE	EQU	<"Software\Microsoft\Windows\CurrentVersion\RunOnce">
REGSTR_PATH_RUN	EQU	<"Software\Microsoft\Windows\CurrentVersion\Run">
REGSTR_PATH_RUNSERVICESONCE	EQU	<"Software\Microsoft\Windows\CurrentVersion\RunServicesOnce">
REGSTR_PATH_RUNSERVICES	EQU	<"Software\Microsoft\Windows\CurrentVersion\RunServices">
REGSTR_PATH_EXPLORER	EQU	<"Software\Microsoft\Windows\CurrentVersion\Explorer">
REGSTR_PATH_DETECT	EQU	<"Software\Microsoft\Windows\CurrentVersion\Detect">
REGSTR_PATH_APPPATHS	EQU	<"Software\Microsoft\Windows\CurrentVersion\App Paths">
REGSTR_PATH_UNINSTALL	EQU	<"Software\Microsoft\Windows\CurrentVersion\Uninstall">
REGSTR_PATH_REALMODENET	EQU	<"Software\Microsoft\Windows\CurrentVersion\Network\Real Mode Net">
REGSTR_PATH_NETEQUIV	EQU	<"Software\Microsoft\Windows\CurrentVersion\Network\Equivalent">
REGSTR_PATH_CVNETWORK	EQU	<"Software\Microsoft\Windows\CurrentVersion\Network">
REGSTR_PATH_IDCONFIGDB	EQU	<"System\CurrentControlSet\Control\IDConfigDB">
REGSTR_PATH_CLASS	EQU	<"System\CurrentControlSet\Services\Class">
REGSTR_PATH_DISPLAYSETTINGS	EQU	<"Display\Settings">
REGSTR_PATH_FONTS	EQU	<"Display\Fonts">
REGSTR_PATH_ENUM	EQU	<"Enum">
REGSTR_PATH_ROOT	EQU	<"Enum\Root">
REGSTR_PATH_SERVICES	EQU	<"System\CurrentControlSet\Services">
REGSTR_PATH_VXD	EQU	<"System\CurrentControlSet\Services\VxD">
REGSTR_PATH_IOS	EQU	<"System\CurrentControlSet\Services\VxD\IOS">
REGSTR_PATH_VMM	EQU	<"System\CurrentControlSet\Services\VxD\VMM">
REGSTR_PATH_VPOWERD	EQU	<"System\CurrentControlSet\Services\VxD\VPOWERD">
REGSTR_PATH_VNETSUP	EQU	<"System\CurrentControlSet\Services\VxD\VNETSUP">
REGSTR_PATH_NWREDIR	EQU	<"System\CurrentControlSet\Services\VxD\NWREDIR">
REGSTR_PATH_NCPSERVER	EQU	<"System\CurrentControlSet\Services\NcpServer\Parameters">
REGSTR_PATH_IOARB	EQU	<"System\CurrentControlSet\Services\Arbitrators\IOArb">
REGSTR_PATH_ADDRARB	EQU	<"System\CurrentControlSet\Services\Arbitrators\AddrArb">
REGSTR_PATH_DMAARB	EQU	<"System\CurrentControlSet\Services\Arbitrators\DMAArb">
REGSTR_PATH_IRQARB	EQU	<"System\CurrentControlSet\Services\Arbitrators\IRQArb">
REGSTR_PATH_CODEPAGE	EQU	<"System\CurrentControlSet\Control\Nls\Codepage">
REGSTR_PATH_FILESYSTEM	EQU	<"System\CurrentControlSet\Control\FileSystem">
REGSTR_PATH_FILESYSTEM_NOVOLTRACK	EQU	<"System\CurrentControlSet\Control\FileSystem\NoVolTrack">
REGSTR_PATH_CDFS	EQU	<"System\CurrentControlSet\Control\FileSystem\CDFS">
REGSTR_PATH_WINBOOT	EQU	<"System\CurrentControlSet\Control\WinBoot">
REGSTR_PATH_INSTALLEDFILES	EQU	<"System\CurrentControlSet\Control\InstalledFiles">
REGSTR_PATH_VMM32FILES	EQU	<"System\CurrentControlSet\Control\VMM32Files">
REGSTR_MAX_VALUE_LENGTH	EQU	256
REGSTR_VAL_BITSPERPIXEL	EQU	<"BitsPerPixel">
REGSTR_VAL_RESOLUTION	EQU	<"Resolution">
REGSTR_VAL_DPILOGICALX	EQU	<"DPILogicalX">
REGSTR_VAL_DPILOGICALY	EQU	<"DPILogicalY">
REGSTR_VAL_DPIPHYSICALX	EQU	<"DPIPhysicalX">
REGSTR_VAL_DPIPHYSICALY	EQU	<"DPIPhysicalY">
REGSTR_VAL_REFRESHRATE	EQU	<"RefreshRate">
REGSTR_VAL_DISPLAYFLAGS	EQU	<"DisplayFlags">
REGSTR_PATH_CONTROLPANEL	EQU	<"Control Panel">
REGSTR_PATH_CONTROLSFOLDER	EQU	<"Software\Microsoft\Windows\CurrentVersion\Controls Folder">
REGSTR_VAL_DOSCP	EQU	<"OEMCP">
REGSTR_VAL_WINCP	EQU	<"ACP">
REGSTR_PATH_DYNA_ENUM	EQU	<"Config Manager\Enum">
REGSTR_VAL_HARDWARE_KEY	EQU	<"HardWareKey">
REGSTR_VAL_ALLOCATION	EQU	<"Allocation">
REGSTR_VAL_PROBLEM	EQU	<"Problem">
REGSTR_VAL_STATUS	EQU	<"Status">
REGSTR_VAL_DONTUSEMEM	EQU	<"DontAllocLastMem">
REGSTR_VAL_SYSTEMROOT	EQU	<"SystemRoot">
REGSTR_VAL_BOOTCOUNT	EQU	<"BootCount">
REGSTR_VAL_REALNETSTART	EQU	<"RealNetStart">
REGSTR_VAL_MEDIA	EQU	<"MediaPath">
REGSTR_VAL_CONFIG	EQU	<"ConfigPath">
REGSTR_VAL_DEVICEPATH	EQU	<"DevicePath">
REGSTR_VAL_SRCPATH	EQU	<"SourcePath">
REGSTR_VAL_OLDWINDIR	EQU	<"OldWinDir">
REGSTR_VAL_SETUPFLAGS	EQU	<"SetupFlags">
REGSTR_VAL_REGOWNER	EQU	<"RegisteredOwner">
REGSTR_VAL_REGORGANIZATION	EQU	<"RegisteredOrganization">
REGSTR_VAL_LICENSINGINFO	EQU	<"LicensingInfo">
REGSTR_VAL_OLDMSDOSVER	EQU	<"OldMSDOSVer">
REGSTR_VAL_FIRSTINSTALLDATETIME	EQU	<"FirstInstallDateTime">
REGSTR_VAL_INSTALLTYPE	EQU	<"InstallType">
REGSTR_VAL_WRAPPER	EQU	<"Wrapper">
IT_COMPACT	EQU	0000H
IT_TYPICAL	EQU	0001H
IT_PORTABLE	EQU	0002H
IT_CUSTOM	EQU	0003H
REGSTR_KEY_SETUP	EQU	<"\Setup">
REGSTR_VAL_BOOTDIR	EQU	<"BootDir">
REGSTR_VAL_WINBOOTDIR	EQU	<"WinbootDir">
REGSTR_VAL_WINDIR	EQU	<"WinDir">
REGSTR_VAL_APPINSTPATH	EQU	<"AppInstallPath">
REGSTR_PATH_EBD	EQU	<REGSTR_PATH_SETUPREGSTR_KEY_SETUP"\\EBD">
REGSTR_KEY_EBDFILESLOCAL	EQU	<"EBDFilesLocale">
REGSTR_KEY_EBDFILESKEYBOARD	EQU	<"EBDFilesKeyboard">
REGSTR_KEY_EBDAUTOEXECBATLOCAL	EQU	<"EBDAutoexecBatLocale">
REGSTR_KEY_EBDAUTOEXECBATKEYBOARD	EQU	<"EBDAutoexecBatKeyboard">
REGSTR_KEY_EBDCONFIGSYSLOCAL	EQU	<"EBDConfigSysLocale">
REGSTR_KEY_EBDCONFIGSYSKEYBOARD	EQU	<"EBDConfigSysKeyboard">
REGSTR_VAL_MSDOSMODE	EQU	<"MSDOSMode">
REGSTR_VAL_MSDOSMODEDISCARD	EQU	<"Discard">
REGSTR_VAL_DOSOPTGLOBALFLAGS	EQU	<"GlobalFlags">
DOSOPTGF_DEFCLEAN	EQU	00000001H
REGSTR_VAL_DOSOPTFLAGS	EQU	<"Flags">
REGSTR_VAL_OPTORDER	EQU	<"Order">
REGSTR_VAL_CONFIGSYS	EQU	<"Config.Sys">
REGSTR_VAL_AUTOEXEC	EQU	<"Autoexec.Bat">
REGSTR_VAL_STDDOSOPTION	EQU	<"StdOption">
REGSTR_VAL_DOSOPTTIP	EQU	<"TipText">
DOSOPTF_DEFAULT	EQU	00000001H
DOSOPTF_SUPPORTED	EQU	00000002H
DOSOPTF_ALWAYSUSE	EQU	00000004H
DOSOPTF_USESPMODE	EQU	00000008H
DOSOPTF_PROVIDESUMB	EQU	00000010H
DOSOPTF_NEEDSETUP	EQU	00000020H
DOSOPTF_INDOSSTART	EQU	00000040H
DOSOPTF_MULTIPLE	EQU	00000080H
SUF_FIRSTTIME	EQU	00000001H
SUF_EXPRESS	EQU	00000002H
SUF_BATCHINF	EQU	00000004H
SUF_CLEAN	EQU	00000008H
SUF_INSETUP	EQU	00000010H
SUF_NETSETUP	EQU	00000020H
SUF_NETHDBOOT	EQU	00000040H
SUF_NETRPLBOOT	EQU	00000080H
SUF_SBSCOPYOK	EQU	00000100H
REGSTR_VAL_DOSPAGER	EQU	<"DOSPager">
REGSTR_VAL_VXDGROUPS	EQU	<"VXDGroups">
REGSTR_VAL_VPOWERDFLAGS	EQU	<"Flags">
VPDF_DISABLEPWRMGMT	EQU	00000001H
VPDF_FORCEAPM10MODE	EQU	00000002H
VPDF_SKIPINTELSLCHECK	EQU	00000004H
VPDF_DISABLEPWRSTATUSPOLL	EQU	00000008H
REGSTR_VAL_WORKGROUP	EQU	<"Workgroup">
REGSTR_VAL_DIRECTHOST	EQU	<"DirectHost">
REGSTR_VAL_FILESHARING	EQU	<"FileSharing">
REGSTR_VAL_PRINTSHARING	EQU	<"PrintSharing">
REGSTR_VAL_FIRSTNETDRIVE	EQU	<"FirstNetworkDrive">
REGSTR_VAL_MAXCONNECTIONS	EQU	<"MaxConnections">
REGSTR_VAL_APISUPPORT	EQU	<"APISupport">
REGSTR_VAL_MAXRETRY	EQU	<"MaxRetry">
REGSTR_VAL_MINRETRY	EQU	<"MinRetry">
REGSTR_VAL_SUPPORTLFN	EQU	<"SupportLFN">
REGSTR_VAL_SUPPORTBURST	EQU	<"SupportBurst">
REGSTR_VAL_SUPPORTTUNNELLING	EQU	<"SupportTunnelling">
REGSTR_VAL_FULLTRACE	EQU	<"FullTrace">
REGSTR_VAL_READCACHING	EQU	<"ReadCaching">
REGSTR_VAL_SHOWDOTS	EQU	<"ShowDots">
REGSTR_VAL_GAPTIME	EQU	<"GapTime">
REGSTR_VAL_SEARCHMODE	EQU	<"SearchMode">
REGSTR_VAL_SHELLVERSION	EQU	<"ShellVersion">
REGSTR_VAL_MAXLIP	EQU	<"MaxLIP">
REGSTR_VAL_PRESERVECASE	EQU	<"PreserveCase">
REGSTR_VAL_OPTIMIZESFN	EQU	<"OptimizeSFN">
REGSTR_VAL_NCP_BROWSEMASTER	EQU	<"BrowseMaster">
REGSTR_VAL_NCP_USEPEERBROWSING	EQU	<"Use_PeerBrowsing">
REGSTR_VAL_NCP_USESAP	EQU	<"Use_Sap">
REGSTR_VAL_WIN31FILESYSTEM	EQU	<"Win31FileSystem">
REGSTR_VAL_PRESERVELONGNAMES	EQU	<"PreserveLongNames">
REGSTR_VAL_DRIVEWRITEBEHIND	EQU	<"DriveWriteBehind">
REGSTR_VAL_ASYNCFILECOMMIT	EQU	<"AsyncFileCommit">
REGSTR_VAL_PATHCACHECOUNT	EQU	<"PathCache">
REGSTR_VAL_NAMECACHECOUNT	EQU	<"NameCache">
REGSTR_VAL_CONTIGFILEALLOC	EQU	<"ContigFileAllocSize">
REGSTR_VAL_VOLIDLETIMEOUT	EQU	<"VolumeIdleTimeout">
REGSTR_VAL_BUFFIDLETIMEOUT	EQU	<"BufferIdleTimeout">
REGSTR_VAL_BUFFAGETIMEOUT	EQU	<"BufferAgeTimeout">
REGSTR_VAL_NAMENUMERICTAIL	EQU	<"NameNumericTail">
REGSTR_VAL_READAHEADTHRESHOLD	EQU	<"ReadAheadThreshold">
REGSTR_VAL_DOUBLEBUFFER	EQU	<"DoubleBuffer">
REGSTR_VAL_SOFTCOMPATMODE	EQU	<"SoftCompatMode">
REGSTR_VAL_DRIVESPINDOWN	EQU	<"DriveSpinDown">
REGSTR_VAL_FORCEPMIO	EQU	<"ForcePMIO">
REGSTR_VAL_FORCERMIO	EQU	<"ForceRMIO">
REGSTR_VAL_LASTBOOTPMDRVS	EQU	<"LastBootPMDrvs">
REGSTR_VAL_VIRTUALHDIRQ	EQU	<"VirtualHDIRQ">
REGSTR_VAL_SRVNAMECACHECOUNT	EQU	<"ServerNameCacheMax">
REGSTR_VAL_SRVNAMECACHE	EQU	<"ServerNameCache">
REGSTR_VAL_SRVNAMECACHENETPROV	EQU	<"ServerNameCacheNumNets">
REGSTR_VAL_AUTOMOUNT	EQU	<"AutoMountDrives">
REGSTR_VAL_COMPRESSIONMETHOD	EQU	<"CompressionAlgorithm">
REGSTR_VAL_COMPRESSIONTHRESHOLD	EQU	<"CompressionThreshold">
REGSTR_VAL_CDCACHESIZE	EQU	<"CacheSize">
REGSTR_VAL_CDPREFETCH	EQU	<"Prefetch">
REGSTR_VAL_CDPREFETCHTAIL	EQU	<"PrefetchTail">
REGSTR_VAL_CDRAWCACHE	EQU	<"RawCache">
REGSTR_VAL_CDEXTERRORS	EQU	<"ExtendedErrors">
REGSTR_VAL_CDSVDSENSE	EQU	<"SVDSense">
REGSTR_VAL_CDSHOWVERSIONS	EQU	<"ShowVersions">
REGSTR_VAL_CDCOMPATNAMES	EQU	<"MSCDEXCompatNames">
REGSTR_VAL_CDNOREADAHEAD	EQU	<"NoReadAhead">
REGSTR_VAL_SCSI	EQU	<"SCSI\">
REGSTR_VAL_ESDI	EQU	<"ESDI\">
REGSTR_VAL_FLOP	EQU	<"FLOP\">
REGSTR_VAL_DISK	EQU	<"GenDisk">
REGSTR_VAL_CDROM	EQU	<"GenCD">
REGSTR_VAL_TAPE	EQU	<"TAPE">
REGSTR_VAL_SCANNER	EQU	<"SCANNER">
REGSTR_VAL_FLOPPY	EQU	<"FLOPPY">
REGSTR_VAL_SCSITID	EQU	<"SCSITargetID">
REGSTR_VAL_SCSILUN	EQU	<"SCSILUN">
REGSTR_VAL_REVLEVEL	EQU	<"RevisionLevel">
REGSTR_VAL_PRODUCTID	EQU	<"ProductId">
REGSTR_VAL_PRODUCTTYPE	EQU	<"ProductType">
REGSTR_VAL_DEVTYPE	EQU	<"DeviceType">
REGSTR_VAL_REMOVABLE	EQU	<"Removable">
REGSTR_VAL_CURDRVLET	EQU	<"CurrentDriveLetterAssignment">
REGSTR_VAL_USRDRVLET	EQU	<"UserDriveLetterAssignment">
REGSTR_VAL_SYNCDATAXFER	EQU	<"SyncDataXfer">
REGSTR_VAL_AUTOINSNOTE	EQU	<"AutoInsertNotification">
REGSTR_VAL_DISCONNECT	EQU	<"Disconnect">
REGSTR_VAL_INT13	EQU	<"Int13">
REGSTR_VAL_PMODE_INT13	EQU	<"PModeInt13">
REGSTR_VAL_USERSETTINGS	EQU	<"AdapterSettings">
REGSTR_VAL_NOIDE	EQU	<"NoIDE">
REGSTR_VAL_DISKCLASSNAME	EQU	<"DiskDrive">
REGSTR_VAL_CDROMCLASSNAME	EQU	<"CDROM">
REGSTR_VAL_FORCELOAD	EQU	<"ForceLoadPD">
REGSTR_VAL_FORCEFIFO	EQU	<"ForceFIFO">
REGSTR_VAL_FORCECL		EQU <"ForceChangeLine">
REGSTR_VAL_NOUSECLASS	EQU	<"NoUseClass">
REGSTR_VAL_NOINSTALLCLASS	EQU	<"NoInstallClass">
REGSTR_VAL_NODISPLAYCLASS	EQU	<"NoDisplayClass">
REGSTR_VAL_SILENTINSTALL	EQU	<"SilentInstall">
REGSTR_KEY_PCMCIA_CLASS	EQU	<"PCMCIA">
REGSTR_KEY_SCSI_CLASS	EQU	<"SCSIAdapter">
REGSTR_KEY_PORTS_CLASS	EQU	<"ports">
REGSTR_KEY_MEDIA_CLASS	EQU	<"MEDIA">
REGSTR_KEY_DISPLAY_CLASS	EQU	<"Display">
REGSTR_KEY_KEYBOARD_CLASS	EQU	<"Keyboard">
REGSTR_KEY_MOUSE_CLASS	EQU	<"Mouse">
REGSTR_KEY_MONITOR_CLASS	EQU	<"Monitor">
REGSTR_VAL_PCMCIA_OPT	EQU	<"Options">
PCMCIA_OPT_HAVE_SOCKET	EQU	00000001H
PCMCIA_OPT_AUTOMEM	EQU	00000004H
PCMCIA_OPT_NO_SOUND	EQU	00000008H
PCMCIA_OPT_NO_AUDIO	EQU	00000010H
PCMCIA_OPT_NO_APMREMOVE	EQU	00000020H
REGSTR_VAL_PCMCIA_MEM	EQU	<"Memory">
PCMCIA_DEF_MEMBEGIN	EQU	000C0000H
PCMCIA_DEF_MEMEND	EQU	00FFFFFFH
PCMCIA_DEF_MEMLEN	EQU	00001000H
REGSTR_VAL_PCMCIA_ALLOC	EQU	<"AllocMemWin">
REGSTR_VAL_PCMCIA_ATAD	EQU	<"ATADelay">
REGSTR_VAL_PCMCIA_SIZ	EQU	<"MinRegionSize">
PCMCIA_DEF_MIN_REGION	EQU	00010000H
REGSTR_VAL_P1284MDL	EQU	<"Model">
REGSTR_VAL_P1284MFG	EQU	<"Manufacturer">
REGSTR_VAL_ISAPNP	EQU	<"ISAPNP">
REGSTR_VAL_ISAPNP_RDP_OVERRIDE	EQU	<"RDPOverRide">
REGSTR_VAL_PCI	EQU	<"PCI">
REGSTR_PCI_OPTIONS	EQU	<"Options">
REGSTR_PCI_DUAL_IDE	EQU	<"PCIDualIDE">
PCI_OPTIONS_USE_BIOS	EQU	00000001H
PCI_OPTIONS_USE_IRQ_STEERING	EQU	00000002H
PCI_FLAG_NO_VIDEO_IRQ	EQU	00000001H
PCI_FLAG_PCMCIA_WANT_IRQ	EQU	00000002H
PCI_FLAG_DUAL_IDE	EQU	00000004H
PCI_FLAG_NO_ENUM_AT_ALL	EQU	00000008H
PCI_FLAG_ENUM_NO_RESOURCE	EQU	00000010H
PCI_FLAG_NEED_DWORD_ACCESS	EQU	00000020H
PCI_FLAG_SINGLE_FUNCTION	EQU	00000040H
PCI_FLAG_ALWAYS_ENABLED	EQU	00000080H
PCI_FLAG_IS_IDE	EQU	00000100H
PCI_FLAG_IS_VIDEO	EQU	00000200H
PCI_FLAG_FAIL_START	EQU	00000400H
REGSTR_KEY_CRASHES	EQU	<"Crashes">
REGSTR_KEY_DANGERS	EQU	<"Dangers">
REGSTR_KEY_DETMODVARS	EQU	<"DetModVars">
REGSTR_KEY_NDISINFO	EQU	<"NDISInfo">
REGSTR_VAL_PROTINIPATH	EQU	<"ProtIniPath">
REGSTR_VAL_RESOURCES	EQU	<"Resources">
REGSTR_VAL_CRASHFUNCS	EQU	<"CrashFuncs">
REGSTR_VAL_CLASS	EQU	<"Class">
REGSTR_VAL_DEVDESC	EQU	<"DeviceDesc">
REGSTR_VAL_BOOTCONFIG	EQU	<"BootConfig">
REGSTR_VAL_DETFUNC	EQU	<"DetFunc">
REGSTR_VAL_DETFLAGS	EQU	<"DetFlags">
REGSTR_VAL_COMPATIBLEIDS	EQU	<"CompatibleIDs">
REGSTR_VAL_DETCONFIG	EQU	<"DetConfig">
REGSTR_VAL_VERIFYKEY	EQU	<"VerifyKey">
REGSTR_VAL_COMINFO	EQU	<"ComInfo">
REGSTR_VAL_INFNAME	EQU	<"InfName">
REGSTR_VAL_CARDSPECIFIC	EQU	<"CardSpecific">
REGSTR_VAL_NETOSTYPE	EQU	<"NetOSType">
REGSTR_DATA_NETOS_NDIS	EQU	<"NDIS">
REGSTR_DATA_NETOS_ODI	EQU	<"ODI">
REGSTR_DATA_NETOS_IPX	EQU	<"IPX">
REGSTR_VAL_MFG	EQU	<"Mfg">
REGSTR_VAL_SCAN_ONLY_FIRST	EQU	<"ScanOnlyFirstDrive">
REGSTR_VAL_SHARE_IRQ	EQU	<"ForceIRQSharing">
REGSTR_VAL_NONSTANDARD_ATAPI	EQU	<"NonStandardATAPI">
REGSTR_VAL_IDE_FORCE_SERIALIZE	EQU	<"ForceSerialization">
REGSTR_VAL_MAX_HCID_LEN	EQU	1024
REGSTR_VAL_HWREV	EQU	<"HWRevision">
REGSTR_VAL_ENABLEINTS	EQU	<"EnableInts">
REGDF_NOTDETIO	EQU	00000001H
REGDF_NOTDETMEM	EQU	00000002H
REGDF_NOTDETIRQ	EQU	00000004H
REGDF_NOTDETDMA	EQU	00000008H
REGDF_NOTDETALL	EQU	(REGDF_NOTDETIO OR REGDF_NOTDETMEM OR REGDF_NOTDETIRQ OR REGDF_NOTDETDMA)
REGDF_NEEDFULLCONFIG	EQU	00000010H
REGDF_GENFORCEDCONFIG	EQU	00000020H
REGDF_NODETCONFIG	EQU	00008000H
REGDF_CONFLICTIO	EQU	00010000H
REGDF_CONFLICTMEM	EQU	00020000H
REGDF_CONFLICTIRQ	EQU	00040000H
REGDF_CONFLICTDMA	EQU	00080000H
REGDF_CONFLICTALL	EQU	(REGDF_CONFLICTIO OR REGDF_CONFLICTMEM OR REGDF_CONFLICTIRQ OR REGDF_CONFLICTDMA)
REGDF_MAPIRQ2TO9	EQU	00100000H
REGDF_NOTVERIFIED	EQU	80000000H
REGSTR_VAL_APMBIOSVER	EQU	<"APMBiosVer">
REGSTR_VAL_APMFLAGS	EQU	<"APMFlags">
REGSTR_VAL_SLSUPPORT	EQU	<"SLSupport">
REGSTR_VAL_MACHINETYPE	EQU	<"MachineType">
REGSTR_VAL_SETUPMACHINETYPE	EQU	<"SetupMachineType">
REGSTR_MACHTYPE_UNKNOWN	EQU	<"Unknown">
REGSTR_MACHTYPE_IBMPC	EQU	<"IBM PC">
REGSTR_MACHTYPE_IBMPCJR	EQU	<"IBM PCjr">
REGSTR_MACHTYPE_IBMPCCONV	EQU	<"IBM PC Convertible">
REGSTR_MACHTYPE_IBMPCXT	EQU	<"IBM PC/XT">
REGSTR_MACHTYPE_IBMPCXT_286	EQU	<"IBM PC/XT 286">
REGSTR_MACHTYPE_IBMPCAT	EQU	<"IBM PC/AT">
REGSTR_MACHTYPE_IBMPS2_25	EQU	<"IBM PS/2-25">
REGSTR_MACHTYPE_IBMPS2_30_286	EQU	<"IBM PS/2-30 286">
REGSTR_MACHTYPE_IBMPS2_30	EQU	<"IBM PS/2-30">
REGSTR_MACHTYPE_IBMPS2_50	EQU	<"IBM PS/2-50">
REGSTR_MACHTYPE_IBMPS2_50Z	EQU	<"IBM PS/2-50Z">
REGSTR_MACHTYPE_IBMPS2_55SX	EQU	<"IBM PS/2-55SX">
REGSTR_MACHTYPE_IBMPS2_60	EQU	<"IBM PS/2-60">
REGSTR_MACHTYPE_IBMPS2_65SX	EQU	<"IBM PS/2-65SX">
REGSTR_MACHTYPE_IBMPS2_70	EQU	<"IBM PS/2-70">
REGSTR_MACHTYPE_IBMPS2_P70	EQU	<"IBM PS/2-P70">
REGSTR_MACHTYPE_IBMPS2_70_80	EQU	<"IBM PS/2-70/80">
REGSTR_MACHTYPE_IBMPS2_80	EQU	<"IBM PS/2-80">
REGSTR_MACHTYPE_IBMPS2_90	EQU	<"IBM PS/2-90">
REGSTR_MACHTYPE_IBMPS1	EQU	<"IBM PS/1">
REGSTR_MACHTYPE_PHOENIX_PCAT	EQU	<"Phoenix PC/AT Compatible">
REGSTR_MACHTYPE_HP_VECTRA	EQU	<"HP Vectra">
REGSTR_MACHTYPE_ATT_PC	EQU	<"AT&T PC">
REGSTR_MACHTYPE_ZENITH_PC	EQU	<"Zenith PC">
REGSTR_VAL_APMMENUSUSPEND	EQU	<"APMMenuSuspend">
APMMENUSUSPEND_DISABLED	EQU	0
APMMENUSUSPEND_ENABLED	EQU	1
APMMENUSUSPEND_UNDOCKED	EQU	2
APMMENUSUSPEND_NOCHANGE	EQU	80H
REGSTR_VAL_BUSTYPE	EQU	<"BusType">
REGSTR_VAL_CPU	EQU	<"CPU">
REGSTR_VAL_NDP	EQU	<"NDP">
REGSTR_VAL_PNPBIOSVER	EQU	<"PnPBIOSVer">
REGSTR_VAL_PNPSTRUCOFFSET	EQU	<"PnPStrucOffset">
REGSTR_VAL_PCIBIOSVER	EQU	<"PCIBIOSVer">
REGSTR_VAL_HWMECHANISM	EQU	<"HWMechanism">
REGSTR_VAL_LASTPCIBUSNUM	EQU	<"LastPCIBusNum">
REGSTR_VAL_CONVMEM	EQU	<"ConvMem">
REGSTR_VAL_EXTMEM	EQU	<"ExtMem">
REGSTR_VAL_COMPUTERNAME	EQU	<"ComputerName">
REGSTR_VAL_BIOSNAME	EQU	<"BIOSName">
REGSTR_VAL_BIOSVERSION	EQU	<"BIOSVersion">
REGSTR_VAL_BIOSDATE	EQU	<"BIOSDate">
REGSTR_VAL_MODEL	EQU	<"Model">
REGSTR_VAL_SUBMODEL	EQU	<"Submodel">
REGSTR_VAL_REVISION	EQU	<"Revision">
REGSTR_VAL_FIFODEPTH	EQU	<"FIFODepth">
REGSTR_VAL_RDINTTHRESHOLD	EQU	<"RDIntThreshold">
REGSTR_VAL_WRINTTHRESHOLD	EQU	<"WRIntThreshold">
REGSTR_VAL_PRIORITY	EQU	<"Priority">
REGSTR_VAL_DRIVER	EQU	<"Driver">
REGSTR_VAL_FUNCDESC	EQU	<"FunctionDesc">
REGSTR_VAL_FORCEDCONFIG	EQU	<"ForcedConfig">
REGSTR_VAL_CONFIGFLAGS	EQU	<"ConfigFlags">
REGSTR_VAL_CSCONFIGFLAGS	EQU	<"CSConfigFlags">
CONFIGFLAG_DISABLED	EQU	00000001H
CONFIGFLAG_REMOVED	EQU	00000002H
CONFIGFLAG_MANUAL_INSTALL	EQU	00000004H
CONFIGFLAG_IGNORE_BOOT_LC	EQU	00000008H
CONFIGFLAG_NET_BOOT	EQU	00000010H
CONFIGFLAG_REINSTALL	EQU	00000020H
CONFIGFLAG_FAILEDINSTALL	EQU	00000040H
CONFIGFLAG_CANTSTOPACHILD	EQU	00000080H
CONFIGFLAG_OKREMOVEROM	EQU	00000100H
CONFIGFLAG_NOREMOVEEXIT	EQU	00000200H
CSCONFIGFLAG_BITS	EQU	00000007H
CSCONFIGFLAG_DISABLED	EQU	00000001H
CSCONFIGFLAG_DO_NOT_CREATE	EQU	00000002H
CSCONFIGFLAG_DO_NOT_START	EQU	00000004H
DMSTATEFLAG_APPLYTOALL	EQU	00000001H
REGSTR_VAL_ROOT_DEVNODE	EQU	<"HTREE\ROOT\0">
REGSTR_VAL_RESERVED_DEVNODE	EQU	<"HTREE\RESERVED\0">
REGSTR_PATH_READDATAPORT	EQU	<REGSTR_KEY_ISAENUM"\\ReadDataPort\\0">
REGSTR_PATH_MULTI_FUNCTION	EQU	<"MF">
REGSTR_VAL_RESOURCE_MAP	EQU	<"ResourceMap">
REGSTR_PATH_CHILD_PREFIX	EQU	<"Child">
NUM_RESOURCE_MAP	EQU	256
REGSTR_VAL_MF_FLAGS	EQU	<"MFFlags">
MF_FLAGS_EVEN_IF_NO_RESOURCE	EQU	00000001H
MF_FLAGS_NO_CREATE_IF_NO_RESOURCE	EQU	00000002H
MF_FLAGS_FILL_IN_UNKNOWN_RESOURCE	EQU	00000004H
MF_FLAGS_CREATE_BUT_NO_SHOW_DISABLED	EQU	00000008H
ifndef NEC_98
REGSTR_VAL_EISA_RANGES	EQU	<"EISARanges">
REGSTR_VAL_EISA_FUNCTIONS	EQU	<"EISAFunctions">
REGSTR_VAL_EISA_FUNCTIONS_MASK	EQU	<"EISAFunctionsMask">
REGSTR_VAL_EISA_FLAGS	EQU	<"EISAFlags">
REGSTR_VAL_EISA_SIMULATE_INT15	EQU	<"EISASimulateInt15">
else
REGSTR_VAL_EISA_RANGES	EQU	<"NESARanges">
REGSTR_VAL_EISA_FUNCTIONS	EQU	<"NESAFunctions">
REGSTR_VAL_EISA_FUNCTIONS_MASK	EQU	<"NESAFunctionsMask">
REGSTR_VAL_EISA_FLAGS	EQU	<"NESAFlags">
REGSTR_VAL_EISA_SIMULATE_INT15	EQU	<"NESASimulateInt15">
endif
EISAFLAG_NO_IO_MERGE	EQU	00000001H
EISAFLAG_SLOT_IO_FIRST	EQU	00000002H
EISA_NO_MAX_FUNCTION	EQU	0FFH
NUM_EISA_RANGES	EQU	4
REGSTR_VAL_DRVDESC	EQU	<"DriverDesc">
REGSTR_VAL_DEVLOADER	EQU	<"DevLoader">
REGSTR_VAL_STATICVXD	EQU	<"StaticVxD">
REGSTR_VAL_PROPERTIES	EQU	<"Properties">
REGSTR_VAL_MANUFACTURER	EQU	<"Manufacturer">
REGSTR_VAL_EXISTS	EQU	<"Exists">
REGSTR_VAL_CMENUMFLAGS	EQU	<"CMEnumFlags">
REGSTR_VAL_CMDRIVFLAGS	EQU	<"CMDrivFlags">
REGSTR_VAL_ENUMERATOR	EQU	<"Enumerator">
REGSTR_VAL_DEVICEDRIVER	EQU	<"DeviceDriver">
REGSTR_VAL_PORTNAME	EQU	<"PortName">
REGSTR_VAL_INFPATH	EQU	<"InfPath">
REGSTR_VAL_INFSECTION	EQU	<"InfSection">
REGSTR_VAL_POLLING	EQU	<"Polling">
REGSTR_VAL_DONTLOADIFCONFLICT	EQU	<"DontLoadIfConflict">
REGSTR_VAL_PORTSUBCLASS	EQU	<"PortSubClass">
REGSTR_VAL_NETCLEAN	EQU	<"NetClean">
REGSTR_VAL_IDE_NO_SERIALIZE	EQU	<"IDENoSerialize">
REGSTR_VAL_NOCMOSORFDPT	EQU	<"NoCMOSorFDPT">
REGSTR_VAL_COMVERIFYBASE	EQU	<"COMVerifyBase">
REGSTR_KEY_OVERRIDE	EQU	<"Override">
REGSTR_VAL_CONFIGMG	EQU	<"CONFIGMG">
REGSTR_VAL_SYSDM	EQU	<"SysDM">
REGSTR_VAL_SYSDMFUNC	EQU	<"SysDMFunc">
REGSTR_VAL_PRIVATE	EQU	<"Private">
REGSTR_VAL_PRIVATEFUNC	EQU	<"PrivateFunc">
REGSTR_VAL_DETECT	EQU	<"Detect">
REGSTR_VAL_DETECTFUNC	EQU	<"DetectFunc">
REGSTR_VAL_ASKFORCONFIG	EQU	<"AskForConfig">
REGSTR_VAL_ASKFORCONFIGFUNC	EQU	<"AskForConfigFunc">
REGSTR_VAL_WAITFORUNDOCK	EQU	<"WaitForUndock">
REGSTR_VAL_WAITFORUNDOCKFUNC	EQU	<"WaitForUndockFunc">
REGSTR_VAL_REMOVEROMOKAY	EQU	<"RemoveRomOkay">
REGSTR_VAL_REMOVEROMOKAYFUNC	EQU	<"RemoveRomOkayFunc">
REGSTR_VAL_CURCONFIG	EQU	<"CurrentConfig">
REGSTR_VAL_FRIENDLYNAME	EQU	<"FriendlyName">
REGSTR_VAL_CURRENTCONFIG	EQU	<"CurrentConfig">
REGSTR_VAL_MAP	EQU	<"Map">
REGSTR_VAL_ID	EQU	<"CurrentID">
REGSTR_VAL_DOCKED	EQU	<"CurrentDockedState">
REGSTR_VAL_CHECKSUM	EQU	<"CurrentChecksum">
REGSTR_VAL_HWDETECT	EQU	<"HardwareDetect">
REGSTR_VAL_INHIBITRESULTS	EQU	<"InhibitResults">
REGSTR_VAL_PROFILEFLAGS	EQU	<"ProfileFlags">
REGSTR_KEY_PCMCIA	EQU	<"PCMCIA\">
REGSTR_KEY_PCUNKNOWN	EQU	<"UNKNOWN_MANUFACTURER">
REGSTR_VAL_PCSSDRIVER	EQU	<"Driver">
REGSTR_KEY_PCMTD	EQU	<"MTD-">
REGSTR_VAL_PCMTDRIVER	EQU	<"MTD">
REGSTR_VAL_HARDWAREID	EQU	<"HardwareID">
REGSTR_VAL_INSTALLER	EQU	<"Installer">
REGSTR_VAL_INSICON	EQU	<"Icon">
REGSTR_VAL_ENUMPROPPAGES	EQU	<"EnumPropPages">
REGSTR_VAL_BASICPROPERTIES	EQU	<"BasicProperties">
REGSTR_VAL_PRIVATEPROBLEM	EQU	<"PrivateProblem">
REGSTR_KEY_CURRENT	EQU	<"Current">
REGSTR_KEY_DEFAULT	EQU	<"Default">
REGSTR_KEY_MODES	EQU	<"Modes">
REGSTR_VAL_MODE	EQU	<"Mode">
REGSTR_VAL_BPP	EQU	<"BPP">
REGSTR_VAL_HRES	EQU	<"HRes">
REGSTR_VAL_VRES	EQU	<"VRes">
REGSTR_VAL_FONTSIZE	EQU	<"FontSize">
REGSTR_VAL_DRV	EQU	<"drv">
REGSTR_VAL_GRB	EQU	<"grb">
REGSTR_VAL_VDD	EQU	<"vdd">
REGSTR_VAL_VER	EQU	<"Ver">
REGSTR_VAL_MAXRES	EQU	<"MaxResolution">
REGSTR_VAL_DPMS	EQU	<"DPMS">
REGSTR_VAL_RESUMERESET	EQU	<"ResumeReset">
REGSTR_VAL_DESCRIPTION	EQU	<"Description">
REGSTR_KEY_SYSTEM	EQU	<"System">
REGSTR_KEY_USER	EQU	<"User">
REGSTR_VAL_DPI	EQU	<"dpi">
REGSTR_VAL_PCICOPTIONS	EQU	<"PCICOptions">
ifndef NEC_98
PCIC_DEFAULT_IRQMASK	EQU	4EB8H
else
PCIC_DEFAULT_IRQMASK	EQU	1468H
endif
PCIC_DEFAULT_NUMSOCKETS	EQU	0
REGSTR_VAL_PCICIRQMAP	EQU	<"PCICIRQMap">
REGSTR_PATH_APPEARANCE	EQU	<"Control Panel\Appearance">
REGSTR_PATH_LOOKSCHEMES	EQU	<"Control Panel\Appearance\Schemes">
REGSTR_VAL_CUSTOMCOLORS	EQU	<"CustomColors">
REGSTR_PATH_SCREENSAVE	EQU	<"Control Panel\Desktop">
REGSTR_VALUE_USESCRPASSWORD	EQU	<"ScreenSaveUsePassword">
REGSTR_VALUE_SCRPASSWORD	EQU	<"ScreenSave_Data">
REGSTR_VALUE_LOWPOWERTIMEOUT	EQU	<"ScreenSaveLowPowerTimeout">
REGSTR_VALUE_POWEROFFTIMEOUT	EQU	<"ScreenSavePowerOffTimeout">
REGSTR_VALUE_LOWPOWERACTIVE	EQU	<"ScreenSaveLowPowerActive">
REGSTR_VALUE_POWEROFFACTIVE	EQU	<"ScreenSavePowerOffActive">
REGSTR_PATH_WINDOWSAPPLETS	EQU	<"Software\Microsoft\Windows\CurrentVersion\Applets">
REGSTR_PATH_SYSTRAY	EQU	<"Software\Microsoft\Windows\CurrentVersion\Applets\SysTray">
REGSTR_VAL_SYSTRAYSVCS	EQU	<"Services">
REGSTR_VAL_SYSTRAYBATFLAGS	EQU	<"PowerFlags">
REGSTR_VAL_SYSTRAYPCCARDFLAGS	EQU	<"PCMCIAFlags">
REGSTR_PATH_NETWORK_USERSETTINGS	EQU	<"Network">
REGSTR_KEY_NETWORK_PERSISTENT	EQU	<"\Persistent">
REGSTR_KEY_NETWORK_RECENT	EQU	<"\Recent">
REGSTR_VAL_REMOTE_PATH	EQU	<"RemotePath">
REGSTR_VAL_USER_NAME	EQU	<"UserName">
REGSTR_VAL_PROVIDER_NAME	EQU	<"ProviderName">
REGSTR_VAL_CONNECTION_TYPE	EQU	<"ConnectionType">
REGSTR_VAL_UPGRADE	EQU	<"Upgrade">
REGSTR_KEY_LOGON	EQU	<"\Logon">
REGSTR_VAL_MUSTBEVALIDATED	EQU	<"MustBeValidated">
REGSTR_VAL_RUNLOGINSCRIPT	EQU	<"ProcessLoginScript">
REGSTR_KEY_NETWORKPROVIDER	EQU	<"\NetworkProvider">
REGSTR_PATH_NW32NETPROVIDER	EQU	<REGSTR_PATH_SERVICES"\\NWNP32"REGSTR_KEY_NETWORKPROVIDER>
REGSTR_PATH_MS32NETPROVIDER	EQU	<REGSTR_PATH_SERVICES"\\MSNP32"REGSTR_KEY_NETWORKPROVIDER>
REGSTR_VAL_AUTHENT_AGENT	EQU	<"AuthenticatingAgent">
REGSTR_VAL_PREFREDIR	EQU	<"PreferredRedir">
REGSTR_VAL_AUTOSTART	EQU	<"AutoStart">
REGSTR_VAL_AUTOLOGON	EQU	<"AutoLogon">
REGSTR_VAL_NETCARD	EQU	<"Netcard">
REGSTR_VAL_TRANSPORT	EQU	<"Transport">
REGSTR_VAL_DYNAMIC	EQU	<"Dynamic">
REGSTR_VAL_TRANSITION	EQU	<"Transition">
REGSTR_VAL_STATICDRIVE	EQU	<"StaticDrive">
REGSTR_VAL_LOADHI	EQU	<"LoadHi">
REGSTR_VAL_LOADRMDRIVERS	EQU	<"LoadRMDrivers">
REGSTR_VAL_SETUPN	EQU	<"SetupN">
REGSTR_VAL_SETUPNPATH	EQU	<"SetupNPath">
REGSTR_VAL_WRKGRP_FORCEMAPPING	EQU	<"WrkgrpForceMapping">
REGSTR_VAL_WRKGRP_REQUIRED	EQU	<"WrkgrpRequired">
REGSTR_PATH_CURRENT_CONTROL_SET	EQU	<"System\CurrentControlSet\Control">
REGSTR_VAL_CURRENT_USER	EQU	<"Current User">
REGSTR_PATH_PWDPROVIDER	EQU	<"System\CurrentControlSet\Control\PwdProvider">
REGSTR_VAL_PWDPROVIDER_PATH	EQU	<"ProviderPath">
REGSTR_VAL_PWDPROVIDER_DESC	EQU	<"Description">
REGSTR_VAL_PWDPROVIDER_CHANGEPWD	EQU	<"ChangePassword">
REGSTR_VAL_PWDPROVIDER_CHANGEPWDHWND	EQU	<"ChangePasswordHwnd">
REGSTR_VAL_PWDPROVIDER_GETPWDSTATUS	EQU	<"GetPasswordStatus">
REGSTR_VAL_PWDPROVIDER_ISNP	EQU	<"NetworkProvider">
REGSTR_VAL_PWDPROVIDER_CHANGEORDER	EQU	<"ChangeOrder">
REGSTR_PATH_POLICIES	EQU	<"Software\Microsoft\Windows\CurrentVersion\Policies">
REGSTR_PATH_UPDATE	EQU	<"System\CurrentControlSet\Control\Update">
REGSTR_VALUE_ENABLE	EQU	<"Enable">
REGSTR_VALUE_VERBOSE	EQU	<"Verbose">
REGSTR_VALUE_NETPATH	EQU	<"NetworkPath">
REGSTR_VALUE_DEFAULTLOC	EQU	<"UseDefaultNetLocation">
REGSTR_KEY_NETWORK	EQU	<"Network">
REGSTR_KEY_SYSTEM	EQU	<"System">
REGSTR_KEY_PRINTERS	EQU	<"Printers">
REGSTR_KEY_WINOLDAPP	EQU	<"WinOldApp">
REGSTR_VAL_NOFILESHARING	EQU	<"NoFileSharing">
REGSTR_VAL_NOPRINTSHARING	EQU	<"NoPrintSharing">
REGSTR_VAL_NOFILESHARINGCTRL	EQU	<"NoFileSharingControl">
REGSTR_VAL_NOPRINTSHARINGCTRL	EQU	<"NoPrintSharingControl">
REGSTR_VAL_HIDESHAREPWDS	EQU	<"HideSharePwds">
REGSTR_VAL_DISABLEPWDCACHING	EQU	<"DisablePwdCaching">
REGSTR_VAL_ALPHANUMPWDS	EQU	<"AlphanumPwds">
REGSTR_VAL_NETSETUP_DISABLE	EQU	<"NoNetSetup">
REGSTR_VAL_NETSETUP_NOCONFIGPAGE	EQU	<"NoNetSetupConfigPage">
REGSTR_VAL_NETSETUP_NOIDPAGE	EQU	<"NoNetSetupIDPage">
REGSTR_VAL_NETSETUP_NOSECURITYPAGE	EQU	<"NoNetSetupSecurityPage">
REGSTR_VAL_SYSTEMCPL_NOVIRTMEMPAGE	EQU	<"NoVirtMemPage">
REGSTR_VAL_SYSTEMCPL_NODEVMGRPAGE	EQU	<"NoDevMgrPage">
REGSTR_VAL_SYSTEMCPL_NOCONFIGPAGE	EQU	<"NoConfigPage">
REGSTR_VAL_SYSTEMCPL_NOFILESYSPAGE	EQU	<"NoFileSysPage">
REGSTR_VAL_DISPCPL_NODISPCPL	EQU	<"NoDispCPL">
REGSTR_VAL_DISPCPL_NOBACKGROUNDPAGE	EQU	<"NoDispBackgroundPage">
REGSTR_VAL_DISPCPL_NOSCRSAVPAGE	EQU	<"NoDispScrSavPage">
REGSTR_VAL_DISPCPL_NOAPPEARANCEPAGE	EQU	<"NoDispAppearancePage">
REGSTR_VAL_DISPCPL_NOSETTINGSPAGE	EQU	<"NoDispSettingsPage">
REGSTR_VAL_SECCPL_NOSECCPL	EQU	<"NoSecCPL">
REGSTR_VAL_SECCPL_NOPWDPAGE	EQU	<"NoPwdPage">
REGSTR_VAL_SECCPL_NOADMINPAGE	EQU	<"NoAdminPage">
REGSTR_VAL_SECCPL_NOPROFILEPAGE	EQU	<"NoProfilePage">
REGSTR_VAL_PRINTERS_HIDETABS	EQU	<"NoPrinterTabs">
REGSTR_VAL_PRINTERS_NODELETE	EQU	<"NoDeletePrinter">
REGSTR_VAL_PRINTERS_NOADD	EQU	<"NoAddPrinter">
REGSTR_VAL_WINOLDAPP_DISABLED	EQU	<"Disabled">
REGSTR_VAL_WINOLDAPP_NOREALMODE	EQU	<"NoRealMode">
REGSTR_VAL_NOENTIRENETWORK	EQU	<"NoEntireNetwork">
REGSTR_VAL_NOWORKGROUPCONTENTS	EQU	<"NoWorkgroupContents">
REGSTR_VAL_MINPWDLEN	EQU	<"MinPwdLen">
REGSTR_VAL_PWDEXPIRATION	EQU	<"PwdExpiration">
REGSTR_VAL_WIN31PROVIDER	EQU	<"Win31Provider">
REGSTR_VAL_DISABLEREGTOOLS	EQU	<"DisableRegistryTools">
REGSTR_PATH_WINLOGON	EQU	<"Software\Microsoft\Windows\CurrentVersion\Winlogon">
REGSTR_VAL_LEGALNOTICECAPTION	EQU	<"LegalNoticeCaption">
REGSTR_VAL_LEGALNOTICETEXT	EQU	<"LegalNoticeText">
REGSTR_VAL_RESTRICTRUN	EQU	<"RestrictRun">
REGSTR_KEY_POL_USERS	EQU	<"Users">
REGSTR_KEY_POL_COMPUTERS	EQU	<"Computers">
REGSTR_KEY_POL_USERGROUPS	EQU	<"UserGroups">
REGSTR_KEY_POL_DEFAULT	EQU	<".default">
REGSTR_KEY_POL_USERGROUPDATA	EQU	<"GroupData\UserGroups\Priority">
REGSTR_PATH_TIMEZONE	EQU	<"System\CurrentControlSet\Control\TimeZoneInformation">
REGSTR_VAL_TZBIAS	EQU	<"Bias">
REGSTR_VAL_TZDLTBIAS	EQU	<"DaylightBias">
REGSTR_VAL_TZSTDBIAS	EQU	<"StandardBias">
REGSTR_VAL_TZACTBIAS	EQU	<"ActiveTimeBias">
REGSTR_VAL_TZDLTFLAG	EQU	<"DaylightFlag">
REGSTR_VAL_TZSTDSTART	EQU	<"StandardStart">
REGSTR_VAL_TZDLTSTART	EQU	<"DaylightStart">
REGSTR_VAL_TZDLTNAME	EQU	<"DaylightName">
REGSTR_VAL_TZSTDNAME	EQU	<"StandardName">
REGSTR_VAL_TZNOCHANGESTART	EQU	<"NoChangeStart">
REGSTR_VAL_TZNOCHANGEEND	EQU	<"NoChangeEnd">
REGSTR_VAL_TZNOAUTOTIME	EQU	<"DisableAutoDaylightTimeSet">
REGSTR_PATH_FLOATINGPOINTPROCESSOR	EQU	<"HARDWARE\DESCRIPTION\System\FloatingPointProcessor">
REGSTR_PATH_FLOATINGPOINTPROCESSOR0	EQU	<"HARDWARE\DESCRIPTION\System\FloatingPointProcessor\0">
REGSTR_PATH_COMPUTRNAME	EQU	<"System\CurrentControlSet\Control\ComputerName\ComputerName">
REGSTR_VAL_COMPUTRNAME	EQU	<"ComputerName">
REGSTR_PATH_SHUTDOWN	EQU	<"System\CurrentControlSet\Control\Shutdown">
REGSTR_VAL_FORCEREBOOT	EQU	<"ForceReboot">
REGSTR_VAL_SETUPPROGRAMRAN	EQU	<"SetupProgramRan">
REGSTR_VAL_DOES_POLLING	EQU	<"PollingSupportNeeded">
REGSTR_PATH_KNOWNDLLS	EQU	<"System\CurrentControlSet\Control\SessionManager\KnownDLLs">
REGSTR_PATH_KNOWN16DLLS	EQU	<"System\CurrentControlSet\Control\SessionManager\Known16DLLs">
REGSTR_PATH_CHECKVERDLLS	EQU	<"System\CurrentControlSet\Control\SessionManager\CheckVerDLLs">
REGSTR_PATH_WARNVERDLLS	EQU	<"System\CurrentControlSet\Control\SessionManager\WarnVerDLLs">
REGSTR_PATH_HACKINIFILE	EQU	<"System\CurrentControlSet\Control\SessionManager\HackIniFiles">
REGSTR_PATH_CHECKBADAPPS	EQU	<"System\CurrentControlSet\Control\SessionManager\CheckBadApps">
REGSTR_PATH_APPPATCH	EQU	<"System\CurrentControlSet\Control\SessionManager\AppPatches">
REGSTR_PATH_KNOWNVXDS	EQU	<"System\CurrentControlSet\Control\SessionManager\KnownVxDs">
REGSTR_VAL_UNINSTALLER_DISPLAYNAME	EQU	<"DisplayName">
REGSTR_VAL_UNINSTALLER_COMMANDLINE	EQU	<"UninstallString">
REGSTR_PATH_DESKTOP	EQU	<REGSTR_PATH_SCREENSAVE>
REGSTR_PATH_MOUSE	EQU	<"Control Panel\Mouse">
REGSTR_PATH_KEYBOARD	EQU	<"Control Panel\Keyboard">
REGSTR_PATH_COLORS	EQU	<"Control Panel\Colors">
REGSTR_PATH_SOUND	EQU	<"Control Panel\Sound">
REGSTR_PATH_METRICS	EQU	<"Control Panel\Desktop\WindowMetrics">
REGSTR_PATH_ICONS	EQU	<"Control Panel\Icons">
REGSTR_PATH_CURSORS	EQU	<"Control Panel\Cursors">
REGSTR_PATH_CHECKDISK	EQU	<"Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive">
REGSTR_PATH_CHECKDISKSET	EQU	<"Settings">
REGSTR_PATH_CHECKDISKUDRVS	EQU	<"NoUnknownDDErrDrvs">
REGSTR_PATH_FAULT	EQU	<"Software\Microsoft\Windows\CurrentVersion\Fault">
REGSTR_VAL_FAULT_LOGFILE	EQU	<"LogFile">
REGSTR_PATH_AEDEBUG	EQU	<"Software\Microsoft\Windows NT\CurrentVersion\AeDebug">
REGSTR_VAL_AEDEBUG_DEBUGGER	EQU	<"Debugger">
REGSTR_VAL_AEDEBUG_AUTO	EQU	<"Auto">
REGSTR_PATH_GRPCONV	EQU	<"Software\Microsoft\Windows\CurrentVersion\GrpConv">
REGSTR_VAL_REGITEMDELETEMESSAGE	EQU	<"Removal Message">
REGSTR_PATH_LASTCHECK	EQU	<"Software\Microsoft\Windows\CurrentVersion\Explorer\LastCheck">
REGSTR_PATH_LASTOPTIMIZE	EQU	<"Software\Microsoft\Windows\CurrentVersion\Explorer\LastOptimize">
REGSTR_PATH_LASTBACKUP	EQU	<"Software\Microsoft\Windows\CurrentVersion\Explorer\LastBackup">
REGSTR_PATH_CHKLASTCHECK	EQU	<"Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastCheck">
REGSTR_PATH_CHKLASTSURFAN	EQU	<"Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastSurfaceAnalysis">

_DSKTLSYSTEMTIME	STRUC
wYear	DW	?
wMonth	DW	?
wDayOfWeek	DW	?
wDay	DW	?
wHour	DW	?
wMinute	DW	?
wSecond	DW	?
wMilliseconds	DW	?
wResult	DW	?
_DSKTLSYSTEMTIME	ENDS
DTRESULTOK	EQU	0
DTRESULTFIX	EQU	1
DTRESULTPROB	EQU	2
DTRESULTPART	EQU	3
REGSTR_KEY_SHARES	EQU	<"Software\Microsoft\Windows\CurrentVersion\Network\LanMan">
REGSTR_VAL_SHARES_FLAGS	EQU	<"Flags">
REGSTR_VAL_SHARES_TYPE	EQU	<"Type">
REGSTR_VAL_SHARES_PATH	EQU	<"Path">
REGSTR_VAL_SHARES_REMARK	EQU	<"Remark">
REGSTR_VAL_SHARES_RW_PASS	EQU	<"Parm1">
REGSTR_VAL_SHARES_RO_PASS	EQU	<"Parm2">
REGSTR_PATH_PRINT	EQU	<"System\CurrentControlSet\Control\Print">
REGSTR_PATH_PRINTERS	EQU	<"System\CurrentControlSet\Control\Print\Printers">
REGSTR_PATH_PROVIDERS	EQU	<"System\CurrentControlSet\Control\Print\Providers">
REGSTR_PATH_MONITORS	EQU	<"System\CurrentControlSet\Control\Print\Monitors">
REGSTR_PATH_ENVIRONMENTS	EQU	<"System\CurrentControlSet\Control\Print\Environments">
REGSTR_VAL_START_ON_BOOT	EQU	<"StartOnBoot">
REGSTR_VAL_PRINTERS_MASK	EQU	<"PrintersMask">
REGSTR_VAL_DOS_SPOOL_MASK	EQU	<"DOSSpoolMask">
REGSTR_KEY_CURRENT_ENV	EQU	<"\Windows 4.0">
REGSTR_KEY_DRIVERS	EQU	<"\Drivers">
REGSTR_KEY_PRINT_PROC	EQU	<"\Print Processors">
REGSTR_PATH_EVENTLABELS	EQU	<"AppEvents\EventLabels">
REGSTR_PATH_SCHEMES	EQU	<"AppEvents\Schemes">
REGSTR_PATH_APPS	EQU	<REGSTR_PATH_SCHEMES"\\Apps">
REGSTR_PATH_APPS_DEFAULT	EQU	<REGSTR_PATH_SCHEMES"\\Apps\\.Default">
REGSTR_PATH_NAMES	EQU	<REGSTR_PATH_SCHEMES"\\Names">
REGSTR_PATH_MULTIMEDIA	EQU	<REGSTR_PATH_SETUP"\\Multimedia">
REGSTR_PATH_MULTIMEDIA_AUDIO	EQU	<"Software\Microsoft\Multimedia\Audio">
REGSTR_PATH_MEDIARESOURCES	EQU	<REGSTR_PATH_CURRENT_CONTROL_SET"\\MediaResources">
REGSTR_PATH_MEDIAPROPERTIES	EQU	<REGSTR_PATH_CURRENT_CONTROL_SET"\\MediaProperties">
REGSTR_PATH_PRIVATEPROPERTIES	EQU	<REGSTR_PATH_MEDIAPROPERTIES"\\PrivateProperties">
REGSTR_PATH_PUBLICPROPERTIES	EQU	<REGSTR_PATH_MEDIAPROPERTIES"\\PublicProperties">
REGSTR_PATH_JOYOEM	EQU	<REGSTR_PATH_PRIVATEPROPERTIES"\\Joystick\\OEM">
REGSTR_PATH_JOYCONFIG	EQU	<REGSTR_PATH_MEDIARESOURCES"\\Joystick">
REGSTR_KEY_JOYCURR	EQU	<"CurrentJoystickSettings">
REGSTR_KEY_JOYSETTINGS	EQU	<"JoystickSettings">
REGSTR_VAL_JOYUSERVALUES	EQU	<"JoystickUserValues">
REGSTR_VAL_JOYCALLOUT	EQU	<"JoystickCallout">
REGSTR_VAL_JOYNCONFIG	EQU	<"Joystick%dConfiguration">
REGSTR_VAL_JOYNOEMNAME	EQU	<"Joystick%dOEMName">
REGSTR_VAL_JOYNOEMCALLOUT	EQU	<"Joystick%dOEMCallout">
REGSTR_VAL_JOYOEMCALLOUT	EQU	<"OEMCallout">
REGSTR_VAL_JOYOEMNAME	EQU	<"OEMName">
REGSTR_VAL_JOYOEMDATA	EQU	<"OEMData">
REGSTR_VAL_JOYOEMXYLABEL	EQU	<"OEMXYLabel">
REGSTR_VAL_JOYOEMZLABEL	EQU	<"OEMZLabel">
REGSTR_VAL_JOYOEMRLABEL	EQU	<"OEMRLabel">
REGSTR_VAL_JOYOEMPOVLABEL	EQU	<"OEMPOVLabel">
REGSTR_VAL_JOYOEMULABEL	EQU	<"OEMULabel">
REGSTR_VAL_JOYOEMVLABEL	EQU	<"OEMVLabel">
REGSTR_VAL_JOYOEMTESTMOVEDESC	EQU	<"OEMTestMoveDesc">
REGSTR_VAL_JOYOEMTESTBUTTONDESC	EQU	<"OEMTestButtonDesc">
REGSTR_VAL_JOYOEMTESTMOVECAP	EQU	<"OEMTestMoveCap">
REGSTR_VAL_JOYOEMTESTBUTTONCAP	EQU	<"OEMTestButtonCap">
REGSTR_VAL_JOYOEMTESTWINCAP	EQU	<"OEMTestWinCap">
REGSTR_VAL_JOYOEMCALCAP	EQU	<"OEMCalCap">
REGSTR_VAL_JOYOEMCALWINCAP	EQU	<"OEMCalWinCap">
REGSTR_VAL_JOYOEMCAL1	EQU	<"OEMCal1">
REGSTR_VAL_JOYOEMCAL2	EQU	<"OEMCal2">
REGSTR_VAL_JOYOEMCAL3	EQU	<"OEMCal3">
REGSTR_VAL_JOYOEMCAL4	EQU	<"OEMCal4">
REGSTR_VAL_JOYOEMCAL5	EQU	<"OEMCal5">
REGSTR_VAL_JOYOEMCAL6	EQU	<"OEMCal6">
REGSTR_VAL_JOYOEMCAL7	EQU	<"OEMCal7">
REGSTR_VAL_JOYOEMCAL8	EQU	<"OEMCal8">
REGSTR_VAL_JOYOEMCAL9	EQU	<"OEMCal9">
REGSTR_VAL_JOYOEMCAL10	EQU	<"OEMCal10">
REGSTR_VAL_JOYOEMCAL11	EQU	<"OEMCal11">
REGSTR_VAL_JOYOEMCAL12	EQU	<"OEMCal12">
endif
