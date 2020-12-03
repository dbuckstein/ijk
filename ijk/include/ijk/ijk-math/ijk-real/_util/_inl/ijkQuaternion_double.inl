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

	ijkQuaternion_double.inl
	Inline definitions for double quaternion types.
*/

#ifdef _IJK_QUATERNION_DOUBLE_H_
#ifndef _IJK_QUATERNION_DOUBLE_INL_
#define _IJK_QUATERNION_DOUBLE_INL_


//-----------------------------------------------------------------------------

ijk_inl doublev ijkQuatPdv(double4 q_out)
{
	return q_out;
}

ijk_inl double4m ijkDualQuatPdm(double2x4 dq_out)
{
	return dq_out;
}


//-----------------------------------------------------------------------------

ijk_inl doublev ijkQuatInitQdv(double4 q_out)
{
	q_out[0] = q_out[1] = q_out[2] = dbl_zero;
	q_out[3] = dbl_one;
	return q_out;
}

ijk_inl doublev ijkQuatInitZeroQdv(double4 q_out)
{
	q_out[0] = q_out[1] = q_out[2] = q_out[3] = dbl_zero;
	return q_out;
}

ijk_inl doublev ijkQuatInitElemsQdv(double4 q_out, f64 const x, f64 const y, f64 const z, f64 const w)
{
	q_out[0] = x;
	q_out[1] = y;
	q_out[2] = z;
	q_out[3] = w;
	return q_out;
}

ijk_inl doublev ijkQuatInitVecReQdv(double4 q_out, double3 const vec, f64 const re)
{
	q_out[0] = vec[0];
	q_out[1] = vec[1];
	q_out[2] = vec[2];
	q_out[3] = re;
	return q_out;
}

ijk_inl doublev ijkQuatInitVecProductQdv(double4 q_out, double3 const v_lh, double3 const v_rh)
{
	q_out[3] = -ijkVecDot3dv(v_lh, v_rh);
	return ijkVecCross3dv(q_out, v_lh, v_rh);
}

ijk_inl doublev ijkQuatInitVecProductSqrtQdv(double4 q_out, double3 const v_lh, double3 const v_rh)
{
	double3 const hv = {
		dbl_half * (v_lh[0] + v_rh[0]),
		dbl_half * (v_lh[1] + v_rh[1]),
		dbl_half * (v_lh[2] + v_rh[2]),
	};
	return ijkQuatInitVecProductQdv(q_out, v_lh, hv);
}

ijk_inl doublev ijkQuatInitVecProductSqrtUnitQdv(double4 q_out, double3 const v_lh, double3 const v_rh)
{
	double3 hv = {
		dbl_half * (v_lh[0] + v_rh[0]),
		dbl_half * (v_lh[1] + v_rh[1]),
		dbl_half * (v_lh[2] + v_rh[2]),
	};
	return ijkQuatInitVecProductQdv(q_out, v_lh, ijkVecNormalize3dv(hv, hv));
}

ijk_inl doublev ijkQuatInitMatQdv3(double4 q_out, double3x3 const m_in)
{
	f64 t, w, x, y, z;
	f64 diag = (m_in[0][0] + m_in[1][1] + m_in[2][2]);

	// scale is the sixth root of the determinant
	// alternatively, since it is a uniform scale, each column's squared 
	//	length gives same scale value
	f64 const s2 = ijkVecLength3dv(*m_in);
	if (diag > dbl_zero)
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
		w = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / w;
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
		x = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / x;
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
		y = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / y;
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
		z = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / z;
		w = t * (m_in[0][1] - m_in[1][0]);
		x = t * (m_in[2][0] + m_in[0][2]);
		y = t * (m_in[1][2] + m_in[2][1]);
	}
	return ijkQuatInitElemsQdv(q_out, x, y, z, w);
}

ijk_inl doublev ijkQuatInitMatQdv4(double4 q_out, double4x4 const m_in)
{
	f64 t, w, x, y, z;
	f64 diag = (m_in[0][0] + m_in[1][1] + m_in[2][2]);
	f64 const s2 = ijkVecLength3dv(*m_in);
	if (diag > dbl_zero)
	{
		diag += s2;
		w = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / w;
		x = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[0][1] - m_in[1][0]);
	}
	else if (m_in[0][0] > m_in[1][1] && m_in[0][0] > m_in[2][2])
	{
		diag = s2 + m_in[0][0] - m_in[1][1] - m_in[2][2];
		x = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / x;
		w = t * (m_in[1][2] - m_in[2][1]);
		y = t * (m_in[0][1] + m_in[1][0]);
		z = t * (m_in[2][0] + m_in[0][2]);
	}
	else if (m_in[1][1] > m_in[2][2]) // && m_in[1][1] > m_in[0][0]
	{
		diag = s2 - m_in[0][0] + m_in[1][1] - m_in[2][2];
		y = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / y;
		w = t * (m_in[2][0] - m_in[0][2]);
		z = t * (m_in[1][2] + m_in[2][1]);
		x = t * (m_in[0][1] + m_in[1][0]);
	}
	else // if (m_in[2][2] > m_in[0][0] && m_in[2][2] > m_in[1][1])
	{
		diag = s2 - m_in[0][0] - m_in[1][1] + m_in[2][2];
		z = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / z;
		w = t * (m_in[0][1] - m_in[1][0]);
		x = t * (m_in[2][0] + m_in[0][2]);
		y = t * (m_in[1][2] + m_in[2][1]);
	}
	return ijkQuatInitElemsQdv(q_out, x, y, z, w);
}

ijk_inl doublev ijkQuatCopyQdv(double4 q_out, double4 const q_in)
{
	q_out[0] = q_in[0];
	q_out[1] = q_in[1];
	q_out[2] = q_in[2];
	q_out[3] = q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatNegateQdv(double4 q_out, double4 const q_in)
{
	q_out[0] = -q_in[0];
	q_out[1] = -q_in[1];
	q_out[2] = -q_in[2];
	q_out[3] = -q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatConjugateQdv(double4 q_out, double4 const q_in)
{
	q_out[0] = -q_in[0];
	q_out[1] = -q_in[1];
	q_out[2] = -q_in[2];
	q_out[3] = +q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatConjugateMulQdvs(double4 q_out, double4 const q_in, f64 const s)
{
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = +q_in[3] * s;
	return q_out;
}

ijk_inl doublev ijkQuatNegateConjugateQdv(double4 q_out, double4 const q_in)
{
	q_out[0] = +q_in[0];
	q_out[1] = +q_in[1];
	q_out[2] = +q_in[2];
	q_out[3] = -q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatNegateConjugateMulQdvs(double4 q_out, double4 const q_in, f64 const s)
{
	q_out[0] = +q_in[0] * s;
	q_out[1] = +q_in[1] * s;
	q_out[2] = +q_in[2] * s;
	q_out[3] = -q_in[3] * s;
	return q_out;
}

ijk_inl doublev ijkQuatAddQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	q_out[0] = q_lh[0] + q_rh[0];
	q_out[1] = q_lh[1] + q_rh[1];
	q_out[2] = q_lh[2] + q_rh[2];
	q_out[3] = q_lh[3] + q_rh[3];
	return q_out;
}

ijk_inl doublev ijkQuatSubQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	q_out[0] = q_lh[0] - q_rh[0];
	q_out[1] = q_lh[1] - q_rh[1];
	q_out[2] = q_lh[2] - q_rh[2];
	q_out[3] = q_lh[3] - q_rh[3];
	return q_out;
}

ijk_inl doublev ijkQuatMulQdvs(double4 q_out, double4 const q_lh, f64 const s_rh)
{
	q_out[0] = q_lh[0] * s_rh;
	q_out[1] = q_lh[1] * s_rh;
	q_out[2] = q_lh[2] * s_rh;
	q_out[3] = q_lh[3] * s_rh;
	return q_out;
}

ijk_inl doublev ijkQuatDivQdvs(double4 q_out, double4 const q_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	return ijkQuatMulQdvs(q_out, q_lh, s);
}

ijk_inl doublev ijkQuatDivSafeQdvs(double4 q_out, double4 const q_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	return ijkQuatMulQdvs(q_out, q_lh, s);
}

ijk_inl f64 ijkQuatLengthSqQdv(double4 const q_in)
{
	return ijkVecLengthSq4dv(q_in);
}

ijk_inl f64 ijkQuatLengthQdv(double4 const q_in)
{
	return ijkVecLength4dv(q_in);
}

ijk_inl f64 ijkQuatLengthSqInvQdv(double4 const q_in)
{
	return ijkVecLengthSqInv4dv(q_in);
}

ijk_inl f64 ijkQuatLengthInvQdv(double4 const q_in)
{
	return ijkVecLengthInv4dv(q_in);
}

ijk_inl f64 ijkQuatLengthSqInvSafeQdv(double4 const q_in)
{
	return ijkVecLengthSqInvSafe4dv(q_in);
}

ijk_inl f64 ijkQuatLengthInvSafeQdv(double4 const q_in)
{
	return ijkVecLengthInvSafe4dv(q_in);
}

ijk_inl doublev ijkQuatNormalizeQdv(double4 q_out, double4 const q_in)
{
	return ijkVecNormalize4dv(q_out, q_in);
}

ijk_inl doublev ijkQuatNormalizeSafeQdv(double4 q_out, double4 const q_in)
{
	return ijkVecNormalizeSafe4dv(q_out, q_in);
}

ijk_inl doublev ijkQuatInverseQdv(double4 q_out, double4 const q_in)
{
	// q^-1 = q* / |q|^2
	f64 const s = ijkQuatLengthSqInvQdv(q_in);
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = q_in[3] * s;
	return q_out;
}

ijk_inl doublev ijkQuatInverseSafeQdv(double4 q_out, double4 const q_in)
{
	f64 const s = ijkQuatLengthSqInvSafeQdv(q_in);
	q_out[0] = -q_in[0] * s;
	q_out[1] = -q_in[1] * s;
	q_out[2] = -q_in[2] * s;
	q_out[3] = q_in[3] * s;
	return q_out;
}

ijk_inl doublev ijkQuatMulVecQdv3(double4 q_out, double4 const q_lh, double3 const v_rh)
{
	// ql vr = (vl + wl)vr
	//		= vl vr + wl vr
	//		= vl x vr - vl . vr + wl vr
	//		= (vl x vr + wl vr) - (vl . vr)
	double4 q;
	q[0] = q_lh[1] * v_rh[2] - q_lh[2] * v_rh[1] + q_lh[3] * v_rh[0];
	q[1] = q_lh[2] * v_rh[0] - q_lh[0] * v_rh[2] + q_lh[3] * v_rh[1];
	q[2] = q_lh[0] * v_rh[1] - q_lh[1] * v_rh[0] + q_lh[3] * v_rh[2];
	q[3] = -q_lh[0] * v_rh[0] - q_lh[1] * v_rh[1] - q_lh[2] * v_rh[2];
	return ijkQuatCopyQdv(q_out, q);
}

ijk_inl doublev ijkQuatMulVecQdv3q(double4 q_out, double3 const v_lh, double4 const q_rh)
{
	// vl qr = vl(vr + wr)
	//		= vl vr + vr wr
	//		= vl x vr - vl . vr + vr wr
	//		= (vl x vr + vr wr) - (vl . vr)
	double4 q;
	q[0] = v_lh[1] * q_rh[2] - v_lh[2] * q_rh[1] + v_lh[0] * q_rh[3];
	q[1] = v_lh[2] * q_rh[0] - v_lh[0] * q_rh[2] + v_lh[1] * q_rh[3];
	q[2] = v_lh[0] * q_rh[1] - v_lh[1] * q_rh[0] + v_lh[2] * q_rh[3];
	q[3] = -v_lh[0] * q_rh[0] - v_lh[1] * q_rh[1] - v_lh[2] * q_rh[2];
	return ijkQuatCopyQdv(q_out, q);
}

ijk_inl doublev ijkQuatMulQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	// ql qr = (vl + wl)(vr + wr)
	//		= vl vr + vl wr + wl vr + wl wr
	//		= vl x vr - vl . vr + vl wr + wl vr + wl wr
	//		= (vl x vr + vl wr + wl vr) + (wl wr - vl . vr)
	double4 q;
	q[0] = q_lh[1] * q_rh[2] - q_lh[2] * q_rh[1] + q_lh[3] * q_rh[0] + q_lh[0] * q_rh[3];
	q[1] = q_lh[2] * q_rh[0] - q_lh[0] * q_rh[2] + q_lh[3] * q_rh[1] + q_lh[1] * q_rh[3];
	q[2] = q_lh[0] * q_rh[1] - q_lh[1] * q_rh[0] + q_lh[3] * q_rh[2] + q_lh[2] * q_rh[3];
	q[3] = q_lh[3] * q_rh[3] - q_lh[0] * q_rh[0] - q_lh[1] * q_rh[1] - q_lh[2] * q_rh[2];
	return ijkQuatCopyQdv(q_out, q);
}

ijk_inl doublev ijkQuatMulConjQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	// ql qr* = (wl + vl)(wr - vr)
	//		= wl wr - wl vr + vl wr - vl vr
	//		= wl wr - wl vr + vl wr - vl x vr + vl . vr
	//		= (wl wr + vl . vr) + vr x vl + vl wr - wl vr
	//		= ql . qr + vr x vl + vl wr - wl vr
	double4 q;
	q[0] = q_rh[1] * q_lh[2] - q_rh[2] * q_lh[1] - q_lh[3] * q_rh[0] + q_lh[0] * q_rh[3];
	q[1] = q_rh[2] * q_lh[0] - q_rh[0] * q_lh[2] - q_lh[3] * q_rh[1] + q_lh[1] * q_rh[3];
	q[2] = q_rh[0] * q_lh[1] - q_rh[1] * q_lh[0] - q_lh[3] * q_rh[2] + q_lh[2] * q_rh[3];
	q[3] = ijkVecDot4dv(q_lh, q_rh);
	return ijkQuatCopyQdv(q_out, q);
}

ijk_inl doublev ijkQuatConjMulQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	// ql* qr = (wl - vl)(wr + vr)
	//		= wl wr + wl vr - vl wr - vl vr
	//		= wl wr + wl vr - vl wr - vl x vr + vl . vr
	//		= (wl wr + vl . vr) + vr x vl - vl wr + wl vr
	//		= ql . qr + vr x vl - vl wr + wl vr
	double4 q;
	q[0] = q_rh[1] * q_lh[2] - q_rh[2] * q_lh[1] - q_rh[3] * q_lh[0] + q_rh[0] * q_lh[3];
	q[1] = q_rh[2] * q_lh[0] - q_rh[0] * q_lh[2] - q_rh[3] * q_lh[1] + q_rh[1] * q_lh[3];
	q[2] = q_rh[0] * q_lh[1] - q_rh[1] * q_lh[0] - q_rh[3] * q_lh[2] + q_rh[2] * q_lh[3];
	q[3] = ijkVecDot4dv(q_lh, q_rh);
	return ijkQuatCopyQdv(q_out, q);
}

ijk_inl doublev ijkQuatDivQdv(double4 q_out, double4 const q_lh, double4 const q_rh)
{
	double4 q_inv;
	ijkQuatInverseQdv(q_inv, q_rh);
	return ijkQuatMulQdv(q_out, q_lh, q_inv);
}

ijk_inl doublev ijkQuatRotateXYZQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = cx * sy * sz + sx * cy * cz;
	q_out[1] = cx * sy * cz - sx * cy * sz;
	q_out[2] = cx * cy * sz + sx * sy * cz;
	q_out[3] = cx * cy * cz - sx * sy * sz;
	return q_out;
}

