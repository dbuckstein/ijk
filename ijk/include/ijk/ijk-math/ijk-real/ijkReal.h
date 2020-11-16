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

	ijkReal.h
	Real number types.
*/

#ifndef _IJK_REAL_H_
#define _IJK_REAL_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// IJK_REAL_DBL
//	User-defined macro to select double as base real number type. If not 
//	defined, the base real number type defaults to float.	
#ifdef IJK_REAL_DBL
// Real number type is based on 64-bit float (double).
#define ijk_real					dbl
// Single letter real suffix.
#define ijk_reals					d
#else	// !IJK_REAL_DBL
// Real number type is based on 32-bit float (single).
#define ijk_real					flt
// Single letter real suffix.
#define ijk_reals					f
#endif	// IJK_REAL_DBL

// real
//	Real number type.
typedef ijk_real					real;

// szreal
//	Size of real type.
#define szreal						szb(real)

// szrealbr
//	Byte ratio of real type size to single-precision float size.
#define szrealbr					(szreal / szflt)

// ijk_x2r
//	Cast to real.
//		param x: value to cast
//		result: value as real
#define ijk_x2r(x)					(real)(x)

// ijk_declrealf
//	Declare real function.
//		param func: name of function to declare for real type
//		result: name of function for real type
#define ijk_declrealf(func)			ijk_tokencat(ijk_tokencat(func,_),ijk_real)

// ijk_declrealv
//	Declare real variable.
//		param var: name of variable to declare for real type
//		result: name of variable for real type
#define ijk_declrealv(var)			ijk_tokencat(ijk_real,ijk_tokencat(_,var))

// ijk_declrealfs
//	Declare real function with suffix.
//		param func: name of function to declare for real type
//		param sfx: suffix for function
//		result: name of function for real type
#define ijk_declrealfs(func,sfx)	ijk_tokencat(ijk_tokencat(func,ijk_reals),sfx)

// ijk_declrealpv
//	Declare real variable with prefix.
//		param var: name of variable to declare for real type
//		param pfx: suffix for variable
//		result: name of variable for real type
#define ijk_declrealpv(var,pfx)		ijk_tokencat(pfx,ijk_tokencat(ijk_reals,var))


//-----------------------------------------------------------------------------

// ijk_lerp
//	Linear interpolation.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param t: interpolation parameter; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
//		result: interpolated value 'v'; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
#define ijk_lerp(v0,v1,t)			((v0) + ((v1) - (v0)) * (t))

// ijk_lerp_inv
//	Linear interpolation inverse.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param v: interpolated value; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
//		result: interpolation parameter 't'; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
#define ijk_lerp_inv(v0,v1,v)		(((v) - (v0)) / ((v1) - (v0)))

// ijk_lerp_inv_safe
//	Linear interpolation inverse with division-by-zero safety.
#define ijk_lerp_inv_safe(v0,v1,v)	((v0) != (v1) ? ijk_lerp_inv(v0,v1,v) : ((v1) - (v0)))

// ijk_remap
//	Re-map or re-interpolate value from one range into another.
//		param v0_new: lower bound of new/output range
//		param v1_new: upper bound of new/output range
//		param v0_orig: lower bound of original/input range
//		param v1_orig: upper bound of original/input range
//		result: re-interpolated value 'v_new' in new/output range
#define ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig)			((v0_new) + (((v1_new) - (v0_new)) * ((v_orig) - (v0_orig))) / ((v1_orig) - (v0_orig)))

// ijk_remap_safe
//	Re-map/re-interpolate value with division-by-zero safety.
#define ijk_remap_safe(v0_new,v1_new,v0_orig,v1_orig,v_orig)	((v0_orig) != (v1_orig) ? ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig) : (v0_new))

// ijk_divide
//	Perform division.
//		param n: numerator (top)
//		param d: denominator (bottom)
//		result: quotient of (n/d)
#define ijk_divide(n,d)				((n) / (d))


//-----------------------------------------------------------------------------

