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

	ijkMatrix_float.h
	Declarations for float matrix functions.
*/

#ifdef _IJK_MATRIX_H_
#ifndef _IJK_MATRIX_FLOAT_H_
#define _IJK_MATRIX_FLOAT_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
	
// ijkMatInit2*m
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
float2m ijkMatInit2fm(float2x2 m_out);

// ijkMatInitElems2*m
//	Initialize 2x2 matrix given elements.
//		param m_out: output matrix
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: m_out
float2m ijkMatInitElems2fm(float2x2 m_out, f32 const x0, f32 const y0, f32 const x1, f32 const y1);

// ijkMatInitVecs2*m
//	Initialize 2x2 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		return: m_out
float2m ijkMatInitVecs2fm(float2x2 m_out, float2 const c0, float2 const c1);

// ijkMatCopy2*m2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float2m ijkMatCopy2fm2(float2x2 m_out, float2x2 const m_in);

// ijkMatCopy2*m3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
float2m ijkMatCopy2fm3(float2x2 m_out, float3x3 const m_in);

// ijkMatCopy2*m4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
float2m ijkMatCopy2fm4(float2x2 m_out, float4x4 const m_in);

// ijkMatCopy2*ms
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
float2m ijkMatCopy2fms(float2x2 m_out, f32 const s_diag);

// ijkMatMul2*ms
//	Multiply 2x2 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float2m ijkMatMul2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh);

// ijkMatDiv2*ms
//	Divide 2x2 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float2m ijkMatDiv2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh);

// ijkMatDivSafe2*ms
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float2m ijkMatDivSafe2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh);

// ijkMatMul2*sm
//	Multiply scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatMul2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh);

// ijkMatDiv2*sm
//	Divide scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatDiv2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh);

// ijkMatDivSafe2*sm
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatDivSafe2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh);

// ijkMatAdd2*m
//	Add 2x2 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatAdd2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);

// ijkMatSub2*m
//	Subtract 2x2 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatSub2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);


//-----------------------------------------------------------------------------

// 3D array-based


//-----------------------------------------------------------------------------

// 4D array-based


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------
	
// ijkMatInit2*
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
fmat2 ijkMatInit2f();

// ijkMatInitElems2*
//	Initialize 2x2 matrix given elements.
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: matrix of elements
fmat2 ijkMatInitElems2f(float const x0, float const y0, float const x1, float const y1);

// ijkMatInitVecs2*
//	Initialize 2x2 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		return: matrix of columns
fmat2 ijkMatInitVecs2f(fvec2 const c0, fvec2 const c1);

// ijkMatCopy2*2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_in: input matrix
//		return: copy of input
fmat2 ijkMatCopy2f2(fmat2 const m_in);

// ijkMatCopy2*3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
fmat2 ijkMatCopy2f3(fmat3 const m_in);

// ijkMatCopy2*4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
fmat2 ijkMatCopy2f4(fmat4 const m_in);

// ijkMatCopy2*s
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
fmat2 ijkMatCopy2fs(float const s_diag);

// ijkMatMul2*s
//	Multiply 2x2 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
fmat2 ijkMatMul2fs(fmat2 const m_lh, float const s_rh);

// ijkMatDiv2*s
//	Divide 2x2 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat2 ijkMatDiv2fs(fmat2 const m_lh, float const s_rh);

// ijkMatDivSafe2*s
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat2 ijkMatDivSafe2fs(fmat2 const m_lh, float const s_rh);

// ijkMatMul2*s
//	Multiply scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
fmat2 ijkMatMul2sf(float const s_lh, fmat2 const m_rh);

// ijkMatDiv2*s
//	Divide scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat2 ijkMatDiv2sf(float const s_lh, fmat2 const m_rh);

// ijkMatDivSafe2*s
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat2 ijkMatDivSafe2sf(float const s_lh, fmat2 const m_rh);

// ijkMatAdd2*
//	Add 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
fmat2 ijkMatAdd2f(fmat2 const m_lh, fmat2 const m_rh);

// ijkMatSub2*
//	Subtract 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
fmat2 ijkMatSub2f(fmat2 const m_lh, fmat2 const m_rh);


//-----------------------------------------------------------------------------

// 3D struct-based


//-----------------------------------------------------------------------------

// 4D struct-based


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*m
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
f32 ijkMatDeterminant2fm(float2x2 const m_in);

// ijkMatDeterminantInv2*m
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
f32 ijkMatDeterminantInv2fm(float2x2 const m_in);

// ijkMatDeterminantInvSafe2*m
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant
f32 ijkMatDeterminantInvSafe2fm(float2x2 const m_in);

// ijkMatMulRowVec2*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and v
f32 ijkMatMulRowVec2fm(float2x2 const m_in, float2 const v_in, index const row);

