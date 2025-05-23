; ==================================================================================================
; Title:      word2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  word2hexA
; Purpose:    Convert a DORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: WORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 5 BYTEs large to allocate the output string
;             (4 character BYTEs + ZTC = 5 BYTEs).

OPTION PROC:NONE

align ALIGN_CODE
word2hexA proc pBuffer:POINTER, wValue:WORD
  ;rcx -> Buffer, dx = wValue
  lea r10, HexCharTableA
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shl r8, 16
  movzx eax, dh
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  mov [rcx], r8d
  m2z CHRA ptr [rcx + 4*sizeof(CHRA)]                   ;Set ZTC
  ret
word2hexA endp

OPTION PROC:DEFAULT

end
