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

	ijkMatrix_float.inl
	Inline definitions for float matrix types.
*/

#ifdef _IJK_MATRIX_FLOAT_H_
#ifndef _IJK_MATRIX_FLOAT_INL_
#define _IJK_MATRIX_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl float2m ijkMatInit2fm(float2x2 m_out)
{
	m_out[0][0] = m_out[1][1] = flt_one;
	m_out[0][1] = m_out[1][0] = flt_zero;
	return m_out;
}

ijk_inl float2m ijkMatInitElems2fm(float2x2 m_out, f32 const x0, f32 const y0, f32 const x1, f32 const y1)
{
	m_out[0][0] = x0;
	m_out[0][1] = y0;
	m_out[1][0] = x1;
	m_out[1][1] = y1;
	return m_out;
}

ijk_inl float2m ijkMatInitVecs2fm(float2x2 m_out, float2 const c0, float2 const c1)
{
	m_out[0][0] = c0[0];
	m_out[0][1] = c0[1];
	m_out[1][0] = c1[0];
	m_out[1][1] = c1[1];
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm2(float2x2 m_out, float2x2 const m_in)
{
	m_out[0][0] = m_in[0][0];
	m_out[0][1] = m_in[0][1];
	m_out[1][0] = m_in[1][0];
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm3(float2x2 m_out, float3x3 const m_in)
{
	m_out[0][0] = m_in[0][0];
	m_out[0][1] = m_in[0][1];
	m_out[1][0] = m_in[1][0];
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm4(float2x2 m_out, float4x4 const m_in)
{
	m_out[0][0] = m_in[0][0];
	m_out[0][1] = m_in[0][1];
	m_out[1][0] = m_in[1][0];
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatCopy2fms(float2x2 m_out, f32 const s_diag)
{
	m_out[0][0] = m_out[1][1] = s_diag;
	m_out[0][1] = m_out[1][0] = flt_zero;
	return m_out;
}

ijk_inl float2m ijkMatMul2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	m_out[0][0] = m_lh[0][0] * s_rh;
	m_out[0][1] = m_lh[0][1] * s_rh;
	m_out[1][0] = m_lh[1][0] * s_rh;
	m_out[1][1] = m_lh[1][1] * s_rh;
	return m_out;
}

ijk_inl float2m ijkMatDiv2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	m_out[0][0] = m_lh[0][0] * s;
	m_out[0][1] = m_lh[0][1] * s;
	m_out[1][0] = m_lh[1][0] * s;
	m_out[1][1] = m_lh[1][1] * s;
	return m_out;
}

ijk_inl float2m ijkMatDivSafe2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	m_out[0][0] = m_lh[0][0] * s;
	m_out[0][1] = m_lh[0][1] * s;
	m_out[1][0] = m_lh[1][0] * s;
	m_out[1][1] = m_lh[1][1] * s;
	return m_out;
}

ijk_inl float2m ijkMatMul2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	m_out[0][0] = s_lh * m_rh[0][0];
	m_out[0][1] = s_lh * m_rh[0][1];
	m_out[1][0] = s_lh * m_rh[1][0];
	m_out[1][1] = s_lh * m_rh[1][1];
	return m_out;
}

ijk_inl float2m ijkMatDiv2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	m_out[0][0] = s_lh / m_rh[0][0];
	m_out[0][1] = s_lh / m_rh[0][1];
	m_out[1][0] = s_lh / m_rh[1][0];
	m_out[1][1] = s_lh / m_rh[1][1];
	return m_out;
}

ijk_inl float2m ijkMatDivSafe2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	m_out[0][0] = ijk_divide_safe_flt(s_lh, m_rh[0][0]);
	m_out[0][1] = ijk_divide_safe_flt(s_lh, m_rh[0][1]);
	m_out[1][0] = ijk_divide_safe_flt(s_lh, m_rh[1][0]);
	m_out[1][1] = ijk_divide_safe_flt(s_lh, m_rh[1][1]);
	return m_out;
}

ijk_inl float2m ijkMatAdd2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	m_out[0][0] = m_lh[0][0] + m_rh[0][0];
	m_out[0][1] = m_lh[0][1] + m_rh[0][1];
	m_out[1][0] = m_lh[1][0] + m_rh[1][0];
	m_out[1][1] = m_lh[1][1] + m_rh[1][1];
	return m_out;
}