ijk_inl doublev ijkQuatRotateYZXQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = cy * cz * sx + sy * sz * cx;
	q_out[1] = cy * sz * sx + sy * cz * cx;
	q_out[2] = cy * sz * cx - sy * cz * sx;
	q_out[3] = cy * cz * cx - sy * sz * sx;
	return q_out;
}

ijk_inl doublev ijkQuatRotateZXYQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = cz * sx * cy - sz * cx * sy;
	q_out[1] = cz * cx * sy + sz * sx * cy;
	q_out[2] = cz * sx * sy + sz * cx * cy;
	q_out[3] = cz * cx * cy - sz * sx * sy;
	return q_out;
}

ijk_inl doublev ijkQuatRotateYXZQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = cy * sx * cz + sy * cx * sz;
	q_out[1] = sy * cx * cz - cy * sx * sz;
	q_out[2] = cy * cx * sz - sy * sx * cz;
	q_out[3] = cy * cx * cz + sy * sx * sz;
	return q_out;
}

ijk_inl doublev ijkQuatRotateXZYQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = sx * cz * cy - cx * sz * sy;
	q_out[1] = cx * cz * sy - sx * sz * cy;
	q_out[2] = cx * sz * cy + sx * cz * sy;
	q_out[3] = cx * cz * cy + sx * sz * sy;
	return q_out;
}

ijk_inl doublev ijkQuatRotateZYXQdv(double4 q_out, double3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[0] * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[1] * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ[2] * dbl_half, &sz, &cz);
	q_out[0] = cz * cy * sx - sz * sy * cx;
	q_out[1] = cz * sy * cx + sz * cy * sx;
	q_out[2] = sz * cy * cx - cz * sy * sx;
	q_out[3] = cz * cy * cx + sz * sy * sx;
	return q_out;
}

ijk_inl doublekv ijkQuatGetRotateXYZQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	f64 s = dbl_two * (z * x + y * w), c;
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * z - y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * x - y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateYZXQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	f64 s = dbl_two * (x * y + z * w), c;
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * x - z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * y - z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateZXYQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	f64 s = dbl_two * (y * z + x * w), c;
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * y - x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * z - x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateYXZQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	f64 s = dbl_two * (w * x - y * z), c;
	rotateDegXYZ_out[0] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * y + x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * z + x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateXZYQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	f64 s = dbl_two * (w * z - x * y), c;
	rotateDegXYZ_out[2] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * x + z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * y + z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out[1] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateZYXQdv(double4 const q_in, double3 rotateDegXYZ_out)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	f64 s = dbl_two * (w * y - z * x), c;
	rotateDegXYZ_out[1] = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * z + y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out[2] = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * x + y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out[0] = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl doublev ijkQuatRotateQdv(double4 q_out, ijkRotationOrder const order, double3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatRotateXYZQdv(q_out, rotateDegXYZ);
	case ijkRotationYZX:
		return ijkQuatRotateYZXQdv(q_out, rotateDegXYZ);
	case ijkRotationZXY:
		return ijkQuatRotateZXYQdv(q_out, rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkQuatRotateYXZQdv(q_out, rotateDegXYZ);
	case ijkRotationXZY:
		return ijkQuatRotateXZYQdv(q_out, rotateDegXYZ);
	case ijkRotationZYX:
		return ijkQuatRotateZYXQdv(q_out, rotateDegXYZ);
	}
	return q_out;
}

ijk_inl doublev ijkQuatAxisAngleQdv(double4 q_out, double3 const axis_unit, f64 const angle_degrees)
{
	f64 s;
	ijkTrigSinCos_deg_dbl(angle_degrees * dbl_half, &s, q_out + 3);
	return ijkVecMul3dvs(q_out, axis_unit, s);
}

ijk_inl doublev ijkQuatScaleQdv(double4 q_out, f64 const scale_unif)
{
	q_out[0] = q_out[1] = q_out[2] = dbl_zero;
	q_out[3] = ijkSqrt_dbl(scale_unif);
	return q_out;
}

ijk_inl doublev ijkQuatRotateScaleQdv(double4 q_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif)
{
	f64 const len = ijkSqrt_dbl(scale_unif);
	ijkQuatRotateQdv(q_out, order, rotateDegXYZ);
	return ijkQuatMulQdvs(q_out, q_out, len);
}

ijk_inl doublev ijkQuatAxisAngleScaleQdv(double4 q_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif)
{
	f64 s;
	f64 const len = ijkSqrt_dbl(scale_unif);
	ijkTrigSinCos_deg_dbl(angle_degrees * dbl_half, &s, q_out + 3);
	q_out[3] *= len;
	return ijkVecMul3dvs(q_out, axis_unit, s * len);
}

ijk_inl doublekv ijkQuatGetRotateQdv(double4 const q_in, ijkRotationOrder const order, double3 rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatGetRotateXYZQdv(q_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkQuatGetRotateYZXQdv(q_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkQuatGetRotateZXYQdv(q_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkQuatGetRotateYXZQdv(q_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkQuatGetRotateXZYQdv(q_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkQuatGetRotateZYXQdv(q_in, rotateDegXYZ_out);
	}
	return q_in;
}

ijk_inl doublekv ijkQuatGetAxisAngleQdv(double4 const q_in, double3 axis_unit_out, f64* const angle_degrees_out)
{
	f64 const s = ijkVecLength3dv(q_in);
	ijkVecDivSafe3dvs(axis_unit_out, q_in, s);
	*angle_degrees_out = dbl_two * ijkTrigAtan2_deg_dbl(s, q_in[3]);
	return q_in;
}

ijk_inl doublekv ijkQuatGetScaleQdv(double4 const q_in, f64* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQdv(q_in);
	return q_in;
}

ijk_inl doublekv ijkQuatGetRotateScaleQdv(double4 const q_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQdv(q_in);
	return ijkQuatGetRotateQdv(q_in, order, rotateDegXYZ_out);
}

ijk_inl doublekv ijkQuatGetAxisAngleScaleQdv(double4 const q_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out)
{
	f64 s = ijkVecLengthSq3dv(q_in);
	*scale_unif_out = ijkSqrt_dbl(s + q_in[3] * q_in[3]);
	s = ijkSqrt_dbl(s);
	ijkVecDivSafe3dvs(axis_unit_out, q_in, s);
	*angle_degrees_out = dbl_two * ijkTrigAtan2_deg_dbl(s, q_in[3]);
	return q_in;
}

ijk_inl double3m ijkQuatGetMatQdv3(double3x3 m_out, double4 const q_in)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = dbl_two * (xy + zw);
	m_out[0][2] = dbl_two * (zx - yw);
	m_out[1][0] = dbl_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = dbl_two * (yz + xw);
	m_out[2][0] = dbl_two * (zx + yw);
	m_out[2][1] = dbl_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	return m_out;
}

ijk_inl double3m ijkQuatUnitGetMatQdv3(double3x3 m_out, double4 const q_in)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = dbl_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = dbl_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = dbl_one - (xx2 + yy2);
	return m_out;
}

ijk_inl double4m ijkQuatGetMatQdv4(double4x4 m_out, double4 const q_in)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = dbl_two * (xy + zw);
	m_out[0][2] = dbl_two * (zx - yw);
	m_out[1][0] = dbl_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = dbl_two * (yz + xw);
	m_out[2][0] = dbl_two * (zx + yw);
	m_out[2][1] = dbl_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	m_out[3][3] = dbl_one;
	return m_out;
}

ijk_inl double4m ijkQuatUnitGetMatQdv4(double4x4 m_out, double4 const q_in)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = dbl_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = dbl_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = dbl_one - (xx2 + yy2);
	m_out[0][3] = m_out[1][3] = m_out[2][3] = m_out[3][0] = m_out[3][1] = m_out[3][2] = dbl_zero;
	m_out[3][3] = dbl_one;
	return m_out;
}

ijk_inl double4m ijkQuatGetMatQdv4t(double4x4 m_out, double4 const q_in, double3 const translate)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	m_out[0][0] = ww + xx - yy - zz;
	m_out[0][1] = dbl_two * (xy + zw);
	m_out[0][2] = dbl_two * (zx - yw);
	m_out[1][0] = dbl_two * (xy - zw);
	m_out[1][1] = wwxx + yyzz;
	m_out[1][2] = dbl_two * (yz + xw);
	m_out[2][0] = dbl_two * (zx + yw);
	m_out[2][1] = dbl_two * (yz - xw);
	m_out[2][1] = wwxx - yyzz;
	m_out[0][3] = m_out[1][3] = m_out[2][3] = dbl_zero;
	ijkVecCopy4dvw(m_out[3], translate, dbl_one);
	return m_out;
}

ijk_inl double4m ijkQuatUnitGetMatQdv4t(double4x4 m_out, double4 const q_in, double3 const translate)
{
	f64 const x = q_in[0], y = q_in[1], z = q_in[2], w = q_in[3],
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	m_out[0][0] = dbl_one - (yy2 + zz2);
	m_out[0][1] = (xy2 + zw2);
	m_out[0][2] = (zx2 - yw2);
	m_out[1][0] = (xy2 - zw2);
	m_out[1][1] = dbl_one - (zz2 + xx2);
	m_out[1][2] = (yz2 + xw2);
	m_out[2][0] = (zx2 + yw2);
	m_out[2][1] = (yz2 - xw2);
	m_out[2][1] = dbl_one - (xx2 + yy2);
	m_out[0][3] = m_out[1][3] = m_out[2][3] = dbl_zero;
	ijkVecCopy4dvw(m_out[3], translate, dbl_one);
	return m_out;
}

ijk_inl doublev ijkQuatRotateScaleVecQdv3(double3 v_out, double4 const q_in, double3 const v_in)
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
	// 24*,14+-
	f64 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3],
		ww = qw * qw - ijkVecLengthSq3dv(q_in), w2 = dbl_two * qw, d = dbl_two * ijkVecDot3dv(q_in, v_in);	// 9*, 5+-
	double3 const v = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d),	// 5*, 3+-
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d),	// 5*, 3+-
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d),	// 5*, 3+-
	};
	// 25*,15+-
	//f64 const lenSq = ijkQuatLengthSqQdv(q_in);	// 4*, 3+
	//double3 const v = {
	//	(qy * vz - qz * vy + qw * vx),	// 3*, 2+-
	//	(qz * vx - qx * vz + qw * vy),	// 3*, 2+-
	//	(qx * vy - qy * vx + qw * vz),	// 3*, 2+-
	//};
	//v_out[0] = vx * lenSq + dbl_two * (qy * v[2] - qz * v[1]);	// 4*, 2+-
	//v_out[1] = vy * lenSq + dbl_two * (qz * v[0] - qx * v[2]);	// 4*, 2+-
	//v_out[2] = vz * lenSq + dbl_two * (qx * v[1] - qy * v[0]);	// 4*, 2+-
	return ijkVecCopy3dv(v_out, v);
}

ijk_inl doublev ijkQuatUnitRotateVecQdv3(double3 v_out, double4 const q_in, double3 const v_in)
{
	// v' = q v q*
	//		= v + 2vq x (vq x v + wq v)
	f64 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3];
	double3 const v = {
		(qy * vz - qz * vy + qw * vx),	// 3*, 2+-
		(qz * vx - qx * vz + qw * vy),	// 3*, 2+-
		(qx * vy - qy * vx + qw * vz),	// 3*, 2+-
	};
	v_out[0] = vx + dbl_two * (qy * v[2] - qz * v[1]);	// 3*, 2+-
	v_out[1] = vy + dbl_two * (qz * v[0] - qx * v[2]);	// 3*, 2+-
	v_out[2] = vz + dbl_two * (qx * v[1] - qy * v[0]);	// 3*, 2+-
	return v_out;
}

ijk_inl doublev ijkQuatRotateVecQdv3(double3 v_out, double4 const q_in, double3 const v_in)
{
	// v' /= |q|^2
	//		= v(wq2 - vq . vq) + 2wq(vq x v) + 2vq(vq . v)
	//	|q|^2 = 2wq2 - (wq2 - vq . vq) = 2wq2 - wq2 + vq . vq
	f64 const vx = v_in[0], vy = v_in[1], vz = v_in[2], qx = q_in[0], qy = q_in[1], qz = q_in[2], qw = q_in[3],
		ww = qw * qw - ijkVecLengthSq3dv(q_in), w2 = dbl_two * qw, d = dbl_two * ijkVecDot3dv(q_in, v_in);
	f64 const nrm = dbl_one / (w2 * qw - ww);
	double3 const v = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d) * nrm,
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d) * nrm,
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d) * nrm,
	};
	return ijkVecCopy3dv(v_out, v);
}

