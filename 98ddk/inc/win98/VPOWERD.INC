ifndef _INC_VPOWERD
_INC_VPOWERD	EQU	1
ifndef Not_VxD
Begin_Service_Table VPOWERD, VxD
    VPOWERD_Service      _VPOWERD_Get_Version, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_APM_BIOS_Version, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_Power_Management_Level, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Set_Power_Management_Level, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Set_Device_Power_State, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Set_System_Power_State, VxD_LOCKED_CODE
    VPOWERD_Service      _VPOWERD_Restore_Power_On_Defaults, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_Power_Status, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_Power_State, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_OEM_APM_Function, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Register_Power_Handler, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Deregister_Power_Handler, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_W32_Get_System_Power_Status, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_W32_Set_System_Power_State, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Get_Capabilities, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Enable_Resume_On_Ring, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Disable_Resume_On_Ring, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Set_Resume_Timer, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Get_Resume_Timer, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Disable_Resume_Timer, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Enable_Timer_Based_Requests, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_Disable_Timer_Based_Requests, VxD_PAGEABLE_CODE
	VPOWERD_Service      _VPOWERD_W32_Get_Power_Status, VxD_PAGEABLE_CODE
	VPOWERD_Service		 _VPOWERD_Get_Timer_Based_Requests_Status, VxD_PAGEABLE_CODE
	VPOWERD_Service		 _VPOWERD_Get_Ring_Resume_Status, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Transfer_Control, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_OS_Shutdown, VxD_PAGEABLE_CODE
    VPOWERD_Service		 _VPOWERD_Indicate_User_Arrival, VxD_PAGEABLE_CODE
    VPOWERD_Service		 _VPOWERD_Get_Battery_Unit_Status, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_Battery_Unit_Presence, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Disable_APM_Idle, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Enable_APM_Idle, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Get_Mode, VxD_PAGEABLE_CODE
    VPOWERD_Service      _VPOWERD_Critical_Shutdown, VxD_PAGEABLE_CODE
End_Service_Table VPOWERD, VxD
endif
PR_SUCCESS	EQU	00000000H
PR_PM_DISABLED	EQU	00000001H
PR_RM_CONNECT_EXISTS	EQU	00000002H
PR_INTERFACE_NOT_CONNECTED	EQU	00000003H
PR_16BIT_PM_CONNECT_EXISTS	EQU	00000005H
PR_16BIT_PM_UNSUPPORTED	EQU	00000006H
PR_32BIT_PM_CONNECT_EXISTS	EQU	00000007H
PR_32BIT_PM_UNSUPPORTED	EQU	00000008H
PR_UNRECOGNIZED_DEVICE_ID	EQU	00000009H
PR_PARAMETER_OUT_OF_RANGE	EQU	0000000AH
PR_INTERFACE_NOT_ENGAGED	EQU	0000000BH
PR_FUNC_NOT_SUPPORTED	EQU	0000000CH
PR_RESUME_TIMER_DISABLED	EQU	0000000DH
PR_CANNOT_ENTER_STATE	EQU	00000060H
PR_NO_PM_EVENTS_PENDING	EQU	00000080H
PR_APM_NOT_PRESENT	EQU	00000086H
PR_UNDEFINED_FUNCTION	EQU	000000FFH
PR_DEFAULT	EQU	80000000H
PR_FAILURE	EQU	80000001H
PR_REQUEST_VETOED	EQU	80000002H
PR_INVALID_POINTER	EQU	80000003H
PR_INVALID_FLAG	EQU	80000004H
PR_INVALID_PMLEVEL	EQU	80000005H
PR_INVALID_DEVICE_ID	EQU	80000006H
PR_INVALID_POWER_STATE	EQU	80000007H
PR_INVALID_REQUEST_TYPE	EQU	80000008H
PR_OUT_OF_MEMORY	EQU	80000009H
PR_DUPLICATE_POWER_HANDLER	EQU	8000000AH
PR_POWER_HANDLER_NOT_FOUND	EQU	8000000BH
PR_INVALID_FUNCTION	EQU	8000000CH
PDI_APM_BIOS	EQU	0000H
PDI_MANAGED_BY_APM_BIOS	EQU	0001H
PDI_MANAGED_BY_APM_BIOS_OLD	EQU	0FFFFH
PDI_SPECIFIC_BATTERY	EQU	8000H
ifdef _NTDDK_
else
endif
PSTATE_APM_ENABLED	EQU	0000H
PSTATE_STANDBY	EQU	0001H
PSTATE_SUSPEND	EQU	0002H
PSTATE_OFF	EQU	0003H
PSTATE_HIBERNATE	EQU	0006H
PMLEVEL_ADVANCED	EQU	0
PMLEVEL_STANDARD	EQU	1
PMLEVEL_OFF	EQU	2
PMLEVEL_ACPI	EQU	3
PMLEVEL_MAXIMUM	EQU	PMLEVEL_ACPI
REQTYPE_USER_INITIATED	EQU	00000000H
REQTYPE_TIMER_INITIATED	EQU	00000001H
REQTYPE_FORCED_REQUEST	EQU	00000002H
REQTYPE_BIOS_CRITICAL_SUSPEND	EQU	00000003H
REQTYPE_FROM_BIOS_FLAG	EQU	80000000H
CAPABILITY_ENABLED	EQU	00000001H
CAPABILITY_DISABLED	EQU	00000000H
ifndef NOPOWERSTATUSDEFINES
AC_LINE_OFFLINE	EQU	00H
AC_LINE_ONLINE	EQU	01H
AC_LINE_BACKUP_POWER	EQU	02H
AC_LINE_UNKNOWN	EQU	0FFH
BATTERY_STATUS_HIGH	EQU	00H
BATTERY_STATUS_LOW	EQU	01H
BATTERY_STATUS_CRITICAL	EQU	02H
BATTERY_STATUS_CHARGING	EQU	03H
BATTERY_STATUS_UNKNOWN	EQU	0FFH
BATTERY_FLAG_HIGH	EQU	01H
BATTERY_FLAG_LOW	EQU	02H
BATTERY_FLAG_CRITICAL	EQU	04H
BATTERY_FLAG_CHARGING	EQU	08H
BATTERY_NOT_PRESENT	EQU	10H
BATTERY_FLAG_NO_BATTERY	EQU	80H
BATTERY_FLAG_UNKNOWN	EQU	0FFH
BATTERY_PERCENTAGE_UNKNOWN	EQU	0FFH
BATTERY_LIFE_MINUTES_MASK	EQU	8000H
BATTERY_LIFE_UNKNOWN	EQU	0FFFFH
BATTERY_LIFE_W32_UNKNOWN	EQU	0FFFFFFFFH
endif

