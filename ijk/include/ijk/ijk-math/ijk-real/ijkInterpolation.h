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

	ijkInterpolation.h
	Core interpolation and curve segment management utilities.
*/

#ifndef _IJK_INTERPOLATION_H_
#define _IJK_INTERPOLATION_H_


#include "ijkReal.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkInterpNearest_flt
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param t: interpolation parameter
//		return: nearest-neighbor interpolated value, exactly v0 or v1
flt ijkInterpNearest_flt(flt const v0, flt const v1, flt const t);

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
flt ijkInterpBinearest_flt(flt const v00, flt const v01, flt const v10, flt const v11, flt const t0, flt const t1, flt const t);

// ijkInterpLinear_flt
//	Linear interpolation ("LERP") between two reference values.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: interpolated value between v0 and v1
flt ijkInterpLinear_flt(flt const v0, flt const v1, flt const t);

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
flt ijkInterpBilinear_flt(flt const v00, flt const v01, flt const v10, flt const v11, flt const t0, flt const t1, flt const t);

// ijkInterpLinearInv_flt
//	Inverse linear interpolation between two reference values to get parameter.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
flt ijkInterpLinearInv_flt(flt const v0, flt const v1, flt const v);

// ijkInterpLinearInvSafe_flt
//	Inverse linear interpolation between two reference values to get parameter 
//	with divide-by-zero safety.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
flt ijkInterpLinearInvSafe_flt(flt const v0, flt const v1, flt const v);

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
flt ijkInterpRemap_flt(flt const v0_dst, flt const v1_dst, flt const v0_src, flt const v1_src, flt const v_src);

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
flt ijkInterpRemapSafe_flt(flt const v0_dst, flt const v1_dst, flt const v0_src, flt const v1_src, flt const v_src);

// ijkInterpLinearRev0_flt
//	Reverse linear interpolation to get first control value.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
flt ijkInterpLinearRev0_flt(flt const v, flt const v1, flt const t);

// ijkInterpLinearRevSafe0_flt
//	Reverse linear interpolation to get first control value; division-by-zero
//	safety.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
flt ijkInterpLinearRevSafe0_flt(flt const v, flt const v1, flt const t);

// ijkInterpLinearRev1_flt
//	Reverse linear interpolation to get second control value.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
flt ijkInterpLinearRev1_flt(flt const v0, flt const v, flt const t);

// ijkInterpLinearRevSafe1_flt
//	Reverse linear interpolation to get second control value; division-by-zero
//	safety.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
flt ijkInterpLinearRevSafe1_flt(flt const v0, flt const v, flt const t);

// ijkInterpSmoothstep_flt
//	Smoothstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
flt ijkInterpSmoothstep_flt(flt const t);

// ijkInterpSmootherstep_flt
//	Smootherstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
flt ijkInterpSmootherstep_flt(flt const t);

// ijkInterpBezier0_flt
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param t: interpolation parameter; not used for order 0 interpolation
//		return: v0
flt ijkInterpBezier0_flt(flt const v0, flt const t);

// ijkInterpBezier1_flt
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
flt ijkInterpBezier1_flt(flt const v0, flt const v1, flt const t);

// ijkInterpBezier2_flt
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
flt ijkInterpBezier2_flt(flt const v0, flt const v1, flt const v2, flt const t);

// ijkInterpBezier3_flt
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
flt ijkInterpBezier3_flt(flt const v0, flt const v1, flt const v2, flt const v3, flt const t);

// ijkInterpBezierN_flt
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
flt ijkInterpBezierN_flt(flt const v[], size const order, flt const t);

// ijkInterpCubicHermite_flt
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
flt ijkInterpCubicHermite_flt(flt const v0, flt const dv0, flt const v1, flt const dv1, flt const t);

// ijkInterpCubicHermiteHandles_flt
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
flt ijkInterpCubicHermiteHandles_flt(flt const v0, flt const cv0, flt const v1, flt const cv1, flt const t);

// ijkInterpCubicCatmullRom_flt
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
flt ijkInterpCubicCatmullRom_flt(flt const vp, flt const v0, flt const v1, flt const v2, flt const t);

