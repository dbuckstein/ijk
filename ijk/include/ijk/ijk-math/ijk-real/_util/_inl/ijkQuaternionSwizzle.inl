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
inline ttquat<type>::ttquat(ttquat const& qc)
	: x(qc.x), y(qc.y), z(qc.z), w(qc.w)
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
inline ttdualquat<type>::ttdualquat(ttdualquat const& qc)
	: qr(qc.qr), qd(qc.qd)
{
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