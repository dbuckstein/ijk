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

	ijk-plugin.c
	Default source for plugin dynamic library.
*/

#include "ijk/ijk/ijk-typedefs.h"
#include "ijk/ijk-platform/ijk-app/_util/ijk-dylib.h"

#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------

typedef i32 ijkPluginData;


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

IJK_DYLIB_SYMBOL iret ijkPluginCallback_load(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_load_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_reload(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_reload_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_unload(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_unload_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winActivate(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winDeactivate(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_display(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_idle(ijkPluginData* data);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winMove(ijkPluginData* data, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_winResize(ijkPluginData* data, i32 w, i32 h);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyPressVirt(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyPressAscii(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyHoldVirt(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyHoldAscii(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyReleaseVirt(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_keyReleaseAscii(ijkPluginData* data, i32 key);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseClick(ijkPluginData* data, i32 btn, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseClick2(ijkPluginData* data, i32 btn, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseRelease(ijkPluginData* data, i32 btn, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseWheel(ijkPluginData* data, i32 dir, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseMove(ijkPluginData* data, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseDrag(ijkPluginData* data, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseEnter(ijkPluginData* data, i32 x, i32 y);
IJK_DYLIB_SYMBOL iret ijkPluginCallback_mouseLeave(ijkPluginData* data, i32 x, i32 y);
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

iret ijkPluginCallback_load(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (!*data_out)
	{
		*data_out = (ijkPluginData*)malloc(szb(ijkPluginData));
		**data_out = f;
	}

	printf("\n ijkPluginCallback_load(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_load_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (!*data_out)
	{
		*data_out = (ijkPluginData*)malloc(szb(ijkPluginData));
		**data_out = f;
	}

	printf("\n ijkPluginCallback_load_hot(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_reload(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (*data_out)
	{
		free(*data_out);
		*data_out = 0;
	}
	if (!*data_out)
	{
		*data_out = (ijkPluginData*)malloc(szb(ijkPluginData));
		**data_out = f;
	}

	printf("\n ijkPluginCallback_reload(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_reload_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (*data_out)
	{
		free(*data_out);
		*data_out = 0;
	}
	if (!*data_out)
	{
		*data_out = (ijkPluginData*)malloc(szb(ijkPluginData));
		**data_out = f;
	}

	printf("\n ijkPluginCallback_reload_hot(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_unload(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (*data_out)
	{
		free(*data_out);
		*data_out = 0;
	}

	printf("\n ijkPluginCallback_unload(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_unload_hot(ijkPluginData* data, i32 f, ijkPluginData** data_out)
{
	if (*data_out)
	{
		free(*data_out);
		*data_out = 0;
	}

	printf("\n ijkPluginCallback_unload_hot(data=%p, f=%d, *data_out=%p)", data, f, (data_out ? *data_out : 0));

	return ijk_success;
}

iret ijkPluginCallback_winActivate(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_winActivate(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_winDeactivate(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_winDeactivate(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_display(ijkPluginData* data)
{
	//printf("\n ijkPluginCallback_winDisplay(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_idle(ijkPluginData* data)
{
	//printf("\n ijkPluginCallback_winIdle(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_winMove(ijkPluginData* data, i32 x, i32 y)
{
	printf("\n ijkPluginCallback_winMove(data=%p, x=%d, y=%d)", data, x, y);

	return ijk_success;
}

iret ijkPluginCallback_winResize(ijkPluginData* data, i32 w, i32 h)
{
	printf("\n ijkPluginCallback_winResize(data=%p, w=%d, h=%d)", data, w, h);

	return ijk_success;
}

iret ijkPluginCallback_keyPressVirt(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyPressVirt(data=%p, key=%d)", data, key);

	return ijk_success;
}

iret ijkPluginCallback_keyPressAscii(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyPressAscii(data=%p, key=%c)", data, (i8)key);

	return ijk_success;
}

iret ijkPluginCallback_keyHoldVirt(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyHoldVirt(data=%p, key=%d)", data, key);

	return ijk_success;
}

iret ijkPluginCallback_keyHoldAscii(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyHoldAscii(data=%p, key=%c)", data, (i8)key);

	return ijk_success;
}

iret ijkPluginCallback_keyReleaseVirt(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyReleaseVirt(data=%p, key=%d)", data, key);

	return ijk_success;
}

iret ijkPluginCallback_keyReleaseAscii(ijkPluginData* data, i32 key)
{
	//printf("\n ijkPluginCallback_keyReleaseAscii(data=%p, key=%c)", data, (i8)key);

	return ijk_success;
}

iret ijkPluginCallback_mouseClick(ijkPluginData* data, i32 btn, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseClick(data=%p, btn=%d, x=%d, y=%d)", data, btn, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseClick2(ijkPluginData* data, i32 btn, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseClick2(data=%p, btn=%d, x=%d, y=%d)", data, btn, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseRelease(ijkPluginData* data, i32 btn, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseRelease(data=%p, btn=%d, x=%d, y=%d)", data, btn, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseWheel(ijkPluginData* data, i32 dir, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseWheel(data=%p, dir=%d, x=%d, y=%d)", data, dir, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseMove(ijkPluginData* data, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseMove(data=%p, x=%d, y=%d)", data, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseDrag(ijkPluginData* data, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseDrag(data=%p, x=%d, y=%d)", data, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseEnter(ijkPluginData* data, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseEnter(data=%p, x=%d, y=%d)", data, x, y);

	return ijk_success;
}

iret ijkPluginCallback_mouseLeave(ijkPluginData* data, i32 x, i32 y)
{
	//printf("\n ijkPluginCallback_mouseLeave(data=%p, x=%d, y=%d)", data, x, y);

	return ijk_success;
}

iret ijkPluginCallback_willReload(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_willReload(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_willUnload(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_willUnload(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_user1(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_user1(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_user2(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_user2(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_user3(ijkPluginData* data)
{
	printf("\n ijkPluginCallback_user3(data=%p)", data);

	return ijk_success;
}

iret ijkPluginCallback_user4c(ijkPluginData* data, i32 const argc, byte const* const argv[])
{
	printf("\n ijkPluginCallback_user4c(data=%p, argc=%d, *argv=%s)", data, argc, (argv ? *argv : 0));

	return ijk_success;
}


//-----------------------------------------------------------------------------
