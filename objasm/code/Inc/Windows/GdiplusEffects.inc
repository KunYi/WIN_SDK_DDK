;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusEffects.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSEFFECTS_HPP
  _GDIPLUSEFFECTS_HPP equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      SharpenParams struct
        radius REAL4 ?
        amount REAL4 ?
      SharpenParams ends

      BlurParams struct
        radius REAL4 ?
        expandEdge BOOL ?
      BlurParams ends

      BrightnessContrastParams struct
        brightnessLevel INT_ ?
        contrastLevel INT_ ?
      BrightnessContrastParams ends

      RedEyeCorrectionParams struct
        numberOfAreas UINT ?
        areas POINTER ?
      RedEyeCorrectionParams ends

      HueSaturationLightnessParams struct
        hueLevel INT_ ?
        saturationLevel INT_ ?
        lightnessLevel INT_ ?
      HueSaturationLightnessParams ends

      TintParams struct
        hue INT_ ?
        amount INT_ ?
      TintParams ends

      LevelsParams struct
        highlight INT_ ?
        midtone INT_ ?
        shadow INT_ ?
      LevelsParams ends

      ColorBalanceParams struct
        cyanRed INT_ ?
        magentaGreen INT_ ?
        yellowBlue INT_ ?
      ColorBalanceParams ends

      ColorLUTParams struct
        lutB ColorChannelLUT ?
        lutG ColorChannelLUT ?
        lutR ColorChannelLUT ?
        lutA ColorChannelLUT ?
      ColorLUTParams ends

      CurveAdjustments typedef SDWORD
      AdjustExposure equ 0
      AdjustDensity equ 1
      AdjustContrast equ 2
      AdjustHighlight equ 3
      AdjustShadow equ 4
      AdjustMidtone equ 5
      AdjustWhiteSaturation equ 6
      AdjustBlackSaturation equ 7
      
      CurveChannel typedef SDWORD
      CurveChannelAll equ 0
      CurveChannelRed equ 1
      CurveChannelGreen equ 2
      CurveChannelBlue equ 3
      
      ColorCurveParams struct
        adjustment CurveAdjustments ?
        channel CurveChannel ?
        adjustValue INT_ ?
      ColorCurveParams ends

      externdef GdipCreateEffect proto WIN_STD_CALL_CONV :GUID, :ptr ptr CGpEffect
      GdipDeleteEffect proto WIN_STD_CALL_CONV :ptr CGpEffect
      GdipGetEffectParameterSize proto WIN_STD_CALL_CONV :ptr CGpEffect, :ptr UINT
      GdipSetEffectParameters proto WIN_STD_CALL_CONV :ptr CGpEffect, :ptr VOID, :UINT
      GdipGetEffectParameters proto WIN_STD_CALL_CONV :ptr CGpEffect, :ptr UINT, :ptr VOID
      ifndef _GDIPLUSEFFECTS_EXCLUDEOBJECTS
        Effect struct
            POINTER  ?   ; 'virtual method table'
        Effect ends

        Blur struct
          ;public:
           Effect <>
        Blur ends

        Sharpen struct
          ;public:
           Effect <>
        Sharpen ends

        RedEyeCorrection struct
          ;public:
           Effect <>
        RedEyeCorrection ends

        BrightnessContrast struct
          ;public:
           Effect <>
        BrightnessContrast ends

        HueSaturationLightness struct
          ;public:
           Effect <>
        HueSaturationLightness ends

        Levels struct
          ;public:
           Effect <>
        Levels ends

        Tint struct
          ;public:
           Effect <>
        Tint ends

        ColorBalance struct
          ;public:
           Effect <>
        ColorBalance ends

        ColorMatrixEffect struct
          ;public:
           Effect <>
        ColorMatrixEffect ends

        ColorLUT struct
          ;public:
           Effect <>
        ColorLUT ends

        ColorCurve struct
          ;public:
           Effect <>
        ColorCurve ends

      endif
    endif
  endif
endif
 