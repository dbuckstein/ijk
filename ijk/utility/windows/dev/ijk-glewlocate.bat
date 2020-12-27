:: ijk GLEW Locator (internal, locate OpenGL Extension Wrangler)
:: By Daniel S. Buckstein
@echo off
call "ijk-verlocate" "glew" "C:\GLEW"
if not "%ver%"=="" (
	::echo %ver%
	setx GLEW_PATH %ver%
	echo ijk-glewlocate succeeded
) else (
	echo ijk-glewlocate failed
)
