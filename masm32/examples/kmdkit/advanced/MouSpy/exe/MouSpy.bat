;@echo off
;goto make

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;
;  Client of MouSpy.sys driver
;
;  Written by Four-F (four-f@mail.ru)
;
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

.386
.model flat, stdcall
option casemap:none

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                  I N C L U D E   F I L E S                                        
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

include \masm32\include\windows.inc

include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\comctl32.inc
include \masm32\include\advapi32.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\comctl32.lib
includelib \masm32\lib\advapi32.lib

include \masm32\include\winioctl.inc

include cocomac\cocomac.mac
include cocomac\ListView.mac
include \masm32\Macros\Strings.mac

include ..\common.inc

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                     S T R U C T U R E S                                           
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

; Because of improper definition in windows.inc

_LARGE_INTEGER UNION
	struct
		LowPart		DWORD ?
		HighPart	SDWORD ?
	ends
	struct u
		LowPart		DWORD ?
		HighPart	SDWORD ?
	ends
	QuadPart		QWORD ?	; signed
_LARGE_INTEGER ENDS

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                      E Q U A T E S                                                
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

IDD_MAIN				equ	1000
IDC_LISTVIEW			equ 1001
IDC_INVERT_BUTTONS		equ 1002
IDC_INVERT_MOVEMENT		equ 1003
IDI_ICON				equ 1004
IDM_ABOUT				equ 2000
IDM_STAY_ON_TOP			equ 2001
IDM_AUTOSCROLL			equ 2002
IDM_CLEAR				equ 2003

MAX_ITEMS				equ 1000

; ntddmou.inc defines the...

MOUSE_LEFT_BUTTON_DOWN   equ 0001  ; Left Button changed to down.
MOUSE_LEFT_BUTTON_UP     equ 0002  ; Left Button changed to up.
MOUSE_RIGHT_BUTTON_DOWN  equ 0004  ; Right Button changed to down.
MOUSE_RIGHT_BUTTON_UP    equ 0008  ; Right Button changed to up.
MOUSE_MIDDLE_BUTTON_DOWN equ 0010h ; Middle Button changed to down.
MOUSE_MIDDLE_BUTTON_UP   equ 0020h ; Middle Button changed to up.
MOUSE_WHEEL              equ 0400h

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                              U N I N I T I A L I Z E D  D A T A                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

.data?
g_hDevice			HANDLE		?
g_hEvent			HANDLE		?
g_hInstance			HINSTANCE	?
g_hwndDlg			HWND		?
g_hwndListView		HWND		?
g_fExitNow			BOOL		?
g_dwDlgWidth		DWORD		?
g_hPopupMenu		HMENU		?
g_fAlwaysOnTop		BOOL		?
g_fAutoscroll		BOOL		?

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                         C O D E                                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

.code

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                            malloc                                                 
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

malloc proc dwBytes:DWORD

option PROLOGUE:NONE
option EPILOGUE:NONE

	invoke GetProcessHeap
	invoke HeapAlloc, eax, HEAP_ZERO_MEMORY, [esp+4]
	ret 4

option PROLOGUE:PROLOGUEDEF
option EPILOGUE:EPILOGUEDEF

malloc endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                             free                                                  
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

free proc lpMem:PVOID

option PROLOGUE:NONE
option EPILOGUE:NONE

	invoke GetProcessHeap
	invoke HeapFree, eax, 0, [esp+4]
	ret 4

option PROLOGUE:PROLOGUEDEF
option EPILOGUE:EPILOGUEDEF

free endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                    UnregisterDriver                                               
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

UnregisterDriver proc

local hSCManager:HANDLE

	invoke OpenSCManager, NULL, NULL, SC_MANAGER_ALL_ACCESS
	.if eax != NULL

		mov hSCManager, eax
		
		; Unregister driver - remove registry directory
	
		invoke OpenService, hSCManager, $CTA0("MouSpy"), DELETE
		.if eax != NULL

			push eax
			invoke DeleteService, eax
			call CloseServiceHandle

		.endif

		invoke CloseServiceHandle, hSCManager

	.endif

	ret

