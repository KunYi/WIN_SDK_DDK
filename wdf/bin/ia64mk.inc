!IF 0

Copyright (c) Microsoft Corporation

Module Name:

    ia64mk.inc

Abstract:

        This module contains the ia64 specific build controls.  It is included
        by makefile.def.

Revision History:

!ENDIF

#
# ia64 option control
#

UMBASE=$(UMBASE:*=ia64)
UMLIBS=$(UMLIBS:*=ia64)
NTRES=$(NTRES:*=ia64)
UMRES=$(UMRES:*=ia64)
UMOBJS=$(UMOBJS:*=ia64)
CRTLIBS=$(CRTLIBS:*=ia64)
LINKLIBS=$(LINKLIBS:*=ia64)
GDI_DRIVER_LIBS=$(GDI_DRIVER_LIBS:*=ia64)
DLLBASE=$(DLLBASE:*=ia64)
DLLDEF=$(DLLDEF:*=ia64)
MACHINE_TARGETLIBS=$(MACHINE_TARGETLIBS:*=ia64)
TARGET=$(TARGET:*=ia64)
DYNLINK_LIB=$(DYNLINK_LIB:*=ia64)
TARGETEXEFILES=$(TARGETEXEFILES:*=ia64)
TARGETLIBFILES=$(TARGETLIBFILES:*=ia64)
TARGETOBJFILES=$(TARGETOBJFILES:*=ia64)
UMOBJFILES=$(UMOBJFILES:*=ia64)
UMEXEFILES=$(UMEXEFILES:*=ia64)
HEADERFILE=$(HEADERFILE:*=ia64)
HEADEROBJNAME=$(HEADEROBJNAME:*=ia64)
HEADEROBJ=$(HEADEROBJ:*=ia64)
PRECOMPILED=$(PRECOMPILED:*=ia64)
PRECOMPILED_CXX=$(PRECOMPILED_CXX:*=ia64)
PRECOMPILED_TARGET=$(PRECOMPILED_TARGET:*=ia64)
MFC_STATIC_LIB=$(MFC_STATIC_LIB:*=ia64)
CRT_LIB_PATH=$(CRT_LIB_PATH:*=ia64)
SDK_LIB_PATH=$(SDK_LIB_PATH:*=ia64)
DDK_LIB_PATH=$(DDK_LIB_PATH:*=ia64)
IFSKIT_LIB_PATH=$(IFSKIT_LIB_PATH:*=ia64)
HALKIT_LIB_PATH=$(HALKIT_LIB_PATH:*=ia64)
ORDER=$(ORDER:*=ia64)
OBJLIBFILES=$(OBJLIBFILES:*=ia64)
MISCFILES=$(MISCFILES) $(IA64_MISCFILES)
!if defined(IA64_DRIVER_INFS)
DRIVER_INFS=$(DRIVER_INFS) $(IA64_DRIVER_INFS)
!endif
!if defined(IA64_MANIFESTED_INFS)
MANIFESTED_INFS=$(MANIFESTED_INFS) $(IA64_MANIFESTED_INFS)
!endif
!if defined(IA64_PRINTER_INFS)
PRINTER_INFS=$(PRINTER_INFS) $(IA64_PRINTER_INFS)
!endif
!if defined(IA64_MANIFESTED_PRINTER_INFS)
MANIFESTED_PRINTER_INFS=$(MANIFESTED_PRINTER_INFS) $(IA64_MANIFESTED_PRINTER_INFS)
!endif
!if defined(IA64_NON_PNP_INFS)
NON_PNP_INFS=$(NON_PNP_INFS) $(IA64_NON_PNP_INFS)
!endif
!if defined(IA64_NON_PNP_SIGN_INFS)
NON_PNP_SIGN_INFS=$(NON_PNP_SIGN_INFS) $(IA64_NON_PNP_SIGN_INFS)
!endif
!if defined(IA64_LOC_DRIVER_INFS)
LOC_DRIVER_INFS=$(LOC_DRIVER_INFS) $(IA64_LOC_DRIVER_INFS)
!endif
!if defined(IA64_LOC_MANIFESTED_INFS)
LOC_MANIFESTED_INFS=$(LOC_MANIFESTED_INFS) $(IA64_LOC_MANIFESTED_INFS)
!endif
!if defined(IA64_LOC_PRINTER_INFS)
LOC_PRINTER_INFS=$(LOC_PRINTER_INFS) $(IA64_LOC_PRINTER_INFS)
!endif
!if defined(IA64_LOC_MANIFESTED_PRINTER_INFS)
LOC_MANIFESTED_PRINTER_INFS=$(LOC_MANIFESTED_PRINTER_INFS) $(IA64_LOC_MANIFESTED_PRINTER_INFS)
!endif
!if defined(IA64_LOC_NON_PNP_INFS)
LOC_NON_PNP_INFS=$(LOC_NON_PNP_INFS) $(IA64_LOC_NON_PNP_INFS)
!endif
!if defined(IA64_LOC_NON_PNP_SIGN_INFS)
LOC_NON_PNP_SIGN_INFS=$(LOC_NON_PNP_SIGN_INFS) $(IA64_LOC_NON_PNP_SIGN_INFS)
!endif
SOURCES=$(SOURCES) $(IA64_SOURCES)
# BINPLACE_FLAGS=$(BINPLACE_FLAGS) /CI 8,halo.exe,/certain,/errata,/quiet

