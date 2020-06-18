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

// ijkInterpLinear_flt
//	Linear interpolation ("LERP") between two reference values.
//		param v0: initial reference value/start point, result when t = 0
//		param v1: terminal reference value/end point, result when t = 1
//		param t: interpolation parameter; inputs in [0,1] interpolate in 
//			[v0,v1], others yield extrapolation beyond reference values
//		return: interpolated value between v0 and v1

// ijkInterpLinearInv_flt
//	Inverse linear interpolation between two reference values to get parameter.
//		param v0: initial reference value/start point, result when t = 0
//		param v1: terminal reference value/end point, result when t = 1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1

// ijkInterpLinearInvSafe_flt
//	Inverse linear interpolation between two reference values to get parameter 
//	with divide-by-zero safety.
//		param v0: initial reference value/start point, result when t = 0
//		param v1: terminal reference value/end point, result when t = 1
//		param v: interpolated value; inputs within [v0,v1] yield a paremeter 
//			in [0,1] used for interpolation, others yield parameters beyond 
//			unit range used for extrapolation
//		return: interpolation parameter used to interpolate between v0 and v1

// ijkInterpRemap_flt
//	Linear remap between two ranges.
//		param v0_dst: initial referene value in destination/target range
//		param v1_dst: terminal reference value in destination/target range
//		param v0_src: initial referene value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: value in original range remapped to target range

// ijkInterpRemapSafe_flt
//	Linear remap between two ranges with divide-by-zero safety.
//		param v0_dst: initial referene value in destination/target range
//		param v1_dst: terminal reference value in destination/target range
//		param v0_src: initial referene value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: value in original range remapped to target range


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkInterpolation.inl"


#endif	// !_IJK_INTERPOLATION_H_