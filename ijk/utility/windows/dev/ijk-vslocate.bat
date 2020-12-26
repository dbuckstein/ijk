:: ijk Visual Studio Version Locator (internal, locate Visual Studio)
:: By Daniel S. Buckstein
@echo off

::echo ENTER ijk-vslocate

::help from <https://github.com/Microsoft/vswhere>

:: remove -latest to enumerate versions
:: -requires Microsoft.Component.MSBuild for msbuild
:: msbuild path: MSBuild\**\msbuild.exe
set "vswhere=C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq tokens=*" %%i in (`"%vswhere%" -latest -find Common7\IDE\**\devenv.com`) do (
	set "ijk_vsdevenv=%%i"
)
set "vswhere="

::echo EXIT ijk-vslocate