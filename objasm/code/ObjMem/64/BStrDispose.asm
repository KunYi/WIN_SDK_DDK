; ==================================================================================================
; Title:      BStrDispose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  BStrDispose
; Purpose:    Free the memory allocated for the string using BStrNew, BStrCNew, BStrLENew or
;             BStrAlloc.
;             If the pointer to the string is NULL, BStrDispose does nothing.
; Arguments:  Arg1: -> BStr.
; Return:     Nothing.

align ALIGN_CODE
BStrDispose proc pBStr:POINTER                          ;rcx -> BStr
  .if rcx != NULL                   
    sub rcx, 4
    invoke GlobalFree, rcx
  .endif
  ret
BStrDispose endp

end
