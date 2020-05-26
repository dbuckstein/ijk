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

	ijkGamepad.inl
	Gamepad/controller/handheld input device inline implementation.
*/

#ifdef _IJK_GAMEPAD_H_
#ifndef _IJK_GAMEPAD_INL_
#define _IJK_GAMEPAD_INL_


//-----------------------------------------------------------------------------

ijk_inl iret ijkGamepadGetButtonState(ijkGamepadState const* const gamepad, ibool state_out[1], ijkGamepadBtn const button)
{
	if (gamepad && state_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonDown(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonUp(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonDownAgain(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonUpAgain(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonPressed(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsButtonReleased(ijkGamepadState const* const gamepad, ijkGamepadBtn const button)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetConnectionState(ijkGamepadState const* const gamepad, ibool state_out[1])
{
	if (gamepad && state_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsConnected(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsNotConnected(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsConnectedAgain(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadIsNotConnectedAgain(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadReconnected(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadDisconnected(ijkGamepadState const* const gamepad)
{
	if (gamepad)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetTriggerLeft(ijkGamepadState const* const gamepad, dbl v_out[1])
{
	if (gamepad && v_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetTriggerRight(ijkGamepadState const* const gamepad, dbl v_out[1])
{
	if (gamepad && v_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetTriggerLeftChange(ijkGamepadState const* const gamepad, dbl dv_out[1])
{
	if (gamepad && dv_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetTriggerRightChange(ijkGamepadState const* const gamepad, dbl dv_out[1])
{
	if (gamepad && dv_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetThumbstickLeft(ijkGamepadState const* const gamepad, dbl v_out[1])
{
	if (gamepad && v_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetThumbstickRight(ijkGamepadState const* const gamepad, dbl v_out[1])
{
	if (gamepad && v_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetThumbstickLeftChange(ijkGamepadState const* const gamepad, dbl dv_out[1])
{
	if (gamepad && dv_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadGetThumbstickRightChange(ijkGamepadState const* const gamepad, dbl dv_out[1])
{
	if (gamepad && dv_out)
	{

	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadSetID(ijkGamepadState* const gamepad, ijkGamepadID const gamepadID)
{
	if (gamepad)
	{
		gamepad->ctrlID = gamepadID;
		return ijkGamepadUpdate(gamepad);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkGamepadReset(ijkGamepadState* const gamepad)
{
	ptr ijkMemorySetZero(ptr const dst, size const sz_bytes);
	if (gamepad)
	{
		ijkMemorySetZero(gamepad->packet, (szb(gamepad->packet) + szb(gamepad->state)));
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_GAMEPAD_INL_
#endif	// _IJK_GAMEPAD_H_