;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusTypes.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSTYPES_H
  _GDIPLUSTYPES_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
;    externdef TYPE_ImageAbort 
;    typedef proto WIN_STD_CALL_CONV :ptr VOID
    ImageAbort typedef ptr TYPE_ImageAbort
    DrawImageAbort typedef ImageAbort
    GetThumbnailImageAbort typedef ImageAbort
;    externdef TYPE_EnumerateMetafileProc 
;    typedef proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE, :ptr VOID
    EnumerateMetafileProc typedef ptr TYPE_EnumerateMetafileProc
    if (GDIPVER ge 0110h)
      Abort proto WIN_STD_CALL_CONV
    endif
    REAL typedef REAL4
    REAL_MAX equ <FLT_MAX>
    REAL_MIN equ <FLT_MIN>
    REAL_TOLERANCE equ (FLT_MIN * 100)
    REAL_EPSILON equ 1.192092896E-07
    Status typedef SDWORD
    Ok equ 0
    GenericError equ 1
    InvalidParameter equ 2
    OutOfMemory equ 3
    ObjectBusy equ 4
    InsufficientBuffer equ 5
    NotImplemented equ 6
    Win32Error equ 7
    WrongState equ 8
    Aborted equ 9
    FileNotFound equ 10
    ValueOverflow equ 11
    AccessDenied equ 12
    UnknownImageFormat equ 13
    FontFamilyNotFound equ 14
    FontStyleNotFound equ 15
    NotTrueTypeFont equ 16
    UnsupportedGdiplusVersion equ 17
    GdiplusNotInitialized equ 18
    PropertyNotFound equ 19
    PropertyNotSupported equ 20
    if (GDIPVER ge 0110h)
      ProfileNotFound equ 21
    endif
    
    SizeF struct
    SizeF ends
    Size_ struct
    Size_ ends
    PointF struct
    PointF ends
    Point struct
    Point ends
    RectF struct
    RectF ends
    Rect struct
    Rect ends
    PathData struct
    PathData ends
    CharacterRange struct
    CharacterRange ends
    if _MSC_VER ge 1200
    endif
  endif
endif
 