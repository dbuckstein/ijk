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

	ijkMatrix_real.h
	Declarations for real matrix functions.
*/

#ifdef _IJK_MATRIX_H_
#ifndef _IJK_MATRIX_REAL_H_
#define _IJK_MATRIX_REAL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
	
// ijkMatInit2*m
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
//real2m ijkMatInit2rm(real2x2 m_out);
#define ijkMatInit2rm ijk_declrealfs(ijkMatInit2,m)

// ijkMatInitElems2*m
//	Initialize 2x2 matrix given elements.
//		param m_out: output matrix
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: m_out
//real2m ijkMatInitElems2rm(real2x2 m_out, real const x0, real const y0, real const x1, real const y1);
#define ijkMatInitElems2rm ijk_declrealfs(ijkMatInitElems2,m)

// ijkMatInitVecs2*m
//	Initialize 2x2 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		return: m_out
//real2m ijkMatInitVecs2rm(real2x2 m_out, real2 const c0, real2 const c1);
#define ijkMatInitVecs2rm ijk_declrealfs(ijkMatInitVecs2,m)

// ijkMatCopy2*m2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatCopy2rm2(real2x2 m_out, real2x2 const m_in);
#define ijkMatCopy2rm2 ijk_declrealfs(ijkMatCopy2,m2)

// ijkMatCopy2*m3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatCopy2rm3(real2x2 m_out, real3x3 const m_in);
#define ijkMatCopy2rm3 ijk_declrealfs(ijkMatCopy2,m3)

// ijkMatCopy2*m4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 2x2 matrix
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatCopy2rm4(real2x2 m_out, real4x4 const m_in);
#define ijkMatCopy2rm4 ijk_declrealfs(ijkMatCopy2,m4)

// ijkMatNegate2*m
//	Negate 2x2 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatNegate2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatNegate2rm ijk_declrealfs(ijkMatNegate2,m)

// ijkMatCopy2*ms
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
//real2m ijkMatCopy2rms(real2x2 m_out, real const s_diag);
#define ijkMatCopy2rms ijk_declrealfs(ijkMatCopy2,ms)

// ijkMatMul2*ms
//	Multiply 2x2 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real2m ijkMatMul2rms(real2x2 m_out, real2x2 const m_lh, real const s_rh);
#define ijkMatMul2rms ijk_declrealfs(ijkMatMul2,ms)

// ijkMatDiv2*ms
//	Divide 2x2 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real2m ijkMatDiv2rms(real2x2 m_out, real2x2 const m_lh, real const s_rh);
#define ijkMatDiv2rms ijk_declrealfs(ijkMatDiv2,ms)

// ijkMatDivSafe2*ms
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real2m ijkMatDivSafe2rms(real2x2 m_out, real2x2 const m_lh, real const s_rh);
#define ijkMatDivSafe2rms ijk_declrealfs(ijkMatDivSafe2,ms)

// ijkMatMul2*sm
//	Multiply scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatMul2rsm(real2x2 m_out, real const s_lh, real2x2 const m_rh);
#define ijkMatMul2rsm ijk_declrealfs(ijkMatMul2,sm)

// ijkMatDiv2*sm
//	Divide scalar by 2x2 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatDiv2rsm(real2x2 m_out, real const s_lh, real2x2 const m_rh);
#define ijkMatDiv2rsm ijk_declrealfs(ijkMatDiv2,sm)

// ijkMatDivSafe2*sm
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatDivSafe2rsm(real2x2 m_out, real const s_lh, real2x2 const m_rh);
#define ijkMatDivSafe2rsm ijk_declrealfs(ijkMatDivSafe2,sm)

// ijkMatAdd2*m
//	Add 2x2 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatAdd2rm(real2x2 m_out, real2x2 const m_lh, real2x2 const m_rh);
#define ijkMatAdd2rm ijk_declrealfs(ijkMatAdd2,m)

// ijkMatSub2*m
//	Subtract 2x2 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatSub2rm(real2x2 m_out, real2x2 const m_lh, real2x2 const m_rh);
#define ijkMatSub2rm ijk_declrealfs(ijkMatSub2,m)


//-----------------------------------------------------------------------------

// ijkMatInit3*m
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
//real3m ijkMatInit3rm(real3x3 m_out);
#define ijkMatInit3rm ijk_declrealfs(ijkMatInit3,m)

// ijkMatInitElems3*m
//	Initialize 3x3 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: m_out
//real3m ijkMatInitElems3rm(real3x3 m_out, real const x0, real const y0, real const z0, real const x1, real const y1, real const z1, real const x2, real const y2, real const z2);
#define ijkMatInitElems3rm ijk_declrealfs(ijkMatInitElems3,m)

// ijkMatInitVecs3*m
//	Initialize 3x3 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: m_out
//real3m ijkMatInitVecs3rm(real3x3 m_out, real3 const c0, real3 const c1, real3 const c2);
#define ijkMatInitVecs3rm ijk_declrealfs(ijkMatInitVecs3,m)

// ijkMatCopy3*m2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatCopy3rm2(real3x3 m_out, real2x2 const m_in);
#define ijkMatCopy3rm2 ijk_declrealfs(ijkMatCopy3,m2)

// ijkMatCopy3*m3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatCopy3rm3(real3x3 m_out, real3x3 const m_in);
#define ijkMatCopy3rm3 ijk_declrealfs(ijkMatCopy3,m3)

// ijkMatCopy3*m4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_out: output matrix; input's upper-left 3x3 matrix
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatCopy3rm4(real3x3 m_out, real4x4 const m_in);
#define ijkMatCopy3rm4 ijk_declrealfs(ijkMatCopy3,m4)

// ijkMatNegate3*m
//	Negate 3x3 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatNegate3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatNegate3rm ijk_declrealfs(ijkMatNegate3,m)

// ijkMatCopy3*ms
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
//real3m ijkMatCopy3rms(real3x3 m_out, real const s_diag);
#define ijkMatCopy3rms ijk_declrealfs(ijkMatCopy3,ms)

// ijkMatMul3*ms
//	Multiply 3x3 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real3m ijkMatMul3rms(real3x3 m_out, real3x3 const m_lh, real const s_rh);
#define ijkMatMul3rms ijk_declrealfs(ijkMatMul3,ms)

// ijkMatDiv3*ms
//	Divide 3x3 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real3m ijkMatDiv3rms(real3x3 m_out, real3x3 const m_lh, real const s_rh);
#define ijkMatDiv3rms ijk_declrealfs(ijkMatDiv3,ms)

// ijkMatDivSafe3*ms
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real3m ijkMatDivSafe3rms(real3x3 m_out, real3x3 const m_lh, real const s_rh);
#define ijkMatDivSafe3rms ijk_declrealfs(ijkMatDivSafe3,ms)

// ijkMatMul3*sm
//	Multiply scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatMul3rsm(real3x3 m_out, real const s_lh, real3x3 const m_rh);
#define ijkMatMul3rsm ijk_declrealfs(ijkMatMul3,sm)

// ijkMatDiv3*sm
//	Divide scalar by 3x3 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatDiv3rsm(real3x3 m_out, real const s_lh, real3x3 const m_rh);
#define ijkMatDiv3rsm ijk_declrealfs(ijkMatDiv3,sm)

// ijkMatDivSafe3*sm
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatDivSafe3rsm(real3x3 m_out, real const s_lh, real3x3 const m_rh);
#define ijkMatDivSafe3rsm ijk_declrealfs(ijkMatDivSafe3,sm)

// ijkMatAdd3*m
//	Add 3x3 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatAdd3rm(real3x3 m_out, real3x3 const m_lh, real3x3 const m_rh);
#define ijkMatAdd3rm ijk_declrealfs(ijkMatAdd3,m)

// ijkMatSub3*m
//	Subtract 3x3 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatSub3rm(real3x3 m_out, real3x3 const m_lh, real3x3 const m_rh);
#define ijkMatSub3rm ijk_declrealfs(ijkMatSub3,m)


//-----------------------------------------------------------------------------

// ijkMatInit4*m
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		param m_out: output matrix
//		return: m_out
//real4m ijkMatInit4rm(real4x4 m_out);
#define ijkMatInit4rm ijk_declrealfs(ijkMatInit4,m)

// ijkMatInitElems4*m
//	Initialize 4x4 matrix given elements.
//		param m_out: output matrix
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: m_out
//real4m ijkMatInitElems4rm(real4x4 m_out, real const x0, real const y0, real const z0, real const w0, real const x1, real const y1, real const z1, real const w1, real const x2, real const y2, real const z2, real const w2, real const x3, real const y3, real const z3, real const w3);
#define ijkMatInitElems4rm ijk_declrealfs(ijkMatInitElems4,m)

// ijkMatInitVecs4*m
//	Initialize 4x4 matrix given column vectors.
//		param m_out: output matrix
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: m_out
//real4m ijkMatInitVecs4rm(real4x4 m_out, real4 const c0, real4 const c1, real4 const c2, real4 const c3);
#define ijkMatInitVecs4rm ijk_declrealfs(ijkMatInitVecs4,m)

// ijkMatCopy4*m2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatCopy4rm2(real4x4 m_out, real2x2 const m_in);
#define ijkMatCopy4rm2 ijk_declrealfs(ijkMatCopy4,m2)

// ijkMatCopy4*m3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatCopy4rm3(real4x4 m_out, real3x3 const m_in);
#define ijkMatCopy4rm3 ijk_declrealfs(ijkMatCopy4,m3)

// ijkMatCopy4*m4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatCopy4rm4(real4x4 m_out, real4x4 const m_in);
#define ijkMatCopy4rm4 ijk_declrealfs(ijkMatCopy4,m4)

// ijkMatNegate4*m
//	Negate 4x4 matrix.
//		param m_out: output matrix
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatNegate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatNegate4rm ijk_declrealfs(ijkMatNegate4,m)

// ijkMatCopy4*ms
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param m_out: output matrix
//		param s_diag: input scalar assigned to diagonal elements
//		return: m_out
//real4m ijkMatCopy4rms(real4x4 m_out, real const s_diag);
#define ijkMatCopy4rms ijk_declrealfs(ijkMatCopy4,ms)

// ijkMatMul4*ms
//	Multiply 4x4 matrix by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real4m ijkMatMul4rms(real4x4 m_out, real4x4 const m_lh, real const s_rh);
#define ijkMatMul4rms ijk_declrealfs(ijkMatMul4,ms)

// ijkMatDiv4*ms
//	Divide 4x4 matrix elements by scalar.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real4m ijkMatDiv4rms(real4x4 m_out, real4x4 const m_lh, real const s_rh);
#define ijkMatDiv4rms ijk_declrealfs(ijkMatDiv4,ms)

// ijkMatDivSafe4*ms
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_out: output matrix
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: m_out
//real4m ijkMatDivSafe4rms(real4x4 m_out, real4x4 const m_lh, real const s_rh);
#define ijkMatDivSafe4rms ijk_declrealfs(ijkMatDivSafe4,ms)

// ijkMatMul4*sm
//	Multiply scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatMul4rsm(real4x4 m_out, real const s_lh, real4x4 const m_rh);
#define ijkMatMul4rsm ijk_declrealfs(ijkMatMul4,sm)

