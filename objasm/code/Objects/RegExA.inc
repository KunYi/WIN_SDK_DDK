; ==================================================================================================
; Title:      RegExA.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of RegExA objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     RegExA
; Purpose:    This object is a small wrapper around a Perl Compatible Regular Expression (PCRE).
; Note:       Exec returns an array of PCRE_OUTDATA structures. The first contains the global
;             match, while the rest contain the submatches.  

Object RegExA, RegExAID, Streamable
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER, PSTRINGA, DWORD      ;-> Owner, -> RegEx, Options
  VirtualMethod     Exec,         POINTER, DWORD, DWORD, DWORD  ;-> Subject, Char count, start, opts
  VirtualMethod     GetConfig,    DWORD, POINTER                ;What, -> Where
  VirtualMethod     GetInfo,      POINTER, DWORD, POINTER       ;-> ExtraData, What, -> Where
  VirtualMethod     SetOutCount,  DWORD                         ;Count
  VirtualMethod     Study,        DWORD                         ;Options
  RedefineMethod    Load,         $ObjPtr(Stream)               ;-> Stream
  RedefineMethod    Store,        $ObjPtr(Stream)               ;-> Stream

  DefineVariable    dPatternSize, DWORD,        0       ;Size of the compiled re in bytes
  DefineVariable    pPattern,     POINTER,      NULL    ;Compiled regular expression
  DefineVariable    dMatchCount,  DWORD,        0       ;# of matches stored in the output vector
  DefineVariable    dOutVecSize,  DWORD,        0       ;# of indices that fit in the Output vector
  DefineVariable    pOutVector,   POINTER,      NULL    ;-> array of PCRE_OUTDATA structures (*)
  DefineVariable    dExtraSize,   DWORD,        0       ;Size of the extra data mem block in bytes
  DefineVariable    pExtra,       POINTER,      NULL    ;-> pcre_extra returned from a pcre_study
  DefineVariable    ObjLock,      OBJECT_LOCK,  {}
ObjectEnd

; (*) The number of indices must be 3 times the value returnrd by
; pcre_fullinfo(PCRE_INFO_CAPTURECOUNT)


; ==================================================================================================

if IMPLEMENT

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Done (Destructor)
; Purpose:    Finalize the RegExA object and frees allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method RegExA.Done, uses xsi
  SetObject xsi
  .if [xsi].pPattern != NULL
    invoke pcre_free, [xsi].pPattern
    m2z [xsi].pPattern
    m2z [xsi].dPatternSize
  .endif
  .if [xsi].pOutVector != NULL
    invoke pcre_free, [xsi].pOutVector
    m2z [xsi].pOutVector
    m2z [xsi].dOutVecSize
  .endif
  .if [xsi].pExtra != NULL
    invoke pcre_free, [xsi].pExtra
    m2z [xsi].pExtra
    m2z [xsi].dExtraSize
  .endif
  ACall xsi.Done
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Exec
; Purpose:    Perform a search for a pattern match on the subject string.
; Arguments:  Arg1: -> Subject string.
;             Arg2: Character count.
;             Arg3: Start offset in CHR.
;             Arg4: Options [PCRE_ANCHORED..PCRE_PARTIAL_HARD]
; Return:     eax < 0: Error code.
;             eax >= 0: Number of matches, otherwise error code.

Method RegExA.Exec, uses xsi, pSubject:POINTER, dLength:DWORD, dStartOffset:DWORD, dOptions:DWORD
  SetObject xsi
  invoke pcre_exec, [xsi].pPattern, [xsi].pExtra, pSubject, dLength, dStartOffset, \
                    dOptions, [xsi].pOutVector, [xsi].dOutVecSize
  mov [xsi].dMatchCount, eax
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:   	RegExA.GetConfig
; Purpose:  	Return info about what features are configured.
; Arguments:	Arg1: What information is required.
;           	Arg2: -> where to put the information.
; Return:   	eax = 0 if data returned, negative on error.

Method RegExA.GetConfig,, dWhat:DWORD, pWhere:POINTER
  invoke pcre_config, dWhat, pWhere
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.GetInfo
; Purpose:    Returns info about the compiled pattern.
; Arguments:  Arg1: -> Extra data or NULL.
;             Arg2: What information is required.
;             Arg3: -> where to put the information.
; Return:     eax = 0 if data returned, negative on error.

Method RegExA.GetInfo,, pExtraData:POINTER, dWhat:DWORD, pWhere:POINTER
  SetObject xcx
  invoke pcre_fullinfo, [xcx].pPattern, pExtraData, dWhat, pWhere
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Init (Constructor)
; Purpose:    Initialize the object calculating the pattern resulting from the input regular
;             expression.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Regular expression (ANSI String).
;             Arg3: Option bits (PCRE_CASELESS..PCRE_NO_START_OPTIMISE)
; Return:     eax: Error code.