!ifdef NTTARGETFILES
NTTARGETFILES=$(NTTARGETFILES:*=ia64)
!endif
!ifdef NTTARGETFILE0
NTTARGETFILE0=$(NTTARGETFILE0:*=ia64)
!endif
!ifdef NTTARGETFILE1
NTTARGETFILE1=$(NTTARGETFILE1:*=ia64)
!endif

!ifdef PROJECT_LIB_PATH
PROJECT_LIB_PATH=$(PROJECT_LIB_PATH:*=ia64)
!endif

ENTRY_SUFFIX=
GDI_ENTRY_SUFFIX=

DEFAULT_STACKRESERVE=0x100000
DEFAULT_STACKCOMMIT=0x4000

ADDITIONAL_ATL_LIBS = $(ADDITIONAL_ATL_LIBS) $(ATL_LIB_PATH)\atl21asm.lib

!ifndef _IA64_HAZARD_DETECTION
_IA64_HAZARD_DETECTION=-X explicit
!endif

!ifdef IA64_WARNING_LEVEL
MSC_WARNING_LEVEL=$(IA64_WARNING_LEVEL)
!ENDIF

MSC_WARNING_LEVEL=$(MSC_WARNING_LEVEL) $(COMPILER_WX_SWITCH)

!ifdef IA64_PERFFLAGS
PERFFLAGS = $(IA64_PERFFLAGS)
!endif

# Set MSC_OPTIMIZATION.
# Order of precedence:
#   Platform specific override
#   Environment variable
#   System Default

!ifdef IA64_OPTIMIZATION
MSC_OPTIMIZATION=$(IA64_OPTIMIZATION)
!elseif !defined(MSC_OPTIMIZATION)
MSC_OPTIMIZATION=$(DEFAULT_MSC_OPT)
!endif

LINK_TIME_CODE_GENERATION_MSC_FLAG=

!ifndef GENIA64
!ifdef IA64_DEBUGGABLE_OPTIMIZATION
MSC_OPTIMIZATION=$(MSC_OPTIMIZATION) /Zx
!endif
!ifndef IA64_FULL_FLOATING_POINT
MSC_OPTIMIZATION=$(MSC_OPTIMIZATION) /QIPF_fr32
!endif
!if defined(LINK_TIME_CODE_GENERATION) && !defined(FORCENATIVEOBJECT)
# Some objects must be built native, so turn off GL for those
LINK_TIME_CODE_GENERATION_MSC_FLAG=/GL
!endif
!if !defined(MANAGED_CXX)
MSC_OPTIMIZATION=$(MSC_OPTIMIZATION) /QIPF_noPIC
!endif 
!endif

DBGFLAGS=$(DBGFLAGS) $(MSC_OPTIMIZATION) $(LINK_TIME_CODE_GENERATION_MSC_FLAG)
IA64_ADBGFLAGS=$(IA64_ADBGFLAGS) /d debug

!ifdef IA64_CPPFLAGS
MSC_CPPFLAGS=$(IA64_CPPFLAGS)
!elseif defined(386_CPPFLAGS)
MSC_CPPFLAGS=$(386_CPPFLAGS)
!ENDIF

!ifdef NTCPPFLAGS
!error NTCPPFLAGS is deprecated.
!endif

!ifdef NO_STRING_POOLING
STRING_POOLING =
!else
!ifdef NO_READONLY_STRINGS
STRING_POOLING = /Gf
!else
STRING_POOLING = /GF
!endif
!endif

!ifdef USE_NATIVE_EH
!if "$(USE_NATIVE_EH)" == "ASYNC"
EH_FLAGS=/EHa
!else
!if "$(USE_NATIVE_EH)" == "CTHROW"
EH_FLAGS=/EHsc-
!else
EH_FLAGS=/EHsc
!endif
!endif
!else
EH_FLAGS=/EHs-c-
!endif

!if defined(USE_RTTI) || defined(MANAGED_CXX)
RTTI_FLAGS=/GR
! else
RTTI_FLAGS=/GR-
! endif

# On by default
!if "$(BUFFER_OVERFLOW_CHECKS)" == ""
BUFFER_OVERFLOW_CHECKS=1
!endif

# Turn off for the select few
!if ("$(DRIVERTYPE)" == "VXD") || \
    (("$(TARGETTYPE)" == "MINIPORT") && ($(_NT_TARGET_VERSION) < 0x502)) || \
    (("$(TARGETTYPE)" == "DYNLINK") && defined(RESOURCE_ONLY_DLL)) || \
    "$(BUFFER_OVERFLOW_CHECKS)" == "0"
!undef BUFFER_OVERFLOW_CHECKS
!endif

!if defined(BUFFER_OVERFLOW_CHECKS)
# verify it's one of the chosen few - 1, NTDLL or compile only - all others are wrong.
! if "$(BUFFER_OVERFLOW_CHECKS)" != "1" && \
     "$(BUFFER_OVERFLOW_CHECKS)" != "NTDLL" && \
     "$(BUFFER_OVERFLOW_CHECKS)" != "COMPILE_ONLY" && \
     "$(BUFFER_OVERFLOW_CHECKS)" != "LINK_ONLY"
!  error INVALID BUFFER_OVERFLOW_CHECKS value "$(BUFFER_OVERFLOW_CHECKS)" in $(MAKEDIR)
! endif
! if "$(BUFFER_OVERFLOW_CHECKS)" == "LINK_ONLY"
BO_FLAGS=/GS-
BUFFER_OVERFLOW_CHECKS=1
! else
BO_FLAGS=/GS
! endif
! if "$(BUFFER_OVERFLOW_CHECKS)" == "1"
!  if "$(TARGETTYPE)" == "DRIVER" || \
      "$(TARGETTYPE)" == "EXPORT_DRIVER" || \
      "$(TARGETTYPE)" == "DRIVER_LIBRARY" || \
      "$(TARGETTYPE)" == "MINIPORT" 
