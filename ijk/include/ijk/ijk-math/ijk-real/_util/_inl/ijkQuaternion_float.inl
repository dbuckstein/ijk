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
	q_out[3] = q_in[3];
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

	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4(float4x4 m_out, float4 const q_in)
{

	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate)
{

	return m_out;
}

ijk_inl floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectScaleVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatExpQfv(float4 q_out, float3 const v_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatLnQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatLerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{

	return q_out;
}

ijk_inl floatv ijkQuatNlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{

	return q_out;
}

ijk_inl floatv ijkQuatSlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{

	return q_out;
}

ijk_inl floatv ijkQuatDerivQfv(float4 q1_out, float4 const q_in, float3 const angularVelocity)
{

	return q1_out;
}

ijk_inl floatv ijkQuatDeriv2Qfv(float4 q2_out, float4 q1_out, float4 const q_in, float3 const angularVelocity, float3 const angularAcceleration)
{

	return q2_out;
}

ijk_inl floatv ijkQuatEncodeTranslateQfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{

	return qt_out;
}

ijk_inl floatv ijkQuatEncodeTranslateRemScaleQfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{

	return qt_out;
}

ijk_inl floatv ijkQuatDecodeTranslateQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{

	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateRemScaleQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{

	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl float4m ijkDualQuatInitDQfm(float2x4 dq_out)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitDualReDQfm(float2x4 dq_out, float4 const dual, float4 const re)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm3(float2x4 dq_out, float3x3 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm4(float2x4 dq_out, float4x4 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatCopyDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAddDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSubDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivSafeDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl f32 ijkDualQuatLengthSqDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvSafeDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvSafeDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl float4m ijkDualQuatNormalizeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNormalizeSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3(float2x4 dq_out, float2x4 const dq_lh, float3 const q_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3q(float2x4 dq_out, float3 const v_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulScaleDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleDQfm(float2x4 dq_out, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatTranslateDQfm(float2x4 dq_out, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleTranslateDQfm(float2x4 dq_out, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4km ijkDualQuatGetRotateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetTranslateDQfm(float2x4 const dq_in, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleTranslateDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScrewParamsDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out, float3 momentArm_out, f32* const screwDisplace_out)
{

	return dq_in;
}

ijk_inl float3m ijkDualQuatGetMatDQfm3(float3x3 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl float4m ijkDualQuatGetMatDQfm4(float4x4 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfm4(float4 v_out, float2x4 const dq_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfm4(float4 v_out, float2x4 const dq_in, float4 const v_in)
{

	return v_out;
}

ijk_inl float4m ijkDualQuatLerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNlerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSclerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDerivDQfm(float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const angularVelocity)
{

	return dq1_out;
}

ijk_inl float4m ijkDualQuatDeriv2DQfm(float2x4 dq2_out, float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const linearAcceleration, float3 const angularVelocity, float3 const angularAcceleration)
{

	return dq2_out;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_FLOAT_INL_
#endif	// _IJK_QUATERNION_FLOAT_H_