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
	// det = m00 * m11 - m10 * m01
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

ijk_inl f32 ijkMatMulRowVec2fmv(float2x2 const m_in, float2 const v_in, index const row)
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
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatTransposeMul2fms(float2x2 m_out, float2x2 const m_in, f32 const s)
{
	f32 const tmp = m_in[0][1];
	m_out[0][1] = s * m_in[1][0];
	m_out[1][0] = s * tmp;
	m_out[0][0] = s * m_in[0][0];
	m_out[1][1] = s * m_in[1][1];
	return m_out;
}

ijk_inl float2m ijkMatInverse2fm(float2x2 m_out, float2x2 const m_in)
{
	// inv = adj/det
	// adj = {{+m11,-m01},{-m10,+m00}}
	f32 const detInv = ijkMatDeterminantInv2fm(m_in);
	float2x2 const adj_det = {
		(+m_in[1][1] * detInv),
		(-m_in[0][1] * detInv),
		(-m_in[1][0] * detInv),
		(+m_in[0][0] * detInv),
	};
	return ijkMatCopy2fm2(m_out, adj_det);
}

ijk_inl float2m ijkMatInverseSafe2fm(float2x2 m_out, float2x2 const m_in)
{
	f32 const detInv = ijkMatDeterminantInvSafe2fm(m_in);
	float2x2 const adj_det = {
		(+m_in[1][1] * detInv),
		(-m_in[0][1] * detInv),
		(-m_in[1][0] * detInv),
		(+m_in[0][0] * detInv),
	};
	return ijkMatCopy2fm2(m_out, adj_det);
}

ijk_inl floatv ijkMatMulVec2fmv(float2 v_out, float2x2 const m_lh, float2 const v_rh)
{
	float2 const v_copy = {
		ijkMatMulRowVec2fmv(m_lh, v_rh, 0),
		ijkMatMulRowVec2fmv(m_lh, v_rh, 1),
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
	ijkMatGetScale2fm(m_in, sx_out, sy_out);
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in[0][1], m_in[0][0]);
	return m_in;
}

ijk_inl float2m ijkMatInverseRotate2fm(float2x2 m_out, float2x2 const m_in)
{
	return ijkMatTranspose2fm(m_out, m_in);
}

ijk_inl float2m ijkMatInverseScale2fm(float2x2 m_out, float2x2 const m_in)
{
	m_out[0][0] = ijk_recip_flt(m_in[0][0]);
	m_out[1][1] = ijk_recip_flt(m_in[1][1]);
	m_out[0][1] = m_out[1][0] = flt_zero;
	return m_out;
}

ijk_inl float2m ijkMatInverseRotateScale2fm(float2x2 m_out, float2x2 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	f32 const sx2_inv = ijkVecLengthSqInv2fv(m_in[0]);
	f32 const sy2_inv = ijkVecLengthSqInv2fv(m_in[1]);
	f32 const tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0] * sy2_inv;
	m_out[1][0] = tmp * sx2_inv;
	m_out[0][0] = m_in[0][0] * sx2_inv;
	m_out[1][1] = m_in[1][1] * sy2_inv;
	return m_out;
}

