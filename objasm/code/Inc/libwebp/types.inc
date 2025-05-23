;Include file created by h2incX, Version C.01.00, 14/10/2022 22:00
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'types.h', last modified: 26/12/2019 20:24


ifndef WEBP_WEBP_TYPES_INC_
  WEBP_WEBP_TYPES_INC_ equ <>

  int8_t typedef SBYTE
  uint8_t typedef BYTE
  int16_t typedef SWORD
  uint16_t typedef WORD
  int32_t typedef SDWORD
  uint32_t typedef DWORD
  uint64_t typedef QWORD
  int64_t typedef SQWORD
  ifndef WEBP_EXTERN
    WEBP_EXTERN equ <extern>
  endif
  WEBP_ABI_IS_INCOMPATIBLE macro a, b
    exitm <(((a) shr 8) != ((b) shr 8))>
  endm
  WebPMalloc proto WEBP_CALL_CONV :size_t
  WebPFree proto WEBP_CALL_CONV :ptr
endif
 