// Macros for integers.
///
#define ijk_sgn_int(x)				((x) != ijk_zero ? (x) > ijk_zero ? +ijk_one : -ijk_one : ijk_zero)	// sgn(x) = x > 0 ? +1 : x < 0 ? -1 : 0
#define ijk_abs_int(x)				((x) >= ijk_zero ? +(x) : -(x))										// abs(x) = x >= 0 ? +x : -x
#define ijk_nrm2sym_int(x)			(((x) << ijk_one) - ijk_one)										// nrm2sym(x) = 2x - 1
#define ijk_sym2nrm_int(x)			(((x) + ijk_one) >> ijk_one)										// sym2nrm(x) = (x + 1)/2
#define ijk_isnrm_int(x)			ijk_isclamp(ijk_zero,ijk_one,x)										// isnrm(x) = 0 <= x <= 1
#define ijk_isnnrm_int(x)			ijk_isnclamp(ijk_zero,ijk_one,x)									// isnnrm(x) = !isnrm(x)
#define ijk_issym_int(x)			ijk_isclamp(-ijk_one,+ijk_one,x)									// issym(x) = -1 <= x <= +1
#define ijk_isnsym_int(x)			ijk_isnclamp(-ijk_one,+ijk_one,x)									// isnsym(x) = !issym(x)
#define ijk_iszero_int(x)			((x) == ijk_zero)													// iszero(x) = -eps <= x <= +eps
#define ijk_isnzero_int(x)			((x) != ijk_zero)													// isnzero(x) = !iszero(x)
#define ijk_divide_safe_int(n,d)	((d) != ijk_zero ? ijk_divide(n,d) : ijk_zero)						// divide_safe(n,d) = n/d, d != 0
#define ijk_modulo_int(n,d)			((n) % (d))															// modulo(n,d) = n%d
#define ijk_modulo_safe_int(n,d)	((d) != ijk_zero ? ijk_modulo_int(n,d) : (n))						// modulo_safe(n,d) = d != 0 ? n%d : n


//-----------------------------------------------------------------------------

