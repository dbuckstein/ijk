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

	ijkTrigonometry.h
	Core fast trigonometry functions and utilities.
*/

#ifndef _IJK_TRIGONOMETRY_H_
#define _IJK_TRIGONOMETRY_H_


#include "ijkReal.h"


//-----------------------------------------------------------------------------

// ijkTrigGetTableSize_flt
//	Get the minimum required fast trigonometry table size in bytes. This will 
//	be different based on the sample type (float or double) and architecture 
//	(32-bit or 64-bit integer for index).
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if set data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkTrigSetTable_flt
//	Set data tables for fast trigonometry.
//		param table: pointer to pre-allocated table
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= SZ_sample * (
//						(720 degrees * 3 sets [params, sine, cosine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 indices * 2 sets[arcsine, arccosine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if set data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkTrigInit_flt
//	Initialize and set data tables for fast trigonometry.
//		param table_out: pointer to pre-allocated table to store data
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= SZ_sample * (
//						(720 degrees * 3 sets [params, sine, cosine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 indices * 2 sets[arcsine, arccosine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: ijk_success if initialized data
//		return FAILURE: ijk_fail_invalidparams if invalid parameters


// ijkTrigValidateDegree_flt
//	Validate a degree parameter to be passed to a trig function. Maps 
//	input to respective value in [-360, +360].
//		param x: input (as degree) to validate
//		return: x mapped to [-360, +360]


// ijkTrigValidateRadian_flt
//	Validate a parameter to be passed to a trig function in radians. Maps 
//	input to respective value in [-2pi, +2pi].
//		param x: input (as radian) to validate
//		return: x mapped to [-2pi, +2pi]


// ijkTrigValidateInverse_flt
//	Validate a parameter to be passed to an inverse trig function, namely 
//	arcsine and arccosine. Clamps input to [-1, +1].
//		param x: input to validate
//		return: x clamped to [-1, +1]


// ijkTrigValidateInverseRecip_flt
//	Validate a parameter to be passed to an inverse reciprocal trig function, 
//	namely arccosecant and arcsecant. Clamps input to (-inf, -1] U [+1, +inf).
//		param x: input to validate
//		return: x clamped to [-1, +1]


// ijkTrigSind_flt
//	Calculate sine with degree input.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]


// ijkTrigCosd_flt
//	Calculate cosine with degree input.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]


// ijkTrigTand_flt
//	Calculate tangent with degree input.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)


// ijkTrigCscd_flt
//	Calculate cosecant with degree input.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)


// ijkTrigSecd_flt
//	Calculate secant with degree input.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)


// ijkTrigCotd_flt
//	Calculate cotangent with degree input.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)


// ijkTrigAsind_flt
//	Calculate arcsine with degree output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-90, +90]


// ijkTrigAcosd_flt
//	Calculate arccosine with degree output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+180, 0]


// ijkTrigAtand_flt
//	Calculate arctangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-90, +90)


// ijkTrigAcscd_flt
//	Calculate arccosecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -90] U [+90, 0)


// ijkTrigAsecd_flt
//	Calculate arcsecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+90, +180] U [0, +90)


// ijkTrigAcotd_flt
//	Calculate arccotangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+180, 0)


// ijkTrigAtan2d_flt
//	Calculate arctangent with degree output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-90, +90)


// ijkTrigSinr_flt
//	Calculate sine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]


// ijkTrigCosr_flt
//	Calculate cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]


// ijkTrigTanr_flt
//	Calculate tangent with radian input.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)


// ijkTrigCscr_flt
//	Calculate cosecant with radian input.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)


// ijkTrigSecr_flt
//	Calculate secant with radian input.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)


// ijkTrigCotr_flt
//	Calculate cotangent with radian input.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)


// ijkTrigAsinr_flt
//	Calculate arcsine with radian output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-pi/2, +pi/2]


// ijkTrigAcosr_flt
//	Calculate arccosine with radian output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+pi, 0]


// ijkTrigAtanr_flt
//	Calculate arctangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-pi/2, +pi/2)


// ijkTrigAcscr_flt
//	Calculate arccosecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -pi/2] U [+pi/2, 0)


// ijkTrigAsecr_flt
//	Calculate arcsecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+pi/2, +pi] U [0, +pi/2)


// ijkTrigAcotr_flt
//	Calculate arccotangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+pi, 0)


// ijkTrigAtan2r_flt
//	Calculate arctangent with radian output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-pi/2, +pi/2)


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkTrigonometry.inl"


#endif	// !_IJK_TRIGONOMETRY_H_