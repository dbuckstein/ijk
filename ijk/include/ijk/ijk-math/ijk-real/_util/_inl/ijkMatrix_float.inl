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
	ijkVecInitElems2fv(m_out[0], x0, y0);
	ijkVecInitElems2fv(m_out[1], x1, y1);
	return m_out;
}

ijk_inl float2m ijkMatInitVecs2fm(float2x2 m_out, float2 const c0, float2 const c1)
{
	ijkVecCopy2fv(m_out[0], c0);
	ijkVecCopy2fv(m_out[1], c1);
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm2(float2x2 m_out, float2x2 const m_in)
{
	ijkVecCopy2fv(m_out[0], m_in[0]);
	ijkVecCopy2fv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm3(float2x2 m_out, float3x3 const m_in)
{
	ijkVecCopy2fv(m_out[0], m_in[0]);
	ijkVecCopy2fv(m_out[1], m_in[1]);
	return m_out;
}

ijk_inl float2m ijkMatCopy2fm4(float2x2 m_out, float4x4 const m_in)
{
	ijkVecCopy2fv(m_out[0], m_in[0]);
	ijkVecCopy2fv(m_out[1], m_in[1]);
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
	ijkVecMul2fvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul2fvs(m_out[1], m_lh[1], s_rh);
	return m_out;
}

ijk_inl float2m ijkMatDiv2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	ijkVecMul2fvs(m_out[0], m_lh[0], s);
	ijkVecMul2fvs(m_out[1], m_lh[1], s);
	return m_out;
}

ijk_inl float2m ijkMatDivSafe2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	ijkVecMul2fvs(m_out[0], m_lh[0], s);
	ijkVecMul2fvs(m_out[1], m_lh[1], s);
	return m_out;
}

ijk_inl float2m ijkMatMul2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	ijkVecMul2fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul2fsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl float2m ijkMatDiv2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	ijkVecDiv2fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv2fsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl float2m ijkMatDivSafe2fsm(float2x2 m_out, f32 const s_lh, float2x2 const m_rh)
{
	ijkVecDivSafe2fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe2fsv(m_out[1], s_lh, m_rh[1]);
	return m_out;
}

ijk_inl float2m ijkMatAdd2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	ijkVecAdd2fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd2fv(m_out[1], m_lh[1], m_rh[1]);
	return m_out;
}

ijk_inl float2m ijkMatSub2fm(float2x2 m_out, float2x2 const m_lh, float2x2 const m_rh)
{
	ijkVecSub2fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub2fv(m_out[1], m_lh[1], m_rh[1]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl float3m ijkMatInit3fm(float3x3 m_out)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = flt_one;
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = flt_zero;
	return m_out;
}

ijk_inl float3m ijkMatInitElems3fm(float3x3 m_out, f32 const x0, f32 const y0, f32 const z0, f32 const x1, f32 const y1, f32 const z1, f32 const x2, f32 const y2, f32 const z2)
{
	ijkVecInitElems3fv(m_out[0], x0, y0, z0);
	ijkVecInitElems3fv(m_out[1], x1, y1, z1);
	ijkVecInitElems3fv(m_out[2], x2, y2, z2);
	return m_out;
}

ijk_inl float3m ijkMatInitVecs3fm(float3x3 m_out, float3 const c0, float3 const c1, float3 const c2)
{
	ijkVecCopy3fv(m_out[0], c0);
	ijkVecCopy3fv(m_out[1], c1);
	ijkVecCopy3fv(m_out[2], c2);
	return m_out;
}

ijk_inl float3m ijkMatCopy3fm2(float3x3 m_out, float2x2 const m_in)
{
	ijkVecCopy3fvz(m_out[0], m_in[0], flt_zero);
	ijkVecCopy3fvz(m_out[1], m_in[1], flt_zero);
	ijkVecCopy3fv(m_out[2], float3_z);
	return m_out;
}

ijk_inl float3m ijkMatCopy3fm3(float3x3 m_out, float3x3 const m_in)
{
	ijkVecCopy3fv(m_out[0], m_in[0]);
	ijkVecCopy3fv(m_out[1], m_in[1]);
	ijkVecCopy3fv(m_out[2], m_in[2]);
	return m_out;
}

ijk_inl float3m ijkMatCopy3fm4(float3x3 m_out, float4x4 const m_in)
{
	ijkVecCopy3fv(m_out[0], m_in[0]);
	ijkVecCopy3fv(m_out[1], m_in[1]);
	ijkVecCopy3fv(m_out[2], m_in[2]);
	return m_out;
}

ijk_inl float3m ijkMatCopy3fms(float3x3 m_out, f32 const s_diag)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = s_diag;
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = flt_zero;
	return m_out;
}

