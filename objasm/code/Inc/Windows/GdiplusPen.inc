;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusPen.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSPEN_H
  _GDIPLUSPEN_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
;    Pen struct
;      ;public:
;       GdiplusBase <>
;    Pen ends
    if _MSC_VER ge 1200
    endif
  endif
endif
 