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


//-----------------------------------------------------------------------------

template <typename type>
inline ttdualquat<type>::ttdualquat()
	: qr(), qd(0, 0, 0, 0)
{
}
template <typename type>
inline ttdualquat<type>::ttdualquat(ttquat<type> const& qr)
	: qr(qr), qd(0, 0, 0, 0)
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


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_QUATERNIONSWIZZLE_INL_
#endif	// _IJK_QUATERNIONSWIZZLE_H_