ijk_inl float3m ijkMatMul3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh)
{
	ijkVecMul3fvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul3fvs(m_out[1], m_lh[1], s_rh);
	ijkVecMul3fvs(m_out[2], m_lh[2], s_rh);
	return m_out;
}

ijk_inl float3m ijkMatDiv3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	ijkVecMul3fvs(m_out[0], m_lh[0], s);
	ijkVecMul3fvs(m_out[1], m_lh[1], s);
	ijkVecMul3fvs(m_out[2], m_lh[2], s);
	return m_out;
}

ijk_inl float3m ijkMatDivSafe3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	ijkVecMul3fvs(m_out[0], m_lh[0], s);
	ijkVecMul3fvs(m_out[1], m_lh[1], s);
	ijkVecMul3fvs(m_out[2], m_lh[2], s);
	return m_out;
}

ijk_inl float3m ijkMatMul3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh)
{
	ijkVecMul3fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul3fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecMul3fsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl float3m ijkMatDiv3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh)
{
	ijkVecDiv3fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv3fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDiv3fsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl float3m ijkMatDivSafe3fsm(float3x3 m_out, f32 const s_lh, float3x3 const m_rh)
{
	ijkVecDivSafe3fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe3fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDivSafe3fsv(m_out[2], s_lh, m_rh[2]);
	return m_out;
}

ijk_inl float3m ijkMatAdd3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh)
{
	ijkVecAdd3fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd3fv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecAdd3fv(m_out[2], m_lh[2], m_rh[2]);
	return m_out;
}

ijk_inl float3m ijkMatSub3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh)
{
	ijkVecSub3fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub3fv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecSub3fv(m_out[2], m_lh[2], m_rh[2]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl float4m ijkMatInit4fm(float4x4 m_out)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = m_out[3][3] = flt_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatInitElems4fm(float4x4 m_out, f32 const x0, f32 const y0, f32 const z0, f32 const w0, f32 const x1, f32 const y1, f32 const z1, f32 const w1, f32 const x2, f32 const y2, f32 const z2, f32 const w2, f32 const x3, f32 const y3, f32 const z3, f32 const w3)
{
	ijkVecInitElems4fv(m_out[0], x0, y0, z0, w0);
	ijkVecInitElems4fv(m_out[1], x1, y1, z1, w1);
	ijkVecInitElems4fv(m_out[2], x2, y2, z2, w2);
	ijkVecInitElems4fv(m_out[3], x3, y3, z3, w3);
	return m_out;
}

ijk_inl float4m ijkMatInitVecs4fm(float4x4 m_out, float4 const c0, float4 const c1, float4 const c2, float4 const c3)
{
	ijkVecCopy4fv(m_out[0], c0);
	ijkVecCopy4fv(m_out[1], c1);
	ijkVecCopy4fv(m_out[2], c2);
	ijkVecCopy4fv(m_out[3], c3);
	return m_out;
}

ijk_inl float4m ijkMatCopy4fm2(float4x4 m_out, float2x2 const m_in)
{
	ijkVecCopy4fvzw(m_out[0], m_in[0], flt_zero, flt_zero);
	ijkVecCopy4fvzw(m_out[1], m_in[1], flt_zero, flt_zero);
	ijkVecCopy4fv(m_out[2], float4_z);
	ijkVecCopy4fv(m_out[3], float4_w);
	return m_out;
}

ijk_inl float4m ijkMatCopy4fm3(float4x4 m_out, float3x3 const m_in)
{
	ijkVecCopy4fvw(m_out[0], m_in[0], flt_zero);
	ijkVecCopy4fvw(m_out[1], m_in[1], flt_zero);
	ijkVecCopy4fvw(m_out[2], m_in[2], flt_zero);
	ijkVecCopy4fv(m_out[3], float4_w);
	return m_out;
}

ijk_inl float4m ijkMatCopy4fm4(float4x4 m_out, float4x4 const m_in)
{
	ijkVecCopy4fv(m_out[0], m_in[0]);
	ijkVecCopy4fv(m_out[1], m_in[1]);
	ijkVecCopy4fv(m_out[2], m_in[2]);
	ijkVecCopy4fv(m_out[3], m_in[3]);
	return m_out;
}

ijk_inl float4m ijkMatCopy4fms(float4x4 m_out, f32 const s_diag)
{
	m_out[0][0] = m_out[1][1] = m_out[2][2] = m_out[3][3] = s_diag;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatMul4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh)
{
	ijkVecMul4fvs(m_out[0], m_lh[0], s_rh);
	ijkVecMul4fvs(m_out[1], m_lh[1], s_rh);
	ijkVecMul4fvs(m_out[2], m_lh[2], s_rh);
	ijkVecMul4fvs(m_out[3], m_lh[3], s_rh);
	return m_out;
}

ijk_inl float4m ijkMatDiv4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	ijkVecMul4fvs(m_out[0], m_lh[0], s);
	ijkVecMul4fvs(m_out[1], m_lh[1], s);
	ijkVecMul4fvs(m_out[2], m_lh[2], s);
	ijkVecMul4fvs(m_out[3], m_lh[3], s);
	return m_out;
}

ijk_inl float4m ijkMatDivSafe4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	ijkVecMul4fvs(m_out[0], m_lh[0], s);
	ijkVecMul4fvs(m_out[1], m_lh[1], s);
	ijkVecMul4fvs(m_out[2], m_lh[2], s);
	ijkVecMul4fvs(m_out[3], m_lh[3], s);
	return m_out;
}

