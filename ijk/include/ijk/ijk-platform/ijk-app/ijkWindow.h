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


// Window callbacks
///
typedef iret(*ijkWindowCallback_p)		(ptr p);											// Window callback with pointer parameter.
typedef iret(*ijkWindowCallback_pi)		(ptr p, i32 const i0);								// Window callback with pointer and integer parameters.
typedef iret(*ijkWindowCallback_pii)	(ptr p, i32 const i0, i32 const i1);				// Window callback with pointer and two integer parameters.
typedef iret(*ijkWindowCallback_piii)	(ptr p, i32 const i0, i32 const i1, i32 const i2);	// Window callback with pointer and three integer parameters.
typedef iret(*ijkWindowCallback_pp2)	(ptr p, ptr* p_out);								// Window callback with pointer and pointer-to-pointer parameters.


//-----------------------------------------------------------------------------

// ijkWindowControl
//	Control or feature flags for window creation.
enum ijkWindowControl
{
	ijkWinCtrl_none,					// All control/feature flags disabled.
	ijkWinCtrl_F1_info = 0x0001,		// Press F1 to bring up player info window.
	ijkWinCtrl_F2_load = 0x0002,		// Press F2 to bring up load plugin window.
	ijkWinCtrl_F3_reload = 0x0004,		// Press F3 to reload current plugin.
	ijkWinCtrl_F4_close = 0x0008,		// Press F4 to close current plugin.
	ijkWinCtrl_F5_debug = 0x0010,		// Press F5 to load and run debug plugin.
	ijkWinCtrl_F6_build = 0x0020,		// Press F6 to hot build-and-swap debug plugin.
	ijkWinCtrl_F7_rebuild = 0x0040,		// Press F7 to hot rebuild-and-swap debug plugin.
	ijkWinCtrl_F8_fullscr = 0x0080,		// Press F8 to toggle full-screen.
	ijkWinCtrl_F9_user1 = 0x0100,		// Press F9 for user function 1.
	ijkWinCtrl_F10_user2 = 0x0200,		// Press F10 for user function 2.
	ijkWinCtrl_F11_user3 = 0x0400,		// Press F11 for user function 3.
	ijkWinCtrl_F12_user4 = 0x0800,		// Press F12 for user function 4.
	ijkWinCtrl_esc_quit = 0x1000,		// Press escape to quit application.
	ijkWinCtrl_autoLoad = 0x2000,		// Auto-load debug plugin on-load.
	ijkWinCtrl_startFullscr = 0x4000,	// Full-screen on start.
	ijkWinCtrl_hideCursor = 0x8000,		// Hide cursor or mouse pointer.
};


// ijkWindow
//	Window descriptor.
//		member pluginData: pointer to persistent plugin data
//		member pluginHandle: pointer to persistent plugin handle
//		member winPlat: pointer to platform info
//		member winRender: pointer to renderer info
//		member winCtrl: window controls and feature flags
//		member id: window identifier
//		members pos_x, pos_y: position of window on display in pixels
//		members sz_x, sz_y: size of window on display in pixels
//		members callback: array of function pointers to callbacks in plugin
struct ijkWindow
{
	ptr pluginData;
	ptr pluginHandle;
	ijkWindowPlatform winPlat;
	ijkRendererInfo winRender;

	ijkWindowControl winCtrl;
	i32 id;
	i32 pos_x, pos_y;
	i32 sz_x, sz_y;

	union {
		ptr callback[32];
		struct {
			ijkWindowCallback_pp2 callback_load, callback_load_hot;									// Load/hot-load callback.
			ijkWindowCallback_pp2 callback_reload, callback_reload_hot;								// Reload/hot-reload callback.
			ijkWindowCallback_p callback_unload, callback_unload_hot;								// Unload/hot-unload callback.
			ijkWindowCallback_p callback_winActivate, callback_winDeactivate;						// Window activate/deactivate callback.
			ijkWindowCallback_pii callback_winMove, callback_winResize;								// Window move/resize callback.
			ijkWindowCallback_pi callback_keyPressVirt, callback_keyPressAscii;						// Virtual/ASCII key press callback.
			ijkWindowCallback_pi callback_keyHoldVirt, callback_keyHoldAscii;						// Virtual/ASCII key hold callback.
			ijkWindowCallback_pi callback_keyReleaseVirt, callback_keyReleaseAscii;					// Virtual/ASCII key release callback.
			ijkWindowCallback_piii callback_mouseClick, callback_mouseClick2;						// Mouse click/double-click callback.
			ijkWindowCallback_piii callback_mouseRelease, callback_mouseWheel;						// Mouse release/scroll callback.
			ijkWindowCallback_pii callback_mouseMove, callback_mouseMove_ext;						// Mouse move inside/outside window callback.
			ijkWindowCallback_pii callback_mouseEnter, callback_mouseLeave;							// Mouse enter/leave window callback.
			ijkWindowCallback_p callback_willReload, callback_willReload_hot;						// Plugin will reload/hot-reload callback.
			ijkWindowCallback_p callback_willUnload, callback_willUnload_hot;						// Plugin will unload/hot-unload callback.
			ijkWindowCallback_p callback_user1, callback_user2, callback_user3, callback_user4;		// User function callbacks (F9-F12).
		};
	};
};


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_WINDOW_H_