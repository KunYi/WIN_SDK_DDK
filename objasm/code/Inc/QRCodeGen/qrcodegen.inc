;Include file created by h2incX, Version C.01.00, 21/11/2022 20:08
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'qrcodegen.h', last modified: 21/11/2022 13:43
;
;https://github.com/nayuki/QR-Code-generator
;
;QR Code generator library (C)
;
;Copyright (c) Project Nayuki. (MIT License)
;https://www.nayuki.io/page/qr-code-generator-library
;
;Permission is hereby granted, free of charge, to any person obtaining a copy of
;this software and associated documentation files (the "Software"), to deal in
;the Software without restriction, including without limitation the rights to
;use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
;the Software, and to permit persons to whom the Software is furnished to do so,
;subject to the following conditions:
;- The above copyright notice and this permission notice shall be included in
;  all copies or substantial portions of the Software.
;- The Software is provided "as is", without warranty of any kind, express or
;  implied, including but not limited to the warranties of merchantability,
;  fitness for a particular purpose and noninfringement. In no event shall the
;  authors or copyright holders be liable for any claim, damages or other
;  liability, whether in an action of contract, tort or otherwise, arising from,
;  out of or in connection with the Software or the use or other dealings in the
;  Software.


qrcodegen_Ecc typedef SDWORD
qrcodegen_Ecc_LOW equ 0
qrcodegen_Ecc_MEDIUM equ 1
qrcodegen_Ecc_QUARTILE equ 2
qrcodegen_Ecc_HIGH equ 3

qrcodegen_Mask typedef SDWORD
qrcodegen_Mask_AUTO equ -1
qrcodegen_Mask_0 equ 0
qrcodegen_Mask_1 equ 1
qrcodegen_Mask_2 equ 2
qrcodegen_Mask_3 equ 3
qrcodegen_Mask_4 equ 4
qrcodegen_Mask_5 equ 5
qrcodegen_Mask_6 equ 6
qrcodegen_Mask_7 equ 7

qrcodegen_Mode typedef SDWORD
qrcodegen_Mode_NUMERIC equ 1h
qrcodegen_Mode_ALPHANUMERIC equ 2h
qrcodegen_Mode_BYTE equ 4h
qrcodegen_Mode_KANJI equ 8h
qrcodegen_Mode_ECI equ 7h

qrcodegen_Segment struct
  mode qrcodegen_Mode ?
  numChars SDWORD ?
  data POINTER ?
  bitLength SDWORD ?
qrcodegen_Segment ends
qrcodegen_VERSION_MIN equ 1
qrcodegen_VERSION_MAX equ 40
qrcodegen_BUFFER_LEN_FOR_VERSION macro n
  exitm <((((n) * 4 + 17) * ((n) * 4 + 17) + 7) / 8 + 1)>
endm
qrcodegen_BUFFER_LEN_MAX equ <qrcodegen_BUFFER_LEN_FOR_VERSION(qrcodegen_VERSION_MAX)>

qrcodegen_encodeText proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr uint8_t, :ptr uint8_t, :qrcodegen_Ecc, :SDWORD, :SDWORD, :qrcodegen_Mask, :BYTE
qrcodegen_encodeBinary proto WIN_STD_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t, :qrcodegen_Ecc, :SDWORD, :SDWORD, :qrcodegen_Mask, :BYTE
qrcodegen_encodeSegments proto WIN_STD_CALL_CONV :ptr qrcodegen_Segment, :size_t, :qrcodegen_Ecc, :ptr uint8_t, :ptr uint8_t
qrcodegen_encodeSegmentsAdvanced proto WIN_STD_CALL_CONV :ptr qrcodegen_Segment, :size_t, :qrcodegen_Ecc, :SDWORD, :SDWORD, :qrcodegen_Mask, :BYTE, :ptr uint8_t, :ptr uint8_t
qrcodegen_isNumeric proto WIN_STD_CALL_CONV :ptr SBYTE
qrcodegen_isAlphanumeric proto WIN_STD_CALL_CONV :ptr SBYTE
qrcodegen_calcSegmentBufferSize proto WIN_STD_CALL_CONV :qrcodegen_Mode, :size_t
qrcodegen_makeBytes proto WIN_STD_CALL_CONV :ptr uint8_t, :size_t, :ptr uint8_t
qrcodegen_makeNumeric proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr uint8_t
qrcodegen_makeAlphanumeric proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr uint8_t
qrcodegen_makeEci proto WIN_STD_CALL_CONV :SDWORD, :ptr uint8_t
qrcodegen_getSize proto WIN_STD_CALL_CONV :ptr uint8_t
qrcodegen_getModule proto WIN_STD_CALL_CONV :ptr uint8_t, :SDWORD, :SDWORD
 