# Microsoft Developer Studio Project File - Name="ATIXBar" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=ATIXBar - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "atixbar.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atixbar.mak" CFG="ATIXBar - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ATIXBar - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "ATIXBar - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "ATIXBar - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Cmd_Line "NMAKE /f Makefile"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "Makefile.exe"
# PROP BASE Bsc_Name "Makefile.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Cmd_Line "NMAKE /f Makefile"
# PROP Rebuild_Opt "/a"
# PROP Target_File "ATIXBar.exe"
# PROP Bsc_Name "debug\ATIXBar.bsc"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "ATIXBar - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Cmd_Line "NMAKE /f Makefile"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "Makefile.exe"
# PROP BASE Bsc_Name "Makefile.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Cmd_Line "NMAKE /f Makefile"
# PROP Rebuild_Opt "/a"
# PROP Target_File "ATIXBar.exe"
# PROP Bsc_Name "debug\ATIXBar.bsc"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "ATIXBar - Win32 Release"
# Name "ATIXBar - Win32 Debug"

!IF  "$(CFG)" == "ATIXBar - Win32 Release"

!ELSEIF  "$(CFG)" == "ATIXBar - Win32 Debug"

!ENDIF 

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\..\ATIShare\aticonfg.cpp
# End Source File
# Begin Source File

SOURCE=.\ATIXBAR.cpp
# End Source File
# Begin Source File

SOURCE=..\..\ATIShare\i2script.cpp
# End Source File
# Begin Source File

SOURCE=.\Makefile
# End Source File
# Begin Source File

SOURCE=..\..\ATIShare\Registry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\ATIShare\Wdmshare.cpp
# End Source File
# Begin Source File

SOURCE=.\WDMXBar.cpp
# End Source File
# Begin Source File

SOURCE=.\xbarprop.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=..\..\ATIShare\aticonfg.h
# End Source File
# Begin Source File

SOURCE=..\..\ATIShare\i2script.h
# End Source File
# Begin Source File

SOURCE=.\Wdmxbar.h
# End Source File
# End Group
# End Target
# End Project
