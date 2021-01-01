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

	ijkVector_double.h
	Declarations for 64-bit float (double) vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_DOUBLE_H_
#define _IJK_VECTOR_DOUBLE_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
	
// ijkVecAbs1*s
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
f64 ijkVecAbs1ds(f64 const s);

// ijkVecSgn1*s
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
f64 ijkVecSgn1ds(f64 const s);

// ijkVecDot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
f64 ijkVecDot1ds(f64 const s_lh, f64 const s_rh);

// ijkVecLengthSq1*s
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
f64 ijkVecLengthSq1ds(f64 const s);

// ijkVecLength1*s
//	Length of scalar.
//		param s: scalar
//		return: length
f64 ijkVecLength1ds(f64 const s);

// ijkVecLengthSqInv1*s
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
f64 ijkVecLengthSqInv1ds(f64 const s);

// ijkVecLengthSqInv1*s
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
f64 ijkVecLengthInv1ds(f64 const s);

// ijkVecNormalize1*s
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
f64 ijkVecNormalize1ds(f64 const s);

// ijkVecNormalizeGetLength1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
f64 ijkVecNormalizeGetLength1ds(f64 const s, f64* const length_out);

// ijkVecNormalizeGetLengthInv1*s
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
f64 ijkVecNormalizeGetLengthInv1ds(f64 const s, f64* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecP*v
//	Pass-thru array-based vector function (does nothing).
//		param v_out: output vector
//		return: v_out
doublev ijkVecPdv(doublev v_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*v
//	Initialize 2D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
doublev ijkVecInit2dv(double2 v_out);

// ijkVecInitElems2*v
//	Initialize 2D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		return: v_out
doublev ijkVecInitElems2dv(double2 v_out, f64 const x, f64 const y);

// ijkVecCopy2*v
//	Copy 2D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
doublev ijkVecCopy2dv(double2 v_out, double2 const v_in);

// ijkVecNegate2*v
//	Negate 2D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
doublev ijkVecNegate2dv(double2 v_out, double2 const v_in);

// ijkVecNot2*v
//	Calculate component-wise logical 'not' of 2D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot2dv(bool2 bv_out, double2 const v_in);

// ijkVecAdd2*v
//	Calculate sum of 2D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecSub2*v
//	Calculate difference of 2D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecMul2*v
//	Calculate component-wise product of 2D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecDiv2*v
//	Calculate component-wise quotient of 2D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecDivSafe2*v
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecMod2*v
//	Calculate component-wise remainder of 2D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecModSafe2*v
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe2dv(double2 v_out, double2 const v_lh, double2 const v_rh);

// ijkVecEqual2*v
//	Equality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecInequal2*v
//	Inequality comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecLessEqual2*v
//	Less-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecGreaterEqual2*v
//	Greater-than or equal comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecLess2*v
//	Less-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecGreater2*v
//	Greater-than comparison for 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecAnd2*v
//	Component-wise logical 'and' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecNand2*v
//	Component-wise logical 'nand' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecOr2*v
//	Component-wise logical 'or' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecNor2*v
//	Component-wise logical 'nor' of 2D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2dv(bool2 bv_out, double2 const v_lh, double2 const v_rh);

// ijkVecCopy2*vs
//	Copy 2D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
doublev ijkVecCopy2dvs(double2 v_out, f64 const s_in);

// ijkVecNegate2*vs
//	Negate scalar to 2D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
doublev ijkVecNegate2dvs(double2 v_out, f64 const s_in);

// ijkVecNot2*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot2dvs(bool2 bv_out, f64 const s_in);

// ijkVecAdd2*vs
//	Calculate sum of 2D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecAdd2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecSub2*vs
//	Calculate difference of 2D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecSub2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecMul2*vs
//	Calculate product of 2D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMul2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecDiv2*vs
//	Calculate quotient of 2D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDiv2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecDivSafe2*vs
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDivSafe2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecMod2*vs
//	Calculate remainder of 2D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMod2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecModSafe2*vs
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecModSafe2dvs(double2 v_out, double2 const v_lh, f64 const s_rh);

// ijkVecEqual2*vs
//	Equality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecInequal2*vs
//	Inequality comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecLessEqual2*vs
//	Less-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecGreaterEqual2*vs
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecLess2*vs
//	Less-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecGreater2*vs
//	Greater-than comparison of 2D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecAnd2*vs
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecNand2*vs
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecOr2*vs
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecNor2*vs
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor2dvs(bool2 bv_out, double2 const v_lh, f64 const s_rh);

// ijkVecAdd2*sv
//	Calculate sum of scalar and 2D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecSub2*sv
//	Calculate difference of scalar and 2D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecMul2*sv
//	Calculate product of scalar by 2D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecDiv2*sv
//	Calculate quotient of scalar by 2D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecDivSafe2*sv
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecMod2*sv
//	Calculate remainder of scalar by 2D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecModSafe2*sv
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe2dsv(double2 v_out, f64 const s_lh, double2 const v_rh);

// ijkVecEqual2*sv
//	Equality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecInequal2*sv
//	Inequality comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecLessEqual2*sv
//	Less-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecGreaterEqual2*sv
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecLess2*sv
//	Less-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecGreater2*sv
//	Greater-than comparison of scalar and 2D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecAnd2*sv
//	Component-wise logical 'and' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecNand2*sv
//	Component-wise logical 'nand' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecOr2*sv
//	Component-wise logical 'or' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecNor2*sv
//	Component-wise logical 'nor' of 2D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor2dsv(bool2 bv_out, f64 const s_lh, double2 const v_rh);

// ijkVecDot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f64 ijkVecDot2dv(double2 const v_lh, double2 const v_rh);

// ijkVecCross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
f64 ijkVecCross2dv(double2 const v_lh, double2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*v
//	Initialize 3D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
doublev ijkVecInit3dv(double3 v_out);

// ijkVecInitElems3*v
//	Initialize 3D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		return: v_out
doublev ijkVecInitElems3dv(double3 v_out, f64 const x, f64 const y, f64 const z);

// ijkVecCopy3*v
//	Copy 3D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
doublev ijkVecCopy3dv(double3 v_out, double3 const v_in);

// ijkVecNegate3*v
//	Negate 3D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
doublev ijkVecNegate3dv(double3 v_out, double3 const v_in);

// ijkVecNot3*v
//	Calculate component-wise logical 'not' of 3D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot3dv(bool3 bv_out, double3 const v_in);

// ijkVecAdd3*v
//	Calculate sum of 3D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecSub3*v
//	Calculate difference of 3D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecMul3*v
//	Calculate component-wise product of 3D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecDiv3*v
//	Calculate component-wise quotient of 3D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecDivSafe3*v
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecMod3*v
//	Calculate component-wise remainder of 3D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecModSafe3*v
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecEqual3*v
//	Equality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecInequal3*v
//	Inequality comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecLessEqual3*v
//	Less-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecGreaterEqual3*v
//	Greater-than or equal comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecLess3*v
//	Less-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecGreater3*v
//	Greater-than comparison for 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecAnd3*v
//	Component-wise logical 'and' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecNand3*v
//	Component-wise logical 'nand' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecOr3*v
//	Component-wise logical 'or' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecNor3*v
//	Component-wise logical 'nor' of 3D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3dv(bool3 bv_out, double3 const v_lh, double3 const v_rh);

// ijkVecCopy3*vz
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: v_out
doublev ijkVecCopy3dvz(double3 v_out, double2 const v_xy, f64 const z);

// ijkVecCopy3*vs
//	Copy 3D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
doublev ijkVecCopy3dvs(double3 v_out, f64 const s_in);

// ijkVecNegate3*vs
//	Negate scalar to 3D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
doublev ijkVecNegate3dvs(double3 v_out, f64 const s_in);

// ijkVecNot3*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot3dvs(bool3 bv_out, f64 const s_in);

// ijkVecAdd3*vs
//	Calculate sum of 3D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecAdd3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecSub3*vs
//	Calculate difference of 3D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecSub3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecMul3*vs
//	Calculate product of 3D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMul3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecDiv3*vs
//	Calculate quotient of 3D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDiv3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecDivSafe3*vs
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDivSafe3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecMod3*vs
//	Calculate remainder of 3D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMod3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecModSafe3*vs
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecModSafe3dvs(double3 v_out, double3 const v_lh, f64 const s_rh);

// ijkVecEqual3*vs
//	Equality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecInequal3*vs
//	Inequality comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecLessEqual3*vs
//	Less-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecGreaterEqual3*vs
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecLess3*vs
//	Less-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecGreater3*vs
//	Greater-than comparison of 3D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecAnd3*vs
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecNand3*vs
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecOr3*vs
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecNor3*vs
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor3dvs(bool3 bv_out, double3 const v_lh, f64 const s_rh);

// ijkVecCopy3*xv
//	Copy 3D vector from 2D vector and one scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: v_out
doublev ijkVecCopy3dxv(double3 v_out, f64 const x, double2 const v_yz);

// ijkVecAdd3*sv
//	Calculate sum of scalar and 3D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecSub3*sv
//	Calculate difference of scalar and 3D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecMul3*sv
//	Calculate product of scalar by 3D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecDiv3*sv
//	Calculate quotient of scalar by 3D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecDivSafe3*sv
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecMod3*sv
//	Calculate remainder of scalar by 3D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecModSafe3*sv
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe3dsv(double3 v_out, f64 const s_lh, double3 const v_rh);

// ijkVecEqual3*sv
//	Equality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecInequal3*sv
//	Inequality comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecLessEqual3*sv
//	Less-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecGreaterEqual3*sv
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecLess3*sv
//	Less-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecGreater3*sv
//	Greater-than comparison of scalar and 3D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecAnd3*sv
//	Component-wise logical 'and' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecNand3*sv
//	Component-wise logical 'nand' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecOr3*sv
//	Component-wise logical 'or' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecNor3*sv
//	Component-wise logical 'nor' of 3D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor3dsv(bool3 bv_out, f64 const s_lh, double3 const v_rh);

// ijkVecDot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f64 ijkVecDot3dv(double3 const v_lh, double3 const v_rh);

// ijkVecCross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecCross3dv(double3 v_out, double3 const v_lh, double3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*v
//	Initialize 4D vector to default value (zero vector).
//		param v_out: output vector
//		return: v_out
doublev ijkVecInit4dv(double4 v_out);

// ijkVecInitElems4*v
//	Initialize 4D vector to specified individual elements.
//		param v_out: output vector
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: v_out
doublev ijkVecInitElems4dv(double4 v_out, f64 const x, f64 const y, f64 const z, f64 const w);

// ijkVecCopy4*xvw
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: v_out
doublev ijkVecCopy4dxvw(double4 v_out, f64 const x, double2 const v_yz, f64 const w);

// ijkVecCopy4*v2
//	Copy 4D vector from two 2D vectors.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: v_out
doublev ijkVecCopy4dv2(double4 v_out, double2 const v_xy, double2 const v_zw);

// ijkVecCopy4*v
//	Copy 4D vector from first elements of another vector.
//		param v_out: output vector to hold copy
//		param v_in: input vector
//		return: v_out
doublev ijkVecCopy4dv(double4 v_out, double4 const v_in);

// ijkVecNegate4*v
//	Negate 4D vector.
//		param v_out: output vector to hold negated
//		param v_in: input vector
//		return: v_out
doublev ijkVecNegate4dv(double4 v_out, double4 const v_in);

// ijkVecNot4*v
//	Calculate component-wise logical 'not' of 4D vector.
//		param bv_out: boolean vector to hold component-wise logical 'not'
//		param v_in: input vector
//		return: bv_out
boolv ijkVecNot4dv(bool4 bv_out, double4 const v_in);

// ijkVecAdd4*v
//	Calculate sum of 4D vectors.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecSub4*v
//	Calculate difference of 4D vectors.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecMul4*v
//	Calculate component-wise product of 4D vectors.
//		param v_out: output vector to hold component-wise product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecDiv4*v
//	Calculate component-wise quotient of 4D vectors.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecDivSafe4*v
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise quotient
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecMod4*v
//	Calculate component-wise remainder of 4D vectors.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecModSafe4*v
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_out: output vector to hold component-wise remainder
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecEqual4*v
//	Equality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecInequal4*v
//	Inequality comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecLessEqual4*v
//	Less-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecGreaterEqual4*v
//	Greater-than or equal comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecLess4*v
//	Less-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecGreater4*v
//	Greater-than comparison for 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecAnd4*v
//	Component-wise logical 'and' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecNand4*v
//	Component-wise logical 'nand' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecOr4*v
//	Component-wise logical 'or' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecNor4*v
//	Component-wise logical 'nor' of 4D vectors.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4dv(bool4 bv_out, double4 const v_lh, double4 const v_rh);

// ijkVecCopy4*vzw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_out: output vector to hold copy
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: v_out
doublev ijkVecCopy4dvzw(double4 v_out, double2 const v_xy, f64 const z, f64 const w);

// ijkVecCopy4*vw
//	Copy 4D vector from 3D vector and one scalar.
//		param v_out: output vector to hold copy
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: v_out
doublev ijkVecCopy4dvw(double4 v_out, double3 const v_xyz, f64 const w);

// ijkVecCopy4*vs
//	Copy 4D vector from scalar.
//		param v_out: output vector to hold copy
//		param s_in: input scalar
//		return: v_out
doublev ijkVecCopy4dvs(double4 v_out, f64 const s_in);

// ijkVecNegate4*vs
//	Negate scalar to 4D vector.
//		param v_out: output vector to hold negated
//		param s_in: input scalar
//		return: v_out
doublev ijkVecNegate4dvs(double4 v_out, f64 const s_in);

// ijkVecNot4*vs
//	Calculate logical 'not' of scalar.
//		param bv_out: boolean vector to hold logical 'not'
//		param s_in: input scalar
//		return: bv_out
boolv ijkVecNot4dvs(bool4 bv_out, f64 const s_in);

// ijkVecAdd4*vs
//	Calculate sum of 4D vector components and scalar.
//		param v_out: output vector to hold sum
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecAdd4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecSub4*vs
//	Calculate difference of 4D vector components and scalar.
//		param v_out: output vector to hold difference
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecSub4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecMul4*vs
//	Calculate product of 4D vector components by scalar.
//		param v_out: output vector to hold product
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMul4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecDiv4*vs
//	Calculate quotient of 4D vector components by scalar.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDiv4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecDivSafe4*vs
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecDivSafe4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecMod4*vs
//	Calculate remainder of 4D vector components by scalar.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecMod4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecModSafe4*vs
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
doublev ijkVecModSafe4dvs(double4 v_out, double4 const v_lh, f64 const s_rh);

// ijkVecEqual4*vs
//	Equality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecInequal4*vs
//	Inequality comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecInequal4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecLessEqual4*vs
//	Less-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLessEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecGreaterEqual4*vs
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreaterEqual4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecLess4*vs
//	Less-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecLess4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecGreater4*vs
//	Greater-than comparison of 4D vector components and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecGreater4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecAnd4*vs
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecAnd4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecNand4*vs
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNand4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecOr4*vs
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecOr4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecNor4*vs
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: bv_out
boolv ijkVecNor4dvs(bool4 bv_out, double4 const v_lh, f64 const s_rh);

// ijkVecCopy4*xyv
//	Copy 4D vector from two scalars and 2D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: v_out
doublev ijkVecCopy4dxyv(double4 v_out, f64 const x, f64 const y, double2 const v_zw);

// ijkVecCopy4*xv
//	Copy 4D vector from one scalar and 3D vector.
//		param v_out: output vector to hold copy
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: v_out
doublev ijkVecCopy4dxv(double4 v_out, f64 const x, double3 const v_yzw);

// ijkVecAdd4*sv
//	Calculate sum of scalar and 4D vector components.
//		param v_out: output vector to hold sum
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecAdd4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecSub4*sv
//	Calculate difference of scalar and 4D vector components.
//		param v_out: output vector to hold difference
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecSub4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecMul4*sv
//	Calculate product of scalar by 4D vector components.
//		param v_out: output vector to hold product
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMul4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecDiv4*sv
//	Calculate quotient of scalar by 4D vector components.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDiv4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecDivSafe4*sv
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold quotient
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecDivSafe4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecMod4*sv
//	Calculate remainder of scalar by 4D vector components.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecMod4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecModSafe4*sv
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param v_out: output vector to hold remainder
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecModSafe4dsv(double4 v_out, f64 const s_lh, double4 const v_rh);

// ijkVecEqual4*sv
//	Equality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecInequal4*sv
//	Inequality comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecInequal4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecLessEqual4*sv
//	Less-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLessEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecGreaterEqual4*sv
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreaterEqual4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecLess4*sv
//	Less-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecLess4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecGreater4*sv
//	Greater-than comparison of scalar and 4D vector components.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecGreater4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecAnd4*sv
//	Component-wise logical 'and' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecAnd4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecNand4*sv
//	Component-wise logical 'nand' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNand4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecOr4*sv
//	Component-wise logical 'or' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecOr4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecNor4*sv
//	Component-wise logical 'nor' of 4D vector and scalar.
//		param bv_out: output vector holding boolean results of comparisons
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: bv_out
boolv ijkVecNor4dsv(bool4 bv_out, f64 const s_lh, double4 const v_rh);

// ijkVecDot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
f64 ijkVecDot4dv(double4 const v_lh, double4 const v_rh);

// ijkVecCross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
doublev ijkVecCross4dv(double4 v_out, double4 const v_lh, double4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecAbs1*
//	Absolute value of scalar: (s >= 0 ? +s : -s).
//		param s: scalar
//		return: absolute value
double ijkVecAbs1d(double const s);

// ijkVecSgn1*
//	Sign of scalar: (s != 0 ? s > 0 ? +1 : -1).
//		param s: scalar
//		return: sign
double ijkVecSgn1d(double const s);

// ijkVecDot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
double ijkVecDot1d(double const s_lh, double const s_rh);

// ijkVecLengthSq1*
//	Squared length of scalar.
//		param s: scalar
//		return: squared length
double ijkVecLengthSq1d(double const s);

// ijkVecLength1*
//	Length of scalar.
//		param s: scalar
//		return: length
double ijkVecLength1d(double const s);

// ijkVecLengthSqInv1*
//	Inverse squared length of scalar.
//		param s: scalar
//		return: inverse squared length
double ijkVecLengthSqInv1d(double const s);

// ijkVecLengthSqInv1*
//	Inverse length of scalar.
//		param s: scalar
//		return: inverse length
double ijkVecLengthInv1d(double const s);

// ijkVecNormalize1*
//	Calculate unit scalar in same direction as input (sign).
//		param s: scalar
//		return: unit scalar (sign)
double ijkVecNormalize1d(double const s);

// ijkVecNormalizeGetLength1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the length (absolute value).
//		param s: scalar
//		param length_out: pointer to length storage
//		return: unit scalar (sign)
double ijkVecNormalizeGetLength1d(double const s, double* const length_out);

// ijkVecNormalizeGetLengthInv1*
//	Calculate unit scalar in same direction as input (sign).
//	Also calculate and store the inverse length length (absolute value).
//		param s: scalar
//		param lengthInv_out: pointer to length storage
//		return: unit scalar (sign)
double ijkVecNormalizeGetLengthInv1d(double const s, double* const lengthInv_out);


//-----------------------------------------------------------------------------

// ijkVecInit2*
//	Initialize 2D vector to default value (zero vector).
//		return: default vector
dvec2 ijkVecInit2d();

// ijkVecInitElems2*
//	Initialize 2D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		return: result vector
dvec2 ijkVecInitElems2d(double const x, double const y);

// ijkVecCopy2*
//	Copy 2D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
dvec2 ijkVecCopy2d(dvec2 const v_in);

// ijkVecNegate2*
//	Negate 2D vector.
//		param v_in: input vector
//		return: result vector
dvec2 ijkVecNegate2d(dvec2 const v_in);

// ijkVecNot2*
//	Calculate component-wise logical 'not' of 2D vector.
//		param v_in: input vector
//		return: comparison vector
bvec2 ijkVecNot2d(dvec2 const v_in);

// ijkVecAdd2*
//	Calculate sum of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecAdd2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecSub2*
//	Calculate difference of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecSub2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecMul2*
//	Calculate component-wise product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecMul2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecDiv2*
//	Calculate component-wise quotient of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecDiv2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecDivSafe2*
//	Calculate component-wise quotient of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecDivSafe2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecMod2*
//	Calculate component-wise remainder of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecMod2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecModSafe2*
//	Calculate component-wise remainder of 2D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecModSafe2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecEqual2*
//	Equality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecInequal2*
//	Inequality comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecLessEqual2*
//	Less-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecGreaterEqual2*
//	Greater-than or equal comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecLess2*
//	Less-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecGreater2*
//	Greater-than comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecAnd2*
//	Component-wise logical 'and' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecNand2*
//	Component-wise logical 'nand' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecOr2*
//	Component-wise logical 'or' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecNor2*
//	Component-wise logical 'nor' comparison for 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecCopy2*s
//	Copy 2D vector from scalar.
//		param s_in: input scalar
//		return: result vector
dvec2 ijkVecCopy2ds(double const s_in);

// ijkVecNegate2*s
//	Negate scalar to 2D vector.
//		param s_in: input scalar
//		return: result vector
dvec2 ijkVecNegate2ds(double const s_in);

// ijkVecNot2*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec2 ijkVecNot2ds(double const s_in);

// ijkVecAdd2*s
//	Calculate sum of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecAdd2ds(dvec2 const v_lh, double const s_rh);

// ijkVecSub2*s
//	Calculate difference of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecSub2ds(dvec2 const v_lh, double const s_rh);

// ijkVecMul2*s
//	Calculate product of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecMul2ds(dvec2 const v_lh, double const s_rh);

// ijkVecDiv2*s
//	Calculate quotient of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecDiv2ds(dvec2 const v_lh, double const s_rh);

// ijkVecDivSafe2*s
//	Calculate quotient of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecDivSafe2ds(dvec2 const v_lh, double const s_rh);

// ijkVecMod2*s
//	Calculate remainder of 2D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecMod2ds(dvec2 const v_lh, double const s_rh);

// ijkVecModSafe2*s
//	Calculate remainder of 2D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec2 ijkVecModSafe2ds(dvec2 const v_lh, double const s_rh);

// ijkVecEqual2*s
//	Equality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecEqual2ds(dvec2 const v_lh, double const s_rh);

// ijkVecInequal2*s
//	Inequality comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecInequal2ds(dvec2 const v_lh, double const s_rh);

// ijkVecLessEqual2*s
//	Less-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLessEqual2ds(dvec2 const v_lh, double const s_rh);

// ijkVecGreaterEqual2*s
//	Greater-than or equal comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreaterEqual2ds(dvec2 const v_lh, double const s_rh);

// ijkVecLess2*s
//	Less-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecLess2ds(dvec2 const v_lh, double const s_rh);

// ijkVecGreater2*s
//	Greater-than comparison of 2D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecGreater2ds(dvec2 const v_lh, double const s_rh);

// ijkVecAnd2*s
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecAnd2ds(dvec2 const v_lh, double const s_rh);

// ijkVecNand2*s
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNand2ds(dvec2 const v_lh, double const s_rh);

// ijkVecOr2*s
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecOr2ds(dvec2 const v_lh, double const s_rh);

// ijkVecNor2*s
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec2 ijkVecNor2ds(dvec2 const v_lh, double const s_rh);

// ijkVecAdd2s*
//	Calculate sum of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecAdd2sd(double const s_lh, dvec2 const v_rh);

// ijkVecSub2s*
//	Calculate difference of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecSub2sd(double const s_lh, dvec2 const v_rh);

// ijkVecMul2s*
//	Calculate product of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecMul2sd(double const s_lh, dvec2 const v_rh);

// ijkVecDiv2s*
//	Calculate quotient of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecDiv2sd(double const s_lh, dvec2 const v_rh);

// ijkVecDivSafe2s*
//	Calculate quotient of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecDivSafe2sd(double const s_lh, dvec2 const v_rh);

// ijkVecMod2s*
//	Calculate remainder of scalar by 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecMod2sd(double const s_lh, dvec2 const v_rh);

// ijkVecModSafe2s*
//	Calculate remainder of scalar by 2D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec2 ijkVecModSafe2sd(double const s_lh, dvec2 const v_rh);

// ijkVecEqual2s*
//	Equality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecEqual2sd(double const s_lh, dvec2 const v_rh);

// ijkVecInequal2s*
//	Inequality comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecInequal2sd(double const s_lh, dvec2 const v_rh);

// ijkVecLessEqual2s*
//	Less-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLessEqual2sd(double const s_lh, dvec2 const v_rh);

// ijkVecGreaterEqual2s*
//	Greater-than or equal comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreaterEqual2sd(double const s_lh, dvec2 const v_rh);

// ijkVecLess2s*
//	Less-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecLess2sd(double const s_lh, dvec2 const v_rh);

// ijkVecGreater2s*
//	Greater-than comparison of scalar and 2D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecGreater2sd(double const s_lh, dvec2 const v_rh);

// ijkVecAnd2s*
//	Component-wise logical 'and' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecAnd2sd(double const s_lh, dvec2 const v_rh);

// ijkVecNand2s*
//	Component-wise logical 'nand' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNand2sd(double const s_lh, dvec2 const v_rh);

// ijkVecOr2s*
//	Component-wise logical 'or' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecOr2sd(double const s_lh, dvec2 const v_rh);

// ijkVecNor2s*
//	Component-wise logical 'nor' comparison of 2D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec2 ijkVecNor2sd(double const s_lh, dvec2 const v_rh);

// ijkVecDot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
double ijkVecDot2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecCross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
double ijkVecCross2d(dvec2 const v_lh, dvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit3*
//	Initialize 3D vector to default value (zero vector).
//		return: default vector
dvec3 ijkVecInit3d();

// ijkVecInitElems3*
//	Initialize 3D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		return: result vector
dvec3 ijkVecInitElems3d(double const x, double const y, double const z);

// ijkVecCopy3*
//	Copy 3D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
dvec3 ijkVecCopy3d(dvec3 const v_in);

// ijkVecNegate3*
//	Negate 3D vector.
//		param v_in: input vector
//		return: result vector
dvec3 ijkVecNegate3d(dvec3 const v_in);

// ijkVecNot3*
//	Calculate component-wise logical 'not' of 3D vector.
//		param v_in: input vector
//		return: comparison vector
bvec3 ijkVecNot3d(dvec3 const v_in);

// ijkVecAdd3*
//	Calculate sum of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecAdd3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecSub3*
//	Calculate difference of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecSub3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecMul3*
//	Calculate component-wise product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecMul3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecDiv3*
//	Calculate component-wise quotient of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecDiv3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecDivSafe3*
//	Calculate component-wise quotient of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecDivSafe3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecMod3*
//	Calculate component-wise remainder of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecMod3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecModSafe3*
//	Calculate component-wise remainder of 3D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecModSafe3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecEqual3*
//	Equality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecInequal3*
//	Inequality comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecLessEqual3*
//	Less-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecGreaterEqual3*
//	Greater-than or equal comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecLess3*
//	Less-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecGreater3*
//	Greater-than comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecAnd3*
//	Component-wise logical 'and' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecNand3*
//	Component-wise logical 'nand' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecOr3*
//	Component-wise logical 'or' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecNor3*
//	Component-wise logical 'nor' comparison for 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecCopy3*z
//	Copy 3D vector from 2D vector and one scalar.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		return: result vector
dvec3 ijkVecCopy3dz(dvec2 const v_xy, double const z);

// ijkVecCopy3*s
//	Copy 3D vector from scalar.
//		param s_in: input scalar
//		return: result vector
dvec3 ijkVecCopy3ds(double const s_in);

// ijkVecNegate3*s
//	Negate scalar to 3D vector.
//		param s_in: input scalar
//		return: result vector
dvec3 ijkVecNegate3ds(double const s_in);

// ijkVecNot3*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec3 ijkVecNot3ds(double const s_in);

// ijkVecAdd3*s
//	Calculate sum of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecAdd3ds(dvec3 const v_lh, double const s_rh);

// ijkVecSub3*s
//	Calculate difference of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecSub3ds(dvec3 const v_lh, double const s_rh);

// ijkVecMul3*s
//	Calculate product of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecMul3ds(dvec3 const v_lh, double const s_rh);

// ijkVecDiv3*s
//	Calculate quotient of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecDiv3ds(dvec3 const v_lh, double const s_rh);

// ijkVecDivSafe3*s
//	Calculate quotient of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecDivSafe3ds(dvec3 const v_lh, double const s_rh);

// ijkVecMod3*s
//	Calculate remainder of 3D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecMod3ds(dvec3 const v_lh, double const s_rh);

// ijkVecModSafe3*s
//	Calculate remainder of 3D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec3 ijkVecModSafe3ds(dvec3 const v_lh, double const s_rh);

// ijkVecEqual3*s
//	Equality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecEqual3ds(dvec3 const v_lh, double const s_rh);

// ijkVecInequal3*s
//	Inequality comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecInequal3ds(dvec3 const v_lh, double const s_rh);

// ijkVecLessEqual3*s
//	Less-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLessEqual3ds(dvec3 const v_lh, double const s_rh);

// ijkVecGreaterEqual3*s
//	Greater-than or equal comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreaterEqual3ds(dvec3 const v_lh, double const s_rh);

// ijkVecLess3*s
//	Less-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecLess3ds(dvec3 const v_lh, double const s_rh);

// ijkVecGreater3*s
//	Greater-than comparison of 3D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecGreater3ds(dvec3 const v_lh, double const s_rh);

// ijkVecAnd3*s
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecAnd3ds(dvec3 const v_lh, double const s_rh);

// ijkVecNand3*s
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNand3ds(dvec3 const v_lh, double const s_rh);

// ijkVecOr3*s
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecOr3ds(dvec3 const v_lh, double const s_rh);

// ijkVecNor3*s
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec3 ijkVecNor3ds(dvec3 const v_lh, double const s_rh);

// ijkVecCopy3x*
//	Copy 3D vector from 2D vector and one scalar.
//		param x: first element
//		param v_yz: input 2D vector holding last two components
//		return: result vector
dvec3 ijkVecCopy3xd(double const x, dvec2 const v_yz);

// ijkVecAdd3s*
//	Calculate sum of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecAdd3sd(double const s_lh, dvec3 const v_rh);

// ijkVecSub3s*
//	Calculate difference of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecSub3sd(double const s_lh, dvec3 const v_rh);

// ijkVecMul3s*
//	Calculate product of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecMul3sd(double const s_lh, dvec3 const v_rh);

// ijkVecDiv3s*
//	Calculate quotient of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecDiv3sd(double const s_lh, dvec3 const v_rh);

// ijkVecDivSafe3s*
//	Calculate quotient of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecDivSafe3sd(double const s_lh, dvec3 const v_rh);

// ijkVecMod3s*
//	Calculate remainder of scalar by 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecMod3sd(double const s_lh, dvec3 const v_rh);

// ijkVecModSafe3s*
//	Calculate remainder of scalar by 3D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec3 ijkVecModSafe3sd(double const s_lh, dvec3 const v_rh);

// ijkVecEqual3s*
//	Equality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecEqual3sd(double const s_lh, dvec3 const v_rh);

// ijkVecInequal3s*
//	Inequality comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecInequal3sd(double const s_lh, dvec3 const v_rh);

// ijkVecLessEqual3s*
//	Less-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLessEqual3sd(double const s_lh, dvec3 const v_rh);

// ijkVecGreaterEqual3s*
//	Greater-than or equal comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreaterEqual3sd(double const s_lh, dvec3 const v_rh);

// ijkVecLess3s*
//	Less-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecLess3sd(double const s_lh, dvec3 const v_rh);

// ijkVecGreater3s*
//	Greater-than comparison of scalar and 3D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecGreater3sd(double const s_lh, dvec3 const v_rh);

// ijkVecAnd3s*
//	Component-wise logical 'and' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecAnd3sd(double const s_lh, dvec3 const v_rh);

// ijkVecNand3s*
//	Component-wise logical 'nand' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNand3sd(double const s_lh, dvec3 const v_rh);

// ijkVecOr3s*
//	Component-wise logical 'or' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecOr3sd(double const s_lh, dvec3 const v_rh);

// ijkVecNor3s*
//	Component-wise logical 'nor' comparison of 3D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec3 ijkVecNor3sd(double const s_lh, dvec3 const v_rh);

// ijkVecDot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
double ijkVecDot3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecCross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
dvec3 ijkVecCross3d(dvec3 const v_lh, dvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInit4*
//	Initialize 4D vector to default value (zero vector).
//		return: default vector
dvec4 ijkVecInit4d();

// ijkVecInitElems4*
//	Initialize 4D vector to specified individual elements.
//		param x: first element
//		param y: second element
//		param z: third element
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: result vector
dvec4 ijkVecInitElems4d(double const x, double const y, double const z, double const w);

// ijkVecCopy4x*w
//	Copy 4D vector from scalar, 2D vector and another scalar.
//		param x: first element
//		param v_yz: input 2D vector holding middle two components
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: result vector
dvec4 ijkVecCopy4xdw(double const x, dvec2 const v_yz, double const w);

// ijkVecCopy4*2
//	Copy 4D vector from two 2D vectors.
//		param v_xy: input 2D vector holding first two components
//		param v_zw: input 2D vector holding last two components
//		return: result vector
dvec4 ijkVecCopy4d2(dvec2 const v_xy, dvec2 const v_zw);

// ijkVecCopy4*
//	Copy 4D vector from first elements of another vector.
//		param v_in: input vector
//		return: result vector
dvec4 ijkVecCopy4d(dvec4 const v_in);

// ijkVecNegate4*
//	Negate 4D vector.
//		param v_in: input vector
//		return: result vector
dvec4 ijkVecNegate4d(dvec4 const v_in);

// ijkVecNot4*
//	Calculate component-wise logical 'not' of 4D vector.
//		param v_in: input vector
//		return: comparison vector
bvec4 ijkVecNot4d(dvec4 const v_in);

// ijkVecAdd4*
//	Calculate sum of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecAdd4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecSub4*
//	Calculate difference of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecSub4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecMul4*
//	Calculate component-wise product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecMul4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecDiv4*
//	Calculate component-wise quotient of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecDiv4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecDivSafe4*
//	Calculate component-wise quotient of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecDivSafe4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecMod4*
//	Calculate component-wise remainder of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecMod4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecModSafe4*
//	Calculate component-wise remainder of 4D vectors, division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecModSafe4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecEqual4*
//	Equality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecInequal4*
//	Inequality comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecLessEqual4*
//	Less-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecGreaterEqual4*
//	Greater-than or equal comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecLess4*
//	Less-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecGreater4*
//	Greater-than comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecAnd4*
//	Component-wise logical 'and' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecNand4*
//	Component-wise logical 'nand' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecOr4*
//	Component-wise logical 'or' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecNor4*
//	Component-wise logical 'nor' comparison for 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecCopy4*zw
//	Copy 4D vector from 2D vector and two scalars.
//		param v_xy: input 2D vector holding first two components
//		param z: third element
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: result vector
dvec4 ijkVecCopy4dzw(dvec2 const v_xy, double const z, double const w);

// ijkVecCopy4*w
//	Copy 4D vector from 3D vector and one scalar.
//		param v_xyz: input 3D vector holding first three components
//		param w: fourth element (in space, set as 1 for podouble, 0 for vector)
//		return: result vector
dvec4 ijkVecCopy4dw(dvec3 const v_xyz, double const w);

// ijkVecCopy4*s
//	Copy 4D vector from scalar.
//		param s_in: input scalar
//		return: result vector
dvec4 ijkVecCopy4ds(double const s_in);

// ijkVecNegate4*s
//	Negate scalar to 4D vector.
//		param s_in: input scalar
//		return: result vector
dvec4 ijkVecNegate4ds(double const s_in);

// ijkVecNot4*s
//	Calculate logical 'not' of scalar.
//		param s_in: input scalar
//		return: comparison vector
bvec4 ijkVecNot4ds(double const s_in);

// ijkVecAdd4*s
//	Calculate sum of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecAdd4ds(dvec4 const v_lh, double const s_rh);

// ijkVecSub4*s
//	Calculate difference of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecSub4ds(dvec4 const v_lh, double const s_rh);

// ijkVecMul4*s
//	Calculate product of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecMul4ds(dvec4 const v_lh, double const s_rh);

// ijkVecDiv4*s
//	Calculate quotient of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecDiv4ds(dvec4 const v_lh, double const s_rh);

// ijkVecDivSafe4*s
//	Calculate quotient of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecDivSafe4ds(dvec4 const v_lh, double const s_rh);

// ijkVecMod4*s
//	Calculate remainder of 4D vector components by scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecMod4ds(dvec4 const v_lh, double const s_rh);

// ijkVecModSafe4*s
//	Calculate remainder of 4D vector components by scalar, division-by-zero safe.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: result vector
dvec4 ijkVecModSafe4ds(dvec4 const v_lh, double const s_rh);

// ijkVecEqual4*s
//	Equality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecEqual4ds(dvec4 const v_lh, double const s_rh);

// ijkVecInequal4*s
//	Inequality comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecInequal4ds(dvec4 const v_lh, double const s_rh);

// ijkVecLessEqual4*s
//	Less-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLessEqual4ds(dvec4 const v_lh, double const s_rh);

// ijkVecGreaterEqual4*s
//	Greater-than or equal comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreaterEqual4ds(dvec4 const v_lh, double const s_rh);

// ijkVecLess4*s
//	Less-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecLess4ds(dvec4 const v_lh, double const s_rh);

// ijkVecGreater4*s
//	Greater-than comparison of 4D vector components and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecGreater4ds(dvec4 const v_lh, double const s_rh);

// ijkVecAnd4*s
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecAnd4ds(dvec4 const v_lh, double const s_rh);

// ijkVecNand4*s
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNand4ds(dvec4 const v_lh, double const s_rh);

// ijkVecOr4*s
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecOr4ds(dvec4 const v_lh, double const s_rh);

// ijkVecNor4*s
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: comparison vector
bvec4 ijkVecNor4ds(dvec4 const v_lh, double const s_rh);

// ijkVecCopy4xy*
//	Copy 4D vector from two scalars and 2D vector.
//		param x: first element
//		param y: second element
//		param v_zw: input 2D vector holding last two components
//		return: result vector
dvec4 ijkVecCopy4xyd(double const x, double const y, dvec2 const v_zw);

// ijkVecCopy4x*
//	Copy 4D vector from one scalar and 3D vector.
//		param x: first element
//		param v_yzw: input 3D vector holding last three components
//		return: result vector
dvec4 ijkVecCopy4xd(double const x, dvec3 const v_yzw);

// ijkVecAdd4s*
//	Calculate sum of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecAdd4sd(double const s_lh, dvec4 const v_rh);

// ijkVecSub4s*
//	Calculate difference of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecSub4sd(double const s_lh, dvec4 const v_rh);

// ijkVecMul4s*
//	Calculate product of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecMul4sd(double const s_lh, dvec4 const v_rh);

// ijkVecDiv4s*
//	Calculate quotient of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecDiv4sd(double const s_lh, dvec4 const v_rh);

// ijkVecDivSafe4s*
//	Calculate quotient of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecDivSafe4sd(double const s_lh, dvec4 const v_rh);

// ijkVecMod4s*
//	Calculate remainder of scalar by 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecMod4sd(double const s_lh, dvec4 const v_rh);

// ijkVecModSafe4s*
//	Calculate remainder of scalar by 4D vector components, division-by-zero safe.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: result vector
dvec4 ijkVecModSafe4sd(double const s_lh, dvec4 const v_rh);

// ijkVecEqual4s*
//	Equality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecEqual4sd(double const s_lh, dvec4 const v_rh);

// ijkVecInequal4s*
//	Inequality comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecInequal4sd(double const s_lh, dvec4 const v_rh);

// ijkVecLessEqual4s*
//	Less-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLessEqual4sd(double const s_lh, dvec4 const v_rh);

// ijkVecGreaterEqual4s*
//	Greater-than or equal comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreaterEqual4sd(double const s_lh, dvec4 const v_rh);

// ijkVecLess4s*
//	Less-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecLess4sd(double const s_lh, dvec4 const v_rh);

// ijkVecGreater4s*
//	Greater-than comparison of scalar and 4D vector components.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecGreater4sd(double const s_lh, dvec4 const v_rh);

// ijkVecAnd4s*
//	Component-wise logical 'and' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecAnd4sd(double const s_lh, dvec4 const v_rh);

// ijkVecNand4s*
//	Component-wise logical 'nand' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNand4sd(double const s_lh, dvec4 const v_rh);

// ijkVecOr4s*
//	Component-wise logical 'or' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecOr4sd(double const s_lh, dvec4 const v_rh);

// ijkVecNor4s*
//	Component-wise logical 'nor' comparison of 4D vector and scalar.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: comparison vector
bvec4 ijkVecNor4sd(double const s_lh, dvec4 const v_rh);

// ijkVecDot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
double ijkVecDot4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecCross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
dvec4 ijkVecCross4d(dvec4 const v_lh, dvec4 const v_rh);


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f64 ijkVecLengthSq2dv(double2 const v_in);

// ijkVecLength2*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f64 ijkVecLength2dv(double2 const v_in);

// ijkVecLengthSqInv2*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInv2dv(double2 const v_in);

// ijkVecLengthSqInvSafe2*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInvSafe2dv(double2 const v_in);

// ijkVecLengthInv2*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInv2dv(double2 const v_in);

// ijkVecLengthInvSafe2*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInvSafe2dv(double2 const v_in);

// ijkVecNormalize2*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalize2dv(double2 v_out, double2 const v_in);

// ijkVecNormalizeSafe2*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalizeSafe2dv(double2 v_out, double2 const v_in);

// ijkVecNormalizeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLength2dv(double2 v_out, double2 const v_in, f64* const length_out);

// ijkVecNormalizeSafeGetLength2*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLength2dv(double2 v_out, double2 const v_in, f64* const length_out);

// ijkVecNormalizeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLengthInv2dv(double2 v_out, double2 const v_in, f64* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv2*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLengthInv2dv(double2 v_out, double2 const v_in, f64* const lengthInv_out);

// ijkVecCrossNormalize2*v
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
f64 ijkVecCrossNormalize2dv(double2 const v_lh, double2 const v_rh);

// ijkVecCrossNormalizeSafe2*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
f64 ijkVecCrossNormalizeSafe2dv(double2 const v_lh, double2 const v_rh);

// ijkVecCrossNormalizeGetLength2*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
f64 ijkVecCrossNormalizeGetLength2dv(double2 const v_lh, double2 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeSafeGetLength2*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
f64 ijkVecCrossNormalizeSafeGetLength2dv(double2 const v_lh, double2 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
f64 ijkVecCrossNormalizeGetLengthInv2dv(double2 const v_lh, double2 const v_rh, f64* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv2*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
f64 ijkVecCrossNormalizeSafeGetLengthInv2dv(double2 const v_lh, double2 const v_rh, f64* const lengthInv_out);

// ijkVecLerp2*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecLerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u);

// ijkVecLerpInv2*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
doublev ijkVecLerpInv2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v_lerp);

// ijkVecLerpRevInit2*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
doublev ijkVecLerpRevInit2dv(double2 v0_out, double2 const v_lerp, double2 const v1, f64 const u);

// ijkVecLerpRevTerm2*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
doublev ijkVecLerpRevTerm2dv(double2 v1_out, double2 const v0, double2 const v_lerp, f64 const u);

// ijkVecProjRatio2*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f64 ijkVecProjRatio2dv(double2 const v_base, double2 const v_in);

// ijkVecProj2*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
doublev ijkVecProj2dv(double2 v_out, double2 const v_base, double2 const v_in);

// ijkVecOrtho2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
doublev ijkVecOrtho2dv(double2 v_out, double2 const v_base, double2 const v_in);

// ijkVecOrthoNorm2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
doublev ijkVecOrthoNorm2dv(double2 v_out, double2 const v_base, double2 const v_in, double2 v_base_norm_out);

// ijkVecOrthoList2*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
double2* ijkVecOrthoList2dv(double2 vl_out[], double2 const v_base, double2 const vl_in[], size const n);

// ijkVecOrthoNormList2*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
double2* ijkVecOrthoNormList2dv(double2 vl_out[], double2 const v_base, double2 const vl_in[], size const n, double2 v_base_norm_out);

// ijkVecNlerp2*v
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecNlerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u);

// ijkVecSlerp2*v
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecSlerp2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u);

// ijkVecReflectScale2*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflectScale2dv(double2 v_out, double2 const v_in, double2 const v_nrm);

// ijkVecUnitReflect2*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecUnitReflect2dv(double2 v_out, double2 const v_in, double2 const v_nrm);

// ijkVecReflect2*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflect2dv(double2 v_out, double2 const v_in, double2 const v_nrm);

// ijkVecDistance2*v
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
f64 ijkVecDistance2dv(double2 const v_lh, double2 const v_rh);

// ijkVecResize2*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResize2dv(double2 v_out, double2 const v_in, f64 const length);

// ijkVecResizeSafe2*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResizeSafe2dv(double2 v_out, double2 const v_in, f64 const length);

// ijkVecCrossResize2*v
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
f64 ijkVecCrossResize2dv(double2 const v_lh, double2 const v_rh, f64 const length);

// ijkVecCrossResizeSafe2*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
f64 ijkVecCrossResizeSafe2dv(double2 const v_lh, double2 const v_rh, f64 const length);

// ijkVecNearest2*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
doublev ijkVecNearest2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u);

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
doublev ijkVecBinearest2dv(double2 v_out, double2 const v00, double2 const v01, double2 const v10, double2 const v11, f64 const u0, f64 const u1, f64 const u);

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
doublev ijkVecRemap2dv(double2 v_out, double2 const v0_dst, double2 const v1_dst, double2 const v0_src, double2 const v1_src, double2 const v_src);

// ijkVecBezier0O2*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
doublev ijkVecBezier0O2dv(double2 v_out, double2 const v0, f64 const u);

// ijkVecBezier1O2*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
doublev ijkVecBezier1O2dv(double2 v_out, double2 const v0, double2 const v1, f64 const u);

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
doublev ijkVecBezier2O2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v2, f64 const u);

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
doublev ijkVecBezier3O2dv(double2 v_out, double2 const v0, double2 const v1, double2 const v2, double2 const v3, f64 const u);

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
doublev ijkVecBezierNO2dv(double2 v_out, double2 const v[], size const order, f64 const u);

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
doublev ijkVecCubicHermite2dv(double2 v_out, double2 const v0, double2 const dv0, double2 const v1, double2 const dv1, f64 const u);

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
doublev ijkVecCubicHermiteHandles2dv(double2 v_out, double2 const v0, double2 const cv0, double2 const v1, double2 const cv1, f64 const u);

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
doublev ijkVecCubicCatmullRom2dv(double2 v_out, double2 const vp, double2 const v0, double2 const v1, double2 const v2, f64 const u);

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
doublev ijkVecBicubicCatmullRom2dv(double2 v_out, double2 const vpp, double2 const vp0, double2 const vp1, double2 const vp2, double2 const v0p, double2 const v00, double2 const v01, double2 const v02, double2 const v1p, double2 const v10, double2 const v11, double2 const v12, double2 const v2p, double2 const v20, double2 const v21, double2 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u);

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
f64 ijkVecReparamCubicHermite2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const v0, double2 const dv0, double2 const v1, double2 const dv1);

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
f64 ijkVecReparamCubicHermiteHandles2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const v0, double2 const cv0, double2 const v1, double2 const cv1);

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
f64 ijkVecReparamCubicCatmullRom2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const vp, double2 const v0, double2 const v1, double2 const v2);

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
f64 ijkVecReparamBicubicCatmullRom2dv(f64 uTable_out[], f64 lTable_out[], double2 vTable_out[], size const numDivisions, ibool const lNormalize, double2 const vpp, double2 const vp0, double2 const vp1, double2 const vp2, double2 const v0p, double2 const v00, double2 const v01, double2 const v02, double2 const v1p, double2 const v10, double2 const v11, double2 const v12, double2 const v2p, double2 const v20, double2 const v21, double2 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2);

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
doublev ijkVecSampleTableInc2dv(double2 v_out, f64 const uTable[], double2 const vTable[], index i, index di, f64 const u);

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
doublev ijkVecSampleTableDec2dv(double2 v_out, f64 const uTable[], double2 const vTable[], index i, index di, f64 const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f64 ijkVecLengthSq3dv(double3 const v_in);

// ijkVecLength3*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f64 ijkVecLength3dv(double3 const v_in);

// ijkVecLengthSqInv3*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInv3dv(double3 const v_in);

// ijkVecLengthSqInvSafe3*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInvSafe3dv(double3 const v_in);

// ijkVecLengthInv3*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInv3dv(double3 const v_in);

// ijkVecLengthInvSafe3*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInvSafe3dv(double3 const v_in);

// ijkVecNormalize3*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalize3dv(double3 v_out, double3 const v_in);

// ijkVecNormalizeSafe3*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalizeSafe3dv(double3 v_out, double3 const v_in);

// ijkVecNormalizeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLength3dv(double3 v_out, double3 const v_in, f64* const length_out);

// ijkVecNormalizeSafeGetLength3*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLength3dv(double3 v_out, double3 const v_in, f64* const length_out);

// ijkVecNormalizeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLengthInv3dv(double3 v_out, double3 const v_in, f64* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv3*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLengthInv3dv(double3 v_out, double3 const v_in, f64* const lengthInv_out);

// ijkVecCrossNormalize3*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecCrossNormalize3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecCrossNormalizeSafe3*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecCrossNormalizeSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh);

// ijkVecCrossNormalizeGetLength3*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeGetLength3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeSafeGetLength3*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeSafeGetLength3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeGetLengthInv3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv3*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeSafeGetLengthInv3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64* const lengthInv_out);

// ijkVecLerp3*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecLerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u);

// ijkVecLerpInv3*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
doublev ijkVecLerpInv3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v_lerp);

// ijkVecLerpRevInit3*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
doublev ijkVecLerpRevInit3dv(double3 v0_out, double3 const v_lerp, double3 const v1, f64 const u);

// ijkVecLerpRevTerm3*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
doublev ijkVecLerpRevTerm3dv(double3 v1_out, double3 const v0, double3 const v_lerp, f64 const u);

// ijkVecProjRatio3*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f64 ijkVecProjRatio3dv(double3 const v_base, double3 const v_in);

// ijkVecProj3*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
doublev ijkVecProj3dv(double3 v_out, double3 const v_base, double3 const v_in);

// ijkVecOrtho3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
doublev ijkVecOrtho3dv(double3 v_out, double3 const v_base, double3 const v_in);

// ijkVecOrthoNorm3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
doublev ijkVecOrthoNorm3dv(double3 v_out, double3 const v_base, double3 const v_in, double3 v_base_norm_out);

// ijkVecOrthoList3*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
double3* ijkVecOrthoList3dv(double3 vl_out[], double3 const v_base, double3 const vl_in[], size const n);

// ijkVecOrthoNormList3*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
double3* ijkVecOrthoNormList3dv(double3 vl_out[], double3 const v_base, double3 const vl_in[], size const n, double3 v_base_norm_out);

// ijkVecNlerp3*v
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecNlerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u);