// Global constants for float type.
///
ijk_ext flt const flt_zero;										   // Zero as float.
ijk_ext flt const flt_eps;										   // Epsilon as float.
ijk_ext flt const flt_halfeps;									   // Half epsilon as float.
ijk_ext flt const flt_1000th;									   // 1/1000 as float.
ijk_ext flt const flt_100th;									   // 1/100 as float.
ijk_ext flt const flt_10th;										   // 1/10 as float.
ijk_ext flt const flt_9th;										   // 1/9 as float.
ijk_ext flt const flt_8th;										   // 1/8 as float.
ijk_ext flt const flt_7th;										   // 1/7 as float.
ijk_ext flt const flt_6th;										   // 1/6 as float.
ijk_ext flt const flt_5th;										   // 1/5 as float.
ijk_ext flt const flt_quarter;									   // 1/4 as float.
ijk_ext flt const flt_third;									   // 1/3 as float.
ijk_ext flt const flt_half;										   // 1/2 as float.
ijk_ext flt const flt_2thirds;									   // 2/3 as float.
ijk_ext flt const flt_3quarters;								   // 3/4 as float.
ijk_ext flt const flt_one;										   // One as float.
ijk_ext flt const flt_4third;									   // 4/3 as float.
ijk_ext flt const flt_3half;									   // 3/2 as float.
ijk_ext flt const flt_two;										   // 2 as float.
ijk_ext flt const flt_three;									   // 3 as float.
ijk_ext flt const flt_four;										   // 4 as float.
ijk_ext flt const flt_five;										   // 5 as float.
ijk_ext flt const flt_six;										   // 6 as float.
ijk_ext flt const flt_seven;									   // 7 as float.
ijk_ext flt const flt_eight;									   // 8 as float.
ijk_ext flt const flt_nine;										   // 9 as float.
ijk_ext flt const flt_ten;										   // 10 as float.
ijk_ext flt const flt_hundred;									   // 100 as float.
ijk_ext flt const flt_thousand;									   // 1000 as float.
ijk_ext flt const flt_sqrtthird;								   // Sqrt(1/3) as float.
ijk_ext flt const flt_sqrthalf;									   // Sqrt(1/2) as float.
ijk_ext flt const flt_sqrt2;									   // Sqrt(2) as float.
ijk_ext flt const flt_sqrt3;									   // Sqrt(3) as float.
ijk_ext flt const flt_6pi;										   // Pi*6 (approx 18.84956) as float.
ijk_ext flt const flt_4pi;										   // Pi*4 (approx 12.56637) as float.
ijk_ext flt const flt_3pi;										   // Pi*3 (approx 9.42478) as float.
ijk_ext flt const flt_2pi;										   // Pi*2 (approx 6.28319) as float.
ijk_ext flt const flt_3pi_2;									   // Pi*3/2 (approx 4.71239) as float.
ijk_ext flt const flt_4pi_3;									   // Pi*4/3 (approx 4.18879) as float.
ijk_ext flt const flt_6pi_5;									   // Pi*6/5 (approx 3.76991) as float.
ijk_ext flt const flt_pi;										   // Pi (approx 3.14159) as float.
ijk_ext flt const flt_5pi_6;									   // Pi*5/6 (approx 2.61799) as float.
ijk_ext flt const flt_3pi_4;									   // Pi*3/4 (approx 2.35619) as float.
ijk_ext flt const flt_2pi_3;									   // Pi*2/3 (approx 2.09439) as float.
ijk_ext flt const flt_pi_2;										   // Pi/2 (approx 1.57079) as float.
ijk_ext flt const flt_pi_3;										   // Pi/3 (approx 1.05719) as float.
ijk_ext flt const flt_pi_4;										   // Pi/4 (approx 0.78539) as float.
ijk_ext flt const flt_pi_6;										   // Pi/6 (approx 0.52360) as float.
ijk_ext flt const flt_360;										   // 360 as float.
ijk_ext flt const flt_180;										   // 180 as float.
ijk_ext flt const flt_90;										   // 90 as float.
ijk_ext flt const flt_60;										   // 60 as float.
ijk_ext flt const flt_45;										   // 45 as float.
ijk_ext flt const flt_30;										   // 30 as float.
ijk_ext flt const flt_deg2rad;									   // Pi/180 (approx 0.01745) as float.
ijk_ext flt const flt_rad2deg;									   // 180/pi (approx 57.29578) as float.


// Macros for floats.
///
#define ijk_sgn_flt(x)				((x) != flt_zero ? (x) > flt_zero ? +flt_one : -flt_one : flt_zero)	// sgn(x) = x > 0 ? +1 : x < 0 ? -1 : 0
#define ijk_abs_flt(x)				((x) >= flt_zero ? +(x) : -(x))										// abs(x) = x >= 0 ? +x : -x
#define ijk_nrm2sym_flt(x)			((x) * flt_two - flt_one)											// nrm2sym(x) = 2x - 1
#define ijk_sym2nrm_flt(x)			((x) * flt_half + flt_half)											// sym2nrm(x) = (x + 1)/2
#define ijk_isnrm_flt(x)			ijk_isclamp(flt_zero,flt_one,x)										// isnrm(x) = 0 <= x <= 1
#define ijk_isnnrm_flt(x)			ijk_isnclamp(flt_zero,flt_one,x)									// isnnrm(x) = !isnrm(x)
#define ijk_issym_flt(x)			ijk_isclamp(-flt_one,+flt_one,x)									// issym(x) = -1 <= x <= +1
#define ijk_isnsym_flt(x)			ijk_isnclamp(-flt_one,+flt_one,x)									// isnsym(x) = !issym(x)
#define ijk_iszero_flt(x)			ijk_isclamp(-flt_eps,+flt_eps,x)									// iszero(x) = -eps <= x <= +eps
#define ijk_isnzero_flt(x)			ijk_isnclamp(-flt_eps,+flt_eps,x)									// isnzero(x) = !iszero(x)
#define ijk_trunc_flt(x)			((f32)((i32)(x)))													// trunc(x) = int(x)
#define ijk_divide_safe_flt(n,d)	((d) != flt_zero ? ijk_divide(n,d) : flt_zero)						// divide_safe(n,d) = n/d, d != 0
#define ijk_modulo_flt(n,d)			((n) - (d)*ijk_trunc_flt(ijk_divide(n,d)))							// modulo(n,d) = n - d*trunc(n/d)
#define ijk_modulo_safe_flt(n,d)	((d) != flt_zero ? ijk_modulo_flt(n,d) : (n))						// modulo_safe(n,d) = d != 0 ? modulo(n,d) : n
#define ijk_recip_flt(x)			(flt_one / (x))														// recip(x) = 1/x
#define ijk_recip_safe_flt(x)		((x != flt_zero) ? ijk_recip_flt(x) : flt_zero)						// recip_safe(x) = 1/x, x != 0
#define ijk_deg2rad_flt(x)			((x) * flt_deg2rad)													// deg2rad(x) = x * pi/180
#define ijk_rad2deg_flt(x)			((x) * flt_rad2deg)													// rad2deg(x) = x * 180/pi


