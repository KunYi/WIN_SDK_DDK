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

	title	High Resolution Font Definitions
	%out	fonts
	page	,132




OEM	segment public


;	OEM Font Description

OEMFixed	dw	12		;lfheight
		dw	8		;lfwidth
		dw	0		;lfescapement
		dw	0		;character orientation
		dw	0		;weight
		db	0		;Italic
		db	0		;underline
		db	0		;strikeout
		db	255		;charset
		db	0		;output precision
		db	2		;clip precision
		db	2		;quality
		db	1		;pitch
		db	'Terminal',0	;face

;	Ansi Fixed Font Description

AnsiFixed	dw	12		;lfheight
		dw	9		;lfwidth
		dw	0		;lfescapement
		dw	0		;character orientation
		dw	0		;weight
		db	0		;Italic
		db	0		;underline
		db	0		;strikeout
		db	0		;charset
		db	0		;output precision
		db	2		;clip precision
		db	2		;quality
		db	1		;pitch
		db	'Courier',0	;face

;	Ansi Variable Pitch Font Definition

AnsiVar 	dw	12		;lfheight
		dw	9		;lfwidth
		dw	0		;lfescapement
		dw	0		;character orientation
		dw	0		;weight
		db	0		;Italic
		db	0		;underline
		db	0		;strikeout
		db	0		;charset
		db	0		;output precision
		db	2		;clip precision
		db	2		;quality
		db	2		;pitch
		db	'MS Sans Serif',0 ;face

OEM	ends
end