// ijkVecSlerp3*v
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecSlerp3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u);

// ijkVecReflectScale3*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflectScale3dv(double3 v_out, double3 const v_in, double3 const v_nrm);

// ijkVecUnitReflect3*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecUnitReflect3dv(double3 v_out, double3 const v_in, double3 const v_nrm);

// ijkVecReflect3*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflect3dv(double3 v_out, double3 const v_in, double3 const v_nrm);

// ijkVecDistance3*v
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
f64 ijkVecDistance3dv(double3 const v_lh, double3 const v_rh);

// ijkVecResize3*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResize3dv(double3 v_out, double3 const v_in, f64 const length);

// ijkVecResizeSafe3*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResizeSafe3dv(double3 v_out, double3 const v_in, f64 const length);

// ijkVecCrossResize3*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecCrossResize3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64 const length);

// ijkVecCrossResizeSafe3*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecCrossResizeSafe3dv(double3 v_out, double3 const v_lh, double3 const v_rh, f64 const length);

// ijkVecNearest3*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
doublev ijkVecNearest3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u);

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
doublev ijkVecBinearest3dv(double3 v_out, double3 const v00, double3 const v01, double3 const v10, double3 const v11, f64 const u0, f64 const u1, f64 const u);

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
doublev ijkVecRemap3dv(double3 v_out, double3 const v0_dst, double3 const v1_dst, double3 const v0_src, double3 const v1_src, double3 const v_src);