//-----------------------------------------------------------------------------

// Global constants for double type.
///
ijk_ext dbl const dbl_zero;										   // Zero as double.
ijk_ext dbl const dbl_eps;										   // Epsilon as double.
ijk_ext dbl const dbl_halfeps;									   // Half epsilon as double.
ijk_ext dbl const dbl_1000th;									   // 1/1000 as double.
ijk_ext dbl const dbl_100th;									   // 1/100 as double.
ijk_ext dbl const dbl_10th;										   // 1/10 as double.
ijk_ext dbl const dbl_9th;										   // 1/9 as double.
ijk_ext dbl const dbl_8th;										   // 1/8 as double.
ijk_ext dbl const dbl_7th;										   // 1/7 as double.
ijk_ext dbl const dbl_6th;										   // 1/6 as double.
ijk_ext dbl const dbl_5th;										   // 1/5 as double.
ijk_ext dbl const dbl_quarter;									   // 1/4 as double.
ijk_ext dbl const dbl_third;									   // 1/3 as double.
ijk_ext dbl const dbl_half;										   // 1/2 as double.
ijk_ext dbl const dbl_2thirds;									   // 2/3 as double.
ijk_ext dbl const dbl_3quarters;								   // 3/4 as double.
ijk_ext dbl const dbl_one;										   // One as double.
ijk_ext dbl const dbl_4third;									   // 4/3 as double.
ijk_ext dbl const dbl_3half;									   // 3/2 as double.
ijk_ext dbl const dbl_two;										   // 2 as double.
ijk_ext dbl const dbl_three;									   // 3 as double.
ijk_ext dbl const dbl_four;										   // 4 as double.
ijk_ext dbl const dbl_five;										   // 5 as double.
ijk_ext dbl const dbl_six;										   // 6 as double.
ijk_ext dbl const dbl_seven;									   // 7 as double.
ijk_ext dbl const dbl_eight;									   // 8 as double.
ijk_ext dbl const dbl_nine;										   // 9 as double.
ijk_ext dbl const dbl_ten;										   // 10 as double.
ijk_ext dbl const dbl_hundred;									   // 100 as double.
ijk_ext dbl const dbl_thousand;									   // 1000 as double.
ijk_ext dbl const dbl_sqrtthird;								   // Sqrt(1/3) as double.
ijk_ext dbl const dbl_sqrthalf;									   // Sqrt(1/2) as double.
ijk_ext dbl const dbl_sqrt2;									   // Sqrt(2) as double.
ijk_ext dbl const dbl_sqrt3;									   // Sqrt(3) as double.
ijk_ext dbl const dbl_6pi;										   // Pi*6 (approx 18.84956) as double.
ijk_ext dbl const dbl_4pi;										   // Pi*4 (approx 12.56637) as double.
ijk_ext dbl const dbl_3pi;										   // Pi*3 (approx 9.42478) as double.
ijk_ext dbl const dbl_2pi;										   // Pi*2 (approx 6.28319) as double.
ijk_ext dbl const dbl_3pi_2;									   // Pi*3/2 (approx 4.71239) as double.
ijk_ext dbl const dbl_4pi_3;									   // Pi*4/3 (approx 4.18879) as double.
ijk_ext dbl const dbl_6pi_5;									   // Pi*6/5 (approx 3.76991) as double.
ijk_ext dbl const dbl_pi;										   // Pi (approx 3.14159) as double.
ijk_ext dbl const dbl_5pi_6;									   // Pi*5/6 (approx 2.61799) as double.
ijk_ext dbl const dbl_3pi_4;									   // Pi*3/4 (approx 2.35619) as double.
ijk_ext dbl const dbl_2pi_3;									   // Pi*2/3 (approx 2.09439) as double.
ijk_ext dbl const dbl_pi_2;										   // Pi/2 (approx 1.57079) as double.
ijk_ext dbl const dbl_pi_3;										   // Pi/3 (approx 1.05719) as double.
ijk_ext dbl const dbl_pi_4;										   // Pi/4 (approx 0.78539) as double.
ijk_ext dbl const dbl_pi_6;										   // Pi/6 (approx 0.52360) as double.
ijk_ext dbl const dbl_360;										   // 360 as double.
ijk_ext dbl const dbl_180;										   // 180 as double.
ijk_ext dbl const dbl_90;										   // 90 as double.
ijk_ext dbl const dbl_60;										   // 60 as double.
ijk_ext dbl const dbl_45;										   // 45 as double.
ijk_ext dbl const dbl_30;										   // 30 as double.
ijk_ext dbl const dbl_deg2rad;									   // Pi/180 (approx 0.01745) as double.
ijk_ext dbl const dbl_rad2deg;									   // 180/pi (approx 57.29578) as double.