ijk_inl float4m ijkMatMul4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh)
{
	ijkVecMul4fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecMul4fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecMul4fsv(m_out[2], s_lh, m_rh[2]);
	ijkVecMul4fsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl float4m ijkMatDiv4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh)
{
	ijkVecDiv4fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDiv4fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDiv4fsv(m_out[2], s_lh, m_rh[2]);
	ijkVecDiv4fsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl float4m ijkMatDivSafe4fsm(float4x4 m_out, f32 const s_lh, float4x4 const m_rh)
{
	ijkVecDivSafe4fsv(m_out[0], s_lh, m_rh[0]);
	ijkVecDivSafe4fsv(m_out[1], s_lh, m_rh[1]);
	ijkVecDivSafe4fsv(m_out[2], s_lh, m_rh[2]);
	ijkVecDivSafe4fsv(m_out[3], s_lh, m_rh[3]);
	return m_out;
}

ijk_inl float4m ijkMatAdd4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	ijkVecAdd4fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecAdd4fv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecAdd4fv(m_out[2], m_lh[2], m_rh[2]);
	ijkVecAdd4fv(m_out[3], m_lh[3], m_rh[3]);
	return m_out;
}

ijk_inl float4m ijkMatSub4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	ijkVecSub4fv(m_out[0], m_lh[0], m_rh[0]);
	ijkVecSub4fv(m_out[1], m_lh[1], m_rh[1]);
	ijkVecSub4fv(m_out[2], m_lh[2], m_rh[2]);
	ijkVecSub4fv(m_out[3], m_lh[3], m_rh[3]);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl fmat2 ijkMatInit2f()
{
	fmat2 const m_out = {
		flt_one, flt_zero,
		flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInitElems2f(float const x0, float const y0, float const x1, float const y1)
{
	fmat2 const m_out = {
		x0, y0,
		x1, y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInitVecs2f(fvec2 const c0, fvec2 const c1)
{
	fmat2 const m_out = {
		c0.x, c0.y,
		c1.x, c1.y,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f2(fmat2 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f3(fmat3 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2f4(fmat4 const m_in)
{
	fmat2 const m_out = {
		m_in.x0, m_in.y0,
		m_in.x1, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatCopy2fs(float const s_diag)
{
	fmat2 const m_out = {
		s_diag, flt_zero,
		flt_zero, s_diag,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatMul2fs(fmat2 const m_lh, float const s_rh)
{
	fmat2 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDiv2fs(fmat2 const m_lh, float const s_rh)
{
	float const s = ijk_recip_flt(s_rh);
	fmat2 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDivSafe2fs(fmat2 const m_lh, float const s_rh)
{
	float const s = ijk_recip_safe_flt(s_rh);
	fmat2 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatMul2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDiv2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatDivSafe2sf(float const s_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		ijk_divide_safe_flt(s_lh, m_rh.x0), ijk_divide_safe_flt(s_lh, m_rh.y0),
		ijk_divide_safe_flt(s_lh, m_rh.x1), ijk_divide_safe_flt(s_lh, m_rh.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatAdd2f(fmat2 const m_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatSub2f(fmat2 const m_lh, fmat2 const m_rh)
{
	fmat2 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl fmat3 ijkMatInit3f()
{
	fmat3 const m_out = {
		flt_one, flt_zero, flt_zero,
		flt_zero, flt_one, flt_zero,
		flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatInitElems3f(float const x0, float const y0, float const z0, float const x1, float const y1, float const z1, float const x2, float const y2, float const z2)
{
	fmat3 const m_out = {
		x0, y0, z0,
		x1, y1, z1,
		x2, y2, z2,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatInitVecs3f(fvec3 const c0, fvec3 const c1, fvec3 const c2)
{
	fmat3 const m_out = {
		c0.x, c0.y, c0.z,
		c1.x, c1.y, c1.z,
		c2.x, c2.y, c2.z,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatCopy3f2(fmat2 const m_in)
{
	fmat3 const m_out = {
		m_in.x0, m_in.y0, flt_zero,
		m_in.x1, m_in.y1, flt_zero,
		flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatCopy3f3(fmat3 const m_in)
{
	fmat3 const m_out = {
		m_in.x0, m_in.y0, m_in.z0,
		m_in.x1, m_in.y1, m_in.z1,
		m_in.x2, m_in.y2, m_in.z2,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatCopy3f4(fmat4 const m_in)
{
	fmat3 const m_out = {
		m_in.x0, m_in.y0, m_in.z0,
		m_in.x1, m_in.y1, m_in.z1,
		m_in.x2, m_in.y2, m_in.z2,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatCopy3fs(float const s_diag)
{
	fmat3 const m_out = {
		s_diag, flt_zero, flt_zero,
		flt_zero, s_diag, flt_zero,
		flt_zero, flt_zero, s_diag,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatMul3fs(fmat3 const m_lh, float const s_rh)
{
	fmat3 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh), (m_lh.z0* s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh), (m_lh.z1* s_rh),
		(m_lh.x2 * s_rh), (m_lh.y2 * s_rh), (m_lh.z2* s_rh),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatDiv3fs(fmat3 const m_lh, float const s_rh)
{
	float const s = ijk_recip_flt(s_rh);
	fmat3 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatDivSafe3fs(fmat3 const m_lh, float const s_rh)
{
	float const s = ijk_recip_safe_flt(s_rh);
	fmat3 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatMul3sf(float const s_lh, fmat3 const m_rh)
{
	fmat3 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0), (s_lh * m_rh.z0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1), (s_lh * m_rh.z1),
		(s_lh * m_rh.x2), (s_lh * m_rh.y2), (s_lh * m_rh.z2),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatDiv3sf(float const s_lh, fmat3 const m_rh)
{
	fmat3 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0), (s_lh / m_rh.z0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1), (s_lh / m_rh.z1),
		(s_lh / m_rh.x2), (s_lh / m_rh.y2), (s_lh / m_rh.z2),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatDivSafe3sf(float const s_lh, fmat3 const m_rh)
{
	fmat3 const m_out = {
		ijk_divide_safe_flt(s_lh, m_rh.x0), ijk_divide_safe_flt(s_lh, m_rh.y0), ijk_divide_safe_flt(s_lh, m_rh.z0),
		ijk_divide_safe_flt(s_lh, m_rh.x1), ijk_divide_safe_flt(s_lh, m_rh.y1), ijk_divide_safe_flt(s_lh, m_rh.z1),
		ijk_divide_safe_flt(s_lh, m_rh.x2), ijk_divide_safe_flt(s_lh, m_rh.y2), ijk_divide_safe_flt(s_lh, m_rh.z2),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatAdd3f(fmat3 const m_lh, fmat3 const m_rh)
{
	fmat3 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0), (m_lh.z0 + m_rh.z0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1), (m_lh.z1 + m_rh.z1),
		(m_lh.x2 + m_rh.x2), (m_lh.y2 + m_rh.y2), (m_lh.z2 + m_rh.z2),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatSub3f(fmat3 const m_lh, fmat3 const m_rh)
{
	fmat3 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0), (m_lh.z0 - m_rh.z0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1), (m_lh.z1 - m_rh.z1),
		(m_lh.x2 - m_rh.x2), (m_lh.y2 - m_rh.y2), (m_lh.z2 - m_rh.z2),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl fmat4 ijkMatInit4f()
{
	fmat4 const m_out = {
		flt_one, flt_zero, flt_zero, flt_zero,
		flt_zero, flt_one, flt_zero, flt_zero,
		flt_zero, flt_zero, flt_one, flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatInitElems4f(float const x0, float const y0, float const z0, float const w0, float const x1, float const y1, float const z1, float const w1, float const x2, float const y2, float const z2, float const w2, float const x3, float const y3, float const z3, float const w3)
{
	fmat4 const m_out = {
		x0, y0, z0, w0,
		x1, y1, z1, w1,
		x2, y2, z2, w2,
		x3, y3, z3, w3,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatInitVecs4f(fvec4 const c0, fvec4 const c1, fvec4 const c2, fvec4 const c3)
{
	fmat4 const m_out = {
		c0.x, c0.y, c0.z, c0.w,
		c1.x, c1.y, c1.z, c1.w,
		c2.x, c2.y, c2.z, c2.w,
		c3.x, c3.y, c3.z, c3.w,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatCopy4f2(fmat2 const m_in)
{
	fmat4 const m_out = {
		m_in.x0, m_in.y0, flt_zero, flt_zero,
		m_in.x1, m_in.y1, flt_zero, flt_zero,
		flt_zero, flt_zero, flt_one, flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatCopy4f3(fmat3 const m_in)
{
	fmat4 const m_out = {
		m_in.x0, m_in.y0, m_in.z0, flt_zero,
		m_in.x1, m_in.y1, m_in.z1, flt_zero,
		m_in.x2, m_in.y2, m_in.z2, flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatCopy4f4(fmat4 const m_in)
{
	fmat4 const m_out = {
		m_in.x0, m_in.y0, m_in.z0, m_in.w0,
		m_in.x1, m_in.y1, m_in.z1, m_in.w1,
		m_in.x2, m_in.y2, m_in.z2, m_in.w2,
		m_in.x3, m_in.y3, m_in.z3, m_in.w3,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatCopy4fs(float const s_diag)
{
	fmat4 const m_out = {
		s_diag, flt_zero, flt_zero, flt_zero,
		flt_zero, s_diag, flt_zero, flt_zero,
		flt_zero, flt_zero, s_diag, flt_zero,
		flt_zero, flt_zero, flt_zero, s_diag,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatMul4fs(fmat4 const m_lh, float const s_rh)
{
	fmat4 const m_out = {
		(m_lh.x0 * s_rh), (m_lh.y0 * s_rh), (m_lh.z0 * s_rh), (m_lh.w0 * s_rh),
		(m_lh.x1 * s_rh), (m_lh.y1 * s_rh), (m_lh.z1 * s_rh), (m_lh.w1 * s_rh),
		(m_lh.x2 * s_rh), (m_lh.y2 * s_rh), (m_lh.z2 * s_rh), (m_lh.w2 * s_rh),
		(m_lh.x3 * s_rh), (m_lh.y3 * s_rh), (m_lh.z3 * s_rh), (m_lh.w3 * s_rh),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatDiv4fs(fmat4 const m_lh, float const s_rh)
{
	float const s = ijk_recip_flt(s_rh);
	fmat4 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s), (m_lh.w0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s), (m_lh.w1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s), (m_lh.w2 * s),
		(m_lh.x3 * s), (m_lh.y3 * s), (m_lh.z3 * s), (m_lh.w3 * s),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatDivSafe4fs(fmat4 const m_lh, float const s_rh)
{
	float const s = ijk_recip_safe_flt(s_rh);
	fmat4 const m_out = {
		(m_lh.x0 * s), (m_lh.y0 * s), (m_lh.z0 * s), (m_lh.w0 * s),
		(m_lh.x1 * s), (m_lh.y1 * s), (m_lh.z1 * s), (m_lh.w1 * s),
		(m_lh.x2 * s), (m_lh.y2 * s), (m_lh.z2 * s), (m_lh.w2 * s),
		(m_lh.x3 * s), (m_lh.y3 * s), (m_lh.z3 * s), (m_lh.w3 * s),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatMul4sf(float const s_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		(s_lh * m_rh.x0), (s_lh * m_rh.y0), (s_lh * m_rh.z0), (s_lh * m_rh.w0),
		(s_lh * m_rh.x1), (s_lh * m_rh.y1), (s_lh * m_rh.z1), (s_lh * m_rh.w1),
		(s_lh * m_rh.x2), (s_lh * m_rh.y2), (s_lh * m_rh.z2), (s_lh * m_rh.w2),
		(s_lh * m_rh.x3), (s_lh * m_rh.y3), (s_lh * m_rh.z3), (s_lh * m_rh.w3),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatDiv4sf(float const s_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		(s_lh / m_rh.x0), (s_lh / m_rh.y0), (s_lh / m_rh.z0), (s_lh / m_rh.w0),
		(s_lh / m_rh.x1), (s_lh / m_rh.y1), (s_lh / m_rh.z1), (s_lh / m_rh.w1),
		(s_lh / m_rh.x2), (s_lh / m_rh.y2), (s_lh / m_rh.z2), (s_lh / m_rh.w2),
		(s_lh / m_rh.x3), (s_lh / m_rh.y3), (s_lh / m_rh.z3), (s_lh / m_rh.w3),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatDivSafe4sf(float const s_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		ijk_divide_safe_flt(s_lh, m_rh.x0), ijk_divide_safe_flt(s_lh, m_rh.y0), ijk_divide_safe_flt(s_lh, m_rh.z0), ijk_divide_safe_flt(s_lh, m_rh.w0),
		ijk_divide_safe_flt(s_lh, m_rh.x1), ijk_divide_safe_flt(s_lh, m_rh.y1), ijk_divide_safe_flt(s_lh, m_rh.z1), ijk_divide_safe_flt(s_lh, m_rh.w1),
		ijk_divide_safe_flt(s_lh, m_rh.x2), ijk_divide_safe_flt(s_lh, m_rh.y2), ijk_divide_safe_flt(s_lh, m_rh.z2), ijk_divide_safe_flt(s_lh, m_rh.w2),
		ijk_divide_safe_flt(s_lh, m_rh.x3), ijk_divide_safe_flt(s_lh, m_rh.y3), ijk_divide_safe_flt(s_lh, m_rh.z3), ijk_divide_safe_flt(s_lh, m_rh.w3),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatAdd4f(fmat4 const m_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		(m_lh.x0 + m_rh.x0), (m_lh.y0 + m_rh.y0), (m_lh.z0 + m_rh.z0), (m_lh.w0 + m_rh.w0),
		(m_lh.x1 + m_rh.x1), (m_lh.y1 + m_rh.y1), (m_lh.z1 + m_rh.z1), (m_lh.w1 + m_rh.w1),
		(m_lh.x2 + m_rh.x2), (m_lh.y2 + m_rh.y2), (m_lh.z2 + m_rh.z2), (m_lh.w2 + m_rh.w2),
		(m_lh.x3 + m_rh.x3), (m_lh.y3 + m_rh.y3), (m_lh.z3 + m_rh.z3), (m_lh.w3 + m_rh.w3),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatSub4f(fmat4 const m_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		(m_lh.x0 - m_rh.x0), (m_lh.y0 - m_rh.y0), (m_lh.z0 - m_rh.z0), (m_lh.w0 - m_rh.w0),
		(m_lh.x1 - m_rh.x1), (m_lh.y1 - m_rh.y1), (m_lh.z1 - m_rh.z1), (m_lh.w1 - m_rh.w1),
		(m_lh.x2 - m_rh.x2), (m_lh.y2 - m_rh.y2), (m_lh.z2 - m_rh.z2), (m_lh.w2 - m_rh.w2),
		(m_lh.x3 - m_rh.x3), (m_lh.y3 - m_rh.y3), (m_lh.z3 - m_rh.z3), (m_lh.w3 - m_rh.w3),
	};
	return m_out;
}


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
	f32 const tmp = m_in[0][1];
	m_out[0][0] = m_in[0][0];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
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

ijk_inl float ijkMatDeterminant2f(fmat2 const m_in)
{
	return ijkVecCross2f(m_in.c0, m_in.c1);
}

ijk_inl float ijkMatDeterminantInv2f(fmat2 const m_in)
{
	float const s = ijkMatDeterminant2f(m_in);
	return ijk_recip_flt(s);
}

ijk_inl float ijkMatDeterminantInvSafe2f(fmat2 const m_in)
{
	float const s = ijkMatDeterminant2f(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl float ijkMatMulRowVec2f(fmat2 const m_in, fvec2 const v_in, index const row)
{
	return (m_in.c0.xy[row] * v_in.x + m_in.c1.xy[row] * v_in.y);
}

ijk_inl fvec2 ijkMatGetRow2f(fmat2 const m_in, index const row)
{
	fvec2 const v_out = {
		m_in.c0.xy[row],
		m_in.c1.xy[row],
	};
	return v_out;
}

ijk_inl fmat2 ijkMatTranspose2f(fmat2 const m_in)
{
	fmat2 const m_out = {
		m_in.m00,
		m_in.m10,
		m_in.m01,
		m_in.m11,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInverse2f(fmat2 const m_in)
{
	// inv = adj/det
	// adj = {{+m11,-m01},{-m10,+m00}}
	float const detInv = ijkMatDeterminantInv2f(m_in);
	fmat2 const adj_det = {
		+m_in.m11 * detInv,
		-m_in.m01 * detInv,
		-m_in.m10 * detInv,
		+m_in.m00 * detInv,
	};
	return adj_det;
}

ijk_inl fmat2 ijkMatInverseSafe2f(fmat2 const m_in)
{
	float const detInv = ijkMatDeterminantInvSafe2f(m_in);
	fmat2 const adj_det = {
		+m_in.m11 * detInv,
		-m_in.m01 * detInv,
		-m_in.m10 * detInv,
		+m_in.m00 * detInv,
	};
	return adj_det;
}

ijk_inl fvec2 ijkMatMulVec2f(fmat2 const m_lh, fvec2 const v_rh)
{
	fvec2 const v_copy = {
		ijkMatMulRowVec2f(m_lh, v_rh, 0),
		ijkMatMulRowVec2f(m_lh, v_rh, 1),
	};
	return v_copy;
}

ijk_inl fmat2 ijkMatMul2f(fmat2 const m_lh, fmat2 const m_rh)
{
	fmat2 m_out;
	m_out.c0 = ijkMatMulVec2f(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec2f(m_lh, m_rh.c1);
	return m_out;
}

ijk_inl fmat2 ijkMatDiv2f(fmat2 const m_lh, fmat2 const m_rh)
{
	return ijkMatMul2f(m_lh, ijkMatInverse2f(m_rh));
}

ijk_inl fmat2 ijkMatDivSafe2f(fmat2 const m_lh, fmat2 const m_rh)
{
	return ijkMatMul2f(m_lh, ijkMatInverseSafe2f(m_rh));
}

ijk_inl fmat2 ijkMatRotate2f(float const angle_degrees)
{
	fmat2 m_out;
	ijkTrigSinCos_deg_flt(angle_degrees, m_out.c0.xy + 1, m_out.c0.xy + 0);
	m_out.m10 = -m_out.m01;
	m_out.m11 = +m_out.m00;
	return m_out;
}

ijk_inl fmat2 ijkMatScale2f(float const sx, float const sy)
{
	fmat2 const m_out = {
		sx, flt_zero, flt_zero, sy,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatRotateScale2f(float const angle_degrees, float const sx, float const sy)
{
	fmat2 m_out;
	ijkTrigSinCos_deg_flt(angle_degrees, m_out.c0.xy + 1, m_out.c0.xy + 0);
	m_out.m10 = -m_out.m01 * sy;
	m_out.m11 = +m_out.m00 * sy;
	m_out.m00 *= sx;
	m_out.m01 *= sx;
	return m_out;
}

ijk_inl fmat2 ijkMatGetRotate2f(fmat2 const m_in, float* const angle_degrees_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in.m01, m_in.m00);
	return m_in;
}

ijk_inl fmat2 ijkMatGetScale2f(fmat2 const m_in, float* const sx_out, float* const sy_out)
{
	*sx_out = ijkVecLength2f(m_in.c0);
	*sy_out = ijkVecLength2f(m_in.c1);
	return m_in;
}

ijk_inl fmat2 ijkMatGetRotateScale2f(fmat2 const m_in, float* const angle_degrees_out, float* const sx_out, float* const sy_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in.m01, m_in.m00);
	*sx_out = ijkVecLength2f(m_in.c0);
	*sy_out = ijkVecLength2f(m_in.c1);
	return m_in;
}


//-----------------------------------------------------------------------------

// 3D struct-based special


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_FLOAT_INL_
#endif	// _IJK_MATRIX_FLOAT_H_