// ijkVecBezier0O3*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
doublev ijkVecBezier0O3dv(double3 v_out, double3 const v0, f64 const u);

// ijkVecBezier1O3*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
doublev ijkVecBezier1O3dv(double3 v_out, double3 const v0, double3 const v1, f64 const u);

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
doublev ijkVecBezier2O3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v2, f64 const u);

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
doublev ijkVecBezier3O3dv(double3 v_out, double3 const v0, double3 const v1, double3 const v2, double3 const v3, f64 const u);

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
doublev ijkVecBezierNO3dv(double3 v_out, double3 const v[], size const order, f64 const u);

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
doublev ijkVecCubicHermite3dv(double3 v_out, double3 const v0, double3 const dv0, double3 const v1, double3 const dv1, f64 const u);

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
doublev ijkVecCubicHermiteHandles3dv(double3 v_out, double3 const v0, double3 const cv0, double3 const v1, double3 const cv1, f64 const u);

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
doublev ijkVecCubicCatmullRom3dv(double3 v_out, double3 const vp, double3 const v0, double3 const v1, double3 const v2, f64 const u);

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
doublev ijkVecBicubicCatmullRom3dv(double3 v_out, double3 const vpp, double3 const vp0, double3 const vp1, double3 const vp2, double3 const v0p, double3 const v00, double3 const v01, double3 const v02, double3 const v1p, double3 const v10, double3 const v11, double3 const v12, double3 const v2p, double3 const v20, double3 const v21, double3 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u);

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
f64 ijkVecReparamCubicHermite3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const v0, double3 const dv0, double3 const v1, double3 const dv1);

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
f64 ijkVecReparamCubicHermiteHandles3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const v0, double3 const cv0, double3 const v1, double3 const cv1);

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
f64 ijkVecReparamCubicCatmullRom3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const vp, double3 const v0, double3 const v1, double3 const v2);

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
f64 ijkVecReparamBicubicCatmullRom3dv(f64 uTable_out[], f64 lTable_out[], double3 vTable_out[], size const numDivisions, ibool const lNormalize, double3 const vpp, double3 const vp0, double3 const vp1, double3 const vp2, double3 const v0p, double3 const v00, double3 const v01, double3 const v02, double3 const v1p, double3 const v10, double3 const v11, double3 const v12, double3 const v2p, double3 const v20, double3 const v21, double3 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2);

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
doublev ijkVecSampleTableInc3dv(double3 v_out, f64 const uTable[], double3 const vTable[], index i, index di, f64 const u);

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
doublev ijkVecSampleTableDec3dv(double3 v_out, f64 const uTable[], double3 const vTable[], index i, index di, f64 const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*v
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
f64 ijkVecLengthSq4dv(double4 const v_in);

// ijkVecLength4*v
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
f64 ijkVecLength4dv(double4 const v_in);

// ijkVecLengthSqInv4*v
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInv4dv(double4 const v_in);

// ijkVecLengthSqInvSafe4*v
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
f64 ijkVecLengthSqInvSafe4dv(double4 const v_in);

// ijkVecLengthInv4*v
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInv4dv(double4 const v_in);

// ijkVecLengthInvSafe4*v
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
f64 ijkVecLengthInvSafe4dv(double4 const v_in);

// ijkVecNormalize4*v
//	Calculate the unit-length direction of a vector.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalize4dv(double4 v_out, double4 const v_in);

// ijkVecNormalizeSafe4*v
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		return: v_out
doublev ijkVecNormalizeSafe4dv(double4 v_out, double4 const v_in);

// ijkVecNormalizeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLength4dv(double4 v_out, double4 const v_in, f64* const length_out);

// ijkVecNormalizeSafeGetLength4*v
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLength4dv(double4 v_out, double4 const v_in, f64* const length_out);

// ijkVecNormalizeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeGetLengthInv4dv(double4 v_out, double4 const v_in, f64* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv4*v
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_out: output vector
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecNormalizeSafeGetLengthInv4dv(double4 v_out, double4 const v_in, f64* const lengthInv_out);

// ijkVecCrossNormalize4*v
//	Calculate unit-length result of cross product.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecCrossNormalize4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecCrossNormalizeSafe4*v
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
doublev ijkVecCrossNormalizeSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh);

