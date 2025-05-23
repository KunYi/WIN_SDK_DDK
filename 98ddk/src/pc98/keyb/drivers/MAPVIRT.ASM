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

        page    ,132

VKFUN = 0

.xlist
include keyboard.inc

include vkwin.inc
include vkoem.inc
.list
include lcid.inc

if1
%out
%out   mapVirt.asm  (Microsoft)
endif
createSeg _MAPVK, MAPVK, BYTE, PUBLIC, CODE

        TITLE   MAPVIRTUALKEYEX - NEW ASCII translation routine

;*****************************************************************************

regptr          esdi,    es,di
by              equ      byte ptr
externFP        GetLCIDtable

;*****************************************************************************

sBegin   DATA

externD CurrentLocale

        ;***
        ;*** These are the values that are (a) always the same regardless of
        ;*** state, and (b) always the same regardless of keyboard.
        ;***
        ;*** Good assumption, but in case it's not true, we check this list
        ;*** AFTER the lcid list.
        ;***
ifdef	NEC_98
ScanCodes       label   byte
        DB   0eh        ;BS	VK_BACK
        DB   0fh        ;TAB	VK_TAB
        DB   01ch       ;Return	VK_RETURN
        DB   034h       ;Space	VK_SPACE
        DB   00h        ;ESC	VK_ESCAPE

        DB   039h       ;DEL	VK_DELETE

        DB   0bh        ;-,=	VK_OEM_MINUS    ; variable
        DB   26h        ;;,+	VK_OEM_PLUS     ; variable
        DB   01bh       ;[{	VK_OEM_4        ; variable
        DB   028h       ;]}	VK_OEM_6        ; variable
        DB   74h        ;CTRL	VK_CONTROL      
        DB   027h       ;:,*	VK_OEM_1        ; variable -- also VK_M
        DB   01ah       ;@,~	VK_OEM_3        ; variable
        DB   070h       ;SHIFT	VK_SHIFT        
        DB   0dh        ;\,|	VK_OEM_5        ; variable

        DB   030h       ;,,<	VK_OEM_COMMA    ; variable
        DB   031h       ;.,>	VK_OEM_PERIOD   ; variable
        DB   032h       ;/,?	VK_OEM_2        ; variable

	DB   033h	;_	VK_OEM_8

ifdef 	NEC_SHIFT
	DB   07Dh	;R-SHIFT
else	;NEC_SHIFT
        DB   070h       ;SHIFT		VK_SHIFT
endif	;NEC_SHIFT
        DB   073h       ;GRPH		VK_MENU
        DB   071h       ;CAPS LOCK	VK_CAPITAL
        DB   062h       ;f.1		VK_F1
        DB   063h       ;f.2		VK_F2
        DB   064h       ;f.3		VK_F3
        DB   065h       ;f.4		VK_F4
        DB   066h       ;f.5		VK_F5
        DB   067h       ;f.6		VK_F6
        DB   068h       ;f.7		VK_F7
        DB   069h       ;f.8		VK_F8
        DB   06ah       ;f.9		VK_F9
        DB   06bh       ;f.10		VK_F10

        DB   036h       ;ROLL UP	VK_NEXT
        DB   037h       ;ROLL DOWN	VK_PRIOR
        DB   038h       ;INS		VK_INSERT
        DB   03ah       ;up		VK_UP
        DB   03bh       ;left		VK_LEFT
        DB   03ch       ;right		VK_RIGHT
        DB   03dh       ;down		VK_DOWN

	DB   060h	;STOP		VK_CANCEL
	DB   061h	;COPY		VK_SNAPSHOT
	DB   072h	;Kana		VK_KANA
	DB   051h	;NFER		VK_NOCONVERT
	DB   035h	;XFER		VK_KANJI

        DB  052h        ;vf.1		VK_F11
        DB  053h        ;vf.2		VK_F12
        DB  054h        ;vf.3		VK_F13
        DB  055h        ;vf.4		VK_F14
        DB  056h        ;vf.5		VK_F15

