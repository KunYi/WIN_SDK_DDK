;*  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
;*  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
;*  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR
;*  A PARTICULAR PURPOSE.
;*
;*  Copyright (C) 1993 - 1995 Microsoft Corporation. All Rights Reserved.

?PLM=1      ; PASCAL Calling convention is DEFAULT
?WIN=1	    ; Windows calling convention

        .286p
	.xlist
	include cmacros.inc
;       include windows.inc
        .list

ifndef SEGNAME
    SEGNAME equ <_TEXT>
endif

createSeg %SEGNAME, CodeSeg, word, public, CODE

;-----------------------------------------------------------------------;
;   external functions
;
        externFP    LocalInit           ; in KERNEL
;       externP     LibMain             ; C code to do DLL init

;-----------------------------------------------------------------------;
;
; Stuff needed to avoid the C runtime coming in, and init the windows
; reserved parameter block at the base of DGROUP
;
%out link me first!!
sBegin  Data
assumes DS,Data
            org 0               ; base of DATA segment!

            DD  0               ; So null pointers get 0
maxRsrvPtrs = 5
            DW  maxRsrvPtrs
usedRsrvPtrs = 0
labelDP     <PUBLIC,rsrvptrs>

DefRsrvPtr  MACRO   name
globalW     name,0
usedRsrvPtrs = usedRsrvPtrs + 1
ENDM

DefRsrvPtr  pLocalHeap          ; Local heap pointer
DefRsrvPtr  pAtomTable          ; Atom table pointer
DefRsrvPtr  pStackTop           ; top of stack
DefRsrvPtr  pStackMin           ; minimum value of SP
DefRsrvPtr  pStackBot           ; bottom of stack

if maxRsrvPtrs-usedRsrvPtrs
            DW maxRsrvPtrs-usedRsrvPtrs DUP (0)
endif

public  __acrtused
	__acrtused = 1

sEnd        Data

;-----------------------------------------------------------------------;

sBegin  CodeSeg
        assumes cs,CodeSeg

;--------------------------Private-Routine-----------------------------;
;
; LibEntry - called when DLL is loaded
;
; Entry:
;       CX    = size of heap
;       DI    = module handle
;       DS    = automatic data segment
;       ES:SI = address of command line (not used)
;
; Returns:
;       AX = TRUE if success
; Error Returns:
;       AX = FALSE if error (ie fail load process)
; Registers Preserved:
;	SI,DI,DS,BP
; Registers Destroyed:
;       AX,BX,CX,DX,ES,FLAGS
; Calls:
;	None
; History:
;
;       06-27-89 Created.
;-----------------------------------------------------------------------;

cProc   LibEntry,<FAR,PUBLIC,NODATA>,<>
cBegin
	;
        ; Push frame for LibMain (hModule,cbHeap,lpszCmdLine)
	;
	push	di
	push	cx
	push	es
	push	si
        ;
        ; Init the local heap (if one is declared in the .def file)
        ;
        jcxz no_heap

        cCall   LocalInit,<0,0,cx>

no_heap:
;        cCall   LibMain
cEnd

        assumes ds,nothing
        assumes es,nothing

cProc   WEP, <FAR, PUBLIC, PASCAL>, <>
;       ParmW  fSystemExit
cBegin nogen
        mov     ax,1
        retf 2
cEnd   nogen

sEnd    CodeSeg

        end     LibEntry
