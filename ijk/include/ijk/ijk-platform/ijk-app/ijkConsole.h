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

// ijk_warn_console_dummy
//	Console warning indicating that a "dummy console" (no in/out) was created.
#define ijk_warn_console_dummy	ijk_warncode(0x1)


// ijkConsole
//	Descriptor for console instance.
//		member handle: internal handle data
//		member io: input/output flags
struct ijkConsole
{
	ptr handle[2];
	i32 io;
};


//-----------------------------------------------------------------------------

// ijkConsoleCreate
//	Create and initialize console instance.
//		param console_out: pointer to console descriptor
//			valid: non-null, uninitialized
//		param input: boolean flag to allow receiving input
//		param output: boolean flag to allow displaying output
//		param error: boolean flag to allow displaying error output
//		return SUCCESS: ijk_success if console successfully initialized
//		return WARNING: ijk_warn_console_dummy if created dummy console (no IO)
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if console not initialized
iret ijkConsoleCreate(ijkConsole* const console_out, ibool const input, ibool const output, ibool const error);

// ijkConsoleCreateMain
//	Create and initialize console instance for the main process.
//		param input: boolean flag to allow receiving input
//		param output: boolean flag to allow displaying output
//		param error: boolean flag to allow displaying error output
//		return SUCCESS: ijk_success if console successfully initialized
//		return WARNING: ijk_warn_console_dummy if created dummy console (no IO)
//		return FAILURE: ijk_fail_operationfail if console not initialized
iret ijkConsoleCreateMain(ibool const input, ibool const output, ibool const error);

// ijkConsoleRelease
//	Terminate and release console instance.
//		return SUCCESS: ijk_success if console successfully initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if console not terminated
iret ijkConsoleRelease(ijkConsole* const console);

// ijkConsoleReleaseMain
//	Terminate and release console instance for the main process.
//		return SUCCESS: ijk_success if console successfully initialized
//		return FAILURE: ijk_fail_operationfail if console not terminated
iret ijkConsoleReleaseMain();

// ijkConsoleActivate
//	Activate console for interaction.
//		param console: pointer to console descriptor to activate
//			valid: non-null, initialized
//		return SUCCESS: ijk_success if console successfully initialized
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if console not terminated
iret ijkConsoleActivate(ijkConsole const* const console);

// ijkConsoleDeactivate
//	Deactivate any console, allowing user to interact with main process 
//	console if one is open.
//		return SUCCESS: ijk_success if console successfully initialized
//		return FAILURE: ijk_fail_operationfail if console not terminated
iret ijkConsoleDeactive();


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_CONSOLE_H_