// ijkMatDiv4*sm
//	Divide scalar by 4x4 matrix elements.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatDiv4rsm(real4x4 m_out, real const s_lh, real4x4 const m_rh);
#define ijkMatDiv4rsm ijk_declrealfs(ijkMatDiv4,sm)

// ijkMatDivSafe4*sm
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param m_out: output matrix
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatDivSafe4rsm(real4x4 m_out, real const s_lh, real4x4 const m_rh);
#define ijkMatDivSafe4rsm ijk_declrealfs(ijkMatDivSafe4,sm)

// ijkMatAdd4*m
//	Add 4x4 matrices.
//		param m_out: output matrix, sum of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatAdd4rm(real4x4 m_out, real4x4 const m_lh, real4x4 const m_rh);
#define ijkMatAdd4rm ijk_declrealfs(ijkMatAdd4,m)

// ijkMatSub4*m
//	Subtract 4x4 matrices.
//		param m_out: output matrix, difference of inputs
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatSub4rm(real4x4 m_out, real4x4 const m_lh, real4x4 const m_rh);
#define ijkMatSub4rm ijk_declrealfs(ijkMatSub4,m)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkMatInit2*
//	Initialize 2x2 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
//rmat2 ijkMatInit2r();
#define ijkMatInit2r ijk_declrealfs(ijkMatInit2,)

// ijkMatInitElems2*
//	Initialize 2x2 matrix given elements.
//		params x0, y0: elements of first column
//		params x1, y1: elements of second column
//		return: matrix of elements
//rmat2 ijkMatInitElems2r(real const x0, real const y0, real const x1, real const y1);
#define ijkMatInitElems2r ijk_declrealfs(ijkMatInitElems2,)

// ijkMatInitVecs2*
//	Initialize 2x2 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		return: matrix of columns
//rmat2 ijkMatInitVecs2r(rvec2 const c0, rvec2 const c1);
#define ijkMatInitVecs2r ijk_declrealfs(ijkMatInitVecs2,)

// ijkMatCopy2*2
//	Copy 2x2 matrix from 2x2 matrix.
//		param m_in: input matrix
//		return: copy of input
//rmat2 ijkMatCopy2r2(rmat2 const m_in);
#define ijkMatCopy2r2 ijk_declrealfs(ijkMatCopy2,2)

// ijkMatCopy2*3
//	Copy 2x2 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
//rmat2 ijkMatCopy2r3(rmat3 const m_in);
#define ijkMatCopy2r3 ijk_declrealfs(ijkMatCopy2,3)

// ijkMatCopy2*4
//	Copy 2x2 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 2x2 matrix
//rmat2 ijkMatCopy2r4(rmat4 const m_in);
#define ijkMatCopy2r4 ijk_declrealfs(ijkMatCopy2,4)

// ijkMatNegate2*
//	Negate 2x2 matrix.
//		param m_in: input matrix
//		return: negated matrix
//rmat2 ijkMatNegate2r(rmat2 const m_in);
#define ijkMatNegate2r ijk_declrealfs(ijkMatNegate2,)

// ijkMatCopy2*s
//	Copy 2x2 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
//rmat2 ijkMatCopy2rs(real const s_diag);
#define ijkMatCopy2rs ijk_declrealfs(ijkMatCopy2,s)

// ijkMatMul2*s
//	Multiply 2x2 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
//rmat2 ijkMatMul2rs(rmat2 const m_lh, real const s_rh);
#define ijkMatMul2rs ijk_declrealfs(ijkMatMul2,s)

// ijkMatDiv2*s
//	Divide 2x2 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat2 ijkMatDiv2rs(rmat2 const m_lh, real const s_rh);
#define ijkMatDiv2rs ijk_declrealfs(ijkMatDiv2,s)

// ijkMatDivSafe2*s
//	Divide 2x2 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat2 ijkMatDivSafe2rs(rmat2 const m_lh, real const s_rh);
#define ijkMatDivSafe2rs ijk_declrealfs(ijkMatDivSafe2,s)

// ijkMatMul2s*
//	Multiply scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
//rmat2 ijkMatMul2sr(real const s_lh, rmat2 const m_rh);
#define ijkMatMul2sr ijk_declrealfs(ijkMatMul2s,)

// ijkMatDiv2s*
//	Divide scalar by 2x2 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat2 ijkMatDiv2sr(real const s_lh, rmat2 const m_rh);
#define ijkMatDiv2sr ijk_declrealfs(ijkMatDiv2s,)

// ijkMatDivSafe2s*
//	Divide scalar by 2x2 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat2 ijkMatDivSafe2sr(real const s_lh, rmat2 const m_rh);
#define ijkMatDivSafe2sr ijk_declrealfs(ijkMatDivSafe2s,)

// ijkMatAdd2*
//	Add 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
//rmat2 ijkMatAdd2r(rmat2 const m_lh, rmat2 const m_rh);
#define ijkMatAdd2r ijk_declrealfs(ijkMatAdd2,)

// ijkMatSub2*
//	Subtract 2x2 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
//rmat2 ijkMatSub2r(rmat2 const m_lh, rmat2 const m_rh);
#define ijkMatSub2r ijk_declrealfs(ijkMatSub2,)


//-----------------------------------------------------------------------------

// ijkMatInit3*
//	Initialize 3x3 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
//rmat3 ijkMatInit3r();
#define ijkMatInit3r ijk_declrealfs(ijkMatInit3,)

// ijkMatInitElems3*
//	Initialize 3x3 matrix given elements.
//		params x0, y0, z0: elements of first column
//		params x1, y1, z1: elements of second column
//		params x2, y2, z2: elements of third column
//		return: matrix of elements
//rmat3 ijkMatInitElems3r(real const x0, real const y0, real const z0, real const x1, real const y1, real const z1, real const x2, real const y2, real const z2);
#define ijkMatInitElems3r ijk_declrealfs(ijkMatInitElems3,)

// ijkMatInitVecs3*
//	Initialize 3x3 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		return: matrix of columns
//rmat3 ijkMatInitVecs3r(rvec3 const c0, rvec3 const c1, rvec3 const c2);
#define ijkMatInitVecs3r ijk_declrealfs(ijkMatInitVecs3,)

// ijkMatCopy3*2
//	Copy 3x3 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
//rmat3 ijkMatCopy3r2(rmat2 const m_in);
#define ijkMatCopy3r2 ijk_declrealfs(ijkMatCopy3,2)

// ijkMatCopy3*3
//	Copy 3x3 matrix from 3x3 matrix.
//		param m_in: input matrix
//		return: copy of input
//rmat3 ijkMatCopy3r3(rmat3 const m_in);
#define ijkMatCopy3r3 ijk_declrealfs(ijkMatCopy3,3)

// ijkMatCopy3*4
//	Copy 3x3 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input's upper-left 3x3 matrix
//rmat3 ijkMatCopy3r4(rmat4 const m_in);
#define ijkMatCopy3r4 ijk_declrealfs(ijkMatCopy3,4)

// ijkMatNegate3*
//	Negate 3x3 matrix.
//		param m_in: input matrix
//		return: negated matrix
//rmat3 ijkMatNegate3r(rmat3 const m_in);
#define ijkMatNegate3r ijk_declrealfs(ijkMatNegate3,)

// ijkMatCopy3*s
//	Copy 3x3 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
//rmat3 ijkMatCopy3rs(real const s_diag);
#define ijkMatCopy3rs ijk_declrealfs(ijkMatCopy3,s)

// ijkMatMul3*s
//	Multiply 3x3 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
//rmat3 ijkMatMul3rs(rmat3 const m_lh, real const s_rh);
#define ijkMatMul3rs ijk_declrealfs(ijkMatMul3,s)

// ijkMatDiv3*s
//	Divide 3x3 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat3 ijkMatDiv3rs(rmat3 const m_lh, real const s_rh);
#define ijkMatDiv3rs ijk_declrealfs(ijkMatDiv3,s)

// ijkMatDivSafe3*s
//	Divide 3x3 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat3 ijkMatDivSafe3rs(rmat3 const m_lh, real const s_rh);
#define ijkMatDivSafe3rs ijk_declrealfs(ijkMatDivSafe3,s)

// ijkMatMul3s*
//	Multiply scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
//rmat3 ijkMatMul3sr(real const s_lh, rmat3 const m_rh);
#define ijkMatMul3sr ijk_declrealfs(ijkMatMul3s,)

// ijkMatDiv3s*
//	Divide scalar by 3x3 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat3 ijkMatDiv3sr(real const s_lh, rmat3 const m_rh);
#define ijkMatDiv3sr ijk_declrealfs(ijkMatDiv3s,)

// ijkMatDivSafe3s*
//	Divide scalar by 3x3 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat3 ijkMatDivSafe3sr(real const s_lh, rmat3 const m_rh);
#define ijkMatDivSafe3sr ijk_declrealfs(ijkMatDivSafe3s,)

// ijkMatAdd3*
//	Add 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
//rmat3 ijkMatAdd3r(rmat3 const m_lh, rmat3 const m_rh);
#define ijkMatAdd3r ijk_declrealfs(ijkMatAdd3,)

// ijkMatSub3*
//	Subtract 3x3 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
//rmat3 ijkMatSub3r(rmat3 const m_lh, rmat3 const m_rh);
#define ijkMatSub3r ijk_declrealfs(ijkMatSub3,)


//-----------------------------------------------------------------------------

// ijkMatInit4*
//	Initialize 4x4 matrix to default (identity: ones along the diagonal).
//		return: identity matrix
//rmat4 ijkMatInit4r();
#define ijkMatInit4r ijk_declrealfs(ijkMatInit4,)

// ijkMatInitElems4*
//	Initialize 4x4 matrix given elements.
//		params x0, y0, z0, w0: elements of first column
//		params x1, y1, z1, w1: elements of second column
//		params x2, y2, z2, w2: elements of third column
//		params x3, y3, z3, w3: elements of fourth column
//		return: matrix of elements
//rmat4 ijkMatInitElems4r(real const x0, real const y0, real const z0, real const w0, real const x1, real const y1, real const z1, real const w1, real const x2, real const y2, real const z2, real const w2, real const x3, real const y3, real const z3, real const w3);
#define ijkMatInitElems4r ijk_declrealfs(ijkMatInitElems4,)

// ijkMatInitVecs4*
//	Initialize 4x4 matrix given column vectors.
//		param c0: first column vector
//		param c1: second column vector
//		param c2: third column vector
//		param c3: fourth column vector
//		return: matrix of columns
//rmat4 ijkMatInitVecs4r(rvec4 const c0, rvec4 const c1, rvec4 const c2, rvec4 const c3);
#define ijkMatInitVecs4r ijk_declrealfs(ijkMatInitVecs4,)

// ijkMatCopy4*2
//	Copy 4x4 matrix from 2x2 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
//rmat4 ijkMatCopy4r2(rmat2 const m_in);
#define ijkMatCopy4r2 ijk_declrealfs(ijkMatCopy4,2)

