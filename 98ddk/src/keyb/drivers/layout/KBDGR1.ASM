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

	page	,132
;*****************************************************************************
;
;	kbdgr1.asm : GERMAN - Capslock-normal mode of operation
;
; notes: DEL on numpad should give ',' NOT '.'.
;
;*****************************************************************************

VKFUN = 0
.xlist
include cmacros.inc
include ..\vkwin.inc
include ..\vkoem.inc
include ..\lcid.inc
.list
sBegin	DATA


;---------------------------------------------------------------------------

kbdgr1Layout	label byte
public kbdgr1Layout

	db	'DS'
	dd	00010407H			; Default LCID
	dw	0					; Version
	dd	dataOFFSET pkbdgr1Start	; Start of Data
	dW	DATASIZE				; Size of Data
	dd	0					; pDibData
	dw	0					; DIBSIZE
	dd	0					; pUnicode
	dd	0					; nUnicode
LayoutData	label byte

; pkbdgr1DibData label word

; DIBSIZE EQU $ - pkbdgr1DibData

pkbdgr1Start label word
	dw	ALTGRUSED or CAPSNORMAL	; flags
	dw		NSTATEKEYS			; NSTATE_KEYS
	dw		kbdgr1_NSTATES		; NSTATES
	dw		3				; NUM_DEAD
	dw		0				; NUM_LIG
	KBDOFFSET       pkbdgr1States		; STATE_LIST
	KBDOFFSET       pkbdgr1ToAscStates	; TOASC_STATES
	KBDOFFSET       pkbdgr1ToAscStateTables	; STATETABLES
	KBDOFFSET       pkbdgr1ToAscVkeyList	; VKEY_LISTS
	KBDOFFSET       pkbdgr1ToAscVKeyListLens	; VKEY_LIST_LENS
	KBDOFFSET       pkbdgr1VKShiftStates	; VK_STATES
	KBDOFFSET       pkbdgr1ScanToIdx		; SCANTOIDX
	KBDOFFSET       pkbdgr1VKeyToIdx		; VKEYTOIDX
	dw		SCANSIZE		; SCAN_SIZE
	KBDOFFSET       kbdgr1VKeyToAnsi		; VKEYTOANSI
	KBDOFFSET       pkbdgr1DeadKeyTable	; DEAD_KEYS
	KBDOFFSET       pkbdgr1DeadTrans		; DEAD_KEYTRANS
	dw		0			; LIG_KEYS
	KBDOFFSET		pEngCapsBits			; CAPS

;---------------------------------------------------------------------------
; CapsLock Vkey Bit Enable Table - CAPSNORMAL flag is required
;
pEngCapsBits label byte				;used with CAPSNORMAL

	db	0,0,0,0,0,0,0,0				; Controls & Numerals
	db	0FEh,0FFh,0FFh,07h,0,0,0,0 	; VK_A -> VK_Z & Numpad & Function Keys
	db	0,0,0,0,0,0,0,4				; Function Keys & OEM Keys
	db	1,0,0,40h,0,0,0,0			; OEM Keys, SVK_A -> SVK_Z, OEM Controls
;---------------------------------------------------------------------------

pkbdgr1States	label byte
	db	VK_MENU,    080H
	db	VK_SHIFT,   080H
	db	VK_CONTROL, 080H

NSTATEKEYS equ ($ - pkbdgr1States) shr 1

	db	0

pkbdgr1ToAscStates	label byte
	db	1		; Alt
	db	2		; Shift
	db	3		; Alt+Shift
	db	5		; altgr
	db	4		; Control
	db	6		; Ctrl+Shift

kbdgr1_NSTATES equ $-pkbdgr1ToAscStates

pkbdgr1VKShiftStates label byte
	db	0		; unshifted
	db	0		; alt
	db	1		; shifted
	db	1		; alt+shift
	db	6		; AltGr
	db	2		; Ctrl
	db	3		; Ctrl+Shift