UnregisterDriver endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                                                                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

RegisterAndStartDriver proc

local hSCManager:HANDLE
local hService:HANDLE
local hDevice:HANDLE
local acModulePath[MAX_PATH]:CHAR

	mov hDevice, INVALID_HANDLE_VALUE

	invoke OpenSCManager, NULL, NULL, SC_MANAGER_ALL_ACCESS
	.if eax != NULL

		mov hSCManager, eax

		push eax
		invoke GetFullPathName, $CTA0("MouSpy.sys"), sizeof acModulePath, addr acModulePath, esp
    	pop eax
  
		invoke CreateService, hSCManager, $CTA0("MouSpy"), $CTA0("Mouse Spy"), \
			SERVICE_START, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, \
			SERVICE_ERROR_IGNORE, addr acModulePath, NULL, NULL, NULL, NULL, NULL
		.if eax != NULL

			mov hService, eax

			invoke StartService, hService, 0, NULL
			.if eax != 0

				invoke CreateFile, $CTA0("\\\\.\\MouSpy"), GENERIC_READ + GENERIC_WRITE, \
								0, NULL, OPEN_EXISTING, 0, NULL
				.if eax != INVALID_HANDLE_VALUE
					mov hDevice, eax
				.endif

			.endif

			invoke CloseServiceHandle, hService

		.endif

		invoke CloseServiceHandle, hSCManager

	.endif
invoke GetLastError
	mov eax, hDevice
	ret

RegisterAndStartDriver endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                                                                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

StopDriver proc

local hSCManager:HANDLE
local hService:HANDLE
local _ss:SERVICE_STATUS
local fOK:BOOL

	and fOK, FALSE

	invoke OpenSCManager, NULL, NULL, SC_MANAGER_ALL_ACCESS
	.if eax != NULL

		mov hSCManager, eax

		invoke OpenService, hSCManager, $CTA0("MouSpy"), SERVICE_STOP + DELETE

		.if eax != NULL

			mov hService, eax

			invoke ControlService, hService, SERVICE_CONTROL_STOP, addr _ss
			.if eax != 0

				invoke GetLastError
				.if eax == ERROR_SUCCESS  ||  eax == ERROR_IO_PENDING
					mov fOK, TRUE
				.endif
				
			.endif

 			invoke DeleteService, hService
			invoke CloseServiceHandle, hService

		.endif

		invoke CloseServiceHandle, hSCManager

	.endif

	mov eax, fOK
	ret

StopDriver endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                             MyUnhandledExceptionFilter                                            
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

MyUnhandledExceptionFilter proc lpExceptionInfo:PTR EXCEPTION_POINTERS

; Just cleanup every possible thing

local dwBytesReturned:DWORD
local _ss:SERVICE_STATUS

	; If something went wrong let the driver know it should undo the things.

	invoke DeviceIoControl, g_hDevice, IOCTL_MOUSE_DETACH, NULL, 0, NULL, 0, \
								addr dwBytesReturned, NULL

	mov g_fExitNow, TRUE		; Loop thread should exit now.
	invoke SetEvent, g_hEvent
					
	invoke CloseHandle, g_hEvent
	invoke CloseHandle, g_hDevice

	invoke StopDriver

	mov eax, EXCEPTION_EXECUTE_HANDLER
	ret

MyUnhandledExceptionFilter endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                     ListViewInsertColumn                                          
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

ListViewInsertColumn proc

local lvc:LV_COLUMN

	mov lvc.imask, LVCF_TEXT + LVCF_WIDTH + LVCF_FMT
	mov lvc.fmt, LVCFMT_LEFT
	mov lvc.pszText, $CTA0("L")
	mov lvc.lx, 40
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 0, addr lvc

	mov lvc.pszText, $CTA0("M")
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 1, addr lvc
	
	mov lvc.pszText, $CTA0("R")
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 2, addr lvc

	mov lvc.fmt, LVCFMT_RIGHT
	mov lvc.pszText, $CTA0("X")
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 3, addr lvc

	mov lvc.pszText, $CTA0("Y")
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 4, addr lvc

	mov lvc.pszText, $CTA0("Wheel")
	mov lvc.lx, 50
	invoke SendMessage, g_hwndListView, LVM_INSERTCOLUMN, 5, addr lvc

	ret