// ijkMatCopy4*3
//	Copy 4x4 matrix from 3x3 matrix; fill the rest as identity.
//		param m_in: input matrix
//		return: copy of input
//rmat4 ijkMatCopy4r3(rmat3 const m_in);
#define ijkMatCopy4r3 ijk_declrealfs(ijkMatCopy4,3)

// ijkMatCopy4*4
//	Copy 4x4 matrix from 4x4 matrix.
//		param m_in: input matrix
//		return: copy of input
//rmat4 ijkMatCopy4r4(rmat4 const m_in);
#define ijkMatCopy4r4 ijk_declrealfs(ijkMatCopy4,4)

// ijkMatNegate4*
//	Negate 4x4 matrix.
//		param m_in: input matrix
//		return: negated matrix
//rmat4 ijkMatNegate4r(rmat4 const m_in);
#define ijkMatNegate4r ijk_declrealfs(ijkMatNegate4,)

// ijkMatCopy4*s
//	Copy 4x4 matrix diagonal from scalar (scalar along the diagonal).
//		param s_diag: input scalar assigned to diagonal elements
//		return: diagonal matrix
//rmat4 ijkMatCopy4rs(real const s_diag);
#define ijkMatCopy4rs ijk_declrealfs(ijkMatCopy4,s)

// ijkMatMul4*s
//	Multiply 4x4 matrix by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: product
//rmat4 ijkMatMul4rs(rmat4 const m_lh, real const s_rh);
#define ijkMatMul4rs ijk_declrealfs(ijkMatMul4,s)

// ijkMatDiv4*s
//	Divide 4x4 matrix elements by scalar.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat4 ijkMatDiv4rs(rmat4 const m_lh, real const s_rh);
#define ijkMatDiv4rs ijk_declrealfs(ijkMatDiv4,s)

// ijkMatDivSafe4*s
//	Divide 4x4 matrix elements by scalar; division-by-zero safety.
//		param m_lh: left-hand matrix
//		param s_rh: right-hand scalar
//		return: quotient
//rmat4 ijkMatDivSafe4rs(rmat4 const m_lh, real const s_rh);
#define ijkMatDivSafe4rs ijk_declrealfs(ijkMatDivSafe4,s)

// ijkMatMul4s*
//	Multiply scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise product
//rmat4 ijkMatMul4sr(real const s_lh, rmat4 const m_rh);
#define ijkMatMul4sr ijk_declrealfs(ijkMatMul4s,)

// ijkMatDiv4s*
//	Divide scalar by 4x4 matrix elements.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat4 ijkMatDiv4sr(real const s_lh, rmat4 const m_rh);
#define ijkMatDiv4sr ijk_declrealfs(ijkMatDiv4s,)

// ijkMatDivSafe4s*
//	Divide scalar by 4x4 matrix elements; division-by-zero safety.
//		param s_lh: left-hand scalar
//		param m_rh: right-hand matrix
//		return: component-wise quotient
//rmat4 ijkMatDivSafe4sr(real const s_lh, rmat4 const m_rh);
#define ijkMatDivSafe4sr ijk_declrealfs(ijkMatDivSafe4s,)

// ijkMatAdd4*
//	Add 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: sum of inputs
//rmat4 ijkMatAdd4r(rmat4 const m_lh, rmat4 const m_rh);
#define ijkMatAdd4r ijk_declrealfs(ijkMatAdd4,)

// ijkMatSub4*
//	Subtract 4x4 matrices.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: difference of inputs
//rmat4 ijkMatSub4r(rmat4 const m_lh, rmat4 const m_rh);
#define ijkMatSub4r ijk_declrealfs(ijkMatSub4,)


//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*m
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant2rm(real2x2 const m_in);
#define ijkMatDeterminant2rm ijk_declrealfs(ijkMatDeterminant2,m)

// ijkMatDeterminantInv2*m
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv2rm(real2x2 const m_in);
#define ijkMatDeterminantInv2rm ijk_declrealfs(ijkMatDeterminantInv2,m)

// ijkMatDeterminantInvSafe2*m
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe2rm(real2x2 const m_in);
#define ijkMatDeterminantInvSafe2rm ijk_declrealfs(ijkMatDeterminantInvSafe2,m)

// ijkMatMulRowVec2*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec2rmv(real2x2 const m_in, real2 const v_in, index const row);
#define ijkMatMulRowVec2rmv ijk_declrealfs(ijkMatMulRowVec2,mv)

// ijkMatGetRow2*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
//realv ijkMatGetRow2rm(real2 v_out, real2x2 const m_in, index const row);
#define ijkMatGetRow2rm ijk_declrealfs(ijkMatGetRow2,m)

// ijkMatTranspose2*m
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatTranspose2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatTranspose2rm ijk_declrealfs(ijkMatTranspose2,m)

// ijkMatTransposeMul2*ms
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
//real2m ijkMatTransposeMul2rms(real2x2 m_out, real2x2 const m_in, real const s);
#define ijkMatTransposeMul2rms ijk_declrealfs(ijkMatTransposeMul2,ms)

// ijkMatInverse2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverse2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverse2rm ijk_declrealfs(ijkMatInverse2,m)

// ijkMatInverseSafe2*m
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverseSafe2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverseSafe2rm ijk_declrealfs(ijkMatInverseSafe2,m)

// ijkMatMulVec2*mv
//	Multiply 2D vector by 2x2 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
//realv ijkMatMulVec2rmv(real2 v_out, real2x2 const m_lh, real2 const v_rh);
#define ijkMatMulVec2rmv ijk_declrealfs(ijkMatMulVec2,mv)

// ijkMatMul2*m
//	Multiply 2x2 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatMul2rm(real2x2 m_out, real2x2 const m_lh, real2x2 const m_rh);
#define ijkMatMul2rm ijk_declrealfs(ijkMatMul2,m)

// ijkMatDiv2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatDiv2rm(real2x2 m_out, real2x2 const m_lh, real2x2 const m_rh);
#define ijkMatDiv2rm ijk_declrealfs(ijkMatDiv2,m)

// ijkMatDivSafe2*m
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real2m ijkMatDivSafe2rm(real2x2 m_out, real2x2 const m_lh, real2x2 const m_rh);
#define ijkMatDivSafe2rm ijk_declrealfs(ijkMatDivSafe2,m)

// ijkMatRotate2*m
//	Make 2D rotation matrix.
//		param m_out: output matrix, rotation
//		param angle_degrees: input angle in degrees
//		return: m_out
//real2m ijkMatRotate2rm(real2x2 m_out, real const angle_degrees);
#define ijkMatRotate2rm ijk_declrealfs(ijkMatRotate2,m)

// ijkMatScale2*m
//	Make 2D scale matrix.
//		param m_out: output matrix, scale
//		params sx, sy: scales on each dimension
//		return: m_out
//real2m ijkMatScale2rm(real2x2 m_out, real const sx, real const sy);
#define ijkMatScale2rm ijk_declrealfs(ijkMatScale2,m)

// ijkMatRotateScale2*m
//	Make 2D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: m_out
//real2m ijkMatRotateScale2rm(real2x2 m_out, real const angle_degrees, real const sx, real const sy);
#define ijkMatRotateScale2rm ijk_declrealfs(ijkMatRotateScale2,m)

// ijkMatGetRotate2*m
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//real2km ijkMatGetRotate2rm(real2x2 const m_in, real* const angle_degrees_out);
#define ijkMatGetRotate2rm ijk_declrealfs(ijkMatGetRotate2,m)

// ijkMatGetScale2*m
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
//real2km ijkMatGetScale2rm(real2x2 const m_in, real* const sx_out, real* const sy_out);
#define ijkMatGetScale2rm ijk_declrealfs(ijkMatGetScale2,m)

// ijkMatGetRotateScale2*m
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
//real2km ijkMatGetRotateScale2rm(real2x2 const m_in, real* const angle_degrees_out, real* const sx_out, real* const sy_out);
#define ijkMatGetRotateScale2rm ijk_declrealfs(ijkMatGetRotateScale2,m)

// ijkMatInverseRotate2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverseRotate2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverseRotate2rm ijk_declrealfs(ijkMatInverseRotate2,m)

// ijkMatInverseScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverseScale2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverseScale2rm ijk_declrealfs(ijkMatInverseScale2,m)

// ijkMatInverseRotateScale2*m
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverseRotateScale2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverseRotateScale2rm ijk_declrealfs(ijkMatInverseRotateScale2,m)

// ijkMatInverseTranspose2*m
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
//real2m ijkMatInverseTranspose2rm(real2x2 m_out, real2x2 const m_in);
#define ijkMatInverseTranspose2rm ijk_declrealfs(ijkMatInverseTranspose2,m)


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*m
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant3rm(real3x3 const m_in);
#define ijkMatDeterminant3rm ijk_declrealfs(ijkMatDeterminant3,m)

// ijkMatDeterminantInv3*m
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv3rm(real3x3 const m_in);
#define ijkMatDeterminantInv3rm ijk_declrealfs(ijkMatDeterminantInv3,m)

// ijkMatDeterminantInvSafe3*m
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe3rm(real3x3 const m_in);
#define ijkMatDeterminantInvSafe3rm ijk_declrealfs(ijkMatDeterminantInvSafe3,m)

// ijkMatMulRowVec3*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec3rmv(real3x3 const m_in, real3 const v_in, index const row);
#define ijkMatMulRowVec3rmv ijk_declrealfs(ijkMatMulRowVec3,mv)

// ijkMatGetRow3*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
//realv ijkMatGetRow3rm(real3 v_out, real3x3 const m_in, index const row);
#define ijkMatGetRow3rm ijk_declrealfs(ijkMatGetRow3,m)

// ijkMatTranspose3*m
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatTranspose3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatTranspose3rm ijk_declrealfs(ijkMatTranspose3,m)

// ijkMatTransposeMul3*ms
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
//real3m ijkMatTransposeMul3rms(real3x3 m_out, real3x3 const m_in, real const s);
#define ijkMatTransposeMul3rms ijk_declrealfs(ijkMatTransposeMul3,ms)

// ijkMatInverse3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverse3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverse3rm ijk_declrealfs(ijkMatInverse3,m)

// ijkMatInverseSafe3*m
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverseSafe3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverseSafe3rm ijk_declrealfs(ijkMatInverseSafe3,m)

// ijkMatMulVec3*mv
//	Multiply 3D vector by 3x3 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
//realv ijkMatMulVec3rmv(real3 v_out, real3x3 const m_lh, real3 const v_rh);
#define ijkMatMulVec3rmv ijk_declrealfs(ijkMatMulVec3,mv)

// ijkMatMul3*m
//	Multiply 3x3 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatMul3rm(real3x3 m_out, real3x3 const m_lh, real3x3 const m_rh);
#define ijkMatMul3rm ijk_declrealfs(ijkMatMul3,m)

// ijkMatDiv3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatDiv3rm(real3x3 m_out, real3x3 const m_lh, real3x3 const m_rh);
#define ijkMatDiv3rm ijk_declrealfs(ijkMatDiv3,m)

// ijkMatDivSafe3*m
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real3m ijkMatDivSafe3rm(real3x3 m_out, real3x3 const m_lh, real3x3 const m_rh);
#define ijkMatDivSafe3rm ijk_declrealfs(ijkMatDivSafe3,m)

