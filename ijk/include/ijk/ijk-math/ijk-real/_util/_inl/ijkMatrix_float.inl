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

	ijkMatrix_float.inl
	Inline definitions for float matrix types.
*/

#ifdef _IJK_MATRIX_FLOAT_H_
#ifndef _IJK_MATRIX_FLOAT_INL_
#define _IJK_MATRIX_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl float2m ijkMat2Pfm(float2x2 m_out)
{
	return m_out;
}

ijk_inl float3m ijkMat3Pfm(float3x3 m_out)
{
	return m_out;
}

ijk_inl float4m ijkMat4Pfm(float4x4 m_out)
{
	return m_out;
}


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

ijk_inl float2m ijkMatNegate2fm(float2x2 m_out, float2x2 const m_in)
{
	ijkVecNegate2fv(m_out[0], m_in[0]);
	ijkVecNegate2fv(m_out[1], m_in[1]);
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
	f32 const recip = ijk_recip_flt(s_rh);
	ijkVecMul2fvs(m_out[0], m_lh[0], recip);
	ijkVecMul2fvs(m_out[1], m_lh[1], recip);
	return m_out;
}

ijk_inl float2m ijkMatDivSafe2fms(float2x2 m_out, float2x2 const m_lh, f32 const s_rh)
{
	f32 const recip = ijk_recip_safe_flt(s_rh);
	ijkVecMul2fvs(m_out[0], m_lh[0], recip);
	ijkVecMul2fvs(m_out[1], m_lh[1], recip);
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

ijk_inl float3m ijkMatNegate3fm(float3x3 m_out, float3x3 const m_in)
{
	ijkVecNegate3fv(m_out[0], m_in[0]);
	ijkVecNegate3fv(m_out[1], m_in[1]);
	ijkVecNegate3fv(m_out[2], m_in[2]);
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
	f32 const recip = ijk_recip_flt(s_rh);
	ijkVecMul3fvs(m_out[0], m_lh[0], recip);
	ijkVecMul3fvs(m_out[1], m_lh[1], recip);
	ijkVecMul3fvs(m_out[2], m_lh[2], recip);
	return m_out;
}

ijk_inl float3m ijkMatDivSafe3fms(float3x3 m_out, float3x3 const m_lh, f32 const s_rh)
{
	f32 const recip = ijk_recip_safe_flt(s_rh);
	ijkVecMul3fvs(m_out[0], m_lh[0], recip);
	ijkVecMul3fvs(m_out[1], m_lh[1], recip);
	ijkVecMul3fvs(m_out[2], m_lh[2], recip);
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

ijk_inl float4m ijkMatNegate4fm(float4x4 m_out, float4x4 const m_in)
{
	ijkVecNegate4fv(m_out[0], m_in[0]);
	ijkVecNegate4fv(m_out[1], m_in[1]);
	ijkVecNegate4fv(m_out[2], m_in[2]);
	ijkVecNegate4fv(m_out[3], m_in[3]);
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
	f32 const recip = ijk_recip_flt(s_rh);
	ijkVecMul4fvs(m_out[0], m_lh[0], recip);
	ijkVecMul4fvs(m_out[1], m_lh[1], recip);
	ijkVecMul4fvs(m_out[2], m_lh[2], recip);
	ijkVecMul4fvs(m_out[3], m_lh[3], recip);
	return m_out;
}

ijk_inl float4m ijkMatDivSafe4fms(float4x4 m_out, float4x4 const m_lh, f32 const s_rh)
{
	f32 const recip = ijk_recip_safe_flt(s_rh);
	ijkVecMul4fvs(m_out[0], m_lh[0], recip);
	ijkVecMul4fvs(m_out[1], m_lh[1], recip);
	ijkVecMul4fvs(m_out[2], m_lh[2], recip);
	ijkVecMul4fvs(m_out[3], m_lh[3], recip);
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

ijk_inl fmat2 ijkMatNegate2f(fmat2 const m_in)
{
	fmat2 const m_out = {
		-m_in.x0, -m_in.y0,
		-m_in.x1, -m_in.y1,
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

ijk_inl fmat3 ijkMatNegate3f(fmat3 const m_in)
{
	fmat3 const m_out = {
		-m_in.x0, -m_in.y0, -m_in.z0,
		-m_in.x1, -m_in.y1, -m_in.z1,
		-m_in.x2, -m_in.y2, -m_in.z2,
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

ijk_inl fmat4 ijkMatNegate4f(fmat4 const m_in)
{
	fmat4 const m_out = {
		-m_in.x0, -m_in.y0, -m_in.z0, -m_in.w0,
		-m_in.x1, -m_in.y1, -m_in.z1, -m_in.w1,
		-m_in.x2, -m_in.y2, -m_in.z2, -m_in.w2,
		-m_in.x3, -m_in.y3, -m_in.z3, -m_in.w3,
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
	float2x2 const m_copy = {
		ijkMatMulRowVec2fmv(m_lh, m_rh[0], 0),
		ijkMatMulRowVec2fmv(m_lh, m_rh[0], 1),
		ijkMatMulRowVec2fmv(m_lh, m_rh[1], 0),
		ijkMatMulRowVec2fmv(m_lh, m_rh[1], 1),
	};
	return ijkMatCopy2fm2(m_out, m_copy);
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

ijk_inl float3m ijkMatTransposeMul3fms(float3x3 m_out, float3x3 const m_in, f32 const s)
{
	f32 tmp = m_in[0][1];
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
	float3x3 const m_copy = {
		ijkMatMulRowVec3fmv(m_lh, m_rh[0], 0),
		ijkMatMulRowVec3fmv(m_lh, m_rh[0], 1),
		ijkMatMulRowVec3fmv(m_lh, m_rh[0], 2),
		ijkMatMulRowVec3fmv(m_lh, m_rh[1], 0),
		ijkMatMulRowVec3fmv(m_lh, m_rh[1], 1),
		ijkMatMulRowVec3fmv(m_lh, m_rh[1], 2),
		ijkMatMulRowVec3fmv(m_lh, m_rh[2], 0),
		ijkMatMulRowVec3fmv(m_lh, m_rh[2], 1),
		ijkMatMulRowVec3fmv(m_lh, m_rh[2], 2),
	};
	return ijkMatCopy3fm3(m_out, m_copy);
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

ijk_inl float3m ijkMatLookAt3fm(float3x3 m_out, float3x3 m_inv_out_opt, float3 const origin, float3 const target, float3 const calibUnit, ijkTransformBasis const calibAxis)
{
	// right-handed: direction basis is from target to center, side = up x dir, up = dir x side
	uindex const up = calibAxis % 3, dir = (up + 1) % 3, side = (up + 2) % 3;
	ijkVecSub3fv(m_out[dir], origin, target);
	ijkVecNormalize3fv(m_out[dir], m_out[dir]);
	ijkVecCrossNormalize3fv(m_out[side], calibUnit, m_out[dir]);
	ijkVecCross3fv(m_out[up], m_out[dir], m_out[side]);
	if (m_inv_out_opt)
		ijkMatTranspose3fm(m_inv_out_opt, m_out);
	return m_out;
}


//-----------------------------------------------------------------------------

ijk_inl f32 ijkMatDeterminant4fm(float4x4 const m_in)
{
	float3 cross;
	f32 det = flt_zero;
	det += m_in[0][3] * ijkVecDot3fv(m_in[1], ijkVecCross3fv(cross, m_in[2], m_in[3]));
	det += m_in[1][3] * ijkVecDot3fv(m_in[2], ijkVecCross3fv(cross, m_in[3], m_in[0]));
	det += m_in[2][3] * ijkVecDot3fv(m_in[3], ijkVecCross3fv(cross, m_in[0], m_in[1]));
	det += m_in[3][3] * ijkVecDot3fv(m_in[0], ijkVecCross3fv(cross, m_in[1], m_in[2]));
	return det;
}

ijk_inl f32 ijkMatDeterminantInv4fm(float4x4 const m_in)
{
	f32 const s = ijkMatDeterminant4fm(m_in);
	return ijk_recip_flt(s);
}

ijk_inl f32 ijkMatDeterminantInvSafe4fm(float4x4 const m_in)
{
	f32 const s = ijkMatDeterminant4fm(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl f32 ijkMatMulRowVec4fmv(float4x4 const m_in, float4 const v_in, index const row)
{
	return (m_in[0][row] * v_in[0] + m_in[1][row] * v_in[1] + m_in[2][row] * v_in[2] + m_in[3][row] * v_in[3]);
}

ijk_inl floatv ijkMatGetRow4fm(float4 v_out, float4x4 const m_in, index const row)
{
	v_out[0] = m_in[0][row];
	v_out[1] = m_in[1][row];
	v_out[2] = m_in[2][row];
	v_out[3] = m_in[3][row];
	return v_out;
}

ijk_inl float4m ijkMatTranspose4fm(float4x4 m_out, float4x4 const m_in)
{
	f32 tmp = m_in[0][1];
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

ijk_inl float4m ijkMatTransposeMul4fms(float4x4 m_out, float4x4 const m_in, f32 const s)
{
	f32 tmp = m_in[0][1];
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

ijk_inl float4m ijkMatInverse4fm(float4x4 m_out, float4x4 const m_in)
{
	// block-wise inversion; upper-left 3x3 (A), bottom-right 1x1 (D)
	f32 const blockD = -m_in[3][3], blockInvD = ijk_recip_flt(blockD);
	float3 const blockB_D = {
		(m_in[3][0] * blockInvD), (m_in[3][1] * blockInvD), (m_in[3][2] * blockInvD),
	};
	float3 const blockC_D = {
		(blockInvD * m_in[0][3]), (blockInvD * m_in[1][3]), (blockInvD * m_in[2][3]),
	};
	float3x3 blockInvA = {
		(m_in[0][0] + blockB_D[0] * m_in[0][3]), (m_in[0][1] + blockB_D[1] * m_in[0][3]), (m_in[0][2] + blockB_D[2] * m_in[0][3]),
		(m_in[1][0] + blockB_D[0] * m_in[1][3]), (m_in[1][1] + blockB_D[1] * m_in[1][3]), (m_in[1][2] + blockB_D[2] * m_in[1][3]),
		(m_in[2][0] + blockB_D[0] * m_in[2][3]), (m_in[2][1] + blockB_D[1] * m_in[2][3]), (m_in[2][2] + blockB_D[2] * m_in[2][3]),
	};
	ijkMatInverse3fm(blockInvA, blockInvA);
	ijkVecCopy4fvw(m_out[0], blockInvA[0], ijkVecDot3fv(blockC_D, blockInvA[0]));
	ijkVecCopy4fvw(m_out[1], blockInvA[1], ijkVecDot3fv(blockC_D, blockInvA[1]));
	ijkVecCopy4fvw(m_out[2], blockInvA[2], ijkVecDot3fv(blockC_D, blockInvA[2]));
	ijkMatMulVec3fmv(m_out[3], blockInvA, blockB_D);
	m_out[3][3] = ijkVecDot3fv(m_out[3], blockC_D) - blockInvD;
	return m_out;
}

ijk_inl float4m ijkMatInverseSafe4fm(float4x4 m_out, float4x4 const m_in)
{
	f32 const blockD = -m_in[3][3], blockInvD = ijk_recip_safe_flt(blockD);
	float3 const blockB_D = {
		(m_in[3][0] * blockInvD), (m_in[3][1] * blockInvD), (m_in[3][2] * blockInvD),
	};
	float3 const blockC_D = {
		(blockInvD * m_in[0][3]), (blockInvD * m_in[1][3]), (blockInvD * m_in[2][3]),
	};
	float3x3 blockInvA = {
		(m_in[0][0] + blockB_D[0] * m_in[0][3]), (m_in[0][1] + blockB_D[1] * m_in[0][3]), (m_in[0][2] + blockB_D[2] * m_in[0][3]),
		(m_in[1][0] + blockB_D[0] * m_in[1][3]), (m_in[1][1] + blockB_D[1] * m_in[1][3]), (m_in[1][2] + blockB_D[2] * m_in[1][3]),
		(m_in[2][0] + blockB_D[0] * m_in[2][3]), (m_in[2][1] + blockB_D[1] * m_in[2][3]), (m_in[2][2] + blockB_D[2] * m_in[2][3]),
	};
	ijkMatInverseSafe3fm(blockInvA, blockInvA);
	ijkVecCopy4fvw(m_out[0], blockInvA[0], ijkVecDot3fv(blockC_D, blockInvA[0]));
	ijkVecCopy4fvw(m_out[1], blockInvA[1], ijkVecDot3fv(blockC_D, blockInvA[1]));
	ijkVecCopy4fvw(m_out[2], blockInvA[2], ijkVecDot3fv(blockC_D, blockInvA[2]));
	ijkMatMulVec3fmv(m_out[3], blockInvA, blockB_D);
	m_out[3][3] = ijkVecDot3fv(m_out[3], blockC_D) - blockInvD;
	return m_out;
}

ijk_inl floatv ijkMatMulVec4fmv(float4 v_out, float4x4 const m_lh, float4 const v_rh)
{
	float4 const v_copy = {
		ijkMatMulRowVec4fmv(m_lh, v_rh, 0),
		ijkMatMulRowVec4fmv(m_lh, v_rh, 1),
		ijkMatMulRowVec4fmv(m_lh, v_rh, 2),
		ijkMatMulRowVec4fmv(m_lh, v_rh, 3),
	};
	return ijkVecCopy4fv(v_out, v_copy);
}

ijk_inl float4m ijkMatMul4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	float4x4 const m_copy = {
		ijkMatMulRowVec4fmv(m_lh, m_rh[0], 0),
		ijkMatMulRowVec4fmv(m_lh, m_rh[0], 1),
		ijkMatMulRowVec4fmv(m_lh, m_rh[0], 2),
		ijkMatMulRowVec4fmv(m_lh, m_rh[0], 3),
		ijkMatMulRowVec4fmv(m_lh, m_rh[1], 0),
		ijkMatMulRowVec4fmv(m_lh, m_rh[1], 1),
		ijkMatMulRowVec4fmv(m_lh, m_rh[1], 2),
		ijkMatMulRowVec4fmv(m_lh, m_rh[1], 3),
		ijkMatMulRowVec4fmv(m_lh, m_rh[2], 0),
		ijkMatMulRowVec4fmv(m_lh, m_rh[2], 1),
		ijkMatMulRowVec4fmv(m_lh, m_rh[2], 2),
		ijkMatMulRowVec4fmv(m_lh, m_rh[2], 3),
		ijkMatMulRowVec4fmv(m_lh, m_rh[3], 0),
		ijkMatMulRowVec4fmv(m_lh, m_rh[3], 1),
		ijkMatMulRowVec4fmv(m_lh, m_rh[3], 2),
		ijkMatMulRowVec4fmv(m_lh, m_rh[3], 3),
	};
	return ijkMatCopy4fm4(m_out, m_copy);
}

ijk_inl float4m ijkMatDiv4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	float4x4 inv_rh;
	return ijkMatMul4fm(m_out, m_lh, ijkMatInverse4fm(inv_rh, m_rh));
}

ijk_inl float4m ijkMatDivSafe4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	float4x4 inv_rh;
	return ijkMatMul4fm(m_out, m_lh, ijkMatInverseSafe4fm(inv_rh, m_rh));
}

ijk_inl float4m ijkMatRotateXYZ4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems4fm(m_out,
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz), flt_zero,
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz), flt_zero,
		(+sy), (-sx * cy), (+cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateYZX4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems4fm(m_out,
		(+cy * cz), (+sz), (-sy * cz), flt_zero,
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx), flt_zero,
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateZXY4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems4fm(m_out,
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy), flt_zero,
		(-sz * cx), (+cz * cx), (+sx), flt_zero,
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateYXZ4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems4fm(m_out,
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz), flt_zero,
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz), flt_zero,
		(+sy * cx), (-sx), (+cy * cx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateXZY4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems4fm(m_out,
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy), flt_zero,
		(-sz), (+cx * cz), (+sx * cz), flt_zero,
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateZYX4fm(float4x4 m_out, float3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0], &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1], &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2], &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems4fm(m_out,
		(+cz * cy), (+sy * cy), (-sy), flt_zero,
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx), flt_zero,
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4km ijkMatGetRotateXYZ4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(+m_in[2][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(-m_in[1][0], +m_in[0][0]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(-m_in[2][1], +m_in[2][2]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateYZX4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(+m_in[0][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(-m_in[2][1], +m_in[1][1]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(-m_in[0][2], +m_in[0][0]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateZXY4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(+m_in[1][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(-m_in[0][2], +m_in[2][2]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(-m_in[1][0], +m_in[1][1]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateYXZ4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(-m_in[2][1]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(+m_in[2][0], +m_in[2][2]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(+m_in[0][1], +m_in[1][1]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateXZY4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(-m_in[1][0]);
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(+m_in[1][2], +m_in[1][1]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(+m_in[2][0], +m_in[0][0]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateZYX4fm(float4x4 const m_in, float3 rotateDegXYZ_out)
{
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(-m_in[0][2]);
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(+m_in[0][1], +m_in[0][0]);
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(+m_in[1][2], +m_in[2][2]);
	return m_in;
}

ijk_inl float4m ijkMatRotate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ4fm(m_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX4fm(m_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY4fm(m_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ4fm(m_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY4fm(m_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX4fm(m_out, rotateDegXYZ);
	}
	return m_out;
}

ijk_inl float4m ijkMatScale4fm(float4x4 m_out, float3 const scale)
{
	m_out[0][0] = scale[0];
	m_out[1][1] = scale[1];
	m_out[2][2] = scale[2];
	m_out[3][3] = flt_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatRotateScale4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale)
{
	ijkMatRotate4fm(m_out, order, rotateDegXYZ);
	ijkVecMul3fvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul3fvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul3fvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl float4km ijkMatGetRotate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ4fm(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX4fm(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY4fm(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ4fm(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY4fm(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX4fm(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl float4km ijkMatGetScale4fm(float4x4 const m_in, float3 scale_out)
{
	scale_out[0] = ijkVecLength3fv(m_in[0]);
	scale_out[1] = ijkVecLength3fv(m_in[1]);
	scale_out[2] = ijkVecLength3fv(m_in[2]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateScale4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out)
{
	float3x3 rot;
	ijkVecDivSafe3fvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3fv(m_in[0])));
	ijkVecDivSafe3fvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3fv(m_in[1])));
	ijkVecDivSafe3fvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3fv(m_in[2])));
	ijkMatGetRotate3fm(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl float4m ijkMatInverseRotate4fm(float4x4 m_out, float4x4 const m_in)
{
	f32 tmp = m_in[0][1];
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
	m_out[3][3] = flt_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatInverseScale4fm(float4x4 m_out, float4x4 const m_in)
{
	m_out[0][0] = ijk_recip_flt(m_in[0][0]);
	m_out[1][1] = ijk_recip_flt(m_in[1][1]);
	m_out[2][2] = ijk_recip_flt(m_in[2][2]);
	m_out[3][3] = flt_one;
	m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatInverseRotateScale4fm(float4x4 m_out, float4x4 const m_in)
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
	m_out[3][3] = flt_one;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatInverseTranspose4fm(float4x4 m_out, float4x4 const m_in)
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
	m_out[3][3] = flt_one;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	return m_out;
}

ijk_inl float4m ijkMatRotateAxisAngle4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees)
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
	return ijkMatInitElems4fm(m_out,
		(x * xt + x), (xyt + zs), (zxt - ys), flt_zero,
		(xyt - zs), (y * yt + c), (yzt + xs), flt_zero,
		(zxt + ys), (yzt - xs), (z * zt + c), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl float4m ijkMatRotateAxisAngleScale4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale)
{
	ijkMatRotateAxisAngle4fm(m_out, axis_unit, angle_degrees);
	ijkVecMul4fvs(m_out[0], m_out[0], scale[0]);
	ijkVecMul4fvs(m_out[1], m_out[1], scale[1]);
	ijkVecMul4fvs(m_out[2], m_out[2], scale[2]);
	return m_out;
}

ijk_inl float4km ijkMatGetRotateAxisAngle4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out)
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

ijk_inl float4km ijkMatGetRotateAxisAngleScale4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out)
{
	float3x3 rot;
	ijkVecDivSafe3fvs(rot[0], m_in[0], (scale_out[0] = ijkVecLength3fv(m_in[0])));
	ijkVecDivSafe3fvs(rot[1], m_in[1], (scale_out[1] = ijkVecLength3fv(m_in[1])));
	ijkVecDivSafe3fvs(rot[2], m_in[2], (scale_out[2] = ijkVecLength3fv(m_in[2])));
	ijkMatGetRotateAxisAngle3fm(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl float4m ijkMatTranslate4fm(float4x4 m_out, float3 const translate)
{
	ijkVecCopy4fv(m_out[0], float4_x);
	ijkVecCopy4fv(m_out[1], float4_y);
	ijkVecCopy4fv(m_out[2], float4_z);
	ijkVecCopy4fvw(m_out[3], translate, flt_one);
	return m_out;
}

ijk_inl float4m ijkMatRotateTranslate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate)
{
	ijkMatRotate4fm(m_out, order, rotateDegXYZ);
	ijkVecCopy3fv(m_out[3], translate);
	return m_out;
}

ijk_inl float4m ijkMatScaleTranslate4fm(float4x4 m_out, float3 const scale, float3 const translate)
{
	ijkMatScale4fm(m_out, scale);
	ijkVecCopy3fv(m_out[3], translate);
	return m_out;
}

ijk_inl float4m ijkMatRotateScaleTranslate4fm(float4x4 m_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const scale, float3 const translate)
{
	ijkMatRotateScale4fm(m_out, order, rotateDegXYZ, scale);
	ijkVecCopy3fv(m_out[3], translate);
	return m_out;
}

ijk_inl float4m ijkMatRotateAxisAngleTranslate4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate)
{
	ijkMatRotateAxisAngle4fm(m_out, axis_unit, angle_degrees);
	ijkVecCopy3fv(m_out[3], translate);
	return m_out;
}

ijk_inl float4m ijkMatRotateAxisAngleScaleTranslate4fm(float4x4 m_out, float3 const axis_unit, f32 const angle_degrees, float3 const scale, float3 const translate)
{
	ijkMatRotateAxisAngleScale4fm(m_out, axis_unit, angle_degrees, scale);
	ijkVecCopy3fv(m_out[3], translate);
	return m_out;
}

ijk_inl float4km ijkMatGetTranslate4fm(float4x4 const m_in, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return m_in;
}

ijk_inl float4km ijkMatGetRotateTranslate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return ijkMatGetRotate4fm(m_in, order, rotateDegXYZ_out);
}

ijk_inl float4km ijkMatGetScaleTranslate4fm(float4x4 const m_in, float3 scale_out, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return ijkMatGetScale4fm(m_in, scale_out);
}

ijk_inl float4km ijkMatGetRotateScaleTranslate4fm(float4x4 const m_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 scale_out, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return ijkMatGetRotateScale4fm(m_in, order, rotateDegXYZ_out, scale_out);
}

ijk_inl float4km ijkMatGetRotateAxisAngleTranslate4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return ijkMatGetRotateAxisAngle4fm(m_in, axis_unit_out, angle_degrees_out);
}

ijk_inl float4km ijkMatGetRotateAxisAngleScaleTranslate4fm(float4x4 const m_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 scale_out, float3 translate_out)
{
	ijkVecCopy3fv(translate_out, m_in[3]);
	return ijkMatGetRotateAxisAngleScale4fm(m_in, axis_unit_out, angle_degrees_out, scale_out);
}

ijk_inl float4m ijkMatInverseRotateTranslate4fm(float4x4 m_out, float4x4 const m_in)
{
	ijkMatInverseRotate4fm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl float4m ijkMatInverseScaleTranslate4fm(float4x4 m_out, float4x4 const m_in)
{
	ijkMatInverseScale4fm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl float4m ijkMatInverseRotateScaleTranslate4fm(float4x4 m_out, float4x4 const m_in)
{
	ijkMatInverseRotateScale4fm(m_out, m_in);
	m_out[3][0] = -(m_out[0][0] * m_in[3][0] + m_out[1][0] * m_in[3][1] + m_out[2][0] * m_in[3][2]);
	m_out[3][1] = -(m_out[0][1] * m_in[3][0] + m_out[1][1] * m_in[3][1] + m_out[2][1] * m_in[3][2]);
	m_out[3][2] = -(m_out[0][2] * m_in[3][0] + m_out[1][2] * m_in[3][1] + m_out[2][2] * m_in[3][2]);
	return m_out;
}

ijk_inl float4m ijkMatInverseTransposeTranslate4fm(float4x4 m_out, float4x4 const m_in)
{
	ijkMatInverseTranspose4fm(m_out, m_in);
	ijkVecCopy3fv(m_out[3], m_in[3]);
	return m_out;
}

ijk_inl float4m ijkMatMulTransform4fm(float4x4 m_out, float4x4 const m_lh, float4x4 const m_rh)
{
	float4x4 const m = {
		(m_lh[0][0] * m_rh[0][0] + m_lh[1][0] * m_rh[0][1] + m_lh[2][0] * m_rh[0][2]),
		(m_lh[0][1] * m_rh[0][0] + m_lh[1][1] * m_rh[0][1] + m_lh[2][1] * m_rh[0][2]),
		(m_lh[0][2] * m_rh[0][0] + m_lh[1][2] * m_rh[0][1] + m_lh[2][2] * m_rh[0][2]),
		flt_zero,
		(m_lh[0][0] * m_rh[1][0] + m_lh[1][0] * m_rh[1][1] + m_lh[2][0] * m_rh[1][2]),
		(m_lh[0][1] * m_rh[1][0] + m_lh[1][1] * m_rh[1][1] + m_lh[2][1] * m_rh[1][2]),
		(m_lh[0][2] * m_rh[1][0] + m_lh[1][2] * m_rh[1][1] + m_lh[2][2] * m_rh[1][2]),
		flt_zero,
		(m_lh[0][0] * m_rh[2][0] + m_lh[1][0] * m_rh[2][1] + m_lh[2][0] * m_rh[2][2]),
		(m_lh[0][1] * m_rh[2][0] + m_lh[1][1] * m_rh[2][1] + m_lh[2][1] * m_rh[2][2]),
		(m_lh[0][2] * m_rh[2][0] + m_lh[1][2] * m_rh[2][1] + m_lh[2][2] * m_rh[2][2]),
		flt_zero,
		(m_lh[0][0] * m_rh[3][0] + m_lh[1][0] * m_rh[3][1] + m_lh[2][0] * m_rh[3][2] + m_lh[3][0]),
		(m_lh[0][1] * m_rh[3][0] + m_lh[1][1] * m_rh[3][1] + m_lh[2][1] * m_rh[3][2] + m_lh[3][1]),
		(m_lh[0][2] * m_rh[3][0] + m_lh[1][2] * m_rh[3][1] + m_lh[2][2] * m_rh[3][2] + m_lh[3][2]),
		flt_one,
	};
	return ijkMatCopy4fm4(m_out, m);
}

ijk_inl floatv ijkMatMulVecTransform4fmv3(float3 v_out, float4x4 const m_lh, float3 const v_rh)
{
	float3 const v = {
		(m_lh[0][0] * v_rh[0] + m_lh[1][0] * v_rh[1] + m_lh[2][0] * v_rh[2] + m_lh[3][0]),
		(m_lh[0][1] * v_rh[0] + m_lh[1][1] * v_rh[1] + m_lh[2][1] * v_rh[2] + m_lh[3][1]),
		(m_lh[0][2] * v_rh[0] + m_lh[1][2] * v_rh[1] + m_lh[2][2] * v_rh[2] + m_lh[3][2]),
	};
	return ijkVecCopy3fv(v_out, v);
}

ijk_inl floatv ijkMatMulVecTransform4fmv4(float4 v_out, float4x4 const m_lh, float4 const v_rh)
{
	v_out[3] = flt_one;
	return ijkMatMulVecTransform4fmv3(v_out, m_lh, v_rh);
}

ijk_inl float4m ijkMatLookAt4fm(float4x4 m_out, float4x4 m_inv_out_opt, float3 const origin, float3 const target, float3 const calibUnit, ijkTransformBasis const calibAxis)
{
	// right-handed: direction basis is from target to center, side = up x dir, up = dir x side, pos = orig
	uindex const up = calibAxis % 3, dir = (up + 1) % 3, side = (up + 2) % 3, pos = ijkTransformOrig;
	ijkVecSub3fv(m_out[dir], origin, target);
	ijkVecNormalize3fv(m_out[dir], m_out[dir]);
	ijkVecCrossNormalize3fv(m_out[side], calibUnit, m_out[dir]);
	ijkVecCross3fv(m_out[up], m_out[dir], m_out[side]);
	ijkVecCopy3fv(m_out[pos], origin);
	if (m_inv_out_opt)
		ijkMatInverseRotateTranslate4fm(m_inv_out_opt, m_out);
	return m_out;
}

ijk_inl float4m ijkMatProjectionPerspective4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const fovyDeg, f32 const aspect, f32 const nearDist, f32 const farDist)
{
	if (m_out && fovyDeg > flt_zero && fovyDeg < flt_180 && aspect > flt_zero && nearDist > flt_zero && farDist > nearDist)
	{
		// top of near plane is calculated using tan(theta/2)
		// store half angle then use it to calculate top
		// t = n*tan(a/2)
		// r = t*aspect
		// y1 = n/t = n/(n*tan(a/2)) = 1/tan(a/2) = cot(a/2)
		// x0 = n/r = n/(t*aspect) = (n/t)/aspect = y1/aspect
		f32 const halfAngle = flt_half * fovyDeg;
		f32 const farToNearInv = flt_one / (nearDist - farDist);
		m_out[1][1] = ijkTrigCot_deg_flt(halfAngle);
		m_out[0][0] = m_out[1][1] / aspect;
		m_out[2][2] = (nearDist + farDist) * farToNearInv;
		m_out[2][3] = -flt_one;
		m_out[3][2] = flt_two * nearDist * farDist * farToNearInv;

		// the rest are zero
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[3][0] = m_out[3][1] = m_out[3][3] = m_out[2][0] = m_out[2][1] = flt_zero;

		// inverse
		if (m_inv_out_opt)
		{
			// t = n*tan(a/2) = n*sin(a/2)/cos(a/2)
			// r = t*aspect
			// y1 = t/n = (n*tan(a/2))/n = tan(a/2)
			// x0 = r/n = (t*aspect)/n = aspect*(t/n) = y1*aspect
			f32 const doubleNearFarInv = flt_half / (nearDist * farDist);
			m_inv_out_opt[1][1] = flt_one / m_out[1][1];
			m_inv_out_opt[0][0] = m_inv_out_opt[1][1] * aspect;
			m_inv_out_opt[2][3] = (nearDist - farDist) * doubleNearFarInv;
			m_inv_out_opt[3][2] = -flt_one;
			m_inv_out_opt[3][3] = (nearDist + farDist) * doubleNearFarInv;

			// zeros
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][2] = m_inv_out_opt[3][0] = m_inv_out_opt[3][1] = flt_zero;
		}
	}
	return m_out;
}

ijk_inl float4m ijkMatProjectionParallel4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const fovyDeg, f32 const aspect, f32 const nearDist, f32 const farDist)
{
	if (m_out && fovyDeg > flt_zero && fovyDeg < flt_180 && aspect > flt_zero && nearDist > flt_zero && farDist > nearDist)
	{
		f32 const halfAngle = flt_half * fovyDeg;
		f32 const farToNearInv = flt_one / (nearDist - farDist);
		m_out[1][1] = ijkTrigCot_deg_flt(halfAngle);
		m_out[0][0] = m_out[1][1] / aspect;
		m_out[2][2] = flt_two * farToNearInv;
		m_out[3][2] = (nearDist + farDist) * farToNearInv;
		m_out[3][3] = flt_one;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = m_out[3][0] = m_out[3][1] = flt_zero;

		if (m_inv_out_opt)
		{
			m_inv_out_opt[1][1] = flt_one / m_out[1][1];
			m_inv_out_opt[0][0] = m_inv_out_opt[1][1] * aspect;
			m_inv_out_opt[2][2] = flt_half * (nearDist - farDist);
			m_inv_out_opt[3][2] = -flt_half * (nearDist + farDist);
			m_inv_out_opt[3][3] = flt_one;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][3] = m_inv_out_opt[3][0] = m_inv_out_opt[3][1] = flt_zero;
		}
	}
	return m_out;
}

ijk_inl float4m ijkMatProjectionPerspectivePlanes4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const leftDist, f32 const rightDist, f32 const bottomDist, f32 const topDist, f32 const nearDist, f32 const farDist)
{
	if (m_out && leftDist != rightDist && bottomDist != topDist && nearDist > flt_zero && farDist > nearDist)
	{
		f32 const leftToRightInv = flt_one / (rightDist - leftDist);
		f32 const bottomToTopInv = flt_one / (topDist - bottomDist);
		f32 const farToNearInv = flt_one / (nearDist - farDist);
		f32 const doubleNear = nearDist + nearDist;
		m_out[0][0] = doubleNear * leftToRightInv;
		m_out[1][1] = doubleNear * bottomToTopInv;
		m_out[2][0] = (rightDist + leftDist) * leftToRightInv;
		m_out[2][1] = (topDist + bottomDist) * bottomToTopInv;
		m_out[2][2] = (nearDist + farDist) * farToNearInv;
		m_out[2][3] = -flt_one;
		m_out[3][2] = doubleNear * farDist * farToNearInv;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[3][0] = m_out[3][1] = m_out[3][3] = flt_zero;

		if (m_inv_out_opt)
		{
			f32 const doubleNearInv = flt_half / nearDist;
			f32 const doubleNearFarInv = flt_half / (nearDist * farDist);
			m_inv_out_opt[3][0] = (rightDist - leftDist) * doubleNearInv;
			m_inv_out_opt[3][1] = (topDist - bottomDist) * doubleNearInv;
			m_inv_out_opt[2][3] = (nearDist - farDist) * doubleNearFarInv;
			m_inv_out_opt[3][0] = (rightDist + leftDist) * doubleNearInv;
			m_inv_out_opt[3][1] = (topDist + bottomDist) * doubleNearInv;
			m_inv_out_opt[3][2] = -flt_one;
			m_inv_out_opt[3][3] = (nearDist + farDist) * doubleNearFarInv;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][2] = flt_zero;
		}
	}
	return m_out;
}

ijk_inl float4m ijkMatProjectionParallelPlanes4fm(float4x4 m_out, float4x4 m_inv_out_opt, f32 const leftDist, f32 const rightDist, f32 const bottomDist, f32 const topDist, f32 const nearDist, f32 const farDist)
{
	if (m_out && leftDist != rightDist && bottomDist != topDist && nearDist != farDist)
	{
		f32 const leftToRightInv = flt_one / (rightDist - leftDist);
		f32 const bottomToTopInv = flt_one / (topDist - bottomDist);
		f32 const farToNearInv = flt_one / (nearDist - farDist);
		m_out[0][0] = leftToRightInv + leftToRightInv;
		m_out[1][1] = bottomToTopInv + bottomToTopInv;
		m_out[2][2] = farToNearInv + farToNearInv;
		m_out[3][0] = -(rightDist + leftDist) * leftToRightInv;
		m_out[3][1] = -(topDist + bottomDist) * bottomToTopInv;
		m_out[3][2] = (nearDist + farDist) * farToNearInv;
		m_out[3][3] = flt_one;
		m_out[0][1] = m_out[0][2] = m_out[0][3] = m_out[1][0] = m_out[1][2] = m_out[1][3] = m_out[2][0] = m_out[2][1] = m_out[2][3] = flt_zero;

		if (m_inv_out_opt)
		{
			m_inv_out_opt[0][0] = flt_half * (rightDist - leftDist);
			m_inv_out_opt[1][1] = flt_half * (topDist - bottomDist);
			m_inv_out_opt[2][2] = flt_half * (nearDist - farDist);
			m_inv_out_opt[3][0] = flt_half * (rightDist + leftDist);
			m_inv_out_opt[3][1] = flt_half * (topDist + bottomDist);
			m_inv_out_opt[3][2] = -flt_half * (nearDist + farDist);
			m_inv_out_opt[3][3] = flt_one;
			m_inv_out_opt[0][1] = m_inv_out_opt[0][2] = m_inv_out_opt[0][3] = m_inv_out_opt[1][0] = m_inv_out_opt[1][2] = m_inv_out_opt[1][3] = m_inv_out_opt[2][0] = m_inv_out_opt[2][1] = m_inv_out_opt[2][3] = flt_zero;
		}
	}
	return m_out;
}

ijk_inl float4m ijkMatProjectionStereoConversion4fm(float4x4 m_left_out, float4x4 m_right_out, float4x4 m_left_inv_out_opt, float4x4 m_right_inv_out_opt, f32 const interocularDist, f32 const convergenceDist)
{
	if (interocularDist > flt_zero && convergenceDist > flt_zero)
	{
		f32 const dx3 = flt_half * interocularDist, dx2 = dx3 / convergenceDist;
		if (m_left_out)
		{
			ijkMatInit4fm(m_left_out);
			m_left_out[3][0] = +dx3;
			m_left_out[2][0] = +dx2;
		}
		if (m_right_out)
		{
			ijkMatInit4fm(m_right_out);
			m_right_out[3][0] = -dx3;
			m_right_out[2][0] = -dx2;
		}
		if (m_left_inv_out_opt)
		{
			ijkMatInit4fm(m_left_inv_out_opt);
			m_left_inv_out_opt[3][0] = -dx3;
			m_left_inv_out_opt[2][0] = -dx2;
		}
		if (m_right_inv_out_opt)
		{
			ijkMatInit4fm(m_right_inv_out_opt);
			m_right_inv_out_opt[3][0] = +dx3;
			m_right_inv_out_opt[2][0] = +dx2;
		}
	}
	return m_left_out;
}


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
	return (m_in.c0.v[row] * v_in.x + m_in.c1.v[row] * v_in.y);
}

ijk_inl fvec2 ijkMatGetRow2f(fmat2 const m_in, index const row)
{
	fvec2 const v_out = {
		m_in.c0.v[row],
		m_in.c1.v[row],
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
	ijkTrigSinCos_deg_flt(angle_degrees, m_out.c0.v + 1, m_out.c0.v + 0);
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
	ijkTrigSinCos_deg_flt(angle_degrees, m_out.c0.v + 1, m_out.c0.v + 0);
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
	return (m_in.c0.v[row] * v_in.x + m_in.c1.v[row] * v_in.y + m_in.c2.v[row] * v_in.z);
}

ijk_inl fvec3 ijkMatGetRow3f(fmat3 const m_in, index const row)
{
	fvec3 const v_out = {
		m_in.c0.v[row],
		m_in.c1.v[row],
		m_in.c2.v[row],
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
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
	f32 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f32 const x = axis_unit.x, y = axis_unit.y, z = axis_unit.z;
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

ijk_inl fmat3 ijkMatLookAt3f(fmat3* const m_inv_out_opt, fvec3 const origin, fvec3 const target, fvec3 const calibUnit, ijkTransformBasis const calibAxis)
{
	fmat3 rot;
	ijkMatLookAt3fm(rot.m, m_inv_out_opt->m, origin.v, target.v, calibUnit.v, calibAxis);
	return rot;
}


//-----------------------------------------------------------------------------

ijk_inl float ijkMatDeterminant4f(fmat4 const m_in)
{
	float det = flt_zero;
	det += m_in.w0 * ijkVecDot4f(m_in.c1, ijkVecCross4f(m_in.c2, m_in.c3));
	det += m_in.w1 * ijkVecDot4f(m_in.c2, ijkVecCross4f(m_in.c3, m_in.c0));
	det += m_in.w2 * ijkVecDot4f(m_in.c3, ijkVecCross4f(m_in.c0, m_in.c1));
	det += m_in.w3 * ijkVecDot4f(m_in.c0, ijkVecCross4f(m_in.c1, m_in.c2));
	return det;
}

ijk_inl float ijkMatDeterminantInv4f(fmat4 const m_in)
{
	float const s = ijkMatDeterminant4f(m_in);
	return ijk_recip_flt(s);
}

ijk_inl float ijkMatDeterminantInvSafe4f(fmat4 const m_in)
{
	float const s = ijkMatDeterminant4f(m_in);
	return ijk_recip_safe_flt(s);
}

ijk_inl float ijkMatMulRowVec4f(fmat4 const m_in, fvec4 const v_in, index const row)
{
	return (m_in.c0.v[row] * v_in.x + m_in.c1.v[row] * v_in.y + m_in.c2.v[row] * v_in.z + m_in.c3.v[row] * v_in.w);
}

ijk_inl fvec4 ijkMatGetRow4f(fmat4 const m_in, index const row)
{
	fvec4 const v_out = {
		m_in.c0.v[row],
		m_in.c1.v[row],
		m_in.c2.v[row],
		m_in.c3.v[row],
	};
	return v_out;
}

ijk_inl fmat4 ijkMatTranspose4f(fmat4 const m_in)
{
	fmat4 const m_out = {
		m_in.x0, m_in.x1, m_in.x2, m_in.x3,
		m_in.y0, m_in.y1, m_in.y2, m_in.y3,
		m_in.z0, m_in.z1, m_in.z2, m_in.z3,
		m_in.w0, m_in.w1, m_in.w2, m_in.w3,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatTransposeMul4fs(fmat4 const m_in, float const s)
{
	fmat4 const m_out = {
		(m_in.x0 * s), (m_in.x1 * s), (m_in.x2 * s), (m_in.x3 * s),
		(m_in.y0 * s), (m_in.y1 * s), (m_in.y2 * s), (m_in.y3 * s),
		(m_in.z0 * s), (m_in.z1 * s), (m_in.z2 * s), (m_in.z3 * s),
		(m_in.w0 * s), (m_in.w1 * s), (m_in.w2 * s), (m_in.w3 * s),
	};
	return m_out;
}

ijk_inl fmat4 ijkMatInverse4f(fmat4 const m_in)
{
	fmat4 m_out;
	ijkMatInverse4fm(m_out.m, m_in.m);
	return m_out;
}

ijk_inl fmat4 ijkMatInverseSafe4f(fmat4 const m_in)
{
	fmat4 m_out;
	ijkMatInverseSafe4fm(m_out.m, m_in.m);
	return m_out;
}

ijk_inl fvec4 ijkMatMulVec4f(fmat4 const m_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijkMatMulRowVec4f(m_lh, v_rh, 0),
		ijkMatMulRowVec4f(m_lh, v_rh, 1),
		ijkMatMulRowVec4f(m_lh, v_rh, 2),
		ijkMatMulRowVec4f(m_lh, v_rh, 3),
	};
	return v_out;
}

ijk_inl fmat4 ijkMatMul4f(fmat4 const m_lh, fmat4 const m_rh)
{
	fmat4 m_out;
	m_out.c0 = ijkMatMulVec4f(m_lh, m_rh.c0);
	m_out.c1 = ijkMatMulVec4f(m_lh, m_rh.c1);
	m_out.c2 = ijkMatMulVec4f(m_lh, m_rh.c2);
	m_out.c3 = ijkMatMulVec4f(m_lh, m_rh.c3);
	return m_out;
}

ijk_inl fmat4 ijkMatDiv4f(fmat4 const m_lh, fmat4 const m_rh)
{
	return ijkMatMul4f(m_lh, ijkMatInverse4f(m_rh));
}

ijk_inl fmat4 ijkMatDivSafe4f(fmat4 const m_lh, fmat4 const m_rh)
{
	return ijkMatMul4f(m_lh, ijkMatInverseSafe4f(m_rh));
}

ijk_inl fmat4 ijkMatRotateXYZ4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sy;
	cs = cx * sy;
	return ijkMatInitElems4f(
		(+cy * cz), (+cx * sz + ss * cz), (+sx * sz - cs * cz), flt_zero,
		(-cy * sz), (+cx * cz - ss * sz), (+sx * cz + cs * sz), flt_zero,
		(+sy), (-sx * cy), (+cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateYZX4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sz;
	cs = cy * sz;
	return ijkMatInitElems4f(
		(+cy * cz), (+sz), (-sy * cz), flt_zero,
		(+sy * sx - cs * cx), (+cz * cx), (+cy * sx + ss * cx), flt_zero,
		(+sy * cx + cs * sx), (-cz * sx), (+cy * cx - ss * sx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateZXY4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sx;
	cs = cz * sx;
	return ijkMatInitElems4f(
		(+cz * cy - ss * sy), (+sz * cy + cs * sy), (-cx * sy), flt_zero,
		(-sz * cx), (+cz * cx), (+sx), flt_zero,
		(+cz * sy + ss * cy), (+sz * sy - cs * cy), (+cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateYXZ4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sy * sx;
	cs = cy * sx;
	return ijkMatInitElems4f(
		(+ss * sz + cy * cz), (+cx * sz), (+cs * sz - sy * cz), flt_zero,
		(+ss * cz - cy * sz), (+cx * cz), (+cs * cz + sy * sz), flt_zero,
		(+sy * cx), (-sx), (+cy * cx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateXZY4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sx * sz;
	cs = cx * sz;
	return ijkMatInitElems4f(
		(+cz * cy), (+cs * cy + sx * sy), (+ss * cy - cx * sy), flt_zero,
		(-sz), (+cx * cz), (+sx * cz), flt_zero,
		(+cz * sy), (+cs * sy - sx * cy), (+ss * sy + cx * cy), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateZYX4f(fvec3 const rotateDegXYZ)
{
	f32 sx, sy, sz, cx, cy, cz, ss, cs;
	ijkTrigSinCos_deg_flt(rotateDegXYZ.x, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.y, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ.z, &sz, &cz);
	ss = sz * sy;
	cs = cz * sy;
	return ijkMatInitElems4f(
		(+cz * cy), (+sy * cy), (-sy), flt_zero,
		(+cs * sx - sz * cx), (+ss * sx + cz * cx), (+cy * sx), flt_zero,
		(+cs * cx + sz * sx), (+ss * cx - cz * sx), (+cy * cx), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatGetRotateXYZ4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_flt(+m_in.x2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(-m_in.x1, +m_in.x0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(-m_in.y2, +m_in.z2);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateYZX4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_flt(+m_in.y0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(-m_in.y2, +m_in.y1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(-m_in.z0, +m_in.x0);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateZXY4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_flt(+m_in.z1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(-m_in.z0, +m_in.z2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(-m_in.x1, +m_in.y1);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateYXZ4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->x = ijkTrigAsin_deg_flt(-m_in.y2);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(+m_in.x2, +m_in.z2);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(+m_in.y0, +m_in.y1);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateXZY4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->z = ijkTrigAsin_deg_flt(-m_in.x1);
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_flt(+m_in.z1, +m_in.y1);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(+m_in.x2, +m_in.x0);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateZYX4f(fmat4 const m_in, fvec3* const rotateDegXYZ_out)
{
	rotateDegXYZ_out->y = ijkTrigAsin_deg_flt(-m_in.z0);
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_flt(+m_in.y0, +m_in.x0);
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_flt(+m_in.z1, +m_in.z2);
	return m_in;
}

ijk_inl fmat4 ijkMatRotate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatRotateXYZ4f(rotateDegXYZ);
	case ijkRotationYZX:
		return ijkMatRotateYZX4f(rotateDegXYZ);
	case ijkRotationZXY:
		return ijkMatRotateZXY4f(rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkMatRotateYXZ4f(rotateDegXYZ);
	case ijkRotationXZY:
		return ijkMatRotateXZY4f(rotateDegXYZ);
	case ijkRotationZYX:
		return ijkMatRotateZYX4f(rotateDegXYZ);
	}
	//return m_out;
}

ijk_inl fmat4 ijkMatScale4f(fvec3 const scale)
{
	fmat4 const m_out = {
		scale.x, flt_zero, flt_zero, flt_zero,
		flt_zero, scale.y, flt_zero, flt_zero,
		flt_zero, flt_zero, scale.z, flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatRotateScale4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale)
{
	fmat4 m_out = ijkMatRotate4f(order, rotateDegXYZ);
	m_out.c0 = ijkVecMul4fs(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul4fs(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul4fs(m_out.c2, scale.z);
	return m_out;
}

ijk_inl fmat4 ijkMatGetRotate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkMatGetRotateXYZ4f(m_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkMatGetRotateYZX4f(m_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkMatGetRotateZXY4f(m_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkMatGetRotateYXZ4f(m_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkMatGetRotateXZY4f(m_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkMatGetRotateZYX4f(m_in, rotateDegXYZ_out);
	}
	return m_in;
}

ijk_inl fmat4 ijkMatGetScale4f(fmat4 const m_in, fvec3* const scale_out)
{
	scale_out->x = ijkVecLength3fv(m_in.c0.v);
	scale_out->y = ijkVecLength3fv(m_in.c1.v);
	scale_out->z = ijkVecLength3fv(m_in.c2.v);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateScale4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out)
{
	fmat4 rot;
	rot.c0 = ijkVecDivSafe4fs(m_in.c0, (scale_out->x = ijkVecLength3fv(m_in.c0.v)));
	rot.c1 = ijkVecDivSafe4fs(m_in.c1, (scale_out->y = ijkVecLength3fv(m_in.c1.v)));
	rot.c2 = ijkVecDivSafe4fs(m_in.c2, (scale_out->z = ijkVecLength3fv(m_in.c2.v)));
	ijkMatGetRotate4f(rot, order, rotateDegXYZ_out);
	return m_in;
}

ijk_inl fmat4 ijkMatInverseRotate4f(fmat4 const m_in)
{
	return ijkMatTranspose4f(m_in);
}

ijk_inl fmat4 ijkMatInverseScale4f(fmat4 const m_in)
{
	fmat4 const m_out = {
		ijk_recip_flt(m_in.x0), flt_zero, flt_zero, flt_zero,
		flt_zero, ijk_recip_flt(m_in.y1), flt_zero, flt_zero,
		flt_zero, flt_zero, ijk_recip_flt(m_in.z2), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatInverseRotateScale4f(fmat4 const m_in)
{
	// M = RS
	// M^-1 = (RS)^-1
	//		= S^-1 * R^-1
	//			R^-1 = R^T
	// M^-1 = S^-1 * R^T
	//		= S^-T * R^T
	//		= (R * S^-1)^T
	//		= ((RS) / S^2)^T
	float const sx2_inv = ijkVecLengthSqInv4f(m_in.c0);
	float const sy2_inv = ijkVecLengthSqInv4f(m_in.c1);
	float const sz2_inv = ijkVecLengthSqInv4f(m_in.c2);
	fmat4 const m_out = {
		(m_in.x0 * sx2_inv), (m_in.x1 * sy2_inv), (m_in.x2 * sz2_inv), flt_zero,
		(m_in.y0 * sx2_inv), (m_in.y1 * sy2_inv), (m_in.y2 * sz2_inv), flt_zero,
		(m_in.z0 * sx2_inv), (m_in.z1 * sy2_inv), (m_in.z2 * sz2_inv), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one,
	};
	return m_out;
}

ijk_inl fmat4 ijkMatInverseTranspose4f(fmat4 const m_in)
{
	// M = RS
	// M^-T = (RS)^-T
	//		= (S^-1 * R^-1)^T
	//		= R^-T * S^-T
	//			R^-T = R
	//			S^-T = S^-1
	// M^-T = R * S^-1
	//		= (RS) / S^2
	fmat4 m_out;
	m_out.c0 = ijkVecMul4fs(m_in.c0, ijkVecLengthSqInv4f(m_in.c0));
	m_out.c1 = ijkVecMul4fs(m_in.c1, ijkVecLengthSqInv4f(m_in.c1));
	m_out.c2 = ijkVecMul4fs(m_in.c2, ijkVecLengthSqInv4f(m_in.c2));
	m_out.c3 = ijkVecInitElems4f(flt_zero, flt_zero, flt_zero, flt_one);
	return m_out;
}

ijk_inl fmat4 ijkMatRotateAxisAngle4f(fvec3 const axis_unit, float const angle_degrees)
{
	f32 c, s, t, xs, ys, zs, xt, yt, zt, xyt, yzt, zxt;
	f32 const x = axis_unit.x, y = axis_unit.y, z = axis_unit.z;
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
	return ijkMatInitElems4f(
		(x * xt + x), (xyt + zs), (zxt - ys), flt_zero,
		(xyt - zs), (y * yt + c), (yzt + xs), flt_zero,
		(zxt + ys), (yzt - xs), (z * zt + c), flt_zero,
		flt_zero, flt_zero, flt_zero, flt_one);
}

ijk_inl fmat4 ijkMatRotateAxisAngleScale4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale)
{
	fmat4 m_out = ijkMatRotateAxisAngle4f(axis_unit, angle_degrees);
	m_out.c0 = ijkVecMul4fs(m_out.c0, scale.x);
	m_out.c1 = ijkVecMul4fs(m_out.c1, scale.y);
	m_out.c2 = ijkVecMul4fs(m_out.c2, scale.z);
	return m_out;
}

ijk_inl fmat4 ijkMatGetRotateAxisAngle4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out)
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

ijk_inl fmat4 ijkMatGetRotateAxisAngleScale4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out)
{
	fmat4 rot;
	rot.c0 = ijkVecDivSafe4fs(m_in.c0, (scale_out->x = ijkVecLength3fv(m_in.c0.v)));
	rot.c1 = ijkVecDivSafe4fs(m_in.c1, (scale_out->y = ijkVecLength3fv(m_in.c1.v)));
	rot.c2 = ijkVecDivSafe4fs(m_in.c2, (scale_out->z = ijkVecLength3fv(m_in.c2.v)));
	ijkMatGetRotateAxisAngle4f(rot, axis_unit_out, angle_degrees_out);
	return m_in;
}

ijk_inl fmat4 ijkMatTranslate4f(fvec3 const translate)
{
	fmat4 m_out;
	m_out.c0 = fvec4_x;
	m_out.c1 = fvec4_y;
	m_out.c2 = fvec4_z;
	m_out.c3 = ijkVecCopy4fw(translate, flt_one);
	return m_out;
}

ijk_inl fmat4 ijkMatRotateTranslate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const translate)
{
	fmat4 m_out = ijkMatRotate4f(order, rotateDegXYZ);
	ijkVecCopy3fv(m_out.c3.v, translate.v);
	return m_out;
}

ijk_inl fmat4 ijkMatScaleTranslate4f(fvec3 const scale, fvec3 const translate)
{
	fmat4 m_out = ijkMatScale4f(scale);
	ijkVecCopy3fv(m_out.c3.v, translate.v);
	return m_out;
}

ijk_inl fmat4 ijkMatRotateScaleTranslate4f(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const scale, fvec3 const translate)
{
	fmat4 m_out = ijkMatRotateScale4f(order, rotateDegXYZ, scale);
	ijkVecCopy3fv(m_out.c3.v, translate.v);
	return m_out;
}

ijk_inl fmat4 ijkMatRotateAxisAngleTranslate4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const translate)
{
	fmat4 m_out = ijkMatRotateAxisAngle4f(axis_unit, angle_degrees);
	ijkVecCopy3fv(m_out.c3.v, translate.v);
	return m_out;
}

ijk_inl fmat4 ijkMatRotateAxisAngleScaleTranslate4f(fvec3 const axis_unit, float const angle_degrees, fvec3 const scale, fvec3 const translate)
{
	fmat4 m_out = ijkMatRotateAxisAngleScale4f(axis_unit, angle_degrees, scale);
	ijkVecCopy3fv(m_out.c3.v, translate.v);
	return m_out;
}

ijk_inl fmat4 ijkMatGetTranslate4f(fmat4 const m_in, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return m_in;
}

ijk_inl fmat4 ijkMatGetRotateTranslate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return ijkMatGetRotate4f(m_in, order, rotateDegXYZ_out);
}

ijk_inl fmat4 ijkMatGetScaleTranslate4f(fmat4 const m_in, fvec3* const scale_out, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return ijkMatGetScale4f(m_in, scale_out);
}

ijk_inl fmat4 ijkMatGetRotateScaleTranslate4f(fmat4 const m_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const scale_out, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return ijkMatGetRotateScale4f(m_in, order, rotateDegXYZ_out, scale_out);
}

ijk_inl fmat4 ijkMatGetRotateAxisAngleTranslate4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return ijkMatGetRotateAxisAngle4f(m_in, axis_unit_out, angle_degrees_out);
}

ijk_inl fmat4 ijkMatGetRotateAxisAngleScaleTranslate4f(fmat4 const m_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const scale_out, fvec3* const translate_out)
{
	ijkVecCopy3fv(translate_out->v, m_in.c3.v);
	return ijkMatGetRotateAxisAngleScale4f(m_in, axis_unit_out, angle_degrees_out, scale_out);
}

ijk_inl fmat4 ijkMatInverseRotateTranslate4f(fmat4 const m_in)
{
	fmat4 m_out = ijkMatInverseRotate4f(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl fmat4 ijkMatInverseScaleTranslate4f(fmat4 const m_in)
{
	fmat4 m_out = ijkMatInverseScale4f(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl fmat4 ijkMatInverseRotateScaleTranslate4f(fmat4 const m_in)
{
	fmat4 m_out = ijkMatInverseRotateScale4f(m_in);
	m_out.x3 = -(m_out.x0 * m_in.x3 + m_out.x1 * m_in.y3 + m_out.x2 * m_in.z3);
	m_out.y3 = -(m_out.y0 * m_in.x3 + m_out.y1 * m_in.y3 + m_out.y2 * m_in.z3);
	m_out.z3 = -(m_out.z0 * m_in.x3 + m_out.z1 * m_in.y3 + m_out.z2 * m_in.z3);
	return m_out;
}

ijk_inl fmat4 ijkMatInverseTransposeTranslate4f(fmat4 const m_in)
{
	fmat4 m_out = ijkMatInverseTranspose4f(m_in);
	m_out.c3 = m_in.c3;
	return m_out;
}

ijk_inl fmat4 ijkMatMulTransform4f(fmat4 const m_lh, fmat4 const m_rh)
{
	fmat4 const m_out = {
		(m_lh.m00 * m_rh.m00 + m_lh.m10 * m_rh.m01 + m_lh.m20 * m_rh.m02),
		(m_lh.m01 * m_rh.m00 + m_lh.m11 * m_rh.m01 + m_lh.m21 * m_rh.m02),
		(m_lh.m02 * m_rh.m00 + m_lh.m12 * m_rh.m01 + m_lh.m22 * m_rh.m02),
		flt_zero,
		(m_lh.m00 * m_rh.m10 + m_lh.m10 * m_rh.m11 + m_lh.m20 * m_rh.m12),
		(m_lh.m01 * m_rh.m10 + m_lh.m11 * m_rh.m11 + m_lh.m21 * m_rh.m12),
		(m_lh.m02 * m_rh.m10 + m_lh.m12 * m_rh.m11 + m_lh.m22 * m_rh.m12),
		flt_zero,
		(m_lh.m00 * m_rh.m20 + m_lh.m10 * m_rh.m21 + m_lh.m20 * m_rh.m22),
		(m_lh.m01 * m_rh.m20 + m_lh.m11 * m_rh.m21 + m_lh.m21 * m_rh.m22),
		(m_lh.m02 * m_rh.m20 + m_lh.m12 * m_rh.m21 + m_lh.m22 * m_rh.m22),
		flt_zero,
		(m_lh.m00 * m_rh.m30 + m_lh.m10 * m_rh.m31 + m_lh.m20 * m_rh.m32 + m_lh.m30),
		(m_lh.m01 * m_rh.m30 + m_lh.m11 * m_rh.m31 + m_lh.m21 * m_rh.m32 + m_lh.m31),
		(m_lh.m02 * m_rh.m30 + m_lh.m12 * m_rh.m31 + m_lh.m22 * m_rh.m32 + m_lh.m32),
		flt_one,
	};
	return m_out;
}

ijk_inl fvec3 ijkMatMulVecTransform4fv3(fmat4 const m_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		(m_lh.m00 * v_rh.x + m_lh.m10 * v_rh.y + m_lh.m20 * v_rh.z + m_lh.m30),
		(m_lh.m01 * v_rh.x + m_lh.m11 * v_rh.y + m_lh.m21 * v_rh.z + m_lh.m31),
		(m_lh.m02 * v_rh.x + m_lh.m12 * v_rh.y + m_lh.m22 * v_rh.z + m_lh.m32),
	};
	return v_out;
}

ijk_inl fvec4 ijkMatMulVecTransform4fv4(fmat4 const m_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		(m_lh.m00 * v_rh.x + m_lh.m10 * v_rh.y + m_lh.m20 * v_rh.z + m_lh.m30),
		(m_lh.m01 * v_rh.x + m_lh.m11 * v_rh.y + m_lh.m21 * v_rh.z + m_lh.m31),
		(m_lh.m02 * v_rh.x + m_lh.m12 * v_rh.y + m_lh.m22 * v_rh.z + m_lh.m32),
		flt_one,
	};
	return v_out;
}

ijk_inl fmat4 ijkMatLookAt4f(fmat4* const m_inv_out_opt, fvec3 const origin, fvec3 const target, fvec3 const calibUnit, ijkTransformBasis const calibAxis)
{
	fmat4 rot;
	ijkMatLookAt4fm(rot.m, m_inv_out_opt->m, origin.v, target.v, calibUnit.v, calibAxis);
	return rot;
}

ijk_inl fmat4 ijkMatProjectionPerspective4f(fmat4* const m_inv_out_opt, float const fovyDeg, float const aspect, float const nearDist, float const farDist)
{
	fmat4 m_out;
	ijkMatProjectionPerspective4fm(m_out.m, (float4m)m_inv_out_opt, fovyDeg, aspect, nearDist, farDist);
	return m_out;
}

ijk_inl fmat4 ijkMatProjectionParallel4f(fmat4* const m_inv_out_opt, float const fovyDeg, float const aspect, float const nearDist, float const farDist)
{
	fmat4 m_out;
	ijkMatProjectionParallel4fm(m_out.m, (float4m)m_inv_out_opt, fovyDeg, aspect, nearDist, farDist);
	return m_out;
}

ijk_inl fmat4 ijkMatProjectionPerspectivePlanes4f(fmat4* const m_inv_out_opt, float const leftDist, float const rightDist, float const bottomDist, float const topDist, float const nearDist, float const farDist)
{
	fmat4 m_out;
	ijkMatProjectionPerspectivePlanes4fm(m_out.m, (float4m)m_inv_out_opt, leftDist, rightDist, bottomDist, topDist, nearDist, farDist);
	return m_out;
}

ijk_inl fmat4 ijkMatProjectionParallelPlanes4f(fmat4* const m_inv_out_opt, float const leftDist, float const rightDist, float const bottomDist, float const topDist, float const nearDist, float const farDist)
{
	fmat4 m_out;
	ijkMatProjectionParallelPlanes4fm(m_out.m, (float4m)m_inv_out_opt, leftDist, rightDist, bottomDist, topDist, nearDist, farDist);
	return m_out;
}

ijk_inl fmat4 ijkMatProjectionStereoConversion4f(fmat4* const m_left_out, fmat4* const m_right_out, fmat4* const m_left_inv_out_opt, fmat4* const m_right_inv_out_opt, float const interocularDist, float const convergenceDist)
{
	ijkMatProjectionStereoConversion4fm((float4m)m_left_out, (float4m)m_right_out, (float4m)m_left_inv_out_opt, (float4m)m_right_inv_out_opt, interocularDist, convergenceDist);
	return *m_left_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_MATRIX_FLOAT_INL_
#endif	// _IJK_MATRIX_FLOAT_H_