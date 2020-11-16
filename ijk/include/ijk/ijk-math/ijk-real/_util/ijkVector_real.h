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
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
//real ijkVecSgn1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
//real ijkVecDot1rs(real const s_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
//real ijkVecLengthSq1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
//real ijkVecLength1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
//real ijkVecLengthSqInv1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
//real ijkVecLengthInv1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
//real ijkVecNormalize1rs(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLength1rs(real const s, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLengthInv1rs(real const s, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
//realv ijkVecPrv(realv v_out);
#define func***sfx ijk_declrealfs(func,**sfx)


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit2rv(real2 v_out);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
//realv ijkVecInitElems2rv(real2 v_out, real const x, real const y);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy2rv(real2 v_out, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate2rv(real2 v_out, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot2rv(bool2 bv_out, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe2rv(real2 v_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor2rv(bool2 bv_out, real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy2rvs(real2 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate2rvs(real2 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot2rvs(bool2 bv_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe2rvs(real2 v_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor2rvs(bool2 bv_out, real2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe2rsv(real2 v_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor2rsv(bool2 bv_out, real const s_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot2rv(real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
//real ijkVecCross2rv(real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit3rv(real3 v_out);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
//realv ijkVecInitElems3rv(real3 v_out, real const x, real const y, real const z);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy3rv(real3 v_out, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate3rv(real3 v_out, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot3rv(bool3 bv_out, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor3rv(bool3 bv_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
//realv ijkVecCopy3rvz(real3 v_out, real2 const v_xy, real const z);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy3rvs(real3 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate3rvs(real3 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot3rvs(bool3 bv_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe3rvs(real3 v_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor3rvs(bool3 bv_out, real3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy3rxv(real3 v_out, real const x, real2 const v_yz);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe3rsv(real3 v_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor3rsv(bool3 bv_out, real const s_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot3rv(real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCross3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
//realv ijkVecInit4rv(real4 v_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecInitElems4rv(real4 v_out, real const x, real const y, real const z, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4rxvw(real4 v_out, real const x, real2 const v_yz, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy4fv2(real4 v_out, real2 const v_xy, real2 const v_zw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
//realv ijkVecCopy4rv(real4 v_out, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
//realv ijkVecNegate4rv(real4 v_out, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
//boolv ijkVecNot4rv(bool4 bv_out, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor4rv(bool4 bv_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4fvzw(real4 v_out, real2 const v_xy, real const z, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: v_out
//realv ijkVecCopy4fvw(real4 v_out, real3 const v_xyz, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
//realv ijkVecCopy4rvs(real4 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
//realv ijkVecNegate4rvs(real4 v_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
//boolv ijkVecNot4rvs(bool4 bv_out, real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecAdd4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecSub4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMul4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDiv4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecDivSafe4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecMod4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
//realv ijkVecModSafe4rvs(real4 v_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecInequal4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLessEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreaterEqual4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecLess4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecGreater4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecAnd4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNand4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecOr4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
//boolv ijkVecNor4rvs(bool4 bv_out, real4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
//realv ijkVecCopy4rxyv(real4 v_out, real const x, real const y, real2 const v_zw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
//realv ijkVecCopy4rxv(real4 v_out, real const x, real3 const v_yzw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecAdd4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecSub4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMul4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDiv4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecDivSafe4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecMod4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecModSafe4rsv(real4 v_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecInequal4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLessEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreaterEqual4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecLess4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecGreater4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecAnd4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNand4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecOr4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
//boolv ijkVecNor4rsv(bool4 bv_out, real const s_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot4rv(real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
//realv ijkVecCross4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
//real ijkVecAbs1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
//real ijkVecSgn1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
//real ijkVecDot1r(real const s_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
//real ijkVecLengthSq1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
//real ijkVecLength1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
//real ijkVecLengthSqInv1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
//real ijkVecLengthInv1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
//real ijkVecNormalize1r(real const s);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLength1r(real const s, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
//real ijkVecNormalizeGetLengthInv1r(real const s, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
//rvec2 ijkVecInit2r();
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
//rvec2 ijkVecInitElems2r(real const x, real const y);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec2 ijkVecCopy2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
//rvec2 ijkVecNegate2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec2 ijkVecNot2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecAdd2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecSub2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMul2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDiv2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDivSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMod2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecModSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecInequal2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLessEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLess2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreater2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecAnd2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNand2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecOr2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNor2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec2 ijkVecCopy2rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
//rvec2 ijkVecNegate2rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec2 ijkVecNot2rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecAdd2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecSub2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecMul2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecDiv2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecDivSafe2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecMod2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec2 ijkVecModSafe2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecEqual2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecInequal2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecLessEqual2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecLess2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecGreater2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecAnd2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecNand2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecOr2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec2 ijkVecNor2rs(rvec2 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecAdd2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecSub2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMul2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDiv2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecDivSafe2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecMod2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec2 ijkVecModSafe2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecEqual2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecInequal2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLessEqual2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreaterEqual2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecLess2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecGreater2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecAnd2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNand2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecOr2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec2 ijkVecNor2sr(real const s_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
//real ijkVecCross2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
//rvec3 ijkVecInit3r();
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
//rvec3 ijkVecInitElems3r(real const x, real const y, real const z);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec3 ijkVecCopy3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
//rvec3 ijkVecNegate3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec3 ijkVecNot3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecAdd3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecSub3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMul3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDiv3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDivSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMod3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecModSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecInequal3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLessEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLess3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreater3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecAnd3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNand3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecOr3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNor3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
//rvec3 ijkVecCopy3rz(rvec2 const v_xy, real const z);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec3 ijkVecCopy3rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
//rvec3 ijkVecNegate3rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec3 ijkVecNot3rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecAdd3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecSub3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecMul3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecDiv3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecDivSafe3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecMod3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec3 ijkVecModSafe3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecEqual3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecInequal3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecLessEqual3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecLess3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecGreater3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecAnd3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecNand3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecOr3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec3 ijkVecNor3rs(rvec3 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
//rvec3 ijkVecCopy3xr(real const x, rvec2 const v_yz);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecAdd3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecSub3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMul3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDiv3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecDivSafe3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecMod3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec3 ijkVecModSafe3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecEqual3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecInequal3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLessEqual3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreaterEqual3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecLess3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecGreater3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecAnd3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNand3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecOr3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec3 ijkVecNor3sr(real const s_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
//rvec3 ijkVecCross3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
//rvec4 ijkVecInit4r();
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecInitElems4r(real const x, real const y, real const z, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4xrw(real const x, rvec2 const v_yz, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
//rvec4 ijkVecCopy4r2(rvec2 const v_xy, rvec2 const v_zw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
//rvec4 ijkVecCopy4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
//rvec4 ijkVecNegate4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
//bvec4 ijkVecNot4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecAdd4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecSub4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMul4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDiv4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDivSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMod4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecModSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecInequal4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLessEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLess4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreater4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecAnd4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNand4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecOr4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNor4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4fzw(rvec2 const v_xy, real const z, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for poreal, 0 for vector)
//		return: result vector
//rvec4 ijkVecCopy4rw(rvec3 const v_xyz, real const w);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
//rvec4 ijkVecCopy4rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
//rvec4 ijkVecNegate4rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
//bvec4 ijkVecNot4rs(real const s_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecAdd4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecSub4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecMul4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecDiv4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecDivSafe4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecMod4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
//rvec4 ijkVecModSafe4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecEqual4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecInequal4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecLessEqual4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecLess4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecGreater4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecAnd4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecNand4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecOr4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
//bvec4 ijkVecNor4rs(rvec4 const v_lh, real const s_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
//rvec4 ijkVecCopy4xyr(real const x, real const y, rvec2 const v_zw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
//rvec4 ijkVecCopy4xr(real const x, rvec3 const v_yzw);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecAdd4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecSub4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMul4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDiv4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecDivSafe4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecMod4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
//rvec4 ijkVecModSafe4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecEqual4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecInequal4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLessEqual4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreaterEqual4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecLess4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecGreater4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecAnd4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNand4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecOr4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
//bvec4 ijkVecNor4sr(real const s_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
//real ijkVecDot4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
//rvec4 ijkVecCross4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq2*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength2*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv2*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe2*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv2*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe2*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe2rv(real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize2*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize2rv(real2 v_out, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe2*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe2rv(real2 v_out, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength2rv(real2 v_out, real2 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength2rv(real2 v_out, real2 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv2rv(real2 v_out, real2 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv2rv(real2 v_out, real2 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize2*v
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalize2rv(real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe2*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafe2rv(real2 const v_lh, real2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength2*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLength2rv(real2 const v_lh, real2 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength2*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLength2rv(real2 const v_lh, real2 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLengthInv2rv(real2 const v_lh, real2 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLengthInv2rv(real2 const v_lh, real2 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp2*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp2rv(real2 v_out, real2 const v0, real2 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv2*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv2rv(real2 v_out, real2 const v0, real2 const v1, real2 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit2*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit2rv(real2 v0_out, real2 const v_lerp, real2 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm2*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm2rv(real2 v1_out, real2 const v0, real2 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio2*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio2rv(real2 const v_base, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj2*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj2rv(real2 v_out, real2 const v_base, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho2rv(real2 v_out, real2 const v_base, real2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm2rv(real2 v_out, real2 const v_base, real2 const v_in, real2 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real2* ijkVecOrthoList2rv(real2 vl_out[], real2 const v_base, real2 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real2* ijkVecOrthoNormList2rv(real2 vl_out[], real2 const v_base, real2 const vl_in[], size const n, real2 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq3*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength3*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv3*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe3*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv3*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe3*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe3rv(real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize3*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize3rv(real3 v_out, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe3*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe3rv(real3 v_out, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength3rv(real3 v_out, real3 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength3rv(real3 v_out, real3 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv3rv(real3 v_out, real3 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv3rv(real3 v_out, real3 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize3*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalize3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe3*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalizeSafe3rv(real3 v_out, real3 const v_lh, real3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength3*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLength3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength3*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLength3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLengthInv3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLengthInv3rv(real3 v_out, real3 const v_lh, real3 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp3*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp3rv(real3 v_out, real3 const v0, real3 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv3*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv3rv(real3 v_out, real3 const v0, real3 const v1, real3 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit3*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit3rv(real3 v0_out, real3 const v_lerp, real3 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm3*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm3rv(real3 v1_out, real3 const v0, real3 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio3*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio3rv(real3 const v_base, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj3*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj3rv(real3 v_out, real3 const v_base, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho3rv(real3 v_out, real3 const v_base, real3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm3rv(real3 v_out, real3 const v_base, real3 const v_in, real3 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real3* ijkVecOrthoList3rv(real3 vl_out[], real3 const v_base, real3 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real3* ijkVecOrthoNormList3rv(real3 vl_out[], real3 const v_base, real3 const vl_in[], size const n, real3 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq4*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength4*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv4*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe4*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv4*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe4*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe4rv(real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize4*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalize4rv(real4 v_out, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe4*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
//realv ijkVecNormalizeSafe4rv(real4 v_out, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLength4rv(real4 v_out, real4 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLength4rv(real4 v_out, real4 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeGetLengthInv4rv(real4 v_out, real4 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecNormalizeSafeGetLengthInv4rv(real4 v_out, real4 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize4*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalize4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe4*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
//realv ijkVecCrossNormalizeSafe4rv(real4 v_out, real4 const v_lh, real4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength4*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLength4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength4*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLength4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeGetLengthInv4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
//realv ijkVecCrossNormalizeSafeGetLengthInv4rv(real4 v_out, real4 const v_lh, real4 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp4*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
//realv ijkVecLerp4rv(real4 v_out, real4 const v0, real4 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv4*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
//realv ijkVecLerpInv4rv(real4 v_out, real4 const v0, real4 const v1, real4 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit4*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
//realv ijkVecLerpRevInit4rv(real4 v0_out, real4 const v_lerp, real4 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm4*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
//realv ijkVecLerpRevTerm4rv(real4 v1_out, real4 const v0, real4 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio4*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio4rv(real4 const v_base, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj4*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
//realv ijkVecProj4rv(real4 v_out, real4 const v_base, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
//realv ijkVecOrtho4rv(real4 v_out, real4 const v_base, real4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
//realv ijkVecOrthoNorm4rv(real4 v_out, real4 const v_base, real4 const v_in, real4 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//real4* ijkVecOrthoList4rv(real4 vl_out[], real4 const v_base, real4 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//real4* ijkVecOrthoNormList4rv(real4 vl_out[], real4 const v_base, real4 const vl_in[], size const n, real4 v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq2*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength2*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv2*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe2*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv2*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe2*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize2*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec2 ijkVecNormalize2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe2*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafe2r(rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeGetLength2r(rvec2 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafeGetLength2r(rvec2 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeGetLengthInv2r(rvec2 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec2 ijkVecNormalizeSafeGetLengthInv2r(rvec2 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize2*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalize2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe2*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafe2r(rvec2 const v_lh, rvec2 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength2*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLength2r(rvec2 const v_lh, rvec2 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength2*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLength2r(rvec2 const v_lh, rvec2 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeGetLengthInv2r(rvec2 const v_lh, rvec2 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
//real ijkVecCrossNormalizeSafeGetLengthInv2r(rvec2 const v_lh, rvec2 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp2*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec2 ijkVecLerp2r(rvec2 const v0, rvec2 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv2*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec2 ijkVecLerpInv2r(rvec2 const v0, rvec2 const v1, rvec2 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit2*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec2 ijkVecLerpRevInit2r(rvec2 const v_lerp, rvec2 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm2*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec2 ijkVecLerpRevTerm2r(rvec2 const v0, rvec2 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio2*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio2r(rvec2 const v_base, rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj2*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec2 ijkVecProj2r(rvec2 const v_base, rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec2 ijkVecOrtho2r(rvec2 const v_base, rvec2 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec2 ijkVecOrthoNorm2r(rvec2 const v_base, rvec2 const v_in, rvec2* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec2* ijkVecOrthoList2r(rvec2 vl_out[], rvec2 const v_base, rvec2 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec2* ijkVecOrthoNormList2r(rvec2 vl_out[], rvec2 const v_base, rvec2 const vl_in[], size const n, rvec2* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq3*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength3*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv3*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe3*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv3*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe3*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize3*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec3 ijkVecNormalize3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe3*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafe3r(rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeGetLength3r(rvec3 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafeGetLength3r(rvec3 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeGetLengthInv3r(rvec3 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec3 ijkVecNormalizeSafeGetLengthInv3r(rvec3 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize3*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec3 ijkVecCrossNormalize3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe3*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafe3r(rvec3 const v_lh, rvec3 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength3*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeGetLength3r(rvec3 const v_lh, rvec3 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength3*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafeGetLength3r(rvec3 const v_lh, rvec3 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeGetLengthInv3r(rvec3 const v_lh, rvec3 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec3 ijkVecCrossNormalizeSafeGetLengthInv3r(rvec3 const v_lh, rvec3 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp3*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec3 ijkVecLerp3r(rvec3 const v0, rvec3 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv3*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec3 ijkVecLerpInv3r(rvec3 const v0, rvec3 const v1, rvec3 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit3*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec3 ijkVecLerpRevInit3r(rvec3 const v_lerp, rvec3 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm3*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec3 ijkVecLerpRevTerm3r(rvec3 const v0, rvec3 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio3*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio3r(rvec3 const v_base, rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj3*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec3 ijkVecProj3r(rvec3 const v_base, rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec3 ijkVecOrtho3r(rvec3 const v_base, rvec3 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec3 ijkVecOrthoNorm3r(rvec3 const v_base, rvec3 const v_in, rvec3* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec3* ijkVecOrthoList3r(rvec3 vl_out[], rvec3 const v_base, rvec3 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec3* ijkVecOrthoNormList3r(rvec3 vl_out[], rvec3 const v_base, rvec3 const vl_in[], size const n, rvec3* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSq4*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
//real ijkVecLengthSq4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLength4*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
//real ijkVecLength4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInv4*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInv4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthSqInvSafe4*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
//real ijkVecLengthSqInvSafe4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInv4*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInv4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLengthInvSafe4*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
//real ijkVecLengthInvSafe4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalize4*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec4 ijkVecNormalize4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafe4*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafe4r(rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeGetLength4r(rvec4 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafeGetLength4r(rvec4 const v_in, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeGetLengthInv4r(rvec4 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecNormalizeSafeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
//rvec4 ijkVecNormalizeSafeGetLengthInv4r(rvec4 const v_in, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalize4*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec4 ijkVecCrossNormalize4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafe4*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafe4r(rvec4 const v_lh, rvec4 const v_rh);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLength4*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeGetLength4r(rvec4 const v_lh, rvec4 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLength4*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafeGetLength4r(rvec4 const v_lh, rvec4 const v_rh, real* const length_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeGetLengthInv4r(rvec4 const v_lh, rvec4 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecCrossNormalizeSafeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
//rvec4 ijkVecCrossNormalizeSafeGetLengthInv4r(rvec4 const v_lh, rvec4 const v_rh, real* const lengthInv_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerp4*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
//rvec4 ijkVecLerp4r(rvec4 const v0, rvec4 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpInv4*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
//rvec4 ijkVecLerpInv4r(rvec4 const v0, rvec4 const v1, rvec4 const v_lerp);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevInit4*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
//rvec4 ijkVecLerpRevInit4r(rvec4 const v_lerp, rvec4 const v1, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecLerpRevTerm4*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
//rvec4 ijkVecLerpRevTerm4r(rvec4 const v0, rvec4 const v_lerp, real const u);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProjRatio4*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
//real ijkVecProjRatio4r(rvec4 const v_base, rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecProj4*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
//rvec4 ijkVecProj4r(rvec4 const v_base, rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrtho4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
//rvec4 ijkVecOrtho4r(rvec4 const v_base, rvec4 const v_in);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNorm4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
//rvec4 ijkVecOrthoNorm4r(rvec4 const v_base, rvec4 const v_in, rvec4* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoList4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
//rvec4* ijkVecOrthoList4r(rvec4 vl_out[], rvec4 const v_base, rvec4 const vl_in[], size const n);
#define func***sfx ijk_declrealfs(func,**sfx)
// ijkVecOrthoNormList4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
//rvec4* ijkVecOrthoNormList4r(rvec4 vl_out[], rvec4 const v_base, rvec4 const vl_in[], size const n, rvec4* const v_base_norm_out);
#define func***sfx ijk_declrealfs(func,**sfx)
#define func***sfx ijk_declrealfs(func,**sfx)
//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_REAL_H_
#endif	// _IJK_VECTOR_H_