ListViewInsertColumn endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                         FillMouseInfo                                             
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

FillMouseInfo proc uses esi ebx paKeyData:PTR KEY_DATA, cb:UINT

local lvi:LV_ITEM
local buffer[32]:CHAR

	ListView_GetItemCount g_hwndListView

	.if eax > MAX_ITEMS

		mov ebx, eax
		sub ebx, MAX_ITEMS

		invoke SendMessage, g_hwndListView, WM_SETREDRAW  , FALSE, 0
		
		.while ebx

			; Delete oldest item
			ListView_DeleteItem g_hwndListView, 0
			
			dec ebx

		.endw

		invoke SendMessage, g_hwndListView, WM_SETREDRAW  , TRUE, 0

	.endif

	mov esi, paKeyData
	assume esi:ptr MOUSE_DATA

	mov eax, cb
	mov ecx, sizeof MOUSE_DATA
	xor edx, edx
	div ecx
	mov ebx, eax

	mov lvi.imask, LVIF_TEXT

	ListView_GetItemCount g_hwndListView
	mov lvi.iItem, eax
		
	.while ebx

		; buttons

		and lvi.iSubItem, 0
		movzx eax, [esi].ButtonFlags
		.if eax & MOUSE_LEFT_BUTTON_DOWN
			mov ecx, $CTA0("down")
		.elseif eax & MOUSE_LEFT_BUTTON_UP
			mov ecx, $CTA0("up")
		.else		
			mov ecx, $CTA0("")
		.endif
		mov lvi.pszText, ecx
		ListView_InsertItem g_hwndListView, addr lvi
		
		inc lvi.iSubItem
		movzx eax, [esi].ButtonFlags
		.if eax & (MOUSE_MIDDLE_BUTTON_DOWN or MOUSE_MIDDLE_BUTTON_UP)
			.if eax & MOUSE_MIDDLE_BUTTON_DOWN
				mov ecx, $CTA0("down")
			.elseif eax & MOUSE_MIDDLE_BUTTON_UP
				mov ecx, $CTA0("up")		
			.endif
			mov lvi.pszText, ecx
			ListView_SetItem g_hwndListView, addr lvi
		.endif

		inc lvi.iSubItem
		movzx eax, [esi].ButtonFlags
		.if eax & (MOUSE_RIGHT_BUTTON_DOWN or MOUSE_RIGHT_BUTTON_UP)
			.if eax & MOUSE_RIGHT_BUTTON_DOWN
				mov ecx, $CTA0("down")
			.elseif eax & MOUSE_RIGHT_BUTTON_UP
				mov ecx, $CTA0("up")		
			.endif
			mov lvi.pszText, ecx
			ListView_SetItem g_hwndListView, addr lvi
		.endif

		; X
		
		inc lvi.iSubItem
		.if [esi].LastX != 0
			invoke wsprintf, addr buffer, $CTA0("%d"), [esi].LastX
			lea ecx, buffer
			mov lvi.pszText, ecx
			ListView_SetItem g_hwndListView, addr lvi
		.endif

		; Y

		inc lvi.iSubItem
		.if [esi].LastY != 0
			invoke wsprintf, addr buffer, $CTA0("%d"), [esi].LastY
			lea ecx, buffer
			mov lvi.pszText, ecx
			ListView_SetItem g_hwndListView, addr lvi
		.endif

		; Wheel if any

		inc lvi.iSubItem
		movzx eax, [esi].ButtonFlags
		.if eax & MOUSE_WHEEL
			movzx eax, [esi].ButtonData
			invoke wsprintf, addr buffer, $CTA0("%04X"), eax
			lea ecx, buffer
			mov lvi.pszText, ecx
			ListView_SetItem g_hwndListView, addr lvi
		.endif


		dec ebx
		add esi, sizeof MOUSE_DATA
		inc lvi.iItem

	.endw

	; Scroll down if needed

	.if g_fAutoscroll
		ListView_GetItemCount g_hwndListView
		dec eax				; Make index zero-based
		ListView_EnsureVisible g_hwndListView, eax, FALSE
	.endif

	assume esi:nothing

	ret

