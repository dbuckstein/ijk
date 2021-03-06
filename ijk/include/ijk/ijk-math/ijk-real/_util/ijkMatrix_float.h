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

// ijkMat2P*m
//	Pass-thru array-based 2D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
float2m ijkMat2Pfm(float2x2 m_out);

// ijkMat3P*m
//	Pass-thru array-based 3D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
float3m ijkMat3Pfm(float3x3 m_out);

// ijkMat4P*m
//	Pass-thru array-based 4D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
float4m ijkMat4Pfm(float4x4 m_out);


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

// ijkMatNegate2*m
//	Negate 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float2m ijkMatNegate2fm(float2x2 m_out, float2x2 const m_in);

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
	
// ijkMatInit3*m
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
float3m ijkMatInit3fm(float3x3 m_out);

// ijkMatInitElems3*m
//	Initialize 3x3 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: m_out
float3m ijkMatInitElems3fm(float3x3 m_out, f32 const x0, f32 const y0, f32 const z0, f32 const x1, f32 const y1, f32 const z1, f32 const x2, f32 const y2, f32 const z2);

// ijkMatInitVecs3*m
//	Initialize 3x3 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: m_out
float3m ijkMatInitVecs3fm(float3x3 m_out, float3 const c0, float3 const c1, float3 const c2);

// ijkMatCopy3*m2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float3m ijkMatCopy3fm2(float3x3 m_out, float2x2 const m_in);

// ijkMatCopy3*m3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float3m ijkMatCopy3fm3(float3x3 m_out, float3x3 const m_in);

// ijkMatCopy3*m4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 3x3 matrix
//		param m_in: input matrix
//		return: m_out
float3m ijkMatCopy3fm4(float3x3 m_out, float4x4 const m_in);

// ijkMatNegate3*m
//	Negate 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float3m ijkMatNegate3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatCopy3*ms
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
float3m ijkMatCopy3fms(float3x3 m_out, f32 const s_diag);

// ijkMatMul3*ms
//	Multiply 3x3 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float3m ijkMatMul3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh);

// ijkMatDiv3*ms
//	Divide 3x3 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float3m ijkMatDiv3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh);

// ijkMatDivSafe3*ms
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float3m ijkMatDivSafe3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh);

// ijkMatMul3*sm
//	Multiply scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatMul3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh);

// ijkMatDiv3*sm
//	Divide scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatDiv3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh);

// ijkMatDivSafe3*sm
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatDivSafe3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh);

// ijkMatAdd3*m
//	Add 3x3 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatAdd3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh);

// ijkMatSub3*m
//	Subtract 3x3 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatSub3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh);


//-----------------------------------------------------------------------------
	
// ijkMatInit4*m
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
float4m ijkMatInit4fm(float4x4 m_out);

// ijkMatInitElems4*m
//	Initialize 4x4 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: m_out
float4m ijkMatInitElems4fm(float4x4 m_out, f32 const x0, f32 const y0, f32 const z0, f32 const w0, f32 const x1, f32 const y1, f32 const z1, f32 const w1, f32 const x2, f32 const y2, f32 const z2, f32 const w2, f32 const x3, f32 const y3, f32 const z3, f32 const w3);

// ijkMatInitVecs4*m
//	Initialize 4x4 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: m_out
float4m ijkMatInitVecs4fm(float4x4 m_out, float4 const c0, float4 const c1, float4 const c2, float4 const c3);

// ijkMatCopy4*m2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float4m ijkMatCopy4fm2(float4x4 m_out, float2x2 const m_in);

// ijkMatCopy4*m3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float4m ijkMatCopy4fm3(float4x4 m_out, float3x3 const m_in);

// ijkMatCopy4*m4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float4m ijkMatCopy4fm4(float4x4 m_out, float4x4 const m_in);

// ijkMatNegate4*m
//	Negate 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
float4m ijkMatNegate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatCopy4*ms
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
float4m ijkMatCopy4fms(float4x4 m_out, f32 const s_diag);

// ijkMatMul4*ms
//	Multiply 4x4 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float4m ijkMatMul4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh);

// ijkMatDiv4*ms
//	Divide 4x4 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float4m ijkMatDiv4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh);

// ijkMatDivSafe4*ms
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
float4m ijkMatDivSafe4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh);

// ijkMatMul4*sm
//	Multiply scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatMul4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh);

// ijkMatDiv4*sm
//	Divide scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatDiv4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh);

// ijkMatDivSafe4*sm
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatDivSafe4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh);

// ijkMatAdd4*m
//	Add 4x4 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatAdd4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);

// ijkMatSub4*m
//	Subtract 4x4 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatSub4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);


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

// ijkMatNegate2*
//	Negate 2x2 matrix.
//		param m_in: input matrix
//		return: negated matrix
fmat2 ijkMatNegate2f(fmat2 const m_in);

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

// ijkMatMul2s*
//	Multiply scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
fmat2 ijkMatMul2sf(float const s_lh, fmat2 const m_rh);