ijk_inl float2m ijkMatSub2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	m_out[0][0] = m_lh[0][0] - m_rh[0][0];
	m_out[0][1] = m_lh[0][1] - m_rh[0][1];
	m_out[1][0] = m_lh[1][0] - m_rh[1][0];
	m_out[1][1] = m_lh[1][1] - m_rh[1][1];
	return m_out;
}


//-----------------------------------------------------------------------------

// 3D array-based


//-----------------------------------------------------------------------------

// 4D array-based


//-----------------------------------------------------------------------------

ijk_inl fmat2 ijkMatInit2f()
{
	fmat2 const m_out = {
		flt_one, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInitElems2f(float const x0, float const y0, float const x1, float const y1)
{
	fmat2 const m_out = {
		x0, y0, x1, y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInitVecs2f(fvec2 const c0, fvec2 const c1)
{
	fmat2 const m_out = {
		c0.x, c0.y, c1.x, c1.y,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f2(fmat2 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0, m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f3(fmat3 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0, m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f4(fmat4 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0, m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2fs(float const s_diag)
{
	fmat2 const m_out = {
		s_diag, flt_zero, flt_zero, s_diag,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatMul2fs(fmat2 const m_lh, float const s_rh)
{
	fmat2 const m_out = {
		m_lh.m00 * s_rh,
		m_lh.m01 * s_rh,
		m_lh.m10 * s_rh,
		m_lh.m11 * s_rh,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDiv2fs(fmat2 const m_lh, float const s_rh)
{
	float const s = ijk_recip_flt(s_rh);
	fmat2 const m_out = {
		m_lh.m00 * s,
		m_lh.m01 * s,
		m_lh.m10 * s,
		m_lh.m11 * s,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDivSafe2fs(fmat2 const m_lh, float const s_rh)
{
	float const s = ijk_recip_safe_flt(s_rh);
	fmat2 const m_out = {
		m_lh.m00 * s,
		m_lh.m01 * s,
		m_lh.m10 * s,
		m_lh.m11 * s,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatMul2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		s_lh * m_rh.m00,
		s_lh * m_rh.m01,
		s_lh * m_rh.m10,
		s_lh * m_rh.m11,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDiv2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		s_lh / m_rh.m00,
		s_lh / m_rh.m01,
		s_lh / m_rh.m10,
		s_lh / m_rh.m11,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDivSafe2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		ijk_divide_safe_flt(s_lh, m_rh.m00),
		ijk_divide_safe_flt(s_lh, m_rh.m01),
		ijk_divide_safe_flt(s_lh, m_rh.m10),
		ijk_divide_safe_flt(s_lh, m_rh.m11),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatAdd2f(fmat2 const m_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		m_lh.m00 + m_rh.m00,
		m_lh.m01 + m_rh.m01,
		m_lh.m10 + m_rh.m10,
		m_lh.m11 + m_rh.m11,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatSub2f(fmat2 const m_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		m_lh.m00 - m_rh.m00,
		m_lh.m01 - m_rh.m01,
		m_lh.m10 - m_rh.m10,
		m_lh.m11 - m_rh.m11,
	};
	return m_out;
}


//-----------------------------------------------------------------------------

// 3D struct-based


//-----------------------------------------------------------------------------

// 4D struct-based


//-----------------------------------------------------------------------------

ijk_inl f32 ijkMatDeterminant2fm(float2x2 const m_in)
{
	return ijkVecCross2fv(m_in[0], m_in[1]);
}

ijk_inl f32 ijkMatDeterminantInv2fm(float2x2 const m_in)
{
	f32 const s = ijkMatDeterminant2fm(m_in);
	return ijk_recip_flt(s);
}

ijk_inl f32 ijkMatDeterminantInvSafe2fm(float2x2 const m_in)
{
	f32 const s = ijkMatDeterminant2fm(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl f32 ijkMatMulRowVec2fm(float2x2 const m_in, float2 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1]);
}

ijk_inl floatv ijkMatGetRow2fm(float2 v_out, float2x2 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	return v_out;
}

ijk_inl float2m ijkMatTranspose2fm(float2x2 m_out, float2x2 const m_in)
{
	f32 const m01 = m_in[0][1];
	m_out[0][0] = m_in[0][0];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = m01;
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatInverse2fm(float2x2 m_out, float2x2 const m_in)
{
	// inv = adj/det
	// adj = {{+m11,-m01},{-m10,+m00}}
	f32 const detInv = ijkMatDeterminantInv2fm(m_in);
	float2x2 const adj_det = {
		+m_in[1][1] * detInv,
		-m_in[0][1] * detInv,
		-m_in[1][0] * detInv,
		+m_in[0][0] * detInv,
	};
	return ijkMatCopy2fm2(m_out, adj_det);
}

ijk_inl float2m ijkMatInverseSafe2fm(float2x2 m_out, float2x2 const m_in)
{
	f32 const detInv = ijkMatDeterminantInvSafe2fm(m_in);
	float2x2 const adj_det = {
		+m_in[1][1] * detInv,
		-m_in[0][1] * detInv,
		-m_in[1][0] * detInv,
		+m_in[0][0] * detInv,
	};
	return ijkMatCopy2fm2(m_out, adj_det);
}

ijk_inl floatv ijkMatMulVec2fmv(float2 v_out, float2x2 const m_lh, float2 const v_rh)
{
	float2 const v_copy = {
		ijkMatMulRowVec2fm(m_lh, v_rh, 0),
		ijkMatMulRowVec2fm(m_lh, v_rh, 1),
	};
	return ijkVecCopy2fv(v_out, v_copy);
}

ijk_inl float2m ijkMatMul2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	ijkMatMulVec2fmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMulVec2fmv(m_out[1], m_lh, m_rh[1]);
	return m_out;
}

ijk_inl float2m ijkMatDiv2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	float2x2 inv_rh;
	return ijkMatMul2fm(m_out, m_lh, ijkMatInverse2fm(inv_rh, m_rh));
}

ijk_inl float2m ijkMatDivSafe2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	float2x2 inv_rh;
	return ijkMatMul2fm(m_out, m_lh, ijkMatInverseSafe2fm(inv_rh, m_rh));
}

ijk_inl float2m ijkMatRotate2fm(float2x2 m_out, f32 const angle_degrees)
{
	ijkTrigSinCos_deg_flt(angle_degrees, m_out[0] + 1, m_out[0] + 0);
	m_out[1][0] = -m_out[0][1];
	m_out[1][1] = +m_out[0][0];
	return m_out;
}

ijk_inl float2m ijkMatScale2fm(float2x2 m_out, f32 const sx, f32 const sy)
{
	m_out[0][0] = sx;
	m_out[1][1] = sy;
	m_out[0][1] = m_out[1][0] = flt_zero;
	return m_out;
}

ijk_inl float2m ijkMatRotateScale2fm(float2x2 m_out, f32 const angle_degrees, f32 const sx, f32 const sy)
{
	ijkTrigSinCos_deg_flt(angle_degrees, m_out[0] + 1, m_out[0] + 0);
	m_out[1][0] = -m_out[0][1] * sy;
	m_out[1][1] = +m_out[0][0] * sy;
	m_out[0][0] *= sx;
	m_out[0][1] *= sx;
	return m_out;
}

ijk_inl float2km ijkMatGetRotate2fm(float2x2 const m_in, f32* const angle_degrees_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in[0][1], m_in[0][0]);
	return m_in;
}

ijk_inl float2km ijkMatGetScale2fm(float2x2 const m_in, f32* const sx_out, f32* const sy_out)
{
	*sx_out = ijkVecLength2fv(m_in[0]);
	*sy_out = ijkVecLength2fv(m_in[1]);
	return m_in;
}

ijk_inl float2km ijkMatGetRotateScale2fm(float2x2 const m_in, f32* const angle_degrees_out, f32* const sx_out, f32* const sy_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in[0][1], m_in[0][0]);
	*sx_out = ijkVecLength2fv(m_in[0]);
	*sy_out = ijkVecLength2fv(m_in[1]);
	return m_in;
}


//-----------------------------------------------------------------------------

// 3D array-based special


//-----------------------------------------------------------------------------

// 4D array-based special


//-----------------------------------------------------------------------------

// 2D struct-based special


//-----------------------------------------------------------------------------

// 3D struct-based special


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_FLOAT_INL_
#endif	// _IJK_MATRIX_FLOAT_H_