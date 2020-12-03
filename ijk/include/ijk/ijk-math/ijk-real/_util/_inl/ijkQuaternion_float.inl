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

	ijkQuaternion_float.inl
	Inline definitions for float quaternion types.
*/

#ifdef _IJK_QUATERNION_FLOAT_H_
#ifndef _IJK_QUATERNION_FLOAT_INL_
#define _IJK_QUATERNION_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl floatv ijkQuatPfv(float4 q_out)
{
	return q_out;
}

ijk_inl float4m ijkDualQuatPfm(float2x4 dq_out)
{
	return dq_out;
}


//-----------------------------------------------------------------------------

ijk_inl floatv ijkQuatInitQfv(float4 q_out)
{
	q_out[0] = q_out[1] = q_out[2] = flt_zero;
	q_out[3] = flt_one;
	return q_out;
}

ijk_inl floatv ijkQuatInitZeroQfv(float4 q_out)
{
	q_out[0] = q_out[1] = q_out[2] = q_out[3] = flt_zero;
	return q_out;
}

ijk_inl floatv ijkQuatInitElemsQfv(float4 q_out, f32 const x, f32 const y, f32 const z, f32 const w)
{
	q_out[0] = x;
	q_out[1] = y;
	q_out[2] = z;
	q_out[3] = w;
	return q_out;
}

ijk_inl floatv ijkQuatInitVecReQfv(float4 q_out, float3 const vec, f32 const re)
{
	q_out[0] = vec[0];
	q_out[1] = vec[1];
	q_out[2] = vec[2];
	q_out[3] = re;
	return q_out;
}

ijk_inl floatv ijkQuatInitVecProductQfv(float4 q_out, float3 const v_lh, float3 const v_rh)
{
	q_out[3] = -ijkVecDot3fv(v_lh, v_rh);
	return ijkVecCross3fv(q_out, v_lh, v_rh);
}

ijk_inl floatv ijkQuatInitVecProductSqrtQfv(float4 q_out, float3 const v_lh, float3 const v_rh)
{
	float3 const hv = {
		flt_half * (v_lh[0] + v_rh[0]),
		flt_half * (v_lh[1] + v_rh[1]),
		flt_half * (v_lh[2] + v_rh[2]),
	};
	return ijkQuatInitVecProductQfv(q_out, v_lh, hv);
}

ijk_inl floatv ijkQuatInitVecProductSqrtUnitQfv(float4 q_out, float3 const v_lh, float3 const v_rh)
{
	float3 hv = {
		flt_half * (v_lh[0] + v_rh[0]),
		flt_half * (v_lh[1] + v_rh[1]),
		flt_half * (v_lh[2] + v_rh[2]),
	};
	return ijkQuatInitVecProductQfv(q_out, v_lh, ijkVecNormalize3fv(hv, hv));
}

ijk_inl floatv ijkQuatInitMatQfv3(float4 q_out, float3x3 const m_in)
{
	f32 t, w, x, y, z;
	f32 diag = (m_in[0][0] + m_in[1][1] + m_in[2][2]);

	// scale is the sixth root of the determinant
	// alternatively, since it is a uniform scale, each column's squared 
	//	length gives same scale value
	f32 const s2 = ijkVecLength3fv(*m_in);
	if (diag > flt_zero)
	{
		// basic formula for quaternion with scale: 
		//	W = sqrt(s2 + m00 + m11 + m22) / 2
		//		= sqrt(s2 + s2(w2 + x2 - y2 - z2) + s2(w2 - x2 + y2 - z2) + s2(w2 - x2 - y2 + z2)) / 2
		//		= sqrt(s2(1 + 3w2 - x2 - y2 - z2)) / 2
		//		= sqrt(s2*4w2) / 2
		//		= 2sw / 2
		//		= sw
		//	t = 1 / (2 sqrt(s2 + m00 + m11 + m22))
		//		= 1 / (4W)
		//		= 1 / (4sw)
		//	Xi+Yj+Zk = t(m12 - m21)i + t(m20 - m02)j + t(m01 - m10)k
		//		= s2(yz + xw - yz + xw)2i / 4sw + s2(zx + yw - zx + yw)2j / 4sw + s2(xy + zw - xy + zw)2k / 4sw
		//		= s(2xw)i / 2w + s(2yw)j / 2w + s(2zw)k / 2w
		//		= sxi + syj + szk
		diag += s2;
		w = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / w;
		x = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[0][1] - m_in[1][0]);
	}
	else if (m_in[0][0] > m_in[1][1] && m_in[0][0] > m_in[2][2])
	{
		// favors first column: 
		//	Xi = sqrt(s2 + m00 - m11 - m22)i / 2
		//	t = 1 / (4X)
		//	W+Yj+Zk = t(m12 - m21) + t(m01 + m10)j + t(m20 + m02)k
		diag = s2 + m_in[0][0] - m_in[1][1] - m_in[2][2];
		x = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / x;
		w = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[0][1] + m_in[1][0]);
		z = t * (m_in[2][0] + m_in[0][2]);
	}
	else if (m_in[1][1] > m_in[2][2]) // && m_in[1][1] > m_in[0][0]
	{
		// favors second column: 
		//	Yj = sqrt(s2 - m00 + m11 - m22)j / 2
		//	t = 1 / (4Y)
		//	W+Zk+Xi = t(m20 - m02) + t(m12 + m21)k + t(m01 + m10)i
		diag = s2 - m_in[0][0] + m_in[1][1] - m_in[2][2];
		y = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / y;
		w = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[1][2] + m_in[2][1]);
		x = t * (m_in[0][1] + m_in[1][0]);
	}
	else // if (m_in[2][2] > m_in[0][0] && m_in[2][2] > m_in[1][1])
	{
		// favors second column: 
		//	Zk = sqrt(s2 - m00 - m11 + m22)k / 2
		//	t = 1 / (4Z)
		//	W+Xi+Yj = t(m01 - m10) + t(m20 + m02)i + t(m12 + m21)j
		diag = s2 - m_in[0][0] - m_in[1][1] + m_in[2][2];
		z = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / z;
		w = t * (m_in[0][1] - m_in[1][0]);
		x = t * (m_in[2][0] + m_in[0][2]);
		y = t * (m_in[1][2] + m_in[2][1]);
	}
	return ijkQuatInitElemsQfv(q_out, x, y, z, w);
}

ijk_inl floatv ijkQuatInitMatQfv4(float4 q_out, float4x4 const m_in)
{
	f32 t, w, x, y, z;
	f32 diag = (m_in[0][0] + m_in[1][1] + m_in[2][2]);
	f32 const s2 = ijkVecLength3fv(*m_in);
	if (diag > flt_zero)
	{
		diag += s2;
		w = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / w;
		x = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[0][1] - m_in[1][0]);
	}
	else if (m_in[0][0] > m_in[1][1] && m_in[0][0] > m_in[2][2])
	{
		diag = s2 + m_in[0][0] - m_in[1][1] - m_in[2][2];
		x = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / x;
		w = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[0][1] + m_in[1][0]);
		z = t * (m_in[2][0] + m_in[0][2]);
	}
	else if (m_in[1][1] > m_in[2][2]) // && m_in[1][1] > m_in[0][0]
	{
		diag = s2 - m_in[0][0] + m_in[1][1] - m_in[2][2];
		y = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / y;
		w = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[1][2] + m_in[2][1]);
		x = t * (m_in[0][1] + m_in[1][0]);
	}
	else // if (m_in[2][2] > m_in[0][0] && m_in[2][2] > m_in[1][1])
	{
		diag = s2 - m_in[0][0] - m_in[1][1] + m_in[2][2];
		z = flt_half * ijkSqrt_flt(diag);
		t = flt_quarter / z;
		w = t * (m_in[0][1] - m_in[1][0]);
		x = t * (m_in[2][0] + m_in[0][2]);
		y = t * (m_in[1][2] + m_in[2][1]);
	}
	return ijkQuatInitElemsQfv(q_out, x, y, z, w);
}

