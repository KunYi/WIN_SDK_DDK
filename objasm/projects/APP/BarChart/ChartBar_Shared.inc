; ==================================================================================================
; Title:      ChartBar_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm chart demonstration program.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <ChartBar>
ABOUT_TEXT                    textequ   <ChartBar>
COPYRIGHT                     textequ   <G. Friedrich   August 2021>
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       261
BUILD_DATE_STR                textequ   <2022-12-15>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_NEW                  equ       051
IDM_FILE_CLOSE                equ       052
IDM_FILE_EXIT                 equ       053

IDM_WINDOW                    equ       080
IDM_WINDOW_CASCADE            equ       081
IDM_WINDOW_TILE_HOR           equ       082
IDM_WINDOW_TILE_VER           equ       083
IDM_WINDOW_ARRANGE            equ       084
IDM_WINDOW_CLOSEALL           equ       085

IDM_HELP                      equ       090
IDM_HELP_HELP                 equ       091
IDM_HELP_ABOUT                equ       092

;Bitmap IDs
IDB_FILE_NEW                  equ       002
IDB_FILE_CLOSE                equ       003
IDB_FILE_EXIT                 equ       004

IDB_WINDOW_CASCADE            equ       005
IDB_WINDOW_TILE_HOR           equ       006
IDB_WINDOW_TILE_VER           equ       007
IDB_WINDOW_ARRANGE            equ       008
IDB_WINDOW_CLOSEALL           equ       009

;Control IDs
IDC_TOOLBARFILE               equ       100
IDC_TOOLBARWINDOW             equ       101
IDC_STATUSBAR                 equ       102

;Language IDs
IDLANG_ENGLISH                equ       000

ID_MDI_MORE                   equ       50009
ID_MDI_LIST                   equ       50010
