::Utility script to copy build files.
::By Daniel S. Buckstein
@echo off

set "libpath=%1"
set "binpath=%2"
set "libname=%3"
set "binname=%4"
set "datapath=%5"

:: create output directory in case it does not exist yet
:: write to dummy file and perform copy
:: also create asset data directory
cd "%ijk_sdk%"
mkdir %binpath%
mkdir %datapath%
set dstfile="%~2\%~4"
@echo ijk_sdk>%dstfile%
call ".\utility\windows\dev\ijk-copy.bat" %libpath% %binpath% %libname% %binname%
