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

	ijkVector_float.h
	Declarations for 32-bit float vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_FLOAT_H_
#define _IJK_VECTOR_FLOAT_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
f32 ijkVecAbs1fs(f32 const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
f32 ijkVecSgn1fs(f32 const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
f32 ijkVecDot1fs(f32 const s_lh, f32 const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
f32 ijkVecLengthSq1fs(f32 const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
f32 ijkVecLength1fs(f32 const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
f32 ijkVecLengthSqInv1fs(f32 const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
f32 ijkVecLengthInv1fs(f32 const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
f32 ijkVecNormalize1fs(f32 const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
f32 ijkVecNormalizeGetLength1fs(f32 const s, f32* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
f32 ijkVecNormalizeGetLengthInv1fs(f32 const s, f32* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
floatv ijkVecPfv(floatv v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
floatv ijkVecInit2fv(float2 v_out);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
floatv ijkVecInitElems2fv(float2 v_out, f32 const x, f32 const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
floatv ijkVecCopy2fv(float2 v_out, float2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
floatv ijkVecNegate2fv(float2 v_out, float2 const v_in);

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot2fv(bool2 bv_out, float2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe2fv(float2 v_out, float2 const v_lh, float2 const v_rh);

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
floatv ijkVecCopy2fvs(float2 v_out, f32 const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
floatv ijkVecNegate2fvs(float2 v_out, f32 const s_in);

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot2fvs(bool2 bv_out, f32 const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecAdd2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecSub2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMul2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDiv2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDivSafe2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMod2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecModSafe2fvs(float2 v_out, float2 const v_lh, f32 const s_rh);

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe2fsv(float2 v_out, f32 const s_lh, float2 const v_rh);

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f32 ijkVecDot2fv(float2 const v_lh, float2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
f32 ijkVecCross2fv(float2 const v_lh, float2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
floatv ijkVecInit3fv(float3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
floatv ijkVecInitElems3fv(float3 v_out, f32 const x, f32 const y, f32 const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
floatv ijkVecCopy3fv(float3 v_out, float3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
floatv ijkVecNegate3fv(float3 v_out, float3 const v_in);

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot3fv(bool3 bv_out, float3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
floatv ijkVecCopy3fvz(float3 v_out, float2 const v_xy, f32 const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
floatv ijkVecCopy3fvs(float3 v_out, f32 const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
floatv ijkVecNegate3fvs(float3 v_out, f32 const s_in);

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot3fvs(bool3 bv_out, f32 const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecAdd3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecSub3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMul3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDiv3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDivSafe3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMod3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecModSafe3fvs(float3 v_out, float3 const v_lh, f32 const s_rh);

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
floatv ijkVecCopy3fxv(float3 v_out, f32 const x, float2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe3fsv(float3 v_out, f32 const s_lh, float3 const v_rh);

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh);

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f32 ijkVecDot3fv(float3 const v_lh, float3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecCross3fv(float3 v_out, float3 const v_lh, float3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
floatv ijkVecInit4fv(float4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: v_out
floatv ijkVecInitElems4fv(float4 v_out, f32 const x, f32 const y, f32 const z, f32 const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: v_out
floatv ijkVecCopy4fxvw(float4 v_out, f32 const x, float2 const v_yz, f32 const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
floatv ijkVecCopy4fv2(float4 v_out, float2 const v_xy, float2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
floatv ijkVecCopy4fv(float4 v_out, float4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
floatv ijkVecNegate4fv(float4 v_out, float4 const v_in);

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot4fv(bool4 bv_out, float4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: v_out
floatv ijkVecCopy4fvzw(float4 v_out, float2 const v_xy, f32 const z, f32 const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: v_out
floatv ijkVecCopy4fvw(float4 v_out, float3 const v_xyz, f32 const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
floatv ijkVecCopy4fvs(float4 v_out, f32 const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
floatv ijkVecNegate4fvs(float4 v_out, f32 const s_in);

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot4fvs(bool4 bv_out, f32 const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecAdd4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecSub4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMul4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDiv4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecDivSafe4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecMod4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
floatv ijkVecModSafe4fvs(float4 v_out, float4 const v_lh, f32 const s_rh);

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
floatv ijkVecCopy4fxyv(float4 v_out, f32 const x, f32 const y, float2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
floatv ijkVecCopy4fxv(float4 v_out, f32 const x, float3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecAdd4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecSub4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMul4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDiv4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecDivSafe4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecMod4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecModSafe4fsv(float4 v_out, f32 const s_lh, float4 const v_rh);

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh);

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f32 ijkVecDot4fv(float4 const v_lh, float4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
floatv ijkVecCross4fv(float4 v_out, float4 const v_lh, float4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
float ijkVecAbs1f(float const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
float ijkVecSgn1f(float const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
float ijkVecDot1f(float const s_lh, float const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
float ijkVecLengthSq1f(float const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
float ijkVecLength1f(float const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
float ijkVecLengthSqInv1f(float const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
float ijkVecLengthInv1f(float const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
float ijkVecNormalize1f(float const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
float ijkVecNormalizeGetLength1f(float const s, float* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
float ijkVecNormalizeGetLengthInv1f(float const s, float* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
fvec2 ijkVecInit2f();

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
fvec2 ijkVecInitElems2f(float const x, float const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
fvec2 ijkVecCopy2f(fvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
fvec2 ijkVecNegate2f(fvec2 const v_in);

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
bvec2 ijkVecNot2f(fvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecAdd2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecSub2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecMul2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecDiv2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecDivSafe2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecMod2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecModSafe2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
fvec2 ijkVecCopy2fs(float const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
fvec2 ijkVecNegate2fs(float const s_in);

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec2 ijkVecNot2fs(float const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecAdd2fs(fvec2 const v_lh, float const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecSub2fs(fvec2 const v_lh, float const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecMul2fs(fvec2 const v_lh, float const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecDiv2fs(fvec2 const v_lh, float const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecDivSafe2fs(fvec2 const v_lh, float const s_rh);

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecMod2fs(fvec2 const v_lh, float const s_rh);

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec2 ijkVecModSafe2fs(fvec2 const v_lh, float const s_rh);

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecEqual2fs(fvec2 const v_lh, float const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecInequal2fs(fvec2 const v_lh, float const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLessEqual2fs(fvec2 const v_lh, float const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreaterEqual2fs(fvec2 const v_lh, float const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLess2fs(fvec2 const v_lh, float const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreater2fs(fvec2 const v_lh, float const s_rh);

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecAnd2fs(fvec2 const v_lh, float const s_rh);

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNand2fs(fvec2 const v_lh, float const s_rh);

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecOr2fs(fvec2 const v_lh, float const s_rh);

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNor2fs(fvec2 const v_lh, float const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecAdd2sf(float const s_lh, fvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecSub2sf(float const s_lh, fvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecMul2sf(float const s_lh, fvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecDiv2sf(float const s_lh, fvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecDivSafe2sf(float const s_lh, fvec2 const v_rh);

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecMod2sf(float const s_lh, fvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec2 ijkVecModSafe2sf(float const s_lh, fvec2 const v_rh);

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2sf(float const s_lh, fvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2sf(float const s_lh, fvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2sf(float const s_lh, fvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2sf(float const s_lh, fvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2sf(float const s_lh, fvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2sf(float const s_lh, fvec2 const v_rh);

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2sf(float const s_lh, fvec2 const v_rh);

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2sf(float const s_lh, fvec2 const v_rh);

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2sf(float const s_lh, fvec2 const v_rh);

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2sf(float const s_lh, fvec2 const v_rh);

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
float ijkVecDot2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
float ijkVecCross2f(fvec2 const v_lh, fvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
fvec3 ijkVecInit3f();

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
fvec3 ijkVecInitElems3f(float const x, float const y, float const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
fvec3 ijkVecCopy3f(fvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
fvec3 ijkVecNegate3f(fvec3 const v_in);

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
bvec3 ijkVecNot3f(fvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecAdd3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecSub3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecMul3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecDiv3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecDivSafe3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecMod3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecModSafe3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
fvec3 ijkVecCopy3fz(fvec2 const v_xy, float const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
fvec3 ijkVecCopy3fs(float const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
fvec3 ijkVecNegate3fs(float const s_in);

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec3 ijkVecNot3fs(float const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecAdd3fs(fvec3 const v_lh, float const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecSub3fs(fvec3 const v_lh, float const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecMul3fs(fvec3 const v_lh, float const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecDiv3fs(fvec3 const v_lh, float const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecDivSafe3fs(fvec3 const v_lh, float const s_rh);

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecMod3fs(fvec3 const v_lh, float const s_rh);

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec3 ijkVecModSafe3fs(fvec3 const v_lh, float const s_rh);

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecEqual3fs(fvec3 const v_lh, float const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecInequal3fs(fvec3 const v_lh, float const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLessEqual3fs(fvec3 const v_lh, float const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreaterEqual3fs(fvec3 const v_lh, float const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLess3fs(fvec3 const v_lh, float const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreater3fs(fvec3 const v_lh, float const s_rh);

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecAnd3fs(fvec3 const v_lh, float const s_rh);

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNand3fs(fvec3 const v_lh, float const s_rh);

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecOr3fs(fvec3 const v_lh, float const s_rh);

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNor3fs(fvec3 const v_lh, float const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
fvec3 ijkVecCopy3xf(float const x, fvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecAdd3sf(float const s_lh, fvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecSub3sf(float const s_lh, fvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecMul3sf(float const s_lh, fvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecDiv3sf(float const s_lh, fvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecDivSafe3sf(float const s_lh, fvec3 const v_rh);

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecMod3sf(float const s_lh, fvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec3 ijkVecModSafe3sf(float const s_lh, fvec3 const v_rh);

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3sf(float const s_lh, fvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3sf(float const s_lh, fvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3sf(float const s_lh, fvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3sf(float const s_lh, fvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3sf(float const s_lh, fvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3sf(float const s_lh, fvec3 const v_rh);

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3sf(float const s_lh, fvec3 const v_rh);

// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3sf(float const s_lh, fvec3 const v_rh);

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3sf(float const s_lh, fvec3 const v_rh);

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3sf(float const s_lh, fvec3 const v_rh);

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
float ijkVecDot3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
fvec3 ijkVecCross3f(fvec3 const v_lh, fvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
fvec4 ijkVecInit4f();

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: result vector
fvec4 ijkVecInitElems4f(float const x, float const y, float const z, float const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: result vector
fvec4 ijkVecCopy4xfw(float const x, fvec2 const v_yz, float const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
fvec4 ijkVecCopy4f2(fvec2 const v_xy, fvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
fvec4 ijkVecCopy4f(fvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
fvec4 ijkVecNegate4f(fvec4 const v_in);

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
bvec4 ijkVecNot4f(fvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecAdd4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecSub4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecMul4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecDiv4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecDivSafe4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecMod4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecModSafe4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: result vector
fvec4 ijkVecCopy4fzw(fvec2 const v_xy, float const z, float const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for pofloat, 0 for vector)
//		return: result vector
fvec4 ijkVecCopy4fw(fvec3 const v_xyz, float const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
fvec4 ijkVecCopy4fs(float const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
fvec4 ijkVecNegate4fs(float const s_in);

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec4 ijkVecNot4fs(float const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecAdd4fs(fvec4 const v_lh, float const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecSub4fs(fvec4 const v_lh, float const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecMul4fs(fvec4 const v_lh, float const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecDiv4fs(fvec4 const v_lh, float const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecDivSafe4fs(fvec4 const v_lh, float const s_rh);

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecMod4fs(fvec4 const v_lh, float const s_rh);

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
fvec4 ijkVecModSafe4fs(fvec4 const v_lh, float const s_rh);

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecEqual4fs(fvec4 const v_lh, float const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecInequal4fs(fvec4 const v_lh, float const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLessEqual4fs(fvec4 const v_lh, float const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreaterEqual4fs(fvec4 const v_lh, float const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLess4fs(fvec4 const v_lh, float const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreater4fs(fvec4 const v_lh, float const s_rh);

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecAnd4fs(fvec4 const v_lh, float const s_rh);

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNand4fs(fvec4 const v_lh, float const s_rh);

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecOr4fs(fvec4 const v_lh, float const s_rh);

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNor4fs(fvec4 const v_lh, float const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
fvec4 ijkVecCopy4xyf(float const x, float const y, fvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
fvec4 ijkVecCopy4xf(float const x, fvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecAdd4sf(float const s_lh, fvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecSub4sf(float const s_lh, fvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecMul4sf(float const s_lh, fvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecDiv4sf(float const s_lh, fvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecDivSafe4sf(float const s_lh, fvec4 const v_rh);

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecMod4sf(float const s_lh, fvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
fvec4 ijkVecModSafe4sf(float const s_lh, fvec4 const v_rh);

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4sf(float const s_lh, fvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4sf(float const s_lh, fvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4sf(float const s_lh, fvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4sf(float const s_lh, fvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4sf(float const s_lh, fvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4sf(float const s_lh, fvec4 const v_rh);

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4sf(float const s_lh, fvec4 const v_rh);

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4sf(float const s_lh, fvec4 const v_rh);

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4sf(float const s_lh, fvec4 const v_rh);

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4sf(float const s_lh, fvec4 const v_rh);

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
float ijkVecDot4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
fvec4 ijkVecCross4f(fvec4 const v_lh, fvec4 const v_rh);


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f32 ijkVecLengthSq2fv(float2 const v_in);

// ijkVecLength2*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f32 ijkVecLength2fv(float2 const v_in);

// ijkVecLengthSqInv2*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInv2fv(float2 const v_in);

// ijkVecLengthSqInvSafe2*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInvSafe2fv(float2 const v_in);

// ijkVecLengthInv2*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInv2fv(float2 const v_in);

// ijkVecLengthInvSafe2*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInvSafe2fv(float2 const v_in);

// ijkVecNormalize2*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalize2fv(float2 v_out, float2 const v_in);

// ijkVecNormalizeSafe2*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalizeSafe2fv(float2 v_out, float2 const v_in);

// ijkVecNormalizeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLength2fv(float2 v_out, float2 const v_in, f32* const length_out);

// ijkVecNormalizeSafeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLength2fv(float2 v_out, float2 const v_in, f32* const length_out);

// ijkVecNormalizeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLengthInv2fv(float2 v_out, float2 const v_in, f32* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLengthInv2fv(float2 v_out, float2 const v_in, f32* const lengthInv_out);

// ijkVecCrossNormalize2*v
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
f32 ijkVecCrossNormalize2fv(float2 const v_lh, float2 const v_rh);

// ijkVecCrossNormalizeSafe2*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
f32 ijkVecCrossNormalizeSafe2fv(float2 const v_lh, float2 const v_rh);

// ijkVecCrossNormalizeGetLength2*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
f32 ijkVecCrossNormalizeGetLength2fv(float2 const v_lh, float2 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeSafeGetLength2*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
f32 ijkVecCrossNormalizeSafeGetLength2fv(float2 const v_lh, float2 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
f32 ijkVecCrossNormalizeGetLengthInv2fv(float2 const v_lh, float2 const v_rh, f32* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
f32 ijkVecCrossNormalizeSafeGetLengthInv2fv(float2 const v_lh, float2 const v_rh, f32* const lengthInv_out);

// ijkVecLerp2*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecLerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u);

// ijkVecLerpInv2*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
floatv ijkVecLerpInv2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v_lerp);

// ijkVecLerpRevInit2*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
floatv ijkVecLerpRevInit2fv(float2 v0_out, float2 const v_lerp, float2 const v1, f32 const u);

// ijkVecLerpRevTerm2*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
floatv ijkVecLerpRevTerm2fv(float2 v1_out, float2 const v0, float2 const v_lerp, f32 const u);

// ijkVecProjRatio2*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f32 ijkVecProjRatio2fv(float2 const v_base, float2 const v_in);

// ijkVecProj2*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
floatv ijkVecProj2fv(float2 v_out, float2 const v_base, float2 const v_in);

// ijkVecOrtho2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
floatv ijkVecOrtho2fv(float2 v_out, float2 const v_base, float2 const v_in);

// ijkVecOrthoNorm2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
floatv ijkVecOrthoNorm2fv(float2 v_out, float2 const v_base, float2 const v_in, float2 v_base_norm_out);

// ijkVecOrthoList2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
float2* ijkVecOrthoList2fv(float2 vl_out[], float2 const v_base, float2 const vl_in[], size const n);

// ijkVecOrthoNormList2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
float2* ijkVecOrthoNormList2fv(float2 vl_out[], float2 const v_base, float2 const vl_in[], size const n, float2 v_base_norm_out);

// ijkVecNlerp2*v
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecNlerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u);

// ijkVecSlerp2*v
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecSlerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u);

// ijkVecReflectScale2*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflectScale2fv(float2 v_out, float2 const v_in, float2 const v_nrm);

// ijkVecUnitReflect2*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecUnitReflect2fv(float2 v_out, float2 const v_in, float2 const v_nrm);

// ijkVecReflect2*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflect2fv(float2 v_out, float2 const v_in, float2 const v_nrm);

// ijkVecResize2*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResize2fv(float2 v_out, float2 const v_in, f32 const length);

// ijkVecResizeSafe2*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResizeSafe2fv(float2 v_out, float2 const v_in, f32 const length);

// ijkVecCrossResize2*v
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
f32 ijkVecCrossResize2fv(float2 const v_lh, float2 const v_rh, f32 const length);

// ijkVecCrossResizeSafe2*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
f32 ijkVecCrossResizeSafe2fv(float2 const v_lh, float2 const v_rh, f32 const length);

// ijkVecNearest2*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
floatv ijkVecNearest2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u);

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
floatv ijkVecBinearest2fv(float2 v_out, float2 const v00, float2 const v01, float2 const v10, float2 const v11, f32 const u0, f32 const u1, f32 const u);

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
floatv ijkVecRemap2fv(float2 v_out, float2 const v0_dst, float2 const v1_dst, float2 const v0_src, float2 const v1_src, float2 const v_src);

// ijkVecBezier0O2*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
floatv ijkVecBezier0O2fv(float2 v_out, float2 const v0, f32 const u);

// ijkVecBezier1O2*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
floatv ijkVecBezier1O2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u);

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
floatv ijkVecBezier2O2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v2, f32 const u);

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
floatv ijkVecBezier3O2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v2, float2 const v3, f32 const u);

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
floatv ijkVecBezierNO2fv(float2 v_out, float2 const v[], size const order, f32 const u);

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
floatv ijkVecCubicHermite2fv(float2 v_out, float2 const v0, float2 const dv0, float2 const v1, float2 const dv1, f32 const u);

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
floatv ijkVecCubicHermiteHandles2fv(float2 v_out, float2 const v0, float2 const cv0, float2 const v1, float2 const cv1, f32 const u);

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
floatv ijkVecCubicCatmullRom2fv(float2 v_out, float2 const vp, float2 const v0, float2 const v1, float2 const v2, f32 const u);

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
floatv ijkVecBicubicCatmullRom2fv(float2 v_out, float2 const vpp, float2 const vp0, float2 const vp1, float2 const vp2, float2 const v0p, float2 const v00, float2 const v01, float2 const v02, float2 const v1p, float2 const v10, float2 const v11, float2 const v12, float2 const v2p, float2 const v20, float2 const v21, float2 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u);

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
f32 ijkVecReparamCubicHermite2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, ibool const lNormalize, float2 const v0, float2 const dv0, float2 const v1, float2 const dv1);

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
f32 ijkVecReparamCubicHermiteHandles2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, ibool const lNormalize, float2 const v0, float2 const cv0, float2 const v1, float2 const cv1);

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
f32 ijkVecReparamCubicCatmullRom2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, ibool const lNormalize, float2 const vp, float2 const v0, float2 const v1, float2 const v2);

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
f32 ijkVecReparamBicubicCatmullRom2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, ibool const lNormalize, float2 const vpp, float2 const vp0, float2 const vp1, float2 const vp2, float2 const v0p, float2 const v00, float2 const v01, float2 const v02, float2 const v1p, float2 const v10, float2 const v11, float2 const v12, float2 const v2p, float2 const v20, float2 const v21, float2 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2);

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
floatv ijkVecSampleTableInc2fv(float2 v_out, f32 const uTable[], float2 const vTable[], index i, index di, f32 const u);

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
floatv ijkVecSampleTableDec2fv(float2 v_out, f32 const uTable[], float2 const vTable[], index i, index di, f32 const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f32 ijkVecLengthSq3fv(float3 const v_in);

// ijkVecLength3*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f32 ijkVecLength3fv(float3 const v_in);

// ijkVecLengthSqInv3*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInv3fv(float3 const v_in);

// ijkVecLengthSqInvSafe3*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInvSafe3fv(float3 const v_in);

// ijkVecLengthInv3*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInv3fv(float3 const v_in);

// ijkVecLengthInvSafe3*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInvSafe3fv(float3 const v_in);

// ijkVecNormalize3*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalize3fv(float3 v_out, float3 const v_in);

// ijkVecNormalizeSafe3*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalizeSafe3fv(float3 v_out, float3 const v_in);

// ijkVecNormalizeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLength3fv(float3 v_out, float3 const v_in, f32* const length_out);

// ijkVecNormalizeSafeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLength3fv(float3 v_out, float3 const v_in, f32* const length_out);

// ijkVecNormalizeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLengthInv3fv(float3 v_out, float3 const v_in, f32* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLengthInv3fv(float3 v_out, float3 const v_in, f32* const lengthInv_out);

// ijkVecCrossNormalize3*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecCrossNormalize3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecCrossNormalizeSafe3*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecCrossNormalizeSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh);

// ijkVecCrossNormalizeGetLength3*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeGetLength3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeSafeGetLength3*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeSafeGetLength3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeGetLengthInv3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeSafeGetLengthInv3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const lengthInv_out);

// ijkVecLerp3*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecLerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u);

// ijkVecLerpInv3*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
floatv ijkVecLerpInv3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v_lerp);

// ijkVecLerpRevInit3*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
floatv ijkVecLerpRevInit3fv(float3 v0_out, float3 const v_lerp, float3 const v1, f32 const u);

// ijkVecLerpRevTerm3*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
floatv ijkVecLerpRevTerm3fv(float3 v1_out, float3 const v0, float3 const v_lerp, f32 const u);

// ijkVecProjRatio3*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f32 ijkVecProjRatio3fv(float3 const v_base, float3 const v_in);

// ijkVecProj3*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
floatv ijkVecProj3fv(float3 v_out, float3 const v_base, float3 const v_in);

// ijkVecOrtho3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
floatv ijkVecOrtho3fv(float3 v_out, float3 const v_base, float3 const v_in);

// ijkVecOrthoNorm3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
floatv ijkVecOrthoNorm3fv(float3 v_out, float3 const v_base, float3 const v_in, float3 v_base_norm_out);

// ijkVecOrthoList3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
float3* ijkVecOrthoList3fv(float3 vl_out[], float3 const v_base, float3 const vl_in[], size const n);

// ijkVecOrthoNormList3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
float3* ijkVecOrthoNormList3fv(float3 vl_out[], float3 const v_base, float3 const vl_in[], size const n, float3 v_base_norm_out);

// ijkVecNlerp3*v
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecNlerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u);

// ijkVecSlerp3*v
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecSlerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u);

// ijkVecReflectScale3*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflectScale3fv(float3 v_out, float3 const v_in, float3 const v_nrm);

// ijkVecUnitReflect3*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecUnitReflect3fv(float3 v_out, float3 const v_in, float3 const v_nrm);

// ijkVecReflect3*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflect3fv(float3 v_out, float3 const v_in, float3 const v_nrm);

// ijkVecResize3*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResize3fv(float3 v_out, float3 const v_in, f32 const length);

// ijkVecResizeSafe3*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResizeSafe3fv(float3 v_out, float3 const v_in, f32 const length);

// ijkVecCrossResize3*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecCrossResize3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32 const length);

// ijkVecCrossResizeSafe3*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecCrossResizeSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32 const length);

// ijkVecNearest3*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
floatv ijkVecNearest3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u);

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
floatv ijkVecBinearest3fv(float3 v_out, float3 const v00, float3 const v01, float3 const v10, float3 const v11, f32 const u0, f32 const u1, f32 const u);

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
floatv ijkVecRemap3fv(float3 v_out, float3 const v0_dst, float3 const v1_dst, float3 const v0_src, float3 const v1_src, float3 const v_src);

// ijkVecBezier0O3*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
floatv ijkVecBezier0O3fv(float3 v_out, float3 const v0, f32 const u);

// ijkVecBezier1O3*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
floatv ijkVecBezier1O3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u);

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
floatv ijkVecBezier2O3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v2, f32 const u);

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
floatv ijkVecBezier3O3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v2, float3 const v3, f32 const u);

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
floatv ijkVecBezierNO3fv(float3 v_out, float3 const v[], size const order, f32 const u);

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
floatv ijkVecCubicHermite3fv(float3 v_out, float3 const v0, float3 const dv0, float3 const v1, float3 const dv1, f32 const u);

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
floatv ijkVecCubicHermiteHandles3fv(float3 v_out, float3 const v0, float3 const cv0, float3 const v1, float3 const cv1, f32 const u);

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
floatv ijkVecCubicCatmullRom3fv(float3 v_out, float3 const vp, float3 const v0, float3 const v1, float3 const v2, f32 const u);

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
floatv ijkVecBicubicCatmullRom3fv(float3 v_out, float3 const vpp, float3 const vp0, float3 const vp1, float3 const vp2, float3 const v0p, float3 const v00, float3 const v01, float3 const v02, float3 const v1p, float3 const v10, float3 const v11, float3 const v12, float3 const v2p, float3 const v20, float3 const v21, float3 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u);

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
f32 ijkVecReparamCubicHermite3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, ibool const lNormalize, float3 const v0, float3 const dv0, float3 const v1, float3 const dv1);

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
f32 ijkVecReparamCubicHermiteHandles3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, ibool const lNormalize, float3 const v0, float3 const cv0, float3 const v1, float3 const cv1);

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
f32 ijkVecReparamCubicCatmullRom3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, ibool const lNormalize, float3 const vp, float3 const v0, float3 const v1, float3 const v2);

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
f32 ijkVecReparamBicubicCatmullRom3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, ibool const lNormalize, float3 const vpp, float3 const vp0, float3 const vp1, float3 const vp2, float3 const v0p, float3 const v00, float3 const v01, float3 const v02, float3 const v1p, float3 const v10, float3 const v11, float3 const v12, float3 const v2p, float3 const v20, float3 const v21, float3 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2);

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
floatv ijkVecSampleTableInc3fv(float3 v_out, f32 const uTable[], float3 const vTable[], index i, index di, f32 const u);

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
floatv ijkVecSampleTableDec3fv(float3 v_out, f32 const uTable[], float3 const vTable[], index i, index di, f32 const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f32 ijkVecLengthSq4fv(float4 const v_in);

// ijkVecLength4*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f32 ijkVecLength4fv(float4 const v_in);

// ijkVecLengthSqInv4*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInv4fv(float4 const v_in);

// ijkVecLengthSqInvSafe4*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f32 ijkVecLengthSqInvSafe4fv(float4 const v_in);

// ijkVecLengthInv4*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInv4fv(float4 const v_in);

// ijkVecLengthInvSafe4*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f32 ijkVecLengthInvSafe4fv(float4 const v_in);

// ijkVecNormalize4*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalize4fv(float4 v_out, float4 const v_in);

// ijkVecNormalizeSafe4*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
floatv ijkVecNormalizeSafe4fv(float4 v_out, float4 const v_in);

// ijkVecNormalizeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLength4fv(float4 v_out, float4 const v_in, f32* const length_out);

// ijkVecNormalizeSafeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLength4fv(float4 v_out, float4 const v_in, f32* const length_out);

// ijkVecNormalizeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeGetLengthInv4fv(float4 v_out, float4 const v_in, f32* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecNormalizeSafeGetLengthInv4fv(float4 v_out, float4 const v_in, f32* const lengthInv_out);

// ijkVecCrossNormalize4*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecCrossNormalize4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecCrossNormalizeSafe4*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
floatv ijkVecCrossNormalizeSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh);

// ijkVecCrossNormalizeGetLength4*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeGetLength4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeSafeGetLength4*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeSafeGetLength4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const length_out);

// ijkVecCrossNormalizeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeGetLengthInv4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
floatv ijkVecCrossNormalizeSafeGetLengthInv4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const lengthInv_out);

// ijkVecLerp4*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecLerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u);

// ijkVecLerpInv4*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
floatv ijkVecLerpInv4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v_lerp);

// ijkVecLerpRevInit4*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
floatv ijkVecLerpRevInit4fv(float4 v0_out, float4 const v_lerp, float4 const v1, f32 const u);

// ijkVecLerpRevTerm4*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
floatv ijkVecLerpRevTerm4fv(float4 v1_out, float4 const v0, float4 const v_lerp, f32 const u);

// ijkVecProjRatio4*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f32 ijkVecProjRatio4fv(float4 const v_base, float4 const v_in);

// ijkVecProj4*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
floatv ijkVecProj4fv(float4 v_out, float4 const v_base, float4 const v_in);

// ijkVecOrtho4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
floatv ijkVecOrtho4fv(float4 v_out, float4 const v_base, float4 const v_in);

// ijkVecOrthoNorm4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
floatv ijkVecOrthoNorm4fv(float4 v_out, float4 const v_base, float4 const v_in, float4 v_base_norm_out);

// ijkVecOrthoList4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
float4* ijkVecOrthoList4fv(float4 vl_out[], float4 const v_base, float4 const vl_in[], size const n);

// ijkVecOrthoNormList4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
float4* ijkVecOrthoNormList4fv(float4 vl_out[], float4 const v_base, float4 const vl_in[], size const n, float4 v_base_norm_out);

// ijkVecNlerp4*v
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecNlerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u);

// ijkVecSlerp4*v
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
floatv ijkVecSlerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u);

// ijkVecReflectScale4*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflectScale4fv(float4 v_out, float4 const v_in, float4 const v_nrm);

// ijkVecUnitReflect4*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecUnitReflect4fv(float4 v_out, float4 const v_in, float4 const v_nrm);

// ijkVecReflect4*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
floatv ijkVecReflect4fv(float4 v_out, float4 const v_in, float4 const v_nrm);

// ijkVecResize4*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResize4fv(float4 v_out, float4 const v_in, f32 const length);

// ijkVecResizeSafe4*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecResizeSafe4fv(float4 v_out, float4 const v_in, f32 const length);

// ijkVecCrossResize4*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecCrossResize4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32 const length);

// ijkVecCrossResizeSafe4*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
floatv ijkVecCrossResizeSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32 const length);

// ijkVecNearest4*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
floatv ijkVecNearest4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u);

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
floatv ijkVecBinearest4fv(float4 v_out, float4 const v00, float4 const v01, float4 const v10, float4 const v11, f32 const u0, f32 const u1, f32 const u);

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
floatv ijkVecRemap4fv(float4 v_out, float4 const v0_dst, float4 const v1_dst, float4 const v0_src, float4 const v1_src, float4 const v_src);

// ijkVecBezier0O4*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
floatv ijkVecBezier0O4fv(float4 v_out, float4 const v0, f32 const u);

// ijkVecBezier1O4*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
floatv ijkVecBezier1O4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u);

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
floatv ijkVecBezier2O4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v2, f32 const u);

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
floatv ijkVecBezier3O4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v2, float4 const v3, f32 const u);

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
floatv ijkVecBezierNO4fv(float4 v_out, float4 const v[], size const order, f32 const u);

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
floatv ijkVecCubicHermite4fv(float4 v_out, float4 const v0, float4 const dv0, float4 const v1, float4 const dv1, f32 const u);

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
floatv ijkVecCubicHermiteHandles4fv(float4 v_out, float4 const v0, float4 const cv0, float4 const v1, float4 const cv1, f32 const u);

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
floatv ijkVecCubicCatmullRom4fv(float4 v_out, float4 const vp, float4 const v0, float4 const v1, float4 const v2, f32 const u);

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
floatv ijkVecBicubicCatmullRom4fv(float4 v_out, float4 const vpp, float4 const vp0, float4 const vp1, float4 const vp2, float4 const v0p, float4 const v00, float4 const v01, float4 const v02, float4 const v1p, float4 const v10, float4 const v11, float4 const v12, float4 const v2p, float4 const v20, float4 const v21, float4 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u);

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
f32 ijkVecReparamCubicHermite4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, ibool const lNormalize, float4 const v0, float4 const dv0, float4 const v1, float4 const dv1);

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
f32 ijkVecReparamCubicHermiteHandles4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, ibool const lNormalize, float4 const v0, float4 const cv0, float4 const v1, float4 const cv1);

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
f32 ijkVecReparamCubicCatmullRom4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, ibool const lNormalize, float4 const vp, float4 const v0, float4 const v1, float4 const v2);

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
f32 ijkVecReparamBicubicCatmullRom4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, ibool const lNormalize, float4 const vpp, float4 const vp0, float4 const vp1, float4 const vp2, float4 const v0p, float4 const v00, float4 const v01, float4 const v02, float4 const v1p, float4 const v10, float4 const v11, float4 const v12, float4 const v2p, float4 const v20, float4 const v21, float4 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2);

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
floatv ijkVecSampleTableInc4fv(float4 v_out, f32 const uTable[], float4 const vTable[], index i, index di, f32 const u);

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
floatv ijkVecSampleTableDec4fv(float4 v_out, f32 const uTable[], float4 const vTable[], index i, index di, f32 const u);


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
float ijkVecLengthSq2f(fvec2 const v_in);

// ijkVecLength2*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
float ijkVecLength2f(fvec2 const v_in);

// ijkVecLengthSqInv2*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInv2f(fvec2 const v_in);

// ijkVecLengthSqInvSafe2*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInvSafe2f(fvec2 const v_in);

// ijkVecLengthInv2*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInv2f(fvec2 const v_in);

// ijkVecLengthInvSafe2*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInvSafe2f(fvec2 const v_in);

// ijkVecNormalize2*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
fvec2 ijkVecNormalize2f(fvec2 const v_in);

// ijkVecNormalizeSafe2*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
fvec2 ijkVecNormalizeSafe2f(fvec2 const v_in);

// ijkVecNormalizeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec2 ijkVecNormalizeGetLength2f(fvec2 const v_in, float* const length_out);

// ijkVecNormalizeSafeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec2 ijkVecNormalizeSafeGetLength2f(fvec2 const v_in, float* const length_out);

// ijkVecNormalizeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec2 ijkVecNormalizeGetLengthInv2f(fvec2 const v_in, float* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec2 ijkVecNormalizeSafeGetLengthInv2f(fvec2 const v_in, float* const lengthInv_out);

// ijkVecCrossNormalize2*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
float ijkVecCrossNormalize2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecCrossNormalizeSafe2*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
float ijkVecCrossNormalizeSafe2f(fvec2 const v_lh, fvec2 const v_rh);

// ijkVecCrossNormalizeGetLength2*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
float ijkVecCrossNormalizeGetLength2f(fvec2 const v_lh, fvec2 const v_rh, float* const length_out);

// ijkVecCrossNormalizeSafeGetLength2*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
float ijkVecCrossNormalizeSafeGetLength2f(fvec2 const v_lh, fvec2 const v_rh, float* const length_out);

// ijkVecCrossNormalizeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
float ijkVecCrossNormalizeGetLengthInv2f(fvec2 const v_lh, fvec2 const v_rh, float* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
float ijkVecCrossNormalizeSafeGetLengthInv2f(fvec2 const v_lh, fvec2 const v_rh, float* const lengthInv_out);

// ijkVecLerp2*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec2 ijkVecLerp2f(fvec2 const v0, fvec2 const v1, float const u);

// ijkVecLerpInv2*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
fvec2 ijkVecLerpInv2f(fvec2 const v0, fvec2 const v1, fvec2 const v_lerp);

// ijkVecLerpRevInit2*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
fvec2 ijkVecLerpRevInit2f(fvec2 const v_lerp, fvec2 const v1, float const u);

// ijkVecLerpRevTerm2*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
fvec2 ijkVecLerpRevTerm2f(fvec2 const v0, fvec2 const v_lerp, float const u);

// ijkVecProjRatio2*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
float ijkVecProjRatio2f(fvec2 const v_base, fvec2 const v_in);

// ijkVecProj2*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
fvec2 ijkVecProj2f(fvec2 const v_base, fvec2 const v_in);

// ijkVecOrtho2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
fvec2 ijkVecOrtho2f(fvec2 const v_base, fvec2 const v_in);

// ijkVecOrthoNorm2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
fvec2 ijkVecOrthoNorm2f(fvec2 const v_base, fvec2 const v_in, fvec2* const v_base_norm_out);

// ijkVecOrthoList2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
fvec2* ijkVecOrthoList2f(fvec2 vl_out[], fvec2 const v_base, fvec2 const vl_in[], size const n);

// ijkVecOrthoNormList2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
fvec2* ijkVecOrthoNormList2f(fvec2 vl_out[], fvec2 const v_base, fvec2 const vl_in[], size const n, fvec2* const v_base_norm_out);

// ijkVecNlerp2*
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec2 ijkVecNlerp2f(fvec2 const v0, fvec2 const v1, float const u);

// ijkVecSlerp2*
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec2 ijkVecSlerp2f(fvec2 const v0, fvec2 const v1, float const u);

// ijkVecReflectScale2*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec2 ijkVecReflectScale2f(fvec2 const v_in, fvec2 const v_nrm);

// ijkVecUnitReflect2*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec2 ijkVecUnitReflect2f(fvec2 const v_in, fvec2 const v_nrm);

// ijkVecReflect2*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec2 ijkVecReflect2f(fvec2 const v_in, fvec2 const v_nrm);

// ijkVecResize2*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec2 ijkVecResize2f(fvec2 const v_in, float const length);

// ijkVecResizeSafe2*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec2 ijkVecResizeSafe2f(fvec2 const v_in, float const length);

// ijkVecCrossResize2*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
float ijkVecCrossResize2f(fvec2 const v_lh, fvec2 const v_rh, float const length);

// ijkVecCrossResizeSafe2*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
float ijkVecCrossResizeSafe2f(fvec2 const v_lh, fvec2 const v_rh, float const length);

// ijkVecNearest2*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
fvec2 ijkVecNearest2f(fvec2 const v0, fvec2 const v1, float const u);

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
fvec2 ijkVecBinearest2f(fvec2 const v00, fvec2 const v01, fvec2 const v10, fvec2 const v11, float const u0, float const u1, float const u);

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
fvec2 ijkVecRemap2f(fvec2 const v0_dst, fvec2 const v1_dst, fvec2 const v0_src, fvec2 const v1_src, fvec2 const v_src);

// ijkVecBezier0O2*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
fvec2 ijkVecBezier0O2f(fvec2 const v0, float const u);

// ijkVecBezier1O2*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
fvec2 ijkVecBezier1O2f(fvec2 const v0, fvec2 const v1, float const u);

// ijkVecBezier2O2*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
fvec2 ijkVecBezier2O2f(fvec2 const v0, fvec2 const v1, fvec2 const v2, float const u);

// ijkVecBezier3O2*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
fvec2 ijkVecBezier3O2f(fvec2 const v0, fvec2 const v1, fvec2 const v2, fvec2 const v3, float const u);

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
fvec2 ijkVecBezierNO2f(fvec2 const v[], size const order, float const u);

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
fvec2 ijkVecCubicHermite2f(fvec2 const v0, fvec2 const dv0, fvec2 const v1, fvec2 const dv1, float const u);

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
fvec2 ijkVecCubicHermiteHandles2f(fvec2 const v0, fvec2 const cv0, fvec2 const v1, fvec2 const cv1, float const u);

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
fvec2 ijkVecCubicCatmullRom2f(fvec2 const vp, fvec2 const v0, fvec2 const v1, fvec2 const v2, float const u);

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
fvec2 ijkVecBicubicCatmullRom2f(fvec2 const vpp, fvec2 const vp0, fvec2 const vp1, fvec2 const vp2, fvec2 const v0p, fvec2 const v00, fvec2 const v01, fvec2 const v02, fvec2 const v1p, fvec2 const v10, fvec2 const v11, fvec2 const v12, fvec2 const v2p, fvec2 const v20, fvec2 const v21, fvec2 const v22, float const up, float const u0, float const u1, float const u2, float const u);

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
float ijkVecReparamCubicHermite2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, ibool const lNormalize, fvec2 const v0, fvec2 const dv0, fvec2 const v1, fvec2 const dv1);

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
float ijkVecReparamCubicHermiteHandles2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, ibool const lNormalize, fvec2 const v0, fvec2 const cv0, fvec2 const v1, fvec2 const cv1);

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
float ijkVecReparamCubicCatmullRom2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, ibool const lNormalize, fvec2 const vp, fvec2 const v0, fvec2 const v1, fvec2 const v2);

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
float ijkVecReparamBicubicCatmullRom2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, ibool const lNormalize, fvec2 const vpp, fvec2 const vp0, fvec2 const vp1, fvec2 const vp2, fvec2 const v0p, fvec2 const v00, fvec2 const v01, fvec2 const v02, fvec2 const v1p, fvec2 const v10, fvec2 const v11, fvec2 const v12, fvec2 const v2p, fvec2 const v20, fvec2 const v21, fvec2 const v22, float const up, float const u0, float const u1, float const u2);

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
fvec2 ijkVecSampleTableInc2f(float const uTable[], fvec2 const vTable[], index i, index di, float const u);

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
fvec2 ijkVecSampleTableDec2f(float const uTable[], fvec2 const vTable[], index i, index di, float const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
float ijkVecLengthSq3f(fvec3 const v_in);

// ijkVecLength3*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
float ijkVecLength3f(fvec3 const v_in);

// ijkVecLengthSqInv3*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInv3f(fvec3 const v_in);

// ijkVecLengthSqInvSafe3*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInvSafe3f(fvec3 const v_in);

// ijkVecLengthInv3*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInv3f(fvec3 const v_in);

// ijkVecLengthInvSafe3*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInvSafe3f(fvec3 const v_in);

// ijkVecNormalize3*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
fvec3 ijkVecNormalize3f(fvec3 const v_in);

// ijkVecNormalizeSafe3*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
fvec3 ijkVecNormalizeSafe3f(fvec3 const v_in);

// ijkVecNormalizeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec3 ijkVecNormalizeGetLength3f(fvec3 const v_in, float* const length_out);

// ijkVecNormalizeSafeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec3 ijkVecNormalizeSafeGetLength3f(fvec3 const v_in, float* const length_out);

// ijkVecNormalizeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec3 ijkVecNormalizeGetLengthInv3f(fvec3 const v_in, float* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec3 ijkVecNormalizeSafeGetLengthInv3f(fvec3 const v_in, float* const lengthInv_out);

// ijkVecCrossNormalize3*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
fvec3 ijkVecCrossNormalize3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecCrossNormalizeSafe3*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
fvec3 ijkVecCrossNormalizeSafe3f(fvec3 const v_lh, fvec3 const v_rh);

// ijkVecCrossNormalizeGetLength3*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
fvec3 ijkVecCrossNormalizeGetLength3f(fvec3 const v_lh, fvec3 const v_rh, float* const length_out);

// ijkVecCrossNormalizeSafeGetLength3*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
fvec3 ijkVecCrossNormalizeSafeGetLength3f(fvec3 const v_lh, fvec3 const v_rh, float* const length_out);

// ijkVecCrossNormalizeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
fvec3 ijkVecCrossNormalizeGetLengthInv3f(fvec3 const v_lh, fvec3 const v_rh, float* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
fvec3 ijkVecCrossNormalizeSafeGetLengthInv3f(fvec3 const v_lh, fvec3 const v_rh, float* const lengthInv_out);

// ijkVecLerp3*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec3 ijkVecLerp3f(fvec3 const v0, fvec3 const v1, float const u);

// ijkVecLerpInv3*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
fvec3 ijkVecLerpInv3f(fvec3 const v0, fvec3 const v1, fvec3 const v_lerp);

// ijkVecLerpRevInit3*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
fvec3 ijkVecLerpRevInit3f(fvec3 const v_lerp, fvec3 const v1, float const u);

// ijkVecLerpRevTerm3*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
fvec3 ijkVecLerpRevTerm3f(fvec3 const v0, fvec3 const v_lerp, float const u);

// ijkVecProjRatio3*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
float ijkVecProjRatio3f(fvec3 const v_base, fvec3 const v_in);

// ijkVecProj3*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
fvec3 ijkVecProj3f(fvec3 const v_base, fvec3 const v_in);

// ijkVecOrtho3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
fvec3 ijkVecOrtho3f(fvec3 const v_base, fvec3 const v_in);

// ijkVecOrthoNorm3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
fvec3 ijkVecOrthoNorm3f(fvec3 const v_base, fvec3 const v_in, fvec3* const v_base_norm_out);

// ijkVecOrthoList3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
fvec3* ijkVecOrthoList3f(fvec3 vl_out[], fvec3 const v_base, fvec3 const vl_in[], size const n);

// ijkVecOrthoNormList3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
fvec3* ijkVecOrthoNormList3f(fvec3 vl_out[], fvec3 const v_base, fvec3 const vl_in[], size const n, fvec3* const v_base_norm_out);

// ijkVecNlerp3*
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec3 ijkVecNlerp3f(fvec3 const v0, fvec3 const v1, float const u);

// ijkVecSlerp3*
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec3 ijkVecSlerp3f(fvec3 const v0, fvec3 const v1, float const u);

// ijkVecReflectScale3*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec3 ijkVecReflectScale3f(fvec3 const v_in, fvec3 const v_nrm);

// ijkVecUnitReflect3*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec3 ijkVecUnitReflect3f(fvec3 const v_in, fvec3 const v_nrm);

// ijkVecReflect3*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec3 ijkVecReflect3f(fvec3 const v_in, fvec3 const v_nrm);

// ijkVecResize3*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec3 ijkVecResize3f(fvec3 const v_in, float const length);

// ijkVecResizeSafe3*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec3 ijkVecResizeSafe3f(fvec3 const v_in, float const length);

// ijkVecCrossResize3*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
fvec3 ijkVecCrossResize3f(fvec3 const v_lh, fvec3 const v_rh, float const length);

// ijkVecCrossResizeSafe3*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
fvec3 ijkVecCrossResizeSafe3f(fvec3 const v_lh, fvec3 const v_rh, float const length);

// ijkVecNearest3*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
fvec3 ijkVecNearest3f(fvec3 const v0, fvec3 const v1, float const u);

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
fvec3 ijkVecBinearest3f(fvec3 const v00, fvec3 const v01, fvec3 const v10, fvec3 const v11, float const u0, float const u1, float const u);

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
fvec3 ijkVecRemap3f(fvec3 const v0_dst, fvec3 const v1_dst, fvec3 const v0_src, fvec3 const v1_src, fvec3 const v_src);

// ijkVecBezier0O3*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
fvec3 ijkVecBezier0O3f(fvec3 const v0, float const u);

// ijkVecBezier1O3*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
fvec3 ijkVecBezier1O3f(fvec3 const v0, fvec3 const v1, float const u);

// ijkVecBezier2O3*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
fvec3 ijkVecBezier2O3f(fvec3 const v0, fvec3 const v1, fvec3 const v2, float const u);

// ijkVecBezier3O3*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
fvec3 ijkVecBezier3O3f(fvec3 const v0, fvec3 const v1, fvec3 const v2, fvec3 const v3, float const u);

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
fvec3 ijkVecBezierNO3f(fvec3 const v[], size const order, float const u);

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
fvec3 ijkVecCubicHermite3f(fvec3 const v0, fvec3 const dv0, fvec3 const v1, fvec3 const dv1, float const u);

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
fvec3 ijkVecCubicHermiteHandles3f(fvec3 const v0, fvec3 const cv0, fvec3 const v1, fvec3 const cv1, float const u);

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
fvec3 ijkVecCubicCatmullRom3f(fvec3 const vp, fvec3 const v0, fvec3 const v1, fvec3 const v2, float const u);

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
fvec3 ijkVecBicubicCatmullRom3f(fvec3 const vpp, fvec3 const vp0, fvec3 const vp1, fvec3 const vp2, fvec3 const v0p, fvec3 const v00, fvec3 const v01, fvec3 const v02, fvec3 const v1p, fvec3 const v10, fvec3 const v11, fvec3 const v12, fvec3 const v2p, fvec3 const v20, fvec3 const v21, fvec3 const v22, float const up, float const u0, float const u1, float const u2, float const u);

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
float ijkVecReparamCubicHermite3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, ibool const lNormalize, fvec3 const v0, fvec3 const dv0, fvec3 const v1, fvec3 const dv1);

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
float ijkVecReparamCubicHermiteHandles3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, ibool const lNormalize, fvec3 const v0, fvec3 const cv0, fvec3 const v1, fvec3 const cv1);

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
float ijkVecReparamCubicCatmullRom3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, ibool const lNormalize, fvec3 const vp, fvec3 const v0, fvec3 const v1, fvec3 const v2);

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
float ijkVecReparamBicubicCatmullRom3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, ibool const lNormalize, fvec3 const vpp, fvec3 const vp0, fvec3 const vp1, fvec3 const vp2, fvec3 const v0p, fvec3 const v00, fvec3 const v01, fvec3 const v02, fvec3 const v1p, fvec3 const v10, fvec3 const v11, fvec3 const v12, fvec3 const v2p, fvec3 const v20, fvec3 const v21, fvec3 const v22, float const up, float const u0, float const u1, float const u2);

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
fvec3 ijkVecSampleTableInc3f(float const uTable[], fvec3 const vTable[], index i, index di, float const u);

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
fvec3 ijkVecSampleTableDec3f(float const uTable[], fvec3 const vTable[], index i, index di, float const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
float ijkVecLengthSq4f(fvec4 const v_in);

// ijkVecLength4*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
float ijkVecLength4f(fvec4 const v_in);

// ijkVecLengthSqInv4*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInv4f(fvec4 const v_in);

// ijkVecLengthSqInvSafe4*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
float ijkVecLengthSqInvSafe4f(fvec4 const v_in);

// ijkVecLengthInv4*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInv4f(fvec4 const v_in);

// ijkVecLengthInvSafe4*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
float ijkVecLengthInvSafe4f(fvec4 const v_in);

// ijkVecNormalize4*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
fvec4 ijkVecNormalize4f(fvec4 const v_in);

// ijkVecNormalizeSafe4*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
fvec4 ijkVecNormalizeSafe4f(fvec4 const v_in);

// ijkVecNormalizeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec4 ijkVecNormalizeGetLength4f(fvec4 const v_in, float* const length_out);

// ijkVecNormalizeSafeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec4 ijkVecNormalizeSafeGetLength4f(fvec4 const v_in, float* const length_out);

// ijkVecNormalizeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec4 ijkVecNormalizeGetLengthInv4f(fvec4 const v_in, float* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
fvec4 ijkVecNormalizeSafeGetLengthInv4f(fvec4 const v_in, float* const lengthInv_out);

// ijkVecCrossNormalize4*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
fvec4 ijkVecCrossNormalize4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecCrossNormalizeSafe4*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
fvec4 ijkVecCrossNormalizeSafe4f(fvec4 const v_lh, fvec4 const v_rh);

// ijkVecCrossNormalizeGetLength4*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
fvec4 ijkVecCrossNormalizeGetLength4f(fvec4 const v_lh, fvec4 const v_rh, float* const length_out);

// ijkVecCrossNormalizeSafeGetLength4*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
fvec4 ijkVecCrossNormalizeSafeGetLength4f(fvec4 const v_lh, fvec4 const v_rh, float* const length_out);

// ijkVecCrossNormalizeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
fvec4 ijkVecCrossNormalizeGetLengthInv4f(fvec4 const v_lh, fvec4 const v_rh, float* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
fvec4 ijkVecCrossNormalizeSafeGetLengthInv4f(fvec4 const v_lh, fvec4 const v_rh, float* const lengthInv_out);

// ijkVecLerp4*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec4 ijkVecLerp4f(fvec4 const v0, fvec4 const v1, float const u);

// ijkVecLerpInv4*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
fvec4 ijkVecLerpInv4f(fvec4 const v0, fvec4 const v1, fvec4 const v_lerp);

// ijkVecLerpRevInit4*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
fvec4 ijkVecLerpRevInit4f(fvec4 const v_lerp, fvec4 const v1, float const u);

// ijkVecLerpRevTerm4*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
fvec4 ijkVecLerpRevTerm4f(fvec4 const v0, fvec4 const v_lerp, float const u);

// ijkVecProjRatio4*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
float ijkVecProjRatio4f(fvec4 const v_base, fvec4 const v_in);

// ijkVecProj4*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
fvec4 ijkVecProj4f(fvec4 const v_base, fvec4 const v_in);

// ijkVecOrtho4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
fvec4 ijkVecOrtho4f(fvec4 const v_base, fvec4 const v_in);

// ijkVecOrthoNorm4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
fvec4 ijkVecOrthoNorm4f(fvec4 const v_base, fvec4 const v_in, fvec4* const v_base_norm_out);

// ijkVecOrthoList4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
fvec4* ijkVecOrthoList4f(fvec4 vl_out[], fvec4 const v_base, fvec4 const vl_in[], size const n);

// ijkVecOrthoNormList4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
fvec4* ijkVecOrthoNormList4f(fvec4 vl_out[], fvec4 const v_base, fvec4 const vl_in[], size const n, fvec4* const v_base_norm_out);

// ijkVecNlerp4*
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec4 ijkVecNlerp4f(fvec4 const v0, fvec4 const v1, float const u);

// ijkVecSlerp4*
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
fvec4 ijkVecSlerp4f(fvec4 const v0, fvec4 const v1, float const u);

// ijkVecReflectScale4*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec4 ijkVecReflectScale4f(fvec4 const v_in, fvec4 const v_nrm);

// ijkVecUnitReflect4*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec4 ijkVecUnitReflect4f(fvec4 const v_in, fvec4 const v_nrm);

// ijkVecReflect4*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
fvec4 ijkVecReflect4f(fvec4 const v_in, fvec4 const v_nrm);

// ijkVecResize4*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec4 ijkVecResize4f(fvec4 const v_in, float const length);

// ijkVecResizeSafe4*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
fvec4 ijkVecResizeSafe4f(fvec4 const v_in, float const length);

// ijkVecCrossResize4*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
fvec4 ijkVecCrossResize4f(fvec4 const v_lh, fvec4 const v_rh, float const length);

// ijkVecCrossResizeSafe4*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
fvec4 ijkVecCrossResizeSafe4f(fvec4 const v_lh, fvec4 const v_rh, float const length);

// ijkVecNearest4*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
fvec4 ijkVecNearest4f(fvec4 const v0, fvec4 const v1, float const u);

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
fvec4 ijkVecBinearest4f(fvec4 const v00, fvec4 const v01, fvec4 const v10, fvec4 const v11, float const u0, float const u1, float const u);

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
fvec4 ijkVecRemap4f(fvec4 const v0_dst, fvec4 const v1_dst, fvec4 const v0_src, fvec4 const v1_src, fvec4 const v_src);

// ijkVecBezier0O4*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
fvec4 ijkVecBezier0O4f(fvec4 const v0, float const u);

// ijkVecBezier1O4*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
fvec4 ijkVecBezier1O4f(fvec4 const v0, fvec4 const v1, float const u);

// ijkVecBezier2O4*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
fvec4 ijkVecBezier2O4f(fvec4 const v0, fvec4 const v1, fvec4 const v2, float const u);

// ijkVecBezier3O4*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
fvec4 ijkVecBezier3O4f(fvec4 const v0, fvec4 const v1, fvec4 const v2, fvec4 const v3, float const u);

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
fvec4 ijkVecBezierNO4f(fvec4 const v[], size const order, float const u);

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
fvec4 ijkVecCubicHermite4f(fvec4 const v0, fvec4 const dv0, fvec4 const v1, fvec4 const dv1, float const u);

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
fvec4 ijkVecCubicHermiteHandles4f(fvec4 const v0, fvec4 const cv0, fvec4 const v1, fvec4 const cv1, float const u);

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
fvec4 ijkVecCubicCatmullRom4f(fvec4 const vp, fvec4 const v0, fvec4 const v1, fvec4 const v2, float const u);

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
fvec4 ijkVecBicubicCatmullRom4f(fvec4 const vpp, fvec4 const vp0, fvec4 const vp1, fvec4 const vp2, fvec4 const v0p, fvec4 const v00, fvec4 const v01, fvec4 const v02, fvec4 const v1p, fvec4 const v10, fvec4 const v11, fvec4 const v12, fvec4 const v2p, fvec4 const v20, fvec4 const v21, fvec4 const v22, float const up, float const u0, float const u1, float const u2, float const u);

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
float ijkVecReparamCubicHermite4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, ibool const lNormalize, fvec4 const v0, fvec4 const dv0, fvec4 const v1, fvec4 const dv1);

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
float ijkVecReparamCubicHermiteHandles4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, ibool const lNormalize, fvec4 const v0, fvec4 const cv0, fvec4 const v1, fvec4 const cv1);

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
float ijkVecReparamCubicCatmullRom4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, ibool const lNormalize, fvec4 const vp, fvec4 const v0, fvec4 const v1, fvec4 const v2);

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
float ijkVecReparamBicubicCatmullRom4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, ibool const lNormalize, fvec4 const vpp, fvec4 const vp0, fvec4 const vp1, fvec4 const vp2, fvec4 const v0p, fvec4 const v00, fvec4 const v01, fvec4 const v02, fvec4 const v1p, fvec4 const v10, fvec4 const v11, fvec4 const v12, fvec4 const v2p, fvec4 const v20, fvec4 const v21, fvec4 const v22, float const up, float const u0, float const u1, float const u2);

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
fvec4 ijkVecSampleTableInc4f(float const uTable[], fvec4 const vTable[], index i, index di, float const u);

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
fvec4 ijkVecSampleTableDec4f(float const uTable[], fvec4 const vTable[], index i, index di, float const u);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_float.inl"


#endif	// !_IJK_VECTOR_FLOAT_H_
#endif	// _IJK_VECTOR_H_