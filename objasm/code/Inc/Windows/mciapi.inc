;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\mciapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _MCIAPI_H_
  _MCIAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _MCIERROR_
      _MCIERROR_ equ <>
      MCIERROR typedef DWORD
    endif
    ifndef _MCIDEVICEID_
      _MCIDEVICEID_ equ <>
      MCIDEVICEID typedef UINT
    endif
    TYPE_YIELDPROC typedef proto WIN_STD_CALL_CONV :MCIDEVICEID, :DWORD
    YIELDPROC typedef ptr TYPE_YIELDPROC
    ifdef _WIN32
      @DefProto DllImport, mciSendCommandA, WIN_STD_CALL_CONV,, <:MCIDEVICEID, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
      @DefProto DllImport, mciSendCommandW, WIN_STD_CALL_CONV,, <:MCIDEVICEID, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
      ifdef UNICODE
        mciSendCommand equ <mciSendCommandW>
      else
        mciSendCommand equ <mciSendCommandA>
      endif
      @DefProto DllImport, mciSendStringA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :UINT, :HWND>, 16
      @DefProto DllImport, mciSendStringW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :UINT, :HWND>, 16
      ifdef UNICODE
        mciSendString equ <mciSendStringW>
      else
        mciSendString equ <mciSendStringA>
      endif
      @DefProto DllImport, mciGetDeviceIDA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, mciGetDeviceIDW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        mciGetDeviceID equ <mciGetDeviceIDW>
      else
        mciGetDeviceID equ <mciGetDeviceIDA>
      endif
      @DefProto DllImport, mciGetDeviceIDFromElementIDA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR>, 8
      @DefProto DllImport, mciGetDeviceIDFromElementIDW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR>, 8
      ifdef UNICODE
        mciGetDeviceIDFromElementID equ <mciGetDeviceIDFromElementIDW>
      else
        mciGetDeviceIDFromElementID equ <mciGetDeviceIDFromElementIDA>
      endif
      @DefProto DllImport, mciGetErrorStringA, WIN_STD_CALL_CONV,, <:MCIERROR, :LPSTR, :UINT>, 12
      @DefProto DllImport, mciGetErrorStringW, WIN_STD_CALL_CONV,, <:MCIERROR, :LPWSTR, :UINT>, 12
      ifdef UNICODE
        mciGetErrorString equ <mciGetErrorStringW>
      else
        mciGetErrorString equ <mciGetErrorStringA>
      endif
    else
      ;[...]
    endif
    @DefProto DllImport, mciSetYieldProc, WIN_STD_CALL_CONV,, <:MCIDEVICEID, :YIELDPROC, :DWORD>, 12
    if (WINVER ge 030ah)
      @DefProto DllImport, mciGetCreatorTask, WIN_STD_CALL_CONV,, <:MCIDEVICEID>, 4
      @DefProto DllImport, mciGetYieldProc, WIN_STD_CALL_CONV,, <:MCIDEVICEID, :LPDWORD>, 8
    endif
    if (WINVER lt 030ah)
      @DefProto DllImport, mciExecute, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    endif
    MCIERR_INVALID_DEVICE_ID equ (MCIERR_BASE + 1)
    MCIERR_UNRECOGNIZED_KEYWORD equ (MCIERR_BASE + 3)
    MCIERR_UNRECOGNIZED_COMMAND equ (MCIERR_BASE + 5)
    MCIERR_HARDWARE equ (MCIERR_BASE + 6)
    MCIERR_INVALID_DEVICE_NAME equ (MCIERR_BASE + 7)
    MCIERR_OUT_OF_MEMORY equ (MCIERR_BASE + 8)
    MCIERR_DEVICE_OPEN equ (MCIERR_BASE + 9)
    MCIERR_CANNOT_LOAD_DRIVER equ (MCIERR_BASE + 10)
    MCIERR_MISSING_COMMAND_STRING equ (MCIERR_BASE + 11)
    MCIERR_PARAM_OVERFLOW equ (MCIERR_BASE + 12)
    MCIERR_MISSING_STRING_ARGUMENT equ (MCIERR_BASE + 13)
    MCIERR_BAD_INTEGER equ (MCIERR_BASE + 14)
    MCIERR_PARSER_INTERNAL equ (MCIERR_BASE + 15)
    MCIERR_DRIVER_INTERNAL equ (MCIERR_BASE + 16)
    MCIERR_MISSING_PARAMETER equ (MCIERR_BASE + 17)
    MCIERR_UNSUPPORTED_FUNCTION equ (MCIERR_BASE + 18)
    MCIERR_FILE_NOT_FOUND equ (MCIERR_BASE + 19)
    MCIERR_DEVICE_NOT_READY equ (MCIERR_BASE + 20)
    MCIERR_INTERNAL equ (MCIERR_BASE + 21)
    MCIERR_DRIVER equ (MCIERR_BASE + 22)
    MCIERR_CANNOT_USE_ALL equ (MCIERR_BASE + 23)
    MCIERR_MULTIPLE equ (MCIERR_BASE + 24)
    MCIERR_EXTENSION_NOT_FOUND equ (MCIERR_BASE + 25)
    MCIERR_OUTOFRANGE equ (MCIERR_BASE + 26)
    MCIERR_FLAGS_NOT_COMPATIBLE equ (MCIERR_BASE + 28)
    MCIERR_FILE_NOT_SAVED equ (MCIERR_BASE + 30)
    MCIERR_DEVICE_TYPE_REQUIRED equ (MCIERR_BASE + 31)
    MCIERR_DEVICE_LOCKED equ (MCIERR_BASE + 32)
    MCIERR_DUPLICATE_ALIAS equ (MCIERR_BASE + 33)
    MCIERR_BAD_CONSTANT equ (MCIERR_BASE + 34)
    MCIERR_MUST_USE_SHAREABLE equ (MCIERR_BASE + 35)
    MCIERR_MISSING_DEVICE_NAME equ (MCIERR_BASE + 36)
    MCIERR_BAD_TIME_FORMAT equ (MCIERR_BASE + 37)
    MCIERR_NO_CLOSING_QUOTE equ (MCIERR_BASE + 38)
    MCIERR_DUPLICATE_FLAGS equ (MCIERR_BASE + 39)
    MCIERR_INVALID_FILE equ (MCIERR_BASE + 40)
    MCIERR_NULL_PARAMETER_BLOCK equ (MCIERR_BASE + 41)
    MCIERR_UNNAMED_RESOURCE equ (MCIERR_BASE + 42)
    MCIERR_NEW_REQUIRES_ALIAS equ (MCIERR_BASE + 43)
    MCIERR_NOTIFY_ON_AUTO_OPEN equ (MCIERR_BASE + 44)
    MCIERR_NO_ELEMENT_ALLOWED equ (MCIERR_BASE + 45)
    MCIERR_NONAPPLICABLE_FUNCTION equ (MCIERR_BASE + 46)
    MCIERR_ILLEGAL_FOR_AUTO_OPEN equ (MCIERR_BASE + 47)
    MCIERR_FILENAME_REQUIRED equ (MCIERR_BASE + 48)
    MCIERR_EXTRA_CHARACTERS equ (MCIERR_BASE + 49)
    MCIERR_DEVICE_NOT_INSTALLED equ (MCIERR_BASE + 50)
    MCIERR_GET_CD equ (MCIERR_BASE + 51)
    MCIERR_SET_CD equ (MCIERR_BASE + 52)
    MCIERR_SET_DRIVE equ (MCIERR_BASE + 53)
    MCIERR_DEVICE_LENGTH equ (MCIERR_BASE + 54)
    MCIERR_DEVICE_ORD_LENGTH equ (MCIERR_BASE + 55)
    MCIERR_NO_INTEGER equ (MCIERR_BASE + 56)
    MCIERR_WAVE_OUTPUTSINUSE equ (MCIERR_BASE + 64)
    MCIERR_WAVE_SETOUTPUTINUSE equ (MCIERR_BASE + 65)
    MCIERR_WAVE_INPUTSINUSE equ (MCIERR_BASE + 66)
    MCIERR_WAVE_SETINPUTINUSE equ (MCIERR_BASE + 67)
    MCIERR_WAVE_OUTPUTUNSPECIFIED equ (MCIERR_BASE + 68)
    MCIERR_WAVE_INPUTUNSPECIFIED equ (MCIERR_BASE + 69)
    MCIERR_WAVE_OUTPUTSUNSUITABLE equ (MCIERR_BASE + 70)
    MCIERR_WAVE_SETOUTPUTUNSUITABLE equ (MCIERR_BASE + 71)
    MCIERR_WAVE_INPUTSUNSUITABLE equ (MCIERR_BASE + 72)
    MCIERR_WAVE_SETINPUTUNSUITABLE equ (MCIERR_BASE + 73)
    MCIERR_SEQ_DIV_INCOMPATIBLE equ (MCIERR_BASE + 80)
    MCIERR_SEQ_PORT_INUSE equ (MCIERR_BASE + 81)
    MCIERR_SEQ_PORT_NONEXISTENT equ (MCIERR_BASE + 82)
    MCIERR_SEQ_PORT_MAPNODEVICE equ (MCIERR_BASE + 83)
    MCIERR_SEQ_PORT_MISCERROR equ (MCIERR_BASE + 84)
    MCIERR_SEQ_TIMER equ (MCIERR_BASE + 85)
    MCIERR_SEQ_PORTUNSPECIFIED equ (MCIERR_BASE + 86)
    MCIERR_SEQ_NOMIDIPRESENT equ (MCIERR_BASE + 87)
    MCIERR_NO_WINDOW equ (MCIERR_BASE + 90)
    MCIERR_CREATEWINDOW equ (MCIERR_BASE + 91)
    MCIERR_FILE_READ equ (MCIERR_BASE + 92)
    MCIERR_FILE_WRITE equ (MCIERR_BASE + 93)
    MCIERR_NO_IDENTITY equ (MCIERR_BASE + 94)
    MCIERR_CUSTOM_DRIVER_BASE equ (MCIERR_BASE + 256)
    MCI_FIRST equ <DRV_MCI_FIRST>
    MCI_OPEN equ 0803h
    MCI_CLOSE equ 0804h
    MCI_ESCAPE equ 0805h
    MCI_PLAY equ 0806h
    MCI_SEEK equ 0807h
    MCI_STOP equ 0808h
    MCI_PAUSE equ 0809h
    MCI_INFO equ 080Ah
    MCI_GETDEVCAPS equ 080Bh
    MCI_SPIN equ 080Ch
    MCI_SET equ 080Dh
    MCI_STEP equ 080Eh
    MCI_RECORD equ 080Fh
    MCI_SYSINFO equ 0810h
    MCI_BREAK equ 0811h
    MCI_SAVE equ 0813h
    MCI_STATUS equ 0814h
    MCI_CUE equ 0830h
    MCI_REALIZE equ 0840h
    MCI_WINDOW equ 0841h
    MCI_PUT equ 0842h
    MCI_WHERE equ 0843h
    MCI_FREEZE equ 0844h
    MCI_UNFREEZE equ 0845h
    MCI_LOAD equ 0850h
    MCI_CUT equ 0851h
    MCI_COPY equ 0852h
    MCI_PASTE equ 0853h
    MCI_UPDATE equ 0854h
    MCI_RESUME equ 0855h
    MCI_DELETE equ 0856h
    MCI_USER_MESSAGES equ (DRV_MCI_FIRST + 400h)
    MCI_LAST equ 0FFFh
    MCI_ALL_DEVICE_ID equ ((MCIDEVICEID) - 1)
    MCI_DEVTYPE_VCR equ 513
    MCI_DEVTYPE_VIDEODISC equ 514
    MCI_DEVTYPE_OVERLAY equ 515
    MCI_DEVTYPE_CD_AUDIO equ 516
    MCI_DEVTYPE_DAT equ 517
    MCI_DEVTYPE_SCANNER equ 518
    MCI_DEVTYPE_ANIMATION equ 519
    MCI_DEVTYPE_DIGITAL_VIDEO equ 520
    MCI_DEVTYPE_OTHER equ 521
    MCI_DEVTYPE_WAVEFORM_AUDIO equ 522
    MCI_DEVTYPE_SEQUENCER equ 523
    MCI_DEVTYPE_FIRST equ <MCI_DEVTYPE_VCR>
    MCI_DEVTYPE_LAST equ <MCI_DEVTYPE_SEQUENCER>
    MCI_DEVTYPE_FIRST_USER equ 1000h
    MCI_MODE_NOT_READY equ (MCI_STRING_OFFSET + 12)
    MCI_MODE_STOP equ (MCI_STRING_OFFSET + 13)
    MCI_MODE_PLAY equ (MCI_STRING_OFFSET + 14)
    MCI_MODE_RECORD equ (MCI_STRING_OFFSET + 15)
    MCI_MODE_SEEK equ (MCI_STRING_OFFSET + 16)
    MCI_MODE_PAUSE equ (MCI_STRING_OFFSET + 17)
    MCI_MODE_OPEN equ (MCI_STRING_OFFSET + 18)
    MCI_FORMAT_MILLISECONDS equ 0
    MCI_FORMAT_HMS equ 1
    MCI_FORMAT_MSF equ 2
    MCI_FORMAT_FRAMES equ 3
    MCI_FORMAT_SMPTE_24 equ 4
    MCI_FORMAT_SMPTE_25 equ 5
    MCI_FORMAT_SMPTE_30 equ 6
    MCI_FORMAT_SMPTE_30DROP equ 7
    MCI_FORMAT_BYTES equ 8
    MCI_FORMAT_SAMPLES equ 9
    MCI_FORMAT_TMSF equ 10
    MCI_MSF_MINUTE macro msf
      exitm <((msf))>
    endm
    MCI_MSF_SECOND macro msf
      exitm <((((msf)) shr 8))>
    endm
    MCI_MSF_FRAME macro msf
      exitm <(((msf) shr 16))>
    endm
    MCI_MAKE_MSF macro m, s, f
      exitm <((((m) or ((s) shl 8)) or (((f)) shl 16)))>
    endm
    MCI_TMSF_TRACK macro tmsf
      exitm <((tmsf))>
    endm
    MCI_TMSF_MINUTE macro tmsf
      exitm <((((tmsf)) shr 8))>
    endm
    MCI_TMSF_SECOND macro tmsf
      exitm <(((tmsf) shr 16))>
    endm
    MCI_TMSF_FRAME macro tmsf
      exitm <(((tmsf) shr 24))>
    endm
    MCI_MAKE_TMSF macro t, m, s, f
      exitm <((((t) or ((m) shl 8)) or (((s) or ((f) shl 8)) shl 16)))>
    endm
    MCI_HMS_HOUR macro hms
      exitm <((hms))>
    endm
    MCI_HMS_MINUTE macro hms
      exitm <((((hms)) shr 8))>
    endm
    MCI_HMS_SECOND macro hms
      exitm <(((hms) shr 16))>
    endm
    MCI_MAKE_HMS macro h, m, s
      exitm <((((h) or ((m) shl 8)) or (((s)) shl 16)))>
    endm
    MCI_NOTIFY_SUCCESSFUL equ 0001h
    MCI_NOTIFY_SUPERSEDED equ 0002h
    MCI_NOTIFY_ABORTED equ 0004h
    MCI_NOTIFY_FAILURE equ 0008h
    MCI_NOTIFY equ 00000001h
    MCI_WAIT equ 00000002h
    MCI_FROM equ 00000004h
    MCI_TO equ 00000008h
    MCI_TRACK equ 00000010h
    MCI_OPEN_SHAREABLE equ 00000100h
    MCI_OPEN_ELEMENT equ 00000200h
    MCI_OPEN_ALIAS equ 00000400h
    MCI_OPEN_ELEMENT_ID equ 00000800h
    MCI_OPEN_TYPE_ID equ 00001000h
    MCI_OPEN_TYPE equ 00002000h
    MCI_SEEK_TO_START equ 00000100h
    MCI_SEEK_TO_END equ 00000200h
    MCI_STATUS_ITEM equ 00000100h
    MCI_STATUS_START equ 00000200h
    MCI_STATUS_LENGTH equ 00000001h
    MCI_STATUS_POSITION equ 00000002h
    MCI_STATUS_NUMBER_OF_TRACKS equ 00000003h
    MCI_STATUS_MODE equ 00000004h
    MCI_STATUS_MEDIA_PRESENT equ 00000005h
    MCI_STATUS_TIME_FORMAT equ 00000006h
    MCI_STATUS_READY equ 00000007h
    MCI_STATUS_CURRENT_TRACK equ 00000008h
    MCI_INFO_PRODUCT equ 00000100h
    MCI_INFO_FILE equ 00000200h
    MCI_INFO_MEDIA_UPC equ 00000400h
    MCI_INFO_MEDIA_IDENTITY equ 00000800h
    MCI_INFO_NAME equ 00001000h
    MCI_INFO_COPYRIGHT equ 00002000h
    MCI_GETDEVCAPS_ITEM equ 00000100h
    MCI_GETDEVCAPS_CAN_RECORD equ 00000001h
    MCI_GETDEVCAPS_HAS_AUDIO equ 00000002h
    MCI_GETDEVCAPS_HAS_VIDEO equ 00000003h
    MCI_GETDEVCAPS_DEVICE_TYPE equ 00000004h
    MCI_GETDEVCAPS_USES_FILES equ 00000005h
    MCI_GETDEVCAPS_COMPOUND_DEVICE equ 00000006h
    MCI_GETDEVCAPS_CAN_EJECT equ 00000007h
    MCI_GETDEVCAPS_CAN_PLAY equ 00000008h
    MCI_GETDEVCAPS_CAN_SAVE equ 00000009h
    MCI_SYSINFO_QUANTITY equ 00000100h
    MCI_SYSINFO_OPEN equ 00000200h
    MCI_SYSINFO_NAME equ 00000400h
    MCI_SYSINFO_INSTALLNAME equ 00000800h
    MCI_SET_DOOR_OPEN equ 00000100h
    MCI_SET_DOOR_CLOSED equ 00000200h
    MCI_SET_TIME_FORMAT equ 00000400h
    MCI_SET_AUDIO equ 00000800h
    MCI_SET_VIDEO equ 00001000h
    MCI_SET_ON equ 00002000h
    MCI_SET_OFF equ 00004000h
    MCI_SET_AUDIO_ALL equ 00000000h
    MCI_SET_AUDIO_LEFT equ 00000001h
    MCI_SET_AUDIO_RIGHT equ 00000002h
    MCI_BREAK_KEY equ 00000100h
    MCI_BREAK_HWND equ 00000200h
    MCI_BREAK_OFF equ 00000400h
    MCI_RECORD_INSERT equ 00000100h
    MCI_RECORD_OVERWRITE equ 00000200h
    MCI_SAVE_FILE equ 00000100h
    MCI_LOAD_FILE equ 00000100h
    MCI_GENERIC_PARMS struct
      dwCallback DWORD_PTR ?
    MCI_GENERIC_PARMS ends

    tagMCI_GENERIC_PARMS typedef MCI_GENERIC_PARMS
    PMCI_GENERIC_PARMS typedef ptr MCI_GENERIC_PARMS
    LPMCI_GENERIC_PARMS typedef ptr MCI_GENERIC_PARMS
    
    ifdef _WIN32
      MCI_OPEN_PARMSA struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCSTR ?
        lpstrElementName LPCSTR ?
        lpstrAlias LPCSTR ?
      MCI_OPEN_PARMSA ends

      tagMCI_OPEN_PARMSA typedef MCI_OPEN_PARMSA
      PMCI_OPEN_PARMSA typedef ptr MCI_OPEN_PARMSA
      LPMCI_OPEN_PARMSA typedef ptr MCI_OPEN_PARMSA
      
      MCI_OPEN_PARMSW struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCWSTR ?
        lpstrElementName LPCWSTR ?
        lpstrAlias LPCWSTR ?
      MCI_OPEN_PARMSW ends

      tagMCI_OPEN_PARMSW typedef MCI_OPEN_PARMSW
      PMCI_OPEN_PARMSW typedef ptr MCI_OPEN_PARMSW
      LPMCI_OPEN_PARMSW typedef ptr MCI_OPEN_PARMSW
      
      ifdef UNICODE
        MCI_OPEN_PARMS typedef MCI_OPEN_PARMSW
        PMCI_OPEN_PARMS typedef PMCI_OPEN_PARMSW
        LPMCI_OPEN_PARMS typedef LPMCI_OPEN_PARMSW
      else
        MCI_OPEN_PARMS typedef MCI_OPEN_PARMSA
        PMCI_OPEN_PARMS typedef PMCI_OPEN_PARMSA
        LPMCI_OPEN_PARMS typedef LPMCI_OPEN_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_PLAY_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrom DWORD ?
      dwTo DWORD ?
    MCI_PLAY_PARMS ends

    tagMCI_PLAY_PARMS typedef MCI_PLAY_PARMS
    PMCI_PLAY_PARMS typedef ptr MCI_PLAY_PARMS
    LPMCI_PLAY_PARMS typedef ptr MCI_PLAY_PARMS
    
    MCI_SEEK_PARMS struct
      dwCallback DWORD_PTR ?
      dwTo DWORD ?
    MCI_SEEK_PARMS ends

    tagMCI_SEEK_PARMS typedef MCI_SEEK_PARMS
    PMCI_SEEK_PARMS typedef ptr MCI_SEEK_PARMS
    LPMCI_SEEK_PARMS typedef ptr MCI_SEEK_PARMS
    
    MCI_STATUS_PARMS struct
      dwCallback DWORD_PTR ?
      dwReturn DWORD_PTR ?
      dwItem DWORD ?
      dwTrack DWORD ?
    MCI_STATUS_PARMS ends

    tagMCI_STATUS_PARMS typedef MCI_STATUS_PARMS
    PMCI_STATUS_PARMS typedef ptr MCI_STATUS_PARMS
    LPMCI_STATUS_PARMS typedef ptr MCI_STATUS_PARMS
    
    ifdef _WIN32
      MCI_INFO_PARMSA struct
        dwCallback DWORD_PTR ?
        lpstrReturn LPSTR ?
        dwRetSize DWORD ?
      MCI_INFO_PARMSA ends

      tagMCI_INFO_PARMSA typedef MCI_INFO_PARMSA
      LPMCI_INFO_PARMSA typedef ptr MCI_INFO_PARMSA
      
      MCI_INFO_PARMSW struct
        dwCallback DWORD_PTR ?
        lpstrReturn LPWSTR ?
        dwRetSize DWORD ?
      MCI_INFO_PARMSW ends

      tagMCI_INFO_PARMSW typedef MCI_INFO_PARMSW
      LPMCI_INFO_PARMSW typedef ptr MCI_INFO_PARMSW
      
      ifdef UNICODE
        MCI_INFO_PARMS typedef MCI_INFO_PARMSW
        LPMCI_INFO_PARMS typedef LPMCI_INFO_PARMSW
      else
        MCI_INFO_PARMS typedef MCI_INFO_PARMSA
        LPMCI_INFO_PARMS typedef LPMCI_INFO_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_GETDEVCAPS_PARMS struct
      dwCallback DWORD_PTR ?
      dwReturn DWORD ?
      dwItem DWORD ?
    MCI_GETDEVCAPS_PARMS ends

    tagMCI_GETDEVCAPS_PARMS typedef MCI_GETDEVCAPS_PARMS
    PMCI_GETDEVCAPS_PARMS typedef ptr MCI_GETDEVCAPS_PARMS
    LPMCI_GETDEVCAPS_PARMS typedef ptr MCI_GETDEVCAPS_PARMS
    
    ifdef _WIN32
      MCI_SYSINFO_PARMSA struct
        dwCallback DWORD_PTR ?
        lpstrReturn LPSTR ?
        dwRetSize DWORD ?
        dwNumber DWORD ?
        wDeviceType UINT ?
      MCI_SYSINFO_PARMSA ends

      tagMCI_SYSINFO_PARMSA typedef MCI_SYSINFO_PARMSA
      PMCI_SYSINFO_PARMSA typedef ptr MCI_SYSINFO_PARMSA
      LPMCI_SYSINFO_PARMSA typedef ptr MCI_SYSINFO_PARMSA
      
      MCI_SYSINFO_PARMSW struct
        dwCallback DWORD_PTR ?
        lpstrReturn LPWSTR ?
        dwRetSize DWORD ?
        dwNumber DWORD ?
        wDeviceType UINT ?
      MCI_SYSINFO_PARMSW ends

      tagMCI_SYSINFO_PARMSW typedef MCI_SYSINFO_PARMSW
      PMCI_SYSINFO_PARMSW typedef ptr MCI_SYSINFO_PARMSW
      LPMCI_SYSINFO_PARMSW typedef ptr MCI_SYSINFO_PARMSW
      
      ifdef UNICODE
        MCI_SYSINFO_PARMS typedef MCI_SYSINFO_PARMSW
        PMCI_SYSINFO_PARMS typedef PMCI_SYSINFO_PARMSW
        LPMCI_SYSINFO_PARMS typedef LPMCI_SYSINFO_PARMSW
      else
        MCI_SYSINFO_PARMS typedef MCI_SYSINFO_PARMSA
        PMCI_SYSINFO_PARMS typedef PMCI_SYSINFO_PARMSA
        LPMCI_SYSINFO_PARMS typedef LPMCI_SYSINFO_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_SET_PARMS struct
      dwCallback DWORD_PTR ?
      dwTimeFormat DWORD ?
      dwAudio DWORD ?
    MCI_SET_PARMS ends

    tagMCI_SET_PARMS typedef MCI_SET_PARMS
    PMCI_SET_PARMS typedef ptr MCI_SET_PARMS
    LPMCI_SET_PARMS typedef ptr MCI_SET_PARMS
    
    MCI_BREAK_PARMS struct
      dwCallback DWORD_PTR ?
      ifdef _WIN32
        nVirtKey SDWORD ?
        hwndBreak HWND ?
      else
        ;[...]
      endif
    MCI_BREAK_PARMS ends

    tagMCI_BREAK_PARMS typedef MCI_BREAK_PARMS
    PMCI_BREAK_PARMS typedef ptr MCI_BREAK_PARMS
    LPMCI_BREAK_PARMS typedef ptr MCI_BREAK_PARMS
    
    ifdef _WIN32
      MCI_SAVE_PARMSA struct
        dwCallback DWORD_PTR ?
        lpfilename LPCSTR ?
      MCI_SAVE_PARMSA ends

      tagMCI_SAVE_PARMSA typedef MCI_SAVE_PARMSA
      PMCI_SAVE_PARMSA typedef ptr MCI_SAVE_PARMSA
      LPMCI_SAVE_PARMSA typedef ptr MCI_SAVE_PARMSA
      
      MCI_SAVE_PARMSW struct
        dwCallback DWORD_PTR ?
        lpfilename LPCWSTR ?
      MCI_SAVE_PARMSW ends

      tagMCI_SAVE_PARMSW typedef MCI_SAVE_PARMSW
      PMCI_SAVE_PARMSW typedef ptr MCI_SAVE_PARMSW
      LPMCI_SAVE_PARMSW typedef ptr MCI_SAVE_PARMSW
      
      ifdef UNICODE
        MCI_SAVE_PARMS typedef MCI_SAVE_PARMSW
        PMCI_SAVE_PARMS typedef PMCI_SAVE_PARMSW
        LPMCI_SAVE_PARMS typedef LPMCI_SAVE_PARMSW
      else
        MCI_SAVE_PARMS typedef MCI_SAVE_PARMSA
        PMCI_SAVE_PARMS typedef PMCI_SAVE_PARMSA
        LPMCI_SAVE_PARMS typedef LPMCI_SAVE_PARMSA
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      MCI_LOAD_PARMSA struct
        dwCallback DWORD_PTR ?
        lpfilename LPCSTR ?
      MCI_LOAD_PARMSA ends

      tagMCI_LOAD_PARMSA typedef MCI_LOAD_PARMSA
      PMCI_LOAD_PARMSA typedef ptr MCI_LOAD_PARMSA
      LPMCI_LOAD_PARMSA typedef ptr MCI_LOAD_PARMSA
      
      MCI_LOAD_PARMSW struct
        dwCallback DWORD_PTR ?
        lpfilename LPCWSTR ?
      MCI_LOAD_PARMSW ends

      tagMCI_LOAD_PARMSW typedef MCI_LOAD_PARMSW
      PMCI_LOAD_PARMSW typedef ptr MCI_LOAD_PARMSW
      LPMCI_LOAD_PARMSW typedef ptr MCI_LOAD_PARMSW
      
      ifdef UNICODE
        MCI_LOAD_PARMS typedef MCI_LOAD_PARMSW
        PMCI_LOAD_PARMS typedef PMCI_LOAD_PARMSW
        LPMCI_LOAD_PARMS typedef LPMCI_LOAD_PARMSW
      else
        MCI_LOAD_PARMS typedef MCI_LOAD_PARMSA
        PMCI_LOAD_PARMS typedef PMCI_LOAD_PARMSA
        LPMCI_LOAD_PARMS typedef LPMCI_LOAD_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_RECORD_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrom DWORD ?
      dwTo DWORD ?
    MCI_RECORD_PARMS ends

    tagMCI_RECORD_PARMS typedef MCI_RECORD_PARMS
    LPMCI_RECORD_PARMS typedef ptr MCI_RECORD_PARMS
    
    MCI_VD_MODE_PARK equ (MCI_VD_OFFSET + 1)
    MCI_VD_MEDIA_CLV equ (MCI_VD_OFFSET + 2)
    MCI_VD_MEDIA_CAV equ (MCI_VD_OFFSET + 3)
    MCI_VD_MEDIA_OTHER equ (MCI_VD_OFFSET + 4)
    MCI_VD_FORMAT_TRACK equ 4001h
    MCI_VD_PLAY_REVERSE equ 00010000h
    MCI_VD_PLAY_FAST equ 00020000h
    MCI_VD_PLAY_SPEED equ 00040000h
    MCI_VD_PLAY_SCAN equ 00080000h
    MCI_VD_PLAY_SLOW equ 00100000h
    MCI_VD_SEEK_REVERSE equ 00010000h
    MCI_VD_STATUS_SPEED equ 00004002h
    MCI_VD_STATUS_FORWARD equ 00004003h
    MCI_VD_STATUS_MEDIA_TYPE equ 00004004h
    MCI_VD_STATUS_SIDE equ 00004005h
    MCI_VD_STATUS_DISC_SIZE equ 00004006h
    MCI_VD_GETDEVCAPS_CLV equ 00010000h
    MCI_VD_GETDEVCAPS_CAV equ 00020000h
    MCI_VD_SPIN_UP equ 00010000h
    MCI_VD_SPIN_DOWN equ 00020000h
    MCI_VD_GETDEVCAPS_CAN_REVERSE equ 00004002h
    MCI_VD_GETDEVCAPS_FAST_RATE equ 00004003h
    MCI_VD_GETDEVCAPS_SLOW_RATE equ 00004004h
    MCI_VD_GETDEVCAPS_NORMAL_RATE equ 00004005h
    MCI_VD_STEP_FRAMES equ 00010000h
    MCI_VD_STEP_REVERSE equ 00020000h
    MCI_VD_ESCAPE_STRING equ 00000100h
    MCI_VD_PLAY_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrom DWORD ?
      dwTo DWORD ?
      dwSpeed DWORD ?
    MCI_VD_PLAY_PARMS ends

    tagMCI_VD_PLAY_PARMS typedef MCI_VD_PLAY_PARMS
    PMCI_VD_PLAY_PARMS typedef ptr MCI_VD_PLAY_PARMS
    LPMCI_VD_PLAY_PARMS typedef ptr MCI_VD_PLAY_PARMS
    
    MCI_VD_STEP_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrames DWORD ?
    MCI_VD_STEP_PARMS ends

    tagMCI_VD_STEP_PARMS typedef MCI_VD_STEP_PARMS
    PMCI_VD_STEP_PARMS typedef ptr MCI_VD_STEP_PARMS
    LPMCI_VD_STEP_PARMS typedef ptr MCI_VD_STEP_PARMS
    
    ifdef _WIN32
      MCI_VD_ESCAPE_PARMSA struct
        dwCallback DWORD_PTR ?
        lpstrCommand LPCSTR ?
      MCI_VD_ESCAPE_PARMSA ends

      tagMCI_VD_ESCAPE_PARMSA typedef MCI_VD_ESCAPE_PARMSA
      PMCI_VD_ESCAPE_PARMSA typedef ptr MCI_VD_ESCAPE_PARMSA
      LPMCI_VD_ESCAPE_PARMSA typedef ptr MCI_VD_ESCAPE_PARMSA
      
      MCI_VD_ESCAPE_PARMSW struct
        dwCallback DWORD_PTR ?
        lpstrCommand LPCWSTR ?
      MCI_VD_ESCAPE_PARMSW ends

      tagMCI_VD_ESCAPE_PARMSW typedef MCI_VD_ESCAPE_PARMSW
      PMCI_VD_ESCAPE_PARMSW typedef ptr MCI_VD_ESCAPE_PARMSW
      LPMCI_VD_ESCAPE_PARMSW typedef ptr MCI_VD_ESCAPE_PARMSW
      
      ifdef UNICODE
        MCI_VD_ESCAPE_PARMS typedef MCI_VD_ESCAPE_PARMSW
        PMCI_VD_ESCAPE_PARMS typedef PMCI_VD_ESCAPE_PARMSW
        LPMCI_VD_ESCAPE_PARMS typedef LPMCI_VD_ESCAPE_PARMSW
      else
        MCI_VD_ESCAPE_PARMS typedef MCI_VD_ESCAPE_PARMSA
        PMCI_VD_ESCAPE_PARMS typedef PMCI_VD_ESCAPE_PARMSA
        LPMCI_VD_ESCAPE_PARMS typedef LPMCI_VD_ESCAPE_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_CDA_STATUS_TYPE_TRACK equ 00004001h
    MCI_CDA_TRACK_AUDIO equ (MCI_CD_OFFSET + 0)
    MCI_CDA_TRACK_OTHER equ (MCI_CD_OFFSET + 1)
    MCI_WAVE_PCM equ (MCI_WAVE_OFFSET + 0)
    MCI_WAVE_MAPPER equ (MCI_WAVE_OFFSET + 1)
    MCI_WAVE_OPEN_BUFFER equ 00010000h
    MCI_WAVE_SET_FORMATTAG equ 00010000h
    MCI_WAVE_SET_CHANNELS equ 00020000h
    MCI_WAVE_SET_SAMPLESPERSEC equ 00040000h
    MCI_WAVE_SET_AVGBYTESPERSEC equ 00080000h
    MCI_WAVE_SET_BLOCKALIGN equ 00100000h
    MCI_WAVE_SET_BITSPERSAMPLE equ 00200000h
    MCI_WAVE_INPUT equ 00400000h
    MCI_WAVE_OUTPUT equ 00800000h
    MCI_WAVE_STATUS_FORMATTAG equ 00004001h
    MCI_WAVE_STATUS_CHANNELS equ 00004002h
    MCI_WAVE_STATUS_SAMPLESPERSEC equ 00004003h
    MCI_WAVE_STATUS_AVGBYTESPERSEC equ 00004004h
    MCI_WAVE_STATUS_BLOCKALIGN equ 00004005h
    MCI_WAVE_STATUS_BITSPERSAMPLE equ 00004006h
    MCI_WAVE_STATUS_LEVEL equ 00004007h
    MCI_WAVE_SET_ANYINPUT equ 04000000h
    MCI_WAVE_SET_ANYOUTPUT equ 08000000h
    MCI_WAVE_GETDEVCAPS_INPUTS equ 00004001h
    MCI_WAVE_GETDEVCAPS_OUTPUTS equ 00004002h
    ifdef _WIN32
      MCI_WAVE_OPEN_PARMSA struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCSTR ?
        lpstrElementName LPCSTR ?
        lpstrAlias LPCSTR ?
        dwBufferSeconds DWORD ?
      MCI_WAVE_OPEN_PARMSA ends

      tagMCI_WAVE_OPEN_PARMSA typedef MCI_WAVE_OPEN_PARMSA
      PMCI_WAVE_OPEN_PARMSA typedef ptr MCI_WAVE_OPEN_PARMSA
      LPMCI_WAVE_OPEN_PARMSA typedef ptr MCI_WAVE_OPEN_PARMSA
      
      MCI_WAVE_OPEN_PARMSW struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCWSTR ?
        lpstrElementName LPCWSTR ?
        lpstrAlias LPCWSTR ?
        dwBufferSeconds DWORD ?
      MCI_WAVE_OPEN_PARMSW ends

      tagMCI_WAVE_OPEN_PARMSW typedef MCI_WAVE_OPEN_PARMSW
      PMCI_WAVE_OPEN_PARMSW typedef ptr MCI_WAVE_OPEN_PARMSW
      LPMCI_WAVE_OPEN_PARMSW typedef ptr MCI_WAVE_OPEN_PARMSW
      
      ifdef UNICODE
        MCI_WAVE_OPEN_PARMS typedef MCI_WAVE_OPEN_PARMSW
        PMCI_WAVE_OPEN_PARMS typedef PMCI_WAVE_OPEN_PARMSW
        LPMCI_WAVE_OPEN_PARMS typedef LPMCI_WAVE_OPEN_PARMSW
      else
        MCI_WAVE_OPEN_PARMS typedef MCI_WAVE_OPEN_PARMSA
        PMCI_WAVE_OPEN_PARMS typedef PMCI_WAVE_OPEN_PARMSA
        LPMCI_WAVE_OPEN_PARMS typedef LPMCI_WAVE_OPEN_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_WAVE_DELETE_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrom DWORD ?
      dwTo DWORD ?
    MCI_WAVE_DELETE_PARMS ends

    tagMCI_WAVE_DELETE_PARMS typedef MCI_WAVE_DELETE_PARMS
    PMCI_WAVE_DELETE_PARMS typedef ptr MCI_WAVE_DELETE_PARMS
    LPMCI_WAVE_DELETE_PARMS typedef ptr MCI_WAVE_DELETE_PARMS
    
    MCI_WAVE_SET_PARMS struct
      dwCallback DWORD_PTR ?
      dwTimeFormat DWORD ?
      dwAudio DWORD ?
      ifdef _WIN32
        wInput UINT ?
        wOutput UINT ?
      else
        ;[...]
      endif
      wFormatTag WORD ?
      wReserved2 WORD ?
      nChannels WORD ?
      wReserved3 WORD ?
      nSamplesPerSec DWORD ?
      nAvgBytesPerSec DWORD ?
      nBlockAlign WORD ?
      wReserved4 WORD ?
      wBitsPerSample WORD ?
      wReserved5 WORD ?
    MCI_WAVE_SET_PARMS ends

    tagMCI_WAVE_SET_PARMS typedef MCI_WAVE_SET_PARMS
    PMCI_WAVE_SET_PARMS typedef ptr MCI_WAVE_SET_PARMS
    LPMCI_WAVE_SET_PARMS typedef ptr MCI_WAVE_SET_PARMS
    
    MCI_SEQ_DIV_PPQN equ (0 + MCI_SEQ_OFFSET)
    MCI_SEQ_DIV_SMPTE_24 equ (1 + MCI_SEQ_OFFSET)
    MCI_SEQ_DIV_SMPTE_25 equ (2 + MCI_SEQ_OFFSET)
    MCI_SEQ_DIV_SMPTE_30DROP equ (3 + MCI_SEQ_OFFSET)
    MCI_SEQ_DIV_SMPTE_30 equ (4 + MCI_SEQ_OFFSET)
    MCI_SEQ_FORMAT_SONGPTR equ 4001h
    MCI_SEQ_FILE equ 4002h
    MCI_SEQ_MIDI equ 4003h
    MCI_SEQ_SMPTE equ 4004h
    MCI_SEQ_NONE equ 65533
    MCI_SEQ_MAPPER equ 65535
    MCI_SEQ_STATUS_TEMPO equ 00004002h
    MCI_SEQ_STATUS_PORT equ 00004003h
    MCI_SEQ_STATUS_SLAVE equ 00004007h
    MCI_SEQ_STATUS_MASTER equ 00004008h
    MCI_SEQ_STATUS_OFFSET equ 00004009h
    MCI_SEQ_STATUS_DIVTYPE equ 0000400Ah
    MCI_SEQ_STATUS_NAME equ 0000400Bh
    MCI_SEQ_STATUS_COPYRIGHT equ 0000400Ch
    MCI_SEQ_SET_TEMPO equ 00010000h
    MCI_SEQ_SET_PORT equ 00020000h
    MCI_SEQ_SET_SLAVE equ 00040000h
    MCI_SEQ_SET_MASTER equ 00080000h
    MCI_SEQ_SET_OFFSET equ 01000000h
    MCI_SEQ_SET_PARMS struct
      dwCallback DWORD_PTR ?
      dwTimeFormat DWORD ?
      dwAudio DWORD ?
      dwTempo DWORD ?
      dwPort DWORD ?
      dwSlave DWORD ?
      dwMaster DWORD ?
      dwOffset DWORD ?
    MCI_SEQ_SET_PARMS ends

    tagMCI_SEQ_SET_PARMS typedef MCI_SEQ_SET_PARMS
    PMCI_SEQ_SET_PARMS typedef ptr MCI_SEQ_SET_PARMS
    LPMCI_SEQ_SET_PARMS typedef ptr MCI_SEQ_SET_PARMS
    
    MCI_ANIM_OPEN_WS equ 00010000h
    MCI_ANIM_OPEN_PARENT equ 00020000h
    MCI_ANIM_OPEN_NOSTATIC equ 00040000h
    MCI_ANIM_PLAY_SPEED equ 00010000h
    MCI_ANIM_PLAY_REVERSE equ 00020000h
    MCI_ANIM_PLAY_FAST equ 00040000h
    MCI_ANIM_PLAY_SLOW equ 00080000h
    MCI_ANIM_PLAY_SCAN equ 00100000h
    MCI_ANIM_STEP_REVERSE equ 00010000h
    MCI_ANIM_STEP_FRAMES equ 00020000h
    MCI_ANIM_STATUS_SPEED equ 00004001h
    MCI_ANIM_STATUS_FORWARD equ 00004002h
    MCI_ANIM_STATUS_HWND equ 00004003h
    MCI_ANIM_STATUS_HPAL equ 00004004h
    MCI_ANIM_STATUS_STRETCH equ 00004005h
    MCI_ANIM_INFO_TEXT equ 00010000h
    MCI_ANIM_GETDEVCAPS_CAN_REVERSE equ 00004001h
    MCI_ANIM_GETDEVCAPS_FAST_RATE equ 00004002h
    MCI_ANIM_GETDEVCAPS_SLOW_RATE equ 00004003h
    MCI_ANIM_GETDEVCAPS_NORMAL_RATE equ 00004004h
    MCI_ANIM_GETDEVCAPS_PALETTES equ 00004006h
    MCI_ANIM_GETDEVCAPS_CAN_STRETCH equ 00004007h
    MCI_ANIM_GETDEVCAPS_MAX_WINDOWS equ 00004008h
    MCI_ANIM_REALIZE_NORM equ 00010000h
    MCI_ANIM_REALIZE_BKGD equ 00020000h
    MCI_ANIM_WINDOW_HWND equ 00010000h
    MCI_ANIM_WINDOW_STATE equ 00040000h
    MCI_ANIM_WINDOW_TEXT equ 00080000h
    MCI_ANIM_WINDOW_ENABLE_STRETCH equ 00100000h
    MCI_ANIM_WINDOW_DISABLE_STRETCH equ 00200000h
    MCI_ANIM_WINDOW_DEFAULT equ 00000000h
    MCI_ANIM_RECT equ 00010000h
    MCI_ANIM_PUT_SOURCE equ 00020000h
    MCI_ANIM_PUT_DESTINATION equ 00040000h
    MCI_ANIM_WHERE_SOURCE equ 00020000h
    MCI_ANIM_WHERE_DESTINATION equ 00040000h
    MCI_ANIM_UPDATE_HDC equ 00020000h
    ifdef _WIN32
      MCI_ANIM_OPEN_PARMSA struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCSTR ?
        lpstrElementName LPCSTR ?
        lpstrAlias LPCSTR ?
        dwStyle DWORD ?
        hWndParent HWND ?
      MCI_ANIM_OPEN_PARMSA ends

      tagMCI_ANIM_OPEN_PARMSA typedef MCI_ANIM_OPEN_PARMSA
      PMCI_ANIM_OPEN_PARMSA typedef ptr MCI_ANIM_OPEN_PARMSA
      LPMCI_ANIM_OPEN_PARMSA typedef ptr MCI_ANIM_OPEN_PARMSA
      
      MCI_ANIM_OPEN_PARMSW struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCWSTR ?
        lpstrElementName LPCWSTR ?
        lpstrAlias LPCWSTR ?
        dwStyle DWORD ?
        hWndParent HWND ?
      MCI_ANIM_OPEN_PARMSW ends

      tagMCI_ANIM_OPEN_PARMSW typedef MCI_ANIM_OPEN_PARMSW
      PMCI_ANIM_OPEN_PARMSW typedef ptr MCI_ANIM_OPEN_PARMSW
      LPMCI_ANIM_OPEN_PARMSW typedef ptr MCI_ANIM_OPEN_PARMSW
      
      ifdef UNICODE
        MCI_ANIM_OPEN_PARMS typedef MCI_ANIM_OPEN_PARMSW
        PMCI_ANIM_OPEN_PARMS typedef PMCI_ANIM_OPEN_PARMSW
        LPMCI_ANIM_OPEN_PARMS typedef LPMCI_ANIM_OPEN_PARMSW
      else
        MCI_ANIM_OPEN_PARMS typedef MCI_ANIM_OPEN_PARMSA
        PMCI_ANIM_OPEN_PARMS typedef PMCI_ANIM_OPEN_PARMSA
        LPMCI_ANIM_OPEN_PARMS typedef LPMCI_ANIM_OPEN_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_ANIM_PLAY_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrom DWORD ?
      dwTo DWORD ?
      dwSpeed DWORD ?
    MCI_ANIM_PLAY_PARMS ends

    tagMCI_ANIM_PLAY_PARMS typedef MCI_ANIM_PLAY_PARMS
    PMCI_ANIM_PLAY_PARMS typedef ptr MCI_ANIM_PLAY_PARMS
    LPMCI_ANIM_PLAY_PARMS typedef ptr MCI_ANIM_PLAY_PARMS
    
    MCI_ANIM_STEP_PARMS struct
      dwCallback DWORD_PTR ?
      dwFrames DWORD ?
    MCI_ANIM_STEP_PARMS ends

    tagMCI_ANIM_STEP_PARMS typedef MCI_ANIM_STEP_PARMS
    PMCI_ANIM_STEP_PARMS typedef ptr MCI_ANIM_STEP_PARMS
    LPMCI_ANIM_STEP_PARMS typedef ptr MCI_ANIM_STEP_PARMS
    
    ifdef _WIN32
      MCI_ANIM_WINDOW_PARMSA struct
        dwCallback DWORD_PTR ?
        hWnd HWND ?
        nCmdShow UINT ?
        lpstrText LPCSTR ?
      MCI_ANIM_WINDOW_PARMSA ends

      tagMCI_ANIM_WINDOW_PARMSA typedef MCI_ANIM_WINDOW_PARMSA
      PMCI_ANIM_WINDOW_PARMSA typedef ptr MCI_ANIM_WINDOW_PARMSA
      LPMCI_ANIM_WINDOW_PARMSA typedef ptr MCI_ANIM_WINDOW_PARMSA
      
      MCI_ANIM_WINDOW_PARMSW struct
        dwCallback DWORD_PTR ?
        hWnd HWND ?
        nCmdShow UINT ?
        lpstrText LPCWSTR ?
      MCI_ANIM_WINDOW_PARMSW ends

      tagMCI_ANIM_WINDOW_PARMSW typedef MCI_ANIM_WINDOW_PARMSW
      PMCI_ANIM_WINDOW_PARMSW typedef ptr MCI_ANIM_WINDOW_PARMSW
      LPMCI_ANIM_WINDOW_PARMSW typedef ptr MCI_ANIM_WINDOW_PARMSW
      
      ifdef UNICODE
        MCI_ANIM_WINDOW_PARMS typedef MCI_ANIM_WINDOW_PARMSW
        PMCI_ANIM_WINDOW_PARMS typedef PMCI_ANIM_WINDOW_PARMSW
        LPMCI_ANIM_WINDOW_PARMS typedef LPMCI_ANIM_WINDOW_PARMSW
      else
        MCI_ANIM_WINDOW_PARMS typedef MCI_ANIM_WINDOW_PARMSA
        PMCI_ANIM_WINDOW_PARMS typedef PMCI_ANIM_WINDOW_PARMSA
        LPMCI_ANIM_WINDOW_PARMS typedef LPMCI_ANIM_WINDOW_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_ANIM_RECT_PARMS struct
      dwCallback DWORD_PTR ?
      ifdef MCI_USE_OFFEXT
        ptOffset POINT <>
        ptExtent POINT <>
      else
        rc RECT <>
      endif
    MCI_ANIM_RECT_PARMS ends

    tagMCI_ANIM_RECT_PARMS typedef MCI_ANIM_RECT_PARMS
    PMCI_ANIM_RECT_PARMS typedef ptr MCI_ANIM_RECT_PARMS
    LPMCI_ANIM_RECT_PARMS typedef ptr MCI_ANIM_RECT_PARMS
    MCI_ANIM_UPDATE_PARMS struct
      dwCallback DWORD_PTR ?
      rc RECT <>
      hDC HDC ?
    MCI_ANIM_UPDATE_PARMS ends

    tagMCI_ANIM_UPDATE_PARMS typedef MCI_ANIM_UPDATE_PARMS
    PMCI_ANIM_UPDATE_PARMS typedef ptr MCI_ANIM_UPDATE_PARMS
    LPMCI_ANIM_UPDATE_PARMS typedef ptr MCI_ANIM_UPDATE_PARMS
    
    MCI_OVLY_OPEN_WS equ 00010000h
    MCI_OVLY_OPEN_PARENT equ 00020000h
    MCI_OVLY_STATUS_HWND equ 00004001h
    MCI_OVLY_STATUS_STRETCH equ 00004002h
    MCI_OVLY_INFO_TEXT equ 00010000h
    MCI_OVLY_GETDEVCAPS_CAN_STRETCH equ 00004001h
    MCI_OVLY_GETDEVCAPS_CAN_FREEZE equ 00004002h
    MCI_OVLY_GETDEVCAPS_MAX_WINDOWS equ 00004003h
    MCI_OVLY_WINDOW_HWND equ 00010000h
    MCI_OVLY_WINDOW_STATE equ 00040000h
    MCI_OVLY_WINDOW_TEXT equ 00080000h
    MCI_OVLY_WINDOW_ENABLE_STRETCH equ 00100000h
    MCI_OVLY_WINDOW_DISABLE_STRETCH equ 00200000h
    MCI_OVLY_WINDOW_DEFAULT equ 00000000h
    MCI_OVLY_RECT equ 00010000h
    MCI_OVLY_PUT_SOURCE equ 00020000h
    MCI_OVLY_PUT_DESTINATION equ 00040000h
    MCI_OVLY_PUT_FRAME equ 00080000h
    MCI_OVLY_PUT_VIDEO equ 00100000h
    MCI_OVLY_WHERE_SOURCE equ 00020000h
    MCI_OVLY_WHERE_DESTINATION equ 00040000h
    MCI_OVLY_WHERE_FRAME equ 00080000h
    MCI_OVLY_WHERE_VIDEO equ 00100000h
    ifdef _WIN32
      MCI_OVLY_OPEN_PARMSA struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCSTR ?
        lpstrElementName LPCSTR ?
        lpstrAlias LPCSTR ?
        dwStyle DWORD ?
        hWndParent HWND ?
      MCI_OVLY_OPEN_PARMSA ends

      tagMCI_OVLY_OPEN_PARMSA typedef MCI_OVLY_OPEN_PARMSA
      PMCI_OVLY_OPEN_PARMSA typedef ptr MCI_OVLY_OPEN_PARMSA
      LPMCI_OVLY_OPEN_PARMSA typedef ptr MCI_OVLY_OPEN_PARMSA
      
      MCI_OVLY_OPEN_PARMSW struct
        dwCallback DWORD_PTR ?
        wDeviceID MCIDEVICEID ?
        lpstrDeviceType LPCWSTR ?
        lpstrElementName LPCWSTR ?
        lpstrAlias LPCWSTR ?
        dwStyle DWORD ?
        hWndParent HWND ?
      MCI_OVLY_OPEN_PARMSW ends

      tagMCI_OVLY_OPEN_PARMSW typedef MCI_OVLY_OPEN_PARMSW
      PMCI_OVLY_OPEN_PARMSW typedef ptr MCI_OVLY_OPEN_PARMSW
      LPMCI_OVLY_OPEN_PARMSW typedef ptr MCI_OVLY_OPEN_PARMSW
      
      ifdef UNICODE
        MCI_OVLY_OPEN_PARMS typedef MCI_OVLY_OPEN_PARMSW
        PMCI_OVLY_OPEN_PARMS typedef PMCI_OVLY_OPEN_PARMSW
        LPMCI_OVLY_OPEN_PARMS typedef LPMCI_OVLY_OPEN_PARMSW
      else
        MCI_OVLY_OPEN_PARMS typedef MCI_OVLY_OPEN_PARMSA
        PMCI_OVLY_OPEN_PARMS typedef PMCI_OVLY_OPEN_PARMSA
        LPMCI_OVLY_OPEN_PARMS typedef LPMCI_OVLY_OPEN_PARMSA
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      MCI_OVLY_WINDOW_PARMSA struct
        dwCallback DWORD_PTR ?
        hWnd HWND ?
        nCmdShow UINT ?
        lpstrText LPCSTR ?
      MCI_OVLY_WINDOW_PARMSA ends

      tagMCI_OVLY_WINDOW_PARMSA typedef MCI_OVLY_WINDOW_PARMSA
      PMCI_OVLY_WINDOW_PARMSA typedef ptr MCI_OVLY_WINDOW_PARMSA
      LPMCI_OVLY_WINDOW_PARMSA typedef ptr MCI_OVLY_WINDOW_PARMSA
      
      MCI_OVLY_WINDOW_PARMSW struct
        dwCallback DWORD_PTR ?
        hWnd HWND ?
        nCmdShow UINT ?
        lpstrText LPCWSTR ?
      MCI_OVLY_WINDOW_PARMSW ends

      tagMCI_OVLY_WINDOW_PARMSW typedef MCI_OVLY_WINDOW_PARMSW
      PMCI_OVLY_WINDOW_PARMSW typedef ptr MCI_OVLY_WINDOW_PARMSW
      LPMCI_OVLY_WINDOW_PARMSW typedef ptr MCI_OVLY_WINDOW_PARMSW
      
      ifdef UNICODE
        MCI_OVLY_WINDOW_PARMS typedef MCI_OVLY_WINDOW_PARMSW
        PMCI_OVLY_WINDOW_PARMS typedef PMCI_OVLY_WINDOW_PARMSW
        LPMCI_OVLY_WINDOW_PARMS typedef LPMCI_OVLY_WINDOW_PARMSW
      else
        MCI_OVLY_WINDOW_PARMS typedef MCI_OVLY_WINDOW_PARMSA
        PMCI_OVLY_WINDOW_PARMS typedef PMCI_OVLY_WINDOW_PARMSA
        LPMCI_OVLY_WINDOW_PARMS typedef LPMCI_OVLY_WINDOW_PARMSA
      endif
    else
      ;[...]
    endif
    MCI_OVLY_RECT_PARMS struct
      dwCallback DWORD_PTR ?
      ifdef MCI_USE_OFFEXT
        ptOffset POINT <>
        ptExtent POINT <>
      else
        rc RECT <>
      endif
    MCI_OVLY_RECT_PARMS ends

    tagMCI_OVLY_RECT_PARMS typedef MCI_OVLY_RECT_PARMS
    PMCI_OVLY_RECT_PARMS typedef ptr MCI_OVLY_RECT_PARMS
    LPMCI_OVLY_RECT_PARMS typedef ptr MCI_OVLY_RECT_PARMS
    
    ifdef _WIN32
      MCI_OVLY_SAVE_PARMSA struct
        dwCallback DWORD_PTR ?
        lpfilename LPCSTR ?
        rc RECT <>
      MCI_OVLY_SAVE_PARMSA ends

      tagMCI_OVLY_SAVE_PARMSA typedef MCI_OVLY_SAVE_PARMSA
      PMCI_OVLY_SAVE_PARMSA typedef ptr MCI_OVLY_SAVE_PARMSA
      LPMCI_OVLY_SAVE_PARMSA typedef ptr MCI_OVLY_SAVE_PARMSA
      
      MCI_OVLY_SAVE_PARMSW struct
        dwCallback DWORD_PTR ?
        lpfilename LPCWSTR ?
        rc RECT <>
      MCI_OVLY_SAVE_PARMSW ends

      tagMCI_OVLY_SAVE_PARMSW typedef MCI_OVLY_SAVE_PARMSW
      PMCI_OVLY_SAVE_PARMSW typedef ptr MCI_OVLY_SAVE_PARMSW
      LPMCI_OVLY_SAVE_PARMSW typedef ptr MCI_OVLY_SAVE_PARMSW
      
      ifdef UNICODE
        MCI_OVLY_SAVE_PARMS typedef MCI_OVLY_SAVE_PARMSW
        PMCI_OVLY_SAVE_PARMS typedef PMCI_OVLY_SAVE_PARMSW
        LPMCI_OVLY_SAVE_PARMS typedef LPMCI_OVLY_SAVE_PARMSW
      else
        MCI_OVLY_SAVE_PARMS typedef MCI_OVLY_SAVE_PARMSA
        PMCI_OVLY_SAVE_PARMS typedef PMCI_OVLY_SAVE_PARMSA
        LPMCI_OVLY_SAVE_PARMS typedef LPMCI_OVLY_SAVE_PARMSA
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      MCI_OVLY_LOAD_PARMSA struct
        dwCallback DWORD_PTR ?
        lpfilename LPCSTR ?
        rc RECT <>
      MCI_OVLY_LOAD_PARMSA ends

      tagMCI_OVLY_LOAD_PARMSA typedef MCI_OVLY_LOAD_PARMSA
      PMCI_OVLY_LOAD_PARMSA typedef ptr MCI_OVLY_LOAD_PARMSA
      LPMCI_OVLY_LOAD_PARMSA typedef ptr MCI_OVLY_LOAD_PARMSA
      
      MCI_OVLY_LOAD_PARMSW struct
        dwCallback DWORD_PTR ?
        lpfilename LPCWSTR ?
        rc RECT <>
      MCI_OVLY_LOAD_PARMSW ends

      tagMCI_OVLY_LOAD_PARMSW typedef MCI_OVLY_LOAD_PARMSW
      PMCI_OVLY_LOAD_PARMSW typedef ptr MCI_OVLY_LOAD_PARMSW
      LPMCI_OVLY_LOAD_PARMSW typedef ptr MCI_OVLY_LOAD_PARMSW
      
      ifdef UNICODE
        MCI_OVLY_LOAD_PARMS typedef MCI_OVLY_LOAD_PARMSW
        PMCI_OVLY_LOAD_PARMS typedef PMCI_OVLY_LOAD_PARMSW
        LPMCI_OVLY_LOAD_PARMS typedef LPMCI_OVLY_LOAD_PARMSW
      else
        MCI_OVLY_LOAD_PARMS typedef MCI_OVLY_LOAD_PARMSA
        PMCI_OVLY_LOAD_PARMS typedef PMCI_OVLY_LOAD_PARMSA
        LPMCI_OVLY_LOAD_PARMS typedef LPMCI_OVLY_LOAD_PARMSA
      endif
    else
      ;[...]
    endif
    mciGetDriverData proto WIN_STD_CALL_CONV :MCIDEVICEID
    mciLoadCommandResource proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :UINT
    mciSetDriverData proto WIN_STD_CALL_CONV :MCIDEVICEID, :DWORD_PTR
    mciDriverYield proto WIN_STD_CALL_CONV :MCIDEVICEID
    mciDriverNotify proto WIN_STD_CALL_CONV :HANDLE, :MCIDEVICEID, :UINT
    mciFreeCommandResource proto WIN_STD_CALL_CONV :UINT
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

