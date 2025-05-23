;Include file created by h2incX, Version C.01.00, 22/06/2019 12:42
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\IImgCtx.h', last modified: 22/10/2018 21:38
;Creation parameters: 

ifndef _IImgCtxObjects_H_
  _IImgCtxObjects_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    TYPE_PFNIMGCTXCALLBACK typedef proto WIN_STD_CALL_CONV :ptr, :ptr
    PFNIMGCTXCALLBACK typedef ptr TYPE_PFNIMGCTXCALLBACK
    ifdef __cplusplus
      ;[...]
    endif
    IMGCHG_SIZE equ 0001h
    IMGCHG_VIEW equ 0002h
    IMGCHG_COMPLETE equ 0004h
    IMGCHG_ANIMATE equ 0008h
    IMGCHG_MASK equ 000Fh
    IMGLOAD_NOTLOADED equ 00100000h
    IMGLOAD_LOADING equ 00200000h
    IMGLOAD_STOPPED equ 00400000h
    IMGLOAD_ERROR equ 00800000h
    IMGLOAD_COMPLETE equ 01000000h
    IMGLOAD_MASK equ 01F00000h
    IMGBITS_NONE equ 02000000h
    IMGBITS_PARTIAL equ 04000000h
    IMGBITS_TOTAL equ 08000000h
    IMGBITS_MASK equ 0E000000h
    IMGANIM_ANIMATED equ 10000000h
    IMGANIM_MASK equ 10000000h
    IMGTRANS_OPAQUE equ 20000000h
    IMGTRANS_MASK equ 20000000h
    DWN_COLORMODE equ 0000003Fh
    DWN_DOWNLOADONLY equ 00000040h
    DWN_FORCEDITHER equ 00000080h
    DWN_RAWIMAGE equ 00000100h
    DWN_MIRRORIMAGE equ 00000200h
    INTERFACE equ <IImgCtx>
    DEFINE_GUID IID_IImgCtx, 3050f3d7h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
    DECLARE_INTERFACE_ IImgCtx, IUnknown
      ifndef NO_BASEINTERFACE_FUNCS
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
      endif
      STD_METHOD Load, :THIS_, :LPCWSTR, :DWORD
      STD_METHOD SelectChanges, :THIS_, :ULONG, :ULONG, :BOOL
      STD_METHOD SetCallback, :THIS_, :PFNIMGCTXCALLBACK, :ptr
      STD_METHOD Disconnect, :THIS_
      STD_METHOD GetUpdateRects, :THIS_, :ptr tagRECT, :ptr tagRECT, :ptr SDWORD
      STD_METHOD GetStateInfo, :THIS_, :ptr, :ptr tagSIZE, :BOOL
      STD_METHOD GetPalette, :THIS_
      STD_METHOD Draw, :THIS_, :HDC, :ptr tagRECT
      STD_METHOD Tile, :THIS_, :HDC, :ptr tagPOINT, :ptr tagRECT, :ptr tagSIZE
      STD_METHOD StretchBlt, :THIS_, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD
    END_DECLARE_INTERFACE_
    ifdef COBJMACROS
      ;[...]
    endif
    DEFINE_GUID CLSID_IImgCtx, 3050f3d6h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  endif
endif
 