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
#define ijk_real		dbl
#else	// !IJK_REAL_DBL
// Real number type is based on 32-bit float (single).
#define ijk_real		flt
#endif	// IJK_REAL_DBL

// real
//	Real number type.
typedef ijk_real		real;

// ijk_x2real
//	Cast to real.
//		param x: value to cast
//		return: value as real
#define ijk_x2real(x)	(real)(x)


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


// global constants for double, float and real
///
#define dbl_zero					0.0
#define flt_zero					ijk_tokencat(dbl_zero,f)
#define real_zero					ijk_tokencat(ijk_real,_zero)
#define dbl_1000th					0.001
#define flt_1000th					ijk_tokencat(dbl_1000th,f)
#define real_1000th					ijk_tokencat(ijk_real,_1000th)
#define dbl_100th					0.01
#define flt_100th					ijk_tokencat(dbl_100th,f)
#define real_100th					ijk_tokencat(ijk_real,_100th)
#define dbl_10th					0.1
#define flt_10th					ijk_tokencat(dbl_10th,f)
#define real_10th					ijk_tokencat(ijk_real,_10th)
#define dbl_9th						0.11111111111111111111111111111111
#define flt_9th						ijk_tokencat(dbl_9th,f)
#define real_9th					ijk_tokencat(ijk_real,_9th)
#define dbl_8th						0.125
#define flt_8th						ijk_tokencat(dbl_8th,f)
#define real_8th					ijk_tokencat(ijk_real,_8th)
#define dbl_7th						0.14285714285714285714285714285714
#define flt_7th						ijk_tokencat(dbl_7th,f)
#define real_7th					ijk_tokencat(ijk_real,_7th)
#define dbl_6th						0.16666666666666666666666666666667
#define flt_6th						ijk_tokencat(dbl_6th,f)
#define real_6th					ijk_tokencat(ijk_real,_6th)
#define dbl_5th						0.2
#define flt_5th						ijk_tokencat(dbl_5th,f)
#define real_5th					ijk_tokencat(ijk_real,_5th)
#define dbl_quarter					0.25
#define flt_quarter					ijk_tokencat(dbl_quarter,f)
#define real_quarter				ijk_tokencat(ijk_real,_quarter)
#define dbl_third					0.33333333333333333333333333333333
#define flt_third					ijk_tokencat(dbl_third,f)
#define real_third					ijk_tokencat(ijk_real,_third)
#define dbl_half					0.5
#define flt_half					ijk_tokencat(dbl_half,f)
#define real_half					ijk_tokencat(ijk_real,_half)
#define dbl_2thirds					0.66666666666666666666666666666667
#define flt_2thirds					ijk_tokencat(dbl_2thirds,f)
#define real_2thirds				ijk_tokencat(ijk_real,_2thirds)
#define dbl_3quarters				0.75
#define flt_3quarters				ijk_tokencat(dbl_3quarters,f)
#define real_3quarters				ijk_tokencat(ijk_real,_3quarters)
#define dbl_one						1.0
#define flt_one						ijk_tokencat(dbl_one,f)
#define real_one					ijk_tokencat(ijk_real,_one)
#define dbl_4third					1.3333333333333333333333333333333
#define flt_4third					ijk_tokencat(dbl_4third,f)
#define real_4third					ijk_tokencat(ijk_real,_4third)
#define dbl_3half					1.5
#define flt_3half					ijk_tokencat(dbl_3half,f)
#define real_3half					ijk_tokencat(ijk_real,_3half)
#define dbl_two						2.0
#define flt_two						ijk_tokencat(dbl_two,f)
#define real_two					ijk_tokencat(ijk_real,_two)
#define dbl_three					3.0
#define flt_three					ijk_tokencat(dbl_three,f)
#define real_three					ijk_tokencat(ijk_real,_three)
#define dbl_four					4.0
#define flt_four					ijk_tokencat(dbl_four,f)
#define real_four					ijk_tokencat(ijk_real,_four)
#define dbl_five					5.0
#define flt_five					ijk_tokencat(dbl_five,f)
#define real_five					ijk_tokencat(ijk_real,_five)
#define dbl_six						6.0
#define flt_six						ijk_tokencat(dbl_six,f)
#define real_six					ijk_tokencat(ijk_real,_six)
#define dbl_seven					7.0
#define flt_seven					ijk_tokencat(dbl_seven,f)
#define real_seven					ijk_tokencat(ijk_real,_seven)
#define dbl_eight					8.0
#define flt_eight					ijk_tokencat(dbl_eight,f)
#define real_eight					ijk_tokencat(ijk_real,_eight)
#define dbl_nine					9.0
#define flt_nine					ijk_tokencat(dbl_nine,f)
#define real_nine					ijk_tokencat(ijk_real,_nine)
#define dbl_ten						10.0
#define flt_ten						ijk_tokencat(dbl_ten,f)
#define real_ten					ijk_tokencat(ijk_real,_ten)
#define dbl_hundred					100.0
#define flt_hundred					ijk_tokencat(dbl_hundred,f)
#define real_hundred				ijk_tokencat(ijk_real,_hundred)
#define dbl_thousand				1000.0
#define flt_thousand				ijk_tokencat(dbl_thousand,f)
#define real_thousand				ijk_tokencat(ijk_real,_thousand)
#define dbl_sqrtthird				0.57735026918962576450914878050196
#define flt_sqrtthird				ijk_tokencat(dbl_sqrtthird,f)
#define real_sqrtthird				ijk_tokencat(ijk_real,_sqrtthird)
#define dbl_sqrthalf				0.70710678118654752440084436210485
#define flt_sqrthalf				ijk_tokencat(dbl_sqrthalf,f)
#define real_sqrthalf				ijk_tokencat(ijk_real,_sqrthalf)
#define dbl_sqrt2					1.4142135623730950488016887242097
#define flt_sqrt2					ijk_tokencat(dbl_sqrt2,f)
#define real_sqrt2					ijk_tokencat(ijk_real,_sqrt2)
#define dbl_sqrt3					1.7320508075688772935274463415059
#define flt_sqrt3					ijk_tokencat(dbl_sqrt3,f)
#define real_sqrt3					ijk_tokencat(ijk_real,_sqrt3)
#define dbl_2pi						6.283185307179586476925286766559
#define flt_2pi						ijk_tokencat(dbl_2pi,f)
#define real_2pi					ijk_tokencat(ijk_real,_2pi)
#define dbl_pi						3.1415926535897932384626433832795
#define flt_pi						ijk_tokencat(dbl_pi,f)
#define real_pi						ijk_tokencat(ijk_real,_pi)
#define dbl_halfpi					1.5707963267948966192313216916398
#define flt_halfpi					ijk_tokencat(dbl_halfpi,f)
#define real_halfpi					ijk_tokencat(ijk_real,_halfpi)
#define dbl_thirdpi					1.0471975511965977461542144610932
#define flt_thirdpi					ijk_tokencat(dbl_thirdpi,f)
#define real_thirdpi				ijk_tokencat(ijk_real,_thirdpi)
#define dbl_quarterpi				0.78539816339744830961566084581988
#define flt_quarterpi				ijk_tokencat(dbl_quarterpi,f)
#define real_quarterpi				ijk_tokencat(ijk_real,_quarterpi)
#define dbl_360						360.0
#define flt_360						ijk_tokencat(dbl_360,f)
#define real_360					ijk_tokencat(ijk_real,_360)
#define dbl_180						180.0
#define flt_180						ijk_tokencat(dbl_180,f)
#define real_180					ijk_tokencat(ijk_real,_180)
#define dbl_90						90.0
#define flt_90						ijk_tokencat(dbl_90,f)
#define real_90						ijk_tokencat(ijk_real,_90)
#define dbl_60						60.0
#define flt_60						ijk_tokencat(dbl_60,f)
#define real_60						ijk_tokencat(ijk_real,_60)
#define dbl_45						45.0
#define flt_45						ijk_tokencat(dbl_45,f)
#define real_45						ijk_tokencat(ijk_real,_45)
#define dbl_deg2rad					0.01745329251994329576923690768489
#define flt_deg2rad					ijk_tokencat(dbl_deg2rad,f)
#define real_deg2rad				ijk_tokencat(ijk_real,_deg2rad)
#define dbl_rad2deg					57.295779513082320876798154814105
#define flt_rad2deg					ijk_tokencat(dbl_rad2deg,f)
#define real_rad2deg				ijk_tokencat(ijk_real,_rad2deg)
#define dbl_eps						2.22e-16
#define flt_eps						1.19e-07f
#define real_eps					ijk_tokencat(ijk_real,_eps)
#define dbl_halfeps					1.11e-16
#define flt_halfeps					5.96e-08f
#define real_halfeps				ijk_tokencat(ijk_real,_halfeps)


