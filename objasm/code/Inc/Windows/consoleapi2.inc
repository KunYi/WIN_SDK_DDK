;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\consoleapi2.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _APISETCONSOLEL2_
  _APISETCONSOLEL2_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  include wincontypes.inc
  include windef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    FOREGROUND_BLUE equ 0001h
    FOREGROUND_GREEN equ 0002h
    FOREGROUND_RED equ 0004h
    FOREGROUND_INTENSITY equ 0008h
    BACKGROUND_BLUE equ 0010h
    BACKGROUND_GREEN equ 0020h
    BACKGROUND_RED equ 0040h
    BACKGROUND_INTENSITY equ 0080h
    COMMON_LVB_LEADING_BYTE equ 0100h
    COMMON_LVB_TRAILING_BYTE equ 0200h
    COMMON_LVB_GRID_HORIZONTAL equ 0400h
    COMMON_LVB_GRID_LVERTICAL equ 0800h
    COMMON_LVB_GRID_RVERTICAL equ 1000h
    COMMON_LVB_REVERSE_VIDEO equ 4000h
    COMMON_LVB_UNDERSCORE equ 8000h
    COMMON_LVB_SBCSDBCS equ 0300h
    @DefProto DllImport, FillConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :CHAR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, FillConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :WCHAR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      FillConsoleOutputCharacter equ <FillConsoleOutputCharacterW>
    else
      FillConsoleOutputCharacter equ <FillConsoleOutputCharacterA>
    endif
    @DefProto DllImport, FillConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :WORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, GenerateConsoleCtrlEvent, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    @DefProto DllImport, CreateConsoleScreenBuffer, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr SECURITY_ATTRIBUTES, :DWORD, :LPVOID>, 20
    @DefProto DllImport, SetConsoleActiveScreenBuffer, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, FlushConsoleInputBuffer, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetConsoleCP, WIN_STD_CALL_CONV,, <:UINT>, 4
    @DefProto DllImport, SetConsoleOutputCP, WIN_STD_CALL_CONV,, <:UINT>, 4
    CONSOLE_CURSOR_INFO struct
      dwSize DWORD ?
      bVisible BOOL ?
    CONSOLE_CURSOR_INFO ends

    _CONSOLE_CURSOR_INFO typedef CONSOLE_CURSOR_INFO
    PCONSOLE_CURSOR_INFO typedef ptr CONSOLE_CURSOR_INFO
    
    @DefProto DllImport, GetConsoleCursorInfo, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_CURSOR_INFO>, 8
    @DefProto DllImport, SetConsoleCursorInfo, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CONSOLE_CURSOR_INFO>, 8
    CONSOLE_SCREEN_BUFFER_INFO struct
      dwSize COORD <>
      dwCursorPosition COORD <>
      wAttributes WORD ?
      srWindow SMALL_RECT <>
      dwMaximumWindowSize COORD <>
    CONSOLE_SCREEN_BUFFER_INFO ends

    _CONSOLE_SCREEN_BUFFER_INFO typedef CONSOLE_SCREEN_BUFFER_INFO
    PCONSOLE_SCREEN_BUFFER_INFO typedef ptr CONSOLE_SCREEN_BUFFER_INFO
    
    @DefProto DllImport, GetConsoleScreenBufferInfo, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFO>, 8
    CONSOLE_SCREEN_BUFFER_INFOEX struct
      cbSize ULONG ?
      dwSize COORD <>
      dwCursorPosition COORD <>
      wAttributes WORD ?
      srWindow SMALL_RECT <>
      dwMaximumWindowSize COORD <>
      wPopupAttributes WORD ?
      bFullscreenSupported BOOL ?
      ColorTable COLORREF 16 dup (?)
    CONSOLE_SCREEN_BUFFER_INFOEX ends

    _CONSOLE_SCREEN_BUFFER_INFOEX typedef CONSOLE_SCREEN_BUFFER_INFOEX
    PCONSOLE_SCREEN_BUFFER_INFOEX typedef ptr CONSOLE_SCREEN_BUFFER_INFOEX
    
    @DefProto DllImport, GetConsoleScreenBufferInfoEx, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFOEX>, 8
    @DefProto DllImport, SetConsoleScreenBufferInfoEx, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFOEX>, 8
    @DefProto DllImport, SetConsoleScreenBufferSize, WIN_STD_CALL_CONV,, <:HANDLE, :COORD>, 8
    @DefProto DllImport, SetConsoleCursorPosition, WIN_STD_CALL_CONV,, <:HANDLE, :COORD>, 8
    @DefProto DllImport, GetLargestConsoleWindowSize, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetConsoleTextAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :WORD>, 8
    @DefProto DllImport, SetConsoleWindowInfo, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :ptr SMALL_RECT>, 12
    @DefProto DllImport, WriteConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, WriteConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterW>
    else
      WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterA>
    endif
    @DefProto DllImport, WriteConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :ptr WORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, ReadConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, ReadConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterW>
    else
      ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterA>
    endif
    @DefProto DllImport, ReadConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :LPWORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, WriteConsoleInputA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr INPUT_RECORD, :DWORD, :LPDWORD>, 16
    @DefProto DllImport, WriteConsoleInputW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr INPUT_RECORD, :DWORD, :LPDWORD>, 16
    ifdef UNICODE
      WriteConsoleInput equ <WriteConsoleInputW>
    else
      WriteConsoleInput equ <WriteConsoleInputA>
    endif
    @DefProto DllImport, ScrollConsoleScreenBufferA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO>, 20
    @DefProto DllImport, ScrollConsoleScreenBufferW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO>, 20
    ifdef UNICODE
      ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferW>
    else
      ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferA>
    endif
    @DefProto DllImport, WriteConsoleOutputA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    @DefProto DllImport, WriteConsoleOutputW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    ifdef UNICODE
      WriteConsoleOutput equ <WriteConsoleOutputW>
    else
      WriteConsoleOutput equ <WriteConsoleOutputA>
    endif
    @DefProto DllImport, ReadConsoleOutputA, WIN_STD_CALL_CONV,, <:HANDLE, :PCHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    @DefProto DllImport, ReadConsoleOutputW, WIN_STD_CALL_CONV,, <:HANDLE, :PCHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    ifdef UNICODE
      ReadConsoleOutput equ <ReadConsoleOutputW>
    else
      ReadConsoleOutput equ <ReadConsoleOutputA>
    endif
    @DefProto DllImport, GetConsoleTitleA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
    @DefProto DllImport, GetConsoleTitleW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
    ifdef UNICODE
      GetConsoleTitle equ <GetConsoleTitleW>
    else
      GetConsoleTitle equ <GetConsoleTitleA>
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetConsoleOriginalTitleA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, GetConsoleOriginalTitleW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        GetConsoleOriginalTitle equ <GetConsoleOriginalTitleW>
      else
        GetConsoleOriginalTitle equ <GetConsoleOriginalTitleA>
      endif
    endif
    @DefProto DllImport, SetConsoleTitleA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, SetConsoleTitleW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      SetConsoleTitle equ <SetConsoleTitleW>
    else
      SetConsoleTitle equ <SetConsoleTitleA>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

