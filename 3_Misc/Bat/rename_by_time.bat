@echo off
setlocal enabledelayedexpansion
dir /b/od
set /a count=0
pause > nul
for /f "delims=" %%i in ('dir /b/od *.*') do (
	if not "%%i" =="%~nx0" (
		set /a count+=1
		ren "%%i" "!count!%%~xi"
	)
)
pause > nul