// Macros for doubles.
///
#define ijk_sgn_dbl(x)				((x) != dbl_zero ? (x) > dbl_zero ? +dbl_one : -dbl_one : dbl_zero)	// sgn(x) = x > 0 ? +1 : x < 0 ? -1 : 0
#define ijk_abs_dbl(x)				((x) >= dbl_zero ? +(x) : -(x))										// abs(x) = x >= 0 ? +x : -x
#define ijk_nrm2sym_dbl(x)			((x) * dbl_two - dbl_one)											// nrm2sym(x) = 2x - 1
#define ijk_sym2nrm_dbl(x)			((x) * dbl_half + dbl_half)											// sym2nrm(x) = (x + 1)/2
#define ijk_isnrm_dbl(x)			ijk_isclamp(dbl_zero,dbl_one,x)										// isnrm(x) = 0 <= x <= 1
#define ijk_isnnrm_dbl(x)			ijk_isnclamp(dbl_zero,dbl_one,x)									// isnnrm(x) = !isnrm(x)
#define ijk_issym_dbl(x)			ijk_isclamp(-dbl_one,+dbl_one,x)									// issym(x) = -1 <= x <= +1
#define ijk_isnsym_dbl(x)			ijk_isnclamp(-dbl_one,+dbl_one,x)									// isnsym(x) = !issym(x)
#define ijk_iszero_dbl(x)			ijk_isclamp(-dbl_eps,+dbl_eps,x)									// iszero(x) = -eps <= x <= +eps
#define ijk_isnzero_dbl(x)			ijk_isnclamp(-dbl_eps,+dbl_eps,x)									// isnzero(x) = !iszero(x)
#define ijk_trunc_dbl(x)			((f64)((i64)(x)))													// trunc(x) = int(x)
#define ijk_divide_safe_dbl(n,d)	((d) != dbl_zero ? ijk_divide(n,d) : dbl_zero)						// divide_safe(n,d) = n/d, d != 0
#define ijk_modulo_dbl(n,d)			((n) - (d)*ijk_trunc_dbl(ijk_divide(n,d)))							// modulo(n,d) = n - d*trunc(n/d)
#define ijk_modulo_safe_dbl(n,d)	((d) != dbl_zero ? ijk_modulo_dbl(n,d) : (n))						// modulo_safe(n,d) = d != 0 ? modulo(n,d) : n
#define ijk_recip_dbl(x)			(dbl_one / (x))														// recip(x) = 1/x
#define ijk_recip_safe_dbl(x)		((x != dbl_zero) ? ijk_recip_dbl(x) : dbl_zero)						// recip_safe(x) = 1/x, x != 0
#define ijk_deg2rad_dbl(x)			((x) * dbl_deg2rad)													// deg2rad(x) = x * pi/180
#define ijk_rad2deg_dbl(x)			((x) * dbl_rad2deg)													// rad2deg(x) = x * 180/pi


