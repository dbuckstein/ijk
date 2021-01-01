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

	ijkMatrixSwizzle.inl
	Inline definitions for matrix class types (C++).
*/

#ifdef _IJK_MATRIXSWIZZLE_H_
#ifndef _IJK_MATRIXSWIZZLE_INL_
#define _IJK_MATRIXSWIZZLE_INL_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template <typename type>
inline ttvec2<type> const ttmat2<type>::r(index const i) const
{
	return ttvec2<type>(c0.xy[i], c1.xy[i]);
}
template <typename type>
inline type ttmat2<type>::rx(ttvec2<type> const& v_rh, index const i) const
{
	return (c0.xy[i] * v_rh.x + c1.xy[i] * v_rh.y);
}

template <typename type>
inline ttvec3<type> const ttmat3<type>::r(index const i) const
{
	return ttvec3<type>(c0.xyz[i], c1.xyz[i], c2.xyz[i]);
}
template <typename type>
inline type ttmat3<type>::rx(ttvec3<type> const& v_rh, index const i) const
{
	return (c0.xyz[i] * v_rh.x + c1.xyz[i] * v_rh.y + c2.xyz[i] * v_rh.z);
}

template <typename type>
inline ttvec4<type> const ttmat4<type>::r(index const i) const
{
	return ttvec4<type>(c0.xyzw[i], c1.xyzw[i], c2.xyzw[i], c3.xyzw[i]);
}
template <typename type>
inline type ttmat4<type>::rx(ttvec4<type> const& v_rh, index const i) const
{
	return (c0.xyzw[i] * v_rh.x + c1.xyzw[i] * v_rh.y + c2.xyzw[i] * v_rh.z, c3.xyzw[i] * v_rh.w);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttmat2<type>::ttmat2(type const& diag)
	: c0(diag, 0), c1(0, diag)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(type const& x0, type const& y0, type const& x1, type const& y1)
	: c0(x0, y0), c1(x1, y1)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttvec2<type> const& c0, ttvec2<type> const& c1)
	: c0(c0), c1(c1)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat2 const& mc)
	: c0(mc.c0), c1(mc.c1)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat3<type> const& mc)
	: c0(mc.c0), c1(mc.c1)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat4<type> const& mc)
	: c0(mc.c0), c1(mc.c1)
{
}

