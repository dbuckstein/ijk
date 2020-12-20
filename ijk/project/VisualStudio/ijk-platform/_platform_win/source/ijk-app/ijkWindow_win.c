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

#include <stdio.h>
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
	kcstr dir_build;					// Development and build environment.
	kcstr dir_target;					// Framework solution/workspace as build target.
	kcstr dir_sdk;						// Framework SDK directory.
	kcstr tag_cfg;						// Framework configuration.

	// Other important data.
	///
	i32 appWinCt;						// Application window count.
	ui64 appRes;						// Application packed resource info.
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

void ijkWindowInternalProcessF1(ijkWindow* window)
{
	byte buffer[1024] = { 0 }, * bufferPtr = buffer;
	byte const* const info[] = {
		"ijk Player Application: About",
		"ijk: an open-source, cross-platform, light-weight, ",
		"    c-based rendering framework",
		"Copyright 2020 Daniel S.Buckstein",
	};
	bufferPtr += sprintf(bufferPtr, "%s\n%s\n%s", info[1], info[2], info[3]);

	// print renderer info
	bufferPtr += sprintf(bufferPtr, "\n\n");
	if (window->winRender)
	{
		bufferPtr += sprintf(bufferPtr, "Current render context: ");

		// ****TO-DO
		/*
		// e.g. for OpenGL: 
		kptag* const versionStr = glGetString(GL_VERSION);
		kptag* const shadingStr = glGetString(GL_SHADING_LANGUAGE_VERSION);
		kptag* const rendererStr = glGetString(GL_RENDERER);
		kptag* const vendorStr = glGetString(GL_VENDOR);
		*/
	}
	else
		bufferPtr += sprintf(bufferPtr, "No render context initialized.");

	// print plugin info
	bufferPtr += sprintf(bufferPtr, "\n\n");
	if (window->plugin->handle)
	{
		bufferPtr += sprintf(bufferPtr, "Current plugin: ");

		// ****TO-DO
		/*
		// example:
		// name, author, description
		*/
	}
	else
		bufferPtr += sprintf(bufferPtr, "No plugin initialized.");

	// present message box
	MessageBoxA(window->windowData, buffer, *info, (MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND));
}

void ijkWindowInternalProcessF2(ijkWindow* window)
{
	// ****TO-DO
	// display load plugin menu

}

void ijkWindowInternalProcessF3(ijkWindow* window)
{
	// ****TO-DO
	// reload plugin

}

void ijkWindowInternalProcessF4(ijkWindow* window)
{
	// ****TO-DO
	// unload plugin

}

void ijkWindowInternalProcessF5(ijkWindow* window)
{
	// ****TO-DO
	// debug plugin

}

void ijkWindowInternalProcessF6(ijkWindow* window)
{
	// ****TO-DO
	// hot-build-and-load plugin

}

void ijkWindowInternalProcessF7(ijkWindow* window)
{
	// ****TO-DO
	// hot-rebuild-and-load plugin

}

void ijkWindowInternalProcessF8(ijkWindow* window)
{
	// ****TO-DO
	// toggle full-screen

}

void ijkWindowInternalProcessEsc(ijkWindow* window)
{
	byte buffer[80] = { 0 };
	HWND const console = GetConsoleWindow();
	if (GetStdHandle(STD_INPUT_HANDLE) && console)
	{
		// if console exists, make it foreground and get command
		SetForegroundWindow(console);
		printf("\n___:...............................................................................;\nCMD:");
		fgets(buffer, szb(buffer), stdin);

		// pass command to plugin like a regular system command
		window->plugin->ijkPluginCallback_user4c(window->plugin->data, 1, (ptr*)(&buffer));
	}
}


//-----------------------------------------------------------------------------

