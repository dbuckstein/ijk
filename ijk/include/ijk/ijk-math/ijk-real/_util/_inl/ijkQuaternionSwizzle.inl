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

	ijkQuaternionSwizzle.inl
	Inline definitions for quaternion class types (C++).
*/

#ifdef _IJK_QUATERNIONSWIZZLE_H_
#ifndef _IJK_QUATERNIONSWIZZLE_INL_
#define _IJK_QUATERNIONSWIZZLE_INL_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template<typename type>
inline ttmat3<type> const ttquat<type>::mat3() const
{
	type const ww = w * w, xx = x * x, yy = y * y, zz = z * z;
	type const xy = x * y, yz = y * z, zx = z * x;
	type const xw = x * w, yw = y * w, zw = z * w;
	return ttmat3<type>(
		(ww + xx - yy - zz), 2.0 * (xy + zw), 2.0 * (zx - yw),
		2.0 * (xy - zw), (ww - xx + yy - zz), 2.0 * (yz + xw),
		2.0 * (zx + yw), 2.0 * (yz - xw), (ww - xx - yy + zz)
	);
}
template<typename type>
inline ttmat4<type> const ttquat<type>::mat4() const
{
	return ttmat4<type>(mat3());
}

template<typename type>
inline ttmat4<type> const ttdualquat<type>::mat4() const
{
	ttmat3<type> const mat3 = qr.mat3();
	ttvec3<type> const translate = (qd * *qr) * 2.0;
	return ttmat4<type>(mat3.c0, mat3.c1, mat3.c2, ttvec4<type>(translate, 1.0));
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttquat<type>::ttquat()
	: x(0), y(0), z(0), w(1)
{
}
template <typename type>
inline ttquat<type>::ttquat(type const& xc, type const& yc, type const& zc, type const& wc)
	: x(xc), y(yc), z(zc), w(wc)
{
}
template <typename type>
inline ttquat<type>::ttquat(ttvec3<type> const& vc, ttvec1<type> const& rc)
	: x(vc.x), y(vc.y), z(vc.z), w(rc)
{
}
template <typename type>
inline ttquat<type>::ttquat(ttquat const& qc)
	: x(qc.x), y(qc.y), z(qc.z), w(qc.w)
{
}
template <typename type>
inline ttquat<type>::ttquat(ttmat3<type> const& m)
{
	// scale = lenSq of each column; take average (assuming orthogonal)
	type const scale = (type)(
		(m.x0 * m.x0 + m.y0 * m.y0 + m.z0 * m.z0) +
		(m.x1 * m.x1 + m.y1 * m.y1 + m.z1 * m.z1) +
		(m.x2 * m.x2 + m.y2 * m.y2 + m.z2 * m.z2)) / 3.0;
	type const len = (type)ijkSqrt_dbl((dbl)scale);
	type t = (m.m00 + m.m11 + m.m22);
	if (t > (type)0)
	{
		t = (type)(0.5 * ijkSqrtInv_dbl((dbl)((len + t) / len)));
		x = t * (m.m12 - m.m21);
		y = t * (m.m20 - m.m02);
		z = t * (m.m01 - m.m10);
		w = (type)(0.25 / t);
	}
	else if (m.m00 > m.m11 && m.m00 > m.m22)
	{
		t = (type)(0.5 * ijkSqrtInv_dbl((dbl)((len + m.m00 - m.m11 - m.m22) / len)));
		x = (type)(0.25 / t);
		y = t * (m.m01 + m.m10);
		z = t * (m.m20 + m.m02);
		w = t * (m.m12 - m.m21);
	}
	else if (m.m11 > m.m22)
	{
		t = (type)(0.5 * ijkSqrtInv_dbl((dbl)((len - m.m00 + m.m11 - m.m22) / len)));
		x = t * (m.m01 + m.m10);
		y = (type)(0.25 / t);
		z = t * (m.m12 + m.m21);
		w = t * (m.m20 - m.m02);
	}
	else
	{
		t = (type)(0.5 * ijkSqrtInv_dbl((dbl)((len - m.m00 - m.m11 + m.m22) / len)));
		x = t * (m.m20 + m.m02);
		y = t * (m.m12 + m.m21);
		z = (type)(0.25 / t);
		w = t * (m.m01 - m.m10);
	}
}
template <typename type>
inline ttquat<type>::ttquat(ttmat4<type> const& m)
	: ttquat(ttmat3<type>(m))
{
}

template<typename type>
inline ttquat<type> const ttquat<type>::operator *(ttvec3<type> const& v_rh) const
{
	// (xq i + yq j + zq k + wq)(x i + y j + z k)
	//	=	+ xq x ii + xq y ij + xq z ik
	//		+ yq x ji + yq y jj + yq z jk
	//		+ zq x ki + zq y kj + zq z kk
	//		+ wq x i + wq y j + wq z k
	//	=	- xq x + xq y k - xq z j
	//		- yq x k - yq y + yq z i
	//		+ zq x j - zq y i - zq z
	//		+ wq x i + wq y j + wq z k
	//	=	+(yq z - zq y + wq x)i
	//		+(zq x - xq z + wq y)j
	//		+(xq y - yq x + wq z)k
	//		-(xq x + yq y + zq z)
	//	= [cross(vq, v) + wq v] + [-dot(vq, v)]
	return ttquat<type>(
		(y * v_rh.z - z * v_rh.y + w * v_rh.x),
		(z * v_rh.x - x * v_rh.z + w * v_rh.y),
		(x * v_rh.y - y * v_rh.x + w * v_rh.z),
		-(x * v_rh.x + y * v_rh.y + z * v_rh.z)
	);
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator *(ttvec4<type> const& v_rh) const
{
	// (xq i + yq j + zq k + wq)(x i + y j + z k + w)
	//	=	+ (xq x ii + xq y ij + xq z ik) + xq w i
	//		+ (yq x ji + yq y jj + yq z jk) + yq w j
	//		+ (zq x ki + zq y kj + zq z kk) + zq w k
	//		+ (wq x i + wq y j + wq z k) + wq w
	//	= [cross(vq, v) + wq v + vq w] + [wq w - dot(vq, v)]
	return ttquat<type>(
		(y * v_rh.z - z * v_rh.y + w * v_rh.x + x * v_rh.w),
		(z * v_rh.x - x * v_rh.z + w * v_rh.y + y * v_rh.w),
		(x * v_rh.y - y * v_rh.x + w * v_rh.z + z * v_rh.w),
		w * v_rh.w - (x * v_rh.x + y * v_rh.y + z * v_rh.z)
	);
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator +() const
{
	return *this;
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator -() const
{
	return ttquat(-x, -y, -z, -w);
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator *() const
{
	return ttquat(-x, -y, -z, +w);
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator +(ttquat const& q_rh) const
{
	return ttquat((x + q_rh.x), (y + q_rh.y), (z + q_rh.z), (w + q_rh.w));
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator -(ttquat const& q_rh) const
{
	return ttquat((x - q_rh.x), (y - q_rh.y), (z - q_rh.z), (w - q_rh.w));
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator *(ttquat const& q_rh) const
{
	return ttquat<type>(
		(y * q_rh.z - z * q_rh.y + w * q_rh.x + x * q_rh.w),
		(z * q_rh.x - x * q_rh.z + w * q_rh.y + y * q_rh.w),
		(x * q_rh.y - y * q_rh.x + w * q_rh.z + z * q_rh.w),
		w * q_rh.w - (x * q_rh.x + y * q_rh.y + z * q_rh.z)
	);
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator *(type const& s_rh) const
{
	return ttquat((x * s_rh), (y * s_rh), (z * s_rh), (w * s_rh));
}
template<typename type>
inline ttquat<type> const ttquat<type>::operator /(type const& s_rh) const
{
	return ttquat((x / s_rh), (y / s_rh), (z / s_rh), (w / s_rh));
}
template<typename type>
inline type const ttquat<type>::operator [](index const i) const
{
	return v[i];
}
template<typename type>
inline ttquat<type>::operator type const* () const
{
	return v;
}

template<typename type>
inline ttquat<type>& ttquat<type>::operator =(ttquat const& q_rh)
{
	x = q_rh.x;
	y = q_rh.y;
	z = q_rh.z;
	w = q_rh.w;
	return *this;
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator *=(ttvec3<type> const& v_rh)
{
	return (*this = *this * v_rh);
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator *=(ttvec4<type> const& v_rh)
{
	return (*this = *this * v_rh);
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator +=(ttquat const& q_rh)
{
	x += q_rh.x;
	y += q_rh.y;
	z += q_rh.z;
	w += q_rh.w;
	return *this;
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator -=(ttquat const& q_rh)
{
	x -= q_rh.x;
	y -= q_rh.y;
	z -= q_rh.z;
	w -= q_rh.w;
	return *this;
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator *=(ttquat const& q_rh)
{
	return (*this = *this * q_rh);
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	z *= s_rh;
	w *= s_rh;
	return *this;
}
template<typename type>
inline ttquat<type>& ttquat<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	z /= s_rh;
	w /= s_rh;
	return *this;
}
template<typename type>
inline type& ttquat<type>::operator [](index const i)
{
	return v[i];
}
template<typename type>
inline ttquat<type>::operator type* ()
{
	return v;
}

template<typename type>
inline ttquat<type> const operator *(ttvec3<type> const& v_lh, ttquat<type> const& q_rh)
{
	return ttquat<type>(
		(v_lh.y * q_rh.z - v_lh.z * q_rh.y + v_lh.x * q_rh.w),
		(v_lh.z * q_rh.x - v_lh.x * q_rh.z + v_lh.y * q_rh.w),
		(v_lh.x * q_rh.y - v_lh.y * q_rh.x + v_lh.z * q_rh.w),
		-(v_lh.x * q_rh.x + v_lh.y * q_rh.y + v_lh.z * q_rh.z)
	);
}
template<typename type>
inline ttquat<type> const operator *(ttvec4<type> const& v_lh, ttquat<type> const& q_rh)
{
	return ttquat<type>(
		(v_lh.y * q_rh.z - v_lh.z * q_rh.y + v_lh.w * q_rh.x + v_lh.x * q_rh.w),
		(v_lh.z * q_rh.x - v_lh.x * q_rh.z + v_lh.w * q_rh.y + v_lh.y * q_rh.w),
		(v_lh.x * q_rh.y - v_lh.y * q_rh.x + v_lh.w * q_rh.z + v_lh.z * q_rh.w),
		v_lh.w * q_rh.w - (v_lh.x * q_rh.x + v_lh.y * q_rh.y + v_lh.z * q_rh.z)
	);
}
template<typename type>
inline ttquat<type> const operator *(type const& s_lh, ttquat<type> const& q_rh)
{
	return (q_rh * s_lh);
}
template<typename type>
inline ttquat<type> const operator /(type const& s_lh, ttquat<type> const& q_rh)
{
	return ttquat<type>(s_lh / q_rh.x, s_lh / q_rh.y, s_lh / q_rh.z, s_lh / q_rh.w);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttdualquat<type>::ttdualquat()
	: qr(), qd(0, 0, 0, 0)
{
}
template <typename type>
inline ttdualquat<type>::ttdualquat(ttquat<type> const& qr, ttquat<type> const& qd)
	: qr(qr), qd(qd)
{
}
template <typename type>
inline ttdualquat<type>::ttdualquat(ttdualquat const& dqc)
	: qr(dqc.qr), qd(dqc.qd)
{
}
template <typename type>
inline ttdualquat<type>::ttdualquat(ttmat4<type> const& m)
	: qr(m), qd((0.5 * ttvec3<type>(m.c3)) * qr)
{
}

template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator *(ttvec3<type> const& v_rh) const
{
	// (qr + E qd)(E v)
	//	= E qr v + EE qd v
	return ttdualquat<type>(ttquat<type>(0), qr * v_rh);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator *(ttvec4<type> const& v_rh) const
{
	// (qr + E qd)(w + E v)
	//	= qr w + E qr v + E qd w + EE qd v
	return ttdualquat<type>(qr * v_rh.w, qr * v_rh.xyz + qd * v_rh.w);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator -() const
{
	return ttdualquat<type>(-qr, -qd);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator *() const
{
	return ttdualquat<type>(*qr, *qd);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator ~() const
{
	return ttdualquat<type>(qr, -qd);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator !() const
{
	return ttdualquat<type>(*qr, ttquat<type>(qd.vec, -qd.w));
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator +(ttdualquat const& dq_rh) const
{
	return ttdualquat<type>(qr + dq_rh.qr, qd + dq_rh.qd);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator -(ttdualquat const& dq_rh) const
{
	return ttdualquat<type>(qr - dq_rh.qr, qd - dq_rh.qd);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator *(ttdualquat const& dq_rh) const
{
	// (qr_lh + E qd_lh)(qr_rh + E qd_rh)
	//	= qr_lh qr_rh + E qr_lh qd_rh + E qd_lh qr_rh + EE qd_lh qd_rh
	//	= (qr_lh qr_rh) + E(qr_lh qd_rh + qd_lh qr_rh)
	return ttdualquat<type>(qr * dq_rh.qr, qr * dq_rh.qd + qd * dq_rh.qr);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator *(type const& s_rh) const
{
	return ttdualquat<type>(qr * s_rh, qd * s_rh);
}
template <typename type>
inline ttdualquat<type> const ttdualquat<type>::operator /(type const& s_rh) const
{
	return ttdualquat<type>(qr / s_rh, qd / s_rh);
}
template <typename type>
inline ttquat<type> const ttdualquat<type>::operator [](index const i) const
{
	return q[i];
}
template <typename type>
inline ttdualquat<type>::operator type const* () const
{
	return v;
}

template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator =(ttdualquat const& dq_rh)
{
	qr = dq_rh.qr;
	qd = dq_rh.qd;
	return *this;
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator *=(ttvec3<type> const& v_rh)
{
	return (*this = *this * v_rh);
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator *=(ttvec4<type> const& v_rh)
{
	return (*this = *this * v_rh);
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator +=(ttdualquat const& dq_rh)
{
	qr += dq_rh.qr;
	qd += dq_rh.qd;
	return *this;
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator -=(ttdualquat const& dq_rh)
{
	qr -= dq_rh.qr;
	qd -= dq_rh.qd;
	return *this;
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator *=(ttdualquat const& dq_rh)
{
	return (*this = *this * dq_rh);
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator *=(type const& s_rh)
{
	qr *= s_rh;
	qd *= s_rh;
	return *this;
}
template <typename type>
inline ttdualquat<type>& ttdualquat<type>::operator /=(type const& s_rh)
{
	qr /= s_rh;
	qd /= s_rh;
	return *this;
}
template <typename type>
inline ttquat<type>& ttdualquat<type>::operator [](index const i)
{
	return q[i];
}
template <typename type>
inline ttdualquat<type>::operator type* ()
{
	return v;
}

template<typename type>
inline ttdualquat<type> const operator *(ttvec3<type> const& v_lh, ttdualquat<type> const& dq_rh)
{
	// (E v)(qr + E qd)
	//	= E v qr + EE v qd
	return ttdualquat<type>(ttquat<type>(0), v_lh * dq_rh.qr);
}
template<typename type>
inline ttdualquat<type> const operator *(ttvec4<type> const& v_lh, ttdualquat<type> const& dq_rh)
{
	// (w + E v)(qr + E qd)
	//	= w qr + E w qd + E v qr + EE v qd
	return ttdualquat<type>(v_lh.w * dq_rh.qr, v_lh.w * dq_rh.qd + v_lh.xyz * dq_rh.qr);
}
template<typename type>
inline ttdualquat<type> const operator *(type const& s_lh, ttdualquat<type> const& dq_rh)
{
	return (dq_rh * s_lh);
}
template<typename type>
inline ttdualquat<type> const operator /(type const& s_lh, ttdualquat<type> const& dq_rh)
{
	return ttdualquat<type>(s_lh / dq_rh.qr, s_lh / dq_rh.qd);
}


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_QUATERNIONSWIZZLE_INL_
#endif	// _IJK_QUATERNIONSWIZZLE_H_