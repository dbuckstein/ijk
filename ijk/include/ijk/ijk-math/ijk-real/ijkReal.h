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


//-----------------------------------------------------------------------------

// IJK_REAL_DBL
//	User-defined macro to select double as base real number type. If not 
//	defined, the base real number type defaults to float.	
#ifdef IJK_REAL_DBL
// Real number type is based on 64-bit float (double).
#define ijk_real					dbl
#else	// !IJK_REAL_DBL
// Real number type is based on 32-bit float (single).
#define ijk_real					flt
#endif	// IJK_REAL_DBL

// real
//	Real number type.
typedef ijk_real					real;

// ijk_x2real
//	Cast to real.
//		param x: value to cast
//		return: value as real
#define ijk_x2real(x)				(real)(x)

// ijk_declreal
//	Declare real function.
//		param func: name of function to declare for real type
//		return: name of function for real type
#define ijk_declreal(func)			ijk_tokencat(ijk_tokencat(func,_),ijk_real)


// global constants for float type
///
ijk_ext flt const flt_zero;
ijk_ext flt const flt_eps;
ijk_ext flt const flt_halfeps;
ijk_ext flt const flt_1000th;
ijk_ext flt const flt_100th;
ijk_ext flt const flt_10th;
ijk_ext flt const flt_9th;
ijk_ext flt const flt_8th;
ijk_ext flt const flt_7th;
ijk_ext flt const flt_6th;
ijk_ext flt const flt_5th;
ijk_ext flt const flt_quarter;
ijk_ext flt const flt_third;
ijk_ext flt const flt_half;
ijk_ext flt const flt_2thirds;
ijk_ext flt const flt_3quarters;
ijk_ext flt const flt_one;
ijk_ext flt const flt_4third;
ijk_ext flt const flt_3half;
ijk_ext flt const flt_two;
ijk_ext flt const flt_three;
ijk_ext flt const flt_four;
ijk_ext flt const flt_five;
ijk_ext flt const flt_six;
ijk_ext flt const flt_seven;
ijk_ext flt const flt_eight;
ijk_ext flt const flt_nine;
ijk_ext flt const flt_ten;
ijk_ext flt const flt_hundred;
ijk_ext flt const flt_thousand;
ijk_ext flt const flt_sqrtthird;
ijk_ext flt const flt_sqrthalf;
ijk_ext flt const flt_sqrt2;
ijk_ext flt const flt_sqrt3;
ijk_ext flt const flt_2pi;
ijk_ext flt const flt_pi;
ijk_ext flt const flt_halfpi;
ijk_ext flt const flt_thirdpi;
ijk_ext flt const flt_quarterpi;
ijk_ext flt const flt_360;
ijk_ext flt const flt_180;
ijk_ext flt const flt_90;
ijk_ext flt const flt_60;
ijk_ext flt const flt_45;
ijk_ext flt const flt_deg2rad;
ijk_ext flt const flt_rad2deg;


// global constants for double type
///
ijk_ext dbl const dbl_zero;
ijk_ext dbl const dbl_eps;
ijk_ext dbl const dbl_halfeps;
ijk_ext dbl const dbl_1000th;
ijk_ext dbl const dbl_100th;
ijk_ext dbl const dbl_10th;
ijk_ext dbl const dbl_9th;
ijk_ext dbl const dbl_8th;
ijk_ext dbl const dbl_7th;
ijk_ext dbl const dbl_6th;
ijk_ext dbl const dbl_5th;
ijk_ext dbl const dbl_quarter;
ijk_ext dbl const dbl_third;
ijk_ext dbl const dbl_half;
ijk_ext dbl const dbl_2thirds;
ijk_ext dbl const dbl_3quarters;
ijk_ext dbl const dbl_one;
ijk_ext dbl const dbl_4third;
ijk_ext dbl const dbl_3half;
ijk_ext dbl const dbl_two;
ijk_ext dbl const dbl_three;
ijk_ext dbl const dbl_four;
ijk_ext dbl const dbl_five;
ijk_ext dbl const dbl_six;
ijk_ext dbl const dbl_seven;
ijk_ext dbl const dbl_eight;
ijk_ext dbl const dbl_nine;
ijk_ext dbl const dbl_ten;
ijk_ext dbl const dbl_hundred;
ijk_ext dbl const dbl_thousand;
ijk_ext dbl const dbl_sqrtthird;
ijk_ext dbl const dbl_sqrthalf;
ijk_ext dbl const dbl_sqrt2;
ijk_ext dbl const dbl_sqrt3;
ijk_ext dbl const dbl_2pi;
ijk_ext dbl const dbl_pi;
ijk_ext dbl const dbl_halfpi;
ijk_ext dbl const dbl_thirdpi;
ijk_ext dbl const dbl_quarterpi;
ijk_ext dbl const dbl_360;
ijk_ext dbl const dbl_180;
ijk_ext dbl const dbl_90;
ijk_ext dbl const dbl_60;
ijk_ext dbl const dbl_45;
ijk_ext dbl const dbl_deg2rad;
ijk_ext dbl const dbl_rad2deg;


// global constants for real type
///
#define real_zero					ijk_tokencat(ijk_real,_zero)
#define real_eps					ijk_tokencat(ijk_real,_eps)
#define real_halfeps				ijk_tokencat(ijk_real,_halfeps)
#define real_1000th					ijk_tokencat(ijk_real,_1000th)
#define real_100th					ijk_tokencat(ijk_real,_100th)
#define real_10th					ijk_tokencat(ijk_real,_10th)
#define real_9th					ijk_tokencat(ijk_real,_9th)
#define real_8th					ijk_tokencat(ijk_real,_8th)
#define real_7th					ijk_tokencat(ijk_real,_7th)
#define real_6th					ijk_tokencat(ijk_real,_6th)
#define real_5th					ijk_tokencat(ijk_real,_5th)
#define real_quarter				ijk_tokencat(ijk_real,_quarter)
#define real_third					ijk_tokencat(ijk_real,_third)
#define real_half					ijk_tokencat(ijk_real,_half)
#define real_2thirds				ijk_tokencat(ijk_real,_2thirds)
#define real_3quarters				ijk_tokencat(ijk_real,_3quarters)
#define real_one					ijk_tokencat(ijk_real,_one)
#define real_4third					ijk_tokencat(ijk_real,_4third)
#define real_3half					ijk_tokencat(ijk_real,_3half)
#define real_two					ijk_tokencat(ijk_real,_two)
#define real_three					ijk_tokencat(ijk_real,_three)
#define real_four					ijk_tokencat(ijk_real,_four)
#define real_five					ijk_tokencat(ijk_real,_five)
#define real_six					ijk_tokencat(ijk_real,_six)
#define real_seven					ijk_tokencat(ijk_real,_seven)
#define real_eight					ijk_tokencat(ijk_real,_eight)
#define real_nine					ijk_tokencat(ijk_real,_nine)
#define real_ten					ijk_tokencat(ijk_real,_ten)
#define real_hundred				ijk_tokencat(ijk_real,_hundred)
#define real_thousand				ijk_tokencat(ijk_real,_thousand)
#define real_sqrtthird				ijk_tokencat(ijk_real,_sqrtthird)
#define real_sqrthalf				ijk_tokencat(ijk_real,_sqrthalf)
#define real_sqrt2					ijk_tokencat(ijk_real,_sqrt2)
#define real_sqrt3					ijk_tokencat(ijk_real,_sqrt3)
#define real_2pi					ijk_tokencat(ijk_real,_2pi)
#define real_pi						ijk_tokencat(ijk_real,_pi)
#define real_halfpi					ijk_tokencat(ijk_real,_halfpi)
#define real_thirdpi				ijk_tokencat(ijk_real,_thirdpi)
#define real_quarterpi				ijk_tokencat(ijk_real,_quarterpi)
#define real_360					ijk_tokencat(ijk_real,_360)
#define real_180					ijk_tokencat(ijk_real,_180)
#define real_90						ijk_tokencat(ijk_real,_90)
#define real_60						ijk_tokencat(ijk_real,_60)
#define real_45						ijk_tokencat(ijk_real,_45)
#define real_deg2rad				ijk_tokencat(ijk_real,_deg2rad)
#define real_rad2deg				ijk_tokencat(ijk_real,_rad2deg)


