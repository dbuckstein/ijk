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

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
type tfuncs(ijkVecAbs1, s, type const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
type tfuncs(ijkVecSgn1, s, type const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
type tfuncs(ijkVecDot1, s, type const s_lh, type const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
type tfuncs(ijkVecLengthSq1, s, type const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
type tfuncs(ijkVecLength1, s, type const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
type tfuncs(ijkVecLengthSqInv1, s, type const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
type tfuncs(ijkVecLengthInv1, s, type const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
type tfuncs(ijkVecNormalize1, s, type const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
type tfuncs(ijkVecNormalizeGetLength1, s, type const s, type* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
type tfuncs(ijkVecNormalizeGetLengthInv1, s, type const s, type* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVec2*v
//	Pass-thru vector (do nothing).
//		param v: vector
//		return: v
typev tfuncs(ijkVecInit2, v, type2 v);

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
typev tfuncs(ijkVecInit2, v, type2 v_out);

// ijkVecInitValue2*v
//	Initialize 2D vector to the same specified value for all elements.
//		param v_out: output vector
//		param xy: value to be assigned to all elements
//		return: v_out
typev tfuncs(ijkVecInitValue2, v, type2 v_out, type const xy);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
typev tfuncs(ijkVecInitElems2, v, type2 v_out, type const x, type const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecCopy2, v, type2 v_out, type2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecNegate2, v, type2 v_out, type2 const v_in);

// ijkVecBitNot2*v
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecBitNot2, v, type2 v_out, type2 const v_in);

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv tfuncs(ijkVecNot2, v, bool2 bv_out, type2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise modulo of 2D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise modulo of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitAnd2*v
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitNand2*v
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitOr2*v
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitNor2*v
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitXor2*v
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitNxor2*v
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitShiftLeft2*v
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecBitShiftRight2*v
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight2, v, type2 v_out, type2 const v_lh, type2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(ijkVecDot2, v, type2 const v_lh, type2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
type tfuncs(ijkVecCross2, v, type2 const v_lh, type2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(ijkVecDot3, v, type3 const v_lh, type3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecCross3, v, type3 v_out, type3 const v_lh, type3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(ijkVecDot4, v, type4 const v_lh, type4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
typev tfuncs(ijkVecCross4, v, type4 v_out, type4 const v_lh, type4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
type tfunc(ijkVecAbs1, type const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
type tfunc(ijkVecSgn1, type const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
tvec tfunc(ijkVecDot1, tvec const s_lh, tvec const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
tvec tfunc(ijkVecLengthSq1, tvec const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
tvec tfunc(ijkVecLength1, tvec const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
tvec tfunc(ijkVecLengthSqInv1, tvec const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
tvec tfunc(ijkVecLengthInv1, tvec const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
tvec tfunc(ijkVecNormalize1, tvec const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
tvec tfunc(ijkVecNormalizeGetLength1, tvec const s, tvec* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
tvec tfunc(ijkVecNormalizeGetLengthInv1, tvec const s, tvec* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(ijkVecDot2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
tvec tfunc(ijkVecCross2, tvec2 const v_lh, tvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(ijkVecDot3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
tvec3 tfunc(ijkVecCross3, tvec3 const v_lh, tvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(ijkVecDot4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
tvec4 tfunc(ijkVecCross4, tvec4 const v_lh, tvec4 const v_rh);


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