// ijkInterpBicubicCatmullRom_flt
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		param t: interpolation parameter for result
//		return: interpolated value
flt ijkInterpBicubicCatmullRom_flt(flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2, flt const t);

// ijkInterpReparamCubicHermite_flt
//	Reparameterize a cubic Hermite segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		return: total arc length
flt ijkInterpReparamCubicHermite_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const dv0, flt const v1, flt const dv1);

// ijkInterpReparamCubicHermiteHandles_flt
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		return: total arc length
flt ijkInterpReparamCubicHermiteHandles_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const cv0, flt const v1, flt const cv1);

// ijkInterpReparamCubicCatmullRom_flt
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vp: initial control value
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value
//		return: total arc length
flt ijkInterpReparamCubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vp, flt const v0, flt const v1, flt const v2);

// ijkInterpReparamBicubicCatmullRom_flt
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		return: total arc length
flt ijkInterpReparamBicubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2);

// ijkInterpSampleTableInc_flt
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
flt ijkInterpSampleTableInc_flt(flt const tTable[], flt const vTable[], index i, index di, flt const t);

// ijkInterpSampleTableDec_flt
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
flt ijkInterpSampleTableDec_flt(flt const tTable[], flt const vTable[], index i, index di, flt const t);

// ijkInterpSampleTableIncIndex_flt
//	Find index of parameter in table and retrieve interpolation parameter for 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
index ijkInterpSampleTableIncIndex_flt(flt* const tReparam_out, flt const tTable[], index i, index di, flt const t);

// ijkInterpSampleTableDecIndex_flt
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
index ijkInterpSampleTableDecIndex_flt(flt* const tReparam_out, flt const tTable[], index i, index di, flt const t);


//-----------------------------------------------------------------------------

// ijkInterpNearest_dbl
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param t: interpolation parameter
//		return: nearest-neighbor interpolated value, exactly v0 or v1
dbl ijkInterpNearest_dbl(dbl const v0, dbl const v1, dbl const t);

// ijkInterpBinearest_dbl
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
dbl ijkInterpBinearest_dbl(dbl const v00, dbl const v01, dbl const v10, dbl const v11, dbl const t0, dbl const t1, dbl const t);

// ijkInterpLinear_dbl
//	Linear interpolation ("LERP") between two reference values.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: interpolated value between v0 and v1
dbl ijkInterpLinear_dbl(dbl const v0, dbl const v1, dbl const t);

// ijkInterpBilinear_dbl
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
dbl ijkInterpBilinear_dbl(dbl const v00, dbl const v01, dbl const v10, dbl const v11, dbl const t0, dbl const t1, dbl const t);

// ijkInterpLinearInv_dbl
//	Inverse linear interpolation between two reference values to get parameter.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
dbl ijkInterpLinearInv_dbl(dbl const v0, dbl const v1, dbl const v);

// ijkInterpLinearInvSafe_dbl
//	Inverse linear interpolation between two reference values to get parameter 
//	with divide-by-zero safety.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
dbl ijkInterpLinearInvSafe_dbl(dbl const v0, dbl const v1, dbl const v);

// ijkInterpRemap_dbl
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
dbl ijkInterpRemap_dbl(dbl const v0_dst, dbl const v1_dst, dbl const v0_src, dbl const v1_src, dbl const v_src);

// ijkInterpRemapSafe_dbl
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
dbl ijkInterpRemapSafe_dbl(dbl const v0_dst, dbl const v1_dst, dbl const v0_src, dbl const v1_src, dbl const v_src);

// ijkInterpLinearRev0_dbl
//	Reverse linear interpolation to get first control value.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
dbl ijkInterpLinearRev0_dbl(dbl const v, dbl const v1, dbl const t);

// ijkInterpLinearRevSafe0_dbl
//	Reverse linear interpolation to get first control value; division-by-zero
//	safety.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
dbl ijkInterpLinearRevSafe0_dbl(dbl const v, dbl const v1, dbl const t);

// ijkInterpLinearRev1_dbl
//	Reverse linear interpolation to get second control value.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
dbl ijkInterpLinearRev1_dbl(dbl const v0, dbl const v, dbl const t);

// ijkInterpLinearRevSafe1_dbl
//	Reverse linear interpolation to get second control value; division-by-zero
//	safety.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
dbl ijkInterpLinearRevSafe1_dbl(dbl const v0, dbl const v, dbl const t);

// ijkInterpSmoothstep_dbl
//	Smoothstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
dbl ijkInterpSmoothstep_dbl(dbl const t);

// ijkInterpSmootherstep_dbl
//	Smootherstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
dbl ijkInterpSmootherstep_dbl(dbl const t);

// ijkInterpBezier0_dbl
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param t: interpolation parameter; not used for order 0 interpolation
//		return: v0
dbl ijkInterpBezier0_dbl(dbl const v0, dbl const t);

// ijkInterpBezier1_dbl
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
dbl ijkInterpBezier1_dbl(dbl const v0, dbl const v1, dbl const t);

// ijkInterpBezier2_dbl
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
dbl ijkInterpBezier2_dbl(dbl const v0, dbl const v1, dbl const v2, dbl const t);

// ijkInterpBezier3_dbl
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
dbl ijkInterpBezier3_dbl(dbl const v0, dbl const v1, dbl const v2, dbl const v3, dbl const t);

// ijkInterpBezierN_dbl
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
dbl ijkInterpBezierN_dbl(dbl const v[], size const order, dbl const t);

// ijkInterpCubicHermite_dbl
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
dbl ijkInterpCubicHermite_dbl(dbl const v0, dbl const dv0, dbl const v1, dbl const dv1, dbl const t);

// ijkInterpCubicHermiteHandles_dbl
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
dbl ijkInterpCubicHermiteHandles_dbl(dbl const v0, dbl const cv0, dbl const v1, dbl const cv1, dbl const t);

// ijkInterpCubicCatmullRom_dbl
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
dbl ijkInterpCubicCatmullRom_dbl(dbl const vp, dbl const v0, dbl const v1, dbl const v2, dbl const t);

// ijkInterpBicubicCatmullRom_dbl
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		param t: interpolation parameter for result
//		return: interpolated value
dbl ijkInterpBicubicCatmullRom_dbl(dbl const vpp, dbl const vp0, dbl const vp1, dbl const vp2, dbl const v0p, dbl const v00, dbl const v01, dbl const v02, dbl const v1p, dbl const v10, dbl const v11, dbl const v12, dbl const v2p, dbl const v20, dbl const v21, dbl const v22, dbl const tp, dbl const t0, dbl const t1, dbl const t2, dbl const t);

// ijkInterpReparamCubicHermite_dbl
//	Reparameterize a cubic Hermite segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		return: total arc length
dbl ijkInterpReparamCubicHermite_dbl(dbl tTable_out[], dbl lTable_out[], dbl vTable_out[], size const numDivisions, ibool const lNormalize, dbl const v0, dbl const dv0, dbl const v1, dbl const dv1);

// ijkInterpReparamCubicHermiteHandles_dbl
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		return: total arc length
dbl ijkInterpReparamCubicHermiteHandles_dbl(dbl tTable_out[], dbl lTable_out[], dbl vTable_out[], size const numDivisions, ibool const lNormalize, dbl const v0, dbl const cv0, dbl const v1, dbl const cv1);

// ijkInterpReparamCubicCatmullRom_dbl
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vp: initial control value
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value
//		return: total arc length
dbl ijkInterpReparamCubicCatmullRom_dbl(dbl tTable_out[], dbl lTable_out[], dbl vTable_out[], size const numDivisions, ibool const lNormalize, dbl const vp, dbl const v0, dbl const v1, dbl const v2);

// ijkInterpReparamBicubicCatmullRom_dbl
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		return: total arc length
dbl ijkInterpReparamBicubicCatmullRom_dbl(dbl tTable_out[], dbl lTable_out[], dbl vTable_out[], size const numDivisions, ibool const lNormalize, dbl const vpp, dbl const vp0, dbl const vp1, dbl const vp2, dbl const v0p, dbl const v00, dbl const v01, dbl const v02, dbl const v1p, dbl const v10, dbl const v11, dbl const v12, dbl const v2p, dbl const v20, dbl const v21, dbl const v22, dbl const tp, dbl const t0, dbl const t1, dbl const t2);

// ijkInterpSampleTableInc_dbl
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
dbl ijkInterpSampleTableInc_dbl(dbl const tTable[], dbl const vTable[], uindex i, uindex di, dbl const t);

// ijkInterpSampleTableDec_dbl
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
dbl ijkInterpSampleTableDec_dbl(dbl const tTable[], dbl const vTable[], uindex i, uindex di, dbl const t);

// ijkInterpSampleTableIncIndex_dbl
//	Find index of parameter in table and retrieve interpolation parameter for 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
index ijkInterpSampleTableIncIndex_dbl(dbl* const tReparam_out, dbl const tTable[], uindex i, uindex di, dbl const t);

// ijkInterpSampleTableDecIndex_dbl
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
index ijkInterpSampleTableDecIndex_dbl(dbl* const tReparam_out, dbl const tTable[], uindex i, uindex di, dbl const t);


//-----------------------------------------------------------------------------

// ijkInterpNearest
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param t: interpolation parameter
//		return: nearest-neighbor interpolated value, exactly v0 or v1
//real ijkInterpNearest(real const v0, real const v1, real const t);
#define ijkInterpNearest					ijk_declrealf(ijkInterpNearest)

// ijkInterpBinearest
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
//real ijkInterpBinearest(real const v00, real const v01, real const v10, real const v11, real const t0, real const t1, real const t);
#define ijkInterpBinearest					ijk_declrealf(ijkInterpBinearest)

// ijkInterpLinear
//	Linear interpolation ("LERP") between two reference values.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: interpolated value between v0 and v1
//real ijkInterpLinear(real const v0, real const v1, real const t);
#define ijkInterpLinear						ijk_declrealf(ijkInterpLinear)

// ijkInterpBilinear
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
//real ijkInterpBilinear(real const v00, real const v01, real const v10, real const v11, real const t0, real const t1, real const t);
#define ijkInterpBilinear					ijk_declrealf(ijkInterpBilinear)

// ijkInterpLinearInv
//	Inverse linear interpolation between two reference values to get parameter.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
//real ijkInterpLinearInv(real const v0, real const v1, real const v);
#define ijkInterpLinearInv					ijk_declrealf(ijkInterpLinearInv)

// ijkInterpLinearInvSafe
//	Inverse linear interpolation between two reference values to get parameter 
//	with divide-by-zero safety.
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1
//real ijkInterpLinearInvSafe(real const v0, real const v1, real const v);
#define ijkInterpLinearInvSafe				ijk_declrealf(ijkInterpLinearInvSafe)

// ijkInterpRemap
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
//real ijkInterpRemap(real const v0_dst, real const v1_dst, real const v0_src, real const v1_src, real const v_src);
#define ijkInterpRemap						ijk_declrealf(ijkInterpRemap)

// ijkInterpRemapSafe
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
//real ijkInterpRemapSafe(real const v0_dst, real const v1_dst, real const v0_src, real const v1_src, real const v_src);
#define ijkInterpRemapSafe					ijk_declrealf(ijkInterpRemapSafe)

// ijkInterpLinearRev0
//	Reverse linear interpolation to get first control value.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
//real ijkInterpLinearRev0(real const v, real const v1, real const t);
#define ijkInterpLinearRev0					ijk_declrealf(ijkInterpLinearRev0)

// ijkInterpLinearRevSafe0
//	Reverse linear interpolation to get first control value; division-by-zero
//	safety.
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param v1: terminal reference value/end point, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: first control value, v0
//real ijkInterpLinearRevSafe0(real const v, real const v1, real const t);
#define ijkInterpLinearRevSafe0				ijk_declrealf(ijkInterpLinearRevSafe0)

// ijkInterpLinearRev1
//	Reverse linear interpolation to get second control value.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
//real ijkInterpLinearRev1(real const v0, real const v, real const t);
#define ijkInterpLinearRev1					ijk_declrealf(ijkInterpLinearRev1)

// ijkInterpLinearRevSafe1
//	Reverse linear interpolation to get second control value; division-by-zero
//	safety.
//		param v0: initial reference value/start point, result when t=0
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: second control value, v1
//real ijkInterpLinearRevSafe1(real const v0, real const v, real const t);
#define ijkInterpLinearRevSafe1				ijk_declrealf(ijkInterpLinearRevSafe1)

