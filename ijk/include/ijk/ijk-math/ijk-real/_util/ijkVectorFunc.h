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

#ifdef IJK_VECTORFUNC_TYPE
#ifndef _IJK_VECTORFUNC_H_
#define _IJK_VECTORFUNC_H_ IJK_VECTORFUNC_TYPE

// IJK_VECTORFUNC_SETUP
#pragma region IJK_VECTORFUNC_SETUP

#define _BOOL	0
#define _INT	1
#define _INTL	2
#define _UINT	3
#define _UINTL	4
#define _FLOAT	5
#define _DOUBLE	6

#if (IJK_VECTORFUNC_TYPE == _BOOL)
#define tsfx	b
#define type	byte
#define tvec	bool
#define typekv	boolkv
#define typev	boolv
#define type2	bool2
#define type3	bool3
#define type4	bool4
#define tvec2	bvec2
#define tvec3	bvec3
#define tvec4	bvec4
#define tabs(x)		(x)
#define tsgn(x)		(x > 0)
#define trecip(x)	(0)
#define tsqrt(x)	((type)ijkSqrt((real)x))
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_TYPE == _INT)
#define tsfx	i
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
#define tsqrt(x)	((type)ijkSqrt((real)x))
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_TYPE == _INTL)
#define tsfx	il
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
#define tsqrt(x)	((type)ijkSqrt((real)x))
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_TYPE == _UINT)
#define tsfx	u
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
#define tabs(x)		(x)
#define tsgn(x)		(x > 0)
#define trecip(x)	(0)
#define tsqrt(x)	((type)ijkSqrt((real)x))
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_TYPE == _UINTL)
#define tsfx	ul
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
#define tabs(x)		(x)
#define tsgn(x)		(x > 0)
#define trecip(x)	(0)
#define tsqrt(x)	((type)ijkSqrt((real)x))
#define tsqrtinv(x)	(0)
#elif (IJK_VECTORFUNC_TYPE == _DOUBLE)
#define tsfx	d
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
#else // (IJK_VECTORFUNC_TYPE == _FLOAT || IJK_VECTORFUNC_TYPE == ?)
#define tsfx	f
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
#endif	// IJK_VECTORFUNC_TYPE

#define tfunc(func, ...)					ijk_tokencat(func, tsfx)(__VA_ARGS__)
#define tfuncs(func, suffix, ...)			ijk_tokencat(func, ijk_tokencat(tsfx, suffix))(__VA_ARGS__)
#define tfuncp(func, prefix, ...)			ijk_tokencat(func, ijk_tokencat(prefix, tsfx))(__VA_ARGS__)
#define tfuncps(func, prefix, suffix, ...)	ijk_tokencat(func, ijk_tokencat(ijk_tokencat(prefix, tsfx), suffix))(__VA_ARGS__)

#undef _BOOL
#undef _INT
#undef _INTL
#undef _UINT
#undef _UINTL
#undef _FLOAT
#undef _DOUBLE

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

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
typev tfuncs(ijkVecP, v, typev v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
typev tfuncs(ijkVecInit2, v, type2 v_out);

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

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater2, v, bool2 bv_out, type2 const v_lh, type2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecCopy2, vs, type2 v_out, type const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecNegate2, vs, type2 v_out, type const s_in);