ijk_inl doublev ijkQuatReflectScaleQdv(double4 q_out, double4 const q_in, double3 const v_in)
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
	f64 const d = dbl_two * ijkVecDot3dv(q_in, v_in), lenSq = ijkQuatLengthSqQdv(q_in);
	q_out[0] = v_in[0] * lenSq - d * q_in[0];
	q_out[1] = v_in[1] * lenSq - d * q_in[1];
	q_out[2] = v_in[2] * lenSq - d * q_in[2];
	q_out[3] = -d * q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatUnitReflectQdv(double4 q_out, double4 const q_in, double3 const v_in)
{
	// v' = q v q
	//		= v - 2(vq . v)q
	f64 const d = dbl_two * ijkVecDot3dv(q_in, v_in);
	q_out[0] = v_in[0] - d * q_in[0];
	q_out[1] = v_in[1] - d * q_in[1];
	q_out[2] = v_in[2] - d * q_in[2];
	q_out[3] = -d * q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatReflectQdv(double4 q_out, double4 const q_in, double3 const v_in)
{
	// v' = q v q
	//	v' /= |q|^2
	//		= v - 2(vq . v)q / |q|^2
	f64 const d = dbl_two * ijkVecDot3dv(q_in, v_in), lenSqInv = d * ijkQuatLengthSqInvQdv(q_in);
	q_out[0] = v_in[0] - lenSqInv * q_in[0];
	q_out[1] = v_in[1] - lenSqInv * q_in[1];
	q_out[2] = v_in[2] - lenSqInv * q_in[2];
	q_out[3] = -lenSqInv * q_in[3];
	return q_out;
}

ijk_inl doublev ijkQuatExpQdv(double4 q_out, double3 const v_in)
{
	// exp(v) = exp(|v|unit(v)) = cos(|v|) + sin(|v|)unit(v)
	f64 const len = ijkVecLength3dv(v_in);
	if (len > dbl_zero)
	{
		ijkTrigSinCos_rad_dbl(len, q_out, q_out + 3);
		return ijkVecMul3dvs(q_out, v_in, *q_out / len);
	}
	return ijkQuatInitQdv(q_out);
}

ijk_inl doublev ijkQuatLnQdv(double4 q_out, double4 const q_in)
{
	// ln(q) = ln(|q|unit(q))
	//		= ln|q| + ln(w + v)
	//		= ln|q| + ln(cos(|v|) + sin(|v|)unit(v))
	//		= ln|q| + |v|unit(v)
	//		= ln|q| + acos(w/|q|)v/|v|
	f64 lenv = ijkVecLengthSq3dv(q_in);
	if (lenv > dbl_zero)
	{
		f64 const lenq = ijkSqrt_dbl(lenv + q_in[3] * q_in[3]);
		lenv = ijkTrigAcos_rad_dbl(q_in[3] / lenq) * ijkSqrtInv_dbl(lenv);
		q_out[3] = ijkTrigLn1p_dbl(lenq - dbl_one);
		return ijkVecMul3dvs(q_out, q_in, lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = dbl_zero;
	q_out[3] = ijkTrigLn1p_dbl(q_in[3] - dbl_one);
	return q_out;
}

ijk_inl doublev ijkQuatPowQdv(double4 q_out, double4 const q_in, f64 const u)
{
	// q^u = |q|^u unit(q)^u
	//		= |q|^u (cos(a) + sin(a)n)^u
	//		= |q|^u (cos(ua) + sin(ua)n)
	f64 lenv = ijkVecLengthSq3dv(q_in), a, s;
	if (lenv > dbl_zero)
	{
		f64 const lenq = ijkTrigPow_dbl((lenv + q_in[3] * q_in[3]), u * dbl_half);
		lenv = ijkSqrtInv_dbl(lenv);
		a = u * ijkTrigAtan2_deg_dbl(lenv, q_in[3]);
		ijkTrigSinCos_deg_dbl(a, &s, q_out + 3);
		q_out[3] *= lenq;
		return ijkVecMul3dvs(q_out, q_in, lenq / lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = dbl_zero;
	q_out[3] = ijkTrigPow_dbl(q_in[3], u);
	return q_out;
}

ijk_inl doublev ijkQuatSqrtQdv(double4 q_out, double4 const q_in)
{
	f64 lenv = ijkVecLengthSq3dv(q_in);
	if (lenv > dbl_zero)
	{
		f64 const w = q_in[3], lenq = ijkSqrt_dbl(lenv + w * w);
		q_out[3] = ijkSqrt_dbl(dbl_half * (lenq + w));
		lenv = ijkSqrt_dbl(dbl_half * (lenq - w) / lenv);
		return ijkVecMul3dvs(q_out, q_in, lenv);
	}
	q_out[0] = q_out[1] = q_out[2] = dbl_zero;
	q_out[3] = ijkSqrt_dbl(q_in[3]);
	return q_out;
}

ijk_inl doublev ijkQuatLerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u)
{
	return ijkVecLerp4dv(q_out, q0, q1, u);
}

ijk_inl doublev ijkQuatNlerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u)
{
	ijkQuatLerpQdv(q_out, q0, q1, u);
	return ijkQuatNormalizeQdv(q_out, q_out);
}

ijk_inl doublev ijkQuatSlerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u)
{
	// similar to vector slerp except we have to worry about double-coverage
	double4 copy;
	doublekv q1b = q1;
	f64 dot = ijkVecDot4dv(q0, q1);
	if (dot < dbl_zero)
	{
		dot = -dot;
		q1b = ijkQuatNegateQdv(copy, q1b);
	}
	if (dot < dbl_one)
	{
		double4 tmp;
		f64 const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkQuatAddQdv(q_out, ijkQuatMulQdvs(q_out, q0, s0), ijkQuatMulQdvs(tmp, q1b, s1));
	}
	return ijkQuatNlerpQdv(q_out, q0, q1b, u);
}

ijk_inl doublev ijkQuatDerivQdv(double4 q1_out, double4 const q_in, double3 const angularVelocity)
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
	double3 const hw = {
		(dbl_half * angularVelocity[0]), (dbl_half * angularVelocity[1]), (dbl_half * angularVelocity[2])
	};
	return ijkQuatMulVecQdv3q(q1_out, hw, q_in);
}

ijk_inl doublev ijkQuatDeriv2Qdv(double4 q2_out, double4 const q_in, double3 const angularVelocity, double3 const angularAcceleration)
{
	// q" = d(q')/dt = d(w q/2)/dt
	//		= (dw/dt)q/2 + w(dq/dt)/2
	//		= aq/2 + w(wq/2)/2
	//		= aq/2 - q|w|^2/4
	//		= (a/2 - |w|^2/4)q	-> [lenSq: 7; sub&mul: 7; mul: 28; total = 42]
	f64 const angularSpeedSq = ijkVecLengthSq3dv(angularVelocity);
	double4 const q_lh = {
		(dbl_half * angularAcceleration[0]), (dbl_half * angularAcceleration[1]), (dbl_half * angularAcceleration[2]), (-dbl_quarter * angularSpeedSq)
	};
	return ijkQuatMulQdv(q2_out, q_lh, q_in);
}

ijk_inl doublev ijkQuatEncodeTranslateQdv(double4 qt_out, double3 const translate_in, double4 const q_encode)
{
	// q' = tq/2
	//		= t(w + v)/2
	//		= (tw + tv)/2
	//		= ([tw + t x v] - [t . v])/2
	return ijkQuatDerivQdv(qt_out, q_encode, translate_in);
}

ijk_inl doublev ijkQuatEncodeTranslateX2Qdv(double4 qt_out, double3 const translate_in, double4 const q_encode)
{
	// q' = tq
	return ijkQuatMulVecQdv3q(qt_out, translate_in, q_encode);
}

ijk_inl doublev ijkQuatDecodeTranslateQdv(double3 translate_out, double4 const qt_in, double4 const q_decode)
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
	//		= 2([0] + [v' w - w' v + v x v'])	-> [15x9+- = 24]
	f64 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = dbl_two * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = dbl_two * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = dbl_two * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl doublev ijkQuatDecodeTranslateD2Qdvs(double3 translate_out, double4 const qt_in, double4 const q_decode, f64 const s)
{
	// q' = tq/2
	// s t/2 = s q'q*
	f64 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl doublev ijkQuatDecodeTranslateD2Qdv(double3 translate_out, double4 const qt_in, double4 const q_decode)
{
	// q' = tq/2
	// t/2 = q'q*
	f64 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3];
	translate_out[0] = (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl doublev ijkQuatDecodeTranslateRemScaleQdv(double3 translate_out, double4 const qt_in, double4 const q_decode)
{
	// q' = tq/2
	// t = 2q'q^-1 = 2q'q*/|q|^2
	f64 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3],
		s = dbl_two / ijkQuatLengthSqQdv(q_decode);
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}

ijk_inl doublev ijkQuatDecodeTranslateRemScaleD2Qdv(double3 translate_out, double4 const qt_in, double4 const q_decode)
{
	// q' = tq/2
	// t/2 = q'q^-1 = q'q*/|q|^2
	f64 const qx = q_decode[0], qy = q_decode[1], qz = q_decode[2], qw = q_decode[3],
		qtx = qt_in[0], qty = qt_in[1], qtz = qt_in[2], qtw = qt_in[3],
		s = dbl_one / ijkQuatLengthSqQdv(q_decode);
	translate_out[0] = s * (qtx * qw - qtw * qx + qy * qtz - qz * qty);
	translate_out[1] = s * (qty * qw - qtw * qy + qz * qtx - qx * qtz);
	translate_out[2] = s * (qtz * qw - qtw * qz + qx * qty - qy * qtx);
	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl double4m ijkDualQuatInitDQdm(double2x4 dq_out)
{
	ijkQuatInitQdv(dq_out[0]);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatInitDualReDQdm(double2x4 dq_out, double4 const re, double4 const dual)
{
	ijkQuatCopyQdv(dq_out[0], re);
	ijkQuatCopyQdv(dq_out[1], dual);
	return dq_out;
}

ijk_inl double4m ijkDualQuatInitMatDQdm3(double2x4 dq_out, double3x3 const m_in)
{
	ijkQuatInitMatQdv3(dq_out[0], m_in);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatInitMatDQdm4(double2x4 dq_out, double4x4 const m_in)
{
	ijkQuatEncodeTranslateQdv(dq_out[1], m_in[3], ijkQuatInitMatQdv4(dq_out[0], m_in));
	return dq_out;
}

ijk_inl double4m ijkDualQuatCopyDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	ijkQuatCopyQdv(dq_out[0], dq_in[0]);
	ijkQuatCopyQdv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatNegateDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	ijkQuatNegateQdv(dq_out[0], dq_in[0]);
	ijkQuatNegateQdv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatConjugateDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	ijkQuatConjugateQdv(dq_out[0], dq_in[0]);
	ijkQuatConjugateQdv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatNegateDualDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	ijkQuatCopyQdv(dq_out[0], dq_in[0]);
	ijkQuatNegateQdv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatConjugateDualDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	ijkQuatConjugateQdv(dq_out[0], dq_in[0]);
	ijkQuatNegateConjugateQdv(dq_out[1], dq_in[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatAddDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh)
{
	ijkQuatAddQdv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQdv(dq_out[1], dq_lh[1], dq_rh[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatSubDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh)
{
	ijkQuatSubQdv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatSubQdv(dq_out[1], dq_lh[1], dq_rh[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatMulDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh)
{
	ijkQuatMulQdvs(dq_out[0], dq_lh[0], s_rh);
	ijkQuatMulQdvs(dq_out[1], dq_lh[1], s_rh);
	return dq_out;
}

ijk_inl double4m ijkDualQuatDivDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_dbl(s_rh);
	return ijkDualQuatMulDQdms(dq_out, dq_lh, s);
}

ijk_inl double4m ijkDualQuatDivSafeDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh)
{
	f64 const s = ijk_recip_safe_dbl(s_rh);
	return ijkDualQuatMulDQdms(dq_out, dq_lh, s);
}

ijk_inl f64 ijkDualQuatLengthSqDQdm(double2x4 const dq_in)
{
	// length is that of real part only
	return ijkQuatLengthSqQdv(dq_in[0]);
}

ijk_inl f64 ijkDualQuatLengthDQdm(double2x4 const dq_in)
{
	return ijkQuatLengthQdv(dq_in[0]);
}

ijk_inl f64 ijkDualQuatLengthSqInvDQdm(double2x4 const dq_in)
{
	return ijkQuatLengthSqInvQdv(dq_in[0]);
}

ijk_inl f64 ijkDualQuatLengthInvDQdm(double2x4 const dq_in)
{
	return ijkQuatLengthInvQdv(dq_in[0]);
}

ijk_inl f64 ijkDualQuatLengthSqInvSafeDQdm(double2x4 const dq_in)
{
	return ijkQuatLengthSqInvSafeQdv(dq_in[0]);
}

ijk_inl f64 ijkDualQuatLengthInvSafeDQdm(double2x4 const dq_in)
{
	return ijkQuatLengthInvSafeQdv(dq_in[0]);
}

ijk_inl double4m ijkDualQuatNormalizeDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	// divide both parts by real part's length
	f64 const lenInv = ijkQuatLengthInvQdv(dq_in[0]);
	ijkQuatMulQdvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatMulQdvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl double4m ijkDualQuatNormalizeSafeDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	f64 const lenInv = ijkQuatLengthInvSafeQdv(dq_in[0]);
	ijkQuatMulQdvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatMulQdvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl double4m ijkDualQuatInverseDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	// conjugate of each part divided by real part's length
	f64 const lenInv = ijkQuatLengthInvQdv(dq_in[0]);
	ijkQuatConjugateMulQdvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatConjugateMulQdvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl double4m ijkDualQuatInverseSafeDQdm(double2x4 dq_out, double2x4 const dq_in)
{
	f64 const lenInv = ijkQuatLengthInvSafeQdv(dq_in[0]);
	ijkQuatConjugateMulQdvs(dq_out[0], dq_in[0], lenInv);
	ijkQuatConjugateMulQdvs(dq_out[1], dq_in[1], lenInv);
	return dq_out;
}

ijk_inl double4m ijkDualQuatMulVecDQdm3(double2x4 dq_out, double2x4 const dq_lh, double3 const v_rh)
{
	// dq' = (r + Ed)v
	//		= rv + Edv
	ijkQuatMulVecQdv3(dq_out[0], dq_lh[0], v_rh);
	ijkQuatMulVecQdv3(dq_out[1], dq_lh[1], v_rh);
	return dq_out;
}

ijk_inl double4m ijkDualQuatMulVecDQdm3q(double2x4 dq_out, double3 const v_lh, double2x4 const dq_rh)
{
	// dq' = v(r + Ed)
	//		= vr + Evd
	ijkQuatMulVecQdv3q(dq_out[0], v_lh, dq_rh[0]);
	ijkQuatMulVecQdv3q(dq_out[1], v_lh, dq_rh[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatMulDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh)
{
	// dq' = (r_lh + E d_lh)(r_rh + E d_rh)
	//		= r_lh r_rh + E r_lh d_rh + E d_lh r_rh + EE d_lh d_rh -> EE = 0
	//		= r_lh r_rh + E(r_lh d_rh + d_lh r_rh)
	double4 tmp_lh, tmp_rh;
	ijkQuatMulQdv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQdv(dq_out[1], ijkQuatMulQdv(tmp_lh, dq_lh[0], dq_rh[1]), ijkQuatMulQdv(tmp_rh, dq_lh[1], dq_rh[0]));
	return dq_out;
}

ijk_inl double4m ijkDualQuatMulScaleDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh)
{
	// dq' = (r_lh + E d_lh)(r_rh + |r_lh|^2 E d_rh)
	//		= r_lh r_rh + |r_lh|^2 E r_lh d_rh + E d_lh r_rh + |r_lh|^2 EE d_lh d_rh -> EE = 0
	//		= r_lh r_rh + E(|r_lh|^2 r_lh d_rh + d_lh r_rh)
	double4 tmp_lh, tmp_rh;
	f64 const lenSq = ijkQuatLengthSqQdv(dq_lh[0]);
	ijkQuatMulQdv(dq_out[0], dq_lh[0], dq_rh[0]);
	ijkQuatAddQdv(dq_out[1], ijkQuatMulQdvs(tmp_lh, ijkQuatMulQdv(tmp_lh, dq_lh[0], dq_rh[1]), lenSq), ijkQuatMulQdv(tmp_rh, dq_lh[1], dq_rh[0]));
	return dq_out;
}

ijk_inl double4m ijkDualQuatDivDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh)
{
	double2x4 dq_rh_inv;
	return ijkDualQuatMulDQdm(dq_out, dq_lh, ijkDualQuatInverseDQdm(dq_rh_inv, dq_rh));
}

ijk_inl double4m ijkDualQuatRotateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ)
{
	ijkQuatRotateQdv(dq_out[0], order, rotateDegXYZ);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatAxisAngleDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees)
{
	ijkQuatAxisAngleQdv(dq_out[0], axis_unit, angle_degrees);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatScaleDQdm(double2x4 dq_out, f64 const scale_unif)
{
	ijkQuatScaleQdv(dq_out[0], scale_unif);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatRotateScaleDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif)
{
	ijkQuatRotateScaleQdv(dq_out[0], order, rotateDegXYZ, scale_unif);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatAxisAngleScaleDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif)
{
	ijkQuatAxisAngleScaleQdv(dq_out[0], axis_unit, angle_degrees, scale_unif);
	ijkQuatInitZeroQdv(dq_out[1]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatTranslateDQdm(double2x4 dq_out, double3 const translate)
{
	f64 const s = dbl_half;
	ijkQuatInitQdv(dq_out[0]);
	ijkQuatInitElemsQdv(dq_out[1], (translate[0] * s), (translate[1] * s), (translate[2] * s), dbl_zero);
	return dq_out;
}

ijk_inl double4m ijkDualQuatRotateTranslateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const translate)
{
	ijkQuatRotateQdv(dq_out[0], order, rotateDegXYZ);
	ijkQuatEncodeTranslateQdv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatAxisAngleTranslateDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, double3 const translate)
{
	ijkQuatAxisAngleQdv(dq_out[0], axis_unit, angle_degrees);
	ijkQuatEncodeTranslateQdv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatScaleTranslateDQdm(double2x4 dq_out, f64 const scale_unif, double3 const translate)
{
	f64 s = dbl_half;
	ijkQuatScaleQdv(dq_out[0], scale_unif);
	s *= dq_out[0][3];
	ijkQuatInitElemsQdv(dq_out[1], (translate[0] * s), (translate[1] * s), (translate[2] * s), dbl_zero);
	return dq_out;
}

ijk_inl double4m ijkDualQuatRotateScaleTranslateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif, double3 const translate)
{
	ijkQuatRotateScaleQdv(dq_out[0], order, rotateDegXYZ, scale_unif);
	ijkQuatEncodeTranslateQdv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl double4m ijkDualQuatAxisAngleScaleTranslateDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif, double3 const translate)
{
	ijkQuatAxisAngleScaleQdv(dq_out[0], axis_unit, angle_degrees, scale_unif);
	ijkQuatEncodeTranslateQdv(dq_out[1], translate, dq_out[0]);
	return dq_out;
}

ijk_inl double4km ijkDualQuatGetRotateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out)
{
	ijkQuatGetRotateQdv(dq_in[0], order, rotateDegXYZ_out);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out)
{
	ijkQuatGetAxisAngleQdv(dq_in[0], axis_unit_out, angle_degrees_out);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetScaleDQdm(double2x4 const dq_in, f64* const scale_unif_out)
{
	ijkQuatGetScaleQdv(dq_in[0], scale_unif_out);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetRotateScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out)
{
	ijkQuatGetRotateScaleQdv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out)
{
	ijkQuatGetAxisAngleScaleQdv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetTranslateDQdm(double2x4 const dq_in, double3 translate_out)
{
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetRotateTranslateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out)
{
	ijkQuatGetRotateQdv(dq_in[0], order, rotateDegXYZ_out);
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleTranslateDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out)
{
	ijkQuatGetAxisAngleQdv(dq_in[0], axis_unit_out, angle_degrees_out);
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetScaleTranslateDQdm(double2x4 const dq_in, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetScaleQdv(dq_in[0], scale_unif_out);
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetRotateScaleTranslateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetRotateScaleQdv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleScaleTranslateDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetAxisAngleScaleQdv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetTranslateRemScaleDQdm(double2x4 const dq_in, double3 translate_out)
{
	ijkQuatDecodeTranslateRemScaleQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetRotateTranslateRemScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out)
{
	ijkQuatGetRotateQdv(dq_in[0], order, rotateDegXYZ_out);
	ijkQuatDecodeTranslateRemScaleQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleTranslateRemScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out)
{
	ijkQuatGetAxisAngleQdv(dq_in[0], axis_unit_out, angle_degrees_out);
	ijkQuatDecodeTranslateRemScaleQdv(translate_out, dq_in[1], dq_in[0]);
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetScaleTranslateRemScaleDQdm(double2x4 const dq_in, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetScaleQdv(dq_in[0], scale_unif_out);
	ijkQuatDecodeTranslateD2Qdvs(translate_out, dq_in[1], dq_in[0], (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetRotateScaleTranslateRemScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetRotateScaleQdv(dq_in[0], order, rotateDegXYZ_out, scale_unif_out);
	ijkQuatDecodeTranslateD2Qdvs(translate_out, dq_in[1], dq_in[0], (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out, double3 translate_out)
{
	ijkQuatGetAxisAngleScaleQdv(dq_in[0], axis_unit_out, angle_degrees_out, scale_unif_out);
	ijkQuatDecodeTranslateD2Qdvs(translate_out, dq_in[1], dq_in[0], (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl double4km ijkDualQuatGetScrewParamsDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out, double3 momentArm_out, f64* const screwDisplace_out)
{
	doublekv r = dq_in[0], d = dq_in[1];
	f64 const lenSq = ijkQuatLengthSqQdv(r), lenSqInv2 = dbl_two / lenSq;
	f64 const c = r[3], s = ijkSqrt_dbl(lenSq - c * c);
	f64 const angle = ijkTrigAtan2_deg_dbl(s, c), cot = c / s;
	f64 distance;

	translate_out[0] = lenSqInv2 * (d[0] * r[3] + d[2] * r[1] - d[1] * r[2] - d[3] * r[0]);
	translate_out[1] = lenSqInv2 * (d[1] * r[3] + d[0] * r[2] - d[2] * r[0] - d[3] * r[1]);
	translate_out[2] = lenSqInv2 * (d[2] * r[3] + d[1] * r[0] - d[0] * r[1] - d[3] * r[2]);

	axis_unit_out[0] = r[0] * s;
	axis_unit_out[1] = r[1] * s;
	axis_unit_out[2] = r[2] * s;

	*angle_degrees_out = dbl_two * angle;
	*screwDisplace_out = distance = ijkVecDot3dv(translate_out, axis_unit_out);

	// moment = 1/2 * ( cross(translate, axis) + (translate - distance*axis)*cot(halfAngle) )
	momentArm_out[0] = dbl_half * (translate_out[1] * axis_unit_out[2] - translate_out[2] * axis_unit_out[1] + cot * (translate_out[0] - distance * axis_unit_out[0]));
	momentArm_out[1] = dbl_half * (translate_out[2] * axis_unit_out[0] - translate_out[0] * axis_unit_out[2] + cot * (translate_out[1] - distance * axis_unit_out[1]));
	momentArm_out[2] = dbl_half * (translate_out[0] * axis_unit_out[1] - translate_out[1] * axis_unit_out[0] + cot * (translate_out[2] - distance * axis_unit_out[2]));

	return dq_in;
}

ijk_inl double3m ijkDualQuatGetMatDQdm3(double3x3 m_out, double2x4 const dq_in)
{
	return ijkQuatGetMatQdv3(m_out, dq_in[0]);
}

ijk_inl double3m ijkDualQuatUnitGetMatDQdm3(double3x3 m_out, double2x4 const dq_in)
{
	return ijkQuatUnitGetMatQdv3(m_out, dq_in[0]);
}

ijk_inl double3m ijkDualQuatGetMatTranslateDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in)
{
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatGetMatQdv3(m_out, dq_in[0]);
}

ijk_inl double3m ijkDualQuatUnitGetMatTranslateDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in)
{
	ijkQuatDecodeTranslateQdv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatUnitGetMatQdv3(m_out, dq_in[0]);
}

ijk_inl double3m ijkDualQuatGetMatTranslateRemScaleDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in)
{
	ijkQuatDecodeTranslateRemScaleQdv(translate_out, dq_in[1], dq_in[0]);
	return ijkQuatGetMatQdv3(m_out, dq_in[0]);
}

ijk_inl double4m ijkDualQuatGetMatDQdm4(double4x4 m_out, double2x4 const dq_in)
{
	double3 translate;
	return ijkQuatGetMatQdv4t(m_out, dq_in[0], ijkQuatDecodeTranslateQdv(translate, dq_in[1], dq_in[0]));
}

ijk_inl double4m ijkDualQuatUnitGetMatDQdm4(double4x4 m_out, double2x4 const dq_in)
{
	double3 translate;
	return ijkQuatUnitGetMatQdv4t(m_out, dq_in[0], ijkQuatDecodeTranslateQdv(translate, dq_in[1], dq_in[0]));
}

ijk_inl double4m ijkDualQuatGetMatTranslateRemScaleDQdm4(double4x4 m_out, double2x4 const dq_in)
{
	double3 translate;
	return ijkQuatGetMatQdv4t(m_out, dq_in[0], ijkQuatDecodeTranslateRemScaleQdv(translate, dq_in[1], dq_in[0]));
}

ijk_inl doublev ijkDualQuatTransformScaleVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in)
{
	// ensure scale is applied to rotation part only: 
	//	(1 + Ev') = Q (1 + Ev|Q|^2) !Q / |Q|^2
	//				= (r + Ed)(1 + Ev|Q|^2)(r* - Ed*) / |Q|^2
	//				= (r + Ed)(r* - Ed* + Evr*|Q|^2 - EE(...)) / |Q|^2
	//				= (r + Ed)(r* + E(vr*|Q|^2 - d*)) / |Q|^2
	//				= (rr* + Er(vr*|Q|^2 - d*) + Edr* + EE(...)) / |Q|^2
	//				= (|Q|^2 + E(rvr*|Q|^2 - r(r*t*/2) + trr*/2)) / |Q|^2
	//				= (|Q|^2 + E(rvr*|Q|^2 - r(r*t*/2) + trr*/2)) / |Q|^2
	//				= (|Q|^2 + E(rvr*|Q|^2 + rr*t/2 + trr*/2) / |Q|^2
	//				= (|Q|^2 + E(rvr*|Q|^2 + t|Q|^2) / |Q|^2
	//				= 1 + E(rvr* + t)
	//				= 1 + E(rvr* + 2dr^-1) -> rotate, scale, translate in correct sequence
	//						rvr* + 2dr^-1
	//							= rvr* + 2dr*/|Q|^2	-> [rotate&scale: 24x14+; decode: 21; lenSqDiv: 4; add: 3; total = 38+21+4+3 = 66]
	//							= (rv + 2d/|Q|^2)r*	-> [mul: 12x8+; lenSq: 4*3+; recipMulAdd: 9; mulConj(no real): 12*9+; total = 20+7+9+21 = 57]
	doublekv r = dq_in[0], d = dq_in[1];
	f64 const lenSqInv = (dbl_two / ijkQuatLengthSqQdv(r));
	double4 const tmp_lh = {
		(lenSqInv * d[0] + r[1] * v_in[2] - r[2] * v_in[1] + r[3] * v_in[0]),
		(lenSqInv * d[1] + r[2] * v_in[0] - r[0] * v_in[2] + r[3] * v_in[1]),
		(lenSqInv * d[2] + r[0] * v_in[1] - r[1] * v_in[0] + r[3] * v_in[2]),
		(lenSqInv * d[3] - ijkVecDot3dv(r, v_in)),
	};
	return ijkQuatDecodeTranslateD2Qdv(v_out, tmp_lh, r);
}

ijk_inl doublev ijkDualQuatUnitTransformVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in)
{
	// input is assumed to be normalized, or translation part should be scaled as well
	//	(1 + Ev') = Q (1 + Ev) !Q
	//				= (r + Ed)(1 + Ev)(r* - Ed*)
	//				= (r + Ed)(r* - Ed* + Evr* - EE(...))
	//				= (r + Ed)(r* + E(vr* - d*))
	//				= (rr* + Er(vr* - d*) + Edr* + EE(...))
	//				= (|Q|^2 + E(rvr* - r(r*t*/2) + trr*/2))
	//				= (|Q|^2 + E(rvr* - r(r*t*/2) + trr*/2))
	//				= (|Q|^2 + E(rvr* + rr*t/2 + trr*/2)
	//				= (|Q|^2 + E(rvr* + t|Q|^2)
	//				= |Q|^2 + E(rvr* + t|Q|^2)
	//				= |Q|^2 + E(rvr* + 2dr*) -> rotate, scale, scaled translate
	//							rvr* + 2dr*
	//								= rvr* + 2dr*	-> [rotate&scale: 38; decode: 24; add: 3; total = 38+24+3 = 65]
	//								= (rv + 2d)r*	-> [mul: 20; add&scale: 8; mulConj(no real): 21; total = 20+8+21 = 49]
	doublekv r = dq_in[0], d = dq_in[1];
	double4 const tmp_lh = {
		(dbl_two * d[0] + r[1] * v_in[2] - r[2] * v_in[1] + r[3] * v_in[0]),
		(dbl_two * d[1] + r[2] * v_in[0] - r[0] * v_in[2] + r[3] * v_in[1]),
		(dbl_two * d[2] + r[0] * v_in[1] - r[1] * v_in[0] + r[3] * v_in[2]),
		(dbl_two * d[3] - ijkVecDot3dv(r, v_in)),
	};
	return ijkQuatDecodeTranslateD2Qdv(v_out, tmp_lh, r);
}

ijk_inl doublev ijkDualQuatTransformVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in)
{
	// normalize result to make rigid transform
	//	(1 + Ev') = Q (1 + Ev) !Q / |Q|^2
	//				= (r + Ed)(1 + Ev)(r* - Ed*) / |Q|^2
	//				= (r + Ed)(r* - Ed* + Evr* - EE(...)) / |Q|^2
	//				= (r + Ed)(r* + E(vr* - d*)) / |Q|^2
	//				= (rr* + Er(vr* - d*) + Edr* + EE(...)) / |Q|^2
	//				= (|Q|^2 + E(rvr* - r(r*t*/2) + trr*/2)) / |Q|^2
	//				= (|Q|^2 + E(rvr* - r(r*t*/2) + trr*/2)) / |Q|^2
	//				= (|Q|^2 + E(rvr* + rr*t/2 + trr*/2) / |Q|^2
	//				= (|Q|^2 + E(rvr* + t|Q|^2) / |Q|^2
	//				= 1 + E(rvr*/|Q|^2 + t)
	//				= 1 + E(rvr^-1 + t)
	//				= 1 + E(rvr^-1 + 2dr^-1) -> rotate, translate
	//						rvr^-1 + 2dr^-1
	//							= (rvr* + 2dr*)/|Q|^2	-> [see above: 66; lenSq: 4*3+; div: 4; total = 77]
	//							= (rv + 2d)r*/|Q|^2		-> [see above: 49; lenSq: 12; div: 4; total = 65]
	doublekv r = dq_in[0], d = dq_in[1];
	double4 const tmp_lh = {
		(dbl_two * d[0] + r[1] * v_in[2] - r[2] * v_in[1] + r[3] * v_in[0]),
		(dbl_two * d[1] + r[2] * v_in[0] - r[0] * v_in[2] + r[3] * v_in[1]),
		(dbl_two * d[2] + r[0] * v_in[1] - r[1] * v_in[0] + r[3] * v_in[2]),
		(dbl_two * d[3] - ijkVecDot3dv(r, v_in)),
	};
	return ijkQuatDecodeTranslateRemScaleD2Qdv(v_out, tmp_lh, r);
}

ijk_inl double4m ijkDualQuatLerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u)
{
	ijkQuatLerpQdv(dq_out[0], dq0[0], dq1[0], u);
	ijkQuatLerpQdv(dq_out[1], dq0[1], dq1[1], u);
	return dq_out;
}

ijk_inl double4m ijkDualQuatNlerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u)
{
	ijkDualQuatLerpDQdm(dq_out, dq0, dq1, u);
	return ijkDualQuatNormalizeDQdm(dq_out, dq_out);
}

ijk_inl double4m ijkDualQuatSclerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u)
{
	double2x4 copy;
	double4km dq1b = dq1;
	doublekv r0 = dq0[0], r1 = dq1[0], d0 = dq0[1], d1 = dq1[1];
	f64 dot = ijkVecDot4dv(r0, r1);
	if (dot < dbl_zero)
	{
		dot = -dot;
		r1 = ijkVecNegate4dv(copy[0], r1);
		d1 = ijkVecNegate4dv(copy[1], d1);
	}
	if (dot < dbl_one)
	{
		double2x4 tmp;
		f64 const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkDualQuatAddDQdm(dq_out, ijkDualQuatMulDQdms(dq_out, dq0, s0), ijkDualQuatMulDQdms(tmp, dq1b, s1));
	}
	return ijkDualQuatNlerpDQdm(dq_out, dq0, dq1b, u);
}

ijk_inl double4m ijkDualQuatDerivDQdm(double2x4 dq1_out, double2x4 const dq_in, double3 const linearVelocity, double3 const angularVelocity)
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

	doublekv r = dq_in[0], d = dq_in[1], dr_dt = ijkQuatDerivQdv(dq1_out[0], r, angularVelocity);
	doublev dd_dt = dq1_out[1];
	f64 const lenSqInv = ijkQuatLengthSqInvQdv(r);
	dd_dt[0] = linearVelocity[0] * dbl_half - lenSqInv * (d[0] * dr_dt[3] - d[3] * dr_dt[0] + d[2] * dr_dt[1] - d[1] * dr_dt[2]);
	dd_dt[1] = linearVelocity[1] * dbl_half - lenSqInv * (d[1] * dr_dt[3] - d[3] * dr_dt[1] + d[0] * dr_dt[2] - d[2] * dr_dt[0]);
	dd_dt[2] = linearVelocity[2] * dbl_half - lenSqInv * (d[2] * dr_dt[3] - d[3] * dr_dt[2] + d[1] * dr_dt[0] - d[0] * dr_dt[1]);
	dd_dt[3] = -lenSqInv * ijkVecDot4dv(d, dr_dt);
	ijkQuatMulQdv(dd_dt, dd_dt, r);
	return dq1_out;
}

ijk_inl double4m ijkDualQuatDeriv2DQdm(double2x4 dq2_out, double2x4 const dq_in, double3 const linearVelocity, double3 const linearAcceleration, double3 const angularVelocity, double3 const angularAcceleration)
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
	double3 const hw = {
		(dbl_half * angularVelocity[0]), (dbl_half * angularVelocity[1]), (dbl_half * angularVelocity[2])
	};
	f64 const wLenSq = ijkVecLengthSq3dv(hw);
	doublekv r = dq_in[0], d = dq_in[1];
	doublev d2d_dt2 = dq2_out[1], d2r_dt2 = ijkQuatInitElemsQdv(dq2_out[0],
		(dbl_half * angularAcceleration[0]), (dbl_half * angularAcceleration[1]), (dbl_half * angularAcceleration[2]), -wLenSq);
	double4 ht, hdiff = {
		(dbl_half * linearAcceleration[0] + linearVelocity[1] * hw[2] - linearVelocity[2] * hw[1]),
		(dbl_half * linearAcceleration[1] + linearVelocity[2] * hw[0] - linearVelocity[0] * hw[2]),
		(dbl_half * linearAcceleration[2] + linearVelocity[0] * hw[1] - linearVelocity[1] * hw[0]),
		(-ijkVecDot3dv(linearVelocity, hw))
	};
	ijkQuatDecodeTranslateD2Qdv(ht, d, r);
	ijkQuatMulQdv(d2r_dt2, d2r_dt2, r);
	ijkQuatAddQdv(d2d_dt2, ijkQuatMulQdv(hdiff, hdiff, r), ijkQuatMulVecQdv3q(ht, ht, d2r_dt2));
	return dq2_out;
}


//-----------------------------------------------------------------------------

ijk_inl dquat ijkQuatInitQd()
{
	dquat const q_out = {
		dbl_zero, dbl_zero, dbl_zero, dbl_one
	};
	return q_out;
}

ijk_inl dquat ijkQuatInitZeroQd()
{
	dquat const q_out = {
		dbl_zero, dbl_zero, dbl_zero, dbl_zero
	};
	return q_out;
}

ijk_inl dquat ijkQuatInitElemsQd(double const x, double const y, double const z, double const w)
{
	dquat const q_out = {
		x, y, z, w
	};
	return q_out;
}

ijk_inl dquat ijkQuatInitVecReQd(dvec3 const vec, double const re)
{
	dquat const q_out = {
		vec.x, vec.y, vec.z, re
	};
	return q_out;
}

ijk_inl dquat ijkQuatInitVecProductQd(dvec3 const v_lh, dvec3 const v_rh)
{
	dquat q_out;
	q_out.vec = ijkVecCross3d(v_lh, v_rh),
		q_out.re = -ijkVecDot3d(v_lh, v_rh);
	return q_out;
}

ijk_inl dquat ijkQuatInitVecProductSqrtQd(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const hv = {
		dbl_half * (v_lh.x + v_rh.x),
		dbl_half * (v_lh.y + v_rh.y),
		dbl_half * (v_lh.z + v_rh.z),
	};
	return ijkQuatInitVecProductQd(v_lh, hv);
}

ijk_inl dquat ijkQuatInitVecProductSqrtUnitQd(dvec3 const v_lh, dvec3 const v_rh)
{
	dvec3 const hv = {
		dbl_half * (v_lh.x + v_rh.x),
		dbl_half * (v_lh.y + v_rh.y),
		dbl_half * (v_lh.z + v_rh.z),
	};
	return ijkQuatInitVecProductQd(v_lh, ijkVecNormalize3d(hv));
}

ijk_inl dquat ijkQuatInitMatQd3(dmat3 const m_in)
{
	double t, w, x, y, z;
	double diag = (m_in.m00 + m_in.m11 + m_in.m22);

	double const s2 = ijkVecLength3d(m_in.c0);
	if (diag > dbl_zero)
	{
		diag += s2;
		w = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / w;
		x = t * (m_in.m12 - m_in.m21);
		y = t * (m_in.m20 - m_in.m02);
		z = t * (m_in.m01 - m_in.m10);
	}
	else if (m_in.m00 > m_in.m11 && m_in.m00 > m_in.m22)
	{
		diag = s2 + m_in.m00 - m_in.m11 - m_in.m22;
		x = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / x;
		w = t * (m_in.m12 - m_in.m21);
		y = t * (m_in.m01 + m_in.m10);
		z = t * (m_in.m20 + m_in.m02);
	}
	else if (m_in.m11 > m_in.m22) // && m_in.m11 > m_in.m00
	{
		diag = s2 - m_in.m00 + m_in.m11 - m_in.m22;
		y = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / y;
		w = t * (m_in.m20 - m_in.m02);
		z = t * (m_in.m12 + m_in.m21);
		x = t * (m_in.m01 + m_in.m10);
	}
	else // if (m_in.m22 > m_in.m00 && m_in.m22 > m_in.m11)
	{
		diag = s2 - m_in.m00 - m_in.m11 + m_in.m22;
		z = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / z;
		w = t * (m_in.m01 - m_in.m10);
		x = t * (m_in.m20 + m_in.m02);
		y = t * (m_in.m12 + m_in.m21);
	}
	return ijkQuatInitElemsQd(x, y, z, w);
}

ijk_inl dquat ijkQuatInitMatQd4(dmat4 const m_in)
{
	double t, w, x, y, z;
	double diag = (m_in.m00 + m_in.m11 + m_in.m22);
	double const s2 = ijkVecLength3d(m_in.c0.xyz);
	if (diag > dbl_zero)
	{
		diag += s2;
		w = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / w;
		x = t * (m_in.m12 - m_in.m21);
		y = t * (m_in.m20 - m_in.m02);
		z = t * (m_in.m01 - m_in.m10);
	}
	else if (m_in.m00 > m_in.m11 && m_in.m00 > m_in.m22)
	{
		diag = s2 + m_in.m00 - m_in.m11 - m_in.m22;
		x = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / x;
		w = t * (m_in.m12 - m_in.m21);
		y = t * (m_in.m01 + m_in.m10);
		z = t * (m_in.m20 + m_in.m02);
	}
	else if (m_in.m11 > m_in.m22) // && m_in.m11 > m_in.m00
	{
		diag = s2 - m_in.m00 + m_in.m11 - m_in.m22;
		y = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / y;
		w = t * (m_in.m20 - m_in.m02);
		z = t * (m_in.m12 + m_in.m21);
		x = t * (m_in.m01 + m_in.m10);
	}
	else // if (m_in.m22 > m_in.m00 && m_in.m22 > m_in.m11)
	{
		diag = s2 - m_in.m00 - m_in.m11 + m_in.m22;
		z = dbl_half * ijkSqrt_dbl(diag);
		t = dbl_quarter / z;
		w = t * (m_in.m01 - m_in.m10);
		x = t * (m_in.m20 + m_in.m02);
		y = t * (m_in.m12 + m_in.m21);
	}
	return ijkQuatInitElemsQd(x, y, z, w);
}

ijk_inl dquat ijkQuatCopyQd(dquat const q_in)
{
	return q_in;
}

ijk_inl dquat ijkQuatNegateQd(dquat const q_in)
{
	dquat const q_out = {
		-q_in.x, -q_in.y, -q_in.z, -q_in.w
	};
	return q_out;
}

ijk_inl dquat ijkQuatConjugateQd(dquat const q_in)
{
	dquat const q_out = {
		-q_in.x, -q_in.y, -q_in.z, +q_in.w
	};
	return q_out;
}

ijk_inl dquat ijkQuatConjugateMulQds(dquat const q_in, double const s)
{
	dquat const q_out = {
		-q_in.x * s, -q_in.y * s, -q_in.z * s, +q_in.w * s
	};
	return q_out;
}

ijk_inl dquat ijkQuatNegateConjugateQd(dquat const q_in)
{
	dquat const q_out = {
		+q_in.x, +q_in.y, +q_in.z, -q_in.w
	};
	return q_out;
}

ijk_inl dquat ijkQuatNegateConjugateMulQds(dquat const q_in, double const s)
{
	dquat const q_out = {
		+q_in.x * s, +q_in.y * s, +q_in.z * s, -q_in.w * s
	};
	return q_out;
}

ijk_inl dquat ijkQuatAddQd(dquat const q_lh, dquat const q_rh)
{
	dquat const q_out = {
		(q_lh.x + q_rh.x),
		(q_lh.y + q_rh.y),
		(q_lh.z + q_rh.z),
		(q_lh.w + q_rh.w),
	};
	return q_out;
}

ijk_inl dquat ijkQuatSubQd(dquat const q_lh, dquat const q_rh)
{
	dquat const q_out = {
		(q_lh.x - q_rh.x),
		(q_lh.y - q_rh.y),
		(q_lh.z - q_rh.z),
		(q_lh.w - q_rh.w),
	};
	return q_out;
}

ijk_inl dquat ijkQuatMulQds(dquat const q_lh, double const s_rh)
{
	dquat const q_out = {
		(q_lh.x * s_rh),
		(q_lh.y * s_rh),
		(q_lh.z * s_rh),
		(q_lh.w * s_rh),
	};
	return q_out;
}

ijk_inl dquat ijkQuatDivQds(dquat const q_lh, double const s_rh)
{
	double const s = ijk_recip_dbl(s_rh);
	dquat const q_out = {
		(q_lh.x * s),
		(q_lh.y * s),
		(q_lh.z * s),
		(q_lh.w * s),
	};
	return q_out;
}

ijk_inl dquat ijkQuatDivSafeQds(dquat const q_lh, double const s_rh)
{
	double const s = ijk_recip_safe_dbl(s_rh);
	dquat const q_out = {
		(q_lh.x * s),
		(q_lh.y * s),
		(q_lh.z * s),
		(q_lh.w * s),
	};
	return q_out;
}

ijk_inl double ijkQuatLengthSqQd(dquat const q_in)
{
	return ijkVecLengthSq4dv(q_in.v);
}

ijk_inl double ijkQuatLengthQd(dquat const q_in)
{
	return ijkVecLength4dv(q_in.v);
}

ijk_inl double ijkQuatLengthSqInvQd(dquat const q_in)
{
	return ijkVecLengthSqInv4dv(q_in.v);
}

ijk_inl double ijkQuatLengthInvQd(dquat const q_in)
{
	return ijkVecLengthInv4dv(q_in.v);
}

ijk_inl double ijkQuatLengthSqInvSafeQd(dquat const q_in)
{
	return ijkVecLengthSqInvSafe4dv(q_in.v);
}

ijk_inl double ijkQuatLengthInvSafeQd(dquat const q_in)
{
	return ijkVecLengthInvSafe4dv(q_in.v);
}

ijk_inl dquat ijkQuatNormalizeQd(dquat const q_in)
{
	double const lenInv = ijkQuatLengthInvQd(q_in);
	return ijkQuatMulQds(q_in, lenInv);
}

ijk_inl dquat ijkQuatNormalizeSafeQd(dquat const q_in)
{
	double const lenInv = ijkQuatLengthInvSafeQd(q_in);
	return ijkQuatMulQds(q_in, lenInv);
}

ijk_inl dquat ijkQuatInverseQd(dquat const q_in)
{
	double const s = ijkQuatLengthSqInvQd(q_in);
	dquat const q_out = {
		(-q_in.x * s),
		(-q_in.y * s),
		(-q_in.z * s),
		(q_in.w * s),
	};
	return q_out;
}

ijk_inl dquat ijkQuatInverseSafeQd(dquat const q_in)
{
	double const s = ijkQuatLengthSqInvSafeQd(q_in);
	dquat const q_out = {
		(-q_in.x * s),
		(-q_in.y * s),
		(-q_in.z * s),
		(q_in.w * s),
	};
	return q_out;
}

ijk_inl dquat ijkQuatMulVecQd3(dquat const q_lh, dvec3 const v_rh)
{
	dquat const q_out = {
		(q_lh.y * v_rh.z - q_lh.z * v_rh.y + q_lh.w * v_rh.x),
		(q_lh.z * v_rh.x - q_lh.x * v_rh.z + q_lh.w * v_rh.y),
		(q_lh.x * v_rh.y - q_lh.y * v_rh.x + q_lh.w * v_rh.z),
		(-q_lh.x * v_rh.x - q_lh.y * v_rh.y - q_lh.z * v_rh.z),
	};
	return q_out;
}

ijk_inl dquat ijkQuatMulVecQd3q(dvec3 const v_lh, dquat const q_rh)
{
	dquat const q_out = {
		(v_lh.y * q_rh.z - v_lh.z * q_rh.y + v_lh.x * q_rh.w),
		(v_lh.z * q_rh.x - v_lh.x * q_rh.z + v_lh.y * q_rh.w),
		(v_lh.x * q_rh.y - v_lh.y * q_rh.x + v_lh.z * q_rh.w),
		(-v_lh.x * q_rh.x - v_lh.y * q_rh.y - v_lh.z * q_rh.z),
	};
	return q_out;
}

ijk_inl dquat ijkQuatMulQd(dquat const q_lh, dquat const q_rh)
{
	dquat const q_out = {
		(q_lh.y * q_rh.z - q_lh.z * q_rh.y + q_lh.w * q_rh.x + q_lh.x * q_rh.w),
		(q_lh.z * q_rh.x - q_lh.x * q_rh.z + q_lh.w * q_rh.y + q_lh.y * q_rh.w),
		(q_lh.x * q_rh.y - q_lh.y * q_rh.x + q_lh.w * q_rh.z + q_lh.z * q_rh.w),
		(q_lh.w * q_rh.w - q_lh.x * q_rh.x - q_lh.y * q_rh.y - q_lh.z * q_rh.z),
	};
	return q_out;
}

ijk_inl dquat ijkQuatMulConjQd(dquat const q_lh, dquat const q_rh)
{
	dquat const q_out = {
		(q_rh.y * q_lh.z - q_rh.z * q_lh.y - q_lh.w * q_rh.x + q_lh.x * q_rh.w),
		(q_rh.z * q_lh.x - q_rh.x * q_lh.z - q_lh.w * q_rh.y + q_lh.y * q_rh.w),
		(q_rh.x * q_lh.y - q_rh.y * q_lh.x - q_lh.w * q_rh.z + q_lh.z * q_rh.w),
		(ijkVecDot4dv(q_lh.v, q_rh.v)),
	};
	return q_out;
}

ijk_inl dquat ijkQuatConjMulQd(dquat const q_lh, dquat const q_rh)
{
	dquat const q_out = {
		(q_rh.y * q_lh.z - q_rh.z * q_lh.y - q_rh.w * q_lh.x + q_rh.x * q_lh.w),
		(q_rh.z * q_lh.x - q_rh.x * q_lh.z - q_rh.w * q_lh.y + q_rh.y * q_lh.w),
		(q_rh.x * q_lh.y - q_rh.y * q_lh.x - q_rh.w * q_lh.z + q_rh.z * q_lh.w),
		(ijkVecDot4dv(q_lh.v, q_rh.v)),
	};
	return q_out;
}

ijk_inl dquat ijkQuatDivQd(dquat const q_lh, dquat const q_rh)
{
	return ijkQuatMulQd(q_lh, ijkQuatInverseQd(q_rh));
}

ijk_inl dquat ijkQuatRotateXYZQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(cx * sy * sz + sx * cy * cz),
		(cx * sy * cz - sx * cy * sz),
		(cx * cy * sz + sx * sy * cz),
		(cx * cy * cz - sx * sy * sz),
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateYZXQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(cy * cz * sx + sy * sz * cx),
		(cy * sz * sx + sy * cz * cx),
		(cy * sz * cx - sy * cz * sx),
		(cy * cz * cx - sy * sz * sx),
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateZXYQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(cz * sx * cy - sz * cx * sy),
		(cz * cx * sy + sz * sx * cy),
		(cz * sx * sy + sz * cx * cy),
		(cz * cx * cy - sz * sx * sy),
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateYXZQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(cy * sx * cz + sy * cx * sz),
		(sy * cx * cz - cy * sx * sz),
		(cy * cx * sz - sy * sx * cz),
		(cy * cx * cz + sy * sx * sz),
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateXZYQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(sx * cz * cy - cx * sz * sy),
		(cx * cz * sy - sx * sz * cy),
		(cx * sz * cy + sx * cz * sy),
		(cx * cz * cy + sx * sz * sy),
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateZYXQd(dvec3 const rotateDegXYZ)
{
	f64 cx, sx, cy, sy, cz, sz;
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.x * dbl_half, &sx, &cx);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.y * dbl_half, &sy, &cy);
	ijkTrigSinCos_deg_dbl(rotateDegXYZ.z * dbl_half, &sz, &cz);
	dquat const q_out = {
		(cz * cy * sx - sz * sy * cx),
		(cz * sy * cx + sz * cy * sx),
		(sz * cy * cx - cz * sy * sx),
		(cz * cy * cx + sz * sy * sx),
	};
	return q_out;
}

ijk_inl dquat ijkQuatGetRotateXYZQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	double s = dbl_two * (z * x + y * w), c;
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * z - y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * x - y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateYZXQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	double s = dbl_two * (x * y + z * w), c;
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * x - z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * y - z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateZXYQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	double s = dbl_two * (y * z + x * w), c;
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * y - x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * z - x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateYXZQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwxx = w * w - x * x, zzyy = z * z - y * y;
	double s = dbl_two * (w * x - y * z), c;
	rotateDegXYZ_out->x = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * y + x * z);
	c = wwxx + zzyy;
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * z + x * y);
	c = wwxx - zzyy;
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateXZYQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwzz = w * w - z * z, yyxx = y * y - x * x;
	double s = dbl_two * (w * z - x * y), c;
	rotateDegXYZ_out->z = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * x + z * y);
	c = wwzz + yyxx;
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * y + z * x);
	c = wwzz - yyxx;
	rotateDegXYZ_out->y = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateZYXQd(dquat const q_in, dvec3* const rotateDegXYZ_out)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		wwyy = w * w - y * y, xxzz = x * x - z * z;
	double s = dbl_two * (w * y - z * x), c;
	rotateDegXYZ_out->y = ijkTrigAsin_deg_dbl(s);
	s = dbl_two * (w * z + y * x);
	c = wwyy + xxzz;
	rotateDegXYZ_out->z = ijkTrigAtan2_deg_dbl(s, c);
	s = dbl_two * (w * x + y * z);
	c = wwyy - xxzz;
	rotateDegXYZ_out->x = ijkTrigAtan2_deg_dbl(s, c);
	return q_in;
}

ijk_inl dquat ijkQuatRotateQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatRotateXYZQd(rotateDegXYZ);
	case ijkRotationYZX:
		return ijkQuatRotateYZXQd(rotateDegXYZ);
	case ijkRotationZXY:
		return ijkQuatRotateZXYQd(rotateDegXYZ);
	case ijkRotationYXZ:
		return ijkQuatRotateYXZQd(rotateDegXYZ);
	case ijkRotationXZY:
		return ijkQuatRotateXZYQd(rotateDegXYZ);
	case ijkRotationZYX:
		return ijkQuatRotateZYXQd(rotateDegXYZ);
	}
	return ijkQuatInitQd();
}

