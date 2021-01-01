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

	ijkVector_uintl.h
	Declarations for unsigned 64-bit integer vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_UINTL_H_
#define _IJK_VECTOR_UINTL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ui64 ijkVecAbs1uls(ui64 const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ui64 ijkVecSgn1uls(ui64 const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ui64 ijkVecDot1uls(ui64 const s_lh, ui64 const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ui64 ijkVecLengthSq1uls(ui64 const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
ui64 ijkVecLength1uls(ui64 const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
f64 ijkVecLengthSqInv1uls(ui64 const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
f64 ijkVecLengthInv1uls(ui64 const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ui64 ijkVecNormalize1uls(ui64 const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ui64 ijkVecNormalizeGetLength1uls(ui64 const s, ui64* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ui64 ijkVecNormalizeGetLengthInv1uls(ui64 const s, f64* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
uintlv ijkVecPulv(uintlv v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintlv ijkVecInit2ulv(uintl2 v_out);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
uintlv ijkVecInitElems2ulv(uintl2 v_out, ui64 const x, ui64 const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintlv ijkVecCopy2ulv(uintl2 v_out, uintl2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate2ulv(intl2 v_out, uintl2 const v_in);

// ijkVecBitNot2*v
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
uintlv ijkVecBitNot2ulv(uintl2 v_out, uintl2 const v_in);

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot2ulv(bool2 bv_out, uintl2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitAnd2*v
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitNand2*v
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitOr2*v
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitNor2*v
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitXor2*v
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitXnor2*v
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitShiftLeft2*v
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecBitShiftRight2*v
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight2ulv(uintl2 v_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2ulv(bool2 bv_out, uintl2 const v_lh, uintl2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecCopy2ulvs(uintl2 v_out, ui64 const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate2ulvs(intl2 v_out, ui64 const s_in);

// ijkVecBitNot2*vs
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecBitNot2ulvs(uintl2 v_out, ui64 const s_in);

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot2ulvs(bool2 bv_out, ui64 const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecAdd2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecSub2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMul2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDiv2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDivSafe2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMod2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecModSafe2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitAnd2*vs
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitAnd2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitNand2*vs
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNand2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitOr2*vs
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitOr2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitNor2*vs
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitXor2*vs
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitXnor2*vs
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXnor2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitShiftLeft2*vs
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftLeft2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecBitShiftRight2*vs
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftRight2ulvs(uintl2 v_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor2ulvs(bool2 bv_out, uintl2 const v_lh, ui64 const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitAnd2*sv
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitNand2*sv
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitOr2*sv
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitNor2*sv
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitXor2*sv
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitXnor2*sv
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitShiftLeft2*sv
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecBitShiftRight2*sv
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight2ulsv(uintl2 v_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2ulsv(bool2 bv_out, ui64 const s_lh, uintl2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui64 ijkVecDot2ulv(uintl2 const v_lh, uintl2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ui64 ijkVecCross2ulv(uintl2 const v_lh, uintl2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintlv ijkVecInit3ulv(uintl3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
uintlv ijkVecInitElems3ulv(uintl3 v_out, ui64 const x, ui64 const y, ui64 const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintlv ijkVecCopy3ulv(uintl3 v_out, uintl3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate3ulv(intl3 v_out, uintl3 const v_in);

// ijkVecBitNot3*v
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
uintlv ijkVecBitNot3ulv(uintl3 v_out, uintl3 const v_in);

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot3ulv(bool3 bv_out, uintl3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitAnd3*v
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitNand3*v
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitOr3*v
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitNor3*v
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitXor3*v
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitXnor3*v
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitShiftLeft3*v
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecBitShiftRight3*v
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3ulv(bool3 bv_out, uintl3 const v_lh, uintl3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
uintlv ijkVecCopy3ulvz(uintl3 v_out, uintl2 const v_xy, ui64 const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecCopy3ulvs(uintl3 v_out, ui64 const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate3ulvs(intl3 v_out, ui64 const s_in);

// ijkVecBitNot3*vs
//	Calculate bitwise 'not' of 3D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecBitNot3ulvs(uintl3 v_out, ui64 const s_in);

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot3ulvs(bool3 bv_out, ui64 const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecAdd3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecSub3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMul3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDiv3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDivSafe3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMod3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecModSafe3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitAnd3*vs
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitAnd3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitNand3*vs
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNand3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitOr3*vs
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitOr3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitNor3*vs
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitXor3*vs
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitXnor3*vs
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXnor3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitShiftLeft3*vs
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftLeft3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecBitShiftRight3*vs
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftRight3ulvs(uintl3 v_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor3ulvs(bool3 bv_out, uintl3 const v_lh, ui64 const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
uintlv ijkVecCopy3ulxv(uintl3 v_out, ui64 const x, uintl2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitAnd3*sv
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitNand3*sv
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitOr3*sv
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitNor3*sv
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitXor3*sv
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitXnor3*sv
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitShiftLeft3*sv
//	Calculate bit shift left of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecBitShiftRight3*sv
//	Calculate bit shift right of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight3ulsv(uintl3 v_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3ulsv(bool3 bv_out, ui64 const s_lh, uintl3 const v_rh);

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui64 ijkVecDot3ulv(uintl3 const v_lh, uintl3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecCross3ulv(uintl3 v_out, uintl3 const v_lh, uintl3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintlv ijkVecInit4ulv(uintl4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintlv ijkVecInitElems4ulv(uintl4 v_out, ui64 const x, ui64 const y, ui64 const z, ui64 const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintlv ijkVecCopy4ulxvw(uintl4 v_out, ui64 const x, uintl2 const v_yz, ui64 const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
uintlv ijkVecCopy4ulv2(uintl4 v_out, uintl2 const v_xy, uintl2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintlv ijkVecCopy4ulv(uintl4 v_out, uintl4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
intlv ijkVecNegate4ulv(intl4 v_out, uintl4 const v_in);

// ijkVecBitNot4*v
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
uintlv ijkVecBitNot4ulv(uintl4 v_out, uintl4 const v_in);

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot4ulv(bool4 bv_out, uintl4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitAnd4*v
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitNand4*v
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitOr4*v
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitNor4*v
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitXor4*v
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitXnor4*v
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitShiftLeft4*v
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecBitShiftRight4*v
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4ulv(bool4 bv_out, uintl4 const v_lh, uintl4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintlv ijkVecCopy4ulvzw(uintl4 v_out, uintl2 const v_xy, ui64 const z, ui64 const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintlv ijkVecCopy4ulvw(uintl4 v_out, uintl3 const v_xyz, ui64 const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecCopy4ulvs(uintl4 v_out, ui64 const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
intlv ijkVecNegate4ulvs(intl4 v_out, ui64 const s_in);

// ijkVecBitNot4*vs
//	Calculate bitwise 'not' of 4D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
uintlv ijkVecBitNot4ulvs(uintl4 v_out, ui64 const s_in);

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot4ulvs(bool4 bv_out, ui64 const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecAdd4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecSub4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMul4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDiv4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecDivSafe4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecMod4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecModSafe4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitAnd4*vs
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitAnd4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitNand4*vs
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNand4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitOr4*vs
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitOr4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitNor4*vs
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitNor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitXor4*vs
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitXnor4*vs
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitXnor4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitShiftLeft4*vs
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftLeft4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecBitShiftRight4*vs
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintlv ijkVecBitShiftRight4ulvs(uintl4 v_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor4ulvs(bool4 bv_out, uintl4 const v_lh, ui64 const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
uintlv ijkVecCopy4ulxyv(uintl4 v_out, ui64 const x, ui64 const y, uintl2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
uintlv ijkVecCopy4ulxv(uintl4 v_out, ui64 const x, uintl3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecAdd4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecSub4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMul4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDiv4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecDivSafe4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecMod4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecModSafe4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitAnd4*sv
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitAnd4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitNand4*sv
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNand4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitOr4*sv
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitOr4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitNor4*sv
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitNor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitXor4*sv
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitXnor4*sv
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitXnor4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitShiftLeft4*sv
//	Calculate bit shift left of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftLeft4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecBitShiftRight4*sv
//	Calculate bit shift right of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintlv ijkVecBitShiftRight4ulsv(uintl4 v_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4ulsv(bool4 bv_out, ui64 const s_lh, uintl4 const v_rh);

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui64 ijkVecDot4ulv(uintl4 const v_lh, uintl4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
uintlv ijkVecCross4ulv(uintl4 v_out, uintl4 const v_lh, uintl4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
uintl ijkVecAbs1ul(uintl const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
uintl ijkVecSgn1ul(uintl const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
uintl ijkVecDot1ul(uintl const s_lh, uintl const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
uintl ijkVecLengthSq1ul(uintl const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
uintl ijkVecLength1ul(uintl const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
double ijkVecLengthSqInv1ul(uintl const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
double ijkVecLengthInv1ul(uintl const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
uintl ijkVecNormalize1ul(uintl const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
uintl ijkVecNormalizeGetLength1ul(uintl const s, uintl* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
uintl ijkVecNormalizeGetLengthInv1ul(uintl const s, double* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
ulvec2 ijkVecInit2ul();

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
ulvec2 ijkVecInitElems2ul(uintl const x, uintl const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ulvec2 ijkVecCopy2ul(ulvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
ilvec2 ijkVecNegate2ul(ulvec2 const v_in);

// ijkVecBitNot2*
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_in: input vector
//		return: result vector
ulvec2 ijkVecBitNot2ul(ulvec2 const v_in);

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
bvec2 ijkVecNot2ul(ulvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecAdd2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecSub2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecMul2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecDiv2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecDivSafe2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecMod2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecModSafe2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitAnd2*
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitAnd2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitNand2*
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitNand2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitOr2*
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitOr2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitNor2*
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitNor2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitXor2*
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitXor2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitXnor2*
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitXnor2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitShiftLeft2*
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitShiftLeft2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecBitShiftRight2*
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitShiftRight2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ulvec2 ijkVecCopy2uls(uintl const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
ilvec2 ijkVecNegate2uls(uintl const s_in);

// ijkVecBitNot2*s
//	Calculate bitwise 'not' of 2D vector.
//		param s_in: input scalar
//		return: result vector
ulvec2 ijkVecBitNot2uls(uintl const s_in);

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec2 ijkVecNot2uls(uintl const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecAdd2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecSub2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecMul2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecDiv2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecDivSafe2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecMod2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecModSafe2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitAnd2*s
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitAnd2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitNand2*s
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitNand2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitOr2*s
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitOr2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitNor2*s
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitNor2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitXor2*s
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitXor2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitXnor2*s
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitXnor2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitShiftLeft2*s
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitShiftLeft2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecBitShiftRight2*s
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec2 ijkVecBitShiftRight2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecEqual2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecInequal2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLessEqual2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreaterEqual2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLess2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreater2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecAnd2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNand2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecOr2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNor2uls(ulvec2 const v_lh, uintl const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecAdd2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecSub2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecMul2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecDiv2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecDivSafe2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecMod2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecModSafe2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitAnd2s*
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitAnd2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitNand2s*
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitNand2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitOr2s*
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitOr2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitNor2s*
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitNor2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitXor2s*
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitXor2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitXnor2s*
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitXnor2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitShiftLeft2s*
//	Calculate bit shift left of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitShiftLeft2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecBitShiftRight2s*
//	Calculate bit shift right of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec2 ijkVecBitShiftRight2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2sul(uintl const s_lh, ulvec2 const v_rh);

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uintl ijkVecDot2ul(ulvec2 const v_lh, ulvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
uintl ijkVecCross2ul(ulvec2 const v_lh, ulvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
ulvec3 ijkVecInit3ul();

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
ulvec3 ijkVecInitElems3ul(uintl const x, uintl const y, uintl const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ulvec3 ijkVecCopy3ul(ulvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
ilvec3 ijkVecNegate3ul(ulvec3 const v_in);

// ijkVecBitNot3*
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_in: input vector
//		return: result vector
ulvec3 ijkVecBitNot3ul(ulvec3 const v_in);

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
bvec3 ijkVecNot3ul(ulvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecAdd3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecSub3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecMul3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecDiv3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecDivSafe3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecMod3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecModSafe3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitAnd3*
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitAnd3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitNand3*
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitNand3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitOr3*
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitOr3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitNor3*
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitNor3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitXor3*
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitXor3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitXnor3*
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitXnor3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitShiftLeft3*
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitShiftLeft3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecBitShiftRight3*
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitShiftRight3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
ulvec3 ijkVecCopy3ulz(ulvec2 const v_xy, uintl const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ulvec3 ijkVecCopy3uls(uintl const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
ilvec3 ijkVecNegate3uls(uintl const s_in);

// ijkVecBitNot3*s
//	Calculate bitwise 'not' of 3D vector.
//		param s_in: input scalar
//		return: result vector
ulvec3 ijkVecBitNot3uls(uintl const s_in);

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec3 ijkVecNot3uls(uintl const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecAdd3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecSub3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecMul3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecDiv3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecDivSafe3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecMod3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecModSafe3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitAnd3*s
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitAnd3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitNand3*s
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitNand3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitOr3*s
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitOr3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitNor3*s
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitNor3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitXor3*s
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitXor3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitXnor3*s
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitXnor3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitShiftLeft3*s
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitShiftLeft3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecBitShiftRight3*s
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec3 ijkVecBitShiftRight3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecEqual3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecInequal3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLessEqual3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreaterEqual3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLess3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreater3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecAnd3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNand3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecOr3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNor3uls(ulvec3 const v_lh, uintl const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
ulvec3 ijkVecCopy3xul(uintl const x, ulvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecAdd3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecSub3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecMul3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecDiv3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecDivSafe3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecMod3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecModSafe3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitAnd3s*
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitAnd3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitNand3s*
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitNand3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitOr3s*
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitOr3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitNor3s*
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitNor3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitXor3s*
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitXor3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitXnor3s*
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitXnor3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitShiftLeft3s*
//	Calculate bit shift left of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitShiftLeft3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecBitShiftRight3s*
//	Calculate bit shift right of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec3 ijkVecBitShiftRight3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3sul(uintl const s_lh, ulvec3 const v_rh);

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uintl ijkVecDot3ul(ulvec3 const v_lh, ulvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
ulvec3 ijkVecCross3ul(ulvec3 const v_lh, ulvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
ulvec4 ijkVecInit4ul();

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
ulvec4 ijkVecInitElems4ul(uintl const x, uintl const y, uintl const z, uintl const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
ulvec4 ijkVecCopy4xulw(uintl const x, ulvec2 const v_yz, uintl const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
ulvec4 ijkVecCopy4ul2(ulvec2 const v_xy, ulvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
ulvec4 ijkVecCopy4ul(ulvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
ilvec4 ijkVecNegate4ul(ulvec4 const v_in);

// ijkVecBitNot4*
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_in: input vector
//		return: result vector
ulvec4 ijkVecBitNot4ul(ulvec4 const v_in);

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
bvec4 ijkVecNot4ul(ulvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecAdd4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecSub4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecMul4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecDiv4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecDivSafe4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecMod4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecModSafe4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitAnd4*
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitAnd4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitNand4*
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitNand4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitOr4*
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitOr4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitNor4*
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitNor4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitXor4*
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitXor4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitXnor4*
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitXnor4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitShiftLeft4*
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitShiftLeft4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecBitShiftRight4*
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitShiftRight4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
ulvec4 ijkVecCopy4ulzw(ulvec2 const v_xy, uintl const z, uintl const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
ulvec4 ijkVecCopy4ulw(ulvec3 const v_xyz, uintl const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
ulvec4 ijkVecCopy4uls(uintl const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
ilvec4 ijkVecNegate4uls(uintl const s_in);

// ijkVecBitNot4*s
//	Calculate bitwise 'not' of 4D vector.
//		param s_in: input scalar
//		return: result vector
ulvec4 ijkVecBitNot4uls(uintl const s_in);

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec4 ijkVecNot4uls(uintl const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecAdd4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecSub4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecMul4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecDiv4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecDivSafe4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecMod4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecModSafe4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitAnd4*s
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitAnd4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitNand4*s
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitNand4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitOr4*s
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitOr4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitNor4*s
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitNor4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitXor4*s
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitXor4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitXnor4*s
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitXnor4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitShiftLeft4*s
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitShiftLeft4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecBitShiftRight4*s
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
ulvec4 ijkVecBitShiftRight4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecEqual4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecInequal4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLessEqual4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreaterEqual4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLess4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreater4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecAnd4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNand4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecOr4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNor4uls(ulvec4 const v_lh, uintl const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
ulvec4 ijkVecCopy4xyul(uintl const x, uintl const y, ulvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
ulvec4 ijkVecCopy4xul(uintl const x, ulvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecAdd4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecSub4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecMul4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecDiv4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecDivSafe4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecMod4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecModSafe4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitAnd4s*
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitAnd4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitNand4s*
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitNand4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitOr4s*
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitOr4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitNor4s*
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitNor4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitXor4s*
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitXor4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitXnor4s*
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitXnor4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitShiftLeft4s*
//	Calculate bit shift left of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitShiftLeft4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecBitShiftRight4s*
//	Calculate bit shift right of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
ulvec4 ijkVecBitShiftRight4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4sul(uintl const s_lh, ulvec4 const v_rh);

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uintl ijkVecDot4ul(ulvec4 const v_lh, ulvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
ulvec4 ijkVecCross4ul(ulvec4 const v_lh, ulvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_uintl.inl"


#endif	// !_IJK_VECTOR_UINTL_H_
#endif	// _IJK_VECTOR_H_