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

	ijk-dylib.c
	Dynamic library configuration.
*/

#ifndef _IJK_DYLIB_H_
#define _IJK_DYLIB_H_


// platform-specific tags
#if (defined _WINDOWS || defined _WIN32 || !defined __GNUC__)
// Windows / non-GNU-C
#define IJK_DYLIB_EXPORT __declspec(dllexport)
#define IJK_DYLIB_IMPORT __declspec(dllimport)
#else	// !(defined _WINDOWS || defined _WIN32 || !defined __GNUC__)
// Unix (Mac/Linux) / GNU-C
#define IJK_DYLIB_EXPORT __attribute__((visibility("default")))
#define IJK_DYLIB_IMPORT __attribute__((weak_import))
#endif	// (defined _WINDOWS || defined _WIN32 || !defined __GNUC__)


// universal export/import tag definition
#ifdef IJK_PLUGIN_EXPORTS
#define IJK_DYLIB_SYMBOL IJK_DYLIB_EXPORT
#else	// !IJK_PLUGIN_EXPORTS
#ifdef IJK_PLUGIN_IMPORTS
#define IJK_DYLIB_SYMBOL IJK_DYLIB_IMPORT
#else	// !IJK_PLUGIN_IMPORTS
#define IJK_DYLIB_SYMBOL 
#endif	// IJK_PLUGIN_IMPORTS
#endif	// IJK_PLUGIN_EXPORTS


#endif	// !_IJK_DYLIB_H_