::Utility script to call build copy.
::By Daniel S. Buckstein
@echo off

set "calldir=%~dp0"
set "calllibpath=%1"
set "callbinpath=%2"
set "calllibname=%3"
set "callbinname=%4"
set "calldatapath=%5"

if not "%stopcopy%"=="YES" (
	call "%calldir%ijk-copy-build.bat" %calllibpath% %callbinpath% %calllibname% %callbinname% %calldatapath%
) else (
	echo ijk deferred copy build...
)