Method RegExA.Init, uses xsi, pOwner:POINTER, pRegEx:PSTRINGA, dOptions:DWORD
  local dError:DWORD, pErrStr:POINTER, xRet:XWORD

  SetObject xsi
  ACall xsi.Init, pOwner
  invoke pcre_compile, pRegEx, dOptions, addr pErrStr, addr dError, NULL
  .if xax != NULL
    mov [xsi].pPattern, xax                             ;Store compiled pattern
    invoke pcre_fullinfo, [xsi].pPattern, NULL, PCRE_INFO_SIZE , addr xRet
    mov xax, xRet
    mov [xsi].dPatternSize, eax
    xor eax, eax                                        ;OBJ_OK
  .else
    DbgDec dError
    DbgStr pErrStr
    OCall xsi.ErrorReport, NULL, REX_INIT_FAILED
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Load
; Purpose:    Load the array object's data from a stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method RegExA.Load, uses xbx xsi, pStream:$ObjPtr(Stream)
  SetObject xsi

  ;Free all commited memory
  .if [xsi].pPattern != NULL
    invoke pcre_free, [xsi].pPattern
    m2z [xsi].pPattern
    m2z [xsi].dPatternSize
    m2z [xsi].dMatchCount
  .endif
  .if [xsi].pOutVector != NULL
    invoke pcre_free, [xsi].pOutVector
    m2z [xsi].pOutVector
    m2z [xsi].dOutVecSize
  .endif
  .if [xsi].pExtra != NULL
    invoke pcre_free, [xsi].pExtra
    m2z [xsi].pExtra
    m2z [xsi].dExtraSize
  .endif

  ;Read data
  mov [xsi].dErrorCode, $32($OCall(pStream::Stream.BinRead32))

  mov [xsi].dPatternSize, $32($OCall(pStream::Stream.BinRead32))
  .if eax != 0
    mov [xsi].pPattern, $invoke(pcre_malloc, eax)
    OCall pStream::Stream.BinRead, xax, [xsi].dPatternSize
  .endif

  mov [xsi].dMatchCount, $32($OCall(pStream::Stream.BinRead32))

  mov [xsi].dOutVecSize, $32($OCall(pStream::Stream.BinRead32))
  .if eax != 0
    shl eax, $Log2(sizeof(DWORD))
    mov ebx, eax
    mov [xsi].pOutVector, $invoke(pcre_malloc, eax)
    OCall pStream::Stream.BinRead, xax, ebx
  .endif

  mov [xsi].dExtraSize, $32($OCall(pStream::Stream.BinRead32))
  .if eax != 0
    mov [xsi].pExtra, $invoke(pcre_malloc, eax)
    OCall pStream::Stream.BinRead, xax, [xsi].dExtraSize
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.SetOutCount
; Purpose:    Set the number of expected output structures in OutVector and allocates the necessary
;             memory to hold them.
; Arguments:  Arg1: Number of indices that should fit into the output vector. -1 mean an automatic
;                   detection based on the compiled regular expression.
; Return:     eax = Error code.

Method RegExA.SetOutCount, uses xsi, dIndexCount:DWORD
  local xRet:XWORD

  SetObject xsi

  mov eax, dIndexCount
  .if eax == 0
    .if [xsi].pOutVector != NULL
      invoke pcre_free, [xsi].pOutVector
      m2z [xsi].pOutVector
      m2z [xsi].dOutVecSize
      m2z [xsi].dMatchCount
    .endif
    xor eax, eax                                        ;OBJ_OK
    ExitMethod
  .elseif eax == -1
    invoke pcre_fullinfo, [xsi].pPattern, NULL, PCRE_INFO_CAPTURECOUNT, addr xRet
    mov xax, xRet
    inc eax                                             ;Add one for the full match info
  .endif
  lea eax, [2*eax + eax]                                ;x2 (indices) + 1 (workspace)

  .if eax != [xsi].dOutVecSize
    mov [xsi].dOutVecSize, eax
    m2z [xsi].dMatchCount
    .if [xsi].pOutVector != NULL
      invoke pcre_free, [xsi].pOutVector
    .endif
    mov eax, [xsi].dOutVecSize
    shl eax, $Log2(sizeof(DWORD))                       ;4 bytes per index
    invoke pcre_malloc, eax
    mov [xsi].pOutVector, xax
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, REX_OUT_OF_MEMORY
    .else
      xor eax, eax                                      ;OBJ_OK
    .endif
  .else
    xor eax, eax                                        ;OBJ_OK
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Store
; Purpose:    Store the array object's data to a stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method RegExA.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.BinWrite32, [xsi].dErrorCode

  OCall pStream::Stream.BinWrite32, [xsi].dPatternSize
  OCall pStream::Stream.BinWrite, [xsi].pPattern, [xsi].dPatternSize

  OCall pStream::Stream.BinWrite32, [xsi].dMatchCount
  OCall pStream::Stream.BinWrite32, [xsi].dOutVecSize
  mov eax, [xsi].dOutVecSize
  shl eax, $Log2(Sizeof(DWORD))
  OCall pStream::Stream.BinWrite, [xsi].pOutVector, eax

  OCall pStream::Stream.BinWrite32, [xsi].dExtraSize
  OCall pStream::Stream.BinWrite, [xsi].pExtra, [xsi].dExtraSize
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RegExA.Study
; Purpose:    Study a compiled pattern.
; Arguments:  Arg1: Option bits.
; Return:     eax -> pcre_extra block, with study_data filled in and the appropriate flags set;
;             NULL on error or if no optimization is possible.

Method RegExA.Study, uses xsi, dOptions:DWORD
  local pError:POINTER, xRet:XWORD

  SetObject xsi
  mov [xsi].pExtra, $invoke(pcre_study, [xsi].pPattern, dOptions, addr pError)
  .if pError != NULL
    invoke pcre_fullinfo, [xsi].pPattern, [xsi].pExtra, PCRE_INFO_STUDYSIZE, addr xRet
    mov xax, xRet
    mov [xsi].dExtraSize, eax
  .else
    xor eax, eax
  .endif
MethodEnd

endif
