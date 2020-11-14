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

// 2D struct-based


//-----------------------------------------------------------------------------

// 3D struct-based


//-----------------------------------------------------------------------------

// 4D struct-based


//-----------------------------------------------------------------------------

ijk_inl floatv ijkMatMul2fmv(float2 v_out, float2x2 const m_lh, float2 const v_rh)
{
	float2 const v_copy = {
		m_lh[0][0] * v_rh[0] + m_lh[1][0] * v_rh[1],
		m_lh[0][1] * v_rh[0] + m_lh[1][1] * v_rh[1],
	};
	return ijkVecCopy2fv(v_out, v_copy);
}

ijk_inl float2m ijkMatMul2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	ijkMatMul2fmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMul2fmv(m_out[1], m_lh, m_rh[1]);
	return m_out;
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