//-----------------------------------------------------------------------------

// Global constants for real type.
///
#define real_zero					ijk_declrealv(zero)				// Zero as real type.
#define real_eps					ijk_declrealv(eps)				// Epsilon as real type.
#define real_halfeps				ijk_declrealv(halfeps)			// Half epsilon as real type.
#define real_1000th					ijk_declrealv(1000th)			// 1/1000 as real type.
#define real_100th					ijk_declrealv(100th)			// 1/100 as real type.
#define real_10th					ijk_declrealv(10th)				// 1/10 as real type.
#define real_9th					ijk_declrealv(9th)				// 1/9 as real type.
#define real_8th					ijk_declrealv(8th)				// 1/8 as real type.
#define real_7th					ijk_declrealv(7th)				// 1/7 as real type.
#define real_6th					ijk_declrealv(6th)				// 1/6 as real type.
#define real_5th					ijk_declrealv(5th)				// 1/5 as real type.
#define real_quarter				ijk_declrealv(quarter)			// 1/4 as real type.
#define real_third					ijk_declrealv(third)			// 1/3 as real type.
#define real_half					ijk_declrealv(half)				// 1/2 as real type.
#define real_2thirds				ijk_declrealv(2thirds)			// 2/3 as real type.
#define real_3quarters				ijk_declrealv(3quarters)		// 3/4 as real type.
#define real_one					ijk_declrealv(one)				// One as real type.
#define real_4third					ijk_declrealv(4third)			// 4/3 as real type.
#define real_3half					ijk_declrealv(3half)			// 3/2 as real type.
#define real_two					ijk_declrealv(two)				// 2 as real type.
#define real_three					ijk_declrealv(three)			// 3 as real type.
#define real_four					ijk_declrealv(four)				// 4 as real type.
#define real_five					ijk_declrealv(five)				// 5 as real type.
#define real_six					ijk_declrealv(six)				// 6 as real type.
#define real_seven					ijk_declrealv(seven)			// 7 as real type.
#define real_eight					ijk_declrealv(eight)			// 8 as real type.
#define real_nine					ijk_declrealv(nine)				// 9 as real type.
#define real_ten					ijk_declrealv(ten)				// 10 as real type.
#define real_hundred				ijk_declrealv(hundred)			// 100 as real type.
#define real_thousand				ijk_declrealv(thousand)			// 1000 as real type.
#define real_sqrtthird				ijk_declrealv(sqrtthird)		// Sqrt(1/3) as real type.
#define real_sqrthalf				ijk_declrealv(sqrthalf)			// Sqrt(1/2) as real type.
#define real_sqrt2					ijk_declrealv(sqrt2)			// Sqrt(2) as real type.
#define real_sqrt3					ijk_declrealv(sqrt3)			// Sqrt(3) as real type.
#define real_6pi					ijk_declrealv(6pi)				// Pi*6 (approx 18.84956) as real type.
#define real_4pi					ijk_declrealv(4pi)				// Pi*4 (approx 12.56637) as real type.
#define real_3pi					ijk_declrealv(3pi)				// Pi*3 (approx 9.42478) as real type.
#define real_2pi					ijk_declrealv(2pi)				// Pi*2 (approx 6.28319) as real type.
#define real_3pi_2					ijk_declrealv(3pi_2)			// Pi*3/2 (approx 4.71239) as real type.
#define real_4pi_3					ijk_declrealv(4pi_3)			// Pi*4/3 (approx 4.18879) as real type.
#define real_6pi_5					ijk_declrealv(6pi_5)			// Pi*6/5 (approx 3.76991) as real type.
#define real_pi						ijk_declrealv(pi)				// Pi (approx 3.14159) as real type.
#define real_5pi_6					ijk_declrealv(5pi_6)			// Pi*5/6 (approx 2.61799) as real type.
#define real_3pi_4					ijk_declrealv(3pi_4)			// Pi*3/4 (approx 2.35619) as real type.
#define real_2pi_3					ijk_declrealv(2pi_3)			// Pi*2/3 (approx 2.09439) as real type.
#define real_pi_2					ijk_declrealv(pi_2)				// Pi/2 (approx 1.57079) as real type.
#define real_pi_3					ijk_declrealv(pi_3)				// Pi/3 (approx 1.05719) as real type.
#define real_pi_4					ijk_declrealv(pi_4)				// Pi/4 (approx 0.78539) as real type.
#define real_pi_6					ijk_declrealv(pi_6)				// Pi/6 (approx 0.52360) as real type.
#define real_360					ijk_declrealv(360)				// 360 as real type.
#define real_180					ijk_declrealv(180)				// 180 as real type.
#define real_90						ijk_declrealv(90)				// 90 as real type.
#define real_60						ijk_declrealv(60)				// 60 as real type.
#define real_45						ijk_declrealv(45)				// 45 as real type.
#define real_30						ijk_declrealv(30)				// 30 as real type.
#define real_deg2rad				ijk_declrealv(deg2rad)			// Pi/180 (approx 0.01745) as real type.
#define real_rad2deg				ijk_declrealv(rad2deg)			// 180/pi (approx 57.29578) as real type.