ijk_inl floatv ijkQuatCopyQfv(float4 q_out, float4 const q_in)
{
	q_out[0] = q_in[0];
	q_out[1] = q_in[1];
	q_out[2] = q_in[2];
	q_out[3] = q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatNegateQfv(float4 q_out, float4 const q_in)
{
	q_out[0] = -q_in[0];
	q_out[1] = -q_in[1];
	q_out[2] = -q_in[2];
	q_out[3] = -q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatConjugateQfv(float4 q_out, float4 const q_in)
{
	q_out[0] = -q_in[0];
	q_out[1] = -q_in[1];
	q_out[2] = -q_in[2];
	q_out[3] = +q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatConjugateMulQfvs(float4 q_out, float4 const q_in, f32 const s)
{
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = +q_in[3] * s;
	return q_out;
}

ijk_inl floatv ijkQuatNegateConjugateQfv(float4 q_out, float4 const q_in)
{
	q_out[0] = +q_in[0];
	q_out[1] = +q_in[1];
	q_out[2] = +q_in[2];
	q_out[3] = -q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatNegateConjugateMulQfvs(float4 q_out, float4 const q_in, f32 const s)
{
	q_out[0] = +q_in[0] * s;
	q_out[1] = +q_in[1] * s;
	q_out[2] = +q_in[2] * s;
	q_out[3] = -q_in[3] * s;
	return q_out;
}

ijk_inl floatv ijkQuatAddQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{
	q_out[0] = q_lh[0] + q_rh[0];
	q_out[1] = q_lh[1] + q_rh[1];
	q_out[2] = q_lh[2] + q_rh[2];
	q_out[3] = q_lh[3] + q_rh[3];
	return q_out;
}

ijk_inl floatv ijkQuatSubQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{
	q_out[0] = q_lh[0] - q_rh[0];
	q_out[1] = q_lh[1] - q_rh[1];
	q_out[2] = q_lh[2] - q_rh[2];
	q_out[3] = q_lh[3] - q_rh[3];
	return q_out;
}

ijk_inl floatv ijkQuatMulQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{
	q_out[0] = q_lh[0] * s_rh;
	q_out[1] = q_lh[1] * s_rh;
	q_out[2] = q_lh[2] * s_rh;
	q_out[3] = q_lh[3] * s_rh;
	return q_out;
}

ijk_inl floatv ijkQuatDivQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	return ijkQuatMulQfvs(q_out, q_lh, s);
}

ijk_inl floatv ijkQuatDivSafeQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	return ijkQuatMulQfvs(q_out, q_lh, s);
}

ijk_inl f32 ijkQuatLengthSqQfv(float4 const q_in)
{
	return ijkVecLengthSq4fv(q_in);
}

ijk_inl f32 ijkQuatLengthQfv(float4 const q_in)
{
	return ijkVecLength4fv(q_in);
}

ijk_inl f32 ijkQuatLengthSqInvQfv(float4 const q_in)
{
	return ijkVecLengthSqInv4fv(q_in);
}

ijk_inl f32 ijkQuatLengthInvQfv(float4 const q_in)
{
	return ijkVecLengthInv4fv(q_in);
}

ijk_inl f32 ijkQuatLengthSqInvSafeQfv(float4 const q_in)
{
	return ijkVecLengthSqInvSafe4fv(q_in);
}

ijk_inl f32 ijkQuatLengthInvSafeQfv(float4 const q_in)
{
	return ijkVecLengthInvSafe4fv(q_in);
}

ijk_inl floatv ijkQuatNormalizeQfv(float4 q_out, float4 const q_in)
{
	return ijkVecNormalize4fv(q_out, q_in);
}

ijk_inl floatv ijkQuatNormalizeSafeQfv(float4 q_out, float4 const q_in)
{
	return ijkVecNormalizeSafe4fv(q_out, q_in);
}

ijk_inl floatv ijkQuatInverseQfv(float4 q_out, float4 const q_in)
{
	// q^-1 = q* / |q|^2
	f32 const s = ijkQuatLengthSqInvQfv(q_in);
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = q_in[3] * s;
	return q_out;
}

ijk_inl floatv ijkQuatInverseSafeQfv(float4 q_out, float4 const q_in)
{
	f32 const s = ijkQuatLengthSqInvSafeQfv(q_in);
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = q_in[3] * s;
	return q_out;
}

ijk_inl floatv ijkQuatMulVecQfv3(float4 q_out, float4 const q_lh, float3 const v_rh)
{
	// ql vr = (vl + wl)vr
	//		= vl vr + wl vr
	//		= vl x vr - vl . vr + wl vr
	//		= (vl x vr + wl vr) - (vl . vr)
	float4 q;
	q[0] = q_lh[1] * v_rh[2] - q_lh[2] * v_rh[1] + q_lh[3] * v_rh[0];
	q[1] = q_lh[2] * v_rh[0] - q_lh[0] * v_rh[2] + q_lh[3] * v_rh[1];
	q[2] = q_lh[0] * v_rh[1] - q_lh[1] * v_rh[0] + q_lh[3] * v_rh[2];
	q[3] = -q_lh[0] * v_rh[0] - q_lh[1] * v_rh[1] - q_lh[2] * v_rh[2];
	return ijkQuatCopyQfv(q_out, q);
}

ijk_inl floatv ijkQuatMulVecQfv3q(float4 q_out, float3 const v_lh, float4 const q_rh)
{
	// vl qr = vl(vr + wr)
	//		= vl vr + vr wr
	//		= vl x vr - vl . vr + vr wr
	//		= (vl x vr + vr wr) - (vl . vr)
	float4 q;
	q[0] = v_lh[1] * q_rh[2] - v_lh[2] * q_rh[1] + v_lh[0] * q_rh[3];
	q[1] = v_lh[2] * q_rh[0] - v_lh[0] * q_rh[2] + v_lh[1] * q_rh[3];
	q[2] = v_lh[0] * q_rh[1] - v_lh[1] * q_rh[0] + v_lh[2] * q_rh[3];
	q[3] = -v_lh[0] * q_rh[0] - v_lh[1] * q_rh[1] - v_lh[2] * q_rh[2];
	return ijkQuatCopyQfv(q_out, q);
}

ijk_inl floatv ijkQuatMulQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{
	// ql qr = (vl + wl)(vr + wr)
	//		= vl vr + vl wr + wl vr + wl wr
	//		= vl x vr - vl . vr + vl wr + wl vr + wl wr
	//		= (vl x vr + vl wr + wl vr) + (wl wr - vl . vr)
	float4 q;
	q[0] = q_lh[1] * q_rh[2] - q_lh[2] * q_rh[1] + q_lh[3] * q_rh[0] + q_lh[0] * q_rh[3];
	q[1] = q_lh[2] * q_rh[0] - q_lh[0] * q_rh[2] + q_lh[3] * q_rh[1] + q_lh[1] * q_rh[3];
	q[2] = q_lh[0] * q_rh[1] - q_lh[1] * q_rh[0] + q_lh[3] * q_rh[2] + q_lh[2] * q_rh[3];
	q[3] = q_lh[3] * q_rh[3] - q_lh[0] * q_rh[0] - q_lh[1] * q_rh[1] - q_lh[2] * q_rh[2];
	return ijkQuatCopyQfv(q_out, q);
}

ijk_inl floatv ijkQuatDivQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{
	float4 q_inv;
	ijkQuatInverseQfv(q_inv, q_rh);
	return ijkQuatMulQfv(q_out, q_lh, q_inv);
}

ijk_inl floatv ijkQuatRotateXYZQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = cx * sy * sz + sx * cy * cz;
	q_out[1] = cx * sy * cz - sx * cy * sz;
	q_out[2] = cx * cy * sz + sx * sy * cz;
	q_out[3] = cx * cy * cz - sx * sy * sz;
	return q_out;
}

ijk_inl floatv ijkQuatRotateYZXQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = cy * cz * sx + sy * sz * cx;
	q_out[1] = cy * sz * sx + sy * cz * cx;
	q_out[2] = cy * sz * cx - sy * cz * sx;
	q_out[3] = cy * cz * cx - sy * sz * sx;
	return q_out;
}

