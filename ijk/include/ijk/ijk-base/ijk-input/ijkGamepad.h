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

	ijkGamepad.h
	Gamepad/controller/handheld input device interfaces.
*/

#ifndef _IJK_GAMEPAD_H_
#define _IJK_GAMEPAD_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef enum ijkGamepadID				ijkGamepadID;
typedef enum ijkGamepadBtn				ijkGamepadBtn;
typedef struct ijkGamepadState			ijkGamepadState;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkGamepadID
//	Enumeration of gamepad IDs by player number.
enum ijkGamepadID
{
	ijkGamepadID_player1,
	ijkGamepadID_player2,
	ijkGamepadID_player3,
	ijkGamepadID_player4,
};


// ijkGamepadBtn
//	Enumeration of gamepad buttons.
enum ijkGamepadBtn
{
	ijkGamepadBtn_dpad_up		= 0x0001,
	ijkGamepadBtn_dpad_down		= 0x0002,
	ijkGamepadBtn_dpad_left		= 0x0004,
	ijkGamepadBtn_dpad_right	= 0x0008,
	ijkGamepadBtn_start			= 0x0010,
	ijkGamepadBtn_back			= 0x0020,
	ijkGamepadBtn_thumb_left	= 0x0040,
	ijkGamepadBtn_thumb_right	= 0x0080,
	ijkGamepadBtn_bumber_left	= 0x0100,
	ijkGamepadBtn_bumber_right	= 0x0200,
	ijkGamepadBtn_bumber_left2	= 0x0400,
	ijkGamepadBtn_bumber_right2	= 0x0800,
	ijkGamepadBtn_A				= 0x1000,
	ijkGamepadBtn_B				= 0x2000,
	ijkGamepadBtn_X				= 0x4000,
	ijkGamepadBtn_Y				= 0x8000,
};


// ijkGamepadState
//	Gamepad state tracker descriptor.
//		member ctrlID: identifier index of controller
//		member packet: internal data representation (XInput)
//		member state: current state of gamepad
//		member state_prev: previous state of gamepad
//		member button: within states, flags to describe button states
//		members trigger...: left and right trigger values
//		members thumb...: left and right thumbstick directions, X-horiz, Y-vert
//		members trigger...unit: normalized trigger values
//		members thumb...unit: normalized thumbstick directions
//		member connected: connection status
struct ijkGamepadState
{
	dword ctrlID;
	dword packet[1];
	struct {
		word button;
		byte trigger_left, trigger_right;
		i16 thumbX_left, thumbY_left, thumbX_right, thumbY_right;
		dbl trigger_left_unit, trigger_right_unit;
		dbl thumbX_left_unit, thumbY_left_unit, thumbX_right_unit, thumbY_right_unit;
		ibool connected;
	} state, state_prev;
};


//-----------------------------------------------------------------------------

// ijkGamepadGetButtonState
//	Get the current state of a gamepad button.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param state_out: pointer to button state
//			valid: non-null
//			note: upon successful return, points to boolean (true is pressed)
//		param button: gamepad button
//		return SUCCESS: ijk_success if retrieved state
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadGetButtonState(ijkGamepadState const* const gamepad, ibool state_out[1], ijkGamepadBtn const button);

// ijkGamepadIsButtonDown
//	Check whether gamepad button is down.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key is down
//		return SUCCESS: ijk_false if key is up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonDown(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadIsButtonUp
//	Check whether gamepad button is up.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key is up
//		return SUCCESS: ijk_false if key is down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonUp(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadIsButtonDownAgain
//	Check whether gamepad button is consistently down between updates.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key is consistently down
//		return SUCCESS: ijk_false if key is not consistently down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonDownAgain(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadIsButtonUpAgain
//	Check whether gamepad button is consistently up between updates.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key is consistently up
//		return SUCCESS: ijk_false if key is not consistently up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonUpAgain(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadIsButtonPressed
//	Check whether gamepad button changed from up to down.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key changed from up to down
//		return SUCCESS: ijk_false if key did not change from up to down
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonPressed(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadIsButtonReleased
//	Check whether gamepad button changed from down to up.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param button: button enumerator
//		return SUCCESS: ijk_true if key changed from down to up
//		return SUCCESS: ijk_false if key did not change from down to up
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadIsButtonReleased(ijkGamepadState const* const gamepad, ijkGamepadBtn const button);

// ijkGamepadUpdate
//	Copy the current state to the previous state.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state updated
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadUpdate(ijkGamepadState* const gamepad);

// ijkGamepadReset
//	Reset the current state.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		return SUCCESS: ijk_success if state reset
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadReset(ijkGamepadState* const gamepad);

// ijkGamepadSetID
//	Initialize gamepad given ID and update.
//		param gamepad: pointer to gamepad descriptor
//			valid: non-null
//		param gamepadID: gamepad player identifier
//		return SUCCESS: ijk_success if ID set
//		return FAILURE: ijk_fail_invalidparams if invalid parameters
iret ijkGamepadSetID(ijkGamepadState* const gamepad, ijkGamepadID const gamepadID);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkGamepad.inl"


#endif	// !_IJK_GAMEPAD_H_