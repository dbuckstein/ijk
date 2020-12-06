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

	ijkConsole.h
	Console management interface.
*/

#ifndef _IJK_CONSOLE_H_
#define _IJK_CONSOLE_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef struct ijkConsole ijkConsole;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_warn_console_exist
//	Console warning indicating that console cannot be created because one 
//	already exists, or deleted because one does not exist.
#define ijk_warn_console_exist	ijk_warncode(0x1)


// ijkConsole
//	Descriptor for console instance.
//		member handle: internal handle data
//		member io: internal i/o flags
struct ijkConsole
{
	ptr handle[4];
	i32 io[3];
};


//-----------------------------------------------------------------------------

// ijkConsoleCreateMain
//	Create and initialize console instance for the main process.
//		param console: pointer to descriptor that stores console info
//			valid: non-null
//		return SUCCESS: ijk_success if console successfully initialized
//		return WARNING: ijk_warn_console_exist if console already initialized
//		return FAILURE: ijk_fail_operationfail if console not initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleCreateMain(ijkConsole* const console);

// ijkConsoleRedirectMain
//	Redirect standard pipes to console or default.
//		param console: pointer to descriptor that stores console info
//			valid: non-null
//		param redirectInput: option to redirect standard input to console
//		param redirectOutput: option to redirect standard output to console
//		param redirectError: option to redirect standard error to console
//		return SUCCESS: ijk_success if console successfully redirected
//		return FAILURE: ijk_fail_operationfail if console not redirected
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleRedirectMain(ijkConsole* const console, ibool const redirectInput, ibool const redirectOutput, ibool const redirectError);

// ijkConsoleReleaseMain
//	Terminate and release console instance for the main process.
//		param console: pointer to descriptor that stores console info
//			valid: non-null
//		return SUCCESS: ijk_success if console successfully terminated
//		return WARNING: ijk_warn_console_exist if console not initialized
//		return FAILURE: ijk_fail_operationfail if console not terminated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleReleaseMain(ijkConsole* const console);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_CONSOLE_H_