ijk_inl floatv ijkQuatRotateZXYQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = cz * sx * cy - sz * cx * sy;
	q_out[1] = cz * cx * sy + sz * sx * cy;
	q_out[2] = cz * sx * sy + sz * cx * cy;
	q_out[3] = cz * cx * cy - sz * sx * sy;
	return q_out;
}

ijk_inl floatv ijkQuatRotateYXZQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = cy * sx * cz + sy * cx * sz;
	q_out[1] = sy * cx * cz - cy * sx * sz;
	q_out[2] = cy * cx * sz - sy * sx * cz;
	q_out[3] = cy * cx * cz + sy * sx * sz;
	return q_out;
}

ijk_inl floatv ijkQuatRotateXZYQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = sx * cz * cy - cx * sz * sy;
	q_out[1] = cx * cz * sy - sx * sz * cy;
	q_out[2] = cx * sz * cy + sx * cz * sy;
	q_out[3] = cx * cz * cy + sx * sz * sy;
	return q_out;
}

ijk_inl floatv ijkQuatRotateZYXQfv(float4 q_out, float3 const rotateDegXYZ)
{
	f32 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_flt(rotateDegXYZ[0] * flt_half, &sx, &cx);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[1] * flt_half, &sy, &cy);
	ijkTrigSinCos_deg_flt(rotateDegXYZ[2] * flt_half, &sz, &cz);
	q_out[0] = cz * cy * sx - sz * sy * cx;
	q_out[1] = cz * sy * cx + sz * cy * sx;
	q_out[2] = sz * cy * cx - cz * sy * sx;
	q_out[3] = cz * cy * cx + sz * sy * sx;
	return q_out;
}

ijk_inl floatkv ijkQuatGetRotateXYZQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	f32 s = flt_two * (z * x + y * w), c;
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * z - y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * x - y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateYZXQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	f32 s = flt_two * (x * y + z * w), c;
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * x - z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * y - z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateZXYQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	f32 s = flt_two * (y * z + x * w), c;
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * y - x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * z - x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateYXZQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	f32 s = flt_two * (w * x - y * z), c;
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * y + x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * z + x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateXZYQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	f32 s = flt_two * (w * z - x * y), c;
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * x + z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * y + z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateZYXQfv(float4 const q_in, float3 rotateDegXYZ_out)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	f32 s = flt_two * (w * y - z * x), c;
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_flt(s);
	s = flt_two * (w * z + y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_flt(s, c);
	s = flt_two * (w * x + y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_flt(s, c);
	return q_in;
}

ijk_inl floatv ijkQuatRotateQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatRotateXYZQfv(q_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkQuatRotateYZXQfv(q_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkQuatRotateZXYQfv(q_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkQuatRotateYXZQfv(q_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkQuatRotateXZYQfv(q_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkQuatRotateZYXQfv(q_out, rotateDegXYZ);
	}
	return q_out;
}

ijk_inl floatv ijkQuatAxisAngleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees)
{
	ijkTrigSinCos_deg_flt(angle_degrees * flt_half, q_out, q_out + 3);
	return ijkVecMul3fvs(q_out, axis_unit, *q_out);
}

ijk_inl floatv ijkQuatScaleQfv(float4 q_out, f32 const scale_unif)
{
	q_out[0] = q_out[1] = q_out[2] = flt_zero;
	q_out[3] = ijkSqrt_flt(scale_unif);
	return q_out;
}

ijk_inl floatv ijkQuatRotateScaleQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{
	f32 const len = ijkSqrt_flt(scale_unif);
	ijkQuatRotateQfv(q_out, order, rotateDegXYZ);
	return ijkQuatMulQfvs(q_out, q_out, len);
}

ijk_inl floatv ijkQuatAxisAngleScaleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{
	f32 const len = ijkSqrt_flt(scale_unif);
	ijkTrigSinCos_deg_flt(angle_degrees * flt_half, q_out, q_out + 3);
	q_out[3] *= len;
	return ijkVecMul3fvs(q_out, axis_unit, *q_out * len);
}

ijk_inl floatkv ijkQuatGetRotateQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatGetRotateXYZQfv(q_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkQuatGetRotateYZXQfv(q_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkQuatGetRotateZXYQfv(q_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkQuatGetRotateYXZQfv(q_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkQuatGetRotateXZYQfv(q_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkQuatGetRotateZYXQfv(q_in, rotateDegXYZ_out);
	}
	return q_in;
}

ijk_inl floatkv ijkQuatGetAxisAngleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out)
{
	f32 const s = ijkVecLength3fv(q_in);
	ijkVecDivSafe3fvs(axis_unit_out, q_in, s);
	*angle_degrees_out = flt_two * ijkTrigAtan2_deg_flt(s, q_in[3]);
	return q_in;
}

ijk_inl floatkv ijkQuatGetScaleQfv(float4 const q_in, f32* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQfv(q_in);
	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateScaleQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQfv(q_in);
	return ijkQuatGetRotateQfv(q_in, order, rotateDegXYZ_out);
}

ijk_inl floatkv ijkQuatGetAxisAngleScaleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{
	f32 s = ijkVecLengthSq3fv(q_in);
	*scale_unif_out = ijkSqrt_flt(s + q_in[3] * q_in[3]);
	s = ijkSqrt_flt(s);
	ijkVecDivSafe3fvs(axis_unit_out, q_in, s);
	*angle_degrees_out = flt_two * ijkTrigAtan2_deg_flt(s, q_in[3]);
	return q_in;
}

ijk_inl float3m ijkQuatGetMatQfv3(float3x3 m_out, float4 const q_in)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = flt_two * (xy + zw);
	m_out[0][2] = flt_two * (zx - yw);
	m_out[1][0] = flt_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = flt_two * (yz + xw);
	m_out[2][0] = flt_two * (zx + yw);
	m_out[2][1] = flt_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	return m_out;
}

ijk_inl float3m ijkQuatUnitGetMatQfv3(float3x3 m_out, float4 const q_in)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * flt_two, y2 = y * flt_two, z2 = z * flt_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = flt_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = flt_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = flt_one - (xx2 + yy2);
	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4(float4x4 m_out, float4 const q_in)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = flt_two * (xy + zw);
	m_out[0][2] = flt_two * (zx - yw);
	m_out[1][0] = flt_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = flt_two * (yz + xw);
	m_out[2][0] = flt_two * (zx + yw);
	m_out[2][1] = flt_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	m_out[3][3] = flt_one;
	return m_out;
}

ijk_inl float4m ijkQuatUnitGetMatQfv4(float4x4 m_out, float4 const q_in)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * flt_two, y2 = y * flt_two, z2 = z * flt_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = flt_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = flt_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = flt_one - (xx2 + yy2);
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = flt_zero;
	m_out[3][3] = flt_one;
	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = flt_two * (xy + zw);
	m_out[0][2] = flt_two * (zx - yw);
	m_out[1][0] = flt_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = flt_two * (yz + xw);
	m_out[2][0] = flt_two * (zx + yw);
	m_out[2][1] = flt_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = flt_zero;
	ijkVecCopy4fvw(m_out[3], translate, flt_one);
	return m_out;
}

ijk_inl float4m ijkQuatUnitGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate)
{
	f32 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * flt_two, y2 = y * flt_two, z2 = z * flt_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = flt_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = flt_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = flt_one - (xx2 + yy2);
	m_out[0][3] = m_out[1][3] = m_out[2][3] = flt_zero;
	ijkVecCopy4fvw(m_out[3], translate, flt_one);
	return m_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{
	// v' = q v q*
	//		= (wq + vq)v(wq - vq)
	//		= (wq + vq)(v wq - v vq)
	//		= (wq + vq)(v wq - v x vq + v . vq)
	//		= (wq + vq)(v wq + vq x v + v . vq)
	//		= wq v wq + wq(vq x v) + wq(v . vq) + vq v wq + vq(vq x v) + vq(v . vq)
	//		= wq2 v + wq(vq x v) + wq(v . vq) + (vq x v - vq . v)wq + vq x (vq x v) - vq . (vq x v) + vq(v . vq)
	//		= [wq(v . vq) - (vq . v)wq] + wq2 v + wq(vq x v) + (vq x v)wq + [vq x (vq x v)] - [vq . (vq x v)] + vq(v . vq)
	//	real part and scalar triple product cancel out, while the vector triple product is expanded: 
	//		= wq2 v + wq(vq x v) + (vq x v)wq + vq(vq . v) - v(vq . vq) + vq(v . vq)
	//		= v(wq2 - vq . vq) + 2wq(vq x v) + 2vq(vq . v)
	//		= v(|q|^2 - 2(vq . vq)) + 2wq(vq x v) + 2vq(vq . v)
	//		= v|q|^2 + 2(wq(vq x v) + vq(vq . v) - v(vq . vq))
	//		= v|q|^2 + 2(vq x (wq v) + vq x (vq x v))
	//		= v|q|^2 + 2vq x (wq v + vq x v)
	f32 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3],
		ww = qw * qw - ijkVecLengthSq3fv(q_in), w2 = flt_two * qw, d = flt_two * ijkVecDot3fv(q_in, v_in);	// 9*, 5+-
	float3 const v = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d),	// 5*, 3+-
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d),	// 5*, 3+-
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d),	// 5*, 3+-
	};
	//f32 const lenSq = ijkQuatLengthSqQfv(q_in);	// 4*, 3+
	//float3 const v = {
	//	(qy * vz - qz * vy + qw * vx),	// 3*, 2+-
	//	(qz * vx - qx * vz + qw * vy),	// 3*, 2+-
	//	(qx * vy - qy * vx + qw * vz),	// 3*, 2+-
	//};
	//v_out[0] = vx * lenSq + flt_two * (qy * vz - qz * vy);	// 4*, 2+-
	//v_out[1] = vy * lenSq + flt_two * (qz * vx - qx * vz);	// 4*, 2+-
	//v_out[2] = vz * lenSq + flt_two * (qx * vy - qy * vx);	// 4*, 2+-
	return ijkVecCopy3fv(v_out, v);
}

