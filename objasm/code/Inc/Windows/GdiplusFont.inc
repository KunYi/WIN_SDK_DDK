;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusFont.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSFONT_H
  _GDIPLUSFONT_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
;    Font proto WIN_STD_CALL_CONV :HDC
;    Font proto WIN_STD_CALL_CONV :HDC, :HFONT
;    Font proto WIN_STD_CALL_CONV :HDC, :ptr LOGFONTW
;    Font proto WIN_STD_CALL_CONV :HDC, :ptr LOGFONTA
;    Font proto WIN_STD_CALL_CONV :ptr FontFamily, :REAL, :INT_, :Unit
;    Font proto WIN_STD_CALL_CONV :ptr WCHAR, :REAL, :INT_, :Unit, :ptr FontCollection
;    GetLogFontA proto WIN_STD_CALL_CONV :ptr Graphics, :ptr LOGFONTA
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :g, :logfontA
;    GetLogFontW proto WIN_STD_CALL_CONV :ptr Graphics, :ptr LOGFONTW
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :g, :logfontW
;    Clone proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr cloneFont
;    Font proto WIN_STD_CALL_CONV :cloneFont, :lastResult
;    Font proto WIN_STD_CALL_CONV
;    IsAvailable proto WIN_STD_CALL_CONV
;    return proto WIN_STD_CALL_CONV :nativeFont
;    GetFamily proto WIN_STD_CALL_CONV :ptr FontFamily
;    if_ proto WIN_STD_CALL_CONV :family
;    SetStatus proto WIN_STD_CALL_CONV :InvalidParameter
;    GdipGetFamily proto WIN_STD_CALL_CONV :nativeFont, :ptr family
;    SetStatus proto WIN_STD_CALL_CONV :status
;    SetStatus proto WIN_STD_CALL_CONV :status
;    GetStyle proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr style
;    GetSize proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr size_
;    GetUnit proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr unit
;    GetHeight proto WIN_STD_CALL_CONV :ptr Graphics
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :graphics, :ptr height
;    GetHeight proto WIN_STD_CALL_CONV :REAL
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :dpi, :ptr height
;    Font proto WIN_STD_CALL_CONV :ptr GpFont, :Status
;    SetNativeFont proto WIN_STD_CALL_CONV :ptr GpFont
;    GetLastStatus proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :Status
;    if_ proto WIN_STD_CALL_CONV :status
;    return proto WIN_STD_CALL_CONV :lastResult
  endif
endif
 