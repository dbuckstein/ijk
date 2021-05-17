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

	ijkSqrt.h
	Fast square root functions.
*/

#ifndef _IJK_SQRT_H_
#define _IJK_SQRT_H_


#include "ijkReal.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkSqrtInv0x_flt
//	Compute fast square root inverse using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root and invert
//		return: approximate inverse (reciprocal) square root of x
flt ijkSqrtInv0x_flt(flt const x);

// ijkSqrt0x_flt
//	Compute fast square root using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root
//		return: approximate square root of x
flt ijkSqrt0x_flt(flt const x);

// ijkSqrt_flt
//	Compute fast square root.
//		param x: number to square root
//		return: square root of x
flt ijkSqrt_flt(flt const x);

// ijkSqrtInv_flt
//	Compute fast inverse square root.
//		param x: number to square root
//		return: inverse square root of x
flt ijkSqrtInv_flt(flt const x);

// ijkCbrt_flt
//	Compute fast unsigned cube root.
//		param x: number to cube root
//		return: cube root of x
flt ijkCbrt_flt(flt const x);

// ijkCbrtInv_flt
//	Compute fast unsigned inverse cube root.
//		param x: number to cube root
//		return: inverse cube root of x
flt ijkCbrtInv_flt(flt const x);

// ijkSqrtInvSafe_flt
//	Compute fast inverse square root with divide-by-zero safety.
//		param x: number to square root
//		return: inverse square root of x
#define ijkSqrtInvSafe_flt(x)	((x) != flt_zero ? ijkSqrtInv_flt(x) : flt_zero)

// ijkCbrtInvSafe_flt
//	Compute fast inverse cube root with divide-by-zero safety.
//		param x: number to cube root
//		return: inverse cube root of x
#define ijkCbrtInvSafe_flt(x)	((x) != flt_zero ? ijkCbrtInv_flt(x) : flt_zero)


//-----------------------------------------------------------------------------

// ijkSqrtInv0x_dbl
//	Compute fast square root inverse using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root and invert
//		return: approximate inverse (reciprocal) square root of x
dbl ijkSqrtInv0x_dbl(dbl const x);

// ijkSqrt0x_dbl
//	Compute fast square root using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root
//		return: approximate square root of x
dbl ijkSqrt0x_dbl(dbl const x);

// ijkSqrt_dbl
//	Compute fast square root.
//		param x: number to square root
//		return: square root of x
dbl ijkSqrt_dbl(dbl const x);

// ijkSqrtInv_dbl
//	Compute fast inverse square root.
//		param x: number to square root
//		return: inverse square root of x
dbl ijkSqrtInv_dbl(dbl const x);

// ijkCbrt_dbl
//	Compute fast unsigned cube root.
//		param x: number to cube root
//		return: cube root of x
dbl ijkCbrt_dbl(dbl const x);

// ijkCbrtInv_dbl
//	Compute fast unsigned inverse cube root.
//		param x: number to cube root
//		return: inverse cube root of x
dbl ijkCbrtInv_dbl(dbl const x);

// ijkSqrtInvSafe_dbl
//	Compute fast inverse square root with divide-by-zero safety.
//		param x: number to square root
//		return: inverse square root of x
#define ijkSqrtInvSafe_dbl(x)	((x) != dbl_zero ? ijkSqrtInv_dbl(x) : dbl_zero)

// ijkCbrtInvSafe_dbl
//	Compute fast inverse cube root with divide-by-zero safety.
//		param x: number to cube root
//		return: inverse cube root of x
#define ijkCbrtInvSafe_dbl(x)	((x) != dbl_zero ? ijkCbrtInv_dbl(x) : dbl_zero)


//-----------------------------------------------------------------------------

// ijkSqrtInv0x
//	Compute fast square root inverse using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root and invert
//		return: approximate inverse (reciprocal) square root of x
// real ijkSqrtInv0x(real const x);
#define ijkSqrtInv0x		ijk_declrealf(ijkSqrtInv0x)

// ijkSqrt0x
//	Compute fast square root using Quake's method ("0x5f3759df") using 
//	Newton's approximation method.
//		param x: number to square root
//		return: approximate square root of x
// real ijkSqrt0x(real const x);
#define ijkSqrt0x			ijk_declrealf(ijkSqrt0x)

// ijkSqrt
//	Compute fast square root.
//		param x: number to square root
//		return: square root of x
// real ijkSqrt(real const x);
#define ijkSqrt				ijk_declrealf(ijkSqrt)

// ijkSqrtInv
//	Compute fast inverse square root.
//		param x: number to square root
//		return: inverse square root of x
// real ijkSqrtInv(real const x);
#define ijkSqrtInv			ijk_declrealf(ijkSqrtInv)

// ijkCbrt
//	Compute fast unsigned cube root.
//		param x: number to cube root
//		return: cube root of x
// real ijkCbrt(real const x);
#define ijkCbrt				ijk_declrealf(ijkCbrt)

// ijkCbrtInv
//	Compute fast unsigned inverse cube root.
//		param x: number to cube root
//		return: inverse cube root of x
// real ijkCbrtInv(real const x);
#define ijkCbrtInv			ijk_declrealf(ijkCbrtInv)

// ijkSqrtInvSafe
//	Compute fast inverse square root with divide-by-zero safety.
//		param x: number to square root
//		return: inverse square root of x
//#define ijkSqrtInvSafe(x)	(x != real_zero ? ijkSqrtInv(x) : real_zero)
#define ijkSqrtInvSafe		ijk_declrealf(ijkSqrtInvSafe)

// ijkCbrtInvSafe
//	Compute fast inverse cube root with divide-by-zero safety.
//		param x: number to cube root
//		return: inverse cube root of x
//#define ijkCbrtInvSafe(x)	(x != real_zero ? ijkCbrtInv(x) : real_zero)
#define ijkCbrtInvSafe		ijk_declrealf(ijkCbrtInvSafe)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkSqrt.inl"


#endif	// !_IJK_SQRT_H_