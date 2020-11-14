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
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float2m ijkMatCopy2fm3(float2x2 m_out, float3x3 const m_in);

// ijkMatCopy2*m4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_out: output matrix
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

// 2D struct-based


//-----------------------------------------------------------------------------

// 3D struct-based


//-----------------------------------------------------------------------------

// 4D struct-based


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
	
// ijkMatMul2*mv
//	Multiply 2D vector by 2x2 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
floatv ijkMatMul2fmv(float2 v_out, float2x2 const m_lh, float2 const v_rh);

// ijkMatMul2*m
//	Multiply 2x2 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatMul2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);


//-----------------------------------------------------------------------------

// 3D array-based special


//-----------------------------------------------------------------------------

// 4D array-based special


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// 2D struct-based special


//-----------------------------------------------------------------------------

// 3D struct-based special


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#include "_inl/ijkMatrix_float.inl"


#endif	// !_IJK_MATRIX_FLOAT_H_
#endif	// _IJK_MATRIX_H_