// ijkVecCrossNormalizeGetLength4*v
//	Calculate unit-length result of cross product; also capture length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeGetLength4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeSafeGetLength4*v
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeSafeGetLength4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const length_out);

// ijkVecCrossNormalizeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeGetLengthInv4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv4*v
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_out: output unit cross product vector
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: v_out
doublev ijkVecCrossNormalizeSafeGetLengthInv4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64* const lengthInv_out);

// ijkVecLerp4*v
//	Vector linear interpolation.
//		param v_out: output vector, interpolated components
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecLerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u);

// ijkVecLerpInv4*v
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v_out: output vector, interpolation parameter for each component
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: v_out
doublev ijkVecLerpInv4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v_lerp);

// ijkVecLerpRevInit4*v
//	Vector linear interpolation reversal to calculate initial control.
//		param v0_out: output initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v0_out
doublev ijkVecLerpRevInit4dv(double4 v0_out, double4 const v_lerp, double4 const v1, f64 const u);

// ijkVecLerpRevTerm4*v
//	Vector linear interpolation reversal to calculate terminal control.
//		param v1_out: output terminal control vector, result when param is 1
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v1_out
doublev ijkVecLerpRevTerm4dv(double4 v1_out, double4 const v0, double4 const v_lerp, f64 const u);