// ijk_lerp
//	Linear interpolation.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param t: interpolation parameter; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
//		return: interpolated value 'v'; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
#define ijk_lerp(v0,v1,t)			((v0) + ((v1) - (v0)) * (t))

// ijk_unlerp
//	Linear interpolation inverse.
//		param v0: lower bound at t=0
//		param v1: upper bound at t=1
//		param v: interpolated value; v=[v0,v1] for interpolation,
//			v=(-inf,v0)U(v1,+inf) for extrapolation
//		return: interpolation parameter 't'; t=[0,1] for interpolation,
//			t=(-inf,0)U(1,+inf) for extrapolation
#define ijk_unlerp(v0,v1,v)			(((v) - (v0)) / ((v1) - (v0)))

// ijk_unlerp_safe
//	Linear interpolation with division-by-zero safety.
#define ijk_unlerp_safe(v0,v1,v)	((v0) != (v1) ? ijk_unlerp(v0,v1,v) : ((v1) - (v0)))

// ijk_remap
//	Re-map or re-interpolate value from one range into another.
//		param v0_new: lower bound of new/output range
//		param v1_new: upper bound of new/output range
//		param v0_orig: lower bound of original/input range
//		param v1_orig: upper bound of original/input range
//		return: re-interpolated value 'v_new' in new/output range
#define ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig)			((v0_new) + (((v1_new) - (v0_new)) * ((v_orig) - (v0_orig))) / ((v1_orig) - (v0_orig)))

// ijk_remap_safe
//	Re-map/re-interpolate with division-by-zero safety.
#define ijk_remap_safe(v0_new,v1_new,v0_orig,v1_orig,v_orig)	((v0_orig) != (v1_orig) ? ijk_remap(v0_new,v1_new,v0_orig,v1_orig,v_orig) : (v0_new))

// ijk_divide
//	Perform division.
//		param n: numerator (top)
//		param d: denominator (bottom)
//		return: quotient of (n/d)
#define ijk_divide(n,d)				((n) / (d))


// sign function
///
#define ijk_sgn_int(x)				((x) > ijk_zero ? +ijk_one : (x) < ijk_zero ? -ijk_one : ijk_zero)
#define ijk_sgn_flt(x)				((x) > flt_zero ? +flt_one : (x) < flt_zero ? -flt_one : flt_zero)
#define ijk_sgn_dbl(x)				((x) > dbl_zero ? +dbl_one : (x) < dbl_zero ? -dbl_one : dbl_zero)
#define ijk_sgn						ijk_declreal(ijk_sgn)

// absolute value function
///
#define ijk_abs_int(x)				((x) >= ijk_zero ? +(x) : -(x))
#define ijk_abs_flt(x)				((x) >= flt_zero ? +(x) : -(x))
#define ijk_abs_dbl(x)				((x) >= dbl_zero ? +(x) : -(x))
#define ijk_abs						ijk_declreal(ijk_abs)

// conversion from normalized unit [0,1] to symmetric unit [-1,+1]
///
#define ijk_nrm2sym_int(x)			(((x) << ijk_one) - ijk_one)
#define ijk_nrm2sym_flt(x)			((x) * flt_two - flt_one)
#define ijk_nrm2sym_dbl(x)			((x) * dbl_two - dbl_one)
#define ijk_nrm2sym					ijk_declreal(ijk_nrm2sym)

// conversion from symmetric unit [-1,+1] to normalized unit [0,1]
///
#define ijk_sym2nrm_int(x)			(((x) + ijk_one) >> ijk_one)
#define ijk_sym2nrm_flt(x)			((x) * flt_half + flt_half)
#define ijk_sym2nrm_dbl(x)			((x) * dbl_half + dbl_half)
#define ijk_sym2nrm					ijk_declreal(ijk_sym2nrm)

