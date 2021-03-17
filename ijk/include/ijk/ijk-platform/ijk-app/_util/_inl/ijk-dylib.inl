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

	ijk-dylib.inl
	Dynamic library configuration.
*/

#ifndef _IJK_DYLIB_INL_
#define _IJK_DYLIB_INL_
#include "../ijk-dylib.h"

//-----------------------------------------------------------------------------

// ijkDylibLoad
//	Call dynamic library load.
//		param handle_out: pointer to library handle
//			valid: non-null, points at null
//		param dylibPath: string representing path to library
//			valid: non-null, non-empty
//		return SUCCESS: ijk_success if library loaded; handle_out points to 
//			non-null, valid library handle
//		return FAILURE: ijk_fail_operationfail if library not loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
ijk_inl iret ijkDylibLoad(IJK_DYLIB_HANDLE* const handle_out, kstr const dylibPath)
{
	if (handle_out && dylibPath && !*handle_out && *dylibPath)
	{
		IJK_DYLIB_HANDLE const handle = IJK_DYLIB_LOAD(dylibPath);
		if (handle)
		{
			*handle_out = handle;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

// ijkDylibUnload
//	Call dynamic library unload.
//		param handle: library handle
//			valid: non-null
//		return SUCCESS: ijk_success if library unloaded
//		return FAILURE: ijk_fail_operationfail if library not loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
ijk_inl iret ijkDylibUnload(IJK_DYLIB_HANDLE const handle)
{
	if (handle)
	{
		if (IJK_DYLIB_UNLOAD(handle))
			return ijk_success;
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}

// ijkDylibGetSymbol
//	Call dynamic library get symbol.
//		param symbol_out: pointer to function handle
//			valid: non-null, points at null
//		param handle: library handle
//			valid: non-null
//		param symbolName: string representing name of symbol in library
//			valid: non-null, non-empty
//		return SUCCESS: ijk_success if symbol loaded; symbol_out points to 
//			non-null, valid function pointer
//		return FAILURE: ijk_fail_operationfail if empty not loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
ijk_inl iret ijkDylibGetSymbol(IJK_DYLIB_FUNC* const symbol_out, IJK_DYLIB_HANDLE const handle, kstr const symbolName)
{
	if (symbol_out && handle && symbolName && !*symbol_out && *symbolName)
	{
		IJK_DYLIB_FUNC const symbol = IJK_DYLIB_GETFUNC(handle, symbolName);
		if (symbol)
		{
			*symbol_out = symbol;
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_DYLIB_INL_