// ijkMatRotateXYZ3*m
//	Make 3D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateXYZ3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateXYZ3rm ijk_declrealfs(ijkMatRotateXYZ3,m)

// ijkMatRotateYZX3*m
//	Make 3D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateYZX3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateYZX3rm ijk_declrealfs(ijkMatRotateYZX3,m)

// ijkMatRotateZXY3*m
//	Make 3D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateZXY3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateZXY3rm ijk_declrealfs(ijkMatRotateZXY3,m)

// ijkMatRotateYXZ3*m
//	Make 3D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateYXZ3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateYXZ3rm ijk_declrealfs(ijkMatRotateYXZ3,m)

// ijkMatRotateXZY3*m
//	Make 3D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateXZY3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateXZY3rm ijk_declrealfs(ijkMatRotateXZY3,m)

// ijkMatRotateZYX3*m
//	Make 3D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real3m ijkMatRotateZYX3rm(real3x3 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateZYX3rm ijk_declrealfs(ijkMatRotateZYX3,m)

// ijkMatGetRotateXYZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateXYZ3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateXYZ3rm ijk_declrealfs(ijkMatGetRotateXYZ3,m)

// ijkMatGetRotateYZX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateYZX3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateYZX3rm ijk_declrealfs(ijkMatGetRotateYZX3,m)

// ijkMatGetRotateZXY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateZXY3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateZXY3rm ijk_declrealfs(ijkMatGetRotateZXY3,m)

// ijkMatGetRotateYXZ3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateYXZ3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateYXZ3rm ijk_declrealfs(ijkMatGetRotateYXZ3,m)

// ijkMatGetRotateXZY3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateXZY3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateXZY3rm ijk_declrealfs(ijkMatGetRotateXZY3,m)

// ijkMatGetRotateZYX3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotateZYX3rm(real3x3 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateZYX3rm ijk_declrealfs(ijkMatGetRotateZYX3,m)

// ijkMatRotate3*m
//	Make 3D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_out
//real3m ijkMatRotate3rm(real3x3 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ);
#define ijkMatRotate3rm ijk_declrealfs(ijkMatRotate3,m)

// ijkMatScale3*m
//	Make 3D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
//real3m ijkMatScale3rm(real3x3 m_out, real3 const scale);
#define ijkMatScale3rm ijk_declrealfs(ijkMatScale3,m)

// ijkMatRotateScale3*m
//	Make 3D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
//real3m ijkMatRotateScale3rm(real3x3 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real3 const scale);
#define ijkMatRotateScale3rm ijk_declrealfs(ijkMatRotateScale3,m)

// ijkMatGetRotate3*m
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real3km ijkMatGetRotate3rm(real3x3 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out);
#define ijkMatGetRotate3rm ijk_declrealfs(ijkMatGetRotate3,m)

// ijkMatGetScale3*m
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
//real3km ijkMatGetScale3rm(real3x3 const m_in, real3 scale_out);
#define ijkMatGetScale3rm ijk_declrealfs(ijkMatGetScale3,m)

// ijkMatGetRotateScale3*m
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
//real3km ijkMatGetRotateScale3rm(real3x3 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 scale_out);
#define ijkMatGetRotateScale3rm ijk_declrealfs(ijkMatGetRotateScale3,m)

// ijkMatInverseRotate3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverseRotate3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverseRotate3rm ijk_declrealfs(ijkMatInverseRotate3,m)

// ijkMatInverseScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverseScale3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverseScale3rm ijk_declrealfs(ijkMatInverseScale3,m)

// ijkMatInverseRotateScale3*m
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverseRotateScale3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverseRotateScale3rm ijk_declrealfs(ijkMatInverseRotateScale3,m)

// ijkMatInverseTranspose3*m
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
//real3m ijkMatInverseTranspose3rm(real3x3 m_out, real3x3 const m_in);
#define ijkMatInverseTranspose3rm ijk_declrealfs(ijkMatInverseTranspose3,m)

// ijkMatRotateAxisAngle3*m
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
//real3m ijkMatRotateAxisAngle3rm(real3x3 m_out, real3 const axis_unit, real const angle_degrees);
#define ijkMatRotateAxisAngle3rm ijk_declrealfs(ijkMatRotateAxisAngle3,m)

// ijkMatRotateAxisAngleScale3*m
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
//real3m ijkMatRotateAxisAngleScale3rm(real3x3 m_out, real3 const axis_unit, real const angle_degrees, real3 const scale);
#define ijkMatRotateAxisAngleScale3rm ijk_declrealfs(ijkMatRotateAxisAngleScale3,m)

// ijkMatGetRotateAxisAngle3*m
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//real3km ijkMatGetRotateAxisAngle3rm(real3x3 const m_in, real3 axis_unit_out, real* const angle_degrees_out);
#define ijkMatGetRotateAxisAngle3rm ijk_declrealfs(ijkMatGetRotateAxisAngle3,m)

// ijkMatGetRotateAxisAngleScale3*m
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
//real3km ijkMatGetRotateAxisAngleScale3rm(real3x3 const m_in, real3 axis_unit_out, real* const angle_degrees_out, real3 scale_out);
#define ijkMatGetRotateAxisAngleScale3rm ijk_declrealfs(ijkMatGetRotateAxisAngleScale3,m)

// ijkMatLookAt3*m
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
//real3m ijkMatLookAt3rm(real3x3 m_out, real3x3 m_inv_out_opt, real3 const origin, real3 const target, real3 const calibUnit, ijkTransformBasis const calibAxis);
#define ijkMatLookAt3rm ijk_declrealfs(ijkMatLookAt3,m)


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*m
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant4rm(real4x4 const m_in);
#define ijkMatDeterminant4rm ijk_declrealfs(ijkMatDeterminant4,m)

// ijkMatDeterminantInv4*m
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv4rm(real4x4 const m_in);
#define ijkMatDeterminantInv4rm ijk_declrealfs(ijkMatDeterminantInv4,m)

// ijkMatDeterminantInvSafe4*m
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe4rm(real4x4 const m_in);
#define ijkMatDeterminantInvSafe4rm ijk_declrealfs(ijkMatDeterminantInvSafe4,m)

// ijkMatMulRowVec4*mv
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec4rmv(real4x4 const m_in, real4 const v_in, index const row);
#define ijkMatMulRowVec4rmv ijk_declrealfs(ijkMatMulRowVec4,mv)

// ijkMatGetRow4*m
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: v_out
//realv ijkMatGetRow4rm(real4 v_out, real4x4 const m_in, index const row);
#define ijkMatGetRow4rm ijk_declrealfs(ijkMatGetRow4,m)

// ijkMatTranspose4*m
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_out: output matrix, transpose
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatTranspose4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatTranspose4rm ijk_declrealfs(ijkMatTranspose4,m)

// ijkMatTransposeMul4*ms
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_out: output matrix, scaled transpose
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: m_out
//real4m ijkMatTransposeMul4rms(real4x4 m_out, real4x4 const m_in, real const s);
#define ijkMatTransposeMul4rms ijk_declrealfs(ijkMatTransposeMul4,ms)

// ijkMatInverse4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverse4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverse4rm ijk_declrealfs(ijkMatInverse4,m)

// ijkMatInverseSafe4*m
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_out: output matrix, inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseSafe4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseSafe4rm ijk_declrealfs(ijkMatInverseSafe4,m)

// ijkMatMulVec4*mv
//	Multiply 4D vector by 4x4 matrix.
//		param v_out: output vector, product
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: m_out
//realv ijkMatMulVec4rmv(real4 v_out, real4x4 const m_lh, real4 const v_rh);
#define ijkMatMulVec4rmv ijk_declrealfs(ijkMatMulVec4,mv)

// ijkMatMul4*m
//	Multiply 4x4 matrices (non-commutative).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatMul4rm(real4x4 m_out, real4x4 const m_lh, real4x4 const m_rh);
#define ijkMatMul4rm ijk_declrealfs(ijkMatMul4,m)

// ijkMatDiv4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatDiv4rm(real4x4 m_out, real4x4 const m_lh, real4x4 const m_rh);
#define ijkMatDiv4rm ijk_declrealfs(ijkMatDiv4,m)

// ijkMatDivSafe4*m
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_out: output matrix, quotient
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: m_out
//real4m ijkMatDivSafe4rm(real4x4 m_out, real4x4 const m_lh, real4x4 const m_rh);
#define ijkMatDivSafe4rm ijk_declrealfs(ijkMatDivSafe4,m)

// ijkMatRotateXYZ4*m
//	Make 4D rotation matrix with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateXYZ4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateXYZ4rm ijk_declrealfs(ijkMatRotateXYZ4,m)

// ijkMatRotateYZX4*m
//	Make 4D rotation matrix with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateYZX4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateYZX4rm ijk_declrealfs(ijkMatRotateYZX4,m)

// ijkMatRotateZXY4*m
//	Make 4D rotation matrix with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateZXY4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateZXY4rm ijk_declrealfs(ijkMatRotateZXY4,m)

// ijkMatRotateYXZ4*m
//	Make 4D rotation matrix with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateYXZ4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateYXZ4rm ijk_declrealfs(ijkMatRotateYXZ4,m)

// ijkMatRotateXZY4*m
//	Make 4D rotation matrix with Euler angles in written order XZY, meaning 
//	the order of operations is Y then Z then X.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateXZY4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateXZY4rm ijk_declrealfs(ijkMatRotateXZY4,m)

// ijkMatRotateZYX4*m
//	Make 4D rotation matrix with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param m_out: output matrix, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: m_out
//real4m ijkMatRotateZYX4rm(real4x4 m_out, real3 const rotateDegXYZ);
#define ijkMatRotateZYX4rm ijk_declrealfs(ijkMatRotateZYX4,m)

// ijkMatGetRotateXYZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateXYZ4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateXYZ4rm ijk_declrealfs(ijkMatGetRotateXYZ4,m)

// ijkMatGetRotateYZX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateYZX4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateYZX4rm ijk_declrealfs(ijkMatGetRotateYZX4,m)

// ijkMatGetRotateZXY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateZXY4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateZXY4rm ijk_declrealfs(ijkMatGetRotateZXY4,m)

// ijkMatGetRotateYXZ4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateYXZ4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateYXZ4rm ijk_declrealfs(ijkMatGetRotateYXZ4,m)

// ijkMatGetRotateXZY4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateXZY4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateXZY4rm ijk_declrealfs(ijkMatGetRotateXZY4,m)

// ijkMatGetRotateZYX4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotateZYX4rm(real4x4 const m_in, real3 rotateDegXYZ_out);
#define ijkMatGetRotateZYX4rm ijk_declrealfs(ijkMatGetRotateZYX4,m)

// ijkMatRotate4*m
//	Make 4D rotation matrix.
//		param m_out: output matrix, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_out
//real4m ijkMatRotate4rm(real4x4 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ);
#define ijkMatRotate4rm ijk_declrealfs(ijkMatRotate4,m)