ijk_inl floatv ijkQuatUnitRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{
	// v' = q v q*
	//		= v + 2vq x (vq x v + wq v)
	f32 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3];
	float3 const v = {
		(qy * vz - qz * vy + qw * vx),	// 3*, 2+-
		(qz * vx - qx * vz + qw * vy),	// 3*, 2+-
		(qx * vy - qy * vx + qw * vz),	// 3*, 2+-
	};
	v_out[0] = vx + flt_two * (qy * vz - qz * vy);	// 3*, 2+-
	v_out[1] = vy + flt_two * (qz * vx - qx * vz);	// 3*, 2+-
	v_out[2] = vz + flt_two * (qx * vy - qy * vx);	// 3*, 2+-
	return v_out;
}

ijk_inl floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{
	// v' /= |q|^2
	//		= v(wq2 - vq . vq) + 2wq(vq x v) + 2vq(vq . v)
	//	|q|^2 = 2wq2 - (wq2 - vq . vq) = 2wq2 - wq2 + vq . vq
	f32 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3],
		ww = qw * qw - ijkVecLengthSq3fv(q_in), w2 = flt_two * qw, d = flt_two * ijkVecDot3fv(q_in, v_in);
	f32 const nrm = flt_one / (w2 * qw - ww);
	float3 const v = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d) * nrm,
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d) * nrm,
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d) * nrm,
	};
	return ijkVecCopy3fv(v_out, v);
}

