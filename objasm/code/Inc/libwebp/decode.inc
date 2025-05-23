;Include file created by h2incX, Version C.01.00, 14/10/2022 22:00
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'decode.h', last modified: 26/12/2019 20:24


ifndef WEBP_WEBP_DECODE_INC_
  WEBP_WEBP_DECODE_INC_ equ <>

  %include &WEBP_INC_PATH&\types.inc
  WEBP_DECODER_ABI_VERSION equ 0209h
  WebPGetDecoderVersion proto WEBP_CALL_CONV
  WebPGetInfo proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeRGBA proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeARGB proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeBGRA proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeRGB proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeBGR proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeYUV proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr SDWORD, :ptr SDWORD, :ptr ptr uint8_t, :ptr ptr uint8_t, :ptr SDWORD, :ptr SDWORD
  WebPDecodeRGBAInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD
  WebPDecodeARGBInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD
  WebPDecodeBGRAInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD
  WebPDecodeRGBInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD
  WebPDecodeBGRInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD
  WebPDecodeYUVInto proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD
  WEBP_CSP_MODE typedef SDWORD
  MODE_RGB equ 0
  MODE_RGBA equ 1
  MODE_BGR equ 2
  MODE_BGRA equ 3
  MODE_ARGB equ 4
  MODE_RGBA_4444 equ 5
  MODE_RGB_565 equ 6
  MODE_rgbA equ 7
  MODE_bgrA equ 8
  MODE_Argb equ 9
  MODE_rgbA_4444 equ 10
  MODE_YUV equ 11
  MODE_YUVA equ 12
  MODE_LAST equ 13

  WebPIsPremultipliedMode proto WEBP_CALL_CONV :WEBP_CSP_MODE
  WebPIsAlphaMode proto WEBP_CALL_CONV :WEBP_CSP_MODE
  WebPIsRGBMode proto WEBP_CALL_CONV :WEBP_CSP_MODE
  WebPRGBABuffer struct
    rgba POINTER ?
    stride SDWORD ?
    size_ size_t ?
  WebPRGBABuffer ends
  WebPYUVABuffer struct
    y POINTER ?
    y_stride SDWORD ?
    u_stride SDWORD ?
    a_stride SDWORD ?
    y_size size_t ?
    u_size size_t ?
    a_size size_t ?
  WebPYUVABuffer ends
  WebPDecBuffer struct
    colorspace WEBP_CSP_MODE ?
    width_ SDWORD ?
    is_external_memory SDWORD ?
    union u
      RGBA WebPRGBABuffer <>
      YUVA WebPYUVABuffer <>
    ends
    pad uint32_t 4 dup (?)
    private_memory POINTER ?
  WebPDecBuffer ends
  WebPInitDecBufferInternal proto WEBP_CALL_CONV :ptr WebPDecBuffer, :SDWORD
  WebPInitDecBuffer proto WEBP_CALL_CONV :ptr WebPDecBuffer
  WebPFreeDecBuffer proto WEBP_CALL_CONV :ptr WebPDecBuffer
  VP8StatusCode typedef SDWORD
  VP8_STATUS_OK equ 0
  VP8_STATUS_OUT_OF_MEMORY equ 1
  VP8_STATUS_INVALID_PARAM equ 2
  VP8_STATUS_BITSTREAM_ERROR equ 3
  VP8_STATUS_UNSUPPORTED_FEATURE equ 4
  VP8_STATUS_SUSPENDED equ 5
  VP8_STATUS_USER_ABORT equ 6
  VP8_STATUS_NOT_ENOUGH_DATA equ 7

  WebPINewDecoder proto WEBP_CALL_CONV :ptr WebPDecBuffer
  WebPINewRGB proto WEBP_CALL_CONV :WEBP_CSP_MODE, :ptr uint8_t, :size_t, :SDWORD
  WebPINewYUVA proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD
  WebPINewYUV proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD, :ptr uint8_t, :size_t, :SDWORD
  WebPIDelete proto WEBP_CALL_CONV :ptr WebPIDecoder
  WebPIAppend proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr uint8_t, :size_t
  WebPIUpdate proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr uint8_t, :size_t
  WebPIDecGetRGB proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD
  WebPIDecGetYUVA proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr SDWORD, :ptr ptr uint8_t, :ptr ptr uint8_t, :ptr ptr uint8_t, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD
  WebPIDecGetYUV proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr SDWORD, :ptr ptr uint8_t, :ptr ptr uint8_t, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD
  WebPIDecodedArea proto WEBP_CALL_CONV :ptr WebPIDecoder, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD
  WebPBitstreamFeatures struct
    width_ SDWORD ?
    height SDWORD ?
    has_alpha SDWORD ?
    has_animation SDWORD ?
    format SDWORD ?
    pad uint32_t 5 dup (?)
  WebPBitstreamFeatures ends
  WebPGetFeaturesInternal proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr WebPBitstreamFeatures, :SDWORD
  WebPGetFeatures proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr WebPBitstreamFeatures
  WebPDecoderOptions struct
    bypass_filtering SDWORD ?
    no_fancy_upsampling SDWORD ?
    use_cropping SDWORD ?
    crop_left SDWORD ?
    crop_width SDWORD ?
    use_scaling SDWORD ?
    scaled_width SDWORD ?
    use_threads SDWORD ?
    dithering_strength SDWORD ?
    flip SDWORD ?
    alpha_dithering_strength SDWORD ?
    pad uint32_t 5 dup (?)
  WebPDecoderOptions ends
  WebPDecoderConfig struct
    input WebPBitstreamFeatures <>
    output WebPDecBuffer <>
    options WebPDecoderOptions <>
  WebPDecoderConfig ends
  WebPInitDecoderConfigInternal proto WEBP_CALL_CONV :ptr WebPDecoderConfig, :SDWORD
  WebPInitDecoderConfig proto WEBP_CALL_CONV :ptr WebPDecoderConfig
  WebPIDecode proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr WebPDecoderConfig
  WebPDecode proto WEBP_CALL_CONV :ptr uint8_t, :size_t, :ptr WebPDecoderConfig
endif
 