// ijkVecBitNot2*vs
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecBitNot2, vs, type2 v_out, type const s_in);

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv tfuncs(ijkVecNot2, vs, bool2 bv_out, type const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecAdd2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecSub2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMul2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDiv2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDivSafe2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecMod2*vs
//	Calculate modulo of 2D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMod2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecModSafe2*vs
//	Calculate modulo of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecModSafe2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitAnd2*vs
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitAnd2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitNand2*vs
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNand2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitOr2*vs
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitOr2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitNor2*vs
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNor2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitXor2*vs
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitXor2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitNxor2*vs
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNxor2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitShiftLeft2*vs
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecBitShiftRight2*vs
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftRight2, vs, type2 v_out, type2 const v_lh, type const s_rh);

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecInequal2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLessEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLess2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreater2, vs, bool2 bv_out, type2 const v_lh, type const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecMod2*sv
//	Calculate modulo of scalar by 2D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate modulo of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitAnd2*sv
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitNand2*sv
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitOr2*sv
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitNor2*sv
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitXor2*sv
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitNxor2*sv
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitShiftLeft2*sv
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecBitShiftRight2*sv
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight2, sv, type2 v_out, type const s_lh, type2 const v_rh);

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater2, sv, bool2 bv_out, type const s_lh, type2 const v_rh);

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

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
typev tfuncs(ijkVecInit3, v, type3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
typev tfuncs(ijkVecInitElems3, v, type3 v_out, type const x, type const y, type const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecCopy3, v, type3 v_out, type3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecNegate3, v, type3 v_out, type3 const v_in);

// ijkVecBitNot3*v
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecBitNot3, v, type3 v_out, type3 const v_in);

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv tfuncs(ijkVecNot3, v, bool3 bv_out, type3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise modulo of 3D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise modulo of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitAnd3*v
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitNand3*v
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitOr3*v
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitNor3*v
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitXor3*v
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitNxor3*v
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitShiftLeft3*v
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecBitShiftRight3*v
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight3, v, type3 v_out, type3 const v_lh, type3 const v_rh);

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater3, v, bool3 bv_out, type3 const v_lh, type3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
typev tfuncs(ijkVecCopy3, vz, type3 v_out, type2 const v_xy, type const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecCopy3, vs, type3 v_out, type const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecNegate3, vs, type3 v_out, type const s_in);