ijk_inl dquat ijkQuatAxisAngleQd(dvec3 const axis_unit, double const angle_degrees)
{
	f64 s, c, x = ijkTrigSinCos_deg_dbl(angle_degrees * dbl_half, &s, &c);
	dquat const q_out = {
		(axis_unit.x * s),
		(axis_unit.y * s),
		(axis_unit.z * s),
		(c),
	};
	return q_out;
}

ijk_inl dquat ijkQuatScaleQd(double const scale_unif)
{
	dquat const q_out = {
		dbl_zero, dbl_zero, dbl_zero, ijkSqrt_dbl(scale_unif)
	};
	return q_out;
}

ijk_inl dquat ijkQuatRotateScaleQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif)
{
	double const len = ijkSqrt_dbl(scale_unif);
	return ijkQuatMulQds(ijkQuatRotateQd(order, rotateDegXYZ), len);
}

ijk_inl dquat ijkQuatAxisAngleScaleQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif)
{
	f64 s, c, x = ijkTrigSinCos_deg_dbl(angle_degrees * dbl_half, &s, &c);
	double const len = ijkSqrt_dbl(scale_unif), slen = s * len;
	dquat const q_out = {
		(axis_unit.x * slen),
		(axis_unit.y * slen),
		(axis_unit.z * slen),
		(c * len),
	};
	return q_out;
}