// ijkWindowInternalEventProcess
//	Internal processor for window events.
LRESULT CALLBACK ijkWindowInternalEventProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// prototype for setting default callbacks
	iret ijkPluginInternalSetCallbackDefaults(ijkPlugin* const plugin);

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
		ijkPluginInternalSetCallbackDefaults(window->plugin);
	}	break;
		// window closed
	case WM_CLOSE: {
		// this will also recursively take down any menus the window has
		DestroyWindow(hWnd);
	}	break;
		// window destroyed
	case WM_DESTROY: {
		// unload plugin
		if (window->plugin->handle)
		{
			// ****TO-DO

			ijkPluginInternalSetCallbackDefaults(window->plugin);
			window->plugin->data = 0;
			window->plugin->handle = 0;
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
		if (ijk_isfailure(window->plugin->ijkPluginCallback_display(window->plugin->data)))
		{
			PAINTSTRUCT paint[1];
			RECT updateRect[1];
			GetUpdateRect(hWnd, updateRect, 0);
			FillRect(BeginPaint(hWnd, paint), updateRect, (HBRUSH)(COLOR_WINDOW));
			EndPaint(hWnd, paint);
		}
	}	break;
	//case WM_ERASEBKGND: {
	//	// return non-zero if processed invalidated portion of background
	//}	break;
	//case WM_HELP: {
	//	LPHELPINFO const help = (LPHELPINFO)HIWORD(lParam);
	//}	break;

		// menu or accelerator item
	case WM_COMMAND: {
		iret ijkWindowPlatformInternalUnpackControlBase(ui64 const resource);
		word const value = LOWORD(wParam);
		ui16 base = 0;
		info = (ijkWindowPlatform_win*)window->winPlat;
		base = (ui16)ijkWindowPlatformInternalUnpackControlBase(info->appRes);
		if ((value <= (base + 12)) && value >= base)
		{
			// accelerator table entry
			switch (value - base)
			{
			case 0: // F1: info dialog
				if (window->winCtrl & ijkWinCtrl_F1_info)
					ijkWindowInternalProcessF1(window);
				break;
			case 1: // F2: load plugin
				if (window->winCtrl & ijkWinCtrl_F2_load)
					ijkWindowInternalProcessF2(window);
				break;
			case 2: // F3: reload plugin
				if (window->winCtrl & ijkWinCtrl_F3_reload)
					ijkWindowInternalProcessF3(window);
				break;
			case 3: // F4: unload plugin
				if (window->winCtrl & ijkWinCtrl_F4_unload)
					ijkWindowInternalProcessF4(window);
				break;
			case 4: // F5: debug plugin
				if (window->winCtrl & ijkWinCtrl_F5_debug)
					ijkWindowInternalProcessF5(window);
				break;
			case 5: // F6: hot-build plugin
				if (window->winCtrl & ijkWinCtrl_F6_build)
					ijkWindowInternalProcessF6(window);
				break;
			case 6: // F7: hot-rebuild plugin
				if (window->winCtrl & ijkWinCtrl_F7_rebuild)
					ijkWindowInternalProcessF7(window);
				break;
			case 7: // F8: toggle full-screen
				if (window->winCtrl & ijkWinCtrl_F8_fullscr)
					ijkWindowInternalProcessF8(window);
				break;
			case 8: // F9: user 1
				if (window->winCtrl & ijkWinCtrl_F9_user1)
					window->plugin->ijkPluginCallback_user1(window->plugin->data);
				break;
			case 9: // F10: user 2
				if (window->winCtrl & ijkWinCtrl_F10_user2)
					window->plugin->ijkPluginCallback_user2(window->plugin->data);
				break;
			case 10: // F11: user 3
				if (window->winCtrl & ijkWinCtrl_F11_user3)
					window->plugin->ijkPluginCallback_user3(window->plugin->data);
				break;
			case 11: // F12: user 4
				if (window->winCtrl & ijkWinCtrl_F12_user4c)
					window->plugin->ijkPluginCallback_user4c(window->plugin->data, 0, 0);
				break;
			case 12: // ESC: command
				if (window->winCtrl & ijkWinCtrl_esc_cmd)
					ijkWindowInternalProcessEsc(window);
				break;
			}
		}
	}	break;

		// window changes activation state
	case WM_ACTIVATE: {
		word const value = LOWORD(wParam);
		switch (value)
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

iret ijkWindowPlatformCreate(ijkWindowPlatform* const platformInfo_out, kptr const applicationInst, tag const dev, tag const target, tag const sdk, tag const cfg, ui64 const applicationRes)
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
	iret ijkWindowPlatformInternalUnpackIconID(ui64 const resource);
	iret ijkWindowPlatformInternalUnpackCursorID(ui64 const resource);

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
	iret ijkWindowPlatformInternalUnpackControlBase(ui64 const resource);
	iret ijkWindowPlatformInternalUnpackControlID(ui64 const resource);

	// validate
	if (window && window->windowData)
	{
		// platform info
		ijkWindowPlatform_win const* const info = (ijkWindowPlatform_win*)window->winPlat;
		ui16 const accelBase = (ui16)ijkWindowPlatformInternalUnpackControlBase(info->appRes);
		i8 const accelID = (i8)ijkWindowPlatformInternalUnpackControlID(info->appRes);

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
				result = window->plugin->ijkPluginCallback_idle(window->plugin->data);

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
					if (ijk_flagch(window->winCtrl, ijkWinCtrl_esc_cmd))
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