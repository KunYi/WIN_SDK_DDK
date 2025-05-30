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
;	kbdusx2.asm - includes ALTGR/ALTGR+SHIFT layers
;
;*****************************************************************************


VKFUN = 0

.xlist
include	cmacros.inc

include ..\vkwin.inc
include ..\vkoem.inc
include ..\lcid.inc
.list

if1
%out
%out   lcidusx2.asm  (Microsoft)
endif

sBegin	DATA

;---------------------------------------------------------------------------

header	label byte
public header

kbdusx2Layout	label byte
public kbdusx2Layout

	db	'DS'
	dd	00000409H			; Default LCID
	dw	0				; Version
	dd	dataOFFSET pkbdusx2Start		; Start of Data
	dW	DATASIZE				; Size of Data
	dd	0				; pDibData
	dw	0				; DIBSIZE
	dd	0				; pUnicode
	dd	0				; nUnicode
LayoutData	label byte

; pkbdusx2DibData label word

; DIBSIZE EQU $ - pkbdusx2DibData

;---------------------------------------------------------------------------
pkbdusx2Start label word
	dw		ALTGRUSED or CAPSNORMAL 
	dw		NSTATEKEYS		; NSTATE_KEYS
	dw		kbdusx2_NSTATES		; NSTATES
	dw		5			; NUM_DEAD
	dw		0			; NUM_LIG
	KBDOFFSET       pkbdusx2States		; STATE_LIST
	KBDOFFSET       pkbdusx2ToAscStates	; TOASC_STATES
	KBDOFFSET       pkbdusx2ToAscStateTables	; STATETABLES
	KBDOFFSET       pkbdusx2ToAscVkeyList	; VKEY_LISTS
	KBDOFFSET       pkbdusx2ToAscVKeyListLens; VKEY_LIST_LENS
	KBDOFFSET       pkbdusx2VKShiftStates	; VK_STATES
	KBDOFFSET       pkbdusx2ScanToIdx	; SCANTOIDX
	KBDOFFSET       pkbdusx2VKeyToIdx	; VKEYTOIDX
	dw		SCANSIZE		; SCAN_SIZE
	KBDOFFSET       kbdusx2VKeyToAnsi	; VKEYTOANSI
	KBDOFFSET       pkbdusx2DeadKeyTable	; DEAD_KEYS
	KBDOFFSET       pkbdusx2DeadTrans	; DEAD_KEYTRANS
	dw		0			; LIG_KEYS
	KBDOFFSET	pusx2CapsBits			; CAPS

;---------------------------------------------------------------------------
; CapsLock Vkey Bit Enable Table - CAPSNORMAL flag is required
;
pusx2CapsBits label byte				;used with CAPSNORMAL

	db	0,0,0,0,0,0,0,0				; Controls & Numerals
	db	0FEh,0FFh,0FFh,07h,0,0,0,0 	; VK_A -> VK_Z & Numpad & Function Keys
	db	0,0,0,0,0,0,0,0				; Function Keys & OEM Keys
	db	0,0,0,0,0,0,0,0				; OEM Keys, SVK_A -> SVK_Z, OEM Controls
;---------------------------------------------------------------------------

pkbdusx2States	label byte
	db	VK_MENU,    080H
	db	VK_SHIFT,   080H
	db	VK_CONTROL, 080H

NSTATEKEYS equ ($ - pkbdusx2States) shr 1

;---------------------------------------------------------------------------
	db	0
pkbdusx2ToAscStates	label byte
	db	1		; Alt
	db	2		; Shift
	db	3		; Alt+Shift
	db	4		; Ctrl
	db	6		; Ctrl+Shift 
	db	5		; AltGr
	db	7		; AltGr+Shift

kbdusx2_NSTATES equ $-pkbdusx2ToAscStates

pkbdusx2VKShiftStates label byte
	db	0		; unshifted
	db	0		; alt
	db	1		; shifted
	db	1		; alt+shift
	db	2		; Control
	db	3		; Ctrl+Shift
	db	6		; AltGr
	db	7		; AltGr+Shift

;---------------------------------------------------------------------------
pkbdusx2ToAscStateTables label word
        KBDOFFSET       kbdusx2ToAscNormal
        KBDOFFSET       kbdusx2ToAscAlt
        KBDOFFSET       kbdusx2ToAscShift
        KBDOFFSET       kbdusx2ToAscAltShift
        KBDOFFSET       kbdusx2ToAscCtrl
        KBDOFFSET       kbdusx2ToAscCtrlShift
        KBDOFFSET       kbdusx2ToAscAltGr
        KBDOFFSET       kbdusx2ToAscAltGrShift

