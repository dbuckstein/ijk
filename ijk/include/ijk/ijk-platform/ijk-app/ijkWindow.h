/*
   Copyright 2020-2021 Daniel S. Buckstein

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

#include "ijkPlugin.h"
#include "ijk/ijk-platform/ijk-render/ijkRenderContext.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkWindowPlatform
//	Platform descriptor for internal use.
typedef ptr ijkWindowPlatform;

// ijkWindowInfo
//	Platform-agnostic alias for window info descriptor, implemented in source 
//	for platform-specific requirements.
typedef ptr ijkWindowInfo;


//-----------------------------------------------------------------------------

// ijkWindowControl
//	Control or feature flags for window creation.
typedef enum ijkWindowControl
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
	ijkWinCtrl_F12_user4c = 0x0800,		// Press F12 for user function 4, no additional command (also triggers a breakpoint in VS).
	ijkWinCtrl_esc_cmd = 0x1000,		// Press escape to enter and process command (calls user4 with additional command).
	ijkWinCtrl_hideCursor = 0x2000,		// Hide cursor or mouse pointer.
	ijkWinCtrl_lockCursor = 0x4000,		// Lock cursor to window area.
	ijkWinCtrl_drawInactive = 0x8000,	// Draw even when window is inactive.
	ijkWinCtrl_all = 0xffff				// All control/feature flags enabled.
} ijkWindowControl;


// ijkWindow
//	Window descriptor.
//		member plugin: plugin descriptor
//		member pluginInfo: plugin info descriptor
//		member winPlat: pointer to platform info
//		member winCtrl: window controls and feature flags
//		member renderContext: pointer to render context
//		members pos_x, pos_y: position of window on display in pixels
//		members sz_x, sz_y: size of window on display in pixels
//		member platformData: internal platform data pertinent to window
//		member windowData: internal window data
typedef struct ijkWindow
{
	ijkPlugin plugin[1];
	ijkPluginInfo pluginInfo[1];
	ijkWindowPlatform winPlat;
	ijkWindowControl winCtrl;
	ijkRenderContext renderContext[1];
	i16 pos_x, pos_y;
	i16 sz_x, sz_y;
	ptr platformData;
	ptr windowData;
} ijkWindow;


//-----------------------------------------------------------------------------

// ijkWindowPlatformPackResource
//	Pack resource flags into integer.
//		param res_out: pointer to resource integer
//		param controlBase: control base offset
//		param controlID: control identifier
//		param dialogID: dialog identifier
//		param iconID: icon identifier
//		param cursorID: cursor identifier
//		return SUCCESS: ijk_success if resource packed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowPlatformPackResource(ui64* const res_out, i16 const controlBase, i8 const controlID, i8 const dialogID, i8 const iconID, i8 const cursorID);

// ijkWindowPlatformCreateGlobal
//	Initialize globally-accessible platform info.
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
//		param platformInfo_out_opt: optional pointer to platform info handle
//		return SUCCESS: ijk_success if info initialized
//		return FAILURE: ijk_fail_operationfail if info not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowPlatformCreateGlobal(kptr const applicationInst, tag const dev, tag const target, tag const sdk, tag const cfg, ui64 const applicationRes, ijkWindowPlatform* const platformInfo_out_opt);

// ijkWindowPlatformReleaseGlobal
//	Release globally-accessible platform info.
//		return SUCCESS: ijk_success if info released
//		return FAILURE: ijk_fail_operationfail if info not released
iret ijkWindowPlatformReleaseGlobal();

// ijkWindowInfoCreateDefault
//	Create default window info with rendering capabilities.
//		param windowInfo_out: pointer to window info handle
//			valid: non-null, points to null
//		param descriptorName: brief description of info
//			valid: non-null, non-empty c-string
//		return SUCCESS: ijk_success if info initialized
//		return FAILURE: ijk_fail_operationfail if info not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowInfoCreateDefault(ijkWindowInfo* const windowInfo_out, tag const descriptorName);

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
//		param windowName: name of window
//			valid: non-null, non-empty c-string
//		param windowPos_x: horizontal position of window on display in pixels
//			note: left edge of display is zero
//		param windowPos_y: vertical position of window on display in pixels
//			note: top edge of display is zero
//		param windowSize_x: horizontal size of window on display in pixels
//		param windowSize_y: vertical size of window on display in pixels
//		param windowCtrl: control/feature flags for window
//		param fullScreen: flag to create full-screen window
//		param renderer_opt: optional renderer type
//		return SUCCESS: ijk_success if window initialized
//		return FAILURE: ijk_fail_operationfail if window not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowCreate(ijkWindow* const window_out, ijkWindowInfo const* const windowInfo, tag const windowName, ui16 const windowPos_x, ui16 const windowPos_y, ui16 const windowSize_x, ui16 const windowSize_y, ijkWindowControl const windowCtrl, bool const fullScreen, ijkRenderer const renderer_opt);

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

// ijkWindowLoadDefaultPlugin
//	Interface to load default plugin into target window; any loaded plugin is 
//	cleaned up when the window is closed, which is why there is no matching 
//	public unload interface.
//		param window: pointer to target window
//			valid: non-null, initialized
//		param author: short name of author/creator of plugin
//			note: if invalid c-string, uses default
//		param version: short description of plugin parameters/details
//			note: if invalid c-string, uses default
//		param reload: flag describing whether demo should reload (true) or be 
//			treated as a new load (false)
//		return SUCCESS: ijk_success if plugin loaded
//		return FAILURE: ijk_fail_operationfail if plugin not loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowLoadDefaultPlugin(ijkWindow* const window, tag const author, tag const version, bool const reload);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_WINDOW_H_