// ijkVecProjRatio4*v
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
f64 ijkVecProjRatio4dv(double4 const v_base, double4 const v_in);

// ijkVecProj4*v
//	Vector projection.
//		param v_out: output vector, projected input onto base
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: v_out
doublev ijkVecProj4dv(double4 v_out, double4 const v_base, double4 const v_in);

// ijkVecOrtho4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_out: output orthogonalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: v_out
doublev ijkVecOrtho4dv(double4 v_out, double4 const v_base, double4 const v_in);

// ijkVecOrthoNorm4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_out: output orthonormalized vector; difference between input 
//			and its projection onto base vector
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: v_out
doublev ijkVecOrthoNorm4dv(double4 v_out, double4 const v_base, double4 const v_in, double4 v_base_norm_out);

// ijkVecOrthoList4*v
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
double4* ijkVecOrthoList4dv(double4 vl_out[], double4 const v_base, double4 const vl_in[], size const n);

// ijkVecOrthoNormList4*v
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
double4* ijkVecOrthoNormList4dv(double4 vl_out[], double4 const v_base, double4 const vl_in[], size const n, double4 v_base_norm_out);

// ijkVecNlerp4*v
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecNlerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u);

// ijkVecSlerp4*v
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v_out: output vector, interpolated vector
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: v_out
doublev ijkVecSlerp4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u);

// ijkVecReflectScale4*v
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflectScale4dv(double4 v_out, double4 const v_in, double4 const v_nrm);

// ijkVecUnitReflect4*v
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecUnitReflect4dv(double4 v_out, double4 const v_in, double4 const v_nrm);

// ijkVecReflect4*v
//	Reflect incident vector about normal.
//		param v_out: output vector, reflected vector
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: v_out
doublev ijkVecReflect4dv(double4 v_out, double4 const v_in, double4 const v_nrm);

// ijkVecDistance4*v
//	Calculate "distance" between two 4D vectors.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
f64 ijkVecDistance4dv(double4 const v_lh, double4 const v_rh);

// ijkVecResize4*v
//	Change length of vector, retaining direction.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResize4dv(double4 v_out, double4 const v_in, f64 const length);

// ijkVecResizeSafe4*v
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_out: output vector, resized
//		param v_in: input vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecResizeSafe4dv(double4 v_out, double4 const v_in, f64 const length);

// ijkVecCrossResize4*v
//	Change length of cross product result, retaining direction.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecCrossResize4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64 const length);

// ijkVecCrossResizeSafe4*v
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_out: output cross product vector, resized
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: v_out
doublev ijkVecCrossResizeSafe4dv(double4 v_out, double4 const v_lh, double4 const v_rh, f64 const length);

// ijkVecNearest4*v
//	Nearest-neighbor interpolation between two reference values.
//		param v_out: output vector, interpolated
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: v_out
doublev ijkVecNearest4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u);

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
doublev ijkVecBinearest4dv(double4 v_out, double4 const v00, double4 const v01, double4 const v10, double4 const v11, f64 const u0, f64 const u1, f64 const u);

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
doublev ijkVecRemap4dv(double4 v_out, double4 const v0_dst, double4 const v1_dst, double4 const v0_src, double4 const v1_src, double4 const v_src);

// ijkVecBezier0O4*v
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v_out: output vector, interpolated
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v_out
doublev ijkVecBezier0O4dv(double4 v_out, double4 const v0, f64 const u);

// ijkVecBezier1O4*v
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v_out: output vector, interpolated
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: v_out
doublev ijkVecBezier1O4dv(double4 v_out, double4 const v0, double4 const v1, f64 const u);

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
doublev ijkVecBezier2O4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v2, f64 const u);

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
doublev ijkVecBezier3O4dv(double4 v_out, double4 const v0, double4 const v1, double4 const v2, double4 const v3, f64 const u);

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
doublev ijkVecBezierNO4dv(double4 v_out, double4 const v[], size const order, f64 const u);

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
doublev ijkVecCubicHermite4dv(double4 v_out, double4 const v0, double4 const dv0, double4 const v1, double4 const dv1, f64 const u);

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
doublev ijkVecCubicHermiteHandles4dv(double4 v_out, double4 const v0, double4 const cv0, double4 const v1, double4 const cv1, f64 const u);

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
doublev ijkVecCubicCatmullRom4dv(double4 v_out, double4 const vp, double4 const v0, double4 const v1, double4 const v2, f64 const u);

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
doublev ijkVecBicubicCatmullRom4dv(double4 v_out, double4 const vpp, double4 const vp0, double4 const vp1, double4 const vp2, double4 const v0p, double4 const v00, double4 const v01, double4 const v02, double4 const v1p, double4 const v10, double4 const v11, double4 const v12, double4 const v2p, double4 const v20, double4 const v21, double4 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2, f64 const u);

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
f64 ijkVecReparamCubicHermite4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const v0, double4 const dv0, double4 const v1, double4 const dv1);

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
f64 ijkVecReparamCubicHermiteHandles4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const v0, double4 const cv0, double4 const v1, double4 const cv1);

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
f64 ijkVecReparamCubicCatmullRom4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const vp, double4 const v0, double4 const v1, double4 const v2);

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
f64 ijkVecReparamBicubicCatmullRom4dv(f64 uTable_out[], f64 lTable_out[], double4 vTable_out[], size const numDivisions, ibool const lNormalize, double4 const vpp, double4 const vp0, double4 const vp1, double4 const vp2, double4 const v0p, double4 const v00, double4 const v01, double4 const v02, double4 const v1p, double4 const v10, double4 const v11, double4 const v12, double4 const v2p, double4 const v20, double4 const v21, double4 const v22, f64 const up, f64 const u0, f64 const u1, f64 const u2);

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
doublev ijkVecSampleTableInc4dv(double4 v_out, f64 const uTable[], double4 const vTable[], index i, index di, f64 const u);

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
doublev ijkVecSampleTableDec4dv(double4 v_out, f64 const uTable[], double4 const vTable[], index i, index di, f64 const u);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecLengthSq2*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
double ijkVecLengthSq2d(dvec2 const v_in);

// ijkVecLength2*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
double ijkVecLength2d(dvec2 const v_in);

// ijkVecLengthSqInv2*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInv2d(dvec2 const v_in);

// ijkVecLengthSqInvSafe2*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInvSafe2d(dvec2 const v_in);

// ijkVecLengthInv2*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInv2d(dvec2 const v_in);

// ijkVecLengthInvSafe2*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInvSafe2d(dvec2 const v_in);

// ijkVecNormalize2*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
dvec2 ijkVecNormalize2d(dvec2 const v_in);

// ijkVecNormalizeSafe2*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
dvec2 ijkVecNormalizeSafe2d(dvec2 const v_in);

// ijkVecNormalizeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec2 ijkVecNormalizeGetLength2d(dvec2 const v_in, double* const length_out);

// ijkVecNormalizeSafeGetLength2*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec2 ijkVecNormalizeSafeGetLength2d(dvec2 const v_in, double* const length_out);

// ijkVecNormalizeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec2 ijkVecNormalizeGetLengthInv2d(dvec2 const v_in, double* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv2*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec2 ijkVecNormalizeSafeGetLengthInv2d(dvec2 const v_in, double* const lengthInv_out);

// ijkVecCrossNormalize2*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
double ijkVecCrossNormalize2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecCrossNormalizeSafe2*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar cross product sign
double ijkVecCrossNormalizeSafe2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecCrossNormalizeGetLength2*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
double ijkVecCrossNormalizeGetLength2d(dvec2 const v_lh, dvec2 const v_rh, double* const length_out);

// ijkVecCrossNormalizeSafeGetLength2*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: scalar cross product sign
double ijkVecCrossNormalizeSafeGetLength2d(dvec2 const v_lh, dvec2 const v_rh, double* const length_out);

// ijkVecCrossNormalizeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
double ijkVecCrossNormalizeGetLengthInv2d(dvec2 const v_lh, dvec2 const v_rh, double* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv2*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: scalar cross product sign
double ijkVecCrossNormalizeSafeGetLengthInv2d(dvec2 const v_lh, dvec2 const v_rh, double* const lengthInv_out);

// ijkVecLerp2*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec2 ijkVecLerp2d(dvec2 const v0, dvec2 const v1, double const u);

// ijkVecLerpInv2*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
dvec2 ijkVecLerpInv2d(dvec2 const v0, dvec2 const v1, dvec2 const v_lerp);

// ijkVecLerpRevInit2*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
dvec2 ijkVecLerpRevInit2d(dvec2 const v_lerp, dvec2 const v1, double const u);

// ijkVecLerpRevTerm2*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
dvec2 ijkVecLerpRevTerm2d(dvec2 const v0, dvec2 const v_lerp, double const u);

// ijkVecProjRatio2*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
double ijkVecProjRatio2d(dvec2 const v_base, dvec2 const v_in);

// ijkVecProj2*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
dvec2 ijkVecProj2d(dvec2 const v_base, dvec2 const v_in);

// ijkVecOrtho2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
dvec2 ijkVecOrtho2d(dvec2 const v_base, dvec2 const v_in);

// ijkVecOrthoNorm2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
dvec2 ijkVecOrthoNorm2d(dvec2 const v_base, dvec2 const v_in, dvec2* const v_base_norm_out);

// ijkVecOrthoList2*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
dvec2* ijkVecOrthoList2d(dvec2 vl_out[], dvec2 const v_base, dvec2 const vl_in[], size const n);

// ijkVecOrthoNormList2*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
dvec2* ijkVecOrthoNormList2d(dvec2 vl_out[], dvec2 const v_base, dvec2 const vl_in[], size const n, dvec2* const v_base_norm_out);

// ijkVecNlerp2*
//	Calculate normalized linear interpolation between two 2D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec2 ijkVecNlerp2d(dvec2 const v0, dvec2 const v1, double const u);

// ijkVecSlerp2*
//	Calculate spherical linear interpolation between two unit 2D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec2 ijkVecSlerp2d(dvec2 const v0, dvec2 const v1, double const u);

// ijkVecReflectScale2*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec2 ijkVecReflectScale2d(dvec2 const v_in, dvec2 const v_nrm);

// ijkVecUnitReflect2*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec2 ijkVecUnitReflect2d(dvec2 const v_in, dvec2 const v_nrm);

// ijkVecReflect2*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec2 ijkVecReflect2d(dvec2 const v_in, dvec2 const v_nrm);

// ijkVecDistance2*
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
double ijkVecDistance2d(dvec2 const v_lh, dvec2 const v_rh);

// ijkVecResize2*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec2 ijkVecResize2d(dvec2 const v_in, double const length);

// ijkVecResizeSafe2*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec2 ijkVecResizeSafe2d(dvec2 const v_in, double const length);

// ijkVecCrossResize2*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
double ijkVecCrossResize2d(dvec2 const v_lh, dvec2 const v_rh, double const length);

// ijkVecCrossResizeSafe2*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized scalar cross product
double ijkVecCrossResizeSafe2d(dvec2 const v_lh, dvec2 const v_rh, double const length);

// ijkVecNearest2*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
dvec2 ijkVecNearest2d(dvec2 const v0, dvec2 const v1, double const u);

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
dvec2 ijkVecBinearest2d(dvec2 const v00, dvec2 const v01, dvec2 const v10, dvec2 const v11, double const u0, double const u1, double const u);

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
dvec2 ijkVecRemap2d(dvec2 const v0_dst, dvec2 const v1_dst, dvec2 const v0_src, dvec2 const v1_src, dvec2 const v_src);

// ijkVecBezier0O2*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
dvec2 ijkVecBezier0O2d(dvec2 const v0, double const u);

// ijkVecBezier1O2*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
dvec2 ijkVecBezier1O2d(dvec2 const v0, dvec2 const v1, double const u);

// ijkVecBezier2O2*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
dvec2 ijkVecBezier2O2d(dvec2 const v0, dvec2 const v1, dvec2 const v2, double const u);

// ijkVecBezier3O2*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
dvec2 ijkVecBezier3O2d(dvec2 const v0, dvec2 const v1, dvec2 const v2, dvec2 const v3, double const u);

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
dvec2 ijkVecBezierNO2d(dvec2 const v[], size const order, double const u);

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
dvec2 ijkVecCubicHermite2d(dvec2 const v0, dvec2 const dv0, dvec2 const v1, dvec2 const dv1, double const u);

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
dvec2 ijkVecCubicHermiteHandles2d(dvec2 const v0, dvec2 const cv0, dvec2 const v1, dvec2 const cv1, double const u);

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
dvec2 ijkVecCubicCatmullRom2d(dvec2 const vp, dvec2 const v0, dvec2 const v1, dvec2 const v2, double const u);

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
dvec2 ijkVecBicubicCatmullRom2d(dvec2 const vpp, dvec2 const vp0, dvec2 const vp1, dvec2 const vp2, dvec2 const v0p, dvec2 const v00, dvec2 const v01, dvec2 const v02, dvec2 const v1p, dvec2 const v10, dvec2 const v11, dvec2 const v12, dvec2 const v2p, dvec2 const v20, dvec2 const v21, dvec2 const v22, double const up, double const u0, double const u1, double const u2, double const u);

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
double ijkVecReparamCubicHermite2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const v0, dvec2 const dv0, dvec2 const v1, dvec2 const dv1);

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
double ijkVecReparamCubicHermiteHandles2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const v0, dvec2 const cv0, dvec2 const v1, dvec2 const cv1);

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
double ijkVecReparamCubicCatmullRom2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const vp, dvec2 const v0, dvec2 const v1, dvec2 const v2);

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
double ijkVecReparamBicubicCatmullRom2d(double uTable_out[], double lTable_out[], dvec2 vTable_out[], size const numDivisions, ibool const lNormalize, dvec2 const vpp, dvec2 const vp0, dvec2 const vp1, dvec2 const vp2, dvec2 const v0p, dvec2 const v00, dvec2 const v01, dvec2 const v02, dvec2 const v1p, dvec2 const v10, dvec2 const v11, dvec2 const v12, dvec2 const v2p, dvec2 const v20, dvec2 const v21, dvec2 const v22, double const up, double const u0, double const u1, double const u2);

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
dvec2 ijkVecSampleTableInc2d(double const uTable[], dvec2 const vTable[], index i, index di, double const u);

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
dvec2 ijkVecSampleTableDec2d(double const uTable[], dvec2 const vTable[], index i, index di, double const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq3*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
double ijkVecLengthSq3d(dvec3 const v_in);

// ijkVecLength3*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
double ijkVecLength3d(dvec3 const v_in);

// ijkVecLengthSqInv3*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInv3d(dvec3 const v_in);

// ijkVecLengthSqInvSafe3*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInvSafe3d(dvec3 const v_in);

// ijkVecLengthInv3*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInv3d(dvec3 const v_in);

// ijkVecLengthInvSafe3*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInvSafe3d(dvec3 const v_in);

// ijkVecNormalize3*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
dvec3 ijkVecNormalize3d(dvec3 const v_in);

// ijkVecNormalizeSafe3*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
dvec3 ijkVecNormalizeSafe3d(dvec3 const v_in);

// ijkVecNormalizeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec3 ijkVecNormalizeGetLength3d(dvec3 const v_in, double* const length_out);

// ijkVecNormalizeSafeGetLength3*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec3 ijkVecNormalizeSafeGetLength3d(dvec3 const v_in, double* const length_out);

// ijkVecNormalizeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec3 ijkVecNormalizeGetLengthInv3d(dvec3 const v_in, double* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv3*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec3 ijkVecNormalizeSafeGetLengthInv3d(dvec3 const v_in, double* const lengthInv_out);

// ijkVecCrossNormalize3*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
dvec3 ijkVecCrossNormalize3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecCrossNormalizeSafe3*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
dvec3 ijkVecCrossNormalizeSafe3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecCrossNormalizeGetLength3*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
dvec3 ijkVecCrossNormalizeGetLength3d(dvec3 const v_lh, dvec3 const v_rh, double* const length_out);

// ijkVecCrossNormalizeSafeGetLength3*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
dvec3 ijkVecCrossNormalizeSafeGetLength3d(dvec3 const v_lh, dvec3 const v_rh, double* const length_out);

// ijkVecCrossNormalizeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
dvec3 ijkVecCrossNormalizeGetLengthInv3d(dvec3 const v_lh, dvec3 const v_rh, double* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv3*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
dvec3 ijkVecCrossNormalizeSafeGetLengthInv3d(dvec3 const v_lh, dvec3 const v_rh, double* const lengthInv_out);

// ijkVecLerp3*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec3 ijkVecLerp3d(dvec3 const v0, dvec3 const v1, double const u);

// ijkVecLerpInv3*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
dvec3 ijkVecLerpInv3d(dvec3 const v0, dvec3 const v1, dvec3 const v_lerp);

// ijkVecLerpRevInit3*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
dvec3 ijkVecLerpRevInit3d(dvec3 const v_lerp, dvec3 const v1, double const u);

// ijkVecLerpRevTerm3*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
dvec3 ijkVecLerpRevTerm3d(dvec3 const v0, dvec3 const v_lerp, double const u);

// ijkVecProjRatio3*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
double ijkVecProjRatio3d(dvec3 const v_base, dvec3 const v_in);

// ijkVecProj3*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
dvec3 ijkVecProj3d(dvec3 const v_base, dvec3 const v_in);

// ijkVecOrtho3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
dvec3 ijkVecOrtho3d(dvec3 const v_base, dvec3 const v_in);

// ijkVecOrthoNorm3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
dvec3 ijkVecOrthoNorm3d(dvec3 const v_base, dvec3 const v_in, dvec3* const v_base_norm_out);

// ijkVecOrthoList3*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
dvec3* ijkVecOrthoList3d(dvec3 vl_out[], dvec3 const v_base, dvec3 const vl_in[], size const n);

// ijkVecOrthoNormList3*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
dvec3* ijkVecOrthoNormList3d(dvec3 vl_out[], dvec3 const v_base, dvec3 const vl_in[], size const n, dvec3* const v_base_norm_out);

// ijkVecNlerp3*
//	Calculate normalized linear interpolation between two 3D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec3 ijkVecNlerp3d(dvec3 const v0, dvec3 const v1, double const u);

// ijkVecSlerp3*
//	Calculate spherical linear interpolation between two unit 3D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec3 ijkVecSlerp3d(dvec3 const v0, dvec3 const v1, double const u);

// ijkVecReflectScale3*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec3 ijkVecReflectScale3d(dvec3 const v_in, dvec3 const v_nrm);

// ijkVecUnitReflect3*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec3 ijkVecUnitReflect3d(dvec3 const v_in, dvec3 const v_nrm);

// ijkVecReflect3*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec3 ijkVecReflect3d(dvec3 const v_in, dvec3 const v_nrm);

// ijkVecDistance3*
//	Calculate distance between two points.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
double ijkVecDistance3d(dvec3 const v_lh, dvec3 const v_rh);

// ijkVecResize3*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec3 ijkVecResize3d(dvec3 const v_in, double const length);

// ijkVecResizeSafe3*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec3 ijkVecResizeSafe3d(dvec3 const v_in, double const length);

// ijkVecCrossResize3*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
dvec3 ijkVecCrossResize3d(dvec3 const v_lh, dvec3 const v_rh, double const length);

// ijkVecCrossResizeSafe3*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
dvec3 ijkVecCrossResizeSafe3d(dvec3 const v_lh, dvec3 const v_rh, double const length);

// ijkVecNearest3*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
dvec3 ijkVecNearest3d(dvec3 const v0, dvec3 const v1, double const u);

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
dvec3 ijkVecBinearest3d(dvec3 const v00, dvec3 const v01, dvec3 const v10, dvec3 const v11, double const u0, double const u1, double const u);

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
dvec3 ijkVecRemap3d(dvec3 const v0_dst, dvec3 const v1_dst, dvec3 const v0_src, dvec3 const v1_src, dvec3 const v_src);

// ijkVecBezier0O3*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
dvec3 ijkVecBezier0O3d(dvec3 const v0, double const u);

// ijkVecBezier1O3*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
dvec3 ijkVecBezier1O3d(dvec3 const v0, dvec3 const v1, double const u);

// ijkVecBezier2O3*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
dvec3 ijkVecBezier2O3d(dvec3 const v0, dvec3 const v1, dvec3 const v2, double const u);

// ijkVecBezier3O3*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
dvec3 ijkVecBezier3O3d(dvec3 const v0, dvec3 const v1, dvec3 const v2, dvec3 const v3, double const u);

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
dvec3 ijkVecBezierNO3d(dvec3 const v[], size const order, double const u);

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
dvec3 ijkVecCubicHermite3d(dvec3 const v0, dvec3 const dv0, dvec3 const v1, dvec3 const dv1, double const u);

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
dvec3 ijkVecCubicHermiteHandles3d(dvec3 const v0, dvec3 const cv0, dvec3 const v1, dvec3 const cv1, double const u);

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
dvec3 ijkVecCubicCatmullRom3d(dvec3 const vp, dvec3 const v0, dvec3 const v1, dvec3 const v2, double const u);

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
dvec3 ijkVecBicubicCatmullRom3d(dvec3 const vpp, dvec3 const vp0, dvec3 const vp1, dvec3 const vp2, dvec3 const v0p, dvec3 const v00, dvec3 const v01, dvec3 const v02, dvec3 const v1p, dvec3 const v10, dvec3 const v11, dvec3 const v12, dvec3 const v2p, dvec3 const v20, dvec3 const v21, dvec3 const v22, double const up, double const u0, double const u1, double const u2, double const u);

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
double ijkVecReparamCubicHermite3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const v0, dvec3 const dv0, dvec3 const v1, dvec3 const dv1);

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
double ijkVecReparamCubicHermiteHandles3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const v0, dvec3 const cv0, dvec3 const v1, dvec3 const cv1);

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
double ijkVecReparamCubicCatmullRom3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const vp, dvec3 const v0, dvec3 const v1, dvec3 const v2);

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
double ijkVecReparamBicubicCatmullRom3d(double uTable_out[], double lTable_out[], dvec3 vTable_out[], size const numDivisions, ibool const lNormalize, dvec3 const vpp, dvec3 const vp0, dvec3 const vp1, dvec3 const vp2, dvec3 const v0p, dvec3 const v00, dvec3 const v01, dvec3 const v02, dvec3 const v1p, dvec3 const v10, dvec3 const v11, dvec3 const v12, dvec3 const v2p, dvec3 const v20, dvec3 const v21, dvec3 const v22, double const up, double const u0, double const u1, double const u2);

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
dvec3 ijkVecSampleTableInc3d(double const uTable[], dvec3 const vTable[], index i, index di, double const u);

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
dvec3 ijkVecSampleTableDec3d(double const uTable[], dvec3 const vTable[], index i, index di, double const u);


