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

	ijkInput.c
	Input implementation.
*/

#include "ijk/ijk-base/ijk-input/ijkInput.h"


#if ijk_platform_is(WINDOWS)
#include <Windows.h>
#else	// !WINDOWS

#endif	// WINDOWS


//-----------------------------------------------------------------------------

iret ijkInputGetSystemCursor(i32 x_out[1], i32 y_out[1])
{
	if (x_out && y_out)
	{
		iret result = 0;
#if ijk_platform_is(WINDOWS)
		POINT p[1];
		result = GetCursorPos(p);
		if (result)
		{
			*x_out = p->x;
			*y_out = p->y;
			return ijk_success;
		}
#else	// !WINDOWS

#endif	// WINDOWS
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkInputSetSystemCursor(i32 const x, i32 const y)
{
	iret result = 0;
#if ijk_platform_is(WINDOWS)
	result = SetCursorPos(x, y);
	if (result)
		return ijk_success;
#else	// !WINDOWS

#endif	// WINDOWS
	return ijk_fail_operationfail;
}


iret ijkInputGetSystemKeyboardState(sbyte keys_out[256])
{
	if (keys_out)
	{
		iret result = 0;
#if ijk_platform_is(WINDOWS)
		result = GetKeyboardState((pbyte)keys_out);
		if (result)
			return ijk_success;
#else	// !WINDOWS

#endif	// WINDOWS
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkInputGetSystemKeyState(sbyte key_out[1], ijkKeyVirt const keyVirt)
{
	if (key_out)
	{
#if ijk_platform_is(WINDOWS)
		word const result = GetAsyncKeyState(keyVirt);
		if (result)
		{
			*key_out = ijk_istrue(result & (word)(1 << 15));
			return ijk_success;
		}
#else	// !WINDOWS

#endif	// WINDOWS
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