pkbdgr1ToAscStateTables label word
	KBDOFFSET       kbdgr1ToAscNormal
	KBDOFFSET       kbdgr1ToAscAlt
	KBDOFFSET       kbdgr1ToAscShift
	KBDOFFSET       kbdgr1ToAscAltShift
	KBDOFFSET		kbdgr1ToAscAltGr
	KBDOFFSET       kbdgr1ToAscCtrl
	KBDOFFSET		kbdgr1ToAscCtrlShift

pkbdgr1ToAscVKeyList label word
	KBDOFFSET       pkbdgr1VKeyToIdx
	KBDOFFSET       pkbdgr1VKeyToIdx
	KBDOFFSET       pkbdgr1VKeyToIdx
	KBDOFFSET       pkbdgr1VKeyToIdx
	KBDOFFSET	pkbdgr1AltGrVKeyToIdx
	KBDOFFSET       pkbdgr1VKeyCtrlToIdx
	KBDOFFSET       pkbdgr1VKeyCtrlShiftToIdx

pkbdgr1ToAscVKeyListLens	label byte
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db ALTGR_VKEY_LIST_SIZE
	db VKEY_CTRL_SIZE
	db VKEY_CTRLSHIFT_SIZE

pkbdgr1ScanToIdx label byte
	db 41, 2, 3, 4, 5, 6, 7, 8
	db 9, 10, 11, 12, 13, 16, 17, 18
	db 19, 20, 21, 22, 23, 24, 25, 26
	db 27, 43, 30, 31, 32, 33, 34, 35
	db 36, 37, 38, 39, 40, 44, 45, 46
	db 47, 48, 49, 50, 51, 52, 53
	db 56H
SCANSIZE	equ	$ - pkbdgr1ScanToIdx

	db 53H			; numpad '.'

;---------------------------------------------------------------------------

pkbdgr1VKeyToIdx label byte
;Virtual Keys
	db VK_OEM_5, VK_1, VK_2, VK_3, VK_4, VK_5, VK_6, VK_7
	db VK_8, VK_9, VK_0, VK_OEM_4, VK_OEM_6

	db VK_Q, VK_W, VK_E, VK_R, VK_T, VK_Z, VK_U, VK_I
	db VK_O, VK_P, VK_OEM_1, VK_OEM_PLUS, VK_OEM_2

	db VK_A, VK_S, VK_D, VK_F, VK_G, VK_H, VK_J, VK_K
	db VK_L, VK_OEM_3, VK_OEM_7

	db VK_Y, VK_X, VK_C, VK_V, VK_B, VK_N 
	db VK_M, VK_OEM_COMMA, VK_OEM_PERIOD, VK_OEM_MINUS

	db VK_OEM_102	
	db 06Eh			;VK_DECIMAL

VKEY_LIST_SIZE	equ	$ - pkbdgr1VKeyToIdx

;---------------------------------------------------------------------------
kbdgr1ToAscCtrl  label byte
	db  01BH, 01DH, 01CH

pkbdgr1VKeyCtrlToIdx  label byte
	db  0BAH, 0BBH, 0BFH
VKEY_CTRL_SIZE	equ	$ - pkbdgr1VKeyCtrlToIdx

kbdgr1ToAscCtrlShift  label byte
	db  01EH, 01FH

pkbdgr1VKeyCtrlShiftToIdx  label byte
	db  036H, 0BDH
VKEY_CTRLSHIFT_SIZE	equ	$ - pkbdgr1VKeyCtrlShiftToIdx

;---------------------------------------------------------------------------

kbdgr1ToAscNormal	label byte
kbdgr1ToAscAlt		label byte
;Unshifted Keys'
	db circumflex,'1234567890',beta_g, acute
	db 'qwertzuiop',0FCH, '+',hash
	db 'asdfghjkl',0F6H, 0E4H
	db 'yxcvbnm,.-'
	db '<'
	db ','			; numpad '.'
