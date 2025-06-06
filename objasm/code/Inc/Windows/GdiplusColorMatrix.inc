;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusColorMatrix.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSCOLORMATRIX_H
  _GDIPLUSCOLORMATRIX_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      ColorChannelLUT struct
        BYTE 256 dup (?)
      ColorChannelLUT ends
      HistogramFormat typedef SDWORD
      HistogramFormatARGB equ 0
      HistogramFormatPARGB equ 1
      HistogramFormatRGB equ 2
      HistogramFormatGray equ 3
      HistogramFormatB equ 4
      HistogramFormatG equ 5
      HistogramFormatR equ 6
      HistogramFormatA equ 7
      
    endif
;    ColorMatrix struct
;      m REAL 5 dup (?)
;    ColorMatrix ends
    ColorMatrixFlags typedef SDWORD
    ColorMatrixFlagsDefault equ 0
    ColorMatrixFlagsSkipGrays equ 1
    ColorMatrixFlagsAltGray equ 2
    
    ColorAdjustType typedef SDWORD
    ColorAdjustTypeDefault equ 0
    ColorAdjustTypeBitmap equ 1
    ColorAdjustTypeBrush equ 2
    ColorAdjustTypePen equ 3
    ColorAdjustTypeText equ 4
    ColorAdjustTypeCount equ 5
    ColorAdjustTypeAny equ 6
    
;    ColorMap struct
;      oldColor Color <>
;      newColor Color <>
;    ColorMap ends
  endif
endif
 