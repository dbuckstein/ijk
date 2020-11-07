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


#include "ijkInterpolation.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkTrigGetTableSize_flt
//	Get the minimum required fast trigonometry table size in bytes. This will 
//	be different based on the sample type (float or double) and architecture 
//	(32-bit or 64-bit integer for index).
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//			note: ideal results with 4 as input
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigGetTableSize_flt(size const subdivisionsPerDegree);

// ijkTrigSetTable_flt
//	Set data tables for fast trigonometry.
//		param table: pointer to pre-allocated table
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szflt * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * (
//						(1024 indices * 1 set [arcsine])
//						+ 2 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigSetTable_flt(flt const table[], size const tableSize_bytes, size const subdivisionsPerDegree);

// ijkTrigInit_flt
//	Initialize and set data tables for fast trigonometry.
//		param table_out: pointer to pre-allocated table to store data
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szflt * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * (
//						(1024 indices * 1 set [arcsine])
//						+ 2 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigInit_flt(flt table_out[], size const tableSize_bytes, size const subdivisionsPerDegree);

// ijkTrigDeg2Rad_flt
//	Convert degree to radian.
//		param x: degree input
//		return: x as radian
flt ijkTrigDeg2Rad_flt(flt const x);

// ijkTrigRad2Deg_flt
//	Convert radian to degree.
//		param x: radian input
//		return: x as degree
flt ijkTrigRad2Deg_flt(flt const x);

// ijkTrigValidateDegree_flt
//	Validate a degree parameter to be passed to a trig function. Maps 
//	input to respective value in [-360, +360].
//		param x: input (as degree) to validate
//		return: x mapped to [-360, +360]
flt ijkTrigValidateDegree_flt(flt x);

// ijkTrigValidateRadian_flt
//	Validate a parameter to be passed to a trig function in radians. Maps 
//	input to respective value in [-2pi, +2pi].
//		param x: input (as radian) to validate
//		return: x mapped to [-2pi, +2pi]
flt ijkTrigValidateRadian_flt(flt x);

// ijkTrigValidateInverse_flt
//	Validate a parameter to be passed to an inverse trig function, namely 
//	arcsine and arccosine. Clamps input to [-1, +1].
//		param x: input to validate
//		return: x clamped to [-1, +1]
flt ijkTrigValidateInverse_flt(flt x);

// ijkTrigValidateInverseRecip_flt
//	Validate a parameter to be passed to an inverse reciprocal trig function, 
//	namely arccosecant and arcsecant. Clamps input to (-inf, -1] U [+1, +inf).
//		param x: input to validate
//		return: x clamped to [-1, +1]
flt ijkTrigValidateInverseRecip_flt(flt x);

// ijkTrigSinCos_deg_flt
//	Calculate sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigTanSinCos_deg_flt
//	Calculate tangent, sine and consine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigCotSinCos_deg_flt
//	Calculate cotantent, sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigSin_deg_flt
//	Calculate sine with degree input.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSin_deg_flt(flt const x);

// ijkTrigCos_deg_flt
//	Calculate cosine with degree input.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCos_deg_flt(flt const x);

// ijkTrigTan_deg_flt
//	Calculate tangent with degree input.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTan_deg_flt(flt const x);

// ijkTrigCsc_deg_flt
//	Calculate cosecant with degree input.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCsc_deg_flt(flt const x);

// ijkTrigSec_deg_flt
//	Calculate secant with degree input.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSec_deg_flt(flt const x);

// ijkTrigCot_deg_flt
//	Calculate cotangent with degree input.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCot_deg_flt(flt const x);

// ijkTrigAsin_deg_flt
//	Calculate arcsine with degree output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-90, +90]
flt ijkTrigAsin_deg_flt(flt const x);

// ijkTrigAcos_deg_flt
//	Calculate arccosine with degree output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+180, 0]
flt ijkTrigAcos_deg_flt(flt const x);

// ijkTrigAtan_deg_flt
//	Calculate arctangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-90, +90)
flt ijkTrigAtan_deg_flt(flt const x);

// ijkTrigAcsc_deg_flt
//	Calculate arccosecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -90] U [+90, 0)
flt ijkTrigAcsc_deg_flt(flt const x);

// ijkTrigAsec_deg_flt
//	Calculate arcsecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+90, +180] U [0, +90)
flt ijkTrigAsec_deg_flt(flt const x);

// ijkTrigAcot_deg_flt
//	Calculate arccotangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+180, 0)
flt ijkTrigAcot_deg_flt(flt const x);

// ijkTrigAtan2_deg_flt
//	Calculate arctangent with degree output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-90, +90)
flt ijkTrigAtan2_deg_flt(flt const y_sin, flt const x_cos);

// ijkTrigSinCos_rad_flt
//	Calculate sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigTanSinCos_rad_flt
//	Calculate tangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigCotSinCos_rad_flt
//	Calculate cotangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigSin_rad_flt
//	Calculate sine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSin_rad_flt(flt const x);

// ijkTrigCos_rad_flt
//	Calculate cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCos_rad_flt(flt const x);

// ijkTrigTan_rad_flt
//	Calculate tangent with radian input.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTan_rad_flt(flt const x);

// ijkTrigCsc_rad_flt
//	Calculate cosecant with radian input.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCsc_rad_flt(flt const x);

// ijkTrigSec_rad_flt
//	Calculate secant with radian input.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSec_rad_flt(flt const x);

// ijkTrigCot_rad_flt
//	Calculate cotangent with radian input.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCot_rad_flt(flt const x);

// ijkTrigAsin_rad_flt
//	Calculate arcsine with radian output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-pi/2, +pi/2]
flt ijkTrigAsin_rad_flt(flt const x);

// ijkTrigAcos_rad_flt
//	Calculate arccosine with radian output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+pi, 0]
flt ijkTrigAcos_rad_flt(flt const x);

// ijkTrigAtan_rad_flt
//	Calculate arctangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-pi/2, +pi/2)
flt ijkTrigAtan_rad_flt(flt const x);

// ijkTrigAcsc_rad_flt
//	Calculate arccosecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -pi/2] U [+pi/2, 0)
flt ijkTrigAcsc_rad_flt(flt const x);

// ijkTrigAsec_rad_flt
//	Calculate arcsecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+pi/2, +pi] U [0, +pi/2)
flt ijkTrigAsec_rad_flt(flt const x);

// ijkTrigAcot_rad_flt
//	Calculate arccotangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+pi, 0)
flt ijkTrigAcot_rad_flt(flt const x);

// ijkTrigAtan2_rad_flt
//	Calculate arctangent with radian output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-pi/2, +pi/2)
flt ijkTrigAtan2_rad_flt(flt const y_sin, flt const x_cos);

// ijkTrigSinCosTaylor_rad_flt
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigTanSinCosTaylor_rad_flt
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigCotSinCosTaylor_rad_flt
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigSinTaylor_rad_flt
//	Calculate sine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSinTaylor_rad_flt(flt const x);

// ijkTrigCosTaylor_rad_flt
//	Calculate cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosTaylor_rad_flt(flt const x);

// ijkTrigTanTaylor_rad_flt
//	Calculate tangent with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanTaylor_rad_flt(flt const x);

// ijkTrigCscTaylor_rad_flt
//	Calculate cosecant with radian input using a Taylor series.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscTaylor_rad_flt(flt const x);

// ijkTrigSecTaylor_rad_flt
//	Calculate secant with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecTaylor_rad_flt(flt const x);

// ijkTrigCotTaylor_rad_flt
//	Calculate cotangent with radian input using a Taylor series.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotTaylor_rad_flt(flt const x);

// ijkTrigSinCosTaylor_deg_flt
//	Calculate sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigTanSinCosTaylor_deg_flt
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigCotSinCosTaylor_deg_flt
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out);

// ijkTrigSinTaylor_deg_flt
//	Calculate sine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSinTaylor_deg_flt(flt const x);

// ijkTrigCosTaylor_deg_flt
//	Calculate cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosTaylor_deg_flt(flt const x);

// ijkTrigTanTaylor_deg_flt
//	Calculate tangent with degree input using a Taylor series.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanTaylor_deg_flt(flt const x);

// ijkTrigCscTaylor_deg_flt
//	Calculate cosecant with degree input using a Taylor series.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscTaylor_deg_flt(flt const x);

// ijkTrigSecTaylor_deg_flt
//	Calculate secant with degree input using a Taylor series.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecTaylor_deg_flt(flt const x);

// ijkTrigCotTaylor_deg_flt
//	Calculate cotangent with degree input using a Taylor series.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotTaylor_deg_flt(flt const x);

// ijkTrigPointToEdgeRatio_flt
//	Calculate the size ratio of a real to discrete circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of real to discrete circle size
flt ijkTrigPointToEdgeRatio_flt(flt const azimuth, size const numSlices);

// ijkTrigEdgeToPointRatio_flt
//	Calculate the size ratio of a discrete to real circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of discrete to real circle size
flt ijkTrigEdgeToPointRatio_flt(flt const azimuth, size const numSlices);

// ijkTrigPointToFaceRatio_flt
//	Calculate the size ratio of a real to discrete sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of real to discrete sphere size
flt ijkTrigPointToFaceRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks);

