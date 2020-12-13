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
	// Important paths and strings.
	///
	kcstr dir_build;	// Development and build environment.
	kcstr dir_target;	// Framework solution/workspace as build target.
	kcstr dir_sdk;		// Framework SDK directory.
	kcstr tag_cfg;		// Framework configuration.

	// Other important data.
	///
	i32 appRes;							// Application resource.
	ijkAppInst_win appInst;				// Application instance.
	TRACKMOUSEEVENT mouseTracker[1];	// Mouse tracker inside and outside window.
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

iret ijkWindowPlatformCreate(ijkWindowPlatform* const platformInfo_out, kptr const applicationInst, tag const dev, tag const target, tag const sdk, tag const cfg, i32 const applicationRes)
{
	if (platformInfo_out && !*platformInfo_out && applicationInst && dev && *dev && target && *target && sdk && *sdk && cfg && *cfg)
	{
		ijkWindowPlatform_win* const platformInfo = malloc(sizeof(ijkWindowPlatform_win));
		if (platformInfo)
		{
			platformInfo->dir_build = dev;
			platformInfo->dir_target = target;
			platformInfo->dir_sdk = sdk;
			platformInfo->tag_cfg = cfg;

			platformInfo->appRes = applicationRes;
			platformInfo->appInst = (ijkAppInst_win)applicationInst;
			memset(platformInfo->mouseTracker, 0, sizeof(platformInfo->mouseTracker));
			
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


iret ijkWindowInfoCreateDefault(ijkWindowInfo* const windowInfo_out, ijkWindowPlatform const* const platformInfo, tag const descriptorName)
{
	// get info
	iret ijkWindowPlatformInternalUnpackIconID(iret const resource);
	iret ijkWindowPlatformInternalUnpackCursorID(iret const resource);

	// validate
	if (windowInfo_out && !*windowInfo_out && platformInfo && *platformInfo && descriptorName && *descriptorName)
	{
		size const sz = sizeof(ijkWindowInfo_win);
		ijkWindowInfo_win* const windowInfo = malloc(sz);
		if (windowInfo)
		{
			ijkWindowPlatform_win const* const info = *platformInfo;
			i8 const iconID = (i8)ijkWindowPlatformInternalUnpackIconID(info->appRes);
			i8 const cursorID = (i8)ijkWindowPlatformInternalUnpackCursorID(info->appRes);

			// fill in properties
			windowInfo->cbSize = (ui32)sz;
			windowInfo->style = (CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS);
			windowInfo->lpfnWndProc = ijkWindowInternalEventProcess;
			windowInfo->cbClsExtra = 0;
			windowInfo->cbWndExtra = (i32)szaddr;
			windowInfo->hInstance = info->appInst;
			windowInfo->hIcon = LoadIconA(windowInfo->hInstance, (iconID >= 0 ? MAKEINTRESOURCEA(iconID) : MAKEINTRESOURCEA(32517))); // IDI_WINLOGO = 32517
			windowInfo->hCursor = LoadCursorA(windowInfo->hInstance, (cursorID >= 0 ? MAKEINTRESOURCEA(cursorID) : MAKEINTRESOURCEA(32512))); // IDC_ARROW = 32512
			windowInfo->hbrBackground = 0;
			windowInfo->lpszMenuName = 0;
			windowInfo->lpszClassName = descriptorName;
			windowInfo->hIconSm = windowInfo->hIcon;

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


iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const* const windowInfo, ijkWindowPlatform const* const platformInfo, ijkRendererInfo const* const rendererInfo_opt, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl)
{
	// prototype for setting default callbacks
	iret ijkWindowInternalSetCallbackDefaults(ijkWindow* const window);

	// validate
	if (window_out && !window_out->windowData && windowInfo && *windowInfo && platformInfo && *platformInfo && windowName && *windowName)
	{
		ibool const fullScreen = ijk_flagch(windowCtrl, ijkWinCtrl_fullscr_start);
		ibool const hideCursor = ijk_flagch(windowCtrl, ijkWinCtrl_hideCursor);
		ibool const lockCursor = ijk_flagch(windowCtrl, ijkWinCtrl_lockCursor);
		ibool const showWindow = SW_SHOW;
		
		HWND parent = 0;
		HWND handle = 0;
		RECT displayArea = { 0 };
		dword style = (WS_CLIPCHILDREN | WS_CLIPSIBLINGS), styleEx = 0;

		ijkWindowInfo_win const* const info = *windowInfo;

		// set display area as child of another window
		if (parent)
		{
			displayArea.left = (i16)windowPos_x;
			displayArea.top = (i16)windowPos_y;
			displayArea.right = displayArea.left + windowSize_x;
			displayArea.bottom = displayArea.top + windowSize_y;
			style |= WS_CHILD | WS_VISIBLE;
		}
		// set display area for full-screen
		else if (fullScreen)
		{
			GetWindowRect(GetDesktopWindow(), &displayArea);
			styleEx |= WS_EX_APPWINDOW;
			style |= WS_POPUP;
			AdjustWindowRectEx(&displayArea, style, ijk_false, styleEx);
		}
		// set display area for windowed
		else
		{
			displayArea.left = (i16)windowPos_x;
			displayArea.top = (i16)windowPos_y;
			displayArea.right = displayArea.left + windowSize_x;
			displayArea.bottom = displayArea.top + windowSize_y;
			styleEx |= WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
			style |= WS_OVERLAPPEDWINDOW;
			AdjustWindowRectEx(&displayArea, style, ijk_false, styleEx);
		}

		// set data
		window_out->winPlat = platformInfo;
		window_out->winRender = rendererInfo_opt;
		window_out->winCtrl = windowCtrl;
		ijkWindowInternalSetCallbackDefaults(window_out);

		// attempt to make a window
		// 'window_out->window' is set through window process callback
		handle = CreateWindowExA(
			styleEx, info->lpszClassName, windowName, style,
			displayArea.left, displayArea.top, (displayArea.right - displayArea.left), (displayArea.bottom - displayArea.top),
			parent, NULL, info->hInstance, window_out);

		// success
		if (handle)
		{
			if (lockCursor)
			{
				GetWindowRect(handle, &displayArea);
				ClipCursor(&displayArea);
			}
			ShowCursor(!hideCursor);
			ShowWindow(handle, showWindow);
			UpdateWindow(handle);

			// done
			return ijk_success;
		}

		// fail
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowRelease(ijkWindow* const window)
{
	// prototype for resetting
	iret ijkWindowInternalSetCallbackDefaults(ijkWindow* const window);

	// validate
	if (window && window->windowData)
	{
		// destroy window
		if (DestroyWindow((HWND)(window->windowData)))
		{
			// window properties should be set during destruction
			// just need to reset callbacks
			return ijkWindowInternalSetCallbackDefaults(window);
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowLoop(ijkWindow* const window)
{
	// unpacking utility
	iret ijkWindowPlatformInternalUnpackControl(iret const resource);

	// validate
	if (window && window->windowData)
	{
		// platform info
		ijkWindowPlatform_win const* const info = *((ijkWindowPlatform_win**)window->winPlat);
		i8 const accelID = (i8)ijkWindowPlatformInternalUnpackControl(info->appRes);

		// load accelerator table
		HACCEL hAccel = (accelID >= 0 ? LoadAcceleratorsA(info->appInst, MAKEINTRESOURCEA(accelID)) : 0);

		// window
		HWND handle = (HWND)window->windowData;

		// message
		MSG msg[1] = { 0 };

		// idle result
		iret idle;

		// while quit message has not been posted
		while (msg->message - WM_QUIT)
		{
			// check for accelerator key
			if (!TranslateAccelerator(handle, hAccel, msg))
			{
				TranslateMessage(msg);
				DispatchMessage(msg);
			}

			// check for other message
			//else if (PeekMessage(msg, NULL, 0, 0, PM_REMOVE))
			//{
			//	// if there is a message, process the message
			//	TranslateMessage(msg);
			//	DispatchMessage(msg);
			//}

			// if no message, idle
			else
			{
				idle = window->callback_idle(window->pluginData);

				// if the result is positive, idle is successful
				// if rendering, this should mean that a frame was rendered
				if (idle > 0)
				{
					//ijkRendererInfo_win* const info = *window->winRender;
					//if (ijkRenderContextIsCurrent(info->renderContext))
					//{
					//	// swap buffers
					//	SwapBuffers(info->deviceContext);
					//}
				}

				// if the result is negative, the demo should be unloaded
				// standalone window should close the window, which also unloads
				else if (idle < 0)
				{
					if (ijk_flagch(window->winCtrl, ijkWinCtrl_esc_quit))
					{
						// standalone mode, kill window
						//PostMessageA(handle, WM_CLOSE, 0, 0);
					}
					else
					{
						// exit demo
						//PostMessageA(handle, ID_ACCEL_ESC, 0, 0);
					}
				}

				// if result is zero, nothing happened
				// ...carry on
			}
		}

		// unload

		// done
		return (i32)msg->wParam;
	}
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