// ijkMatGetRow2*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
floatv ijkMatGetRow2fm(float2 v_out, float2x2 const m_in, index const row);

// ijkMatTranspose2*m
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
float2m ijkMatTranspose2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatInverse2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverse2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatInverseSafe2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverseSafe2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatMulVec2*mv
//	Multiply 2D vector by 2x2 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
floatv ijkMatMulVec2fmv(float2 v_out, float2x2 const m_lh, float2 const v_rh);

// ijkMatMul2*m
//	Multiply 2x2 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatMul2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);

// ijkMatDiv2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatDiv2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);

// ijkMatDivSafe2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatDivSafe2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);

// ijkMatRotate2*m
//	Make 2D rotation matrix.
//		param m_out: output matrix, rotation
//		param angle_degrees: input angle in degrees
//		return: m_out
float2m ijkMatRotate2fm(float2x2 m_out, f32 const angle_degrees);

// ijkMatScale2*m
//	Make 2D scale matrix.
//		param m_out: output matrix, scale
//		params sx, sy: scales on each dimension
//		return: m_out
float2m ijkMatScale2fm(float2x2 m_out, f32 const sx, f32 const sy);

// ijkMatRotateScale2*m
//	Make 2D rotation-scale matrix.
//		param m_out: output matrix, rotation
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: m_out
float2m ijkMatRotateScale2fm(float2x2 m_out, f32 const angle_degrees, f32 const sx, f32 const sy);

// ijkMatGetRotate2*m
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
float2km ijkMatGetRotate2fm(float2x2 const m_in, f32* const angle_degrees_out);

// ijkMatGetScale2*m
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
float2km ijkMatGetScale2fm(float2x2 const m_in, f32* const sx_out, f32* const sy_out);

// ijkMatGetRotateScale2*m
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
float2km ijkMatGetRotateScale2fm(float2x2 const m_in, f32* const angle_degrees_out, f32* const sx_out, f32* const sy_out);


//-----------------------------------------------------------------------------

// 3D array-based special


//-----------------------------------------------------------------------------

// 4D array-based special


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
float ijkMatDeterminant2f(fmat2 const m_in);

// ijkMatDeterminantInv2*
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
float ijkMatDeterminantInv2f(fmat2 const m_in);

// ijkMatDeterminantInvSafe2*
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant
float ijkMatDeterminantInvSafe2f(fmat2 const m_in);

// ijkMatMulRowVec2*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and v
float ijkMatMulRowVec2f(fmat2 const m_in, fvec2 const v_in, index const row);

// ijkMatGetRow2*
//	Get row as vector.
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
fvec2 ijkMatGetRow2f(fmat2 const m_in, index const row);

// ijkMatTranspose2*
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
fmat2 ijkMatTranspose2f(fmat2 const m_in);

// ijkMatInverse2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
fmat2 ijkMatInverse2f(fmat2 const m_in);

// ijkMatInverseSafe2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
fmat2 ijkMatInverseSafe2f(fmat2 const m_in);

// ijkMatMulVec2*
//	Multiply 2D vector by 2x2 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
fvec2 ijkMatMulVec2f(fmat2 const m_lh, fvec2 const v_rh);

// ijkMatMul2*
//	Multiply 2x2 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
fmat2 ijkMatMul2f(fmat2 const m_lh, fmat2 const m_rh);

// ijkMatDiv2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat2 ijkMatDiv2f(fmat2 const m_lh, fmat2 const m_rh);

// ijkMatDivSafe2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat2 ijkMatDivSafe2f(fmat2 const m_lh, fmat2 const m_rh);

// ijkMatRotate2*
//	Make 2D rotation matrix.
//		param angle_degrees: input angle in degrees
//		return: rotation matrix
fmat2 ijkMatRotate2f(float const angle_degrees);

// ijkMatScale2*
//	Make 2D scale matrix.
//		params sx, sy: scales on each dimension
//		return: scale matrix
fmat2 ijkMatScale2f(float const sx, float const sy);

// ijkMatRotateScale2*
//	Make 2D rotation-scale matrix.
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: rotation-scale matrix
fmat2 ijkMatRotateScale2f(float const angle_degrees, float const sx, float const sy);

// ijkMatGetRotate2*
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
fmat2 ijkMatGetRotate2f(fmat2 const m_in, float* const angle_degrees_out);

// ijkMatGetScale2*
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
fmat2 ijkMatGetScale2f(fmat2 const m_in, float* const sx_out, float* const sy_out);

// ijkMatGetRotateScale2*
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
fmat2 ijkMatGetRotateScale2f(fmat2 const m_in, float* const angle_degrees_out, float* const sx_out, float* const sy_out);


//-----------------------------------------------------------------------------

// 3D struct-based special


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#include "_inl/ijkMatrix_float.inl"


#endif	// !_IJK_MATRIX_FLOAT_H_
#endif	// _IJK_MATRIX_H_