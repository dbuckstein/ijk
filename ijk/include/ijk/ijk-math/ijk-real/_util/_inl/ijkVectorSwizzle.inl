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

	ijkVectorSwizzle.inl
	Inline definitions for vector swizzling types (C++).
*/

#ifdef _IJK_VECTORSWIZZLE_H_
#ifndef _IJK_VECTORSWIZZLE_INL_
#define _IJK_VECTORSWIZZLE_INL_


#ifdef __cplusplus

//-----------------------------------------------------------------------------
/*
ttvec1 const operator +() const;
ttvec1 const operator -() const;
ttvec1 const operator ~() const;
ttvec1 const operator +(ttvec1 const& v_rh) const;
ttvec1 const operator -(ttvec1 const& v_rh) const;
ttvec1 const operator *(ttvec1 const& v_rh) const;
ttvec1 const operator /(ttvec1 const& v_rh) const;
ttvec1 const operator %(ttvec1 const& v_rh) const;
ttvec1 const operator &(ttvec1 const& v_rh) const;
ttvec1 const operator |(ttvec1 const& v_rh) const;
ttvec1 const operator ^(ttvec1 const& v_rh) const;
ttvec1 const operator <<(ttvec1 const& v_rh) const;
ttvec1 const operator >>(ttvec1 const& v_rh) const;
ttvec1 const operator +(type const& s_rh) const;
ttvec1 const operator -(type const& s_rh) const;
ttvec1 const operator *(type const& s_rh) const;
ttvec1 const operator /(type const& s_rh) const;
ttvec1 const operator %(type const& s_rh) const;
ttvec1 const operator &(type const& s_rh) const;
ttvec1 const operator |(type const& s_rh) const;
ttvec1 const operator ^(type const& s_rh) const;
ttvec1 const operator <<(type const& s_rh) const;
ttvec1 const operator >>(type const& s_rh) const;
ttvec1<bool> const operator !() const;
ttvec1<bool> const operator ==(ttvec1 const& v_rh) const;
ttvec1<bool> const operator !=(ttvec1 const& v_rh) const;
ttvec1<bool> const operator <=(ttvec1 const& v_rh) const;
ttvec1<bool> const operator >=(ttvec1 const& v_rh) const;
ttvec1<bool> const operator <(ttvec1 const& v_rh) const;
ttvec1<bool> const operator >(ttvec1 const& v_rh) const;
ttvec1<bool> const operator ==(type const& s_rh) const;
ttvec1<bool> const operator !=(type const& s_rh) const;
ttvec1<bool> const operator <=(type const& s_rh) const;
ttvec1<bool> const operator >=(type const& s_rh) const;
ttvec1<bool> const operator <(type const& s_rh) const;
ttvec1<bool> const operator >(type const& s_rh) const;

ttvec1& operator +=(ttvec1 const& v_rh);
ttvec1& operator -=(ttvec1 const& v_rh);
ttvec1& operator *=(ttvec1 const& v_rh);
ttvec1& operator /=(ttvec1 const& v_rh);
ttvec1& operator %=(ttvec1 const& v_rh);
ttvec1& operator &=(ttvec1 const& v_rh);
ttvec1& operator |=(ttvec1 const& v_rh);
ttvec1& operator ^=(ttvec1 const& v_rh);
ttvec1& operator <<=(ttvec1 const& v_rh);
ttvec1& operator >>=(ttvec1 const& v_rh);
ttvec1& operator +=(type const& s_rh);
ttvec1& operator -=(type const& s_rh);
ttvec1& operator *=(type const& s_rh);
ttvec1& operator /=(type const& s_rh);
ttvec1& operator %=(type const& s_rh);
ttvec1& operator &=(type const& s_rh);
ttvec1& operator |=(type const& s_rh);
ttvec1& operator ^=(type const& s_rh);
ttvec1& operator <<=(type const& s_rh);
ttvec1& operator >>=(type const& s_rh);
*/
/*
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator +() const
{
	return *this;
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator -() const
{
	return ttvec1<type>(-x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator ~() const
{
	return ttvec1<type>(~x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator +(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x + v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator -(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x - v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator *(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x * v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator /(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x / v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator %(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x % v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator &(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x & v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator |(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x | v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator ^(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x ^ v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator <<(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x << v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator >>(ttvec1 const& v_rh) const
{
	return ttvec1<type>(x >> v_rh.x);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator +(type const& s_rh) const
{
	return ttvec1<type>(x + s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator -(type const& s_rh) const
{
	return ttvec1<type>(x - s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator *(type const& s_rh) const
{
	return ttvec1<type>(x * s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator /(type const& s_rh) const
{
	return ttvec1<type>(x / s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator %(type const& s_rh) const
{
	return ttvec1<type>(x % s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator &(type const& s_rh) const
{
	return ttvec1<type>(x & s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator |(type const& s_rh) const
{
	return ttvec1<type>(x | s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator ^(type const& s_rh) const
{
	return ttvec1<type>(x ^ s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator <<(type const& s_rh) const
{
	return ttvec1<type>(x << s_rh);
}
template<typename type>
inline ttvec1<type> const ttvec1<type>::operator >>(type const& s_rh) const
{
	return ttvec1<type>(x >> s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator !() const
{
	return ttvec1<bool>(!x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator ==(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x == v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator !=(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x != v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator <=(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x <= v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator >=(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x >= v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator <(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x < v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator >(ttvec1 const& v_rh) const
{
	return ttvec1<bool>(x > v_rh.x);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator ==(type const& s_rh) const
{
	return ttvec1<bool>(x == s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator !=(type const& s_rh) const
{
	return ttvec1<bool>(x != s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator <=(type const& s_rh) const
{
	return ttvec1<bool>(x <= s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator >=(type const& s_rh) const
{
	return ttvec1<bool>(x >= s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator <(type const& s_rh) const
{
	return ttvec1<bool>(x < s_rh);
}
template<typename type>
inline ttvec1<bool> const ttvec1<type>::operator >(type const& s_rh) const
{
	return ttvec1<bool>(x > s_rh);
}

template<typename type>
inline ttvec1<type>& ttvec1<type>::operator +=(ttvec1 const& v_rh)
{
	x += v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator -=(ttvec1 const& v_rh)
{
	x -= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator *=(ttvec1 const& v_rh)
{
	x *= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator /=(ttvec1 const& v_rh)
{
	x /= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator %=(ttvec1 const& v_rh)
{
	x %= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator &=(ttvec1 const& v_rh)
{
	x &= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator |=(ttvec1 const& v_rh)
{
	x |= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator ^=(ttvec1 const& v_rh)
{
	x ^= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator <<=(ttvec1 const& v_rh)
{
	x <<= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator >>=(ttvec1 const& v_rh)
{
	x >>= v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator +=(type const& s_rh)
{
	x += s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator -=(type const& s_rh)
{
	x -= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator *=(type const& s_rh)
{
	x *= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator /=(type const& s_rh)
{
	x /= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator %=(type const& s_rh)
{
	x %= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator &=(type const& s_rh)
{
	x &= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator |=(type const& s_rh)
{
	x |= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator ^=(type const& s_rh)
{
	x ^= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator <<=(type const& s_rh)
{
	x <<= s_rh;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator >>=(type const& s_rh)
{
	x >>= s_rh;
	return *this;
}
*/

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
inline ttvec1<type>& ttvec1<type>::operator =(ttvec1 const& v_rh)
{
	x = v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(stvec1<type> const& v_rh)
{
	x = v_rh.x;
	return *this;
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(type const& s_rh)
{
	x = s_rh;
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
inline ttvec2<type>::ttvec2(bool const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(i32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(i64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ui32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ui64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(f32 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(f64 const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<bool> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<i32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<i64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<ui32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<ui64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<f32> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
{
}
template <typename type>
inline ttvec2<type>::ttvec2(ttvec1<f64> const xy[2])
	: x((type)xy[0]), y((type)xy[1])
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
inline ttvec2<bool> const ttvec2<type>::operator !() const
{
	return ttvec2<bool>(!x, !y);
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
inline ttvec3<type>::ttvec3(bool const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(i32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(i64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ui32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ui64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(f32 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(f64 const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<bool> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<i32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<i64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<ui32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<ui64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<f32> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
{
}
template <typename type>
inline ttvec3<type>::ttvec3(ttvec1<f64> const xyz[3])
	: x((type)xyz[0]), y((type)xyz[1]), z((type)xyz[2])
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
inline ttvec3<bool> const ttvec3<type>::operator !() const
{
	return ttvec3<bool>(!x, !y, !z);
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
inline ttvec4<type>::ttvec4(bool const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(i32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(i64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ui32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ui64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(f32 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(f64 const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<bool> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<i32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<i64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<ui32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<ui64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<f32> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
{
}
template <typename type>
inline ttvec4<type>::ttvec4(ttvec1<f64> const xyzw[4])
	: x((type)xyzw[0]), y((type)xyzw[1]), z((type)xyzw[2]), w((type)xyzw[3])
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
inline ttvec4<bool> const ttvec4<type>::operator !() const
{
	return ttvec4<bool>(!x, !y, !z, !w);
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
inline ttvec1<type> const stvec1<type>::operator =(ttvec1<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	this->x = v.x;
	return ttvec1<type>(*this);
}
template<typename type>
inline ttvec1<type> const stvec1<type>::operator =(stvec1 const& v)
{
	return (*this = ttvec1<type>(v));
}
template<typename type>
inline ttvec1<type> const stvec1<type>::operator =(type const& xc)
{
	return (*this = ttvec1<type>(xc));
}
template<typename type>
inline stvec1<type>::stvec1(type& xr)
	: ttvec1<type>(xr), xr(xr)
{
}
template<typename type>
inline stvec1<type>::~stvec1()
{
	// assign final state
	xr = this->x;
}


template<typename type>
inline ttvec2<type> const stvec2<type>::operator =(ttvec2<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	this->x = v.x;
	this->y = v.y;
	return ttvec2<type>(*this);
}
template<typename type>
inline ttvec2<type> const stvec2<type>::operator =(stvec2 const& v)
{
	return (*this = ttvec2<type>(v));
}
template<typename type>
inline ttvec2<type> const stvec2<type>::operator =(type const& xy)
{
	return (*this = ttvec2<type>(xy));
}
template<typename type>
inline stvec2<type>::stvec2(type& xr, type& yr)
	: ttvec2<type>(xr, yr), xr(xr), yr(yr)
{
}
template<typename type>
inline stvec2<type>::~stvec2()
{
	// assign final state
	xr = this->x;
	yr = this->y;
}


template<typename type>
inline ttvec3<type> const stvec3<type>::operator =(ttvec3<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return ttvec3<type>(*this);
}
template<typename type>
inline ttvec3<type> const stvec3<type>::operator =(stvec3 const& v)
{
	return (*this = ttvec3<type>(v));
}
template<typename type>
inline ttvec3<type> const stvec3<type>::operator =(type const& xyz)
{
	return (*this = ttvec3<type>(xyz));
}
template<typename type>
inline stvec3<type>::stvec3(type& xr, type& yr, type& zr)
	: ttvec3<type>(xr, yr, zr), xr(xr), yr(yr), zr(zr)
{
}
template<typename type>
inline stvec3<type>::~stvec3()
{
	// assign final state
	xr = this->x;
	yr = this->y;
	zr = this->z;
}


template<typename type>
inline ttvec4<type> const stvec4<type>::operator =(ttvec4<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	return ttvec4<type>(*this);
}
template<typename type>
inline ttvec4<type> const stvec4<type>::operator =(stvec4 const& v)
{
	return (*this = ttvec4<type>(v));
}
template<typename type>
inline ttvec4<type> const stvec4<type>::operator =(type const& xyzw)
{
	return (*this = ttvec4<type>(xyzw));
}
template<typename type>
inline stvec4<type>::stvec4(type& xr, type& yr, type& zr, type& wr)
	: ttvec4<type>(xr, yr, zr, wr), xr(xr), yr(yr), zr(zr), wr(wr)
{
}
template<typename type>
inline stvec4<type>::~stvec4()
{
	// assign final state
	xr = this->x;
	yr = this->y;
	zr = this->z;
	wr = this->w;
}


//-----------------------------------------------------------------------------

#ifdef IJK_VECTOR_SWIZZLE
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 2, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 3, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 4, inline);
/*
IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 1);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 2);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 2, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 3);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 3, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 4);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 4, inline);
*/
#endif	// IJK_VECTOR_SWIZZLE


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_VECTORSWIZZLE_INL_
#endif	// _IJK_VECTORSWIZZLE_H_