// sign function
///
#define ijk_sgn_int(x)				((x) > ijk_zero ? +ijk_one : (x) < ijk_zero ? -ijk_one : ijk_zero)
#define ijk_sgn_flt(x)				((x) > flt_zero ? +flt_one : (x) < flt_zero ? -flt_one : flt_zero)
#define ijk_sgn_dbl(x)				((x) > dbl_zero ? +dbl_one : (x) < dbl_zero ? -dbl_one : dbl_zero)
#define ijk_sgn						ijk_tokencat(ijk_sign_,ijk_real)

// absolute value function
///
#define ijk_abs_int(x)				((x) >= ijk_zero ? +(x) : -(x))
#define ijk_abs_flt(x)				((x) >= flt_zero ? +(x) : -(x))
#define ijk_abs_dbl(x)				((x) >= dbl_zero ? +(x) : -(x))
#define ijk_abs						ijk_tokencat(ijk_abs_,ijk_real)

// conversion from normalized unit [0,1] to symmetric unit [-1,+1]
///
#define ijk_nrm2sym_int(x)			(((x) << ijk_one) - ijk_one)
#define ijk_nrm2sym_flt(x)			((x) * flt_two - flt_one)
#define ijk_nrm2sym_dbl(x)			((x) * dbl_two - dbl_one)
#define ijk_nrm2sym					ijk_tokencat(ijk_nrm2sym_,ijk_real)

