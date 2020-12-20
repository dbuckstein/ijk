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

	ijkPlugin.h
	Plugin management interface.
*/

#ifndef _IJK_PLUGIN_H_
#define _IJK_PLUGIN_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct ijkPluginInfo	ijkPluginInfo;
typedef struct ijkPlugin		ijkPlugin;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// Plugin callback function pointer types.
///
typedef iret(*ijkPluginCallback_p)		(ptr p);							// Plugin callback with pointer parameter.
typedef iret(*ijkPluginCallback_pi)		(ptr p, i32 i);						// Plugin callback with pointer and integer parameters.
typedef iret(*ijkPluginCallback_pii)	(ptr p, i32 i0, i32 i1);			// Plugin callback with pointer and two integer parameters.
typedef iret(*ijkPluginCallback_piii)	(ptr p, i32 i0, i32 i1, i32 i2);	// Plugin callback with pointer and three integer parameters.
typedef iret(*ijkPluginCallback_pip2)	(ptr p, i32 i, ptr* pp);			// Plugin callback with pointer, integer and pointer-to-pointer parameters.


//-----------------------------------------------------------------------------

// ijkPluginInfo
//	Plugin info descriptor.
//		member name: short name of plugin
//		member dylib: short name of dynamic library file (no extension)
//		member author: short name of author/creator of plugin
//		member version: short description of plugin parameters/details
//		member info: longer description of plugin purpose/activities
struct ijkPluginInfo
{
	tag name;
	tag dylib;
	tag author;
	tag version;
	byte info[128];
};

// ijkPlugin
//	Plugin descriptor.
//		member handle: handle to dylib
//		member data: user data defined in plugin
//		member ijkPluginCallback: array of plugin callbacks from dylib
//		members ijkPluginCallback*: specific plugin callbacks from dylib
struct ijkPlugin
{
	ptr handle;
	ptr data;
	union {
		ptr ijkPluginCallback[32];
		struct {
			ijkPluginCallback_pip2 ijkPluginCallback_load, ijkPluginCallback_load_hot;						// Load/hot-load callback.
			ijkPluginCallback_pip2 ijkPluginCallback_reload, ijkPluginCallback_reload_hot;					// Reload/hot-reload callback.
			ijkPluginCallback_p ijkPluginCallback_unload, ijkPluginCallback_unload_hot;						// Unload/hot-unload callback.
			ijkPluginCallback_p ijkPluginCallback_winActivate, ijkPluginCallback_winDeactivate;				// Window activate/deactivate callback.
			ijkPluginCallback_p ijkPluginCallback_display, ijkPluginCallback_idle;							// Window display/idle callback.
			ijkPluginCallback_pii ijkPluginCallback_winMove, ijkPluginCallback_winResize;					// Window move/resize callback.
			ijkPluginCallback_pi ijkPluginCallback_keyPressVirt, ijkPluginCallback_keyPressAscii;			// Virtual/ASCII key press callback.
			ijkPluginCallback_pi ijkPluginCallback_keyHoldVirt, ijkPluginCallback_keyHoldAscii;				// Virtual/ASCII key hold callback.
			ijkPluginCallback_pi ijkPluginCallback_keyReleaseVirt, ijkPluginCallback_keyReleaseAscii;		// Virtual/ASCII key release callback.
			ijkPluginCallback_piii ijkPluginCallback_mouseClick, ijkPluginCallback_mouseClick2;				// Mouse click/double-click callback.
			ijkPluginCallback_piii ijkPluginCallback_mouseRelease, ijkPluginCallback_mouseWheel;			// Mouse release/scroll callback.
			ijkPluginCallback_pii ijkPluginCallback_mouseMove, ijkPluginCallback_mouseMove_ext;				// Mouse move inside/outside window callback.
			ijkPluginCallback_pii ijkPluginCallback_mouseEnter, ijkPluginCallback_mouseLeave;				// Mouse enter/leave window callback.
			ijkPluginCallback_p ijkPluginCallback_willReload, ijkPluginCallback_willUnload;					// Plugin pre-reload/unload callback.
			ijkPluginCallback_p ijkPluginCallback_user1, ijkPluginCallback_user2, ijkPluginCallback_user3;	// User function callbacks (F9-F11).
			ijkPluginCallback_pip2 ijkPluginCallback_user4c;												// User function callback with command (F12/ESC).
		};
	};
};


//-----------------------------------------------------------------------------

// ijkPluginInfoSet
//	Set fields in plugin info descriptor.
//		param pluginInfo_out: pointer to plugin info descriptor
//			valid: non-null
//		param name: short name of plugin
//			note: if invalid c-string, uses default
//		param dylib: short name of dynamic library file (no extension)
//			note: if invalid c-string, uses default
//		param author: short name of author/creator of plugin
//			note: if invalid c-string, uses default
//		param version: short description of plugin parameters/details
//			note: if invalid c-string, uses default
//		param info: longer description of plugin purpose/activities
//			note: if invalid c-string, uses default
//		return SUCCESS: ijk_success if set descriptor
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginInfoSet(ijkPluginInfo* const pluginInfo_out, tag const name, tag const dylib, tag const author, tag const version, byte const info[128]);

// ijkPluginInfoSetDefault
//	Set default plugin info descriptor with a couple optional fields.
//		param pluginInfo_out: pointer to plugin info descriptor
//			valid: non-null
//		param author: short name of author/creator of plugin
//			note: if invalid c-string, uses default
//		param version: short description of plugin parameters/details
//			note: if invalid c-string, uses default
//		return SUCCESS: ijk_success if set descriptor
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginInfoSetDefault(ijkPluginInfo* const pluginInfo_out, tag const author, tag const version);

// ijkPluginInfoReset
//	Set default plugin info descriptor.
//		param pluginInfo: pointer to plugin info descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if set descriptor
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginInfoReset(ijkPluginInfo* const pluginInfo);

// ijkPluginLoad
//		param plugin_out: pointer to plugin descriptor
//			valid: non-null, uninitialized
//		param pluginInfo: pointer to plugin info descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if loaded plugin
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginLoad(ijkPlugin* const plugin_out, ijkPluginInfo const* const pluginInfo);

// ijkPluginUnload
//		param plugin: pointer to plugin descriptor
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if unloaded plugin
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginUnload(ijkPlugin* const plugin);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_PLUGIN_H_