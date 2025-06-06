; ==================================================================================================
; Title:      St0ToStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

option stackbase:rbp

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  St0ToStrW
; Purpose:    Create a WIDE string representation of the content of the st(0) FPU register.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Minimal number of places from the start of string up to the decimal point.
;                   (f_NOR only)
;             Arg3: Number of decimal places after the decimal point.
;             Arg4: Format flag (f_NOR, f_SCI, f_TRIM, f_ALIGNED) defined in fMath.inc
; Return:     eax = Result code f_OK, f_ERROR, f_NAN, ...
; Notes:      - Based on the work of Raymond Filiatreault (FpuLib).
;             - st4, st5, st6 and st7 must be empty.
;             - f_NOR: regular output format
;             - f_SCI: Scientific output format
;             - f_TRIM: Trim zeros on the right
;             - f_ALIGN: Add a heading space to align the output with other negative numbers
;             - f_PLUS: like f_ALIGN, but using a + character.

% include &ObjMemPath&Common\St0ToStr_WXP.inc

end