// ijkMatDiv2s*
//	Divide scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat2 ijkMatDiv2sf(float const s_lh, fmat2 const m_rh);

// ijkMatDivSafe2s*
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

// ijkMatInit3*
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
fmat3 ijkMatInit3f();

// ijkMatInitElems3*
//	Initialize 3x3 matrix given elements.
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: matrix of elements
fmat3 ijkMatInitElems3f(float const x0, float const y0, float const z0, float const x1, float const y1, float const z1, float const x2, float const y2, float const z2);

// ijkMatInitVecs3*
//	Initialize 3x3 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: matrix of columns
fmat3 ijkMatInitVecs3f(fvec3 const c0, fvec3 const c1, fvec3 const c2);

// ijkMatCopy3*2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
fmat3 ijkMatCopy3f2(fmat2 const m_in);

// ijkMatCopy3*3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input
fmat3 ijkMatCopy3f3(fmat3 const m_in);

// ijkMatCopy3*4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 3x3 matrix
fmat3 ijkMatCopy3f4(fmat4 const m_in);

// ijkMatNegate3*
//	Negate 3x3 matrix.
//		param m_in: input matrix
//		return: negated matrix
fmat3 ijkMatNegate3f(fmat3 const m_in);

// ijkMatCopy3*s
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
fmat3 ijkMatCopy3fs(float const s_diag);

// ijkMatMul3*s
//	Multiply 3x3 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
fmat3 ijkMatMul3fs(fmat3 const m_lh, float const s_rh);

// ijkMatDiv3*s
//	Divide 3x3 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat3 ijkMatDiv3fs(fmat3 const m_lh, float const s_rh);

// ijkMatDivSafe3*s
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat3 ijkMatDivSafe3fs(fmat3 const m_lh, float const s_rh);

// ijkMatMul3s*
//	Multiply scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
fmat3 ijkMatMul3sf(float const s_lh, fmat3 const m_rh);

// ijkMatDiv3s*
//	Divide scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat3 ijkMatDiv3sf(float const s_lh, fmat3 const m_rh);

// ijkMatDivSafe3s*
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat3 ijkMatDivSafe3sf(float const s_lh, fmat3 const m_rh);

// ijkMatAdd3*
//	Add 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
fmat3 ijkMatAdd3f(fmat3 const m_lh, fmat3 const m_rh);

// ijkMatSub3*
//	Subtract 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
fmat3 ijkMatSub3f(fmat3 const m_lh, fmat3 const m_rh);


//-----------------------------------------------------------------------------

// ijkMatInit4*
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
fmat4 ijkMatInit4f();

// ijkMatInitElems4*
//	Initialize 4x4 matrix given elements.
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: matrix of elements
fmat4 ijkMatInitElems4f(float const x0, float const y0, float const z0, float const w0, float const x1, float const y1, float const z1, float const w1, float const x2, float const y2, float const z2, float const w2, float const x3, float const y3, float const z3, float const w3);

// ijkMatInitVecs4*
//	Initialize 4x4 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: matrix of columns
fmat4 ijkMatInitVecs4f(fvec4 const c0, fvec4 const c1, fvec4 const c2, fvec4 const c3);

// ijkMatCopy4*2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
fmat4 ijkMatCopy4f2(fmat2 const m_in);

// ijkMatCopy4*3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
fmat4 ijkMatCopy4f3(fmat3 const m_in);

// ijkMatCopy4*4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input
fmat4 ijkMatCopy4f4(fmat4 const m_in);

// ijkMatNegate4*
//	Negate 4x4 matrix.
//		param m_in: input matrix
//		return: negated matrix
fmat4 ijkMatNegate4f(fmat4 const m_in);

// ijkMatCopy4*s
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
fmat4 ijkMatCopy4fs(float const s_diag);

// ijkMatMul4*s
//	Multiply 4x4 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
fmat4 ijkMatMul4fs(fmat4 const m_lh, float const s_rh);

// ijkMatDiv4*s
//	Divide 4x4 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat4 ijkMatDiv4fs(fmat4 const m_lh, float const s_rh);

// ijkMatDivSafe4*s
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
fmat4 ijkMatDivSafe4fs(fmat4 const m_lh, float const s_rh);

// ijkMatMul4s*
//	Multiply scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
fmat4 ijkMatMul4sf(float const s_lh, fmat4 const m_rh);

// ijkMatDiv4s*
//	Divide scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat4 ijkMatDiv4sf(float const s_lh, fmat4 const m_rh);

// ijkMatDivSafe4s*
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
fmat4 ijkMatDivSafe4sf(float const s_lh, fmat4 const m_rh);

// ijkMatAdd4*
//	Add 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
fmat4 ijkMatAdd4f(fmat4 const m_lh, fmat4 const m_rh);

// ijkMatSub4*
//	Subtract 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
fmat4 ijkMatSub4f(fmat4 const m_lh, fmat4 const m_rh);


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
//		return: determinant inverse
f32 ijkMatDeterminantInv2fm(float2x2 const m_in);

