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

	ijk-config.h
	Common configuation.
*/

#ifndef _IJK_CONFIG_H_
#define _IJK_CONFIG_H_


// set macro for architecture
///
#if (defined _M_IX86 || defined __i386__)		// 32-bit
#define __ijk_cfg_instrset				x86
#define __ijk_cfg_archbits				32

#elif (defined _M_X64 || defined __x86_64__)	// 64-bit
#define __ijk_cfg_instrset				x86_64
#define __ijk_cfg_archbits				64

#else											// !32-/64-bit
#error "ERROR: UNKNOWN/INVALID INSTRUCTION SET AND ARCHITECTURE"

#endif	// 32-/64-bit


// set development platform
///
#if (defined _WIN32)	// Windows, MSVC
#define __ijk_cfg_platform				WINDOWS
#define __ijk_cfg_compiler				MSVC

#else
#error "ERROR: UNKNOWN/INVALID PLATFORM AND COMPILER"

#endif	// platform


// set build configuration
///
#if (defined _DEBUG && !defined NDEBUG)
#define __ijk_cfg_buildcfg				Debug
#else
#define __ijk_cfg_buildcfg				Release
#endif	// config


// global config macros
///
#define __ijk_cfg_tokenstr(x)			#x
#define __ijk_cfg_tokencat(x, y)		x##y


#endif	// !_IJK_CONFIG_H_