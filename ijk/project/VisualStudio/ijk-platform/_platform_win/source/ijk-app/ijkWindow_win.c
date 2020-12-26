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
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

#include "ijk/ijk-base/ijk-input/ijkInput.h"


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
	RECT originalWindowArea[1];			// Window area for toggling full-screen.
	BOOL mouseState;					// Mouse tracker for hovering.
	BOOL buildState;					// Build tracker for hot-build.
	HDC deviceContext;					// Window device context.
} ijkPlatformData_win;

// ijkWindowControlMessage
//	Message identifiers for handling window controls.
enum ijkWindowControlMessage
{
	ijkWinCtrlMsg = WM_USER,
	ijkWinCtrlMsg_load,
	ijkWinCtrlMsg_reload,
	ijkWinCtrlMsg_unload,
	ijkWinCtrlMsg_debug,
	ijkWinCtrlMsg_build,
	ijkWinCtrlMsg_rebuild,
	ijkWinCtrlMsg_cmd,
};


//-----------------------------------------------------------------------------

// ijkWindowInternalUnlockPDB
//	Release PDB.
iret ijkWindowInternalUnlockPDB(kptag const sdkDirStr, kptag const cfgDirStr, kptag const projName);

iret ijkWindowInternalBuild(ijkWindow* const window, ibool const rebuild)
{
	ijkPlatformData_win* const platform = (ijkPlatformData_win*)window->platformData;
	if (!platform->buildState)
	{
		platform->buildState = 1;

		// ****TO-DO
		// build

		platform->buildState = 0;
		return ijk_success;
	}
	return ijk_fail_operationfail;
}

iret ijkWindowInternalBuildThread(ijkWindow* const window)
{
	return ijkWindowInternalBuild(window, ijk_false);
}

iret ijkWindowInternalRebuildThread(ijkWindow* const window)
{
	return ijkWindowInternalBuild(window, ijk_true);
}

iret ijkWindowInternalCreateBuildWarning(ijkWindow* const window)
{
	ijkPlatformData_win* const platform = (ijkPlatformData_win*)window->platformData;
	if (platform->buildState)
	{
		ibool const hideCursor = (window->winCtrl & ijkWinCtrl_hideCursor);

		// reveal cursor
		if (hideCursor)
			ShowCursor(TRUE);

		// warning
		MessageBoxA(window->windowData, "Please wait for build operation to finish.", "ijk Player Application: Building", (MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND));

		// reveal cursor
		if (hideCursor)
			ShowCursor(TRUE);

		// done
		return ijk_failure;
	}
	return ijk_success;
}


//-----------------------------------------------------------------------------

