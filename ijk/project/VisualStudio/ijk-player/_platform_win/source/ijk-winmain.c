/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*
	ijk: an open-source, cross-platform, light-weight,
		c-based rendering framework
	By Daniel S. Buckstein

	ijk-winmain.c
	Windows application entry point.
*/

#include "ijk/ijk-platform/ijk-platform.h"

#if ijk_platform_is(WINDOWS)

#include <stdio.h>
#include <stdlib.h>

#include "../../ijk-player.rc.h"


//-----------------------------------------------------------------------------
// application entry point

iret __stdcall wWinMain(
	kptr const		hInstance,
	kptr const		hPrevInstance,
	kwcstr const	lpCmdLine,
	i32 const		nCmdShow)
{
	ktag appName = "ijk Player Application";
	ktag infoName = "ijkPlayerApplicationInfo";
	iret status = -1;
	i32 i = -1;

	ptr app[1] = { 0 };
	ijkConsole console[1] = { 0 };
	ijkWindowInfo windowInfo[1] = { 0 };
	ijkWindowPlatform platformInfo[1] = { 0 };

	status = ijkApplicationStartSingleInstanceSwitch(app, appName, &i);
	status = ijkConsoleCreateMain(console);
	status = ijkWindowInfoCreateDefault(windowInfo, hInstance, infoName, IDI_ICON1);
	status = ijkWindowPlatformCreate(platformInfo, ijk_envstr_vsdevenv, ijk_envstr_slnpath, ijk_envstr_sdkdir, ijk_envstr_cfgdir);

	status = ijkWindowPlatformRelease(platformInfo);
	status = ijkWindowInfoRelease(windowInfo);
	status = ijkConsoleReleaseMain(console);
	status = ijkApplicationStopSingleInstance(app, &i);

	// the end
	return status;
}


//-----------------------------------------------------------------------------


#endif  // WINDOWS