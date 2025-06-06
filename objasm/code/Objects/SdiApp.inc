; ==================================================================================================
; Title:      SdiApp.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Windows SDI application objects.
; Notes:      Version C.1.1, January 2020
;               - SdiApp.OnNCDestroy moved to WinApp.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     SdiApp
; Purpose:    Implement a base object for Single Document Interface applications. It contains all
;             the needed support to build a running Windows application.

Object SdiApp, SdiAppID, WinApp
  RedefineMethod    Run
ObjectEnd


; ==================================================================================================
;    SdiApp implementation
; ==================================================================================================

if IMPLEMENT

;; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;; Method:     SdiApp.Init   - code sample-
;; Purpose:    Initialize the SDI application object.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method SdiApp.Init, uses xsi
;  SetObject xsi
;  ACall xsi.Init
;  mov dWndWidth, 500                                    ;Default creation width
;  mov dWndHeight, 350                                   ;Default creation height
;  invoke GetSystemMetrics, SM_CXSCREEN
;  invoke CenterForm, dWndWidth, eax
;  mov dWndPosX, eax
;
;  invoke GetSystemMetrics, SM_CYSCREEN
;  invoke CenterForm, dWndHeight, eax
;  mov dWndPosY, eax
;
;  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
;                         offset(szXTVDemoApp), offset(szAppTitle), WS_OVERLAPPEDWINDOW, \
;                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf
;
;  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
;  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
;MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     SdiApp.Run
; Purpose:    Launch the SDI application object starting the message loop.
; Arguments:  None.
; Return:     xax = Exit code passed to PostQuitMessage.
; Note:       xdi = Idle counter.

Method SdiApp.Run, uses xbx xdi xsi
  local Msg:MSG

  SetObject xsi
  lea xbx, Msg
  xor edi, edi                                          ;Reset idle counter
  .if [xsi].hWnd != 0
    .repeat
      invoke PeekMessage, xbx, 0, 0, 0, PM_REMOVE
      .if eax == FALSE
        OCall xsi.OnIdle, xdi                           ;Pass idle count
        .if eax == 0
          invoke WaitMessage
        .else
          inc xdi
        .endif
      .else
        .break .if Msg.message == WM_QUIT
        .if [xsi].hActiveMlsDlg != 0
          .continue .if $invoke(IsDialogMessage, [xsi].hActiveMlsDlg, xbx) != NULL
        .endif
        invoke TranslateAccelerator, [xsi].hWnd, [xsi].hAccelerators, xbx
        .if eax == 0                                    ;No accel translated
          invoke TranslateMessage, xbx                  ;=> translate the message
          invoke DispatchMessage, xbx
        .endif
        xor edi, edi                                    ;Reset idle counter
      .endif
    .until FALSE
    mov xax, Msg.wParam
  .else
    mov xax, -1
  .endif
MethodEnd

endif