LRESULT CALLBACK ijkWindowInternalEventProcessList(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	typedef struct ijkTagWindowDialog
	{
		HWND box, text;
		ijkPluginInfo* pluginInfo;
		size pluginInfoCount;
		ijkWindowControl winCtrl;
	} ijkWindowDialog;
	ijkWindowDialog* dlg = (ijkWindowDialog*)GetWindowLongPtrA(hDlg, GWLP_USERDATA);

	word const value = LOWORD(wParam), cmd = HIWORD(wParam);
	switch (message)
	{
	case WM_INITDIALOG: {
		HINSTANCE const inst = (HINSTANCE)GetWindowLongPtrA(hDlg, GWLP_HINSTANCE);
		ijkWindowControl const winCtrl = (ijkWindowControl)lParam;
		byte caption[256] = { 0 };
		RECT rect = { 0 };
		HWND box = 0, text = 0;
		ijkPluginInfo* pluginInfo = 0;
		size pluginInfoCount = 0, i = 0;
		i32 pos = -1;

		GetWindowTextA(hDlg, caption, szb(caption));
		switch (winCtrl)
		{
		case ijkWinCtrl_F2_load: {
			// relative path to plugin info resource
			kptag const IJK_PLUGIN_INFO_PATH = "../../../../resource/ijk-player/_util/ijk-plugin-info.txt";

			// load plugin data
			if (ijk_issuccess(ijkPluginInfoListLoad(&pluginInfo, &pluginInfoCount, IJK_PLUGIN_INFO_PATH)) && pluginInfoCount)
			{
				i32 w, h;

				// create plugin box
				strcat(caption, "Load Plugin");
				GetWindowRect(hDlg, &rect);
				box = CreateWindowExA(0, "LISTBOX", 0,
					(WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | LBS_NOTIFY),
					(8), (8), (w = (rect.right - rect.left - 304)), (h = (rect.bottom - rect.top - 96)),
					hDlg, 0, inst, NULL);
				SetFocus(box);

				// create info display box
				text = CreateWindowExA(0, "STATIC", 0,
					(WS_CHILD | WS_VISIBLE | SS_LEFT),
					(w + 16), (8), w, h,
					hDlg, 0, inst, NULL);
				SetWindowTextA(text, "Select plugin info to display.");

				// populate list
				for (i = 0; i < pluginInfoCount; ++i)
				{
					pos = (i32)SendMessageA(box, LB_ADDSTRING, 0, (LPARAM)pluginInfo[i].name);
					if (pos >= 0)
						SendMessageA(box, LB_SETITEMDATA, pos, (LPARAM)i);
				}
			}
			// if empty, display warning and close dialog before it appears
			else
			{
				MessageBoxA(hDlg, "No plugin information available.", "ijk Player Application: Load Plugin Failed", (MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND));
				EndDialog(hDlg, value);
				return TRUE;
			}
		}	break;
		case ijkWinCtrl_esc_cmd: {
			i32 w, h;

			// create command box
			strcat(caption, "Enter Command");
			GetWindowRect(hDlg, &rect);
			box = CreateWindowExA(0, "EDIT", 0,
				(WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_UPPERCASE | ES_WANTRETURN | ES_AUTOVSCROLL),
				(8), (8), (w = (rect.right - rect.left - 32)), (h = (rect.bottom - rect.top - 96)),
				hDlg, 0, inst, NULL);
			SetFocus(box);

			// create info display box
			text = CreateWindowExA(0, "STATIC", 0,
				(WS_CHILD | WS_VISIBLE | SS_LEFT),
				(8), (h + 24), 256, 16,
				hDlg, 0, inst, NULL);
			SetWindowTextA(text, "Enter command.");
		}	break;
		}
		dlg = (ijkWindowDialog*)malloc(szb(ijkWindowDialog));
		dlg->box = box;
		dlg->text = text;
		dlg->pluginInfo = pluginInfo;
		dlg->pluginInfoCount = pluginInfoCount;
		dlg->winCtrl = winCtrl;
		SetWindowTextA(hDlg, caption);
		SetWindowLongPtrA(hDlg, GWLP_USERDATA, (LONG_PTR)dlg);
		return TRUE;
	}
	case WM_CLOSE: {
		if (dlg->winCtrl == ijkWinCtrl_F2_load)
			ijkPluginInfoListRelease(&dlg->pluginInfo);
		free(dlg);
		EndDialog(hDlg, value);
		return TRUE;
	}
	case WM_COMMAND:
		switch (cmd)
		{
		case EN_CHANGE:
			if (dlg->winCtrl == ijkWinCtrl_esc_cmd)
			{
				// toggle OK button
				if (SendMessageA(dlg->box, WM_GETTEXTLENGTH, 0, 0))
				{
					EnableWindow(GetDlgItem(hDlg, IDOK), TRUE);
					SetWindowTextA(dlg->text, "Press OK to send command.");
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, IDOK), FALSE);
					SetWindowTextA(dlg->text, "Enter command.");
				}
				return TRUE;
			}
			break;
		case LBN_SELCHANGE:
		case LBN_DBLCLK:
			if (dlg->winCtrl == ijkWinCtrl_F2_load)
			{
				ijkPluginInfo const* info = 0;
				byte buf[512] = { 0 };
				i32 i = -1;

				// display info in text box
				i = (i32)SendMessageA(dlg->box, LB_GETCURSEL, 0, 0);
				if (i >= 0)
				{
					i = (i32)SendMessageA(dlg->box, LB_GETITEMDATA, i, 0);
					info = dlg->pluginInfo + i;
					sprintf(buf, "Press OK to load plugin: \n\n\"%s\" \n  By %s \n  Ver. %s \n%s \n",
						info->name, info->author, info->version, info->info);
					SetWindowTextA(dlg->text, buf);

					// enable OK button
					EnableWindow(GetDlgItem(hDlg, IDOK), TRUE);
				}
				return TRUE;
			}
			break;
		case LBN_SELCANCEL: {
			SetWindowTextA(dlg->text, "Select plugin info to display.");
		}	break;

		default:
			switch (value)
			{
			case IDOK: {
				//	send command to parent window
				HWND hWnd = GetParent(hDlg);
				switch (dlg->winCtrl)
				{
				case ijkWinCtrl_F2_load: {
					//	send info structure at selected index
					ijkPluginInfo const* info = 0;
					i32 i = (i32)SendMessageA(dlg->box, LB_GETCURSEL, 0, 0);
					if (i >= 0)
					{
						i = (i32)SendMessageA(dlg->box, LB_GETITEMDATA, i, 0);
						info = dlg->pluginInfo + i;
						SendMessageA(hWnd, ijkWinCtrlMsg_unload, 0, 0);
						SendMessageA(hWnd, ijkWinCtrlMsg_load, (WPARAM)i, (LPARAM)info);
					}
					else
					{
						MessageBoxA(hDlg, "Error: Invalid plugin info.", "ijk Player Application: Load Plugin Failed", (MB_OK | MB_ICONHAND | MB_SETFOREGROUND));
					}
				}	break;
				case ijkWinCtrl_esc_cmd: {
					//	send command string
					i32 const i = GetWindowTextLengthA(dlg->box), j = (i + 1);
					if (i > 0)
					{
						ptag buf = (ptag)malloc((size)j);
						buf[i] = 0;
						GetWindowTextA(dlg->box, buf, j);
						SendMessageA(hWnd, ijkWinCtrlMsg_cmd, (WPARAM)i, (LPARAM)buf);
						free(buf);
					}
				}	break;
				}
				// fall through to close
			}
			case IDCLOSE:
			case IDCANCEL:
				// exit dialog
				if (dlg->winCtrl == ijkWinCtrl_F2_load)
					ijkPluginInfoListRelease(&dlg->pluginInfo);
				free(dlg);
				EndDialog(hDlg, value);
				return TRUE;
			}
			break;
		}
	}
	return FALSE;
}