// ijkMatScale4*m
//	Make 4D scale matrix.
//		param m_out: output matrix, scale
//		param scale: scales on each dimension
//		return: m_out
//real4m ijkMatScale4rm(real4x4 m_out, real3 const scale);
#define ijkMatScale4rm ijk_declrealfs(ijkMatScale4,m)

// ijkMatRotateScale4*m
//	Make 4D rotation-scale matrix.
//		param m_out: output matrix, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: m_out
//real4m ijkMatRotateScale4rm(real4x4 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real3 const scale);
#define ijkMatRotateScale4rm ijk_declrealfs(ijkMatRotateScale4,m)

// ijkMatGetRotate4*m
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//real4km ijkMatGetRotate4rm(real4x4 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out);
#define ijkMatGetRotate4rm ijk_declrealfs(ijkMatGetRotate4,m)

// ijkMatGetScale4*m
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
//real4km ijkMatGetScale4rm(real4x4 const m_in, real3 scale_out);
#define ijkMatGetScale4rm ijk_declrealfs(ijkMatGetScale4,m)

// ijkMatGetRotateScale4*m
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
//real4km ijkMatGetRotateScale4rm(real4x4 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 scale_out);
#define ijkMatGetRotateScale4rm ijk_declrealfs(ijkMatGetRotateScale4,m)

// ijkMatInverseRotate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseRotate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseRotate4rm ijk_declrealfs(ijkMatInverseRotate4,m)

// ijkMatInverseScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseScale4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseScale4rm ijk_declrealfs(ijkMatInverseScale4,m)

// ijkMatInverseRotateScale4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseRotateScale4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseRotateScale4rm ijk_declrealfs(ijkMatInverseRotateScale4,m)

// ijkMatInverseTranspose4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseTranspose4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseTranspose4rm ijk_declrealfs(ijkMatInverseTranspose4,m)

// ijkMatRotateAxisAngle4*m
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param m_out: output matrix, rotation
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: m_out
//real4m ijkMatRotateAxisAngle4rm(real4x4 m_out, real3 const axis_unit, real const angle_degrees);
#define ijkMatRotateAxisAngle4rm ijk_declrealfs(ijkMatRotateAxisAngle4,m)

// ijkMatRotateAxisAngleScale4*m
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param m_out: output matrix, rotation-scale
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: m_out
//real4m ijkMatRotateAxisAngleScale4rm(real4x4 m_out, real3 const axis_unit, real const angle_degrees, real3 const scale);
#define ijkMatRotateAxisAngleScale4rm ijk_declrealfs(ijkMatRotateAxisAngleScale4,m)

// ijkMatGetRotateAxisAngle4*m
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//real4km ijkMatGetRotateAxisAngle4rm(real4x4 const m_in, real3 axis_unit_out, real* const angle_degrees_out);
#define ijkMatGetRotateAxisAngle4rm ijk_declrealfs(ijkMatGetRotateAxisAngle4,m)

// ijkMatGetRotateAxisAngleScale4*m
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
//real4km ijkMatGetRotateAxisAngleScale4rm(real4x4 const m_in, real3 axis_unit_out, real* const angle_degrees_out, real3 scale_out);
#define ijkMatGetRotateAxisAngleScale4rm ijk_declrealfs(ijkMatGetRotateAxisAngleScale4,m)

// ijkMatTranslate4*m
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, translation
//		param translate: translation offset vector
//		return: m_out
//real4m ijkMatTranslate4rm(real4x4 m_out, real3 const translate);
#define ijkMatTranslate4rm ijk_declrealfs(ijkMatTranslate4,m)

// ijkMatRotateTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: m_out
//real4m ijkMatRotateTranslate4rm(real4x4 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real3 const translate);
#define ijkMatRotateTranslate4rm ijk_declrealfs(ijkMatRotateTranslate4,m)

// ijkMatScaleTranslate4*m
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, scale-translate
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
//real4m ijkMatScaleTranslate4rm(real4x4 m_out, real3 const scale, real3 const translate);
#define ijkMatScaleTranslate4rm ijk_declrealfs(ijkMatScaleTranslate4,m)

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
//real4m ijkMatRotateScaleTranslate4rm(real4x4 m_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real3 const scale, real3 const translate);
#define ijkMatRotateScaleTranslate4rm ijk_declrealfs(ijkMatRotateScaleTranslate4,m)

// ijkMatRotateAxisAngleTranslate4*m
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param m_out: output matrix, rotate-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: m_out
//real4m ijkMatRotateAxisAngleTranslate4rm(real4x4 m_out, real3 const axis_unit, real const angle_degrees, real3 const translate);
#define ijkMatRotateAxisAngleTranslate4rm ijk_declrealfs(ijkMatRotateAxisAngleTranslate4,m)

// ijkMatRotateAxisAngleScaleTranslate4*m
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param m_out: output matrix, rotate-scale-translate
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: m_out
//real4m ijkMatRotateAxisAngleScaleTranslate4rm(real4x4 m_out, real3 const axis_unit, real const angle_degrees, real3 const scale, real3 const translate);
#define ijkMatRotateAxisAngleScaleTranslate4rm ijk_declrealfs(ijkMatRotateAxisAngleScaleTranslate4,m)

// ijkMatGetTranslate4*m
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
//real4km ijkMatGetTranslate4rm(real4x4 const m_in, real3 translate_out);
#define ijkMatGetTranslate4rm ijk_declrealfs(ijkMatGetTranslate4,m)

// ijkMatGetRotateTranslate4*m
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
//real4km ijkMatGetRotateTranslate4rm(real4x4 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 translate_out);
#define ijkMatGetRotateTranslate4rm ijk_declrealfs(ijkMatGetRotateTranslate4,m)

// ijkMatGetScaleTranslate4*m
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
//real4km ijkMatGetScaleTranslate4rm(real4x4 const m_in, real3 scale_out, real3 translate_out);
#define ijkMatGetScaleTranslate4rm ijk_declrealfs(ijkMatGetScaleTranslate4,m)

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
//real4km ijkMatGetRotateScaleTranslate4rm(real4x4 const m_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 scale_out, real3 translate_out);
#define ijkMatGetRotateScaleTranslate4rm ijk_declrealfs(ijkMatGetRotateScaleTranslate4,m)

// ijkMatGetRotateAxisAngleTranslate4*m
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
//real4km ijkMatGetRotateAxisAngleTranslate4rm(real4x4 const m_in, real3 axis_unit_out, real* const angle_degrees_out, real3 translate_out);
#define ijkMatGetRotateAxisAngleTranslate4rm ijk_declrealfs(ijkMatGetRotateAxisAngleTranslate4,m)

// ijkMatGetRotateAxisAngleScaleTranslate4*m
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
//real4km ijkMatGetRotateAxisAngleScaleTranslate4rm(real4x4 const m_in, real3 axis_unit_out, real* const angle_degrees_out, real3 scale_out, real3 translate_out);
#define ijkMatGetRotateAxisAngleScaleTranslate4rm ijk_declrealfs(ijkMatGetRotateAxisAngleScaleTranslate4,m)

// ijkMatInverseRotateTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseRotateTranslate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseRotateTranslate4rm ijk_declrealfs(ijkMatInverseRotateTranslate4,m)

// ijkMatInverseScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseScaleTranslate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseScaleTranslate4rm ijk_declrealfs(ijkMatInverseScaleTranslate4,m)

// ijkMatInverseRotateScaleTranslate4*m
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseRotateScaleTranslate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseRotateScaleTranslate4rm ijk_declrealfs(ijkMatInverseRotateScaleTranslate4,m)

// ijkMatInverseTransposeTranslate4*m
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_out: output matrix, quick inverse-transpose
//		param m_in: input matrix
//		return: m_out
//real4m ijkMatInverseTransposeTranslate4rm(real4x4 m_out, real4x4 const m_in);
#define ijkMatInverseTransposeTranslate4rm ijk_declrealfs(ijkMatInverseTransposeTranslate4,m)

// ijkMatLookAt4*m
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_out: output matrix, look-at
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: m_out
//real4m ijkMatLookAt4rm(real4x4 m_out, real4x4 m_inv_out_opt, real3 const origin, real3 const target, real3 const calibUnit, ijkTransformBasis const calibAxis);
#define ijkMatLookAt4rm ijk_declrealfs(ijkMatLookAt4,m)

// ijkMatProjectionPerspective4*m
//	Create perspective projection matrix.
//		param m_out: output matrix, perspective projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
//real4m ijkMatProjectionPerspective4rm(real4x4 m_out, real4x4 m_inv_out_opt, real const fovyDeg, real const aspect, real const nearDist, real const farDist);
#define ijkMatProjectionPerspective4rm ijk_declrealfs(ijkMatProjectionPerspective4,m)

// ijkMatProjectionParallel4*m
//	Create parallel/orthographic projection matrix.
//		param m_out: output matrix, parallel projection
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: m_out
//real4m ijkMatProjectionParallel4rm(real4x4 m_out, real4x4 m_inv_out_opt, real const fovyDeg, real const aspect, real const nearDist, real const farDist);
#define ijkMatProjectionParallel4rm ijk_declrealfs(ijkMatProjectionParallel4,m)

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
//real4m ijkMatProjectionPerspectivePlanes4rm(real4x4 m_out, real4x4 m_inv_out_opt, real const leftDist, real const rightDist, real const bottomDist, real const topDist, real const nearDist, real const farDist);
#define ijkMatProjectionPerspectivePlanes4rm ijk_declrealfs(ijkMatProjectionPerspectivePlanes4,m)

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
//real4m ijkMatProjectionParallelPlanes4rm(real4x4 m_out, real4x4 m_inv_out_opt, real const leftDist, real const rightDist, real const bottomDist, real const topDist, real const nearDist, real const farDist);
#define ijkMatProjectionParallelPlanes4rm ijk_declrealfs(ijkMatProjectionParallelPlanes4,m)

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
//real4m ijkMatProjectionStereoConversion4rm(real4x4 m_left_out, real4x4 m_right_out, real4x4 m_left_inv_out_opt, real4x4 m_right_inv_out_opt, real const interocularDist, real const convergenceDist);
#define ijkMatProjectionStereoConversion4rm ijk_declrealfs(ijkMatProjectionStereoConversion4,m)


//-----------------------------------------------------------------------------

	
#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkMatDeterminant2*
//	Calculate determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant2r(rmat2 const m_in);
#define ijkMatDeterminant2r ijk_declrealfs(ijkMatDeterminant2,)

// ijkMatDeterminantInv2*
//	Calculate inverse determinant of 2x2 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv2r(rmat2 const m_in);
#define ijkMatDeterminantInv2r ijk_declrealfs(ijkMatDeterminantInv2,)

// ijkMatDeterminantInvSafe2*
//	Calculate inverse determinant of 2x2 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe2r(rmat2 const m_in);
#define ijkMatDeterminantInvSafe2r ijk_declrealfs(ijkMatDeterminantInvSafe2,)

// ijkMatMulRowVec2*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec2r(rmat2 const m_in, rvec2 const v_in, index const row);
#define ijkMatMulRowVec2r ijk_declrealfs(ijkMatMulRowVec2,)

