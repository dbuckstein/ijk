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

	ijkMatrix_double.h
	Declarations for double matrix functions.
*/

#ifdef _IJK_MATRIX_H_
#ifndef _IJK_MATRIX_DOUBLE_H_
#define _IJK_MATRIX_DOUBLE_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMat2P*m
//	Pass-thru array-based 2D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
double2m ijkMat2Pdm(double2x2 m_out);

// ijkMat3P*m
//	Pass-thru array-based 3D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
double3m ijkMat3Pdm(double3x3 m_out);

// ijkMat4P*m
//	Pass-thru array-based 4D matrix function (does nothing).
//		param m_out: output matrix
//		return: m_out
double4m ijkMat4Pdm(double4x4 m_out);


//-----------------------------------------------------------------------------
	
// ijkMatInit2*m
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
double2m ijkMatInit2dm(double2x2 m_out);

// ijkMatInitElems2*m
//	Initialize 2x2 matrix given elements.
//		param m_out: output matrix
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: m_out
double2m ijkMatInitElems2dm(double2x2 m_out, f64 const x0, f64 const y0, f64 const x1, f64 const y1);

// ijkMatInitVecs2*m
//	Initialize 2x2 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		return: m_out
double2m ijkMatInitVecs2dm(double2x2 m_out, double2 const c0, double2 const c1);

// ijkMatCopy2*m2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double2m ijkMatCopy2dm2(double2x2 m_out, double2x2 const m_in);

// ijkMatCopy2*m3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
double2m ijkMatCopy2dm3(double2x2 m_out, double3x3 const m_in);

// ijkMatCopy2*m4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
double2m ijkMatCopy2dm4(double2x2 m_out, double4x4 const m_in);

// ijkMatNegate2*m
//	Negate 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double2m ijkMatNegate2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatCopy2*ms
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
double2m ijkMatCopy2dms(double2x2 m_out, f64 const s_diag);

// ijkMatMul2*ms
//	Multiply 2x2 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double2m ijkMatMul2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh);

// ijkMatDiv2*ms
//	Divide 2x2 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double2m ijkMatDiv2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh);

// ijkMatDivSafe2*ms
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double2m ijkMatDivSafe2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh);

// ijkMatMul2*sm
//	Multiply scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatMul2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh);

// ijkMatDiv2*sm
//	Divide scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatDiv2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh);

// ijkMatDivSafe2*sm
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatDivSafe2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh);

// ijkMatAdd2*m
//	Add 2x2 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatAdd2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh);

// ijkMatSub2*m
//	Subtract 2x2 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatSub2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh);


//-----------------------------------------------------------------------------
	
// ijkMatInit3*m
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
double3m ijkMatInit3dm(double3x3 m_out);

// ijkMatInitElems3*m
//	Initialize 3x3 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: m_out
double3m ijkMatInitElems3dm(double3x3 m_out, f64 const x0, f64 const y0, f64 const z0, f64 const x1, f64 const y1, f64 const z1, f64 const x2, f64 const y2, f64 const z2);

// ijkMatInitVecs3*m
//	Initialize 3x3 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: m_out
double3m ijkMatInitVecs3dm(double3x3 m_out, double3 const c0, double3 const c1, double3 const c2);

// ijkMatCopy3*m2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double3m ijkMatCopy3dm2(double3x3 m_out, double2x2 const m_in);

// ijkMatCopy3*m3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double3m ijkMatCopy3dm3(double3x3 m_out, double3x3 const m_in);

// ijkMatCopy3*m4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 3x3 matrix
//		param m_in: input matrix
//		return: m_out
double3m ijkMatCopy3dm4(double3x3 m_out, double4x4 const m_in);

// ijkMatNegate3*m
//	Negate 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double3m ijkMatNegate3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatCopy3*ms
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
double3m ijkMatCopy3dms(double3x3 m_out, f64 const s_diag);

// ijkMatMul3*ms
//	Multiply 3x3 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double3m ijkMatMul3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh);

// ijkMatDiv3*ms
//	Divide 3x3 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double3m ijkMatDiv3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh);

// ijkMatDivSafe3*ms
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double3m ijkMatDivSafe3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh);

// ijkMatMul3*sm
//	Multiply scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatMul3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh);

// ijkMatDiv3*sm
//	Divide scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatDiv3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh);

// ijkMatDivSafe3*sm
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatDivSafe3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh);

// ijkMatAdd3*m
//	Add 3x3 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatAdd3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh);

// ijkMatSub3*m
//	Subtract 3x3 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatSub3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh);


//-----------------------------------------------------------------------------
	
// ijkMatInit4*m
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
double4m ijkMatInit4dm(double4x4 m_out);

// ijkMatInitElems4*m
//	Initialize 4x4 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: m_out
double4m ijkMatInitElems4dm(double4x4 m_out, f64 const x0, f64 const y0, f64 const z0, f64 const w0, f64 const x1, f64 const y1, f64 const z1, f64 const w1, f64 const x2, f64 const y2, f64 const z2, f64 const w2, f64 const x3, f64 const y3, f64 const z3, f64 const w3);

// ijkMatInitVecs4*m
//	Initialize 4x4 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: m_out
double4m ijkMatInitVecs4dm(double4x4 m_out, double4 const c0, double4 const c1, double4 const c2, double4 const c3);

// ijkMatCopy4*m2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double4m ijkMatCopy4dm2(double4x4 m_out, double2x2 const m_in);

