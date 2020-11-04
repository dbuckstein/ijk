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

	ijkVector_intl.h
	Declarations for signed 64-bit integer vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_INTL_H_
#define _IJK_VECTOR_INTL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
i64 ijkVecAbs1ils(i64 const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
i64 ijkVecSgn1ils(i64 const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
i64 ijkVecDot1ils(i64 const s_lh, i64 const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
i64 ijkVecLengthSq1ils(i64 const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
i64 ijkVecLength1ils(i64 const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
f64 ijkVecLengthSqInv1ils(i64 const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
f64 ijkVecLengthInv1ils(i64 const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
i64 ijkVecNormalize1ils(i64 const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
i64 ijkVecNormalizeGetLength1ils(i64 const s, i64* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
i64 ijkVecNormalizeGetLengthInv1ils(i64 const s, f64* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
intlv ijkVecPiv(intlv v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
intlv ijkVecInit2ilv(intl2 v_out);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
intlv ijkVecInitElems2ilv(intl2 v_out, i64 const x, i64 const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
intlv ijkVecCopy2ilv(intl2 v_out, intl2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate2ilv(intl2 v_out, intl2 const v_in);

// ijkVecBitNot2*v
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
intlv ijkVecBitNot2ilv(intl2 v_out, intl2 const v_in);

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot2ilv(bool2 bv_out, intl2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitAnd2*v
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitNand2*v
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitOr2*v
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitNor2*v
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitXor2*v
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitXnor2*v
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitShiftLeft2*v
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecBitShiftRight2*v
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight2ilv(intl2 v_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2ilv(bool2 bv_out, intl2 const v_lh, intl2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
intlv ijkVecCopy2ilvs(intl2 v_out, i64 const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate2ilvs(intl2 v_out, i64 const s_in);

// ijkVecBitNot2*vs
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
intlv ijkVecBitNot2ilvs(intl2 v_out, i64 const s_in);

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot2ilvs(bool2 bv_out, i64 const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecAdd2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecSub2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMul2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDiv2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDivSafe2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMod2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecModSafe2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitAnd2*vs
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitAnd2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitNand2*vs
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNand2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitOr2*vs
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitOr2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitNor2*vs
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitXor2*vs
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitXnor2*vs
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXnor2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitShiftLeft2*vs
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftLeft2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecBitShiftRight2*vs
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftRight2ilvs(intl2 v_out, intl2 const v_lh, i64 const s_rh);

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor2ilvs(bool2 bv_out, intl2 const v_lh, i64 const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitAnd2*sv
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitNand2*sv
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitOr2*sv
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitNor2*sv
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitXor2*sv
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitXnor2*sv
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitShiftLeft2*sv
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecBitShiftRight2*sv
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight2ilsv(intl2 v_out, i64 const s_lh, intl2 const v_rh);

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2ilsv(bool2 bv_out, i64 const s_lh, intl2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
i64 ijkVecDot2ilv(intl2 const v_lh, intl2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
i64 ijkVecCross2ilv(intl2 const v_lh, intl2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
intlv ijkVecInit3ilv(intl3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
intlv ijkVecInitElems3ilv(intl3 v_out, i64 const x, i64 const y, i64 const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
intlv ijkVecCopy3ilv(intl3 v_out, intl3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate3ilv(intl3 v_out, intl3 const v_in);

// ijkVecBitNot3*v
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
intlv ijkVecBitNot3ilv(intl3 v_out, intl3 const v_in);

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot3ilv(bool3 bv_out, intl3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitAnd3*v
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitNand3*v
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitOr3*v
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitNor3*v
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitXor3*v
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitXnor3*v
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitShiftLeft3*v
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecBitShiftRight3*v
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3ilv(bool3 bv_out, intl3 const v_lh, intl3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
intlv ijkVecCopy3ilvz(intl3 v_out, intl2 const v_xy, i64 const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
intlv ijkVecCopy3ilvs(intl3 v_out, i64 const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate3ilvs(intl3 v_out, i64 const s_in);

// ijkVecBitNot3*vs
//	Calculate bitwise 'not' of 3D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
intlv ijkVecBitNot3ilvs(intl3 v_out, i64 const s_in);

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot3ilvs(bool3 bv_out, i64 const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecAdd3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecSub3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMul3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDiv3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDivSafe3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMod3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecModSafe3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitAnd3*vs
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitAnd3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitNand3*vs
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNand3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitOr3*vs
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitOr3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitNor3*vs
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitXor3*vs
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitXnor3*vs
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXnor3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitShiftLeft3*vs
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftLeft3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecBitShiftRight3*vs
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftRight3ilvs(intl3 v_out, intl3 const v_lh, i64 const s_rh);

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor3ilvs(bool3 bv_out, intl3 const v_lh, i64 const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
intlv ijkVecCopy3ilxv(intl3 v_out, i64 const x, intl2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitAnd3*sv
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitNand3*sv
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitOr3*sv
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitNor3*sv
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitXor3*sv
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitXnor3*sv
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitShiftLeft3*sv
//	Calculate bit shift left of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecBitShiftRight3*sv
//	Calculate bit shift right of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight3ilsv(intl3 v_out, i64 const s_lh, intl3 const v_rh);

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3ilsv(bool3 bv_out, i64 const s_lh, intl3 const v_rh);

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
i64 ijkVecDot3ilv(intl3 const v_lh, intl3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecCross3ilv(intl3 v_out, intl3 const v_lh, intl3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
intlv ijkVecInit4ilv(intl4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
intlv ijkVecInitElems4ilv(intl4 v_out, i64 const x, i64 const y, i64 const z, i64 const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
intlv ijkVecCopy4ilxvw(intl4 v_out, i64 const x, intl2 const v_yz, i64 const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
intlv ijkVecCopy4ilv2(intl4 v_out, intl2 const v_xy, intl2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
intlv ijkVecCopy4ilv(intl4 v_out, intl4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate4ilv(intl4 v_out, intl4 const v_in);

// ijkVecBitNot4*v
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
intlv ijkVecBitNot4ilv(intl4 v_out, intl4 const v_in);

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot4ilv(bool4 bv_out, intl4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitAnd4*v
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitNand4*v
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitOr4*v
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitNor4*v
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitXor4*v
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitXnor4*v
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitShiftLeft4*v
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecBitShiftRight4*v
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4ilv(bool4 bv_out, intl4 const v_lh, intl4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
intlv ijkVecCopy4ilvzw(intl4 v_out, intl2 const v_xy, i64 const z, i64 const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: v_out
intlv ijkVecCopy4ilvw(intl4 v_out, intl3 const v_xyz, i64 const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
intlv ijkVecCopy4ilvs(intl4 v_out, i64 const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate4ilvs(intl4 v_out, i64 const s_in);

// ijkVecBitNot4*vs
//	Calculate bitwise 'not' of 4D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
intlv ijkVecBitNot4ilvs(intl4 v_out, i64 const s_in);

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot4ilvs(bool4 bv_out, i64 const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecAdd4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecSub4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMul4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDiv4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecDivSafe4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecMod4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecModSafe4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitAnd4*vs
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitAnd4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitNand4*vs
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNand4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitOr4*vs
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitOr4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitNor4*vs
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitNor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitXor4*vs
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitXnor4*vs
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitXnor4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitShiftLeft4*vs
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftLeft4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecBitShiftRight4*vs
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
intlv ijkVecBitShiftRight4ilvs(intl4 v_out, intl4 const v_lh, i64 const s_rh);

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor4ilvs(bool4 bv_out, intl4 const v_lh, i64 const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
intlv ijkVecCopy4ilxyv(intl4 v_out, i64 const x, i64 const y, intl2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
intlv ijkVecCopy4ilxv(intl4 v_out, i64 const x, intl3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecAdd4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecSub4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMul4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDiv4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecDivSafe4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecMod4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecModSafe4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitAnd4*sv
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitAnd4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitNand4*sv
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNand4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitOr4*sv
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitOr4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitNor4*sv
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitNor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitXor4*sv
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitXnor4*sv
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitXnor4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitShiftLeft4*sv
//	Calculate bit shift left of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftLeft4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecBitShiftRight4*sv
//	Calculate bit shift right of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
intlv ijkVecBitShiftRight4ilsv(intl4 v_out, i64 const s_lh, intl4 const v_rh);

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4ilsv(bool4 bv_out, i64 const s_lh, intl4 const v_rh);

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
i64 ijkVecDot4ilv(intl4 const v_lh, intl4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
intlv ijkVecCross4ilv(intl4 v_out, intl4 const v_lh, intl4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
int ijkVecAbs1il(int const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
int ijkVecSgn1il(int const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
int ijkVecDot1il(int const s_lh, int const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
int ijkVecLengthSq1il(int const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
int ijkVecLength1il(int const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
float ijkVecLengthSqInv1il(int const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
float ijkVecLengthInv1il(int const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
int ijkVecNormalize1il(int const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
int ijkVecNormalizeGetLength1il(int const s, int* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
int ijkVecNormalizeGetLengthInv1il(int const s, float* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
ilvec2 ijkVecInit2il();

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
ilvec2 ijkVecInitElems2il(int const x, int const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ilvec2 ijkVecCopy2il(ilvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
ilvec2 ijkVecNegate2il(ilvec2 const v_in);

// ijkVecBitNot2*
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_in: input vector
//		return: result vector
ilvec2 ijkVecBitNot2il(ilvec2 const v_in);

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
bvec2 ijkVecNot2il(ilvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecAdd2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecSub2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecMul2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecDiv2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecDivSafe2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecMod2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecModSafe2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitAnd2*
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitAnd2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitNand2*
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitNand2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitOr2*
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitOr2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitNor2*
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitNor2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitXor2*
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitXor2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitXnor2*
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitXnor2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitShiftLeft2*
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitShiftLeft2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecBitShiftRight2*
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitShiftRight2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ilvec2 ijkVecCopy2ils(int const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
ilvec2 ijkVecNegate2ils(int const s_in);

// ijkVecBitNot2*s
//	Calculate bitwise 'not' of 2D vector.
//		param s_in: input scalar
//		return: result vector
ilvec2 ijkVecBitNot2ils(int const s_in);

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec2 ijkVecNot2ils(int const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecAdd2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecSub2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecMul2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecDiv2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecDivSafe2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecMod2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecModSafe2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitAnd2*s
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitAnd2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitNand2*s
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitNand2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitOr2*s
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitOr2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitNor2*s
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitNor2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitXor2*s
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitXor2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitXnor2*s
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitXnor2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitShiftLeft2*s
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitShiftLeft2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecBitShiftRight2*s
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec2 ijkVecBitShiftRight2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecEqual2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecInequal2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLessEqual2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreaterEqual2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLess2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreater2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecAnd2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNand2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecOr2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNor2ils(ilvec2 const v_lh, int const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecAdd2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecSub2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecMul2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecDiv2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecDivSafe2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecMod2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecModSafe2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitAnd2s*
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitAnd2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitNand2s*
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitNand2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitOr2s*
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitOr2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitNor2s*
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitNor2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitXor2s*
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitXor2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitXnor2s*
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitXnor2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitShiftLeft2s*
//	Calculate bit shift left of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitShiftLeft2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecBitShiftRight2s*
//	Calculate bit shift right of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec2 ijkVecBitShiftRight2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2sil(int const s_lh, ilvec2 const v_rh);

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
int ijkVecDot2il(ilvec2 const v_lh, ilvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
int ijkVecCross2il(ilvec2 const v_lh, ilvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
ilvec3 ijkVecInit3il();

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
ilvec3 ijkVecInitElems3il(int const x, int const y, int const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ilvec3 ijkVecCopy3il(ilvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
ilvec3 ijkVecNegate3il(ilvec3 const v_in);

// ijkVecBitNot3*
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_in: input vector
//		return: result vector
ilvec3 ijkVecBitNot3il(ilvec3 const v_in);

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
bvec3 ijkVecNot3il(ilvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecAdd3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecSub3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecMul3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecDiv3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecDivSafe3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecMod3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecModSafe3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitAnd3*
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitAnd3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitNand3*
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitNand3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitOr3*
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitOr3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitNor3*
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitNor3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitXor3*
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitXor3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitXnor3*
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitXnor3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitShiftLeft3*
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitShiftLeft3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecBitShiftRight3*
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitShiftRight3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
ilvec3 ijkVecCopy3ilz(ilvec2 const v_xy, int const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ilvec3 ijkVecCopy3ils(int const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
ilvec3 ijkVecNegate3ils(int const s_in);

// ijkVecBitNot3*s
//	Calculate bitwise 'not' of 3D vector.
//		param s_in: input scalar
//		return: result vector
ilvec3 ijkVecBitNot3ils(int const s_in);

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec3 ijkVecNot3ils(int const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecAdd3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecSub3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecMul3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecDiv3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecDivSafe3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecMod3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecModSafe3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitAnd3*s
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitAnd3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitNand3*s
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitNand3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitOr3*s
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitOr3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitNor3*s
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitNor3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitXor3*s
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitXor3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitXnor3*s
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitXnor3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitShiftLeft3*s
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitShiftLeft3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecBitShiftRight3*s
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec3 ijkVecBitShiftRight3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecEqual3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecInequal3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLessEqual3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreaterEqual3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLess3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreater3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecAnd3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNand3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecOr3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNor3ils(ilvec3 const v_lh, int const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
ilvec3 ijkVecCopy3xi(int const x, ilvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecAdd3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecSub3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecMul3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecDiv3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecDivSafe3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecMod3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecModSafe3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitAnd3s*
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitAnd3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitNand3s*
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitNand3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitOr3s*
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitOr3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitNor3s*
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitNor3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitXor3s*
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitXor3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitXnor3s*
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitXnor3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitShiftLeft3s*
//	Calculate bit shift left of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitShiftLeft3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecBitShiftRight3s*
//	Calculate bit shift right of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec3 ijkVecBitShiftRight3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3sil(int const s_lh, ilvec3 const v_rh);

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
int ijkVecDot3il(ilvec3 const v_lh, ilvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
ilvec3 ijkVecCross3il(ilvec3 const v_lh, ilvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
ilvec4 ijkVecInit4il();

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: result vector
ilvec4 ijkVecInitElems4il(int const x, int const y, int const z, int const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: result vector
ilvec4 ijkVecCopy4xiw(int const x, ilvec2 const v_yz, int const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
ilvec4 ijkVecCopy4il2(ilvec2 const v_xy, ilvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ilvec4 ijkVecCopy4il(ilvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
ilvec4 ijkVecNegate4il(ilvec4 const v_in);

// ijkVecBitNot4*
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_in: input vector
//		return: result vector
ilvec4 ijkVecBitNot4il(ilvec4 const v_in);

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
bvec4 ijkVecNot4il(ilvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecAdd4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecSub4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecMul4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecDiv4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecDivSafe4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecMod4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecModSafe4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitAnd4*
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitAnd4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitNand4*
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitNand4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitOr4*
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitOr4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitNor4*
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitNor4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitXor4*
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitXor4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitXnor4*
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitXnor4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitShiftLeft4*
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitShiftLeft4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecBitShiftRight4*
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitShiftRight4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: result vector
ilvec4 ijkVecCopy4ilzw(ilvec2 const v_xy, int const z, int const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for point, 0 for vector)
//		return: result vector
ilvec4 ijkVecCopy4ilw(ilvec3 const v_xyz, int const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ilvec4 ijkVecCopy4ils(int const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
ilvec4 ijkVecNegate4ils(int const s_in);

// ijkVecBitNot4*s
//	Calculate bitwise 'not' of 4D vector.
//		param s_in: input scalar
//		return: result vector
ilvec4 ijkVecBitNot4ils(int const s_in);

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec4 ijkVecNot4ils(int const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecAdd4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecSub4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecMul4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecDiv4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecDivSafe4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecMod4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecModSafe4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitAnd4*s
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitAnd4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitNand4*s
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitNand4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitOr4*s
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitOr4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitNor4*s
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitNor4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitXor4*s
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitXor4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitXnor4*s
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitXnor4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitShiftLeft4*s
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitShiftLeft4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecBitShiftRight4*s
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ilvec4 ijkVecBitShiftRight4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecEqual4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecInequal4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLessEqual4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreaterEqual4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLess4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreater4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecAnd4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNand4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecOr4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNor4ils(ilvec4 const v_lh, int const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
ilvec4 ijkVecCopy4xyi(int const x, int const y, ilvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
ilvec4 ijkVecCopy4xi(int const x, ilvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecAdd4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecSub4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecMul4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecDiv4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecDivSafe4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecMod4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecModSafe4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitAnd4s*
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitAnd4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitNand4s*
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitNand4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitOr4s*
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitOr4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitNor4s*
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitNor4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitXor4s*
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitXor4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitXnor4s*
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitXnor4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitShiftLeft4s*
//	Calculate bit shift left of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitShiftLeft4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecBitShiftRight4s*
//	Calculate bit shift right of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ilvec4 ijkVecBitShiftRight4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4sil(int const s_lh, ilvec4 const v_rh);

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
int ijkVecDot4il(ilvec4 const v_lh, ilvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
ilvec4 ijkVecCross4il(ilvec4 const v_lh, ilvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_intl.inl"


#endif	// !_IJK_VECTOR_INTL_H_
#endif	// _IJK_VECTOR_H_