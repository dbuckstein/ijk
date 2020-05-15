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
typedef enum ijkInputState				ijkInputState;
typedef enum ijkInputStateChange		ijkInputStateChange;
typedef enum ijkMouseButton				ijkMouseButton;
typedef enum ijkMouseWheelState			ijkMouseWheelState;
typedef enum ijkKeyboardKey				ijkKeyboardKey;
typedef enum ijkKeyboardKeyChar			ijkKeyboardKeyChar;
typedef struct ijkMouseInput			ijkMouseInput;
typedef struct ijkKeyboardInput			ijkKeyboardInput;
#endif	// __cplusplus


//-----------------------------------------------------------------------------



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