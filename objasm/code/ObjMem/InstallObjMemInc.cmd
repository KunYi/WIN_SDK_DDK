@echo off
copy /y "%OBJASM_PATH%\Code\ObjMem\ObjMem.inc" "%OBJASM_PATH%\Code\Inc\ObjAsm\ObjMem.inc" > nul
if not [%RADASM_PATH%] == [] copy /y "%OBJASM_PATH%\Code\ObjMem\ObjMem.api" "%RADASM_PATH%\Masm\ObjMem.api" > nul