// ijkMatDeterminantInvSafe2*m
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f32 ijkMatDeterminantInvSafe2fm(float2x2 const m_in);

// ijkMatMulRowVec2*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f32 ijkMatMulRowVec2fmv(float2x2 const m_in, float2 const v_in, index const row);

// ijkMatGetRow2*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
floatv ijkMatGetRow2fm(float2 v_out, float2x2 const m_in, index const row);

// ijkMatTranspose2*m
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
float2m ijkMatTranspose2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatTransposeMul2*ms
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
float2m ijkMatTransposeMul2fms(float2x2 m_out, float2x2 const m_in, f32 const s);

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
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float2m ijkMatDiv2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh);

// ijkMatDivSafe2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
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
//		param m_out: output matrix, rotation-scale
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

// ijkMatInverseRotate2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverseRotate2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatInverseScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverseScale2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatInverseRotateScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverseRotateScale2fm(float2x2 m_out, float2x2 const m_in);

// ijkMatInverseTranspose2*m
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
float2m ijkMatInverseTranspose2fm(float2x2 m_out, float2x2 const m_in);


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*m
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
f32 ijkMatDeterminant3fm(float3x3 const m_in);

// ijkMatDeterminantInv3*m
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
f32 ijkMatDeterminantInv3fm(float3x3 const m_in);

// ijkMatDeterminantInvSafe3*m
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f32 ijkMatDeterminantInvSafe3fm(float3x3 const m_in);

// ijkMatMulRowVec3*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f32 ijkMatMulRowVec3fmv(float3x3 const m_in, float3 const v_in, index const row);

// ijkMatGetRow3*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
floatv ijkMatGetRow3fm(float3 v_out, float3x3 const m_in, index const row);

// ijkMatTranspose3*m
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
float3m ijkMatTranspose3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatTransposeMul3*ms
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
float3m ijkMatTransposeMul3fms(float3x3 m_out, float3x3 const m_in, f32 const s);

// ijkMatInverse3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverse3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatInverseSafe3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverseSafe3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatMulVec3*mv
//	Multiply 3D vector by 3x3 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
floatv ijkMatMulVec3fmv(float3 v_out, float3x3 const m_lh, float3 const v_rh);

// ijkMatMul3*m
//	Multiply 3x3 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatMul3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh);

// ijkMatDiv3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatDiv3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh);

// ijkMatDivSafe3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float3m ijkMatDivSafe3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh);

// ijkMatRotateXYZ3*m
//	Make 3D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateXYZ3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatRotateYZX3*m
//	Make 3D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateYZX3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatRotateZXY3*m
//	Make 3D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateZXY3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatRotateYXZ3*m
//	Make 3D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateYXZ3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatRotateXZY3*m
//	Make 3D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateXZY3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatRotateZYX3*m
//	Make 3D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotateZYX3fm(float3x3 m_out, float3 const rotateDegXYZ);

// ijkMatGetRotateXYZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateXYZ3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateYZX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateYZX3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateZXY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateZXY3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateYXZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateYXZ3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateXZY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateXZY3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateZYX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotateZYX3fm(float3x3 const m_in, float3 rotateDegXYZ_out);

// ijkMatRotate3*m
//	Make 3D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float3m ijkMatRotate3fm(float3x3 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ);

// ijkMatScale3*m
//	Make 3D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
float3m ijkMatScale3fm(float3x3 m_out, float3 const scale);

// ijkMatRotateScale3*m
//	Make 3D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
float3m ijkMatRotateScale3fm(float3x3 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale);

// ijkMatGetRotate3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float3km ijkMatGetRotate3fm(float3x3 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out);

// ijkMatGetScale3*m
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
float3km ijkMatGetScale3fm(float3x3 const m_in, float3 scale_out);

// ijkMatGetRotateScale3*m
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
float3km ijkMatGetRotateScale3fm(float3x3 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out);

// ijkMatInverseRotate3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverseRotate3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatInverseScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverseScale3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatInverseRotateScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverseRotateScale3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatInverseTranspose3*m
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
float3m ijkMatInverseTranspose3fm(float3x3 m_out, float3x3 const m_in);

// ijkMatRotateAxisAngle3*m
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
float3m ijkMatRotateAxisAngle3fm(float3x3 m_out, float3 const axis_unit, f32 const angle_degrees);

// ijkMatRotateAxisAngleScale3*m
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
float3m ijkMatRotateAxisAngleScale3fm(float3x3 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale);