ijk_inl floatv ijkQuatReflectScaleQfv(float4 q_out, float4 const q_in, float3 const v_in)
{
	// v' = q v q
	//		= (wq + vq)v(wq + vq)
	//		= (wq + vq)(v wq + v vq)
	//		= (wq + vq)(v wq + v x vq - v . vq)
	//		= wq v wq + wq(v x vq) - wq(v . vq) + (vq v)wq + vq(v x vq) - vq(v . vq)
	//		= wq2 v + wq(v x vq) - wq(v . vq) + (vq x v - vq . v)wq + vq x (v x vq) - vq . (v x vq) - vq(v . vq)
	//		= wq2 v + [wq(v x vq) + (vq x v)wq] + [vq x (v x vq)] - [vq . (v x vq)] - vq(v . vq) - wq(v . vq) - (vq . v)wq
	//		= wq2 v + [wq(v x vq) - (v x vq)wq] + [v(vq . vq) - vq(vq . v)] - vq(v . vq) - wq(v . vq) - (vq . v)wq
	//		= wq2 v + v(vq . vq) - vq(vq . v) - vq(v . vq) - wq(v . vq) - (vq . v)wq
	//		= v|q|^2 - 2vq(vq . v) - 2wq(v . vq)
	//		= v|q|^2 - 2(vq . v)q
	f32 const d = flt_two * ijkVecDot3fv(q_in, v_in), lenSq = ijkQuatLengthSqQfv(q_in);
	q_out[0] = v_in[0] * lenSq - d * q_in[0];
	q_out[1] = v_in[1] * lenSq - d * q_in[1];
	q_out[2] = v_in[2] * lenSq - d * q_in[2];
	q_out[3] = -d * q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatUnitReflectQfv(float4 q_out, float4 const q_in, float3 const v_in)
{
	// v' = q v q
	//		= v - 2(vq . v)q
	f32 const d = flt_two * ijkVecDot3fv(q_in, v_in);
	q_out[0] = v_in[0] - d * q_in[0];
	q_out[1] = v_in[1] - d * q_in[1];
	q_out[2] = v_in[2] - d * q_in[2];
	q_out[3] = -d * q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatReflectQfv(float4 q_out, float4 const q_in, float3 const v_in)
{
	// v' = q v q
	//	v' /= |q|^2
	//		= v - 2(vq . v)q / |q|^2
	f32 const d = flt_two * ijkVecDot3fv(q_in, v_in), lenSqInv = d * ijkQuatLengthSqInvQfv(q_in);
	q_out[0] = v_in[0] - lenSqInv * q_in[0];
	q_out[1] = v_in[1] - lenSqInv * q_in[1];
	q_out[2] = v_in[2] - lenSqInv * q_in[2];
	q_out[3] = -lenSqInv * q_in[3];
	return q_out;
}

ijk_inl floatv ijkQuatExpQfv(float4 q_out, float3 const v_in)
{
	// exp(v) = exp(|v|unit(v)) = cos(|v|) + sin(|v|)unit(v)
	f32 const len = ijkVecLength3fv(v_in);
	if (len > flt_zero)
	{
		ijkTrigSinCos_rad_flt(len, q_out, q_out + 3);
		return ijkVecMul3fvs(q_out, q_out, *q_out / len);
	}
	return ijkQuatInitQfv(q_out);
}

ijk_inl floatv ijkQuatLnQfv(float4 q_out, float4 const q_in)
{
	// ln(q) = ln(|q|unit(q))
	//		= ln|q| + ln(w + v)
	//		= ln|q| + ln(cos(|v|) + sin(|v|)unit(v))
	//		= ln|q| + |v|unit(v)
	//		= ln|q| + acos(w/|q|)v/|v|
	f32 lenv = ijkVecLengthSq3fv(q_in);
	if (lenv > flt_zero)
	{
		f32 const lenq = ijkSqrt_flt(lenv + q_in[3] * q_in[3]);
		lenv = ijkTrigAcos_rad_flt(q_in[3] / lenq) * ijkSqrtInv_flt(lenv);
		q_out[3] = ijkTrigLn1p_flt(lenq - flt_one);
		return ijkVecMul3fvs(q_out, q_in, lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = flt_zero;
	q_out[3] = ijkTrigLn1p_flt(q_in[3] - flt_one);
	return q_out;
}

ijk_inl floatv ijkQuatPowQfv(float4 q_out, float4 const q_in, f32 const u)
{
	// q^u = |q|^u unit(q)^u
	//		= |q|^u (cos(a) + sin(a)n)^u
	//		= |q|^u (cos(ua) + sin(ua)n)
	f32 lenv = ijkVecLengthSq3fv(q_in), a, s;
	if (lenv > flt_zero)
	{
		f32 const lenq = ijkTrigPow_flt((lenv + q_in[3] * q_in[3]), u * flt_half);
		lenv = ijkSqrtInv_flt(lenv);
		a = u * ijkTrigAtan2_deg_flt(lenv, q_in[3]);
		ijkTrigSinCos_deg_flt(a, &s, q_out + 3);
		q_out[3] *= lenq;
		return ijkVecMul3fvs(q_out, q_in, lenq / lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = flt_zero;
	q_out[3] = ijkTrigPow_flt(q_in[3], u);
	return q_out;
}

ijk_inl floatv ijkQuatSqrtQfv(float4 q_out, float4 const q_in)
{
	f32 lenv = ijkVecLengthSq3fv(q_in);
	if (lenv > flt_zero)
	{
		f32 const lenq = ijkSqrt_flt(lenv + q_in[3] * q_in[3]);
		f32 const w = q_in[3];
		q_out[3] = ijkSqrt_flt(flt_half * (lenq + w));
		lenv = ijkSqrt_flt(flt_half * (lenq - w) / lenv);
		return ijkVecMul3fvs(q_out, q_in, lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = flt_zero;
	q_out[3] = ijkSqrt_flt(q_in[3]);
	return q_out;
}

ijk_inl floatv ijkQuatLerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{
	return ijkVecLerp4fv(q_out, q0, q1, u);
}

ijk_inl floatv ijkQuatNlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{
	ijkQuatLerpQfv(q_out, q0, q1, u);
	return ijkQuatNormalizeQfv(q_out, q_out);
}

ijk_inl floatv ijkQuatSlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{
	// similar to vector slerp except we have to worry about double-coverage
	float4 copy;
	floatkv q1b = q1;
	f32 dot = ijkVecDot4fv(q0, q1);
	if (dot < flt_zero)
	{
		dot = -dot;
		q1b = ijkQuatNegateQfv(copy, q1b);
	}
	if (dot < flt_one)
	{
		float4 tmp;
		f32 const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkQuatAddQfv(q_out, ijkQuatMulQfvs(q_out, q0, s0), ijkQuatMulQfvs(tmp, q1b, s1));
	}
	return ijkQuatNlerpQfv(q_out, q0, q1b, u);
}

ijk_inl floatv ijkQuatDerivQfv(float4 q1_out, float4 const q_in, float3 const angularVelocity)
{
	// using quaternion as exponential of vector: 
	//	q' = d(e^v)/dt = dv/dt e^v
	//		v = (angle/2)axis
	//		dv/dt = (angular velocity)/2 = w/2
	//	q' = wq/2
	// using limit of difference quotient: 
	//	q' = lim[dt->0](q[t+dt] - q[t])/dt
	//		= lim[dt->0]((cos(|w|dt/2) + sin(|w|dt/2)w/|w|)q - q)/dt
	//		= lim[dt->0](cos(|w|dt/2) - 1 + sin(|w|dt/2)w/|w|)q/dt
	//		= lim[dt->0](cos(|w|dt/2) - 1)/dt + lim[dt->0]sin(|w|dt/2)wq/(|w|dt)
	//			a = |w|/2
	//		= lim[dt->0](cos(a dt) - 1)/dt + (wq/|w|)lim[dt->0]sin(a dt)/dt -> squeeze theorem: lim[x->0]sin(kx)/x = k
	//		= lim[dt->0](cos(a dt) - 1)(cos(a dt) + 1)/(cos(a dt) + 1)dt + (wq/|w|)a
	//		= lim[dt->0](cos^2(a dt) - 1)/(cos(a dt) + 1)dt + (wq/|w|)|w|/2
	//		= lim[dt->0](-sin^2(a dt)/dt)/(cos(a dt) + 1) + wq/2
	//		= -lim[dt->0](sin(a dt)sin(a dt)/dt)/(cos(a dt) + 1) + wq/2
	//		= -lim[dt->0]sin(a dt) lim[dt->0](sin(a dt)/dt)/lim[dt->0](cos(a dt) + 1) + wq/2
	//		= -sin(0)a/(cos(0) + 1) + wq/2
	//		= 0/2 + wq/2
	//		= wq/2 -> [half: 3x; wq: 12x8+; total = 15x8+ = 23]
	float3 const hw = {
		(flt_half * angularVelocity[0]), (flt_half * angularVelocity[1]), (flt_half * angularVelocity[2])
	};
	return ijkQuatMulVecQfv3q(q1_out, hw, q_in);
}

ijk_inl floatv ijkQuatDeriv2Qfv(float4 q2_out, float4 const q_in, float3 const angularVelocity, float3 const angularAcceleration)
{
	// q" = d(q')/dt = d(w q/2)/dt
	//		= (dw/dt)q/2 + w(dq/dt)/2
	//		= aq/2 + w(wq/2)/2
	//		= aq/2 - q|w|^2/4
	//		= (a/2 - |w|^2/4)q	-> [lenSq: 7; sub&mul: 7; mul: 28; total = 42]
	f32 const angularSpeedSq = ijkVecLengthSq3fv(angularVelocity);
	float4 const q_lh = {
		(flt_half * angularAcceleration[0]), (flt_half * angularAcceleration[1]), (flt_half * angularAcceleration[2]), (-flt_quarter * angularSpeedSq)
	};
	return ijkQuatMulQfv(q2_out, q_lh, q_in);
}

ijk_inl floatv ijkQuatEncodeTranslateQfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{
	// q' = tq/2
	//		= t(w + v)/2
	//		= (tw + tv)/2
	//		= ([tw + t x v] - [t . v])/2
	return ijkQuatDerivQfv(qt_out, q_encode, translate_in);
}

ijk_inl floatv ijkQuatEncodeTranslateX2Qfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{
	// q' = tq
	return ijkQuatMulVecQfv3q(qt_out, translate_in, q_encode);
}

ijk_inl floatv ijkQuatDecodeTranslateQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{
	// q' = tq/2
	// t = 2q'q*
	//		= 2(w' + v')(w - v)
	//		= 2(w' w - w' v + v' w - v' v)
	//		= 2(w' w - w' v + v' w - v' x v + v' . v)
	//		= 2(w' w + v . v' - w' v + v' w + v x v')
	//		= 2(-[t . v]w/2 + [v . [tw + t x v]]/2 + [t . v]v/2 + [tw + t x v]w/2 + v x [tw + t x v]/2)
	//		= -[t . v]w + [v . t]w + [v . [t x v]] + [t . v]v + tww + [t x v]w + [v x t]w + v x [t x v]
	//		= [v . t - t . v]w + [t x v - t x v]w + tw2 + [t . v]v + t[v . v] - v[v . t]
	//		= tw2 + t[v . v] + [t . v - v . t]v
	//		= t|q|^2 = t (unit encoding quaternion; proves that real is zero)
	// t = 2q'q*
	//		= 2([w' w + v . v'] - w' v + v' w + v x v')
	//		= 2([0] + [v' w - w' v + v x v'])
	f32 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = flt_two * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = flt_two * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = flt_two * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateD2Qfvs(float3 translate_out, float4 const qt_in, float4 const q_decode, f32 const s)
{
	// q' = tq/2
	// s t/2 = s q'q*
	f32 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateD2Qfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{
	// q' = tq/2
	// t/2 = q'q*
	f32 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateRemScaleQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{
	// q' = tq/2
	// t = 2q'q^-1 = 2q'q*/|q|^2
	f32 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3],
		s = flt_two / ijkQuatLengthSqQfv(q_decode);
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateRemScaleD2Qfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{
	// q' = tq/2
	// t/2 = q'q^-1 = q'q*/|q|^2
	f32 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3],
		s = flt_one / ijkQuatLengthSqQfv(q_decode);
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl float4m ijkDualQuatInitDQfm(float2x4 dq_out)
{
	ijkQuatInitQfv(dq_out[0]);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatInitDualReDQfm(float2x4 dq_out, float4 const re, float4 const dual)
{
	ijkQuatCopyQfv(dq_out[0], re);
	ijkQuatCopyQfv(dq_out[1], dual);
	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm3(float2x4 dq_out, float3x3 const m_in)
{
	ijkQuatInitMatQfv3(dq_out[0], m_in);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm4(float2x4 dq_out, float4x4 const m_in)
{
	ijkQuatEncodeTranslateQfv(dq_out[1], m_in[3], ijkQuatInitMatQfv4(dq_out[0], m_in));
	return dq_out;
}

ijk_inl float4m ijkDualQuatCopyDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	ijkQuatCopyQfv(dq_out[0], dq_in[0]);
	ijkQuatCopyQfv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	ijkQuatNegateQfv(dq_out[0], dq_in[0]);
	ijkQuatNegateQfv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	ijkQuatConjugateQfv(dq_out[0], dq_in[0]);
	ijkQuatConjugateQfv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	ijkQuatCopyQfv(dq_out[0], dq_in[0]);
	ijkQuatNegateQfv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	ijkQuatConjugateQfv(dq_out[0], dq_in[0]);
	ijkQuatNegateConjugateQfv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatAddDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{
	ijkQuatAddQfv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQfv(dq_out[1], dq_lh[1], dq_rh[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatSubDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{
	ijkQuatSubQfv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatSubQfv(dq_out[1], dq_lh[1], dq_rh[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{
	ijkQuatMulQfvs(dq_out[0], dq_lh[0], s_rh);
	ijkQuatMulQfvs(dq_out[1], dq_lh[1], s_rh);
	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	return ijkDualQuatMulDQfms(dq_out, dq_lh, s);
}

ijk_inl float4m ijkDualQuatDivSafeDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	return ijkDualQuatMulDQfms(dq_out, dq_lh, s);
}

ijk_inl f32 ijkDualQuatLengthSqDQfm(float2x4 const dq_in)
{
	// length is that of real part only
	return ijkQuatLengthSqQfv(dq_in[0]);
}

ijk_inl f32 ijkDualQuatLengthDQfm(float2x4 const dq_in)
{
	return ijkQuatLengthQfv(dq_in[0]);
}

ijk_inl f32 ijkDualQuatLengthSqInvDQfm(float2x4 const dq_in)
{
	return ijkQuatLengthSqInvQfv(dq_in[0]);
}

ijk_inl f32 ijkDualQuatLengthInvDQfm(float2x4 const dq_in)
{
	return ijkQuatLengthInvQfv(dq_in[0]);
}

ijk_inl f32 ijkDualQuatLengthSqInvSafeDQfm(float2x4 const dq_in)
{
	return ijkQuatLengthSqInvSafeQfv(dq_in[0]);
}

ijk_inl f32 ijkDualQuatLengthInvSafeDQfm(float2x4 const dq_in)
{
	return ijkQuatLengthInvSafeQfv(dq_in[0]);
}

ijk_inl float4m ijkDualQuatNormalizeDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	// divide both parts by real part's length
	f32 const lenInv = ijkQuatLengthInvQfv(dq_out[0]);
	ijkQuatMulQfvs(dq_out[0], dq_out[0], lenInv);
	ijkQuatMulQfvs(dq_out[1], dq_out[1], lenInv);
	return dq_out;
}

ijk_inl float4m ijkDualQuatNormalizeSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	f32 const lenInv = ijkQuatLengthInvSafeQfv(dq_out[0]);
	ijkQuatMulQfvs(dq_out[0], dq_out[0], lenInv);
	ijkQuatMulQfvs(dq_out[1], dq_out[1], lenInv);
	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	// conjugate of each part divided by real part's length
	f32 const lenInv = ijkQuatLengthInvQfv(dq_out[0]);
	ijkQuatConjugateMulQfvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatConjugateMulQfvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{
	f32 const lenInv = ijkQuatLengthInvSafeQfv(dq_out[0]);
	ijkQuatConjugateMulQfvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatConjugateMulQfvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3(float2x4 dq_out, float2x4 const dq_lh, float3 const v_rh)
{
	// dq' = (r + Ed)v
	//		= rv + Edv
	ijkQuatMulVecQfv3(dq_out[0], dq_lh[0], v_rh);
	ijkQuatMulVecQfv3(dq_out[1], dq_lh[1], v_rh);
	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3q(float2x4 dq_out, float3 const v_lh, float2x4 const dq_rh)
{
	// dq' = v(r + Ed)
	//		= vr + Evd
	ijkQuatMulVecQfv3q(dq_out[0], v_lh, dq_rh[0]);
	ijkQuatMulVecQfv3q(dq_out[1], v_lh, dq_rh[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{
	// dq' = (r_lh + E d_lh)(r_rh + E d_rh)
	//		= r_lh r_rh + E r_lh d_rh + E d_lh r_rh + EE d_lh d_rh -> EE = 0
	//		= r_lh r_rh + E(r_lh d_rh + d_lh r_rh)
	float4 tmp_lh, tmp_rh;
	ijkQuatMulQfv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQfv(dq_out[1], ijkQuatMulQfv(tmp_lh, dq_lh[0], dq_rh[1]), ijkQuatMulQfv(tmp_rh, dq_lh[1], dq_rh[0]));
	return dq_out;
}

ijk_inl float4m ijkDualQuatMulScaleDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{
	// dq' = (r_lh + E d_lh)(r_rh + |r_lh|^2 E d_rh)
	//		= r_lh r_rh + |r_lh|^2 E r_lh d_rh + E d_lh r_rh + |r_lh|^2 EE d_lh d_rh -> EE = 0
	//		= r_lh r_rh + E(|r_lh|^2 r_lh d_rh + d_lh r_rh)
	float4 tmp_lh, tmp_rh;
	f32 const lenSq = ijkQuatLengthSqQfv(dq_lh[0]);
	ijkQuatMulQfv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQfv(dq_out[1], ijkQuatMulQfvs(tmp_lh, ijkQuatMulQfv(tmp_lh, dq_lh[0], dq_rh[1]), lenSq), ijkQuatMulQfv(tmp_rh, dq_lh[1], dq_rh[0]));
	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{
	float2x4 dq_rh_inv;
	return ijkDualQuatMulDQfm(dq_out, dq_lh, ijkDualQuatInverseDQfm(dq_rh_inv, dq_rh));
}

ijk_inl float4m ijkDualQuatRotateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{
	ijkQuatRotateQfv(dq_out[0], order, rotateDegXYZ);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees)
{
	ijkQuatAxisAngleQfv(dq_out[0], axis_unit, angle_degrees);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleDQfm(float2x4 dq_out, f32 const scale_unif)
{
	ijkQuatScaleQfv(dq_out[0], scale_unif);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{
	ijkQuatRotateScaleQfv(dq_out[0], order, rotateDegXYZ, scale_unif);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{
	ijkQuatAxisAngleScaleQfv(dq_out[0], axis_unit, angle_degrees, scale_unif);
	ijkQuatInitZeroQfv(dq_out[1]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatTranslateDQfm(float2x4 dq_out, float3 const translate)
{
	f32 const s = flt_half;
	ijkQuatInitQfv(dq_out[0]);
	ijkQuatInitElemsQfv(dq_out[1], (translate[0] * s), (translate[1] * s), (translate[2] * s), flt_zero);
	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate)
{
	ijkQuatRotateQfv(dq_out[0], order, rotateDegXYZ);
	ijkQuatEncodeTranslateQfv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate)
{
	ijkQuatAxisAngleQfv(dq_out[0], axis_unit, angle_degrees);
	ijkQuatEncodeTranslateQfv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleTranslateDQfm(float2x4 dq_out, f32 const scale_unif, float3 const translate)
{
	f32 s = flt_half;
	ijkQuatScaleQfv(dq_out[0], scale_unif);
	s *= dq_out[0][3];
	ijkQuatInitElemsQfv(dq_out[1], (translate[0] * s), (translate[1] * s), (translate[2] * s), flt_zero);
	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif, float3 const translate)
{
	ijkQuatRotateScaleQfv(dq_out[0], order, rotateDegXYZ, scale_unif);
	ijkQuatEncodeTranslateQfv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif, float3 const translate)
{
	ijkQuatAxisAngleScaleQfv(dq_out[0], axis_unit, angle_degrees, scale_unif);
	ijkQuatEncodeTranslateQfv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl float4km ijkDualQuatGetRotateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{
	ijkQuatGetRotateQfv(dq_in[0], order, rotateDegXYZ_out);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out)
{
	ijkQuatGetAxisAngleQfv(dq_in[0], axis_unit_out, angle_degrees_out);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out)
{
	ijkQuatGetScaleQfv(dq_in[0], scale_unif_out);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{
	ijkQuatGetRotateScaleQfv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{
	ijkQuatGetAxisAngleScaleQfv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetTranslateDQfm(float2x4 const dq_in, float3 translate_out)
{
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{
	ijkQuatGetRotateQfv(dq_in[0], order, rotateDegXYZ_out);
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{
	ijkQuatGetAxisAngleQfv(dq_in[0], axis_unit_out, angle_degrees_out);
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleTranslateDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetScaleQfv(dq_in[0], scale_unif_out);
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetRotateScaleQfv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetAxisAngleScaleQfv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetTranslateRemScaleDQfm(float2x4 const dq_in, float3 translate_out)
{
	ijkQuatDecodeTranslateRemScaleQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateTranslateRemScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{
	ijkQuatGetRotateQfv(dq_in[0], order, rotateDegXYZ_out);
	ijkQuatDecodeTranslateRemScaleQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleTranslateRemScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{
	ijkQuatGetAxisAngleQfv(dq_in[0], axis_unit_out, angle_degrees_out);
	ijkQuatDecodeTranslateRemScaleQfv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleTranslateRemScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetScaleQfv(dq_in[0], scale_unif_out);
	ijkQuatDecodeTranslateD2Qfvs(translate_out, dq_in[1], dq_in[0], (flt_two / *scale_unif_out));
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleTranslateRemScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetRotateScaleQfv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	ijkQuatDecodeTranslateD2Qfvs(translate_out, dq_in[1], dq_in[0], (flt_two / *scale_unif_out));
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out)
{
	ijkQuatGetAxisAngleScaleQfv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	ijkQuatDecodeTranslateD2Qfvs(translate_out, dq_in[1], dq_in[0], (flt_two / *scale_unif_out));
	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScrewParamsDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out, float3 momentArm_out, f32* const screwDisplace_out)
{
	floatkv r = dq_in[0], d = dq_in[1];
	f32 distance;
	f32 const lenSq = ijkQuatLengthSqQfv(r), lenSqInv2 = flt_two / lenSq;
	f32 const c = r[3], s = ijkVecLength3fv(r);
	f32 const angle = ijkTrigAtan2_deg_flt(s, c), cot = c / s;

	translate_out[0] = lenSqInv2 * (d[0] * r[3] + d[2] * r[1] - d[1] * r[2] - d[3] * r[0]);
	translate_out[1] = lenSqInv2 * (d[1] * r[3] + d[0] * r[2] - d[2] * r[0] - d[3] * r[1]);
	translate_out[2] = lenSqInv2 * (d[2] * r[3] + d[1] * r[0] - d[0] * r[1] - d[3] * r[2]);

	axis_unit_out[0] = r[0] * s;
	axis_unit_out[1] = r[1] * s;
	axis_unit_out[2] = r[2] * s;

	*angle_degrees_out = flt_two * angle;
	*screwDisplace_out = distance = ijkVecDot3fv(translate_out, axis_unit_out);

	// moment = 1/2 * ( cross(translate, axis) + (translate - distance*axis)*cot(halfAngle) )
	momentArm_out[0] = flt_half * (translate_out[1] * axis_unit_out[2] - translate_out[2] * axis_unit_out[1] + cot * (translate_out[0] - distance * axis_unit_out[0]));
	momentArm_out[1] = flt_half * (translate_out[2] * axis_unit_out[0] - translate_out[0] * axis_unit_out[2] + cot * (translate_out[1] - distance * axis_unit_out[1]));
	momentArm_out[2] = flt_half * (translate_out[0] * axis_unit_out[1] - translate_out[1] * axis_unit_out[0] + cot * (translate_out[2] - distance * axis_unit_out[2]));
	
	return dq_in;
}

ijk_inl float3m ijkDualQuatGetMatDQfm3(float3x3 m_out, float2x4 const dq_in)
{
	return ijkQuatGetMatQfv3(m_out, dq_in[0]);
}

ijk_inl float3m ijkDualQuatUnitGetMatDQfm3(float3x3 m_out, float2x4 const dq_in)
{
	return ijkQuatUnitGetMatQfv3(m_out, dq_in[0]);
}

ijk_inl float3m ijkDualQuatGetMatTranslateDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in)
{
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatGetMatQfv3(m_out, dq_in[0]);
}

ijk_inl float3m ijkDualQuatUnitGetMatTranslateDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in)
{
	ijkQuatDecodeTranslateQfv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatUnitGetMatQfv3(m_out, dq_in[0]);
}

ijk_inl float3m ijkDualQuatGetMatTranslateRemScaleDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in)
{
	ijkQuatDecodeTranslateRemScaleQfv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatGetMatQfv3(m_out, dq_in[0]);
}

ijk_inl float4m ijkDualQuatGetMatDQfm4(float4x4 m_out, float2x4 const dq_in)
{
	float3 translate;
	return ijkQuatGetMatQfv4t(m_out, dq_in[0], ijkQuatDecodeTranslateQfv(translate, dq_in[1], dq_in[0]));
}

ijk_inl float4m ijkDualQuatUnitGetMatDQfm4(float4x4 m_out, float2x4 const dq_in)
{
	float3 translate;
	return ijkQuatUnitGetMatQfv4t(m_out, dq_in[0], ijkQuatDecodeTranslateQfv(translate, dq_in[1], dq_in[0]));
}

ijk_inl float4m ijkDualQuatGetMatTranslateRemScaleDQfm4(float4x4 m_out, float2x4 const dq_in)
{
	float3 translate;
	return ijkQuatGetMatQfv4t(m_out, dq_in[0], ijkQuatDecodeTranslateRemScaleQfv(translate, dq_in[1], dq_in[0]));
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatUnitTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl float4m ijkDualQuatLerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{
	ijkQuatLerpQfv(dq_out[0], dq0[0], dq1[0], u);
	ijkQuatLerpQfv(dq_out[1], dq0[1], dq1[1], u);
	return dq_out;
}

ijk_inl float4m ijkDualQuatNlerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{
	ijkDualQuatLerpDQfm(dq_out, dq0, dq1, u);
	return ijkDualQuatNormalizeDQfm(dq_out, dq_out);
}

ijk_inl float4m ijkDualQuatSclerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{
	float2x4 copy;
	float4km dq1b = dq1;
	floatkv r0 = dq0[0], r1 = dq1[0], d0 = dq0[1], d1 = dq1[1];
	f32 dot = ijkVecDot4fv(r0, r1);
	if (dot < flt_zero)
	{
		dot = -dot;
		r1 = ijkVecNegate4fv(copy[0], r1);
		d1 = ijkVecNegate4fv(copy[1], d1);
	}
	if (dot < flt_one)
	{
		float2x4 tmp;
		f32 const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkDualQuatAddDQfm(dq_out, ijkDualQuatMulDQfms(dq_out, dq0, s0), ijkDualQuatMulDQfms(tmp, dq1b, s1));
	}
	return ijkDualQuatNlerpDQfm(dq_out, dq0, dq1b, u);
}

ijk_inl float4m ijkDualQuatDerivDQfm(float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const angularVelocity)
{
	// Q' = d(R + E D)/dt
	//		= dR/dt + E dD/dt
	//		= R' + E d(TR/2)/dt
	//		= R' + E(dT/dt R + T dR/dt)/2
	//		= R' + E(VR + TR')/2 -> definition
	//			R' = WR/2 -> 23
	//		= R' + E(VR/2 + DR^-1 WR/2)
	//		= R' + E(VR/2 + D(R^-1 W R)/2)	-> [deriv x2: 46; half: 3; lenSqInv: 8; rotate: 24; vq = 20; total = 101]
	//		= R' + E(V/2 - D(R*W*/2)/|R|^2)R
	//		= R' + E(V/2 - (D R'*)/|R|^2)R	-> [deriv: 23; mul/mulConj x2: 56; mulLenSqInv: 12; half&sub: 6; total = 97]

	floatkv r = dq_in[0], d = dq_in[1], dr_dt = ijkQuatDerivQfv(dq1_out[0], r, angularVelocity);
	floatv dd_dt = dq1_out[1];
	f32 const lenSqInv = ijkQuatLengthSqInvQfv(r);
	dd_dt[0] = linearVelocity[0] * flt_half - lenSqInv * (d[0] * dr_dt[3] - d[3] * dr_dt[0] + d[2] * dr_dt[1] - d[1] * dr_dt[2]);
	dd_dt[1] = linearVelocity[1] * flt_half - lenSqInv * (d[1] * dr_dt[3] - d[3] * dr_dt[1] + d[0] * dr_dt[2] - d[2] * dr_dt[0]);
	dd_dt[2] = linearVelocity[2] * flt_half - lenSqInv * (d[2] * dr_dt[3] - d[3] * dr_dt[2] + d[1] * dr_dt[0] - d[0] * dr_dt[1]);
	dd_dt[3] = -lenSqInv * ijkVecDot4fv(d, dr_dt);
	ijkQuatMulQfv(dd_dt, dd_dt, r);
	return dq1_out;
}

ijk_inl float4m ijkDualQuatDeriv2DQfm(float2x4 dq2_out, float2x4 const dq_in, float3 const linearVelocity, float3 const linearAcceleration, float3 const angularVelocity, float3 const angularAcceleration)
{
	// Q" = d(Q')/dt
	//		= d(R')/dt + E d(D')/dt
	//		= R" + E d(VR + TR')/2)/dt
	//		= R" + E(d(VR)/dt + d(TR')/dt)/2
	//		= R" + E(dV/dt R + V dR/dt + dT/dt R' + T dR'/dt)/2
	//		= R" + E(AR + VR' + VR' + TR")/2
	//		= R" + E(AR + 2VR' + TR")/2 -> definition
	//			R' = WR/2, R" = (W'/2 - |W|^2/4)R -> 23, 42
	//		= (W'/2 - |W|^2/4)R + E(AR + 2VWR/2 + 2DR^-1(W'/2 - |W|^2/4)R)/2
	//		= (W'/2 - |W/2|^2)R + E((A/2 + V(W/2))R + DR^-1(W'/2 - |W/2|^2)R/|R|^2)
	//		= R" + E((A/2 + V(W/2))R + (T/2)R")
	//		= R" + E((A/2 + V x (W/2) - V.(W/2))R + (T/2)R")
	float3 const hw = {
		(flt_half * angularVelocity[0]), (flt_half * angularVelocity[1]), (flt_half * angularVelocity[2])
	};
	f32 const wLenSq = ijkVecLengthSq3fv(hw);
	floatkv r = dq_in[0], d = dq_in[1];
	floatv d2d_dt2 = dq2_out[1], d2r_dt2 = ijkQuatInitElemsQfv(dq2_out[0],
		(flt_half * angularAcceleration[0]), (flt_half * angularAcceleration[1]), (flt_half * angularAcceleration[2]), -wLenSq);
	float4 ht, hdiff = {
		(flt_half * linearAcceleration[0] + linearVelocity[1] * hw[2] - linearVelocity[2] * hw[1]),
		(flt_half * linearAcceleration[1] + linearVelocity[2] * hw[0] - linearVelocity[0] * hw[2]),
		(flt_half * linearAcceleration[2] + linearVelocity[0] * hw[1] - linearVelocity[1] * hw[0]),
		(-ijkVecDot3fv(linearVelocity, hw))
	};
	ijkQuatDecodeTranslateD2Qfv(ht, d, r);
	ijkQuatMulQfv(d2r_dt2, d2r_dt2, r);
	ijkQuatAddQfv(d2d_dt2, ijkQuatMulQfv(hdiff, hdiff, r), ijkQuatMulQfv(ht, ht, d2r_dt2));
	return dq2_out;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_FLOAT_INL_
#endif	// _IJK_QUATERNION_FLOAT_H_