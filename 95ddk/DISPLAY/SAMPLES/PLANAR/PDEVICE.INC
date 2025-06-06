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
; Module Name: PDEVICE.BLT
;
; Subroutine for processing the physical device data structures.
;
; This file is part of a set that makes up the Windows BitBLT function
; at driver-level.
;-----------------------------------------------------------------------;
	.list


	.xlist
if	MASMFLAGS and PUBDEFS
	public	pdevice_processing
	public	pdevice_decode_dest
ifdef	GEN_COLOR_BLT
	public	pdevice_chk_color_conv
	public	pdevice_set_src_flag
	public	pdevice_set_dest_flag
endif
	public	pdevice_proc_end
	public	pdevice_error
endif
	.list

;----------------------------Private-Routine----------------------------;
; pdevice_processing
;
; Check the required bitmaps for validity, get their parameters
; and store the information locally.
;
; If a brush (pattern) is required, get the address of the bits
; making up the pattern.
;
; If an invalid bitmap is encountered, abort.
;
; Entry:
;	BL = Initial gl_the_flags
;	     F0_SRC_PRESENT set is source needed
;	     F0_PAT_PRESENT set if pattern needed
; Returns:
;	Carry flag clear if no error.
; Error Returns:
;	Carry flag set if error (null pointer to source device, when
;		one is expected; error returned from copy_dev).
; Registers Preserved:
;	BL,CX,DX,BP
; Registers Destroyed:
;	AX,BH,SI,DI,DS,ES,flags
; Calls:
;	copy_dev
;-----------------------------------------------------------------------;

;------------------------------Pseudo-Code------------------------------;
; {
; }
;-----------------------------------------------------------------------;

pdevice_processing	proc	near

ifdef	THIS_IS_DOS_3_STUFF
else
	mov	ScreenSelector,0FFF0h	;!!! rip incase selector is loaded
endif
	mov	ax,ss			;Set ES to frame segment
	mov	es,ax
	xor	bh,bh			;BH = real gl_the_flags

	test	bl,F0_SRC_PRESENT	;Is a source needed?
	jz	pdevice_decode_dest	;  No, skip source validation

	lds	si,lpSrcDev		;Get pointer to source
	mov	ax,ds			;Null pointer?
	or	ax,si
	jz	pdevice_error		;Null pointer, error, abort
	lea	di,gl_src		;--> where parameters will go
	call	copy_dev 		;Get all the data
	jc	pdevice_error



;	Decode the destination parameters.  All BLTs must have a destination.

pdevice_decode_dest:
	lds	si,lpDestDev		;Get pointer to destination
	lea	di,gl_dest 		;--> where parameters will go
	call	copy_dev 		;Get all the data
	jc	pdevice_error


;	The pattern fetch code will be based on the color format of the
;	destination.  If the destination is mono, then a mono fetch will be
;	performed.  If the destination is color, then a color fetch will be
;	performed.

	or	bh,bl			;Merge in F0_SRC_PRESENT, F0_PAT_PRESENT
ifdef	GEN_COLOR_BLT
	test	bh,F0_DEST_IS_COLOR	;Show color pattern needed if
	jz	pdevice_chk_color_conv	;  destination is color
	or	bh,F0_COLOR_PAT



;	Check for color conversion.  If so, then set F0_GAG_CHOKE.
;	Color conversion will exist if the source and destination are of
;	different color formats.


pdevice_chk_color_conv:
	test	bh,F0_SRC_PRESENT    	;Is there a source?
	jz	pdevice_set_dest_flag	;  No, cannot be converting.
	mov	al,bh
	and	al,F0_SRC_IS_COLOR+F0_DEST_IS_COLOR
	jz	pdevice_set_src_flag	;Both are monochrome
	xor	al,F0_SRC_IS_COLOR+F0_DEST_IS_COLOR
	jz	pdevice_set_src_flag	;Both are color
	or	bh,F0_GAG_CHOKE		;Mono ==> color or color ==> mono
	lds	si,lpDrawMode
	mov	al,[si].bkColor.SPECIAL
	mov	ah,[si].TextColor.SPECIAL
	errnz	C0_BIT+C1_BIT+C2_BIT+C3_BIT-0Fh
	and	ax,0F0Fh
	mov	cl_both_colors,ax

;	Setup the scan line update flag in the source device structure.
;	The source will use a monochrome style update if it is the display,
;	it is monochrome, or it is color and the destination device is
;	monochrome.

pdevice_set_src_flag:
	mov	al,bh			;Set 'Z' if to use color update
	and	al,F0_SRC_IS_DEV+F0_SRC_IS_COLOR+F0_DEST_IS_COLOR
	xor	al,F0_SRC_IS_COLOR+F0_DEST_IS_COLOR
	jnz	pdevice_set_dest_flag	;Use the mono update
	or	gl_src.dev_flags,COLOR_UP;Show color scan update

;	Setup the scan line update flag in the destination device
;	structure.  The destination will use a monochrome update
;	if it is monochrome or the display.  It will use a color
;	update if it is a color bitmap.

pdevice_set_dest_flag:
	mov	al,bh			;Set 'Z' if to use color destination
	and	al,F0_DEST_IS_DEV+F0_DEST_IS_COLOR;  update code
	xor	al,F0_DEST_IS_COLOR
	jnz	pdevice_proc_end	;Mono update
	or	gl_dest.dev_flags,COLOR_UP;Show color scan update
endif	;GEN_COLOR_BLT

pdevice_proc_end:
	clc
	ret

pdevice_error:
	stc
	ret

pdevice_processing	endp