template <typename type>
inline ttmat2<type>::ttmat2(float2x2 const mc)
	: c0(mc[0]), c1(mc[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(double2x2 const mc)
	: c0(mc[0]), c1(mc[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttvec1<f32> const mc[2][2])
	: c0(mc[0]), c1(mc[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttvec1<f64> const mc[2][2])
	: c0(mc[0]), c1(mc[1])
{
}

template <typename type>
inline ttmat2<type> const ttmat2<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator -() const
{
	return ttmat2(-c0, -c1);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator +(ttmat2 const& m_rh) const
{
	return ttmat2(c0 + m_rh.c0, c1 + m_rh.c1);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator -(ttmat2 const& m_rh) const
{
	return ttmat2(c0 - m_rh.c0, c1 - m_rh.c1);
}
template <typename type>
inline ttvec2<type> const ttmat2<type>::operator *(ttvec2<type> const& v_rh) const
{
	return ttvec2<type>(rx(v, 0), rx(v, 1));
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator *(ttmat2 const& m_rh) const
{
	return ttmat2(operator *(m_rh.c0), operator *(m_rh.c1));
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator *(type const& s_rh) const
{
	return ttmat2(c0 * s_rh, c1 * s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator /(type const& s_rh) const
{
	return ttmat2(c0 / s_rh, c1 / s_rh);
}
template <typename type>
inline ttvec2<type> const ttmat2<type>::operator [](index const i) const
{
	return c[i];
}
template <typename type>
inline ttmat2<type>::operator type const* () const
{
	return v;
}

template <typename type>
inline ttmat2<type>& ttmat2<type>::operator =(ttmat2 const& m_rh)
{
	c0 = m_rh.c0;
	c1 = m_rh.c1;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator +=(ttmat2 const& m_rh)
{
	c0 += m_rh.c0;
	c1 += m_rh.c1;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator -=(ttmat2 const& m_rh)
{
	c0 -= m_rh.c0;
	c1 -= m_rh.c1;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator *=(ttmat2 const& m_rh)
{
	return (*this = *this * m_rh);
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator =(type const& s_rh)
{
	return (*this = ttmat2(s_rh));
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator *=(type const& s_rh)
{
	c0 *= s_rh;
	c1 *= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator /=(type const& s_rh)
{
	c0 /= s_rh;
	c1 /= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttmat2<type>::operator [](index const i)
{
	return c[i];
}
template <typename type>
inline ttmat2<type>::operator type* ()
{
	return v;
}

template<typename type>
inline ttmat2<type> const operator *(type const& s_lh, ttmat2<type> const& m_rh)
{
	return (m_rh * s_lh);
}
template<typename type>
inline ttmat2<type> const operator /(type const& s_lh, ttmat2<type> const& m_rh)
{
	return ttmat2<type>(s_lh / m_rh.c0, s_lh / m_rh.c1);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttmat3<type>::ttmat3(type const& diag)
	: c0(diag, 0), c1(0, diag), c2(0, 0, diag)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(type const& x0, type const& y0, type const& z0, type const& x1, type const& y1, type const& z1, type const& x2, type const& y2, type const& z2)
	: c0(x0, y0, z0), c1(x1, y1, z1), c2(x2, y2, z2)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttvec3<type> const& c0, ttvec3<type> const& c1, ttvec3<type> const& c2)
	: c0(c0), c1(c1), c2(c2)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat2<type> const& mc)
	: c0(mc.c0), c1(mc.c1), c2(0, 0, 1)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat3 const& mc)
	: c0(mc.c0), c1(mc.c1), c2(mc.c2)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat4<type> const& mc)
	: c0(mc.c0), c1(mc.c1), c2(mc.c2)
{
}

template <typename type>
inline ttmat3<type>::ttmat3(float3x3 const mc)
	: c0(mc[0]), c1(mc[1]), c2(mc[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(double3x3 const mc)
	: c0(mc[0]), c1(mc[1]), c2(mc[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttvec1<f32> const mc[3][3])
	: c0(mc[0]), c1(mc[1]), c2(mc[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttvec1<f64> const mc[3][3])
	: c0(mc[0]), c1(mc[1]), c2(mc[2])
{
}

template <typename type>
inline ttmat3<type> const ttmat3<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator -() const
{
	return ttmat3(-c0, -c1, -c2);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator +(ttmat3 const& m_rh) const
{
	return ttmat3(c0 + m_rh.c0, c1 + m_rh.c1, c2 + m_rh.c2);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator -(ttmat3 const& m_rh) const
{
	return ttmat3(c0 - m_rh.c0, c1 - m_rh.c1, c2 - m_rh.c2);
}
template <typename type>
inline ttvec3<type> const ttmat3<type>::operator *(ttvec3<type> const& v_rh) const
{
	return ttvec3<type>(rx(v, 0), rx(v, 1), rx(v, 2));
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator *(ttmat3 const& m_rh) const
{
	return ttmat3(operator *(m_rh.c0), operator *(m_rh.c1), operator *(m_rh.c2));
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator *(type const& s_rh) const
{
	return ttmat3(c0 * s_rh, c1 * s_rh, c2 * s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator /(type const& s_rh) const
{
	return ttmat3(c0 / s_rh, c1 / s_rh, c2 / s_rh);
}
template <typename type>
inline ttvec3<type> const ttmat3<type>::operator [](index const i) const
{
	return c[i];
}
template <typename type>
inline ttmat3<type>::operator type const* () const
{
	return v;
}

template <typename type>
inline ttmat3<type>& ttmat3<type>::operator =(ttmat3 const& m_rh)
{
	c0 = m_rh.c0;
	c1 = m_rh.c1;
	c2 = m_rh.c2;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator +=(ttmat3 const& m_rh)
{
	c0 += m_rh.c0;
	c1 += m_rh.c1;
	c2 += m_rh.c2;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator -=(ttmat3 const& m_rh)
{
	c0 -= m_rh.c0;
	c1 -= m_rh.c1;
	c2 -= m_rh.c2;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator *=(ttmat3 const& m_rh)
{
	return (*this = *this * m_rh);
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator =(type const& s_rh)
{
	return (*this = ttmat3(s_rh));
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator *=(type const& s_rh)
{
	c0 *= s_rh;
	c1 *= s_rh;
	c2 *= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator /=(type const& s_rh)
{
	c0 /= s_rh;
	c1 /= s_rh;
	c2 /= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttmat3<type>::operator [](index const i)
{
	return c[i];
}
template <typename type>
inline ttmat3<type>::operator type* ()
{
	return v;
}

template<typename type>
inline ttmat3<type> const operator *(type const& s_lh, ttmat3<type> const& m_rh)
{
	return (m_rh * s_lh);
}
template<typename type>
inline ttmat3<type> const operator /(type const& s_lh, ttmat3<type> const& m_rh)
{
	return ttmat3<type>(s_lh / m_rh.c0, s_lh / m_rh.c1, s_lh / m_rh.c2);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttmat4<type>::ttmat4(type const& diag)
	: c0(diag, 0), c1(0, diag), c2(0, 0, diag), c3(0, 0, 0, diag)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& x0, type const& y0, type const& z0, type const& w0, type const& x1, type const& y1, type const& z1, type const& w1, type const& x2, type const& y2, type const& z2, type const& w2, type const& x3, type const& y3, type const& z3, type const& w3)
	: c0(x0, y0, z0, w0), c1(x1, y1, z1, w1), c2(x2, y2, z2, w2), c3(x3, y3, z3, w3)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttvec4<type> const& c0, ttvec4<type> const& c1, ttvec4<type> const& c2, ttvec4<type> const& c3)
	: c0(c0), c1(c1), c2(c2), c3(c3)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat2<type> const& mc)
	: c0(mc.c0), c1(mc.c1), c2(0, 0, 1), c3(0, 0, 0, 1)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat3<type> const& mc)
	: c0(mc.c0), c1(mc.c1), c2(mc.c2), c3(mc.c3)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat4 const& mc)
	: c0(mc.c0), c1(mc.c1), c2(mc.c2), c3(mc.c3)
{
}

template <typename type>
inline ttmat4<type>::ttmat4(float4x4 const mc)
	: c0(mc[0]), c1(mc[1]), c2(mc[2]), c3(mc[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(double4x4 const mc)
	: c0(mc[0]), c1(mc[1]), c2(mc[2]), c3(mc[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttvec1<f32> const mc[4][4])
	: c0(mc[0]), c1(mc[1]), c2(mc[2]), c3(mc[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttvec1<f64> const mc[4][4])
	: c0(mc[0]), c1(mc[1]), c2(mc[2]), c3(mc[3])
{
}

template <typename type>
inline ttmat4<type> const ttmat4<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator -() const
{
	return ttmat4(-c0, -c1, -c2, -c3);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator +(ttmat4 const& m_rh) const
{
	return ttmat4(c0 + m_rh.c0, c1 + m_rh.c1, c2 + m_rh.c2, c3 + m_rh.c3);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator -(ttmat4 const& m_rh) const
{
	return ttmat4(c0 - m_rh.c0, c1 - m_rh.c1, c2 - m_rh.c2, c3 - m_rh.c3);
}
template <typename type>
inline ttvec4<type> const ttmat4<type>::operator *(ttvec4<type> const& v_rh) const
{
	return ttvec4<type>(rx(v, 0), rx(v, 1), rx(v, 2), rx(v, 3));
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator *(ttmat4 const& m_rh) const
{
	return ttmat4(operator *(m_rh.c0), operator *(m_rh.c1), operator *(m_rh.c2), operator *(m_rh.c3));
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator *(type const& s_rh) const
{
	return ttmat4(c0 * s_rh, c1 * s_rh, c2 * s_rh, c3 * s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator /(type const& s_rh) const
{
	return ttmat4(c0 / s_rh, c1 / s_rh, c2 / s_rh, c3 / s_rh);
}
template <typename type>
inline ttvec4<type> const ttmat4<type>::operator [](index const i) const
{
	return c[i];
}
template <typename type>
inline ttmat4<type>::operator type const* () const
{
	return v;
}

template <typename type>
inline ttmat4<type>& ttmat4<type>::operator =(ttmat4 const& m_rh)
{
	c0 = m_rh.c0;
	c1 = m_rh.c1;
	c2 = m_rh.c2;
	c3 = m_rh.c3;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator +=(ttmat4 const& m_rh)
{
	c0 += m_rh.c0;
	c1 += m_rh.c1;
	c2 += m_rh.c2;
	c3 += m_rh.c3;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator -=(ttmat4 const& m_rh)
{
	c0 -= m_rh.c0;
	c1 -= m_rh.c1;
	c2 -= m_rh.c2;
	c3 -= m_rh.c3;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator *=(ttmat4 const& m_rh)
{
	return (*this = *this * m_rh);
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator =(type const& s_rh)
{
	return (*this = ttmat4(s_rh));
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator *=(type const& s_rh)
{
	c0 *= s_rh;
	c1 *= s_rh;
	c2 *= s_rh;
	c3 *= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator /=(type const& s_rh)
{
	c0 /= s_rh;
	c1 /= s_rh;
	c2 /= s_rh;
	c3 /= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttmat4<type>::operator [](index const i)
{
	return c[i];
}
template <typename type>
inline ttmat4<type>::operator type* ()
{
	return v;
}

template<typename type>
inline ttmat4<type> const operator *(type const& s_lh, ttmat4<type> const& m_rh)
{
	return (m_rh * s_lh);
}
template<typename type>
inline ttmat4<type> const operator /(type const& s_lh, ttmat4<type> const& m_rh)
{
	return ttmat4<type>(s_lh / m_rh.c0, s_lh / m_rh.c1, s_lh / m_rh.c2, s_lh / m_rh.c3);
}


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_MATRIXSWIZZLE_INL_
#endif	// _IJK_MATRIXSWIZZLE_H_