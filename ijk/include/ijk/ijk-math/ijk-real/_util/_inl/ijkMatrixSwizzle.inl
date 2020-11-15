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

	ijkMatrixSwizzle.inl
	Inline definitions for matrix class types (C++).
*/

#ifdef _IJK_MATRIXSWIZZLE_H_
#ifndef _IJK_MATRIXSWIZZLE_INL_
#define _IJK_MATRIXSWIZZLE_INL_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template <typename type>
inline ttmat2<type>::ttmat2(type const& diag)
	: x0(diag), y0(0), x1(0), y1(diag)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(type const& x0, type const& y0, type const& x1, type const& y1)
	: x0(x0), y0(y0), x1(x1), y1(y1)
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
inline ttvec2<type> const ttmat2<type>::operator *(ttvec2<type> const& m_rh) const
{
	//return ttmat2(x * m_rh.x, y * m_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator *(ttmat2 const& m_rh) const
{
	//return ttmat2(x * m_rh.x, y * m_rh.y);
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



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_MATRIXSWIZZLE_INL_
#endif	// _IJK_MATRIXSWIZZLE_H_