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

	ijkConsole.h
	Console management interface.
*/

#ifndef _IJK_CONSOLE_H_
#define _IJK_CONSOLE_H_

#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijk_warn_console_exist
//	Console warning indicating that console cannot be created because one 
//	already exists, or deleted because one does not exist.
#define ijk_warn_console_exist	ijk_warncode(0x1)

// eprintf
//	Shorthand macro for outputting formatted string to standard error.
#define eprintf(fmt, ...)		fprintf(stderr, fmt, __VA_ARGS__)

// dprintf
//	Shorthand macro for outputting formatted string to debugging interface.
#define dprintf(fmt, ...)		ijkConsolePrintDebug(fmt, __VA_ARGS__)


// ijkConsole
//	Descriptor for console instance.
//		member handle: internal handle data
//		member io: internal i/o flags
typedef struct ijkConsole
{
	ptr handle[4];
	i32 io[3];
} ijkConsole;


// ijkConsoleColor
//	List of color codes for changing display style in console.
typedef enum ijkConsoleColor
{
	// Channels.
	///
	ijkConsoleColor_0 = 0x0,	// Color is disabled.
	ijkConsoleColor_b = 0x1,	// Color contains blue channel.
	ijkConsoleColor_g = 0x2,	// Color contains green channel.
	ijkConsoleColor_gb,			// Color contains green and blue channels.
	ijkConsoleColor_r = 0x4,	// Color contains red channel.
	ijkConsoleColor_br,			// Color contains blue and red channels.
	ijkConsoleColor_rg,			// Color contains red and green channels.
	ijkConsoleColor_rgb,		// Color contains red, green and blue channels.
	ijkConsoleColor_a = 0x8,	// Color is fully opaque/intense.

	// Colors.
	///
	ijkConsoleColor_black = ijkConsoleColor_0,	// Black:           (0, 0, 0, 0)
	ijkConsoleColor_blue_d,						// Blue (dark):     (0, 0, 1, 0)
	ijkConsoleColor_green_d,					// Green (dark):    (0, 1, 0, 0)
	ijkConsoleColor_cyan_d,						// Cyan (dark):     (0, 1, 1, 0)
	ijkConsoleColor_red_d,						// Red (dark):      (1, 0, 0, 0)
	ijkConsoleColor_magenta_d,					// Magenta (dark):  (1, 0, 1, 0)
	ijkConsoleColor_yellow_d,					// Yellow (dark):   (1, 1, 0, 0)
	ijkConsoleColor_grey,						// Grey:            (1, 1, 1, 0)
	ijkConsoleColor_grey_d,						// Grey (dark):     (0, 0, 0, 1)
	ijkConsoleColor_blue,						// Blue:            (0, 0, 1, 1)
	ijkConsoleColor_green,						// Green:           (0, 1, 0, 1)
	ijkConsoleColor_cyan,						// Cyan:            (0, 1, 1, 1)
	ijkConsoleColor_red,						// Red:             (1, 0, 0, 1)
	ijkConsoleColor_magenta,					// Magenta:         (1, 0, 1, 1)
	ijkConsoleColor_yellow,						// Yellow:          (1, 1, 0, 1)
	ijkConsoleColor_white,						// White:           (1, 1, 1, 1)
} ijkConsoleColor;


//-----------------------------------------------------------------------------

// ijkConsoleCreateMain
//	Create and initialize console instance for the main process; redirects 
//	standard input and output to new console (excludes standard error).
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
iret ijkConsoleRedirectMain(ijkConsole* const console, bool const redirectInput, bool const redirectOutput, bool const redirectError);

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
iret ijkConsoleToggleCursor(bool const visible);

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

// ijkConsoleDrawTestPatch
//	Display test patch in console.
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleDrawTestPatch();

// ijkConsoleClear
//	Clear console, erasing text and setting background to set color.
//		return SUCCESS: ijk_success if operation succeeded
//		return FAILURE: ijk_fail_operationfail if operation failed
iret ijkConsoleClear();


//-----------------------------------------------------------------------------

// ijkConsolePrintDebug
//	Print formatted string to debugging interface.
//		param format: format string, as used with standard 'printf'
//			valid: non-null c-string
//		params ...: parameter list matching specifications in 'format'
//		return SUCCESS: result of internal print operation if succeeded
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkConsolePrintDebug(kstr const format, ...);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_CONSOLE_H_