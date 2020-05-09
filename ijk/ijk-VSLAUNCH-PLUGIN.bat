:: ijk Visual Studio Launcher (simplified plugin-only environment)
:: By Daniel S. Buckstein
@echo off
set ijk_sdk=%~dp0
call "%ijk_sdk%\utility\windows\dev\ijk-vslaunch-latest.bat" "ijk-plugin"
