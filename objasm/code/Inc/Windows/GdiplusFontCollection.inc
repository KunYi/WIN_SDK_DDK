;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusFontCollection.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSFONTCOLL_H
  _GDIPLUSFONTCOLL_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
;    if _MSC_VER ge 1200
;      if _MSC_VER ge 1400
;      endif
;    endif
;    FontCollection proto WIN_STD_CALL_CONV
;    FontCollection proto WIN_STD_CALL_CONV
;    GetFamilyCount proto WIN_STD_CALL_CONV
;    GdipGetFontCollectionFamilyCount proto WIN_STD_CALL_CONV :nativeFontCollection, :ptr numFound
;    GetFamilies proto WIN_STD_CALL_CONV :INT_, :ptr FontFamily, :ptr INT_
;    if_ proto WIN_STD_CALL_CONV :numSought
;    SetStatus proto WIN_STD_CALL_CONV :InvalidParameter
;    if_ proto WIN_STD_CALL_CONV :nativeFamilyList
;    SetStatus proto WIN_STD_CALL_CONV :OutOfMemory
;    GdipGetFontCollectionFamilyList proto WIN_STD_CALL_CONV :nativeFontCollection, :numSought, :nativeFamilyList, :numFound
;    if_ proto WIN_STD_CALL_CONV :status
;    for_ proto WIN_STD_CALL_CONV
;    GdipCloneFontFamily proto WIN_STD_CALL_CONV :ptr nativeFamilyList, :ptr ptr gpfamilies
;    SetStatus proto WIN_STD_CALL_CONV :status
;    GetLastStatus proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :Status
;    InstalledFontCollection proto WIN_STD_CALL_CONV
;    InstalledFontCollection proto WIN_STD_CALL_CONV
;    PrivateFontCollection proto WIN_STD_CALL_CONV
;    PrivateFontCollection proto WIN_STD_CALL_CONV
;    AddFontFile proto WIN_STD_CALL_CONV :ptr WCHAR
;    AddMemoryFont proto WIN_STD_CALL_CONV :ptr, :length_
;    if _MSC_VER ge 1200
;    endif
  endif
endif
 