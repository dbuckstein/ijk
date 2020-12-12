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

#include <stdlib.h>

#include "ijk/ijk-platform/ijk-app/_util/ijk-dylib.h"


//-----------------------------------------------------------------------------

// ijkApplicationInstance_win
//	Windows-specific application instance descriptor.
typedef HINSTANCE ijkAppInst_win;

// ijkApplicationInstance_win
//	Windows-specific window info descriptor.
typedef WNDCLASSEXA ijkWindowInfo_win;

// ijkWindowPlatform_win
//	Windows-specific platform info descriptor.
typedef struct
{
	kcstr dir_build;
	kcstr dir_target;
	kcstr dir_sdk;
	kcstr tag_cfg;
} ijkWindowPlatform_win;


//-----------------------------------------------------------------------------

// ijkWindowInternalEventProcess
//	Internal processor for window events.
LRESULT CALLBACK ijkWindowInternalEventProcess(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	default:
		break;
	}
	return DefWindowProcA(window, message, wParam, lParam);
}


//-----------------------------------------------------------------------------

iret ijkWindowInfoCreateDefault(ijkWindowInfo* const windowInfo_out, kptr const applicationInst, tag const descriptorName, i32 const iconID)
{
	if (windowInfo_out && !*windowInfo_out && applicationInst && descriptorName && *descriptorName)
	{
		size const sz = sizeof(ijkWindowInfo_win);
		ijkWindowInfo_win* windowInfo = malloc(sz);
		if (windowInfo)
		{
			// fill in properties
			windowInfo->cbSize = (ui32)sz;
			windowInfo->style = (CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS);
			windowInfo->lpfnWndProc = ijkWindowInternalEventProcess;
			windowInfo->cbClsExtra = 0;
			windowInfo->cbWndExtra = (i32)szaddr;
			windowInfo->hInstance = (ijkAppInst_win)applicationInst;
			windowInfo->hIcon = windowInfo->hIconSm = LoadIconA(windowInfo->hInstance, (iconID >= 0 ? MAKEINTRESOURCEA(iconID) : MAKEINTRESOURCEA(32517))); // IDI_WINLOGO = 32517
			windowInfo->hCursor = LoadCursorA(0, MAKEINTRESOURCEA(32512)); // IDC_ARROW = 32512
			windowInfo->hbrBackground = 0;
			windowInfo->lpszMenuName = 0;
			windowInfo->lpszClassName = descriptorName;

			// register
			if (RegisterClassExA(windowInfo))
			{
				// success, copy
				*windowInfo_out = windowInfo;

				// done
				return ijk_success;
			}

			// fail, release
			free(windowInfo);
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowInfoRelease(ijkWindowInfo* const windowInfo)
{
	if (windowInfo && *windowInfo)
	{
		ijkWindowInfo_win* const info = *windowInfo;
		if (UnregisterClassA(info->lpszClassName, info->hInstance))
		{
			// release and reset
			free(info);
			*windowInfo = 0;

			// done
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowPlatformCreate(ijkWindowPlatform* const platformInfo_out, tag const dev, tag const target, tag const sdk, tag const cfg)
{
	if (platformInfo_out && !*platformInfo_out && dev && *dev && target && *target && sdk && *sdk && cfg && *cfg)
	{
		ijkWindowPlatform_win* const platformInfo = malloc(sizeof(ijkWindowPlatform_win));
		if (platformInfo)
		{
			platformInfo->dir_build = dev;
			platformInfo->dir_target = target;
			platformInfo->dir_sdk = sdk;
			platformInfo->tag_cfg = cfg;
			*platformInfo_out = platformInfo;

			// done
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowPlatformRelease(ijkWindowPlatform* const platformInfo)
{
	if (platformInfo && *platformInfo)
	{
		// release and reset
		ijkWindowPlatform_win* const info = *platformInfo;
		free(info);
		*platformInfo = 0;

		// done
		return ijk_success;
	}
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


iret ijkWindowLoopThreadStatus(kptr* const thread)
{

	return ijk_fail_invalidparams;
}


iret ijkWindowLoopThreadKill(ptr* const thread)
{

	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS