; ==================================================================================================
; Title:      XTreeView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XTreeView object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&SDLL.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Collection
LoadObjects XWCollection
LoadObjects DataPool
LoadObjects SimpleImageList
LoadObjects MaskedImageList

;Add here the file that defines the object(s) to be included in the library
MakeObjects XTreeView

end
