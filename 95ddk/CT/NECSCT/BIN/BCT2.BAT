@REM This batch file is called by BCT.bat to run the BCT
if NOT (%3)==(gumby) goto INVOKEERR
cd %1\hctlogs
if not (%5)==() goto NetworkInstall
WINHCT.EXE /I %1\hctlogs\winbct.ini
goto end            

:NetworkInstall
if exist %2\%4\ct\COMMON\CTSHELL\WINHCT.EXE goto DrivePresent
	net use %2 %3 /y 
if exist %2\%4\ct\COMMON\CTSHELL\WINHCT.EXE goto DrivePresent
:DriveNotPresent 
echo Please Make sure the BCT is present in drive %2 %5  
pause
goto end
:DrivePresent
%2\%4\ct\COMMON\CTSHELL\WINHCT.EXE /I %1\hctlogs\winbct.ini
goto end

:INVOKEERR
echo 
echo ********************************************************
echo This batch file should not be called directly, use bct.bat
pause
echo 
echo ********************************************************
goto end



:end