@echo off
setlocal EnableDelayedExpansion

if "where /q cl.exe" neq 0 (
	set __VSCMD_ARG_NO_LOGO=1
	for /f "tokens=*" %%i in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -latest -requires Microsoft.VisualStudio.Workload.NativeDesktop -property installationPath') do set VS=%%i
	if "!VS!" equ "" (
		echo ERROR: Visual Studio installation not found
		exit /b 1
	)
	call "!VS!\VC\Auxiliary\Build\vcvarsall.bat" amd64 || exit /b 1
)

set SRCS=src/args.c ^
	src/avra.c ^
	src/coff.c ^
	src/device.c ^
	src/directiv.c ^
	src/expr.c ^
	src/file.c ^
	src/macro.c ^
	src/map.c ^
	src/mnemonic.c ^
	src/parser.c ^
	src/stdextra.c

call cl /O2 /MT /nologo %SRCS% /link /out:avra.exe
del *.obj
