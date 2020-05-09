:: ijk Visual Studio Launcher (internal, locate and launch latest version)
:: By Daniel S. Buckstein
@echo off

::echo ENTER ijk-vslaunch-latest

:: locate devenv
call "%~dp0/ijk-vslocate.bat"

set "tmp_sln=%~1"
set "tmp_slndir=%ijk_sdk%project\VisualStudio\_SLN\"
set "tmp_slnpath=%tmp_slndir%%tmp_sln%\%tmp_sln%.sln"

::echo ijk_vsdevenv: %ijk_vsdevenv%
::echo tmp_slnpath: %tmp_slnpath%
start "%ijk_vsdevenv%" "%tmp_slnpath%"

:: unset variables
set "tmp_slnpath="
set "tmp_slndir="
set "tmp_sln="

::echo EXIT ijk-vslaunch-latest