// ijkInterpSmoothstep
//	Smoothstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
//real ijkInterpSmoothstep(real const t);
#define ijkInterpSmoothstep					ijk_declrealf(ijkInterpSmoothstep)

// ijkInterpSmootherstep
//	Smootherstep for parameter.
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[0,1], others yield extrapolation beyond reference values
//		return: interpolated value between 0 and 1
//real ijkInterpSmoothstep(real const t);
#define ijkInterpSmootherstep				ijk_declrealf(ijkInterpSmootherstep)

// ijkInterpBezier0
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param t: interpolation parameter; not used for order 0 interpolation
//		return: v0
//real ijkInterpBezier0(real const v0, real const t);
#define ijkInterpBezier0					ijk_declrealf(ijkInterpBezier0)

// ijkInterpBezier1
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
//real ijkInterpBezier1(real const v0, real const v1, real const t);
#define ijkInterpBezier1					ijk_declrealf(ijkInterpBezier1)

// ijkInterpBezier2
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
//real ijkInterpBezier2(real const v0, real const v1, real const v2, real const t);
#define ijkInterpBezier2					ijk_declrealf(ijkInterpBezier2)

// ijkInterpBezier3
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
//real ijkInterpBezier3(real const v0, real const v1, real const v2, real const v3, real const t);
#define ijkInterpBezier3					ijk_declrealf(ijkInterpBezier3)

// ijkInterpBezierN
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
//real ijkInterpBezierN(real const v[], size const order, real const t);
#define ijkInterpBezierN					ijk_declrealf(ijkInterpBezierN)

// ijkInterpCubicHermite
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
//real ijkInterpCubicHermite(real const v0, real const dv0, real const v1, real const dv1, real const t);
#define ijkInterpCubicHermite				ijk_declrealf(ijkInterpCubicHermite)

// ijkInterpCubicHermiteHandles
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
//real ijkInterpCubicHermiteHandles(real const v0, real const cv0, real const v1, real const cv1, real const t);
#define ijkInterpCubicHermiteHandles		ijk_declrealf(ijkInterpCubicHermiteHandles)

// ijkInterpCubicCatmullRom
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param t: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated value on spline/curve segment
//real ijkInterpCubicCatmullRom(real const vp, real const v0, real const v1, real const v2, real const t);
#define ijkInterpCubicCatmullRom			ijk_declrealf(ijkInterpCubicCatmullRom)

// ijkInterpBicubicCatmullRom
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		param t: interpolation parameter for result
//		return: interpolated value
//real ijkInterpBicubicCatmullRom(real const vpp, real const vp0, real const vp1, real const vp2, real const v0p, real const v00, real const v01, real const v02, real const v1p, real const v10, real const v11, real const v12, real const v2p, real const v20, real const v21, real const v22, real const tp, real const t0, real const t1, real const t2, real const t);
#define ijkInterpBicubicCatmullRom			ijk_declrealf(ijkInterpBicubicCatmullRom)

// ijkInterpReparamCubicHermite
//	Reparameterize a cubic Hermite segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		return: total arc length
//real ijkInterpReparamCubicHermite(real tTable_out[], real lTable_out[], real vTable_out[], size const numDivisions, ibool const lNormalize, real const v0, real const dv0, real const v1, real const dv1);
#define ijkInterpReparamCubicHermite		ijk_declrealf(ijkInterpReparamCubicHermite)

// ijkInterpReparamCubicHermiteHandles
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		return: total arc length
//real ijkInterpReparamCubicHermiteHandles(real tTable_out[], real lTable_out[], real vTable_out[], size const numDivisions, ibool const lNormalize, real const v0, real const cv0, real const v1, real const cv1);
#define ijkInterpReparamCubicHermiteHandles	ijk_declrealf(ijkInterpReparamCubicHermiteHandles)

