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

	ijkWindow_win.c
	Window management source for Windows.
*/

#include "ijk/ijk-platform/ijk-app/ijkWindow.h"
#if ijk_platform_is(WINDOWS)

// Windows / non-GNU-C
#include <Windows.h>
// Unix (Mac/Linux) / GNU-C
//#include <dlfcn.h>

#include "ijk/ijk-platform/ijk-app/_util/ijk-dylib.h"


//-----------------------------------------------------------------------------

typedef HINSTANCE ijkApplicationInstance_win;
typedef WNDCLASSEXA ijkWindowInfo_win;
typedef struct
{
	kcstr dir_build;
	kcstr dir_target;
	kcstr dir_sdk;
	kcstr tag_cfg;
} ijkWindowPlatform_win;


//-----------------------------------------------------------------------------

iret ijkWindowInfoCreateDefault(ijkWindowInfo* const windowInfo_out, ptr const applicationInst, tag const descriptorName, i32 const iconID)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowInfoRelease(ijkWindowInfo const windowInfo)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowPlatformCreate(ijkWindowPlatform* const platformInfo_out, tag const dev, tag const target, tag const sdk, tag const cfg)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowPlatformRelease(ijkWindowPlatform const platformInfo)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const windowInfo, ijkWindowPlatform const platformInfo, ijkRendererInfo const rendererInfo_opt, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowRelease(ijkWindow* const window)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowLoop(ijkWindow* const window)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowLoopThread(ptr* const thread_out, tag const threadName, ijkWindow* const window)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowLoopThreadStatus(ptr const thread)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowLoopThreadKill(ptr const thread)
{

	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS