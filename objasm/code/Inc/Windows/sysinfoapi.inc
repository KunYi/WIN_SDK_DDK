;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\sysinfoapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _SYSINFOAPI_H_
  _SYSINFOAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  if (_MSC_VER ge 800)
    ifndef __WINDOWS_DONT_DISABLE_PRAGMA_PACK_WARNING__
    endif
    if _MSC_VER ge 1200
    endif
  endif
  if Defined(FKG_FORCED_USAGE) or Defined(WINPHONE) or Defined(BUILD_WINDOWS)
    NOT_BUILD_WINDOWS_DEPRECATE equ <>
  else
    NOT_BUILD_WINDOWS_DEPRECATE equ <__declspec(deprecated)>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    SYSTEM_INFO struct
      union
        dwOemId DWORD ?
        struct
          wProcessorArchitecture WORD ?
          wReserved WORD ?
        ends
      ends
      dwPageSize DWORD ?
      lpMinimumApplicationAddress LPVOID ?
      lpMaximumApplicationAddress LPVOID ?
      dwActiveProcessorMask DWORD_PTR ?
      dwNumberOfProcessors DWORD ?
      dwProcessorType DWORD ?
      dwAllocationGranularity DWORD ?
      wProcessorLevel WORD ?
      wProcessorRevision WORD ?
    SYSTEM_INFO ends

    _SYSTEM_INFO typedef SYSTEM_INFO
    LPSYSTEM_INFO typedef ptr SYSTEM_INFO
    
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    MEMORYSTATUSEX struct
      dwLength DWORD ?
      dwMemoryLoad DWORD ?
      ullTotalPhys DWORDLONG ?
      ullAvailPhys DWORDLONG ?
      ullTotalPageFile DWORDLONG ?
      ullAvailPageFile DWORDLONG ?
      ullTotalVirtual DWORDLONG ?
      ullAvailVirtual DWORDLONG ?
      ullAvailExtendedVirtual DWORDLONG ?
    MEMORYSTATUSEX ends

    _MEMORYSTATUSEX typedef MEMORYSTATUSEX
    LPMEMORYSTATUSEX typedef ptr MEMORYSTATUSEX
    
    @DefProto DllImport, GlobalMemoryStatusEx, WIN_STD_CALL_CONV,, <:LPMEMORYSTATUSEX>, 4
    @DefProto DllImport, GetSystemInfo, WIN_STD_CALL_CONV,, <:LPSYSTEM_INFO>, 4
    @DefProto DllImport, GetSystemTime, WIN_STD_CALL_CONV,, <:LPSYSTEMTIME>, 4
    @DefProto DllImport, GetSystemTimeAsFileTime, WIN_STD_CALL_CONV,, <:LPFILETIME>, 4
    @DefProto DllImport, GetLocalTime, WIN_STD_CALL_CONV,, <:LPSYSTEMTIME>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetVersion, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetLocalTime, WIN_STD_CALL_CONV,, <:ptr SYSTEMTIME>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetTickCount, WIN_STD_CALL_CONV,, <>, 0
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetTickCount64, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetSystemTimeAdjustment, WIN_STD_CALL_CONV,, <:PDWORD, :PDWORD, :PBOOL>, 12
    @DefProto DllImport, GetSystemTimeAdjustmentPrecise, WIN_STD_CALL_CONV,, <:PDWORD64, :PDWORD64, :PBOOL>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetSystemDirectoryA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
    @DefProto DllImport, GetSystemDirectoryW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
    ifdef UNICODE
      GetSystemDirectory equ <GetSystemDirectoryW>
    else
      GetSystemDirectory equ <GetSystemDirectoryA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetWindowsDirectoryA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
    @DefProto DllImport, GetWindowsDirectoryW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
    ifdef UNICODE
      GetWindowsDirectory equ <GetWindowsDirectoryW>
    else
      GetWindowsDirectory equ <GetWindowsDirectoryA>
    endif
    @DefProto DllImport, GetSystemWindowsDirectoryA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
    @DefProto DllImport, GetSystemWindowsDirectoryW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
    ifdef UNICODE
      GetSystemWindowsDirectory equ <GetSystemWindowsDirectoryW>
    else
      GetSystemWindowsDirectory equ <GetSystemWindowsDirectoryA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    COMPUTER_NAME_FORMAT typedef SDWORD
    ComputerNameNetBIOS equ 0
    ComputerNameDnsHostname equ 1
    ComputerNameDnsDomain equ 2
    ComputerNameDnsFullyQualified equ 3
    ComputerNamePhysicalNetBIOS equ 4
    ComputerNamePhysicalDnsHostname equ 5
    ComputerNamePhysicalDnsDomain equ 6
    ComputerNamePhysicalDnsFullyQualified equ 7
    ComputerNameMax equ 8
    _COMPUTER_NAME_FORMAT typedef COMPUTER_NAME_FORMAT
    
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetComputerNameExA, WIN_STD_CALL_CONV,, <:COMPUTER_NAME_FORMAT, :LPSTR, :LPDWORD>, 12
    @DefProto DllImport, GetComputerNameExW, WIN_STD_CALL_CONV,, <:COMPUTER_NAME_FORMAT, :LPWSTR, :LPDWORD>, 12
    ifdef UNICODE
      GetComputerNameEx equ <GetComputerNameExW>
    else
      GetComputerNameEx equ <GetComputerNameExA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetComputerNameExW, WIN_STD_CALL_CONV,, <:COMPUTER_NAME_FORMAT, :LPCWSTR>, 8
    ifdef UNICODE
      SetComputerNameEx equ <SetComputerNameExW>
    endif
    @DefProto DllImport, SetSystemTime, WIN_STD_CALL_CONV,, <:ptr SYSTEMTIME>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetVersionExA, WIN_STD_CALL_CONV,, <:LPOSVERSIONINFOA>, 4
    @DefProto DllImport, GetVersionExW, WIN_STD_CALL_CONV,, <:LPOSVERSIONINFOW>, 4
    ifdef UNICODE
      GetVersionEx equ <GetVersionExW>
    else
      GetVersionEx equ <GetVersionExA>
    endif
    @DefProto DllImport, GetLogicalProcessorInformation, WIN_STD_CALL_CONV,, <:PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, :PDWORD>, 8
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      @DefProto DllImport, GetLogicalProcessorInformationEx, WIN_STD_CALL_CONV,, <:LOGICAL_PROCESSOR_RELATIONSHIP, :PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, :PDWORD>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      @DefProto DllImport, GetNativeSystemInfo, WIN_STD_CALL_CONV,, <:LPSYSTEM_INFO>, 4
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, GetSystemTimePreciseAsFileTime, WIN_STD_CALL_CONV,, <:LPFILETIME>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      @DefProto DllImport, GetProductInfo, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :DWORD, :PDWORD>, 20
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      @DefProto DllImport, VerSetConditionMask, WIN_STD_CALL_CONV,, <:ULONGLONG, :ULONG, :UCHAR>, 16
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, GetOsSafeBootMode, WIN_STD_CALL_CONV,, <:PDWORD>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP)
    @DefProto DllImport, EnumSystemFirmwareTables, WIN_STD_CALL_CONV,, <:DWORD, :PVOID, :DWORD>, 12
    @DefProto DllImport, GetSystemFirmwareTable, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :PVOID, :DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DnsHostnameToComputerNameExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :LPDWORD>, 12
    @DefProto DllImport, GetPhysicallyInstalledSystemMemory, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    SCEX2_ALT_NETBIOS_NAME equ 00000001h
    @DefProto DllImport, SetComputerNameEx2W, WIN_STD_CALL_CONV,, <:COMPUTER_NAME_FORMAT, :DWORD, :LPCWSTR>, 12
    ifdef UNICODE
      SetComputerNameEx2 equ <SetComputerNameEx2W>
    endif
    @DefProto DllImport, SetSystemTimeAdjustment, WIN_STD_CALL_CONV,, <:DWORD, :BOOL>, 8
    @DefProto DllImport, SetSystemTimeAdjustmentPrecise, WIN_STD_CALL_CONV,, <:DWORD64, :BOOL>, 12
    @DefProto DllImport, InstallELAMCertificateInfo, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
    @DefProto DllImport, GetProcessorSystemCycleTime, WIN_STD_CALL_CONV,, <:USHORT, :PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION, :PDWORD>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      @DefProto DllImport, GetOsManufacturingMode, WIN_STD_CALL_CONV,, <:PBOOL>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      @DefProto DllImport, GetIntegratedDisplaySize, WIN_STD_CALL_CONV,, <:ptr REAL8>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetComputerNameA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, SetComputerNameW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      SetComputerName equ <SetComputerNameW>
    else
      SetComputerName equ <SetComputerNameA>
    endif
    @DefProto DllImport, SetComputerNameExA, WIN_STD_CALL_CONV,, <:COMPUTER_NAME_FORMAT, :LPCSTR>, 8
    ifndef UNICODE
      SetComputerNameEx equ <SetComputerNameExA>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
endif