// ijkMatCopy4*m3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double4m ijkMatCopy4dm3(double4x4 m_out, double3x3 const m_in);

// ijkMatCopy4*m4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double4m ijkMatCopy4dm4(double4x4 m_out, double4x4 const m_in);

// ijkMatNegate4*m
//	Negate 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
double4m ijkMatNegate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatCopy4*ms
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
double4m ijkMatCopy4dms(double4x4 m_out, f64 const s_diag);

// ijkMatMul4*ms
//	Multiply 4x4 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double4m ijkMatMul4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh);

// ijkMatDiv4*ms
//	Divide 4x4 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double4m ijkMatDiv4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh);

// ijkMatDivSafe4*ms
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
double4m ijkMatDivSafe4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh);

// ijkMatMul4*sm
//	Multiply scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatMul4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh);

// ijkMatDiv4*sm
//	Divide scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatDiv4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh);

// ijkMatDivSafe4*sm
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatDivSafe4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh);

// ijkMatAdd4*m
//	Add 4x4 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatAdd4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);

// ijkMatSub4*m
//	Subtract 4x4 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatSub4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------
	
// ijkMatInit2*
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
dmat2 ijkMatInit2d();

// ijkMatInitElems2*
//	Initialize 2x2 matrix given elements.
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: matrix of elements
dmat2 ijkMatInitElems2d(double const x0, double const y0, double const x1, double const y1);

// ijkMatInitVecs2*
//	Initialize 2x2 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		return: matrix of columns
dmat2 ijkMatInitVecs2d(dvec2 const c0, dvec2 const c1);

// ijkMatCopy2*2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_in: input matrix
//		return: copy of input
dmat2 ijkMatCopy2d2(dmat2 const m_in);

// ijkMatCopy2*3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
dmat2 ijkMatCopy2d3(dmat3 const m_in);

// ijkMatCopy2*4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
dmat2 ijkMatCopy2d4(dmat4 const m_in);

// ijkMatNegate2*
//	Negate 2x2 matrix.
//		param m_in: input matrix
//		return: negated matrix
dmat2 ijkMatNegate2d(dmat2 const m_in);

// ijkMatCopy2*s
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
dmat2 ijkMatCopy2ds(double const s_diag);

// ijkMatMul2*s
//	Multiply 2x2 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
dmat2 ijkMatMul2ds(dmat2 const m_lh, double const s_rh);

// ijkMatDiv2*s
//	Divide 2x2 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat2 ijkMatDiv2ds(dmat2 const m_lh, double const s_rh);

// ijkMatDivSafe2*s
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat2 ijkMatDivSafe2ds(dmat2 const m_lh, double const s_rh);

// ijkMatMul2s*
//	Multiply scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
dmat2 ijkMatMul2sd(double const s_lh, dmat2 const m_rh);

// ijkMatDiv2s*
//	Divide scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat2 ijkMatDiv2sd(double const s_lh, dmat2 const m_rh);

// ijkMatDivSafe2s*
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat2 ijkMatDivSafe2sd(double const s_lh, dmat2 const m_rh);

// ijkMatAdd2*
//	Add 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
dmat2 ijkMatAdd2d(dmat2 const m_lh, dmat2 const m_rh);

// ijkMatSub2*
//	Subtract 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
dmat2 ijkMatSub2d(dmat2 const m_lh, dmat2 const m_rh);


//-----------------------------------------------------------------------------

// ijkMatInit3*
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
dmat3 ijkMatInit3d();

// ijkMatInitElems3*
//	Initialize 3x3 matrix given elements.
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: matrix of elements
dmat3 ijkMatInitElems3d(double const x0, double const y0, double const z0, double const x1, double const y1, double const z1, double const x2, double const y2, double const z2);

// ijkMatInitVecs3*
//	Initialize 3x3 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: matrix of columns
dmat3 ijkMatInitVecs3d(dvec3 const c0, dvec3 const c1, dvec3 const c2);

// ijkMatCopy3*2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
dmat3 ijkMatCopy3d2(dmat2 const m_in);

// ijkMatCopy3*3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input
dmat3 ijkMatCopy3d3(dmat3 const m_in);

// ijkMatCopy3*4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 3x3 matrix
dmat3 ijkMatCopy3d4(dmat4 const m_in);

// ijkMatNegate3*
//	Negate 3x3 matrix.
//		param m_in: input matrix
//		return: negated matrix
dmat3 ijkMatNegate3d(dmat3 const m_in);

// ijkMatCopy3*s
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
dmat3 ijkMatCopy3ds(double const s_diag);

// ijkMatMul3*s
//	Multiply 3x3 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
dmat3 ijkMatMul3ds(dmat3 const m_lh, double const s_rh);

// ijkMatDiv3*s
//	Divide 3x3 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat3 ijkMatDiv3ds(dmat3 const m_lh, double const s_rh);

// ijkMatDivSafe3*s
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat3 ijkMatDivSafe3ds(dmat3 const m_lh, double const s_rh);

// ijkMatMul3s*
//	Multiply scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
dmat3 ijkMatMul3sd(double const s_lh, dmat3 const m_rh);

// ijkMatDiv3s*
//	Divide scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat3 ijkMatDiv3sd(double const s_lh, dmat3 const m_rh);

// ijkMatDivSafe3s*
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat3 ijkMatDivSafe3sd(double const s_lh, dmat3 const m_rh);

// ijkMatAdd3*
//	Add 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
dmat3 ijkMatAdd3d(dmat3 const m_lh, dmat3 const m_rh);

