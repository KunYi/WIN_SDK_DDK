; ==================================================================================================
; Title:      Demo10_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Demo10 globals.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


include Demo10_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "� &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

.data
dSetupOption1   DWORD   3     ;None