FillMouseInfo endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                       WaitForMouseData                                            
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

WaitForMouseData proc hEvent:HANDLE

local paMouseData:PMOUSE_DATA
local cbMouseData:DWORD
local dwBytesReturned:DWORD

	mov cbMouseData, MOUSE_DATA * MAX_MOUSE_DATA_ENTRIES

	invoke malloc, cbMouseData
	.if eax != NULL
	
		mov paMouseData, eax

		.while TRUE

			invoke WaitForSingleObject, hEvent, INFINITE

			.if eax != WAIT_FAILED
		
				.break .if g_fExitNow == TRUE

				; We wait a little to not ask driver too often.
				; And we do it before DeviceIoControl - this way
				; our monitor log looks more natural.

				invoke Sleep, 250

				invoke DeviceIoControl, g_hDevice, IOCTL_GET_MOUSE_DATA, NULL, 0, \
							paMouseData, cbMouseData, addr dwBytesReturned, NULL

				.if ( eax != 0 ) && ( dwBytesReturned != 0 )
					invoke FillMouseInfo, paMouseData, dwBytesReturned
				.endif

			.else

				invoke MessageBox, g_hwndDlg, \
					$CTA0("Wait failed. Thread now exits. Restart application."), NULL, MB_ICONERROR
				.break

			.endif

		.endw

		invoke free, paMouseData

	.endif

	invoke ExitThread, 0
	ret							; Never executed.

WaitForMouseData endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                               D I A L O G     P R O C E D U R E                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

DlgProc proc uses ebx hDlg:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

