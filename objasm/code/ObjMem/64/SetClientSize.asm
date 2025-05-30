; ==================================================================================================
; Title:      SetClientSize.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  SetClientSize
; Purpose:    Set the client window size.
; Arguments:  Arg1: Target window handle.
;             Arg2: Client area width in pixel.
;             Arg3: Client area height in pixel.
; Return:     Nothing.

% include &ObjMemPath&Common\SetClientSize_X.inc

end