ijk_inl float2m ijkMatInverseTranspose2fm(float2x2 m_out, float2x2 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	ijkVecMul2fvs(m_out[0], m_in[0], ijkVecLengthSqInv2fv(m_in[0]));
	ijkVecMul2fvs(m_out[1], m_in[1], ijkVecLengthSqInv2fv(m_in[1]));
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl f32 ijkMatDeterminant3fm(float3x3 const m_in)
{
	// det = dot(c0, cross(c1, c2))
	float3 cross;
	return ijkVecDot3fv(m_in[0], ijkVecCross3fv(cross, m_in[1], m_in[2]));
}

ijk_inl f32 ijkMatDeterminantInv3fm(float3x3 const m_in)
{
	f32 const s = ijkMatDeterminant3fm(m_in);
	return ijk_recip_flt(s);
}

ijk_inl f32 ijkMatDeterminantInvSafe3fm(float3x3 const m_in)
{
	f32 const s = ijkMatDeterminant3fm(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl f32 ijkMatMulRowVec3fmv(float3x3 const m_in, float3 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1] + m_in[2][row] * v_in[2]);
}

ijk_inl floatv ijkMatGetRow3fm(float3 v_out, float3x3 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	v_out[2] = m_in[2][row];
	return v_out;
}

ijk_inl float3m ijkMatTranspose3fm(float3x3 m_out, float3x3 const m_in)
{
	f32 tmp = m_in[0][1];
	m_out[0][1] = m_in[1][0];
	m_out[1][0] = tmp;
	tmp = m_in[1][2];
	m_out[1][2] = m_in[2][1];
	m_out[2][1] = tmp;
	tmp = m_in[2][0];
	m_out[2][0] = m_in[0][2];
	m_out[0][2] = tmp;
	m_out[0][0] = m_in[0][0];
	m_out[1][1] = m_in[1][1];
	m_out[2][2] = m_in[2][2];
	return m_out;
}

ijk_inl float3m ijkMatTransposeMul3fms(float3x3 m_out, float3x3 const m_in, f32 const s)
{
	f32 tmp = m_in[0][1];
	m_out[0][1] = s * m_in[1][0];
	m_out[1][0] = s * tmp;
	tmp = m_in[1][2];
	m_out[1][2] = s * m_in[2][1];
	m_out[2][1] = s * tmp;
	tmp = m_in[2][0];
	m_out[2][0] = s * m_in[0][2];
	m_out[0][2] = s * tmp;
	m_out[0][0] = s * m_in[0][0];
	m_out[1][1] = s * m_in[1][1];
	m_out[2][2] = s * m_in[2][2];
	return m_out;
}

ijk_inl float3m ijkMatInverse3fm(float3x3 m_out, float3x3 const m_in)
{
	f32 detInv;
	float3x3 cross;
	ijkVecCross3fv(cross[0], m_in[1], m_in[2]);
	ijkVecCross3fv(cross[1], m_in[2], m_in[0]);
	ijkVecCross3fv(cross[2], m_in[0], m_in[1]);
	detInv = ijkVecDot3fv(m_in[0], cross[0]);
	return ijkMatTransposeMul3fms(m_out, cross, ijk_recip_flt(detInv));
}

ijk_inl float3m ijkMatInverseSafe3fm(float3x3 m_out, float3x3 const m_in)
{
	f32 detInv;
	float3x3 cross;
	ijkVecCross3fv(cross[0], m_in[1], m_in[2]);
	ijkVecCross3fv(cross[1], m_in[2], m_in[0]);
	ijkVecCross3fv(cross[2], m_in[0], m_in[1]);
	detInv = ijkVecDot3fv(m_in[0], cross[0]);
	return ijkMatTransposeMul3fms(m_out, cross, ijk_recip_safe_flt(detInv));
}

ijk_inl floatv ijkMatMulVec3fmv(float3 v_out, float3x3 const m_lh, float3 const v_rh)
{
	float3 const v_copy = {
		ijkMatMulRowVec3fmv(m_lh, v_rh, 0),
		ijkMatMulRowVec3fmv(m_lh, v_rh, 1),
		ijkMatMulRowVec3fmv(m_lh, v_rh, 2),
	};
	return ijkVecCopy3fv(v_out, v_copy);
}

ijk_inl float3m ijkMatMul3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh)
{
	ijkMatMulVec3fmv(m_out[0], m_lh, m_rh[0]);
	ijkMatMulVec3fmv(m_out[1], m_lh, m_rh[1]);
	ijkMatMulVec3fmv(m_out[2], m_lh, m_rh[2]);
	return m_out;
}

ijk_inl float3m ijkMatDiv3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh)
{
	float3x3 inv_rh;
	return ijkMatMul3fm(m_out, m_lh, ijkMatInverse3fm(inv_rh, m_rh));
}

ijk_inl float3m ijkMatDivSafe3fm(float3x3 m_out, float3x3 const m_lh, float3x3 const m_rh)
{
	float3x3 inv_rh;
	return ijkMatMul3fm(m_out, m_lh, ijkMatInverseSafe3fm(inv_rh, m_rh));
}

ijk_inl float3m ijkMatRotateXYZ3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems3fm(m_out,
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz),
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz),
		(+sy), (-sx * cy), (+cx * cy));
}

ijk_inl float3m ijkMatRotateYZX3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems3fm(m_out,
		(+cy * cz), (+sz), (-sy * cz),
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx),
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx));
}

ijk_inl float3m ijkMatRotateZXY3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems3fm(m_out,
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy),
		(-sz * cx), (+cz * cx), (+sx),
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy));
}

