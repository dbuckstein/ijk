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

	ijkWindow.c
	Platform-agnostic window management source.
*/

#include "ijk/ijk-platform/ijk-app/ijkWindow.h"


//-----------------------------------------------------------------------------

// Default callbacks.
///
iret ijkWindowCallbackDefault_p(ptr p) { return ijk_fail_invalidparams; }												// Default window callback with pointer parameter.
iret ijkWindowCallbackDefault_pi(ptr p, i32 const i0) { return ijk_fail_invalidparams; }								// Default window callback with pointer and integer parameters.
iret ijkWindowCallbackDefault_pii(ptr p, i32 const i0, i32 const i1) { return ijk_fail_invalidparams; }					// Default window callback with pointer and two integer parameters.
iret ijkWindowCallbackDefault_piii(ptr p, i32 const i0, i32 const i1, i32 const i2) { return ijk_fail_invalidparams; }	// Default window callback with pointer and three integer parameters.
iret ijkWindowCallbackDefault_pp2(ptr p, ptr* p_out) { return ijk_fail_invalidparams; }									// Default window callback with pointer and pointer-to-pointer parameters.


// ijkWindowInternalSetCallbackDefaults
//	Set default callbacks for window interface.
//		param window: pointer to window descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if set callbacks
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkWindowInternalSetCallbackDefaults(ijkWindow* const window)
{
	if (window)
	{
		// set default function for all callbacks
		window->callback_load = window->callback_load_hot = ijkWindowCallbackDefault_pp2;
		window->callback_reload = window->callback_reload_hot = ijkWindowCallbackDefault_pp2;
		window->callback_unload = window->callback_unload_hot = ijkWindowCallbackDefault_p;
		window->callback_winActivate = window->callback_winDeactivate = ijkWindowCallbackDefault_p;
		window->callback_display = window->callback_idle = ijkWindowCallbackDefault_p;
		window->callback_winMove = window->callback_winResize = ijkWindowCallbackDefault_pii;
		window->callback_keyPressVirt = window->callback_keyPressAscii = ijkWindowCallbackDefault_pi;
		window->callback_keyHoldVirt = window->callback_keyHoldAscii = ijkWindowCallbackDefault_pi;
		window->callback_keyReleaseVirt = window->callback_keyReleaseAscii = ijkWindowCallbackDefault_pi;
		window->callback_mouseClick = window->callback_mouseClick2 = ijkWindowCallbackDefault_piii;
		window->callback_mouseRelease = window->callback_mouseWheel = ijkWindowCallbackDefault_piii;
		window->callback_mouseMove = window->callback_mouseMove_ext = ijkWindowCallbackDefault_pii;
		window->callback_mouseEnter = window->callback_mouseLeave = ijkWindowCallbackDefault_pii;
		window->callback_willReload = window->callback_willUnload = ijkWindowCallbackDefault_p;
		window->callback_user1 = window->callback_user2 = window->callback_user3 = window->callback_user4 = ijkWindowCallbackDefault_p;

		// done
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

iret ijkWindowPlatformPackResource(i8 const controlID, i8 const iconID, i8 const cursorID)
{
	return ((iret)controlID | (iret)iconID << 8 | (iret)cursorID << 16);
}


iret ijkWindowPlatformInternalUnpackControl(iret const resource)
{
	return (resource & 0xff);
}

iret ijkWindowPlatformInternalUnpackIconID(iret const resource)
{
	return (resource >> 8 & 0xff);
}

iret ijkWindowPlatformInternalUnpackCursorID(iret const resource)
{
	return (resource >> 16 & 0xff);
}


//-----------------------------------------------------------------------------