//-----------------------------------------------------------------------------

// ijkVecLengthSq4*
//	Calculate the squared length of a vector.
//		param v_in: input vector
//		return: squared length
double ijkVecLengthSq4d(dvec4 const v_in);

// ijkVecLength4*
//	Calculate the length of a vector.
//		param v_in: input vector
//		return: length
double ijkVecLength4d(dvec4 const v_in);

// ijkVecLengthSqInv4*
//	Calculate the inverse squared length of a vector.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInv4d(dvec4 const v_in);

// ijkVecLengthSqInvSafe4*
//	Calculate the inverse squared length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse squared length
double ijkVecLengthSqInvSafe4d(dvec4 const v_in);

// ijkVecLengthInv4*
//	Calculate the inverse length of a vector.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInv4d(dvec4 const v_in);

// ijkVecLengthInvSafe4*
//	Calculate the inverse length of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: inverse length
double ijkVecLengthInvSafe4d(dvec4 const v_in);

// ijkVecNormalize4*
//	Calculate the unit-length direction of a vector.
//		param v_in: input vector
//		return: unit-length direction vector
dvec4 ijkVecNormalize4d(dvec4 const v_in);

// ijkVecNormalizeSafe4*
//	Calculate the unit-length direction of a vector; division-by-zero safe.
//		param v_in: input vector
//		return: unit-length direction vector
dvec4 ijkVecNormalizeSafe4d(dvec4 const v_in);

// ijkVecNormalizeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec4 ijkVecNormalizeGetLength4d(dvec4 const v_in, double* const length_out);

// ijkVecNormalizeSafeGetLength4*
//	Calculate the unit-length direction of a vector; also capture the length 
//	of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec4 ijkVecNormalizeSafeGetLength4d(dvec4 const v_in, double* const length_out);

// ijkVecNormalizeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec4 ijkVecNormalizeGetLengthInv4d(dvec4 const v_in, double* const lengthInv_out);

// ijkVecNormalizeSafeGetLengthInv4*
//	Calculate the unit-length direction of a vector; also capture the inverse 
//	length of the input vector; division-by-zero safe.
//		param v_in: input vector
//		param length_out: pointer to length storage
//		return: unit-length direction vector
dvec4 ijkVecNormalizeSafeGetLengthInv4d(dvec4 const v_in, double* const lengthInv_out);

// ijkVecCrossNormalize4*
//	Calculate unit-length result of cross product.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
dvec4 ijkVecCrossNormalize4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecCrossNormalizeSafe4*
//	Calculate unit-length result of cross product; division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: unit cross product
dvec4 ijkVecCrossNormalizeSafe4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecCrossNormalizeGetLength4*
//	Calculate unit-length result of cross product; also capture length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
dvec4 ijkVecCrossNormalizeGetLength4d(dvec4 const v_lh, dvec4 const v_rh, double* const length_out);

// ijkVecCrossNormalizeSafeGetLength4*
//	Calculate unit-length result of cross product; also capture length; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param length_out: pointer to length storage
//		return: unit cross product
dvec4 ijkVecCrossNormalizeSafeGetLength4d(dvec4 const v_lh, dvec4 const v_rh, double* const length_out);

// ijkVecCrossNormalizeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
dvec4 ijkVecCrossNormalizeGetLengthInv4d(dvec4 const v_lh, dvec4 const v_rh, double* const lengthInv_out);

// ijkVecCrossNormalizeSafeGetLengthInv4*
//	Calculate unit-length result of cross product; also capture inverse length;
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		param lengthInv_out: pointer to length storage
//		return: unit cross product
dvec4 ijkVecCrossNormalizeSafeGetLengthInv4d(dvec4 const v_lh, dvec4 const v_rh, double* const lengthInv_out);

// ijkVecLerp4*
//	Vector linear interpolation.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec4 ijkVecLerp4d(dvec4 const v0, dvec4 const v1, double const u);

// ijkVecLerpInv4*
//	Vector linear interpolation inverse to calculate parameters given control .
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param v_lerp: interpolated vector used to calculate parameters; params 
//			in range [0,1] indicate interpolation, others for extrapolation
//		return: interpolation parameter for each component
dvec4 ijkVecLerpInv4d(dvec4 const v0, dvec4 const v1, dvec4 const v_lerp);

// ijkVecLerpRevInit4*
//	Vector linear interpolation reversal to calculate initial control.
//		param v_lerp: input interpolated vector
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: initial control vector, result when param is 0
dvec4 ijkVecLerpRevInit4d(dvec4 const v_lerp, dvec4 const v1, double const u);

// ijkVecLerpRevTerm4*
//	Vector linear interpolation reversal to calculate terminal control.
//		param v0: input initial control vector, result when param is 0
//		param v_lerp: input interpolated vector
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: terminal control vector, result when param is 1
dvec4 ijkVecLerpRevTerm4d(dvec4 const v0, dvec4 const v_lerp, double const u);

// ijkVecProjRatio4*
//	Calculate projection length ratio.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: length ratio of projected vector to base
double ijkVecProjRatio4d(dvec4 const v_base, dvec4 const v_in);

// ijkVecProj4*
//	Vector projection.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be projected
//		return: projected input onto base
dvec4 ijkVecProj4d(dvec4 const v_base, dvec4 const v_in);

// ijkVecOrtho4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthogonalized
//		return: output orthogonalized vector
dvec4 ijkVecOrtho4d(dvec4 const v_base, dvec4 const v_in);

// ijkVecOrthoNorm4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param v_base: fixed base vector onto which input is projected
//		param v_in: input vector to be orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: output orthonormalized vector
dvec4 ijkVecOrthoNorm4d(dvec4 const v_base, dvec4 const v_in, dvec4* const v_base_norm_out);

// ijkVecOrthoList4*
//	Vector orthogonalization using the Gram-Schmidt process.
//		param vl_out: output list of orthogonalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthogonalized
//		param n: number of vectors to orthogonalize
//		return: vl_out
dvec4* ijkVecOrthoList4d(dvec4 vl_out[], dvec4 const v_base, dvec4 const vl_in[], size const n);

// ijkVecOrthoNormList4*
//	Vector orthonormalization using the Gram-Schmidt process.
//		param vl_out: output list of orthonormalized vectors
//		param v_base: fixed base vector onto which inputs are projected
//		param vl_in: input list of vectors to be orthonormalized
//		param n: number of vectors to orthonormalized
//		param v_base_norm_out: normalized base vector
//		return: vl_out
dvec4* ijkVecOrthoNormList4d(dvec4 vl_out[], dvec4 const v_base, dvec4 const vl_in[], size const n, dvec4* const v_base_norm_out);

// ijkVecNlerp4*
//	Calculate normalized linear interpolation between two 4D vectors; keeps
//	result at unit-length but yields a non-uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec4 ijkVecNlerp4d(dvec4 const v0, dvec4 const v1, double const u);

// ijkVecSlerp4*
//	Calculate spherical linear interpolation between two unit 4D vectors; keeps
//	result at unit-length and yields a uniform rate of change.
//		param v0: input initial control vector, result when param is 0
//		param v1: input terminal control vector, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [v0,v1], others result in extrapolation
//		return: interpolated vector
dvec4 ijkVecSlerp4d(dvec4 const v0, dvec4 const v1, double const u);

// ijkVecReflectScale4*
//	Reflect incident vector about normal, scaling to match normal size.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec4 ijkVecReflectScale4d(dvec4 const v_in, dvec4 const v_nrm);

// ijkVecUnitReflect4*
//	Reflect incident vector about normal; optimized for unit normal vector.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec4 ijkVecUnitReflect4d(dvec4 const v_in, dvec4 const v_nrm);

// ijkVecReflect4*
//	Reflect incident vector about normal.
//		param v_in: input vector, incident vector
//		param v_nrm: normal vector
//		return: reflected vector
dvec4 ijkVecReflect4d(dvec4 const v_in, dvec4 const v_nrm);

// ijkVecDistance4*
//	Calculate "distance" between two 4D vectors.
//		param v_lh: left-hand input
//		param v_rh: right-hand input
//		return: distance between inputs
double ijkVecDistance4d(dvec4 const v_lh, dvec4 const v_rh);

// ijkVecResize4*
//	Change length of vector, retaining direction.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec4 ijkVecResize4d(dvec4 const v_in, double const length);

// ijkVecResizeSafe4*
//	Change length of vector, retaining direction; division-by-zero safe.
//		param v_in: input vector
//		param length: new length of vector
//		return: resized vector
dvec4 ijkVecResizeSafe4d(dvec4 const v_in, double const length);

// ijkVecCrossResize4*
//	Change length of cross product result, retaining direction.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
dvec4 ijkVecCrossResize4d(dvec4 const v_lh, dvec4 const v_rh, double const length);

// ijkVecCrossResizeSafe4*
//	Change length of cross product result, retaining direction; 
//	division-by-zero safe.
//		param v_lh: left-hand vector
//		param v_lh: right-hand vector
//		param length: new length of vector
//		return: resized cross product
dvec4 ijkVecCrossResizeSafe4d(dvec4 const v_lh, dvec4 const v_rh, double const length);

// ijkVecNearest4*
//	Nearest-neighbor interpolation between two reference values.
//		param v0: initial reference value/start point, result when t<0.5
//		param v1: terminal reference value/end point, result when t>=0.5
//		param u: interpolation parameter
//		return: nearest-neighbor interpolated vector, exactly v0 or v1
dvec4 ijkVecNearest4d(dvec4 const v0, dvec4 const v1, double const u);

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
dvec4 ijkVecBinearest4d(dvec4 const v00, dvec4 const v01, dvec4 const v10, dvec4 const v11, double const u0, double const u1, double const u);

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
dvec4 ijkVecRemap4d(dvec4 const v0_dst, dvec4 const v1_dst, dvec4 const v0_src, dvec4 const v1_src, dvec4 const v_src);

// ijkVecBezier0O4*
//	Perform order-0 (point) Bezier interpolation given one reference value.
//		param v0: reference value, always returned
//		param u: interpolation parameter; not used for order 0 interpolation
//		return: v0
dvec4 ijkVecBezier0O4d(dvec4 const v0, double const u);

// ijkVecBezier1O4*
//	Perform order-1 (linear) Bezier interpolation given two reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v1
//		return: linear interpolation between v0 and v1
dvec4 ijkVecBezier1O4d(dvec4 const v0, dvec4 const v1, double const u);

// ijkVecBezier2O4*
//	Perform order-2 (quadratic) Bezier interpolation given three reference 
//	values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v2
//		return: quadratic Bezier interpolation between v0 and v2
dvec4 ijkVecBezier2O4d(dvec4 const v0, dvec4 const v1, dvec4 const v2, double const u);