// ijkMatGetRow2*
//	Get row as vector.
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
//rvec2 ijkMatGetRow2r(rmat2 const m_in, index const row);
#define ijkMatGetRow2r ijk_declrealfs(ijkMatGetRow2,)

// ijkMatTranspose2*
//	Calculate transpose of 2x2 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
//rmat2 ijkMatTranspose2r(rmat2 const m_in);
#define ijkMatTranspose2r ijk_declrealfs(ijkMatTranspose2,)

// ijkMatTransposeMul2*s
//	Calculate transpose of 2x2 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
//rmat2 ijkMatTransposeMul2rs(rmat2 const m_in, real const s);
#define ijkMatTransposeMul2rs ijk_declrealfs(ijkMatTransposeMul2,s)

// ijkMatInverse2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
//rmat2 ijkMatInverse2r(rmat2 const m_in);
#define ijkMatInverse2r ijk_declrealfs(ijkMatInverse2,)

// ijkMatInverseSafe2*
//	Calculate inverse of 2x2 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
//rmat2 ijkMatInverseSafe2r(rmat2 const m_in);
#define ijkMatInverseSafe2r ijk_declrealfs(ijkMatInverseSafe2,)

// ijkMatMulVec2*
//	Multiply 2D vector by 2x2 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
//rvec2 ijkMatMulVec2r(rmat2 const m_lh, rvec2 const v_rh);
#define ijkMatMulVec2r ijk_declrealfs(ijkMatMulVec2,)

// ijkMatMul2*
//	Multiply 2x2 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
//rmat2 ijkMatMul2r(rmat2 const m_lh, rmat2 const m_rh);
#define ijkMatMul2r ijk_declrealfs(ijkMatMul2,)

// ijkMatDiv2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse).
//		param m_out: output matrix, product
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat2 ijkMatDiv2r(rmat2 const m_lh, rmat2 const m_rh);
#define ijkMatDiv2r ijk_declrealfs(ijkMatDiv2,)

// ijkMatDivSafe2*
//	Divide 2x2 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat2 ijkMatDivSafe2r(rmat2 const m_lh, rmat2 const m_rh);
#define ijkMatDivSafe2r ijk_declrealfs(ijkMatDivSafe2,)

// ijkMatRotate2*
//	Make 2D rotation matrix.
//		param angle_degrees: input angle in degrees
//		return: rotation matrix
//rmat2 ijkMatRotate2r(real const angle_degrees);
#define ijkMatRotate2r ijk_declrealfs(ijkMatRotate2,)

// ijkMatScale2*
//	Make 2D scale matrix.
//		params sx, sy: scales on each dimension
//		return: scale matrix
//rmat2 ijkMatScale2r(real const sx, real const sy);
#define ijkMatScale2r ijk_declrealfs(ijkMatScale2,)

// ijkMatRotateScale2*
//	Make 2D rotation-scale matrix.
//		param angle_degrees: input angle in degrees
//		params sx, sy: scales on each dimension
//		return: rotation-scale matrix
//rmat2 ijkMatRotateScale2r(real const angle_degrees, real const sx, real const sy);
#define ijkMatRotateScale2r ijk_declrealfs(ijkMatRotateScale2,)

// ijkMatGetRotate2*
//	Extract rotation angle in degrees from 2D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//rmat2 ijkMatGetRotate2r(rmat2 const m_in, real* const angle_degrees_out);
#define ijkMatGetRotate2r ijk_declrealfs(ijkMatGetRotate2,)

// ijkMatGetScale2*
//	Extract scales from 2D matrix.
//		param m_in: input matrix
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
//rmat2 ijkMatGetScale2r(rmat2 const m_in, real* const sx_out, real* const sy_out);
#define ijkMatGetScale2r ijk_declrealfs(ijkMatGetScale2,)

// ijkMatGetRotateScale2*
//	Extract rotation angle in degrees and scales from 2D matrix.
//		param m_in: input matrix
//		param angle_degrees_out: pointer to angle storage
//		params sx_out, sy_out: pointers to scale storage
//		return: m_in
//rmat2 ijkMatGetRotateScale2r(rmat2 const m_in, real* const angle_degrees_out, real* const sx_out, real* const sy_out);
#define ijkMatGetRotateScale2r ijk_declrealfs(ijkMatGetRotateScale2,)

// ijkMatInverseRotate2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
//rmat2 ijkMatInverseRotate2r(rmat2 const m_in);
#define ijkMatInverseRotate2r ijk_declrealfs(ijkMatInverseRotate2,)

// ijkMatInverseScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
//rmat2 ijkMatInverseScale2r(rmat2 const m_in);
#define ijkMatInverseScale2r ijk_declrealfs(ijkMatInverseScale2,)

// ijkMatInverseRotateScale2*
//	Calculate quick transform inverse for 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
//rmat2 ijkMatInverseRotateScale2r(rmat2 const m_in);
#define ijkMatInverseRotateScale2r ijk_declrealfs(ijkMatInverseRotateScale2,)

// ijkMatInverseTranspose2*
//	Calculate quick inverse-transpose of 2D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
//rmat2 ijkMatInverseTranspose2r(rmat2 const m_in);
#define ijkMatInverseTranspose2r ijk_declrealfs(ijkMatInverseTranspose2,)


//-----------------------------------------------------------------------------

// ijkMatDeterminant3*
//	Calculate determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant3r(rmat3 const m_in);
#define ijkMatDeterminant3r ijk_declrealfs(ijkMatDeterminant3,)

// ijkMatDeterminantInv3*
//	Calculate inverse determinant of 3x3 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv3r(rmat3 const m_in);
#define ijkMatDeterminantInv3r ijk_declrealfs(ijkMatDeterminantInv3,)

// ijkMatDeterminantInvSafe3*
//	Calculate inverse determinant of 3x3 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe3r(rmat3 const m_in);
#define ijkMatDeterminantInvSafe3r ijk_declrealfs(ijkMatDeterminantInvSafe3,)

// ijkMatMulRowVec3*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec3r(rmat3 const m_in, rvec3 const v_in, index const row);
#define ijkMatMulRowVec3r ijk_declrealfs(ijkMatMulRowVec3,)

// ijkMatMulRowVec3*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
//rvec3 ijkMatGetRow3r(rmat3 const m_in, index const row);
#define ijkMatMulRowVec3r ijk_declrealfs(ijkMatMulRowVec3,)

// ijkMatTranspose3*
//	Calculate transpose of 3x3 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
//rmat3 ijkMatTranspose3r(rmat3 const m_in);
#define ijkMatTranspose3r ijk_declrealfs(ijkMatTranspose3,)

// ijkMatTransposeMul3*s
//	Calculate transpose of 3x3 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
//rmat3 ijkMatTransposeMul3rs(rmat3 const m_in, real const s);
#define ijkMatTransposeMul3rs ijk_declrealfs(ijkMatTransposeMul3,s)

// ijkMatInverse3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
//rmat3 ijkMatInverse3r(rmat3 const m_in);
#define ijkMatInverse3r ijk_declrealfs(ijkMatInverse3,)

// ijkMatInverseSafe3*
//	Calculate inverse of 3x3 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
//rmat3 ijkMatInverseSafe3r(rmat3 const m_in);
#define ijkMatInverseSafe3r ijk_declrealfs(ijkMatInverseSafe3,)

// ijkMatMulVec3*
//	Multiply 3D vector by 3x3 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
//rvec3 ijkMatMulVec3r(rmat3 const m_lh, rvec3 const v_rh);
#define ijkMatMulVec3r ijk_declrealfs(ijkMatMulVec3,)

// ijkMatMul3*
//	Multiply 3x3 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
//rmat3 ijkMatMul3r(rmat3 const m_lh, rmat3 const m_rh);
#define ijkMatMul3r ijk_declrealfs(ijkMatMul3,)

// ijkMatDiv3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat3 ijkMatDiv3r(rmat3 const m_lh, rmat3 const m_rh);
#define ijkMatDiv3r ijk_declrealfs(ijkMatDiv3,)

// ijkMatDivSafe3*
//	Divide 3x3 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat3 ijkMatDivSafe3r(rmat3 const m_lh, rmat3 const m_rh);
#define ijkMatDivSafe3r ijk_declrealfs(ijkMatDivSafe3,)

// ijkMatRotateXYZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateXYZ3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateXYZ3r ijk_declrealfs(ijkMatRotateXYZ3,)

// ijkMatRotateYZX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateYZX3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateYZX3r ijk_declrealfs(ijkMatRotateYZX3,)

// ijkMatRotateZXY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateZXY3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateZXY3r ijk_declrealfs(ijkMatRotateZXY3,)

// ijkMatRotateYXZ3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateYXZ3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateYXZ3r ijk_declrealfs(ijkMatRotateYXZ3,)

// ijkMatRotateXZY3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateXZY3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateXZY3r ijk_declrealfs(ijkMatRotateXZY3,)

// ijkMatRotateZYX3*
//	Make 3D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotateZYX3r(rvec3 const rotateDegXYZ);
#define ijkMatRotateZYX3r ijk_declrealfs(ijkMatRotateZYX3,)

// ijkMatGetRotateXYZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateXYZ3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateXYZ3r ijk_declrealfs(ijkMatGetRotateXYZ3,)

// ijkMatGetRotateYZX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateYZX3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateYZX3r ijk_declrealfs(ijkMatGetRotateYZX3,)

// ijkMatGetRotateZXY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateZXY3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateZXY3r ijk_declrealfs(ijkMatGetRotateZXY3,)

// ijkMatGetRotateYXZ3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateYXZ3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateYXZ3r ijk_declrealfs(ijkMatGetRotateYXZ3,)

// ijkMatGetRotateXZY3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateXZY3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateXZY3r ijk_declrealfs(ijkMatGetRotateXZY3,)

// ijkMatGetRotateZYX3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotateZYX3r(rmat3 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateZYX3r ijk_declrealfs(ijkMatGetRotateZYX3,)

// ijkMatRotate3*
//	Make 3D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat3 ijkMatRotate3r(ijkRotationOrder const order, rvec3 const rotateDegXYZ);
#define ijkMatRotate3r ijk_declrealfs(ijkMatRotate3,)

// ijkMatScale3*
//	Make 3D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
//rmat3 ijkMatScale3r(rvec3 const scale);
#define ijkMatScale3r ijk_declrealfs(ijkMatScale3,)

// ijkMatRotateScale3*
//	Make 3D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
//rmat3 ijkMatRotateScale3r(ijkRotationOrder const order, rvec3 const rotateDegXYZ, rvec3 const scale);
#define ijkMatRotateScale3r ijk_declrealfs(ijkMatRotateScale3,)

// ijkMatGetRotate3*
//	Extract rotation angle in degrees from 3D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat3 ijkMatGetRotate3r(rmat3 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotate3r ijk_declrealfs(ijkMatGetRotate3,)

// ijkMatGetScale3*
//	Extract scales from 3D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat3 ijkMatGetScale3r(rmat3 const m_in, rvec3* const scale_out);
#define ijkMatGetScale3r ijk_declrealfs(ijkMatGetScale3,)

