::Utility script to build project.
::By Daniel S. Buckstein
@echo off

set launchpath=%1
set buildproj=%2
set buildcfg=%3
set buildlog=%4
set buildsw=%~5
set stopcopy=%~6

call %launchpath% %buildproj% /%buildsw% %buildcfg% /Out %buildlog%