ifdef	NEC_WINKEY
;
; NOTE: VK value and scan code are not same for PC98
;
	db  077h	;Left Windows	VK_LWIN
	db  078h	;Right Windows	VK_RWIN
	db  079h	;Application	VK_APPS
	db  06Ch	;		VK_POWER
	db  06Dh	;		VK_SLEEP
endif

else	;NEC_98
ScanCodes       label   byte
        DB   0eh        ; 14    VK_BACK         
        DB   0fh        ; 15    VK_TAB          
        DB   01ch       ; 28    VK_RETURN       
        DB   039h       ; 57    VK_SPACE        
        DB   01h        ; 1     VK_ESCAPE       

        DB   04ah       ; 74    VK_SUBTRACT     
        DB   04eh       ; 78    VK_ADD          
        DB   053h       ; 83    VK_DELETE       

        DB   00h        ; 0     -1              
        DB   0ch        ; 12    VK_OEM_MINUS    ; variable
        DB   0dh        ; 13    VK_OEM_PLUS     ; variable
        DB   01ah       ; 26    VK_OEM_4        ; variable
        DB   01bh       ; 27    VK_OEM_6        ; variable
        DB   01dh       ; 29    VK_CONTROL      
        DB   027h       ; 39    VK_OEM_1        ; variable -- also VK_M
        DB   028h       ; 40    VK_OEM_7        ; variable
        DB   029h       ; 41    VK_OEM_3        ; variable
        DB   02ah       ; 42    VK_SHIFT        
        DB   02bh       ; 43    VK_OEM_5        ; variable

        DB   033h       ; 51    VK_OEM_COMMA    ; variable
        DB   034h       ; 52    VK_OEM_PERIOD   ; variable
        DB   035h       ; 53    VK_OEM_2        ; variable

        DB   036h       ; 54    VK_SHIFT        
        DB   037h       ; 55    VK_MULTIPLY     
        DB   038h       ; 56    VK_MENU         
        DB   03ah       ; 58    VK_CAPITAL      
        DB   03bh       ; 59    VK_F1           
        DB   03ch       ; 60    VK_F2           
        DB   03dh       ; 61    VK_F3           
        DB   03eh       ; 62    VK_F4           
        DB   03fh       ; 63    VK_F5           
        DB   040h       ; 64    VK_F6           
        DB   041h       ; 65    VK_F7           
        DB   042h       ; 66    VK_F8           
        DB   043h       ; 67    VK_F9           
        DB   044h       ; 68    VK_F10          

        DB   045h       ; 69    VK_NUMLOCK      
        DB   046h       ; 70    VK_OEM_SCROLL   

ifdef WINKEY
;
; NOTE: VK value and scan code are the same! (except prefix for DOS)
;
	db	VK_LWIN		; 5b
	db	VK_RWIN		; 5c
	db	VK_APPS		; 5d
    db  VK_POWER    ; 5e
    db  VK_SLEEP    ; 5f
endif

        ; This is always in normal IBM-compatible driver:

ifdef ENHANCE
        DB  056h        ; 86    VK_OEM_102       
        DB  057h        ; 87    VK_F11           
        DB  058h        ; 88    VK_F12           
        ; This is the end of the table for drivers handling Enhanced keyboards!
endif   ; ENHANCE

endif	;NEC_98