// ijkMatSub3*
//	Subtract 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
dmat3 ijkMatSub3d(dmat3 const m_lh, dmat3 const m_rh);


//-----------------------------------------------------------------------------

// ijkMatInit4*
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
dmat4 ijkMatInit4d();

// ijkMatInitElems4*
//	Initialize 4x4 matrix given elements.
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: matrix of elements
dmat4 ijkMatInitElems4d(double const x0, double const y0, double const z0, double const w0, double const x1, double const y1, double const z1, double const w1, double const x2, double const y2, double const z2, double const w2, double const x3, double const y3, double const z3, double const w3);

// ijkMatInitVecs4*
//	Initialize 4x4 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: matrix of columns
dmat4 ijkMatInitVecs4d(dvec4 const c0, dvec4 const c1, dvec4 const c2, dvec4 const c3);

// ijkMatCopy4*2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
dmat4 ijkMatCopy4d2(dmat2 const m_in);

// ijkMatCopy4*3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
dmat4 ijkMatCopy4d3(dmat3 const m_in);

// ijkMatCopy4*4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input
dmat4 ijkMatCopy4d4(dmat4 const m_in);

// ijkMatNegate4*
//	Negate 4x4 matrix.
//		param m_in: input matrix
//		return: negated matrix
dmat4 ijkMatNegate4d(dmat4 const m_in);

// ijkMatCopy4*s
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
dmat4 ijkMatCopy4ds(double const s_diag);

// ijkMatMul4*s
//	Multiply 4x4 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
dmat4 ijkMatMul4ds(dmat4 const m_lh, double const s_rh);

// ijkMatDiv4*s
//	Divide 4x4 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat4 ijkMatDiv4ds(dmat4 const m_lh, double const s_rh);

// ijkMatDivSafe4*s
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
dmat4 ijkMatDivSafe4ds(dmat4 const m_lh, double const s_rh);

// ijkMatMul4s*
//	Multiply scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
dmat4 ijkMatMul4sd(double const s_lh, dmat4 const m_rh);

// ijkMatDiv4s*
//	Divide scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat4 ijkMatDiv4sd(double const s_lh, dmat4 const m_rh);

// ijkMatDivSafe4s*
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
dmat4 ijkMatDivSafe4sd(double const s_lh, dmat4 const m_rh);

// ijkMatAdd4*
//	Add 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
dmat4 ijkMatAdd4d(dmat4 const m_lh, dmat4 const m_rh);

// ijkMatSub4*
//	Subtract 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
dmat4 ijkMatSub4d(dmat4 const m_lh, dmat4 const m_rh);


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*m
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
f64 ijkMatDeterminant2dm(double2x2 const m_in);

// ijkMatDeterminantInv2*m
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInv2dm(double2x2 const m_in);

// ijkMatDeterminantInvSafe2*m
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInvSafe2dm(double2x2 const m_in);

// ijkMatMulRowVec2*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f64 ijkMatMulRowVec2dmv(double2x2 const m_in, double2 const v_in, index const row);

// ijkMatGetRow2*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
doublev ijkMatGetRow2dm(double2 v_out, double2x2 const m_in, index const row);

// ijkMatTranspose2*m
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
double2m ijkMatTranspose2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatTransposeMul2*ms
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
double2m ijkMatTransposeMul2dms(double2x2 m_out, double2x2 const m_in, f64 const s);

// ijkMatInverse2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverse2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatInverseSafe2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverseSafe2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatMulVec2*mv
//	Multiply 2D vector by 2x2 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
doublev ijkMatMulVec2dmv(double2 v_out, double2x2 const m_lh, double2 const v_rh);

// ijkMatMul2*m
//	Multiply 2x2 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatMul2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh);

// ijkMatDiv2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatDiv2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh);

// ijkMatDivSafe2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double2m ijkMatDivSafe2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh);

// ijkMatRotate2*m
//	Make 2D rotation matrix.
//		param m_out: output matrix, rotation
//		param angle_degrees: input angle in degrees
//		return: m_out
double2m ijkMatRotate2dm(double2x2 m_out, f64 const angle_degrees);

// ijkMatScale2*m
//	Make 2D scale matrix.
//		param m_out: output matrix, scale
//		params sx, sy: scales on each dimension
//		return: m_out
double2m ijkMatScale2dm(double2x2 m_out, f64 const sx, f64 const sy);

// ijkMatRotateScale2*m
//	Make 2D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: m_out
double2m ijkMatRotateScale2dm(double2x2 m_out, f64 const angle_degrees, f64 const sx, f64 const sy);

// ijkMatGetRotate2*m
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
double2km ijkMatGetRotate2dm(double2x2 const m_in, f64* const angle_degrees_out);

// ijkMatGetScale2*m
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
double2km ijkMatGetScale2dm(double2x2 const m_in, f64* const sx_out, f64* const sy_out);

// ijkMatGetRotateScale2*m
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
double2km ijkMatGetRotateScale2dm(double2x2 const m_in, f64* const angle_degrees_out, f64* const sx_out, f64* const sy_out);

// ijkMatInverseRotate2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverseRotate2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatInverseScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverseScale2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatInverseRotateScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverseRotateScale2dm(double2x2 m_out, double2x2 const m_in);

// ijkMatInverseTranspose2*m
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
double2m ijkMatInverseTranspose2dm(double2x2 m_out, double2x2 const m_in);


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*m
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
f64 ijkMatDeterminant3dm(double3x3 const m_in);

