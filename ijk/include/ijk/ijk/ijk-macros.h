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

	ijk-macros.h
	Common macros.
*/

#ifndef _IJK_MACROS_H_
#define _IJK_MACROS_H_


#include "ijk-config.h"


// General symbol qualifiers.
///
#define ijk_inl_ext						extern inline	// Tag external and inline; useful for compilation with local inlining.
#define ijk_inl							static inline	// Tag inline and static.
#define ijk_ext							extern			// Tag external.


// General integer constants.
///
#define ijk_zero						0					// Zero.
#define ijk_one							1					// One.
#define ijk_pos(x)						(+(x))				// Positive.
#define ijk_neg(x)						(-(x))				// Negative.
#define ijk_one_p						ijk_pos(ijk_one)	// Positive one.
#define ijk_one_n						ijk_neg(ijk_one)	// Negative one.


// General flags and checks.
///
#define ijk_success						ijk_zero			// Code when function exits successfully, no errors or warnings (zero).
#define ijk_failure						ijk_one_n			// Code when function exits unsuccessfully, with errors (negative).
#define ijk_warning						ijk_one_p			// Code when function exits successfully but with warnings (positive).
#define ijk_failcode(x)					ijk_neg(x)			// Code for specific failure cause.
#define ijk_warncode(x)					ijk_pos(x)			// Code for specific warning cause.
#define ijk_fail_invalidparams			ijk_failcode(0x1)	// Code for failure due to invalid parameter(s).
#define ijk_fail_operationfail			ijk_failcode(0x2)	// Code for failure due to general failure(s).

#define ijk_true						ijk_one						// Shorthand for true (one).
#define ijk_false						ijk_zero					// Shorthand for false (zero).
#define ijk_istrue(x)					((x) != ijk_false)			// Check if value represents true (non-zero).
#define ijk_isfalse(x)					((x) == ijk_false)			// Check if value represents false (zero).
#define ijk_issuccess(x)				((x) == ijk_success)		// Check if value represents success code (zero).
#define ijk_isfailure(x)				((x) <  ijk_success)		// Check if value represents failure code (negative).
#define ijk_iswarning(x)				((x) >  ijk_success)		// Check if value represents warning code (positive).
#define ijk_isnfailure(x)				((x) >= ijk_success)		// Check if value represents non-failure code (non-negative).
#define ijk_failch(xn,f)				(ijk_failcode(xn) & (f))	// Check negative failure code (xn) against reason/cause flag (f).
#define ijk_warnch(xp,f)				(ijk_warncode(xp) & (f))	// Check positive failure code (xp) against reason/cause flag (f).

#define ijk_flagraise(x,f)				((x) | (f))					// Raise flag (f) on base value (x).
#define ijk_flaglower(x,f)				((x) & ~(f))				// Lower flag (f) from base value (x).
#define ijk_flagch(x,f)					(((x) & (f)) != (ijk_zero))	// Check whether flag (f) is partially raised in base value (x).
#define ijk_flagnch(x,f)				(((x) & (f)) == (ijk_zero))	// Check whether all bits in flag (f) are lowered in base value (x).
#define ijk_flageq(x,f)					(((x) & (f)) == (f))		// Check whether all bits in flag (f) are raised in base value (x).
#define ijk_flagneq(x,f)				(((x) & (f)) != (f))		// Check whether flag (f) is partially lowered in base value (x).


// Token stringify and concatenate.
///
#define ijk_tokenstr(x)					__ijk_cfg_tokenstr(x)				// Stringify token x.
#define ijk_tokencat(x,y)				__ijk_cfg_tokencat(x,y)				// Concatenate tokens x and y.
#define ijk_tokencat_arch(x)			ijk_tokencat(x,__ijk_cfg_archbits)	// Concatenate token x with architecture bits.


// Platform and configuration checks.
///
#define ijk_platform_is(x)				(__ijk_cfg_platform == (x))			// Platform comparison.
#define ijk_platform_isn(x)				(__ijk_cfg_platform != (x))			// Platform not comparison.
#define ijk_platform_fn(f)				ijk_tokencat(f,__ijk_cfg_platform)	// Platform-specific function.
#define ijk_buildcfg_is(x)				(__ijk_cfg_buildcfg == (x))			// Build configuration comparison.
#define ijk_buildcfg_isn(x)				(__ijk_cfg_buildcfg != (x))			// Build configuration not comparison.
#define ijk_buildcfg_fn(f)				ijk_tokencat(f,__ijk_cfg_buildcfg)	// Build configuration-specific function.


// Simple global logical operations.
///
#define ijk_squared(x)						((x) * (x))							// Square value x.
#define ijk_minimum(x,y)					((x) <= (y) ? (x) : (y))			// Minimum value of x and y.
#define ijk_maximum(x,y)					((x) >= (y) ? (x) : (y))			// Maximum value of x and y.
#define ijk_isclamp(x_min,x_max,x)			((x) >= (x_min) && (x) <= (x_max))	// Check if value x is between x_min and x_max.
#define ijk_isnclamp(x_min,x_max,x)			((x) < (x_min) || (x) > (x_max))	// Check if value is not between x_min and x_max.
#define ijk_clamp(x_min,x_max,x)			((x) >= (x_min) ? (x) <= (x_max) ? (x) : (x_max) : (x_min))						// Clamp value x between x_min and x_max.
#define ijk_clamp_inv(x_min,x_max,x0,x)		((x) >= (x_max) || (x) <= (x_min) ? (x) : ((x) >= (x0) ? (x_max) : (x_min)))	// Clamp value x to limit x_min or x_max based on origin x0 if value is clamped.
#define ijk_clamp_loop(x_min,x_max,dx,x)	(x); while((x) > (x_max)) x -= (dx); while((x) < (x_min)) x += (dx)				// Clamp value x by looping by dx to end up between x_min and x_max.
#define ijk_swap2(x,y,tmp)					(tmp=x);x=y;y=tmp					// Swap two values x and y using placeholder tmp.
#define ijk_swap3(x,y,z,tmp)				(tmp=x);x=y;y=z;z=tmp				// Swap/rotate three values x, y and z using placeholder tmp.
#define ijk_swap4(x,y,z,w,tmp)				(tmp=x);x=y;y=z;z=w;w=tmp			// Swap/rotate four values x, y, z and w using placeholder tmp.


#endif	// !_IJK_MACROS_H_