// Macros for real type.
///
#define ijk_sgn						ijk_declrealf(ijk_sgn)												// sgn(x) = x > 0 ? +1 : x < 0 ? -1 : 0
#define ijk_abs						ijk_declrealf(ijk_abs)												// abs(x) = x >= 0 ? +x : -x
#define ijk_nrm2sym					ijk_declrealf(ijk_nrm2sym)											// nrm2sym(x) = 2x - 1
#define ijk_sym2nrm					ijk_declrealf(ijk_sym2nrm)											// sym2nrm(x) = (x + 1)/2
#define ijk_isnrm					ijk_declrealf(ijk_isnrm)											// isnrm(x) = 0 <= x <= 1
#define ijk_isnnrm					ijk_declrealf(ijk_isnnrm)											// isnnrm(x) = !isnrm(x)
#define ijk_issym					ijk_declrealf(ijk_issym)											// issym(x) = -1 <= x <= +1
#define ijk_isnsym					ijk_declrealf(ijk_isnsym)											// isnsym(x) = !issym(x)
#define ijk_iszero					ijk_declrealf(ijk_iszero)											// iszero(x) = -eps <= x <= +eps
#define ijk_isnzero					ijk_declrealf(ijk_isnzero)											// isnzero(x) = !iszero(x)
#define ijk_trunc					ijk_declrealf(ijk_trunc)											// trunc(x) = int(x)
#define ijk_divide_safe				ijk_declrealf(ijk_divide_safe)										// divide_safe(n,d) = n/d, d != 0
#define ijk_modulo					ijk_declrealf(ijk_modulo)											// modulo(n,d) = n - d*trunc(n/d)
#define ijk_modulo_safe				ijk_declrealf(ijk_modulo_safe)										// modulo_safe(n,d) = d != 0 ? modulo(n,d) : n
#define ijk_recip					ijk_declrealf(ijk_recip)											// recip(x) = 1/x
#define ijk_recip_safe				ijk_declrealf(ijk_recip_safe)										// recip_safe(x) = 1/x, x != 0
#define ijk_deg2rad					ijk_declrealf(ijk_deg2rad)											// deg2rad(x) = x * pi/180
#define ijk_rad2deg					ijk_declrealf(ijk_rad2deg)											// rad2deg(x) = x * 180/pi


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif	// !_IJK_REAL_H_