// ijkMatDeterminantInv3*m
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInv3dm(double3x3 const m_in);

// ijkMatDeterminantInvSafe3*m
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInvSafe3dm(double3x3 const m_in);

// ijkMatMulRowVec3*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f64 ijkMatMulRowVec3dmv(double3x3 const m_in, double3 const v_in, index const row);

// ijkMatGetRow3*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
doublev ijkMatGetRow3dm(double3 v_out, double3x3 const m_in, index const row);

// ijkMatTranspose3*m
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
double3m ijkMatTranspose3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatTransposeMul3*ms
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
double3m ijkMatTransposeMul3dms(double3x3 m_out, double3x3 const m_in, f64 const s);

// ijkMatInverse3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverse3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatInverseSafe3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverseSafe3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatMulVec3*mv
//	Multiply 3D vector by 3x3 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
doublev ijkMatMulVec3dmv(double3 v_out, double3x3 const m_lh, double3 const v_rh);

// ijkMatMul3*m
//	Multiply 3x3 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatMul3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh);

// ijkMatDiv3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatDiv3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh);

// ijkMatDivSafe3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double3m ijkMatDivSafe3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh);

// ijkMatRotateXYZ3*m
//	Make 3D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateXYZ3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatRotateYZX3*m
//	Make 3D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateYZX3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatRotateZXY3*m
//	Make 3D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateZXY3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatRotateYXZ3*m
//	Make 3D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateYXZ3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatRotateXZY3*m
//	Make 3D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateXZY3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatRotateZYX3*m
//	Make 3D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotateZYX3dm(double3x3 m_out, double3 const rotateDegXYZ);

// ijkMatGetRotateXYZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateXYZ3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateYZX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateYZX3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateZXY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateZXY3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateYXZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateYXZ3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateXZY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateXZY3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateZYX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotateZYX3dm(double3x3 const m_in, double3 rotateDegXYZ_out);

// ijkMatRotate3*m
//	Make 3D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double3m ijkMatRotate3dm(double3x3 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ);

// ijkMatScale3*m
//	Make 3D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
double3m ijkMatScale3dm(double3x3 m_out, double3 const scale);

// ijkMatRotateScale3*m
//	Make 3D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
double3m ijkMatRotateScale3dm(double3x3 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale);

// ijkMatGetRotate3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double3km ijkMatGetRotate3dm(double3x3 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out);

// ijkMatGetScale3*m
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
double3km ijkMatGetScale3dm(double3x3 const m_in, double3 scale_out);

// ijkMatGetRotateScale3*m
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
double3km ijkMatGetRotateScale3dm(double3x3 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out);

// ijkMatInverseRotate3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverseRotate3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatInverseScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverseScale3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatInverseRotateScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverseRotateScale3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatInverseTranspose3*m
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
double3m ijkMatInverseTranspose3dm(double3x3 m_out, double3x3 const m_in);

// ijkMatRotateAxisAngle3*m
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
double3m ijkMatRotateAxisAngle3dm(double3x3 m_out, double3 const axis_unit, f64 const angle_degrees);

// ijkMatRotateAxisAngleScale3*m
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
double3m ijkMatRotateAxisAngleScale3dm(double3x3 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale);

// ijkMatGetRotateAxisAngle3*m
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
double3km ijkMatGetRotateAxisAngle3dm(double3x3 const m_in, double3 axis_unit_out, f64* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale3*m
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
double3km ijkMatGetRotateAxisAngleScale3dm(double3x3 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out);

// ijkMatLookAt3*m
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
double3m ijkMatLookAt3dm(double3x3 m_out, double3x3 m_inv_out_opt, double3 const origin, double3 const target, double3 const calibUnit, ijkTransformBasis const calibAxis);


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*m
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
f64 ijkMatDeterminant4dm(double4x4 const m_in);

// ijkMatDeterminantInv4*m
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInv4dm(double4x4 const m_in);

// ijkMatDeterminantInvSafe4*m
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
f64 ijkMatDeterminantInvSafe4dm(double4x4 const m_in);

// ijkMatMulRowVec4*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
f64 ijkMatMulRowVec4dmv(double4x4 const m_in, double4 const v_in, index const row);

// ijkMatGetRow4*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
doublev ijkMatGetRow4dm(double4 v_out, double4x4 const m_in, index const row);

// ijkMatTranspose4*m
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
double4m ijkMatTranspose4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatTransposeMul4*ms
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
double4m ijkMatTransposeMul4dms(double4x4 m_out, double4x4 const m_in, f64 const s);

// ijkMatInverse4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverse4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseSafe4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseSafe4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatMulVec4*mv
//	Multiply 4D vector by 4x4 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
doublev ijkMatMulVec4dmv(double4 v_out, double4x4 const m_lh, double4 const v_rh);

// ijkMatMul4*m
//	Multiply 4x4 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatMul4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);

// ijkMatDiv4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatDiv4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);

// ijkMatDivSafe4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
double4m ijkMatDivSafe4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);

// ijkMatRotateXYZ4*m
//	Make 4D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateXYZ4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatRotateYZX4*m
//	Make 4D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateYZX4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatRotateZXY4*m
//	Make 4D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateZXY4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatRotateYXZ4*m
//	Make 4D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateYXZ4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatRotateXZY4*m
//	Make 4D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateXZY4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatRotateZYX4*m
//	Make 4D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotateZYX4dm(double4x4 m_out, double3 const rotateDegXYZ);

// ijkMatGetRotateXYZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateXYZ4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateYZX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateYZX4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateZXY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateZXY4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateYXZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateYXZ4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateXZY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateXZY4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatGetRotateZYX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotateZYX4dm(double4x4 const m_in, double3 rotateDegXYZ_out);

// ijkMatRotate4*m
//	Make 4D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
double4m ijkMatRotate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ);

// ijkMatScale4*m
//	Make 4D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
double4m ijkMatScale4dm(double4x4 m_out, double3 const scale);

// ijkMatRotateScale4*m
//	Make 4D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
double4m ijkMatRotateScale4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale);

// ijkMatGetRotate4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
double4km ijkMatGetRotate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out);

// ijkMatGetScale4*m
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
double4km ijkMatGetScale4dm(double4x4 const m_in, double3 scale_out);

// ijkMatGetRotateScale4*m
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
double4km ijkMatGetRotateScale4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out);

// ijkMatInverseRotate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseRotate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseScale4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseRotateScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseRotateScale4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseTranspose4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseTranspose4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatRotateAxisAngle4*m
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
double4m ijkMatRotateAxisAngle4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees);

// ijkMatRotateAxisAngleScale4*m
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
double4m ijkMatRotateAxisAngleScale4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale);

// ijkMatGetRotateAxisAngle4*m
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
double4km ijkMatGetRotateAxisAngle4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale4*m
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
double4km ijkMatGetRotateAxisAngleScale4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out);

// ijkMatTranslate4*m
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, translation
//		param translate: translation offset vector
//		return: m_out
double4m ijkMatTranslate4dm(double4x4 m_out, double3 const translate);

// ijkMatRotateTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: m_out
double4m ijkMatRotateTranslate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const translate);

// ijkMatScaleTranslate4*m
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, scale-translate
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
double4m ijkMatScaleTranslate4dm(double4x4 m_out, double3 const scale, double3 const translate);

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
double4m ijkMatRotateScaleTranslate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale, double3 const translate);

// ijkMatRotateAxisAngleTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: m_out
double4m ijkMatRotateAxisAngleTranslate4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const translate);

// ijkMatRotateAxisAngleScaleTranslate4*m
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param m_out: output matrix, rotate-scale-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
double4m ijkMatRotateAxisAngleScaleTranslate4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale, double3 const translate);

// ijkMatGetTranslate4*m
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
double4km ijkMatGetTranslate4dm(double4x4 const m_in, double3 translate_out);

// ijkMatGetRotateTranslate4*m
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
double4km ijkMatGetRotateTranslate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out);

// ijkMatGetScaleTranslate4*m
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
double4km ijkMatGetScaleTranslate4dm(double4x4 const m_in, double3 scale_out, double3 translate_out);

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
double4km ijkMatGetRotateScaleTranslate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out, double3 translate_out);

// ijkMatGetRotateAxisAngleTranslate4*m
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
double4km ijkMatGetRotateAxisAngleTranslate4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out);

// ijkMatGetRotateAxisAngleScaleTranslate4*m
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
double4km ijkMatGetRotateAxisAngleScaleTranslate4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out, double3 translate_out);

// ijkMatInverseRotateTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseRotateTranslate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseScaleTranslate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseRotateScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseRotateScaleTranslate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatInverseTransposeTranslate4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
double4m ijkMatInverseTransposeTranslate4dm(double4x4 m_out, double4x4 const m_in);

// ijkMatMulTransform4*m
//	Concatenate as if inputs are transformation matrices, saving a few 
//	operations over full 4x4 product.
//		param m_out: output matrix, transform product
//		param m_lh: left-hand input matrix
//		param m_rh: right-hand input matrix
//		return: m_out
double4m ijkMatMulTransform4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh);

// ijkMatMulVecTransform4*mv3
//	Multiply 3D vector by transformation matrix, saving a few operations.
//		param v_out: output vector, transformed input
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: v_out
doublev ijkMatMulVecTransform4dmv3(double3 v_out, double4x4 const m_lh, double3 const v_rh);

// ijkMatMulVecTransform4*mv4
//	Multiply 4D vector by transformation matrix, saving a few operations.
//		param v_out: output vector, transformed input
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: v_out
doublev ijkMatMulVecTransform4dmv4(double4 v_out, double4x4 const m_lh, double4 const v_rh);

// ijkMatLookAt4*m
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
double4m ijkMatLookAt4dm(double4x4 m_out, double4x4 m_inv_out_opt, double3 const origin, double3 const target, double3 const calibUnit, ijkTransformBasis const calibAxis);

// ijkMatProjectionPerspective4*m
//	Create perspective projection matrix.
//		param m_out: output matrix, perspective projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
double4m ijkMatProjectionPerspective4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const fovyDeg, f64 const aspect, f64 const nearDist, f64 const farDist);

// ijkMatProjectionParallel4*m
//	Create parallel/orthographic projection matrix.
//		param m_out: output matrix, parallel projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
double4m ijkMatProjectionParallel4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const fovyDeg, f64 const aspect, f64 const nearDist, f64 const farDist);

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
double4m ijkMatProjectionPerspectivePlanes4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const leftDist, f64 const rightDist, f64 const bottomDist, f64 const topDist, f64 const nearDist, f64 const farDist);

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
double4m ijkMatProjectionParallelPlanes4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const leftDist, f64 const rightDist, f64 const bottomDist, f64 const topDist, f64 const nearDist, f64 const farDist);

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
double4m ijkMatProjectionStereoConversion4dm(double4x4 m_left_out, double4x4 m_right_out, double4x4 m_left_inv_out_opt, double4x4 m_right_inv_out_opt, f64 const interocularDist, f64 const convergenceDist);


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
double ijkMatDeterminant2d(dmat2 const m_in);