ijk_inl dquat ijkQuatGetRotateQd(dquat const q_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out)
{
	switch (order)
	{
	case ijkRotationXYZ:
		return ijkQuatGetRotateXYZQd(q_in, rotateDegXYZ_out);
	case ijkRotationYZX:
		return ijkQuatGetRotateYZXQd(q_in, rotateDegXYZ_out);
	case ijkRotationZXY:
		return ijkQuatGetRotateZXYQd(q_in, rotateDegXYZ_out);
	case ijkRotationYXZ:
		return ijkQuatGetRotateYXZQd(q_in, rotateDegXYZ_out);
	case ijkRotationXZY:
		return ijkQuatGetRotateXZYQd(q_in, rotateDegXYZ_out);
	case ijkRotationZYX:
		return ijkQuatGetRotateZYXQd(q_in, rotateDegXYZ_out);
	}
	return q_in;
}

ijk_inl dquat ijkQuatGetAxisAngleQd(dquat const q_in, dvec3* const axis_unit_out, double* const angle_degrees_out)
{
	double const s = ijkVecLength3d(q_in.vec);
	*axis_unit_out = ijkVecDivSafe3ds(q_in.vec, s);
	*angle_degrees_out = dbl_two * ijkTrigAtan2_deg_dbl(s, q_in.w);
	return q_in;
}

