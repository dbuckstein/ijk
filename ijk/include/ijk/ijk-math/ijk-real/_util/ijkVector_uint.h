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

	ijkVector_uuint.h
	Declarations for unsigned 32-bit uinteger vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_UINT_H_
#define _IJK_VECTOR_UINT_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
ui32 ijkVecAbs1us(ui32 const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
ui32 ijkVecSgn1us(ui32 const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
ui32 ijkVecDot1us(ui32 const s_lh, ui32 const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
ui32 ijkVecLengthSq1us(ui32 const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
ui32 ijkVecLength1us(ui32 const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
f32 ijkVecLengthSqInv1us(ui32 const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
f32 ijkVecLengthInv1us(ui32 const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
ui32 ijkVecNormalize1us(ui32 const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
ui32 ijkVecNormalizeGetLength1us(ui32 const s, ui32* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
ui32 ijkVecNormalizeGetLengthInv1us(ui32 const s, f32* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
uintv ijkVecPuv(uintv v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintv ijkVecInit2uv(uint2 v_out);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
uintv ijkVecInitElems2uv(uint2 v_out, ui32 const x, ui32 const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintv ijkVecCopy2uv(uint2 v_out, uint2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
#if TSIGNED
uintv ijkVecNegate2uv(uint2 v_out, uint2 const v_in);
#endif	// TSIGNED

// ijkVecBitNot2*v
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot2uv(uint2 v_out, uint2 const v_in);
#endif	// TINTEGER

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot2uv(bool2 bv_out, uint2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

#if TINTEGER
// ijkVecBitAnd2*v
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitNand2*v
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitOr2*v
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitNor2*v
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitXor2*v
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitXnor2*v
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitShiftLeft2*v
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecBitShiftRight2*v
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight2uv(uint2 v_out, uint2 const v_lh, uint2 const v_rh);
#endif	// TINTEGER

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2uv(bool2 bv_out, uint2 const v_lh, uint2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintv ijkVecCopy2uvs(uint2 v_out, ui32 const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
#if TSIGNED
uintv ijkVecNegate2uvs(uint2 v_out, ui32 const s_in);
#endif	// TSIGNED

// ijkVecBitNot2*vs
//	Calculate bitwise 'not' of 2D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot2uvs(uint2 v_out, ui32 const s_in);
#endif	// TINTEGER

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot2uvs(bool2 bv_out, ui32 const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecAdd2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecSub2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMul2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDiv2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDivSafe2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMod2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecModSafe2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

#if TINTEGER
// ijkVecBitAnd2*vs
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitAnd2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitNand2*vs
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNand2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitOr2*vs
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitOr2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitNor2*vs
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitXor2*vs
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitXnor2*vs
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXnor2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitShiftLeft2*vs
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftLeft2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecBitShiftRight2*vs
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftRight2uvs(uint2 v_out, uint2 const v_lh, ui32 const s_rh);
#endif	// TINTEGER

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor2uvs(bool2 bv_out, uint2 const v_lh, ui32 const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

#if TINTEGER
// ijkVecBitAnd2*sv
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitNand2*sv
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitOr2*sv
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitNor2*sv
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitXor2*sv
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitXnor2*sv
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitShiftLeft2*sv
//	Calculate bit shift left of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecBitShiftRight2*sv
//	Calculate bit shift right of scalar by 2D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight2usv(uint2 v_out, ui32 const s_lh, uint2 const v_rh);
#endif	// TINTEGER

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2usv(bool2 bv_out, ui32 const s_lh, uint2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui32 ijkVecDot2uv(uint2 const v_lh, uint2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
ui32 ijkVecCross2uv(uint2 const v_lh, uint2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintv ijkVecInit3uv(uint3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
uintv ijkVecInitElems3uv(uint3 v_out, ui32 const x, ui32 const y, ui32 const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintv ijkVecCopy3uv(uint3 v_out, uint3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
#if TSIGNED
uintv ijkVecNegate3uv(uint3 v_out, uint3 const v_in);
#endif	// TSIGNED

// ijkVecBitNot3*v
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot3uv(uint3 v_out, uint3 const v_in);
#endif	// TINTEGER

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot3uv(bool3 bv_out, uint3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

#if TINTEGER
// ijkVecBitAnd3*v
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitNand3*v
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitOr3*v
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitNor3*v
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitXor3*v
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitXnor3*v
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitShiftLeft3*v
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecBitShiftRight3*v
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);
#endif	// TINTEGER

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3uv(bool3 bv_out, uint3 const v_lh, uint3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
uintv ijkVecCopy3uvz(uint3 v_out, uint2 const v_xy, ui32 const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintv ijkVecCopy3uvs(uint3 v_out, ui32 const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
#if TSIGNED
uintv ijkVecNegate3uvs(uint3 v_out, ui32 const s_in);
#endif	// TSIGNED

// ijkVecBitNot3*vs
//	Calculate bitwise 'not' of 3D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot3uvs(uint3 v_out, ui32 const s_in);
#endif	// TINTEGER

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot3uvs(bool3 bv_out, ui32 const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecAdd3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecSub3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMul3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDiv3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDivSafe3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMod3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecModSafe3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

#if TINTEGER
// ijkVecBitAnd3*vs
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitAnd3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitNand3*vs
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNand3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitOr3*vs
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitOr3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitNor3*vs
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitXor3*vs
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitXnor3*vs
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXnor3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitShiftLeft3*vs
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftLeft3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecBitShiftRight3*vs
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftRight3uvs(uint3 v_out, uint3 const v_lh, ui32 const s_rh);
#endif	// TINTEGER

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor3uvs(bool3 bv_out, uint3 const v_lh, ui32 const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
uintv ijkVecCopy3uxv(uint3 v_out, ui32 const x, uint2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

#if TINTEGER
// ijkVecBitAnd3*sv
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitNand3*sv
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitOr3*sv
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitNor3*sv
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitXor3*sv
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitXnor3*sv
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitShiftLeft3*sv
//	Calculate bit shift left of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecBitShiftRight3*sv
//	Calculate bit shift right of scalar by 3D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight3usv(uint3 v_out, ui32 const s_lh, uint3 const v_rh);
#endif	// TINTEGER

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3usv(bool3 bv_out, ui32 const s_lh, uint3 const v_rh);

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui32 ijkVecDot3uv(uint3 const v_lh, uint3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecCross3uv(uint3 v_out, uint3 const v_lh, uint3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
uintv ijkVecInit4uv(uint4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintv ijkVecInitElems4uv(uint4 v_out, ui32 const x, ui32 const y, ui32 const z, ui32 const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintv ijkVecCopy4uxvw(uint4 v_out, ui32 const x, uint2 const v_yz, ui32 const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
uintv ijkVecCopy4uv2(uint4 v_out, uint2 const v_xy, uint2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
uintv ijkVecCopy4uv(uint4 v_out, uint4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
#if TSIGNED
uintv ijkVecNegate4uv(uint4 v_out, uint4 const v_in);
#endif	// TSIGNED

// ijkVecBitNot4*v
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_out: output vector to hold component-wise bitwise 'not'
//		param v_in: input vector
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot4uv(uint4 v_out, uint4 const v_in);
#endif	// TINTEGER

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot4uv(bool4 bv_out, uint4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

#if TINTEGER
// ijkVecBitAnd4*v
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'and'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitNand4*v
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nand'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitOr4*v
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'or'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitNor4*v
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitXor4*v
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'xor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitXnor4*v
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_out: output vector to hold component-wise bitwise 'nxor'
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitShiftLeft4*v
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecBitShiftRight4*v
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_out: output vector to hold component-wise bit shift
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);
#endif	// TINTEGER

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4uv(bool4 bv_out, uint4 const v_lh, uint4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintv ijkVecCopy4uvzw(uint4 v_out, uint2 const v_xy, ui32 const z, ui32 const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: v_out
uintv ijkVecCopy4uvw(uint4 v_out, uint3 const v_xyz, ui32 const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
uintv ijkVecCopy4uvs(uint4 v_out, ui32 const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
#if TSIGNED
uintv ijkVecNegate4uvs(uint4 v_out, ui32 const s_in);
#endif	// TSIGNED

// ijkVecBitNot4*vs
//	Calculate bitwise 'not' of 4D vector.
//		param v_out: output vector to hold bitwise 'not'
//		param s_in: input scalar
//		return: v_out
#if TINTEGER
uintv ijkVecBitNot4uvs(uint4 v_out, ui32 const s_in);
#endif	// TINTEGER

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot4uvs(bool4 bv_out, ui32 const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecAdd4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecSub4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMul4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDiv4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecDivSafe4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecMod4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecModSafe4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

#if TINTEGER
// ijkVecBitAnd4*vs
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'and'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitAnd4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitNand4*vs
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nand'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNand4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitOr4*vs
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'or'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitOr4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitNor4*vs
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitNor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitXor4*vs
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'xor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitXnor4*vs
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_out: output vector to hold bitwise 'nxor'
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitXnor4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitShiftLeft4*vs
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftLeft4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecBitShiftRight4*vs
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_out: output vector to hold bit shift
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
uintv ijkVecBitShiftRight4uvs(uint4 v_out, uint4 const v_lh, ui32 const s_rh);
#endif	// TINTEGER

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor4uvs(bool4 bv_out, uint4 const v_lh, ui32 const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
uintv ijkVecCopy4uxyv(uint4 v_out, ui32 const x, ui32 const y, uint2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
uintv ijkVecCopy4uxv(uint4 v_out, ui32 const x, uint3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecAdd4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecSub4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMul4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDiv4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecDivSafe4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecMod4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecModSafe4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

#if TINTEGER
// ijkVecBitAnd4*sv
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'and'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitAnd4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitNand4*sv
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nand'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNand4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitOr4*sv
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'or'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitOr4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitNor4*sv
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitNor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitXor4*sv
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'xor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitXnor4*sv
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param v_out: output vector to hold bitwise 'nxor'
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitXnor4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitShiftLeft4*sv
//	Calculate bit shift left of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftLeft4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecBitShiftRight4*sv
//	Calculate bit shift right of scalar by 4D vector components.
//		param v_out: output vector to hold bit shift
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
uintv ijkVecBitShiftRight4usv(uint4 v_out, ui32 const s_lh, uint4 const v_rh);
#endif	// TINTEGER

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4usv(bool4 bv_out, ui32 const s_lh, uint4 const v_rh);

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
ui32 ijkVecDot4uv(uint4 const v_lh, uint4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
uintv ijkVecCross4uv(uint4 v_out, uint4 const v_lh, uint4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
uint ijkVecAbs1u(uint const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
uint ijkVecSgn1u(uint const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
uint ijkVecDot1u(uint const s_lh, uint const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
uint ijkVecLengthSq1u(uint const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
uint ijkVecLength1u(uint const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
float ijkVecLengthSqInv1u(uint const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
float ijkVecLengthInv1u(uint const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
uint ijkVecNormalize1u(uint const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
uint ijkVecNormalizeGetLength1u(uint const s, uint* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
uint ijkVecNormalizeGetLengthInv1u(uint const s, float* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
uvec2 ijkVecInit2u();

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
uvec2 ijkVecInitElems2u(uint const x, uint const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
uvec2 ijkVecCopy2u(uvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
#if TSIGNED
uvec2 ijkVecNegate2u(uvec2 const v_in);
#endif	// TSIGNED

// ijkVecBitNot2*
//	Calculate component-wise bitwise 'not' of 2D vector.
//		param v_in: input vector
//		return: result vector
#if TINTEGER
uvec2 ijkVecBitNot2u(uvec2 const v_in);
#endif	// TINTEGER

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
bvec2 ijkVecNot2u(uvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecAdd2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecSub2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecMul2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecDiv2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecDivSafe2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecMod2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecModSafe2u(uvec2 const v_lh, uvec2 const v_rh);

#if TINTEGER
// ijkVecBitAnd2*
//	Calculate component-wise bitwise 'and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitAnd2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitNand2*
//	Calculate component-wise bitwise 'not and' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitNand2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitOr2*
//	Calculate component-wise bitwise 'or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitOr2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitNor2*
//	Calculate component-wise bitwise 'not or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitNor2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitXor2*
//	Calculate component-wise bitwise 'exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitXor2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitXnor2*
//	Calculate component-wise bitwise 'not exclusive or' of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitXnor2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitShiftLeft2*
//	Calculate component-wise bit shift left of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitShiftLeft2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecBitShiftRight2*
//	Calculate component-wise bit shift right of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitShiftRight2u(uvec2 const v_lh, uvec2 const v_rh);
#endif	// TINTEGER

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
uvec2 ijkVecCopy2us(uint const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
#if TSIGNED
uvec2 ijkVecNegate2us(uint const s_in);
#endif	// TSIGNED

// ijkVecBitNot2*s
//	Calculate bitwise 'not' of 2D vector.
//		param s_in: input scalar
//		return: result vector
#if TINTEGER
uvec2 ijkVecBitNot2us(uint const s_in);
#endif	// TINTEGER

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec2 ijkVecNot2us(uint const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecAdd2us(uvec2 const v_lh, uint const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecSub2us(uvec2 const v_lh, uint const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecMul2us(uvec2 const v_lh, uint const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecDiv2us(uvec2 const v_lh, uint const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecDivSafe2us(uvec2 const v_lh, uint const s_rh);

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecMod2us(uvec2 const v_lh, uint const s_rh);

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecModSafe2us(uvec2 const v_lh, uint const s_rh);

#if TINTEGER
// ijkVecBitAnd2*s
//	Calculate bitwise 'and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitAnd2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitNand2*s
//	Calculate bitwise 'not and' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitNand2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitOr2*s
//	Calculate bitwise 'or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitOr2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitNor2*s
//	Calculate bitwise 'not or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitNor2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitXor2*s
//	Calculate bitwise 'exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitXor2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitXnor2*s
//	Calculate bitwise 'not exclusive or' of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitXnor2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitShiftLeft2*s
//	Calculate bit shift left of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitShiftLeft2us(uvec2 const v_lh, uint const s_rh);

// ijkVecBitShiftRight2*s
//	Calculate bit shift right of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec2 ijkVecBitShiftRight2us(uvec2 const v_lh, uint const s_rh);
#endif	// TINTEGER

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecEqual2us(uvec2 const v_lh, uint const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecInequal2us(uvec2 const v_lh, uint const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLessEqual2us(uvec2 const v_lh, uint const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreaterEqual2us(uvec2 const v_lh, uint const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLess2us(uvec2 const v_lh, uint const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreater2us(uvec2 const v_lh, uint const s_rh);

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecAnd2us(uvec2 const v_lh, uint const s_rh);

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNand2us(uvec2 const v_lh, uint const s_rh);

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecOr2us(uvec2 const v_lh, uint const s_rh);

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNor2us(uvec2 const v_lh, uint const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecAdd2su(uint const s_lh, uvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecSub2su(uint const s_lh, uvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecMul2su(uint const s_lh, uvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecDiv2su(uint const s_lh, uvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecDivSafe2su(uint const s_lh, uvec2 const v_rh);

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecMod2su(uint const s_lh, uvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecModSafe2su(uint const s_lh, uvec2 const v_rh);

#if TINTEGER
// ijkVecBitAnd2s*
//	Calculate bitwise 'and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitAnd2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitNand2s*
//	Calculate bitwise 'not and' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitNand2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitOr2s*
//	Calculate bitwise 'or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitOr2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitNor2s*
//	Calculate bitwise 'not or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitNor2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitXor2s*
//	Calculate bitwise 'exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitXor2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitXnor2s*
//	Calculate bitwise 'not exclusive or' of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitXnor2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitShiftLeft2s*
//	Calculate bit shift left of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitShiftLeft2su(uint const s_lh, uvec2 const v_rh);

// ijkVecBitShiftRight2s*
//	Calculate bit shift right of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec2 ijkVecBitShiftRight2su(uint const s_lh, uvec2 const v_rh);
#endif	// TINTEGER

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2su(uint const s_lh, uvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2su(uint const s_lh, uvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2su(uint const s_lh, uvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2su(uint const s_lh, uvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2su(uint const s_lh, uvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2su(uint const s_lh, uvec2 const v_rh);

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2su(uint const s_lh, uvec2 const v_rh);

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2su(uint const s_lh, uvec2 const v_rh);

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2su(uint const s_lh, uvec2 const v_rh);

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2su(uint const s_lh, uvec2 const v_rh);

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uint ijkVecDot2u(uvec2 const v_lh, uvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
uint ijkVecCross2u(uvec2 const v_lh, uvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
uvec3 ijkVecInit3u();

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
uvec3 ijkVecInitElems3u(uint const x, uint const y, uint const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
uvec3 ijkVecCopy3u(uvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
#if TSIGNED
uvec3 ijkVecNegate3u(uvec3 const v_in);
#endif	// TSIGNED

// ijkVecBitNot3*
//	Calculate component-wise bitwise 'not' of 3D vector.
//		param v_in: input vector
//		return: result vector
#if TINTEGER
uvec3 ijkVecBitNot3u(uvec3 const v_in);
#endif	// TINTEGER

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
bvec3 ijkVecNot3u(uvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecAdd3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecSub3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecMul3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecDiv3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecDivSafe3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecMod3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecModSafe3u(uvec3 const v_lh, uvec3 const v_rh);

#if TINTEGER
// ijkVecBitAnd3*
//	Calculate component-wise bitwise 'and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitAnd3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitNand3*
//	Calculate component-wise bitwise 'not and' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitNand3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitOr3*
//	Calculate component-wise bitwise 'or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitOr3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitNor3*
//	Calculate component-wise bitwise 'not or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitNor3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitXor3*
//	Calculate component-wise bitwise 'exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitXor3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitXnor3*
//	Calculate component-wise bitwise 'not exclusive or' of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitXnor3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitShiftLeft3*
//	Calculate component-wise bit shift left of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitShiftLeft3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecBitShiftRight3*
//	Calculate component-wise bit shift right of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitShiftRight3u(uvec3 const v_lh, uvec3 const v_rh);
#endif	// TINTEGER

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
uvec3 ijkVecCopy3uz(uvec2 const v_xy, uint const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
uvec3 ijkVecCopy3us(uint const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
#if TSIGNED
uvec3 ijkVecNegate3us(uint const s_in);
#endif	// TSIGNED

// ijkVecBitNot3*s
//	Calculate bitwise 'not' of 3D vector.
//		param s_in: input scalar
//		return: result vector
#if TINTEGER
uvec3 ijkVecBitNot3us(uint const s_in);
#endif	// TINTEGER

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec3 ijkVecNot3us(uint const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecAdd3us(uvec3 const v_lh, uint const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecSub3us(uvec3 const v_lh, uint const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecMul3us(uvec3 const v_lh, uint const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecDiv3us(uvec3 const v_lh, uint const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecDivSafe3us(uvec3 const v_lh, uint const s_rh);

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecMod3us(uvec3 const v_lh, uint const s_rh);

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecModSafe3us(uvec3 const v_lh, uint const s_rh);

#if TINTEGER
// ijkVecBitAnd3*s
//	Calculate bitwise 'and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitAnd3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitNand3*s
//	Calculate bitwise 'not and' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitNand3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitOr3*s
//	Calculate bitwise 'or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitOr3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitNor3*s
//	Calculate bitwise 'not or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitNor3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitXor3*s
//	Calculate bitwise 'exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitXor3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitXnor3*s
//	Calculate bitwise 'not exclusive or' of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitXnor3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitShiftLeft3*s
//	Calculate bit shift left of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitShiftLeft3us(uvec3 const v_lh, uint const s_rh);

// ijkVecBitShiftRight3*s
//	Calculate bit shift right of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec3 ijkVecBitShiftRight3us(uvec3 const v_lh, uint const s_rh);
#endif	// TINTEGER

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecEqual3us(uvec3 const v_lh, uint const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecInequal3us(uvec3 const v_lh, uint const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLessEqual3us(uvec3 const v_lh, uint const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreaterEqual3us(uvec3 const v_lh, uint const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLess3us(uvec3 const v_lh, uint const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreater3us(uvec3 const v_lh, uint const s_rh);

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecAnd3us(uvec3 const v_lh, uint const s_rh);

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNand3us(uvec3 const v_lh, uint const s_rh);

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecOr3us(uvec3 const v_lh, uint const s_rh);

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNor3us(uvec3 const v_lh, uint const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
uvec3 ijkVecCopy3xu(uint const x, uvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecAdd3su(uint const s_lh, uvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecSub3su(uint const s_lh, uvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecMul3su(uint const s_lh, uvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecDiv3su(uint const s_lh, uvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecDivSafe3su(uint const s_lh, uvec3 const v_rh);

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecMod3su(uint const s_lh, uvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecModSafe3su(uint const s_lh, uvec3 const v_rh);

#if TINTEGER
// ijkVecBitAnd3s*
//	Calculate bitwise 'and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitAnd3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitNand3s*
//	Calculate bitwise 'not and' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitNand3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitOr3s*
//	Calculate bitwise 'or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitOr3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitNor3s*
//	Calculate bitwise 'not or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitNor3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitXor3s*
//	Calculate bitwise 'exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitXor3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitXnor3s*
//	Calculate bitwise 'not exclusive or' of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitXnor3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitShiftLeft3s*
//	Calculate bit shift left of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitShiftLeft3su(uint const s_lh, uvec3 const v_rh);

// ijkVecBitShiftRight3s*
//	Calculate bit shift right of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec3 ijkVecBitShiftRight3su(uint const s_lh, uvec3 const v_rh);
#endif	// TINTEGER

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3su(uint const s_lh, uvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3su(uint const s_lh, uvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3su(uint const s_lh, uvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3su(uint const s_lh, uvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3su(uint const s_lh, uvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3su(uint const s_lh, uvec3 const v_rh);

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3su(uint const s_lh, uvec3 const v_rh);

// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3su(uint const s_lh, uvec3 const v_rh);

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3su(uint const s_lh, uvec3 const v_rh);

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3su(uint const s_lh, uvec3 const v_rh);

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uint ijkVecDot3u(uvec3 const v_lh, uvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
uvec3 ijkVecCross3u(uvec3 const v_lh, uvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
uvec4 ijkVecInit4u();

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
uvec4 ijkVecInitElems4u(uint const x, uint const y, uint const z, uint const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
uvec4 ijkVecCopy4xuw(uint const x, uvec2 const v_yz, uint const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
uvec4 ijkVecCopy4u2(uvec2 const v_xy, uvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
uvec4 ijkVecCopy4u(uvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
#if TSIGNED
uvec4 ijkVecNegate4u(uvec4 const v_in);
#endif	// TSIGNED

// ijkVecBitNot4*
//	Calculate component-wise bitwise 'not' of 4D vector.
//		param v_in: input vector
//		return: result vector
#if TINTEGER
uvec4 ijkVecBitNot4u(uvec4 const v_in);
#endif	// TINTEGER

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
bvec4 ijkVecNot4u(uvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecAdd4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecSub4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecMul4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecDiv4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecDivSafe4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecMod4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecModSafe4u(uvec4 const v_lh, uvec4 const v_rh);

#if TINTEGER
// ijkVecBitAnd4*
//	Calculate component-wise bitwise 'and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitAnd4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitNand4*
//	Calculate component-wise bitwise 'not and' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitNand4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitOr4*
//	Calculate component-wise bitwise 'or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitOr4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitNor4*
//	Calculate component-wise bitwise 'not or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitNor4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitXor4*
//	Calculate component-wise bitwise 'exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitXor4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitXnor4*
//	Calculate component-wise bitwise 'not exclusive or' of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitXnor4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitShiftLeft4*
//	Calculate component-wise bit shift left of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitShiftLeft4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecBitShiftRight4*
//	Calculate component-wise bit shift right of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitShiftRight4u(uvec4 const v_lh, uvec4 const v_rh);
#endif	// TINTEGER

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
uvec4 ijkVecCopy4uzw(uvec2 const v_xy, uint const z, uint const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pouint, 0 for vector)
//		return: result vector
uvec4 ijkVecCopy4uw(uvec3 const v_xyz, uint const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
uvec4 ijkVecCopy4us(uint const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
#if TSIGNED
uvec4 ijkVecNegate4us(uint const s_in);
#endif	// TSIGNED

// ijkVecBitNot4*s
//	Calculate bitwise 'not' of 4D vector.
//		param s_in: input scalar
//		return: result vector
#if TINTEGER
uvec4 ijkVecBitNot4us(uint const s_in);
#endif	// TINTEGER

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec4 ijkVecNot4us(uint const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecAdd4us(uvec4 const v_lh, uint const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecSub4us(uvec4 const v_lh, uint const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecMul4us(uvec4 const v_lh, uint const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecDiv4us(uvec4 const v_lh, uint const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecDivSafe4us(uvec4 const v_lh, uint const s_rh);

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecMod4us(uvec4 const v_lh, uint const s_rh);

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecModSafe4us(uvec4 const v_lh, uint const s_rh);

#if TINTEGER
// ijkVecBitAnd4*s
//	Calculate bitwise 'and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitAnd4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitNand4*s
//	Calculate bitwise 'not and' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitNand4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitOr4*s
//	Calculate bitwise 'or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitOr4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitNor4*s
//	Calculate bitwise 'not or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitNor4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitXor4*s
//	Calculate bitwise 'exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitXor4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitXnor4*s
//	Calculate bitwise 'not exclusive or' of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitXnor4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitShiftLeft4*s
//	Calculate bit shift left of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitShiftLeft4us(uvec4 const v_lh, uint const s_rh);

// ijkVecBitShiftRight4*s
//	Calculate bit shift right of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
uvec4 ijkVecBitShiftRight4us(uvec4 const v_lh, uint const s_rh);
#endif	// TINTEGER

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecEqual4us(uvec4 const v_lh, uint const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecInequal4us(uvec4 const v_lh, uint const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLessEqual4us(uvec4 const v_lh, uint const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreaterEqual4us(uvec4 const v_lh, uint const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLess4us(uvec4 const v_lh, uint const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreater4us(uvec4 const v_lh, uint const s_rh);

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecAnd4us(uvec4 const v_lh, uint const s_rh);

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNand4us(uvec4 const v_lh, uint const s_rh);

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecOr4us(uvec4 const v_lh, uint const s_rh);

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNor4us(uvec4 const v_lh, uint const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
uvec4 ijkVecCopy4xyu(uint const x, uint const y, uvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
uvec4 ijkVecCopy4xu(uint const x, uvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecAdd4su(uint const s_lh, uvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecSub4su(uint const s_lh, uvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecMul4su(uint const s_lh, uvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecDiv4su(uint const s_lh, uvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecDivSafe4su(uint const s_lh, uvec4 const v_rh);

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecMod4su(uint const s_lh, uvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecModSafe4su(uint const s_lh, uvec4 const v_rh);

#if TINTEGER
// ijkVecBitAnd4s*
//	Calculate bitwise 'and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitAnd4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitNand4s*
//	Calculate bitwise 'not and' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitNand4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitOr4s*
//	Calculate bitwise 'or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitOr4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitNor4s*
//	Calculate bitwise 'not or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitNor4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitXor4s*
//	Calculate bitwise 'exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitXor4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitXnor4s*
//	Calculate bitwise 'not exclusive or' of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitXnor4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitShiftLeft4s*
//	Calculate bit shift left of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitShiftLeft4su(uint const s_lh, uvec4 const v_rh);

// ijkVecBitShiftRight4s*
//	Calculate bit shift right of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
uvec4 ijkVecBitShiftRight4su(uint const s_lh, uvec4 const v_rh);
#endif	// TINTEGER

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4su(uint const s_lh, uvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4su(uint const s_lh, uvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4su(uint const s_lh, uvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4su(uint const s_lh, uvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4su(uint const s_lh, uvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4su(uint const s_lh, uvec4 const v_rh);

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4su(uint const s_lh, uvec4 const v_rh);

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4su(uint const s_lh, uvec4 const v_rh);

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4su(uint const s_lh, uvec4 const v_rh);

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4su(uint const s_lh, uvec4 const v_rh);

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
uint ijkVecDot4u(uvec4 const v_lh, uvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
uvec4 ijkVecCross4u(uvec4 const v_lh, uvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_uint.inl"


#endif	// !_IJK_VECTOR_UINT_H_
#endif	// _IJK_VECTOR_H_