void ijkWindowInternalCreateInfo(ijkWindow* const window)
{
	ibool const hideCursor = (window->winCtrl & ijkWinCtrl_hideCursor);

	byte buffer[1024] = { 0 }, * bufferPtr = buffer;
	byte const* const info[] = {
		"ijk Player Application: About",
		"ijk: an open-source, cross-platform, light-weight, ",
		"    c-based rendering framework",
		"Copyright 2020 Daniel S.Buckstein",
	};
	bufferPtr += sprintf(bufferPtr, "%s\n%s\n%s\n\n", info[1], info[2], info[3]);

	// print renderer info
	if (window->winRender)
	{
		kptag const rendererName = "dummyName", rendererInfo = "dummyInfo";
		bufferPtr += sprintf(bufferPtr,
			"Current render context: %s \n %s\n\n",
			rendererName, rendererInfo);

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
		bufferPtr += sprintf(bufferPtr, "No render context initialized.\n\n");

	// print plugin info
	if (window->plugin->handle)
	{
		bufferPtr += sprintf(bufferPtr,
			"Plugin: \"%s\" \n  By: %s \n  Ver. %s \n%s \n\n",
			window->pluginInfo->name, window->pluginInfo->author,
			window->pluginInfo->version, window->pluginInfo->info);
	}
	else
		bufferPtr += sprintf(bufferPtr, "No plugin initialized.\n\n");

	// reveal cursor
	if (hideCursor)
		ShowCursor(TRUE);

	// present message box
	MessageBoxA(window->windowData, buffer, *info, (MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND));

	// hide cursor
	if (hideCursor)
		ShowCursor(FALSE);
}


void ijkWindowInternalCreateDialog(ijkWindow* const window, ijkWindowControl const purpose)
{
	iret ijkWindowPlatformInternalUnpackDialogID(ui64 const resource);

	ijkWindowPlatform_win* info = (ijkWindowPlatform_win*)window->winPlat;
	i8 const dialogID = (i8)ijkWindowPlatformInternalUnpackDialogID(info->appRes);
	ibool const hideCursor = (window->winCtrl & ijkWinCtrl_hideCursor);
	LPCSTR const dialogRes = MAKEINTRESOURCEA(dialogID);

	// reveal cursor
	if (hideCursor)
		ShowCursor(TRUE);

	// present dialog box
	DialogBoxParamA(info->appInst, dialogRes, window->windowData, ijkWindowInternalEventProcessList, (LPARAM)purpose);

	// hide cursor
	if (hideCursor)
		ShowCursor(FALSE);
}


void ijkWindowInternalLockCursor(ijkWindow* const window)
{
	if (window)
	{
		HWND const handle = window->windowData;
		POINT corners[2];
		RECT displayArea[1];

		// calculate corners in client space and lock
		GetClientRect(handle, displayArea);
		corners[0].x = displayArea->left;
		corners[0].y = displayArea->top;
		corners[1].x = displayArea->right;
		corners[1].y = displayArea->bottom;
		ClientToScreen(handle, corners + 0);
		ClientToScreen(handle, corners + 1);
		displayArea->left = corners[0].x;
		displayArea->top = corners[0].y;
		displayArea->right = corners[1].x;
		displayArea->bottom = corners[1].y;
		ClipCursor(displayArea);
	}
	else
	{
		ClipCursor(0);
	}
}


void ijkWindowInternalToggleFullscreen(ijkWindow* const window)
{
	RECT displayArea = { 0 };
	HWND hWnd = window->windowData;
	dword style = (dword)GetWindowLongPtrA(hWnd, GWL_STYLE), styleEx = (dword)GetWindowLongPtrA(hWnd, GWL_EXSTYLE);

	// full-screen if original display area is not all zeros
	ijkPlatformData_win* const info = (ijkPlatformData_win*)window->platformData;
	if (info->originalWindowArea->left | info->originalWindowArea->top | info->originalWindowArea->right | info->originalWindowArea->bottom)
	{
		// full-screen to windowed
		styleEx |= WS_EX_WINDOWEDGE;
		style |= WS_OVERLAPPEDWINDOW;
		displayArea = *info->originalWindowArea;
		memset(info->originalWindowArea, 0, szb(info->originalWindowArea));
	}
	else
	{
		// windowed to full-screen
		styleEx &= ~WS_EX_WINDOWEDGE;
		style &= ~WS_OVERLAPPEDWINDOW;
		GetClientRect(hWnd, info->originalWindowArea);
		GetWindowRect(GetDesktopWindow(), &displayArea);
	}

	// perform resize
	SetWindowLongPtrA(hWnd, GWL_EXSTYLE, styleEx);
	SetWindowLongPtrA(hWnd, GWL_STYLE, style);
	AdjustWindowRectEx(&displayArea, style, ijk_false, styleEx);
	MoveWindow(hWnd, 0, 0, (displayArea.right - displayArea.left), (displayArea.bottom - displayArea.top), TRUE);
}


//-----------------------------------------------------------------------------

// ijkWindowInternalEventProcess
//	Internal processor for window events.
LRESULT CALLBACK ijkWindowInternalEventProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// get user data
	ijkWindow* window = (ijkWindow*)GetWindowLongPtrA(hWnd, GWLP_USERDATA);
	ijkPlatformData_win* platformData;
	ijkWindowPlatform_win* info;

	// process message
	switch (message)
	{
		// window initial creation
	case WM_NCCREATE: {
		platformData = (ijkPlatformData_win*)malloc(szb(ijkPlatformData_win));
		if (platformData)
		{
			memset(platformData, 0, szb(*platformData));
			platformData->mouseTracker[0].hwndTrack = hWnd;
			platformData->mouseTracker[0].cbSize = szb(TRACKMOUSEEVENT);
			platformData->mouseTracker[0].dwFlags = (TME_LEAVE);
			platformData->deviceContext = GetDC(hWnd);

			window = (ijkWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
			window->platformData = platformData;
			window->windowData = hWnd;

			info = (ijkWindowPlatform_win*)window->winPlat;
			++info->appWinCt;

			// track mouse
			TrackMouseEvent(platformData->mouseTracker);

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

		// reset plugin and callbacks
		ijkPluginReset(window->plugin);
	}	break;
		// window closed
	case WM_CLOSE: {
		// this will also recursively take down any menus the window has
		DestroyWindow(hWnd);
	}	break;
		// window destroyed
	case WM_DESTROY: {
		// unload plugin
		window->plugin->ijkPluginCallback_willUnload(window->plugin->data);
		ijkPluginUnload(window->plugin, ijk_true);

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
			PostQuitMessage(ijk_success);
	}	break;
	case WM_PAINT: {
		PAINTSTRUCT paint[1];
		RECT updateRect[1];
		GetUpdateRect(hWnd, updateRect, 0);
		FillRect(BeginPaint(hWnd, paint), updateRect, (HBRUSH)(COLOR_WINDOW));
		EndPaint(hWnd, paint);
		window->plugin->ijkPluginCallback_display(window->plugin->data);
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
					ijkWindowInternalCreateInfo(window);
				break;
			case 1: // F2: load plugin dialog
				if (window->winCtrl & ijkWinCtrl_F2_load)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						ijkWindowInternalCreateDialog(window, ijkWinCtrl_F2_load);
				break;
			case 2: // F3: reload plugin
				if (window->winCtrl & ijkWinCtrl_F3_reload)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						SendMessageA(window->windowData, ijkWinCtrlMsg_reload, 0, 0);
				break;
			case 3: // F4: unload plugin
				if (window->winCtrl & ijkWinCtrl_F4_unload)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						SendMessageA(window->windowData, ijkWinCtrlMsg_unload, 0, 0);
				break;
			case 4: // F5: debug plugin
				if (window->winCtrl & ijkWinCtrl_F5_debug)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						SendMessageA(window->windowData, ijkWinCtrlMsg_debug, 0, 0);
				break;
			case 5: // F6: hot-build plugin
				if (window->winCtrl & ijkWinCtrl_F6_build)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						SendMessageA(window->windowData, ijkWinCtrlMsg_build, 0, 0);
				break;
			case 6: // F7: hot-rebuild plugin
				if (window->winCtrl & ijkWinCtrl_F7_rebuild)
					if (ijk_issuccess(ijkWindowInternalCreateBuildWarning(window)))
						SendMessageA(window->windowData, ijkWinCtrlMsg_rebuild, 0, 0);
				break;
			case 7: // F8: toggle full-screen
				if (window->winCtrl & ijkWinCtrl_F8_fullscr)
					ijkWindowInternalToggleFullscreen(window);
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
			case 12: // ESC: command dialog
				if (window->winCtrl & ijkWinCtrl_esc_cmd)
					ijkWindowInternalCreateDialog(window, ijkWinCtrl_esc_cmd);
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
			if (window->winCtrl & ijkWinCtrl_lockCursor)
				ijkWindowInternalLockCursor(window);
			if (window->winRender)
			{
				// ****TO-DO
				// enable context
			}
			window->plugin->ijkPluginCallback_winActivate(window->plugin->data);
			break;
		case WA_INACTIVE:
			window->plugin->ijkPluginCallback_winDeactivate(window->plugin->data);
			if (!(window->winCtrl & ijkWinCtrl_drawInactive) && window->winRender)
			{
				// ****TO-DO
				// disable context
			}
			if (window->winCtrl & ijkWinCtrl_lockCursor)
				ijkWindowInternalLockCursor(0);
			break;
		}
	}	break;
		// window moves
	case WM_MOVE: {
		// clip cursor
		if (window->winCtrl & ijkWinCtrl_lockCursor)
			ijkWindowInternalLockCursor(window);

		// callback
		window->pos_x = (i16)LOWORD(lParam);
		window->pos_y = (i16)HIWORD(lParam);
		window->plugin->ijkPluginCallback_winMove(window->plugin->data, window->pos_x, window->pos_y);
	}	break;
		// window is resized
	case WM_SIZE: {
		// clip cursor
		if (window->winCtrl & ijkWinCtrl_lockCursor)
			ijkWindowInternalLockCursor(window);

		// callback
		window->sz_x = (i16)LOWORD(lParam);
		window->sz_y = (i16)HIWORD(lParam);
		window->plugin->ijkPluginCallback_winResize(window->plugin->data, window->sz_x, window->sz_y);
	}	break;

		// any virtual key
	case WM_KEYDOWN: {
		ijkPluginCallback_pi const cb = (HIWORD(lParam) & KF_REPEAT) ? window->plugin->ijkPluginCallback_keyHoldVirt : window->plugin->ijkPluginCallback_keyPressVirt;
		i32 const key = (i32)LOWORD(wParam);
		cb(window->plugin->data, key);
	}	break;
		// character keys, no up call, track which character key
	case WM_CHAR: {
		ijkPluginCallback_pi const cb = (HIWORD(lParam) & KF_REPEAT) ? window->plugin->ijkPluginCallback_keyHoldAscii : window->plugin->ijkPluginCallback_keyPressAscii;
		i32 const key_a = (i32)LOWORD(wParam);
		cb(window->plugin->data, key_a);
	}	break;
		// release for keyPress, need to figure out if character is released
	case WM_KEYUP: {
		i32 const key = (i32)wParam, key_map = MapVirtualKeyA(key, MAPVK_VK_TO_CHAR), key_a = (i32)LOWORD(key_map);
		window->plugin->ijkPluginCallback_keyReleaseVirt(window->plugin->data, key);
		if (key_a)
			window->plugin->ijkPluginCallback_keyReleaseAscii(window->plugin->data, key_a);
	}	break;

		// left mouse pressed
	case WM_LBUTTONDOWN:
		window->plugin->ijkPluginCallback_mouseClick(window->plugin->data, ijkMouseBtn_left, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// middle button pressed
	case WM_MBUTTONDOWN:
		window->plugin->ijkPluginCallback_mouseClick(window->plugin->data, ijkMouseBtn_middle, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// right button pressed
	case WM_RBUTTONDOWN:
		window->plugin->ijkPluginCallback_mouseClick(window->plugin->data, ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// other button pressed
	case WM_XBUTTONDOWN:
		window->plugin->ijkPluginCallback_mouseClick(window->plugin->data, (i32)HIWORD(wParam) + ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// left mouse double-clicked
	case WM_LBUTTONDBLCLK:
		window->plugin->ijkPluginCallback_mouseClick2(window->plugin->data, ijkMouseBtn_left, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// middle button double-clicked
	case WM_MBUTTONDBLCLK:
		window->plugin->ijkPluginCallback_mouseClick2(window->plugin->data, ijkMouseBtn_middle, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// right button double-clicked
	case WM_RBUTTONDBLCLK:
		window->plugin->ijkPluginCallback_mouseClick2(window->plugin->data, ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// other button double-clicked
	case WM_XBUTTONDBLCLK:
		window->plugin->ijkPluginCallback_mouseClick2(window->plugin->data, (i32)HIWORD(wParam) + ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// left mouse released
	case WM_LBUTTONUP:
		window->plugin->ijkPluginCallback_mouseRelease(window->plugin->data, ijkMouseBtn_left, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// middle button released
	case WM_MBUTTONUP:
		window->plugin->ijkPluginCallback_mouseRelease(window->plugin->data, ijkMouseBtn_middle, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// right button released
	case WM_RBUTTONUP:
		window->plugin->ijkPluginCallback_mouseRelease(window->plugin->data, ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// other button released
	case WM_XBUTTONUP:
		window->plugin->ijkPluginCallback_mouseRelease(window->plugin->data, (i32)HIWORD(wParam) + ijkMouseBtn_right, (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// mouse wheel scrolled
	case WM_MOUSEWHEEL:
		window->plugin->ijkPluginCallback_mouseWheel(window->plugin->data, (i32)(GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA), (i32)LOWORD(lParam), (i32)HIWORD(lParam));
		break;
		// mouse moved
	case WM_MOUSEMOVE: {
		i32 const x = (i32)LOWORD(lParam), y = (i32)HIWORD(lParam);
		i32 const btn = (MK_LBUTTON | MK_MBUTTON | MK_RBUTTON | MK_XBUTTON1 | MK_XBUTTON2);
		ijkPluginCallback_pii const cb = (wParam & btn) ? window->plugin->ijkPluginCallback_mouseDrag : window->plugin->ijkPluginCallback_mouseMove;
		platformData = (ijkPlatformData_win*)window->platformData;
		if (!platformData->mouseState)
		{
			platformData->mouseState = ijk_true;
			window->plugin->ijkPluginCallback_mouseEnter(window->plugin->data, x, y);
		}
		cb(window->plugin->data, x, y);
		TrackMouseEvent(platformData->mouseTracker + 0);
	}	break;
		// mouse left
	case WM_MOUSELEAVE: {
		POINT pos;
		GetCursorPos(&pos);
		ScreenToClient(window->windowData, &pos);
		window->plugin->ijkPluginCallback_mouseLeave(window->plugin->data, pos.x, pos.y);
		platformData = (ijkPlatformData_win*)window->platformData;
		platformData->mouseState = ijk_false;
	}	break;
		// mouse hovers (used to track enter)
	//case WM_MOUSEHOVER:
	//	break;
		// mouse click activates
	//case WM_MOUSEACTIVATE:
	//	break;

		// window control events
	case ijkWinCtrlMsg_load: {
		// load plugin
		ijkPluginInfo const* info = (ijkPluginInfo*)lParam;
		i32 const pluginID = (i32)wParam;
		if (ijk_issuccess(ijkPluginLoad(window->plugin, info, pluginID)))
		{
			// copy info
			*window->pluginInfo = *info;
		}
	}	break;
	case ijkWinCtrlMsg_reload: {
		// reload plugin
		window->plugin->ijkPluginCallback_willReload(window->plugin->data);
		if (ijk_issuccess(ijkPluginReload(window->plugin, 0)))
		{
			// done
		}
	}	break;
	case ijkWinCtrlMsg_unload: {
		// unload plugin
		window->plugin->ijkPluginCallback_willUnload(window->plugin->data);
		if (ijk_issuccess(ijkPluginUnload(window->plugin, ijk_true)))
		{
			// repaint
			RECT rect;
			GetWindowRect(window->windowData, &rect);
			InvalidateRect(window->windowData, &rect, TRUE);
			UpdateWindow(window->windowData);
		}
	}	break;
	case ijkWinCtrlMsg_debug: {
		// unload current
		if (window->plugin->id >= 0)
			SendMessageA(hWnd, ijkWinCtrlMsg_unload, 0, 0);
		// load debug (default)
		ijkWindowLoadDefaultPlugin(window, 0, 0, (window->plugin->id == -2));
	}	break;
	case ijkWinCtrlMsg_build: {
		CreateThread(0, 0, ijkWindowInternalBuildThread, window, 0, 0);
	}	break;
	case ijkWinCtrlMsg_rebuild: {
		CreateThread(0, 0, ijkWindowInternalRebuildThread, window, 0, 0);
	}	break;
	case ijkWinCtrlMsg_cmd: {
		kpbyte const cmd = (pbyte)lParam;
		i32 const len = (i32)wParam;
		if (cmd && len)
			window->plugin->ijkPluginCallback_user4c(window->plugin->data, 1, (ptr*)(&cmd));
	}	break;

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
		ijkWindowPlatform_win* const platformInfo = malloc(szb(ijkWindowPlatform_win));
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
		size const sz = szb(ijkWindowInfo_win);
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


iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const* const windowInfo, ijkWindowPlatform const* const platformInfo, ijkRendererInfo const* const rendererInfo_opt, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl, ibool const fullScreen)
{
	if (window_out && !window_out->windowData && windowInfo && *windowInfo && platformInfo && *platformInfo && windowName && *windowName)
	{
		ibool const hideCursor = ijk_flagch(windowCtrl, ijkWinCtrl_hideCursor);
		ibool const lockCursor = ijk_flagch(windowCtrl, ijkWinCtrl_lockCursor);
		ibool const showWindow = SW_SHOW;
		
		HWND handle = 0;
		RECT displayArea = { 0 };
		dword style = (WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_POPUP), styleEx = (WS_EX_APPWINDOW);

		ijkWindowInfo_win const* const info = *windowInfo;
		ijkWindowPlatform_win* const plat = *platformInfo;
		ijkRendererInfo* const render = (rendererInfo_opt ? *rendererInfo_opt : 0);

		// set full-screen area
		//if (fullScreen)
		//	GetWindowRect(GetDesktopWindow(), &displayArea);
		
		// set display area for windowed
		//else
		{
			displayArea.left = (i16)windowPos_x;
			displayArea.top = (i16)windowPos_y;
			displayArea.right = displayArea.left + windowSize_x;
			displayArea.bottom = displayArea.top + windowSize_y;
			styleEx |= WS_EX_WINDOWEDGE;
			style |= WS_OVERLAPPEDWINDOW;
		}

		// set data
		window_out->winPlat = plat;
		window_out->winRender = render;
		window_out->winCtrl = windowCtrl;

		// attempt to make a window
		// window's handle is set through window process callback
		AdjustWindowRectEx(&displayArea, style, ijk_false, styleEx);
		handle = CreateWindowExA(
			styleEx, info->lpszClassName, windowName, style,
			windowPos_x, windowPos_y, (displayArea.right - displayArea.left), (displayArea.bottom - displayArea.top),
			NULL, NULL, info->hInstance, window_out);

		// success
		if (handle)
		{
			ShowCursor(!hideCursor);
			ShowWindow(handle, showWindow);
			UpdateWindow(handle);
			if (lockCursor)
				ijkWindowInternalLockCursor(window_out);
			if (fullScreen)
				ijkWindowInternalToggleFullscreen(window_out);

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
					// send command
					if (window->winCtrl & ijkWinCtrl_esc_cmd)
						ijkWindowInternalCreateDialog(window, ijkWinCtrl_esc_cmd);

					// auto-kill window
					else
						PostMessageA(handle, WM_CLOSE, 0, 0);
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


iret ijkWindowLoadDefaultPlugin(ijkWindow* const window, tag const author, tag const version, ibool const reload)
{
	if (window && window->windowData)
	{
		i32 const i = -2;
		ui32 const msg = (reload ? ijkWinCtrlMsg_reload : ijkWinCtrlMsg_load);
		ijkPluginInfo info[1] = { 0 };
		if (ijk_issuccess(ijkPluginInfoSetDefault(info, author, version)))
		{
			SendMessageA(window->windowData, msg, (WPARAM)i, (LPARAM)info);
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// WINDOWS