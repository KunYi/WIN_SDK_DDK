;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusMetafile.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSMETAFILE_H
  _GDIPLUSMETAFILE_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    Metafile proto WIN_STD_CALL_CONV :HMETAFILE, :ptr WmfPlaceableFileHeader, :BOOL
;    Metafile proto WIN_STD_CALL_CONV :HENHMETAFILE, :BOOL
;    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr WmfPlaceableFileHeader
;    Metafile proto WIN_STD_CALL_CONV :ptr IStream
;    Metafile proto WIN_STD_CALL_CONV :HDC, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
;    GetMetafileHeader proto WIN_STD_CALL_CONV :HMETAFILE, :ptr WmfPlaceableFileHeader, :ptr MetafileHeader
;    GetMetafileHeader proto WIN_STD_CALL_CONV :HENHMETAFILE, :ptr MetafileHeader
;    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr MetafileHeader
;    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr IStream, :ptr MetafileHeader
;    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr MetafileHeader
;    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :header
;    GetHENHMETAFILE proto WIN_STD_CALL_CONV
;    PlayRecord proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE
;    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :recordType, :flags, :dataSize, :data
;    SetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV :UINT
;    GetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :ptr metafileRasterizationLimitDpi
;    EmfToWmfBits proto WIN_STD_CALL_CONV :HENHMETAFILE, :UINT, :LPBYTE, :INT_, :eFlags_
    if (GDIPVER ge 0110h)
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr WCHAR, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr IStream, :ptr INT_, :EmfType, :ptr WCHAR
    endif
  endif
endif
 