// conversion from symmetric unit [-1,+1] to normalized unit [0,1]
///
#define ijk_sym2nrm_int(x)			(((x) + ijk_one) >> ijk_one)
#define ijk_sym2nrm_flt(x)			((x) * flt_half + flt_half)
#define ijk_sym2nrm_dbl(x)			((x) * dbl_half + dbl_half)
#define ijk_sym2nrm					ijk_tokencat(ijk_sym2nrm_,ijk_real)

// check if value is in normalized unit range [0,1]
#define ijk_isnrm_int(x)			((x) >= ijk_zero && (x) <= ijk_one)
#define ijk_isnrm_flt(x)			((x) >= flt_zero && (x) <= flt_one)
#define ijk_isnrm_dbl(x)			((x) >= dbl_zero && (x) <= dbl_one)
#define ijk_isnrm					ijk_tokencat(ijk_isnrm_,ijk_real)

// check if value is not in normalized unit range
#define ijk_isnnrm_int(x)			((x) < ijk_zero || (x) > ijk_one)
#define ijk_isnnrm_flt(x)			((x) < flt_zero || (x) > flt_one)
#define ijk_isnnrm_dbl(x)			((x) < dbl_zero || (x) > dbl_one)
#define ijk_isnnrm					ijk_tokencat(ijk_isnrm_,ijk_real)

// check if value is in symmetric unit range [-1,+1]
#define ijk_issym_int(x)			((x) >= -ijk_one && (x) <= +ijk_one)
#define ijk_issym_flt(x)			((x) >= -flt_one && (x) <= +flt_one)
#define ijk_issym_dbl(x)			((x) >= -dbl_one && (x) <= +dbl_one)
#define ijk_issym					ijk_tokencat(ijk_issym_,ijk_real)

// check if value is not in symmetric unit range
#define ijk_isnsym_int(x)			((x) < -ijk_one || (x) > +ijk_one)
#define ijk_isnsym_flt(x)			((x) < -flt_one || (x) > +flt_one)
#define ijk_isnsym_dbl(x)			((x) < -dbl_one || (x) > +dbl_one)
#define ijk_isnsym					ijk_tokencat(ijk_issym_,ijk_real)

// check if value is near zero
///
#define ijk_iszero_int(x)			((x) == ijk_zero)
#define ijk_iszero_flt(x)			((x) >= -flt_eps && (x) <= +flt_eps)
#define ijk_iszero_dbl(x)			((x) >= -dbl_eps && (x) <= +dbl_eps)
#define ijk_iszero					ijk_tokencat(ijk_iszero_,ijk_real)

// check if value is not near zero
///
#define ijk_isnzero_int(x)			((x) != ijk_zero)
#define ijk_isnzero_flt(x)			((x) < -flt_eps || (x) > +flt_eps)
#define ijk_isnzero_dbl(x)			((x) < -dbl_eps || (x) > +dbl_eps)
#define ijk_isnzero					ijk_tokencat(ijk_isnzero_,ijk_real)

// division-by-zero safety
///
#define ijk_divide_safe_int(n,d)	((d) != ijk_zero ? (n) / (d) : ijk_zero)
#define ijk_divide_safe_flt(n,d)	((d) != flt_zero ? (n) / (d) : flt_zero)
#define ijk_divide_safe_dbl(n,d)	((d) != dbl_zero ? (n) / (d) : dbl_zero)
#define ijk_divide_safe				ijk_tokencat(ijk_divide_safe_,ijk_real)


// reciprocal
///
#define ijk_recip_flt(x)			(flt_one / (x))
#define ijk_recip_dbl(x)			(dbl_one / (x))
#define ijk_recip					ijk_tokencat(ijk_recip_,ijk_real)

// reciprocal with division-by-zero safety
///
#define ijk_recip_safe_flt(x)		((x != flt_zero) ? flt_one / (x) : flt_zero)
#define ijk_recip_safe_dbl(x)		((x != dbl_zero) ? dbl_one / (x) : dbl_zero)
#define ijk_recip_safe				ijk_tokencat(ijk_recip_safe_,ijk_real)

// convert degrees to radians
///
#define ijk_deg2rad_flt(x)			((x) * flt_deg2rad)
#define ijk_deg2rad_dbl(x)			((x) * dbl_deg2rad)
#define ijk_deg2rad					ijk_tokencat(ijk_deg2rad_,ijk_real)

// convert radians to degrees
///
#define ijk_rad2deg_flt(x)			((x) * flt_rad2deg)
#define ijk_rad2deg_dbl(x)			((x) * dbl_rad2deg)
#define ijk_rad2deg					ijk_tokencat(ijk_rad2deg_,ijk_real)


//-----------------------------------------------------------------------------


#endif	// !_IJK_REAL_H_