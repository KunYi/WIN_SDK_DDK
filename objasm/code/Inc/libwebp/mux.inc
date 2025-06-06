;Include file created by h2incX, Version C.01.00, 14/10/2022 22:00
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'mux.h', last modified: 26/12/2019 20:24


ifndef WEBP_WEBP_MUX_INC_
  WEBP_WEBP_MUX_INC_ equ <>

  %include &WEBP_INC_PATH&\mux_types.inc
  WEBP_MUX_ABI_VERSION equ 0108h
  WebPMuxError typedef SDWORD
  WEBP_MUX_OK equ 1
  WEBP_MUX_NOT_FOUND equ 0
  WEBP_MUX_INVALID_ARGUMENT equ -1
  WEBP_MUX_BAD_DATA equ -2
  WEBP_MUX_MEMORY_ERROR equ -3
  WEBP_MUX_NOT_ENOUGH_DATA equ -4

  WebPChunkId typedef SDWORD
  WEBP_CHUNK_VP8X equ 0
  WEBP_CHUNK_ICCP equ 1
  WEBP_CHUNK_ANIM equ 2
  WEBP_CHUNK_ANMF equ 3
  WEBP_CHUNK_DEPRECATED equ 4
  WEBP_CHUNK_ALPHA equ 5
  WEBP_CHUNK_IMAGE equ 6
  WEBP_CHUNK_EXIF equ 7
  WEBP_CHUNK_XMP equ 8
  WEBP_CHUNK_UNKNOWN equ 9
  WEBP_CHUNK_NIL equ 10

  WebPGetMuxVersion proto WEBP_CALL_CONV
  WebPNewInternal proto WEBP_CALL_CONV :SDWORD
  WebPMuxNew proto WEBP_CALL_CONV
  WebPMuxDelete proto WEBP_CALL_CONV :ptr WebPMux
  WebPMuxCreateInternal proto WEBP_CALL_CONV :ptr WebPData, :SDWORD, :SDWORD
  WebPMuxCreate proto WEBP_CALL_CONV :ptr WebPData, :SDWORD
  WebPMuxSetChunk proto WEBP_CALL_CONV :ptr WebPMux, :ptr SBYTE, :ptr WebPData, :SDWORD
  WebPMuxGetChunk proto WEBP_CALL_CONV :ptr WebPMux, :ptr SBYTE, :ptr WebPData
  WebPMuxDeleteChunk proto WEBP_CALL_CONV :ptr WebPMux, :ptr SBYTE
  WebPMuxFrameInfo struct
    bitstream WebPData <>
    x_offset SDWORD ?
    y_offset SDWORD ?
    duration SDWORD ?
    id WebPChunkId ?
    dispose_method WebPMuxAnimDispose ?
    blend_method WebPMuxAnimBlend ?
    pad uint32_t 1 dup (?)
  WebPMuxFrameInfo ends
  WebPMuxSetImage proto WEBP_CALL_CONV :ptr WebPMux, :ptr WebPData, :SDWORD
  WebPMuxPushFrame proto WEBP_CALL_CONV :ptr WebPMux, :ptr WebPMuxFrameInfo, :SDWORD
  WebPMuxGetFrame proto WEBP_CALL_CONV :ptr WebPMux, :uint32_t, :ptr WebPMuxFrameInfo
  WebPMuxDeleteFrame proto WEBP_CALL_CONV :ptr WebPMux, :uint32_t
  WebPMuxAnimParams struct
    bgcolor uint32_t ?
    loop_count SDWORD ?
  WebPMuxAnimParams ends
  WebPMuxSetAnimationParams proto WEBP_CALL_CONV :ptr WebPMux, :ptr WebPMuxAnimParams
  WebPMuxGetAnimationParams proto WEBP_CALL_CONV :ptr WebPMux, :ptr WebPMuxAnimParams
  WebPMuxSetCanvasSize proto WEBP_CALL_CONV :ptr WebPMux, :SDWORD, :SDWORD
  WebPMuxGetCanvasSize proto WEBP_CALL_CONV :ptr WebPMux, :ptr SDWORD, :ptr SDWORD
  WebPMuxGetFeatures proto WEBP_CALL_CONV :ptr WebPMux, :ptr uint32_t
  WebPMuxNumChunks proto WEBP_CALL_CONV :ptr WebPMux, :WebPChunkId, :ptr SDWORD
  WebPMuxAssemble proto WEBP_CALL_CONV :ptr WebPMux, :ptr WebPData
  ;WebPAnimEncoder typedef WebPAnimEncoder

  WebPAnimEncoderOptions struct
    anim_params WebPMuxAnimParams <>
    minimize_size SDWORD ?
    kmin SDWORD ?
    kmax SDWORD ?
    allow_mixed SDWORD ?
    verbose SDWORD ?
    padding uint32_t 4 dup (?)
  WebPAnimEncoderOptions ends
  WebPAnimEncoderOptionsInitInternal proto WEBP_CALL_CONV :ptr WebPAnimEncoderOptions, :SDWORD
  WebPAnimEncoderOptionsInit proto WEBP_CALL_CONV :ptr WebPAnimEncoderOptions
  WebPAnimEncoderNewInternal proto WEBP_CALL_CONV :SDWORD, :SDWORD, :ptr WebPAnimEncoderOptions, :SDWORD
  WebPAnimEncoderNew proto WEBP_CALL_CONV :SDWORD, :SDWORD, :ptr WebPAnimEncoderOptions
  WebPAnimEncoderAdd proto WEBP_CALL_CONV :ptr WebPAnimEncoder, :ptr WebPPicture, :SDWORD, :ptr WebPConfig
  WebPAnimEncoderAssemble proto WEBP_CALL_CONV :ptr WebPAnimEncoder, :ptr WebPData
  WebPAnimEncoderGetError proto WEBP_CALL_CONV :ptr WebPAnimEncoder
  WebPAnimEncoderDelete proto WEBP_CALL_CONV :ptr WebPAnimEncoder
endif
 