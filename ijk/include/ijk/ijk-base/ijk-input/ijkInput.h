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
typedef enum ijkKeyVirt					ijkKeyVirt;
typedef enum ijkKeyChar					ijkKeyChar;
typedef struct ijkMouseState			ijkMouseState;
typedef struct ijkKeyboardState			ijkKeyboardState;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkMouseBtn
//	Enumeration of mouse buttons.
enum ijkMouseBtn
{
	ijkMouseBtn_left,
	ijkMouseBtn_middle,
	ijkMouseBtn_right,
	ijkMouseBtn_extra1,
	ijkMouseBtn_extra2,
};


// ijkKeyVirt
//	Enumeration of virtual keys. These are not ASCII characters, they are the 
//	codes for the actual keys. For special ASCII character codes, see below.
enum ijkKeyVirt
{
	ijkKeyVirt_null,
	ijkKeyVirt_backspace = 8,
	ijkKeyVirt_tab,
	ijkKeyVirt_clear = 12,
	ijkKeyVirt_return,
	ijkKeyVirt_enter = ijkKeyVirt_return,
	ijkKeyVirt_shift = 16,
	ijkKeyVirt_control,
	ijkKeyVirt_alt,							// not processed
	ijkKeyVirt_pause,
	ijkKeyVirt_capslock,
	ijkKeyVirt_escape = 27,
	ijkKeyVirt_esc = ijkKeyVirt_escape,
	ijkKeyVirt_space = 32,
	ijkKeyVirt_pageup,
	ijkKeyVirt_pagedown,
	ijkKeyVirt_end,
	ijkKeyVirt_home,
	ijkKeyVirt_left,
	ijkKeyVirt_up,
	ijkKeyVirt_right,
	ijkKeyVirt_down,
	ijkKeyVirt_select,
	ijkKeyVirt_print,
	ijkKeyVirt_execute,
	ijkKeyVirt_printscreen,					// processed only on release
	ijkKeyVirt_insert,
	ijkKeyVirt_delete,
	ijkKeyVirt_help,
	ijkKeyVirt_0,
	ijkKeyVirt_1,
	ijkKeyVirt_2,
	ijkKeyVirt_3,
	ijkKeyVirt_4,
	ijkKeyVirt_5,
	ijkKeyVirt_6,
	ijkKeyVirt_7,
	ijkKeyVirt_8,
	ijkKeyVirt_9,
	ijkKeyVirt_rightparen = ijkKeyVirt_0,
	ijkKeyVirt_exclamation,
	ijkKeyVirt_at,
	ijkKeyVirt_number,
	ijkKeyVirt_dollar,
	ijkKeyVirt_percent,
	ijkKeyVirt_hat,
	ijkKeyVirt_ampersand,
	ijkKeyVirt_asterisk,
	ijkKeyVirt_leftparen,
	ijkKeyVirt_A = 65,
	ijkKeyVirt_B,
	ijkKeyVirt_C,
	ijkKeyVirt_D,
	ijkKeyVirt_E,
	ijkKeyVirt_F,
	ijkKeyVirt_G,
	ijkKeyVirt_H,
	ijkKeyVirt_I,
	ijkKeyVirt_J,
	ijkKeyVirt_K,
	ijkKeyVirt_L,
	ijkKeyVirt_M,
	ijkKeyVirt_N,
	ijkKeyVirt_O,
	ijkKeyVirt_P,
	ijkKeyVirt_Q,
	ijkKeyVirt_R,
	ijkKeyVirt_S,
	ijkKeyVirt_T,
	ijkKeyVirt_U,
	ijkKeyVirt_V,
	ijkKeyVirt_W,
	ijkKeyVirt_X,
	ijkKeyVirt_Y,
	ijkKeyVirt_Z,
	ijkKeyVirt_command_left,
	ijkKeyVirt_command_right,
	ijkKeyVirt_window_left = ijkKeyVirt_command_left,
	ijkKeyVirt_window_right,
	ijkKeyVirt_menu,
	ijkKeyVirt_sleep = 95,
	ijkKeyVirt_numpad_0,
	ijkKeyVirt_numpad_1,
	ijkKeyVirt_numpad_2,
	ijkKeyVirt_numpad_3,
	ijkKeyVirt_numpad_4,
	ijkKeyVirt_numpad_5,
	ijkKeyVirt_numpad_6,
	ijkKeyVirt_numpad_7,
	ijkKeyVirt_numpad_8,
	ijkKeyVirt_numpad_9,
	ijkKeyVirt_numpad_times,
	ijkKeyVirt_numpad_plus,
	ijkKeyVirt_numpad_separator,
	ijkKeyVirt_numpad_minus,
	ijkKeyVirt_numpad_point,
	ijkKeyVirt_numpad_divide,
	ijkKeyVirt_F1,
	ijkKeyVirt_F2,
	ijkKeyVirt_F3,
	ijkKeyVirt_F4,
	ijkKeyVirt_F5,
	ijkKeyVirt_F6,
	ijkKeyVirt_F7,
	ijkKeyVirt_F8,
	ijkKeyVirt_F9,
	ijkKeyVirt_F10,							// not processed
	ijkKeyVirt_F11,
	ijkKeyVirt_F12,
	ijkKeyVirt_F13,
	ijkKeyVirt_F14,
	ijkKeyVirt_F15,
	ijkKeyVirt_F16,
	ijkKeyVirt_F17,
	ijkKeyVirt_F18,
	ijkKeyVirt_F19,
	ijkKeyVirt_F20,
	ijkKeyVirt_F21,
	ijkKeyVirt_F22,
	ijkKeyVirt_F23,
	ijkKeyVirt_F24,
	ijkKeyVirt_numlock = 144,
	ijkKeyVirt_scrolllock,
	ijkKeyVirt_numpad_equal,
	ijkKeyVirt_shift_left = 160,				// not processed with callbacks
	ijkKeyVirt_shift_right,					// not processed with callbacks
	ijkKeyVirt_control_left,					// not processed with callbacks
	ijkKeyVirt_control_right,				// not processed with callbacks
	ijkKeyVirt_menu_left,					// not processed with callbacks
	ijkKeyVirt_menu_right,					// not processed with callbacks
	ijkKeyVirt_browser_back,
	ijkKeyVirt_browser_forward,
	ijkKeyVirt_browser_refresh,
	ijkKeyVirt_browser_stop,
	ijkKeyVirt_browser_search,
	ijkKeyVirt_browser_favorites,
	ijkKeyVirt_browser_home,
	ijkKeyVirt_media_mute,
	ijkKeyVirt_media_volumedown,
	ijkKeyVirt_media_volumeup,
	ijkKeyVirt_media_next,
	ijkKeyVirt_media_prev,
	ijkKeyVirt_media_stop,
	ijkKeyVirt_media_playpause,
	ijkKeyVirt_launch_email,
	ijkKeyVirt_launch_media,
	ijkKeyVirt_launch_app1,
	ijkKeyVirt_launch_app2,
	ijkKeyVirt_semicolon = 186,
	ijkKeyVirt_equal,
	ijkKeyVirt_comma,
	ijkKeyVirt_dash,
	ijkKeyVirt_period,
	ijkKeyVirt_slash,
	ijkKeyVirt_colon = ijkKeyVirt_semicolon,
	ijkKeyVirt_minus = ijkKeyVirt_dash,
	ijkKeyVirt_plus,
	ijkKeyVirt_lessthan,
	ijkKeyVirt_underscore,
	ijkKeyVirt_greaterthan,
	ijkKeyVirt_question,
	ijkKeyVirt_tilde,
	ijkKeyVirt_leftbracket = 219,
	ijkKeyVirt_backslash,
	ijkKeyVirt_rightbracket,
	ijkKeyVirt_singlequote,
	ijkKeyVirt_leftbrace = ijkKeyVirt_leftbracket,
	ijkKeyVirt_pipe,
	ijkKeyVirt_rightbrace,
	ijkKeyVirt_doublequote,
	ijkKeyVirt_quote = ijkKeyVirt_singlequote,
	ijkKeyVirt_apostrophe = ijkKeyVirt_singlequote,
	ijkKeyVirt_function = 255
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


// ijkMouseState
//	Mouse state tracker descriptor.
//		member state: current state of mouse
//		member state_prev: previous state of mouse
//		member button: within states, flags to describe button states
//		member x: within states, horizontal coordinate of cursor
//		member y: within states, vertical coordinate of cursor
struct ijkMouseState
{
	struct {
		sbyte button[8];		// button state flags
		i32 x, y;				// screen coordinate of cursor
	} state, state_prev;		// current and previous states
};


// ijkKeyboardState
//	Keyboard state tracker descriptor.
//		member state: current state of keyboard
//		member state_prev: previous state of keyboard
//		member key: within states, flags to describe virtual key states
//		member keyChar: within states, flags to describe ASCII/char key states
struct ijkKeyboardState
{
	struct {
		sbyte key[256];			// virtual key state flags
		sbyte keyChar[128];		// ASCII/char key state flags
	} state, state_prev;		// current and previous states
};


//-----------------------------------------------------------------------------

// ijkMouseGetButtonState
//	Get the current state of a mouse button.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state_out: pointer to button state
//			valid: non-null
//			note: upon successful return, points to boolean (true is pressed)
//		param button: button enumerator
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseSetButtonState
//	Set the current state of a mouse button.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state: button state to set
//		param button: button enumerator
//		return SUCCESS: ijk_success if set state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetWheelState
//	Get the current state of the mouse wheel.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state_out: pointer to wheel state
//			valid: non-null
//			note: upon successful return, points to wheel state value
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseSetWheelState
//	Set the current state of the mouse wheel.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state: wheel state to set
//		return SUCCESS: ijk_success if set state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetButtonStatePrev
//	Get the previous state of a mouse button.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state_out: pointer to button state
//			valid: non-null
//			note: upon successful return, points to boolean (true is pressed)
//		param button: button enumerator
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetWheelStatePrev
//	Get the previous state of the mouse wheel.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state_out: pointer to wheel state
//			valid: non-null
//			note: upon successful return, points to wheel state value
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonDown
//	Check whether a mouse button is down.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button is down
//		return SUCCESS: ijk_false if button is up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonUp
//	Check whether a mouse button is up.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button is up
//		return SUCCESS: ijk_false if button is down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonDownAgain
//	Check whether a mouse button is consistently down between updates.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button is consistently down
//		return SUCCESS: ijk_false if button is not consistently down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonUpAgain
//	Check whether a mouse button is consistently up between updates.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button is consistently up
//		return SUCCESS: ijk_false if button is not consistently up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonPressed
//	Check whether a mouse button changed from up to down.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button changed from up to down
//		return SUCCESS: ijk_false if button did not change from up to down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseIsButtonReleased
//	Check whether a mouse button changed from down to up.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if button changed from down to up
//		return SUCCESS: ijk_false if button did not change from down to up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetWheelChange
//	Get the change in the mouse wheel state.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param state_out: pointer to wheel state
//			valid: non-null
//			note: upon successful return, points to wheel change value
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetPos
//	Get the current position of the cursor.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param x_out: pointer to horizontal position of cursor
//			valid: non-null
//			note: [0, w) = [left, right)
//		param y_out: pointer to vertical position of cursor
//			valid: non-null
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseSetPos
//	Set the current position of the cursor.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param x: horizontal position of cursor
//			note: [0, w) = [left, right)
//		param y: vertical position of cursor
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseGetPosPrev
//	Get the previous position of the cursor.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		param x_out: pointer to horizontal position of cursor
//			valid: non-null
//			note: [0, w) = [left, right)
//		param y_out: pointer to vertical position of cursor
//			valid: non-null
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseUpdate
//	Copy the current state to the previous state.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state updated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkMouseReset
//	Reset the current state.
//		param mouse: pointer to mouse descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state reset
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


//-----------------------------------------------------------------------------

// ijkKeyboardGetKeyState
//	Get the current state of a virtual key.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		param state_out: pointer to button state
//			valid: non-null
//			note: upon successful return, points to boolean (true is pressed)
//		param keyVirt: virtual key code
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardSetKeyState
//	Set the current state of a virtual key.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardGetKeyCharState
//	Get the current state of a character/ASCII key.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardSetKeyCharState
//	Set the current state of a character/ASCII key.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyDown
//	Check whether key is down.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyUp
//	Check whether key is up.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyDownAgain
//	Check whether key is consistently down between updates.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyUpAgain
//	Check whether key is consistently up between updates.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyPressed
//	Check whether key changed from up to down.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyReleased
//	Check whether key changed from down to up.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharDown
//	Check whether character key is down.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharUp
//	Check whether character key is up.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharDownAgain
//	Check whether character key is consistently down between updates.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharUpAgain
//	Check whether character key is consistently up between updates.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharPressed
//	Check whether character key changed from up to down.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardIsKeyCharReleased
//	Check whether character key changed from down to up.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardUpdate
//	Copy the current state to the previous state.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state updated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters

// ijkKeyboardReset
//	Reset the current state.
//		param keyboard: pointer to keyboard descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state reset
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


//-----------------------------------------------------------------------------

// ijkInputGetSystemCursor
//	Get the cursor position at the system level.
//		param x_out: pointer to horizontal position of cursor
//			valid: non-null
//			note: [0, w) = [left, right)
//		param y_out: pointer to vertical position of cursor
//			valid: non-null
//			note: [0, h) = [top, bottom)
//		return SUCCESS: ijk_success if cursor position retrieved
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not get position
iret ijkInputGetSystemCursor(i32 x_out[1], i32 y_out[1]);

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

// ijkInputGetSystemKeyboardState
//	Get the state of the keyboard at a system level.
//		param keys_out: array of key states to capture keyboard
//			valid: non-null
//			note: upon successful return, points to an array of boolean states 
//				where true is pressed and false is not pressed
//		return SUCCESS: ijk_success if keyboard state captured
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not get state
iret ijkInputGetSystemKeyboardState(sbyte keys_out[256]);

// ijkInputGetSystemKeyState
//	Get the state of a single key at a system level.
//		param key_out: pointer to key state
//			valid: non-null
//			note: upon successful return, points to boolean (true is pressed)
//		param keyVirt: virtual key to check
//		return SUCCESS: ijk_success if key state captured
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
//		return FAILURE: ijk_fail_operationfail if did not get state
iret ijkInputGetSystemKeyState(sbyte key_out[1], ijkKeyVirt const keyVirt);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkInput.inl"


#endif	// !_IJK_INPUT_H_