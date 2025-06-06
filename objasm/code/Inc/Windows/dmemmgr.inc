;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\dmemmgr.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef __DMEMMGR_INCLUDED__
  __DMEMMGR_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    ifndef __NTDDKCOMP__
      FLATPTR typedef ULONG_PTR
      LPVIDMEM typedef ptr _VIDMEM
      
    else
      FLATPTR typedef ULONG_PTR
      LPVIDMEM typedef ptr _VIDEOMEMORY
      
    endif
    SURFACEALIGNMENT struct
      union
        struct Linear
          dwStartAlignment DWORD ?
          dwPitchAlignment DWORD ?
          dwFlags DWORD ?
          dwReserved2 DWORD ?
        ends
        struct Rectangular
          dwXAlignment DWORD ?
          dwYAlignment DWORD ?
          dwFlags DWORD ?
          dwReserved2 DWORD ?
        ends
      ends
    SURFACEALIGNMENT ends

    _SURFACEALIGNMENT typedef SURFACEALIGNMENT
    LPSURFACEALIGNMENT typedef ptr _SURFACEALIGNMENT
    
    SURFACEALIGN_DISCARDABLE equ 00000001h
    HEAPALIGNMENT struct
      dwSize DWORD ?
      ddsCaps DDSCAPS <>
      dwReserved DWORD ?
      ExecuteBuffer SURFACEALIGNMENT <>
      Overlay SURFACEALIGNMENT <>
      Texture SURFACEALIGNMENT <>
      ZBuffer SURFACEALIGNMENT <>
      AlphaBuffer SURFACEALIGNMENT <>
      Offscreen SURFACEALIGNMENT <>
      FlipTarget SURFACEALIGNMENT <>
    HEAPALIGNMENT ends

    _HEAPALIGNMENT typedef HEAPALIGNMENT
    LPHEAPALIGNMENT typedef ptr _HEAPALIGNMENT
    
    DD_GETHEAPALIGNMENTDATA struct
      dwInstance ULONG_PTR ?
      dwHeap DWORD ?
      ddRVal HRESULT ?
      GetHeapAlignment POINTER ?
      Alignment HEAPALIGNMENT <>
    DD_GETHEAPALIGNMENTDATA ends

    _DD_GETHEAPALIGNMENTDATA typedef DD_GETHEAPALIGNMENTDATA
    PDD_GETHEAPALIGNMENTDATA typedef ptr _DD_GETHEAPALIGNMENTDATA
    
    VMEML struct
      next POINTER ?
      ptr_ FLATPTR ?
      size_ DWORD ?
      bDiscardable BOOL ?
    VMEML ends

    _VMEML typedef VMEML
    LPVMEML typedef ptr VMEML
    LPLPVMEML typedef ptr ptr VMEML
    
    VMEMR struct
      next POINTER ?
      prev POINTER ?
      pUp POINTER ?
      pDown POINTER ?
      pLeft POINTER ?
      pRight POINTER ?
      ptr_ FLATPTR ?
      size_ DWORD ?
      x DWORD ?
      y DWORD ?
      cx_ DWORD ?
      cy DWORD ?
      flags DWORD ?
      pBits FLATPTR ?
      bDiscardable BOOL ?
    VMEMR ends

    _VMEMR typedef VMEMR
    LPVMEMR typedef ptr VMEMR
    LPLPVMEMR typedef ptr ptr VMEMR
    
    VMEMHEAP struct
      dwFlags DWORD ?
      stride DWORD ?
      freeList LPVOID ?
      allocList LPVOID ?
      dwTotalSize DWORD ?
      fpGARTLin FLATPTR ?
      fpGARTDev FLATPTR ?
      dwCommitedSize DWORD ?
      dwCoalesceCount DWORD ?
      Alignment HEAPALIGNMENT <>
      ddsCapsEx DDSCAPSEX <>
      ddsCapsExAlt DDSCAPSEX <>
      ifndef IS_16
        liPhysAGPBase LARGE_INTEGER <>
      endif
      hdevAGP HANDLE ?
      pvPhysRsrv LPVOID ?
      if (NTDDI_VERSION ge NTDDI_WINXP)
        pAgpCommitMask POINTER ?
        dwAgpCommitMaskSize DWORD ?
      endif
    VMEMHEAP ends

    _VMEMHEAP typedef VMEMHEAP
    LPVMEMHEAP typedef ptr VMEMHEAP
    VMEMHEAP_LINEAR equ 00000001h
    VMEMHEAP_RECTANGULAR equ 00000002h
    VMEMHEAP_ALIGNMENT equ 00000004h
    ifndef __NTDDKCOMP__
      VidMemAlloc proto WIN_STD_CALL_CONV :LPVMEMHEAP, :DWORD, :DWORD
    endif
    HeapVidMemAllocAligned proto WIN_STD_CALL_CONV :LPVIDMEM, :DWORD, :DWORD, :LPSURFACEALIGNMENT, :LPLONG
    VidMemFree proto WIN_STD_CALL_CONV :LPVMEMHEAP, :FLATPTR
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif

