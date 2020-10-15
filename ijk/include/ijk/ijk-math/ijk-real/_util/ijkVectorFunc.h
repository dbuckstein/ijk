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

	ijkVectorFunc.h
	Vector function declarations, using "templates" for C.
	This file is an attempt to avoid writing 7 declarations for each vector 
		function, one per type, of which there are many.
*/

#ifdef IJK_VECTORFUNC_PREFIX
#ifndef _IJK_VECTORFUNC_H_
#define _IJK_VECTORFUNC_H_ ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H)

// IJK_VECTORFUNC_SETUP
#pragma region IJK_VECTORFUNC_SETUP

#if (IJK_VECTORFUNC_PREFIX == i)
#define type	i32
#define tvec	int
#define typekv	intkv
#define typev	intv
#define type2	int2
#define type3	int3
#define type4	int4
#define tvec2	ivec2
#define tvec3	ivec3
#define tvec4	ivec4
#define tabs(x)		ijk_abs_int(x)
#define tsgn(x)		ijk_sgn_int(x)
#define trecip(x)	(0)
#define tsqrt(x)	(0)
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_PREFIX == il)
#define type	i64
#define tvec	intl
#define typekv	intlkv
#define typev	intlv
#define type2	intl2
#define type3	intl3
#define type4	intl4
#define tvec2	ilvec2
#define tvec3	ilvec3
#define tvec4	ilvec4
#define tabs(x)		ijk_abs_int(x)
#define tsgn(x)		ijk_sgn_int(x)
#define trecip(x)	(0)
#define tsqrt(x)	(0)
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_PREFIX == u)
#define type	ui32
#define tvec	uint
#define typekv	uintkv
#define typev	uintv
#define type2	uint2
#define type3	uint3
#define type4	uint4
#define tvec2	uvec2
#define tvec3	uvec3
#define tvec4	uvec4
#define tabs(x)		ijk_abs_int(x)
#define tsgn(x)		ijk_sgn_int(x)
#define trecip(x)	(0)
#define tsqrt(x)	(0)
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_PREFIX == ul)
#define type	ui64
#define tvec	uintl
#define typekv	uintlkv
#define typev	uintlv
#define type2	uintl2
#define type3	uintl3
#define type4	uintl4
#define tvec2	ulvec2
#define tvec3	ulvec3
#define tvec4	ulvec4
#define tabs(x)		ijk_abs_int(x)
#define tsgn(x)		ijk_sgn_int(x)
#define trecip(x)	(0)
#define tsqrt(x)	(0)
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_PREFIX == d)
#define type	f64
#define tvec	double
#define typekv	doublekv
#define typev	doublev
#define type2	double2
#define type3	double3
#define type4	double4
#define tvec2	dvec2
#define tvec3	dvec3
#define tvec4	dvec4
#define tabs(x)		ijk_abs_dbl(x)
#define tsgn(x)		ijk_sgn_dbl(x)
#define trecip(x)	ijk_recip_safe_dbl(x)
#define tsqrt(x)	ijkSqrt_dbl(x)
#define tsqrtinv(x)	ijkSqrtInv_dbl(x)
#else // (IJK_VECTORFUNC_PREFIX == f || IJK_VECTORFUNC_PREFIX == ?)
#define type	f32
#define tvec	float
#define typekv	floatkv
#define typev	floatv
#define type2	float2
#define type3	float3
#define type4	float4
#define tvec2	fvec2
#define tvec3	fvec3
#define tvec4	fvec4
#define tabs(x)		ijk_abs_flt(x)
#define tsgn(x)		ijk_sgn_flt(x)
#define trecip(x)	ijk_recip_safe_flt(x)
#define tsqrt(x)	ijkSqrt_flt(x)
#define tsqrtinv(x)	ijkSqrtInv_flt(x)
#endif	// IJK_VECTORFUNC_PREFIX