// ijkVecBitNot3*vs
//	Calculate bitwise 'not' of 3D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecBitNot3, vs, type3 v_out, type const s_in);

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv tfuncs(ijkVecNot3, vs, bool3 bv_out, type const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecAdd3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecSub3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMul3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDiv3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDivSafe3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecMod3*vs
//	Calculate modulo of 3D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMod3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecModSafe3*vs
//	Calculate modulo of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecModSafe3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitAnd3*vs
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitAnd3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitNand3*vs
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNand3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitOr3*vs
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitOr3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitNor3*vs
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNor3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitXor3*vs
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitXor3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitNxor3*vs
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNxor3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitShiftLeft3*vs
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecBitShiftRight3*vs
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftRight3, vs, type3 v_out, type3 const v_lh, type const s_rh);

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecEqual3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecInequal3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLessEqual3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLess3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreater3, vs, bool3 bv_out, type3 const v_lh, type const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
typev tfuncs(ijkVecCopy3, xv, type3 v_out, type const x, type2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecMod3*sv
//	Calculate modulo of scalar by 3D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate modulo of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitAnd3*sv
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitNand3*sv
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitOr3*sv
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitNor3*sv
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitXor3*sv
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitNxor3*sv
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitShiftLeft3*sv
//	Calculate bit shift left of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecBitShiftRight3*sv
//	Calculate bit shift right of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight3, sv, type3 v_out, type const s_lh, type3 const v_rh);

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater3, sv, bool3 bv_out, type const s_lh, type3 const v_rh);

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

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
typev tfuncs(ijkVecInit4, v, type4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
typev tfuncs(ijkVecInitElems4, v, type4 v_out, type const x, type const y, type const z, type const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
typev tfuncs(ijkVecCopy4, xvw, type4 v_out, type const x, type2 const v_yz, type const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
typev tfuncs(ijkVecCopy4, v2, type4 v_out, type2 const v_xy, type2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecCopy4, v, type4 v_out, type4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecNegate4, v, type4 v_out, type4 const v_in);

// ijkVecBitNot4*v
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
typev tfuncs(ijkVecBitNot4, v, type4 v_out, type4 const v_in);

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv tfuncs(ijkVecNot4, v, bool4 bv_out, type4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise modulo of 4D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise modulo of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitAnd4*v
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitNand4*v
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitOr4*v
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitNor4*v
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitXor4*v
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitNxor4*v
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitShiftLeft4*v
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecBitShiftRight4*v
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight4, v, type4 v_out, type4 const v_lh, type4 const v_rh);

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater4, v, bool4 bv_out, type4 const v_lh, type4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
typev tfuncs(ijkVecCopy4, vzw, type4 v_out, type2 const v_xy, type const z, type const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
typev tfuncs(ijkVecCopy4, vw, type4 v_out, type3 const v_xyz, type const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecCopy4, vs, type4 v_out, type const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecNegate4, vs, type4 v_out, type const s_in);

// ijkVecBitNot4*vs
//	Calculate bitwise 'not' of 4D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
typev tfuncs(ijkVecBitNot4, vs, type4 v_out, type const s_in);

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv tfuncs(ijkVecNot4, vs, bool4 bv_out, type const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecAdd4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecSub4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMul4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDiv4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecDivSafe4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecMod4*vs
//	Calculate modulo of 4D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecMod4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecModSafe4*vs
//	Calculate modulo of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecModSafe4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitAnd4*vs
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitAnd4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitNand4*vs
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNand4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitOr4*vs
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitOr4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitNor4*vs
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNor4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitXor4*vs
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitXor4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitNxor4*vs
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitNxor4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitShiftLeft4*vs
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecBitShiftRight4*vs
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
typev tfuncs(ijkVecBitShiftRight4, vs, type4 v_out, type4 const v_lh, type const s_rh);

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecEqual4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecInequal4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLessEqual4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecLess4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv tfuncs(ijkVecGreater4, vs, bool4 bv_out, type4 const v_lh, type const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
typev tfuncs(ijkVecCopy4, xyv, type4 v_out, type const x, type const y, type2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
typev tfuncs(ijkVecCopy4, xv, type4 v_out, type const x, type3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecAdd4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecSub4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMul4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDiv4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecDivSafe4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecMod4*sv
//	Calculate modulo of scalar by 4D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecMod4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate modulo of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecModSafe4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitAnd4*sv
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitAnd4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitNand4*sv
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNand4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitOr4*sv
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitOr4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitNor4*sv
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNor4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitXor4*sv
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitXor4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitNxor4*sv
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitNxor4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitShiftLeft4*sv
//	Calculate bit shift left of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftLeft4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecBitShiftRight4*sv
//	Calculate bit shift right of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(ijkVecBitShiftRight4, sv, type4 v_out, type const s_lh, type4 const v_rh);

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecEqual4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecInequal4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLessEqual4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreaterEqual4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecLess4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv tfuncs(ijkVecGreater4, sv, bool4 bv_out, type const s_lh, type4 const v_rh);

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
tvec tfunc(ijkVecAbs1, tvec const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
tvec tfunc(ijkVecSgn1, tvec const s);

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

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
tvec2 tfunc(ijkVecInit2);

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
tvec2 tfunc(ijkVecInitElems2, tvec const x, tvec const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
tvec2 tfunc(ijkVecCopy2, tvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
tvec2 tfunc(ijkVecNegate2, tvec2 const v_in);

// ijkVecBitNot2*
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
tvec2 tfunc(ijkVecBitNot2, tvec2 const v_in);

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
bvec2 tfunc(ijkVecNot2, tvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecAdd2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecSub2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecMul2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecDiv2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecDivSafe2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise modulo of 2D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecMod2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise modulo of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecModSafe2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitAnd2*
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitAnd2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitNand2*
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNand2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitOr2*
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitOr2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitNor2*
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNor2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitXor2*
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitXor2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitNxor2*
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNxor2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitShiftLeft2*
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitShiftLeft2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecBitShiftRight2*
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitShiftRight2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecEqual2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecInequal2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecLessEqual2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecGreaterEqual2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecLess2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecGreater2, tvec2 const v_lh, tvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
tvec2 tfuncs(ijkVecCopy2, s, tvec const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
tvec2 tfuncs(ijkVecNegate2, s, tvec const s_in);

// ijkVecBitNot2*s
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitNot2, s, tvec const s_in);

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
bvec2 tfuncs(ijkVecNot2, s, tvec const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecAdd2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecSub2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecMul2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecDiv2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecDivSafe2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecMod2*s
//	Calculate modulo of 2D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecMod2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecModSafe2*s
//	Calculate modulo of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecModSafe2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitAnd2*s
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitAnd2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitNand2*s
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitNand2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitOr2*s
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitOr2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitNor2*s
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitNor2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitXor2*s
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitXor2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitNxor2*s
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitNxor2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitShiftLeft2*s
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitShiftLeft2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecBitShiftRight2*s
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec2 tfuncs(ijkVecBitShiftRight2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecEqual2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecInequal2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecLessEqual2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecGreaterEqual2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecLess2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec2 tfuncs(ijkVecGreater2, s, tvec2 const v_lh, tvec const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecAdd2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecSub2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecMul2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecDiv2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecDivSafe2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecMod2s*
//	Calculate modulo of scalar by 2D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecMod2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate modulo of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecModSafe2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitAnd2s*
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitAnd2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitNand2s*
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNand2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitOr2s*
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitOr2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitNor2s*
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNor2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitXor2s*
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitXor2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitNxor2s*
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitNxor2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitShiftLeft2s*
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitShiftLeft2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecBitShiftRight2s*
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec2 tfunc(ijkVecBitShiftRight2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecEqual2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecInequal2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecLessEqual2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecGreaterEqual2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecLess2s, tvec const s_lh, tvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec2 tfunc(ijkVecGreater2s, tvec const s_lh, tvec2 const v_rh);

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

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
tvec3 tfunc(ijkVecInit3);

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
tvec3 tfunc(ijkVecInitElems3, tvec const x, tvec const y, tvec const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
tvec3 tfunc(ijkVecCopy3, tvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
tvec3 tfunc(ijkVecNegate3, tvec3 const v_in);

// ijkVecBitNot3*
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
tvec3 tfunc(ijkVecBitNot3, tvec3 const v_in);

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
bvec3 tfunc(ijkVecNot3, tvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecAdd3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecSub3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecMul3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecDiv3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecDivSafe3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise modulo of 3D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecMod3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise modulo of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecModSafe3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitAnd3*
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitAnd3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitNand3*
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNand3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitOr3*
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitOr3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitNor3*
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNor3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitXor3*
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitXor3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitNxor3*
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNxor3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitShiftLeft3*
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitShiftLeft3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecBitShiftRight3*
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitShiftRight3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecEqual3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecInequal3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecLessEqual3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecGreaterEqual3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecLess3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecGreater3, tvec3 const v_lh, tvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
tvec3 tfuncs(ijkVecCopy3, z, tvec2 const v_xy, tvec const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
tvec3 tfuncs(ijkVecCopy3, s, tvec const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
tvec3 tfuncs(ijkVecNegate3, s, tvec const s_in);

// ijkVecBitNot3*s
//	Calculate bitwise 'not' of 3D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitNot3, s, tvec const s_in);

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
bvec3 tfuncs(ijkVecNot3, s, tvec const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecAdd3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecSub3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecMul3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecDiv3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecDivSafe3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecMod3*s
//	Calculate modulo of 3D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecMod3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecModSafe3*s
//	Calculate modulo of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecModSafe3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitAnd3*s
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitAnd3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitNand3*s
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitNand3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitOr3*s
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitOr3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitNor3*s
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitNor3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitXor3*s
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitXor3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitNxor3*s
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitNxor3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitShiftLeft3*s
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitShiftLeft3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecBitShiftRight3*s
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec3 tfuncs(ijkVecBitShiftRight3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecEqual3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecInequal3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecLessEqual3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecGreaterEqual3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecLess3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec3 tfuncs(ijkVecGreater3, s, tvec3 const v_lh, tvec const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
tvec3 tfunc(ijkVecCopy3x, tvec const x, tvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecAdd3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecSub3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecMul3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecDiv3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecDivSafe3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecMod3s*
//	Calculate modulo of scalar by 3D vector components.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecMod3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate modulo of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecModSafe3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitAnd3s*
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitAnd3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitNand3s*
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNand3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitOr3s*
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitOr3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitNor3s*
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNor3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitXor3s*
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitXor3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitNxor3s*
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitNxor3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitShiftLeft3s*
//	Calculate bit shift left of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitShiftLeft3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecBitShiftRight3s*
//	Calculate bit shift right of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec3 tfunc(ijkVecBitShiftRight3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecEqual3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecInequal3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecLessEqual3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecGreaterEqual3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecLess3s, tvec const s_lh, tvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec3 tfunc(ijkVecGreater3s, tvec const s_lh, tvec3 const v_rh);

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

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
tvec4 tfunc(ijkVecInit4);

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
tvec4 tfunc(ijkVecInitElems4, tvec const x, tvec const y, tvec const z, tvec const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
tvec4 tfuncs(ijkVecCopy4x, w, tvec const x, tvec2 const v_yz, tvec const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
tvec4 tfuncs(ijkVecCopy4, 2, tvec2 const v_xy, tvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
tvec4 tfunc(ijkVecCopy4, tvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
tvec4 tfunc(ijkVecNegate4, tvec4 const v_in);

// ijkVecBitNot4*
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
tvec4 tfunc(ijkVecBitNot4, tvec4 const v_in);

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
bvec4 tfunc(ijkVecNot4, tvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecAdd4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecSub4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecMul4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecDiv4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecDivSafe4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise modulo of 4D vectors.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecMod4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise modulo of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise modulo
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecModSafe4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitAnd4*
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitAnd4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitNand4*
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNand4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitOr4*
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitOr4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitNor4*
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNor4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitXor4*
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitXor4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitNxor4*
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNxor4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitShiftLeft4*
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitShiftLeft4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecBitShiftRight4*
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitShiftRight4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecEqual4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecInequal4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecLessEqual4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecGreaterEqual4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecLess4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecGreater4, tvec4 const v_lh, tvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
tvec4 tfuncs(ijkVecCopy4, zw, tvec2 const v_xy, tvec const z, tvec const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
tvec4 tfuncs(ijkVecCopy4, w, tvec3 const v_xyz, tvec const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
tvec4 tfuncs(ijkVecCopy4, s, tvec const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
tvec4 tfuncs(ijkVecNegate4, s, tvec const s_in);

// ijkVecBitNot4*s
//	Calculate bitwise 'not' of 4D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitNot4, s, tvec const s_in);

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
bvec4 tfuncs(ijkVecNot4, s, tvec const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecAdd4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecSub4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecMul4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecDiv4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecDivSafe4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecMod4*s
//	Calculate modulo of 4D vector components by scalar.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecMod4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecModSafe4*s
//	Calculate modulo of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold modulo
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecModSafe4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitAnd4*s
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitAnd4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitNand4*s
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitNand4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitOr4*s
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitOr4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitNor4*s
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitNor4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitXor4*s
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitXor4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitNxor4*s
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitNxor4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitShiftLeft4*s
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitShiftLeft4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecBitShiftRight4*s
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
tvec4 tfuncs(ijkVecBitShiftRight4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecEqual4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecInequal4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecLessEqual4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecGreaterEqual4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecLess4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
bvec4 tfuncs(ijkVecGreater4, s, tvec4 const v_lh, tvec const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
tvec4 tfunc(ijkVecCopy4xy, tvec const x, tvec const y, tvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
tvec4 tfunc(ijkVecCopy4x, tvec const x, tvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecAdd4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecSub4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecMul4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecDiv4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecDivSafe4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecMod4s*
//	Calculate modulo of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecMod4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate modulo of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecModSafe4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitAnd4s*
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitAnd4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitNand4s*
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNand4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitOr4s*
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitOr4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitNor4s*
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNor4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitXor4s*
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitXor4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitNxor4s*
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitNxor4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitShiftLeft4s*
//	Calculate bit shift left of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitShiftLeft4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecBitShiftRight4s*
//	Calculate bit shift right of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
tvec4 tfunc(ijkVecBitShiftRight4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecEqual4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecInequal4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecLessEqual4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecGreaterEqual4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecLess4s, tvec const s_lh, tvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
bvec4 tfunc(ijkVecGreater4s, tvec const s_lh, tvec4 const v_rh);

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

#undef tsfx
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


#undef IJK_VECTORFUNC_TYPE
#undef _IJK_VECTORFUNC_H_
#endif	// !_IJK_VECTORFUNC_H_
#endif	// IJK_VECTORFUNC_TYPE