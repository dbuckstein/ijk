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

	ijk-dylib.h
	Multi-platform dynamic library configuration utility for importing and 
	exporting symbols.
*/

#ifndef _IJK_DYLIB_H_
#define _IJK_DYLIB_H_

#include "ijk/ijk/ijk-typedefs.h"


//-----------------------------------------------------------------------------

#if ijk_platform_is(WINDOWS)

// Export symbol to dylib.
#define IJK_DYLIB_EXPORT	__declspec(dllexport)
// Import symbol from dylib.
#define IJK_DYLIB_IMPORT	__declspec(dllimport)
// Tag for dylib handle.
#define IJK_DYLIB_HANDLE	HMODULE
// Tag for symbol handle.
#define IJK_DYLIB_FUNC		FARPROC
// Tag for loading dylib.
#define IJK_DYLIB_LOAD(dylib_path)		LoadLibraryA(dylib_path)
// Tag for unloading dylib.
#define IJK_DYLIB_UNLOAD(dylib_handle)	FreeLibrary(dylib_handle)
// Tag for getting symbol from dylib.
#define IJK_DYLIB_GETFUNC(dylib_handle, symbol_name)	GetProcAddress(dylib_handle, symbol_name)

#else	// !WINDOWS

// Export symbol to dylib.
#define IJK_DYLIB_EXPORT	__attribute__((visibility("default")))
// Import symbol from dylib.
#define IJK_DYLIB_IMPORT	__attribute__((weak_import))
// Tag for dylib handle.
#define IJK_DYLIB_HANDLE	void*
// Tag for symbol handle.
#define IJK_DYLIB_FUNC		void*
// Tag for loading dylib.
#define IJK_DYLIB_LOAD(dylib_path)		dlopen(dylib_path, RTLD_NOW)
// Tag for unloading dylib.
#define IJK_DYLIB_UNLOAD(dylib_handle)	dlclose(dylib_handle)
// Tag for getting symbol from dylib.
#define IJK_DYLIB_GETFUNC(dylib_handle, symbol_name)	dlsym(dylib_handle, symbol_name)
#endif	// WINDOWS


// universal export/import tag definition
#ifdef IJK_PLUGIN_EXPORTS
#define IJK_DYLIB_SYMBOL	IJK_DYLIB_EXPORT
#else	// !IJK_PLUGIN_EXPORTS
#ifdef IJK_PLUGIN_IMPORTS
#define IJK_DYLIB_SYMBOL	IJK_DYLIB_IMPORT
#else	// !IJK_PLUGIN_IMPORTS
#define IJK_DYLIB_SYMBOL	
#endif	// IJK_PLUGIN_IMPORTS
#endif	// IJK_PLUGIN_EXPORTS


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
iret ijkDylibLoad(IJK_DYLIB_HANDLE* const handle_out, kcstr const dylibPath);

// ijkDylibUnload
//	Call dynamic library unload.
//		param handle: library handle
//			valid: non-null
//		return SUCCESS: ijk_success if library unloaded
//		return FAILURE: ijk_fail_operationfail if library not loaded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkDylibUnload(IJK_DYLIB_HANDLE const handle);

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
iret ijkDylibGetSymbol(IJK_DYLIB_FUNC* const symbol_out, IJK_DYLIB_HANDLE const handle, kcstr const symbolName);


//-----------------------------------------------------------------------------


#include "_inl/ijk-dylib.inl"


#endif	// !_IJK_DYLIB_H_