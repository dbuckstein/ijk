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

	ijk-plugin.c
	Default source for plugin dynamic library.
*/

#include "ijk/ijk/ijk-typedefs.h"
#include "ijk/ijk-platform/ijk-app/_util/ijk-dylib.h"


//-----------------------------------------------------------------------------

typedef i32 ijkPluginData;


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

IJK_DYLIB_SYMBOL iret ijkPluginCallback_load(ijkPluginData* data, i32 i, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_load_hot(ijkPluginData* data, i32 i, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_reload(ijkPluginData* data, i32 i, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_reload_hot(ijkPluginData* data, i32 i, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_unload(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_unload_hot(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winActivate(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winDeactivate(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_display(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_idle(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winMove(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winResize(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyPressVirt(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyPressAscii(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyHoldVirt(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyHoldAscii(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyReleaseVirt(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyReleaseAscii(ijkPluginData* data, i32 i);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseClick(ijkPluginData* data, i32 i0, i32 i1, i32 i2);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseClick2(ijkPluginData* data, i32 i0, i32 i1, i32 i2);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseRelease(ijkPluginData* data, i32 i0, i32 i1, i32 i2);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseWheel(ijkPluginData* data, i32 i0, i32 i1, i32 i2);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseMove(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseDrag(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseEnter(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseLeave(ijkPluginData* data, i32 i0, i32 i1);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_willReload(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_willUnload(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_user1(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_user2(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_user3(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_user4c(ijkPluginData* data, i32 const argc, byte const* const argv[]);

#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

iret ijkPluginCallback_load(ijkPluginData* data, i32 i, ijkPluginData** data_out)
{

	return ijk_success;
}

iret ijkPluginCallback_load_hot(ijkPluginData* data, i32 i, ijkPluginData** data_out)
{

	return ijk_success;
}

iret ijkPluginCallback_reload(ijkPluginData* data, i32 i, ijkPluginData** data_out)
{

	return ijk_success;
}

iret ijkPluginCallback_reload_hot(ijkPluginData* data, i32 i, ijkPluginData** data_out)
{

	return ijk_success;
}

iret ijkPluginCallback_unload(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_unload_hot(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_winActivate(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_winDeactivate(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_display(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_idle(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_winMove(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_winResize(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_keyPressVirt(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_keyPressAscii(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_keyHoldVirt(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_keyHoldAscii(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_keyReleaseVirt(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_keyReleaseAscii(ijkPluginData* data, i32 i)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseClick(ijkPluginData* data, i32 i0, i32 i1, i32 i2)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseClick2(ijkPluginData* data, i32 i0, i32 i1, i32 i2)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseRelease(ijkPluginData* data, i32 i0, i32 i1, i32 i2)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseWheel(ijkPluginData* data, i32 i0, i32 i1, i32 i2)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseMove(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseDrag(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseEnter(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_mouseLeave(ijkPluginData* data, i32 i0, i32 i1)
{

	return ijk_success;
}

iret ijkPluginCallback_willReload(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_willUnload(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_user1(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_user2(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_user3(ijkPluginData* data)
{

	return ijk_success;
}

iret ijkPluginCallback_user4c(ijkPluginData* data, i32 const argc, byte const* const argv[])
{

	return ijk_success;
}


//-----------------------------------------------------------------------------
