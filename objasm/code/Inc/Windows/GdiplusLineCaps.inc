;    CustomLineCap proto WIN_STD_CALL_CONV :ptr GraphicsPath, :ptr GraphicsPath, :LineCap, :REAL
;    CustomLineCap proto WIN_STD_CALL_CONV
;    CustomLineCap proto WIN_STD_CALL_CONV
;    SetStrokeCaps proto WIN_STD_CALL_CONV :LineCap, :LineCap
;    GetStrokeCaps proto WIN_STD_CALL_CONV :ptr LineCap, :ptr LineCap
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :startCap, :endCap
;    SetStrokeJoin proto WIN_STD_CALL_CONV :LineJoin
;    GetStrokeJoin proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr lineJoin
;    SetBaseCap proto WIN_STD_CALL_CONV :LineCap
;    GetBaseCap proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr baseCap
;    SetBaseInset proto WIN_STD_CALL_CONV :REAL
;    GetBaseInset proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr inset
;    SetWidthScale proto WIN_STD_CALL_CONV :REAL
;    GetWidthScale proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr widthScale
;    Clone proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr newNativeLineCap
;    if_ proto WIN_STD_CALL_CONV :lastResult
;    CustomLineCap proto WIN_STD_CALL_CONV :newNativeLineCap, :lastResult
;    if_ proto WIN_STD_CALL_CONV :newLineCap
;    SetStatus proto WIN_STD_CALL_CONV :DllExports
;    GetLastStatus proto WIN_STD_CALL_CONV
;    return proto WIN_STD_CALL_CONV :lastStatus
;    AdjustableArrowCap struct
;      ;public:
;       CustomLineCap <>
;    AdjustableArrowCap ends
;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusLineCaps.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSLINECAPS_H
  _GDIPLUSLINECAPS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
endif
 