local rect:RECT
local dwBytesReturned:DWORD
local fSet:BOOL

	mov eax, uMsg
	.if eax == WM_INITDIALOG

		push hDlg
		pop g_hwndDlg

		invoke LoadIcon, g_hInstance, IDI_ICON
		invoke SendMessage, hDlg, WM_SETICON, ICON_BIG, eax

		invoke GetDlgItem, hDlg, IDC_LISTVIEW
		mov g_hwndListView, eax
		invoke SetFocus, g_hwndListView

		ListView_SetExtendedListViewStyle g_hwndListView, LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT

		invoke ListViewInsertColumn

		; Add about menu

		invoke GetSystemMenu, hDlg, FALSE
		mov ebx, eax
		invoke InsertMenu, ebx, -1, MF_BYPOSITION + MF_SEPARATOR, 0, 0
		invoke InsertMenu, ebx, -1, MF_BYPOSITION + MF_STRING, IDM_ABOUT, $CTA0("About...")
		invoke InsertMenu, ebx, -1, MF_BYPOSITION + MF_STRING + MF_CHECKED, IDM_STAY_ON_TOP, $CTA0("Stay On Top")
		invoke InsertMenu, ebx, -1, MF_BYPOSITION + MF_STRING + MF_CHECKED, IDM_AUTOSCROLL, $CTA0("Autoscroll")

		; Make it floating
	
		mov g_fAlwaysOnTop, TRUE
		invoke SetWindowPos, g_hwndDlg, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE

		mov g_fAutoscroll, TRUE

		; Create popup menu

		invoke CreatePopupMenu
		mov g_hPopupMenu,eax

		invoke AppendMenu, g_hPopupMenu, MF_STRING, IDM_CLEAR, $CTA0("Clear")
		

		; for size tracking

		invoke GetWindowRect, hDlg, addr rect

		lea edx, rect
		mov eax, (RECT PTR [edx]).right
		sub eax, (RECT PTR [edx]).left

		mov g_dwDlgWidth, eax


	.elseif eax == WM_SIZE

		TOP_MARGUIN	equ 38

		mov eax, lParam
		mov ecx, eax
		and eax, 0FFFFh
		shr ecx, 16
		sub ecx, TOP_MARGUIN
		invoke MoveWindow, g_hwndListView, 0, TOP_MARGUIN, eax, ecx, TRUE


	.elseif eax == WM_COMMAND

		mov eax, wParam
		and eax, 0FFFFh
		.if eax == IDCANCEL
			invoke EndDialog, hDlg, 0
		.elseif eax == IDM_CLEAR
			ListView_DeleteAllItems g_hwndListView
		.endif

		mov eax, wParam
		shr eax, 16
		.if eax == BN_CLICKED

			mov eax, wParam
			and eax, 0FFFFh

			.if eax == IDC_INVERT_BUTTONS

				invoke IsDlgButtonChecked, hDlg, IDC_INVERT_BUTTONS
				.if eax == BST_CHECKED
					mov fSet, TRUE
				.else
					and fSet, FALSE
				.endif

				invoke DeviceIoControl, g_hDevice, IOCTL_INVERT_BUTTONS, \
						addr fSet, sizeof fSet, NULL, 0, addr dwBytesReturned, NULL

			.elseif eax == IDC_INVERT_MOVEMENT

				invoke IsDlgButtonChecked, hDlg, IDC_INVERT_MOVEMENT
				.if eax == BST_CHECKED
					mov fSet, TRUE
				.else
					and fSet, FALSE
				.endif

				invoke DeviceIoControl, g_hDevice, IOCTL_INVERT_MOVEMENT, \
						addr fSet, sizeof fSet, NULL, 0, addr dwBytesReturned, NULL
			.endif

		.endif


	.elseif eax == WM_DESTROY

		invoke DestroyMenu, g_hPopupMenu


	.elseif uMsg == WM_GETMINMAXINFO

		mov ecx, lParam
		assume ecx:ptr MINMAXINFO
		mov eax, g_dwDlgWidth
		mov [ecx].ptMinTrackSize.x, eax
		mov [ecx].ptMaxTrackSize.x, eax

		mov [ecx].ptMinTrackSize.y, 94
		assume ecx:nothing

		xor eax, eax
		ret


	.elseif eax == WM_CONTEXTMENU

		; Don't pop up menu if list is empty

		ListView_GetItemCount g_hwndListView
		.if eax != 0
			mov eax, lParam
			mov ecx, eax
			and eax, 0FFFFh
			shr ecx, 16
			invoke TrackPopupMenu, g_hPopupMenu, TPM_LEFTALIGN, eax, ecx, NULL, hDlg, NULL
		.endif


	.elseif eax == WM_SYSCOMMAND

		mov eax, wParam
		.if eax == IDM_ABOUT
			invoke MessageBox, hDlg, $CTA0("Mouse Spy v1.0\nWritten by Four-F (four-f@mail.ru)"), \
									$CTA0("About"), MB_ICONINFORMATION

		.elseif wParam == IDM_STAY_ON_TOP

			invoke GetSystemMenu, hDlg, FALSE

			.if g_fAlwaysOnTop
				mov ecx, MF_UNCHECKED
			.else
				mov ecx, MF_CHECKED
			.endif

			invoke CheckMenuItem, eax, IDM_STAY_ON_TOP, ecx

			.if g_fAlwaysOnTop
				and g_fAlwaysOnTop, FALSE
				mov ecx, HWND_NOTOPMOST
			.else
				mov g_fAlwaysOnTop, TRUE
				mov ecx, HWND_TOPMOST
			.endif

			invoke SetWindowPos, g_hwndDlg, ecx, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE

		.elseif wParam == IDM_AUTOSCROLL

			invoke GetSystemMenu, hDlg, FALSE

			.if g_fAutoscroll
				and g_fAutoscroll, FALSE
				mov ecx, MF_UNCHECKED
			.else
				mov g_fAutoscroll, TRUE
				mov ecx, MF_CHECKED
			.endif

			invoke CheckMenuItem, eax, IDM_AUTOSCROLL, ecx

		.endif
 		xor eax, eax
 		ret


	.else

		xor eax, eax
		ret
	
	.endif

	xor eax, eax
	inc eax
	ret
    
DlgProc endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                                                                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