pkbdusx2ToAscVKeyList label word
        KBDOFFSET       pkbdusx2VKeyToIdx
        KBDOFFSET       pkbdusx2VKeyToIdx
        KBDOFFSET       pkbdusx2VKeyToIdx
        KBDOFFSET       pkbdusx2VKeyToIdx
        KBDOFFSET       pkbdusx2VKeyCtrlToIdx
        KBDOFFSET       pkbdusx2VKeyCtrlShiftToIdx
        KBDOFFSET       pkbdusx2VKeyAltGrToIdx
        KBDOFFSET       pkbdusx2VKeyAltGrShiftToIdx

pkbdusx2ToAscVKeyListLens	label byte
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db VKEY_LIST_SIZE
	db VKEY_CTRL_SIZE
	db VKEY_CTRLSHIFT_SIZE
	db VKEY_ALTGR_SIZE
	db VKEY_ALTGRSHIFT_SIZE

;---------------------------------------------------------------------------
pkbdusx2ScanToIdx label byte
	db 41, 2, 3, 4, 5, 6, 7, 8
	db 9, 10, 11, 12, 13, 16, 17, 18
	db 19, 20, 21, 22, 23, 24, 25, 26
	db 27, 43, 30, 31, 32, 33, 34, 35
	db 36, 37, 38, 39, 40, 44, 45, 46
	db 47, 48, 49, 50, 51, 52, 53
	db 056H
SCANSIZE	equ	$ - pkbdusx2ScanToIdx

;---------------------------------------------------------------------------

pkbdusx2VKeyToIdx label byte
;Virtual Keys
	db VK_OEM_3, VK_1, VK_2, VK_3, VK_4, VK_5, VK_6, VK_7
	db VK_8, VK_9, VK_0, VK_OEM_MINUS, VK_OEM_PLUS, VK_Q, VK_W, VK_E
	db VK_R, VK_T, VK_Y, VK_U, VK_I, VK_O, VK_P, VK_OEM_4
	db VK_OEM_6, VK_OEM_5, VK_A, VK_S, VK_D, VK_F, VK_G, VK_H
	db VK_J, VK_K, VK_L, VK_OEM_1, VK_OEM_7, VK_Z, VK_X, VK_C
	db VK_V, VK_B, VK_N, VK_M, VK_OEM_COMMA, VK_OEM_PERIOD, VK_OEM_2
	db VK_OEM_102

VKEY_LIST_SIZE	equ	$ - pkbdusx2VKeyToIdx

;---------------------------------------------------------------------------
kbdusx2ToAscCtrl       label byte
        db 01BH, 01CH, 01DH, 01CH

pkbdusx2VKeyCtrlToIdx label byte
        db 0DBH, 0DCH, 0DDH, 0E2H

VKEY_CTRL_SIZE  equ     $ - pkbdusx2VKeyCtrlToIdx


kbdusx2ToAscCtrlShift    label byte
        db 01EH, 01FH

pkbdusx2VKeyCtrlShiftToIdx   label byte
        db 036H, 0BDH

VKEY_CTRLSHIFT_SIZE  equ     $ - pkbdusx2VKeyCtrlShiftToIdx

;---------------------------------------------------------------------------

kbdusx2ToAscAlt		label byte
kbdusx2ToAscNormal	label byte
;Unshifted Keys'
	db '`1234567'
	db '890-=qwe'
	db 'rtyuiop['
	db ']\asdfgh'
	db 'jkl;''zxc'
	db 'vbnm,./'
	db '\'
;---------------------------------------------------------------------------

kbdusx2ToAscAltShift	label byte
kbdusx2ToAscShift        label byte
;Shift State'
	db '~!@#$%^&'
	db '*()_+QWE'
	db 'RTYUIOP{'
	db '}|ASDFGH'
	db 'JKL:"ZXC'
	db 'VBNM<>?'
	db '|'
;---------------------------------------------------------------------------

kbdusx2VKeyToAnsi	label byte
;ANSII'
	db '`1234567'
	db '890-=QWE'
	db 'RTYUIOP['
	db ']\ASDFGH'
	db 'JKL;''ZXC'
	db 'VBNM,./'
	db '\'
;---------------------------------------------------------------------------
; Table of Vkeys in scancode order and a matching table of ANSI chars
;
pkbdusx2VKeyAltGrToIdx   label   byte
;AltGr Index
	db 031H,032H,033H,034H,036H,037H
	db 038H,039H,030H,0BDH,0BBH,051H
	db 057H,045H,052H,054H,059H,055H
	db 049H,04FH,050H,0DBH,0DDH,041H
	db 053H,044H,04CH,0BAH,0DEH,0DCH
	db 05AH,043H,04EH,04DH,0BCH,0BFH

VKEY_ALTGR_SIZE  equ     $ - pkbdusx2VKeyAltGrToIdx

;AltGr Keys
kbdusx2ToAscAltGr    label byte
	db 0A1H,0B2H,0B3H,0A4H,0BCH,0BDH
	db 0BEH,091H,092H,0A5H,0D7H,0E4H
	db 0E5H,0E9H,0AEH,0FEH,0FCH,0FAH
	db 0EDH,0F3H,0F6H,0ABH,0BBH,0E1H
	db 0DFH,0F0H,0F8H,0B6H,0B4H,0ACH
	db 0E6H,0A9H,0F1H,0B5H,0E7H,0BFH