// ijkMatGetRotateScale3*
//	Extract rotation angle in degrees and scales from 3D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat3 ijkMatGetRotateScale3r(rmat3 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const scale_out);
#define ijkMatGetRotateScale3r ijk_declrealfs(ijkMatGetRotateScale3,)

// ijkMatInverseRotate3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
//rmat3 ijkMatInverseRotate3r(rmat3 const m_in);
#define ijkMatInverseRotate3r ijk_declrealfs(ijkMatInverseRotate3,)

// ijkMatInverseScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
//rmat3 ijkMatInverseScale3r(rmat3 const m_in);
#define ijkMatInverseScale3r ijk_declrealfs(ijkMatInverseScale3,)

// ijkMatInverseRotateScale3*
//	Calculate quick transform inverse for 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
//rmat3 ijkMatInverseRotateScale3r(rmat3 const m_in);
#define ijkMatInverseRotateScale3r ijk_declrealfs(ijkMatInverseRotateScale3,)

// ijkMatInverseTranspose3*
//	Calculate quick inverse-transpose of 3D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
//rmat3 ijkMatInverseTranspose3r(rmat3 const m_in);
#define ijkMatInverseTranspose3r ijk_declrealfs(ijkMatInverseTranspose3,)

// ijkMatRotateAxisAngle3*
//	Create 3D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
//rmat3 ijkMatRotateAxisAngle3r(rvec3 const axis_unit, real const angle_degrees);
#define ijkMatRotateAxisAngle3r ijk_declrealfs(ijkMatRotateAxisAngle3,)

// ijkMatRotateAxisAngleScale3*
//	Create 3D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
//rmat3 ijkMatRotateAxisAngleScale3r(rvec3 const axis_unit, real const angle_degrees, rvec3 const scale);
#define ijkMatRotateAxisAngleScale3r ijk_declrealfs(ijkMatRotateAxisAngleScale3,)

// ijkMatGetRotateAxisAngle3*
//	Extract unit axis of rotation and angle in degrees from 3D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//rmat3 ijkMatGetRotateAxisAngle3r(rmat3 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out);
#define ijkMatGetRotateAxisAngle3r ijk_declrealfs(ijkMatGetRotateAxisAngle3,)

// ijkMatGetRotateAxisAngleScale3*
//	Extract unit axis of rotation, angle in degrees and scale from 3D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat3 ijkMatGetRotateAxisAngleScale3r(rmat3 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const scale_out);
#define ijkMatGetRotateAxisAngleScale3r ijk_declrealfs(ijkMatGetRotateAxisAngleScale3,)

// ijkMatLookAt3*
//	Create look-at 3D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
//rmat3 ijkMatLookAt3r(rmat3* const m_inv_out_opt, rvec3 const origin, rvec3 const target, rvec3 const calibUnit, ijkTransformBasis const calibAxis);
#define ijkMatLookAt3r ijk_declrealfs(ijkMatLookAt3,)


//-----------------------------------------------------------------------------

// ijkMatDeterminant4*
//	Calculate determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant
//real ijkMatDeterminant4r(rmat4 const m_in);
#define ijkMatDeterminant4r ijk_declrealfs(ijkMatDeterminant4,)

// ijkMatDeterminantInv4*
//	Calculate inverse determinant of 4x4 matrix.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInv4r(rmat4 const m_in);
#define ijkMatDeterminantInv4r ijk_declrealfs(ijkMatDeterminantInv4,)

// ijkMatDeterminantInvSafe4*
//	Calculate inverse determinant of 4x4 matrix; division-by-zero safety.
//		param m_in: input matrix
//		return: determinant inverse
//real ijkMatDeterminantInvSafe4r(rmat4 const m_in);
#define ijkMatDeterminantInvSafe4r ijk_declrealfs(ijkMatDeterminantInvSafe4,)

// ijkMatMulRowVec4*
//	Get row as vector.
//		param m_in: input matrix
//		param v_in: input vector
//		param row: matrix row index
//		return: product of matrix row and vector
//real ijkMatMulRowVec4r(rmat4 const m_in, rvec4 const v_in, index const row);
#define ijkMatMulRowVec4r ijk_declrealfs(ijkMatMulRowVec4,)

// ijkMatGetRow4*
//	Get row as vector.
//		param v_out: output row vector
//		param m_in: input matrix
//		param row: matrix row index
//		return: vector of row elements
//rvec4 ijkMatGetRow4r(rmat4 const m_in, index const row);
#define ijkMatGetRow4r ijk_declrealfs(ijkMatGetRow4,)

// ijkMatTranspose4*
//	Calculate transpose of 4x4 matrix (flip elements about diagonal).
//		param m_in: input matrix
//		return: transpose matrix
//rmat4 ijkMatTranspose4r(rmat4 const m_in);
#define ijkMatTranspose4r ijk_declrealfs(ijkMatTranspose4,)

// ijkMatTransposeMul4*s
//	Calculate transpose of 4x4 matrix (flip elements about diagonal), and 
//	multiply elements by scalar.
//		param m_in: input matrix
//		param s: scalar multiplier
//		return: scaled transpose
//rmat4 ijkMatTransposeMul4rs(rmat4 const m_in, real const s);
#define ijkMatTransposeMul4rs ijk_declrealfs(ijkMatTransposeMul4,s)

// ijkMatInverse4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity.
//		param m_in: input matrix
//		return: inverse matrix
//rmat4 ijkMatInverse4r(rmat4 const m_in);
#define ijkMatInverse4r ijk_declrealfs(ijkMatInverse4,)

// ijkMatInverseSafe4*
//	Calculate inverse of 4x4 matrix; matrix multiplied by inverse is identity; 
//	division-by-zero safety.
//		param m_in: input matrix
//		return: inverse matrix
//rmat4 ijkMatInverseSafe4r(rmat4 const m_in);
#define ijkMatInverseSafe4r ijk_declrealfs(ijkMatInverseSafe4,)

// ijkMatMulVec4*
//	Multiply 4D vector by 4x4 matrix.
//		param m_lh: left-hand matrix
//		param v_rh: right-hand vector
//		return: product vector
//rvec4 ijkMatMulVec4r(rmat4 const m_lh, rvec4 const v_rh);
#define ijkMatMulVec4r ijk_declrealfs(ijkMatMulVec4,)

// ijkMatMul4*
//	Multiply 4x4 matrices (non-commutative).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: product matrix
//rmat4 ijkMatMul4r(rmat4 const m_lh, rmat4 const m_rh);
#define ijkMatMul4r ijk_declrealfs(ijkMatMul4,)

// ijkMatDiv4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse).
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat4 ijkMatDiv4r(rmat4 const m_lh, rmat4 const m_rh);
#define ijkMatDiv4r ijk_declrealfs(ijkMatDiv4,)

// ijkMatDivSafe4*
//	Divide 4x4 matrices (multiply left-hand by right-hand inverse); 
//	division-by-zero safety.
//		param m_lh: left-hand matrix
//		param m_rh: right-hand matrix
//		return: quotient matrix
//rmat4 ijkMatDivSafe4r(rmat4 const m_lh, rmat4 const m_rh);
#define ijkMatDivSafe4r ijk_declrealfs(ijkMatDivSafe4,)

// ijkMatRotateXYZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateXYZ4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateXYZ4r ijk_declrealfs(ijkMatRotateXYZ4,)

// ijkMatRotateYZX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateYZX4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateYZX4r ijk_declrealfs(ijkMatRotateYZX4,)

// ijkMatRotateZXY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateZXY4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateZXY4r ijk_declrealfs(ijkMatRotateZXY4,)

// ijkMatRotateYXZ4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateYXZ4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateYXZ4r ijk_declrealfs(ijkMatRotateYXZ4,)

// ijkMatRotateXZY4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateXZY4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateXZY4r ijk_declrealfs(ijkMatRotateXZY4,)

// ijkMatRotateZYX4*
//	Make 4D rotation matrix.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotateZYX4r(rvec3 const rotateDegXYZ);
#define ijkMatRotateZYX4r ijk_declrealfs(ijkMatRotateZYX4,)

// ijkMatGetRotateXYZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateXYZ4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateXYZ4r ijk_declrealfs(ijkMatGetRotateXYZ4,)

// ijkMatGetRotateYZX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateYZX4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateYZX4r ijk_declrealfs(ijkMatGetRotateYZX4,)

// ijkMatGetRotateZXY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateZXY4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateZXY4r ijk_declrealfs(ijkMatGetRotateZXY4,)

// ijkMatGetRotateYXZ4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateYXZ4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateYXZ4r ijk_declrealfs(ijkMatGetRotateYXZ4,)

// ijkMatGetRotateXZY4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateXZY4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateXZY4r ijk_declrealfs(ijkMatGetRotateXZY4,)

// ijkMatGetRotateZYX4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotateZYX4r(rmat4 const m_in, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotateZYX4r ijk_declrealfs(ijkMatGetRotateZYX4,)

// ijkMatRotate4*
//	Make 4D rotation matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation matrix
//rmat4 ijkMatRotate4r(ijkRotationOrder const order, rvec3 const rotateDegXYZ);
#define ijkMatRotate4r ijk_declrealfs(ijkMatRotate4,)

// ijkMatScale4*
//	Make 4D scale matrix.
//		param scale: scales on each dimension
//		return: scale matrix
//rmat4 ijkMatScale4r(rvec3 const scale);
#define ijkMatScale4r ijk_declrealfs(ijkMatScale4,)

// ijkMatRotateScale4*
//	Make 4D rotation-scale matrix.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale: scales on each dimension
//		return: rotation-scale matrix
//rmat4 ijkMatRotateScale4r(ijkRotationOrder const order, rvec3 const rotateDegXYZ, rvec3 const scale);
#define ijkMatRotateScale4r ijk_declrealfs(ijkMatRotateScale4,)

// ijkMatGetRotate4*
//	Extract rotation angle in degrees from 4D rotation matrix; assumes columns 
//	are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: m_in
//rmat4 ijkMatGetRotate4r(rmat4 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out);
#define ijkMatGetRotate4r ijk_declrealfs(ijkMatGetRotate4,)

// ijkMatGetScale4*
//	Extract scales from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat4 ijkMatGetScale4r(rmat4 const m_in, rvec3* const scale_out);
#define ijkMatGetScale4r ijk_declrealfs(ijkMatGetScale4,)

// ijkMatGetRotateScale4*
//	Extract rotation angle in degrees and scales from 4D matrix.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat4 ijkMatGetRotateScale4r(rmat4 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const scale_out);
#define ijkMatGetRotateScale4r ijk_declrealfs(ijkMatGetRotateScale4,)

// ijkMatInverseRotate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only rotation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseRotate4r(rmat4 const m_in);
#define ijkMatInverseRotate4r ijk_declrealfs(ijkMatInverseRotate4,)

// ijkMatInverseScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	only scale; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseScale4r(rmat4 const m_in);
#define ijkMatInverseScale4r ijk_declrealfs(ijkMatInverseScale4,)