ijk_inl dquat ijkQuatGetScaleQd(dquat const q_in, double* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQd(q_in);
	return q_in;
}

ijk_inl dquat ijkQuatGetRotateScaleQd(dquat const q_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out)
{
	*scale_unif_out = ijkQuatLengthSqQd(q_in);
	return ijkQuatGetRotateQd(q_in, order, rotateDegXYZ_out);
}

ijk_inl dquat ijkQuatGetAxisAngleScaleQd(dquat const q_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out)
{
	double s = ijkVecLengthSq3d(q_in.vec);
	*scale_unif_out = ijkSqrt_dbl(s + q_in.w * q_in.w);
	s = ijkSqrt_dbl(s);
	*axis_unit_out = ijkVecDivSafe3ds(q_in.vec, s);
	*angle_degrees_out = dbl_two * ijkTrigAtan2_deg_dbl(s, q_in.w);
	return q_in;
}

ijk_inl dmat3 ijkQuatGetMatQd3(dquat const q_in)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	dmat3 const m_out = {
		(ww + xx - yy - zz),
		(dbl_two * (xy + zw)),
		(dbl_two * (zx - yw)),
		(dbl_two * (xy - zw)),
		(wwxx + yyzz),
		(dbl_two * (yz + xw)),
		(dbl_two * (zx + yw)),
		(dbl_two * (yz - xw)),
		(wwxx - yyzz),
	};
	return m_out;
}

ijk_inl dmat3 ijkQuatUnitGetMatQd3(dquat const q_in)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	dmat3 const m_out = {
		(dbl_one - (yy2 + zz2)),
		(xy2 + zw2),
		(zx2 - yw2),
		(xy2 - zw2),
		(dbl_one - (zz2 + xx2)),
		(yz2 + xw2),
		(zx2 + yw2),
		(yz2 - xw2),
		(dbl_one - (xx2 + yy2)),
	};
	return m_out;
}

ijk_inl dmat4 ijkQuatGetMatQd4(dquat const q_in)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	dmat4 const m_out = {
		(ww + xx - yy - zz),
		(dbl_two * (xy + zw)),
		(dbl_two * (zx - yw)),
		dbl_zero,
		(dbl_two * (xy - zw)),
		(wwxx + yyzz),
		(dbl_two * (yz + xw)),
		dbl_zero,
		(dbl_two * (zx + yw)),
		(dbl_two * (yz - xw)),
		(wwxx - yyzz),
		dbl_zero,
		dbl_zero,
		dbl_zero,
		dbl_zero,
		dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkQuatUnitGetMatQd4(dquat const q_in)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	dmat4 const m_out = {
		(dbl_one - (yy2 + zz2)),
		(xy2 + zw2),
		(zx2 - yw2),
		dbl_zero,
		(xy2 - zw2),
		(dbl_one - (zz2 + xx2)),
		(yz2 + xw2),
		dbl_zero,
		(zx2 + yw2),
		(yz2 - xw2),
		(dbl_one - (xx2 + yy2)),
		dbl_zero,
		dbl_zero,
		dbl_zero,
		dbl_zero,
		dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkQuatGetMatQd4t(dquat const q_in, dvec3 const translate)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		ww = w * w, xx = x * x, yy = y * y, zz = z * z, wwxx = ww - xx, yyzz = yy - zz,
		xy = x * y, yz = y * z, zx = z * x, xw = x * w, yw = y * w, zw = z * w;
	dmat4 const m_out = {
		(ww + xx - yy - zz),
		(dbl_two * (xy + zw)),
		(dbl_two * (zx - yw)),
		dbl_zero,
		(dbl_two * (xy - zw)),
		(wwxx + yyzz),
		(dbl_two * (yz + xw)),
		dbl_zero,
		(dbl_two * (zx + yw)),
		(dbl_two * (yz - xw)),
		(wwxx - yyzz),
		dbl_zero,
		translate.x,
		translate.y,
		translate.z,
		dbl_one,
	};
	return m_out;
}

ijk_inl dmat4 ijkQuatUnitGetMatQd4t(dquat const q_in, dvec3 const translate)
{
	double const x = q_in.x, y = q_in.y, z = q_in.z, w = q_in.w,
		x2 = x * dbl_two, y2 = y * dbl_two, z2 = z * dbl_two,
		xx2 = x2 * x, yy2 = y2 * y, zz2 = z2 * z,
		xy2 = x2 * y, yz2 = y2 * z, zx2 = z2 * x, xw2 = x2 * w, yw2 = y2 * w, zw2 = z2 * w;
	dmat4 const m_out = {
		(dbl_one - (yy2 + zz2)),
		(xy2 + zw2),
		(zx2 - yw2),
		dbl_zero,
		(xy2 - zw2),
		(dbl_one - (zz2 + xx2)),
		(yz2 + xw2),
		dbl_zero,
		(zx2 + yw2),
		(yz2 - xw2),
		(dbl_one - (xx2 + yy2)),
		dbl_zero,
		translate.x,
		translate.y,
		translate.z,
		dbl_one,
	};
	return m_out;
}

ijk_inl dvec3 ijkQuatRotateScaleVecQd3(dquat const q_in, dvec3 const v_in)
{
	double const vx = v_in.x, vy = v_in.y, vz = v_in.z, qx = q_in.x, qy = q_in.y, qz = q_in.z, qw = q_in.w,
		ww = qw * qw - ijkVecLengthSq3d(q_in.vec), w2 = dbl_two * qw, d = dbl_two * ijkVecDot3d(q_in.vec, v_in);	// 9*, 5+-
	dvec3 const v_out = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d),	// 5*, 3+-
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d),	// 5*, 3+-
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d),	// 5*, 3+-
	};
	return v_out;
}

ijk_inl dvec3 ijkQuatUnitRotateVecQd3(dquat const q_in, dvec3 const v_in)
{
	double const vx = v_in.x, vy = v_in.y, vz = v_in.z, qx = q_in.x, qy = q_in.y, qz = q_in.z, qw = q_in.w;
	dvec3 const v = {
		(qy * vz - qz * vy + qw * vx),	// 3*, 2+-
		(qz * vx - qx * vz + qw * vy),	// 3*, 2+-
		(qx * vy - qy * vx + qw * vz),	// 3*, 2+-
	};
	dvec3 const v_out = {
		(vx + dbl_two * (qy * v.z - qz * v.y)),	// 3*, 2+-
		(vy + dbl_two * (qz * v.x - qx * v.z)),	// 3*, 2+-
		(vz + dbl_two * (qx * v.y - qy * v.x)),	// 3*, 2+-
	};
	return v_out;
}

ijk_inl dvec3 ijkQuatRotateVecQd3(dquat const q_in, dvec3 const v_in)
{
	double const vx = v_in.x, vy = v_in.y, vz = v_in.z, qx = q_in.x, qy = q_in.y, qz = q_in.z, qw = q_in.w,
		ww = qw * qw - ijkVecLengthSq3d(q_in.vec), w2 = dbl_two * qw, d = dbl_two * ijkVecDot3d(q_in.vec, v_in);
	double const nrm = dbl_one / (w2 * qw - ww);
	dvec3 const v_out = {
		(vx * ww + w2 * (qy * vz - qz * vy) + qx * d) * nrm,
		(vy * ww + w2 * (qz * vx - qx * vz) + qy * d) * nrm,
		(vz * ww + w2 * (qx * vy - qy * vx) + qz * d) * nrm,
	};
	return v_out;
}

ijk_inl dquat ijkQuatReflectScaleQd(dquat const q_in, dvec3 const v_in)
{
	double const d = dbl_two * ijkVecDot3d(q_in.vec, v_in), lenSq = ijkQuatLengthSqQd(q_in);
	dquat const q_out = {
		(v_in.x * lenSq - d * q_in.x),
		(v_in.y * lenSq - d * q_in.y),
		(v_in.z * lenSq - d * q_in.z),
		(-d * q_in.w),
	};
	return q_out;
}

ijk_inl dquat ijkQuatUnitReflectQd(dquat const q_in, dvec3 const v_in)
{
	double const d = dbl_two * ijkVecDot3d(q_in.vec, v_in);
	dquat const q_out = {
		(v_in.x - d * q_in.x),
		(v_in.y - d * q_in.y),
		(v_in.z - d * q_in.z),
		(-d * q_in.w),
	};
	return q_out;
}

ijk_inl dquat ijkQuatReflectQd(dquat const q_in, dvec3 const v_in)
{
	double const d = dbl_two * ijkVecDot3d(q_in.vec, v_in), lenSqInv = d * ijkQuatLengthSqInvQd(q_in);
	dquat const q_out = {
		(v_in.x - lenSqInv * q_in.x),
		(v_in.y - lenSqInv * q_in.y),
		(v_in.z - lenSqInv * q_in.z),
		(-lenSqInv * q_in.w),
	};
	return q_out;
}