;---------------------------------------------------------------------------
; Table of Vkeys in scancode order and a matching table of ANSI chars
;
;AltGr Shifted Index
pkbdusx2VKeyAltGrShiftToIdx label byte
	db 031H,034H,0bbH,051H, 057h, 045h
	db 054H,059H,055H,049H,04fH,050H
	db 041H,053H,044H,04cH,0baH,0deH
	db 0dcH,05aH,043H,04eH,0bcH

VKEY_ALTGRSHIFT_SIZE  equ     $ - pkbdusx2VKeyAltGrShiftToIdx

;AltGr SHifted Keys
kbdusx2ToAscAltGrShift	label byte
	db 0b9H,0a3H,0f7H,0c4H,0c5H,0c9H
	db 0deH,0dcH,0daH,0cdH,0d3H,0d6H
	db 0c1H,0a7H,0d0H,0d8H,0b0H,0a8H
	db 0a6H,0c6H,0a2H,0d1H,0c7H
;---------------------------------------------------------------
pkbdusx2DeadKeyTable	label byte
	Db	GRAVE		;; 0, VK_OEM_3, 0
	Db	ACUTE		;; 0, VK_OEM_7, 5	
	Db	CIRCUMFLEX	;; 0, VK_6,     2
	Db	UMLAUT		;; 0, VK_OEM_7, 7
	Db	TILDE		;; 0, VK_OEM_3, 2

pkbdusx2DeadTrans	label byte
	dw	NDEADLIST

	db	grave,	'a'
	db	grave,	'e'
	db	grave,	'i'
	db	grave,	'o'
	db	grave,	'u'
	db	grave,	'A'
	db	grave,	'E'
	db	grave,	'I'
	db	grave,	'O'
	db	grave,	'U'
	db	grave,	' '

	db	acute,	'a'
	db	acute,	'e'
	db	acute,	'i'
	db	acute,	'o'
	db	acute,	'u'
	db	acute,	'y'
	db	acute,	'A'
	db	acute,	'E'
	db	acute,	'I'
	db	acute,	'O'
	db	acute,	'U'
	db	acute,	'Y'
	db	acute,	'c'
	db	acute,	'C'
	db	acute,	' '

	db	circumflex,'a'
	db	circumflex,'e'
	db	circumflex,'i'
	db	circumflex,'o'
	db	circumflex,'u'
	db	circumflex,'A'
	db	circumflex,'E'
	db	circumflex,'I'
	db	circumflex,'O'
	db	circumflex,'U'
	db	circumflex,' '

	db	umlaut,	'a'
	db	umlaut,	'e'
	db	umlaut,	'i'
	db	umlaut,	'o'
	db	umlaut,	'u'
	db	umlaut,	'y'
	db	umlaut,	'A'
	db	umlaut,	'E'
	db	umlaut,	'I'
	db	umlaut,	'O'
	db	umlaut,	'U'
	db	umlaut,	'Y'
	db	umlaut,	' '

	db	tilde,	'a'
	db	tilde,	'o'
	db	tilde,	'n'
	db	tilde,	'A'
	db	tilde,	'O'
	db	tilde,	'N'
	db	tilde,	' '

NDEADLIST	equ	(($-pkbdusx2DeadTrans) shr 1)-1

pkbdusx2DeadList	label byte
;grave
	db	0E0H	
	db	0E8H
	db	0ECH
	db	0F2H
	db	0F9H
	db	0C0H
	db	0C8H
	db	0CCH
	db	0D2H
	db	0D9H
	db	grave

;acute
	db	0E1H
	db	0E9H
	db	0EDH
	db	0F3H
	db	0FAH
	db	0FDH
	db	0C1H
	db	0C9H
	db	0CDH
	db	0D3H
	db	0DAH
	db	0DDH
	db	231	;0E7H
	db	199	;0C7H
	db	acute

;circumflex
	db	0E2H
	db	0EAH
	db	0EEH
	db	0F4H
	db	0FBH
	db	0C2H
	db	0CAH
	db	0CEH
	db	0D4H
	db	0DBH
	db	circumflex

;umlaut
	db	0E4H
	db	0EBH
	db	0EFH
	db	0F6H
	db	0FCH
	db	0FFH
	db	0C4H
	db	0CBH
	db	0CFH
	db	0D6H
	db	0DCH
    db	09FH
	db	umlaut

;tilde
	db	0e3H	
	db	0f5H
	db	0F1H
	db	0c3H
	db	0d5H
	db	0D1H
	db	tilde

;---------------------------------------------------------------------------

DATASIZE equ $-pkbdusx2Start

sEnd	DATA

;---------------------------------------------------------------------------


sBegin	CODE	; Beginning of code segment
assumes CS,CODE
assumes DS,DATA
sEnd	CODE

end

