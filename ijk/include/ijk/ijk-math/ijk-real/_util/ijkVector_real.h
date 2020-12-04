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

	ijkVector_real.h
	Declarations for 32-bit real vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_REAL_H_
#define _IJK_VECTOR_REAL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
//real ijkVecAbs1rs(real const s);
#define ijkVecAbs1rs ijk_declrealfs(ijkVecAbs1,s)

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
//real ijkVecSgn1rs(real const s);
#define ijkVecSgn1rs ijk_declrealfs(ijkVecSgn1,s)

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
//real ijkVecDot1rs(real const s_lh, real const s_rh);
#define ijkVecDot1rs ijk_declrealfs(ijkVecDot1,s)

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
//real ijkVecLengthSq1rs(real const s);
#define ijkVecLengthSq1rs ijk_declrealfs(ijkVecLengthSq1,s)

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
//real ijkVecLength1rs(real const s);
#define ijkVecLength1rs ijk_declrealfs(ijkVecLength1,s)

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
//real ijkVecLengthSqInv1rs(real const s);
#define ijkVecLengthSqInv1rs ijk_declrealfs(ijkVecLengthSqInv1,s)

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
//real ijkVecLengthInv1rs(real const s);
#define ijkVecLengthSqInv1rs ijk_declrealfs(ijkVecLengthSqInv1,s)

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
//real ijkVecNormalize1rs(real const s);
#define ijkVecNormalize1rs ijk_declrealfs(ijkVecNormalize1,s)

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLength1rs(real const s, real* const length_out);
#define ijkVecNormalizeGetLength1rs ijk_declrealfs(ijkVecNormalizeGetLength1,s)

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLengthInv1rs(real const s, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv1rs ijk_declrealfs(ijkVecNormalizeGetLengthInv1,s)


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
//realv ijkVecPrv(realv v_out);
#define ijkVecPrv ijk_declrealfs(ijkVecP,v)


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit2rv(real2 v_out);
#define ijkVecInit2rv ijk_declrealfs(ijkVecInit2,v)

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
//realv ijkVecInitElems2rv(real2 v_out, real const x, real const y);
#define ijkVecInitElems2rv ijk_declrealfs(ijkVecInitElems2,v)

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy2rv(real2 v_out, real2 const v_in);
#define ijkVecCopy2rv ijk_declrealfs(ijkVecCopy2,v)

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate2rv(real2 v_out, real2 const v_in);
#define ijkVecNegate2rv ijk_declrealfs(ijkVecNegate2,v)

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot2rv(bool2 bv_out, real2 const v_in);
#define ijkVecNot2rv ijk_declrealfs(ijkVecNot2,v)

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecAdd2rv ijk_declrealfs(ijkVecAdd2,v)

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecSub2rv ijk_declrealfs(ijkVecSub2,v)

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecMul2rv ijk_declrealfs(ijkVecMul2,v)

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecDiv2rv ijk_declrealfs(ijkVecDiv2,v)

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecDivSafe2rv ijk_declrealfs(ijkVecDivSafe2,v)

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecMod2rv ijkVecMod2(ijkVecMod2,v)

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define ijkVecModSafe2rv ijk_declrealfs(ijkVecModSafe2,v)

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecEqual2rv ijk_declrealfs(ijkVecEqual2,v)

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecInequal2rv ijk_declrealfs(ijkVecInequal2,v)

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecLessEqual2rv ijk_declrealfs(ijkVecLessEqual2,v)

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecGreaterEqual2rv ijk_declrealfs(ijkVecGreaterEqual2,v)

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecLess2rv ijk_declrealfs(ijkVecLess2,v)

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecGreater2rv ijk_declrealfs(ijkVecGreater2,v)

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecAnd2rv ijk_declrealfs(ijkVecAnd2,v)

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecNand2rv ijk_declrealfs(ijkVecNand2,v)

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecOr2rv ijk_declrealfs(ijkVecOr2,v)

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define ijkVecNor2rv ijk_declrealfs(ijkVecNor2,v)

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy2rvs(real2 v_out, real const s_in);
#define ijkVecCopy2rvs ijk_declrealfs(ijkVecCopy2,vs)

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate2rvs(real2 v_out, real const s_in);
#define ijkVecNegate2rvs ijk_declrealfs(ijkVecNegate2,vs)

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot2rvs(bool2 bv_out, real const s_in);
#define ijkVecNot2rvs ijk_declrealfs(ijkVecNot2,vs)

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecAdd2rvs ijk_declrealfs(ijkVecAdd2,vs)

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecSub2rvs ijk_declrealfs(ijkVecSub2,vs)

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecMul2rvs ijk_declrealfs(ijkVecMul2,vs)

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecDiv2rvs ijk_declrealfs(ijkVecDiv2,vs)

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecDivSafe2rvs ijk_declrealfs(ijkVecDivSafe2,vs)

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecMod2rvs ijk_declrealfs(ijkVecMod2,vs)

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define ijkVecModSafe2rvs ijk_declrealfs(ijkVecModSafe2,vs)

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecEqual2rvs ijk_declrealfs(ijkVecEqual2,vs)

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecInequal2rvs ijk_declrealfs(ijkVecInequal2,vs)

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecLessEqual2rvs ijk_declrealfs(ijkVecLessEqual2,vs)

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecGreaterEqual2rvs ijk_declrealfs(ijkVecGreaterEqual2,vs)

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecLess2rvs ijk_declrealfs(ijkVecLess2,vs)

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecGreater2rvs ijk_declrealfs(ijkVecGreater2,vs)

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecAnd2rvs ijk_declrealfs(ijkVecAnd2,vs)

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecNand2rvs ijk_declrealfs(ijkVecNand2,vs)

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecOr2rvs ijk_declrealfs(ijkVecOr2,vs)

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define ijkVecNor2rvs ijk_declrealfs(ijkVecNor2,vs)

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecAdd2rsv ijk_declrealfs(ijkVecAdd2,sv)

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecSub2rsv ijk_declrealfs(ijkVecSub2,sv)

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecMul2rsv ijk_declrealfs(ijkVecMul2,sv)

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecDiv2rsv ijk_declrealfs(ijkVecDiv2,sv)

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecDivSafe2rsv ijk_declrealfs(ijkVecDivSafe2,sv)

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecMod2rsv ijk_declrealfs(ijkVecMod2,sv)

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define ijkVecModSafe2rsv ijk_declrealfs(ijkVecModSafe2,sv)

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecEqual2rsv ijk_declrealfs(ijkVecEqual2,sv)

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecInequal2rsv ijk_declrealfs(ijkVecInequal2,sv)

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecLessEqual2rsv ijk_declrealfs(ijkVecLessEqual2,sv)

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecGreaterEqual2rsv ijk_declrealfs(ijkVecGreaterEqual2,sv)

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecLess2rsv ijk_declrealfs(ijkVecLess2,sv)

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecGreater2rsv ijk_declrealfs(ijkVecGreater2,sv)

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecAnd2rsv ijk_declrealfs(ijkVecAnd2,sv)

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecNand2rsv ijk_declrealfs(ijkVecNand2,sv)

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecOr2rsv ijk_declrealfs(ijkVecOr2,sv)

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define ijkVecNor2rsv ijk_declrealfs(ijkVecNor2,sv)

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot2rv(real2 const v_lh, real2 const v_rh);
#define ijkVecDot2rv ijk_declrealfs(ijkVecDot2,v)

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
//real ijkVecCross2rv(real2 const v_lh, real2 const v_rh);
#define ijkVecCross2rv ijk_declrealfs(ijkVecCross2,v)


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit3rv(real3 v_out);
#define ijkVecInit3rv ijk_declrealfs(ijkVecInit3,v)

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
//realv ijkVecInitElems3rv(real3 v_out, real const x, real const y, real const z);
#define ijkVecInitElems3rv ijk_declrealfs(ijkVecInitElems3,v)

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy3rv(real3 v_out, real3 const v_in);
#define ijkVecCopy3rv ijk_declrealfs(ijkVecCopy3,v)

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate3rv(real3 v_out, real3 const v_in);
#define ijkVecNegate3rv ijk_declrealfs(ijkVecNegate3,v)

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot3rv(bool3 bv_out, real3 const v_in);
#define ijkVecNot3rv ijk_declrealfs(ijkVecNot3,v)

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecAdd3rv ijk_declrealfs(ijkVecAdd3,v)

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecSub3rv ijk_declrealfs(ijkVecSub3,v)

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecMul3rv ijk_declrealfs(ijkVecMul3,v)

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecDiv3rv ijk_declrealfs(ijkVecDiv3,v)

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecDivSafe3rv ijk_declrealfs(ijkVecDivSafe3,v)

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecMod3rv ijk_declrealfs(ijkVecMod3,v)

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecModSafe3rv ijk_declrealfs(ijkVecModSafe3,v)

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecEqual3rv ijk_declrealfs(ijkVecEqual3,v)

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecInequal3rv ijk_declrealfs(ijkVecInequal3,v)

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecLessEqual3rv ijk_declrealfs(ijkVecLessEqual3,v)

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecGreaterEqual3rv ijk_declrealfs(ijkVecGreaterEqual3,v)

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecLess3rv ijk_declrealfs(ijkVecLess3,v)

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecGreater3rv ijk_declrealfs(ijkVecGreater3,v)

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecAnd3rv ijk_declrealfs(ijkVecAnd3,v)

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecNand3rv ijk_declrealfs(ijkVecNand3,v)

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecOr3rv ijk_declrealfs(ijkVecOr3,v)

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define ijkVecNor3rv ijk_declrealfs(ijkVecNor3,v)

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
//realv ijkVecCopy3rvz(real3 v_out, real2 const v_xy, real const z);
#define ijkVecCopy3rvz ijk_declrealfs(ijkVecCopy3,vz)

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy3rvs(real3 v_out, real const s_in);
#define ijkVecCopy3rvs ijk_declrealfs(ijkVecCopy3,vs)

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate3rvs(real3 v_out, real const s_in);
#define ijkVecNegate3rvs ijk_declrealfs(ijkVecNegate3,vs)

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot3rvs(bool3 bv_out, real const s_in);
#define ijkVecNot3rvs ijk_declrealfs(ijkVecNot3,vs)

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecAdd3rvs ijk_declrealfs(ijkVecAdd3,vs)

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecSub3rvs ijk_declrealfs(ijkVecSub3,vs)

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecMul3rvs ijk_declrealfs(ijkVecMul3,vs)

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecDiv3rvs ijk_declrealfs(ijkVecDiv3,vs)

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecDivSafe3rvs ijk_declrealfs(ijkVecDivSafe3,vs)

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecMod3rvs ijk_declrealfs(ijkVecMod3,vs)

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define ijkVecModSafe3rvs ijk_declrealfs(ijkVecModSafe3,vs)

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecEqual3rvs ijk_declrealfs(ijkVecEqual3,vs)

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecInequal3rvs ijk_declrealfs(ijkVecInequal3,vs)

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecLessEqual3rvs ijk_declrealfs(ijkVecLessEqual3,vs)

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecGreaterEqual3rvs ijk_declrealfs(ijkVecGreaterEqual3,vs)

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecLess3rvs ijk_declrealfs(ijkVecLess3,vs)

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecGreater3rvs ijk_declrealfs(ijkVecGreater3,vs)

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecAnd3rvs ijk_declrealfs(ijkVecAnd3,vs)

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecNand3rvs ijk_declrealfs(ijkVecNand3,vs)

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecOr3rvs ijk_declrealfs(ijkVecOr3,vs)

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define ijkVecNor3rvs ijk_declrealfs(ijkVecNor3,vs)

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy3rxv(real3 v_out, real const x, real2 const v_yz);
#define ijkVecCopy3rxv ijk_declrealfs(ijkVecCopy3,xv)

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecAdd3rsv ijk_declrealfs(ijkVecAdd3,sv)

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecSub3rsv ijk_declrealfs(ijkVecSub3,sv)

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecMul3rsv ijk_declrealfs(ijkVecMul3,sv)

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecDiv3rsv ijk_declrealfs(ijkVecDiv3,sv)

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecDivSafe3rsv ijk_declrealfs(ijkVecDivSafe3,sv)

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecMod3rsv ijk_declrealfs(ijkVecMod3,sv)

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define ijkVecModSafe3rsv ijk_declrealfs(ijkVecModSafe3,sv)

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecEqual3rsv ijk_declrealfs(ijkVecEqual3,sv)

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecInequal3rsv ijk_declrealfs(ijkVecInequal3,sv)

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecLessEqual3rsv ijk_declrealfs(ijkVecLessEqual3,sv)

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecGreaterEqual3rsv ijk_declrealfs(ijkVecGreaterEqual3,sv)

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecLess3rsv ijk_declrealfs(ijkVecLess3,sv)

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecGreater3rsv ijk_declrealfs(ijkVecGreater3,sv)

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecAnd3rsv ijk_declrealfs(ijkVecAnd3,sv)

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecNand3rsv ijk_declrealfs(ijkVecNand3,sv)

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecOr3rsv ijk_declrealfs(ijkVecOr3,sv)

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define ijkVecNor3rsv ijk_declrealfs(ijkVecNor3,sv)

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot3rv(real3 const v_lh, real3 const v_rh);
#define ijkVecDot3rv ijk_declrealfs(ijkVecDot3,v)

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCross3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecCross3rv ijk_declrealfs(ijkVecCross3,v)


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit4rv(real4 v_out);
#define ijkVecInit4rv ijk_declrealfs(ijkVecInit4,v)

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecInitElems4rv(real4 v_out, real const x, real const y, real const z, real const w);
#define ijkVecInitElems4rv ijk_declrealfs(ijkVecInitElems4,v)

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4rxvw(real4 v_out, real const x, real2 const v_yz, real const w);
#define ijkVecCopy4rxvw ijk_declrealfs(ijkVecCopy4,xvw)

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy4rv2(real4 v_out, real2 const v_xy, real2 const v_zw);
#define ijkVecCopy4rv2 ijk_declrealfs(ijkVecCopy4,v2)

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy4rv(real4 v_out, real4 const v_in);
#define ijkVecCopy4rv ijk_declrealfs(ijkVecCopy4,v)

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate4rv(real4 v_out, real4 const v_in);
#define ijkVecNegate4rv ijk_declrealfs(ijkVecNegate4,v)

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot4rv(bool4 bv_out, real4 const v_in);
#define ijkVecNot4rv ijk_declrealfs(ijkVecNot4,v)

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecAdd4rv ijk_declrealfs(ijkVecAdd4,v)

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecSub4rv ijk_declrealfs(ijkVecSub4,v)

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecMul4rv ijk_declrealfs(ijkVecMul4,v)

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecDiv4rv ijk_declrealfs(ijkVecDiv4,v)

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecDivSafe4rv ijk_declrealfs(ijkVecDivSafe4,v)

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecMod4rv ijk_declrealfs(ijkVecMod4,v)

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecModSafe4rv ijk_declrealfs(ijkVecModSafe4,v)

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecEqual4rv ijk_declrealfs(ijkVecEqual4,v)

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecInequal4rv ijk_declrealfs(ijkVecInequal4,v)

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecLessEqual4rv ijk_declrealfs(ijkVecLessEqual4,v)

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecGreaterEqual4rv ijk_declrealfs(ijkVecGreaterEqual4,v)

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecLess4rv ijk_declrealfs(ijkVecLess4,v)

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecGreater4rv ijk_declrealfs(ijkVecGreater4,v)

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecAnd4rv ijk_declrealfs(ijkVecAnd4,v)

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecNand4rv ijk_declrealfs(ijkVecNand4,v)

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecOr4rv ijk_declrealfs(ijkVecOr4,v)

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define ijkVecNor4rv ijk_declrealfs(ijkVecNor4,v)

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4rvzw(real4 v_out, real2 const v_xy, real const z, real const w);
#define ijkVecCopy4rvzw ijk_declrealfs(ijkVecCopy4,vzw)

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4rvw(real4 v_out, real3 const v_xyz, real const w);
#define ijkVecCopy4rvw ijk_declrealfs(ijkVecCopy4,vw)

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy4rvs(real4 v_out, real const s_in);
#define ijkVecCopy4rvs ijk_declrealfs(ijkVecCopy4,vs)

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate4rvs(real4 v_out, real const s_in);
#define ijkVecNegate4rvs ijk_declrealfs(ijkVecNegate4,vs)

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot4rvs(bool4 bv_out, real const s_in);
#define ijkVecNot4rvs ijk_declrealfs(ijkVecNot4,vs)

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecAdd4rvs ijk_declrealfs(ijkVecAdd4,vs)

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecSub4rvs ijk_declrealfs(ijkVecSub4,vs)

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecMul4rvs ijk_declrealfs(ijkVecMul4,vs)

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecDiv4rvs ijk_declrealfs(ijkVecDiv4,vs)

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecDivSafe4rvs ijk_declrealfs(ijkVecDivSafe4,vs)

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecMod4rvs ijk_declrealfs(ijkVecMod4,vs)

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define ijkVecModSafe4rvs ijk_declrealfs(ijkVecModSafe4,vs)

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecEqual4rvs ijk_declrealfs(ijkVecEqual4,vs)

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecInequal4rvs ijk_declrealfs(ijkVecInequal4,vs)

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecLessEqual4rvs ijk_declrealfs(ijkVecLessEqual4,vs)

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecGreaterEqual4rvs ijk_declrealfs(ijkVecGreaterEqual4,vs)

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecLess4rvs ijk_declrealfs(ijkVecLess4,vs)

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecGreater4rvs ijk_declrealfs(ijkVecGreater4,vs)

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecAnd4rvs ijk_declrealfs(ijkVecAnd4r,vs)

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecNand4rvs ijk_declrealfs(ijkVecNand4,vs)

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecOr4rvs ijk_declrealfs(ijkVecOr4,vs)

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define ijkVecNor4rvs ijk_declrealfs(ijkVecNor4,vs)

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy4rxyv(real4 v_out, real const x, real const y, real2 const v_zw);
#define ijkVecCopy4rxyv ijk_declrealfs(ijkVecCopy4,xyv)

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
//realv ijkVecCopy4rxv(real4 v_out, real const x, real3 const v_yzw);
#define ijkVecCopy4rxv ijk_declrealfs(ijkVecCopy4,xv)

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecAdd4rsv ijk_declrealfs(ijkVecAdd4,sv)

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecSub4rsv ijk_declrealfs(ijkVecSub4,sv)

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecMul4rsv ijk_declrealfs(ijkVecMul4,sv)

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecDiv4rsv ijk_declrealfs(ijkVecDiv4,sv)

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecDivSafe4rsv ijk_declrealfs(ijkVecDivSafe4,sv)

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecMod4rsv ijk_declrealfs(ijkVecMod4,sv)

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define ijkVecModSafe4rsv ijk_declrealfs(ijkVecModSafe4,sv)

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecEqual4rsv ijk_declrealfs(ijkVecEqual4,sv)

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecInequal4rsv ijk_declrealfs(ijkVecInequal4,sv)

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecLessEqual4rsv ijk_declrealfs(ijkVecLessEqual4,sv)

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecGreaterEqual4rsv ijk_declrealfs(ijkVecGreaterEqual4,sv)

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecLess4rsv ijk_declrealfs(ijkVecLess4,sv)

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecGreater4rsv ijk_declrealfs(ijkVecGreater4,sv)

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecAnd4rsv ijk_declrealfs(ijkVecAnd4,sv)

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecNand4rsv ijk_declrealfs(ijkVecNand4,sv)

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecOr4rsv ijk_declrealfs(ijkVecOr4,sv)

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define ijkVecNor4rsv ijk_declrealfs(ijkVecNor4,sv)

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot4rv(real4 const v_lh, real4 const v_rh);
#define ijkVecDot4rv ijk_declrealfs(ijkVecDot4,v)

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
//realv ijkVecCross4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecCross4rv ijk_declrealfs(ijkVecCross4,v)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
//real ijkVecAbs1r(real const s);
#define ijkVecAbs1r ijk_declrealfs(ijkVecAbs1,)

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
//real ijkVecSgn1r(real const s);
#define ijkVecSgn1r ijk_declrealfs(ijkVecSgn1,)

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
//real ijkVecDot1r(real const s_lh, real const s_rh);
#define ijkVecDot1r ijk_declrealfs(ijkVecDot1,)

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
//real ijkVecLengthSq1r(real const s);
#define ijkVecLengthSq1r ijk_declrealfs(ijkVecLengthSq1,)

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
//real ijkVecLength1r(real const s);
#define ijkVecLength1r ijk_declrealfs(ijkVecLength1,)

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
//real ijkVecLengthSqInv1r(real const s);
#define ijkVecLengthSqInv1r ijk_declrealfs(ijkVecLengthSqInv1,)

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
//real ijkVecLengthInv1r(real const s);
#define ijkVecLengthSqInv1r ijk_declrealfs(ijkVecLengthSqInv1,)

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
//real ijkVecNormalize1r(real const s);
#define ijkVecNormalize1r ijk_declrealfs(ijkVecNormalize1,)

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLength1r(real const s, real* const length_out);
#define ijkVecNormalizeGetLength1r ijk_declrealfs(ijkVecNormalizeGetLength1,)

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLengthInv1r(real const s, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv1r ijk_declrealfs(ijkVecNormalizeGetLengthInv1,)


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
//rvec2 ijkVecInit2r();
#define ijkVecInit2r ijk_declrealfs(ijkVecInit2,)

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
//rvec2 ijkVecInitElems2r(real const x, real const y);
#define ijkVecInitElems2r ijk_declrealfs(ijkVecInitElems2,)

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec2 ijkVecCopy2r(rvec2 const v_in);
#define ijkVecCopy2r ijk_declrealfs(ijkVecCopy2,)

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
//rvec2 ijkVecNegate2r(rvec2 const v_in);
#define ijkVecNegate2r ijk_declrealfs(ijkVecNegate2,)

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec2 ijkVecNot2r(rvec2 const v_in);
#define ijkVecNot2r ijk_declrealfs(ijkVecNot2,)

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecAdd2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecAdd2r ijk_declrealfs(ijkVecAdd2,)

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecSub2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecSub2r ijk_declrealfs(ijkVecSub2,)

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMul2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecMul2r ijk_declrealfs(ijkVecMul2,)

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDiv2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecDiv2r ijk_declrealfs(ijkVecDiv2,)

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDivSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecDivSafe2r ijk_declrealfs(ijkVecDivSafe2,)

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMod2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecMod2r ijk_declrealfs(ijkVecMod2,)

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecModSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecModSafe2r ijk_declrealfs(ijkVecModSafe2,)

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecEqual2r ijk_declrealfs(ijkVecEqual2,)

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecInequal2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecInequal2r ijk_declrealfs(ijkVecInequal2,)

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLessEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecLessEqual2r ijk_declrealfs(ijkVecLessEqual2,)

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecGreaterEqual2r ijk_declrealfs(ijkVecGreaterEqual2,)

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLess2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecLess2r ijk_declrealfs(ijkVecLess2,)

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreater2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecGreater2r ijk_declrealfs(ijkVecGreater2,)

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecAnd2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecAnd2r ijk_declrealfs(ijkVecAnd2,)

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNand2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecNand2r ijk_declrealfs(ijkVecNand2,)

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecOr2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecOr2r ijk_declrealfs(ijkVecOr2,)

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNor2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecNor2r ijk_declrealfs(ijkVecNor2,)

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec2 ijkVecCopy2rs(real const s_in);
#define ijkVecCopy2rs ijk_declrealfs(ijkVecCopy2,s)

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
//rvec2 ijkVecNegate2rs(real const s_in);
#define ijkVecNegate2rs ijk_declrealfs(ijkVecNegate2,s)

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec2 ijkVecNot2rs(real const s_in);
#define ijkVecNot2rs ijk_declrealfs(ijkVecNot2,s)

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecAdd2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecAdd2rs ijk_declrealfs(ijkVecAdd2,s)

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecSub2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecSub2rs ijk_declrealfs(ijkVecSub2,s)

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecMul2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecMul2rs ijk_declrealfs(ijkVecMul2,s)

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecDiv2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecDiv2rs ijk_declrealfs(ijkVecDiv2,s)

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecDivSafe2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecDivSafe2rs ijk_declrealfs(ijkVecDivSafe2,s)

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecMod2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecMod2rs ijk_declrealfs(ijkVecMod2,s)

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecModSafe2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecModSafe2rs ijk_declrealfs(ijkVecModSafe2,s)

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecEqual2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecEqual2rs ijk_declrealfs(ijkVecEqual2,s)

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecInequal2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecInequal2rs ijk_declrealfs(ijkVecInequal2,s)

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecLessEqual2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecLessEqual2rs ijk_declrealfs(ijkVecLessEqual2,s)

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecGreaterEqual2rs ijk_declrealfs(ijkVecGreaterEqual2,s)

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecLess2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecLess2rs ijk_declrealfs(ijkVecLess2,s)

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecGreater2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecGreater2rs ijk_declrealfs(ijkVecGreater2,s)

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecAnd2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecAnd2rs ijk_declrealfs(ijkVecAnd2,s)

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecNand2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecNand2rs ijk_declrealfs(ijkVecNand2,s)

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecOr2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecOr2rs ijk_declrealfs(ijkVecOr2,s)

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecNor2rs(rvec2 const v_lh, real const s_rh);
#define ijkVecNor2rs ijk_declrealfs(ijkVecNor2,s)

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecAdd2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecAdd2sr ijk_declrealfs(ijkVecAdd2s,)

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecSub2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecSub2sr ijk_declrealfs(ijkVecSub2s,)

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMul2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecMul2sr ijk_declrealfs(ijkVecMul2s,)

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDiv2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecDiv2sr ijk_declrealfs(ijkVecDiv2s,)

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDivSafe2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecDivSafe2sr ijk_declrealfs(ijkVecDivSafe2s,)

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMod2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecMod2sr ijk_declrealfs(ijkVecMod2s,)

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecModSafe2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecModSafe2sr ijk_declrealfs(ijkVecModSafe2s,)

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecEqual2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecEqual2sr ijk_declrealfs(ijkVecEqual2s,)

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecInequal2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecInequal2sr ijk_declrealfs(ijkVecInequal2s,)

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLessEqual2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecLessEqual2sr ijk_declrealfs(ijkVecLessEqual2s,)

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecGreaterEqual2sr ijk_declrealfs(ijkVecGreaterEqual2s,)

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLess2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecLess2sr ijk_declrealfs(ijkVecLess2s,)

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreater2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecGreater2sr ijk_declrealfs(ijkVecGreater2s,)

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecAnd2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecAnd2sr ijk_declrealfs(ijkVecAnd2s,)

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNand2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecNand2sr ijk_declrealfs(ijkVecNand2s,)

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecOr2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecOr2sr ijk_declrealfs(ijkVecOr2s,)

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNor2sr(real const s_lh, rvec2 const v_rh);
#define ijkVecNor2sr ijk_declrealfs(ijkVecNor2s,)

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecDot2r ijk_declrealfs(ijkVecDot2,)

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
//real ijkVecCross2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecCross2r ijk_declrealfs(ijkVecCross2,)


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
//rvec3 ijkVecInit3r();
#define ijkVecInit3r ijk_declrealfs(ijkVecInit3,)

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
//rvec3 ijkVecInitElems3r(real const x, real const y, real const z);
#define ijkVecInitElems3r ijk_declrealfs(ijkVecInitElems3,)

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec3 ijkVecCopy3r(rvec3 const v_in);
#define ijkVecCopy3r ijk_declrealfs(ijkVecCopy3,)

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
//rvec3 ijkVecNegate3r(rvec3 const v_in);
#define ijkVecNegate3r ijk_declrealfs(ijkVecNegate3,)

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec3 ijkVecNot3r(rvec3 const v_in);
#define ijkVecNot3r ijk_declrealfs(ijkVecNot3,)

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecAdd3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecAdd3r ijk_declrealfs(ijkVecAdd3,)

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecSub3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecSub3r ijk_declrealfs(ijkVecSub3,)

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMul3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecMul3r ijk_declrealfs(ijkVecMul3,)

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDiv3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecDiv3r ijk_declrealfs(ijkVecDiv3,)

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDivSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecDivSafe3r ijk_declrealfs(ijkVecDivSafe3,)

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMod3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecMod3r ijk_declrealfs(ijkVecMod3,)

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecModSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecModSafe3r ijk_declrealfs(ijkVecModSafe3,)

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecEqual3r ijk_declrealfs(ijkVecEqual3,)

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecInequal3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecInequal3r ijk_declrealfs(ijkVecInequal3,)

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLessEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecLessEqual3r ijk_declrealfs(ijkVecLessEqual3,)

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecGreaterEqual3r ijk_declrealfs(ijkVecGreaterEqual3,)

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLess3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecLess3r ijk_declrealfs(ijkVecLess3,)

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreater3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecGreater3r ijk_declrealfs(ijkVecGreater3,)

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecAnd3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecAnd3r ijk_declrealfs(ijkVecAnd3,)

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNand3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecNand3r ijk_declrealfs(ijkVecNand3,)

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecOr3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecOr3r ijk_declrealfs(ijkVecOr3,)

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNor3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecNor3r ijk_declrealfs(ijkVecNor3,)

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
//rvec3 ijkVecCopy3rz(rvec2 const v_xy, real const z);
#define ijkVecCopy3rz ijk_declrealfs(ijkVecCopy3,z)

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec3 ijkVecCopy3rs(real const s_in);
#define ijkVecCopy3rs ijk_declrealfs(ijkVecCopy3,s)

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
//rvec3 ijkVecNegate3rs(real const s_in);
#define ijkVecNegate3rs ijk_declrealfs(ijkVecNegate3,s)

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec3 ijkVecNot3rs(real const s_in);
#define ijkVecNot3rs ijk_declrealfs(ijkVecNot3,s)

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecAdd3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecAdd3rs ijk_declrealfs(ijkVecAdd3,s)

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecSub3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecSub3rs ijk_declrealfs(ijkVecSub3,s)

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecMul3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecMul3rs ijk_declrealfs(ijkVecMul3,s)

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecDiv3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecDiv3rs ijk_declrealfs(ijkVecDiv3,s)

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecDivSafe3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecDivSafe3rs ijk_declrealfs(ijkVecDivSafe3,s)

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecMod3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecMod3rs ijk_declrealfs(ijkVecMod3,s)

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecModSafe3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecModSafe3rs ijk_declrealfs(ijkVecModSafe3,s)

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecEqual3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecEqual3rs ijk_declrealfs(ijkVecEqual3,s)

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecInequal3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecInequal3rs ijk_declrealfs(ijkVecInequal3,s)

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecLessEqual3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecLessEqual3rs ijk_declrealfs(ijkVecLessEqual3,s)

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecGreaterEqual3rs ijk_declrealfs(ijkVecGreaterEqual3,s)

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecLess3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecLess3rs ijk_declrealfs(ijkVecLess3,s)

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecGreater3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecGreater3rs ijk_declrealfs(ijkVecGreater3,s)

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecAnd3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecAnd3rs ijk_declrealfs(ijkVecAnd3,s)

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecNand3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecNand3rs ijk_declrealfs(ijkVecNand3,s)

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecOr3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecOr3rs ijk_declrealfs(ijkVecOr3,s)

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecNor3rs(rvec3 const v_lh, real const s_rh);
#define ijkVecNor3rs ijk_declrealfs(ijkVecNor3,s)

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
//rvec3 ijkVecCopy3xr(real const x, rvec2 const v_yz);
#define ijkVecCopy3xr ijk_declrealfs(ijkVecCopy3x,)

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecAdd3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecAdd3sr ijk_declrealfs(ijkVecAdd3s,)

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecSub3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecSub3sr ijk_declrealfs(ijkVecSub3s,)

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMul3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecMul3sr ijk_declrealfs(ijkVecMul3s,)

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDiv3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecDiv3sr ijk_declrealfs(ijkVecDiv3s,)

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDivSafe3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecDivSafe3sr ijk_declrealfs(ijkVecDivSafe3s,)

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMod3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecMod3sr ijk_declrealfs(ijkVecMod3s,)

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecModSafe3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecModSafe3sr ijk_declrealfs(ijkVecModSafe3s,)

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecEqual3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecEqual3sr ijk_declrealfs(ijkVecEqual3s,)

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecInequal3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecInequal3sr ijk_declrealfs(ijkVecInequal3s,)

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLessEqual3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecLessEqual3sr ijk_declrealfs(ijkVecLessEqual3s,)

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecGreaterEqual3sr ijk_declrealfs(ijkVecGreaterEqual3s,)

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLess3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecLess3sr ijk_declrealfs(ijkVecLess3s,)

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreater3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecGreater3sr ijk_declrealfs(ijkVecGreater3s,)

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecAnd3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecAnd3sr ijk_declrealfs(ijkVecAnd3s,)

// ijkVecAnd3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNand3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecAnd3sr ijk_declrealfs(ijkVecAnd3s,)

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecOr3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecOr3sr ijk_declrealfs(ijkVecOr3s,)

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNor3sr(real const s_lh, rvec3 const v_rh);
#define ijkVecNor3sr ijk_declrealfs(ijkVecNor3s,)

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecDot3r ijk_declrealfs(ijkVecDot3,)

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
//rvec3 ijkVecCross3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecCross3r ijk_declrealfs(ijkVecCross3,)


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
//rvec4 ijkVecInit4r();
#define ijkVecInit4r ijk_declrealfs(ijkVecInit4,)

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecInitElems4r(real const x, real const y, real const z, real const w);
#define ijkVecInitElems4r ijk_declrealfs(ijkVecInitElems4,)

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4xrw(real const x, rvec2 const v_yz, real const w);
#define ijkVecCopy4xrw ijk_declrealfs(ijkVecCopy4x,w)

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
//rvec4 ijkVecCopy4r2(rvec2 const v_xy, rvec2 const v_zw);
#define ijkVecCopy4r2 ijk_declrealfs(ijkVecCopy4,2)

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec4 ijkVecCopy4r(rvec4 const v_in);
#define ijkVecCopy4r ijk_declrealfs(ijkVecCopy4,)

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
//rvec4 ijkVecNegate4r(rvec4 const v_in);
#define ijkVecNegate4r ijk_declrealfs(ijkVecNegate4,)

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec4 ijkVecNot4r(rvec4 const v_in);
#define ijkVecNot4r ijk_declrealfs(ijkVecNot4,)

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecAdd4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecAdd4r ijk_declrealfs(ijkVecAdd4,)

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecSub4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecSub4r ijk_declrealfs(ijkVecSub4,)

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMul4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecMul4r ijk_declrealfs(ijkVecMul4,)

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDiv4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecDiv4r ijk_declrealfs(ijkVecDiv4,)

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDivSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecDivSafe4r ijk_declrealfs(ijkVecDivSafe4,)

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMod4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecMod4r ijk_declrealfs(ijkVecMod4,)

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecModSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecModSafe4r ijk_declrealfs(ijkVecModSafe4,)

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecEqual4r ijk_declrealfs(ijkVecEqual4,)

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecInequal4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecInequal4r ijk_declrealfs(ijkVecInequal4,)

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLessEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecLessEqual4r ijk_declrealfs(ijkVecLessEqual4,)

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecGreaterEqual4r ijk_declrealfs(ijkVecGreaterEqual4,)

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLess4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecLess4r ijk_declrealfs(ijkVecLess4,)

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreater4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecGreater4r ijk_declrealfs(ijkVecGreater4,)

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecAnd4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecAnd4r ijk_declrealfs(ijkVecAnd4,)

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNand4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecNand4r ijk_declrealfs(ijkVecNand4,)

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecOr4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecOr4r ijk_declrealfs(ijkVecOr4,)

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNor4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecNor4r ijk_declrealfs(ijkVecNor4,)

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4rzw(rvec2 const v_xy, real const z, real const w);
#define ijkVecCopy4rzw ijk_declrealfs(ijkVecCopy4,zw)

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4rw(rvec3 const v_xyz, real const w);
#define ijkVecCopy4rw ijk_declrealfs(ijkVecCopy4,w)

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec4 ijkVecCopy4rs(real const s_in);
#define ijkVecCopy4rs ijk_declrealfs(ijkVecCopy4,s)

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
//rvec4 ijkVecNegate4rs(real const s_in);
#define ijkVecNegate4rs ijk_declrealfs(ijkVecNegate4,s)

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec4 ijkVecNot4rs(real const s_in);
#define ijkVecNot4rs ijk_declrealfs(ijkVecNot4,s)

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecAdd4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecAdd4rs ijk_declrealfs(ijkVecAdd4,s)

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecSub4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecSub4rs ijk_declrealfs(ijkVecSub4,s)

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecMul4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecMul4rs ijk_declrealfs(ijkVecMul4,s)

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecDiv4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecDiv4rs ijk_declrealfs(ijkVecDiv4,s)

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecDivSafe4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecDivSafe4rs ijk_declrealfs(ijkVecDivSafe4,s)

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecMod4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecMod4rs ijk_declrealfs(ijkVecMod4,s)

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecModSafe4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecModSafe4rs ijk_declrealfs(ijkVecModSafe4,s)

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecEqual4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecEqual4rs ijk_declrealfs(ijkVecEqual4,s)

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecInequal4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecInequal4rs ijk_declrealfs(ijkVecInequal4,s)

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecLessEqual4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecLessEqual4rs ijk_declrealfs(ijkVecLessEqual4,s)

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecGreaterEqual4rs ijk_declrealfs(ijkVecGreaterEqual4,s)

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecLess4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecLess4rs ijk_declrealfs(ijkVecLess4,s)

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecGreater4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecGreater4rs ijk_declrealfs(ijkVecGreater4,s)

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecAnd4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecAnd4rs ijk_declrealfs(ijkVecAnd4,s)

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecNand4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecNand4rs ijk_declrealfs(ijkVecNand4,s)

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecOr4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecOr4rs ijk_declrealfs(ijkVecOr4,s)

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecNor4rs(rvec4 const v_lh, real const s_rh);
#define ijkVecNor4rs ijk_declrealfs(ijkVecNor4,s)

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
//rvec4 ijkVecCopy4xyr(real const x, real const y, rvec2 const v_zw);
#define ijkVecCopy4xyr ijk_declrealfs(ijkVecCopy4xy,)

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
//rvec4 ijkVecCopy4xr(real const x, rvec3 const v_yzw);
#define ijkVecCopy4xr ijk_declrealfs(ijkVecCopy4x,)

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecAdd4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecAdd4sr ijk_declrealfs(ijkVecAdd4s,)

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecSub4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecSub4sr ijk_declrealfs(ijkVecSub4s,)

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMul4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecMul4sr ijk_declrealfs(ijkVecMul4s,)

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDiv4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecDiv4sr ijk_declrealfs(ijkVecDiv4s,)

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDivSafe4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecDivSafe4sr ijk_declrealfs(ijkVecDivSafe4s,)

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMod4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecMod4sr ijk_declrealfs(ijkVecMod4s,)

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecModSafe4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecModSafe4sr ijk_declrealfs(ijkVecModSafe4s,)

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecEqual4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecEqual4sr ijk_declrealfs(ijkVecEqual4s,)

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecInequal4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecInequal4sr ijk_declrealfs(ijkVecInequal4s,)

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLessEqual4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecLessEqual4sr ijk_declrealfs(ijkVecLessEqual4s,)

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecGreaterEqual4sr ijk_declrealfs(ijkVecGreaterEqual4s,)

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLess4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecLess4sr ijk_declrealfs(ijkVecLess4s,)

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreater4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecGreater4sr ijk_declrealfs(ijkVecGreater4s,)

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecAnd4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecAnd4sr ijk_declrealfs(ijkVecAnd4s,)

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNand4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecNand4sr ijk_declrealfs(ijkVecNand4s,)

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecOr4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecOr4sr ijk_declrealfs(ijkVecOr4s,)

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNor4sr(real const s_lh, rvec4 const v_rh);
#define ijkVecNor4sr ijk_declrealfs(ijkVecNor4s,)

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecDot4r ijk_declrealfs(ijkVecDot4,)

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
//rvec4 ijkVecCross4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecCross4r ijk_declrealfs(ijkVecCross4,)


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq2rv(real2 const v_in);
#define ijkVecLengthSq2rv ijk_declrealfs(ijkVecLengthSq2,v)

// ijkVecLength2*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength2rv(real2 const v_in);
#define ijkVecLength2rv ijk_declrealfs(ijkVecLength2,v)

// ijkVecLengthSqInv2*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv2rv(real2 const v_in);
#define ijkVecLengthSqInv2rv ijk_declrealfs(ijkVecLengthSqInv2,v)

// ijkVecLengthSqInvSafe2*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe2rv(real2 const v_in);
#define ijkVecLengthSqInvSafe2rv ijk_declrealfs(ijkVecLengthSqInvSafe2,v)

// ijkVecLengthInv2*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv2rv(real2 const v_in);
#define ijkVecLengthInv2rv ijk_declrealfs(ijkVecLengthInv2,v)

// ijkVecLengthInvSafe2*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe2rv(real2 const v_in);
#define ijkVecLengthInvSafe2rv ijk_declrealfs(ijkVecLengthInvSafe2,v)

// ijkVecNormalize2*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize2rv(real2 v_out, real2 const v_in);
#define ijkVecNormalize2rv ijk_declrealfs(ijkVecNormalize2,v)

// ijkVecNormalizeSafe2*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe2rv(real2 v_out, real2 const v_in);
#define ijkVecNormalizeSafe2rv ijk_declrealfs(ijkVecNormalizeSafe2,v)

// ijkVecNormalizeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength2rv(real2 v_out, real2 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength2rv ijk_declrealfs(ijkVecNormalizeGetLength2,v)

// ijkVecNormalizeSafeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength2rv(real2 v_out, real2 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength2rv ijk_declrealfs(ijkVecNormalizeSafeGetLength2,v)

// ijkVecNormalizeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv2rv(real2 v_out, real2 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv2rv ijk_declrealfs(ijkVecNormalizeGetLengthInv2,v)

// ijkVecNormalizeSafeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv2rv(real2 v_out, real2 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv2rv ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv2,v)

// ijkVecCrossNormalize2*v
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalize2rv(real2 const v_lh, real2 const v_rh);
#define ijkVecCrossNormalize2rv ijk_declrealfs(ijkVecCrossNormalize2,v)

// ijkVecCrossNormalizeSafe2*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafe2rv(real2 const v_lh, real2 const v_rh);
#define ijkVecCrossNormalizeSafe2rv ijk_declrealfs(ijkVecCrossNormalizeSafe2,v)

// ijkVecCrossNormalizeGetLength2*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLength2rv(real2 const v_lh, real2 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength2rv ijk_declrealfs(ijkVecCrossNormalizeGetLength2,v)

// ijkVecCrossNormalizeSafeGetLength2*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLength2rv(real2 const v_lh, real2 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength2rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength2,v)

// ijkVecCrossNormalizeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLengthInv2rv(real2 const v_lh, real2 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv2rv ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv2,v)

// ijkVecCrossNormalizeSafeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLengthInv2rv(real2 const v_lh, real2 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv2rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv2,v)

// ijkVecLerp2*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define ijkVecLerp2rv ijk_declrealfs(ijkVecLerp2,v)

// ijkVecLerpInv2*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv2rv(real2 v_out, real2 const v0, real2 const v1, real2 const v_lerp);
#define ijkVecLerpInv2rv ijk_declrealfs(ijkVecLerpInv2,v)

// ijkVecLerpRevInit2*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit2rv(real2 v0_out, real2 const v_lerp, real2 const v1, real const u);
#define ijkVecLerpRevInit2rv ijk_declrealfs(ijkVecLerpRevInit2,v)

// ijkVecLerpRevTerm2*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm2rv(real2 v1_out, real2 const v0, real2 const v_lerp, real const u);
#define ijkVecLerpRevTerm2rv ijk_declrealfs(ijkVecLerpRevTerm2,v)

// ijkVecProjRatio2*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio2rv(real2 const v_base, real2 const v_in);
#define ijkVecProjRatio2rv ijk_declrealfs(ijkVecProjRatio2,v)

// ijkVecProj2*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj2rv(real2 v_out, real2 const v_base, real2 const v_in);
#define ijkVecProj2rv ijk_declrealfs(ijkVecProj2,v)

// ijkVecOrtho2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho2rv(real2 v_out, real2 const v_base, real2 const v_in);
#define ijkVecOrtho2rv ijk_declrealfs(ijkVecOrtho2,v)

// ijkVecOrthoNorm2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm2rv(real2 v_out, real2 const v_base, real2 const v_in, real2 v_base_norm_out);
#define ijkVecOrthoNorm2rv ijk_declrealfs(ijkVecOrthoNorm2,v)

// ijkVecOrthoList2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real2* ijkVecOrthoList2rv(real2 vl_out[], real2 const v_base, real2 const vl_in[], size const n);
#define ijkVecOrthoList2rv ijk_declrealfs(ijkVecOrthoList2,v)

// ijkVecOrthoNormList2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real2* ijkVecOrthoNormList2rv(real2 vl_out[], real2 const v_base, real2 const vl_in[], size const n, real2 v_base_norm_out);
#define ijkVecOrthoNormList2rv ijk_declrealfs(ijkVecOrthoNormList2,v)

// ijkVecNlerp2*v
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecNlerp2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define ijkVecNlerp2rv ijk_declrealfs(ijkVecNlerp2,v)

// ijkVecSlerp2*v
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecSlerp2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define ijkVecSlerp2rv ijk_declrealfs(ijkVecSlerp2,v)

// ijkVecReflectScale2*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflectScale2rv(real2 v_out, real2 const v_in, real2 const v_nrm);
#define ijkVecReflectScale2rv ijk_declrealfs(ijkVecReflectScale2,v)

// ijkVecUnitReflect2*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecUnitReflect2rv(real2 v_out, real2 const v_in, real2 const v_nrm);
#define ijkVecUnitReflect2rv ijk_declrealfs(ijkVecUnitReflect2,v)

// ijkVecReflect2*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflect2rv(real2 v_out, real2 const v_in, real2 const v_nrm);
#define ijkVecReflect2rv ijk_declrealfs(ijkVecReflect2,v)

// ijkVecDistance2*v
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance2rv(real2 const v_lh, real2 const v_rh);
#define ijkVecDistance2rv ijk_declrealfs(ijkVecDistance2,v)

// ijkVecResize2*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResize2rv(real2 v_out, real2 const v_in, real const length);
#define ijkVecDistance2rv ijk_declrealfs(ijkVecDistance2,v)

// ijkVecResizeSafe2*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResizeSafe2rv(real2 v_out, real2 const v_in, real const length);
#define ijkVecResizeSafe2rv ijk_declrealfs(ijkVecResizeSafe2,v)

// ijkVecCrossResize2*v
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
//real ijkVecCrossResize2rv(real2 const v_lh, real2 const v_rh, real const length);
#define ijkVecCrossResize2rv ijk_declrealfs(ijkVecCrossResize2,v)

// ijkVecCrossResizeSafe2*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
//real ijkVecCrossResizeSafe2rv(real2 const v_lh, real2 const v_rh, real const length);
#define ijkVecCrossResizeSafe2rv ijk_declrealfs(ijkVecCrossResizeSafe2,v)

// ijkVecNearest2*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
//realv ijkVecNearest2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define ijkVecNearest2rv ijk_declrealfs(ijkVecNearest2,v)

// ijkVecBinearest2*v
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v_out: output vector, interpolated
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: v_out
//realv ijkVecBinearest2rv(real2 v_out, real2 const v00, real2 const v01, real2 const v10, real2 const v11, real const u0, real const u1, real const u);
#define ijkVecDistaijkVecBinearest2rvnce2rv ijk_declrealfs(ijkVecBinearest2,v)

// ijkVecRemap2*v
//	Linear remap between two ranges by first inverse interpolating between 
//	source/original range and then linearly interpolating between destination/
//	target range.
//		param v_out: output vector, interpolated
//		param v0_dst: initial reference value in destination/target range, 
//			result when v_src=v0_src
//		param v1_dst: terminal reference value in destination/target range, 
//			result when v_src=v1_src
//		param v0_src: initial reference value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: v_out
//realv ijkVecRemap2rv(real2 v_out, real2 const v0_dst, real2 const v1_dst, real2 const v0_src, real2 const v1_src, real2 const v_src);
#define ijkVecRemap2rv ijk_declrealfs(ijkVecRemap2,v)

// ijkVecBezier0O2*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
//realv ijkVecBezier0O2rv(real2 v_out, real2 const v0, real const u);
#define ijkVecBezier0O2rv ijk_declrealfs(ijkVecBezier0O2,v)

// ijkVecBezier1O2*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecBezier1O2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define ijkVecBezier1O2rv ijk_declrealfs(ijkVecBezier1O2,v)

// ijkVecBezier2O2*v
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: v_out
//realv ijkVecBezier2O2rv(real2 v_out, real2 const v0, real2 const v1, real2 const v2, real const u);
#define ijkVecBezier2O2rv ijk_declrealfs(ijkVecBezier2O2,v)

// ijkVecBezier3O2*v
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: v_out
//realv ijkVecBezier3O2rv(real2 v_out, real2 const v0, real2 const v1, real2 const v2, real2 const v3, real const u);
#define ijkVecBezier3O2rv ijk_declrealfs(ijkVecBezier3O2,v)

// ijkVecBezierNO2*v
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v_out: output vector, interpolated
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: v_out
//realv ijkVecBezierNO2rv(real2 v_out, real2 const v[], size const order, real const u);
#define ijkVecBezierNO2rv ijk_declrealfs(ijkVecBezierNO2,v)

// ijkVecCubicHermite2*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermite2rv(real2 v_out, real2 const v0, real2 const dv0, real2 const v1, real2 const dv1, real const u);
#define ijkVecCubicHermite2rv ijk_declrealfs(ijkVecCubicHermite2,v)

// ijkVecCubicHermiteHandles2*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermiteHandles2rv(real2 v_out, real2 const v0, real2 const cv0, real2 const v1, real2 const cv1, real const u);
#define ijkVecCubicHermiteHandles2rv ijk_declrealfs(ijkVecCubicHermiteHandles2,v)

// ijkVecCubicCatmullRom2*v
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param v_out: output vector, interpolated
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicCatmullRom2rv(real2 v_out, real2 const vp, real2 const v0, real2 const v1, real2 const v2, real const u);
#define ijkVecCubicCatmullRom2rv ijk_declrealfs(ijkVecCubicCatmullRom2,v)

// ijkVecBicubicCatmullRom2*v
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param v_out: output vector, interpolated
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: v_out
//realv ijkVecBicubicCatmullRom2rv(real2 v_out, real2 const vpp, real2 const vp0, real2 const vp1, real2 const vp2, real2 const v0p, real2 const v00, real2 const v01, real2 const v02, real2 const v1p, real2 const v10, real2 const v11, real2 const v12, real2 const v2p, real2 const v20, real2 const v21, real2 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom2rv ijk_declrealfs(ijkVecBicubicCatmullRom2,v)

// ijkVecReparamCubicHermite2*v
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite2rv(real uTable_out[], real lTable_out[], real2 vTable_out[], size const numDivisions, ibool const lNormalize, real2 const v0, real2 const dv0, real2 const v1, real2 const dv1);
#define ijkVecReparamCubicHermite2rv ijk_declrealfs(ijkVecReparamCubicHermite2,v)

// ijkVecReparamCubicHermiteHandles2*v
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles2rv(real uTable_out[], real lTable_out[], real2 vTable_out[], size const numDivisions, ibool const lNormalize, real2 const v0, real2 const cv0, real2 const v1, real2 const cv1);
#define ijkVecReparamCubicHermiteHandles2rv ijk_declrealfs(ijkVecReparamCubicHermiteHandles2,v)

// ijkVecReparamCubicCatmullRom2*v
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom2rv(real uTable_out[], real lTable_out[], real2 vTable_out[], size const numDivisions, ibool const lNormalize, real2 const vp, real2 const v0, real2 const v1, real2 const v2);
#define ijkVecReparamCubicCatmullRom2rv ijk_declrealfs(ijkVecReparamCubicCatmullRom2,v)

// ijkVecReparamBicubicCatmullRom2*v
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom2rv(real uTable_out[], real lTable_out[], real2 vTable_out[], size const numDivisions, ibool const lNormalize, real2 const vpp, real2 const vp0, real2 const vp1, real2 const vp2, real2 const v0p, real2 const v00, real2 const v01, real2 const v02, real2 const v1p, real2 const v10, real2 const v11, real2 const v12, real2 const v2p, real2 const v20, real2 const v21, real2 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom2rv ijk_declrealfs(ijkVecReparamBicubicCatmullRom2,v)

// ijkVecSampleTableInc2*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableInc2rv(real2 v_out, real const uTable[], real2 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc2rv ijk_declrealfs(ijkVecSampleTableInc2,v)

// ijkVecSampleTableDec2*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableDec2rv(real2 v_out, real const uTable[], real2 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec2rv ijk_declrealfs(ijkVecSampleTableDec2,v)


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq3rv(real3 const v_in);
#define ijkVecLengthSq3rv ijk_declrealfs(ijkVecLengthSq3,v)

// ijkVecLength3*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength3rv(real3 const v_in);
#define ijkVecLength3rv ijk_declrealfs(ijkVecLength3,v)

// ijkVecLengthSqInv3*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv3rv(real3 const v_in);
#define ijkVecLengthSqInv3rv ijk_declrealfs(ijkVecLengthSqInv3,v)

// ijkVecLengthSqInvSafe3*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe3rv(real3 const v_in);
#define ijkVecLengthSqInvSafe3rv ijk_declrealfs(ijkVecLengthSqInvSafe3,v)

// ijkVecLengthInv3*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv3rv(real3 const v_in);
#define ijkVecLengthInv3rv ijk_declrealfs(ijkVecLengthInv3,v)

// ijkVecLengthInvSafe3*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe3rv(real3 const v_in);
#define ijkVecLengthInvSafe3rv ijk_declrealfs(ijkVecLengthInvSafe3,v)

// ijkVecNormalize3*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize3rv(real3 v_out, real3 const v_in);
#define ijkVecNormalize3rv ijk_declrealfs(ijkVecNormalize3,v)

// ijkVecNormalizeSafe3*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe3rv(real3 v_out, real3 const v_in);
#define ijkVecNormalizeSafe3rv ijk_declrealfs(ijkVecNormalizeSafe3,v)

// ijkVecNormalizeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength3rv(real3 v_out, real3 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength3rv ijk_declrealfs(ijkVecNormalizeGetLength3,v)

// ijkVecNormalizeSafeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength3rv(real3 v_out, real3 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength3rv ijk_declrealfs(ijkVecNormalizeSafeGetLength3,v)

// ijkVecNormalizeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv3rv(real3 v_out, real3 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv3rv ijk_declrealfs(ijkVecNormalizeGetLengthInv3,v)

// ijkVecNormalizeSafeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv3rv(real3 v_out, real3 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv3rv ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv3,v)

// ijkVecCrossNormalize3*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalize3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecCrossNormalize3rv ijk_declrealfs(ijkVecCrossNormalize3,v)

// ijkVecCrossNormalizeSafe3*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalizeSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define ijkVecCrossNormalizeSafe3rv ijk_declrealfs(ijkVecCrossNormalizeSafe3,v)

// ijkVecCrossNormalizeGetLength3*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLength3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength3rv ijk_declrealfs(ijkVecCrossNormalizeGetLength3,v)

// ijkVecCrossNormalizeSafeGetLength3*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLength3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength3rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength3,v)

// ijkVecCrossNormalizeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLengthInv3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv3rv ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv3,v)

// ijkVecCrossNormalizeSafeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLengthInv3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv3rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv3,v)

// ijkVecLerp3*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define ijkVecLerp3rv ijk_declrealfs(ijkVecLerp3,v)

// ijkVecLerpInv3*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv3rv(real3 v_out, real3 const v0, real3 const v1, real3 const v_lerp);
#define ijkVecLerpInv3rv ijk_declrealfs(ijkVecLerpInv3,v)

// ijkVecLerpRevInit3*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit3rv(real3 v0_out, real3 const v_lerp, real3 const v1, real const u);
#define ijkVecLerpRevInit3rv ijk_declrealfs(ijkVecLerpRevInit3,v)

// ijkVecLerpRevTerm3*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm3rv(real3 v1_out, real3 const v0, real3 const v_lerp, real const u);
#define ijkVecLerpRevTerm3rv ijk_declrealfs(ijkVecLerpRevTerm3,v)

// ijkVecProjRatio3*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio3rv(real3 const v_base, real3 const v_in);
#define ijkVecProjRatio3rv ijk_declrealfs(ijkVecProjRatio3,v)

// ijkVecProj3*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj3rv(real3 v_out, real3 const v_base, real3 const v_in);
#define ijkVecProj3rv ijk_declrealfs(ijkVecProj3,v)

// ijkVecOrtho3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho3rv(real3 v_out, real3 const v_base, real3 const v_in);
#define ijkVecOrtho3rv ijk_declrealfs(ijkVecOrtho3,v)

// ijkVecOrthoNorm3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm3rv(real3 v_out, real3 const v_base, real3 const v_in, real3 v_base_norm_out);
#define ijkVecOrthoNorm3rv ijk_declrealfs(ijkVecOrthoNorm3,v)

// ijkVecOrthoList3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real3* ijkVecOrthoList3rv(real3 vl_out[], real3 const v_base, real3 const vl_in[], size const n);
#define ijkVecOrthoList3rv ijk_declrealfs(ijkVecOrthoList3,v)

// ijkVecOrthoNormList3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real3* ijkVecOrthoNormList3rv(real3 vl_out[], real3 const v_base, real3 const vl_in[], size const n, real3 v_base_norm_out);
#define ijkVecOrthoNormList3rv ijk_declrealfs(ijkVecOrthoNormList3,v)

// ijkVecNlerp3*v
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecNlerp3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define ijkVecNlerp3rv ijk_declrealfs(ijkVecNlerp3,v)

// ijkVecSlerp3*v
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecSlerp3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define ijkVecSlerp3rv ijk_declrealfs(ijkVecSlerp3,v)

// ijkVecReflectScale3*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflectScale3rv(real3 v_out, real3 const v_in, real3 const v_nrm);
#define ijkVecReflectScale3rv ijk_declrealfs(ijkVecReflectScale3,v)

// ijkVecUnitReflect3*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecUnitReflect3rv(real3 v_out, real3 const v_in, real3 const v_nrm);
#define ijkVecUnitReflect3rv ijk_declrealfs(ijkVecUnitReflect3,v)

// ijkVecReflect3*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflect3rv(real3 v_out, real3 const v_in, real3 const v_nrm);
#define ijkVecReflect3rv ijk_declrealfs(ijkVecReflect3,v)

// ijkVecDistance3*v
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance3rv(real3 const v_lh, real3 const v_rh);
#define ijkVecDistance3rv ijk_declrealfs(ijkVecDistance3,v)

// ijkVecResize3*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResize3rv(real3 v_out, real3 const v_in, real const length);
#define ijkVecResize3rv ijk_declrealfs(ijkVecResize3,v)

// ijkVecResizeSafe3*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResizeSafe3rv(real3 v_out, real3 const v_in, real const length);
#define ijkVecResizeSafe3rv ijk_declrealfs(ijkVecResizeSafe3,v)

// ijkVecCrossResize3*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecCrossResize3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real const length);
#define ijkVecCrossResize3rv ijk_declrealfs(ijkVecCrossResize3,v)

// ijkVecCrossResizeSafe3*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecCrossResizeSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real const length);
#define ijkVecCrossResizeSafe3rv ijk_declrealfs(ijkVecCrossResizeSafe3,v)

// ijkVecNearest3*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
//realv ijkVecNearest3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define ijkVecNearest3rv ijk_declrealfs(ijkVecNearest3,v)

// ijkVecBinearest3*v
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v_out: output vector, interpolated
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: v_out
//realv ijkVecBinearest3rv(real3 v_out, real3 const v00, real3 const v01, real3 const v10, real3 const v11, real const u0, real const u1, real const u);
#define ijkVecBinearest3rv ijk_declrealfs(ijkVecBinearest3,v)

// ijkVecRemap3*v
//	Linear remap between two ranges by first inverse interpolating between 
//	source/original range and then linearly interpolating between destination/
//	target range.
//		param v_out: output vector, interpolated
//		param v0_dst: initial reference value in destination/target range, 
//			result when v_src=v0_src
//		param v1_dst: terminal reference value in destination/target range, 
//			result when v_src=v1_src
//		param v0_src: initial reference value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: v_out
//realv ijkVecRemap3rv(real3 v_out, real3 const v0_dst, real3 const v1_dst, real3 const v0_src, real3 const v1_src, real3 const v_src);
#define ijkVecRemap3rv ijk_declrealfs(ijkVecRemap3,v)

// ijkVecBezier0O3*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
//realv ijkVecBezier0O3rv(real3 v_out, real3 const v0, real const u);
#define ijkVecBezier0O3rv ijk_declrealfs(ijkVecBezier0O3,v)

// ijkVecBezier1O3*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecBezier1O3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define ijkVecBezier1O3rv ijk_declrealfs(ijkVecBezier1O3,v)

// ijkVecBezier2O3*v
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: v_out
//realv ijkVecBezier2O3rv(real3 v_out, real3 const v0, real3 const v1, real3 const v2, real const u);
#define ijkVecBezier2O3rv ijk_declrealfs(ijkVecBezier2O3,v)

// ijkVecBezier3O3*v
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: v_out
//realv ijkVecBezier3O3rv(real3 v_out, real3 const v0, real3 const v1, real3 const v2, real3 const v3, real const u);
#define ijkVecBezier3O3rv ijk_declrealfs(ijkVecBezier3O3,v)

// ijkVecBezierNO3*v
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v_out: output vector, interpolated
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: v_out
//realv ijkVecBezierNO3rv(real3 v_out, real3 const v[], size const order, real const u);
#define ijkVecBezierNO3rv ijk_declrealfs(ijkVecBezierNO3,v)

// ijkVecCubicHermite3*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermite3rv(real3 v_out, real3 const v0, real3 const dv0, real3 const v1, real3 const dv1, real const u);
#define ijkVecCubicHermite3rv ijk_declrealfs(ijkVecCubicHermite3,v)

// ijkVecCubicHermiteHandles3*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermiteHandles3rv(real3 v_out, real3 const v0, real3 const cv0, real3 const v1, real3 const cv1, real const u);
#define ijkVecCubicHermiteHandles3rv ijk_declrealfs(ijkVecCubicHermiteHandles3,v)

// ijkVecCubicCatmullRom3*v
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param v_out: output vector, interpolated
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicCatmullRom3rv(real3 v_out, real3 const vp, real3 const v0, real3 const v1, real3 const v2, real const u);
#define ijkVecCubicCatmullRom3rv ijk_declrealfs(ijkVecCubicCatmullRom3,v)

// ijkVecBicubicCatmullRom3*v
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param v_out: output vector, interpolated
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: v_out
//realv ijkVecBicubicCatmullRom3rv(real3 v_out, real3 const vpp, real3 const vp0, real3 const vp1, real3 const vp2, real3 const v0p, real3 const v00, real3 const v01, real3 const v02, real3 const v1p, real3 const v10, real3 const v11, real3 const v12, real3 const v2p, real3 const v20, real3 const v21, real3 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom3rv ijk_declrealfs(ijkVecBicubicCatmullRom3,v)

// ijkVecReparamCubicHermite3*v
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite3rv(real uTable_out[], real lTable_out[], real3 vTable_out[], size const numDivisions, ibool const lNormalize, real3 const v0, real3 const dv0, real3 const v1, real3 const dv1);
#define ijkVecReparamCubicHermite3rv ijk_declrealfs(ijkVecReparamCubicHermite3,v)

// ijkVecReparamCubicHermiteHandles3*v
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles3rv(real uTable_out[], real lTable_out[], real3 vTable_out[], size const numDivisions, ibool const lNormalize, real3 const v0, real3 const cv0, real3 const v1, real3 const cv1);
#define ijkVecReparamCubicHermiteHandles3rv ijk_declrealfs(ijkVecReparamCubicHermiteHandles3,v)

// ijkVecReparamCubicCatmullRom3*v
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom3rv(real uTable_out[], real lTable_out[], real3 vTable_out[], size const numDivisions, ibool const lNormalize, real3 const vp, real3 const v0, real3 const v1, real3 const v2);
#define ijkVecReparamCubicCatmullRom3rv ijk_declrealfs(ijkVecReparamCubicCatmullRom3,v)

// ijkVecReparamBicubicCatmullRom3*v
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom3rv(real uTable_out[], real lTable_out[], real3 vTable_out[], size const numDivisions, ibool const lNormalize, real3 const vpp, real3 const vp0, real3 const vp1, real3 const vp2, real3 const v0p, real3 const v00, real3 const v01, real3 const v02, real3 const v1p, real3 const v10, real3 const v11, real3 const v12, real3 const v2p, real3 const v20, real3 const v21, real3 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom3rv ijk_declrealfs(ijkVecReparamBicubicCatmullRom3,v)

// ijkVecSampleTableInc3*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableInc3rv(real3 v_out, real const uTable[], real3 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc3rv ijk_declrealfs(ijkVecSampleTableInc3,v)

// ijkVecSampleTableDec3*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableDec3rv(real3 v_out, real const uTable[], real3 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec3rv ijk_declrealfs(ijkVecSampleTableDec3,v)


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq4rv(real4 const v_in);
#define ijkVecLengthSq4rv ijk_declrealfs(ijkVecLengthSq4,v)

// ijkVecLength4*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength4rv(real4 const v_in);
#define ijkVecLength4rv ijk_declrealfs(ijkVecLength4,v)

// ijkVecLengthSqInv4*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv4rv(real4 const v_in);
#define ijkVecLengthSqInv4rv ijk_declrealfs(ijkVecLengthSqInv4,v)

// ijkVecLengthSqInvSafe4*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe4rv(real4 const v_in);
#define ijkVecLengthSqInvSafe4rv ijk_declrealfs(ijkVecLengthSqInvSafe4,v)

// ijkVecLengthInv4*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv4rv(real4 const v_in);
#define ijkVecLengthInv4rv ijk_declrealfs(ijkVecLengthInv4,v)

// ijkVecLengthInvSafe4*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe4rv(real4 const v_in);
#define ijkVecLengthInvSafe4rv ijk_declrealfs(ijkVecLengthInvSafe4,v)

// ijkVecNormalize4*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize4rv(real4 v_out, real4 const v_in);
#define ijkVecNormalize4rv ijk_declrealfs(ijkVecNormalize4,v)

// ijkVecNormalizeSafe4*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe4rv(real4 v_out, real4 const v_in);
#define ijkVecNormalizeSafe4rv ijk_declrealfs(ijkVecNormalizeSafe4,v)

// ijkVecNormalizeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength4rv(real4 v_out, real4 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength4rv ijk_declrealfs(ijkVecNormalizeGetLength4,v)

// ijkVecNormalizeSafeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength4rv(real4 v_out, real4 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength4rv ijk_declrealfs(ijkVecNormalizeSafeGetLength4,v)

// ijkVecNormalizeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv4rv(real4 v_out, real4 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv4rv ijk_declrealfs(ijkVecNormalizeGetLengthInv4,v)

// ijkVecNormalizeSafeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv4rv(real4 v_out, real4 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv4rv ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv4,v)

// ijkVecCrossNormalize4*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalize4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecCrossNormalize4rv ijk_declrealfs(ijkVecCrossNormalize4,v)

// ijkVecCrossNormalizeSafe4*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalizeSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define ijkVecCrossNormalizeSafe4rv ijk_declrealfs(ijkVecCrossNormalizeSafe4,v)

// ijkVecCrossNormalizeGetLength4*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLength4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength4rv ijk_declrealfs(ijkVecCrossNormalizeGetLength4,v)

// ijkVecCrossNormalizeSafeGetLength4*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLength4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength4rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength4,v)

// ijkVecCrossNormalizeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLengthInv4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv4rv ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv4,v)

// ijkVecCrossNormalizeSafeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLengthInv4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv4rv ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv4,v)

// ijkVecLerp4*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define ijkVecLerp4rv ijk_declrealfs(ijkVecLerp4,v)

// ijkVecLerpInv4*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv4rv(real4 v_out, real4 const v0, real4 const v1, real4 const v_lerp);
#define ijkVecLerpInv4rv ijk_declrealfs(ijkVecLerpInv4,v)

// ijkVecLerpRevInit4*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit4rv(real4 v0_out, real4 const v_lerp, real4 const v1, real const u);
#define ijkVecLerpRevInit4rv ijk_declrealfs(ijkVecLerpRevInit4,v)

// ijkVecLerpRevTerm4*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm4rv(real4 v1_out, real4 const v0, real4 const v_lerp, real const u);
#define ijkVecLerpRevTerm4rv ijk_declrealfs(ijkVecLerpRevTerm4,v)

// ijkVecProjRatio4*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio4rv(real4 const v_base, real4 const v_in);
#define ijkVecProjRatio4rv ijk_declrealfs(ijkVecProjRatio4,v)

// ijkVecProj4*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj4rv(real4 v_out, real4 const v_base, real4 const v_in);
#define ijkVecProj4rv ijk_declrealfs(ijkVecProj4,v)

// ijkVecOrtho4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho4rv(real4 v_out, real4 const v_base, real4 const v_in);
#define ijkVecOrtho4rv ijk_declrealfs(ijkVecOrtho4,v)

// ijkVecOrthoNorm4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm4rv(real4 v_out, real4 const v_base, real4 const v_in, real4 v_base_norm_out);
#define ijkVecOrthoNorm4rv ijk_declrealfs(ijkVecOrthoNorm4,v)

// ijkVecOrthoList4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real4* ijkVecOrthoList4rv(real4 vl_out[], real4 const v_base, real4 const vl_in[], size const n);
#define ijkVecOrthoList4rv ijk_declrealfs(ijkVecOrthoList4,v)

// ijkVecOrthoNormList4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real4* ijkVecOrthoNormList4rv(real4 vl_out[], real4 const v_base, real4 const vl_in[], size const n, real4 v_base_norm_out);
#define ijkVecOrthoNormList4rv ijk_declrealfs(ijkVecOrthoNormList4,v)

// ijkVecNlerp4*v
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecNlerp4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define ijkVecNlerp4rv ijk_declrealfs(ijkVecNlerp4,v)

// ijkVecSlerp4*v
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecSlerp4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define ijkVecSlerp4rv ijk_declrealfs(ijkVecSlerp4,v)

// ijkVecReflectScale4*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflectScale4rv(real4 v_out, real4 const v_in, real4 const v_nrm);
#define ijkVecReflectScale4rv ijk_declrealfs(ijkVecReflectScale4,v)

// ijkVecUnitReflect4*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecUnitReflect4rv(real4 v_out, real4 const v_in, real4 const v_nrm);
#define ijkVecUnitReflect4rv ijk_declrealfs(ijkVecUnitReflect4,v)

// ijkVecReflect4*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
//realv ijkVecReflect4rv(real4 v_out, real4 const v_in, real4 const v_nrm);
#define ijkVecReflect4rv ijk_declrealfs(ijkVecReflect4,v)

// ijkVecDistance4*v
//	Calculate "distance" between two 4D vectors.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance4rv(real4 const v_lh, real4 const v_rh);
#define ijkVecDistance4rv ijk_declrealfs(ijkVecDistance4,v)

// ijkVecResize4*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResize4rv(real4 v_out, real4 const v_in, real const length);
#define ijkVecResize4rv ijk_declrealfs(ijkVecResize4,v)

// ijkVecResizeSafe4*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecResizeSafe4rv(real4 v_out, real4 const v_in, real const length);
#define ijkVecResizeSafe4rv ijk_declrealfs(ijkVecResizeSafe4,v)

// ijkVecCrossResize4*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecCrossResize4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real const length);
#define ijkVecCrossResize4rv ijk_declrealfs(ijkVecCrossResize4,v)

// ijkVecCrossResizeSafe4*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
//realv ijkVecCrossResizeSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real const length);
#define ijkVecCrossResizeSafe4rv ijk_declrealfs(ijkVecCrossResizeSafe4,v)

// ijkVecNearest4*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
//realv ijkVecNearest4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define ijkVecNearest4rv ijk_declrealfs(ijkVecNearest4,v)

// ijkVecBinearest4*v
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v_out: output vector, interpolated
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: v_out
//realv ijkVecBinearest4rv(real4 v_out, real4 const v00, real4 const v01, real4 const v10, real4 const v11, real const u0, real const u1, real const u);
#define ijkVecBinearest4rv ijk_declrealfs(ijkVecBinearest4,v)

// ijkVecRemap4*v
//	Linear remap between two ranges by first inverse interpolating between 
//	source/original range and then linearly interpolating between destination/
//	target range.
//		param v_out: output vector, interpolated
//		param v0_dst: initial reference value in destination/target range, 
//			result when v_src=v0_src
//		param v1_dst: terminal reference value in destination/target range, 
//			result when v_src=v1_src
//		param v0_src: initial reference value in source/original range
//		param v1_src: terminal reference value in source/original range
//		param v_src: value to be remapped from original to target range
//		return: v_out
//realv ijkVecRemap4rv(real4 v_out, real4 const v0_dst, real4 const v1_dst, real4 const v0_src, real4 const v1_src, real4 const v_src);
#define ijkVecRemap4rv ijk_declrealfs(ijkVecRemap4,v)

// ijkVecBezier0O4*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
//realv ijkVecBezier0O4rv(real4 v_out, real4 const v0, real const u);
#define ijkVecBezier0O4rv ijk_declrealfs(ijkVecBezier0O4,v)

// ijkVecBezier1O4*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecBezier1O4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define ijkVecBezier1O4rv ijk_declrealfs(ijkVecBezier1O4,v)

// ijkVecBezier2O4*v
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: v_out
//realv ijkVecBezier2O4rv(real4 v_out, real4 const v0, real4 const v1, real4 const v2, real const u);
#define ijkVecBezier2O4rv ijk_declrealfs(ijkVecBezier2O4,v)

// ijkVecBezier3O4*v
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: v_out
//realv ijkVecBezier3O4rv(real4 v_out, real4 const v0, real4 const v1, real4 const v2, real4 const v3, real const u);
#define ijkVecBezier3O4rv ijk_declrealfs(ijkVecBezier3O4,v)

// ijkVecBezierNO4*v
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v_out: output vector, interpolated
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: v_out
//realv ijkVecBezierNO4rv(real4 v_out, real4 const v[], size const order, real const u);
#define ijkVecBezierNO4rv ijk_declrealfs(ijkVecBezierNO4,v)

// ijkVecCubicHermite4*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermite4rv(real4 v_out, real4 const v0, real4 const dv0, real4 const v1, real4 const dv1, real const u);
#define ijkVecCubicHermite4rv ijk_declrealfs(ijkVecCubicHermite4,v)

// ijkVecCubicHermiteHandles4*v
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicHermiteHandles4rv(real4 v_out, real4 const v0, real4 const cv0, real4 const v1, real4 const cv1, real const u);
#define ijkVecCubicHermiteHandles4rv ijk_declrealfs(ijkVecCubicHermiteHandles4,v)

// ijkVecCubicCatmullRom4*v
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param v_out: output vector, interpolated
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
//realv ijkVecCubicCatmullRom4rv(real4 v_out, real4 const vp, real4 const v0, real4 const v1, real4 const v2, real const u);
#define ijkVecCubicCatmullRom4rv ijk_declrealfs(ijkVecCubicCatmullRom4,v)

// ijkVecBicubicCatmullRom4*v
//	Bi-cubic interpolation using Catmull-Rom interpolation for segments.
//		param v_out: output vector, interpolated
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: v_out
//realv ijkVecBicubicCatmullRom4rv(real4 v_out, real4 const vpp, real4 const vp0, real4 const vp1, real4 const vp2, real4 const v0p, real4 const v00, real4 const v01, real4 const v02, real4 const v1p, real4 const v10, real4 const v11, real4 const v12, real4 const v2p, real4 const v20, real4 const v21, real4 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom4rv ijk_declrealfs(ijkVecBicubicCatmullRom4,v)

// ijkVecReparamCubicHermite4*v
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite4rv(real uTable_out[], real lTable_out[], real4 vTable_out[], size const numDivisions, ibool const lNormalize, real4 const v0, real4 const dv0, real4 const v1, real4 const dv1);
#define ijkVecReparamCubicHermite4rv ijk_declrealfs(ijkVecReparamCubicHermite4,v)

// ijkVecReparamCubicHermiteHandles4*v
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles4rv(real uTable_out[], real lTable_out[], real4 vTable_out[], size const numDivisions, ibool const lNormalize, real4 const v0, real4 const cv0, real4 const v1, real4 const cv1);
#define ijkVecReparamCubicHermiteHandles4rv ijk_declrealfs(ijkVecReparamCubicHermiteHandles4,v)

// ijkVecReparamCubicCatmullRom4*v
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom4rv(real uTable_out[], real lTable_out[], real4 vTable_out[], size const numDivisions, ibool const lNormalize, real4 const vp, real4 const v0, real4 const v1, real4 const v2);
#define ijkVecReparamCubicCatmullRom4rv ijk_declrealfs(ijkVecReparamCubicCatmullRom4,v)

// ijkVecReparamBicubicCatmullRom4*v
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom4rv(real uTable_out[], real lTable_out[], real4 vTable_out[], size const numDivisions, ibool const lNormalize, real4 const vpp, real4 const vp0, real4 const vp1, real4 const vp2, real4 const v0p, real4 const v00, real4 const v01, real4 const v02, real4 const v1p, real4 const v10, real4 const v11, real4 const v12, real4 const v2p, real4 const v20, real4 const v21, real4 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom4rv ijk_declrealfs(ijkVecReparamBicubicCatmullRom4,v)

// ijkVecSampleTableInc4*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableInc4rv(real4 v_out, real const uTable[], real4 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc4rv ijk_declrealfs(ijkVecSampleTableInc4,v)

// ijkVecSampleTableDec4*v
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param v_out: output vector, interpolated value in table that 
//			approximates input parameter
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: v_out
//realv ijkVecSampleTableDec4rv(real4 v_out, real const uTable[], real4 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec4rv ijk_declrealfs(ijkVecSampleTableDec4,v)


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq2r(rvec2 const v_in);
#define ijkVecLengthSq2r ijk_declrealfs(ijkVecLengthSq2,)

// ijkVecLength2*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength2r(rvec2 const v_in);
#define ijkVecLength2r ijk_declrealfs(ijkVecLength2,)

// ijkVecLengthSqInv2*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv2r(rvec2 const v_in);
#define ijkVecLengthSqInv2r ijk_declrealfs(ijkVecLengthSqInv2,)

// ijkVecLengthSqInvSafe2*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe2r(rvec2 const v_in);
#define ijkVecLengthSqInvSafe2r ijk_declrealfs(ijkVecLengthSqInvSafe2,)

// ijkVecLengthInv2*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv2r(rvec2 const v_in);
#define ijkVecLengthInv2r ijk_declrealfs(ijkVecLengthInv2,)

// ijkVecLengthInvSafe2*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe2r(rvec2 const v_in);
#define ijkVecLengthInvSafe2r ijk_declrealfs(ijkVecLengthInvSafe2,)

// ijkVecNormalize2*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec2 ijkVecNormalize2r(rvec2 const v_in);
#define ijkVecNormalize2r ijk_declrealfs(ijkVecNormalize2,)

// ijkVecNormalizeSafe2*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafe2r(rvec2 const v_in);
#define ijkVecNormalizeSafe2r ijk_declrealfs(ijkVecNormalizeSafe2,)

// ijkVecNormalizeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeGetLength2r(rvec2 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength2r ijk_declrealfs(ijkVecNormalizeGetLength2,)

// ijkVecNormalizeSafeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafeGetLength2r(rvec2 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength2r ijk_declrealfs(ijkVecNormalizeSafeGetLength2,)

// ijkVecNormalizeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeGetLengthInv2r(rvec2 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv2r ijk_declrealfs(ijkVecNormalizeGetLengthInv2,)

// ijkVecNormalizeSafeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafeGetLengthInv2r(rvec2 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv2r ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv2,)

// ijkVecCrossNormalize2*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalize2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecCrossNormalize2r ijk_declrealfs(ijkVecCrossNormalize2,)

// ijkVecCrossNormalizeSafe2*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecCrossNormalizeSafe2r ijk_declrealfs(ijkVecCrossNormalizeSafe2,)

// ijkVecCrossNormalizeGetLength2*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLength2r(rvec2 const v_lh, rvec2 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength2r ijk_declrealfs(ijkVecCrossNormalizeGetLength2,)

// ijkVecCrossNormalizeSafeGetLength2*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLength2r(rvec2 const v_lh, rvec2 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength2r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength2,)

// ijkVecCrossNormalizeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLengthInv2r(rvec2 const v_lh, rvec2 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv2r ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv2,)

// ijkVecCrossNormalizeSafeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLengthInv2r(rvec2 const v_lh, rvec2 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv2r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv2,)

// ijkVecLerp2*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec2 ijkVecLerp2r(rvec2 const v0, rvec2 const v1, real const u);
#define ijkVecLerp2r ijk_declrealfs(ijkVecLerp2,)

// ijkVecLerpInv2*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec2 ijkVecLerpInv2r(rvec2 const v0, rvec2 const v1, rvec2 const v_lerp);
#define ijkVecLerpInv2r ijk_declrealfs(ijkVecLerpInv2,)

// ijkVecLerpRevInit2*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec2 ijkVecLerpRevInit2r(rvec2 const v_lerp, rvec2 const v1, real const u);
#define ijkVecLerpRevInit2r ijk_declrealfs(ijkVecLerpRevInit2,)

// ijkVecLerpRevTerm2*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec2 ijkVecLerpRevTerm2r(rvec2 const v0, rvec2 const v_lerp, real const u);
#define ijkVecLerpRevTerm2r ijk_declrealfs(ijkVecLerpRevTerm2,)

// ijkVecProjRatio2*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio2r(rvec2 const v_base, rvec2 const v_in);
#define ijkVecProjRatio2r ijk_declrealfs(ijkVecProjRatio2,)

// ijkVecProj2*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec2 ijkVecProj2r(rvec2 const v_base, rvec2 const v_in);
#define ijkVecProj2r ijk_declrealfs(ijkVecProj2,)

// ijkVecOrtho2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec2 ijkVecOrtho2r(rvec2 const v_base, rvec2 const v_in);
#define ijkVecOrtho2r ijk_declrealfs(ijkVecOrtho2,)

// ijkVecOrthoNorm2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec2 ijkVecOrthoNorm2r(rvec2 const v_base, rvec2 const v_in, rvec2* const v_base_norm_out);
#define ijkVecOrthoNorm2r ijk_declrealfs(ijkVecOrthoNorm2,)

// ijkVecOrthoList2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec2* ijkVecOrthoList2r(rvec2 vl_out[], rvec2 const v_base, rvec2 const vl_in[], size const n);
#define ijkVecOrthoList2r ijk_declrealfs(ijkVecOrthoList2,)

// ijkVecOrthoNormList2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec2* ijkVecOrthoNormList2r(rvec2 vl_out[], rvec2 const v_base, rvec2 const vl_in[], size const n, rvec2* const v_base_norm_out);
#define ijkVecOrthoNormList2r ijk_declrealfs(ijkVecOrthoNormList2,)

// ijkVecNlerp2*
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec2 ijkVecNlerp2r(rvec2 const v0, rvec2 const v1, real const u);
#define ijkVecNlerp2r ijk_declrealfs(ijkVecNlerp2,)

// ijkVecSlerp2*
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec2 ijkVecSlerp2r(rvec2 const v0, rvec2 const v1, real const u);
#define ijkVecSlerp2r ijk_declrealfs(ijkVecSlerp2,)

// ijkVecReflectScale2*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec2 ijkVecReflectScale2r(rvec2 const v_in, rvec2 const v_nrm);
#define ijkVecReflectScale2r ijk_declrealfs(ijkVecReflectScale2,)

// ijkVecUnitReflect2*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec2 ijkVecUnitReflect2r(rvec2 const v_in, rvec2 const v_nrm);
#define ijkVecUnitReflect2r ijk_declrealfs(ijkVecUnitReflect2,)

// ijkVecReflect2*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec2 ijkVecReflect2r(rvec2 const v_in, rvec2 const v_nrm);
#define ijkVecReflect2r ijk_declrealfs(ijkVecReflect2,)

// ijkVecDistance2*
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance2r(rvec2 const v_lh, rvec2 const v_rh);
#define ijkVecDistance2r ijk_declrealfs(ijkVecDistance2,)

// ijkVecResize2*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec2 ijkVecResize2r(rvec2 const v_in, real const length);
#define ijkVecResize2r ijk_declrealfs(ijkVecResize2,)

// ijkVecResizeSafe2*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec2 ijkVecResizeSafe2r(rvec2 const v_in, real const length);
#define ijkVecResizeSafe2r ijk_declrealfs(ijkVecResizeSafe2,)

// ijkVecCrossResize2*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
//real ijkVecCrossResize2r(rvec2 const v_lh, rvec2 const v_rh, real const length);
#define ijkVecCrossResize2r ijk_declrealfs(ijkVecCrossResize2,)

// ijkVecCrossResizeSafe2*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
//real ijkVecCrossResizeSafe2r(rvec2 const v_lh, rvec2 const v_rh, real const length);
#define ijkVecCrossResizeSafe2r ijk_declrealfs(ijkVecCrossResizeSafe2,)

// ijkVecNearest2*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
//rvec2 ijkVecNearest2r(rvec2 const v0, rvec2 const v1, real const u);
#define ijkVecNearest2r ijk_declrealfs(ijkVecNearest2,)

// ijkVecBinearest2*
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: bi-nearest-neighbor interpolated vector
//rvec2 ijkVecBinearest2r(rvec2 const v00, rvec2 const v01, rvec2 const v10, rvec2 const v11, real const u0, real const u1, real const u);
#define ijkVecBinearest2r ijk_declrealfs(ijkVecBinearest2,)

// ijkVecRemap2*
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
//		return: vector in original range remapped to target range
//rvec2 ijkVecRemap2r(rvec2 const v0_dst, rvec2 const v1_dst, rvec2 const v0_src, rvec2 const v1_src, rvec2 const v_src);
#define ijkVecRemap2r ijk_declrealfs(ijkVecRemap2,)

// ijkVecBezier0O2*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
//rvec2 ijkVecBezier0O2r(rvec2 const v0, real const u);
#define ijkVecBezier0O2r ijk_declrealfs(ijkVecBezier0O2,)

// ijkVecBezier1O2*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
//rvec2 ijkVecBezier1O2r(rvec2 const v0, rvec2 const v1, real const u);
#define ijkVecBezier1O2r ijk_declrealfs(ijkVecBezier1O2,)

// ijkVecBezier2O2*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
//rvec2 ijkVecBezier2O2r(rvec2 const v0, rvec2 const v1, rvec2 const v2, real const u);
#define ijkVecBezier2O2r ijk_declrealfs(ijkVecBezier2O2,)

// ijkVecBezier3O2*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
//rvec2 ijkVecBezier3O2r(rvec2 const v0, rvec2 const v1, rvec2 const v2, rvec2 const v3, real const u);
#define ijkVecBezier3O2r ijk_declrealfs(ijkVecBezier3O2,)

// ijkVecBezierNO2*
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
//rvec2 ijkVecBezierNO2r(rvec2 const v[], size const order, real const u);
#define ijkVecBezierNO2r ijk_declrealfs(ijkVecBezierNO2,)

// ijkVecCubicHermite2*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec2 ijkVecCubicHermite2r(rvec2 const v0, rvec2 const dv0, rvec2 const v1, rvec2 const dv1, real const u);
#define ijkVecCubicHermite2r ijk_declrealfs(ijkVecCubicHermite2,)

// ijkVecCubicHermiteHandles2*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec2 ijkVecCubicHermiteHandles2r(rvec2 const v0, rvec2 const cv0, rvec2 const v1, rvec2 const cv1, real const u);
#define ijkVecCubicHermiteHandles2r ijk_declrealfs(ijkVecCubicHermiteHandles2,)

// ijkVecCubicCatmullRom2*
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec2 ijkVecCubicCatmullRom2r(rvec2 const vp, rvec2 const v0, rvec2 const v1, rvec2 const v2, real const u);
#define ijkVecCubicCatmullRom2r ijk_declrealfs(ijkVecCubicCatmullRom2,)

// ijkVecBicubicCatmullRom2*
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: interpolated vector
//rvec2 ijkVecBicubicCatmullRom2r(rvec2 const vpp, rvec2 const vp0, rvec2 const vp1, rvec2 const vp2, rvec2 const v0p, rvec2 const v00, rvec2 const v01, rvec2 const v02, rvec2 const v1p, rvec2 const v10, rvec2 const v11, rvec2 const v12, rvec2 const v2p, rvec2 const v20, rvec2 const v21, rvec2 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom2r ijk_declrealfs(ijkVecBicubicCatmullRom2,)

// ijkVecReparamCubicHermite2*
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite2r(real uTable_out[], real lTable_out[], rvec2 vTable_out[], size const numDivisions, ibool const lNormalize, rvec2 const v0, rvec2 const dv0, rvec2 const v1, rvec2 const dv1);
#define ijkVecReparamCubicHermite2r ijk_declrealfs(ijkVecReparamCubicHermite2,)

// ijkVecReparamCubicHermiteHandles2*
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles2r(real uTable_out[], real lTable_out[], rvec2 vTable_out[], size const numDivisions, ibool const lNormalize, rvec2 const v0, rvec2 const cv0, rvec2 const v1, rvec2 const cv1);
#define ijkVecReparamCubicHermiteHandles2r ijk_declrealfs(ijkVecReparamCubicHermiteHandles2,)

// ijkVecReparamCubicCatmullRom2*
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom2r(real uTable_out[], real lTable_out[], rvec2 vTable_out[], size const numDivisions, ibool const lNormalize, rvec2 const vp, rvec2 const v0, rvec2 const v1, rvec2 const v2);
#define ijkVecReparamCubicCatmullRom2r ijk_declrealfs(ijkVecReparamCubicCatmullRom2,)

// ijkVecReparamBicubicCatmullRom2*
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom2r(real uTable_out[], real lTable_out[], rvec2 vTable_out[], size const numDivisions, ibool const lNormalize, rvec2 const vpp, rvec2 const vp0, rvec2 const vp1, rvec2 const vp2, rvec2 const v0p, rvec2 const v00, rvec2 const v01, rvec2 const v02, rvec2 const v1p, rvec2 const v10, rvec2 const v11, rvec2 const v12, rvec2 const v2p, rvec2 const v20, rvec2 const v21, rvec2 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom2r ijk_declrealfs(ijkVecReparamBicubicCatmullRom2,)

// ijkVecSampleTableInc2*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec2 ijkVecSampleTableInc2r(real const uTable[], rvec2 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc2r ijk_declrealfs(ijkVecSampleTableInc2,)

// ijkVecSampleTableDec2*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec2 ijkVecSampleTableDec2r(real const uTable[], rvec2 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec2r ijk_declrealfs(ijkVecSampleTableDec2,)


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq3r(rvec3 const v_in);
#define ijkVecLengthSq3r ijk_declrealfs(ijkVecLengthSq3,)

// ijkVecLength3*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength3r(rvec3 const v_in);
#define ijkVecLength3r ijk_declrealfs(ijkVecLength3,)

// ijkVecLengthSqInv3*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv3r(rvec3 const v_in);
#define ijkVecLengthSqInv3r ijk_declrealfs(ijkVecLengthSqInv3,)

// ijkVecLengthSqInvSafe3*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe3r(rvec3 const v_in);
#define ijkVecLengthSqInvSafe3r ijk_declrealfs(ijkVecLengthSqInvSafe3,)

// ijkVecLengthInv3*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv3r(rvec3 const v_in);
#define ijkVecLengthInv3r ijk_declrealfs(ijkVecLengthInv3,)

// ijkVecLengthInvSafe3*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe3r(rvec3 const v_in);
#define ijkVecLengthInvSafe3r ijk_declrealfs(ijkVecLengthInvSafe3,)

// ijkVecNormalize3*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec3 ijkVecNormalize3r(rvec3 const v_in);
#define ijkVecNormalize3r ijk_declrealfs(ijkVecNormalize3,)

// ijkVecNormalizeSafe3*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafe3r(rvec3 const v_in);
#define ijkVecNormalizeSafe3r ijk_declrealfs(ijkVecNormalizeSafe3,)

// ijkVecNormalizeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeGetLength3r(rvec3 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength3r ijk_declrealfs(ijkVecNormalizeGetLength3,)

// ijkVecNormalizeSafeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafeGetLength3r(rvec3 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength3r ijk_declrealfs(ijkVecNormalizeSafeGetLength3,)

// ijkVecNormalizeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeGetLengthInv3r(rvec3 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv3r ijk_declrealfs(ijkVecNormalizeGetLengthInv3,)

// ijkVecNormalizeSafeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafeGetLengthInv3r(rvec3 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv3r ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv3,)

// ijkVecCrossNormalize3*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec3 ijkVecCrossNormalize3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecCrossNormalize3r ijk_declrealfs(ijkVecCrossNormalize3,)

// ijkVecCrossNormalizeSafe3*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecCrossNormalizeSafe3r ijk_declrealfs(ijkVecCrossNormalizeSafe3,)

// ijkVecCrossNormalizeGetLength3*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeGetLength3r(rvec3 const v_lh, rvec3 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength3r ijk_declrealfs(ijkVecCrossNormalizeGetLength3,)

// ijkVecCrossNormalizeSafeGetLength3*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafeGetLength3r(rvec3 const v_lh, rvec3 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength3r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength3,)

// ijkVecCrossNormalizeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeGetLengthInv3r(rvec3 const v_lh, rvec3 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv3r ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv3,)

// ijkVecCrossNormalizeSafeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafeGetLengthInv3r(rvec3 const v_lh, rvec3 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv3r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv3,)

// ijkVecLerp3*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec3 ijkVecLerp3r(rvec3 const v0, rvec3 const v1, real const u);
#define ijkVecLerp3r ijk_declrealfs(ijkVecLerp3,)

// ijkVecLerpInv3*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec3 ijkVecLerpInv3r(rvec3 const v0, rvec3 const v1, rvec3 const v_lerp);
#define ijkVecLerpInv3r ijk_declrealfs(ijkVecLerpInv3,)

// ijkVecLerpRevInit3*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec3 ijkVecLerpRevInit3r(rvec3 const v_lerp, rvec3 const v1, real const u);
#define ijkVecLerpRevInit3r ijk_declrealfs(ijkVecLerpRevInit3,)

// ijkVecLerpRevTerm3*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec3 ijkVecLerpRevTerm3r(rvec3 const v0, rvec3 const v_lerp, real const u);
#define ijkVecLerpRevTerm3r ijk_declrealfs(ijkVecLerpRevTerm3,)

// ijkVecProjRatio3*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio3r(rvec3 const v_base, rvec3 const v_in);
#define ijkVecProjRatio3r ijk_declrealfs(ijkVecProjRatio3,)

// ijkVecProj3*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec3 ijkVecProj3r(rvec3 const v_base, rvec3 const v_in);
#define ijkVecProj3r ijk_declrealfs(ijkVecProj3,)

// ijkVecOrtho3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec3 ijkVecOrtho3r(rvec3 const v_base, rvec3 const v_in);
#define ijkVecOrtho3r ijk_declrealfs(ijkVecOrtho3,)

// ijkVecOrthoNorm3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec3 ijkVecOrthoNorm3r(rvec3 const v_base, rvec3 const v_in, rvec3* const v_base_norm_out);
#define ijkVecOrthoNorm3r ijk_declrealfs(ijkVecOrthoNorm3,)

// ijkVecOrthoList3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec3* ijkVecOrthoList3r(rvec3 vl_out[], rvec3 const v_base, rvec3 const vl_in[], size const n);
#define ijkVecOrthoList3r ijk_declrealfs(ijkVecOrthoList3,)

// ijkVecOrthoNormList3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec3* ijkVecOrthoNormList3r(rvec3 vl_out[], rvec3 const v_base, rvec3 const vl_in[], size const n, rvec3* const v_base_norm_out);
#define ijkVecOrthoNormList3r ijk_declrealfs(ijkVecOrthoNormList3,)

// ijkVecNlerp3*
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec3 ijkVecNlerp3r(rvec3 const v0, rvec3 const v1, real const u);
#define ijkVecNlerp3r ijk_declrealfs(ijkVecNlerp3,)

// ijkVecSlerp3*
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec3 ijkVecSlerp3r(rvec3 const v0, rvec3 const v1, real const u);
#define ijkVecSlerp3r ijk_declrealfs(ijkVecSlerp3,)

// ijkVecReflectScale3*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec3 ijkVecReflectScale3r(rvec3 const v_in, rvec3 const v_nrm);
#define ijkVecReflectScale3r ijk_declrealfs(ijkVecReflectScale3,)

// ijkVecUnitReflect3*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec3 ijkVecUnitReflect3r(rvec3 const v_in, rvec3 const v_nrm);
#define ijkVecUnitReflect3r ijk_declrealfs(ijkVecUnitReflect3,)

// ijkVecReflect3*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec3 ijkVecReflect3r(rvec3 const v_in, rvec3 const v_nrm);
#define ijkVecReflect3r ijk_declrealfs(ijkVecReflect3,)

// ijkVecDistance3*
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance3r(rvec3 const v_lh, rvec3 const v_rh);
#define ijkVecDistance3r ijk_declrealfs(ijkVecDistance3,)

// ijkVecResize3*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec3 ijkVecResize3r(rvec3 const v_in, real const length);
#define ijkVecResize3r ijk_declrealfs(ijkVecResize3,)

// ijkVecResizeSafe3*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec3 ijkVecResizeSafe3r(rvec3 const v_in, real const length);
#define ijkVecResizeSafe3r ijk_declrealfs(ijkVecResizeSafe3,)

// ijkVecCrossResize3*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
//rvec3 ijkVecCrossResize3r(rvec3 const v_lh, rvec3 const v_rh, real const length);
#define ijkVecCrossResize3r ijk_declrealfs(ijkVecCrossResize3,)

// ijkVecCrossResizeSafe3*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
//rvec3 ijkVecCrossResizeSafe3r(rvec3 const v_lh, rvec3 const v_rh, real const length);
#define ijkVecCrossResizeSafe3r ijk_declrealfs(ijkVecCrossResizeSafe3,)

// ijkVecNearest3*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
//rvec3 ijkVecNearest3r(rvec3 const v0, rvec3 const v1, real const u);
#define ijkVecNearest3r ijk_declrealfs(ijkVecNearest3,)

// ijkVecBinearest3*
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: bi-nearest-neighbor interpolated vector
//rvec3 ijkVecBinearest3r(rvec3 const v00, rvec3 const v01, rvec3 const v10, rvec3 const v11, real const u0, real const u1, real const u);
#define ijkVecBinearest3r ijk_declrealfs(ijkVecBinearest3,)

// ijkVecRemap3*
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
//		return: vector in original range remapped to target range
//rvec3 ijkVecRemap3r(rvec3 const v0_dst, rvec3 const v1_dst, rvec3 const v0_src, rvec3 const v1_src, rvec3 const v_src);
#define ijkVecRemap3r ijk_declrealfs(ijkVecRemap3,)

// ijkVecBezier0O3*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
//rvec3 ijkVecBezier0O3r(rvec3 const v0, real const u);
#define ijkVecBezier0O3r ijk_declrealfs(ijkVecBezier0O3,)

// ijkVecBezier1O3*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
//rvec3 ijkVecBezier1O3r(rvec3 const v0, rvec3 const v1, real const u);
#define ijkVecBezier1O3r ijk_declrealfs(ijkVecBezier1O3,)

// ijkVecBezier2O3*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
//rvec3 ijkVecBezier2O3r(rvec3 const v0, rvec3 const v1, rvec3 const v2, real const u);
#define ijkVecBezier2O3r ijk_declrealfs(ijkVecBezier2O3,)

// ijkVecBezier3O3*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
//rvec3 ijkVecBezier3O3r(rvec3 const v0, rvec3 const v1, rvec3 const v2, rvec3 const v3, real const u);
#define ijkVecBezier3O3r ijk_declrealfs(ijkVecBezier3O3,)

// ijkVecBezierNO3*
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
//rvec3 ijkVecBezierNO3r(rvec3 const v[], size const order, real const u);
#define ijkVecBezierNO3r ijk_declrealfs(ijkVecBezierNO3,)

// ijkVecCubicHermite3*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec3 ijkVecCubicHermite3r(rvec3 const v0, rvec3 const dv0, rvec3 const v1, rvec3 const dv1, real const u);
#define ijkVecCubicHermite3r ijk_declrealfs(ijkVecCubicHermite3,)

// ijkVecCubicHermiteHandles3*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec3 ijkVecCubicHermiteHandles3r(rvec3 const v0, rvec3 const cv0, rvec3 const v1, rvec3 const cv1, real const u);
#define ijkVecCubicHermiteHandles3r ijk_declrealfs(ijkVecCubicHermiteHandles3,)

// ijkVecCubicCatmullRom3*
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec3 ijkVecCubicCatmullRom3r(rvec3 const vp, rvec3 const v0, rvec3 const v1, rvec3 const v2, real const u);
#define ijkVecCubicCatmullRom3r ijk_declrealfs(ijkVecCubicCatmullRom3,)

// ijkVecBicubicCatmullRom3*
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: interpolated vector
//rvec3 ijkVecBicubicCatmullRom3r(rvec3 const vpp, rvec3 const vp0, rvec3 const vp1, rvec3 const vp2, rvec3 const v0p, rvec3 const v00, rvec3 const v01, rvec3 const v02, rvec3 const v1p, rvec3 const v10, rvec3 const v11, rvec3 const v12, rvec3 const v2p, rvec3 const v20, rvec3 const v21, rvec3 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom3r ijk_declrealfs(ijkVecBicubicCatmullRom3,)

// ijkVecReparamCubicHermite3*
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite3r(real uTable_out[], real lTable_out[], rvec3 vTable_out[], size const numDivisions, ibool const lNormalize, rvec3 const v0, rvec3 const dv0, rvec3 const v1, rvec3 const dv1);
#define ijkVecReparamCubicHermite3r ijk_declrealfs(ijkVecReparamCubicHermite3,)

// ijkVecReparamCubicHermiteHandles3*
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles3r(real uTable_out[], real lTable_out[], rvec3 vTable_out[], size const numDivisions, ibool const lNormalize, rvec3 const v0, rvec3 const cv0, rvec3 const v1, rvec3 const cv1);
#define ijkVecReparamCubicHermiteHandles3r ijk_declrealfs(ijkVecReparamCubicHermiteHandles3,)

// ijkVecReparamCubicCatmullRom3*
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom3r(real uTable_out[], real lTable_out[], rvec3 vTable_out[], size const numDivisions, ibool const lNormalize, rvec3 const vp, rvec3 const v0, rvec3 const v1, rvec3 const v2);
#define ijkVecReparamCubicCatmullRom3r ijk_declrealfs(ijkVecReparamCubicCatmullRom3,)

// ijkVecReparamBicubicCatmullRom3*
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom3r(real uTable_out[], real lTable_out[], rvec3 vTable_out[], size const numDivisions, ibool const lNormalize, rvec3 const vpp, rvec3 const vp0, rvec3 const vp1, rvec3 const vp2, rvec3 const v0p, rvec3 const v00, rvec3 const v01, rvec3 const v02, rvec3 const v1p, rvec3 const v10, rvec3 const v11, rvec3 const v12, rvec3 const v2p, rvec3 const v20, rvec3 const v21, rvec3 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom3r ijk_declrealfs(ijkVecReparamBicubicCatmullRom3,)

// ijkVecSampleTableInc3*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec3 ijkVecSampleTableInc3r(real const uTable[], rvec3 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc3r ijk_declrealfs(ijkVecSampleTableInc3,)

// ijkVecSampleTableDec3*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec3 ijkVecSampleTableDec3r(real const uTable[], rvec3 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec3r ijk_declrealfs(ijkVecSampleTableDec3,)


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq4r(rvec4 const v_in);
#define ijkVecLengthSq4r ijk_declrealfs(ijkVecLengthSq4,)

// ijkVecLength4*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength4r(rvec4 const v_in);
#define ijkVecLength4r ijk_declrealfs(ijkVecLength4,)

// ijkVecLengthSqInv4*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv4r(rvec4 const v_in);
#define ijkVecLengthSqInv4r ijk_declrealfs(ijkVecLengthSqInv4,)

// ijkVecLengthSqInvSafe4*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe4r(rvec4 const v_in);
#define ijkVecLengthSqInvSafe4r ijk_declrealfs(ijkVecLengthSqInvSafe4,)

// ijkVecLengthInv4*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv4r(rvec4 const v_in);
#define ijkVecLengthInv4r ijk_declrealfs(ijkVecLengthInv4,)

// ijkVecLengthInvSafe4*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe4r(rvec4 const v_in);
#define ijkVecLengthInvSafe4r ijk_declrealfs(ijkVecLengthInvSafe4,)

// ijkVecNormalize4*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec4 ijkVecNormalize4r(rvec4 const v_in);
#define ijkVecNormalize4r ijk_declrealfs(ijkVecNormalize4,)

// ijkVecNormalizeSafe4*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafe4r(rvec4 const v_in);
#define ijkVecNormalizeSafe4r ijk_declrealfs(ijkVecNormalizeSafe4,)

// ijkVecNormalizeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeGetLength4r(rvec4 const v_in, real* const length_out);
#define ijkVecNormalizeGetLength4r ijk_declrealfs(ijkVecNormalizeGetLength4,)

// ijkVecNormalizeSafeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafeGetLength4r(rvec4 const v_in, real* const length_out);
#define ijkVecNormalizeSafeGetLength4r ijk_declrealfs(ijkVecNormalizeSafeGetLength4,)

// ijkVecNormalizeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeGetLengthInv4r(rvec4 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeGetLengthInv4r ijk_declrealfs(ijkVecNormalizeGetLengthInv4,)

// ijkVecNormalizeSafeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafeGetLengthInv4r(rvec4 const v_in, real* const lengthInv_out);
#define ijkVecNormalizeSafeGetLengthInv4r ijk_declrealfs(ijkVecNormalizeSafeGetLengthInv4,)

// ijkVecCrossNormalize4*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec4 ijkVecCrossNormalize4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecCrossNormalize4r ijk_declrealfs(ijkVecCrossNormalize4,)

// ijkVecCrossNormalizeSafe4*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecCrossNormalizeSafe4r ijk_declrealfs(ijkVecCrossNormalizeSafe4,)

// ijkVecCrossNormalizeGetLength4*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeGetLength4r(rvec4 const v_lh, rvec4 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeGetLength4r ijk_declrealfs(ijkVecCrossNormalizeGetLength4,)

// ijkVecCrossNormalizeSafeGetLength4*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafeGetLength4r(rvec4 const v_lh, rvec4 const v_rh, real* const length_out);
#define ijkVecCrossNormalizeSafeGetLength4r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLength4,)

// ijkVecCrossNormalizeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeGetLengthInv4r(rvec4 const v_lh, rvec4 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeGetLengthInv4r ijk_declrealfs(ijkVecCrossNormalizeGetLengthInv4,)

// ijkVecCrossNormalizeSafeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafeGetLengthInv4r(rvec4 const v_lh, rvec4 const v_rh, real* const lengthInv_out);
#define ijkVecCrossNormalizeSafeGetLengthInv4r ijk_declrealfs(ijkVecCrossNormalizeSafeGetLengthInv4,)

// ijkVecLerp4*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec4 ijkVecLerp4r(rvec4 const v0, rvec4 const v1, real const u);
#define ijkVecLerp4r ijk_declrealfs(ijkVecLerp4,)

// ijkVecLerpInv4*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec4 ijkVecLerpInv4r(rvec4 const v0, rvec4 const v1, rvec4 const v_lerp);
#define ijkVecLerpInv4r ijk_declrealfs(ijkVecLerpInv4,)

// ijkVecLerpRevInit4*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec4 ijkVecLerpRevInit4r(rvec4 const v_lerp, rvec4 const v1, real const u);
#define ijkVecLerpRevInit4r ijk_declrealfs(ijkVecLerpRevInit4,)

// ijkVecLerpRevTerm4*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec4 ijkVecLerpRevTerm4r(rvec4 const v0, rvec4 const v_lerp, real const u);
#define ijkVecLerpRevTerm4r ijk_declrealfs(ijkVecLerpRevTerm4,)

// ijkVecProjRatio4*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio4r(rvec4 const v_base, rvec4 const v_in);
#define ijkVecProjRatio4r ijk_declrealfs(ijkVecProjRatio4,)

// ijkVecProj4*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec4 ijkVecProj4r(rvec4 const v_base, rvec4 const v_in);
#define ijkVecProj4r ijk_declrealfs(ijkVecProj4,)

// ijkVecOrtho4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec4 ijkVecOrtho4r(rvec4 const v_base, rvec4 const v_in);
#define ijkVecOrtho4r ijk_declrealfs(ijkVecOrtho4,)

// ijkVecOrthoNorm4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec4 ijkVecOrthoNorm4r(rvec4 const v_base, rvec4 const v_in, rvec4* const v_base_norm_out);
#define ijkVecOrthoNorm4r ijk_declrealfs(ijkVecOrthoNorm4,)

// ijkVecOrthoList4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec4* ijkVecOrthoList4r(rvec4 vl_out[], rvec4 const v_base, rvec4 const vl_in[], size const n);
#define ijkVecOrthoList4r ijk_declrealfs(ijkVecOrthoList4,)

// ijkVecOrthoNormList4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec4* ijkVecOrthoNormList4r(rvec4 vl_out[], rvec4 const v_base, rvec4 const vl_in[], size const n, rvec4* const v_base_norm_out);
#define ijkVecOrthoNormList4r ijk_declrealfs(ijkVecOrthoNormList4,)

// ijkVecNlerp4*
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec4 ijkVecNlerp4r(rvec4 const v0, rvec4 const v1, real const u);
#define ijkVecNlerp4r ijk_declrealfs(ijkVecNlerp4,)

// ijkVecSlerp4*
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec4 ijkVecSlerp4r(rvec4 const v0, rvec4 const v1, real const u);
#define ijkVecSlerp4r ijk_declrealfs(ijkVecSlerp4,)

// ijkVecReflectScale4*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec4 ijkVecReflectScale4r(rvec4 const v_in, rvec4 const v_nrm);
#define ijkVecReflectScale4r ijk_declrealfs(ijkVecReflectScale4,)

// ijkVecUnitReflect4*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec4 ijkVecUnitReflect4r(rvec4 const v_in, rvec4 const v_nrm);
#define ijkVecUnitReflect4r ijk_declrealfs(ijkVecUnitReflect4,)

// ijkVecReflect4*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
//rvec4 ijkVecReflect4r(rvec4 const v_in, rvec4 const v_nrm);
#define ijkVecReflect4r ijk_declrealfs(ijkVecReflect4,)

// ijkVecDistance4*
//	Calculate "distance" between two 4D vectors.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
//real ijkVecDistance4r(rvec4 const v_lh, rvec4 const v_rh);
#define ijkVecDistance4r ijk_declrealfs(ijkVecDistance4,)

// ijkVecResize4*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec4 ijkVecResize4r(rvec4 const v_in, real const length);
#define ijkVecResize4r ijk_declrealfs(ijkVecResize4,)

// ijkVecResizeSafe4*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
//rvec4 ijkVecResizeSafe4r(rvec4 const v_in, real const length);
#define ijkVecResizeSafe4r ijk_declrealfs(ijkVecResizeSafe4,)

// ijkVecCrossResize4*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
//rvec4 ijkVecCrossResize4r(rvec4 const v_lh, rvec4 const v_rh, real const length);
#define ijkVecCrossResize4r ijk_declrealfs(ijkVecCrossResize4,)

// ijkVecCrossResizeSafe4*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
//rvec4 ijkVecCrossResizeSafe4r(rvec4 const v_lh, rvec4 const v_rh, real const length);
#define ijkVecCrossResizeSafe4r ijk_declrealfs(ijkVecCrossResizeSafe4,)

// ijkVecNearest4*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
//rvec4 ijkVecNearest4r(rvec4 const v0, rvec4 const v1, real const u);
#define ijkVecNearest4r ijk_declrealfs(ijkVecNearest4,)

// ijkVecBinearest4*
//	Nearest-neighbor interpolation of nearest-neighbor interpolated values.
//		param v00: initial reference value/start point in first pair, result 
//			of first pair when t0<0.5
//		param v01: terminal reference value/end point in first pair, result 
//			of first pair when t0>=0.5
//		param v10: initial reference value/start point in second pair, result 
//			of second pair when t1<0.5
//		param v11: terminal reference value/end point in second pair, result 
//			of second pair when t1>=0.5
//		param u0: interpolation parameter for first pair
//		param u1: interpolation parameter for second pair
//		param u: interpolation parameter for results
//		return: bi-nearest-neighbor interpolated vector
//rvec4 ijkVecBinearest4r(rvec4 const v00, rvec4 const v01, rvec4 const v10, rvec4 const v11, real const u0, real const u1, real const u);
#define ijkVecBinearest4r ijk_declrealfs(ijkVecBinearest4,)

// ijkVecRemap4*
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
//		return: vector in original range remapped to target range
//rvec4 ijkVecRemap4r(rvec4 const v0_dst, rvec4 const v1_dst, rvec4 const v0_src, rvec4 const v1_src, rvec4 const v_src);
#define ijkVecRemap4r ijk_declrealfs(ijkVecRemap4,)

// ijkVecBezier0O4*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
//rvec4 ijkVecBezier0O4r(rvec4 const v0, real const u);
#define ijkVecBezier0O4r ijk_declrealfs(ijkVecBezier0O4,)

// ijkVecBezier1O4*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
//rvec4 ijkVecBezier1O4r(rvec4 const v0, rvec4 const v1, real const u);
#define ijkVecBezier1O4r ijk_declrealfs(ijkVecBezier1O4,)

// ijkVecBezier2O4*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
//rvec4 ijkVecBezier2O4r(rvec4 const v0, rvec4 const v1, rvec4 const v2, real const u);
#define ijkVecBezier2O4r ijk_declrealfs(ijkVecBezier2O4,)

// ijkVecBezier3O4*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
//rvec4 ijkVecBezier3O4r(rvec4 const v0, rvec4 const v1, rvec4 const v2, rvec4 const v3, real const u);
#define ijkVecBezier3O4r ijk_declrealfs(ijkVecBezier3O4,)

// ijkVecBezierNO4*
//	Perform order-N (recursive) Bezier interpolation given an array of 
//	reference values.
//		param v: array of reference values, result when t=0 is v[0], result 
//			when t=1 is v[order]
//			valid: non-null
//		param order: order of interpolation or number of recursive steps; 
//			note: size of array is order+1, order is maximum index
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v[0] and v[order]
//		return: recursive Bezier interpolation between v[0] and v[order]
//rvec4 ijkVecBezierNO4r(rvec4 const v[], size const order, real const u);
#define ijkVecBezierNO4r ijk_declrealfs(ijkVecBezierNO4,)

// ijkVecCubicHermite4*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control tangents (rates of change at reference values).
//		param v0: initial reference value/start point, result when t=0
//		param dv0: initial tangent/rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param dv1: terminal tangent/rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec4 ijkVecCubicHermite4r(rvec4 const v0, rvec4 const dv0, rvec4 const v1, rvec4 const dv1, real const u);
#define ijkVecCubicHermite4r ijk_declrealfs(ijkVecCubicHermite4,)

// ijkVecCubicHermiteHandles4*
//	Cubic Hermite spline/curve interpolation between two reference values with 
//	control handles to determine rate of change at reference values.
//		param v0: initial reference value/start point, result when t=0
//		param cv0: initial control handle value, should be greater than v0 
//			for a positive rate of change
//		param v1: terminal reference value/end point, result when t=1
//		param cv1: terminal control handle value, should be greater than v1 
//			for a positive rate of change
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec4 ijkVecCubicHermiteHandles4r(rvec4 const v0, rvec4 const cv0, rvec4 const v1, rvec4 const cv1, real const u);
#define ijkVecCubicHermiteHandles4r ijk_declrealfs(ijkVecCubicHermiteHandles4,)

// ijkVecCubicCatmullRom4*
//	Catmull-Rom spline/curve interpolation between two reference values with 
//	two external control values.
//		param vp: initial control value (value before initial reference)
//		param v0: initial reference value/start point, result when t=0
//		param v1: terminal reference value/end point, result when t=1
//		param v2: terminal control value (value after terminal reference)
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: interpolated vector on spline/curve segment
//rvec4 ijkVecCubicCatmullRom4r(rvec4 const vp, rvec4 const v0, rvec4 const v1, rvec4 const v2, real const u);
#define ijkVecCubicCatmullRom4r ijk_declrealfs(ijkVecCubicCatmullRom4,)

// ijkVecBicubicCatmullRom4*
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		param u: interpolation parameter for result
//		return: interpolated vector
//rvec4 ijkVecBicubicCatmullRom4r(rvec4 const vpp, rvec4 const vp0, rvec4 const vp1, rvec4 const vp2, rvec4 const v0p, rvec4 const v00, rvec4 const v01, rvec4 const v02, rvec4 const v1p, rvec4 const v10, rvec4 const v11, rvec4 const v12, rvec4 const v2p, rvec4 const v20, rvec4 const v21, rvec4 const v22, real const up, real const u0, real const u1, real const u2, real const u);
#define ijkVecBicubicCatmullRom4r ijk_declrealfs(ijkVecBicubicCatmullRom4,)

// ijkVecReparamCubicHermite4*
//	Reparameterize a cubic Hermite segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermite4r(real uTable_out[], real lTable_out[], rvec4 vTable_out[], size const numDivisions, ibool const lNormalize, rvec4 const v0, rvec4 const dv0, rvec4 const v1, rvec4 const dv1);
#define ijkVecReparamCubicHermite4r ijk_declrealfs(ijkVecReparamCubicHermite4,)

// ijkVecReparamCubicHermiteHandles4*
//	Reparameterize a cubic Hermite segment with handles into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicHermiteHandles4r(real uTable_out[], real lTable_out[], rvec4 vTable_out[], size const numDivisions, ibool const lNormalize, rvec4 const v0, rvec4 const cv0, rvec4 const v1, rvec4 const cv1);
#define ijkVecReparamCubicHermiteHandles4r ijk_declrealfs(ijkVecReparamCubicHermiteHandles4,)

// ijkVecReparamCubicCatmullRom4*
//	Reparameterize a cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//real ijkVecReparamCubicCatmullRom4r(real uTable_out[], real lTable_out[], rvec4 vTable_out[], size const numDivisions, ibool const lNormalize, rvec4 const vp, rvec4 const v0, rvec4 const v1, rvec4 const v2);
#define ijkVecReparamCubicCatmullRom4r ijk_declrealfs(ijkVecReparamCubicCatmullRom4,)

// ijkVecReparamBicubicCatmullRom4*
//	Reparameterize a bi-cubic Catmull-Rom segment into sample table.
//		param uTable_out: array of interpolation parameters at each sample
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
//		param up: interpolation parameter for initial control curve
//		param u0: interpolation parameter for initial value curve
//		param u1: interpolation parameter for terminal value curve
//		param u2: interpolation parameter for terminal control curve
//		return: total arc length
//real ijkVecReparamBicubicCatmullRom4r(real uTable_out[], real lTable_out[], rvec4 vTable_out[], size const numDivisions, ibool const lNormalize, rvec4 const vpp, rvec4 const vp0, rvec4 const vp1, rvec4 const vp2, rvec4 const v0p, rvec4 const v00, rvec4 const v01, rvec4 const v02, rvec4 const v1p, rvec4 const v10, rvec4 const v11, rvec4 const v12, rvec4 const v2p, rvec4 const v20, rvec4 const v21, rvec4 const v22, real const up, real const u0, real const u1, real const u2);
#define ijkVecReparamBicubicCatmullRom4r ijk_declrealfs(ijkVecReparamBicubicCatmullRom4,)

// ijkVecSampleTableInc4*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values increase as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is greater than input parameter.
//		param uTable: array of increasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec4 ijkVecSampleTableInc4r(real const uTable[], rvec4 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableInc4r ijk_declrealfs(ijkVecSampleTableInc4,)

// ijkVecSampleTableDec4*
//	Find index of parameter in table and approximate value by interpolating 
//	surrounding samples in table. Assumes that parameter values decrease as 
//	the table is traversed (parameter increases as index increases) and will 
//	contuinue searching until tabled parameter is less than input parameter.
//		param uTable: array of decreasing sampling parameters (search table)
//			valid: non-null
//		param vTable: array of sampled values (value table)
//			valid: non-null
//		param i: starting search index
//			note: zero if starting from beginning of tables
//		param di: search index step size (increment of i at each iteration)
//			note: defaults to 1 if passed 0
//		param u: input parameter to find in search table
//		return: interpolated vector in table that approximates input parameter
//rvec4 ijkVecSampleTableDec4r(real const uTable[], rvec4 const vTable[], index i, index di, real const u);
#define ijkVecSampleTableDec4r ijk_declrealfs(ijkVecSampleTableDec4,)


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecPack1*b
//	Compress decimal scalar into a single byte (8 bits).
//		param v_in: symmetric-unit scalar to compress, in [-1,+1]
//		return: byte encoding scalar
//i8 ijkVecPack1rb(real const v_in);
#define ijkVecPack1rb ijk_declrealfs(ijkVecPack1,b)

// ijkVecUnpack1*b
//	Decompress decimal scalar from a single byte (8 bits).
//		param i_in: integer encoding scalar to decompress
//		return: decoded scalar
//real ijkVecUnpack1rb(i8 const i_in);
#define ijkVecUnpack1rb ijk_declrealfs(ijkVecUnpack1,b)

// ijkVecPack1*s
//	Compress decimal scalar into a short integer (16 bits).
//		param v_in: symmetric-unit scalar to compress, in [-1,+1]
//		return: short integer encoding scalar
//i16 ijkVecPack1rs(real const v_in);
#define ijkVecPack1rs ijk_declrealfs(ijkVecPack1,s)

// ijkVecUnpack1*s
//	Decompress decimal scalar from a short integer (16 bits).
//		param i_in: integer encoding scalar to decompress
//		return: decoded scalar
//real ijkVecUnpack1rs(i16 const i_in);
#define ijkVecUnpack1rs ijk_declrealfs(ijkVecUnpack1,s)

// ijkVecPack2*vs
//	Compress 2D vector into a short integer (16 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i16 ijkVecPack2rvs(real2 const v_in);
#define ijkVecPack2rvs ijk_declrealfs(ijkVecPack2,vs)

// ijkVecUnpack2*vs
//	Decompress 2D vector from a short integer (16 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpack2rvs(real2 v_out, i16 const i_in);
#define ijkVecUnpack2rvs ijk_declrealfs(ijkVecUnpack2,vs)

// ijkVecPack2*vl
//	Compress 2D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack2rvl(real2 const v_in);
#define ijkVecPack2rvl ijk_declrealfs(ijkVecPack2,vl)

// ijkVecUnpack2*vl
//	Decompress 2D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpack2rvl(real2 v_out, i32 const i_in);
#define ijkVecUnpack2rvl ijk_declrealfs(ijkVecUnpack2,vl)

// ijkVecPack3*vl
//	Compress 3D vector into a long integer (32 bits); components are encoded 
//	into 10 bits each.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack3rvl(real3 const v_in);
#define ijkVecPack3rvl ijk_declrealfs(ijkVecPack3,vl)

// ijkVecUnpack3*vl
//	Decompress 3D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpack3rvl(real3 v_out, i32 const i_in);
#define ijkVecUnpack3rvl ijk_declrealfs(ijkVecUnpack3,vl)

// ijkVecPack4*vl
//	Compress 4D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack4rvl(real4 const v_in);
#define ijkVecPack4rvl ijk_declrealfs(ijkVecPack4,vl)

// ijkVecUnpack4*vl
//	Decompress 4D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpack4rvl(real4 v_out, i32 const i_in);
#define ijkVecUnpack4rvl ijk_declrealfs(ijkVecUnpack4,vl)

// ijkVecPack4*vll
//	Compress 4D vector into a long-long integer (64 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPack4rvll(real4 const v_in);
#define ijkVecPack4rvll ijk_declrealfs(ijkVecPack4,vll)

// ijkVecUnpack4*vll
//	Decompress 4D vector from a long-long integer (64 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpack4rvll(real4 v_out, i64 const i_in);
#define ijkVecUnpack4rvll ijk_declrealfs(ijkVecUnpack4,vll)

// ijkVecPackUnitXYZ4*vl
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while one of the remaining bits 
//	specifies the sign of the fourth element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPackUnitXYZ4rvl(real4 const v_in);
#define ijkVecPackUnitXYZ4rvl ijk_declrealfs(ijkVecPackUnitXYZ4,vl)

// ijkVecUnpackUnitXYZ4*vl
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the sign of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpackUnitXYZ4rvl(real4 v_out, i32 const i_in);
#define ijkVecUnpackUnitXYZ4rvl ijk_declrealfs(ijkVecUnpackUnitXYZ4,vl)

// ijkVecPackUnit3of4*vl
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while the remaining bits specify 
//	the index of the excluded element. If the excluded component is negative, 
//	the whole vector will be negated.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPackUnit3of4rvl(real4 const v_in);
#define ijkVecPackUnit3of4rvl ijk_declrealfs(ijkVecPackUnit3of4,vl)

// ijkVecUnpackUnit3of4*vl
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the index of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpackUnit3of4rvl(real4 v_out, i32 const i_in);
#define ijkVecUnpackUnit3of4rvl ijk_declrealfs(ijkVecUnpackUnit3of4,vl)

// ijkVecPackUnitXYZ4*vll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 21 bits each, while the remaining 
//	bit specifies the sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPackUnitXYZ4rvll(real4 const v_in);
#define ijkVecPackUnitXYZ4rvll ijk_declrealfs(ijkVecPackUnitXYZ4,vll)

// ijkVecUnpackUnitXYZ4*vll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the sign of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpackUnitXYZ4rvll(real4 v_out, i64 const i_in);
#define ijkVecUnpackUnitXYZ4rvll ijk_declrealfs(ijkVecUnpackUnitXYZ4,vll)

// ijkVecPackUnit3of4*vll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 20 bits each, while the remaining 
//	bits specify the index and sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
//i64 ijkVecPackUnit3of4rvll(real4 const v_in, uindex const excl);
#define ijkVecPackUnit3of4rvll ijk_declrealfs(ijkVecPackUnit3of4,vll)

// ijkVecUnpackUnit3of4*vll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the index of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: v_out
//realv ijkVecUnpackUnit3of4rvll(real4 v_out, i64 const i_in, uindex* const excl_out);
#define ijkVecUnpackUnit3of4rvll ijk_declrealfs(ijkVecUnpackUnit3of4,vll)

// ijkVecPackQuant4*vll
//	Compress three components of 4D quantized unit vector into the 48 MOST 
//	significant bits of a long-long integer (64 bits); components are encoded 
//	into 15 bits each, with the sign and index of the maximum component 
//	stored in the remaining bits. Since the maximum value of the stored three 
//	components will be between [-sqrt(0.5),+sqrt(0.5)], they can be quantized 
//	for better precision when decoded.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPackQuant4rvll(real4 const v_in);
#define ijkVecPackQuant4rvll ijk_declrealfs(ijkVecPackQuant4,vll)

// ijkVecUnpackQuant4*vll
//	Decompress 4D quantized unit vector from a long-long integer (64 bits) 
//	encoding only three components, and the sign and index of the fourth; the 
//	decoded elements are stored in the 48 MOST significant bits.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
//realv ijkVecUnpackQuant4rvll(real4 v_out, i64 const i_in);
#define ijkVecUnpackQuant4rvll ijk_declrealfs(ijkVecUnpackQuant4,vll)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecPack2*s
//	Compress 2D vector into a short integer (16 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i16 ijkVecPack2rs(rvec2 const v_in);
#define ijkVecPack2rs ijk_declrealfs(ijkVecPack2,s)

// ijkVecUnpack2*s
//	Decompress 2D vector from a short integer (16 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec2 ijkVecUnpack2rs(i16 const i_in);
#define ijkVecUnpack2rs ijk_declrealfs(ijkVecUnpack2,s)

// ijkVecPack2*l
//	Compress 2D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack2rl(rvec2 const v_in);
#define ijkVecPack2rl ijk_declrealfs(ijkVecPack2,l)

// ijkVecUnpack2*l
//	Decompress 2D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec2 ijkVecUnpack2rl(i32 const i_in);
#define ijkVecUnpack2rl ijk_declrealfs(ijkVecUnpack2,l)

// ijkVecPack3*l
//	Compress 3D vector into a long integer (32 bits); components are encoded 
//	into 10 bits each.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack3rl(rvec3 const v_in);
#define ijkVecPack3rl ijk_declrealfs(ijkVecPack3,l)

// ijkVecUnpack3*l
//	Decompress 3D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec3 ijkVecUnpack3rl(i32 const i_in);
#define ijkVecUnpack3rl ijk_declrealfs(ijkVecUnpack3,l)

// ijkVecPack4*l
//	Compress 4D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPack4rl(rvec4 const v_in);
#define ijkVecPack4rl ijk_declrealfs(ijkVecPack4,l)

// ijkVecUnpack4*l
//	Decompress 4D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpack4rl(i32 const i_in);
#define ijkVecUnpack4rl ijk_declrealfs(ijkVecUnpack4,l)

// ijkVecPack4*ll
//	Compress 4D vector into a long-long integer (64 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPack4rll(rvec4 const v_in);
#define ijkVecPack4rll ijk_declrealfs(ijkVecPack4,ll)

// ijkVecUnpack4*ll
//	Decompress 4D vector from a long-long integer (64 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpack4rll(i64 const i_in);
#define ijkVecUnpack4rll ijk_declrealfs(ijkVecUnpack4,ll)

// ijkVecPackUnitXYZ4*l
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while one of the remaining bits 
//	specifies the sign of the fourth element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPackUnitXYZ4rl(rvec4 const v_in);
#define ijkVecPackUnitXYZ4rl ijk_declrealfs(ijkVecPackUnitXYZ4,l)

// ijkVecUnpackUnitXYZ4*l
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the sign of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpackUnitXYZ4rl(i32 const i_in);
#define ijkVecUnpackUnitXYZ4rl ijk_declrealfs(ijkVecUnpackUnitXYZ4,l)

// ijkVecPackUnit3of4*l
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while the remaining bits specify 
//	the index of the excluded element. If the excluded component is negative, 
//	the whole vector will be negated.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i32 ijkVecPackUnit3of4rl(rvec4 const v_in);
#define ijkVecPackUnit3of4rl ijk_declrealfs(ijkVecPackUnit3of4,l)

// ijkVecUnpackUnit3of4*l
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the index of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpackUnit3of4rl(i32 const i_in);
#define ijkVecUnpackUnit3of4rl ijk_declrealfs(ijkVecUnpackUnit3of4,l)

// ijkVecPackUnitXYZ4*ll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 21 bits each, while the remaining 
//	bit specifies the sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPackUnitXYZ4rll(rvec4 const v_in);
#define ijkVecPackUnitXYZ4rll ijk_declrealfs(ijkVecPackUnitXYZ4,ll)

// ijkVecUnpackUnitXYZ4*ll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the sign of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpackUnitXYZ4rll(i64 const i_in);
#define ijkVecUnpackUnitXYZ4rll ijk_declrealfs(ijkVecUnpackUnitXYZ4,ll)

// ijkVecPackUnit3of4*ll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 20 bits each, while the remaining 
//	bits specify the index and sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
//i64 ijkVecPackUnit3of4rll(rvec4 const v_in, uindex const excl);
#define ijkVecPackUnit3of4rll ijk_declrealfs(ijkVecPackUnit3of4,ll)

// ijkVecUnpackUnit3of4*ll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the index of the fourth.
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: decoded vector
//rvec4 ijkVecUnpackUnit3of4rll(i64 const i_in, uindex* const excl_out);
#define ijkVecUnpackUnit3of4rll ijk_declrealfs(ijkVecUnpackUnit3of4,ll)

// ijkVecPackQuant4*ll
//	Compress three components of 4D quantized unit vector into the 48 MOST 
//	significant bits of a long-long integer (64 bits); components are encoded 
//	into 15 bits each, with the sign and index of the maximum component 
//	stored in the remaining bits. Since the maximum value of the stored three 
//	components will be between [-sqrt(0.5),+sqrt(0.5)], they can be quantized 
//	for better precision when decoded.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
//i64 ijkVecPackQuant4rll(rvec4 const v_in);
#define ijkVecPackQuant4rll ijk_declrealfs(ijkVecPackQuant4,ll)

// ijkVecUnpackQuant4*ll
//	Decompress 4D quantized unit vector from a long-long integer (64 bits) 
//	encoding only three components, and the sign and index of the fourth; the 
//	decoded elements are stored in the 48 MOST significant bits.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
//rvec4 ijkVecUnpackQuant4rll(i64 const i_in);
#define ijkVecUnpackQuant4rll ijk_declrealfs(ijkVecUnpackQuant4,ll)


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_REAL_H_
#endif	// _IJK_VECTOR_H_