// ijkInterpReparamCubicCatmullRom
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vp: initial control value
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value
//		return: total arc length
//real ijkInterpReparamCubicCatmullRom(real tTable_out[], real lTable_out[], real vTable_out[], size const numDivisions, ibool const lNormalize, real const vp, real const v0, real const v1, real const v2);
#define ijkInterpReparamCubicCatmullRom		ijk_declrealf(ijkInterpReparamCubicCatmullRom)

// ijkInterpReparamBicubicCatmullRom
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param tTable_out: array of interpolation parameters at each sample
//			valid: non-null
//		param lTable_out: array of accumulated arc lengths at each sample
//			valid: non-null
//		param vTable_out: array of values sampled
//			valid: non-null
//		param numDivisions: number of intermediate samples on segment
//			valid: non-zero
//			note: tables should have at least (numDivisions+1) elements
//			note: precision of arc length increases as this number increases
//		param lNormalize: option to normalize arc lengths
//		param vpp: initial control value of initial control curve
//		param vp0: initial reference value/start point of initial control 
//			curve, result of initial control curve when tp=0
//		param vp1: terminal reference value/end point of initial control 
//			curve, result of initial control curve when tp=1
//		param vp2: terminal control value of initial control curve
//		param v0p: initial control value of initial value curve
//		param v00: initial reference value/start point of initial value 
//			curve, result of initial value curve when t0=0
//		param v01: terminal reference value/end point of initial value 
//			curve, result of initial value curve when t0=1
//		param v02: terminal control value of initial value curve
//		param v1p: initial control value of terminal value curve
//		param v10: initial reference value/start point of terminal value 
//			curve, result of terminal value curve when t1=0
//		param v11: terminal reference value/end point of terminal value 
//			curve, result of terminal value curve when t1=1
//		param v12: terminal control value of terminal value curve
//		param v2p: initial control value of terminal control curve
//		param v20: initial reference value/start point of terminal control 
//			curve, result of terminal control curve when t2=0
//		param v21: terminal reference value/end point of terminal control 
//			curve, result of terminal control curve when t2=1
//		param v22: terminal control value of terminal control curve
//		param tp: interpolation parameter for initial control curve
//		param t0: interpolation parameter for initial value curve
//		param t1: interpolation parameter for terminal value curve
//		param t2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkInterpReparamBicubicCatmullRom(real tTable_out[], real lTable_out[], real vTable_out[], size const numDivisions, ibool const lNormalize, real const vpp, real const vp0, real const vp1, real const vp2, real const v0p, real const v00, real const v01, real const v02, real const v1p, real const v10, real const v11, real const v12, real const v2p, real const v20, real const v21, real const v22, real const tp, real const t0, real const t1, real const t2);
#define ijkInterpReparamBicubicCatmullRom	ijk_declrealf(ijkInterpReparamBicubicCatmullRom)

// ijkInterpSampleTableInc
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
//real ijkInterpSampleTableInc(real const tTable[], real const vTable[], uindex i, uindex di, real const t);
#define ijkInterpSampleTableInc				ijk_declrealf(ijkInterpSampleTableInc)

// ijkInterpSampleTableDec
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: interpolated value in table that approximates input parameter
//real ijkInterpSampleTableDec(real const tTable[], real const vTable[], uindex i, uindex di, real const t);
#define ijkInterpSampleTableDec				ijk_declrealf(ijkInterpSampleTableDec)

// ijkInterpSampleTableIncIndex
//	Find index of parameter in table and retrieve interpolation parameter for 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
//index ijkInterpSampleTableIncIndex(real* const tReparam_out, real const tTable[], uindex i, uindex di, real const t);
#define ijkInterpSampleTableIncIndex		ijk_declrealf(ijkInterpSampleTableIncIndex)

// ijkInterpSampleTableDecIndex
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param tReparam_out: interpolation parameter for final approximation
//			valid: non-null
//			note: represents parameter to use to interpolate between value in 
//			some table at return index, and the following value in the table
//		param tTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param t: input parameter to find in search table
//		return: index of interpolation parameter discovered
//index ijkInterpSampleTableDecIndex(real* const tReparam_out, real const tTable[], uindex i, uindex di, real const t);
#define ijkInterpSampleTableDecIndex		ijk_declrealf(ijkInterpSampleTableDecIndex)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkInterpolation.inl"


#endif	// !_IJK_INTERPOLATION_H_