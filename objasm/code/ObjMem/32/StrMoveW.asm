; ==================================================================================================
; Title:      StrMoveW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrMoveW
; Purpose:    Move part of a WIDE string. The ending zero charactrer is not appended automatically.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Character count.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrMoveW proc pBuffer:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  mov eax, [esp + 12]                                   ;dCharCount
  shl eax, 1
  invoke MemShift, [esp + 12], [esp + 12], eax          ;pDstStringW, pSrcStringW
  ret 12
StrMoveW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
