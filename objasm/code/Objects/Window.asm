; ==================================================================================================
; Title:      Window.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Window object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer

;Add here the file that defines the object(s) to be included in the library
MakeObjects Window

end
