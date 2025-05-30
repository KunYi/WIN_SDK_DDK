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
;-----------------------------Module-Header-----------------------------;
; Module Name:	njmp.mac
;
; This file contains macros definitions for near conditional jumps.
;
; Copyright (c) 1987 Microsoft Corporation
;
; Exported Functions:
;  None.
;
; Public Functions:
;  None.
;
; Public Data:
;  None.
;
; General Description:
;  This module defines a series of near (rather than short) conditional
;  jump macros.  Use them when you have a short conditional jump which
;  is out of range.  If your jump is
;
;	jXX	some_label
;
;  and the assembler complains that some_label is out of range, change it to:
;
;	njXX	some_label
;
;  The njXX macros will warn you if they become unnecessary at some point
;  due to code movement or streamlining.
;
;  For every jXX instruction on the 80286, there is a corresponding njXX
;  macro.
;
;  The loop instructions are supported too, with nloop, nloope, nloopne,
;  nloopz, and nloopnz.  Unlike the njXX macros (and unlike the corresponding
;  actual loop instructions), the nloopXX macros do NOT save the flags.
;
; Note:
;  Occasionally an njmp or nloop will be required when FIREWALLS is nonzero,
;  but will become unnecessary when FIREWALLS becomes zero.  In this case
;  you may append an F flag to the njXX or nloopXX macro to tell the macro to
;  generate the near jump code only when FIREWALLS is nonzero.	Thus
;
;	njXX	some_label,F
;
;  is effectively the same as:
;
;   if	FIREWALLS
;	njXX	some_label
;   else
;	jXX	some_label
;   endif
;
;-----------------------------------------------------------------------;

;-----------------------------------------------------------------------;
;
; The bulk of the njXX macros
;
;-----------------------------------------------------------------------;

ljmp	macro	label
	db	0e9h
	dw	label-$-2
	endm

njx	macro	cond,ncond,label
	j&ncond $+5
if @Version LT 600
if2
if (label GE ($-128)) AND (label LE ($+3+127))
%out	Warning: unnecessary  "nj&cond &label"
endif
endif
endif
	ljmp	label
	endm

if	FIREWALLS

	irp	cond,<a,ae,b,be,c,e,z,p,g,ge,l,le,o,s>

nj&cond macro	label,fireonly
	njx	&cond,n&cond,label
	endm

njn&cond macro	 label,fireonly
	njx	n&cond,&cond,label
	endm
	endm	;; irp

else

	irp	cond,<a,ae,b,be,c,e,z,p,g,ge,l,le,o,s>

nj&cond macro	label,fireonly
ifidni	<fireonly>,<f>
	j&cond	label
else
	njx	&cond,n&cond,label
endif
	endm

njn&cond macro	 label,fireonly
ifidni	<fireonly>,<f>
	jn&cond  label
else
	njx	n&cond,&cond,label
endif
	endm
	endm	;; irp

endif

;-----------------------------------------------------------------------;
;
; njpo and njpe
;
;-----------------------------------------------------------------------;
ifdef	INCL_NJMP_ALL
if	FIREWALLS

njpo	macro	label,fireonly
	njx	po,pe,label
	endm

else

njpo	macro	label,fireonly
ifidni	<fireonly>,<f>
	jpo	label
else
	njx	po,pe,label
endif
	endm

endif

if	FIREWALLS

njpe	macro	label,fireonly
	njx	pe,po,label
	endm

else


njpe	macro	label,fireonly
ifidni	<fireonly>,<f>
	jpe	label
else
	njx	pe,po,label
endif
	endm

endif
endif

;-----------------------------------------------------------------------;
;
; njmp
;
;-----------------------------------------------------------------------;

njmp	macro	label,fireonly
ifidni	<fireonly>,<f>
if	FIREWALLS
	jmp	label
if @Version LT 600
if2
if (label GE (($-1)-128)) AND (label LE (($-1)+127))
%out	Warning: unnecessary "njmp &label"
endif
endif
endif
else
	jmp	short label
endif
else
	jmp	label
if @Version LT 600
if2
if (label GE (($-1)-128)) AND (label LE (($-1)+127))
%out	Warning: unnecessary "njmp &label"
endif
endif
endif
endif
	endm

;-----------------------------------------------------------------------;
;
; njcxz
;
;-----------------------------------------------------------------------;

njcxz	macro	label,fireonly
ifidni	<fireonly>,<f>
if	FIREWALLS
	jcxz	$+4
if @Version LT 600
if2
if (label GE ($-128)) AND (label LE ($+5+127))
%out	Warning: unnecessary "njcxz &label"
endif
endif
endif
	jmp	short $+5
	ljmp	label
else
	jcxz	label
endif
else
	jcxz	$+4
if @Version LT 600
if2
if (label GE ($-128)) AND (label LE ($+5+127))
%out	Warning: unnecessary "njcxz &label"
endif
endif
endif
	jmp	short $+5
	ljmp	label
endif
	endm

;-----------------------------------------------------------------------;
;
; nloop
;
;-----------------------------------------------------------------------;

nlp	macro	label
	dec	cx
	jz	$+5
if @Version LT 600
if2
if (label GE (($-3+2)-128)) AND (label LE ($+3+127))
%out	Warning: unnecessary "nloop &label"
endif
endif
endif
	ljmp	 label
	endm

nloop	macro	label,fireonly
ifidni	<fireonly>,<f>
if	FIREWALLS
	nlp	label
else
	loop	label
endif
else
	nlp	label
endif
	endm

;-----------------------------------------------------------------------;
;
; nloope, nloopne, nloopz, and nloopnz
;
;-----------------------------------------------------------------------;

ifdef INCL_NJMP_ALL
nloopx	macro	cond,ncond,label
	j&ncond $+8
if @Version LT 600
if2
if (label GE ($-128)) AND (label LE ($+7+127))
%out	Warning: unnecessary "nloop&cond &label"
endif
endif
endif
	dec	cx
	jz	$+6
	ljmp	label
	dec	cx
	endm

if	FIREWALLS

	irp	cond,<e,z>

nloop&cond  macro   label,fireonly
	nloopx	&cond,n&cond,label
	endm

nloopn&cond macro   label,fireonly
	nloopx	n&cond,&cond,label
	endm
	endm	;; irp

else

	irp	cond,<e,z>

nloop&cond  macro   label,fireonly
ifidni	<fireonly>,<f>
	loop&cond   label
else
	nloopx	&cond,n&cond,label
endif
	endm

nloopn&cond macro   label,fireonly
ifidni	<fireonly>,<f>
	loopn&cond  label
else
	nloopx	n&cond,&cond,label
endif
	endm
	endm	;; irp

endif
endif