BO_LIB=$(SDK_LIB_PATH)\BufferOverflowK.lib
DRIVER_ENTRY=GsDriverEntry
!  elseif "$(TARGETTYPE)" == "GDI_DRIVER"
BO_LIB=$(SDK_LIB_PATH)\BufferOverflowGDI.lib
GDI_DRIVER_ENTRY=GsDrvEnableDriver
!  elseif "$(TARGETTYPE)" == "DYNLINK"
!   if !(("$(UMTYPE)"== "nt") || ("$(UMTYPE)"=="ntss"))
!    if ("$(DLLENTRY)" == "/noentry" || "$(DLLENTRY)" == "-noentry")
!     if defined(USE_MSVCRT) || defined(USE_LIBCMT)
DLLENTRY=-entry:_DllMainCRTStartup
!     else
DLLENTRY=-entry:_DllMainCRTStartupForGS
!     endif
!    endif
!    if !defined(USE_MSVCRT) && !defined(USE_LIBCMT)
BO_LIB=$(SDK_LIB_PATH)\BufferOverflowU.lib
!    endif
!   endif
!  else	# TARGETTYPE == PROGRAM/LIBRARY/NOTARGET with special build rules
!   if ("$(UMTYPE)"== "nt") || ("$(UMTYPE)"=="ntss")
!    if defined(NTKERNEL)
BO_LIB=$(SDK_LIB_PATH)\BufferOverflowK.lib
!    else
BO_LIB=$(SDK_LIB_PATH)\BufferOverflow.lib
!    endif
!   else
!    if !defined(USE_MSVCRT) && !defined(USE_LIBCMT)
BO_LIB=$(SDK_LIB_PATH)\BufferOverflowU.lib
!    endif
!   endif
!  endif
! elseif "$(BUFFER_OVERFLOW_CHECKS)" == "NTDLL"
BO_LIB=$(SDK_LIB_PATH)\BufferOverflow.lib
!  if ("$(TARGETTYPE)" == "DYNLINK") && \
      ("$(DLLENTRY)" == "/noentry" || "$(DLLENTRY)" == "-noentry") && \
      ("$(TARGETNAME)" != "ntdll")
DLLENTRY=-entry:_DllMainCRTStartupForGS
!  endif
! endif
!endif  # Overflow checks


ERRATA_FLAGS=

!if defined(IA64_STRUCT_PACKING)
MSC_STRUCT_PACKING=$(IA64_STRUCT_PACKING)
!elseif !defined(MSC_STRUCT_PACKING)
MSC_STRUCT_PACKING=/Zp8
!endif

# Due to different compilers in the nt tree (older VC++ as well intel compiler)
# interpreting the /Zc:wchar_t- switch as /Zc /Z: /Zw /Zc /Zh /Za ...
# creating a variable to disable /Zc:wchar_t- for the problematic directory
!ifndef NO_WCHAR_T
COMPILER_WCHAR_T=/Zc:wchar_t-
!else
COMPILER_WCHAR_T=
!endif

# Another wchar_t fix, don't want to use any wchar_t flags
# if it's managed and version 1.1 code.
!if "$(URT_VER)" == "1.1" && defined(MANAGED_CXX)
COMPILER_WCHAR_T=
!endif

STDFLAGS= /c $(COMPILER_WCHAR_T) /Zl $(MSC_STRUCT_PACKING) /Gy $(CBSTRING) $(MSC_WARNING_LEVEL) \
          $(ERATTA_FLAGS) $(EH_FLAGS) $(RTTI_FLAGS) $(STRING_POOLING) \
          $(BO_FLAGS)

!IF $(FREEBUILD)
ASM_DBG_DEFINES=/DDBG=0
!ELSE
IA64_ADBGFLAGS=$(IA64_ADBGFLAGS) /d debug
!ENDIF

# This is only needed on x86
TARGET_DBG_DEFINES= $(TARGET_DBG_DEFINES) /DFPO=0

DBGFLAGS=$(DBGFLAGS) /Zi
IA64_ADBGFLAGS=$(IA64_ADBGFLAGS) /d debug

!IFDEF SECTION_ALIGNMENT
SECTION_ALIGNMENT=/align:$(SECTION_ALIGNMENT)
!ENDIF

KERNEL_ALIGNMENT=0x80
HAL_ALIGNMENT=0x80

LINKER_FLAGS = $(LINKER_FLAGS) $(SECTION_ALIGNMENT) /debugtype:pdata