// ijkMatDeterminantInv2*
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInv2d(dmat2 const m_in);

// ijkMatDeterminantInvSafe2*
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInvSafe2d(dmat2 const m_in);

// ijkMatMulRowVec2*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
double ijkMatMulRowVec2d(dmat2 const m_in, dvec2 const v_in, index const row);

// ijkMatGetRow2*
//	Get row as vector.
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
dvec2 ijkMatGetRow2d(dmat2 const m_in, index const row);

// ijkMatTranspose2*
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
dmat2 ijkMatTranspose2d(dmat2 const m_in);

// ijkMatTransposeMul2*s
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
dmat2 ijkMatTransposeMul2ds(dmat2 const m_in, double const s);

// ijkMatInverse2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
dmat2 ijkMatInverse2d(dmat2 const m_in);

// ijkMatInverseSafe2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
dmat2 ijkMatInverseSafe2d(dmat2 const m_in);

// ijkMatMulVec2*
//	Multiply 2D vector by 2x2 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
dvec2 ijkMatMulVec2d(dmat2 const m_lh, dvec2 const v_rh);

// ijkMatMul2*
//	Multiply 2x2 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
dmat2 ijkMatMul2d(dmat2 const m_lh, dmat2 const m_rh);

// ijkMatDiv2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat2 ijkMatDiv2d(dmat2 const m_lh, dmat2 const m_rh);

// ijkMatDivSafe2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat2 ijkMatDivSafe2d(dmat2 const m_lh, dmat2 const m_rh);

// ijkMatRotate2*
//	Make 2D rotation matrix.
//		param angle_degrees: input angle in degrees
//		return: rotation matrix
dmat2 ijkMatRotate2d(double const angle_degrees);

// ijkMatScale2*
//	Make 2D scale matrix.
//		params sx, sy: scales on each dimension
//		return: scale matrix
dmat2 ijkMatScale2d(double const sx, double const sy);

// ijkMatRotateScale2*
//	Make 2D rotation-scale matrix.
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: rotation-scale matrix
dmat2 ijkMatRotateScale2d(double const angle_degrees, double const sx, double const sy);

// ijkMatGetRotate2*
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
dmat2 ijkMatGetRotate2d(dmat2 const m_in, double* const angle_degrees_out);

// ijkMatGetScale2*
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
dmat2 ijkMatGetScale2d(dmat2 const m_in, double* const sx_out, double* const sy_out);

// ijkMatGetRotateScale2*
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
dmat2 ijkMatGetRotateScale2d(dmat2 const m_in, double* const angle_degrees_out, double* const sx_out, double* const sy_out);

// ijkMatInverseRotate2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
dmat2 ijkMatInverseRotate2d(dmat2 const m_in);

// ijkMatInverseScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
dmat2 ijkMatInverseScale2d(dmat2 const m_in);

// ijkMatInverseRotateScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
dmat2 ijkMatInverseRotateScale2d(dmat2 const m_in);

// ijkMatInverseTranspose2*
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
dmat2 ijkMatInverseTranspose2d(dmat2 const m_in);


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
double ijkMatDeterminant3d(dmat3 const m_in);

// ijkMatDeterminantInv3*
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInv3d(dmat3 const m_in);

// ijkMatDeterminantInvSafe3*
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInvSafe3d(dmat3 const m_in);

// ijkMatMulRowVec3*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
double ijkMatMulRowVec3d(dmat3 const m_in, dvec3 const v_in, index const row);

// ijkMatGetRow3*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
dvec3 ijkMatGetRow3d(dmat3 const m_in, index const row);

// ijkMatTranspose3*
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
dmat3 ijkMatTranspose3d(dmat3 const m_in);

// ijkMatTransposeMul3*s
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
dmat3 ijkMatTransposeMul3ds(dmat3 const m_in, double const s);

// ijkMatInverse3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
dmat3 ijkMatInverse3d(dmat3 const m_in);

// ijkMatInverseSafe3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
dmat3 ijkMatInverseSafe3d(dmat3 const m_in);

// ijkMatMulVec3*
//	Multiply 3D vector by 3x3 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
dvec3 ijkMatMulVec3d(dmat3 const m_lh, dvec3 const v_rh);

// ijkMatMul3*
//	Multiply 3x3 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
dmat3 ijkMatMul3d(dmat3 const m_lh, dmat3 const m_rh);

// ijkMatDiv3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat3 ijkMatDiv3d(dmat3 const m_lh, dmat3 const m_rh);

// ijkMatDivSafe3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat3 ijkMatDivSafe3d(dmat3 const m_lh, dmat3 const m_rh);

// ijkMatRotateXYZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateXYZ3d(dvec3 const rotateDegXYZ);

// ijkMatRotateYZX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateYZX3d(dvec3 const rotateDegXYZ);

// ijkMatRotateZXY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateZXY3d(dvec3 const rotateDegXYZ);

// ijkMatRotateYXZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateYXZ3d(dvec3 const rotateDegXYZ);

