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
typedef struct ijkWindowPlatform_win_tag
{
	// Important paths and strings.
	///
	kcstr dir_build;	// Development and build environment.
	kcstr dir_target;	// Framework solution/workspace as build target.
	kcstr dir_sdk;		// Framework SDK directory.
	kcstr tag_cfg;		// Framework configuration.

	// Other important data.
	///
	i32 appWinCt;						// Application window count.
	i32 appRes;							// Application resource.
	ijkAppInst_win appInst;				// Application instance.
} ijkWindowPlatform_win;

// ijkPlatformData_win
//	Windows-specific platform data descriptor for window.
typedef struct ijkPlatformData_win_tag
{
	TRACKMOUSEEVENT mouseTracker[1];	// Mouse tracker inside and outside window.
	byte keyboardTracker[128];			// Keyboard tracker for character keys.
	HDC deviceContext;					// Window device context.
} ijkPlatformData_win;


//-----------------------------------------------------------------------------

// ijkWindowInternalEventProcess
//	Internal processor for window events.
LRESULT CALLBACK ijkWindowInternalEventProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// prototype for setting default callbacks
	iret ijkWindowInternalSetCallbackDefaults(ijkWindow* const window);

	// get user data
	ijkWindow* window = (ijkWindow*)GetWindowLongPtrA(hWnd, GWLP_USERDATA);
	ijkPlatformData_win* platformData;
	ijkWindowPlatform_win* info;

	// process message
	switch (message)
	{
		// window initial creation
	case WM_NCCREATE: {
		platformData = (ijkPlatformData_win*)malloc(sizeof(ijkPlatformData_win));
		if (platformData)
		{
			memset(platformData, 0, sizeof(*platformData));
			platformData->mouseTracker->cbSize = sizeof(platformData->mouseTracker);
			platformData->mouseTracker->dwFlags = (TME_LEAVE | TME_HOVER | TME_NONCLIENT);
			platformData->mouseTracker->dwHoverTime = 0;
			platformData->mouseTracker->hwndTrack = hWnd;
			platformData->deviceContext = GetDC(hWnd);

			window = (ijkWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
			window->platformData = platformData;
			window->windowData = hWnd;

			info = (ijkWindowPlatform_win*)window->winPlat;
			++info->appWinCt;

			// set modified user data
			SetWindowLongPtrA(hWnd, GWLP_USERDATA, (LONG_PTR)window);
		}
	}	break;
		// window finishing creation
	case WM_CREATE: {
		// set up rendering
		if (window->winRender)
		{
			// ****TO-DO

		}
		// set up non-rendering
		else
		{
			// ****TO-DO

		}

		// reset callbacks
		ijkWindowInternalSetCallbackDefaults(window);
	}	break;
		// window closed
	case WM_CLOSE: {
		// this will also recursively take down any menus the window has
		DestroyWindow(hWnd);
	}	break;
		// window destroyed
	case WM_DESTROY: {
		// unload plugin
		if (window->pluginHandle)
		{
			// ****TO-DO

			ijkWindowInternalSetCallbackDefaults(window);
			window->pluginData = 0;
			window->pluginHandle = 0;
		}

		// clean up rendering
		if (window->winRender)
		{
			// ****TO-DO

			window->winRender = 0;
		}

		// clean up data
		if (window->platformData)
		{
			platformData = (ijkPlatformData_win*)window->platformData;
			ReleaseDC(hWnd, platformData->deviceContext);
			free(platformData);
			window->platformData = 0;
		}

		// reset general data
		info = (ijkWindowPlatform_win*)window->winPlat;
		window->windowData = 0;
		window->winPlat = 0;

		// check if all windows are closed
		--info->appWinCt;
		if (info->appWinCt <= 0)
		{
			PostQuitMessage(ijk_success);
		}
	}	break;
	case WM_PAINT: {
		if (ijk_isfailure(window->callback_display(window->pluginData)))
		{
			PAINTSTRUCT paint[1];
			RECT updateRect[1];
			GetUpdateRect(hWnd, updateRect, 0);
			FillRect(BeginPaint(hWnd, paint), updateRect, (HBRUSH)(COLOR_WINDOW));
			EndPaint(hWnd, paint);
		}
	}	break;
	//case WM_ERASEBKGND:
	//	break;

		// menu or accelerator item
	case WM_COMMAND: {
		switch (LOWORD(wParam))
		{
		}
	}	break;

		// window changes activation state
	case WM_ACTIVATE: {
		switch (LOWORD(wParam))
		{
		case WA_ACTIVE:
		case WA_CLICKACTIVE:
			break;
		case WA_INACTIVE:
			break;
		}
	}	break;
		// window moves
	case WM_MOVE:
		break;
		// window is resized
	case WM_SIZE:
		break;

		// any virtual key
	case WM_KEYDOWN:
		break;
		// character keys, no up call
	case WM_CHAR:
		break;
		// release for keyPress, need to figure out if character is released
	case WM_KEYUP:
		break;

		// left mouse pressed
	case WM_LBUTTONDOWN:
		break;
		// middle button pressed
	case WM_MBUTTONDOWN:
		break;
		// right button pressed
	case WM_RBUTTONDOWN:
		break;
		// other button pressed
	case WM_XBUTTONDOWN:
		break;
		// left mouse double-clicked
	case WM_LBUTTONDBLCLK:
		break;
		// middle button double-clicked
	case WM_MBUTTONDBLCLK:
		break;
		// right button double-clicked
	case WM_RBUTTONDBLCLK:
		break;
		// other button double-clicked
	case WM_XBUTTONDBLCLK:
		break;
		// left mouse released
	case WM_LBUTTONUP:
		break;
		// middle button released
	case WM_MBUTTONUP:
		break;
		// right button released
	case WM_RBUTTONUP:
		break;
		// other button released
	case WM_XBUTTONUP:
		break;
		// mouse wheel scrolled
	case WM_MOUSEWHEEL:
		break;
		// mouse moved
	case WM_MOUSEMOVE:
		break;
		// mouse left
	case WM_MOUSELEAVE:
		break;
		// mouse hovers (used to track enter)
	case WM_MOUSEHOVER:
		break;
		// mouse click activates
	case WM_MOUSEACTIVATE:
		break;

	default:
		break;
	}
	return DefWindowProcA(hWnd, message, wParam, lParam);
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
			platformInfo->appWinCt = 0;
			platformInfo->appRes = applicationRes;
			platformInfo->appInst = (ijkAppInst_win)applicationInst;
			
			// done
			*platformInfo_out = platformInfo;
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

		// done
		*platformInfo = 0;
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
			LPSTR const iconStr = (iconID >= 0 ? MAKEINTRESOURCEA(iconID) : MAKEINTRESOURCEA(32517));
			LPSTR const cursorStr = (cursorID >= 0 ? MAKEINTRESOURCEA(cursorID) : MAKEINTRESOURCEA(32512));

			// fill in properties
			windowInfo->cbSize = (ui32)sz;
			windowInfo->style = (CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS);
			windowInfo->lpfnWndProc = ijkWindowInternalEventProcess;
			windowInfo->cbClsExtra = 0;
			windowInfo->cbWndExtra = (i32)szaddr;
			windowInfo->hInstance = info->appInst;
			windowInfo->hIcon = LoadIconA(windowInfo->hInstance, iconStr); // IDI_WINLOGO = 32517
			windowInfo->hCursor = LoadCursorA(NULL, cursorStr); // IDC_ARROW = 32512
			windowInfo->hbrBackground = 0;
			windowInfo->lpszMenuName = 0;
			windowInfo->lpszClassName = descriptorName;
			windowInfo->hIconSm = windowInfo->hIcon;

			// register
			if (RegisterClassExA(windowInfo))
			{
				// done
				*windowInfo_out = windowInfo;
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

			// done
			*windowInfo = 0;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const* const windowInfo, ijkWindowPlatform const* const platformInfo, ijkRendererInfo const* const rendererInfo_opt, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl)
{
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
		ijkWindowPlatform_win* const plat = *platformInfo;
		ijkRendererInfo* const render = (rendererInfo_opt ? *rendererInfo_opt : 0);

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
		window_out->winPlat = plat;
		window_out->winRender = render;
		window_out->winCtrl = windowCtrl;

		// attempt to make a window
		// 'window_out->window' is set through window process callback
		handle = CreateWindowExA(
			styleEx, info->lpszClassName, windowName, style,
			0, 0, (displayArea.right - displayArea.left), (displayArea.bottom - displayArea.top),
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
			return ijk_success;
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
		ijkWindowPlatform_win const* const info = (ijkWindowPlatform_win*)window->winPlat;
		i8 const accelID = (i8)ijkWindowPlatformInternalUnpackControl(info->appRes);

		// load accelerator table
		HACCEL hAccel = (accelID >= 0 ? LoadAcceleratorsA(info->appInst, MAKEINTRESOURCEA(accelID)) : 0);

		// window
		HWND handle = (HWND)window->windowData;

		// message
		MSG msg[1] = { 0 };

		// result
		iret result = 0;

		// while quit message has not been posted
		while (msg->message != WM_QUIT)
		{
			// check for message
			if (PeekMessageA(msg, NULL, 0, 0, PM_REMOVE))
			{
				// check for accelerator key
				if (!TranslateAcceleratorA(handle, hAccel, msg))
				{
					TranslateMessage(msg);
					DispatchMessageA(msg);
				}
			}

			// if no message, idle
			else
			{
				// idle callback
				result = window->callback_idle(window->pluginData);

				// if the result is positive, plugin threw a flag or warning
				// if rendering, this should mean that a frame was rendered
				if (ijk_iswarning(result))
				{
					//ijkRendererInfo_win* const info = *window->winRender;
					//if (ijkRenderContextIsCurrent(info->renderContext))
					//{
					//	// swap buffers
					//	SwapBuffers(info->deviceContext);
					//}
				}

				// if the result is negative, plugin threw a failure code
				// standalone window should close the window, which also unloads
				else if (ijk_isfailure(result))
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

				// if result is zero, plugin idle succeeded, nothing happened
				// ...carry on
			}
		}

		// done
		DestroyAcceleratorTable(hAccel);
		result = (iret)msg->wParam;
		return result;
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