_POWER_STATUS	STRUC
PS_AC_Line_Status	DB	?
PS_Battery_Status	DB	?
PS_Battery_Flag	DB	?
PS_Battery_Life_Percentage	DB	?
PS_Battery_Life_Time	DW	?
_POWER_STATUS	ENDS

_POWERTIME	STRUC
Year	DW	?
Month	DW	?
DayOfWeek	DW	?
Day	DW	?
Hour	DW	?
Minute	DW	?
Second	DW	?
Milliseconds	DW	?
_POWERTIME	ENDS

APM_CAPABILITIES_S	STRUC
Capabilities	DW	?
BatteryCount	DB	?
Reserved	DB	?
APM_CAPABILITIES_S	ENDS
GLOBAL_STANDBY_SUPPORTED_BIT	EQU	0
GLOBAL_STANDBY_SUPPORTED	EQU	(1 SHL GLOBAL_STANDBY_SUPPORTED_BIT)
GLOBAL_SUSPEND_SUPPORTED_BIT	EQU	1
GLOBAL_SUSPEND_SUPPORTED	EQU	(1 SHL GLOBAL_SUSPEND_SUPPORTED_BIT)
WAKE_ON_TIMER_STANDBY_BIT	EQU	2
WAKE_ON_TIMER_STANDBY	EQU	(1 SHL WAKE_ON_TIMER_STANDBY_BIT)
WAKE_ON_TIMER_SUSPEND_BIT	EQU	3
WAKE_ON_TIMER_SUSPEND	EQU	(1 SHL WAKE_ON_TIMER_SUSPEND_BIT)
RING_RESUME_INTERNAL_STANDBY_BIT	EQU	4
RING_RESUME_INTERNAL_STANDBY	EQU	(1 SHL RING_RESUME_INTERNAL_STANDBY_BIT)
RING_RESUME_INTERNAL_SUSPEND_BIT	EQU	5
RING_RESUME_INTERNAL_SUSPEND	EQU	(1 SHL RING_RESUME_INTERNAL_SUSPEND_BIT)
RING_RESUME_PCMCIA_STANDBY_BIT	EQU	6
RING_RESUME_PCMCIA_STANDBY	EQU	(1 SHL RING_RESUME_PCMCIA_STANDBY_BIT)
RING_RESUME_PCMCIA_SUSPEND_BIT	EQU	7
RING_RESUME_PCMCIA_SUSPEND	EQU	(1 SHL RING_RESUME_PCMCIA_SUSPEND_BIT)

_WIN32_SYSTEM_POWER_STATUS	STRUC
W32PS_AC_Line_Status	DB	?
W32PS_Battery_Flag	DB	?
W32PS_Battery_Life_Percent	DB	?
W32PS_Reserved1	DB	?
W32PS_Battery_Life_Time	DD	?
W32PS_Battery_Full_Life_Time	DD	?
_WIN32_SYSTEM_POWER_STATUS	ENDS

