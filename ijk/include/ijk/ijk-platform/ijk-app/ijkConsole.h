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
typedef struct ijkConsole		ijkConsole;
typedef enum ijkConsoleColor	ijkConsoleColor;
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


// ijkConsoleColor
//	List of color codes for changing display style in console.
enum ijkConsoleColor
{
	ijkConsoleColor_off = 0x0,		// Color is disabled (black).
	ijkConsoleColor_blue = 0x1,		// Color contains blue channel.
	ijkConsoleColor_green = 0x2,	// Color contains green channel.
	ijkConsoleColor_cyan = ijkConsoleColor_green | ijkConsoleColor_blue,	// Color contains green and blue channels to form cyan.
	ijkConsoleColor_red = 0x4,		// Color contains red channel.
	ijkConsoleColor_magenta = ijkConsoleColor_blue | ijkConsoleColor_red,	// Color contains blue and red channels to form magenta.
	ijkConsoleColor_yellow = ijkConsoleColor_red | ijkConsoleColor_green,	// Color contains red and green channels to form yellow.
	ijkConsoleColor_white = ijkConsoleColor_red | ijkConsoleColor_green | ijkConsoleColor_blue,	// Color contains all primary channels.
	ijkConsoleColor_alpha = 0x8		// Color is fully opaque/intense.
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

// ijkConsoleGetCursor
//	Get position of cursor in console.
//		param x_out: pointer to value to store horizontal coordinate
//			valid: non-null
//		param y_out: pointer to value to store vertical coordinate (from top)
//			valid: non-null
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleGetCursor(i16* const x_out, i16* const y_out);

// ijkConsoleSetCursor
//	Set position of cursor in console.
//		param x: value of horizontal coordinate to set
//		param y: value of vertical coordinate to set (from top)
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleSetCursor(i16 const x, i16 const y);

// ijkConsoleToggleCursor
//	Toggle blinking underscore at cursor location.
//		param visible: visible flag; interpreted as boolean
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleToggleCursor(ibool const visible);

// ijkConsoleGetColor
//	Set color of console text.
//		param fg_out: pointer to description of foreground (character) channels
//			valid: non-null
//		param bg_out: pointer to description of background (console) channels
//			valid: non-null
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleGetColor(ijkConsoleColor* const fg_out, ijkConsoleColor* const bg_out);

// ijkConsoleSetColor
//	Set color of console text.
//		param fg: description of foreground (character) channels to use
//		param bg: description of background (console) channels to use
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleSetColor(ijkConsoleColor const fg, ijkConsoleColor const bg);

// ijkConsoleResetColor
//	Reset color of console text.
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleResetColor();

// ijkConsoleGetCursorColor
//	Get console cursor position and color.
//		param x_out: pointer to value to store horizontal coordinate
//			valid: non-null
//		param y_out: pointer to value to store vertical coordinate (from top)
//			valid: non-null
//		param fg_out: pointer to description of foreground (character) channels
//			valid: non-null
//		param bg_out: pointer to description of background (console) channels
//			valid: non-null
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleGetCursorColor(i16* const x_out, i16* const y_out, ijkConsoleColor* const fg_out, ijkConsoleColor* const bg_out);

// ijkConsoleSetCursorColor
//	Get console cursor position and color.
//		param x: value of horizontal coordinate to set
//		param y: value of vertical coordinate to set (from top)
//		param fg: description of foreground (character) channels to use
//		param bg: description of background (console) channels to use
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsoleSetCursorColor(i16 const x, i16 const y, ijkConsoleColor const fg, ijkConsoleColor const bg);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_CONSOLE_H_