start proc

local dwBytesReturned:DWORD
local fStop

	mov fStop, TRUE

	invoke SetUnhandledExceptionFilter, MyUnhandledExceptionFilter

	; Try to open device first. It's probably running

	invoke CreateFile, $CTA0("\\\\.\\MouSpy"), GENERIC_WRITE + GENERIC_READ, \
									0, NULL, OPEN_EXISTING, 0, NULL
	mov g_hDevice, eax
	.if eax == INVALID_HANDLE_VALUE

		; driver is not loaded yet

		; delete it anyway it may be registered so RegisterAndStartDriver will not fail
	
		invoke UnregisterDriver	

		invoke RegisterAndStartDriver
		mov g_hDevice, eax

	.endif

	.if g_hDevice != INVALID_HANDLE_VALUE

		; OK. Devise is here. Let's start spying

		; Create unnamed auto-reset event to be signalled when there is data to read.

		invoke CreateEvent, NULL, FALSE, FALSE, NULL
		mov g_hEvent, eax

		; Create thread to wait event signaled.

		push ecx								; place for dwThreadID
		invoke CreateThread, NULL, 0, WaitForMouseData, g_hEvent, 0, esp
		pop ecx									; throw dwThreadID away
		.if eax != NULL
					
			invoke CloseHandle, eax		

			;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

			invoke DeviceIoControl, g_hDevice, IOCTL_MOUSE_ATTACH, \
					addr g_hEvent, sizeof g_hEvent, NULL, 0, addr dwBytesReturned, NULL

			.if eax != 0

				invoke GetModuleHandle, NULL
				mov g_hInstance, eax

				invoke DialogBoxParam, g_hInstance, IDD_MAIN, NULL, addr DlgProc, 0

				invoke DeviceIoControl, g_hDevice, IOCTL_MOUSE_DETACH, NULL, 0, NULL, 0, \
							addr dwBytesReturned, NULL
				.if eax == 0

					and fStop, FALSE

					invoke MessageBox, NULL, \
						$CTA0("Driver failed to detach the filter.\nProbably someone sits over."), \
						NULL, MB_OK + MB_ICONWARNING
				.else

					invoke MessageBox, NULL, \
						$CTA0("Move the mouse to let the driver to be unloaded."), \
						$CTA0("Mouse Spy"), MB_OK

				.endif

			.else

				invoke MessageBox, NULL, $CTA0("Couldn't attach to mouse."), \
											NULL, MB_ICONSTOP
			.endif

			;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

		.else
			invoke MessageBox, NULL, $CTA0("Can't create thread."), NULL, MB_ICONSTOP						
		.endif

		mov g_fExitNow, TRUE
		invoke SetEvent, g_hEvent		; Signal event to make loop thread exit.
					
		invoke CloseHandle, g_hEvent
		invoke CloseHandle, g_hDevice

		.if fStop

			invoke StopDriver
			.if eax == FALSE
				invoke MessageBox, NULL, \
						$CTA0("Could not stop driver.\nIt's still running."), \
						NULL, MB_OK + MB_ICONWARNING			
			.endif
		.endif
		
	.else
		invoke MessageBox, NULL, $CTA0("Could not open device."), NULL, MB_OK + MB_ICONSTOP
	.endif

	; Restore default handler

	invoke SetUnhandledExceptionFilter, NULL

	invoke ExitProcess, 0
	invoke InitCommonControls

start endp

;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;                                                                                                   
;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

end start

:make

set exe=MouSpy

if exist ..\%exe%.exe del ..\%exe%.exe

if exist rsrc.obj goto final
	\masm32\bin\rc /v rsrc.rc
	\masm32\bin\cvtres /machine:ix86 rsrc.res
	if errorlevel 0 goto final
		pause
		exit

:final
if exist rsrc.res del rsrc.res

\masm32\bin\ml /nologo /c /coff %exe%.bat
\masm32\bin\link /nologo /subsystem:windows %exe%.obj rsrc.obj

del %exe%.obj
move %exe%.exe ..
if exist %exe%.exe del %exe%.exe

echo.
pause
