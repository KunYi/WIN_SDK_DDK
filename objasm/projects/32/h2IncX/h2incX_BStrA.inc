; ==================================================================================================
; Title:    h2incX_BStrA.inc
; Authors:  G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm support of BStrA string handling macros.
; Notes:    See h2incX.asm
; ==================================================================================================


;
;          4 bytes     1 byte per character        1 byte
;      覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;  ... | Byte Lenght | ANSI character array | Zero termination marker | ...
;      覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;                    ^
;                    BStrA points here!



; ==================================================================================================
; (($)C/($)T/($)D/($)J)BStrA: Defines an BSTR string in (C) S_CONST, (T) S_TEXT,  (D) S_DATA or
;                             (J) code segment, returning a reference to it,
;                             if the "$" prefix was used.
; $Ofs(C/T/D/J)BStrA:         Same as ($C/$T/$D/$J)BStr, but returns the symbolic string offset.
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      BStrA / ($)CBStrA / ($)TBStrA / ($)DBStrA / ($)JBStrA
; Purpose:    Place an BSTR string in the S_CONST, S_DATA or S_TEXT segment.
; Arguments:  Arg1: Reference name (optional).
;             Arg2: Quoted string text.
; Returns:    Nothing / Reference to the string.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
; Example:    CBStr MyBStr, 'Note: "', "Director's cut", '"', 13, 10
;             Resulting BStr:   Note: "Director's cut" + CRLF

BStrA macro StrName, QuotedText:vararg
    ??Count = 0
    for ??SubText, <QuotedText>
      ??NumFlag textequ <0>
      ??QuotationMark SubStr <??SubText>, 1, 1
%     ifdif <??QuotationMark>, <">
%       ifdif <??QuotationMark>, <'>
          ??NumFlag textequ <1>
          if ??SubText le 0FFh            ;;Maximum 1 byte
            ??Count = ??Count + 1
          else
            .err <BStrA numeric input out of range>
          endif
        endif
      endif

%     ifidn <??NumFlag>, <0>
%       ifdif <@SizeStr(<??SubText>)>, <02>
          ;;Strip quotation marks and loop
%         forc ??Char, <@SubStr(<??SubText>, 2, @SizeStr(<??SubText>) - 2)>
            ??Count = ??Count + 1
          endm
        else
          .err <Wrong BStr definition>
        endif
      endif
    endm

%   dd ??Count + 1       ;;Set byte count incl. ZTC before the ANSI string is placed

    if ??Count eq 0
      StrName db 0
    else
      ??SrcLine textequ @CatStr(StrName, < db >)
      for ??SubText, <QuotedText>
        ??NumFlag textequ <0>
        ??QuotationMark SubStr <??SubText>, 1, 1
%       ifdif <??QuotationMark>, <">
%         ifdif <??QuotationMark>, <'>
            ??NumFlag textequ <1>
            ??Sentence textequ @CatStr(%??SrcLine, <??SubText>, <,>)
            ??SrcLine textequ ??Sentence
          endif
        endif

%       ifidn <??NumFlag>, <0>
%         ifdif <@SizeStr(<??SubText>)>, <02>
            ;;Strip quotation marks and loop
%           forc ??Char, <@SubStr(<??SubText>, 2, @SizeStr(<??SubText>) - 2)>
              if @SizeStr(%??SrcLine) gt 95
                ;;Output ??Sentence
%               ??Sentence
                ;;Initiate new ??SubText
                ??SrcLine textequ <db >
                ??Sentence textequ <>
              endif
              ??QChar CatStr ??QuotationMark, <??Char>, ??QuotationMark
              ??Sentence textequ @CatStr(%??SrcLine, <??QChar>, <,>)
              ??SrcLine textequ ??Sentence
            endm
          endif
        endif

        ;;Output ??Sentence
%       ??Sentence
        ;;Initiate new ??SubText
        ??SrcLine textequ <db >
      endm
      ;;Set zero termination mark
      db 0
    endif
endm

CBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    S_CONST Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    S_CONST ends
endm

TBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    S_TEXT Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    S_TEXT ends
endm

DBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    S_DATA Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    S_DATA ends
endm

JBStrA macro TextReference, QuotedText:vararg
    local Lbl

    jmp Lbl
    align 4
    BStrA <TextReference>, <QuotedText>
    Lbl:
endm

$CBStrA macro QuotedText:vararg
    local ??StrLocation
    S_CONST Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_CONST ends
    exitm <??StrLocation + 4>
endm

$TBStrA macro QuotedText:vararg
    local ??StrLocation
    S_TEXT Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_TEXT ends
    exitm <??StrLocation + 4>
endm

$DBStrA macro QuotedText:vararg
    local ??StrLocation
    S_DATA Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_DATA ends
    exitm <??StrLocation + 4>
endm

$JBStr macro QuotedText:vararg
    local ??StrLocation
    local Lbl

    jmp Lbl
    align 4
    ??StrLocation = $
    BStrA <>, <QuotedText>
    Lbl:
    exitm <??StrLocation + 4>
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      $Ofs(C/T/D/J)BStrA
; Purpose:    Place an BSTR string in the S_CONST, S_TEXT, S_DATA segment.
; Arguments:  Arg1: Quoted string text.
; Returns:    String offset.

$OfsCBStrA macro QuotedText:vararg
    local ??StrLocation
    S_CONST Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_CONST ends
    exitm <offset ??StrLocation + 4>
endm

$OfsTBStrA macro QuotedText:vararg
    local ??StrLocation
    S_TEXT Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_TEXT ends
    exitm <offset ??StrLocation + 4>
endm

$OfsDBStrA macro QuotedText:vararg
    local ??StrLocation
    S_DATA Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    S_DATA ends
    exitm <offset ??StrLocation + 4>
endm

$OfsJBStrA macro QuotedText:vararg
    local ??StrLocation
    local Lbl

    .code
    jmp Lbl
    align 4
    ??StrLocation = $
    BStrA <>, <QuotedText>
    Lbl:
    exitm <offset ??StrLocation + 4>
endm
