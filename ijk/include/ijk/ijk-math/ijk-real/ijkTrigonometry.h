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
//				SZ	= SZ_sample * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 indices * 2 sets[arcsine, arccosine])
//						+ 4 padding)
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
//				SZ	= SZ_sample * (
//						(720 degrees * 2 sets [params, sine]
//						+ 90 degrees * 1 set [cosine])
//						* (samples per degree) + 4 padding)
//					+ SZ_index * (
//						(720 indices * 2 sets[arcsine, arccosine])
//						+ 4 padding)
//		param subdivisionsPerDegree: number of samples per degree
//			valid: non-zero
//			note: each degree will be subsampled this number of times
//		return SUCCESS: size of data set
//		return FAILURE: zero if invalid parameters
size ijkTrigInit_flt(flt table_out[], size const tableSize_bytes, size const subdivisionsPerDegree);

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

// ijkTrigSind_flt
//	Calculate sine with degree input.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSind_flt(flt const x);

// ijkTrigCosd_flt
//	Calculate cosine with degree input.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosd_flt(flt const x);

// ijkTrigTand_flt
//	Calculate tangent with degree input.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTand_flt(flt const x);

// ijkTrigCscd_flt
//	Calculate cosecant with degree input.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscd_flt(flt const x);

// ijkTrigSecd_flt
//	Calculate secant with degree input.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecd_flt(flt const x);

// ijkTrigCotd_flt
//	Calculate cotangent with degree input.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotd_flt(flt const x);

// ijkTrigAsind_flt
//	Calculate arcsine with degree output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-90, +90]
flt ijkTrigAsind_flt(flt const x);

// ijkTrigAcosd_flt
//	Calculate arccosine with degree output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+180, 0]
flt ijkTrigAcosd_flt(flt const x);

// ijkTrigAtand_flt
//	Calculate arctangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-90, +90)
flt ijkTrigAtand_flt(flt const x);

// ijkTrigAcscd_flt
//	Calculate arccosecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -90] U [+90, 0)
flt ijkTrigAcscd_flt(flt const x);

// ijkTrigAsecd_flt
//	Calculate arcsecant with degree output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+90, +180] U [0, +90)
flt ijkTrigAsecd_flt(flt const x);

// ijkTrigAcotd_flt
//	Calculate arccotangent with degree output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+180, 0)
flt ijkTrigAcotd_flt(flt const x);

// ijkTrigAtan2d_flt
//	Calculate arctangent with degree output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-90, +90)
flt ijkTrigAtan2d_flt(flt const x);

// ijkTrigSindTaylor_flt
//	Calculate sine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSindTaylor_flt(flt const x);

// ijkTrigCosdTaylor_flt
//	Calculate cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosdTaylor_flt(flt const x);

// ijkTrigTandTaylor_flt
//	Calculate tangent with degree input using a Taylor series.
//		param x: input in domain (-90, +90)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTandTaylor_flt(flt const x);

// ijkTrigCscdTaylor_flt
//	Calculate cosecant with degree input using a Taylor series.
//		param x: input in domain (-180, 0) U (0, +180)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscdTaylor_flt(flt const x);

// ijkTrigSecdTaylor_flt
//	Calculate secant with degree input using a Taylor series.
//		param x: input in domain (-90, +90) U (+90, +270)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecdTaylor_flt(flt const x);

// ijkTrigCotdTaylor_flt
//	Calculate cotangent with degree input using a Taylor series.
//		param x: input in domain (0, +180)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotdTaylor_flt(flt const x);

// ijkTrigSindCosdTaylor_flt
//	Calculate sine and cosine with degree input using a Taylor series.
//		param x: input in domain [-360, +360]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSindCosdTaylor_flt(flt const x);

// ijkTrigSinr_flt
//	Calculate sine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSinr_flt(flt const x);

// ijkTrigCosr_flt
//	Calculate cosine with radian input.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosr_flt(flt const x);

