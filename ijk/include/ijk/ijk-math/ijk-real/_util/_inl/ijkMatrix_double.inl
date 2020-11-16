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

	ijkMatrix_double.inl
	Inline definitions for double matrix types.
*/

#ifdef _IJK_MATRIX_DOUBLE_H_
#ifndef _IJK_MATRIX_DOUBLE_INL_
#define _IJK_MATRIX_DOUBLE_INL_


//-----------------------------------------------------------------------------

ijk_inl double2m ijkMatInit2dm(double2x2 m_out)
{
	m_out[0][0] = m_out[1][1] = dbl_one;
	m_out[0][1] = m_out[1][0] = dbl_zero;
	return m_out;
}

ijk_inl double2m ijkMatInitElems2dm(double2x2 m_out, f64 const x0, f64 const y0, f64 const x1, f64 const y1)
{
	ijkVecInitElems2dv(m_out[0], x0, y0);
	ijkVecInitElems2dv(m_out[1], x1, y1);
	return m_out;
}

ijk_inl double2m ijkMatInitVecs2dm(double2x2 m_out, double2 const c0, double2 const c1)
{
	ijkVecCopy2dv(m_out[0], c0);
	ijkVecCopy2dv(m_out[1], c1);
	return m_out;
}

ijk_inl double2m ijkMatCopy2dm2(double2x2 m_out, double2x2 const m_in)
{
	ijkVecCopy2dv(m_out[0], m_in[0]);
	ijkVecCopy2dv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl double2m ijkMatCopy2dm3(double2x2 m_out, double3x3 const m_in)
{
	ijkVecCopy2dv(m_out[0], m_in[0]);
	ijkVecCopy2dv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl double2m ijkMatCopy2dm4(double2x2 m_out, double4x4 const m_in)
{
	ijkVecCopy2dv(m_out[0], m_in[0]);
	ijkVecCopy2dv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl double2m ijkMatCopy2dms(double2x2 m_out, f64 const s_diag)
{
	m_out[0][0] = m_out[1][1] = s_diag;
	m_out[0][1] = m_out[1][0] = dbl_zero;
	return m_out;
}

ijk_inl double2m ijkMatMul2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh)
{
	ijkVecMul2dvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul2dvs(m_out[1], m_lh[1], s_rh);
	return m_out;
}

ijk_inl double2m ijkMatDiv2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_dbl(s_rh);
	ijkVecMul2dvs(m_out[0], m_lh[0], recip);
	ijkVecMul2dvs(m_out[1], m_lh[1], recip);
	return m_out;
}

ijk_inl double2m ijkMatDivSafe2dms(double2x2 m_out, double2x2 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_safe_dbl(s_rh);
	ijkVecMul2dvs(m_out[0], m_lh[0], recip);
	ijkVecMul2dvs(m_out[1], m_lh[1], recip);
	return m_out;
}

ijk_inl double2m ijkMatMul2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh)
{
	ijkVecMul2dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul2dsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl double2m ijkMatDiv2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh)
{
	ijkVecDiv2dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv2dsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl double2m ijkMatDivSafe2dsm(double2x2 m_out, f64 const s_lh, double2x2 const m_rh)
{
	ijkVecDivSafe2dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe2dsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl double2m ijkMatAdd2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh)
{
	ijkVecAdd2dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd2dv(m_out[1], m_lh[1], m_rh[1]);
	return m_out;
}

ijk_inl double2m ijkMatSub2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh)
{
	ijkVecSub2dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub2dv(m_out[1], m_lh[1], m_rh[1]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl double3m ijkMatInit3dm(double3x3 m_out)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = dbl_one;
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = dbl_zero;
	return m_out;
}

ijk_inl double3m ijkMatInitElems3dm(double3x3 m_out, f64 const x0, f64 const y0, f64 const z0, f64 const x1, f64 const y1, f64 const z1, f64 const x2, f64 const y2, f64 const z2)
{
	ijkVecInitElems3dv(m_out[0], x0, y0, z0);
	ijkVecInitElems3dv(m_out[1], x1, y1, z1);
	ijkVecInitElems3dv(m_out[2], x2, y2, z2);
	return m_out;
}

ijk_inl double3m ijkMatInitVecs3dm(double3x3 m_out, double3 const c0, double3 const c1, double3 const c2)
{
	ijkVecCopy3dv(m_out[0], c0);
	ijkVecCopy3dv(m_out[1], c1);
	ijkVecCopy3dv(m_out[2], c2);
	return m_out;
}

ijk_inl double3m ijkMatCopy3dm2(double3x3 m_out, double2x2 const m_in)
{
	ijkVecCopy3dvz(m_out[0], m_in[0], dbl_zero);
	ijkVecCopy3dvz(m_out[1], m_in[1], dbl_zero);
	ijkVecCopy3dv(m_out[2], double3_z);
	return m_out;
}

ijk_inl double3m ijkMatCopy3dm3(double3x3 m_out, double3x3 const m_in)
{
	ijkVecCopy3dv(m_out[0], m_in[0]);
	ijkVecCopy3dv(m_out[1], m_in[1]);
	ijkVecCopy3dv(m_out[2], m_in[2]);
	return m_out;
}

ijk_inl double3m ijkMatCopy3dm4(double3x3 m_out, double4x4 const m_in)
{
	ijkVecCopy3dv(m_out[0], m_in[0]);
	ijkVecCopy3dv(m_out[1], m_in[1]);
	ijkVecCopy3dv(m_out[2], m_in[2]);
	return m_out;
}

ijk_inl double3m ijkMatCopy3dms(double3x3 m_out, f64 const s_diag)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = s_diag;
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = dbl_zero;
	return m_out;
}

ijk_inl double3m ijkMatMul3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh)
{
	ijkVecMul3dvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul3dvs(m_out[1], m_lh[1], s_rh);
	ijkVecMul3dvs(m_out[2], m_lh[2], s_rh);
	return m_out;
}

ijk_inl double3m ijkMatDiv3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_dbl(s_rh);
	ijkVecMul3dvs(m_out[0], m_lh[0], recip);
	ijkVecMul3dvs(m_out[1], m_lh[1], recip);
	ijkVecMul3dvs(m_out[2], m_lh[2], recip);
	return m_out;
}

ijk_inl double3m ijkMatDivSafe3dms(double3x3 m_out, double3x3 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_safe_dbl(s_rh);
	ijkVecMul3dvs(m_out[0], m_lh[0], recip);
	ijkVecMul3dvs(m_out[1], m_lh[1], recip);
	ijkVecMul3dvs(m_out[2], m_lh[2], recip);
	return m_out;
}

ijk_inl double3m ijkMatMul3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh)
{
	ijkVecMul3dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul3dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecMul3dsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl double3m ijkMatDiv3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh)
{
	ijkVecDiv3dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv3dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDiv3dsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl double3m ijkMatDivSafe3dsm(double3x3 m_out, f64 const s_lh, double3x3 const m_rh)
{
	ijkVecDivSafe3dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe3dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDivSafe3dsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl double3m ijkMatAdd3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh)
{
	ijkVecAdd3dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd3dv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecAdd3dv(m_out[2], m_lh[2], m_rh[2]);
	return m_out;
}

ijk_inl double3m ijkMatSub3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh)
{
	ijkVecSub3dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub3dv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecSub3dv(m_out[2], m_lh[2], m_rh[2]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl double4m ijkMatInit4dm(double4x4 m_out)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = m_out[3][3] = dbl_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatInitElems4dm(double4x4 m_out, f64 const x0, f64 const y0, f64 const z0, f64 const w0, f64 const x1, f64 const y1, f64 const z1, f64 const w1, f64 const x2, f64 const y2, f64 const z2, f64 const w2, f64 const x3, f64 const y3, f64 const z3, f64 const w3)
{
	ijkVecInitElems4dv(m_out[0], x0, y0, z0, w0);
	ijkVecInitElems4dv(m_out[1], x1, y1, z1, w1);
	ijkVecInitElems4dv(m_out[2], x2, y2, z2, w2);
	ijkVecInitElems4dv(m_out[3], x3, y3, z3, w3);
	return m_out;
}

ijk_inl double4m ijkMatInitVecs4dm(double4x4 m_out, double4 const c0, double4 const c1, double4 const c2, double4 const c3)
{
	ijkVecCopy4dv(m_out[0], c0);
	ijkVecCopy4dv(m_out[1], c1);
	ijkVecCopy4dv(m_out[2], c2);
	ijkVecCopy4dv(m_out[3], c3);
	return m_out;
}

ijk_inl double4m ijkMatCopy4dm2(double4x4 m_out, double2x2 const m_in)
{
	ijkVecCopy4dvzw(m_out[0], m_in[0], dbl_zero, dbl_zero);
	ijkVecCopy4dvzw(m_out[1], m_in[1], dbl_zero, dbl_zero);
	ijkVecCopy4dv(m_out[2], double4_z);
	ijkVecCopy4dv(m_out[3], double4_w);
	return m_out;
}

ijk_inl double4m ijkMatCopy4dm3(double4x4 m_out, double3x3 const m_in)
{
	ijkVecCopy4dvw(m_out[0], m_in[0], dbl_zero);
	ijkVecCopy4dvw(m_out[1], m_in[1], dbl_zero);
	ijkVecCopy4dvw(m_out[2], m_in[2], dbl_zero);
	ijkVecCopy4dv(m_out[3], double4_w);
	return m_out;
}

ijk_inl double4m ijkMatCopy4dm4(double4x4 m_out, double4x4 const m_in)
{
	ijkVecCopy4dv(m_out[0], m_in[0]);
	ijkVecCopy4dv(m_out[1], m_in[1]);
	ijkVecCopy4dv(m_out[2], m_in[2]);
	ijkVecCopy4dv(m_out[3], m_in[3]);
	return m_out;
}

ijk_inl double4m ijkMatCopy4dms(double4x4 m_out, f64 const s_diag)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = m_out[3][3] = s_diag;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatMul4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh)
{
	ijkVecMul4dvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul4dvs(m_out[1], m_lh[1], s_rh);
	ijkVecMul4dvs(m_out[2], m_lh[2], s_rh);
	ijkVecMul4dvs(m_out[3], m_lh[3], s_rh);
	return m_out;
}

ijk_inl double4m ijkMatDiv4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_dbl(s_rh);
	ijkVecMul4dvs(m_out[0], m_lh[0], recip);
	ijkVecMul4dvs(m_out[1], m_lh[1], recip);
	ijkVecMul4dvs(m_out[2], m_lh[2], recip);
	ijkVecMul4dvs(m_out[3], m_lh[3], recip);
	return m_out;
}

ijk_inl double4m ijkMatDivSafe4dms(double4x4 m_out, double4x4 const m_lh, f64 const s_rh)
{
	f64 const recip = ijk_recip_safe_dbl(s_rh);
	ijkVecMul4dvs(m_out[0], m_lh[0], recip);
	ijkVecMul4dvs(m_out[1], m_lh[1], recip);
	ijkVecMul4dvs(m_out[2], m_lh[2], recip);
	ijkVecMul4dvs(m_out[3], m_lh[3], recip);
	return m_out;
}