#define tfunc(func, ...)					ijk_tokencat(func, IJK_VECTORFUNC_PREFIX)(__VA_ARGS__)
#define tfuncs(func, suffix, ...)			ijk_tokencat(func, ijk_tokencat(IJK_VECTORFUNC_PREFIX, suffix))(__VA_ARGS__)
#define tfuncp(func, prefix, ...)			ijk_tokencat(func, ijk_tokencat(prefix, IJK_VECTORFUNC_PREFIX))(__VA_ARGS__)
#define tfuncps(func, prefix, suffix, ...)	ijk_tokencat(func, ijk_tokencat(ijk_tokencat(prefix, IJK_VECTORFUNC_PREFIX), suffix))(__VA_ARGS__)

#pragma endregion
// IJK_VECTORFUNC_SETUP


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// abs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
type tfuncs(abs1, s, type const s);

// sgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
type tfuncs(sgn1, s, type const s);

// dot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
type tfuncs(dot1, s, type const s_lh, type const s_rh);

// lengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
type tfuncs(lengthSq1, s, type const s);

// length1*s
//	Length of scalar.
//		param s: scalar
//		return: length
type tfuncs(length1, s, type const s);

// lengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
type tfuncs(lengthSqInv1, s, type const s);

// lengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
type tfuncs(lengthInv1, s, type const s);

// normalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
type tfuncs(normalize1, s, type const s);

// normalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
type tfuncs(normalizeGetLength1, s, type const s, type* const length_out);

// normalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
type tfuncs(normalizeGetLengthInv1, s, type const s, type* const lengthInv_out);


//-----------------------------------------------------------------------------

// dot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot2, v, type2 const v_lh, type2 const v_rh);

// cross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
type tfuncs(cross2, v, type2 const v_lh, type2 const v_rh);


//-----------------------------------------------------------------------------

// dot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot3, v, type3 const v_lh, type3 const v_rh);

// cross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(cross3, v, type3 v_out, type3 const v_lh, type3 const v_rh);


//-----------------------------------------------------------------------------

// dot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot4, v, type4 const v_lh, type4 const v_rh);

// cross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
typev tfuncs(cross4, v, type4 v_out, type4 const v_lh, type4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// abs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
type tfunc(abs1, type const s);

// sgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
type tfunc(sgn1, type const s);

// dot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
tvec tfunc(dot1, tvec const s_lh, tvec const s_rh);

// lengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
tvec tfunc(lengthSq1, tvec const s);

// length1*
//	Length of scalar.
//		param s: scalar
//		return: length
tvec tfunc(length1, tvec const s);

// lengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
tvec tfunc(lengthSqInv1, tvec const s);

// lengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
tvec tfunc(lengthInv1, tvec const s);

// normalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
tvec tfunc(normalize1, tvec const s);

// normalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
tvec tfunc(normalizeGetLength1, tvec const s, tvec* const length_out);

// normalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
tvec tfunc(normalizeGetLengthInv1, tvec const s, tvec* const lengthInv_out);


//-----------------------------------------------------------------------------

// dot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot2, tvec2 const v_lh, tvec2 const v_rh);

// cross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
tvec tfunc(cross2, tvec2 const v_lh, tvec2 const v_rh);


//-----------------------------------------------------------------------------

// dot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot3, tvec3 const v_lh, tvec3 const v_rh);

// cross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
tvec3 tfunc(cross3, tvec3 const v_lh, tvec3 const v_rh);


//-----------------------------------------------------------------------------

// dot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot4, tvec4 const v_lh, tvec4 const v_rh);

// cross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
tvec4 tfunc(cross4, tvec4 const v_lh, tvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVectorFunc.inl"


#undef tfunc
#undef tfuncs
#undef tfuncp
#undef tfuncps

#undef type
#undef tvec
#undef typekv
#undef typev
#undef type2
#undef type3
#undef type4
#undef tvec2
#undef tvec3
#undef tvec4
#undef tabs
#undef tsgn
#undef trecip
#undef tsqrt
#undef tsqrtinv

#undef IJK_VECTORFUNC_PREFIX

#undef _IJK_VECTORFUNC_H_
#endif	// !_IJK_VECTORFUNC_H_
#endif	// IJK_VECTORFUNC_PREFIX