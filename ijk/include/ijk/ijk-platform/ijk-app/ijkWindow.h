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

	ijkWindow.h
	Window management interface.
*/

#ifndef _IJK_WINDOW_H_
#define _IJK_WINDOW_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct ijkWindow			ijkWindow;
typedef enum ijkWindowControl		ijkWindowControl;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkWindowPlatform
//	Platform descriptor for internal use.
typedef ptr ijkWindowPlatform;

// ijkWindowInfo
//	Platform-agnostic alias for window info descriptor, implemented in source 
//	for platform-specific requirements.
typedef ptr ijkWindowInfo;

// ijkRendererInfo
//	Renderer- and platform-agnostic alias for renderer info descriptor, 
//	implemented in source for renderer- and platform-specific requirements.
typedef ptr ijkRendererInfo;


// Window callback function pointer types.
///
typedef iret(*ijkWindowCallback_p)		(ptr p);							// Window callback with pointer parameter.
typedef iret(*ijkWindowCallback_pi)		(ptr p, i32 i);						// Window callback with pointer and integer parameters.
typedef iret(*ijkWindowCallback_pii)	(ptr p, i32 i0, i32 i1);			// Window callback with pointer and two integer parameters.
typedef iret(*ijkWindowCallback_piii)	(ptr p, i32 i0, i32 i1, i32 i2);	// Window callback with pointer and three integer parameters.
typedef iret(*ijkWindowCallback_pip2)	(ptr p, i32 i, ptr* pp);			// Window callback with pointer, integer and pointer-to-pointer parameters.


//-----------------------------------------------------------------------------

// ijkWindowControl
//	Control or feature flags for window creation.
enum ijkWindowControl
{
	ijkWinCtrl_none,					// All control/feature flags disabled.
	ijkWinCtrl_F1_info = 0x0001,		// Press F1 to bring up player info window.
	ijkWinCtrl_F2_load = 0x0002,		// Press F2 to bring up load plugin window.
	ijkWinCtrl_F3_reload = 0x0004,		// Press F3 to reload current plugin.
	ijkWinCtrl_F4_unload = 0x0008,		// Press F4 to unload current plugin.
	ijkWinCtrl_F5_debug = 0x0010,		// Press F5 to load and run debug plugin.
	ijkWinCtrl_F6_build = 0x0020,		// Press F6 to hot build-and-swap debug plugin.
	ijkWinCtrl_F7_rebuild = 0x0040,		// Press F7 to hot rebuild-and-swap debug plugin.
	ijkWinCtrl_F8_fullscr = 0x0080,		// Press F8 to toggle full-screen.
	ijkWinCtrl_F9_user1 = 0x0100,		// Press F9 for user function 1.
	ijkWinCtrl_F10_user2 = 0x0200,		// Press F10 for user function 2.
	ijkWinCtrl_F11_user3 = 0x0400,		// Press F11 for user function 3.
	ijkWinCtrl_F12_user4c = 0x0800,		// Press F12 for user function 4, no additional command (ignored on Windows, reserved by debugger).
	ijkWinCtrl_esc_cmd = 0x1000,		// Press escape to enter and process command (calls user4 with additional command).
	ijkWinCtrl_hideCursor = 0x2000,		// Hide cursor or mouse pointer.
	ijkWinCtrl_lockCursor = 0x4000,		// Lock cursor to window area.
	ijkWinCtrl_fullscr_start = 0x8000,	// Full-screen on start.
	ijkWinCtrl_all = 0xffff				// All control/feature flags enabled.
};


// ijkWindow
//	Window descriptor.
//		member winPlat: pointer to platform info
//		member winRender: pointer to renderer info
//		member winCtrl: window controls and feature flags
//		members pos_x, pos_y: position of window on display in pixels
//		members sz_x, sz_y: size of window on display in pixels
//		member platformData: internal platform data pertinent to window
//		member windowData: internal window data
//		member pluginData: internal pointer to persistent plugin data
//		member pluginHandle: internal pointer to persistent plugin handle
//		members callback: array of function pointers to callbacks in plugin
struct ijkWindow
{
	ijkWindowPlatform winPlat;
	ijkRendererInfo winRender;
	ijkWindowControl winCtrl;
	i16 pos_x, pos_y;
	i16 sz_x, sz_y;

	ptr platformData;
	ptr windowData;
	ptr pluginData;
	ptr pluginHandle;

	union {
		ptr callback[32];
		struct {
			ijkWindowCallback_pip2 callback_load, callback_load_hot;				// Load/hot-load callback.
			ijkWindowCallback_pip2 callback_reload, callback_reload_hot;			// Reload/hot-reload callback.
			ijkWindowCallback_p callback_unload, callback_unload_hot;				// Unload/hot-unload callback.
			ijkWindowCallback_p callback_winActivate, callback_winDeactivate;		// Window activate/deactivate callback.
			ijkWindowCallback_p callback_display, callback_idle;					// Window display/idle callback.
			ijkWindowCallback_pii callback_winMove, callback_winResize;				// Window move/resize callback.
			ijkWindowCallback_pi callback_keyPressVirt, callback_keyPressAscii;		// Virtual/ASCII key press callback.
			ijkWindowCallback_pi callback_keyHoldVirt, callback_keyHoldAscii;		// Virtual/ASCII key hold callback.
			ijkWindowCallback_pi callback_keyReleaseVirt, callback_keyReleaseAscii;	// Virtual/ASCII key release callback.
			ijkWindowCallback_piii callback_mouseClick, callback_mouseClick2;		// Mouse click/double-click callback.
			ijkWindowCallback_piii callback_mouseRelease, callback_mouseWheel;		// Mouse release/scroll callback.
			ijkWindowCallback_pii callback_mouseMove, callback_mouseMove_ext;		// Mouse move inside/outside window callback.
			ijkWindowCallback_pii callback_mouseEnter, callback_mouseLeave;			// Mouse enter/leave window callback.
			ijkWindowCallback_p callback_willReload, callback_willUnload;			// Plugin pre-reload/unload callback.
			ijkWindowCallback_p callback_user1, callback_user2, callback_user3;		// User function callbacks (F9-F11).
			ijkWindowCallback_pip2 callback_user4c;									// User function callback with command (F12/ESC).
		};
	};
};


