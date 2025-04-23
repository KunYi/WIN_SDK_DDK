set CURRENT_DRIVE=%~d0

call start /B c:\dbgview.exe
for /l %%x in (1, 1, 3) do (
    c:\devcon install %CURRENT_DRIVE%\main.inf *mydriver
    c:\devcon remove %CURRENT_DRIVE%\main.inf *mydriver
)
