;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusStringFormat.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSSTRINGFORMAT_H
  _GDIPLUSSTRINGFORMAT_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
;    StringFormat struct
;      ;public:
;       GdiplusBase <>
;    StringFormat ends
;    sizeof_ proto WIN_STD_CALL_CONV :StringFormat
;    sizeof_ proto WIN_STD_CALL_CONV :StringFormat
;    GenericDefault proto WIN_STD_CALL_CONV
    GenericTypographic proto WIN_STD_CALL_CONV
    if _MSC_VER ge 1200
    endif
  endif
endif
 