// check if value is in normalized unit range [0,1]
#define ijk_isnrm_int(x)			((x) >= ijk_zero && (x) <= ijk_one)
#define ijk_isnrm_flt(x)			((x) >= flt_zero && (x) <= flt_one)
#define ijk_isnrm_dbl(x)			((x) >= dbl_zero && (x) <= dbl_one)
#define ijk_isnrm					ijk_declreal(ijk_isnrm)

// check if value is not in normalized unit range
#define ijk_isnnrm_int(x)			((x) < ijk_zero || (x) > ijk_one)
#define ijk_isnnrm_flt(x)			((x) < flt_zero || (x) > flt_one)
#define ijk_isnnrm_dbl(x)			((x) < dbl_zero || (x) > dbl_one)
#define ijk_isnnrm					ijk_declreal(ijk_isnnrm)

// check if value is in symmetric unit range [-1,+1]
#define ijk_issym_int(x)			((x) >= -ijk_one && (x) <= +ijk_one)
#define ijk_issym_flt(x)			((x) >= -flt_one && (x) <= +flt_one)
#define ijk_issym_dbl(x)			((x) >= -dbl_one && (x) <= +dbl_one)
#define ijk_issym					ijk_declreal(ijk_issym)

// check if value is not in symmetric unit range
#define ijk_isnsym_int(x)			((x) < -ijk_one || (x) > +ijk_one)
#define ijk_isnsym_flt(x)			((x) < -flt_one || (x) > +flt_one)
#define ijk_isnsym_dbl(x)			((x) < -dbl_one || (x) > +dbl_one)
#define ijk_isnsym					ijk_declreal(ijk_isnsym)

// check if value is near zero
///
#define ijk_iszero_int(x)			((x) == ijk_zero)
#define ijk_iszero_flt(x)			((x) >= -flt_eps && (x) <= +flt_eps)
#define ijk_iszero_dbl(x)			((x) >= -dbl_eps && (x) <= +dbl_eps)
#define ijk_iszero					ijk_declreal(ijk_iszero)

// check if value is not near zero
///
#define ijk_isnzero_int(x)			((x) != ijk_zero)
#define ijk_isnzero_flt(x)			((x) < -flt_eps || (x) > +flt_eps)
#define ijk_isnzero_dbl(x)			((x) < -dbl_eps || (x) > +dbl_eps)
#define ijk_isnzero					ijk_declreal(ijk_isnzero)

// division-by-zero safety
///
#define ijk_divide_safe_int(n,d)	((d) != ijk_zero ? ijk_divide(n,d) : ijk_zero)
#define ijk_divide_safe_flt(n,d)	((d) != flt_zero ? ijk_divide(n,d) : flt_zero)
#define ijk_divide_safe_dbl(n,d)	((d) != dbl_zero ? ijk_divide(n,d) : dbl_zero)
#define ijk_divide_safe				ijk_declreal(ijk_divide_safe)


// reciprocal
///
#define ijk_recip_flt(x)			(flt_one / (x))
#define ijk_recip_dbl(x)			(dbl_one / (x))
#define ijk_recip					ijk_declreal(ijk_recip)

// reciprocal with division-by-zero safety
///
#define ijk_recip_safe_flt(x)		((x != flt_zero) ? ijk_recip_flt(x) : flt_zero)
#define ijk_recip_safe_dbl(x)		((x != dbl_zero) ? ijk_recip_dbl(x) : dbl_zero)
#define ijk_recip_safe				ijk_declreal(ijk_recip_safe)

// convert degrees to radians
///
#define ijk_deg2rad_flt(x)			((x) * flt_deg2rad)
#define ijk_deg2rad_dbl(x)			((x) * dbl_deg2rad)
#define ijk_deg2rad					ijk_declreal(ijk_deg2rad)

// convert radians to degrees
///
#define ijk_rad2deg_flt(x)			((x) * flt_rad2deg)
#define ijk_rad2deg_dbl(x)			((x) * dbl_rad2deg)
#define ijk_rad2deg					ijk_declreal(ijk_rad2deg)


//-----------------------------------------------------------------------------


#endif	// !_IJK_REAL_H_