// ijkMatGetRotateAxisAngle3*m
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
float3km ijkMatGetRotateAxisAngle3fm(float3x3 const m_in, float3 axis_unit_out, f32* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale3*m
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
float3km ijkMatGetRotateAxisAngleScale3fm(float3x3 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out);

// ijkMatLookAt3*m
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
float3m ijkMatLookAt3fm(float3x3 m_out, float3x3 m_inv_out_opt, float3 const origin, float3 const target, float3 const calibUnit, ijkTransformBasis const calibAxis);


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*m
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
f32 ijkMatDeterminant4fm(float4x4 const m_in);

// ijkMatDeterminantInv4*m
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
f32 ijkMatDeterminantInv4fm(float4x4 const m_in);

// ijkMatDeterminantInvSafe4*m
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f32 ijkMatDeterminantInvSafe4fm(float4x4 const m_in);

// ijkMatMulRowVec4*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f32 ijkMatMulRowVec4fmv(float4x4 const m_in, float4 const v_in, index const row);

// ijkMatGetRow4*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
floatv ijkMatGetRow4fm(float4 v_out, float4x4 const m_in, index const row);

// ijkMatTranspose4*m
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
float4m ijkMatTranspose4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatTransposeMul4*ms
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
float4m ijkMatTransposeMul4fms(float4x4 m_out, float4x4 const m_in, f32 const s);

// ijkMatInverse4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverse4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseSafe4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseSafe4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatMulVec4*mv
//	Multiply 4D vector by 4x4 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
floatv ijkMatMulVec4fmv(float4 v_out, float4x4 const m_lh, float4 const v_rh);

// ijkMatMul4*m
//	Multiply 4x4 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatMul4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);

// ijkMatDiv4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatDiv4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);

// ijkMatDivSafe4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
float4m ijkMatDivSafe4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);

// ijkMatRotateXYZ4*m
//	Make 4D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateXYZ4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatRotateYZX4*m
//	Make 4D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateYZX4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatRotateZXY4*m
//	Make 4D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateZXY4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatRotateYXZ4*m
//	Make 4D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateYXZ4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatRotateXZY4*m
//	Make 4D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateXZY4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatRotateZYX4*m
//	Make 4D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotateZYX4fm(float4x4 m_out, float3 const rotateDegXYZ);

// ijkMatGetRotateXYZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateXYZ4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateYZX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateYZX4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateZXY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateZXY4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateYXZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateYXZ4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateXZY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateXZY4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatGetRotateZYX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotateZYX4fm(float4x4 const m_in, float3 rotateDegXYZ_out);

// ijkMatRotate4*m
//	Make 4D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
float4m ijkMatRotate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ);

// ijkMatScale4*m
//	Make 4D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
float4m ijkMatScale4fm(float4x4 m_out, float3 const scale);

// ijkMatRotateScale4*m
//	Make 4D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
float4m ijkMatRotateScale4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale);

// ijkMatGetRotate4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
float4km ijkMatGetRotate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out);

// ijkMatGetScale4*m
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
float4km ijkMatGetScale4fm(float4x4 const m_in, float3 scale_out);

// ijkMatGetRotateScale4*m
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
float4km ijkMatGetRotateScale4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out);

// ijkMatInverseRotate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseRotate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseScale4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseRotateScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseRotateScale4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseTranspose4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseTranspose4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatRotateAxisAngle4*m
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
float4m ijkMatRotateAxisAngle4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees);

// ijkMatRotateAxisAngleScale4*m
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
float4m ijkMatRotateAxisAngleScale4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale);

// ijkMatGetRotateAxisAngle4*m
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
float4km ijkMatGetRotateAxisAngle4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale4*m
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
float4km ijkMatGetRotateAxisAngleScale4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out);

// ijkMatTranslate4*m
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, translation
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatTranslate4fm(float4x4 m_out, float3 const translate);

// ijkMatRotateTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatRotateTranslate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate);

// ijkMatScaleTranslate4*m
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, scale-translate
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatScaleTranslate4fm(float4x4 m_out, float3 const scale, float3 const translate);

// ijkMatRotateScaleTranslate4*m
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param m_out: output matrix, rotate-scale-translate
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatRotateScaleTranslate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale, float3 const translate);

// ijkMatRotateAxisAngleTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatRotateAxisAngleTranslate4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate);

// ijkMatRotateAxisAngleScaleTranslate4*m
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param m_out: output matrix, rotate-scale-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
float4m ijkMatRotateAxisAngleScaleTranslate4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale, float3 const translate);

// ijkMatGetTranslate4*m
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetTranslate4fm(float4x4 const m_in, float3 translate_out);

// ijkMatGetRotateTranslate4*m
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetRotateTranslate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out);

// ijkMatGetScaleTranslate4*m
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetScaleTranslate4fm(float4x4 const m_in, float3 scale_out, float3 translate_out);

// ijkMatGetRotateScaleTranslate4*m
//	Extract rotation angle in degrees, scales and translation offset vector 
//	from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetRotateScaleTranslate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out, float3 translate_out);

// ijkMatGetRotateAxisAngleTranslate4*m
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetRotateAxisAngleTranslate4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out);