ifdef	NEC_98
NumPad  label byte
        public NumPad
        
        DB   04eh       ;VK_NUMPAD0
        DB   04ah       ;VK_NUMPAD1
        DB   04bh       ;VK_NUMPAD2
        DB   04ch       ;VK_NUMPAD3
        DB   046h       ;VK_NUMPAD4
        DB   047h       ;VK_NUMPAD5
        DB   048h       ;VK_NUMPAD6
        DB   042h       ;VK_NUMPAD7
        DB   043h       ;VK_NUMPAD8
        DB   044h       ;VK_NUMPAD9
        
        DB   03eh       ;CLR		VK_CLEAR
        DB   03fh       ;HELP		VK_HELP
        DB   040h       ;-	VK_SUBTRACT
	DB   041h	;/ 	VK_DIVIDE
	DB   045h	;VK_MULTIPLY
        DB   049h       ;+	VK_ADD
	DB   04dh	;Numpad =
	DB   04fh	;Numpad ,
	DB   050h	;VK_DECIMAL

else	;NEC_98
NumPad  label byte
        public NumPad
        DB   052h       ; 82    VK_INSERT       
        DB   04fh       ; 79    VK_END          
        DB   050h       ; 80    VK_DOWN         
        DB   051h       ; 81    VK_NEXT         
        DB   04bh       ; 75    VK_LEFT         
        DB   04ch       ; 76    VK_CLEAR        
        DB   04dh       ; 77    VK_RIGHT        
        DB   047h       ; 71    VK_HOME         
        DB   048h       ; 72    VK_UP           
        DB   049h       ; 73    VK_PRIOR        

        DB   052h       ; 82    VK_NUMPAD0
        DB   04fh       ; 79    VK_NUMPAD1
        DB   050h       ; 80    VK_NUMPAD2
        DB   051h       ; 81    VK_NUMPAD3
        DB   04bh       ; 75    VK_NUMPAD4
        DB   04ch       ; 76    VK_NUMPAD5
        DB   04dh       ; 77    VK_NUMPAD6
        DB   047h       ; 71    VK_NUMPAD7
        DB   048h       ; 72    VK_NUMPAD8
        DB   049h       ; 73    VK_NUMPAD9
	DB   053h	;	VK_DECIMAL
endif	;NEC_98
ifdef KOREA
        DB   062h       ; VK_HANJA
        DB   06eh       ; VK_HANGEUL      
        DB   0f0h       ; VK_HANGEUL
        DB   0f1h       ; VK_HANJA
        DB   0f2h       ; VK_HANGEUL  
endif

KBD_SCANS 	equ $ - ScanCodes

;---------------------------------------------------------------------------

BaseAnsi label byte
        db      '0123456789'
VkBaseAnsi label byte
ifdef	NEC_98
        db      '-/*+=,.', 3
else	;NEC_98
        db      '/*-+.', 3
endif	;NEC_98
        db      8,9,0dH, 020H, 01bH

BaseAnsi_Len    equ     $-BaseAnsi
VkBaseAnsi_Len  equ     $-VkBaseAnsi
;---------------------------------------------------------------------------

AsciiVirtKeys   label   byte
        db      060h, 061h, 062h, 063h, 064h, 065h, 066h, 067h
        db      068h, 069h

AsciiVirtKeysNoNumpad label byte
        public AsciiVirtKeys, BaseAnsi, BaseAnsi_Len

VkVirtKeys        label   byte
ifdef	NEC_98
        db      06dh, 06fh, 06ah, 06bh, 092h, 06ch, 06eh, 3
else	;NEC_98
        db      06fh, 06ah, 06dh, 06bh, 06eh, 3
endif	;NEC_98

ifdef	NEC_98
VirtKeys        label   byte
        DB      VK_BACK
        DB      VK_TAB
        DB      VK_RETURN
        DB      VK_SPACE
        DB      VK_ESCAPE

        DB      VK_DELETE

        DB      VK_OEM_MINUS
        DB      VK_OEM_PLUS
        DB      VK_OEM_4
        DB      VK_OEM_6
        DB      VK_CONTROL
        DB      VK_OEM_1
        DB      VK_OEM_3
        DB      VK_SHIFT
        DB      VK_OEM_5

        DB      VK_OEM_COMMA
        DB      VK_OEM_PERIOD
        DB      VK_OEM_2

	DB	VK_OEM_8

        DB      VK_SHIFT
        DB      VK_MENU
        DB      VK_CAPITAL
        DB      VK_F1
        DB      VK_F2
        DB      VK_F3
        DB      VK_F4
        DB      VK_F5
        DB      VK_F6
        DB      VK_F7
        DB      VK_F8
        DB      VK_F9
        DB      VK_F10

        DB      VK_NEXT
        DB      VK_PRIOR
        DB      VK_INSERT
        DB      VK_UP
        DB      VK_LEFT
        DB      VK_RIGHT
        DB      VK_DOWN

