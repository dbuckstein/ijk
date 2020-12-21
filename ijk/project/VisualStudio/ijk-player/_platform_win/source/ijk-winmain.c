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
	ui64 resource = -1;

	ptr app[1] = { 0 };
	ijkConsole console[1] = { 0 };
	ijkWindowPlatform platformInfo[1] = { 0 };
	ijkWindowInfo windowInfo[1] = { 0 };
	ijkRendererInfo renderInfo[1] = { 0 };
	ijkWindow window[1] = { 0 };

	i16 const pos_x = 0, pos_y = 0;
	ui16 const sz_x = 1024, sz_y = 768;
	ijkWindowControl const winCtrl = (
		ijkWinCtrl_F1_info | ijkWinCtrl_F2_load | ijkWinCtrl_F3_reload | ijkWinCtrl_F4_unload |
		ijkWinCtrl_F5_debug | ijkWinCtrl_F6_build | ijkWinCtrl_F7_rebuild | ijkWinCtrl_F8_fullscr |
		ijkWinCtrl_F9_user1 | ijkWinCtrl_F10_user2 | ijkWinCtrl_F11_user3 | ijkWinCtrl_F12_user4c |
		ijkWinCtrl_esc_cmd);// | ijkWinCtrl_hideCursor | ijkWinCtrl_lockCursor | ijkWinCtrl_drawInactive);
	
	status = ijkWindowPlatformPackResource(&resource, ID_ACCEL_F1, IDR_ACCEL, IDD_DIALOGBAR, IDI_ICON1, -1);

	status = ijkApplicationStartSingleInstanceSwitch(app, appName, &i);
	status = ijkConsoleCreateMain(console);
	status = ijkWindowPlatformCreate(platformInfo, hInstance, ijk_envstr_vsdevenv, ijk_envstr_slnpath, ijk_envstr_sdkdir, ijk_envstr_cfgdir, resource);
	status = ijkWindowInfoCreateDefault(windowInfo, platformInfo, infoName);
	status = ijkWindowCreate(window, windowInfo, platformInfo, renderInfo, appName, pos_x, pos_y, sz_x, sz_y, winCtrl);
	status = ijkWindowLoop(window);
	status = ijkWindowRelease(window);
	status = ijkWindowInfoRelease(windowInfo);
	status = ijkWindowPlatformRelease(platformInfo);
	status = ijkConsoleReleaseMain(console);
	status = ijkApplicationStopSingleInstance(app, &i);

	// the end
	return status;
}


//-----------------------------------------------------------------------------


#endif  // WINDOWS