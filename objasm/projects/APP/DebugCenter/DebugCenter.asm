; ==================================================================================================
; Title:      DebugCenter.asm
; Authors:    G. Friedrich
; Version     2.2.0
; Purpose:    ObjAsm DebugCenter application.
; Notes:      Version 1.1.0, October 2017
;               - First release. Ported to BNC.
;             Version 2.1.0, October 2019
;               - Added more color and font customization by HSE.
;             Version 2.1.1, October 2021
;               - First click into ChildTxt bug corrected.
;               - Find text bug corrected.
;               - Word break routine added to ChildTxt to improve usability.
;             Version 2.2.0, September 2022
;               - Background color command added.
;               - Some miscellaneous commands added (see Debug.inc for a complete list).
; ==================================================================================================


;TODO: translate some strings from Globals to resource definitions
;TODO: upgrade resource definitions like OA_Tools


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(CON, INFO)     ;Load OOP files and OS related objects

% include &MacPath&DlgTmpl.inc                          ;Load dialog tempate support
% include &COMPath&COM.inc

% include &IncPath&Windows\ole2.inc
% include &IncPath&Windows\shlobj.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\CommDlg.inc
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\OLE32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\ComDlg32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\UxTheme.lib

if DEBUGGING eq FALSE
  % include &MacPath&DebugShare.inc
endif

MakeObjects Primer, Stream, DiskStream                  ;Load or build the following objects
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects WinPrimer, Window, WinApp, MdiApp
MakeObjects Button, Hyperlink, IconButton
MakeObjects RegKey, IDL, IniFile
MakeObjects Dialog, DialogModal, DialogModalIndirect
MakeObjects DialogModeless, DialogModelessIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, XMenu, Magnetism
MakeObjects WinControl, Toolbar, Rebar, Statusbar, Tooltip, TextView, Image

include DebugCenter_Globals.inc                         ;Include application globals
include DebugCenter_DlgFindText.inc
include DebugCenter_Main.inc                            ;Include DebugCenter main object

start proc uses xbx                                     ;Program entry point
  mov xbx, $invoke(LoadLibrary, $OfsCStr("RichEd20.dll"))
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(DebugCenter)::DebugCenter.Init         ;Initialize the object data
  OCall $ObjTmpl(DebugCenter)::DebugCenter.Run          ;Execute the application
  OCall $ObjTmpl(DebugCenter)::DebugCenter.Done         ;Finalize it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke FreeLibrary, xbx                               ;Unload RichEdit library

  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
