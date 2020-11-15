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
inline ttmat2<type>::ttmat2(type const& xy)
	: x(xy), y(xy)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(type const& xc, type const& yc)
	: x(xc), y(yc)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat2 const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat3<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat4<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(stvec2<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(stvec3<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttmat2<type>::ttmat2(stvec4<type> const& xy)
	: x(xy.x), y(xy.y)
{
}

template <typename type>
inline ttmat2<type>::ttmat2(bool const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(i32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(i64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ui32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ui64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(f32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(f64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<bool> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<i32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<i64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<ui32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<ui64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<f32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttmat2<type>::ttmat2(ttmat1<f64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
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
	return ttmat2(-x, -y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator ~() const
{
	return ttmat2(~x, ~y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator !() const
{
	return ttmat2<bool>(!x, !y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator +(ttmat2 const& v_rh) const
{
	return ttmat2(x + v_rh.x, y + v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator -(ttmat2 const& v_rh) const
{
	return ttmat2(x - v_rh.x, y - v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator *(ttmat2 const& v_rh) const
{
	return ttmat2(x * v_rh.x, y * v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator /(ttmat2 const& v_rh) const
{
	return ttmat2(x / v_rh.x, y / v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator %(ttmat2 const& v_rh) const
{
	return ttmat2(x % v_rh.x, y % v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator &(ttmat2 const& v_rh) const
{
	return ttmat2(x & v_rh.x, y & v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator |(ttmat2 const& v_rh) const
{
	return ttmat2(x | v_rh.x, y | v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator ^(ttmat2 const& v_rh) const
{
	return ttmat2(x ^ v_rh.x, y ^ v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator <<(ttmat2 const& v_rh) const
{
	return ttmat2(x << v_rh.x, y << v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator >>(ttmat2 const& v_rh) const
{
	return ttmat2(x >> v_rh.x, y >> v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator ==(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x == v_rh.x, y == v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator !=(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x != v_rh.x, y != v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator <=(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x <= v_rh.x, y <= v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator >=(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x >= v_rh.x, y >= v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator <(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x < v_rh.x, y < v_rh.y);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator >(ttmat2 const& v_rh) const
{
	return ttmat2<bool>(x > v_rh.x, y > v_rh.y);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator +(type const& s_rh) const
{
	return ttmat2(x + s_rh, y + s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator -(type const& s_rh) const
{
	return ttmat2(x - s_rh, y - s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator *(type const& s_rh) const
{
	return ttmat2(x * s_rh, y * s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator /(type const& s_rh) const
{
	return ttmat2(x / s_rh, y / s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator %(type const& s_rh) const
{
	return ttmat2(x % s_rh, y % s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator &(type const& s_rh) const
{
	return ttmat2(x & s_rh, y & s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator |(type const& s_rh) const
{
	return ttmat2(x | s_rh, y | s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator ^(type const& s_rh) const
{
	return ttmat2(x ^ s_rh, y ^ s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator <<(type const& s_rh) const
{
	return ttmat2(x << s_rh, y << s_rh);
}
template <typename type>
inline ttmat2<type> const ttmat2<type>::operator >>(type const& s_rh) const
{
	return ttmat2(x >> s_rh, y >> s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator ==(type const& s_rh) const
{
	return ttmat2<bool>(x == s_rh, y == s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator !=(type const& s_rh) const
{
	return ttmat2<bool>(x != s_rh, y != s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator <=(type const& s_rh) const
{
	return ttmat2<bool>(x <= s_rh, y <= s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator >=(type const& s_rh) const
{
	return ttmat2<bool>(x >= s_rh, y >= s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator <(type const& s_rh) const
{
	return ttmat2<bool>(x < s_rh, y < s_rh);
}
template <typename type>
inline ttmat2<bool> const ttmat2<type>::operator >(type const& s_rh) const
{
	return ttmat2<bool>(x > s_rh, y > s_rh);
}
template <typename type>
inline type const ttmat2<type>::operator [](index const i) const
{
	return xy[i];
}
template <typename type>
inline ttmat2<type>::operator type const* () const
{
	return xy;
}

template <typename type>
inline ttmat2<type>& ttmat2<type>::operator =(ttmat2 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator =(stvec2<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator +=(ttmat2 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator -=(ttmat2 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator *=(ttmat2 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator /=(ttmat2 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator %=(ttmat2 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator &=(ttmat2 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator |=(ttmat2 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator ^=(ttmat2 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator <<=(ttmat2 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator >>=(ttmat2 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator =(type const& s_rh)
{
	x = y = s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	return *this;
}
template <typename type>
inline ttmat2<type>& ttmat2<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttmat2<type>::operator [](index const i)
{
	return xy[i];
}
template <typename type>
inline ttmat2<type>::operator type* ()
{
	return xy;
}

template<typename type>
inline ttmat2<type> const operator +(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttmat2<type> const operator -(type const& s_lh, ttmat2<type> const& v_rh)
{
	return ttmat2<type>(s_lh - v_rh.x, s_lh - v_rh.y);
}
template<typename type>
inline ttmat2<type> const operator *(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttmat2<type> const operator /(type const& s_lh, ttmat2<type> const& v_rh)
{
	return ttmat2<type>(s_lh / v_rh.x, s_lh / v_rh.y);
}
template<typename type>
inline ttmat2<type> const operator %(type const& s_lh, ttmat2<type> const& v_rh)
{
	return ttmat2<type>(s_lh % v_rh.x, s_lh % v_rh.y);
}
template<typename type>
inline ttmat2<type> const operator &(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttmat2<type> const operator |(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttmat2<type> const operator ^(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttmat2<type> const operator <<(type const& s_lh, ttmat2<type> const& v_rh)
{
	return ttmat2<type>(s_lh << v_rh.x, s_lh << v_rh.y);
}
template<typename type>
inline ttmat2<type> const operator >>(type const& s_lh, ttmat2<type> const& v_rh)
{
	return ttmat2<type>(s_lh >> v_rh.x, s_lh >> v_rh.y);
}
template<typename type>
inline ttmat2<bool> const operator ==(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttmat2<bool> const operator !=(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttmat2<bool> const operator <=(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttmat2<bool> const operator >=(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttmat2<bool> const operator <(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttmat2<bool> const operator >(type const& s_lh, ttmat2<type> const& v_rh)
{
	return (v_rh > s_lh);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttmat3<type>::ttmat3(type const& xyz)
	: x(xyz), y(xyz), z(xyz)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(type const& xc, type const& yc, type const& zc)
	: x(xc), y(yc), z(zc)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat2<type> const& xy, type const& zc)
	: x(xy.x), y(xy.y), z(zc)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(type const& xc, ttmat2<type> const& yz)
	: x(xc), y(yz.x), z(yz.y)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat3 const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat4<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(stvec2<type> const& xy, type const& zc)
	: x(xy.x), y(xy.y), z(zc)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(type const& xc, stvec2<type> const& yz)
	: x(xc), y(yz.x), z(yz.y)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(stvec3<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttmat3<type>::ttmat3(stvec4<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}

template <typename type>
inline ttmat3<type>::ttmat3(bool const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(i32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(i64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ui32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ui64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(f32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(f64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<bool> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<i32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<i64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<ui32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<ui64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<f32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttmat3<type>::ttmat3(ttmat1<f64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
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
	return ttmat3(-x, -y, -z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator ~() const
{
	return ttmat3(~x, ~y, ~z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator !() const
{
	return ttmat3<bool>(!x, !y, !z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator +(ttmat3 const& v_rh) const
{
	return ttmat3(x + v_rh.x, y + v_rh.y, z + v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator -(ttmat3 const& v_rh) const
{
	return ttmat3(x - v_rh.x, y - v_rh.y, z - v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator *(ttmat3 const& v_rh) const
{
	return ttmat3(x * v_rh.x, y * v_rh.y, z * v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator /(ttmat3 const& v_rh) const
{
	return ttmat3(x / v_rh.x, y / v_rh.y, z / v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator %(ttmat3 const& v_rh) const
{
	return ttmat3(x % v_rh.x, y % v_rh.y, z % v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator &(ttmat3 const& v_rh) const
{
	return ttmat3(x & v_rh.x, y & v_rh.y, z & v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator |(ttmat3 const& v_rh) const
{
	return ttmat3(x | v_rh.x, y | v_rh.y, z | v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator ^(ttmat3 const& v_rh) const
{
	return ttmat3(x ^ v_rh.x, y ^ v_rh.y, z ^ v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator <<(ttmat3 const& v_rh) const
{
	return ttmat3(x << v_rh.x, y << v_rh.y, z << v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator >>(ttmat3 const& v_rh) const
{
	return ttmat3(x >> v_rh.x, y >> v_rh.y, z >> v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator ==(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x == v_rh.x, y == v_rh.y, z == v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator !=(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x != v_rh.x, y != v_rh.y, z != v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator <=(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x <= v_rh.x, y <= v_rh.y, z <= v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator >=(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x >= v_rh.x, y >= v_rh.y, z >= v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator <(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x < v_rh.x, y < v_rh.y, z < v_rh.z);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator >(ttmat3 const& v_rh) const
{
	return ttmat3<bool>(x > v_rh.x, y > v_rh.y, z > v_rh.z);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator +(type const& s_rh) const
{
	return ttmat3(x + s_rh, y + s_rh, z + s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator -(type const& s_rh) const
{
	return ttmat3(x - s_rh, y - s_rh, z - s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator *(type const& s_rh) const
{
	return ttmat3(x * s_rh, y * s_rh, z * s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator /(type const& s_rh) const
{
	return ttmat3(x / s_rh, y / s_rh, z / s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator %(type const& s_rh) const
{
	return ttmat3(x % s_rh, y % s_rh, z % s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator &(type const& s_rh) const
{
	return ttmat3(x & s_rh, y & s_rh, z & s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator |(type const& s_rh) const
{
	return ttmat3(x | s_rh, y | s_rh, z | s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator ^(type const& s_rh) const
{
	return ttmat3(x ^ s_rh, y ^ s_rh, z ^ s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator <<(type const& s_rh) const
{
	return ttmat3(x << s_rh, y << s_rh, z << s_rh);
}
template <typename type>
inline ttmat3<type> const ttmat3<type>::operator >>(type const& s_rh) const
{
	return ttmat3(x >> s_rh, y >> s_rh, z >> s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator ==(type const& s_rh) const
{
	return ttmat3<bool>(x == s_rh, y == s_rh, z == s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator !=(type const& s_rh) const
{
	return ttmat3<bool>(x != s_rh, y != s_rh, z != s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator <=(type const& s_rh) const
{
	return ttmat3<bool>(x <= s_rh, y <= s_rh, z <= s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator >=(type const& s_rh) const
{
	return ttmat3<bool>(x >= s_rh, y >= s_rh, z >= s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator <(type const& s_rh) const
{
	return ttmat3<bool>(x < s_rh, y < s_rh, z < s_rh);
}
template <typename type>
inline ttmat3<bool> const ttmat3<type>::operator >(type const& s_rh) const
{
	return ttmat3<bool>(x > s_rh, y > s_rh, z > s_rh);
}
template <typename type>
inline type const ttmat3<type>::operator [](index const i) const
{
	return xyz[i];
}
template <typename type>
inline ttmat3<type>::operator type const* () const
{
	return xyz;
}

template <typename type>
inline ttmat3<type>& ttmat3<type>::operator =(ttmat3 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator =(stvec3<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator +=(ttmat3 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	z += v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator -=(ttmat3 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	z -= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator *=(ttmat3 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	z *= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator /=(ttmat3 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	z /= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator %=(ttmat3 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	z %= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator &=(ttmat3 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	z &= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator |=(ttmat3 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	z |= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator ^=(ttmat3 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	z ^= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator <<=(ttmat3 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	z <<= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator >>=(ttmat3 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	z >>= v_rh.z;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator =(type const& s_rh)
{
	x = y = z = s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	z += s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	z -= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	z *= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	z /= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	z %= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	z &= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	z |= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	z ^= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	z <<= s_rh;
	return *this;
}
template <typename type>
inline ttmat3<type>& ttmat3<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	z >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttmat3<type>::operator [](index const i)
{
	return xyz[i];
}
template <typename type>
inline ttmat3<type>::operator type* ()
{
	return xyz;
}

template<typename type>
inline ttmat3<type> const operator +(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttmat3<type> const operator -(type const& s_lh, ttmat3<type> const& v_rh)
{
	return ttmat3<type>(s_lh - v_rh.x, s_lh - v_rh.y, s_lh - v_rh.z);
}
template<typename type>
inline ttmat3<type> const operator *(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttmat3<type> const operator /(type const& s_lh, ttmat3<type> const& v_rh)
{
	return ttmat3<type>(s_lh / v_rh.x, s_lh / v_rh.y, s_lh / v_rh.z);
}
template<typename type>
inline ttmat3<type> const operator %(type const& s_lh, ttmat3<type> const& v_rh)
{
	return ttmat3<type>(s_lh % v_rh.x, s_lh % v_rh.y, s_lh % v_rh.z);
}
template<typename type>
inline ttmat3<type> const operator &(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttmat3<type> const operator |(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttmat3<type> const operator ^(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttmat3<type> const operator <<(type const& s_lh, ttmat3<type> const& v_rh)
{
	return ttmat3<type>(s_lh << v_rh.x, s_lh << v_rh.y, s_lh << v_rh.z);
}
template<typename type>
inline ttmat3<type> const operator >>(type const& s_lh, ttmat3<type> const& v_rh)
{
	return ttmat3<type>(s_lh >> v_rh.x, s_lh >> v_rh.y, s_lh >> v_rh.z);
}
template<typename type>
inline ttmat3<bool> const operator ==(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttmat3<bool> const operator !=(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttmat3<bool> const operator <=(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttmat3<bool> const operator >=(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttmat3<bool> const operator <(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttmat3<bool> const operator >(type const& s_lh, ttmat3<type> const& v_rh)
{
	return (v_rh > s_lh);
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttmat4<type>::ttmat4(type const& xyzw)
	: x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, type const& yc, type const& zc, type const& wc)
	: x(xc), y(yc), z(zc), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat2<type> const& xy, type const& zc, type const& wc)
	: x(xy.x), y(xy.y), z(zc), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, ttmat2<type> const& yz, type const& wc)
	: x(xc), y(yz.x), z(yz.y), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, type const& yc, ttmat2<type> const& zw)
	: x(xc), y(yc), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat2<type> const& xy, ttmat2<type> const& zw)
	: x(xy.x), y(xy.y), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat3<type> const& xyz, type const& wc)
	: x(xyz.x), y(xyz.y), z(xyz.z), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, ttmat3<type> const& yzw)
	: x(xc), y(yzw.x), z(yzw.y), w(yzw.z)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat4 const& xyzw)
	: x(xyzw.x), y(xyzw.y), z(xyzw.z), w(xyzw.w)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(stvec2<type> const& xy, type const& zc, type const& wc)
	: x(xy.x), y(xy.y), z(zc), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, stvec2<type> const& yz, type const& wc)
	: x(xc), y(yz.x), z(yz.y), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, type const& yc, stvec2<type> const& zw)
	: x(xc), y(yc), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(stvec2<type> const& xy, stvec2<type> const& zw)
	: x(xy.x), y(xy.y), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(stvec3<type> const& xyz, type const& wc)
	: x(xyz.x), y(xyz.y), z(xyz.z), w(wc)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(type const& xc, stvec3<type> const& yzw)
	: x(xc), y(yzw.x), z(yzw.y), w(yzw.z)
{
}
template <typename type>
inline ttmat4<type>::ttmat4(stvec4<type> const& xyzw)
	: x(xyzw.x), y(xyzw.y), z(xyzw.z), w(xyzw.w)
{
}

template <typename type>
inline ttmat4<type>::ttmat4(bool const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(i32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(i64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ui32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ui64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(f32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(f64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<bool> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<i32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<i64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<ui32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<ui64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<f32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttmat4<type>::ttmat4(ttmat1<f64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
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
	return ttmat4(-x, -y, -z, -w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator ~() const
{
	return ttmat4(~x, ~y, ~z, ~w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator !() const
{
	return ttmat4<bool>(!x, !y, !z, !w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator +(ttmat4 const& v_rh) const
{
	return ttmat4(x + v_rh.x, y + v_rh.y, z + v_rh.z, w + v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator -(ttmat4 const& v_rh) const
{
	return ttmat4(x - v_rh.x, y - v_rh.y, z - v_rh.z, w - v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator *(ttmat4 const& v_rh) const
{
	return ttmat4(x * v_rh.x, y * v_rh.y, z * v_rh.z, w * v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator /(ttmat4 const& v_rh) const
{
	return ttmat4(x / v_rh.x, y / v_rh.y, z / v_rh.z, w / v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator %(ttmat4 const& v_rh) const
{
	return ttmat4(x % v_rh.x, y % v_rh.y, z % v_rh.z, w % v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator &(ttmat4 const& v_rh) const
{
	return ttmat4(x & v_rh.x, y & v_rh.y, z & v_rh.z, w & v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator |(ttmat4 const& v_rh) const
{
	return ttmat4(x | v_rh.x, y | v_rh.y, z | v_rh.z, w | v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator ^(ttmat4 const& v_rh) const
{
	return ttmat4(x ^ v_rh.x, y ^ v_rh.y, z ^ v_rh.z, w ^ v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator <<(ttmat4 const& v_rh) const
{
	return ttmat4(x << v_rh.x, y << v_rh.y, z << v_rh.z, w << v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator >>(ttmat4 const& v_rh) const
{
	return ttmat4(x >> v_rh.x, y >> v_rh.y, z >> v_rh.z, w >> v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator ==(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x == v_rh.x, y == v_rh.y, z == v_rh.z, w == v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator !=(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x != v_rh.x, y != v_rh.y, z != v_rh.z, w != v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator <=(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x <= v_rh.x, y <= v_rh.y, z <= v_rh.z, w <= v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator >=(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x >= v_rh.x, y >= v_rh.y, z >= v_rh.z, w >= v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator <(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x < v_rh.x, y < v_rh.y, z < v_rh.z, w < v_rh.w);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator >(ttmat4 const& v_rh) const
{
	return ttmat4<bool>(x > v_rh.x, y > v_rh.y, z > v_rh.z, w > v_rh.w);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator +(type const& s_rh) const
{
	return ttmat4(x + s_rh, y + s_rh, z + s_rh, w + s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator -(type const& s_rh) const
{
	return ttmat4(x - s_rh, y - s_rh, z - s_rh, w - s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator *(type const& s_rh) const
{
	return ttmat4(x * s_rh, y * s_rh, z * s_rh, w * s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator /(type const& s_rh) const
{
	return ttmat4(x / s_rh, y / s_rh, z / s_rh, w / s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator %(type const& s_rh) const
{
	return ttmat4(x % s_rh, y % s_rh, z % s_rh, w % s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator &(type const& s_rh) const
{
	return ttmat4(x & s_rh, y & s_rh, z & s_rh, w & s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator |(type const& s_rh) const
{
	return ttmat4(x | s_rh, y | s_rh, z | s_rh, w | s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator ^(type const& s_rh) const
{
	return ttmat4(x ^ s_rh, y ^ s_rh, z ^ s_rh, w ^ s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator <<(type const& s_rh) const
{
	return ttmat4(x << s_rh, y << s_rh, z << s_rh, w << s_rh);
}
template <typename type>
inline ttmat4<type> const ttmat4<type>::operator >>(type const& s_rh) const
{
	return ttmat4(x >> s_rh, y >> s_rh, z >> s_rh, w >> s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator ==(type const& s_rh) const
{
	return ttmat4<bool>(x == s_rh, y == s_rh, z == s_rh, w == s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator !=(type const& s_rh) const
{
	return ttmat4<bool>(x != s_rh, y != s_rh, z != s_rh, w != s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator <=(type const& s_rh) const
{
	return ttmat4<bool>(x <= s_rh, y <= s_rh, z <= s_rh, w <= s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator >=(type const& s_rh) const
{
	return ttmat4<bool>(x >= s_rh, y >= s_rh, z >= s_rh, w >= s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator <(type const& s_rh) const
{
	return ttmat4<bool>(x < s_rh, y < s_rh, z < s_rh, w < s_rh);
}
template <typename type>
inline ttmat4<bool> const ttmat4<type>::operator >(type const& s_rh) const
{
	return ttmat4<bool>(x > s_rh, y > s_rh, z > s_rh, w > s_rh);
}
template <typename type>
inline type const ttmat4<type>::operator [](index const i) const
{
	return xyzw[i];
}
template <typename type>
inline ttmat4<type>::operator type const* () const
{
	return xyzw;
}

template <typename type>
inline ttmat4<type>& ttmat4<type>::operator =(ttmat4 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	w = v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator =(stvec4<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	w = v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator +=(ttmat4 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	z += v_rh.z;
	w += v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator -=(ttmat4 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	z -= v_rh.z;
	w -= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator *=(ttmat4 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	z *= v_rh.z;
	w *= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator /=(ttmat4 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	z /= v_rh.z;
	w /= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator %=(ttmat4 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	z %= v_rh.z;
	w %= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator &=(ttmat4 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	z &= v_rh.z;
	w &= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator |=(ttmat4 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	z |= v_rh.z;
	w |= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator ^=(ttmat4 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	z ^= v_rh.z;
	w ^= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator <<=(ttmat4 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	z <<= v_rh.z;
	w <<= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator >>=(ttmat4 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	z >>= v_rh.z;
	w >>= v_rh.w;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator =(type const& s_rh)
{
	x = y = z = w = s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	z += s_rh;
	w += s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	z -= s_rh;
	w -= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	z *= s_rh;
	w *= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	z /= s_rh;
	w /= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	z %= s_rh;
	w %= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	z &= s_rh;
	w &= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	z |= s_rh;
	w |= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	z ^= s_rh;
	w ^= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	z <<= s_rh;
	w <<= s_rh;
	return *this;
}
template <typename type>
inline ttmat4<type>& ttmat4<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	z >>= s_rh;
	w >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttmat4<type>::operator [](index const i)
{
	return xyzw[i];
}
template <typename type>
inline ttmat4<type>::operator type* ()
{
	return xyzw;
}

template<typename type>
inline ttmat4<type> const operator +(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttmat4<type> const operator -(type const& s_lh, ttmat4<type> const& v_rh)
{
	return ttmat4<type>(s_lh - v_rh.x, s_lh - v_rh.y, s_lh - v_rh.z, s_lh - v_rh.w);
}
template<typename type>
inline ttmat4<type> const operator *(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttmat4<type> const operator /(type const& s_lh, ttmat4<type> const& v_rh)
{
	return ttmat4<type>(s_lh / v_rh.x, s_lh / v_rh.y, s_lh / v_rh.z, s_lh / v_rh.w);
}
template<typename type>
inline ttmat4<type> const operator %(type const& s_lh, ttmat4<type> const& v_rh)
{
	return ttmat4<type>(s_lh % v_rh.x, s_lh % v_rh.y, s_lh % v_rh.z, s_lh % v_rh.w);
}
template<typename type>
inline ttmat4<type> const operator &(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttmat4<type> const operator |(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttmat4<type> const operator ^(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttmat4<type> const operator <<(type const& s_lh, ttmat4<type> const& v_rh)
{
	return ttmat4<type>(s_lh << v_rh.x, s_lh << v_rh.y, s_lh << v_rh.z, s_lh << v_rh.w);
}
template<typename type>
inline ttmat4<type> const operator >>(type const& s_lh, ttmat4<type> const& v_rh)
{
	return ttmat4<type>(s_lh >> v_rh.x, s_lh >> v_rh.y, s_lh >> v_rh.z, s_lh >> v_rh.w);
}
template<typename type>
inline ttmat4<bool> const operator ==(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttmat4<bool> const operator !=(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttmat4<bool> const operator <=(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttmat4<bool> const operator >=(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttmat4<bool> const operator <(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttmat4<bool> const operator >(type const& s_lh, ttmat4<type> const& v_rh)
{
	return (v_rh > s_lh);
}


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_MATRIXSWIZZLE_INL_
#endif	// _IJK_MATRIXSWIZZLE_H_