//-----------------------------------------------------------------------------

// ijkWindowPlatformPackResource
//	Pack resource flags into integer.
//		param res_out: pointer to resource integer
//		param controlBase: control base offset
//		param controlID: control identifier
//		param iconID: icon identifier
//		param cursorID: cursor identifier
//		return SUCCESS: ijk_success if resource packed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowPlatformPackResource(ui64* const res_out, i16 const controlBase, i8 const controlID, i8 const iconID, i8 const cursorID);

// ijkWindowPlatformCreate
//	Initialize platform info.
//		param platformInfo_out: pointer to platform info handle
//			valid: non-null, points to null
//		param applicationInst: pointer to application handle
//			valid: non-null, valid handle
//		param dev: description of development environment
//			valid: non-null, non-empty c-string
//		param target: description of build target
//			valid: non-null, non-empty c-string
//		param sdk: description of framework
//			valid: non-null, non-empty c-string
//		param cfg: description of configuration
//			valid: non-null, non-empty c-string
//		param applicationRes: resource descriptor
//		return SUCCESS: ijk_success if info initialized
//		return FAILURE: ijk_fail_operationfail if info not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowPlatformCreate(ijkWindowPlatform* const platformInfo_out, kptr const applicationInst, tag const dev, tag const target, tag const sdk, tag const cfg, ui64 const applicationRes);

// ijkWindowPlatformRelease
//	Release platform info.
//		param platformInfo: pointer to platform info
//			valid: non-null, valid handle
//		return SUCCESS: ijk_success if info released
//		return FAILURE: ijk_fail_operationfail if info not released
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowPlatformRelease(ijkWindowPlatform* const platformInfo);

// ijkWindowInfoCreateDefault
//	Create default window info with rendering capabilities.
//		param windowInfo_out: pointer to window info handle
//			valid: non-null, points to null
//		param platformInfo: pointer to platform info
//			valid: non-null, valid handle
//		param descriptorName: brief description of info
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if info initialized
//		return FAILURE: ijk_fail_operationfail if info not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowInfoCreateDefault(ijkWindowInfo* const windowInfo_out, ijkWindowPlatform const* const platformInfo, tag const descriptorName);

// ijkWindowInfoRelease
//	Release window info.
//		param windowInfo: pointer to window info
//			valid: non-null, valid handle
//		return SUCCESS: ijk_success if info released
//		return FAILURE: ijk_fail_operationfail if info not released
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowInfoRelease(ijkWindowInfo* const windowInfo);

// ijkWindowCreate
//	Create and open window with specified features.
//		param window_out: pointer to window descriptor
//			valid: non-null, non-initialized
//		param windowInfo: pointer to window info
//			valid: non-null, valid handle
//		param platformInfo: pointer to platform info
//			valid: non-null, valid handle
//		param rendererInfo_opt: optional pointer to renderer info
//			valid: non-null, valid handle
//		param windowName: name of window
//			valid: non-null, non-empty c-string
//		param windowPos_x: horizontal position of window on display in pixels
//			note: left edge of display is zero
//		param windowPos_y: vertical position of window on display in pixels
//			note: top edge of display is zero
//		param windowSize_x: horizontal size of window on display in pixels
//		param windowSize_y: vertical size of window on display in pixels
//		param windowCtrl: control/feature flags for window
//		return SUCCESS: ijk_success if window initialized
//		return FAILURE: ijk_fail_operationfail if window not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const* const windowInfo, ijkWindowPlatform const* const platformInfo, ijkRendererInfo const* const rendererInfo_opt, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl);

// ijkWindowRelease
//	Close and release window.
//		param window: pointer to window descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if window released
//		return FAILURE: ijk_fail_operationfail if window not released
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowRelease(ijkWindow* const window);

// ijkWindowLoop
//	Enter window event main loop.
//		param window: pointer to window descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if main loop exited successfully
//		return FAILURE: ijk_fail_operationfail if loop not started
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowLoop(ijkWindow* const window);

// ijkWindowLoopThread
//	Enter window event main loop on a separate thread.
//		param thread_out: pointer to thread handle
//			valid: non-null, points to null
//		param threadName: name of thread
//			valid: non-null, non-empty c-string
//		param window: pointer to window descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if main loop thread started successfully
//		return FAILURE: ijk_fail_operationfail if loop thread not started
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowLoopThread(ptr* const thread_out, tag const threadName, ijkWindow* const window);

// ijkWindowLoopThreadStatus
//	If window event loop is threaded, check status (thread return code).
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread has exited
//		return FAILURE: ijk_fail_operationfail if thread has not exited
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowLoopThreadStatus(kptr* const thread);

// ijkWindowLoopThreadKill
//	Force-terminate event loop thread.
//		param thread: pointer to thread descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if thread terminated
//		return FAILURE: ijk_fail_operationfail if thread not terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowLoopThreadKill(ptr* const thread);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_WINDOW_H_