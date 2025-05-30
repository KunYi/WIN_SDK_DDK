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

	.xlist
;----------------------------Module-Header------------------------------;
; Module Name: EXIT.BLT
;
; Subroutine for cleaning up before exit.
;
; This file is part of a set that makes up the Windows BitBLT function
; at driver-level.
;-----------------------------------------------------------------------;
	.list

	.xlist
if	MASMFLAGS and PUBDEFS
	public	clean_up_before_exit
endif

ifdef	THIS_IS_DOS_3_STUFF
	externA	ScreenSelector
endif
	.list

;----------------------------Private-Routine----------------------------;
; clean_up_before_exit
;
; Restore the EGA to a known state.
;
; Entry:
;	EGA registers in uncertain state
; Returns:
;	EGA registers in default state
;	Nothing
; Registers Preserved:
;	BX,CX,SI,DI,BP,ES,flags
; Registers Destroyed:
;	AX,DX,DS
; Calls:
;	None
;-----------------------------------------------------------------------;

;------------------------------Pseudo-Code------------------------------;
; {
; }
;-----------------------------------------------------------------------;

clean_up_before_exit	proc	near

ifdef	GEN_COLOR_BLT

; Here we test if the EGA was involved and skip reseting the EGA state if
; it was not involved.  This saves time and avoids protection violations
; from using an undefined ScreenSelector.

	test	gl_the_flags,F0_DEST_IS_DEV + F0_SRC_IS_DEV
	jz	ega_not_involved

;	Restore EGA registers to the default state.

	mov	dx,EGA_BASE + SEQ_DATA
	mov	al,MM_ALL
	out	dx,al

	mov	dl,GRAF_ADDR
	mov	ax,0FF00h + GRAF_BIT_MASK
	out16	dx,ax

	mov	ax,DR_SET shl 8 + GRAF_DATA_ROT
	out16	dx,ax

	mov	ax,GRAF_ENAB_SR
	out16	dx,ax

	mov	ax,ScreenSelector
	mov	ds,ax
	assumes ds,EGAMem
	mov	ax,M_DATA_READ shl 8 + GRAF_MODE
	mov	shadowed_mode,ah
	out16	dx,ax

ega_not_involved:
endif
	ret

clean_up_before_exit	endp