// ijkMatGetRotateAxisAngleScaleTranslate4*m
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
float4km ijkMatGetRotateAxisAngleScaleTranslate4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out, float3 translate_out);

// ijkMatInverseRotateTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseRotateTranslate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseScaleTranslate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseRotateScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseRotateScaleTranslate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatInverseTransposeTranslate4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
float4m ijkMatInverseTransposeTranslate4fm(float4x4 m_out, float4x4 const m_in);

// ijkMatMulTransform4*m
//	Concatenate as if inputs are transformation matrices, saving a few 
//	operations over full 4x4 product.
//		param m_out: output matrix, transform product
//		param m_lh: left-hand input matrix
//		param m_rh: right-hand input matrix
//		return: m_out
float4m ijkMatMulTransform4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh);

// ijkMatMulVecTransform4*mv3
//	Multiply 3D vector by transformation matrix, saving a few operations.
//		param v_out: output vector, transformed input
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: v_out
floatv ijkMatMulVecTransform4fmv3(float3 v_out, float4x4 const m_lh, float3 const v_rh);

// ijkMatMulVecTransform4*mv4
//	Multiply 4D vector by transformation matrix, saving a few operations.
//		param v_out: output vector, transformed input
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: v_out
floatv ijkMatMulVecTransform4fmv4(float4 v_out, float4x4 const m_lh, float4 const v_rh);

// ijkMatLookAt4*m
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
float4m ijkMatLookAt4fm(float4x4 m_out, float4x4 m_inv_out_opt, float3 const origin, float3 const target, float3 const calibUnit, ijkTransformBasis const calibAxis);

// ijkMatProjectionPerspective4*m
//	Create perspective projection matrix.
//		param m_out: output matrix, perspective projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
float4m ijkMatProjectionPerspective4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const fovyDeg, f32 const aspect, f32 const nearDist, f32 const farDist);

// ijkMatProjectionParallel4*m
//	Create parallel/orthographic projection matrix.
//		param m_out: output matrix, parallel projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
float4m ijkMatProjectionParallel4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const fovyDeg, f32 const aspect, f32 const nearDist, f32 const farDist);

// ijkMatProjectionPerspectivePlanes4*m
//	Create perspective projection matrix given plane distances.
//		param m_out: output matrix, perspective projection
//		param m_inv_out_opt: optional inverse matrix output
//		param leftDist: distance to left plane (not equal to right)
//		param rightDist: distance to right plane (not equal to left)
//		param bottomDist: distance to bottom plane (not equal to top)
//		param topDist: distance to top plane (not equal to bottom)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
float4m ijkMatProjectionPerspectivePlanes4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const leftDist, f32 const rightDist, f32 const bottomDist, f32 const topDist, f32 const nearDist, f32 const farDist);

// ijkMatProjectionParallelPlanes4*m
//	Create parallel/orthographic projection matrix given plane distances.
//		param m_out: output matrix, parallel projection
//		param m_inv_out_opt: optional inverse matrix output
//		param leftDist: distance to left plane (not equal to right)
//		param rightDist: distance to right plane (not equal to left)
//		param bottomDist: distance to bottom plane (not equal to top)
//		param topDist: distance to top plane (not equal to bottom)
//		param nearDist: distance to near plane (not equal to far)
//		param farDist: distance to far plane (not equal to near)
//		return: m_out
float4m ijkMatProjectionParallelPlanes4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const leftDist, f32 const rightDist, f32 const bottomDist, f32 const topDist, f32 const nearDist, f32 const farDist);

// ijkMatProjectionStereoConversion4*m
//	Create stereo projection conversion matrix. Convert monoscopic matrix to 
//	stereoscopic by multiplying conversion matrix on the right (mono * stereo).
//	Convert mono inverse matrix to stereo inverse by multiplying conversion 
//	inverse matrix on the left (stereo inv * mono inv).
//		param m_left_out: output left eye conversion matrix
//		param m_right_out: output right eye conversion matrix
//		param m_left_inv_out_opt: output left eye conversion matrix inverse
//		param m_right_inv_out_opt: output right eye conversion matrix inverse
//		param interocularDist: distance between eyes (greater than zero)
//		param convergenceDist: distance to convergence plane (greater than zero)
//		return: m_left_out
float4m ijkMatProjectionStereoConversion4fm(float4x4 m_left_out, float4x4 m_right_out, float4x4 m_left_inv_out_opt, float4x4 m_right_inv_out_opt, f32 const interocularDist, f32 const convergenceDist);


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
//		return: determinant inverse
float ijkMatDeterminantInv2f(fmat2 const m_in);

// ijkMatDeterminantInvSafe2*
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
float ijkMatDeterminantInvSafe2f(fmat2 const m_in);

// ijkMatMulRowVec2*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
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

// ijkMatTransposeMul2*s
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
fmat2 ijkMatTransposeMul2fs(fmat2 const m_in, float const s);

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

// ijkMatInverseRotate2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
fmat2 ijkMatInverseRotate2f(fmat2 const m_in);

// ijkMatInverseScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
fmat2 ijkMatInverseScale2f(fmat2 const m_in);

// ijkMatInverseRotateScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
fmat2 ijkMatInverseRotateScale2f(fmat2 const m_in);

// ijkMatInverseTranspose2*
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
fmat2 ijkMatInverseTranspose2f(fmat2 const m_in);


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
float ijkMatDeterminant3f(fmat3 const m_in);

// ijkMatDeterminantInv3*
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
float ijkMatDeterminantInv3f(fmat3 const m_in);

// ijkMatDeterminantInvSafe3*
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
float ijkMatDeterminantInvSafe3f(fmat3 const m_in);

// ijkMatMulRowVec3*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
float ijkMatMulRowVec3f(fmat3 const m_in, fvec3 const v_in, index const row);

// ijkMatGetRow3*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
fvec3 ijkMatGetRow3f(fmat3 const m_in, index const row);

// ijkMatTranspose3*
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
fmat3 ijkMatTranspose3f(fmat3 const m_in);

// ijkMatTransposeMul3*s
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
fmat3 ijkMatTransposeMul3fs(fmat3 const m_in, float const s);

// ijkMatInverse3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
fmat3 ijkMatInverse3f(fmat3 const m_in);

// ijkMatInverseSafe3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
fmat3 ijkMatInverseSafe3f(fmat3 const m_in);

// ijkMatMulVec3*
//	Multiply 3D vector by 3x3 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
fvec3 ijkMatMulVec3f(fmat3 const m_lh, fvec3 const v_rh);

// ijkMatMul3*
//	Multiply 3x3 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
fmat3 ijkMatMul3f(fmat3 const m_lh, fmat3 const m_rh);

// ijkMatDiv3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat3 ijkMatDiv3f(fmat3 const m_lh, fmat3 const m_rh);

// ijkMatDivSafe3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat3 ijkMatDivSafe3f(fmat3 const m_lh, fmat3 const m_rh);

// ijkMatRotateXYZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateXYZ3f(fvec3 const rotateDegXYZ);

// ijkMatRotateYZX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateYZX3f(fvec3 const rotateDegXYZ);

// ijkMatRotateZXY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateZXY3f(fvec3 const rotateDegXYZ);

// ijkMatRotateYXZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateYXZ3f(fvec3 const rotateDegXYZ);

// ijkMatRotateXZY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateXZY3f(fvec3 const rotateDegXYZ);

// ijkMatRotateZYX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotateZYX3f(fvec3 const rotateDegXYZ);

// ijkMatGetRotateXYZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateXYZ3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYZX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateYZX3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZXY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateZXY3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYXZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateYXZ3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateXZY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateXZY3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZYX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotateZYX3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatRotate3*
//	Make 3D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat3 ijkMatRotate3f(ijkRotationOrder const order, fvec3 const rotateDegXYZ);

// ijkMatScale3*
//	Make 3D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
fmat3 ijkMatScale3f(fvec3 const scale);

// ijkMatRotateScale3*
//	Make 3D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
fmat3 ijkMatRotateScale3f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale);

// ijkMatGetRotate3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat3 ijkMatGetRotate3f(fmat3 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out);

// ijkMatGetScale3*
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
fmat3 ijkMatGetScale3f(fmat3 const m_in, fvec3* const scale_out);

// ijkMatGetRotateScale3*
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
fmat3 ijkMatGetRotateScale3f(fmat3 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out);

// ijkMatInverseRotate3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
fmat3 ijkMatInverseRotate3f(fmat3 const m_in);

// ijkMatInverseScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
fmat3 ijkMatInverseScale3f(fmat3 const m_in);

// ijkMatInverseRotateScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
fmat3 ijkMatInverseRotateScale3f(fmat3 const m_in);

// ijkMatInverseTranspose3*
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
fmat3 ijkMatInverseTranspose3f(fmat3 const m_in);

// ijkMatRotateAxisAngle3*
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
fmat3 ijkMatRotateAxisAngle3f(fvec3 const axis_unit, float const angle_degrees);

// ijkMatRotateAxisAngleScale3*
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
fmat3 ijkMatRotateAxisAngleScale3f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale);