VirtKeysSTOP	label	byte
	DB	VK_CANCEL
	DB	VK_SNAPSHOT
	DB	VK_KANA
	DB	VK_NONCONVERT	;NFER
	DB	VK_KANJI

        DB      VK_F11
        DB      VK_F12
        DB      VK_F13
        DB      VK_F14
        DB      VK_F15

ifdef WINKEY
	db	VK_LWIN		; 5b
	db	VK_RWIN		; 5c
	db	VK_APPS		; 5d
    db  VK_POWER    ; 5e
    db  VK_SLEEP    ; 5f
endif



        DB      VK_NUMPAD0
        DB      VK_NUMPAD1
        DB      VK_NUMPAD2
        DB      VK_NUMPAD3
        DB      VK_NUMPAD4
        DB      VK_NUMPAD5
        DB      VK_NUMPAD6
        DB      VK_NUMPAD7
        DB      VK_NUMPAD8
        DB      VK_NUMPAD9


VirtKeysCLR	label	byte
        DB      VK_CLEAR
VirtKeysHELP	label	byte
        DB      VK_HELP

	DB	VK_SUBTRACT
	DB	VK_DIVIDE
	DB	VK_MULTIPLY
	DB	VK_ADD
	DB	VK_OEM_EQU
	DB	VK_SEPARATER
        DB      VK_DECIMAL

else	;NEC_98

VirtKeys        label   byte
        DB      VK_BACK         ; 0eh 14
        DB      VK_TAB          ; 0fh 15
        DB      VK_RETURN       ; 01ch 28
        DB      VK_SPACE        ; 039h 57
        DB      VK_ESCAPE       ; 01h 1

        DB      VK_SUBTRACT     ; 04ah 74
        DB      VK_ADD          ; 04eh 78
        DB      VK_DELETE       ; 053h 83

        DB      -1              ; 00h 0
        DB      VK_OEM_MINUS    ; 0ch 12        ; variable
        DB      VK_OEM_PLUS     ; 0dh 13        ; variable
        DB      VK_OEM_4        ; 01ah 26       ; variable
        DB      VK_OEM_6        ; 01bh 27       ; variable
        DB      VK_CONTROL      ; 01dh 29
        DB      VK_OEM_1        ; 027h 39       ; variable -- also VK_M
        DB      VK_OEM_7        ; 028h 40       ; variable
        DB      VK_OEM_3        ; 029h 41       ; variable
        DB      VK_SHIFT        ; 02ah 42
        DB      VK_OEM_5        ; 02bh 43       ; variable

        DB      VK_OEM_COMMA    ; 033h 51       ; variable
        DB      VK_OEM_PERIOD   ; 034h 52       ; variable
        DB      VK_OEM_2        ; 035h 53       ; variable

        DB      VK_SHIFT        ; 036h 54
        DB      VK_MULTIPLY     ; 037h 55
        DB      VK_MENU         ; 038h 56
        DB      VK_CAPITAL      ; 03ah 58
        DB      VK_F1           ; 03bh 59
        DB      VK_F2           ; 03ch 60
        DB      VK_F3           ; 03dh 61
        DB      VK_F4           ; 03eh 62
        DB      VK_F5           ; 03fh 63
        DB      VK_F6           ; 040h 64
        DB      VK_F7           ; 041h 65
        DB      VK_F8           ; 042h 66
        DB      VK_F9           ; 043h 67
        DB      VK_F10          ; 044h 68

        DB      VK_NUMLOCK      ; 045h 69
        DB      VK_OEM_SCROLL   ; 046h 70

