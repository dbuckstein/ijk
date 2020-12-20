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

	ijkPlugin.c
	Platform-agnostic plugin management source.
*/

#include "ijk/ijk-platform/ijk-app/ijkPlugin.h"


//-----------------------------------------------------------------------------

// Default callbacks.
///
iret ijkPluginCallback_default_p(ptr p) { return ijk_fail_invalidparams; }								// Default window callback with pointer parameter.
iret ijkPluginCallback_default_pi(ptr p, i32 i) { return ijk_fail_invalidparams; }						// Default window callback with pointer and integer parameters.
iret ijkPluginCallback_default_pii(ptr p, i32 i0, i32 i1) { return ijk_fail_invalidparams; }			// Default window callback with pointer and two integer parameters.
iret ijkPluginCallback_default_piii(ptr p, i32 i0, i32 i1, i32 i2) { return ijk_fail_invalidparams; }	// Default window callback with pointer and three integer parameters.
iret ijkPluginCallback_default_pip2(ptr p, i32 i, ptr* p_out) { return ijk_fail_invalidparams; }		// Default window callback with pointer and pointer-to-pointer parameters.


//-----------------------------------------------------------------------------

// ijkPluginInternalSetCallbackDefaults
//	Set default callbacks for window interface.
//		param plugin: pointer to plugin descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if set callbacks
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkPluginInternalSetCallbackDefaults(ijkPlugin* const plugin)
{
	if (plugin)
	{
		// set default function for all callbacks
		plugin->ijkPluginCallback_load = plugin->ijkPluginCallback_load_hot = ijkPluginCallback_default_pip2;
		plugin->ijkPluginCallback_reload = plugin->ijkPluginCallback_reload_hot = ijkPluginCallback_default_pip2;
		plugin->ijkPluginCallback_unload = plugin->ijkPluginCallback_unload_hot = ijkPluginCallback_default_p;
		plugin->ijkPluginCallback_winActivate = plugin->ijkPluginCallback_winDeactivate = ijkPluginCallback_default_p;
		plugin->ijkPluginCallback_display = plugin->ijkPluginCallback_idle = ijkPluginCallback_default_p;
		plugin->ijkPluginCallback_winMove = plugin->ijkPluginCallback_winResize = ijkPluginCallback_default_pii;
		plugin->ijkPluginCallback_keyPressVirt = plugin->ijkPluginCallback_keyPressAscii = ijkPluginCallback_default_pi;
		plugin->ijkPluginCallback_keyHoldVirt = plugin->ijkPluginCallback_keyHoldAscii = ijkPluginCallback_default_pi;
		plugin->ijkPluginCallback_keyReleaseVirt = plugin->ijkPluginCallback_keyReleaseAscii = ijkPluginCallback_default_pi;
		plugin->ijkPluginCallback_mouseClick = plugin->ijkPluginCallback_mouseClick2 = ijkPluginCallback_default_piii;
		plugin->ijkPluginCallback_mouseRelease = plugin->ijkPluginCallback_mouseWheel = ijkPluginCallback_default_piii;
		plugin->ijkPluginCallback_mouseMove = plugin->ijkPluginCallback_mouseMove_ext = ijkPluginCallback_default_pii;
		plugin->ijkPluginCallback_mouseEnter = plugin->ijkPluginCallback_mouseLeave = ijkPluginCallback_default_pii;
		plugin->ijkPluginCallback_willReload = plugin->ijkPluginCallback_willUnload = ijkPluginCallback_default_p;
		plugin->ijkPluginCallback_user1 = plugin->ijkPluginCallback_user2 = plugin->ijkPluginCallback_user3 = ijkPluginCallback_default_p;
		plugin->ijkPluginCallback_user4c = ijkPluginCallback_default_pip2;

		// done
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