// ijkMatGetRotateAxisAngle3*
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
fmat3 ijkMatGetRotateAxisAngle3f(fmat3 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale3*
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
fmat3 ijkMatGetRotateAxisAngleScale3f(fmat3 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out);

// ijkMatLookAt3*
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
fmat3 ijkMatLookAt3f(fmat3* const m_inv_out_opt, fvec3 const origin, fvec3 const target, fvec3 const calibUnit, ijkTransformBasis const calibAxis);


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
float ijkMatDeterminant4f(fmat4 const m_in);

// ijkMatDeterminantInv4*
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
float ijkMatDeterminantInv4f(fmat4 const m_in);

// ijkMatDeterminantInvSafe4*
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
float ijkMatDeterminantInvSafe4f(fmat4 const m_in);

// ijkMatMulRowVec4*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
float ijkMatMulRowVec4f(fmat4 const m_in, fvec4 const v_in, index const row);

// ijkMatGetRow4*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
fvec4 ijkMatGetRow4f(fmat4 const m_in, index const row);

// ijkMatTranspose4*
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
fmat4 ijkMatTranspose4f(fmat4 const m_in);

// ijkMatTransposeMul4*s
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
fmat4 ijkMatTransposeMul4fs(fmat4 const m_in, float const s);

// ijkMatInverse4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
fmat4 ijkMatInverse4f(fmat4 const m_in);

// ijkMatInverseSafe4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
fmat4 ijkMatInverseSafe4f(fmat4 const m_in);

// ijkMatMulVec4*
//	Multiply 4D vector by 4x4 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
fvec4 ijkMatMulVec4f(fmat4 const m_lh, fvec4 const v_rh);

// ijkMatMul4*
//	Multiply 4x4 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
fmat4 ijkMatMul4f(fmat4 const m_lh, fmat4 const m_rh);

// ijkMatDiv4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat4 ijkMatDiv4f(fmat4 const m_lh, fmat4 const m_rh);

// ijkMatDivSafe4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
fmat4 ijkMatDivSafe4f(fmat4 const m_lh, fmat4 const m_rh);

// ijkMatRotateXYZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateXYZ4f(fvec3 const rotateDegXYZ);

// ijkMatRotateYZX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateYZX4f(fvec3 const rotateDegXYZ);

// ijkMatRotateZXY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateZXY4f(fvec3 const rotateDegXYZ);

// ijkMatRotateYXZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateYXZ4f(fvec3 const rotateDegXYZ);

// ijkMatRotateXZY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateXZY4f(fvec3 const rotateDegXYZ);

// ijkMatRotateZYX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotateZYX4f(fvec3 const rotateDegXYZ);

// ijkMatGetRotateXYZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateXYZ4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYZX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateYZX4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZXY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateZXY4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYXZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateYXZ4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateXZY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateXZY4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZYX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotateZYX4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out);

// ijkMatRotate4*
//	Make 4D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
fmat4 ijkMatRotate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ);

// ijkMatScale4*
//	Make 4D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
fmat4 ijkMatScale4f(fvec3 const scale);

// ijkMatRotateScale4*
//	Make 4D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
fmat4 ijkMatRotateScale4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale);

// ijkMatGetRotate4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
fmat4 ijkMatGetRotate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out);

// ijkMatGetScale4*
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
fmat4 ijkMatGetScale4f(fmat4 const m_in, fvec3* const scale_out);

// ijkMatGetRotateScale4*
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
fmat4 ijkMatGetRotateScale4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out);

// ijkMatInverseRotate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseRotate4f(fmat4 const m_in);

// ijkMatInverseScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseScale4f(fmat4 const m_in);

// ijkMatInverseRotateScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseRotateScale4f(fmat4 const m_in);

// ijkMatInverseTranspose4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
fmat4 ijkMatInverseTranspose4f(fmat4 const m_in);

// ijkMatRotateAxisAngle4*
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
fmat4 ijkMatRotateAxisAngle4f(fvec3 const axis_unit, float const angle_degrees);

// ijkMatRotateAxisAngleScale4*
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
fmat4 ijkMatRotateAxisAngleScale4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale);

// ijkMatGetRotateAxisAngle4*
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
fmat4 ijkMatGetRotateAxisAngle4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale4*
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
fmat4 ijkMatGetRotateAxisAngleScale4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out);

// ijkMatTranslate4*
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param translate: translation offset vector
//		return: translation matrix
fmat4 ijkMatTranslate4f(fvec3 const translate);

// ijkMatRotateTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: rotation-translation matrix
fmat4 ijkMatRotateTranslate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const translate);

// ijkMatScaleTranslate4*
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: scale-translation matrix
fmat4 ijkMatScaleTranslate4f(fvec3 const scale, fvec3 const translate);

// ijkMatRotateScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
fmat4 ijkMatRotateScaleTranslate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale, fvec3 const translate);

// ijkMatRotateAxisAngleTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation matrix
fmat4 ijkMatRotateAxisAngleTranslate4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const translate);

// ijkMatRotateAxisAngleScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
fmat4 ijkMatRotateAxisAngleScaleTranslate4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale, fvec3 const translate);

// ijkMatGetTranslate4*
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetTranslate4f(fmat4 const m_in, fvec3* const translate_out);

// ijkMatGetRotateTranslate4*
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetRotateTranslate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const translate_out);

// ijkMatGetScaleTranslate4*
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetScaleTranslate4f(fmat4 const m_in, fvec3* const scale_out, fvec3* const translate_out);

// ijkMatGetRotateScaleTranslate4*
//	Extract rotation angle in degrees, scales and translation offset vector 
//	from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetRotateScaleTranslate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out, fvec3* const translate_out);

