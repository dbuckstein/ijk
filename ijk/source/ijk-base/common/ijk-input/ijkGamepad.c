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

	ijkGamepad.c
	Gamepad/controller/handheld input device implementation.
*/

#include "ijk/ijk-base/ijk-input/ijkGamepad.h"


//-----------------------------------------------------------------------------

ijk_inl ui8 ijkGamepadInternalClampDeadzone8U(ui8 const value, ui8 const deadzone)
{
	return (value > deadzone ? value - deadzone : 0);
}


ijk_inl i16 ijkGamepadInternalClampDeadzone16(i16 const value, i16 const deadzone)
{
	return (value > +deadzone ? value - deadzone : value < -deadzone ? value + deadzone + 1 : 0);
}


#if (__ijk_cfg_platform == WINDOWS)
#include <Windows.h>
#include <Xinput.h>


//-----------------------------------------------------------------------------

iret ijkGamepadSetRumble(ijkGamepadState const* const gamepad, word const rumble_left, word const rumble_right)
{
	if (gamepad)
	{
		XINPUT_VIBRATION vib[1] = { { rumble_left, rumble_right } };
		if (XInputSetState(gamepad->ctrlID, vib) == ERROR_SUCCESS)
			return ijk_success;
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkGamepadUpdate(ijkGamepadState* const gamepad)
{
	if (gamepad)
	{
		gamepad->state_prev = gamepad->state;
		gamepad->state.connected = (XInputGetState(gamepad->ctrlID, (PXINPUT_STATE)gamepad->packet) == ERROR_SUCCESS);
		if (gamepad->state.connected)
		{
			// get normalization scalars
			dbl const invTriggerNorm = 1.0 / ((dbl)(255 - XINPUT_GAMEPAD_TRIGGER_THRESHOLD));
			dbl const invThumbNormL = 1.0 / ((dbl)(32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE));
			dbl const invThumbNormR = 1.0 / ((dbl)(32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE));

			// clamp to dead zones
			gamepad->state.trigger_left = ijkGamepadInternalClampDeadzone8U(gamepad->state.trigger_left, XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
			gamepad->state.trigger_right = ijkGamepadInternalClampDeadzone8U(gamepad->state.trigger_right, XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
			gamepad->state.thumbX_left = ijkGamepadInternalClampDeadzone16(gamepad->state.thumbX_left, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
			gamepad->state.thumbY_left = ijkGamepadInternalClampDeadzone16(gamepad->state.thumbY_left, XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
			gamepad->state.thumbX_right = ijkGamepadInternalClampDeadzone16(gamepad->state.thumbX_right, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			gamepad->state.thumbY_right = ijkGamepadInternalClampDeadzone16(gamepad->state.thumbY_right, XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);

			// normalize
			gamepad->state.trigger_left_unit = invTriggerNorm * gamepad->state.trigger_left;
			gamepad->state.trigger_right_unit = invTriggerNorm * gamepad->state.trigger_right;
			gamepad->state.thumbX_left_unit = invThumbNormL * gamepad->state.thumbX_left;
			gamepad->state.thumbY_left_unit = invThumbNormL * gamepad->state.thumbY_left;
			gamepad->state.thumbX_right_unit = invThumbNormR * gamepad->state.thumbX_right;
			gamepad->state.thumbY_right_unit = invThumbNormR * gamepad->state.thumbY_right;

			// changes
			gamepad->button_downAgain = gamepad->state.button & gamepad->state_prev.button;
			gamepad->button_upAgain = gamepad->state.button | gamepad->state_prev.button;
			gamepad->button_pressed = gamepad->state.button & ~gamepad->state_prev.button;
			gamepad->button_released = gamepad->state_prev.button & ~gamepad->state.button;

			// success
			return ijk_success;
		}

		// failed
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


#else	// !WINDOWS


//-----------------------------------------------------------------------------


#endif	// WINDOWS


//-----------------------------------------------------------------------------
