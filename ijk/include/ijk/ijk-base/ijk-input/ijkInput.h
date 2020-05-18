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

	ijkInput.h
	Main input device interfaces.
*/

#ifndef _IJK_INPUT_H_
#define _IJK_INPUT_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef enum ijkMouseBtn				ijkMouseBtn;
typedef struct ijkMouseState			ijkMouseState;
typedef enum ijkKeyBtn					ijkKeyBtn;
typedef enum ijkKeyChar					ijkKeyChar;
typedef struct ijkKeyboardState			ijkKeyboardState;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkMouseBtn
//	
enum ijkMouseBtn
{
	ijkMouseBtn_left,
	ijkMouseBtn_middle,
	ijkMouseBtn_right,
	ijkMouseBtn_extra1,
	ijkMouseBtn_extra2,
	ijkMouseBtn_wheel,
};


// ijkMouseState
//	
struct ijkMouseState
{
	struct {
		sbyte button[8];
		i32 x, y;
	} state, state_prev;
};


// ijkKeyBtn
//	Enumeration of virtual keys. These are not ASCII characters, they are the 
//	codes for the actual keys. For special ASCII character codes, see below.
enum ijkKeyBtn
{
	ijkKeyBtn_null,
	ijkKeyBtn_backspace = 8,
	ijkKeyBtn_tab,
	ijkKeyBtn_clear = 12,
	ijkKeyBtn_return,
	ijkKeyBtn_enter = ijkKeyBtn_return,
	ijkKeyBtn_shift = 16,
	ijkKeyBtn_control,
	ijkKeyBtn_alt,							// not processed
	ijkKeyBtn_pause,
	ijkKeyBtn_capslock,
	ijkKeyBtn_escape = 27,
	ijkKeyBtn_esc = ijkKeyBtn_escape,
	ijkKeyBtn_space = 32,
	ijkKeyBtn_pageup,
	ijkKeyBtn_pagedown,
	ijkKeyBtn_end,
	ijkKeyBtn_home,
	ijkKeyBtn_left,
	ijkKeyBtn_up,
	ijkKeyBtn_right,
	ijkKeyBtn_down,
	ijkKeyBtn_select,
	ijkKeyBtn_print,
	ijkKeyBtn_execute,
	ijkKeyBtn_printscreen,					// processed only on release
	ijkKeyBtn_insert,
	ijkKeyBtn_delete,
	ijkKeyBtn_help,
	ijkKeyBtn_0,
	ijkKeyBtn_1,
	ijkKeyBtn_2,
	ijkKeyBtn_3,
	ijkKeyBtn_4,
	ijkKeyBtn_5,
	ijkKeyBtn_6,
	ijkKeyBtn_7,
	ijkKeyBtn_8,
	ijkKeyBtn_9,
	ijkKeyBtn_rightparen = ijkKeyBtn_0,
	ijkKeyBtn_exclamation,
	ijkKeyBtn_at,
	ijkKeyBtn_number,
	ijkKeyBtn_dollar,
	ijkKeyBtn_percent,
	ijkKeyBtn_hat,
	ijkKeyBtn_ampersand,
	ijkKeyBtn_asterisk,
	ijkKeyBtn_leftparen,
	ijkKeyBtn_A = 65,
	ijkKeyBtn_B,
	ijkKeyBtn_C,
	ijkKeyBtn_D,
	ijkKeyBtn_E,
	ijkKeyBtn_F,
	ijkKeyBtn_G,
	ijkKeyBtn_H,
	ijkKeyBtn_I,
	ijkKeyBtn_J,
	ijkKeyBtn_K,
	ijkKeyBtn_L,
	ijkKeyBtn_M,
	ijkKeyBtn_N,
	ijkKeyBtn_O,
	ijkKeyBtn_P,
	ijkKeyBtn_Q,
	ijkKeyBtn_R,
	ijkKeyBtn_S,
	ijkKeyBtn_T,
	ijkKeyBtn_U,
	ijkKeyBtn_V,
	ijkKeyBtn_W,
	ijkKeyBtn_X,
	ijkKeyBtn_Y,
	ijkKeyBtn_Z,
	ijkKeyBtn_command_left,
	ijkKeyBtn_command_right,
	ijkKeyBtn_window_left = ijkKeyBtn_command_left,
	ijkKeyBtn_window_right,
	ijkKeyBtn_menu,
	ijkKeyBtn_sleep = 95,
	ijkKeyBtn_numpad_0,
	ijkKeyBtn_numpad_1,
	ijkKeyBtn_numpad_2,
	ijkKeyBtn_numpad_3,
	ijkKeyBtn_numpad_4,
	ijkKeyBtn_numpad_5,
	ijkKeyBtn_numpad_6,
	ijkKeyBtn_numpad_7,
	ijkKeyBtn_numpad_8,
	ijkKeyBtn_numpad_9,
	ijkKeyBtn_numpad_times,
	ijkKeyBtn_numpad_plus,
	ijkKeyBtn_numpad_separator,
	ijkKeyBtn_numpad_minus,
	ijkKeyBtn_numpad_point,
	ijkKeyBtn_numpad_divide,
	ijkKeyBtn_F1,
	ijkKeyBtn_F2,
	ijkKeyBtn_F3,
	ijkKeyBtn_F4,
	ijkKeyBtn_F5,
	ijkKeyBtn_F6,
	ijkKeyBtn_F7,
	ijkKeyBtn_F8,
	ijkKeyBtn_F9,
	ijkKeyBtn_F10,							// not processed
	ijkKeyBtn_F11,
	ijkKeyBtn_F12,
	ijkKeyBtn_F13,
	ijkKeyBtn_F14,
	ijkKeyBtn_F15,
	ijkKeyBtn_F16,
	ijkKeyBtn_F17,
	ijkKeyBtn_F18,
	ijkKeyBtn_F19,
	ijkKeyBtn_F20,
	ijkKeyBtn_F21,
	ijkKeyBtn_F22,
	ijkKeyBtn_F23,
	ijkKeyBtn_F24,
	ijkKeyBtn_numlock = 144,
	ijkKeyBtn_scrolllock,
	ijkKeyBtn_numpad_equal,
	ijkKeyBtn_shift_left = 160,				// not processed with callbacks
	ijkKeyBtn_shift_right,					// not processed with callbacks
	ijkKeyBtn_control_left,					// not processed with callbacks
	ijkKeyBtn_control_right,				// not processed with callbacks
	ijkKeyBtn_menu_left,					// not processed with callbacks
	ijkKeyBtn_menu_right,					// not processed with callbacks
	ijkKeyBtn_browser_back,
	ijkKeyBtn_browser_forward,
	ijkKeyBtn_browser_refresh,
	ijkKeyBtn_browser_stop,
	ijkKeyBtn_browser_search,
	ijkKeyBtn_browser_favorites,
	ijkKeyBtn_browser_home,
	ijkKeyBtn_media_mute,
	ijkKeyBtn_media_volumedown,
	ijkKeyBtn_media_volumeup,
	ijkKeyBtn_media_next,
	ijkKeyBtn_media_prev,
	ijkKeyBtn_media_stop,
	ijkKeyBtn_media_playpause,
	ijkKeyBtn_launch_email,
	ijkKeyBtn_launch_media,
	ijkKeyBtn_launch_app1,
	ijkKeyBtn_launch_app2,
	ijkKeyBtn_semicolon = 186,
	ijkKeyBtn_equal,
	ijkKeyBtn_comma,
	ijkKeyBtn_dash,
	ijkKeyBtn_period,
	ijkKeyBtn_slash,
	ijkKeyBtn_colon = ijkKeyBtn_semicolon,
	ijkKeyBtn_minus = ijkKeyBtn_dash,
	ijkKeyBtn_plus,
	ijkKeyBtn_lessthan,
	ijkKeyBtn_underscore,
	ijkKeyBtn_greaterthan,
	ijkKeyBtn_question,
	ijkKeyBtn_tilde,
	ijkKeyBtn_leftbracket = 219,
	ijkKeyBtn_backslash,
	ijkKeyBtn_rightbracket,
	ijkKeyBtn_singlequote,
	ijkKeyBtn_leftbrace = ijkKeyBtn_leftbracket,
	ijkKeyBtn_pipe,
	ijkKeyBtn_rightbrace,
	ijkKeyBtn_doublequote,
	ijkKeyBtn_quote = ijkKeyBtn_singlequote,
	ijkKeyBtn_apostrophe = ijkKeyBtn_singlequote,
	ijkKeyBtn_function = 255
};