// ijkMatGetRotateAxisAngleTranslate4*
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetRotateAxisAngleTranslate4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const translate_out);

// ijkMatGetRotateAxisAngleScaleTranslate4*
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
fmat4 ijkMatGetRotateAxisAngleScaleTranslate4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out, fvec3* const translate_out);

// ijkMatInverseRotateTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseRotateTranslate4f(fmat4 const m_in);

// ijkMatInverseScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseScaleTranslate4f(fmat4 const m_in);

// ijkMatInverseRotateScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseRotateScaleTranslate4f(fmat4 const m_in);

// ijkMatInverseTransposeTranslate4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
fmat4 ijkMatInverseTransposeTranslate4f(fmat4 const m_in);

// ijkMatMulTransform4*
//	Concatenate as if inputs are transformation matrices, saving a few 
//	operations over full 4x4 product.
//		param m_lh: left-hand input matrix
//		param m_rh: right-hand input matrix
//		return: transform product
fmat4 ijkMatMulTransform4f(fmat4 const m_lh, fmat4 const m_rh);

// ijkMatMulVecTransform4*v3
//	Multiply 3D vector by transformation matrix, saving a few operations.
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: transformed input
fvec3 ijkMatMulVecTransform4fv3(fmat4 const m_lh, fvec3 const v_rh);

// ijkMatMulVecTransform4*v4
//	Multiply 4D vector by transformation matrix, saving a few operations.
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: transformed input
fvec4 ijkMatMulVecTransform4fv4(fmat4 const m_lh, fvec4 const v_rh);

// ijkMatLookAt4*
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
fmat4 ijkMatLookAt4f(fmat4* const m_inv_out_opt, fvec3 const origin, fvec3 const target, fvec3 const calibUnit, ijkTransformBasis const calibAxis);

// ijkMatProjectionPerspective4*
//	Create perspective projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: perspective projection matrix
fmat4 ijkMatProjectionPerspective4f(fmat4* const m_inv_out_opt, float const fovyDeg, float const aspect, float const nearDist, float const farDist);

// ijkMatProjectionParallel4*
//	Create parallel/orthographic projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: parallel projection matrix
fmat4 ijkMatProjectionParallel4f(fmat4* const m_inv_out_opt, float const fovyDeg, float const aspect, float const nearDist, float const farDist);

// ijkMatProjectionPerspectivePlanes4*
//	Create perspective projection matrix given plane distances.
//		param m_inv_out_opt: optional inverse matrix output
//		param leftDist: distance to left plane (not equal to right)
//		param rightDist: distance to right plane (not equal to left)
//		param bottomDist: distance to bottom plane (not equal to top)
//		param topDist: distance to top plane (not equal to bottom)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: perspective projection matrix
fmat4 ijkMatProjectionPerspectivePlanes4f(fmat4* const m_inv_out_opt, float const leftDist, float const rightDist, float const bottomDist, float const topDist, float const nearDist, float const farDist);

// ijkMatProjectionParallelPlanes4*
//	Create parallel/orthographic projection matrix given plane distances.
//		param m_inv_out_opt: optional inverse matrix output
//		param leftDist: distance to left plane (not equal to right)
//		param rightDist: distance to right plane (not equal to left)
//		param bottomDist: distance to bottom plane (not equal to top)
//		param topDist: distance to top plane (not equal to bottom)
//		param nearDist: distance to near plane (not equal to far)
//		param farDist: distance to far plane (not equal to near)
//		return: parallel projection matrix
fmat4 ijkMatProjectionParallelPlanes4f(fmat4* const m_inv_out_opt, float const leftDist, float const rightDist, float const bottomDist, float const topDist, float const nearDist, float const farDist);

// ijkMatProjectionStereoConversion4*
//	Create stereo projection conversion matrix. Convert monoscopic matrix to 
//	stereoscopic by multiplying conversion matrix on the right (mono * stereo).
//	Convert mono inverse matrix to stereo inverse by multiplying conversion 
//	inverse matrix on the left (stereo inv * mono inv).
//		param m_left_out: output left eye conversion matrix
//		param m_right_out: output right eye conversion matrix
//		param m_left_inv_out_opt: output left eye conversion matrix inverse
//		param m_right_inv_out_opt: output right eye conversion matrix inverse
//		param interocularDist: distance between eyes (greater than zero)
//		param convergenceDist: distance to convergence plane (greater than zero)
//		return: m_left_out
fmat4 ijkMatProjectionStereoConversion4f(fmat4* const m_left_out, fmat4* const m_right_out, fmat4* const m_left_inv_out_opt, fmat4* const m_right_inv_out_opt, float const interocularDist, float const convergenceDist);


//-----------------------------------------------------------------------------


#include "_inl/ijkMatrix_float.inl"


#endif	// !_IJK_MATRIX_FLOAT_H_
#endif	// _IJK_MATRIX_H_