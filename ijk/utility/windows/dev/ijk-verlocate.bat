:: ijk Version Directory Locator
:: By Daniel S. Buckstein
:: Highest alphanumeric directory is set as %ver% at the end of this program.
@echo off

set dir=%~1
set rt=%~2

::echo ENTER ijk-verlocate %dir% %rt%

for /d /r "%rt%" %%i in (%dir%*) do (
	if exist "%%i" (
		set ver=%%i
	)
)

::echo EXIT ijk-verlocate