!if !defined(USE_PDB_TO_COMPILE) || "$(USE_PDB_TO_COMPILE)" == "0"
DBGFLAGS=$(DBGFLAGS:/Zi=/Z7)
DBGFLAGS=$(DBGFLAGS:-Zi=/Z7)
!else
USER_C_FLAGS=$(USER_C_FLAGS:/Z7=/Zi)
USER_C_FLAGS=$(USER_C_FLAGS:-Z7=/Zi)
! if "$(TARGETTYPE)" == "LIBRARY"
DBGFLAGS=$(DBGFLAGS) /Fd$(TARGETPATH)\$(TARGET_DIRECTORY)\$(TARGETNAME).pdb
! else
DBGFLAGS=$(DBGFLAGS) /Fd$(OBJ_PATH)\$(_OBJ_DIR)\ia64^\
! endif
!endif

!ifndef NO_BROWSER_INFO
! ifdef BROWSER_INFO
DBGFLAGS=$(DBGFLAGS) /FR$(OBJ_PATH)\$(_OBJ_DIR)\ia64^\
! endif
!endif

!IF "$(HALTYPE)" == ""
HALDEF=
!ELSE
HALDEF=/D$(HALTYPE)=1
!ENDIF


#
#
#
!ifdef GENIA64
STD_DEFINES= /D_WIN64 /D_IA64_=1 /DIA64=1 /DNO_HW_DETECT /D_MSC_EXTENSIONS /D_GENIA64_ $(HALDEF) $(STD_DEFINES) /D_CROSS_PLATFORM_=1
!else
STD_DEFINES= /D_WIN64 /D_IA64_=1 /DIA64=1 /DNO_HW_DETECT /D_MSC_EXTENSIONS $(PTR_SIZE) $(HALDEF) $(STD_DEFINES) /D_MERCED_A0_=1
!endif

!ifdef PC98CHANGE
STD_DEFINES=$(STD_DEFINES) /D_PC98_
!endif

CDEFINES=$(STD_DEFINES) $(TARGET_DBG_DEFINES) \
              $(LIBC_DEFINES) $(C_DEFINES) $(NET_C_DEFINES) $(MFC_DEFINES)
ASM_DEFINES=$(ASM_DEFINES) /D__assembler=1
CFLAGS=$(IA64_FLAGS) $(NTIA64FLAGS) $(STDFLAGS) $(DBGFLAGS) $(PERFFLAGS) $(USER_C_FLAGS) /typedil- /wd4603 /wd4627
IA64_ASMFLAGS=$(IA64_ADBGFLAGS) $(STD_DEFINES) $(ASM_DBG_DEFINES)\
              $(TARGET_DBG_DEFINES) $(ASM_DEFINES)

IA64_CDEFINES=$(CDEFINES)
IA64_CFLAGS=$(CFLAGS)

!ifndef CC_NAME
! if defined(SUBSTITUTE_IA64_CC_MANAGED) && defined(MANAGED_CXX)
CC_NAME=$(SUBSTITUTE_IA64_CC_MANAGED) 
! elseif defined(SUBSTITUTE_IA64_CC) && !defined(MANAGED_CXX)
CC_NAME=$(SUBSTITUTE_IA64_CC) 
! elseif !defined(CC_NAME)
!  ifdef RAZZLETOOLPATH
!   if "$(PROCESSOR_ARCHITECTURE)" == "IA64"  
CC_NAME = $(RAZZLETOOLPATH)\ia64\ia64\cl 
!   else
CC_NAME = $(RAZZLETOOLPATH)\x86\ia64\cl 
!   endif
!  else
CC_NAME=cl 
!  endif
! endif
!endif



C_COMPILER_NAME     = $(CC_NAME)
CXX_COMPILER_NAME   = $(CC_NAME)
C_PREPROCESSOR_NAME = $(CC_NAME)
!ifndef IA64_ASSEMBLER_NAME
IA64_ASSEMBLER_NAME  = ias
!endif

# CRT workaround for:  cl : warning D9025 : overriding '/D_MT' with '/U_MT'
!if defined(CRTLIBTYPE) && "$(MTOPTION)" != ""
CRT_BUILD_FLAGS = $(CRT_BUILD_FLAGS:/U_MT=)
!endif
GLOBAL_C_FLAGS = /Iia64 /I. $(INCPATH1) $(CRT_BUILD_FLAGS) $(CDEFINES) $(CFLAGS)