// ijkMatInverseRotateScale4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseRotateScale4r(rmat4 const m_in);
#define ijkMatInverseRotateScale4r ijk_declrealfs(ijkMatInverseRotateScale4,)

// ijkMatInverseTranspose4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation and scale.
//		param m_in: input matrix
//		return: quick inverse-transpose
//rmat4 ijkMatInverseTranspose4r(rmat4 const m_in);
#define ijkMatInverseTranspose4r ijk_declrealfs(ijkMatInverseTranspose4,)

// ijkMatRotateAxisAngle4*
//	Create 4D rotation matrix given unit axis of rotation and angle in degrees.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation matrix
//rmat4 ijkMatRotateAxisAngle4r(rvec3 const axis_unit, real const angle_degrees);
#define ijkMatRotateAxisAngle4r ijk_declrealfs(ijkMatRotateAxisAngle4,)

// ijkMatRotateAxisAngleScale4*
//	Create 4D rotation matrix given unit axis of rotation, angle in degrees 
//	and scales.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		return: rotation-scale matrix
//rmat4 ijkMatRotateAxisAngleScale4r(rvec3 const axis_unit, real const angle_degrees, rvec3 const scale);
#define ijkMatRotateAxisAngleScale4r ijk_declrealfs(ijkMatRotateAxisAngleScale4,)

// ijkMatGetRotateAxisAngle4*
//	Extract unit axis of rotation and angle in degrees from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		return: m_in
//rmat4 ijkMatGetRotateAxisAngle4r(rmat4 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out);
#define ijkMatGetRotateAxisAngle4r ijk_declrealfs(ijkMatGetRotateAxisAngle4,)

// ijkMatGetRotateAxisAngleScale4*
//	Extract unit axis of rotation, angle in degrees and scale from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		return: m_in
//rmat4 ijkMatGetRotateAxisAngleScale4r(rmat4 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const scale_out);
#define ijkMatGetRotateAxisAngleScale4r ijk_declrealfs(ijkMatGetRotateAxisAngleScale4,)

// ijkMatTranslate4*
//	Create 4D translation matrix, identity in upper-left, offset vector in 
//	upper-right.
//		param translate: translation offset vector
//		return: translation matrix
//rmat4 ijkMatTranslate4r(rvec3 const translate);
#define ijkMatTranslate4r ijk_declrealfs(ijkMatTranslate4,)

// ijkMatRotateTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate: translation offset vector
//		return: rotation-translation matrix
//rmat4 ijkMatRotateTranslate4r(ijkRotationOrder const order, rvec3 const rotateDegXYZ, rvec3 const translate);
#define ijkMatRotateTranslate4r ijk_declrealfs(ijkMatRotateTranslate4,)

// ijkMatScaleTranslate4*
//	Create 4D scale-translation matrix, S in upper-left, offset vector in 
//	upper-right.
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: scale-translation matrix
//rmat4 ijkMatScaleTranslate4r(rvec3 const scale, rvec3 const translate);
#define ijkMatScaleTranslate4r ijk_declrealfs(ijkMatScaleTranslate4,)

// ijkMatRotateScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
//rmat4 ijkMatRotateScaleTranslate4r(ijkRotationOrder const order, rvec3 const rotateDegXYZ, rvec3 const scale, rvec3 const translate);
#define ijkMatRotateScaleTranslate4r ijk_declrealfs(ijkMatRotateScaleTranslate4,)

// ijkMatRotateAxisAngleTranslate4*
//	Create 4D rotation-translation matrix, R in upper-left, offset vector in 
//	upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation matrix
//rmat4 ijkMatRotateAxisAngleTranslate4r(rvec3 const axis_unit, real const angle_degrees, rvec3 const translate);
#define ijkMatRotateAxisAngleTranslate4r ijk_declrealfs(ijkMatRotateAxisAngleTranslate4,)

// ijkMatRotateAxisAngleScaleTranslate4*
//	Create 4D rotation-scale-translation matrix, RS in upper-left, offset 
//	vector in upper-right.
//		param axis_unit: pre-normalized axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale: scales on each dimension
//		param translate: translation offset vector
//		return: rotation-scale-translation matrix
//rmat4 ijkMatRotateAxisAngleScaleTranslate4r(rvec3 const axis_unit, real const angle_degrees, rvec3 const scale, rvec3 const translate);
#define ijkMatRotateAxisAngleScaleTranslate4r ijk_declrealfs(ijkMatRotateAxisAngleScaleTranslate4,)

// ijkMatGetTranslate4*
//	Extract translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param translate_out: storage for translation offset
//		return: m_in
//rmat4 ijkMatGetTranslate4r(rmat4 const m_in, rvec3* const translate_out);
#define ijkMatGetTranslate4r ijk_declrealfs(ijkMatGetTranslate4,)

// ijkMatGetRotateTranslate4*
//	Extract rotation angle in degrees and translation offset vector from 4D 
//	rotation matrix; assumes columns are unit-length for optimization.
//		param m_in: input matrix
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset
//		return: m_in
//rmat4 ijkMatGetRotateTranslate4r(rmat4 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const translate_out);
#define ijkMatGetRotateTranslate4r ijk_declrealfs(ijkMatGetRotateTranslate4,)

// ijkMatGetScaleTranslate4*
//	Extract scales and translation offset vector from 4D matrix.
//		param m_in: input matrix
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
//rmat4 ijkMatGetScaleTranslate4r(rmat4 const m_in, rvec3* const scale_out, rvec3* const translate_out);
#define ijkMatGetScaleTranslate4r ijk_declrealfs(ijkMatGetScaleTranslate4,)

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
//rmat4 ijkMatGetRotateScaleTranslate4r(rmat4 const m_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const scale_out, rvec3* const translate_out);
#define ijkMatGetRotateScaleTranslate4r ijk_declrealfs(ijkMatGetRotateScaleTranslate4,)

// ijkMatGetRotateAxisAngleTranslate4*
//	Extract unit axis of rotation, angle in degrees and translation offset 
//	vector from 4D rotation matrix.
//		param m_in: input matrix, rotation
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param translate_out: storage for translation offset
//		return: m_in
//rmat4 ijkMatGetRotateAxisAngleTranslate4r(rmat4 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const translate_out);
#define ijkMatGetRotateAxisAngleTranslate4r ijk_declrealfs(ijkMatGetRotateAxisAngleTranslate4,)

// ijkMatGetRotateAxisAngleScaleTranslate4*
//	Extract unit axis of rotation, angle in degrees, scale and translation 
//	offset vector from 4D matrix.
//		param m_in: input matrix, rotation-scale
//		param axis_unit_out: output unit axis of rotation
//		param angle_degrees_out: pointer to angle storage
//		param scale_out: storage for scale amounts
//		param translate_out: storage for translation offset
//		return: m_in
//rmat4 ijkMatGetRotateAxisAngleScaleTranslate4r(rmat4 const m_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const scale_out, rvec3* const translate_out);
#define ijkMatGetRotateAxisAngleScaleTranslate4r ijk_declrealfs(ijkMatGetRotateAxisAngleScaleTranslate4,)

// ijkMatInverseRotateTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation and translation; this is simply the transpose.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseRotateTranslate4r(rmat4 const m_in);
#define ijkMatInverseRotateTranslate4r ijk_declrealfs(ijkMatInverseRotateTranslate4,)

// ijkMatInverseScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	scale and translation; this is simply the reciprocal of the diagonal elements.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseScaleTranslate4r(rmat4 const m_in);
#define ijkMatInverseScaleTranslate4r ijk_declrealfs(ijkMatInverseScaleTranslate4,)

// ijkMatInverseRotateScaleTranslate4*
//	Calculate quick transform inverse for 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseRotateScaleTranslate4r(rmat4 const m_in);
#define ijkMatInverseRotateScaleTranslate4r ijk_declrealfs(ijkMatInverseRotateScaleTranslate4,)

// ijkMatInverseTransposeTranslate4*
//	Calculate quick inverse-transpose of 4D matrix, assuming matrix encodes 
//	rotation, scale and translation.
//		param m_in: input matrix
//		return: quick inverse
//rmat4 ijkMatInverseTransposeTranslate4r(rmat4 const m_in);
#define ijkMatInverseTransposeTranslate4r ijk_declrealfs(ijkMatInverseTransposeTranslate4,)

// ijkMatLookAt4*
//	Create look-at 4D matrix given origin, target and calibration vector.
//		param m_inv_out_opt: optional output inverse matrix
//		param origin: location of origin/viewer
//		param target: location or target/control
//		param calibUnit: unit calibration vector (e.g. "local/world up")
//		param calibAxis: index of calibration vector (0, 1 or 2)
//		return: look-at matrix
//rmat4 ijkMatLookAt4r(rmat4* const m_inv_out_opt, rvec3 const origin, rvec3 const target, rvec3 const calibUnit, ijkTransformBasis const calibAxis);
#define ijkMatLookAt4r ijk_declrealfs(ijkMatLookAt4,)

// ijkMatProjectionPerspective4*
//	Create perspective projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: perspective projection matrix
//rmat4 ijkMatProjectionPerspective4r(rmat4* const m_inv_out_opt, real const fovyDeg, real const aspect, real const nearDist, real const farDist);
#define ijkMatProjectionPerspective4r ijk_declrealfs(ijkMatProjectionPerspective4,)

// ijkMatProjectionParallel4*
//	Create parallel/orthographic projection matrix.
//		param m_inv_out_opt: optional inverse matrix output
//		param fovyDeg: vertical field-of-view in degrees (greater than zero)
//		param aspect: aspect ratio of viewing plane (greater than zero)
//		param nearDist: distance to near plane (greater than zero)
//		param farDist: distance to far plane (greater than near)
//		return: parallel projection matrix
//rmat4 ijkMatProjectionParallel4r(rmat4* const m_inv_out_opt, real const fovyDeg, real const aspect, real const nearDist, real const farDist);
#define ijkMatProjectionParallel4r ijk_declrealfs(ijkMatProjectionParallel4,)

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
//rmat4 ijkMatProjectionPerspectivePlanes4r(rmat4* const m_inv_out_opt, real const leftDist, real const rightDist, real const bottomDist, real const topDist, real const nearDist, real const farDist);
#define ijkMatProjectionPerspectivePlanes4r ijk_declrealfs(ijkMatProjectionPerspectivePlanes4,)

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
//rmat4 ijkMatProjectionParallelPlanes4r(rmat4* const m_inv_out_opt, real const leftDist, real const rightDist, real const bottomDist, real const topDist, real const nearDist, real const farDist);
#define ijkMatProjectionParallelPlanes4r ijk_declrealfs(ijkMatProjectionParallelPlanes4,)

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
//rmat4 ijkMatProjectionStereoConversion4r(rmat4* const m_left_out, rmat4* const m_right_out, rmat4* const m_left_inv_out_opt, rmat4* const m_right_inv_out_opt, real const interocularDist, real const convergenceDist);
#define ijkMatProjectionStereoConversion4r ijk_declrealfs(ijkMatProjectionStereoConversion4,)


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_REAL_H_
#endif	// _IJK_MATRIX_H_