ifdef WINKEY
	db	VK_LWIN		; 5b
	db	VK_RWIN		; 5c
	db	VK_APPS		; 5d
    db  VK_POWER    ; 5e
    db  VK_SLEEP    ; 5f
endif

        ; This is always in normal IBM-compatible driver:

ifdef ENHANCE
; MERGE INTO ONE DRIVER AND USING PATCH TO CHANGE THE TABLE.
;ifdef KBD86KS   ; Korea only case for 86KS keyboard.
;        DB      VK_HANJA        ; 56h 86
;        DB      VK_HANGEUL      ; 57h 87
;else
ifdef KOREA
KBD_PATCH1    equ $ - VirtKeys
.ERRNZ   (KBD_PATCH-KBD_PATCH1)
endif
        DB      VK_OEM_102      ; 056h 86
        DB      VK_F11          ; 057h 87
;endif
        DB      VK_F12          ; 058h 88
        ; This is the end of the table for drivers handling Enhanced keyboards!
endif   ; ENHANCE

        DB      VK_INSERT       ; 052h 82
        DB      VK_END          ; 04fh 79
        DB      VK_DOWN         ; 050h 80
        DB      VK_NEXT         ; 051h 81
        DB      VK_LEFT         ; 04bh 75
        DB      VK_CLEAR        ; 04ch 76
        DB      VK_RIGHT        ; 04dh 77
        DB      VK_HOME         ; 047h 71
        DB      VK_UP           ; 048h 72
        DB      VK_PRIOR        ; 049h 73

        DB      VK_NUMPAD0      ; 052h 82
        DB      VK_NUMPAD1      ; 04fh 79
        DB      VK_NUMPAD2      ; 050h 80
        DB      VK_NUMPAD3      ; 051h 81
        DB      VK_NUMPAD4      ; 04bh 75
        DB      VK_NUMPAD5      ; 04ch 76
        DB      VK_NUMPAD6      ; 04dh 77
        DB      VK_NUMPAD7      ; 047h 71
        DB      VK_NUMPAD8      ; 048h 72
        DB      VK_NUMPAD9      ; 049h 73
        DB      VK_DECIMAL      ; 053h 
ifdef KOREA
        DB      VK_HANJA        ; 062h
        DB      VK_HANGEUL      ; 06eh
        DB      VK_HANGEUL      ; 0f0h
        DB      VK_HANJA        ; 0f1h
        DB      VK_HANGEUL      ; 0f2h        
endif
endif	;NEC_98
KBD_VIRTKEYS 	equ $ - VirtKeys

SCAN_TO_VKEY_OFFS	equ ((dataOFFSET VirtKeys)-(1+(dataOFFSET ScanCodes)))

        public VirtKeys, ScanCodes, KBD_SCANS, SCAN_TO_VKEY_OFFS
ifdef	NEC_98
	public VirtKeysSTOP, VirtKeysCLR, VirtKeysHELP
endif	;NEC_98

sEnd     DATA

;*****************************************************************************


;  The MapVirtualKey function is used by the PIF editor and
;  Winoldap to get information about keyboard mapping.
;
;  This maps the value in wCode into the returned value in AX,
;  according to the value of wMapType:
;
;  wMapType == 0: Map VK to scan code
;
;  wMapType == 1: Map scan code to VK
;
;  wMapType == 2: Map VK to Ascii.
;
;  (Larger values reserved for future expansion)
;
;***************************************************************************


sBegin MAPVK
assumes CS,MAPVK
assumes DS,DATA

.386

