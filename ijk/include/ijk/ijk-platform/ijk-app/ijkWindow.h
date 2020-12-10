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
typedef struct ijkWindowPlatform	ijkWindowPlatform;
typedef enum ijkWindowControl		ijkWindowControl;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkWindowPlatform
struct ijkWindowPlatform
{
	kcstr const dir_build;
	kcstr const dir_target;
	kcstr const dir_sdk;
	kcstr const tag_cfg;
};

// ijkWindow
typedef ptr ijkWindow;

// ijkWindowInfo
typedef ptr ijkWindowInfo;

// ijkRendererInfo
typedef ptr ijkRendererInfo;


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


//-----------------------------------------------------------------------------

// ijkWindowPlatformInit
//	Initialize permanent window platform descriptor.


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_WINDOW_H_