// ijkMatRotateXZY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateXZY3d(dvec3 const rotateDegXYZ);

// ijkMatRotateZYX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotateZYX3d(dvec3 const rotateDegXYZ);

// ijkMatGetRotateXYZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateXYZ3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYZX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateYZX3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZXY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateZXY3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYXZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateYXZ3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateXZY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateXZY3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZYX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotateZYX3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatRotate3*
//	Make 3D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat3 ijkMatRotate3d(ijkRotationOrder const order, dvec3 const rotateDegXYZ);

// ijkMatScale3*
//	Make 3D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
dmat3 ijkMatScale3d(dvec3 const scale);

// ijkMatRotateScale3*
//	Make 3D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
dmat3 ijkMatRotateScale3d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale);

// ijkMatGetRotate3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat3 ijkMatGetRotate3d(dmat3 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out);

// ijkMatGetScale3*
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
dmat3 ijkMatGetScale3d(dmat3 const m_in, dvec3* const scale_out);

// ijkMatGetRotateScale3*
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
dmat3 ijkMatGetRotateScale3d(dmat3 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out);

// ijkMatInverseRotate3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
dmat3 ijkMatInverseRotate3d(dmat3 const m_in);

// ijkMatInverseScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
dmat3 ijkMatInverseScale3d(dmat3 const m_in);

// ijkMatInverseRotateScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
dmat3 ijkMatInverseRotateScale3d(dmat3 const m_in);

// ijkMatInverseTranspose3*
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
dmat3 ijkMatInverseTranspose3d(dmat3 const m_in);

// ijkMatRotateAxisAngle3*
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
dmat3 ijkMatRotateAxisAngle3d(dvec3 const axis_unit, double const angle_degrees);

// ijkMatRotateAxisAngleScale3*
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
dmat3 ijkMatRotateAxisAngleScale3d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale);

// ijkMatGetRotateAxisAngle3*
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
dmat3 ijkMatGetRotateAxisAngle3d(dmat3 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale3*
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
dmat3 ijkMatGetRotateAxisAngleScale3d(dmat3 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out);

// ijkMatLookAt3*
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
dmat3 ijkMatLookAt3d(dmat3* const m_inv_out_opt, dvec3 const origin, dvec3 const target, dvec3 const calibUnit, ijkTransformBasis const calibAxis);


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
double ijkMatDeterminant4d(dmat4 const m_in);

// ijkMatDeterminantInv4*
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInv4d(dmat4 const m_in);

// ijkMatDeterminantInvSafe4*
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
double ijkMatDeterminantInvSafe4d(dmat4 const m_in);

// ijkMatMulRowVec4*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
double ijkMatMulRowVec4d(dmat4 const m_in, dvec4 const v_in, index const row);

// ijkMatGetRow4*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
dvec4 ijkMatGetRow4d(dmat4 const m_in, index const row);

// ijkMatTranspose4*
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
dmat4 ijkMatTranspose4d(dmat4 const m_in);

// ijkMatTransposeMul4*s
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
dmat4 ijkMatTransposeMul4ds(dmat4 const m_in, double const s);

// ijkMatInverse4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
dmat4 ijkMatInverse4d(dmat4 const m_in);

// ijkMatInverseSafe4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
dmat4 ijkMatInverseSafe4d(dmat4 const m_in);

// ijkMatMulVec4*
//	Multiply 4D vector by 4x4 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
dvec4 ijkMatMulVec4d(dmat4 const m_lh, dvec4 const v_rh);

// ijkMatMul4*
//	Multiply 4x4 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
dmat4 ijkMatMul4d(dmat4 const m_lh, dmat4 const m_rh);

// ijkMatDiv4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat4 ijkMatDiv4d(dmat4 const m_lh, dmat4 const m_rh);

// ijkMatDivSafe4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
dmat4 ijkMatDivSafe4d(dmat4 const m_lh, dmat4 const m_rh);

// ijkMatRotateXYZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateXYZ4d(dvec3 const rotateDegXYZ);

// ijkMatRotateYZX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateYZX4d(dvec3 const rotateDegXYZ);

// ijkMatRotateZXY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateZXY4d(dvec3 const rotateDegXYZ);

// ijkMatRotateYXZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateYXZ4d(dvec3 const rotateDegXYZ);

// ijkMatRotateXZY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateXZY4d(dvec3 const rotateDegXYZ);

// ijkMatRotateZYX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotateZYX4d(dvec3 const rotateDegXYZ);

// ijkMatGetRotateXYZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateXYZ4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYZX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateYZX4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZXY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateZXY4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateYXZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateYXZ4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateXZY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateXZY4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatGetRotateZYX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotateZYX4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out);

// ijkMatRotate4*
//	Make 4D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
dmat4 ijkMatRotate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ);

// ijkMatScale4*
//	Make 4D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
dmat4 ijkMatScale4d(dvec3 const scale);

// ijkMatRotateScale4*
//	Make 4D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
dmat4 ijkMatRotateScale4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale);

// ijkMatGetRotate4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
dmat4 ijkMatGetRotate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out);

// ijkMatGetScale4*
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
dmat4 ijkMatGetScale4d(dmat4 const m_in, dvec3* const scale_out);

// ijkMatGetRotateScale4*
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
dmat4 ijkMatGetRotateScale4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out);

// ijkMatInverseRotate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseRotate4d(dmat4 const m_in);

// ijkMatInverseScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseScale4d(dmat4 const m_in);

// ijkMatInverseRotateScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseRotateScale4d(dmat4 const m_in);

// ijkMatInverseTranspose4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
dmat4 ijkMatInverseTranspose4d(dmat4 const m_in);

// ijkMatRotateAxisAngle4*
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
dmat4 ijkMatRotateAxisAngle4d(dvec3 const axis_unit, double const angle_degrees);

// ijkMatRotateAxisAngleScale4*
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
dmat4 ijkMatRotateAxisAngleScale4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale);

// ijkMatGetRotateAxisAngle4*
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
dmat4 ijkMatGetRotateAxisAngle4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out);

// ijkMatGetRotateAxisAngleScale4*
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
dmat4 ijkMatGetRotateAxisAngleScale4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out);

// ijkMatTranslate4*
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param translate: translation offset vector
//		return: translation matrix
dmat4 ijkMatTranslate4d(dvec3 const translate);

// ijkMatRotateTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: rotation-translation matrix
dmat4 ijkMatRotateTranslate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const translate);

// ijkMatScaleTranslate4*
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: scale-translation matrix
dmat4 ijkMatScaleTranslate4d(dvec3 const scale, dvec3 const translate);

// ijkMatRotateScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
dmat4 ijkMatRotateScaleTranslate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale, dvec3 const translate);

// ijkMatRotateAxisAngleTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation matrix
dmat4 ijkMatRotateAxisAngleTranslate4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const translate);

// ijkMatRotateAxisAngleScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
dmat4 ijkMatRotateAxisAngleScaleTranslate4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale, dvec3 const translate);

// ijkMatGetTranslate4*
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
dmat4 ijkMatGetTranslate4d(dmat4 const m_in, dvec3* const translate_out);

// ijkMatGetRotateTranslate4*
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
dmat4 ijkMatGetRotateTranslate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out);

// ijkMatGetScaleTranslate4*
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
dmat4 ijkMatGetScaleTranslate4d(dmat4 const m_in, dvec3* const scale_out, dvec3* const translate_out);

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
dmat4 ijkMatGetRotateScaleTranslate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out, dvec3* const translate_out);

// ijkMatGetRotateAxisAngleTranslate4*
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
dmat4 ijkMatGetRotateAxisAngleTranslate4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out);

// ijkMatGetRotateAxisAngleScaleTranslate4*
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
dmat4 ijkMatGetRotateAxisAngleScaleTranslate4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out, dvec3* const translate_out);

// ijkMatInverseRotateTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseRotateTranslate4d(dmat4 const m_in);

// ijkMatInverseScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseScaleTranslate4d(dmat4 const m_in);

// ijkMatInverseRotateScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseRotateScaleTranslate4d(dmat4 const m_in);

// ijkMatInverseTransposeTranslate4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
dmat4 ijkMatInverseTransposeTranslate4d(dmat4 const m_in);

// ijkMatMulTransform4*
//	Concatenate as if inputs are transformation matrices, saving a few 
//	operations over full 4x4 product.
//		param m_lh: left-hand input matrix
//		param m_rh: right-hand input matrix
//		return: transform product
dmat4 ijkMatMulTransform4d(dmat4 const m_lh, dmat4 const m_rh);

// ijkMatMulVecTransform4*v3
//	Multiply 3D vector by transformation matrix, saving a few operations.
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: transformed input
dvec3 ijkMatMulVecTransform4dv3(dmat4 const m_lh, dvec3 const v_rh);

// ijkMatMulVecTransform4*v4
//	Multiply 4D vector by transformation matrix, saving a few operations.
//		param m_lh: left-hand input matrix
//		param v_rh: right-hand input vector
//		return: transformed input
dvec4 ijkMatMulVecTransform4dv4(dmat4 const m_lh, dvec4 const v_rh);

// ijkMatLookAt4*
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
dmat4 ijkMatLookAt4d(dmat4* const m_inv_out_opt, dvec3 const origin, dvec3 const target, dvec3 const calibUnit, ijkTransformBasis const calibAxis);

// ijkMatProjectionPerspective4*
//	Create perspective projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: perspective projection matrix
dmat4 ijkMatProjectionPerspective4d(dmat4* const m_inv_out_opt, double const fovyDeg, double const aspect, double const nearDist, double const farDist);

// ijkMatProjectionParallel4*
//	Create parallel/orthographic projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: parallel projection matrix
dmat4 ijkMatProjectionParallel4d(dmat4* const m_inv_out_opt, double const fovyDeg, double const aspect, double const nearDist, double const farDist);

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
dmat4 ijkMatProjectionPerspectivePlanes4d(dmat4* const m_inv_out_opt, double const leftDist, double const rightDist, double const bottomDist, double const topDist, double const nearDist, double const farDist);

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
dmat4 ijkMatProjectionParallelPlanes4d(dmat4* const m_inv_out_opt, double const leftDist, double const rightDist, double const bottomDist, double const topDist, double const nearDist, double const farDist);

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
dmat4 ijkMatProjectionStereoConversion4d(dmat4* const m_left_out, dmat4* const m_right_out, dmat4* const m_left_inv_out_opt, dmat4* const m_right_inv_out_opt, double const interocularDist, double const convergenceDist);


//-----------------------------------------------------------------------------


#include "_inl/ijkMatrix_double.inl"


#endif	// !_IJK_MATRIX_DOUBLE_H_
#endif	// _IJK_MATRIX_H_