;---------------------------------------------------------------------------

kbdgr1ToAscAltShift	label byte
kbdgr1ToAscShift		label byte
;Alt Shift State'
;Shift State'
	db ring,'!"',0A7H,'$%&/()=?`'
	db 'QWERTZUIOP',0dcH, '*', 027H
	db 'ASDFGHJKL',0D6H, 0C4H
	db 'YXCVBNM;:_'
	db '>'
	db 08h
;---------------------------------------------------------------------------

kbdgr1VKeyToAnsi	label byte
	db circumflex,'1234567890',beta_g, acute
	db 'QWERTZUIOP',0DCH, '+', hash
	db 'ASDFGHJKL', 0D6H, 0C4H
	db 'YXCVBNM,.-'
	db '<'
	db ','
;---------------------------------------------------------------------------

kbdgr1ToAscAltGr label byte
	db	0b2h
	db	0b3h
	db	'{'
	db	'['
	db	']'
	db	'}'
	db	'\'
	db	'@'
	db	'~'
	db	0b5h
	db	'|'

ALTGR_VKEY_LIST_SIZE	equ $-kbdgr1ToAscAltGr


pkbdgr1AltGrVKeyToIdx label byte
	db	VK_2
	db	VK_3
	db	VK_7
	db	VK_8
	db	VK_9
	db	VK_0
	db	VK_OEM_4
	db	VK_Q
	db	VK_OEM_PLUS
	db	VK_M
	db	VK_OEM_102

;---------------------------------------------------------------------------

pkbdgr1DeadKeyTable	label byte
	db grave
	db acute
	db circumflex

pkbdgr1DeadTrans	label byte
	dw	NDEADLIST

	db	grave,		'a'
	db	grave,		'e'
	db	grave,		'i'
	db	grave,		'o'
	db	grave,		'u'
	db	grave,		'A'
	db	grave,		'E'
	db	grave,		'I'
	db	grave,		'O'
	db	grave,		'U'
	db	grave,		' '

	db	acute,		'a'
	db	acute,		'e'
	db	acute,		'i'
	db	acute,		'o'
	db	acute,		'u'
	db	acute,		'y'
	db	acute,		'A'
	db	acute,		'E'
	db	acute,		'I'
	db	acute,		'O'
	db	acute,		'U'
	db	acute,		'Y'
	db	acute,		' '

	db	circumflex,	'a'
	db	circumflex,	'e'
	db	circumflex,	'i'
	db	circumflex,	'o'
	db	circumflex,	'u'
	db	circumflex,	'A'
	db	circumflex,	'E'
	db	circumflex,	'I'
	db	circumflex,	'O'
	db	circumflex,	'U'
	db	circumflex,	' '

NDEADLIST	equ	(($-pkbdgr1DeadTrans) shr 1)-1

pkbdgr1DeadList	label byte
	db	0E0h
	db	0E8h
	db	0ECh
	db	0F2h
	db	0F9h
	db	0C0h
	db	0C8h
	db	0CCh
	db	0D2h
	db	0D9h
	db	060h

	db	0E1h
	db	0E9h
	db	0EDh
	db	0F3h
	db	0FAh
	db	0FDh
	db	0C1h
	db	0C9h
	db	0CDh
	db	0D3h
	db	0DAh
	db	0DDh
	db	0B4h

	db	0E2h
	db	0EAh
	db	0EEh
	db	0F4h
	db	0FBh
	db	0C2h
	db	0CAh
	db	0CEh
	db	0D4h
	db	0DBh
	db	'^'

DATASIZE equ $-pkbdgr1Start

;---------------------------------------------------------------------------


sEnd	DATA

;---------------------------------------------------------------------------


sBegin	CODE	; Beginning of code segment
assumes CS,CODE
assumes DS,DATA
sEnd	CODE

end

