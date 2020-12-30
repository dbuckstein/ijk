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

#include "ijk/ijk-platform/ijk-app/ijkWindow.h"

#if ijk_platform_is(WINDOWS)

#include "../../ijk-player.rc.h"


//-----------------------------------------------------------------------------
// application entry point

iret __stdcall WinMain(
	kptr const		hInstance,
	kptr const		hPrevInstance,
	kcstr const		lpCmdLine,
	i32 const		nCmdShow)
{
	iret ijkPlayerMain(ijkWindowPlatform* const platformInfo);

	iret status = -1;
	ui64 resource = -1;
	ijkWindowPlatform platformInfo[1] = { 0 };

	// create platform and run common main
	status = ijkWindowPlatformPackResource(&resource, ID_ACCEL_F1, IDR_ACCEL, IDD_DIALOGBAR, IDI_ICON1, -1);
	status = ijkWindowPlatformCreate(platformInfo, hInstance, ijk_envstr_vsdevenv, ijk_envstr_slnpath, ijk_envstr_sdkdir, ijk_envstr_cfgdir, resource);
	status = ijkPlayerMain(platformInfo);
	status = ijkWindowPlatformRelease(platformInfo);

	// the end
	return status;
}


//-----------------------------------------------------------------------------


#endif  // WINDOWS