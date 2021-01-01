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
// Tag for dylib file extension.
#define IJK_DYLIB_EXT		".dll"
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
#define IJK_DYLIB_HANDLE	ptr
// Tag for symbol handle.
#define IJK_DYLIB_FUNC		ptr
// Tag for dylib file extension.
#define IJK_DYLIB_EXT		".so"
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


#endif	// !_IJK_DYLIB_H_