// ijkTrigFaceToPointRatio_flt
//	Calculate the size ratio of a discrete to real sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of discrete to real sphere size
flt ijkTrigFaceToPointRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks);

// ijkTrigSmoothstepInv_flt
//	Inverse smoothstep.
//		param v: interpolated value; inputs within [0,1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between 0 and 1
flt ijkTrigSmoothstepInv_flt(flt const v);


//-----------------------------------------------------------------------------

// ijkTrigGetTableSize_dbl
//	Get the minimum required fast trigonometry table size in bytes. This will 
//	be different based on the sample type (float or double) and architecture 
//	(32-bit or 64-bit integer for index).
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//			note: ideal results with 4 as input
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigGetTableSize_dbl(size const subdivisionsPerDegree);

// ijkTrigSetTable_dbl
//	Set data tables for fast trigonometry.
//		param table: pointer to pre-allocated table
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szdbl * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * (
//						(2048 indices * 1 set [arcsine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigSetTable_dbl(dbl const table[], size const tableSize_bytes, size const subdivisionsPerDegree);

// ijkTrigInit_dbl
//	Initialize and set data tables for fast trigonometry.
//		param table_out: pointer to pre-allocated table to store data
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szdbl * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * (
//						(2048 indices * 1 set [arcsine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigInit_dbl(dbl table_out[], size const tableSize_bytes, size const subdivisionsPerDegree);

// ijkTrigDeg2Rad_dbl
//	Convert degree to radian.
//		param x: degree input
//		return: x as radian
dbl ijkTrigDeg2Rad_dbl(dbl const x);

// ijkTrigRad2Deg_dbl
//	Convert radian to degree.
//		param x: radian input
//		return: x as degree
dbl ijkTrigRad2Deg_dbl(dbl const x);

// ijkTrigValidateDegree_dbl
//	Validate a degree parameter to be passed to a trig function. Maps 
//	input to respective value in [-360, +360].
//		param x: input (as degree) to validate
//		return: x mapped to [-360, +360]
dbl ijkTrigValidateDegree_dbl(dbl x);

// ijkTrigValidateRadian_dbl
//	Validate a parameter to be passed to a trig function in radians. Maps 
//	input to respective value in [-2pi, +2pi].
//		param x: input (as radian) to validate
//		return: x mapped to [-2pi, +2pi]
dbl ijkTrigValidateRadian_dbl(dbl x);

// ijkTrigValidateInverse_dbl
//	Validate a parameter to be passed to an inverse trig function, namely 
//	arcsine and arccosine. Clamps input to [-1, +1].
//		param x: input to validate
//		return: x clamped to [-1, +1]
dbl ijkTrigValidateInverse_dbl(dbl x);

// ijkTrigValidateInverseRecip_dbl
//	Validate a parameter to be passed to an inverse reciprocal trig function, 
//	namely arccosecant and arcsecant. Clamps input to (-inf, -1] U [+1, +inf).
//		param x: input to validate
//		return: x clamped to [-1, +1]
dbl ijkTrigValidateInverseRecip_dbl(dbl x);

// ijkTrigSinCos_deg_dbl
//	Calculate sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
dbl ijkTrigSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigTanSinCos_deg_dbl
//	Calculate tangent, sine and consine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigCotSinCos_deg_dbl
//	Calculate cotantent, sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigSin_deg_dbl
//	Calculate sine with degree input.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
dbl ijkTrigSin_deg_dbl(dbl const x);

// ijkTrigCos_deg_dbl
//	Calculate cosine with degree input.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
dbl ijkTrigCos_deg_dbl(dbl const x);

// ijkTrigTan_deg_dbl
//	Calculate tangent with degree input.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTan_deg_dbl(dbl const x);

// ijkTrigCsc_deg_dbl
//	Calculate cosecant with degree input.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigCsc_deg_dbl(dbl const x);

// ijkTrigSec_deg_dbl
//	Calculate secant with degree input.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigSec_deg_dbl(dbl const x);

// ijkTrigCot_deg_dbl
//	Calculate cotangent with degree input.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCot_deg_dbl(dbl const x);

// ijkTrigAsin_deg_dbl
//	Calculate arcsine with degree output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-90, +90]
dbl ijkTrigAsin_deg_dbl(dbl const x);

// ijkTrigAcos_deg_dbl
//	Calculate arccosine with degree output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+180, 0]
dbl ijkTrigAcos_deg_dbl(dbl const x);

// ijkTrigAtan_deg_dbl
//	Calculate arctangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-90, +90)
dbl ijkTrigAtan_deg_dbl(dbl const x);

// ijkTrigAcsc_deg_dbl
//	Calculate arccosecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -90] U [+90, 0)
dbl ijkTrigAcsc_deg_dbl(dbl const x);

// ijkTrigAsec_deg_dbl
//	Calculate arcsecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+90, +180] U [0, +90)
dbl ijkTrigAsec_deg_dbl(dbl const x);

// ijkTrigAcot_deg_dbl
//	Calculate arccotangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+180, 0)
dbl ijkTrigAcot_deg_dbl(dbl const x);

// ijkTrigAtan2_deg_dbl
//	Calculate arctangent with degree output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-90, +90)
dbl ijkTrigAtan2_deg_dbl(dbl const y_sin, dbl const x_cos);

// ijkTrigSinCos_rad_dbl
//	Calculate sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
dbl ijkTrigSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigTanSinCos_rad_dbl
//	Calculate tangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigCotSinCos_rad_dbl
//	Calculate cotangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigSin_rad_dbl
//	Calculate sine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
dbl ijkTrigSin_rad_dbl(dbl const x);

// ijkTrigCos_rad_dbl
//	Calculate cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
dbl ijkTrigCos_rad_dbl(dbl const x);

// ijkTrigTan_rad_dbl
//	Calculate tangent with radian input.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTan_rad_dbl(dbl const x);

// ijkTrigCsc_rad_dbl
//	Calculate cosecant with radian input.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigCsc_rad_dbl(dbl const x);

// ijkTrigSec_rad_dbl
//	Calculate secant with radian input.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigSec_rad_dbl(dbl const x);

// ijkTrigCot_rad_dbl
//	Calculate cotangent with radian input.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCot_rad_dbl(dbl const x);

// ijkTrigAsin_rad_dbl
//	Calculate arcsine with radian output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-pi/2, +pi/2]
dbl ijkTrigAsin_rad_dbl(dbl const x);

// ijkTrigAcos_rad_dbl
//	Calculate arccosine with radian output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+pi, 0]
dbl ijkTrigAcos_rad_dbl(dbl const x);

// ijkTrigAtan_rad_dbl
//	Calculate arctangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-pi/2, +pi/2)
dbl ijkTrigAtan_rad_dbl(dbl const x);

// ijkTrigAcsc_rad_dbl
//	Calculate arccosecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -pi/2] U [+pi/2, 0)
dbl ijkTrigAcsc_rad_dbl(dbl const x);

// ijkTrigAsec_rad_dbl
//	Calculate arcsecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+pi/2, +pi] U [0, +pi/2)
dbl ijkTrigAsec_rad_dbl(dbl const x);

// ijkTrigAcot_rad_dbl
//	Calculate arccotangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+pi, 0)
dbl ijkTrigAcot_rad_dbl(dbl const x);

// ijkTrigAtan2_rad_dbl
//	Calculate arctangent with radian output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-pi/2, +pi/2)
dbl ijkTrigAtan2_rad_dbl(dbl const y_sin, dbl const x_cos);

// ijkTrigSinCosTaylor_rad_dbl
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
dbl ijkTrigSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigTanSinCosTaylor_rad_dbl
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigCotSinCosTaylor_rad_dbl
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigSinTaylor_rad_dbl
//	Calculate sine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
dbl ijkTrigSinTaylor_rad_dbl(dbl const x);

// ijkTrigCosTaylor_rad_dbl
//	Calculate cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
dbl ijkTrigCosTaylor_rad_dbl(dbl const x);

// ijkTrigTanTaylor_rad_dbl
//	Calculate tangent with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanTaylor_rad_dbl(dbl const x);

// ijkTrigCscTaylor_rad_dbl
//	Calculate cosecant with radian input using a Taylor series.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigCscTaylor_rad_dbl(dbl const x);

// ijkTrigSecTaylor_rad_dbl
//	Calculate secant with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigSecTaylor_rad_dbl(dbl const x);

// ijkTrigCotTaylor_rad_dbl
//	Calculate cotangent with radian input using a Taylor series.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotTaylor_rad_dbl(dbl const x);

// ijkTrigSinCosTaylor_deg_dbl
//	Calculate sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
dbl ijkTrigSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigTanSinCosTaylor_deg_dbl
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigCotSinCosTaylor_deg_dbl
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out);

// ijkTrigSinTaylor_deg_dbl
//	Calculate sine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
dbl ijkTrigSinTaylor_deg_dbl(dbl const x);

// ijkTrigCosTaylor_deg_dbl
//	Calculate cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
dbl ijkTrigCosTaylor_deg_dbl(dbl const x);

// ijkTrigTanTaylor_deg_dbl
//	Calculate tangent with degree input using a Taylor series.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
dbl ijkTrigTanTaylor_deg_dbl(dbl const x);

// ijkTrigCscTaylor_deg_dbl
//	Calculate cosecant with degree input using a Taylor series.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigCscTaylor_deg_dbl(dbl const x);

// ijkTrigSecTaylor_deg_dbl
//	Calculate secant with degree input using a Taylor series.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
dbl ijkTrigSecTaylor_deg_dbl(dbl const x);

// ijkTrigCotTaylor_deg_dbl
//	Calculate cotangent with degree input using a Taylor series.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
dbl ijkTrigCotTaylor_deg_dbl(dbl const x);

// ijkTrigPointToEdgeRatio_dbl
//	Calculate the size ratio of a real to discrete circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of real to discrete circle size
dbl ijkTrigPointToEdgeRatio_dbl(dbl const azimuth, size const numSlices);

// ijkTrigEdgeToPointRatio_dbl
//	Calculate the size ratio of a discrete to real circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of discrete to real circle size
dbl ijkTrigEdgeToPointRatio_dbl(dbl const azimuth, size const numSlices);

// ijkTrigPointToFaceRatio_dbl
//	Calculate the size ratio of a real to discrete sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of real to discrete sphere size
dbl ijkTrigPointToFaceRatio_dbl(dbl const azimuth, dbl const elevation, size const numSlices, size const numStacks);

// ijkTrigFaceToPointRatio_dbl
//	Calculate the size ratio of a discrete to real sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of discrete to real sphere size
dbl ijkTrigFaceToPointRatio_dbl(dbl const azimuth, dbl const elevation, size const numSlices, size const numStacks);

// ijkTrigSmoothstepInv_dbl
//	Inverse smoothstep.
//		param v: interpolated value; inputs within [0,1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between 0 and 1
dbl ijkTrigSmoothstepInv_dbl(dbl const v);


//-----------------------------------------------------------------------------

// ijkTrigGetTableSize
//	Get the minimum required fast trigonometry table size in bytes. This will 
//	be different based on the sample type (float or double) and architecture 
//	(32-bit or 64-bit integer for index).
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//			note: ideal results with 4 as input
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
//size ijkTrigGetTableSize(size const subdivisionsPerDegree);
#define	ijkTrigGetTableSize				ijk_declrealf(ijkTrigGetTableSize)

// ijkTrigSetTable
//	Set data tables for fast trigonometry.
//		param table: pointer to pre-allocated table
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szreal * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * szrealbr * (
//						(1024 indices * 1 set [arcsine])
//						+ 2 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
//size ijkTrigSetTable(real const table[], size const tableSize_bytes, size const subdivisionsPerDegree);
#define	ijkTrigSetTable					ijk_declrealf(ijkTrigSetTable)

// ijkTrigInit
//	Initialize and set data tables for fast trigonometry.
//		param table_out: pointer to pre-allocated table to store data
//			valid: non-null
//		param tableSize_bytes: size of provided table in bytes
//			valid: at least the minimum required size
//			note: minimum required size (in bytes) is: 
//				SZ	= szreal * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ szindex * szrealbr * (
//						(1024 indices * 1 set [arcsine])
//						+ 2 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
//size ijkTrigInit(real table_out[], size const tableSize_bytes, size const subdivisionsPerDegree);
#define	ijkTrigInit						ijk_declrealf(ijkTrigInit)

// ijkTrigDeg2Rad
//	Convert degree to radian.
//		param x: degree input
//		return: x as radian
//real ijkTrigDeg2Rad(real const x);
#define	ijkTrigDeg2Rad					ijk_declrealf(ijkTrigDeg2Rad)

// ijkTrigRad2Deg
//	Convert radian to degree.
//		param x: radian input
//		return: x as degree
//real ijkTrigRad2Deg(real const x);
#define	ijkTrigRad2Deg					ijk_declrealf(ijkTrigRad2Deg)

// ijkTrigValidateDegree
//	Validate a degree parameter to be passed to a trig function. Maps 
//	input to respective value in [-360, +360].
//		param x: input (as degree) to validate
//		return: x mapped to [-360, +360]
//real ijkTrigValidateDegree(real x);
#define	ijkTrigValidateDegree			ijk_declrealf(ijkTrigValidateDegree)

// ijkTrigValidateRadian
//	Validate a parameter to be passed to a trig function in radians. Maps 
//	input to respective value in [-2pi, +2pi].
//		param x: input (as radian) to validate
//		return: x mapped to [-2pi, +2pi]
//real ijkTrigValidateRadian(real x);
#define	ijkTrigValidateRadian			ijk_declrealf(ijkTrigValidateRadian)

// ijkTrigValidateInverse
//	Validate a parameter to be passed to an inverse trig function, namely 
//	arcsine and arccosine. Clamps input to [-1, +1].
//		param x: input to validate
//		return: x clamped to [-1, +1]
//real ijkTrigValidateInverse(real x);
#define	ijkTrigValidateInverse			ijk_declrealf(ijkTrigValidateInverse)

// ijkTrigValidateInverseRecip
//	Validate a parameter to be passed to an inverse reciprocal trig function, 
//	namely arccosecant and arcsecant. Clamps input to (-inf, -1] U [+1, +inf).
//		param x: input to validate
//		return: x clamped to [-1, +1]
//real ijkTrigValidateInverseRecip(real x);
#define	ijkTrigValidateInverseRecip		ijk_declrealf(ijkTrigValidateInverseRecip)

// ijkTrigSinCos_deg
//	Calculate sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
//real ijkTrigSinCos_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigSinCos_deg				ijk_declrealf(ijkTrigSinCos_deg)

// ijkTrigTanSinCos_deg
//	Calculate tangent, sine and consine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanSinCos_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigTanSinCos_deg			ijk_declrealf(ijkTrigTanSinCos_deg)

// ijkTrigCotSinCos_deg
//	Calculate cotantent, sine and cosine with degree input.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotSinCos_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigCotSinCos_deg			ijk_declrealf(ijkTrigCotSinCos_deg)

// ijkTrigSin_deg
//	Calculate sine with degree input.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
//real ijkTrigSin_deg(real const x);
#define	ijkTrigSin_deg					ijk_declrealf(ijkTrigSin_deg)

// ijkTrigCos_deg
//	Calculate cosine with degree input.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
//real ijkTrigCos_deg(real const x);
#define	ijkTrigCos_deg					ijk_declrealf(ijkTrigCos_deg)

// ijkTrigTan_deg
//	Calculate tangent with degree input.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTan_deg(real const x);
#define	ijkTrigTan_deg					ijk_declrealf(ijkTrigTan_deg)

// ijkTrigCsc_deg
//	Calculate cosecant with degree input.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigCsc_deg(real const x);
#define	ijkTrigCsc_deg					ijk_declrealf(ijkTrigCsc_deg)

// ijkTrigSec_deg
//	Calculate secant with degree input.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigSec_deg(real const x);
#define	ijkTrigSec_deg					ijk_declrealf(ijkTrigSec_deg)

// ijkTrigCot_deg
//	Calculate cotangent with degree input.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCot_deg(real const x);
#define	ijkTrigCot_deg					ijk_declrealf(ijkTrigCot_deg)

// ijkTrigAsin_deg
//	Calculate arcsine with degree output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-90, +90]
//real ijkTrigAsin_deg(real const x);
#define	ijkTrigAsin_deg					ijk_declrealf(ijkTrigAsin_deg)

// ijkTrigAcos_deg
//	Calculate arccosine with degree output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+180, 0]
//real ijkTrigAcos_deg(real const x);
#define	ijkTrigAcos_deg					ijk_declrealf(ijkTrigAcos_deg)

// ijkTrigAtan_deg
//	Calculate arctangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-90, +90)
//real ijkTrigAtan_deg(real const x);
#define	ijkTrigAtan_deg					ijk_declrealf(ijkTrigAtan_deg)

// ijkTrigAcsc_deg
//	Calculate arccosecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -90] U [+90, 0)
//real ijkTrigAcsc_deg(real const x);
#define	ijkTrigAcsc_deg					ijk_declrealf(ijkTrigAcsc_deg)

// ijkTrigAsec_deg
//	Calculate arcsecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+90, +180] U [0, +90)
//real ijkTrigAsec_deg(real const x);
#define	ijkTrigAsec_deg					ijk_declrealf(ijkTrigAsec_deg)

// ijkTrigAcot_deg
//	Calculate arccotangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+180, 0)
//real ijkTrigAcot_deg(real const x);
#define	ijkTrigAcot_deg					ijk_declrealf(ijkTrigAcot_deg)

// ijkTrigAtan2_deg
//	Calculate arctangent with degree output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-90, +90)
//real ijkTrigAtan2_deg(real const y_sin, real const x_cos);
#define	ijkTrigAtan2_deg				ijk_declrealf(ijkTrigAtan2_deg)

// ijkTrigSinCos_rad
//	Calculate sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
//real ijkTrigSinCos_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigSinCos_rad				ijk_declrealf(ijkTrigSinCos_rad)

// ijkTrigTanSinCos_rad
//	Calculate tangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanSinCos_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigTanSinCos_rad			ijk_declrealf(ijkTrigTanSinCos_rad)

// ijkTrigCotSinCos_rad
//	Calculate cotangent, sine and cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotSinCos_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigCotSinCos_rad			ijk_declrealf(ijkTrigCotSinCos_rad)

// ijkTrigSin_rad
//	Calculate sine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
//real ijkTrigSin_rad(real const x);
#define	ijkTrigSin_rad					ijk_declrealf(ijkTrigSin_rad)

// ijkTrigCos_rad
//	Calculate cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
//real ijkTrigCos_rad(real const x);
#define	ijkTrigCos_rad					ijk_declrealf(ijkTrigCos_rad)

// ijkTrigTan_rad
//	Calculate tangent with radian input.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTan_rad(real const x);
#define	ijkTrigTan_rad					ijk_declrealf(ijkTrigTan_rad)

// ijkTrigCsc_rad
//	Calculate cosecant with radian input.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigCsc_rad(real const x);
#define	ijkTrigCsc_rad					ijk_declrealf(ijkTrigCsc_rad)

// ijkTrigSec_rad
//	Calculate secant with radian input.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigSec_rad(real const x);
#define	ijkTrigSec_rad					ijk_declrealf(ijkTrigSec_rad)

// ijkTrigCot_rad
//	Calculate cotangent with radian input.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCot_rad(real const x);
#define	ijkTrigCot_rad					ijk_declrealf(ijkTrigCot_rad)

// ijkTrigAsin_rad
//	Calculate arcsine with radian output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-pi/2, +pi/2]
//real ijkTrigAsin_rad(real const x);
#define	ijkTrigAsin_rad					ijk_declrealf(ijkTrigAsin_rad)

// ijkTrigAcos_rad
//	Calculate arccosine with radian output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+pi, 0]
//real ijkTrigAcos_rad(real const x);
#define	ijkTrigAcos_rad					ijk_declrealf(ijkTrigAcos_rad)

// ijkTrigAtan_rad
//	Calculate arctangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-pi/2, +pi/2)
//real ijkTrigAtan_rad(real const x);
#define	ijkTrigAtan_rad					ijk_declrealf(ijkTrigAtan_rad)

// ijkTrigAcsc_rad
//	Calculate arccosecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -pi/2] U [+pi/2, 0)
//real ijkTrigAcsc_rad(real const x);
#define	ijkTrigAcsc_rad					ijk_declrealf(ijkTrigAcsc_rad)

// ijkTrigAsec_rad
//	Calculate arcsecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+pi/2, +pi] U [0, +pi/2)
//real ijkTrigAsec_rad(real const x);
#define	ijkTrigAsec_rad					ijk_declrealf(ijkTrigAsec_rad)

// ijkTrigAcot_rad
//	Calculate arccotangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+pi, 0)
//real ijkTrigAcot_rad(real const x);
#define	ijkTrigAcot_rad					ijk_declrealf(ijkTrigAcot_rad)

// ijkTrigAtan2_rad
//	Calculate arctangent with radian output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-pi/2, +pi/2)
//real ijkTrigAtan2_rad(real const y_sin, real const x_cos);
#define	ijkTrigAtan2_rad				ijk_declrealf(ijkTrigAtan2_rad)

// ijkTrigSinCosTaylor_rad
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
//real ijkTrigSinCosTaylor_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigSinCosTaylor_rad			ijk_declrealf(ijkTrigSinCosTaylor_rad)

// ijkTrigTanSinCosTaylor_rad
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanSinCosTaylor_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigTanSinCosTaylor_rad		ijk_declrealf(ijkTrigTanSinCosTaylor_rad)

// ijkTrigCotSinCosTaylor_rad
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotSinCosTaylor_rad(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigCotSinCosTaylor_rad		ijk_declrealf(ijkTrigCotSinCosTaylor_rad)

// ijkTrigSinTaylor_rad
//	Calculate sine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
//real ijkTrigSinTaylor_rad(real const x);
#define	ijkTrigSinTaylor_rad			ijk_declrealf(ijkTrigSinTaylor_rad)

// ijkTrigCosTaylor_rad
//	Calculate cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
//real ijkTrigCosTaylor_rad(real const x);
#define	ijkTrigCosTaylor_rad			ijk_declrealf(ijkTrigCosTaylor_rad)

// ijkTrigTanTaylor_rad
//	Calculate tangent with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanTaylor_rad(real const x);
#define	ijkTrigTanTaylor_rad			ijk_declrealf(ijkTrigTanTaylor_rad)

// ijkTrigCscTaylor_rad
//	Calculate cosecant with radian input using a Taylor series.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigCscTaylor_rad(real const x);
#define	ijkTrigCscTaylor_rad			ijk_declrealf(ijkTrigCscTaylor_rad)

// ijkTrigSecTaylor_rad
//	Calculate secant with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigSecTaylor_rad(real const x);
#define	ijkTrigSecTaylor_rad			ijk_declrealf(ijkTrigSecTaylor_rad)

// ijkTrigCotTaylor_rad
//	Calculate cotangent with radian input using a Taylor series.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotTaylor_rad(real const x);
#define	ijkTrigCotTaylor_rad			ijk_declrealf(ijkTrigCotTaylor_rad)

// ijkTrigSinCosTaylor_deg
//	Calculate sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
//real ijkTrigSinCosTaylor_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigSinCosTaylor_deg			ijk_declrealf(ijkTrigSinCosTaylor_deg)

// ijkTrigTanSinCosTaylor_deg
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanSinCosTaylor_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigTanSinCosTaylor_deg		ijk_declrealf(ijkTrigTanSinCosTaylor_deg)

// ijkTrigCotSinCosTaylor_deg
//	Calculate tangent, sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotSinCosTaylor_deg(real const x, real* const sinx_out, real* const cosx_out);
#define	ijkTrigCotSinCosTaylor_deg		ijk_declrealf(ijkTrigCotSinCosTaylor_deg)

// ijkTrigSinTaylor_deg
//	Calculate sine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
//real ijkTrigSinTaylor_deg(real const x);
#define	ijkTrigSinTaylor_deg			ijk_declrealf(ijkTrigSinTaylor_deg)

// ijkTrigCosTaylor_deg
//	Calculate cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
//real ijkTrigCosTaylor_deg(real const x);
#define	ijkTrigCosTaylor_deg			ijk_declrealf(ijkTrigCosTaylor_deg)

// ijkTrigTanTaylor_deg
//	Calculate tangent with degree input using a Taylor series.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
//real ijkTrigTanTaylor_deg(real const x);
#define	ijkTrigTanTaylor_deg			ijk_declrealf(ijkTrigTanTaylor_deg)

// ijkTrigCscTaylor_deg
//	Calculate cosecant with degree input using a Taylor series.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigCscTaylor_deg(real const x);
#define	ijkTrigCscTaylor_deg			ijk_declrealf(ijkTrigCscTaylor_deg)

// ijkTrigSecTaylor_deg
//	Calculate secant with degree input using a Taylor series.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
//real ijkTrigSecTaylor_deg(real const x);
#define	ijkTrigSecTaylor_deg			ijk_declrealf(ijkTrigSecTaylor_deg)

// ijkTrigCotTaylor_deg
//	Calculate cotangent with degree input using a Taylor series.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
//real ijkTrigCotTaylor_deg(real const x);
#define	ijkTrigCotTaylor_deg			ijk_declrealf(ijkTrigCotTaylor_deg)

// ijkTrigPointToEdgeRatio
//	Calculate the size ratio of a real to discrete circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of real to discrete circle size
//real ijkTrigPointToEdgeRatio(real const azimuth, size const numSlices);
#define	ijkTrigPointToEdgeRatio			ijk_declrealf(ijkTrigPointToEdgeRatio)

// ijkTrigEdgeToPointRatio
//	Calculate the size ratio of a discrete to real circle given edge size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a circle 
//	in graphics is not continuous, edge centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of circle in degrees, in [0, +360]
//		param numSlices: number of slices in discrete circle (azimuth divs)
//		return: ratio of discrete to real circle size
//real ijkTrigEdgeToPointRatio(real const azimuth, size const numSlices);
#define	ijkTrigEdgeToPointRatio			ijk_declrealf(ijkTrigEdgeToPointRatio)

// ijkTrigPointToFaceRatio
//	Calculate the size ratio of a real to discrete sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of real to discrete sphere size
//real ijkTrigPointToFaceRatio(real const azimuth, real const elevation, size const numSlices, size const numStacks);
#define	ijkTrigPointToFaceRatio			ijk_declrealf(ijkTrigPointToFaceRatio)

// ijkTrigFaceToPointRatio
//	Calculate the size ratio of a discrete to real sphere given face size. The 
//	error ratio occurring from discrete geometry sampling (e.g. since a sphere 
//	in graphics is not continuous, face centers are closer to the center than 
//	the vertices) determines the uniform scale required to expand or contract 
//	geometry to match true continuous radii (e.g. volume lighting).
//		param azimuth: arc coverage of sphere in degrees, in [0, +360]
//		param elevation: layer coverage of circle in degrees, in [0, +180]
//		param numSlices: number of slices in discrete sphere (azimuth divs)
//		param numStacks: number of stacks in discrete sphere (elevation divs)
//		return: ratio of discrete to real sphere size
//real ijkTrigFaceToPointRatio(real const azimuth, real const elevation, size const numSlices, size const numStacks);
#define	ijkTrigFaceToPointRatio			ijk_declrealf(ijkTrigFaceToPointRatio)

// ijkTrigSmoothstepInv
//	Inverse smoothstep.
//		param v: interpolated value; inputs within [0,1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between 0 and 1
//real ijkTrigSmoothstepInv(real const v);
#define	ijkTrigSmoothstepInv			ijk_declrealf(ijkTrigSmoothstepInv)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkTrigonometry.inl"


#endif	// !_IJK_TRIGONOMETRY_H_