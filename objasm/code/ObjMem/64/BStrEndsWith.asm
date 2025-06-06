; ==================================================================================================
; Title:      BStrEndsWith.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  BStrEndsWith
; Purpose:    Compare the ending of a BSTR.
; Arguments:  Arg1: -> Analized BSTR.
;             Arg2: -> Suffix BSTR.
; Return:     eax = TRUE of the ending matches, otherwise FALSE.

% include &ObjMemPath&Common\BStrEndsWith_X.inc

end
