;Include file created by h2incX, Version C.01.00, 14/10/2022 22:00
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'mux_types.h', last modified: 26/12/2019 20:24


ifndef WEBP_WEBP_MUX_TYPES_INC_
  WEBP_WEBP_MUX_TYPES_INC_ equ <>

  %include &WEBP_INC_PATH&\types.inc
  WebPFeatureFlags typedef SDWORD
  ANIMATION_FLAG equ 00000002h
  XMP_FLAG equ 00000004h
  EXIF_FLAG equ 00000008h
  ALPHA_FLAG equ 00000010h
  ICCP_FLAG equ 00000020h
  ALL_VALID_FLAGS equ 0000003eh

  WebPMuxAnimDispose typedef SDWORD
  WEBP_MUX_DISPOSE_NONE equ 0
  WEBP_MUX_DISPOSE_BACKGROUND equ 1

  WebPMuxAnimBlend typedef SDWORD
  WEBP_MUX_BLEND equ 0
  WEBP_MUX_NO_BLEND equ 1

  WebPData struct
    bytes POINTER ?
    size_ size_t ?
  WebPData ends
  WebPDataInit proto WEBP_CALL_CONV :ptr WebPData
  WebPDataClear proto WEBP_CALL_CONV :ptr WebPData
  WebPDataCopy proto WEBP_CALL_CONV :ptr WebPData, :ptr WebPData
endif
 