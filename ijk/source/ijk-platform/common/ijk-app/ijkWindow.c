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
iret ijkWindowCallbackDefault_p(ptr p) { return ijk_fail_invalidparams; }								// Default window callback with pointer parameter.
iret ijkWindowCallbackDefault_pi(ptr p, i32 i) { return ijk_fail_invalidparams; }						// Default window callback with pointer and integer parameters.
iret ijkWindowCallbackDefault_pii(ptr p, i32 i0, i32 i1) { return ijk_fail_invalidparams; }				// Default window callback with pointer and two integer parameters.
iret ijkWindowCallbackDefault_piii(ptr p, i32 i0, i32 i1, i32 i2) { return ijk_fail_invalidparams; }	// Default window callback with pointer and three integer parameters.
iret ijkWindowCallbackDefault_pip2(ptr p, i32 i, ptr* p_out) { return ijk_fail_invalidparams; }			// Default window callback with pointer and pointer-to-pointer parameters.


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
		window->callback_load = window->callback_load_hot = ijkWindowCallbackDefault_pip2;
		window->callback_reload = window->callback_reload_hot = ijkWindowCallbackDefault_pip2;
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
		window->callback_user1 = window->callback_user2 = window->callback_user3 = ijkWindowCallbackDefault_p;
		window->callback_user4c = ijkWindowCallbackDefault_pip2;

		// done
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

iret ijkWindowPlatformPackResource(ui64* const res_out, i16 const controlBase, i8 const controlID, i8 const iconID, i8 const cursorID)
{
	if (res_out)
	{
		*res_out = ((ui64)((ui16)controlBase) | (ui64)((ui8)controlID) << 16 | (ui64)((ui8)iconID) << 32 | (ui64)((ui8)cursorID) << 40);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}

iret ijkWindowPlatformInternalUnpackControlBase(ui64 const resource)
{
	return (iret)((ui16)(resource & 0xffff));
}

iret ijkWindowPlatformInternalUnpackControlID(ui64 const resource)
{
	return (iret)((ui8)(resource >> 16 & 0xff));
}

iret ijkWindowPlatformInternalUnpackIconID(ui64 const resource)
{
	return (iret)((ui8)(resource >> 32 & 0xff));
}

iret ijkWindowPlatformInternalUnpackCursorID(ui64 const resource)
{
	return (iret)((ui8)(resource >> 40 & 0xff));
}


//-----------------------------------------------------------------------------