ijk_inl float3m ijkMatRotateYXZ3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems3fm(m_out,
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz),
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz),
		(+sy * cx), (-sx), (+cy * cx));
}

ijk_inl float3m ijkMatRotateXZY3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems3fm(m_out,
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy),
		(-sz), (+cx * cz), (+sx * cz),
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy));
}

ijk_inl float3m ijkMatRotateZYX3fm(float3x3 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems3fm(m_out,
		(+cz * cy), (+sy * cy), (-sy),
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx),
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx));
}

ijk_inl float3km ijkMatGetRotateXYZ3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(+m_in[2][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(-m_in[1][0], +m_in[0][0]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(-m_in[2][1], +m_in[2][2]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateYZX3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(+m_in[0][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(-m_in[2][1], +m_in[1][1]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(-m_in[0][2], +m_in[0][0]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateZXY3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(+m_in[1][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(-m_in[0][2], +m_in[2][2]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(-m_in[1][0], +m_in[1][1]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateYXZ3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(-m_in[2][1]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(+m_in[2][0], +m_in[2][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(+m_in[0][1], +m_in[1][1]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateXZY3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(-m_in[1][0]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(+m_in[1][2], +m_in[1][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(+m_in[2][0], +m_in[0][0]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateZYX3fm(float3x3 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(-m_in[0][2]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(+m_in[0][1], +m_in[0][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(+m_in[1][2], +m_in[2][2]);
	return m_in;
}

ijk_inl float3m ijkMatRotate3fm(float3x3 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ3fm(m_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX3fm(m_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY3fm(m_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ3fm(m_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY3fm(m_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX3fm(m_out, rotateDegXYZ);
	}
	return m_out;
}

ijk_inl float3m ijkMatScale3fm(float3x3 m_out, float3 const scale)
{
	m_out[0][0] = scale[0];
	m_out[1][1] = scale[1];
	m_out[2][2] = scale[2];
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = flt_zero;
	return m_out;
}

ijk_inl float3m ijkMatRotateScale3fm(float3x3 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale)
{
	ijkMatRotate3fm(m_out, order, rotateDegXYZ);
	ijkVecMul3fvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3fvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3fvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl float3km ijkMatGetRotate3fm(float3x3 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ3fm(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX3fm(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY3fm(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ3fm(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY3fm(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX3fm(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl float3km ijkMatGetScale3fm(float3x3 const m_in, float3 scale_out)
{
	scale_out[0] = ijkVecLength3fv(m_in[0]);
	scale_out[1] = ijkVecLength3fv(m_in[1]);
	scale_out[2] = ijkVecLength3fv(m_in[2]);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateScale3fm(float3x3 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out)
{
	float3x3 rot;
	ijkVecDivSafe3fvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3fv(m_in[0])));
	ijkVecDivSafe3fvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3fv(m_in[1])));
	ijkVecDivSafe3fvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3fv(m_in[2])));
	ijkMatGetRotate3fm(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl float3m ijkMatInverseRotate3fm(float3x3 m_out, float3x3 const m_in)
{
	return ijkMatTranspose3fm(m_out, m_in);
}

ijk_inl float3m ijkMatInverseScale3fm(float3x3 m_out, float3x3 const m_in)
{
	m_out[0][0] = ijk_recip_flt(m_in[0][0]);
	m_out[1][1] = ijk_recip_flt(m_in[1][1]);
	m_out[2][2] = ijk_recip_flt(m_in[2][2]);
	m_out[0][1] = m_out[0][2] = m_out[1][0] = m_out[1][2] = m_out[2][0] = m_out[2][1] = flt_zero;
	return m_out;
}

ijk_inl float3m ijkMatInverseRotateScale3fm(float3x3 m_out, float3x3 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	f32 const sx2_inv = ijkVecLengthSqInv3fv(m_in[0]);
	f32 const sy2_inv = ijkVecLengthSqInv3fv(m_in[1]);
	f32 const sz2_inv = ijkVecLengthSqInv3fv(m_in[2]);
	f32 tmp = m_in[0][1];
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

ijk_inl float3m ijkMatInverseTranspose3fm(float3x3 m_out, float3x3 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	ijkVecMul3fvs(m_out[0], m_in[0], ijkVecLengthSqInv3fv(m_in[0]));
	ijkVecMul3fvs(m_out[1], m_in[1], ijkVecLengthSqInv3fv(m_in[1]));
	ijkVecMul3fvs(m_out[2], m_in[2], ijkVecLengthSqInv3fv(m_in[2]));
	return m_out;
}

ijk_inl float3m ijkMatRotateAxisAngle3fm(float3x3 m_out, float3 const axis_unit, f32 const angle_degrees)
{
	f32 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f32 const x = axis_unit[0], y = axis_unit[1], z = axis_unit[2];
	ijkTrigSinCos_deg_flt(angle_degrees, &s, &c);
	t = flt_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems3fm(m_out, 
		(x * xt + x), (xyt + zs), (zxt - ys),
		(xyt - zs), (y * yt + c), (yzt + xs),
		(zxt + ys), (yzt - xs), (z * zt + c));
}

ijk_inl float3m ijkMatRotateAxisAngleScale3fm(float3x3 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale)
{
	ijkMatRotateAxisAngle3fm(m_out, axis_unit, angle_degrees);
	ijkVecMul3fvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3fvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3fvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl float3km ijkMatGetRotateAxisAngle3fm(float3x3 const m_in, float3 axis_unit_out, f32* const angle_degrees_out)
{
	f32 r;
	f32 const t = (m_in[0][0] + m_in[1][1] + m_in[2][2] - flt_one);
	ijkVecInitElems3fv(axis_unit_out,
		(m_in[1][2] - m_in[2][1]), (m_in[2][0] - m_in[0][2]), (m_in[0][1] - m_in[1][0]));
	r = ijkVecLength3fv(axis_unit_out);
	ijkVecDivSafe3fvs(axis_unit_out, axis_unit_out, r);
	*angle_degrees_out = ijkTrigAtan2_deg_flt(r, t);
	return m_in;
}

ijk_inl float3km ijkMatGetRotateAxisAngleScale3fm(float3x3 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out)
{
	float3x3 rot;
	ijkVecDivSafe3fvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3fv(m_in[0])));
	ijkVecDivSafe3fvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3fv(m_in[1])));
	ijkVecDivSafe3fvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3fv(m_in[2])));
	ijkMatGetRotateAxisAngle3fm(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}


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
		m_in.x0, m_in.x1,
		m_in.y0, m_in.y1,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatTransposeMul2fs(fmat2 const m_in, float const s)
{
	fmat2 const m_out = {
		(s * m_in.x0), (s * m_in.x1),
		(s * m_in.y0), (s * m_in.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInverse2f(fmat2 const m_in)
{
	// inv = adj/det
	// adj = {{+y1,-y0},{-x1,+x0}}
	float const detInv = ijkMatDeterminantInv2f(m_in);
	fmat2 const adj_det = {
		(+m_in.y1 * detInv), (-m_in.y0 * detInv),
		(-m_in.x1 * detInv), (+m_in.x0 * detInv),
	};
	return adj_det;
}

ijk_inl fmat2 ijkMatInverseSafe2f(fmat2 const m_in)
{
	float const detInv = ijkMatDeterminantInvSafe2f(m_in);
	fmat2 const adj_det = {
		(+m_in.y1 * detInv), (-m_in.y0 * detInv),
		(-m_in.x1 * detInv), (+m_in.x0 * detInv),
	};
	return adj_det;
}

ijk_inl fvec2 ijkMatMulVec2f(fmat2 const m_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijkMatMulRowVec2f(m_lh, v_rh, 0),
		ijkMatMulRowVec2f(m_lh, v_rh, 1),
	};
	return v_out;
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
	m_out.x1 = -m_out.y0;
	m_out.y1 = +m_out.x0;
	return m_out;
}

ijk_inl fmat2 ijkMatScale2f(float const sx, float const sy)
{
	fmat2 const m_out = {
		sx, flt_zero,
		flt_zero, sy,
	};
	return m_out;
}

ijk_inl fmat2 ijkMatRotateScale2f(float const angle_degrees, float const sx, float const sy)
{
	fmat2 m_out;
	ijkTrigSinCos_deg_flt(angle_degrees, m_out.c0.xy + 1, m_out.c0.xy + 0);
	m_out.x1 = -m_out.y0 * sy;
	m_out.y1 = +m_out.x0 * sy;
	m_out.x0 *= sx;
	m_out.y0 *= sx;
	return m_out;
}

ijk_inl fmat2 ijkMatGetRotate2f(fmat2 const m_in, float* const angle_degrees_out)
{
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in.y0, m_in.x0);
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
	*angle_degrees_out = ijkTrigAtan2_deg_flt(m_in.y0, m_in.x0);
	*sx_out = ijkVecLength2f(m_in.c0);
	*sy_out = ijkVecLength2f(m_in.c1);
	return m_in;
}

ijk_inl fmat2 ijkMatInverseRotate2f(fmat2 const m_in)
{
	return ijkMatTranspose2f(m_in);
}

ijk_inl fmat2 ijkMatInverseScale2f(fmat2 const m_in)
{
	fmat2 const m_out = {
		ijk_recip_flt(m_in.x0),	flt_zero,
		flt_zero, ijk_recip_flt(m_in.y1),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInverseRotateScale2f(fmat2 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	float const sx2_inv = ijkVecLengthSqInv2f(m_in.c0);
	float const sy2_inv = ijkVecLengthSqInv2f(m_in.c1);
	fmat2 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv),
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv),
	};
	return m_out;
}

ijk_inl fmat2 ijkMatInverseTranspose2f(fmat2 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	float const sx2_inv = ijkVecLengthSqInv2f(m_in.c0);
	float const sy2_inv = ijkVecLengthSqInv2f(m_in.c1);
	fmat2 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.y0 * sx2_inv),
		(m_in.x1 * sy2_inv), (m_in.y1 * sy2_inv),
	};
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl float ijkMatDeterminant3f(fmat3 const m_in)
{
	// det = dot(c0, cross(c1, c2))
	return ijkVecDot3f(m_in.c0, ijkVecCross3f(m_in.c1, m_in.c2));
}

ijk_inl float ijkMatDeterminantInv3f(fmat3 const m_in)
{
	float const s = ijkMatDeterminant3f(m_in);
	return ijk_recip_flt(s);
}

ijk_inl float ijkMatDeterminantInvSafe3f(fmat3 const m_in)
{
	float const s = ijkMatDeterminant3f(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl float ijkMatMulRowVec3f(fmat3 const m_in, fvec3 const v_in, index const row)
{
	return (m_in.c0.xy[row] * v_in.x + m_in.c1.xy[row] * v_in.y + m_in.c2.xy[row] * v_in.z);
}

ijk_inl fvec3 ijkMatGetRow3f(fmat3 const m_in, index const row)
{
	fvec3 const v_out = {
		m_in.c0.xy[row],
		m_in.c1.xy[row],
		m_in.c2.xy[row],
	};
	return v_out;
}

ijk_inl fmat3 ijkMatTranspose3f(fmat3 const m_in)
{
	fmat3 const m_out = {
		m_in.x0, m_in.x1, m_in.x2,
		m_in.y0, m_in.y1, m_in.y2,
		m_in.z0, m_in.z1, m_in.z2,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatTransposeMul3fs(fmat3 const m_in, float const s)
{
	fmat3 const m_out = {
		(m_in.x0 * s), (m_in.x1 * s), (m_in.x2 * s),
		(m_in.y0 * s), (m_in.y1 * s), (m_in.y2 * s),
		(m_in.z0 * s), (m_in.z1 * s), (m_in.z2 * s),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatInverse3f(fmat3 const m_in)
{
	float detInv;
	fmat3 cross;
	cross.c0 = ijkVecCross3f(m_in.c1, m_in.c2);
	cross.c1 = ijkVecCross3f(m_in.c2, m_in.c0);
	cross.c2 = ijkVecCross3f(m_in.c0, m_in.c1);
	detInv = ijkVecDot3f(m_in.c0, cross.c0);
	return ijkMatTransposeMul3fs(cross, ijk_recip_flt(detInv));
}

ijk_inl fmat3 ijkMatInverseSafe3f(fmat3 const m_in)
{
	float detInv;
	fmat3 cross;
	cross.c0 = ijkVecCross3f(m_in.c1, m_in.c2);
	cross.c1 = ijkVecCross3f(m_in.c2, m_in.c0);
	cross.c2 = ijkVecCross3f(m_in.c0, m_in.c1);
	detInv = ijkVecDot3f(m_in.c0, cross.c0);
	return ijkMatTransposeMul3fs(cross, ijk_recip_safe_flt(detInv));
}

ijk_inl fvec3 ijkMatMulVec3f(fmat3 const m_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijkMatMulRowVec3f(m_lh, v_rh, 0),
		ijkMatMulRowVec3f(m_lh, v_rh, 1),
		ijkMatMulRowVec3f(m_lh, v_rh, 2),
	};
	return v_out;
}

ijk_inl fmat3 ijkMatMul3f(fmat3 const m_lh, fmat3 const m_rh)
{
	fmat3 m_out;
	m_out.c0 = ijkMatMulVec3f(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec3f(m_lh, m_rh.c1);
	m_out.c2 = ijkMatMulVec3f(m_lh, m_rh.c2);
	return m_out;
}

ijk_inl fmat3 ijkMatDiv3f(fmat3 const m_lh, fmat3 const m_rh)
{
	return ijkMatMul3f(m_lh, ijkMatInverse3f(m_rh));
}

ijk_inl fmat3 ijkMatDivSafe3f(fmat3 const m_lh, fmat3 const m_rh)
{
	return ijkMatMul3f(m_lh, ijkMatInverseSafe3f(m_rh));
}

ijk_inl fmat3 ijkMatRotateXYZ3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems3f(
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz),
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz),
		(+sy), (-sx * cy), (+cx * cy));
}

ijk_inl fmat3 ijkMatRotateYZX3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems3f(
		(+cy * cz), (+sz), (-sy * cz),
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx),
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx));
}

ijk_inl fmat3 ijkMatRotateZXY3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems3f(
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy),
		(-sz * cx), (+cz * cx), (+sx),
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy));
}

ijk_inl fmat3 ijkMatRotateYXZ3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems3f(
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz),
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz),
		(+sy * cx), (-sx), (+cy * cx));
}

ijk_inl fmat3 ijkMatRotateXZY3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems3f(
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy),
		(-sz), (+cx * cz), (+sx * cz),
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy));
}

ijk_inl fmat3 ijkMatRotateZYX3f(fvec3 const rotateDegXYZ)
{
	float sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems3f(
		(+cz * cy), (+sy * cy), (-sy),
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx),
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx));
}

ijk_inl fmat3 ijkMatGetRotateXYZ3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_flt(+m_in.x2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(-m_in.x1, +m_in.x0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(-m_in.y2, +m_in.z2);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateYZX3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_flt(+m_in.y0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(-m_in.y2, +m_in.y1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(-m_in.z0, +m_in.x0);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateZXY3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_flt(+m_in.z1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(-m_in.z0, +m_in.z2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(-m_in.x1, +m_in.y1);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateYXZ3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_flt(-m_in.y2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(+m_in.x2, +m_in.z2);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(+m_in.y0, +m_in.y1);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateXZY3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_flt(-m_in.x1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(+m_in.z1, +m_in.y1);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(+m_in.x2, +m_in.x0);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateZYX3f(fmat3 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_flt(-m_in.z0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(+m_in.y0, +m_in.x0);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(+m_in.z1, +m_in.z2);
	return m_in;
}

ijk_inl fmat3 ijkMatRotate3f(ijkRotationOrder const order, fvec3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ3f(rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX3f(rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY3f(rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ3f(rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY3f(rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX3f(rotateDegXYZ);
	}
	//return m_out;
}

ijk_inl fmat3 ijkMatScale3f(fvec3 const scale)
{
	fmat3 const m_out = {
		scale.x, flt_zero, flt_zero,
		flt_zero, scale.y, flt_zero,
		flt_zero, flt_zero, scale.z,
	};
	return m_out;
}

ijk_inl fmat3 ijkMatRotateScale3f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale)
{
	fmat3 m_out = ijkMatRotate3f(order, rotateDegXYZ);
	m_out.c0 = ijkVecMul3fs(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul3fs(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul3fs(m_out.c2, scale.z);
	return m_out;
}

ijk_inl fmat3 ijkMatGetRotate3f(fmat3 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ3f(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX3f(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY3f(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ3f(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY3f(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX3f(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl fmat3 ijkMatGetScale3f(fmat3 const m_in, fvec3* const scale_out)
{
	scale_out->x = ijkVecLength3f(m_in.c0);
	scale_out->y = ijkVecLength3f(m_in.c1);
	scale_out->z = ijkVecLength3f(m_in.c2);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateScale3f(fmat3 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out)
{
	fmat3 rot;
	rot.c0 = ijkVecDivSafe3fs(m_in.c0, (scale_out->x = ijkVecLength3f(m_in.c0)));
	rot.c1 = ijkVecDivSafe3fs(m_in.c1, (scale_out->y = ijkVecLength3f(m_in.c1)));
	rot.c2 = ijkVecDivSafe3fs(m_in.c2, (scale_out->z = ijkVecLength3f(m_in.c2)));
	ijkMatGetRotate3f(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl fmat3 ijkMatInverseRotate3f(fmat3 const m_in)
{
	return ijkMatTranspose3f(m_in);
}

ijk_inl fmat3 ijkMatInverseScale3f(fmat3 const m_in)
{
	fmat3 const m_out = {
		ijk_recip_flt(m_in.x0), flt_zero, flt_zero,
		flt_zero, ijk_recip_flt(m_in.y1), flt_zero,
		flt_zero, flt_zero, ijk_recip_flt(m_in.z2),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatInverseRotateScale3f(fmat3 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	float const sx2_inv = ijkVecLengthSqInv3f(m_in.c0);
	float const sy2_inv = ijkVecLengthSqInv3f(m_in.c1);
	float const sz2_inv = ijkVecLengthSqInv3f(m_in.c2);
	fmat3 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv), (m_in.x2 * sz2_inv),
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv), (m_in.y2 * sz2_inv),
		(m_in.z0 * sx2_inv), (m_in.z1 * sy2_inv), (m_in.z2 * sz2_inv),
	};
	return m_out;
}

ijk_inl fmat3 ijkMatInverseTranspose3f(fmat3 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	fmat3 m_out;
	m_out.c0 = ijkVecMul3fs(m_in.c0, ijkVecLengthSqInv3f(m_in.c0));
	m_out.c1 = ijkVecMul3fs(m_in.c1, ijkVecLengthSqInv3f(m_in.c1));
	m_out.c2 = ijkVecMul3fs(m_in.c2, ijkVecLengthSqInv3f(m_in.c2));
	return m_out;
}

ijk_inl fmat3 ijkMatRotateAxisAngle3f(fvec3 const axis_unit, float const angle_degrees)
{
	float c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	float const x = axis_unit.x, y = axis_unit.y, z = axis_unit.z;
	ijkTrigSinCos_deg_flt(angle_degrees, &s, &c);
	t = flt_one - c;
	xs = x * s;
	ys = y * s;
	zs = z * s;
	xt = x * t;
	yt = y * t;
	zt = z * t;
	xyt = x * yt;
	yzt = y * zt;
	zxt = z * xt;
	return ijkMatInitElems3f(
		(x * xt + x), (xyt + zs), (zxt - ys),
		(xyt - zs), (y * yt + c), (yzt + xs),
		(zxt + ys), (yzt - xs), (z * zt + c));
}

ijk_inl fmat3 ijkMatRotateAxisAngleScale3f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale)
{
	fmat3 m_out = ijkMatRotateAxisAngle3f(axis_unit, angle_degrees);
	m_out.c0 = ijkVecMul3fs(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul3fs(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul3fs(m_out.c2, scale.z);
	return m_out;
}

ijk_inl fmat3 ijkMatGetRotateAxisAngle3f(fmat3 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out)
{
	float r;
	float const t = (m_in.x0 + m_in.y1 + m_in.z2 - flt_one);
	fvec3 const axis = {
		(m_in.z1 - m_in.y2),
		(m_in.x2 - m_in.z0),
		(m_in.y0 - m_in.x1),
	};
	r = ijkVecLength3f(axis);
	*axis_unit_out = ijkVecDivSafe3fs(axis, r);
	*angle_degrees_out = ijkTrigAtan2_deg_flt(r, t);
	return m_in;
}

ijk_inl fmat3 ijkMatGetRotateAxisAngleScale3f(fmat3 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out)
{
	fmat3 rot;
	rot.c0 = ijkVecDivSafe3fs(m_in.c0, (scale_out->x = ijkVecLength3f(m_in.c0)));
	rot.c1 = ijkVecDivSafe3fs(m_in.c1, (scale_out->y = ijkVecLength3f(m_in.c1)));
	rot.c2 = ijkVecDivSafe3fs(m_in.c2, (scale_out->z = ijkVecLength3f(m_in.c2)));
	ijkMatGetRotateAxisAngle3f(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}


//-----------------------------------------------------------------------------

// 4D struct-based special


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_FLOAT_INL_
#endif	// _IJK_MATRIX_FLOAT_H_