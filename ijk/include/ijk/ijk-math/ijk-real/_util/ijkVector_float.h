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


#include "_inl/ijkVector_float.inl"


#endif	// !_IJK_VECTOR_FLOAT_H_
#endif	// _IJK_VECTOR_H_