// ijkKeyChar
//	Enumeration of ASCII character keys. These are for special keys that are 
//	accompanied/represented by ASCII codes and respond to character key 
//	callbacks. If a key can be represented by a character, the enum can be 
//	replaced with the literal character (e.g. 'a'); otherwise, use the enum 
//	codes to check the state of an ASCII key.
enum ijkKeyChar
{
	ijkKeyChar_null,
	ijkKeyChar_ctrl_a,						// ctrl + 'a'
	ijkKeyChar_ctrl_b,						// ctrl + 'b'
	ijkKeyChar_ctrl_c,						// ctrl + 'c' etc.
	ijkKeyChar_ctrl_d,
	ijkKeyChar_ctrl_e,
	ijkKeyChar_ctrl_f,
	ijkKeyChar_ctrl_g,
	ijkKeyChar_ctrl_h,
	ijkKeyChar_ctrl_i,
	ijkKeyChar_ctrl_j,
	ijkKeyChar_ctrl_k,
	ijkKeyChar_ctrl_l,
	ijkKeyChar_ctrl_m,
	ijkKeyChar_ctrl_n,
	ijkKeyChar_ctrl_o,
	ijkKeyChar_ctrl_p,
	ijkKeyChar_ctrl_q,
	ijkKeyChar_ctrl_r,
	ijkKeyChar_ctrl_s,
	ijkKeyChar_ctrl_t,
	ijkKeyChar_ctrl_u,
	ijkKeyChar_ctrl_v,
	ijkKeyChar_ctrl_w,
	ijkKeyChar_ctrl_x,
	ijkKeyChar_ctrl_y,
	ijkKeyChar_ctrl_z,
	ijkKeyChar_ctrl_leftbracket,			// ctrl + '['
	ijkKeyChar_ctrl_backslash,				// ctrl + '\'
	ijkKeyChar_ctrl_rightbracket,			// ctrl + ']'
	ijkKeyChar_ctrl_pause = 3,				// ctrl + pause
	ijkKeyChar_ctrl_scrolllock = 3,			// ctrl + scrolllock
	ijkKeyChar_alert = 7,					// '\a'
	ijkKeyChar_backspace,					// '\b'
	ijkKeyChar_tab,							// '\t'
	ijkKeyChar_newline,						// '\n' or ctrl + enter
	ijkKeyChar_tab_vert,					// '\v'
	ijkKeyChar_formfeed,					// '\f'
	ijkKeyChar_return,						// '\r'
	ijkKeyChar_tab_horiz = ijkKeyChar_tab,
	ijkKeyChar_ctrl_enter,
	ijkKeyChar_enter = ijkKeyChar_return,
	ijkKeyChar_escape = 27,
	ijkKeyChar_ctrl_backspace = 127
};


// ijkKeyboardState
//	
struct ijkKeyboardState
{
	struct {
		sbyte key[256];
		sbyte keyChar[128];
	} state, state_prev;
};


//-----------------------------------------------------------------------------

// ijkInputGetSystemCursor
//	Get the cursor position at the system level.
//		param x_out: pointer to horizontal position of cursor
//			note: [0, w) = [left, right)
//		param y_out: pointer to vertical position of cursor
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not get position
iret ijkInputGetSystemCursor(i32* x_out, i32* y_out);

// ijkInputSetSystemCursor
//	Set the cursor position at the system level.
//		param x: horizontal position of cursor
//			note: [0, w) = [left, right)
//		param y: vertical position of cursor
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not set position
iret ijkInputSetSystemCursor(i32 const x, i32 const y);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkInput.inl"


#endif	// !_IJK_INPUT_H_