// ijkVecBezier3O4*
//	Perform order-3 (cubic) Bezier interpolation given four reference values.
//		param v0: first reference value, result when t=0
//		param v1: second reference value
//		param v2: third reference value
//		param v3: fourth reference value, result when t=1
//		param u: interpolation parameter; inputs in [0,1] interpolate between 
//			v0 and v3
//		return: cubic Bezier interpolation between v0 and v3
dvec4 ijkVecBezier3O4d(dvec4 const v0, dvec4 const v1, dvec4 const v2, dvec4 const v3, double const u);

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
dvec4 ijkVecBezierNO4d(dvec4 const v[], size const order, double const u);

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
dvec4 ijkVecCubicHermite4d(dvec4 const v0, dvec4 const dv0, dvec4 const v1, dvec4 const dv1, double const u);

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
dvec4 ijkVecCubicHermiteHandles4d(dvec4 const v0, dvec4 const cv0, dvec4 const v1, dvec4 const cv1, double const u);

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
dvec4 ijkVecCubicCatmullRom4d(dvec4 const vp, dvec4 const v0, dvec4 const v1, dvec4 const v2, double const u);

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
dvec4 ijkVecBicubicCatmullRom4d(dvec4 const vpp, dvec4 const vp0, dvec4 const vp1, dvec4 const vp2, dvec4 const v0p, dvec4 const v00, dvec4 const v01, dvec4 const v02, dvec4 const v1p, dvec4 const v10, dvec4 const v11, dvec4 const v12, dvec4 const v2p, dvec4 const v20, dvec4 const v21, dvec4 const v22, double const up, double const u0, double const u1, double const u2, double const u);

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
double ijkVecReparamCubicHermite4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const v0, dvec4 const dv0, dvec4 const v1, dvec4 const dv1);

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
double ijkVecReparamCubicHermiteHandles4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const v0, dvec4 const cv0, dvec4 const v1, dvec4 const cv1);

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
double ijkVecReparamCubicCatmullRom4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const vp, dvec4 const v0, dvec4 const v1, dvec4 const v2);

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
double ijkVecReparamBicubicCatmullRom4d(double uTable_out[], double lTable_out[], dvec4 vTable_out[], size const numDivisions, ibool const lNormalize, dvec4 const vpp, dvec4 const vp0, dvec4 const vp1, dvec4 const vp2, dvec4 const v0p, dvec4 const v00, dvec4 const v01, dvec4 const v02, dvec4 const v1p, dvec4 const v10, dvec4 const v11, dvec4 const v12, dvec4 const v2p, dvec4 const v20, dvec4 const v21, dvec4 const v22, double const up, double const u0, double const u1, double const u2);

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
dvec4 ijkVecSampleTableInc4d(double const uTable[], dvec4 const vTable[], index i, index di, double const u);

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
dvec4 ijkVecSampleTableDec4d(double const uTable[], dvec4 const vTable[], index i, index di, double const u);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecPack1*b
//	Compress decimal scalar into a single byte (8 bits).
//		param v_in: symmetric-unit scalar to compress, in [-1,+1]
//		return: byte encoding scalar
i8 ijkVecPack1db(f64 const v_in);

// ijkVecUnpack1*b
//	Decompress decimal scalar from a single byte (8 bits).
//		param i_in: integer encoding scalar to decompress
//		return: decoded scalar
f64 ijkVecUnpack1db(i8 const i_in);

// ijkVecPack1*s
//	Compress decimal scalar into a short integer (16 bits).
//		param v_in: symmetric-unit scalar to compress, in [-1,+1]
//		return: short integer encoding scalar
i16 ijkVecPack1ds(f64 const v_in);

// ijkVecUnpack1*s
//	Decompress decimal scalar from a short integer (16 bits).
//		param i_in: integer encoding scalar to decompress
//		return: decoded scalar
f64 ijkVecUnpack1ds(i16 const i_in);

// ijkVecPack2*vs
//	Compress 2D vector into a short integer (16 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i16 ijkVecPack2dvs(double2 const v_in);

// ijkVecUnpack2*vs
//	Decompress 2D vector from a short integer (16 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpack2dvs(double2 v_out, i16 const i_in);

// ijkVecPack2*vl
//	Compress 2D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack2dvl(double2 const v_in);

// ijkVecUnpack2*vl
//	Decompress 2D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpack2dvl(double2 v_out, i32 const i_in);

// ijkVecPack3*vl
//	Compress 3D vector into a long integer (32 bits); components are encoded 
//	into 10 bits each.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack3dvl(double3 const v_in);

// ijkVecUnpack3*vl
//	Decompress 3D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpack3dvl(double3 v_out, i32 const i_in);

// ijkVecPack4*vl
//	Compress 4D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack4dvl(double4 const v_in);

// ijkVecUnpack4*vl
//	Decompress 4D vector from a long integer (32 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpack4dvl(double4 v_out, i32 const i_in);

// ijkVecPack4*vll
//	Compress 4D vector into a long-long integer (64 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPack4dvll(double4 const v_in);

// ijkVecUnpack4*vll
//	Decompress 4D vector from a long-long integer (64 bits).
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpack4dvll(double4 v_out, i64 const i_in);

// ijkVecPackUnitXYZ4*vl
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while one of the remaining bits 
//	specifies the sign of the fourth element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPackUnitXYZ4dvl(double4 const v_in);

// ijkVecUnpackUnitXYZ4*vl
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the sign of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpackUnitXYZ4dvl(double4 v_out, i32 const i_in);

// ijkVecPackUnit3of4*vl
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while the remaining bits specify 
//	the index of the excluded element. If the excluded component is negative, 
//	the whole vector will be negated.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
i32 ijkVecPackUnit3of4dvl(double4 const v_in, ui32 const excl);

// ijkVecUnpackUnit3of4*vl
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the index of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: v_out
doublev ijkVecUnpackUnit3of4dvl(double4 v_out, i32 const i_in, ui32* const excl_out);

// ijkVecPackQuant4*l
//	Compress three components of 4D quantized unit vector into a long integer 
//	(32 bits); components are encoded into 10 bits each, with the index of the 
//	maximum component stored in the remaining bits. Since the maximum value of 
//	the stored three components will be between [-sqrt(0.5),+sqrt(0.5)], they
//	can be quantized for better precision when decoded. If the excluded (max) 
//	component is negative, the entire vector is negated to make it positive.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPackQuant4dvl(double4 const v_in);

// ijkVecUnpackQuant4*l
//	Decompress 4D quantized unit vector from a long integer (32 bits) 
//	encoding only three components and the index of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpackQuant4dvl(double4 v_out, i32 const i_in);

// ijkVecPackUnitXYZ4*vll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 21 bits each, while the remaining 
//	bit specifies the sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPackUnitXYZ4dvll(double4 const v_in);

// ijkVecUnpackUnitXYZ4*vll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the sign of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpackUnitXYZ4dvll(double4 v_out, i64 const i_in);

// ijkVecPackUnit3of4*vll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 20 bits each, while the remaining 
//	bits specify the index and sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
i64 ijkVecPackUnit3of4dvll(double4 const v_in, ui64 const excl);

// ijkVecUnpackUnit3of4*vll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the index of the fourth.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: v_out
doublev ijkVecUnpackUnit3of4dvll(double4 v_out, i64 const i_in, ui64* const excl_out);

// ijkVecPackQuant4*vll
//	Compress three components of 4D quantized unit vector into the 48 MOST 
//	significant bits of a long-long integer (64 bits); components are encoded 
//	into 15 bits each, with the sign and index of the maximum component 
//	stored in the remaining bits. Since the maximum value of the stored three 
//	components will be between [-sqrt(0.5),+sqrt(0.5)], they can be quantized 
//	for better precision when decoded.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPackQuant4dvll(double4 const v_in);

// ijkVecUnpackQuant4*vll
//	Decompress 4D quantized unit vector from a long-long integer (64 bits) 
//	encoding only three components, and the sign and index of the fourth; the 
//	decoded elements are stored in the 48 MOST significant bits.
//		param v_out: output vector, decoded vector
//		param i_in: integer encoding vector to decompress
//		return: v_out
doublev ijkVecUnpackQuant4dvll(double4 v_out, i64 const i_in);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecPack2*s
//	Compress 2D vector into a short integer (16 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i16 ijkVecPack2ds(dvec2 const v_in);

// ijkVecUnpack2*s
//	Decompress 2D vector from a short integer (16 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec2 ijkVecUnpack2ds(i16 const i_in);

// ijkVecPack2*l
//	Compress 2D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack2dl(dvec2 const v_in);

// ijkVecUnpack2*l
//	Decompress 2D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec2 ijkVecUnpack2dl(i32 const i_in);

// ijkVecPack3*l
//	Compress 3D vector into a long integer (32 bits); components are encoded 
//	into 10 bits each.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack3dl(dvec3 const v_in);

// ijkVecUnpack3*l
//	Decompress 3D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec3 ijkVecUnpack3dl(i32 const i_in);

// ijkVecPack4*l
//	Compress 4D vector into a long integer (32 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPack4dl(dvec4 const v_in);

// ijkVecUnpack4*l
//	Decompress 4D vector from a long integer (32 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpack4dl(i32 const i_in);

// ijkVecPack4*ll
//	Compress 4D vector into a long-long integer (64 bits).
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPack4dll(dvec4 const v_in);

// ijkVecUnpack4*ll
//	Decompress 4D vector from a long-long integer (64 bits).
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpack4dll(i64 const i_in);

// ijkVecPackUnitXYZ4*l
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while one of the remaining bits 
//	specifies the sign of the fourth element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPackUnitXYZ4dl(dvec4 const v_in);

// ijkVecUnpackUnitXYZ4*l
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the sign of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpackUnitXYZ4dl(i32 const i_in);

// ijkVecPackUnit3of4*l
//	Compress three components of 4D unit vector into a long integer (32 bits); 
//	components are encoded into 10 bits each, while the remaining bits specify 
//	the index of the excluded element. If the excluded component is negative, 
//	the whole vector will be negated.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
i32 ijkVecPackUnit3of4dl(dvec4 const v_in, ui32 const excl);

// ijkVecUnpackUnit3of4*l
//	Decompress 4D unit vector from a long integer (32 bits) encoding only 
//	three components and the index of the fourth.
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: decoded vector
dvec4 ijkVecUnpackUnit3of4dl(i32 const i_in, ui32* const excl_out);

// ijkVecPackQuant4*l
//	Compress three components of 4D quantized unit vector into a long integer 
//	(32 bits); components are encoded into 10 bits each, with the index of the 
//	maximum component stored in the remaining bits. Since the maximum value of 
//	the stored three components will be between [-sqrt(0.5),+sqrt(0.5)], they
//	can be quantized for better precision when decoded. If the excluded (max) 
//	component is negative, the entire vector is negated to make it positive.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i32 ijkVecPackQuant4dl(dvec4 const v_in);

// ijkVecUnpackQuant4*l
//	Decompress 4D quantized unit vector from a long integer (32 bits) 
//	encoding only three components and the index of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpackQuant4dl(i32 const i_in);

// ijkVecPackUnitXYZ4*ll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 21 bits each, while the remaining 
//	bit specifies the sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPackUnitXYZ4dll(dvec4 const v_in);

// ijkVecUnpackUnitXYZ4*ll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the sign of the fourth.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpackUnitXYZ4dll(i64 const i_in);

// ijkVecPackUnit3of4*ll
//	Compress three components of 4D unit vector into a long-long integer 
//	(64 bits); components are encoded into 20 bits each, while the remaining 
//	bits specify the index and sign of the excluded element.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		param excl: index of excluded element, in [0,3]
//		return: short integer encoding vector
i64 ijkVecPackUnit3of4dll(dvec4 const v_in, ui64 const excl);

// ijkVecUnpackUnit3of4*ll
//	Decompress 4D unit vector from a long-long integer (64 bits) encoding 
//	only three components and the index of the fourth.
//		param i_in: integer encoding vector to decompress
//		param excl_out: pointer to storage for index of excluded element
//		return: decoded vector
dvec4 ijkVecUnpackUnit3of4dll(i64 const i_in, ui64* const excl_out);

// ijkVecPackQuant4*ll
//	Compress three components of 4D quantized unit vector into the 48 MOST 
//	significant bits of a long-long integer (64 bits); components are encoded 
//	into 15 bits each, with the sign and index of the maximum component 
//	stored in the remaining bits. Since the maximum value of the stored three 
//	components will be between [-sqrt(0.5),+sqrt(0.5)], they can be quantized 
//	for better precision when decoded.
//		param v_in: symmetric-unit vector to compress, elements in [-1,+1]
//		return: short integer encoding vector
i64 ijkVecPackQuant4dll(dvec4 const v_in);

// ijkVecUnpackQuant4*ll
//	Decompress 4D quantized unit vector from a long-long integer (64 bits) 
//	encoding only three components, and the sign and index of the fourth; the 
//	decoded elements are stored in the 48 MOST significant bits.
//		param i_in: integer encoding vector to decompress
//		return: decoded vector
dvec4 ijkVecUnpackQuant4dll(i64 const i_in);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_double.inl"


#endif	// !_IJK_VECTOR_DOUBLE_H_
#endif	// _IJK_VECTOR_H_