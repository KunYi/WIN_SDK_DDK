;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusColor.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSCOLOR_H
  _GDIPLUSCOLOR_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ColorMode typedef SDWORD
    ColorModeARGB32 equ 0
    ColorModeARGB64 equ 1
    
    ColorChannelFlags typedef SDWORD
    ColorChannelFlagsC equ 0
    ColorChannelFlagsM equ 1
    ColorChannelFlagsY equ 2
    ColorChannelFlagsK equ 3
    ColorChannelFlagsLast equ 4
    
;    Color struct
;    Color ends
  endif
endif
 