NP_COMPILER_FLAGS = $(GLOBAL_C_FLAGS) $(COMPILER_WARNINGS)

CXX_COMPILER_FLAGS_NOPCH = $(NP_COMPILER_FLAGS) $(MSC_CPPFLAGS) $(NTCPPFLAGS) $(MANAGED_CXX_FLAGS)
C_COMPILER_FLAGS_NOPCH = $(NP_COMPILER_FLAGS)
C_COMPILER_FLAGS = $(C_COMPILER_FLAGS_NOPCH) $(PRECOMPILED)
CXX_COMPILER_FLAGS = $(CXX_COMPILER_FLAGS_NOPCH) $(PRECOMPILED_CXX)
C_PREPROCESSOR_FLAGS = $(GLOBAL_C_FLAGS) /EP /Tc

C_PREPROCESSOR = $(C_PREPROCESSOR_NAME) $(C_PREPROCESSOR_FLAGS)
C_ASM_PREPROCESSOR = $(C_PREPROCESSOR_NAME) $(ASM_DEFINES) $(C_PREPROCESSOR_FLAGS:/EP=/E)
C_COMPILER     = $(C_COMPILER_NAME) $(C_COMPILER_FLAGS)
NP_C_COMPILER  = $(C_COMPILER_NAME) $(NP_COMPILER_FLAGS)
CXX_COMPILER   = $(CXX_COMPILER_NAME) $(CXX_COMPILER_FLAGS)

IA64_ASSEMBLER=$(IA64_ASSEMBLER_NAME) $(_IA64_HAZARD_DETECTION) -A itanium2 /N so /I ia64 /I . $(INCPATH1:/I=/I ) $(IA64_ADBGFLAGS)

ECHO_MSG=$(C_COMPILER) $<
ECHO_MSG_P=$(NP_C_COMPILER) $**
ECHO_CXX_MSG=$(CXX_COMPILER) $<

ECHO_PRECOMPILED_MSG1=$(C_COMPILER_NAME) $(C_COMPILER_FLAGS) /Yl$(TARGETNAME) /Yc$(?F) $(HEADERFILE) \
               $(HEADEROBJ) $(PRECOMPILED_FLAG) $(PRECOMPILED_SOURCEFILE)
	       
ECHO_PRECOMPILED_MSG2=$(C_COMPILER_NAME) $(C_COMPILER_FLAGS) /Yl$(TARGETNAME) /Yc$(?F) $(HEADERFILE) \
               $(HEADEROBJ) $(PRECOMPILED_FLAG)

{}.c{}.s:
    $(C_COMPILER_NAME) @<< /Fa $<
$(C_COMPILER_FLAGS: =
)
$(C_COMPILER_FLAGS:##= )
<<NOKEEP

{..\ia64}.s{}.lst:
    $(IA64_ASSEMBLER) /o $@.obj $<

{ia64}.s{}.lst:
    $(IA64_ASSEMBLER) /o $@.obj $<

{..\ia64}.s{$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

{$(_OBJ_DIR)\ia64}.s{$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

{ia64}.s{$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

{..\ia64}.s{$(OBJ_PATH)\$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

{$(OBJ_PATH)\$(_OBJ_DIR)\ia64}.s{$(OBJ_PATH)\$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

{ia64}.s{$(OBJ_PATH)\$(_OBJ_DIR)\ia64}.obj:
    @-erase $@ >nul 2>&1
    $(C_ASM_PREPROCESSOR) $< >$@.i
    $(IA64_ASSEMBLER) /o $@ $@.i
    @-erase $@.i >nul 2>&1

NTKERNEL_LINK_OPTIONS=/section:ivt,,align=0x8000 /fixed:no /base:0xE000000084000000 /entry:KiSystemBegin

# SEH support for libs built with an older compiler
!ifdef _NT_TARGET_VERSION
!    if $(_NT_TARGET_VERSION) < 0x600 && $(_NT_TOOLS_VERSION) >= 0x700
TARGETLIBS=$(TARGETLIBS) $(DDK_LIB_PATH)\sehupd.lib
!    endif
!endif
