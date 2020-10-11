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

	ijkVector.inl
	Inline definitions for vector types.
*/

#ifndef _IJK_VECTORSWIZZLE_INL_
#define _IJK_VECTORSWIZZLE_INL_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template<typename type>
inline ttvec1<type>::ttvec1(type const& xc)
	: x(xc)
{
}
template<typename type>
inline ttvec1<type>::ttvec1(ttvec1 const& xc)
	: x(xc.x)
{
}
template<typename type>
inline ttvec1<type>::ttvec1(stvec1<type> const& xc)
	: x(xc.x)
{
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(type const& xc)
{
	x = xc;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(ttvec1 const& xc)
{
	x = xc.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(stvec1<type> const& xc)
{
	x = xc.x;
	return *this;
}
template<typename type>
inline ttvec1<type>::operator type const () const
{
	return x;
}
template<typename type>
inline ttvec1<type>::operator type& ()
{
	return x;
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttvec2<type>::ttvec2(type const& xy)
	: x(xy), y(xy)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(type const& xc, type const& yc)
	: x(xc), y(yc)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(bool const* xy)
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(i32 const* xy)
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(uint const* xy)
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(flt const* xy)
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(dbl const* xy)
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec2 const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec3<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec4<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(stvec2<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(stvec3<type> const& xy)
	: x(xy.x), y(xy.y)
{
}
template <typename type>
inline ttvec2<type>::ttvec2(stvec4<type> const& xy)
	: x(xy.x), y(xy.y)
{
}

template <typename type>
inline ttvec2<type> const ttvec2<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator -() const
{
	return ttvec2(-x, -y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator ~() const
{
	return ttvec2(~x, ~y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator +(ttvec2 const& v_rh) const
{
	return ttvec2(x + v_rh.x, y + v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator -(ttvec2 const& v_rh) const
{
	return ttvec2(x - v_rh.x, y - v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator *(ttvec2 const& v_rh) const
{
	return ttvec2(x * v_rh.x, y * v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator /(ttvec2 const& v_rh) const
{
	return ttvec2(x / v_rh.x, y / v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator %(ttvec2 const& v_rh) const
{
	return ttvec2(x % v_rh.x, y % v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator &(ttvec2 const& v_rh) const
{
	return ttvec2(x & v_rh.x, y & v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator |(ttvec2 const& v_rh) const
{
	return ttvec2(x | v_rh.x, y | v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator ^(ttvec2 const& v_rh) const
{
	return ttvec2(x ^ v_rh.x, y ^ v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator <<(ttvec2 const& v_rh) const
{
	return ttvec2(x << v_rh.x, y << v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator >>(ttvec2 const& v_rh) const
{
	return ttvec2(x >> v_rh.x, y >> v_rh.y);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator +(type const& s_rh) const
{
	return ttvec2(x + s_rh, y + s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator -(type const& s_rh) const
{
	return ttvec2(x - s_rh, y - s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator *(type const& s_rh) const
{
	return ttvec2(x * s_rh, y * s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator /(type const& s_rh) const
{
	return ttvec2(x / s_rh, y / s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator %(type const& s_rh) const
{
	return ttvec2(x % s_rh, y % s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator &(type const& s_rh) const
{
	return ttvec2(x & s_rh, y & s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator |(type const& s_rh) const
{
	return ttvec2(x | s_rh, y | s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator ^(type const& s_rh) const
{
	return ttvec2(x ^ s_rh, y ^ s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator <<(type const& s_rh) const
{
	return ttvec2(x << s_rh, y << s_rh);
}
template <typename type>
inline ttvec2<type> const ttvec2<type>::operator >>(type const& s_rh) const
{
	return ttvec2(x >> s_rh, y >> s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator !() const
{
	return ttvec2<bool>(!x, !y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator ==(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x == v_rh.x, y == v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator !=(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x != v_rh.x, y != v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator <=(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x <= v_rh.x, y <= v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator >=(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x >= v_rh.x, y >= v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator <(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x < v_rh.x, y < v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator >(ttvec2 const& v_rh) const
{
	return ttvec2<bool>(x > v_rh.x, y > v_rh.y);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator ==(type const& s_rh) const
{
	return ttvec2<bool>(x == s_rh, y == s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator !=(type const& s_rh) const
{
	return ttvec2<bool>(x != s_rh, y != s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator <=(type const& s_rh) const
{
	return ttvec2<bool>(x <= s_rh, y <= s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator >=(type const& s_rh) const
{
	return ttvec2<bool>(x >= s_rh, y >= s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator <(type const& s_rh) const
{
	return ttvec2<bool>(x < s_rh, y < s_rh);
}
template <typename type>
inline ttvec2<bool> const ttvec2<type>::operator >(type const& s_rh) const
{
	return ttvec2<bool>(x > s_rh, y > s_rh);
}
template <typename type>
inline type const ttvec2<type>::operator [](index const i) const
{
	return xy[i];
}
template <typename type>
inline ttvec2<type>::operator type const* () const
{
	return xy;
}

template <typename type>
inline ttvec2<type>& ttvec2<type>::operator =(ttvec2 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator =(stvec2<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator +=(ttvec2 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator -=(ttvec2 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator *=(ttvec2 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator /=(ttvec2 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator %=(ttvec2 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator &=(ttvec2 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator |=(ttvec2 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator ^=(ttvec2 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator <<=(ttvec2 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator >>=(ttvec2 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator =(type const& s_rh)
{
	x = y = s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	return *this;
}
template <typename type>
inline ttvec2<type>& ttvec2<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttvec2<type>::operator [](index const i)
{
	return xy[i];
}
template <typename type>
inline ttvec2<type>::operator type* ()
{
	return xy;
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttvec3<type>::ttvec3(type const& xyz)
	: x(xyz), y(xyz), z(xyz)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(type const& xc, type const& yc, type const& zc)
	: x(xc), y(yc), z(zc)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(bool const* xyz)
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(i32 const* xyz)
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(uint const* xyz)
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(flt const* xyz)
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(dbl const* xyz)
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec2<type> const& xy, type const& zc)
	: x(xy.x), y(xy.y), z(zc)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(type const& xc, ttvec2<type> const& yz)
	: x(xc), y(yz.x), z(yz.y)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec3 const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec4<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(stvec2<type> const& xy, type const& zc)
	: x(xy.x), y(xy.y), z(zc)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(type const& xc, stvec2<type> const& yz)
	: x(xc), y(yz.x), z(yz.y)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(stvec3<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}
template <typename type>
inline ttvec3<type>::ttvec3(stvec4<type> const& xyz)
	: x(xyz.x), y(xyz.y), z(xyz.z)
{
}

template <typename type>
inline ttvec3<type> const ttvec3<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator -() const
{
	return ttvec3(-x, -y, -z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator ~() const
{
	return ttvec3(~x, ~y, ~z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator +(ttvec3 const& v_rh) const
{
	return ttvec3(x + v_rh.x, y + v_rh.y, z + v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator -(ttvec3 const& v_rh) const
{
	return ttvec3(x - v_rh.x, y - v_rh.y, z - v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator *(ttvec3 const& v_rh) const
{
	return ttvec3(x * v_rh.x, y * v_rh.y, z * v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator /(ttvec3 const& v_rh) const
{
	return ttvec3(x / v_rh.x, y / v_rh.y, z / v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator %(ttvec3 const& v_rh) const
{
	return ttvec3(x % v_rh.x, y % v_rh.y, z % v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator &(ttvec3 const& v_rh) const
{
	return ttvec3(x & v_rh.x, y & v_rh.y, z & v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator |(ttvec3 const& v_rh) const
{
	return ttvec3(x | v_rh.x, y | v_rh.y, z | v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator ^(ttvec3 const& v_rh) const
{
	return ttvec3(x ^ v_rh.x, y ^ v_rh.y, z ^ v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator <<(ttvec3 const& v_rh) const
{
	return ttvec3(x << v_rh.x, y << v_rh.y, z << v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator >>(ttvec3 const& v_rh) const
{
	return ttvec3(x >> v_rh.x, y >> v_rh.y, z >> v_rh.z);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator +(type const& s_rh) const
{
	return ttvec3(x + s_rh, y + s_rh, z + s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator -(type const& s_rh) const
{
	return ttvec3(x - s_rh, y - s_rh, z - s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator *(type const& s_rh) const
{
	return ttvec3(x * s_rh, y * s_rh, z * s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator /(type const& s_rh) const
{
	return ttvec3(x / s_rh, y / s_rh, z / s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator %(type const& s_rh) const
{
	return ttvec3(x % s_rh, y % s_rh, z % s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator &(type const& s_rh) const
{
	return ttvec3(x & s_rh, y & s_rh, z & s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator |(type const& s_rh) const
{
	return ttvec3(x | s_rh, y | s_rh, z | s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator ^(type const& s_rh) const
{
	return ttvec3(x ^ s_rh, y ^ s_rh, z ^ s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator <<(type const& s_rh) const
{
	return ttvec3(x << s_rh, y << s_rh, z << s_rh);
}
template <typename type>
inline ttvec3<type> const ttvec3<type>::operator >>(type const& s_rh) const
{
	return ttvec3(x >> s_rh, y >> s_rh, z >> s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator !() const
{
	return ttvec3<bool>(!x, !y, !z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator ==(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x == v_rh.x, y == v_rh.y, z == v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator !=(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x != v_rh.x, y != v_rh.y, z != v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator <=(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x <= v_rh.x, y <= v_rh.y, z <= v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator >=(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x >= v_rh.x, y >= v_rh.y, z >= v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator <(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x < v_rh.x, y < v_rh.y, z < v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator >(ttvec3 const& v_rh) const
{
	return ttvec3<bool>(x > v_rh.x, y > v_rh.y, z > v_rh.z);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator ==(type const& s_rh) const
{
	return ttvec3<bool>(x == s_rh, y == s_rh, z == s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator !=(type const& s_rh) const
{
	return ttvec3<bool>(x != s_rh, y != s_rh, z != s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator <=(type const& s_rh) const
{
	return ttvec3<bool>(x <= s_rh, y <= s_rh, z <= s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator >=(type const& s_rh) const
{
	return ttvec3<bool>(x >= s_rh, y >= s_rh, z >= s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator <(type const& s_rh) const
{
	return ttvec3<bool>(x < s_rh, y < s_rh, z < s_rh);
}
template <typename type>
inline ttvec3<bool> const ttvec3<type>::operator >(type const& s_rh) const
{
	return ttvec3<bool>(x > s_rh, y > s_rh, z > s_rh);
}
template <typename type>
inline type const ttvec3<type>::operator [](index const i) const
{
	return xyz[i];
}
template <typename type>
inline ttvec3<type>::operator type const* () const
{
	return xyz;
}

template <typename type>
inline ttvec3<type>& ttvec3<type>::operator =(ttvec3 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator =(stvec3<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator +=(ttvec3 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	z += v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator -=(ttvec3 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	z -= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator *=(ttvec3 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	z *= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator /=(ttvec3 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	z /= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator %=(ttvec3 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	z %= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator &=(ttvec3 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	z &= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator |=(ttvec3 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	z |= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator ^=(ttvec3 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	z ^= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator <<=(ttvec3 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	z <<= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator >>=(ttvec3 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	z >>= v_rh.z;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator =(type const& s_rh)
{
	x = y = z = s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	z += s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	z -= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	z *= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	z /= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	z %= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	z &= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	z |= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	z ^= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	z <<= s_rh;
	return *this;
}
template <typename type>
inline ttvec3<type>& ttvec3<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	z >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttvec3<type>::operator [](index const i)
{
	return xyz[i];
}
template <typename type>
inline ttvec3<type>::operator type* ()
{
	return xyz;
}


//-----------------------------------------------------------------------------

template <typename type>
inline ttvec4<type>::ttvec4(type const& xyzw)
	: x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, type const& yc, type const& zc, type const& wc)
	: x(xc), y(yc), z(zc), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(bool const* xyzw)
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(i32 const* xyzw)
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(uint const* xyzw)
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(flt const* xyzw)
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(dbl const* xyzw)
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec2<type> const& xy, type const& zc, type const& wc)
	: x(xy.x), y(xy.y), z(zc), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, ttvec2<type> const& yz, type const& wc)
	: x(xc), y(yz.x), z(yz.y), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, type const& yc, ttvec2<type> const& zw)
	: x(xc), y(yc), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec2<type> const& xy, ttvec2<type> const& zw)
	: x(xy.x), y(xy.y), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec3<type> const& xyz, type const& wc)
	: x(xyz.x), y(xyz.y), z(xyz.z), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, ttvec3<type> const& yzw)
	: x(xc), y(yzw.x), z(yzw.y), w(yzw.z)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec4 const& xyzw)
	: x(xyzw.x), y(xyzw.y), z(xyzw.z), w(xyzw.w)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(stvec2<type> const& xy, type const& zc, type const& wc)
	: x(xy.x), y(xy.y), z(zc), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, stvec2<type> const& yz, type const& wc)
	: x(xc), y(yz.x), z(yz.y), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, type const& yc, stvec2<type> const& zw)
	: x(xc), y(yc), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(stvec2<type> const& xy, stvec2<type> const& zw)
	: x(xy.x), y(xy.y), z(zw.x), w(zw.y)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(stvec3<type> const& xyz, type const& wc)
	: x(xyz.x), y(xyz.y), z(xyz.z), w(wc)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(type const& xc, stvec3<type> const& yzw)
	: x(xc), y(yzw.x), z(yzw.y), w(yzw.z)
{
}
template <typename type>
inline ttvec4<type>::ttvec4(stvec4<type> const& xyzw)
	: x(xyzw.x), y(xyzw.y), z(xyzw.z), w(xyzw.w)
{
}

template <typename type>
inline ttvec4<type> const ttvec4<type>::operator +() const
{
	return *this;
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator -() const
{
	return ttvec4(-x, -y, -z, -w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator ~() const
{
	return ttvec4(~x, ~y, ~z, ~w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator +(ttvec4 const& v_rh) const
{
	return ttvec4(x + v_rh.x, y + v_rh.y, z + v_rh.z, w + v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator -(ttvec4 const& v_rh) const
{
	return ttvec4(x - v_rh.x, y - v_rh.y, z - v_rh.z, w - v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator *(ttvec4 const& v_rh) const
{
	return ttvec4(x * v_rh.x, y * v_rh.y, z * v_rh.z, w * v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator /(ttvec4 const& v_rh) const
{
	return ttvec4(x / v_rh.x, y / v_rh.y, z / v_rh.z, w / v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator %(ttvec4 const& v_rh) const
{
	return ttvec4(x % v_rh.x, y % v_rh.y, z % v_rh.z, w % v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator &(ttvec4 const& v_rh) const
{
	return ttvec4(x & v_rh.x, y & v_rh.y, z & v_rh.z, w & v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator |(ttvec4 const& v_rh) const
{
	return ttvec4(x | v_rh.x, y | v_rh.y, z | v_rh.z, w | v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator ^(ttvec4 const& v_rh) const
{
	return ttvec4(x ^ v_rh.x, y ^ v_rh.y, z ^ v_rh.z, w ^ v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator <<(ttvec4 const& v_rh) const
{
	return ttvec4(x << v_rh.x, y << v_rh.y, z << v_rh.z, w << v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator >>(ttvec4 const& v_rh) const
{
	return ttvec4(x >> v_rh.x, y >> v_rh.y, z >> v_rh.z, w >> v_rh.w);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator +(type const& s_rh) const
{
	return ttvec4(x + s_rh, y + s_rh, z + s_rh, w + s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator -(type const& s_rh) const
{
	return ttvec4(x - s_rh, y - s_rh, z - s_rh, w - s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator *(type const& s_rh) const
{
	return ttvec4(x * s_rh, y * s_rh, z * s_rh, w * s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator /(type const& s_rh) const
{
	return ttvec4(x / s_rh, y / s_rh, z / s_rh, w / s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator %(type const& s_rh) const
{
	return ttvec4(x % s_rh, y % s_rh, z % s_rh, w % s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator &(type const& s_rh) const
{
	return ttvec4(x & s_rh, y & s_rh, z & s_rh, w & s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator |(type const& s_rh) const
{
	return ttvec4(x | s_rh, y | s_rh, z | s_rh, w | s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator ^(type const& s_rh) const
{
	return ttvec4(x ^ s_rh, y ^ s_rh, z ^ s_rh, w ^ s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator <<(type const& s_rh) const
{
	return ttvec4(x << s_rh, y << s_rh, z << s_rh, w << s_rh);
}
template <typename type>
inline ttvec4<type> const ttvec4<type>::operator >>(type const& s_rh) const
{
	return ttvec4(x >> s_rh, y >> s_rh, z >> s_rh, w >> s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator !() const
{
	return ttvec4<bool>(!x, !y, !z, !w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator ==(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x == v_rh.x, y == v_rh.y, z == v_rh.z, w == v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator !=(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x != v_rh.x, y != v_rh.y, z != v_rh.z, w != v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator <=(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x <= v_rh.x, y <= v_rh.y, z <= v_rh.z, w <= v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator >=(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x >= v_rh.x, y >= v_rh.y, z >= v_rh.z, w >= v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator <(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x < v_rh.x, y < v_rh.y, z < v_rh.z, w < v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator >(ttvec4 const& v_rh) const
{
	return ttvec4<bool>(x > v_rh.x, y > v_rh.y, z > v_rh.z, w > v_rh.w);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator ==(type const& s_rh) const
{
	return ttvec4<bool>(x == s_rh, y == s_rh, z == s_rh, w == s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator !=(type const& s_rh) const
{
	return ttvec4<bool>(x != s_rh, y != s_rh, z != s_rh, w != s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator <=(type const& s_rh) const
{
	return ttvec4<bool>(x <= s_rh, y <= s_rh, z <= s_rh, w <= s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator >=(type const& s_rh) const
{
	return ttvec4<bool>(x >= s_rh, y >= s_rh, z >= s_rh, w >= s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator <(type const& s_rh) const
{
	return ttvec4<bool>(x < s_rh, y < s_rh, z < s_rh, w < s_rh);
}
template <typename type>
inline ttvec4<bool> const ttvec4<type>::operator >(type const& s_rh) const
{
	return ttvec4<bool>(x > s_rh, y > s_rh, z > s_rh, w > s_rh);
}
template <typename type>
inline type const ttvec4<type>::operator [](index const i) const
{
	return xyzw[i];
}
template <typename type>
inline ttvec4<type>::operator type const* () const
{
	return xyzw;
}

template <typename type>
inline ttvec4<type>& ttvec4<type>::operator =(ttvec4 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	w = v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator =(stvec4<type> const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	z = v_rh.z;
	w = v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator +=(ttvec4 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	z += v_rh.z;
	w += v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator -=(ttvec4 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	z -= v_rh.z;
	w -= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator *=(ttvec4 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	z *= v_rh.z;
	w *= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator /=(ttvec4 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	z /= v_rh.z;
	w /= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator %=(ttvec4 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	z %= v_rh.z;
	w %= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator &=(ttvec4 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	z &= v_rh.z;
	w &= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator |=(ttvec4 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	z |= v_rh.z;
	w |= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator ^=(ttvec4 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	z ^= v_rh.z;
	w ^= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator <<=(ttvec4 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	z <<= v_rh.z;
	w <<= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator >>=(ttvec4 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	z >>= v_rh.z;
	w >>= v_rh.w;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator =(type const& s_rh)
{
	x = y = z = w = s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	y += s_rh;
	z += s_rh;
	w += s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	z -= s_rh;
	w -= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	z *= s_rh;
	w *= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	z /= s_rh;
	w /= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	z %= s_rh;
	w %= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	z &= s_rh;
	w &= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	z |= s_rh;
	w |= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	z ^= s_rh;
	w ^= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	z <<= s_rh;
	w <<= s_rh;
	return *this;
}
template <typename type>
inline ttvec4<type>& ttvec4<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	z >>= s_rh;
	w >>= s_rh;
	return *this;
}
template <typename type>
inline type& ttvec4<type>::operator [](index const i)
{
	return xyzw[i];
}
template <typename type>
inline ttvec4<type>::operator type* ()
{
	return xyzw;
}


//-----------------------------------------------------------------------------

template<typename type>
inline ttvec1<type> stvec1<type>::operator =(ttvec1<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	return ttvec1<type>(*this);
}
template<typename type>
inline ttvec1<type> stvec1<type>::operator =(stvec1 const& v)
{
	return (*this = ttvec1<type>(v));
}
template<typename type>
inline ttvec1<type> stvec1<type>::operator =(type const& xc)
{
	return (*this = ttvec1<type>(xc));
}
template<typename type>
inline stvec1<type>::stvec1(type& xr)
	: x(xr)
{
}


template<typename type>
inline ttvec2<type> stvec2<type>::operator =(ttvec2<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	return ttvec2<type>(*this);
}
template<typename type>
inline ttvec2<type> stvec2<type>::operator =(stvec2 const& v)
{
	return (*this = ttvec2<type>(v));
}
template<typename type>
inline ttvec2<type> stvec2<type>::operator =(type const& xy)
{
	return (*this = ttvec2<type>(xy));
}
template<typename type>
inline stvec2<type>::stvec2(type& xr, type& yr)
	: x(xr), y(yr)
{
}


template<typename type>
inline ttvec3<type> stvec3<type>::operator =(ttvec3<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	return ttvec3<type>(*this);
}
template<typename type>
inline ttvec3<type> stvec3<type>::operator =(stvec3 const& v)
{
	return (*this = ttvec3<type>(v));
}
template<typename type>
inline ttvec3<type> stvec3<type>::operator =(type const& xyz)
{
	return (*this = ttvec3<type>(xyz));
}
template<typename type>
inline stvec3<type>::stvec3(type& xr, type& yr, type& zr)
	: x(xr), y(yr), z(zr)
{
}


template<typename type>
inline ttvec4<type> stvec4<type>::operator =(ttvec4<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	return ttvec4<type>(*this);
}
template<typename type>
inline ttvec4<type> stvec4<type>::operator =(stvec4 const& v)
{
	return (*this = ttvec4<type>(v));
}
template<typename type>
inline ttvec4<type> stvec4<type>::operator =(type const& xyzw)
{
	return (*this = ttvec4<type>(xyzw));
}
template<typename type>
inline stvec4<type>::stvec4(type& xr, type& yr, type& zr, type& wr)
	: x(xr), y(yr), z(zr), w(wr)
{
}


//-----------------------------------------------------------------------------

template<typename type>
inline ttvec2<type> const operator +(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttvec2<type> const operator -(type const& s_lh, ttvec2<type> const& v_rh)
{
	return ttvec2<type>(s_lh - v_rh.x, s_lh - v_rh.y);
}
template<typename type>
inline ttvec2<type> const operator *(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttvec2<type> const operator /(type const& s_lh, ttvec2<type> const& v_rh)
{
	return ttvec2<type>(s_lh / v_rh.x, s_lh / v_rh.y);
}
template<typename type>
inline ttvec2<type> const operator %(type const& s_lh, ttvec2<type> const& v_rh)
{
	return ttvec2<type>(s_lh % v_rh.x, s_lh % v_rh.y);
}
template<typename type>
inline ttvec2<type> const operator &(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttvec2<type> const operator |(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttvec2<type> const operator ^(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttvec2<type> const operator <<(type const& s_lh, ttvec2<type> const& v_rh)
{
	return ttvec2<type>(s_lh << v_rh.x, s_lh << v_rh.y);
}
template<typename type>
inline ttvec2<type> const operator >>(type const& s_lh, ttvec2<type> const& v_rh)
{
	return ttvec2<type>(s_lh >> v_rh.x, s_lh >> v_rh.y);
}
template<typename type>
inline ttvec2<bool> const operator ==(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttvec2<bool> const operator !=(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttvec2<bool> const operator <=(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttvec2<bool> const operator >=(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttvec2<bool> const operator <(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttvec2<bool> const operator >(type const& s_lh, ttvec2<type> const& v_rh)
{
	return (v_rh > s_lh);
}


template<typename type>
inline ttvec3<type> const operator +(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttvec3<type> const operator -(type const& s_lh, ttvec3<type> const& v_rh)
{
	return ttvec3<type>(s_lh - v_rh.x, s_lh - v_rh.y, s_lh - v_rh.z);
}
template<typename type>
inline ttvec3<type> const operator *(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttvec3<type> const operator /(type const& s_lh, ttvec3<type> const& v_rh)
{
	return ttvec3<type>(s_lh / v_rh.x, s_lh / v_rh.y, s_lh / v_rh.z);
}
template<typename type>
inline ttvec3<type> const operator %(type const& s_lh, ttvec3<type> const& v_rh)
{
	return ttvec3<type>(s_lh % v_rh.x, s_lh % v_rh.y, s_lh % v_rh.z);
}
template<typename type>
inline ttvec3<type> const operator &(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttvec3<type> const operator |(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttvec3<type> const operator ^(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttvec3<type> const operator <<(type const& s_lh, ttvec3<type> const& v_rh)
{
	return ttvec3<type>(s_lh << v_rh.x, s_lh << v_rh.y, s_lh << v_rh.z);
}
template<typename type>
inline ttvec3<type> const operator >>(type const& s_lh, ttvec3<type> const& v_rh)
{
	return ttvec3<type>(s_lh >> v_rh.x, s_lh >> v_rh.y, s_lh >> v_rh.z);
}
template<typename type>
inline ttvec3<bool> const operator ==(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttvec3<bool> const operator !=(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttvec3<bool> const operator <=(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttvec3<bool> const operator >=(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttvec3<bool> const operator <(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttvec3<bool> const operator >(type const& s_lh, ttvec3<type> const& v_rh)
{
	return (v_rh > s_lh);
}


template<typename type>
inline ttvec4<type> const operator +(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh + s_lh);
}
template<typename type>
inline ttvec4<type> const operator -(type const& s_lh, ttvec4<type> const& v_rh)
{
	return ttvec4<type>(s_lh - v_rh.x, s_lh - v_rh.y, s_lh - v_rh.z, s_lh - v_rh.w);
}
template<typename type>
inline ttvec4<type> const operator *(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh * s_lh);
}
template<typename type>
inline ttvec4<type> const operator /(type const& s_lh, ttvec4<type> const& v_rh)
{
	return ttvec4<type>(s_lh / v_rh.x, s_lh / v_rh.y, s_lh / v_rh.z, s_lh / v_rh.w);
}
template<typename type>
inline ttvec4<type> const operator %(type const& s_lh, ttvec4<type> const& v_rh)
{
	return ttvec4<type>(s_lh % v_rh.x, s_lh % v_rh.y, s_lh % v_rh.z, s_lh % v_rh.w);
}
template<typename type>
inline ttvec4<type> const operator &(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh & s_lh);
}
template<typename type>
inline ttvec4<type> const operator |(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh | s_lh);
}
template<typename type>
inline ttvec4<type> const operator ^(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh ^ s_lh);
}
template<typename type>
inline ttvec4<type> const operator <<(type const& s_lh, ttvec4<type> const& v_rh)
{
	return ttvec4<type>(s_lh << v_rh.x, s_lh << v_rh.y, s_lh << v_rh.z, s_lh << v_rh.w);
}
template<typename type>
inline ttvec4<type> const operator >>(type const& s_lh, ttvec4<type> const& v_rh)
{
	return ttvec4<type>(s_lh >> v_rh.x, s_lh >> v_rh.y, s_lh >> v_rh.z, s_lh >> v_rh.w);
}
template<typename type>
inline ttvec4<bool> const operator ==(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh == s_lh);
}
template<typename type>
inline ttvec4<bool> const operator !=(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh != s_lh);
}
template<typename type>
inline ttvec4<bool> const operator <=(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh <= s_lh);
}
template<typename type>
inline ttvec4<bool> const operator >=(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh >= s_lh);
}
template<typename type>
inline ttvec4<bool> const operator <(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh < s_lh);
}
template<typename type>
inline ttvec4<bool> const operator >(type const& s_lh, ttvec4<type> const& v_rh)
{
	return (v_rh > s_lh);
}


//-----------------------------------------------------------------------------

template<typename type>
inline type const dot(ttvec1<type> const& v_lh, ttvec1<type> const& v_rh)
{
	return (v_lh.x * v_rh.x);
}
template<typename type>
inline type const lengthSq(ttvec1<type> const& v)
{
	return (v.x * v.x);
	//return dot<type>(v, v); // for consistency
}
template<typename type>
inline type const length(ttvec1<type> const& v)
{
	return ijk_abs(v.x);
	//return (type)ijkSqrt((real)lengthSq<type>(v)); // for consistency
}
template<typename type>
inline type const lengthSqInv(ttvec1<type> const& v)
{
	type const lenSq = lengthSq<type>(v);
	return (type)ijk_recip((real)lenSq);
}
template<typename type>
inline type const lengthInv(ttvec1<type> const& v)
{
	type const len = length<type>(v);
	return (type)ijk_recip((real)len);
	//type const lenSq = lengthSq<type>(v); // for consistency
	//return (type)ijkSqrtInv((real)lenSq); // for consistency
}
template<typename type>
inline ttvec1<type> const normalize(ttvec1<type> const& v)
{
	return ijk_sgn(v.x);
	//return (v * (type)ijkSqrtInv((real)lengthSq<type>(v))); // for consistency
}
template<typename type>
inline ttvec1<type>& normalizeSet(ttvec1<type>& v)
{
	return (v.x = ijk_sgn(v.x));
	//return (v *= (type)ijkSqrtInv((real)lengthSq<type>(v))); // for consistency
}
template<typename type>
inline ttvec1<type> const lerp(ttvec1<type> const& v0, ttvec1<type> const& v1, type const u)
{
	return ttvec1<type>(ijk_lerp(v0.x, v1.x, u));
}
template<typename type>
inline ttvec1<type> const unlerp(ttvec1<type> const& v0, ttvec1<type> const& v1, ttvec1<type> const& v)
{
	return ttvec1<type>(ijk_unlerp(v0.x, v1.x, v.x));
}


template<typename type>
inline type const dot(ttvec2<type> const& v_lh, ttvec2<type> const& v_rh)
{
	return (v_lh.x * v_rh.x + v_lh.y * v_rh.y);
}
template<typename type>
inline type const lengthSq(ttvec2<type> const& v)
{
	return dot<type>(v, v);
}
template<typename type>
inline type const length(ttvec2<type> const& v)
{
	return (type)ijkSqrt((real)lengthSq<type>(v));
}
template<typename type>
inline type const lengthSqInv(ttvec2<type> const& v)
{
	type const lenSq = lengthSq<type>(v);
	return (type)ijk_recip((real)lenSq);
}
template<typename type>
inline type const lengthInv(ttvec2<type> const& v)
{
	type const lenSq = lengthSq<type>(v);
	return (type)ijkSqrtInv((real)lenSq);
}
template<typename type>
inline ttvec2<type> const normalize(ttvec2<type> const& v)
{
	return (v * (type)ijkSqrtInv((real)lengthSq<type>(v)));
}
template<typename type>
inline ttvec2<type>& normalizeSet(ttvec2<type>& v)
{
	return (v *= (type)ijkSqrtInv((real)lengthSq<type>(v)));
}
template<typename type>
inline ttvec2<type> const lerp(ttvec2<type> const& v0, ttvec2<type> const& v1, type const u)
{
	return ttvec2<type>(ijk_lerp(v0.x, v1.x, u), ijk_lerp(v0.y, v1.y, u));
}
template<typename type>
inline ttvec2<type> const unlerp(ttvec2<type> const& v0, ttvec2<type> const& v1, ttvec2<type> const& v)
{
	return ttvec2<type>(ijk_unlerp(v0.x, v1.x, v.x), ijk_unlerp(v0.y, v1.y, v.x));
}
template<typename type>
inline type const cross(ttvec2<type> const& v_lh, ttvec2<type> const& v_rh)
{

}
template<typename type>
inline type const crossNormalize(ttvec2<type> const& v_lh, ttvec2<type> const& v_rh)
{

}
template<typename type>
inline ttvec2<type> const project(ttvec2<type> const& v_base, ttvec2<type> const& v)
{

}
template<typename type>
inline ttvec2<type>& projectSet(ttvec2<type> const& v_base, ttvec2<type>& v)
{

}
template<typename type>
inline ttvec2<type> const projectOrtho(ttvec2<type> const& v_base, ttvec2<type> const& v)
{

}
template<typename type>
inline ttvec2<type>& projectOrthoSet(ttvec2<type> const& v_base, ttvec2<type>& v)
{

}


//-----------------------------------------------------------------------------

#ifdef IJK_VECTOR_SWIZZLE
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 2, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 3, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 4, inline);

IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 2, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 3, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 4, inline);
#endif	// IJK_VECTOR_SWIZZLE

//-----------------------------------------------------------------------------

#endif	// __cplusplus


#endif	// !_IJK_VECTORSWIZZLE_INL_