ijk_inl double4m ijkMatMul4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh)
{
	ijkVecMul4dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul4dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecMul4dsv(m_out[2], s_lh, m_rh[2]);
	ijkVecMul4dsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl double4m ijkMatDiv4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh)
{
	ijkVecDiv4dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv4dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDiv4dsv(m_out[2], s_lh, m_rh[2]);
	ijkVecDiv4dsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl double4m ijkMatDivSafe4dsm(double4x4 m_out, f64 const s_lh, double4x4 const m_rh)
{
	ijkVecDivSafe4dsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe4dsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDivSafe4dsv(m_out[2], s_lh, m_rh[2]);
	ijkVecDivSafe4dsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl double4m ijkMatAdd4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh)
{
	ijkVecAdd4dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd4dv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecAdd4dv(m_out[2], m_lh[2], m_rh[2]);
	ijkVecAdd4dv(m_out[3], m_lh[3], m_rh[3]);
	return m_out;
}

ijk_inl double4m ijkMatSub4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh)
{
	ijkVecSub4dv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub4dv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecSub4dv(m_out[2], m_lh[2], m_rh[2]);
	ijkVecSub4dv(m_out[3], m_lh[3], m_rh[3]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl dmat2 ijkMatInit2d()
{
	dmat2 const m_out = {
		dbl_one, dbl_zero,
		dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatInitElems2d(double const x0, double const y0, double const x1, double const y1)
{
	dmat2 const m_out = {
		x0, y0,
		x1, y1,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatInitVecs2d(dvec2 const c0, dvec2 const c1)
{
	dmat2 const m_out = {
		c0.x, c0.y,
		c1.x, c1.y,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatCopy2d2(dmat2 const m_in)
{
	dmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatCopy2d3(dmat3 const m_in)
{
	dmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatCopy2d4(dmat4 const m_in)
{
	dmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatCopy2ds(double const s_diag)
{
	dmat2 const m_out = {
		s_diag, dbl_zero,
		dbl_zero, s_diag,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatMul2ds(dmat2 const m_lh, double const s_rh)
{
	dmat2 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatDiv2ds(dmat2 const m_lh, double const s_rh)
{
	double const s = ijk_recip_dbl(s_rh);
	dmat2 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatDivSafe2ds(dmat2 const m_lh, double const s_rh)
{
	double const s = ijk_recip_safe_dbl(s_rh);
	dmat2 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatMul2sd(double const s_lh, dmat2 const m_rh)
{
	dmat2 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatDiv2sd(double const s_lh, dmat2 const m_rh)
{
	dmat2 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatDivSafe2sd(double const s_lh, dmat2 const m_rh)
{
	dmat2 const m_out = {
		ijk_divide_safe_dbl(s_lh, m_rh.x0), ijk_divide_safe_dbl(s_lh, m_rh.y0),
		ijk_divide_safe_dbl(s_lh, m_rh.x1), ijk_divide_safe_dbl(s_lh, m_rh.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatAdd2d(dmat2 const m_lh, dmat2 const m_rh)
{
	dmat2 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatSub2d(dmat2 const m_lh, dmat2 const m_rh)
{
	dmat2 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl dmat3 ijkMatInit3d()
{
	dmat3 const m_out = {
		dbl_one, dbl_zero, dbl_zero,
		dbl_zero, dbl_one, dbl_zero,
		dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatInitElems3d(double const x0, double const y0, double const z0, double const x1, double const y1, double const z1, double const x2, double const y2, double const z2)
{
	dmat3 const m_out = {
		x0, y0, z0,
		x1, y1, z1,
		x2, y2, z2,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatInitVecs3d(dvec3 const c0, dvec3 const c1, dvec3 const c2)
{
	dmat3 const m_out = {
		c0.x, c0.y, c0.z,
		c1.x, c1.y, c1.z,
		c2.x, c2.y, c2.z,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatCopy3d2(dmat2 const m_in)
{
	dmat3 const m_out = {
		m_in.x0, m_in.y0, dbl_zero,
		m_in.x1, m_in.y1, dbl_zero,
		dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatCopy3d3(dmat3 const m_in)
{
	dmat3 const m_out = {
		m_in.x0, m_in.y0, m_in.z0,
		m_in.x1, m_in.y1, m_in.z1,
		m_in.x2, m_in.y2, m_in.z2,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatCopy3d4(dmat4 const m_in)
{
	dmat3 const m_out = {
		m_in.x0, m_in.y0, m_in.z0,
		m_in.x1, m_in.y1, m_in.z1,
		m_in.x2, m_in.y2, m_in.z2,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatCopy3ds(double const s_diag)
{
	dmat3 const m_out = {
		s_diag, dbl_zero, dbl_zero,
		dbl_zero, s_diag, dbl_zero,
		dbl_zero, dbl_zero, s_diag,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatMul3ds(dmat3 const m_lh, double const s_rh)
{
	dmat3 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh), (m_lh.z0 * s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh), (m_lh.z1 * s_rh),
		(m_lh.x2 * s_rh), (m_lh.y2 * s_rh), (m_lh.z2 * s_rh),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatDiv3ds(dmat3 const m_lh, double const s_rh)
{
	double const s = ijk_recip_dbl(s_rh);
	dmat3 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatDivSafe3ds(dmat3 const m_lh, double const s_rh)
{
	double const s = ijk_recip_safe_dbl(s_rh);
	dmat3 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatMul3sd(double const s_lh, dmat3 const m_rh)
{
	dmat3 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0), (s_lh * m_rh.z0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1), (s_lh * m_rh.z1),
		(s_lh * m_rh.x2), (s_lh * m_rh.y2), (s_lh * m_rh.z2),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatDiv3sd(double const s_lh, dmat3 const m_rh)
{
	dmat3 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0), (s_lh / m_rh.z0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1), (s_lh / m_rh.z1),
		(s_lh / m_rh.x2), (s_lh / m_rh.y2), (s_lh / m_rh.z2),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatDivSafe3sd(double const s_lh, dmat3 const m_rh)
{
	dmat3 const m_out = {
		ijk_divide_safe_dbl(s_lh, m_rh.x0), ijk_divide_safe_dbl(s_lh, m_rh.y0), ijk_divide_safe_dbl(s_lh, m_rh.z0),
		ijk_divide_safe_dbl(s_lh, m_rh.x1), ijk_divide_safe_dbl(s_lh, m_rh.y1), ijk_divide_safe_dbl(s_lh, m_rh.z1),
		ijk_divide_safe_dbl(s_lh, m_rh.x2), ijk_divide_safe_dbl(s_lh, m_rh.y2), ijk_divide_safe_dbl(s_lh, m_rh.z2),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatAdd3d(dmat3 const m_lh, dmat3 const m_rh)
{
	dmat3 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0), (m_lh.z0 + m_rh.z0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1), (m_lh.z1 + m_rh.z1),
		(m_lh.x2 + m_rh.x2), (m_lh.y2 + m_rh.y2), (m_lh.z2 + m_rh.z2),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatSub3d(dmat3 const m_lh, dmat3 const m_rh)
{
	dmat3 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0), (m_lh.z0 - m_rh.z0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1), (m_lh.z1 - m_rh.z1),
		(m_lh.x2 - m_rh.x2), (m_lh.y2 - m_rh.y2), (m_lh.z2 - m_rh.z2),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl dmat4 ijkMatInit4d()
{
	dmat4 const m_out = {
		dbl_one, dbl_zero, dbl_zero, dbl_zero,
		dbl_zero, dbl_one, dbl_zero, dbl_zero,
		dbl_zero, dbl_zero, dbl_one, dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatInitElems4d(double const x0, double const y0, double const z0, double const w0, double const x1, double const y1, double const z1, double const w1, double const x2, double const y2, double const z2, double const w2, double const x3, double const y3, double const z3, double const w3)
{
	dmat4 const m_out = {
		x0, y0, z0, w0,
		x1, y1, z1, w1,
		x2, y2, z2, w2,
		x3, y3, z3, w3,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatInitVecs4d(dvec4 const c0, dvec4 const c1, dvec4 const c2, dvec4 const c3)
{
	dmat4 const m_out = {
		c0.x, c0.y, c0.z, c0.w,
		c1.x, c1.y, c1.z, c1.w,
		c2.x, c2.y, c2.z, c2.w,
		c3.x, c3.y, c3.z, c3.w,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatCopy4d2(dmat2 const m_in)
{
	dmat4 const m_out = {
		m_in.x0, m_in.y0, dbl_zero, dbl_zero,
		m_in.x1, m_in.y1, dbl_zero, dbl_zero,
		dbl_zero, dbl_zero, dbl_one, dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatCopy4d3(dmat3 const m_in)
{
	dmat4 const m_out = {
		m_in.x0, m_in.y0, m_in.z0, dbl_zero,
		m_in.x1, m_in.y1, m_in.z1, dbl_zero,
		m_in.x2, m_in.y2, m_in.z2, dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatCopy4d4(dmat4 const m_in)
{
	dmat4 const m_out = {
		m_in.x0, m_in.y0, m_in.z0, m_in.w0,
		m_in.x1, m_in.y1, m_in.z1, m_in.w1,
		m_in.x2, m_in.y2, m_in.z2, m_in.w2,
		m_in.x3, m_in.y3, m_in.z3, m_in.w3,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatCopy4ds(double const s_diag)
{
	dmat4 const m_out = {
		s_diag, dbl_zero, dbl_zero, dbl_zero,
		dbl_zero, s_diag, dbl_zero, dbl_zero,
		dbl_zero, dbl_zero, s_diag, dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, s_diag,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatMul4ds(dmat4 const m_lh, double const s_rh)
{
	dmat4 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh), (m_lh.z0 * s_rh), (m_lh.w0 * s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh), (m_lh.z1 * s_rh), (m_lh.w1 * s_rh),
		(m_lh.x2 * s_rh), (m_lh.y2 * s_rh), (m_lh.z2 * s_rh), (m_lh.w2 * s_rh),
		(m_lh.x3 * s_rh), (m_lh.y3 * s_rh), (m_lh.z3 * s_rh), (m_lh.w3 * s_rh),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatDiv4ds(dmat4 const m_lh, double const s_rh)
{
	double const s = ijk_recip_dbl(s_rh);
	dmat4 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s), (m_lh.w0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s), (m_lh.w1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s), (m_lh.w2 * s),
		(m_lh.x3 * s), (m_lh.y3 * s), (m_lh.z3 * s), (m_lh.w3 * s),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatDivSafe4ds(dmat4 const m_lh, double const s_rh)
{
	double const s = ijk_recip_safe_dbl(s_rh);
	dmat4 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s), (m_lh.w0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s), (m_lh.w1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s), (m_lh.w2 * s),
		(m_lh.x3 * s), (m_lh.y3 * s), (m_lh.z3 * s), (m_lh.w3 * s),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatMul4sd(double const s_lh, dmat4 const m_rh)
{
	dmat4 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0), (s_lh * m_rh.z0), (s_lh * m_rh.w0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1), (s_lh * m_rh.z1), (s_lh * m_rh.w1),
		(s_lh * m_rh.x2), (s_lh * m_rh.y2), (s_lh * m_rh.z2), (s_lh * m_rh.w2),
		(s_lh * m_rh.x3), (s_lh * m_rh.y3), (s_lh * m_rh.z3), (s_lh * m_rh.w3),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatDiv4sd(double const s_lh, dmat4 const m_rh)
{
	dmat4 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0), (s_lh / m_rh.z0), (s_lh / m_rh.w0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1), (s_lh / m_rh.z1), (s_lh / m_rh.w1),
		(s_lh / m_rh.x2), (s_lh / m_rh.y2), (s_lh / m_rh.z2), (s_lh / m_rh.w2),
		(s_lh / m_rh.x3), (s_lh / m_rh.y3), (s_lh / m_rh.z3), (s_lh / m_rh.w3),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatDivSafe4sd(double const s_lh, dmat4 const m_rh)
{
	dmat4 const m_out = {
		ijk_divide_safe_dbl(s_lh, m_rh.x0), ijk_divide_safe_dbl(s_lh, m_rh.y0), ijk_divide_safe_dbl(s_lh, m_rh.z0), ijk_divide_safe_dbl(s_lh, m_rh.w0),
		ijk_divide_safe_dbl(s_lh, m_rh.x1), ijk_divide_safe_dbl(s_lh, m_rh.y1), ijk_divide_safe_dbl(s_lh, m_rh.z1), ijk_divide_safe_dbl(s_lh, m_rh.w1),
		ijk_divide_safe_dbl(s_lh, m_rh.x2), ijk_divide_safe_dbl(s_lh, m_rh.y2), ijk_divide_safe_dbl(s_lh, m_rh.z2), ijk_divide_safe_dbl(s_lh, m_rh.w2),
		ijk_divide_safe_dbl(s_lh, m_rh.x3), ijk_divide_safe_dbl(s_lh, m_rh.y3), ijk_divide_safe_dbl(s_lh, m_rh.z3), ijk_divide_safe_dbl(s_lh, m_rh.w3),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatAdd4d(dmat4 const m_lh, dmat4 const m_rh)
{
	dmat4 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0), (m_lh.z0 + m_rh.z0), (m_lh.w0 + m_rh.w0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1), (m_lh.z1 + m_rh.z1), (m_lh.w1 + m_rh.w1),
		(m_lh.x2 + m_rh.x2), (m_lh.y2 + m_rh.y2), (m_lh.z2 + m_rh.z2), (m_lh.w2 + m_rh.w2),
		(m_lh.x3 + m_rh.x3), (m_lh.y3 + m_rh.y3), (m_lh.z3 + m_rh.z3), (m_lh.w3 + m_rh.w3),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatSub4d(dmat4 const m_lh, dmat4 const m_rh)
{
	dmat4 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0), (m_lh.z0 - m_rh.z0), (m_lh.w0 - m_rh.w0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1), (m_lh.z1 - m_rh.z1), (m_lh.w1 - m_rh.w1),
		(m_lh.x2 - m_rh.x2), (m_lh.y2 - m_rh.y2), (m_lh.z2 - m_rh.z2), (m_lh.w2 - m_rh.w2),
		(m_lh.x3 - m_rh.x3), (m_lh.y3 - m_rh.y3), (m_lh.z3 - m_rh.z3), (m_lh.w3 - m_rh.w3),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkMatDeterminant2dm(double2x2 const m_in)
{
	// det = m00 * m11 - m10 * m01
	return ijkVecCross2dv(m_in[0], m_in[1]);
}

ijk_inl f64 ijkMatDeterminantInv2dm(double2x2 const m_in)
{
	f64 const s = ijkMatDeterminant2dm(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl f64 ijkMatDeterminantInvSafe2dm(double2x2 const m_in)
{
	f64 const s = ijkMatDeterminant2dm(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl f64 ijkMatMulRowVec2dmv(double2x2 const m_in, double2 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1]);
}

ijk_inl doublev ijkMatGetRow2dm(double2 v_out, double2x2 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	return v_out;
}

ijk_inl double2m ijkMatTranspose2dm(double2x2 m_out, double2x2 const m_in)
{
	f64 const tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl double2m ijkMatTransposeMul2dms(double2x2 m_out, double2x2 const m_in, f64 const s)
{
	f64 const tmp = m_in[0][1];
	m_out[0][1] = s * m_in[1][0];
	m_out[1][0] = s * tmp;
	m_out[0][0] = s * m_in[0][0];
	m_out[1][1] = s * m_in[1][1];
	return m_out;
}

ijk_inl double2m ijkMatInverse2dm(double2x2 m_out, double2x2 const m_in)
{
	// inv = adj/det
	// adj = {{+m11,-m01},{-m10,+m00}}
	f64 const detInv = ijkMatDeterminantInv2dm(m_in);
	double2x2 const adj_det = {
		(+m_in[1][1] * detInv),
		(-m_in[0][1] * detInv),
		(-m_in[1][0] * detInv),
		(+m_in[0][0] * detInv),
	};
	return ijkMatCopy2dm2(m_out, adj_det);
}

ijk_inl double2m ijkMatInverseSafe2dm(double2x2 m_out, double2x2 const m_in)
{
	f64 const detInv = ijkMatDeterminantInvSafe2dm(m_in);
	double2x2 const adj_det = {
		(+m_in[1][1] * detInv),
		(-m_in[0][1] * detInv),
		(-m_in[1][0] * detInv),
		(+m_in[0][0] * detInv),
	};
	return ijkMatCopy2dm2(m_out, adj_det);
}

ijk_inl doublev ijkMatMulVec2dmv(double2 v_out, double2x2 const m_lh, double2 const v_rh)
{
	double2 const v_copy = {
		ijkMatMulRowVec2dmv(m_lh, v_rh, 0),
		ijkMatMulRowVec2dmv(m_lh, v_rh, 1),
	};
	return ijkVecCopy2dv(v_out, v_copy);
}

ijk_inl double2m ijkMatMul2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh)
{
	ijkMatMulVec2dmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMulVec2dmv(m_out[1], m_lh, m_rh[1]);
	return m_out;
}

ijk_inl double2m ijkMatDiv2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh)
{
	double2x2 inv_rh;
	return ijkMatMul2dm(m_out, m_lh, ijkMatInverse2dm(inv_rh, m_rh));
}

ijk_inl double2m ijkMatDivSafe2dm(double2x2 m_out, double2x2 const m_lh, double2x2 const m_rh)
{
	double2x2 inv_rh;
	return ijkMatMul2dm(m_out, m_lh, ijkMatInverseSafe2dm(inv_rh, m_rh));
}

ijk_inl double2m ijkMatRotate2dm(double2x2 m_out, f64 const angle_degrees)
{
	ijkTrigSinCos_deg_dbl(angle_degrees, m_out[0] + 1, m_out[0] + 0);
	m_out[1][0] = -m_out[0][1];
	m_out[1][1] = +m_out[0][0];
	return m_out;
}

ijk_inl double2m ijkMatScale2dm(double2x2 m_out, f64 const sx, f64 const sy)
{
	m_out[0][0] = sx;
	m_out[1][1] = sy;
	m_out[0][1] = m_out[1][0] = dbl_zero;
	return m_out;
}

ijk_inl double2m ijkMatRotateScale2dm(double2x2 m_out, f64 const angle_degrees, f64 const sx, f64 const sy)
{
	ijkTrigSinCos_deg_dbl(angle_degrees, m_out[0] + 1, m_out[0] + 0);
	m_out[1][0] = -m_out[0][1] * sy;
	m_out[1][1] = +m_out[0][0] * sy;
	m_out[0][0] *= sx;
	m_out[0][1] *= sx;
	return m_out;
}

ijk_inl double2km ijkMatGetRotate2dm(double2x2 const m_in, f64* const angle_degrees_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(m_in[0][1], m_in[0][0]);
	return m_in;
}

ijk_inl double2km ijkMatGetScale2dm(double2x2 const m_in, f64* const sx_out, f64* const sy_out)
{
	*sx_out = ijkVecLength2dv(m_in[0]);
	*sy_out = ijkVecLength2dv(m_in[1]);
	return m_in;
}

ijk_inl double2km ijkMatGetRotateScale2dm(double2x2 const m_in, f64* const angle_degrees_out, f64* const sx_out, f64* const sy_out)
{
	ijkMatGetScale2dm(m_in, sx_out, sy_out);
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(m_in[0][1], m_in[0][0]);
	return m_in;
}

ijk_inl double2m ijkMatInverseRotate2dm(double2x2 m_out, double2x2 const m_in)
{
	return ijkMatTranspose2dm(m_out, m_in);
}

ijk_inl double2m ijkMatInverseScale2dm(double2x2 m_out, double2x2 const m_in)
{
	m_out[0][0] = ijk_recip_dbl(m_in[0][0]);
	m_out[1][1] = ijk_recip_dbl(m_in[1][1]);
	m_out[0][1] = m_out[1][0] = dbl_zero;
	return m_out;
}

ijk_inl double2m ijkMatInverseRotateScale2dm(double2x2 m_out, double2x2 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	f64 const sx2_inv = ijkVecLengthSqInv2dv(m_in[0]);
	f64 const sy2_inv = ijkVecLengthSqInv2dv(m_in[1]);
	f64 const tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0] * sy2_inv;
	m_out[1][0] = tmp * sx2_inv;
	m_out[0][0] = m_in[0][0] * sx2_inv;
	m_out[1][1] = m_in[1][1] * sy2_inv;
	return m_out;
}

ijk_inl double2m ijkMatInverseTranspose2dm(double2x2 m_out, double2x2 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	ijkVecMul2dvs(m_out[0], m_in[0], ijkVecLengthSqInv2dv(m_in[0]));
	ijkVecMul2dvs(m_out[1], m_in[1], ijkVecLengthSqInv2dv(m_in[1]));
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkMatDeterminant3dm(double3x3 const m_in)
{
	// det = dot(c0, cross(c1, c2))
	double3 cross;
	return ijkVecDot3dv(m_in[0], ijkVecCross3dv(cross, m_in[1], m_in[2]));
}

ijk_inl f64 ijkMatDeterminantInv3dm(double3x3 const m_in)
{
	f64 const s = ijkMatDeterminant3dm(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl f64 ijkMatDeterminantInvSafe3dm(double3x3 const m_in)
{
	f64 const s = ijkMatDeterminant3dm(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl f64 ijkMatMulRowVec3dmv(double3x3 const m_in, double3 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1] + m_in[2][row] * v_in[2]);
}

ijk_inl doublev ijkMatGetRow3dm(double3 v_out, double3x3 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	v_out[2] = m_in[2][row];
	return v_out;
}

ijk_inl double3m ijkMatTranspose3dm(double3x3 m_out, double3x3 const m_in)
{
	f64 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	tmp = m_in[0][2];
	m_out[0][2] = m_in[2][0];
	m_out[2][0] = tmp;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1];
	m_out[2][1] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	m_out[2][2] = m_in[2][2];
	return m_out;
}

ijk_inl double3m ijkMatTransposeMul3dms(double3x3 m_out, double3x3 const m_in, f64 const s)
{
	f64 tmp = m_in[0][1];
	m_out[0][1] = s * m_in[1][0];
	m_out[1][0] = s * tmp;
	tmp = m_in[0][2];
	m_out[0][2] = s * m_in[2][0];
	m_out[2][0] = s * tmp;
	tmp = m_in[1][2];
	m_out[1][2] = s * m_in[2][1];
	m_out[2][1] = s * tmp;
	m_out[0][0] = s * m_in[0][0];
	m_out[1][1] = s * m_in[1][1];
	m_out[2][2] = s * m_in[2][2];
	return m_out;
}

ijk_inl double3m ijkMatInverse3dm(double3x3 m_out, double3x3 const m_in)
{
	f64 detInv;
	double3x3 cross;
	ijkVecCross3dv(cross[0], m_in[1], m_in[2]);
	ijkVecCross3dv(cross[1], m_in[2], m_in[0]);
	ijkVecCross3dv(cross[2], m_in[0], m_in[1]);
	detInv = ijkVecDot3dv(m_in[0], cross[0]);
	return ijkMatTransposeMul3dms(m_out, cross, ijk_recip_dbl(detInv));
}

ijk_inl double3m ijkMatInverseSafe3dm(double3x3 m_out, double3x3 const m_in)
{
	f64 detInv;
	double3x3 cross;
	ijkVecCross3dv(cross[0], m_in[1], m_in[2]);
	ijkVecCross3dv(cross[1], m_in[2], m_in[0]);
	ijkVecCross3dv(cross[2], m_in[0], m_in[1]);
	detInv = ijkVecDot3dv(m_in[0], cross[0]);
	return ijkMatTransposeMul3dms(m_out, cross, ijk_recip_safe_dbl(detInv));
}

ijk_inl doublev ijkMatMulVec3dmv(double3 v_out, double3x3 const m_lh, double3 const v_rh)
{
	double3 const v_copy = {
		ijkMatMulRowVec3dmv(m_lh, v_rh, 0),
		ijkMatMulRowVec3dmv(m_lh, v_rh, 1),
		ijkMatMulRowVec3dmv(m_lh, v_rh, 2),
	};
	return ijkVecCopy3dv(v_out, v_copy);
}

ijk_inl double3m ijkMatMul3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh)
{
	ijkMatMulVec3dmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMulVec3dmv(m_out[1], m_lh, m_rh[1]);
	ijkMatMulVec3dmv(m_out[2], m_lh, m_rh[2]);
	return m_out;
}

ijk_inl double3m ijkMatDiv3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh)
{
	double3x3 inv_rh;
	return ijkMatMul3dm(m_out, m_lh, ijkMatInverse3dm(inv_rh, m_rh));
}

ijk_inl double3m ijkMatDivSafe3dm(double3x3 m_out, double3x3 const m_lh, double3x3 const m_rh)
{
	double3x3 inv_rh;
	return ijkMatMul3dm(m_out, m_lh, ijkMatInverseSafe3dm(inv_rh, m_rh));
}

ijk_inl double3m ijkMatRotateXYZ3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems3dm(m_out,
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz),
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz),
		(+sy), (-sx * cy), (+cx * cy));
}

ijk_inl double3m ijkMatRotateYZX3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems3dm(m_out,
		(+cy * cz), (+sz), (-sy * cz),
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx),
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx));
}

ijk_inl double3m ijkMatRotateZXY3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems3dm(m_out,
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy),
		(-sz * cx), (+cz * cx), (+sx),
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy));
}

ijk_inl double3m ijkMatRotateYXZ3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems3dm(m_out,
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz),
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz),
		(+sy * cx), (-sx), (+cy * cx));
}

ijk_inl double3m ijkMatRotateXZY3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems3dm(m_out,
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy),
		(-sz), (+cx * cz), (+sx * cz),
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy));
}

ijk_inl double3m ijkMatRotateZYX3dm(double3x3 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems3dm(m_out,
		(+cz * cy), (+sy * cy), (-sy),
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx),
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx));
}

ijk_inl double3km ijkMatGetRotateXYZ3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(+m_in[2][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(-m_in[1][0], +m_in[0][0]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(-m_in[2][1], +m_in[2][2]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateYZX3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(+m_in[0][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(-m_in[2][1], +m_in[1][1]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(-m_in[0][2], +m_in[0][0]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateZXY3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(+m_in[1][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(-m_in[0][2], +m_in[2][2]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(-m_in[1][0], +m_in[1][1]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateYXZ3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(-m_in[2][1]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(+m_in[2][0], +m_in[2][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(+m_in[0][1], +m_in[1][1]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateXZY3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(-m_in[1][0]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(+m_in[1][2], +m_in[1][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(+m_in[2][0], +m_in[0][0]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateZYX3dm(double3x3 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(-m_in[0][2]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(+m_in[0][1], +m_in[0][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(+m_in[1][2], +m_in[2][2]);
	return m_in;
}

ijk_inl double3m ijkMatRotate3dm(double3x3 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ3dm(m_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX3dm(m_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY3dm(m_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ3dm(m_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY3dm(m_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX3dm(m_out, rotateDegXYZ);
	}
	return m_out;
}

ijk_inl double3m ijkMatScale3dm(double3x3 m_out, double3 const scale)
{
	m_out[0][0] = scale[0];
	m_out[1][1] = scale[1];
	m_out[2][2] = scale[2];
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = dbl_zero;
	return m_out;
}

ijk_inl double3m ijkMatRotateScale3dm(double3x3 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale)
{
	ijkMatRotate3dm(m_out, order, rotateDegXYZ);
	ijkVecMul3dvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3dvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3dvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl double3km ijkMatGetRotate3dm(double3x3 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ3dm(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX3dm(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY3dm(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ3dm(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY3dm(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX3dm(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl double3km ijkMatGetScale3dm(double3x3 const m_in, double3 scale_out)
{
	scale_out[0] = ijkVecLength3dv(m_in[0]);
	scale_out[1] = ijkVecLength3dv(m_in[1]);
	scale_out[2] = ijkVecLength3dv(m_in[2]);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateScale3dm(double3x3 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out)
{
	double3x3 rot;
	ijkVecDivSafe3dvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3dv(m_in[0])));
	ijkVecDivSafe3dvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3dv(m_in[1])));
	ijkVecDivSafe3dvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3dv(m_in[2])));
	ijkMatGetRotate3dm(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl double3m ijkMatInverseRotate3dm(double3x3 m_out, double3x3 const m_in)
{
	return ijkMatTranspose3dm(m_out, m_in);
}

ijk_inl double3m ijkMatInverseScale3dm(double3x3 m_out, double3x3 const m_in)
{
	m_out[0][0] = ijk_recip_dbl(m_in[0][0]);
	m_out[1][1] = ijk_recip_dbl(m_in[1][1]);
	m_out[2][2] = ijk_recip_dbl(m_in[2][2]);
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = dbl_zero;
	return m_out;
}

ijk_inl double3m ijkMatInverseRotateScale3dm(double3x3 m_out, double3x3 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	f64 const sx2_inv = ijkVecLengthSqInv3dv(m_in[0]);
	f64 const sy2_inv = ijkVecLengthSqInv3dv(m_in[1]);
	f64 const sz2_inv = ijkVecLengthSqInv3dv(m_in[2]);
	f64 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0] * sy2_inv;
	m_out[1][0] = tmp * sx2_inv;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1] * sz2_inv;
	m_out[2][1] = tmp * sy2_inv;
	tmp = m_in[2][0];
	m_out[2][0] = m_in[0][2] * sx2_inv;
	m_out[0][2] = tmp * sz2_inv;
	m_out[0][0] = m_in[0][0] * sx2_inv;
	m_out[1][1] = m_in[1][1] * sy2_inv;
	m_out[2][2] = m_in[2][2] * sz2_inv;
	return m_out;
}

ijk_inl double3m ijkMatInverseTranspose3dm(double3x3 m_out, double3x3 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	ijkVecMul3dvs(m_out[0], m_in[0], ijkVecLengthSqInv3dv(m_in[0]));
	ijkVecMul3dvs(m_out[1], m_in[1], ijkVecLengthSqInv3dv(m_in[1]));
	ijkVecMul3dvs(m_out[2], m_in[2], ijkVecLengthSqInv3dv(m_in[2]));
	return m_out;
}

ijk_inl double3m ijkMatRotateAxisAngle3dm(double3x3 m_out, double3 const axis_unit, f64 const angle_degrees)
{
	f64 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f64 const x = axis_unit[0], y = axis_unit[1], z = axis_unit[2];
	ijkTrigSinCos_deg_dbl(angle_degrees, &s, &c);
	t = dbl_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems3dm(m_out,
		(x * xt + x), (xyt + zs), (zxt - ys),
		(xyt - zs), (y * yt + c), (yzt + xs),
		(zxt + ys), (yzt - xs), (z * zt + c));
}

ijk_inl double3m ijkMatRotateAxisAngleScale3dm(double3x3 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale)
{
	ijkMatRotateAxisAngle3dm(m_out, axis_unit, angle_degrees);
	ijkVecMul3dvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3dvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3dvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl double3km ijkMatGetRotateAxisAngle3dm(double3x3 const m_in, double3 axis_unit_out, f64* const angle_degrees_out)
{
	f64 r;
	f64 const t = (m_in[0][0] + m_in[1][1] + m_in[2][2] - dbl_one);
	ijkVecInitElems3dv(axis_unit_out,
		(m_in[1][2] - m_in[2][1]), (m_in[2][0] - m_in[0][2]), (m_in[0][1] - m_in[1][0]));
	r = ijkVecLength3dv(axis_unit_out);
	ijkVecDivSafe3dvs(axis_unit_out, axis_unit_out, r);
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(r, t);
	return m_in;
}

ijk_inl double3km ijkMatGetRotateAxisAngleScale3dm(double3x3 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out)
{
	double3x3 rot;
	ijkVecDivSafe3dvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3dv(m_in[0])));
	ijkVecDivSafe3dvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3dv(m_in[1])));
	ijkVecDivSafe3dvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3dv(m_in[2])));
	ijkMatGetRotateAxisAngle3dm(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl double3m ijkMatLookAt3dm(double3x3 m_out, double3x3 m_inv_out_opt, double3 const origin, double3 const target, double3 const calibUnit, ijkTransformBasis const calibAxis)
{
	// right-handed: direction basis is from target to center, side = up x dir, up = dir x side
	uindex const up = calibAxis % 3, dir = (up + 1) % 3, side = (up + 2) % 3;
	ijkVecSub3dv(m_out[dir], origin, target);
	ijkVecNormalize3dv(m_out[dir], m_out[dir]);
	ijkVecCrossNormalize3dv(m_out[side], calibUnit, m_out[dir]);
	ijkVecCross3dv(m_out[up], m_out[dir], m_out[side]);
	if (m_inv_out_opt)
		ijkMatTranspose3dm(m_inv_out_opt, m_out);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl f64 ijkMatDeterminant4dm(double4x4 const m_in)
{
	double3 cross;
	f64 det = dbl_zero;
	det += m_in[0][3] * ijkVecDot3dv(m_in[1], ijkVecCross3dv(cross, m_in[2], m_in[3]));
	det += m_in[1][3] * ijkVecDot3dv(m_in[2], ijkVecCross3dv(cross, m_in[3], m_in[0]));
	det += m_in[2][3] * ijkVecDot3dv(m_in[3], ijkVecCross3dv(cross, m_in[0], m_in[1]));
	det += m_in[3][3] * ijkVecDot3dv(m_in[0], ijkVecCross3dv(cross, m_in[1], m_in[2]));
	return det;
}

ijk_inl f64 ijkMatDeterminantInv4dm(double4x4 const m_in)
{
	f64 const s = ijkMatDeterminant4dm(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl f64 ijkMatDeterminantInvSafe4dm(double4x4 const m_in)
{
	f64 const s = ijkMatDeterminant4dm(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl f64 ijkMatMulRowVec4dmv(double4x4 const m_in, double4 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1] + m_in[2][row] * v_in[2] + m_in[3][row] * v_in[3]);
}

ijk_inl doublev ijkMatGetRow4dm(double4 v_out, double4x4 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	v_out[2] = m_in[2][row];
	v_out[3] = m_in[3][row];
	return v_out;
}

ijk_inl double4m ijkMatTranspose4dm(double4x4 m_out, double4x4 const m_in)
{
	f64 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	tmp = m_in[0][2];
	m_out[0][2] = m_in[2][0];
	m_out[2][0] = tmp;
	tmp = m_in[0][3];
	m_out[0][3] = m_in[3][0];
	m_out[3][0] = tmp;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1];
	m_out[2][1] = tmp;
	tmp = m_in[1][3];
	m_out[1][3] = m_in[3][1];
	m_out[3][1] = tmp;
	tmp = m_in[2][3];
	m_out[2][3] = m_in[3][2];
	m_out[3][2] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	m_out[2][2] = m_in[2][2];
	m_out[3][3] = m_in[3][3];
	return m_out;
}

ijk_inl double4m ijkMatTransposeMul4dms(double4x4 m_out, double4x4 const m_in, f64 const s)
{
	f64 tmp = m_in[0][1];
	m_out[0][1] = s * m_in[1][0];
	m_out[1][0] = s * tmp;
	tmp = m_in[0][2];
	m_out[0][2] = s * m_in[2][0];
	m_out[2][0] = s * tmp;
	tmp = m_in[0][3];
	m_out[0][3] = s * m_in[3][0];
	m_out[3][0] = s * tmp;
	tmp = m_in[1][2];
	m_out[1][2] = s * m_in[2][1];
	m_out[2][1] = s * tmp;
	tmp = m_in[1][3];
	m_out[1][3] = s * m_in[3][1];
	m_out[3][1] = s * tmp;
	tmp = m_in[2][3];
	m_out[2][3] = s * m_in[3][2];
	m_out[3][2] = s * tmp;
	m_out[0][0] = s * m_in[0][0];
	m_out[1][1] = s * m_in[1][1];
	m_out[2][2] = s * m_in[2][2];
	m_out[3][3] = s * m_in[3][3];
	return m_out;
}

ijk_inl double4m ijkMatInverse4dm(double4x4 m_out, double4x4 const m_in)
{
	// block-wise inversion; upper-left 3x3 (A), bottom-right 1x1 (D)
	f64 const blockD = -m_in[3][3], blockInvD = ijk_recip_dbl(blockD);
	double3 const blockB_D = {
		(m_in[3][0] * blockInvD), (m_in[3][1] * blockInvD), (m_in[3][2] * blockInvD),
	};
	double3 const blockC_D = {
		(blockInvD * m_in[0][3]), (blockInvD * m_in[1][3]), (blockInvD * m_in[2][3]),
	};
	double3x3 blockInvA = {
		(m_in[0][0] + blockB_D[0] * m_in[0][3]), (m_in[0][1] + blockB_D[1] * m_in[0][3]), (m_in[0][2] + blockB_D[2] * m_in[0][3]),
		(m_in[1][0] + blockB_D[0] * m_in[1][3]), (m_in[1][1] + blockB_D[1] * m_in[1][3]), (m_in[1][2] + blockB_D[2] * m_in[1][3]),
		(m_in[2][0] + blockB_D[0] * m_in[2][3]), (m_in[2][1] + blockB_D[1] * m_in[2][3]), (m_in[2][2] + blockB_D[2] * m_in[2][3]),
	};
	ijkMatInverse3dm(blockInvA, blockInvA);
	ijkVecCopy4dvw(m_out[0], blockInvA[0], ijkVecDot3dv(blockC_D, blockInvA[0]));
	ijkVecCopy4dvw(m_out[1], blockInvA[1], ijkVecDot3dv(blockC_D, blockInvA[1]));
	ijkVecCopy4dvw(m_out[2], blockInvA[2], ijkVecDot3dv(blockC_D, blockInvA[2]));
	ijkMatMulVec3dmv(m_out[3], blockInvA, blockB_D);
	m_out[3][3] = ijkVecDot3dv(m_out[3], blockC_D) - blockInvD;
	return m_out;
}

ijk_inl double4m ijkMatInverseSafe4dm(double4x4 m_out, double4x4 const m_in)
{
	f64 const blockD = -m_in[3][3], blockInvD = ijk_recip_safe_dbl(blockD);
	double3 const blockB_D = {
		(m_in[3][0] * blockInvD), (m_in[3][1] * blockInvD), (m_in[3][2] * blockInvD),
	};
	double3 const blockC_D = {
		(blockInvD * m_in[0][3]), (blockInvD * m_in[1][3]), (blockInvD * m_in[2][3]),
	};
	double3x3 blockInvA = {
		(m_in[0][0] + blockB_D[0] * m_in[0][3]), (m_in[0][1] + blockB_D[1] * m_in[0][3]), (m_in[0][2] + blockB_D[2] * m_in[0][3]),
		(m_in[1][0] + blockB_D[0] * m_in[1][3]), (m_in[1][1] + blockB_D[1] * m_in[1][3]), (m_in[1][2] + blockB_D[2] * m_in[1][3]),
		(m_in[2][0] + blockB_D[0] * m_in[2][3]), (m_in[2][1] + blockB_D[1] * m_in[2][3]), (m_in[2][2] + blockB_D[2] * m_in[2][3]),
	};
	ijkMatInverseSafe3dm(blockInvA, blockInvA);
	ijkVecCopy4dvw(m_out[0], blockInvA[0], ijkVecDot3dv(blockC_D, blockInvA[0]));
	ijkVecCopy4dvw(m_out[1], blockInvA[1], ijkVecDot3dv(blockC_D, blockInvA[1]));
	ijkVecCopy4dvw(m_out[2], blockInvA[2], ijkVecDot3dv(blockC_D, blockInvA[2]));
	ijkMatMulVec3dmv(m_out[3], blockInvA, blockB_D);
	m_out[3][3] = ijkVecDot3dv(m_out[3], blockC_D) - blockInvD;
	return m_out;
}

ijk_inl doublev ijkMatMulVec4dmv(double4 v_out, double4x4 const m_lh, double4 const v_rh)
{
	double4 const v_copy = {
		ijkMatMulRowVec4dmv(m_lh, v_rh, 0),
		ijkMatMulRowVec4dmv(m_lh, v_rh, 1),
		ijkMatMulRowVec4dmv(m_lh, v_rh, 2),
		ijkMatMulRowVec4dmv(m_lh, v_rh, 3),
	};
	return ijkVecCopy4dv(v_out, v_copy);
}

ijk_inl double4m ijkMatMul4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh)
{
	ijkMatMulVec4dmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMulVec4dmv(m_out[1], m_lh, m_rh[1]);
	ijkMatMulVec4dmv(m_out[2], m_lh, m_rh[2]);
	ijkMatMulVec4dmv(m_out[3], m_lh, m_rh[3]);
	return m_out;
}

ijk_inl double4m ijkMatDiv4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh)
{
	double4x4 inv_rh;
	return ijkMatMul4dm(m_out, m_lh, ijkMatInverse4dm(inv_rh, m_rh));
}

ijk_inl double4m ijkMatDivSafe4dm(double4x4 m_out, double4x4 const m_lh, double4x4 const m_rh)
{
	double4x4 inv_rh;
	return ijkMatMul4dm(m_out, m_lh, ijkMatInverseSafe4dm(inv_rh, m_rh));
}

ijk_inl double4m ijkMatRotateXYZ4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems4dm(m_out,
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz), dbl_zero,
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz), dbl_zero,
		(+sy), (-sx * cy), (+cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateYZX4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems4dm(m_out,
		(+cy * cz), (+sz), (-sy * cz), dbl_zero,
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx), dbl_zero,
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateZXY4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems4dm(m_out,
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy), dbl_zero,
		(-sz * cx), (+cz * cx), (+sx), dbl_zero,
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateYXZ4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems4dm(m_out,
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz), dbl_zero,
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz), dbl_zero,
		(+sy * cx), (-sx), (+cy * cx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateXZY4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems4dm(m_out,
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy), dbl_zero,
		(-sz), (+cx * cz), (+sx * cz), dbl_zero,
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateZYX4dm(double4x4 m_out, double3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems4dm(m_out,
		(+cz * cy), (+sy * cy), (-sy), dbl_zero,
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx), dbl_zero,
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4km ijkMatGetRotateXYZ4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(+m_in[2][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(-m_in[1][0], +m_in[0][0]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(-m_in[2][1], +m_in[2][2]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateYZX4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(+m_in[0][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(-m_in[2][1], +m_in[1][1]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(-m_in[0][2], +m_in[0][0]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateZXY4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(+m_in[1][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(-m_in[0][2], +m_in[2][2]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(-m_in[1][0], +m_in[1][1]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateYXZ4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(-m_in[2][1]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(+m_in[2][0], +m_in[2][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(+m_in[0][1], +m_in[1][1]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateXZY4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(-m_in[1][0]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(+m_in[1][2], +m_in[1][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(+m_in[2][0], +m_in[0][0]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateZYX4dm(double4x4 const m_in, double3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(-m_in[0][2]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(+m_in[0][1], +m_in[0][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(+m_in[1][2], +m_in[2][2]);
	return m_in;
}

ijk_inl double4m ijkMatRotate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ4dm(m_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX4dm(m_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY4dm(m_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ4dm(m_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY4dm(m_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX4dm(m_out, rotateDegXYZ);
	}
	return m_out;
}

ijk_inl double4m ijkMatScale4dm(double4x4 m_out, double3 const scale)
{
	m_out[0][0] = scale[0];
	m_out[1][1] = scale[1];
	m_out[2][2] = scale[2];
	m_out[3][3] = dbl_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatRotateScale4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale)
{
	ijkMatRotate4dm(m_out, order, rotateDegXYZ);
	ijkVecMul3dvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3dvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3dvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl double4km ijkMatGetRotate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ4dm(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX4dm(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY4dm(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ4dm(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY4dm(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX4dm(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl double4km ijkMatGetScale4dm(double4x4 const m_in, double3 scale_out)
{
	scale_out[0] = ijkVecLength3dv(m_in[0]);
	scale_out[1] = ijkVecLength3dv(m_in[1]);
	scale_out[2] = ijkVecLength3dv(m_in[2]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateScale4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out)
{
	double3x3 rot;
	ijkVecDivSafe3dvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3dv(m_in[0])));
	ijkVecDivSafe3dvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3dv(m_in[1])));
	ijkVecDivSafe3dvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3dv(m_in[2])));
	ijkMatGetRotate3dm(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl double4m ijkMatInverseRotate4dm(double4x4 m_out, double4x4 const m_in)
{
	f64 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	tmp = m_in[0][2];
	m_out[0][2] = m_in[2][0];
	m_out[2][0] = tmp;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1];
	m_out[2][1] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	m_out[2][2] = m_in[2][2];
	m_out[3][3] = dbl_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatInverseScale4dm(double4x4 m_out, double4x4 const m_in)
{
	m_out[0][0] = ijk_recip_dbl(m_in[0][0]);
	m_out[1][1] = ijk_recip_dbl(m_in[1][1]);
	m_out[2][2] = ijk_recip_dbl(m_in[2][2]);
	m_out[3][3] = dbl_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatInverseRotateScale4dm(double4x4 m_out, double4x4 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	f64 const sx2_inv = ijkVecLengthSqInv3dv(m_in[0]);
	f64 const sy2_inv = ijkVecLengthSqInv3dv(m_in[1]);
	f64 const sz2_inv = ijkVecLengthSqInv3dv(m_in[2]);
	f64 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0] * sy2_inv;
	m_out[1][0] = tmp * sx2_inv;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1] * sz2_inv;
	m_out[2][1] = tmp * sy2_inv;
	tmp = m_in[2][0];
	m_out[2][0] = m_in[0][2] * sx2_inv;
	m_out[0][2] = tmp * sz2_inv;
	m_out[0][0] = m_in[0][0] * sx2_inv;
	m_out[1][1] = m_in[1][1] * sy2_inv;
	m_out[2][2] = m_in[2][2] * sz2_inv;
	m_out[3][3] = dbl_one;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatInverseTranspose4dm(double4x4 m_out, double4x4 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	ijkVecMul3dvs(m_out[0], m_in[0], ijkVecLengthSqInv3dv(m_in[0]));
	ijkVecMul3dvs(m_out[1], m_in[1], ijkVecLengthSqInv3dv(m_in[1]));
	ijkVecMul3dvs(m_out[2], m_in[2], ijkVecLengthSqInv3dv(m_in[2]));
	m_out[3][3] = dbl_one;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	return m_out;
}

ijk_inl double4m ijkMatRotateAxisAngle4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees)
{
	f64 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f64 const x = axis_unit[0], y = axis_unit[1], z = axis_unit[2];
	ijkTrigSinCos_deg_dbl(angle_degrees, &s, &c);
	t = dbl_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems4dm(m_out,
		(x * xt + x), (xyt + zs), (zxt - ys), dbl_zero,
		(xyt - zs), (y * yt + c), (yzt + xs), dbl_zero,
		(zxt + ys), (yzt - xs), (z * zt + c), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl double4m ijkMatRotateAxisAngleScale4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale)
{
	ijkMatRotateAxisAngle4dm(m_out, axis_unit, angle_degrees);
	ijkVecMul4dvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul4dvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul4dvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl double4km ijkMatGetRotateAxisAngle4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out)
{
	f64 r;
	f64 const t = (m_in[0][0] + m_in[1][1] + m_in[2][2] - dbl_one);
	ijkVecInitElems3dv(axis_unit_out,
		(m_in[1][2] - m_in[2][1]), (m_in[2][0] - m_in[0][2]), (m_in[0][1] - m_in[1][0]));
	r = ijkVecLength3dv(axis_unit_out);
	ijkVecDivSafe3dvs(axis_unit_out, axis_unit_out, r);
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(r, t);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateAxisAngleScale4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out)
{
	double3x3 rot;
	ijkVecDivSafe3dvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3dv(m_in[0])));
	ijkVecDivSafe3dvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3dv(m_in[1])));
	ijkVecDivSafe3dvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3dv(m_in[2])));
	ijkMatGetRotateAxisAngle3dm(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl double4m ijkMatTranslate4dm(double4x4 m_out, double3 const translate)
{
	ijkVecCopy4dv(m_out[0], double4_x);
	ijkVecCopy4dv(m_out[1], double4_y);
	ijkVecCopy4dv(m_out[2], double4_z);
	ijkVecCopy4dvw(m_out[3], translate, dbl_one);
	return m_out;
}

ijk_inl double4m ijkMatRotateTranslate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const translate)
{
	ijkMatRotate4dm(m_out, order, rotateDegXYZ);
	ijkVecCopy3dv(m_out[3], translate);
	return m_out;
}

ijk_inl double4m ijkMatScaleTranslate4dm(double4x4 m_out, double3 const scale, double3 const translate)
{
	ijkMatScale4dm(m_out, scale);
	ijkVecCopy3dv(m_out[3], translate);
	return m_out;
}

ijk_inl double4m ijkMatRotateScaleTranslate4dm(double4x4 m_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const scale, double3 const translate)
{
	ijkMatRotateScale4dm(m_out, order, rotateDegXYZ, scale);
	ijkVecCopy3dv(m_out[3], translate);
	return m_out;
}

ijk_inl double4m ijkMatRotateAxisAngleTranslate4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const translate)
{
	ijkMatRotateAxisAngle4dm(m_out, axis_unit, angle_degrees);
	ijkVecCopy3dv(m_out[3], translate);
	return m_out;
}

ijk_inl double4m ijkMatRotateAxisAngleScaleTranslate4dm(double4x4 m_out, double3 const axis_unit, f64 const angle_degrees, double3 const scale, double3 const translate)
{
	ijkMatRotateAxisAngleScale4dm(m_out, axis_unit, angle_degrees, scale);
	ijkVecCopy3dv(m_out[3], translate);
	return m_out;
}

ijk_inl double4km ijkMatGetTranslate4dm(double4x4 const m_in, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return m_in;
}

ijk_inl double4km ijkMatGetRotateTranslate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return ijkMatGetRotate4dm(m_in, order, rotateDegXYZ_out);
}

ijk_inl double4km ijkMatGetScaleTranslate4dm(double4x4 const m_in, double3 scale_out, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return ijkMatGetScale4dm(m_in, scale_out);
}

ijk_inl double4km ijkMatGetRotateScaleTranslate4dm(double4x4 const m_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 scale_out, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return ijkMatGetRotateScale4dm(m_in, order, rotateDegXYZ_out, scale_out);
}

ijk_inl double4km ijkMatGetRotateAxisAngleTranslate4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return ijkMatGetRotateAxisAngle4dm(m_in, axis_unit_out, angle_degrees_out);
}

ijk_inl double4km ijkMatGetRotateAxisAngleScaleTranslate4dm(double4x4 const m_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 scale_out, double3 translate_out)
{
	ijkVecCopy3dv(translate_out, m_in[3]);
	return ijkMatGetRotateAxisAngleScale4dm(m_in, axis_unit_out, angle_degrees_out, scale_out);
}

ijk_inl double4m ijkMatInverseRotateTranslate4dm(double4x4 m_out, double4x4 const m_in)
{
	ijkMatInverseRotate4dm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl double4m ijkMatInverseScaleTranslate4dm(double4x4 m_out, double4x4 const m_in)
{
	ijkMatInverseScale4dm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl double4m ijkMatInverseRotateScaleTranslate4dm(double4x4 m_out, double4x4 const m_in)
{
	ijkMatInverseRotateScale4dm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl double4m ijkMatInverseTransposeTranslate4dm(double4x4 m_out, double4x4 const m_in)
{
	ijkMatInverseTranspose4dm(m_out, m_in);
	ijkVecCopy3dv(m_out[3], m_in[3]);
	return m_out;
}

ijk_inl double4m ijkMatLookAt4dm(double4x4 m_out, double4x4 m_inv_out_opt, double3 const origin, double3 const target, double3 const calibUnit, ijkTransformBasis const calibAxis)
{
	// right-handed: direction basis is from target to center, side = up x dir, up = dir x side, pos = orig
	uindex const up = calibAxis % 3, dir = (up + 1) % 3, side = (up + 2) % 3, pos = ijkTransformOrig;
	ijkVecSub3dv(m_out[dir], origin, target);
	ijkVecNormalize3dv(m_out[dir], m_out[dir]);
	ijkVecCrossNormalize3dv(m_out[side], calibUnit, m_out[dir]);
	ijkVecCross3dv(m_out[up], m_out[dir], m_out[side]);
	ijkVecCopy3dv(m_out[pos], origin);
	if (m_inv_out_opt)
		ijkMatInverseRotateTranslate4dm(m_inv_out_opt, m_out);
	return m_out;
}

ijk_inl double4m ijkMatProjectionPerspective4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const fovyDeg, f64 const aspect, f64 const nearDist, f64 const farDist)
{
	if (m_out && fovyDeg > dbl_zero && fovyDeg < dbl_180 && aspect > dbl_zero && nearDist > dbl_zero && farDist > nearDist)
	{
		// top of near plane is calculated using tan(theta/2)
		// store half angle then use it to calculate top
		// t = n*tan(a/2)
		// r = t*aspect
		// y1 = n/t = n/(n*tan(a/2)) = 1/tan(a/2) = cot(a/2)
		// x0 = n/r = n/(t*aspect) = (n/t)/aspect = y1/aspect
		f64 const halfAngle = dbl_half * fovyDeg;
		f64 const farToNearInv = dbl_one / (nearDist - farDist);
		m_out[1][1] = ijkTrigCot_deg_dbl(halfAngle);
		m_out[0][0] = m_out[1][1] / aspect;
		m_out[2][2] = (nearDist + farDist) * farToNearInv;
		m_out[2][3] = -dbl_one;
		m_out[3][2] = dbl_two * nearDist * farDist * farToNearInv;

		// the rest are zero
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[3][0] = m_out[3][1] = m_out[3][3] = m_out[2][0] = m_out[2][1] = dbl_zero;

		// inverse
		if (m_inv_out_opt)
		{
			// t = n*tan(a/2) = n*sin(a/2)/cos(a/2)
			// r = t*aspect
			// y1 = t/n = (n*tan(a/2))/n = tan(a/2)
			// x0 = r/n = (t*aspect)/n = aspect*(t/n) = y1*aspect
			f64 const doubleNearFarInv = dbl_half / (nearDist * farDist);
			m_inv_out_opt[1][1] = dbl_one / m_out[1][1];
			m_inv_out_opt[0][0] = m_inv_out_opt[1][1] * aspect;
			m_inv_out_opt[2][3] = (nearDist - farDist) * doubleNearFarInv;
			m_inv_out_opt[3][2] = -dbl_one;
			m_inv_out_opt[3][3] = (nearDist + farDist) * doubleNearFarInv;

			// zeros
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][2] = m_inv_out_opt[3][0] = m_inv_out_opt[3][1] = dbl_zero;
		}
	}
	return m_out;
}

ijk_inl double4m ijkMatProjectionParallel4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const fovyDeg, f64 const aspect, f64 const nearDist, f64 const farDist)
{
	if (m_out && fovyDeg > dbl_zero && fovyDeg < dbl_180 && aspect > dbl_zero && nearDist > dbl_zero && farDist > nearDist)
	{
		f64 const halfAngle = dbl_half * fovyDeg;
		f64 const farToNearInv = dbl_one / (nearDist - farDist);
		m_out[1][1] = ijkTrigCot_deg_dbl(halfAngle);
		m_out[0][0] = m_out[1][1] / aspect;
		m_out[2][2] = dbl_two * farToNearInv;
		m_out[3][2] = (nearDist + farDist) * farToNearInv;
		m_out[3][3] = dbl_one;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = dbl_zero;

		if (m_inv_out_opt)
		{
			m_inv_out_opt[1][1] = dbl_one / m_out[1][1];
			m_inv_out_opt[0][0] = m_inv_out_opt[1][1] * aspect;
			m_inv_out_opt[2][2] = dbl_half * (nearDist - farDist);
			m_inv_out_opt[3][2] = -dbl_half * (nearDist + farDist);
			m_inv_out_opt[3][3] = dbl_one;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][3] = m_inv_out_opt[3][0] = m_inv_out_opt[3][1] = dbl_zero;
		}
	}
	return m_out;
}

ijk_inl double4m ijkMatProjectionPerspectivePlanes4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const leftDist, f64 const rightDist, f64 const bottomDist, f64 const topDist, f64 const nearDist, f64 const farDist)
{
	if (m_out && leftDist != rightDist && bottomDist != topDist && nearDist > dbl_zero && farDist > nearDist)
	{
		f64 const leftToRightInv = dbl_one / (rightDist - leftDist);
		f64 const bottomToTopInv = dbl_one / (topDist - bottomDist);
		f64 const farToNearInv = dbl_one / (nearDist - farDist);
		f64 const doubleNear = nearDist + nearDist;
		m_out[0][0] = doubleNear * leftToRightInv;
		m_out[1][1] = doubleNear * bottomToTopInv;
		m_out[2][0] = (rightDist + leftDist) * leftToRightInv;
		m_out[2][1] = (topDist + bottomDist) * bottomToTopInv;
		m_out[2][2] = (nearDist + farDist) * farToNearInv;
		m_out[2][3] = -dbl_one;
		m_out[3][2] = doubleNear * farDist * farToNearInv;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[3][0] = m_out[3][1] = m_out[3][3] = dbl_zero;

		if (m_inv_out_opt)
		{
			f64 const doubleNearInv = dbl_half / nearDist;
			f64 const doubleNearFarInv = dbl_half / (nearDist * farDist);
			m_inv_out_opt[3][0] = (rightDist - leftDist) * doubleNearInv;
			m_inv_out_opt[3][1] = (topDist - bottomDist) * doubleNearInv;
			m_inv_out_opt[2][3] = (nearDist - farDist) * doubleNearFarInv;
			m_inv_out_opt[3][0] = (rightDist + leftDist) * doubleNearInv;
			m_inv_out_opt[3][1] = (topDist + bottomDist) * doubleNearInv;
			m_inv_out_opt[3][2] = -dbl_one;
			m_inv_out_opt[3][3] = (nearDist + farDist) * doubleNearFarInv;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][2] = dbl_zero;
		}
	}
	return m_out;
}

ijk_inl double4m ijkMatProjectionParallelPlanes4dm(double4x4 m_out, double4x4 m_inv_out_opt, f64 const leftDist, f64 const rightDist, f64 const bottomDist, f64 const topDist, f64 const nearDist, f64 const farDist)
{
	if (m_out && leftDist != rightDist && bottomDist != topDist && nearDist != farDist)
	{
		f64 const leftToRightInv = dbl_one / (rightDist - leftDist);
		f64 const bottomToTopInv = dbl_one / (topDist - bottomDist);
		f64 const farToNearInv = dbl_one / (nearDist - farDist);
		m_out[0][0] = leftToRightInv + leftToRightInv;
		m_out[1][1] = bottomToTopInv + bottomToTopInv;
		m_out[2][2] = farToNearInv + farToNearInv;
		m_out[3][0] = -(rightDist + leftDist) * leftToRightInv;
		m_out[3][1] = -(topDist + bottomDist) * bottomToTopInv;
		m_out[3][2] = (nearDist + farDist) * farToNearInv;
		m_out[3][3] = dbl_one;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = dbl_zero;

		if (m_inv_out_opt)
		{
			m_inv_out_opt[0][0] = dbl_half * (rightDist - leftDist);
			m_inv_out_opt[1][1] = dbl_half * (topDist - bottomDist);
			m_inv_out_opt[2][2] = dbl_half * (nearDist - farDist);
			m_inv_out_opt[3][0] = dbl_half * (rightDist + leftDist);
			m_inv_out_opt[3][1] = dbl_half * (topDist + bottomDist);
			m_inv_out_opt[3][2] = -dbl_half * (nearDist + farDist);
			m_inv_out_opt[3][3] = dbl_one;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][3] = dbl_zero;
		}
	}
	return m_out;
}

ijk_inl double4m ijkMatProjectionStereoConversion4dm(double4x4 m_left_out, double4x4 m_right_out, double4x4 m_left_inv_out_opt, double4x4 m_right_inv_out_opt, f64 const interocularDist, f64 const convergenceDist)
{
	if (interocularDist > dbl_zero && convergenceDist > dbl_zero)
	{
		f64 const dx3 = dbl_half * interocularDist, dx2 = dx3 / convergenceDist;
		if (m_left_out)
		{
			ijkMatInit4dm(m_left_out);
			m_left_out[3][0] = +dx3;
			m_left_out[2][0] = +dx2;
		}
		if (m_right_out)
		{
			ijkMatInit4dm(m_right_out);
			m_right_out[3][0] = -dx3;
			m_right_out[2][0] = -dx2;
		}
		if (m_left_inv_out_opt)
		{
			ijkMatInit4dm(m_left_inv_out_opt);
			m_left_inv_out_opt[3][0] = -dx3;
			m_left_inv_out_opt[2][0] = -dx2;
		}
		if (m_right_inv_out_opt)
		{
			ijkMatInit4dm(m_right_inv_out_opt);
			m_right_inv_out_opt[3][0] = +dx3;
			m_right_inv_out_opt[2][0] = +dx2;
		}
	}
	return m_left_out;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkMatDeterminant2d(dmat2 const m_in)
{
	return ijkVecCross2d(m_in.c0, m_in.c1);
}

ijk_inl double ijkMatDeterminantInv2d(dmat2 const m_in)
{
	double const s = ijkMatDeterminant2d(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl double ijkMatDeterminantInvSafe2d(dmat2 const m_in)
{
	double const s = ijkMatDeterminant2d(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl double ijkMatMulRowVec2d(dmat2 const m_in, dvec2 const v_in, index const row)
{
	return (m_in.c0.xy[row] * v_in.x + m_in.c1.xy[row] * v_in.y);
}

ijk_inl dvec2 ijkMatGetRow2d(dmat2 const m_in, index const row)
{
	dvec2 const v_out = {
		m_in.c0.xy[row],
		m_in.c1.xy[row],
	};
	return v_out;
}

ijk_inl dmat2 ijkMatTranspose2d(dmat2 const m_in)
{
	dmat2 const m_out = {
		m_in.x0, m_in.x1,
		m_in.y0, m_in.y1,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatTransposeMul2ds(dmat2 const m_in, double const s)
{
	dmat2 const m_out = {
		(s * m_in.x0), (s * m_in.x1),
		(s * m_in.y0), (s * m_in.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatInverse2d(dmat2 const m_in)
{
	// inv = adj/det
	// adj = {{+y1,-y0},{-x1,+x0}}
	double const detInv = ijkMatDeterminantInv2d(m_in);
	dmat2 const adj_det = {
		(+m_in.y1 * detInv), (-m_in.y0 * detInv),
		(-m_in.x1 * detInv), (+m_in.x0 * detInv),
	};
	return adj_det;
}

ijk_inl dmat2 ijkMatInverseSafe2d(dmat2 const m_in)
{
	double const detInv = ijkMatDeterminantInvSafe2d(m_in);
	dmat2 const adj_det = {
		(+m_in.y1 * detInv), (-m_in.y0 * detInv),
		(-m_in.x1 * detInv), (+m_in.x0 * detInv),
	};
	return adj_det;
}

ijk_inl dvec2 ijkMatMulVec2d(dmat2 const m_lh, dvec2 const v_rh)
{
	dvec2 const v_out = {
		ijkMatMulRowVec2d(m_lh, v_rh, 0),
		ijkMatMulRowVec2d(m_lh, v_rh, 1),
	};
	return v_out;
}

ijk_inl dmat2 ijkMatMul2d(dmat2 const m_lh, dmat2 const m_rh)
{
	dmat2 m_out;
	m_out.c0 = ijkMatMulVec2d(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec2d(m_lh, m_rh.c1);
	return m_out;
}

ijk_inl dmat2 ijkMatDiv2d(dmat2 const m_lh, dmat2 const m_rh)
{
	return ijkMatMul2d(m_lh, ijkMatInverse2d(m_rh));
}

ijk_inl dmat2 ijkMatDivSafe2d(dmat2 const m_lh, dmat2 const m_rh)
{
	return ijkMatMul2d(m_lh, ijkMatInverseSafe2d(m_rh));
}

ijk_inl dmat2 ijkMatRotate2d(double const angle_degrees)
{
	dmat2 m_out;
	ijkTrigSinCos_deg_dbl(angle_degrees, m_out.c0.xy + 1, m_out.c0.xy + 0);
	m_out.x1 = -m_out.y0;
	m_out.y1 = +m_out.x0;
	return m_out;
}

ijk_inl dmat2 ijkMatScale2d(double const sx, double const sy)
{
	dmat2 const m_out = {
		sx, dbl_zero,
		dbl_zero, sy,
	};
	return m_out;
}

ijk_inl dmat2 ijkMatRotateScale2d(double const angle_degrees, double const sx, double const sy)
{
	dmat2 m_out;
	ijkTrigSinCos_deg_dbl(angle_degrees, m_out.c0.xy + 1, m_out.c0.xy + 0);
	m_out.x1 = -m_out.y0 * sy;
	m_out.y1 = +m_out.x0 * sy;
	m_out.x0 *= sx;
	m_out.y0 *= sx;
	return m_out;
}

ijk_inl dmat2 ijkMatGetRotate2d(dmat2 const m_in, double* const angle_degrees_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(m_in.y0, m_in.x0);
	return m_in;
}

ijk_inl dmat2 ijkMatGetScale2d(dmat2 const m_in, double* const sx_out, double* const sy_out)
{
	*sx_out = ijkVecLength2d(m_in.c0);
	*sy_out = ijkVecLength2d(m_in.c1);
	return m_in;
}

ijk_inl dmat2 ijkMatGetRotateScale2d(dmat2 const m_in, double* const angle_degrees_out, double* const sx_out, double* const sy_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(m_in.y0, m_in.x0);
	*sx_out = ijkVecLength2d(m_in.c0);
	*sy_out = ijkVecLength2d(m_in.c1);
	return m_in;
}

ijk_inl dmat2 ijkMatInverseRotate2d(dmat2 const m_in)
{
	return ijkMatTranspose2d(m_in);
}

ijk_inl dmat2 ijkMatInverseScale2d(dmat2 const m_in)
{
	dmat2 const m_out = {
		ijk_recip_dbl(m_in.x0),	dbl_zero,
		dbl_zero, ijk_recip_dbl(m_in.y1),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatInverseRotateScale2d(dmat2 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	double const sx2_inv = ijkVecLengthSqInv2d(m_in.c0);
	double const sy2_inv = ijkVecLengthSqInv2d(m_in.c1);
	dmat2 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv),
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv),
	};
	return m_out;
}

ijk_inl dmat2 ijkMatInverseTranspose2d(dmat2 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	double const sx2_inv = ijkVecLengthSqInv2d(m_in.c0);
	double const sy2_inv = ijkVecLengthSqInv2d(m_in.c1);
	dmat2 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.y0 * sx2_inv),
		(m_in.x1 * sy2_inv), (m_in.y1 * sy2_inv),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkMatDeterminant3d(dmat3 const m_in)
{
	// det = dot(c0, cross(c1, c2))
	return ijkVecDot3d(m_in.c0, ijkVecCross3d(m_in.c1, m_in.c2));
}

ijk_inl double ijkMatDeterminantInv3d(dmat3 const m_in)
{
	double const s = ijkMatDeterminant3d(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl double ijkMatDeterminantInvSafe3d(dmat3 const m_in)
{
	double const s = ijkMatDeterminant3d(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl double ijkMatMulRowVec3d(dmat3 const m_in, dvec3 const v_in, index const row)
{
	return (m_in.c0.xyz[row] * v_in.x + m_in.c1.xyz[row] * v_in.y + m_in.c2.xyz[row] * v_in.z);
}

ijk_inl dvec3 ijkMatGetRow3d(dmat3 const m_in, index const row)
{
	dvec3 const v_out = {
		m_in.c0.xyz[row],
		m_in.c1.xyz[row],
		m_in.c2.xyz[row],
	};
	return v_out;
}

ijk_inl dmat3 ijkMatTranspose3d(dmat3 const m_in)
{
	dmat3 const m_out = {
		m_in.x0, m_in.x1, m_in.x2,
		m_in.y0, m_in.y1, m_in.y2,
		m_in.z0, m_in.z1, m_in.z2,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatTransposeMul3ds(dmat3 const m_in, double const s)
{
	dmat3 const m_out = {
		(m_in.x0 * s), (m_in.x1 * s), (m_in.x2 * s),
		(m_in.y0 * s), (m_in.y1 * s), (m_in.y2 * s),
		(m_in.z0 * s), (m_in.z1 * s), (m_in.z2 * s),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatInverse3d(dmat3 const m_in)
{
	double detInv;
	dmat3 cross;
	cross.c0 = ijkVecCross3d(m_in.c1, m_in.c2);
	cross.c1 = ijkVecCross3d(m_in.c2, m_in.c0);
	cross.c2 = ijkVecCross3d(m_in.c0, m_in.c1);
	detInv = ijkVecDot3d(m_in.c0, cross.c0);
	return ijkMatTransposeMul3ds(cross, ijk_recip_dbl(detInv));
}

ijk_inl dmat3 ijkMatInverseSafe3d(dmat3 const m_in)
{
	double detInv;
	dmat3 cross;
	cross.c0 = ijkVecCross3d(m_in.c1, m_in.c2);
	cross.c1 = ijkVecCross3d(m_in.c2, m_in.c0);
	cross.c2 = ijkVecCross3d(m_in.c0, m_in.c1);
	detInv = ijkVecDot3d(m_in.c0, cross.c0);
	return ijkMatTransposeMul3ds(cross, ijk_recip_safe_dbl(detInv));
}

ijk_inl dvec3 ijkMatMulVec3d(dmat3 const m_lh, dvec3 const v_rh)
{
	dvec3 const v_out = {
		ijkMatMulRowVec3d(m_lh, v_rh, 0),
		ijkMatMulRowVec3d(m_lh, v_rh, 1),
		ijkMatMulRowVec3d(m_lh, v_rh, 2),
	};
	return v_out;
}

ijk_inl dmat3 ijkMatMul3d(dmat3 const m_lh, dmat3 const m_rh)
{
	dmat3 m_out;
	m_out.c0 = ijkMatMulVec3d(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec3d(m_lh, m_rh.c1);
	m_out.c2 = ijkMatMulVec3d(m_lh, m_rh.c2);
	return m_out;
}

ijk_inl dmat3 ijkMatDiv3d(dmat3 const m_lh, dmat3 const m_rh)
{
	return ijkMatMul3d(m_lh, ijkMatInverse3d(m_rh));
}

ijk_inl dmat3 ijkMatDivSafe3d(dmat3 const m_lh, dmat3 const m_rh)
{
	return ijkMatMul3d(m_lh, ijkMatInverseSafe3d(m_rh));
}

ijk_inl dmat3 ijkMatRotateXYZ3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems3d(
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz),
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz),
		(+sy), (-sx * cy), (+cx * cy));
}

ijk_inl dmat3 ijkMatRotateYZX3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems3d(
		(+cy * cz), (+sz), (-sy * cz),
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx),
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx));
}

ijk_inl dmat3 ijkMatRotateZXY3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems3d(
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy),
		(-sz * cx), (+cz * cx), (+sx),
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy));
}

ijk_inl dmat3 ijkMatRotateYXZ3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems3d(
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz),
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz),
		(+sy * cx), (-sx), (+cy * cx));
}

ijk_inl dmat3 ijkMatRotateXZY3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems3d(
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy),
		(-sz), (+cx * cz), (+sx * cz),
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy));
}

ijk_inl dmat3 ijkMatRotateZYX3d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems3d(
		(+cz * cy), (+sy * cy), (-sy),
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx),
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx));
}

ijk_inl dmat3 ijkMatGetRotateXYZ3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(+m_in.x2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(-m_in.x1, +m_in.x0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(-m_in.y2, +m_in.z2);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateYZX3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(+m_in.y0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(-m_in.y2, +m_in.y1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(-m_in.z0, +m_in.x0);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateZXY3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(+m_in.z1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(-m_in.z0, +m_in.z2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(-m_in.x1, +m_in.y1);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateYXZ3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(-m_in.y2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(+m_in.x2, +m_in.z2);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(+m_in.y0, +m_in.y1);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateXZY3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(-m_in.x1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(+m_in.z1, +m_in.y1);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(+m_in.x2, +m_in.x0);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateZYX3d(dmat3 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(-m_in.z0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(+m_in.y0, +m_in.x0);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(+m_in.z1, +m_in.z2);
	return m_in;
}

ijk_inl dmat3 ijkMatRotate3d(ijkRotationOrder const order, dvec3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ3d(rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX3d(rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY3d(rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ3d(rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY3d(rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX3d(rotateDegXYZ);
	}
	//return m_out;
}

ijk_inl dmat3 ijkMatScale3d(dvec3 const scale)
{
	dmat3 const m_out = {
		scale.x, dbl_zero, dbl_zero,
		dbl_zero, scale.y, dbl_zero,
		dbl_zero, dbl_zero, scale.z,
	};
	return m_out;
}

ijk_inl dmat3 ijkMatRotateScale3d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale)
{
	dmat3 m_out = ijkMatRotate3d(order, rotateDegXYZ);
	m_out.c0 = ijkVecMul3ds(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul3ds(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul3ds(m_out.c2, scale.z);
	return m_out;
}

ijk_inl dmat3 ijkMatGetRotate3d(dmat3 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ3d(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX3d(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY3d(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ3d(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY3d(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX3d(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl dmat3 ijkMatGetScale3d(dmat3 const m_in, dvec3* const scale_out)
{
	scale_out->x = ijkVecLength3d(m_in.c0);
	scale_out->y = ijkVecLength3d(m_in.c1);
	scale_out->z = ijkVecLength3d(m_in.c2);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateScale3d(dmat3 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out)
{
	dmat3 rot;
	rot.c0 = ijkVecDivSafe3ds(m_in.c0, (scale_out->x = ijkVecLength3d(m_in.c0)));
	rot.c1 = ijkVecDivSafe3ds(m_in.c1, (scale_out->y = ijkVecLength3d(m_in.c1)));
	rot.c2 = ijkVecDivSafe3ds(m_in.c2, (scale_out->z = ijkVecLength3d(m_in.c2)));
	ijkMatGetRotate3d(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl dmat3 ijkMatInverseRotate3d(dmat3 const m_in)
{
	return ijkMatTranspose3d(m_in);
}

ijk_inl dmat3 ijkMatInverseScale3d(dmat3 const m_in)
{
	dmat3 const m_out = {
		ijk_recip_dbl(m_in.x0), dbl_zero, dbl_zero,
		dbl_zero, ijk_recip_dbl(m_in.y1), dbl_zero,
		dbl_zero, dbl_zero, ijk_recip_dbl(m_in.z2),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatInverseRotateScale3d(dmat3 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	double const sx2_inv = ijkVecLengthSqInv3d(m_in.c0);
	double const sy2_inv = ijkVecLengthSqInv3d(m_in.c1);
	double const sz2_inv = ijkVecLengthSqInv3d(m_in.c2);
	dmat3 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv), (m_in.x2 * sz2_inv),
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv), (m_in.y2 * sz2_inv),
		(m_in.z0 * sx2_inv), (m_in.z1 * sy2_inv), (m_in.z2 * sz2_inv),
	};
	return m_out;
}

ijk_inl dmat3 ijkMatInverseTranspose3d(dmat3 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	dmat3 m_out;
	m_out.c0 = ijkVecMul3ds(m_in.c0, ijkVecLengthSqInv3d(m_in.c0));
	m_out.c1 = ijkVecMul3ds(m_in.c1, ijkVecLengthSqInv3d(m_in.c1));
	m_out.c2 = ijkVecMul3ds(m_in.c2, ijkVecLengthSqInv3d(m_in.c2));
	return m_out;
}

ijk_inl dmat3 ijkMatRotateAxisAngle3d(dvec3 const axis_unit, double const angle_degrees)
{
	f64 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f64 const x = axis_unit.x, y = axis_unit.y, z = axis_unit.z;
	ijkTrigSinCos_deg_dbl(angle_degrees, &s, &c);
	t = dbl_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems3d(
		(x * xt + x), (xyt + zs), (zxt - ys),
		(xyt - zs), (y * yt + c), (yzt + xs),
		(zxt + ys), (yzt - xs), (z * zt + c));
}

ijk_inl dmat3 ijkMatRotateAxisAngleScale3d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale)
{
	dmat3 m_out = ijkMatRotateAxisAngle3d(axis_unit, angle_degrees);
	m_out.c0 = ijkVecMul3ds(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul3ds(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul3ds(m_out.c2, scale.z);
	return m_out;
}

ijk_inl dmat3 ijkMatGetRotateAxisAngle3d(dmat3 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out)
{
	double r;
	double const t = (m_in.x0 + m_in.y1 + m_in.z2 - dbl_one);
	dvec3 const axis = {
		(m_in.z1 - m_in.y2),
		(m_in.x2 - m_in.z0),
		(m_in.y0 - m_in.x1),
	};
	r = ijkVecLength3d(axis);
	*axis_unit_out = ijkVecDivSafe3ds(axis, r);
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(r, t);
	return m_in;
}

ijk_inl dmat3 ijkMatGetRotateAxisAngleScale3d(dmat3 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out)
{
	dmat3 rot;
	rot.c0 = ijkVecDivSafe3ds(m_in.c0, (scale_out->x = ijkVecLength3d(m_in.c0)));
	rot.c1 = ijkVecDivSafe3ds(m_in.c1, (scale_out->y = ijkVecLength3d(m_in.c1)));
	rot.c2 = ijkVecDivSafe3ds(m_in.c2, (scale_out->z = ijkVecLength3d(m_in.c2)));
	ijkMatGetRotateAxisAngle3d(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl dmat3 ijkMatLookAt3d(dmat3* const m_inv_out_opt, dvec3 const origin, dvec3 const target, dvec3 const calibUnit, ijkTransformBasis const calibAxis)
{
	dmat3 rot;
	ijkMatLookAt3dm(rot.m, m_inv_out_opt->m, origin.xyz, target.xyz, calibUnit.xyz, calibAxis);
	return rot;
}


//-----------------------------------------------------------------------------

ijk_inl double ijkMatDeterminant4d(dmat4 const m_in)
{
	double det = dbl_zero;
	det += m_in.w0 * ijkVecDot4d(m_in.c1, ijkVecCross4d(m_in.c2, m_in.c3));
	det += m_in.w1 * ijkVecDot4d(m_in.c2, ijkVecCross4d(m_in.c3, m_in.c0));
	det += m_in.w2 * ijkVecDot4d(m_in.c3, ijkVecCross4d(m_in.c0, m_in.c1));
	det += m_in.w3 * ijkVecDot4d(m_in.c0, ijkVecCross4d(m_in.c1, m_in.c2));
	return det;
}

ijk_inl double ijkMatDeterminantInv4d(dmat4 const m_in)
{
	double const s = ijkMatDeterminant4d(m_in);
	return ijk_recip_dbl(s);
}

ijk_inl double ijkMatDeterminantInvSafe4d(dmat4 const m_in)
{
	double const s = ijkMatDeterminant4d(m_in);
	return ijk_recip_safe_dbl(s);
}

ijk_inl double ijkMatMulRowVec4d(dmat4 const m_in, dvec4 const v_in, index const row)
{
	return (m_in.c0.xyzw[row] * v_in.x + m_in.c1.xyzw[row] * v_in.y + m_in.c2.xyzw[row] * v_in.z + m_in.c3.xyzw[row] * v_in.w);
}

ijk_inl dvec4 ijkMatGetRow4d(dmat4 const m_in, index const row)
{
	dvec4 const v_out = {
		m_in.c0.xyzw[row],
		m_in.c1.xyzw[row],
		m_in.c2.xyzw[row],
		m_in.c3.xyzw[row],
	};
	return v_out;
}

ijk_inl dmat4 ijkMatTranspose4d(dmat4 const m_in)
{
	dmat4 const m_out = {
		m_in.x0, m_in.x1, m_in.x2, m_in.x3,
		m_in.y0, m_in.y1, m_in.y2, m_in.y3,
		m_in.z0, m_in.z1, m_in.z2, m_in.z3,
		m_in.w0, m_in.w1, m_in.w2, m_in.w3,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatTransposeMul4ds(dmat4 const m_in, double const s)
{
	dmat4 const m_out = {
		(m_in.x0 * s), (m_in.x1 * s), (m_in.x2 * s), (m_in.x3 * s),
		(m_in.y0 * s), (m_in.y1 * s), (m_in.y2 * s), (m_in.y3 * s),
		(m_in.z0 * s), (m_in.z1 * s), (m_in.z2 * s), (m_in.z3 * s),
		(m_in.w0 * s), (m_in.w1 * s), (m_in.w2 * s), (m_in.w3 * s),
	};
	return m_out;
}

ijk_inl dmat4 ijkMatInverse4d(dmat4 const m_in)
{
	dmat4 m_out;
	ijkMatInverse4dm(m_out.m, m_in.m);
	return m_out;
}

ijk_inl dmat4 ijkMatInverseSafe4d(dmat4 const m_in)
{
	dmat4 m_out;
	ijkMatInverseSafe4dm(m_out.m, m_in.m);
	return m_out;
}

ijk_inl dvec4 ijkMatMulVec4d(dmat4 const m_lh, dvec4 const v_rh)
{
	dvec4 const v_out = {
		ijkMatMulRowVec4d(m_lh, v_rh, 0),
		ijkMatMulRowVec4d(m_lh, v_rh, 1),
		ijkMatMulRowVec4d(m_lh, v_rh, 2),
		ijkMatMulRowVec4d(m_lh, v_rh, 3),
	};
	return v_out;
}

ijk_inl dmat4 ijkMatMul4d(dmat4 const m_lh, dmat4 const m_rh)
{
	dmat4 m_out;
	m_out.c0 = ijkMatMulVec4d(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec4d(m_lh, m_rh.c1);
	m_out.c2 = ijkMatMulVec4d(m_lh, m_rh.c2);
	m_out.c3 = ijkMatMulVec4d(m_lh, m_rh.c3);
	return m_out;
}

ijk_inl dmat4 ijkMatDiv4d(dmat4 const m_lh, dmat4 const m_rh)
{
	return ijkMatMul4d(m_lh, ijkMatInverse4d(m_rh));
}

ijk_inl dmat4 ijkMatDivSafe4d(dmat4 const m_lh, dmat4 const m_rh)
{
	return ijkMatMul4d(m_lh, ijkMatInverseSafe4d(m_rh));
}

ijk_inl dmat4 ijkMatRotateXYZ4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems4d(
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz), dbl_zero,
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz), dbl_zero,
		(+sy), (-sx * cy), (+cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateYZX4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems4d(
		(+cy * cz), (+sz), (-sy * cz), dbl_zero,
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx), dbl_zero,
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateZXY4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems4d(
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy), dbl_zero,
		(-sz * cx), (+cz * cx), (+sx), dbl_zero,
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateYXZ4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems4d(
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz), dbl_zero,
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz), dbl_zero,
		(+sy * cx), (-sx), (+cy * cx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateXZY4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems4d(
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy), dbl_zero,
		(-sz), (+cx * cz), (+sx * cz), dbl_zero,
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateZYX4d(dvec3 const rotateDegXYZ)
{
	f64 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems4d(
		(+cz * cy), (+sy * cy), (-sy), dbl_zero,
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx), dbl_zero,
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatGetRotateXYZ4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(+m_in.x2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(-m_in.x1, +m_in.x0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(-m_in.y2, +m_in.z2);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateYZX4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(+m_in.y0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(-m_in.y2, +m_in.y1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(-m_in.z0, +m_in.x0);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateZXY4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(+m_in.z1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(-m_in.z0, +m_in.z2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(-m_in.x1, +m_in.y1);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateYXZ4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(-m_in.y2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(+m_in.x2, +m_in.z2);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(+m_in.y0, +m_in.y1);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateXZY4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(-m_in.x1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(+m_in.z1, +m_in.y1);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(+m_in.x2, +m_in.x0);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateZYX4d(dmat4 const m_in, dvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(-m_in.z0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(+m_in.y0, +m_in.x0);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(+m_in.z1, +m_in.z2);
	return m_in;
}

ijk_inl dmat4 ijkMatRotate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ4d(rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX4d(rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY4d(rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ4d(rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY4d(rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX4d(rotateDegXYZ);
	}
	//return m_out;
}

ijk_inl dmat4 ijkMatScale4d(dvec3 const scale)
{
	dmat4 const m_out = {
		scale.x, dbl_zero, dbl_zero, dbl_zero,
		dbl_zero, scale.y, dbl_zero, dbl_zero,
		dbl_zero, dbl_zero, scale.z, dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatRotateScale4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale)
{
	dmat4 m_out = ijkMatRotate4d(order, rotateDegXYZ);
	m_out.c0 = ijkVecMul4ds(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul4ds(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul4ds(m_out.c2, scale.z);
	return m_out;
}

ijk_inl dmat4 ijkMatGetRotate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ4d(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX4d(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY4d(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ4d(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY4d(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX4d(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl dmat4 ijkMatGetScale4d(dmat4 const m_in, dvec3* const scale_out)
{
	scale_out->x = ijkVecLength3dv(m_in.c0.xyz);
	scale_out->y = ijkVecLength3dv(m_in.c1.xyz);
	scale_out->z = ijkVecLength3dv(m_in.c2.xyz);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateScale4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out)
{
	dmat4 rot;
	rot.c0 = ijkVecDivSafe4ds(m_in.c0, (scale_out->x = ijkVecLength3dv(m_in.c0.xyz)));
	rot.c1 = ijkVecDivSafe4ds(m_in.c1, (scale_out->y = ijkVecLength3dv(m_in.c1.xyz)));
	rot.c2 = ijkVecDivSafe4ds(m_in.c2, (scale_out->z = ijkVecLength3dv(m_in.c2.xyz)));
	ijkMatGetRotate4d(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl dmat4 ijkMatInverseRotate4d(dmat4 const m_in)
{
	return ijkMatTranspose4d(m_in);
}

ijk_inl dmat4 ijkMatInverseScale4d(dmat4 const m_in)
{
	dmat4 const m_out = {
		ijk_recip_dbl(m_in.x0), dbl_zero, dbl_zero, dbl_zero,
		dbl_zero, ijk_recip_dbl(m_in.y1), dbl_zero, dbl_zero,
		dbl_zero, dbl_zero, ijk_recip_dbl(m_in.z2), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatInverseRotateScale4d(dmat4 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	double const sx2_inv = ijkVecLengthSqInv4d(m_in.c0);
	double const sy2_inv = ijkVecLengthSqInv4d(m_in.c1);
	double const sz2_inv = ijkVecLengthSqInv4d(m_in.c2);
	dmat4 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv), (m_in.x2 * sz2_inv), dbl_zero,
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv), (m_in.y2 * sz2_inv), dbl_zero,
		(m_in.z0 * sx2_inv), (m_in.z1 * sy2_inv), (m_in.z2 * sz2_inv), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkMatInverseTranspose4d(dmat4 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	dmat4 m_out;
	m_out.c0 = ijkVecMul4ds(m_in.c0, ijkVecLengthSqInv4d(m_in.c0));
	m_out.c1 = ijkVecMul4ds(m_in.c1, ijkVecLengthSqInv4d(m_in.c1));
	m_out.c2 = ijkVecMul4ds(m_in.c2, ijkVecLengthSqInv4d(m_in.c2));
	m_out.c3 = ijkVecInitElems4d(dbl_zero, dbl_zero, dbl_zero, dbl_one);
	return m_out;
}

ijk_inl dmat4 ijkMatRotateAxisAngle4d(dvec3 const axis_unit, double const angle_degrees)
{
	f64 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f64 const x = axis_unit.x, y = axis_unit.y, z = axis_unit.z;
	ijkTrigSinCos_deg_dbl(angle_degrees, &s, &c);
	t = dbl_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems4d(
		(x * xt + x), (xyt + zs), (zxt - ys), dbl_zero,
		(xyt - zs), (y * yt + c), (yzt + xs), dbl_zero,
		(zxt + ys), (yzt - xs), (z * zt + c), dbl_zero,
		dbl_zero, dbl_zero, dbl_zero, dbl_one);
}

ijk_inl dmat4 ijkMatRotateAxisAngleScale4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale)
{
	dmat4 m_out = ijkMatRotateAxisAngle4d(axis_unit, angle_degrees);
	m_out.c0 = ijkVecMul4ds(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul4ds(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul4ds(m_out.c2, scale.z);
	return m_out;
}

ijk_inl dmat4 ijkMatGetRotateAxisAngle4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out)
{
	double r;
	double const t = (m_in.x0 + m_in.y1 + m_in.z2 - dbl_one);
	dvec3 const axis = {
		(m_in.z1 - m_in.y2),
		(m_in.x2 - m_in.z0),
		(m_in.y0 - m_in.x1),
	};
	r = ijkVecLength3d(axis);
	*axis_unit_out = ijkVecDivSafe3ds(axis, r);
	*angle_degrees_out = ijkTrigAtan2_deg_dbl(r, t);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateAxisAngleScale4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out)
{
	dmat4 rot;
	rot.c0 = ijkVecDivSafe4ds(m_in.c0, (scale_out->x = ijkVecLength3dv(m_in.c0.xyz)));
	rot.c1 = ijkVecDivSafe4ds(m_in.c1, (scale_out->y = ijkVecLength3dv(m_in.c1.xyz)));
	rot.c2 = ijkVecDivSafe4ds(m_in.c2, (scale_out->z = ijkVecLength3dv(m_in.c2.xyz)));
	ijkMatGetRotateAxisAngle4d(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl dmat4 ijkMatTranslate4d(dvec3 const translate)
{
	dmat4 m_out;
	m_out.c0 = dvec4_x;
	m_out.c1 = dvec4_y;
	m_out.c2 = dvec4_z;
	m_out.c3 = ijkVecCopy4dw(translate, dbl_one);
	return m_out;
}

ijk_inl dmat4 ijkMatRotateTranslate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const translate)
{
	dmat4 m_out = ijkMatRotate4d(order, rotateDegXYZ);
	ijkVecCopy3dv(m_out.c3.xyz, translate.xyz);
	return m_out;
}

ijk_inl dmat4 ijkMatScaleTranslate4d(dvec3 const scale, dvec3 const translate)
{
	dmat4 m_out = ijkMatScale4d(scale);
	ijkVecCopy3dv(m_out.c3.xyz, translate.xyz);
	return m_out;
}

ijk_inl dmat4 ijkMatRotateScaleTranslate4d(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const scale, dvec3 const translate)
{
	dmat4 m_out = ijkMatRotateScale4d(order, rotateDegXYZ, scale);
	ijkVecCopy3dv(m_out.c3.xyz, translate.xyz);
	return m_out;
}

ijk_inl dmat4 ijkMatRotateAxisAngleTranslate4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const translate)
{
	dmat4 m_out = ijkMatRotateAxisAngle4d(axis_unit, angle_degrees);
	ijkVecCopy3dv(m_out.c3.xyz, translate.xyz);
	return m_out;
}

ijk_inl dmat4 ijkMatRotateAxisAngleScaleTranslate4d(dvec3 const axis_unit, double const angle_degrees, dvec3 const scale, dvec3 const translate)
{
	dmat4 m_out = ijkMatRotateAxisAngleScale4d(axis_unit, angle_degrees, scale);
	ijkVecCopy3dv(m_out.c3.xyz, translate.xyz);
	return m_out;
}

ijk_inl dmat4 ijkMatGetTranslate4d(dmat4 const m_in, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return m_in;
}

ijk_inl dmat4 ijkMatGetRotateTranslate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return ijkMatGetRotate4d(m_in, order, rotateDegXYZ_out);
}

ijk_inl dmat4 ijkMatGetScaleTranslate4d(dmat4 const m_in, dvec3* const scale_out, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return ijkMatGetScale4d(m_in, scale_out);
}

ijk_inl dmat4 ijkMatGetRotateScaleTranslate4d(dmat4 const m_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const scale_out, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return ijkMatGetRotateScale4d(m_in, order, rotateDegXYZ_out, scale_out);
}

ijk_inl dmat4 ijkMatGetRotateAxisAngleTranslate4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return ijkMatGetRotateAxisAngle4d(m_in, axis_unit_out, angle_degrees_out);
}

ijk_inl dmat4 ijkMatGetRotateAxisAngleScaleTranslate4d(dmat4 const m_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const scale_out, dvec3* const translate_out)
{
	ijkVecCopy3dv(translate_out->xyz, m_in.c3.xyz);
	return ijkMatGetRotateAxisAngleScale4d(m_in, axis_unit_out, angle_degrees_out, scale_out);
}

ijk_inl dmat4 ijkMatInverseRotateTranslate4d(dmat4 const m_in)
{
	dmat4 m_out = ijkMatInverseRotate4d(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl dmat4 ijkMatInverseScaleTranslate4d(dmat4 const m_in)
{
	dmat4 m_out = ijkMatInverseScale4d(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl dmat4 ijkMatInverseRotateScaleTranslate4d(dmat4 const m_in)
{
	dmat4 m_out = ijkMatInverseRotateScale4d(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl dmat4 ijkMatInverseTransposeTranslate4d(dmat4 const m_in)
{
	dmat4 m_out = ijkMatInverseTranspose4d(m_in);
	m_out.c3 = m_in.c3;
	return m_out;
}

ijk_inl dmat4 ijkMatLookAt4d(dmat4* const m_inv_out_opt, dvec3 const origin, dvec3 const target, dvec3 const calibUnit, ijkTransformBasis const calibAxis)
{
	dmat4 rot;
	ijkMatLookAt4dm(rot.m, m_inv_out_opt->m, origin.xyz, target.xyz, calibUnit.xyz, calibAxis);
	return rot;
}

ijk_inl dmat4 ijkMatProjectionPerspective4d(dmat4* const m_inv_out_opt, double const fovyDeg, double const aspect, double const nearDist, double const farDist)
{
	dmat4 m_out;
	ijkMatProjectionPerspective4dm(m_out.m, (double4m)m_inv_out_opt, fovyDeg, aspect, nearDist, farDist);
	return m_out;
}

ijk_inl dmat4 ijkMatProjectionParallel4d(dmat4* const m_inv_out_opt, double const fovyDeg, double const aspect, double const nearDist, double const farDist)
{
	dmat4 m_out;
	ijkMatProjectionParallel4dm(m_out.m, (double4m)m_inv_out_opt, fovyDeg, aspect, nearDist, farDist);
	return m_out;
}

ijk_inl dmat4 ijkMatProjectionPerspectivePlanes4d(dmat4* const m_inv_out_opt, double const leftDist, double const rightDist, double const bottomDist, double const topDist, double const nearDist, double const farDist)
{
	dmat4 m_out;
	ijkMatProjectionPerspectivePlanes4dm(m_out.m, (double4m)m_inv_out_opt, leftDist, rightDist, bottomDist, topDist, nearDist, farDist);
	return m_out;
}

ijk_inl dmat4 ijkMatProjectionParallelPlanes4d(dmat4* const m_inv_out_opt, double const leftDist, double const rightDist, double const bottomDist, double const topDist, double const nearDist, double const farDist)
{
	dmat4 m_out;
	ijkMatProjectionParallelPlanes4dm(m_out.m, (double4m)m_inv_out_opt, leftDist, rightDist, bottomDist, topDist, nearDist, farDist);
	return m_out;
}

ijk_inl dmat4 ijkMatProjectionStereoConversion4d(dmat4* const m_left_out, dmat4* const m_right_out, dmat4* const m_left_inv_out_opt, dmat4* const m_right_inv_out_opt, double const interocularDist, double const convergenceDist)
{
	ijkMatProjectionStereoConversion4dm((double4m)m_left_out, (double4m)m_right_out, (double4m)m_left_inv_out_opt, (double4m)m_right_inv_out_opt, interocularDist, convergenceDist);
	return *m_left_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_DOUBLE_INL_
#endif	// _IJK_MATRIX_DOUBLE_H_