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

	ijkInput.inl
	Main input device inline implementation.
*/

#ifdef _IJK_INPUT_H_
#ifndef _IJK_INPUT_INL_
#define _IJK_INPUT_INL_


//-----------------------------------------------------------------------------

// helper macros for input testing
///
#define ijkMouseBtn_wheel				7


//-----------------------------------------------------------------------------

ijk_inl iret ijkMouseGetButtonState(ijkMouseState const* const mouse, ibool state_out[1], ijkMouseBtn const button)
{
	if (mouse && state_out)
	{
		*state_out = (ibool)(mouse->state.button[button]);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseSetButtonState(ijkMouseState* const mouse, ibool const state, ijkMouseBtn const button)
{
	if (mouse)
	{
		mouse->state.button[button] = (sbyte)ijk_istrue(state);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonDown(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return (mouse->state.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonUp(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return !(mouse->state.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonDownAgain(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return (mouse->state.button[button] && mouse->state_prev.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonUpAgain(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return !(mouse->state.button[button] || mouse->state.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonPressed(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return (mouse->state.button[button] && !mouse->state_prev.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseIsButtonReleased(ijkMouseState const* const mouse, ijkMouseBtn const button)
{
	if (mouse)
	{
		return (mouse->state_prev.button[button] && !mouse->state.button[button]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseGetWheelState(ijkMouseState const* const mouse, istate state_out[1])
{
	if (mouse && state_out)
	{
		*state_out = (istate)(mouse->state.button[ijkMouseBtn_wheel]);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseSetWheelState(ijkMouseState* const mouse, istate const state)
{
	if (mouse)
	{
		mouse->state.button[ijkMouseBtn_wheel] = (sbyte)state;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseGetWheelChange(ijkMouseState const* const mouse, istate state_out[1])
{
	if (mouse && state_out)
	{
		*state_out = (istate)(mouse->state.button[ijkMouseBtn_wheel] - mouse->state_prev.button[ijkMouseBtn_wheel]);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseGetPos(ijkMouseState const* const mouse, i32 x_out[1], i32 y_out[1])
{
	if (mouse && x_out && y_out)
	{
		*x_out = mouse->state.x;
		*y_out = mouse->state.y;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseSetPos(ijkMouseState* const mouse, i32 const x, i32 const y)
{
	if (mouse)
	{
		mouse->state.x = x;
		mouse->state.y = y;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseGetPosChange(ijkMouseState const* const mouse, i32 dx_out[1], i32 dy_out[1])
{
	if (mouse && dx_out && dy_out)
	{
		*dx_out = (mouse->state.x - mouse->state_prev.x);
		*dy_out = (mouse->state.y - mouse->state_prev.y);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseUpdate(ijkMouseState* const mouse)
{
	if (mouse)
	{
		mouse->state_prev = mouse->state;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkMouseReset(ijkMouseState* const mouse)
{
	ptr ijkMemorySetZero(ptr const dst, size const sz_bytes);
	if (mouse)
	{
		ijkMemorySetZero(mouse->state.button, szb(mouse->state));
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------

ijk_inl iret ijkKeyboardGetKeyState(ijkKeyboardState const* const keyboard, ibool state_out[1], ijkKeyVirt const keyVirt)
{
	if (keyboard && state_out)
	{
		*state_out = (ibool)(keyboard->state.key[keyVirt]);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardSetKeyState(ijkKeyboardState* const keyboard, ibool const state, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		keyboard->state.key[keyVirt] = (sbyte)ijk_istrue(state);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyDown(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return (keyboard->state.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyUp(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return !(keyboard->state.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyDownAgain(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return (keyboard->state.key[keyVirt] && keyboard->state_prev.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyUpAgain(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return !(keyboard->state.key[keyVirt] || keyboard->state_prev.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyPressed(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return (keyboard->state.key[keyVirt] && !keyboard->state_prev.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyReleased(ijkKeyboardState const* const keyboard, ijkKeyVirt const keyVirt)
{
	if (keyboard)
	{
		return (keyboard->state_prev.key[keyVirt] && !keyboard->state.key[keyVirt]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardGetKeyCharState(ijkKeyboardState const* const keyboard, ibool state_out[1], sbyte const keyChar)
{
	if (keyboard && state_out && keyChar >= 0)
	{
		*state_out = (ibool)(keyboard->state.keyChar[keyChar]);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardSetKeyCharState(ijkKeyboardState* const keyboard, ibool const state, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		keyboard->state.keyChar[keyChar] = (sbyte)ijk_istrue(state);
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharDown(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return (keyboard->state.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharUp(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return !(keyboard->state.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharDownAgain(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return (keyboard->state.keyChar[keyChar] && keyboard->state_prev.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharUpAgain(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return !(keyboard->state.keyChar[keyChar] || keyboard->state_prev.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharPressed(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return (keyboard->state.keyChar[keyChar] && !keyboard->state_prev.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardIsKeyCharReleased(ijkKeyboardState const* const keyboard, sbyte const keyChar)
{
	if (keyboard && keyChar >= 0)
	{
		return (keyboard->state_prev.keyChar[keyChar] && !keyboard->state.keyChar[keyChar]);
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardUpdate(ijkKeyboardState* const keyboard)
{
	if (keyboard)
	{
		keyboard->state_prev = keyboard->state;
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


ijk_inl iret ijkKeyboardReset(ijkKeyboardState* const keyboard)
{
	ptr ijkMemorySetZero(ptr const dst, size const sz_bytes);
	if (keyboard)
	{
		ijkMemorySetZero(keyboard->state.key, szb(keyboard->state));
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_INPUT_INL_
#endif	// _IJK_INPUT_H_