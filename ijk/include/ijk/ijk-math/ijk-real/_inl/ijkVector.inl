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

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_INL_
#define _IJK_VECTOR_INL_


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#ifdef __cplusplus

//-----------------------------------------------------------------------------
/*
inline bvec2::bvec2(bool const& xy)
	: x(xy), y(xy)
{
}
inline bvec2::bvec2(bool const& xc, bool const& yc)
	: x(xc), y(yc)
{
}


//-----------------------------------------------------------------------------

inline bvec3::bvec3(bool const& xyz)
	: x(xyz), y(xyz), z(xyz)
{
}
inline bvec3::bvec3(bool const& xc, bool const& yc, bool const& zc)
	: x(xc), y(yc), z(zc)
{
}


//-----------------------------------------------------------------------------

inline bvec4::bvec4(bool const& xyzw)
	: x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{
}
inline bvec4::bvec4(bool const& xc, bool const& yc, bool const& zc, bool const& wc)
	: x(xc), y(yc), z(zc), w(wc)
{
}


//-----------------------------------------------------------------------------

inline ivec2::ivec2(int const& xy)
	: x(xy), y(xy)
{
}
inline ivec2::ivec2(int const& xc, int const& yc)
	: x(xc), y(yc)
{
}
inline ivec2::ivec2(int2 const xy)
	: x(xy[0]), y(xy[1])
{
}
inline ivec2::ivec2(uint2 const xy)
	: x(xy[0]), y(xy[1])
{
}
inline ivec2::ivec2(float2 const xy)
	: x((i32)xy[0]), y((i32)xy[1])
{
}
inline ivec2::ivec2(double2 const xy)
	: x((i32)xy[0]), y((i32)xy[1])
{
}
inline ivec2::ivec2(bvec2 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(bvec3 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(bvec4 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(ivec2 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(ivec3 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(ivec4 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(uvec2 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(uvec3 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(uvec4 const& xy)
	: x(xy.x), y(xy.y)
{
}
inline ivec2::ivec2(vec2 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(vec3 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(vec4 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(dvec2 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(dvec3 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(dvec4 const& xy)
	: x((i32)xy.x), y((i32)xy.y)
{
}
inline ivec2::ivec2(sivec2 const& xy)
	: x(xy.x), y(xy.y)
{
}

inline ivec2& ivec2::operator =(int2 const v_rh)
{
	x = v_rh[0];
	y = v_rh[1];
	return *this;
}
inline ivec2& ivec2::operator =(ivec2 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator =(sivec2 const& v_rh)
{
	x = v_rh.x;
	y = v_rh.y;
	return *this;
}

inline ivec2 ivec2::operator +() const
{
	return *this;
}
inline ivec2 ivec2::operator -() const
{
	return ivec2(-x, -y);
}
inline ivec2 ivec2::operator ~() const
{
	return ivec2(~x, ~y);
}
inline ivec2 ivec2::operator +(ivec2 const& v_rh) const
{
	return ivec2(x + v_rh.x, y + v_rh.y);
}
inline ivec2 ivec2::operator -(ivec2 const& v_rh) const
{
	return ivec2(x - v_rh.x, y - v_rh.y);
}
inline ivec2 ivec2::operator *(ivec2 const& v_rh) const
{
	return ivec2(x * v_rh.x, y * v_rh.y);
}
inline ivec2 ivec2::operator /(ivec2 const& v_rh) const
{
	return ivec2(x / v_rh.x, y / v_rh.y);
}
inline ivec2 ivec2::operator %(ivec2 const& v_rh) const
{
	return ivec2(x % v_rh.x, y % v_rh.y);
}
inline ivec2 ivec2::operator &(ivec2 const& v_rh) const
{
	return ivec2(x & v_rh.x, y & v_rh.y);
}
inline ivec2 ivec2::operator |(ivec2 const& v_rh) const
{
	return ivec2(x | v_rh.x, y | v_rh.y);
}
inline ivec2 ivec2::operator ^(ivec2 const& v_rh) const
{
	return ivec2(x ^ v_rh.x, y ^ v_rh.y);
}
inline ivec2 ivec2::operator <<(ivec2 const& v_rh) const
{
	return ivec2(x << v_rh.x, y << v_rh.y);
}
inline ivec2 ivec2::operator >>(ivec2 const& v_rh) const
{
	return ivec2(x >> v_rh.x, y >> v_rh.y);
}
inline bvec2 ivec2::operator ==(ivec2 const& v_rh) const
{
	return bvec2(x == v_rh.x, y == v_rh.y);
}
inline bvec2 ivec2::operator !=(ivec2 const& v_rh) const
{
	return bvec2(x != v_rh.x, y != v_rh.y);
}
inline bvec2 ivec2::operator <=(ivec2 const& v_rh) const
{
	return bvec2(x <= v_rh.x, y <= v_rh.y);
}
inline bvec2 ivec2::operator >=(ivec2 const& v_rh) const
{
	return bvec2(x >= v_rh.x, y >= v_rh.y);
}
inline bvec2 ivec2::operator <(ivec2 const& v_rh) const
{
	return bvec2(x < v_rh.x, y < v_rh.y);
}
inline bvec2 ivec2::operator >(ivec2 const& v_rh) const
{
	return bvec2(x > v_rh.x, y > v_rh.y);
}
inline ivec2 ivec2::operator +(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator -(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator *(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator /(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator %(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator &(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator |(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator ^(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator <<(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline ivec2 ivec2::operator >>(int const& s_rh) const
{
	return ivec2(x + s_rh, y + s_rh);
}
inline bvec2 ivec2::operator ==(int const& s_rh) const
{
	return bvec2(x == s_rh, y == s_rh);
}
inline bvec2 ivec2::operator !=(int const& s_rh) const
{
	return bvec2(x != s_rh, y != s_rh);
}
inline bvec2 ivec2::operator <=(int const& s_rh) const
{
	return bvec2(x <= s_rh, y <= s_rh);
}
inline bvec2 ivec2::operator >=(int const& s_rh) const
{
	return bvec2(x >= s_rh, y >= s_rh);
}
inline bvec2 ivec2::operator <(int const& s_rh) const
{
	return bvec2(x < s_rh, y < s_rh);
}
inline bvec2 ivec2::operator >(int const& s_rh) const
{
	return bvec2(x > s_rh, y > s_rh);
}
inline int ivec2::operator [](index const i) const
{
	return xy[i];
}
inline ivec2::operator intkv () const
{
	return xy;
}
inline ivec2::operator i32 const* () const
{
	return (i32 const*)xy;
}

inline ivec2& ivec2::operator +=(ivec2 const& v_rh)
{
	x += v_rh.x;
	y += v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator -=(ivec2 const& v_rh)
{
	x -= v_rh.x;
	y -= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator *=(ivec2 const& v_rh)
{
	x *= v_rh.x;
	y *= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator /=(ivec2 const& v_rh)
{
	x /= v_rh.x;
	y /= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator %=(ivec2 const& v_rh)
{
	x %= v_rh.x;
	y %= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator &=(ivec2 const& v_rh)
{
	x &= v_rh.x;
	y &= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator |=(ivec2 const& v_rh)
{
	x |= v_rh.x;
	y |= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator ^=(ivec2 const& v_rh)
{
	x ^= v_rh.x;
	y ^= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator <<=(ivec2 const& v_rh)
{
	x <<= v_rh.x;
	y <<= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator >>=(ivec2 const& v_rh)
{
	x >>= v_rh.x;
	y >>= v_rh.y;
	return *this;
}
inline ivec2& ivec2::operator +=(int const& s_rh)
{
	x += s_rh;
	y += s_rh;
	return *this;
}
inline ivec2& ivec2::operator -=(int const& s_rh)
{
	x -= s_rh;
	y -= s_rh;
	return *this;
}
inline ivec2& ivec2::operator *=(int const& s_rh)
{
	x *= s_rh;
	y *= s_rh;
	return *this;
}
inline ivec2& ivec2::operator /=(int const& s_rh)
{
	x /= s_rh;
	y /= s_rh;
	return *this;
}
inline ivec2& ivec2::operator %=(int const& s_rh)
{
	x %= s_rh;
	y %= s_rh;
	return *this;
}
inline ivec2& ivec2::operator &=(int const& s_rh)
{
	x &= s_rh;
	y &= s_rh;
	return *this;
}
inline ivec2& ivec2::operator |=(int const& s_rh)
{
	x |= s_rh;
	y |= s_rh;
	return *this;
}
inline ivec2& ivec2::operator ^=(int const& s_rh)
{
	x ^= s_rh;
	y ^= s_rh;
	return *this;
}
inline ivec2& ivec2::operator <<=(int const& s_rh)
{
	x <<= s_rh;
	y <<= s_rh;
	return *this;
}
inline ivec2& ivec2::operator >>=(int const& s_rh)
{
	x >>= s_rh;
	y >>= s_rh;
	return *this;
}
inline int& ivec2::operator [](index const i)
{
	return xy[i];
}
inline ivec2::operator intv ()
{
	return xy;
}
inline ivec2::operator i32* ()
{
	return (i32*)xy;
}


//-----------------------------------------------------------------------------

inline ivec3::ivec3(int const& xyz)
	: x(xyz), y(xyz), z(xyz)
{
}
inline ivec3::ivec3(int const& xc, int const& yc, int const& zc)
	: x(xc), y(yc), z(zc)
{
}


//-----------------------------------------------------------------------------

inline ivec4::ivec4(int const& xyzw)
	: x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{
}
inline ivec4::ivec4(int const& xc, int const& yc, int const& zc, int const& wc)
	: x(xc), y(yc), z(zc), w(wc)
{
}


//-----------------------------------------------------------------------------
*/


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

//IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL, IJK_SWIZZLE_IMPL, ivec, sivec, ivec, 2, inline);



#endif	// __cplusplus


#include "ijkVectorSwizzle.inl"


#endif	// !_IJK_VECTOR_INL_
#endif	// _IJK_VECTOR_H_