ijk_inl dquat ijkQuatExpQd(dvec3 const v_in)
{
	double const len = ijkVecLength3d(v_in);
	if (len > dbl_zero)
	{
		f64 s, c, x = ijkTrigSinCos_rad_dbl(len, &s, &c);
		double const slen = s / len;
		dquat const q_out = {
			(v_in.x * slen),
			(v_in.y * slen),
			(v_in.z * slen),
			c,
		};
		return q_out;
	}
	return ijkQuatInitQd();
}

ijk_inl dquat ijkQuatLnQd(dquat const q_in)
{
	// ln(q) = ln(|q|unit(q))
	//		= ln|q| + ln(w + v)
	//		= ln|q| + ln(cos(|v|) + sin(|v|)unit(v))
	//		= ln|q| + |v|unit(v)
	//		= ln|q| + acos(w/|q|)v/|v|
	double const lenv = ijkVecLengthSq3d(q_in.vec);
	if (lenv > dbl_zero)
	{
		double const lenq = ijkSqrt_dbl(lenv + q_in.w * q_in.w),
			lenv2 = ijkTrigAcos_rad_dbl(q_in.w / lenq) * ijkSqrtInv_dbl(lenv);
		dquat const q_out = {
			(q_in.x * lenv2),
			(q_in.y * lenv2),
			(q_in.z * lenv2),
			ijkTrigLn1p_dbl(lenq - dbl_one),
		};
		return q_out;
	}
	else
	{
		dquat const q_out = {
			dbl_zero, dbl_zero, dbl_zero, ijkTrigLn1p_dbl(q_in.w - dbl_one)
		};
		return q_out;
	}
}

ijk_inl dquat ijkQuatPowQd(dquat const q_in, double const u)
{
	// q^u = |q|^u unit(q)^u
	//		= |q|^u (cos(a) + sin(a)n)^u
	//		= |q|^u (cos(ua) + sin(ua)n)
	double const lenv = ijkVecLengthSq3d(q_in.vec);
	if (lenv > dbl_zero)
	{
		double const lenq = ijkTrigPow_dbl((lenv + q_in.w * q_in.w), u * dbl_half),
			lenv2 = ijkSqrtInv_dbl(lenv), lenq2 = lenq / lenv2;
		f64 s, c, a = u * ijkTrigAtan2_deg_dbl(lenv2, q_in.w),
			x = ijkTrigSinCos_deg_dbl(a, &s, &c);
		dquat const q_out = {
			(q_in.x * lenq2),
			(q_in.y * lenq2),
			(q_in.z * lenq2),
			(c * lenq),
		};
		return q_out;
	}
	else
	{
		dquat const q_out = {
			dbl_zero, dbl_zero, dbl_zero, ijkTrigPow_dbl(q_in.w, u)
		};
		return q_out;
	}
}

ijk_inl dquat ijkQuatSqrtQd(dquat const q_in)
{
	double const lenv = ijkVecLengthSq3d(q_in.vec);
	if (lenv > dbl_zero)
	{
		double const lenq = ijkSqrt_dbl(lenv + q_in.w * q_in.w),
			lenv2 = ijkSqrt_dbl(dbl_half * (lenq - q_in.w) / lenv);
		dquat const q_out = {
			(q_in.x * lenv2),
			(q_in.y * lenv2),
			(q_in.z * lenv2),
			ijkSqrt_dbl(dbl_half * (lenq + q_in.w)),
		};
		return q_out;
	}
	else
	{
		dquat const q_out = {
			dbl_zero, dbl_zero, dbl_zero, ijkSqrt_dbl(q_in.w)
		};
		return q_out;
	}
}

ijk_inl dquat ijkQuatLerpQd(dquat const q0, dquat const q1, double const u)
{
	dquat q_out;
	q_out.vec = ijkVecLerp3d(q0.vec, q1.vec, u);
	q_out.re = ijkInterpLinear_dbl(q0.re, q1.re, u);
	return q_out;
}

ijk_inl dquat ijkQuatNlerpQd(dquat const q0, dquat const q1, double const u)
{
	return ijkQuatNormalizeQd(ijkQuatLerpQd(q0, q1, u));
}

ijk_inl dquat ijkQuatSlerpQd(dquat const q0, dquat const q1, double const u)
{
	dquat q1b = q1;
	double dot = ijkVecDot4dv(q0.v, q1.v);
	if (dot < dbl_zero)
	{
		dot = -dot;
		q1b = ijkQuatNegateQd(q1b);
	}
	if (dot < dbl_one)
	{
		double const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkQuatAddQd(ijkQuatMulQds(q0, s0), ijkQuatMulQds(q1b, s1));
	}
	return ijkQuatNlerpQd(q0, q1b, u);
}

ijk_inl dquat ijkQuatDerivQd(dquat const q_in, dvec3 const angularVelocity)
{
	dvec3 const hw = {
		(dbl_half * angularVelocity.x), (dbl_half * angularVelocity.y), (dbl_half * angularVelocity.z)
	};
	return ijkQuatMulVecQd3q(hw, q_in);
}

ijk_inl dquat ijkQuatDeriv2Qd(dquat const q_in, dvec3 const angularVelocity, dvec3 const angularAcceleration)
{
	double const angularSpeedSq = ijkVecLengthSq3d(angularVelocity);
	dquat const q_lh = {
		(dbl_half * angularAcceleration.x), (dbl_half * angularAcceleration.y), (dbl_half * angularAcceleration.z), (-dbl_quarter * angularSpeedSq)
	};
	return ijkQuatMulQd(q_lh, q_in);
}

ijk_inl dquat ijkQuatEncodeTranslateQd(dvec3 const translate_in, dquat const q_encode)
{
	return ijkQuatDerivQd(q_encode, translate_in);
}

ijk_inl dquat ijkQuatEncodeTranslateX2Qd(dvec3 const translate_in, dquat const q_encode)
{
	return ijkQuatMulVecQd3q(translate_in, q_encode);
}

ijk_inl dvec3 ijkQuatDecodeTranslateQd(dquat const qt_in, dquat const q_decode)
{
	double const qx = q_decode.x, qy = q_decode.y, qz = q_decode.z, qw = q_decode.w,
		qtx = qt_in.x, qty = qt_in.y, qtz = qt_in.z, qtw = qt_in.w;
	dvec3 const translate_out = {
		(dbl_two * (qtx * qw - qtw * qx + qy * qtz - qz * qty)),
		(dbl_two * (qty * qw - qtw * qy + qz * qtx - qx * qtz)),
		(dbl_two * (qtz * qw - qtw * qz + qx * qty - qy * qtx)),
	};
	return translate_out;
}

ijk_inl dvec3 ijkQuatDecodeTranslateD2Qds(dquat const qt_in, dquat const q_decode, double const s)
{
	double const qx = q_decode.x, qy = q_decode.y, qz = q_decode.z, qw = q_decode.w,
		qtx = qt_in.x, qty = qt_in.y, qtz = qt_in.z, qtw = qt_in.w;
	dvec3 const translate_out = {
		(s * (qtx * qw - qtw * qx + qy * qtz - qz * qty)),
		(s * (qty * qw - qtw * qy + qz * qtx - qx * qtz)),
		(s * (qtz * qw - qtw * qz + qx * qty - qy * qtx)),
	};
	return translate_out;
}

ijk_inl dvec3 ijkQuatDecodeTranslateD2Qd(dquat const qt_in, dquat const q_decode)
{
	// q' = tq/2
	// t/2 = q'q*
	double const qx = q_decode.x, qy = q_decode.y, qz = q_decode.z, qw = q_decode.w,
		qtx = qt_in.x, qty = qt_in.y, qtz = qt_in.z, qtw = qt_in.w;
	dvec3 const translate_out = {
		(qtx * qw - qtw * qx + qy * qtz - qz * qty),
		(qty * qw - qtw * qy + qz * qtx - qx * qtz),
		(qtz * qw - qtw * qz + qx * qty - qy * qtx),
	};
	return translate_out;
}

ijk_inl dvec3 ijkQuatDecodeTranslateRemScaleQd(dquat const qt_in, dquat const q_decode)
{
	// q' = tq/2
	// t = 2q'q^-1 = 2q'q*/|q|^2
	double const qx = q_decode.x, qy = q_decode.y, qz = q_decode.z, qw = q_decode.w,
		qtx = qt_in.x, qty = qt_in.y, qtz = qt_in.z, qtw = qt_in.w,
		s = dbl_two / ijkQuatLengthSqQd(q_decode);
	dvec3 const translate_out = {
		(s * (qtx * qw - qtw * qx + qy * qtz - qz * qty)),
		(s * (qty * qw - qtw * qy + qz * qtx - qx * qtz)),
		(s * (qtz * qw - qtw * qz + qx * qty - qy * qtx)),
	};
	return translate_out;
}

