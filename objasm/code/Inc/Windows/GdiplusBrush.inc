;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusBrush.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSBRUSH_H
  _GDIPLUSBRUSH_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
;    Brush struct
;        POINTER  ?   ; 'virtual method table'
;      ;public:
;       GdiplusBase <>
;    Brush ends
;    SolidBrush struct
;      ;public:
;       Brush <>
;    SolidBrush ends
;    TextureBrush struct
;      ;public:
;       Brush <>
;    TextureBrush ends
;    LinearGradientBrush struct
;      ;public:
;       Brush <>
;    LinearGradientBrush ends
;    HatchBrush struct
;      ;public:
;       Brush <>
;    HatchBrush ends
    if _MSC_VER ge 1200
    endif
  endif
endif
 