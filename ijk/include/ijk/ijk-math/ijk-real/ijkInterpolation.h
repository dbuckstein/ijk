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

	ijkInterpolation.h
	Core interpolation and curve segment management utilities.
*/

#ifndef _IJK_INTERPOLATION_H_
#define _IJK_INTERPOLATION_H_


#include "ijkReal.h"


//-----------------------------------------------------------------------------

// ijkInterpNearest_flt
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param t: interpolation parameter
//		return: nearest-neighbor interpolated value, exactly v0 or v1

// ijkInterpBinearest_flt
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param t0: interpolation parameter for first pair
//		param t1: interpolation parameter for second pair
//		param t: interpolation parameter for results
//		return: bi-nearest-neighbor interpolated value

// ijkInterpLinear_flt
//	Linear interpolation ("LERP") between two reference values.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: interpolated value between v0 and v1

// ijkInterpBilinear_flt
//	Bi-linear interpolation between two pairs of reference values.
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0=0
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0=1
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1=0
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1=1
//		param t0: interpolation parameter for first pair
//		param t1: interpolation parameter for second pair
//		param t: interpolation parameter for results
//		return: interpolated value

// ijkInterpLinearInv_flt
//	Inverse linear interpolation between two reference values to get parameter.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1

// ijkInterpLinearInvSafe_flt
//	Inverse linear interpolation between two reference values to get parameter 
//	with divide-by-zero safety.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1

// ijkInterpRemap_flt
//	Linear remap between two ranges by first inverse interpolating between 
//	source/original range and then linearly interpolating between destination/
//	target range.
//		param v0_dst: initial reference value in destination/target range, 
//			result when v_src=v0_src
//		param v1_dst: terminal reference value in destination/target range, 
//			result when v_src=v1_src
//		param v0_src: initial reference value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: value in original range remapped to target range

// ijkInterpRemapSafe_flt
//	Linear remap between two ranges by first inverse interpolating between 
//	source/original range and then linearly interpolating between destination/
//	target range; divide-by-zero safety.
//		param v0_dst: initial reference value in destination/target range, 
//			result when v_src=v0_src
//		param v1_dst: terminal reference value in destination/target range, 
//			result when v_src=v1_src
//		param v0_src: initial reference value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: value in original range remapped to target range

// ijkInterpBezier0_flt
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: v0

// ijkInterpBezier1_flt
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: linear interpolation between v0 and v1

// ijkInterpBezier2_flt
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: quadratic Bezier interpolation between v0 and v2

// ijkInterpBezier3_flt
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: cubic Bezier interpolation between v0 and v3

// ijkInterpBezierN_flt
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: recursive Bezier interpolation between v[0] and v[order]

// ijkInterpCubicHermite_flt
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: interpolated value on spline/curve segment

// ijkInterpCubicHermiteHandles_flt
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate
//		return: interpolated value on spline/curve segment

// ijkInterpCubicCatmullRom_flt
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vPrev: initial control value
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param vNext: terminal control value
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment

// ijkInterpBicubicCatmullRom_flt
//	Bicubic interpolation using Catmull-Rom interpolation for segments.
//		param vPrevPrev: initial control value of initial control curve
//		param vPrev0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tPrev=0
//		param vPrev1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tPrev=1
//		param vPrevNext: terminal control value of initial control curve
//		param v0Prev: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v0Next: terminal control value of initial value curve
//		param v1Prev: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v1Next: terminal control value of terminal value curve
//		param vNextPrev: initial control value of terminal control curve
//		param vNext0: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when tNext=0
//		param vNext1: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when tNext=1
//		param vNextNext: terminal control value of terminal control curve
//		param tPrev: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param tNext: interpolation parameter for terminal control curve
//		param t: interpolation parameter for result
//		return: interpolated value


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkInterpolation.inl"


#endif	// !_IJK_INTERPOLATION_H_