// ijkTrigTanr_flt
//	Calculate tangent with radian input.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanr_flt(flt const x);

// ijkTrigCscr_flt
//	Calculate cosecant with radian input.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscr_flt(flt const x);

// ijkTrigSecr_flt
//	Calculate secant with radian input.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecr_flt(flt const x);

// ijkTrigCotr_flt
//	Calculate cotangent with radian input.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotr_flt(flt const x);

// ijkTrigAsinr_flt
//	Calculate arcsine with radian output.
//		param x: input in domain [-1, +1]
//		return: asin(x) in range [-pi/2, +pi/2]
flt ijkTrigAsinr_flt(flt const x);

// ijkTrigAcosr_flt
//	Calculate arccosine with radian output.
//		param x: input in domain [-1, +1]
//		return: acos(x) in range [+pi, 0]
flt ijkTrigAcosr_flt(flt const x);

// ijkTrigAtanr_flt
//	Calculate arctangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: atan(x) in range (-pi/2, +pi/2)
flt ijkTrigAtanr_flt(flt const x);

// ijkTrigAcscr_flt
//	Calculate arccosecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: acsc(x) in range (0, -pi/2] U [+pi/2, 0)
flt ijkTrigAcscr_flt(flt const x);

// ijkTrigAsecr_flt
//	Calculate arcsecant with radian output.
//		param x: input in domain (-inf, -1] U [+1, +inf)
//		return: asec(x) in range (+pi/2, +pi] U [0, +pi/2)
flt ijkTrigAsecr_flt(flt const x);

// ijkTrigAcotr_flt
//	Calculate arccotangent with radian output.
//		param x: input in domain (-inf, +inf)
//		return: acot(x) in range (+pi, 0)
flt ijkTrigAcotr_flt(flt const x);

// ijkTrigAtan2r_flt
//	Calculate arctangent with radian output, given fraction components.
//		param y_sin: numerator (y or sine) used to calculate tangent
//		param x_cos: denominator (x or cosine) used to calculate tangent
//		return: atan(y/x) in range (-pi/2, +pi/2)
flt ijkTrigAtan2r_flt(flt const x);

// ijkTrigSinrTaylor_flt
//	Calculate sine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: sin(x) in range [-1, +1]
flt ijkTrigSinrTaylor_flt(flt const x);

// ijkTrigCosrTaylor_flt
//	Calculate cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		return: cos(x) in range [-1, +1]
flt ijkTrigCosrTaylor_flt(flt const x);

// ijkTrigTanrTaylor_flt
//	Calculate tangent with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2)
//		return: tan(x) in range (-inf, +inf)
flt ijkTrigTanrTaylor_flt(flt const x);

// ijkTrigCscrTaylor_flt
//	Calculate cosecant with radian input using a Taylor series.
//		param x: input in domain (-pi, 0) U (0, +pi)
//		return: csc(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigCscrTaylor_flt(flt const x);

// ijkTrigSecrTaylor_flt
//	Calculate secant with radian input using a Taylor series.
//		param x: input in domain (-pi/2, +pi/2) U (+pi/2, +3pi/2)
//		return: sec(x) in range (-inf, -1] U [+1, +inf)
flt ijkTrigSecrTaylor_flt(flt const x);

// ijkTrigCotrTaylor_flt
//	Calculate cotangent with radian input using a Taylor series.
//		param x: input in domain (0, +pi)
//		return: cot(x) in range (-inf, +inf)
flt ijkTrigCotrTaylor_flt(flt const x);

// ijkTrigSinrCosrTaylor_flt
//	Calculate sine and cosine with radian input using a Taylor series.
//		param x: input in domain [-2pi, +2pi]
//		param sinx_out: pointer to value to capture sin(x) in range [-1, +1]
//		param cosx_out: pointer to value to capture cos(x) in range [-1, +1]
//		return: x
flt ijkTrigSinrCosrTaylor_flt(flt const x);

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


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkTrigonometry.inl"


#endif	// !_IJK_TRIGONOMETRY_H_