ijk_inl dvec3 ijkQuatDecodeTranslateRemScaleD2Qd(dquat const qt_in, dquat const q_decode)
{
	// q' = tq/2
	// t/2 = q'q^-1 = q'q*/|q|^2
	double const qx = q_decode.x, qy = q_decode.y, qz = q_decode.z, qw = q_decode.w,
		qtx = qt_in.x, qty = qt_in.y, qtz = qt_in.z, qtw = qt_in.w,
		s = dbl_one / ijkQuatLengthSqQd(q_decode);
	dvec3 const translate_out = {
		(s * (qtx * qw - qtw * qx + qy * qtz - qz * qty)),
		(s * (qty * qw - qtw * qy + qz * qtx - qx * qtz)),
		(s * (qtz * qw - qtw * qz + qx * qty - qy * qtx)),
	};
	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl ddualquat ijkDualQuatInitDQd()
{
	ddualquat dq_out;
	dq_out.re = ijkQuatInitQd();
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatInitDualReDQd(dquat const re, dquat const dual)
{
	ddualquat dq_out;
	dq_out.re = re;
	dq_out.dual = dual;
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatInitMatDQd3(dmat3 const m_in)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatInitMatQd3(m_in);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatInitMatDQd4(dmat4 const m_in)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatInitMatQd4(m_in);
	dq_out.dual = ijkQuatEncodeTranslateQd(m_in.c3.xyz, dq_out.re);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatCopyDQd(ddualquat const dq_in)
{
	ddualquat dq_out;
	dq_out.re = dq_in.re;
	dq_out.dual = dq_in.dual;
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatNegateDQd(ddualquat const dq_in)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatNegateQd(dq_in.re);
	dq_out.dual = ijkQuatNegateQd(dq_in.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatConjugateDQd(ddualquat const dq_in)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatConjugateQd(dq_in.re);
	dq_out.dual = ijkQuatConjugateQd(dq_in.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatNegateDualDQd(ddualquat const dq_in)
{
	ddualquat dq_out;
	dq_out.re = dq_in.re;
	dq_out.dual = ijkQuatNegateQd(dq_in.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatConjugateDualDQd(ddualquat const dq_in)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatConjugateQd(dq_in.re);
	dq_out.dual = ijkQuatNegateConjugateQd(dq_in.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatAddDQd(ddualquat const dq_lh, ddualquat const dq_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatAddQd(dq_lh.re, dq_rh.re);
	dq_out.dual = ijkQuatAddQd(dq_lh.dual, dq_rh.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatSubDQd(ddualquat const dq_lh, ddualquat const dq_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatSubQd(dq_lh.re, dq_rh.re);
	dq_out.dual = ijkQuatSubQd(dq_lh.dual, dq_rh.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatMulDQds(ddualquat const dq_lh, double const s_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatMulQds(dq_lh.re, s_rh);
	dq_out.dual = ijkQuatMulQds(dq_lh.dual, s_rh);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatDivDQds(ddualquat const dq_lh, double const s_rh)
{
	double const s = ijk_recip_dbl(s_rh);
	return ijkDualQuatMulDQds(dq_lh, s);
}

ijk_inl ddualquat ijkDualQuatDivSafeDQds(ddualquat const dq_lh, double const s_rh)
{
	double const s = ijk_recip_safe_dbl(s_rh);
	return ijkDualQuatMulDQds(dq_lh, s);
}

ijk_inl double ijkDualQuatLengthSqDQd(ddualquat const dq_in)
{
	return ijkQuatLengthSqQd(dq_in.re);
}

ijk_inl double ijkDualQuatLengthDQd(ddualquat const dq_in)
{
	return ijkQuatLengthQd(dq_in.re);
}

ijk_inl double ijkDualQuatLengthSqInvDQd(ddualquat const dq_in)
{
	return ijkQuatLengthSqInvQd(dq_in.re);
}

ijk_inl double ijkDualQuatLengthInvDQd(ddualquat const dq_in)
{
	return ijkQuatLengthInvQd(dq_in.re);
}

ijk_inl double ijkDualQuatLengthSqInvSafeDQd(ddualquat const dq_in)
{
	return ijkQuatLengthSqInvSafeQd(dq_in.re);
}

ijk_inl double ijkDualQuatLengthInvSafeDQd(ddualquat const dq_in)
{
	return ijkQuatLengthInvSafeQd(dq_in.re);
}

ijk_inl ddualquat ijkDualQuatNormalizeDQd(ddualquat const dq_in)
{
	double const lenInv = ijkQuatLengthInvQd(dq_in.re);
	ddualquat dq_out;
	dq_out.re = ijkQuatMulQds(dq_in.re, lenInv);
	dq_out.dual = ijkQuatMulQds(dq_in.dual, lenInv);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatNormalizeSafeDQd(ddualquat const dq_in)
{
	double const lenInv = ijkQuatLengthInvSafeQd(dq_in.re);
	ddualquat dq_out;
	dq_out.re = ijkQuatMulQds(dq_in.re, lenInv);
	dq_out.dual = ijkQuatMulQds(dq_in.dual, lenInv);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatInverseDQd(ddualquat const dq_in)
{
	// conjugate of each part divided by real part's length
	double const lenInv = ijkQuatLengthInvQd(dq_in.re);
	ddualquat dq_out;
	dq_out.re = ijkQuatConjugateMulQds(dq_in.re, lenInv);
	dq_out.dual = ijkQuatConjugateMulQds(dq_in.dual, lenInv);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatInverseSafeDQd(ddualquat const dq_in)
{
	double const lenInv = ijkQuatLengthInvSafeQd(dq_in.re);
	ddualquat dq_out;
	dq_out.re = ijkQuatConjugateMulQds(dq_in.re, lenInv);
	dq_out.dual = ijkQuatConjugateMulQds(dq_in.dual, lenInv);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatMulVecDQd3(ddualquat const dq_lh, dvec3 const v_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatMulVecQd3(dq_lh.re, v_rh);
	dq_out.dual = ijkQuatMulVecQd3(dq_lh.dual, v_rh);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatMulVecDQd3q(dvec3 const v_lh, ddualquat const dq_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatMulVecQd3q(v_lh, dq_rh.re);
	dq_out.dual = ijkQuatMulVecQd3q(v_lh, dq_rh.dual);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatMulDQd(ddualquat const dq_lh, ddualquat const dq_rh)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatMulQd(dq_lh.re, dq_rh.re);
	dq_out.dual = ijkQuatAddQd(ijkQuatMulQd(dq_lh.re, dq_rh.dual), ijkQuatMulQd(dq_lh.dual, dq_rh.re));
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatMulScaleDQd(ddualquat const dq_lh, ddualquat const dq_rh)
{
	double const lenSq = ijkQuatLengthSqQd(dq_lh.re);
	ddualquat dq_out;
	dq_out.re = ijkQuatMulQd(dq_lh.re, dq_rh.re);
	dq_out.dual = ijkQuatAddQd(ijkQuatMulQds(ijkQuatMulQd(dq_lh.re, dq_rh.dual), lenSq), ijkQuatMulQd(dq_lh.dual, dq_rh.re));
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatDivDQd(ddualquat const dq_lh, ddualquat const dq_rh)
{
	return ijkDualQuatMulDQd(dq_lh, ijkDualQuatInverseDQd(dq_rh));
}

ijk_inl ddualquat ijkDualQuatRotateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatRotateQd(order, rotateDegXYZ);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatAxisAngleDQd(dvec3 const axis_unit, double const angle_degrees)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatAxisAngleQd(axis_unit, angle_degrees);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatScaleDQd(double const scale_unif)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatScaleQd(scale_unif);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatRotateScaleDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatRotateScaleQd(order, rotateDegXYZ, scale_unif);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatAxisAngleScaleDQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatAxisAngleScaleQd(axis_unit, angle_degrees, scale_unif);
	dq_out.dual = ijkQuatInitZeroQd();
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatTranslateDQd(dvec3 const translate)
{
	double const s = dbl_half;
	ddualquat dq_out;
	dq_out.re = ijkQuatInitQd();
	dq_out.dual = ijkQuatInitElemsQd((translate.x * s), (translate.y * s), (translate.z * s), dbl_zero);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatRotateTranslateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const translate)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatRotateQd(order, rotateDegXYZ);
	dq_out.dual = ijkQuatEncodeTranslateQd(translate, dq_out.re);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatAxisAngleTranslateDQd(dvec3 const axis_unit, double const angle_degrees, dvec3 const translate)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatAxisAngleQd(axis_unit, angle_degrees);
	dq_out.dual = ijkQuatEncodeTranslateQd(translate, dq_out.re);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatScaleTranslateDQd(double const scale_unif, dvec3 const translate)
{
	double s = dbl_half;
	ddualquat dq_out;
	dq_out.re = ijkQuatScaleQd(scale_unif);
	s *= dq_out.re.w;
	dq_out.dual = ijkQuatInitElemsQd((translate.x * s), (translate.y * s), (translate.z * s), dbl_zero);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatRotateScaleTranslateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif, dvec3 const translate)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatRotateScaleQd(order, rotateDegXYZ, scale_unif);
	dq_out.dual = ijkQuatEncodeTranslateQd(translate, dq_out.re);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatAxisAngleScaleTranslateDQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif, dvec3 const translate)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatAxisAngleScaleQd(axis_unit, angle_degrees, scale_unif);
	dq_out.dual = ijkQuatEncodeTranslateQd(translate, dq_out.re);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatGetRotateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out)
{
	ijkQuatGetRotateQd(dq_in.re, order, rotateDegXYZ_out);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out)
{
	ijkQuatGetAxisAngleQd(dq_in.re, axis_unit_out, angle_degrees_out);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetScaleDQd(ddualquat const dq_in, double* const scale_unif_out)
{
	ijkQuatGetScaleQd(dq_in.re, scale_unif_out);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetRotateScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out)
{
	ijkQuatGetRotateScaleQd(dq_in.re, order, rotateDegXYZ_out, scale_unif_out);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out)
{
	ijkQuatGetAxisAngleScaleQd(dq_in.re, axis_unit_out, angle_degrees_out, scale_unif_out);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetTranslateDQd(ddualquat const dq_in, dvec3* const translate_out)
{
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetRotateTranslateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out)
{
	ijkQuatGetRotateQd(dq_in.re, order, rotateDegXYZ_out);
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleTranslateDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out)
{
	ijkQuatGetAxisAngleQd(dq_in.re, axis_unit_out, angle_degrees_out);
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetScaleTranslateDQd(ddualquat const dq_in, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetScaleQd(dq_in.re, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetRotateScaleTranslateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetRotateScaleQd(dq_in.re, order, rotateDegXYZ_out, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleScaleTranslateDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetAxisAngleScaleQd(dq_in.re, axis_unit_out, angle_degrees_out, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const translate_out)
{
	*translate_out = ijkQuatDecodeTranslateRemScaleQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetRotateTranslateRemScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out)
{
	ijkQuatGetRotateQd(dq_in.re, order, rotateDegXYZ_out);
	*translate_out = ijkQuatDecodeTranslateRemScaleQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out)
{
	ijkQuatGetAxisAngleQd(dq_in.re, axis_unit_out, angle_degrees_out);
	*translate_out = ijkQuatDecodeTranslateRemScaleQd(dq_in.dual, dq_in.re);
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetScaleTranslateRemScaleDQd(ddualquat const dq_in, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetScaleQd(dq_in.re, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateD2Qds(dq_in.dual, dq_in.re, (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetRotateScaleTranslateRemScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetRotateScaleQd(dq_in.re, order, rotateDegXYZ_out, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateD2Qds(dq_in.dual, dq_in.re, (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out, dvec3* const translate_out)
{
	ijkQuatGetAxisAngleScaleQd(dq_in.re, axis_unit_out, angle_degrees_out, scale_unif_out);
	*translate_out = ijkQuatDecodeTranslateD2Qds(dq_in.dual, dq_in.re, (dbl_two / *scale_unif_out));
	return dq_in;
}

ijk_inl ddualquat ijkDualQuatGetScrewParamsDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out, dvec3* const momentArm_out, double* const screwDisplace_out)
{
	dquat const r = dq_in.re, d = dq_in.dual;
	double const lenSq = ijkQuatLengthSqQd(r), lenSqInv2 = dbl_two / lenSq;
	double const c = r.w, s = ijkSqrt_dbl(lenSq - c * c);
	double const angle = ijkTrigAtan2_deg_dbl(s, c), cot = c / s;
	double distance;

	translate_out->x = lenSqInv2 * (d.x * r.w + d.z * r.y - d.y * r.z - d.w * r.x);
	translate_out->y = lenSqInv2 * (d.y * r.w + d.x * r.z - d.z * r.x - d.w * r.y);
	translate_out->z = lenSqInv2 * (d.z * r.w + d.y * r.x - d.x * r.y - d.w * r.z);

	axis_unit_out->x = r.x * s;
	axis_unit_out->y = r.y * s;
	axis_unit_out->z = r.z * s;

	*angle_degrees_out = dbl_two * angle;
	*screwDisplace_out = distance = ijkVecDot3dv(translate_out->v, axis_unit_out->v);

	momentArm_out->x = dbl_half * (translate_out->y * axis_unit_out->z - translate_out->z * axis_unit_out->y + cot * (translate_out->x - distance * axis_unit_out->x));
	momentArm_out->y = dbl_half * (translate_out->z * axis_unit_out->x - translate_out->x * axis_unit_out->z + cot * (translate_out->y - distance * axis_unit_out->y));
	momentArm_out->z = dbl_half * (translate_out->x * axis_unit_out->y - translate_out->y * axis_unit_out->x + cot * (translate_out->z - distance * axis_unit_out->z));

	return dq_in;
}

ijk_inl dmat3 ijkDualQuatGetMatDQd3(ddualquat const dq_in)
{
	return ijkQuatGetMatQd3(dq_in.re);
}

ijk_inl dmat3 ijkDualQuatUnitGetMatDQd3(ddualquat const dq_in)
{
	return ijkQuatUnitGetMatQd3(dq_in.re);
}

ijk_inl dmat3 ijkDualQuatGetMatTranslateDQd3(dvec3* const translate_out, ddualquat const dq_in)
{
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return ijkQuatGetMatQd3(dq_in.re);
}

ijk_inl dmat3 ijkDualQuatUnitGetMatTranslateDQd3(dvec3* const translate_out, ddualquat const dq_in)
{
	*translate_out = ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re);
	return ijkQuatUnitGetMatQd3(dq_in.re);
}

ijk_inl dmat3 ijkDualQuatGetMatTranslateRemScaleDQd3(dvec3* const translate_out, ddualquat const dq_in)
{
	*translate_out = ijkQuatDecodeTranslateRemScaleQd(dq_in.dual, dq_in.re);
	return ijkQuatGetMatQd3(dq_in.re);
}

ijk_inl dmat4 ijkDualQuatGetMatDQd4(ddualquat const dq_in)
{
	return ijkQuatGetMatQd4t(dq_in.re, ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re));
}

ijk_inl dmat4 ijkDualQuatUnitGetMatDQd4(ddualquat const dq_in)
{
	return ijkQuatUnitGetMatQd4t(dq_in.re, ijkQuatDecodeTranslateQd(dq_in.dual, dq_in.re));
}

ijk_inl dmat4 ijkDualQuatGetMatTranslateRemScaleDQd4(ddualquat const dq_in)
{
	return ijkQuatGetMatQd4t(dq_in.re, ijkQuatDecodeTranslateRemScaleQd(dq_in.dual, dq_in.re));
}

ijk_inl dvec3 ijkDualQuatTransformScaleVecDQd3(ddualquat const dq_in, dvec3 const v_in)
{
	dquat const r = dq_in.re, d = dq_in.dual;
	double const lenSqInv = (dbl_two / ijkQuatLengthSqQd(r));
	dquat const tmp_lh = {
		(lenSqInv * d.x + r.y * v_in.z - r.z * v_in.y + r.w * v_in.x),
		(lenSqInv * d.y + r.z * v_in.x - r.x * v_in.z + r.w * v_in.y),
		(lenSqInv * d.z + r.x * v_in.y - r.y * v_in.x + r.w * v_in.z),
		(lenSqInv * d.w - ijkVecDot3d(r.vec, v_in)),
	};
	return ijkQuatDecodeTranslateD2Qd(tmp_lh, r);
}

ijk_inl dvec3 ijkDualQuatUnitTransformVecDQd3(ddualquat const dq_in, dvec3 const v_in)
{
	dquat const r = dq_in.re, d = dq_in.dual;
	dquat const tmp_lh = {
		(dbl_two * d.x + r.y * v_in.z - r.z * v_in.y + r.w * v_in.x),
		(dbl_two * d.y + r.z * v_in.x - r.x * v_in.z + r.w * v_in.y),
		(dbl_two * d.z + r.x * v_in.y - r.y * v_in.x + r.w * v_in.z),
		(dbl_two * d.w - ijkVecDot3d(r.vec, v_in)),
	};
	return ijkQuatDecodeTranslateD2Qd(tmp_lh, r);
}

ijk_inl dvec3 ijkDualQuatTransformVecDQd3(ddualquat const dq_in, dvec3 const v_in)
{
	dquat const r = dq_in.re, d = dq_in.dual;
	dquat const tmp_lh = {
		(dbl_two * d.x + r.y * v_in.z - r.z * v_in.y + r.w * v_in.x),
		(dbl_two * d.y + r.z * v_in.x - r.x * v_in.z + r.w * v_in.y),
		(dbl_two * d.z + r.x * v_in.y - r.y * v_in.x + r.w * v_in.z),
		(dbl_two * d.w - ijkVecDot3d(r.vec, v_in)),
	};
	return ijkQuatDecodeTranslateRemScaleD2Qd(tmp_lh, r);
}

ijk_inl ddualquat ijkDualQuatLerpDQd(ddualquat const dq0, ddualquat const dq1, double const u)
{
	ddualquat dq_out;
	dq_out.re = ijkQuatLerpQd(dq0.re, dq1.re, u);
	dq_out.dual = ijkQuatLerpQd(dq0.dual, dq1.dual, u);
	return dq_out;
}

ijk_inl ddualquat ijkDualQuatNlerpDQd(ddualquat const dq0, ddualquat const dq1, double const u)
{
	return ijkDualQuatNormalizeDQd(ijkDualQuatLerpDQd(dq0, dq1, u));
}

ijk_inl ddualquat ijkDualQuatSclerpDQd(ddualquat const dq0, ddualquat const dq1, double const u)
{
	ddualquat dq1b = dq1;
	double dot = ijkVecDot4dv(dq0.v, dq1.v);
	if (dot < dbl_zero)
	{
		dot = -dot;
		dq1b = ijkDualQuatNegateDQd(dq1b);
	}
	if (dot < dbl_one)
	{
		double const angle = ijkTrigAcos_deg_dbl(dot),
			sinInv = ijkTrigCsc_deg_dbl(angle),
			s0 = sinInv * ijkTrigSin_deg_dbl(angle * (dbl_one - u)),
			s1 = sinInv * ijkTrigSin_deg_dbl(angle * u);
		return ijkDualQuatAddDQd(ijkDualQuatMulDQds(dq0, s0), ijkDualQuatMulDQds(dq1b, s1));
	}
	return ijkDualQuatNlerpDQd(dq0, dq1b, u);
}

ijk_inl ddualquat ijkDualQuatDerivDQd(ddualquat const dq_in, dvec3 const linearVelocity, dvec3 const angularVelocity)
{
	dquat const r = dq_in.re, d = dq_in.dual, dr_dt = ijkQuatDerivQd(r, angularVelocity);
	double const lenSqInv = ijkQuatLengthSqInvQd(r);
	dquat const dd_dt = {
		(linearVelocity.x * dbl_half - lenSqInv * (d.x * dr_dt.w - d.w * dr_dt.x + d.z * dr_dt.y - d.y * dr_dt.z)),
		(linearVelocity.y * dbl_half - lenSqInv * (d.y * dr_dt.w - d.w * dr_dt.y + d.x * dr_dt.z - d.z * dr_dt.x)),
		(linearVelocity.z * dbl_half - lenSqInv * (d.z * dr_dt.w - d.w * dr_dt.z + d.y * dr_dt.x - d.x * dr_dt.y)),
		(-lenSqInv * ijkVecDot4dv(d.v, dr_dt.v)),
	};
	ddualquat dq1_out;
	dq1_out.re = dr_dt;
	dq1_out.dual = ijkQuatMulQd(dd_dt, r);
	return dq1_out;
}

ijk_inl ddualquat ijkDualQuatDeriv2DQd(ddualquat const dq_in, dvec3 const linearVelocity, dvec3 const linearAcceleration, dvec3 const angularVelocity, dvec3 const angularAcceleration)
{
	dvec3 const hw = {
		(dbl_half * angularVelocity.x), (dbl_half * angularVelocity.y), (dbl_half * angularVelocity.z)
	};
	double const wLenSq = ijkVecLengthSq3d(hw);
	dquat const r = dq_in.re, d = dq_in.dual;
	dquat const d2r_dt2 = ijkQuatInitElemsQd(
		(dbl_half * angularAcceleration.x), (dbl_half * angularAcceleration.y), (dbl_half * angularAcceleration.z), -wLenSq);
	dquat const hdiff = {
		(dbl_half * linearAcceleration.x + linearVelocity.y * hw.z - linearVelocity.z * hw.y),
		(dbl_half * linearAcceleration.y + linearVelocity.z * hw.x - linearVelocity.x * hw.z),
		(dbl_half * linearAcceleration.z + linearVelocity.x * hw.y - linearVelocity.y * hw.x),
		(-ijkVecDot3d(linearVelocity, hw))
	};
	dvec3 const ht = ijkQuatDecodeTranslateD2Qd(d, r);
	ddualquat dq2_out;
	dq2_out.re = ijkQuatMulQd(d2r_dt2, r);
	dq2_out.dual = ijkQuatAddQd(ijkQuatMulQd(hdiff, r), ijkQuatMulVecQd3q(ht, dq2_out.re));
	return dq2_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_DOUBLE_INL_
#endif	// _IJK_QUATERNION_DOUBLE_H_