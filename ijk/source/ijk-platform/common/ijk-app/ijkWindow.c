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
