;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusHeaders.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSHEADERS_H
  _GDIPLUSHEADERS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
;    Region struct
;      ;public:
;       GdiplusBase <>
;    Region ends
;    FontFamily struct
;      ;public:
;       GdiplusBase <>
;    FontFamily ends
;    sizeof_ proto WIN_STD_CALL_CONV :FontFamily
;    sizeof_ proto WIN_STD_CALL_CONV :FontFamily
;    sizeof_ proto WIN_STD_CALL_CONV :FontFamily
;    Font struct
;      ;public:
;       GdiplusBase <>
;    Font ends
;    FontCollection struct
;        POINTER  ?   ; 'virtual method table'
;      ;public:
;       GdiplusBase <>
;    FontCollection ends
;    InstalledFontCollection struct
;      ;public:
;       FontCollection <>
;    InstalledFontCollection ends
;    PrivateFontCollection struct
;      ;public:
;       FontCollection <>
;    PrivateFontCollection ends
;    Image struct
;        POINTER  ?   ; 'virtual method table'
;      ;public:
;       GdiplusBase <>
;      if (GDIPVER ge 0110h)
;      endif
;    Image ends
;    Bitmap struct
;      ;public:
;       Image <>
;      if (GDIPVER ge 0110h)
;      endif
;    Bitmap ends
;    CustomLineCap struct
;        POINTER  ?   ; 'virtual method table'
;      ;public:
;       GdiplusBase <>
;    CustomLineCap ends
;    CachedBitmap struct
;        POINTER  ?   ; 'virtual method table'
;      ;public:
;       GdiplusBase <>
;    CachedBitmap ends
;    Metafile struct
;      ;public:
;       Image <>
;      if (GDIPVER ge 0110h)
;      endif
;    Metafile ends
;    if _MSC_VER ge 1200
;    endif
  endif
endif
 