MapVirtualKey label far
        public MapVirtualKey
        mov     ax,     ds      ; prolgue
        nop
        mov     es,     ax
        pop     ebx             ; get back the return address
        mov     ecx,    es:CurrentLocale
        push    ecx
        push    ebx
        jmp     MapVirtualKeyEx+3


;***************************************************************************

cProc MapVirtualKeyEx,<PUBLIC,FAR, PASCAL, LOADDS>

        parmW   wCode                   ; value to be translated
        parmW   wMapType
        parmD   lcid

	localW	iDiacritics
cBegin		
        push    esi
        push    edi

        mov     edx, lcid
        call    GetLCIDtable
        or      bx, bx
        jz      BadMap

	xor	ax, ax
	mov	iDiacritics, ax		; cases 0 and 1
        mov     al, by wCode
        mov     cx, wMapType
        or      cx, cx
        jz      VirtKeyToScanCode
        dec     cx
        jz      ScanCodeToVirtKey
        dec     cx
        jnz     BadMap

;-----------------------------------------------------------------------------
VirtKeyToAnsi:

	mov	cx, [bx+NUM_DEAD]		; if we have diacritics
	mov	iDiacritics, cx

        mov     cx,  VkBaseAnsi_Len
	shl	ecx, 16

        mov     di,  dataOFFSET AsciiVirtKeysNoNumpad
        shl     edi, 16
        mov     di,  [bx+VKEYTOIDX]

        mov     si,  dataOFFSET VkBaseAnsi
	shl     esi, 16
        mov     si,  [bx+VKEYTOANSI]

        jmp     DoTheScan

;-----------------------------------------------------------------------------
ScanCodeToVirtKey:

        mov     cx,  KBD_SCANS
	shl	ecx, 16

        mov     si,  dataOFFSET VirtKeys
	shl     esi, 16
	mov     si,  [bx+VKEYTOIDX]

        mov     di,  dataOFFSET ScanCodes
        shl     edi, 16
        mov     di,  [bx+SCANTOIDX]
        jmp     DoTheScan

;-----------------------------------------------------------------------------
BadMap:
        xor     ax,     ax
        jmp     MapVirtDone

;-----------------------------------------------------------------------------
VirtKeyToScanCode:

        mov     cx,  KBD_SCANS
	shl	ecx, 16
        mov     di,  dataOFFSET VirtKeys
	shl     edi, 16
        mov     di,  [bx+VKEYTOIDX]
        mov     si,  dataOFFSET ScanCodes
        shl     esi, 16
        mov     si,  [bx+SCANTOIDX]
DoTheScan:
        mov     cx,  [bx+SCAN_SIZE]
Translate:
        mov     dx,  di
        repnz   scasb
        jz      GetOtherValue

TryStdKbdScan:
        ;
        ; test the base values that stay the same across every language, ie 
        ; VK_LEFT. 
        ;
        ror     esi, 16
        ror     edi, 16
	ror	ecx, 16
        mov     dx,  di
        repnz   scasb
        jnz     BadMap
GetOtherValue:
        dec     di
        sub     di,  dx
        add     si,  di
        lodsb
        xor     ah,  ah

;-----------------------------------------------------------------------------
;
; this will only occur for Vk to Ansi, and only for deadkey'ed tabled
;
	mov	cx, iDiacritics
	jcxz	MapVirtDone
	
	mov	di, [bx+DEAD_KEYS]
	test	[bx+LCID_FLAGS], DEADCOMBOS
	jz	NormalDead
	
	mov	bx, 4			; bump di by this value
@@:
	cmp	al, es:[di]
	jz	FoundDead
	add	di, bx
	loop	@B
	jmp	MapVirtDone		; didn't find it.

NormalDead:
	repnz	scasb
	jnz	MapVirtDone
FoundDead:
	mov	ah, 80H			; dead key!
;-----------------------------------------------------------------------------
MapVirtDone:
        pop     edi
        pop     esi
cEnd
.286p

sEnd MAPVK

end

