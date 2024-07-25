; ==================================================================================================
; Title:      Dictionary.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for Dictionary object.
; Notes:      Version C.1.1, March 2022
;             - First release.
; ==================================================================================================


% include Objects.cop


;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects HashMap

;Add here the file that defines the object(s) to be included in the library
MakeObjects Dictionary

end