_OEM_APM_BYTE_REGS	STRUC
OEMAPM_Reserved1	DW	6 DUP (?)
OEMAPM_BL	DB	?
OEMAPM_BH	DB	?
OEMAPM_Reserved2	DW	?
OEMAPM_DL	DB	?
OEMAPM_DH	DB	?
OEMAPM_Reserved3	DW	?
OEMAPM_CL	DB	?
OEMAPM_CH	DB	?
OEMAPM_Reserved4	DW	?
OEMAPM_AL	DB	?
OEMAPM_AH	DB	?
OEMAPM_Reserved5	DW	?
OEMAPM_Flags	DB	?
OEMAPM_Reserved6	DB	3 DUP (?)
_OEM_APM_BYTE_REGS	ENDS

_OEM_APM_WORD_REGS	STRUC
OEMAPM_DI	DW	?
OEMAPM_Reserved7	DW	?
OEMAPM_SI	DW	?
OEMAPM_Reserved8	DW	?
OEMAPM_BP	DW	?
OEMAPM_Reserved9	DW	?
OEMAPM_BX	DW	?
OEMAPM_Reserved10	DW	?
OEMAPM_DX	DW	?
OEMAPM_Reserved11	DW	?
OEMAPM_CX	DW	?
OEMAPM_Reserved12	DW	?
OEMAPM_AX	DW	?
OEMAPM_Reserved13	DW	3 DUP (?)
_OEM_APM_WORD_REGS	ENDS

_OEM_APM_DWORD_REGS	STRUC
OEMAPM_EDI	DD	?
OEMAPM_ESI	DD	?
OEMAPM_EBP	DD	?
OEMAPM_EBX	DD	?
OEMAPM_EDX	DD	?
OEMAPM_ECX	DD	?
OEMAPM_EAX	DD	?
OEMAPM_Reserved14	DD	?
_OEM_APM_DWORD_REGS	ENDS
?UnionSize = 0
if size _OEM_APM_BYTE_REGS gt ?UnionSize
	?UnionSize = size _OEM_APM_BYTE_REGS
endif
ByteRegs	equ	<(byte ptr 0)>

if size _OEM_APM_WORD_REGS gt ?UnionSize
	?UnionSize = size _OEM_APM_WORD_REGS
endif
WordRegs	equ	<(byte ptr 0)>

if size _OEM_APM_DWORD_REGS gt ?UnionSize
	?UnionSize = size _OEM_APM_DWORD_REGS
endif
DwordRegs	equ	<(byte ptr 0)>


_OEM_APM_REGS	STRUC
	DB	?UnionSize dup(?)
_OEM_APM_REGS	ENDS

PF_SUSPEND_PHASE1	EQU	00000000H
PF_SUSPEND_PHASE2	EQU	00000001H
PF_SUSPEND_INTS_OFF	EQU	00000002H
PF_RESUME_INTS_OFF	EQU	00000003H
PF_RESUME_PHASE2	EQU	00000004H
PF_RESUME_PHASE1	EQU	00000005H
PF_BATTERY_LOW	EQU	00000006H
PF_POWER_STATUS_CHANGE	EQU	00000007H
PF_UPDATE_TIME	EQU	00000008H
PF_CAPABILITIES_CHANGE	EQU	00000009H
PF_USER_ARRIVED	EQU	0000000AH
PF_PRE_FLUSH_DISKS	EQU	0000000BH
PF_APMOEMEVENT_FIRST	EQU	00000200H
PF_APMOEMEVENT_LAST	EQU	000002FFH
PFG_UI_ALLOWED	EQU	00000001H
PFG_CANNOT_FAIL	EQU	00000002H
PFG_REQUEST_VETOED	EQU	00000004H
PFG_REVERSE	EQU	00000008H
PFG_STANDBY	EQU	00000010H
PFG_CRITICAL	EQU	00000020H
PFG_RESUME_AUTOMATIC	EQU	00000040H
PFG_USER_ARRIVED	EQU	00000080H
PHPL_PBT_BROADCAST	EQU	40000000H
PHPL_NTKERN	EQU	60000000H
PHPL_UNKNOWN	EQU	80000000H
PHPL_CONFIGMG	EQU	0C0000000H
PHPL_ACPI	EQU	0D0000000H
PHPL_TIMER	EQU	0E0000000H
PHPL_HANDLE_INTS_OFF	EQU	000000A5H
VPOWERD_ACPI_VERSION	EQU	0800H

_VPOWERD_BSMAPI_HEADER	STRUC
VBAPIH_Packet_Size	DD	?
VBAPIH_Function	DW	?
VBAPIH_Return_Code	DD	?
_VPOWERD_BSMAPI_HEADER	ENDS
VBAPIF_W32_SET_SYSTEM_STATE	EQU	000DH

_VPOWERD_BSMAPI_W32_SET_SYSTEM_STATE	STRUC
VBWSSS_VBAPIH	DB	SIZE _VPOWERD_BSMAPI_HEADER DUP (?)
VBWSSS_Force_Flag	DD	?
_VPOWERD_BSMAPI_W32_SET_SYSTEM_STATE	ENDS
vtc_info 	STRUC
	pAcpiIdleHandler		dd	?
	pSetSystemPowerStateHandler	dd	?
vtc_info 	ENDS

endif
