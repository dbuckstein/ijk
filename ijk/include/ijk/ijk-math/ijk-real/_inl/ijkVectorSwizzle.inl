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

#if (defined _IJK_VECTORSWIZZLE_H_ && defined _IJK_VECTOR_INL_)
#ifndef _IJK_VECTORSWIZZLE_INL_
#define _IJK_VECTORSWIZZLE_INL_


#ifdef __cplusplus
/*
//-----------------------------------------------------------------------------

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
*/

//-----------------------------------------------------------------------------

template<typename type>
inline ttvec1<type>::ttvec1(type const& xc)
	: x(xc)
{
}
template<typename type>
inline ttvec1<type>& ttvec1<type>::operator =(type const& xc)
{
	x = xc;
	return *this;
}
template<typename type>
inline ttvec1<type>::operator type () const
{
	return x;
}
template<typename type>
inline ttvec1<type>::operator type& ()
{
	return x;
}


//-----------------------------------------------------------------------------

template<typename type>
inline ttvec1<type> stvec1<type>::operator =(ttvec1<type> const v)
{
	// pass-by-value is deliberate; need copy in case 'v' is the swizzle target
	return ttvec1<type>(x = v.x);
}
template<typename type>
inline ttvec1<type> stvec1<type>::operator =(stvec1 const& v)
{
	return (*this = ttvec1<type>(v));
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
	return ttvec2<type>(x = v.x, y = v.x);
}
template<typename type>
inline ttvec2<type> stvec2<type>::operator =(stvec2 const& v)
{
	return (*this = ttvec2<type>(v));
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
	return ttvec3<type>(x = v.x, y = v.x, z = v.z);
}
template<typename type>
inline ttvec3<type> stvec3<type>::operator =(stvec3 const& v)
{
	return (*this = ttvec3<type>(v));
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
	return tvec4(x = v.x, y = v.x, z = v.z, w = v.w);
}
template<typename type>
inline ttvec4<type> stvec4<type>::operator =(stvec4 const& v)
{
	return (*this = ttvec4<type>(v));
}
template<typename type>
inline stvec4<type>::stvec4(type& xr, type& yr, type& zr, type& wr)
	: x(xr), y(yr), z(zr), w(wr)
{
}


//-----------------------------------------------------------------------------

IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, ttvec, 2, inline);

IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 1, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 2, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 3, inline);
IJK_SWIZZLE_ALL(IJK_SWIZZLE_IMPL_RTEMP, IJK_SWIZZLE_IMPL_RTEMP, ttvec, stvec, stvec, 4, inline);


//-----------------------------------------------------------------------------

// IJK_SWIZZLE_MACRO_IMPL
#pragma region IJK_SWIZZLE_MACRO_IMPL

// Swizzle shorthand macros.
///
#define x		_x()
#define y		_y()
#define z		_z()
#define w		_w()
#define xx		_xx()
#define xy		_xy()
#define xz		_xz()
#define xw		_xw()
#define yx		_yx()
#define yy		_yy()
#define yz		_yz()
#define yw		_yw()
#define zx		_zx()
#define zy		_zy()
#define zz		_zz()
#define zw		_zw()
#define wx		_wx()
#define wy		_wy()
#define wz		_wz()
#define ww		_ww()
#define xxx		_xxx()
#define xxy		_xxy()
#define xxz		_xxz()
#define xxw		_xxw()
#define xyx		_xyx()
#define xyy		_xyy()
#define xyz		_xyz()
#define xyw		_xyw()
#define xzx		_xzx()
#define xzy		_xzy()
#define xzz		_xzz()
#define xzw		_xzw()
#define xwx		_xwx()
#define xwy		_xwy()
#define xwz		_xwz()
#define xww		_xww()
#define yxx		_yxx()
#define yxy		_yxy()
#define yxz		_yxz()
#define yxw		_yxw()
#define yyx		_yyx()
#define yyy		_yyy()
#define yyz		_yyz()
#define yyw		_yyw()
#define yzx		_yzx()
#define yzy		_yzy()
#define yzz		_yzz()
#define yzw		_yzw()
#define ywx		_ywx()
#define ywy		_ywy()
#define ywz		_ywz()
#define yww		_yww()
#define zxx		_zxx()
#define zxy		_zxy()
#define zxz		_zxz()
#define zxw		_zxw()
#define zyx		_zyx()
#define zyy		_zyy()
#define zyz		_zyz()
#define zyw		_zyw()
#define zzx		_zzx()
#define zzy		_zzy()
#define zzz		_zzz()
#define zzw		_zzw()
#define zwx		_zwx()
#define zwy		_zwy()
#define zwz		_zwz()
#define zww		_zww()
#define wxx		_wxx()
#define wxy		_wxy()
#define wxz		_wxz()
#define wxw		_wxw()
#define wyx		_wyx()
#define wyy		_wyy()
#define wyz		_wyz()
#define wyw		_wyw()
#define wzx		_wzx()
#define wzy		_wzy()
#define wzz		_wzz()
#define wzw		_wzw()
#define wwx		_wwx()
#define wwy		_wwy()
#define wwz		_wwz()
#define www		_www()
#define xxxx	_xxxx()
#define xxxy	_xxxy()
#define xxxz	_xxxz()
#define xxxw	_xxxw()
#define xxyx	_xxyx()
#define xxyy	_xxyy()
#define xxyz	_xxyz()
#define xxyw	_xxyw()
#define xxzx	_xxzx()
#define xxzy	_xxzy()
#define xxzz	_xxzz()
#define xxzw	_xxzw()
#define xxwx	_xxwx()
#define xxwy	_xxwy()
#define xxwz	_xxwz()
#define xxww	_xxww()
#define xyxx	_xyxx()
#define xyxy	_xyxy()
#define xyxz	_xyxz()
#define xyxw	_xyxw()
#define xyyx	_xyyx()
#define xyyy	_xyyy()
#define xyyz	_xyyz()
#define xyyw	_xyyw()
#define xyzx	_xyzx()
#define xyzy	_xyzy()
#define xyzz	_xyzz()
#define xyzw	_xyzw()
#define xywx	_xywx()
#define xywy	_xywy()
#define xywz	_xywz()
#define xyww	_xyww()
#define xzxx	_xzxx()
#define xzxy	_xzxy()
#define xzxz	_xzxz()
#define xzxw	_xzxw()
#define xzyx	_xzyx()
#define xzyy	_xzyy()
#define xzyz	_xzyz()
#define xzyw	_xzyw()
#define xzzx	_xzzx()
#define xzzy	_xzzy()
#define xzzz	_xzzz()
#define xzzw	_xzzw()
#define xzwx	_xzwx()
#define xzwy	_xzwy()
#define xzwz	_xzwz()
#define xzww	_xzww()
#define xwxx	_xwxx()
#define xwxy	_xwxy()
#define xwxz	_xwxz()
#define xwxw	_xwxw()
#define xwyx	_xwyx()
#define xwyy	_xwyy()
#define xwyz	_xwyz()
#define xwyw	_xwyw()
#define xwzx	_xwzx()
#define xwzy	_xwzy()
#define xwzz	_xwzz()
#define xwzw	_xwzw()
#define xwwx	_xwwx()
#define xwwy	_xwwy()
#define xwwz	_xwwz()
#define xwww	_xwww()
#define yxxx	_yxxx()
#define yxxy	_yxxy()
#define yxxz	_yxxz()
#define yxxw	_yxxw()
#define yxyx	_yxyx()
#define yxyy	_yxyy()
#define yxyz	_yxyz()
#define yxyw	_yxyw()
#define yxzx	_yxzx()
#define yxzy	_yxzy()
#define yxzz	_yxzz()
#define yxzw	_yxzw()
#define yxwx	_yxwx()
#define yxwy	_yxwy()
#define yxwz	_yxwz()
#define yxww	_yxww()
#define yyxx	_yyxx()
#define yyxy	_yyxy()
#define yyxz	_yyxz()
#define yyxw	_yyxw()
#define yyyx	_yyyx()
#define yyyy	_yyyy()
#define yyyz	_yyyz()
#define yyyw	_yyyw()
#define yyzx	_yyzx()
#define yyzy	_yyzy()
#define yyzz	_yyzz()
#define yyzw	_yyzw()
#define yywx	_yywx()
#define yywy	_yywy()
#define yywz	_yywz()
#define yyww	_yyww()
#define yzxx	_yzxx()
#define yzxy	_yzxy()
#define yzxz	_yzxz()
#define yzxw	_yzxw()
#define yzyx	_yzyx()
#define yzyy	_yzyy()
#define yzyz	_yzyz()
#define yzyw	_yzyw()
#define yzzx	_yzzx()
#define yzzy	_yzzy()
#define yzzz	_yzzz()
#define yzzw	_yzzw()
#define yzwx	_yzwx()
#define yzwy	_yzwy()
#define yzwz	_yzwz()
#define yzww	_yzww()
#define ywxx	_ywxx()
#define ywxy	_ywxy()
#define ywxz	_ywxz()
#define ywxw	_ywxw()
#define ywyx	_ywyx()
#define ywyy	_ywyy()
#define ywyz	_ywyz()
#define ywyw	_ywyw()
#define ywzx	_ywzx()
#define ywzy	_ywzy()
#define ywzz	_ywzz()
#define ywzw	_ywzw()
#define ywwx	_ywwx()
#define ywwy	_ywwy()
#define ywwz	_ywwz()
#define ywww	_ywww()
#define zxxx	_zxxx()
#define zxxy	_zxxy()
#define zxxz	_zxxz()
#define zxxw	_zxxw()
#define zxyx	_zxyx()
#define zxyy	_zxyy()
#define zxyz	_zxyz()
#define zxyw	_zxyw()
#define zxzx	_zxzx()
#define zxzy	_zxzy()
#define zxzz	_zxzz()
#define zxzw	_zxzw()
#define zxwx	_zxwx()
#define zxwy	_zxwy()
#define zxwz	_zxwz()
#define zxww	_zxww()
#define zyxx	_zyxx()
#define zyxy	_zyxy()
#define zyxz	_zyxz()
#define zyxw	_zyxw()
#define zyyx	_zyyx()
#define zyyy	_zyyy()
#define zyyz	_zyyz()
#define zyyw	_zyyw()
#define zyzx	_zyzx()
#define zyzy	_zyzy()
#define zyzz	_zyzz()
#define zyzw	_zyzw()
#define zywx	_zywx()
#define zywy	_zywy()
#define zywz	_zywz()
#define zyww	_zyww()
#define zzxx	_zzxx()
#define zzxy	_zzxy()
#define zzxz	_zzxz()
#define zzxw	_zzxw()
#define zzyx	_zzyx()
#define zzyy	_zzyy()
#define zzyz	_zzyz()
#define zzyw	_zzyw()
#define zzzx	_zzzx()
#define zzzy	_zzzy()
#define zzzz	_zzzz()
#define zzzw	_zzzw()
#define zzwx	_zzwx()
#define zzwy	_zzwy()
#define zzwz	_zzwz()
#define zzww	_zzww()
#define zwxx	_zwxx()
#define zwxy	_zwxy()
#define zwxz	_zwxz()
#define zwxw	_zwxw()
#define zwyx	_zwyx()
#define zwyy	_zwyy()
#define zwyz	_zwyz()
#define zwyw	_zwyw()
#define zwzx	_zwzx()
#define zwzy	_zwzy()
#define zwzz	_zwzz()
#define zwzw	_zwzw()
#define zwwx	_zwwx()
#define zwwy	_zwwy()
#define zwwz	_zwwz()
#define zwww	_zwww()
#define wxxx	_wxxx()
#define wxxy	_wxxy()
#define wxxz	_wxxz()
#define wxxw	_wxxw()
#define wxyx	_wxyx()
#define wxyy	_wxyy()
#define wxyz	_wxyz()
#define wxyw	_wxyw()
#define wxzx	_wxzx()
#define wxzy	_wxzy()
#define wxzz	_wxzz()
#define wxzw	_wxzw()
#define wxwx	_wxwx()
#define wxwy	_wxwy()
#define wxwz	_wxwz()
#define wxww	_wxww()
#define wyxx	_wyxx()
#define wyxy	_wyxy()
#define wyxz	_wyxz()
#define wyxw	_wyxw()
#define wyyx	_wyyx()
#define wyyy	_wyyy()
#define wyyz	_wyyz()
#define wyyw	_wyyw()
#define wyzx	_wyzx()
#define wyzy	_wyzy()
#define wyzz	_wyzz()
#define wyzw	_wyzw()
#define wywx	_wywx()
#define wywy	_wywy()
#define wywz	_wywz()
#define wyww	_wyww()
#define wzxx	_wzxx()
#define wzxy	_wzxy()
#define wzxz	_wzxz()
#define wzxw	_wzxw()
#define wzyx	_wzyx()
#define wzyy	_wzyy()
#define wzyz	_wzyz()
#define wzyw	_wzyw()
#define wzzx	_wzzx()
#define wzzy	_wzzy()
#define wzzz	_wzzz()
#define wzzw	_wzzw()
#define wzwx	_wzwx()
#define wzwy	_wzwy()
#define wzwz	_wzwz()
#define wzww	_wzww()
#define wwxx	_wwxx()
#define wwxy	_wwxy()
#define wwxz	_wwxz()
#define wwxw	_wwxw()
#define wwyx	_wwyx()
#define wwyy	_wwyy()
#define wwyz	_wwyz()
#define wwyw	_wwyw()
#define wwzx	_wwzx()
#define wwzy	_wwzy()
#define wwzz	_wwzz()
#define wwzw	_wwzw()
#define wwwx	_wwwx()
#define wwwy	_wwwy()
#define wwwz	_wwwz()
#define wwww	_wwww()

#define r		_r()
#define g		_g()
#define b		_b()
#define a		_a()
#define rr		_xx()
#define rg		_xy()
#define rb		_xz()
#define ra		_xw()
#define gr		_yx()
#define gg		_yy()
#define gb		_yz()
#define ga		_yw()
#define br		_zx()
#define bg		_zy()
#define bb		_zz()
#define ba		_zw()
#define ar		_wx()
#define ag		_wy()
#define ab		_wz()
#define aa		_ww()
#define rrr		_xxx()
#define rrg		_xxy()
#define rrb		_xxz()
#define rra		_xxw()
#define rgr		_xyx()
#define rgg		_xyy()
#define rgb		_xyz()
#define rga		_xyw()
#define rbr		_xzx()
#define rbg		_xzy()
#define rbb		_xzz()
#define rba		_xzw()
#define rar		_xwx()
#define rag		_xwy()
#define rab		_xwz()
#define raa		_xww()
#define grr		_yxx()
#define grg		_yxy()
#define grb		_yxz()
#define gra		_yxw()
#define ggr		_yyx()
#define ggg		_yyy()
#define ggb		_yyz()
#define gga		_yyw()
#define gbr		_yzx()
#define gbg		_yzy()
#define gbb		_yzz()
#define gba		_yzw()
#define gar		_ywx()
#define gag		_ywy()
#define gab		_ywz()
#define gaa		_yww()
#define brr		_zxx()
#define brg		_zxy()
#define brb		_zxz()
#define bra		_zxw()
#define bgr		_zyx()
#define bgg		_zyy()
#define bgb		_zyz()
#define bga		_zyw()
#define bbr		_zzx()
#define bbg		_zzy()
#define bbb		_zzz()
#define bba		_zzw()
#define bar		_zwx()
#define bag		_zwy()
#define bab		_zwz()
#define baa		_zww()
#define arr		_wxx()
#define arg		_wxy()
#define arb		_wxz()
#define ara		_wxw()
#define agr		_wyx()
#define agg		_wyy()
#define agb		_wyz()
#define aga		_wyw()
#define abr		_wzx()
#define abg		_wzy()
#define abb		_wzz()
#define aba		_wzw()
#define aar		_wwx()
#define aag		_wwy()
#define aab		_wwz()
#define aaa		_www()
#define rrrr	_xxxx()
#define rrrg	_xxxy()
#define rrrb	_xxxz()
#define rrra	_xxxw()
#define rrgr	_xxyx()
#define rrgg	_xxyy()
#define rrgb	_xxyz()
#define rrga	_xxyw()
#define rrbr	_xxzx()
#define rrbg	_xxzy()
#define rrbb	_xxzz()
#define rrba	_xxzw()
#define rrar	_xxwx()
#define rrag	_xxwy()
#define rrab	_xxwz()
#define rraa	_xxww()
#define rgrr	_xyxx()
#define rgrg	_xyxy()
#define rgrb	_xyxz()
#define rgra	_xyxw()
#define rggr	_xyyx()
#define rggg	_xyyy()
#define rggb	_xyyz()
#define rgga	_xyyw()
#define rgbr	_xyzx()
#define rgbg	_xyzy()
#define rgbb	_xyzz()
#define rgba	_xyzw()
#define rgar	_xywx()
#define rgag	_xywy()
#define rgab	_xywz()
#define rgaa	_xyww()
#define rbrr	_xzxx()
#define rbrg	_xzxy()
#define rbrb	_xzxz()
#define rbra	_xzxw()
#define rbgr	_xzyx()
#define rbgg	_xzyy()
#define rbgb	_xzyz()
#define rbga	_xzyw()
#define rbbr	_xzzx()
#define rbbg	_xzzy()
#define rbbb	_xzzz()
#define rbba	_xzzw()
#define rbar	_xzwx()
#define rbag	_xzwy()
#define rbab	_xzwz()
#define rbaa	_xzww()
#define rarr	_xwxx()
#define rarg	_xwxy()
#define rarb	_xwxz()
#define rara	_xwxw()
#define ragr	_xwyx()
#define ragg	_xwyy()
#define ragb	_xwyz()
#define raga	_xwyw()
#define rabr	_xwzx()
#define rabg	_xwzy()
#define rabb	_xwzz()
#define raba	_xwzw()
#define raar	_xwwx()
#define raag	_xwwy()
#define raab	_xwwz()
#define raaa	_xwww()
#define grrr	_yxxx()
#define grrg	_yxxy()
#define grrb	_yxxz()
#define grra	_yxxw()
#define grgr	_yxyx()
#define grgg	_yxyy()
#define grgb	_yxyz()
#define grga	_yxyw()
#define grbr	_yxzx()
#define grbg	_yxzy()
#define grbb	_yxzz()
#define grba	_yxzw()
#define grar	_yxwx()
#define grag	_yxwy()
#define grab	_yxwz()
#define graa	_yxww()
#define ggrr	_yyxx()
#define ggrg	_yyxy()
#define ggrb	_yyxz()
#define ggra	_yyxw()
#define gggr	_yyyx()
#define gggg	_yyyy()
#define gggb	_yyyz()
#define ggga	_yyyw()
#define ggbr	_yyzx()
#define ggbg	_yyzy()
#define ggbb	_yyzz()
#define ggba	_yyzw()
#define ggar	_yywx()
#define ggag	_yywy()
#define ggab	_yywz()
#define ggaa	_yyww()
#define gbrr	_yzxx()
#define gbrg	_yzxy()
#define gbrb	_yzxz()
#define gbra	_yzxw()
#define gbgr	_yzyx()
#define gbgg	_yzyy()
#define gbgb	_yzyz()
#define gbga	_yzyw()
#define gbbr	_yzzx()
#define gbbg	_yzzy()
#define gbbb	_yzzz()
#define gbba	_yzzw()
#define gbar	_yzwx()
#define gbag	_yzwy()
#define gbab	_yzwz()
#define gbaa	_yzww()
#define garr	_ywxx()
#define garg	_ywxy()
#define garb	_ywxz()
#define gara	_ywxw()
#define gagr	_ywyx()
#define gagg	_ywyy()
#define gagb	_ywyz()
#define gaga	_ywyw()
#define gabr	_ywzx()
#define gabg	_ywzy()
#define gabb	_ywzz()
#define gaba	_ywzw()
#define gaar	_ywwx()
#define gaag	_ywwy()
#define gaab	_ywwz()
#define gaaa	_ywww()
#define brrr	_zxxx()
#define brrg	_zxxy()
#define brrb	_zxxz()
#define brra	_zxxw()
#define brgr	_zxyx()
#define brgg	_zxyy()
#define brgb	_zxyz()
#define brga	_zxyw()
#define brbr	_zxzx()
#define brbg	_zxzy()
#define brbb	_zxzz()
#define brba	_zxzw()
#define brar	_zxwx()
#define brag	_zxwy()
#define brab	_zxwz()
#define braa	_zxww()
#define bgrr	_zyxx()
#define bgrg	_zyxy()
#define bgrb	_zyxz()
#define bgra	_zyxw()
#define bggr	_zyyx()
#define bggg	_zyyy()
#define bggb	_zyyz()
#define bgga	_zyyw()
#define bgbr	_zyzx()
#define bgbg	_zyzy()
#define bgbb	_zyzz()
#define bgba	_zyzw()
#define bgar	_zywx()
#define bgag	_zywy()
#define bgab	_zywz()
#define bgaa	_zyww()
#define bbrr	_zzxx()
#define bbrg	_zzxy()
#define bbrb	_zzxz()
#define bbra	_zzxw()
#define bbgr	_zzyx()
#define bbgg	_zzyy()
#define bbgb	_zzyz()
#define bbga	_zzyw()
#define bbbr	_zzzx()
#define bbbg	_zzzy()
#define bbbb	_zzzz()
#define bbba	_zzzw()
#define bbar	_zzwx()
#define bbag	_zzwy()
#define bbab	_zzwz()
#define bbaa	_zzww()
#define barr	_zwxx()
#define barg	_zwxy()
#define barb	_zwxz()
#define bara	_zwxw()
#define bagr	_zwyx()
#define bagg	_zwyy()
#define bagb	_zwyz()
#define baga	_zwyw()
#define babr	_zwzx()
#define babg	_zwzy()
#define babb	_zwzz()
#define baba	_zwzw()
#define baar	_zwwx()
#define baag	_zwwy()
#define baab	_zwwz()
#define baaa	_zwww()
#define arrr	_wxxx()
#define arrg	_wxxy()
#define arrb	_wxxz()
#define arra	_wxxw()
#define argr	_wxyx()
#define argg	_wxyy()
#define argb	_wxyz()
#define arga	_wxyw()
#define arbr	_wxzx()
#define arbg	_wxzy()
#define arbb	_wxzz()
#define arba	_wxzw()
#define arar	_wxwx()
#define arag	_wxwy()
#define arab	_wxwz()
#define araa	_wxww()
#define agrr	_wyxx()
#define agrg	_wyxy()
#define agrb	_wyxz()
#define agra	_wyxw()
#define aggr	_wyyx()
#define aggg	_wyyy()
#define aggb	_wyyz()
#define agga	_wyyw()
#define agbr	_wyzx()
#define agbg	_wyzy()
#define agbb	_wyzz()
#define agba	_wyzw()
#define agar	_wywx()
#define agag	_wywy()
#define agab	_wywz()
#define agaa	_wyww()
#define abrr	_wzxx()
#define abrg	_wzxy()
#define abrb	_wzxz()
#define abra	_wzxw()
#define abgr	_wzyx()
#define abgg	_wzyy()
#define abgb	_wzyz()
#define abga	_wzyw()
#define abbr	_wzzx()
#define abbg	_wzzy()
#define abbb	_wzzz()
#define abba	_wzzw()
#define abar	_wzwx()
#define abag	_wzwy()
#define abab	_wzwz()
#define abaa	_wzww()
#define aarr	_wwxx()
#define aarg	_wwxy()
#define aarb	_wwxz()
#define aara	_wwxw()
#define aagr	_wwyx()
#define aagg	_wwyy()
#define aagb	_wwyz()
#define aaga	_wwyw()
#define aabr	_wwzx()
#define aabg	_wwzy()
#define aabb	_wwzz()
#define aaba	_wwzw()
#define aaar	_wwwx()
#define aaag	_wwwy()
#define aaab	_wwwz()
#define aaaa	_wwww()

#define s		_s()
#define t		_t()
#define p		_p()
#define q		_q()
#define ss		_xx()
#define st		_xy()
#define sp		_xz()
#define sq		_xw()
#define ts		_yx()
#define tt		_yy()
#define tp		_yz()
#define tq		_yw()
#define ps		_zx()
#define pt		_zy()
#define pp		_zz()
#define pq		_zw()
#define qs		_wx()
#define qt		_wy()
#define qp		_wz()
#define qq		_ww()
#define sss		_xxx()
#define sst		_xxy()
#define ssp		_xxz()
#define ssq		_xxw()
#define sts		_xyx()
#define stt		_xyy()
#define stp		_xyz()
#define stq		_xyw()
#define sps		_xzx()
#define spt		_xzy()
#define spp		_xzz()
#define spq		_xzw()
#define sqs		_xwx()
#define sqt		_xwy()
#define sqp		_xwz()
#define sqq		_xww()
#define tss		_yxx()
#define tst		_yxy()
#define tsp		_yxz()
#define tsq		_yxw()
#define tts		_yyx()
#define ttt		_yyy()
#define ttp		_yyz()
#define ttq		_yyw()
#define tps		_yzx()
#define tpt		_yzy()
#define tpp		_yzz()
#define tpq		_yzw()
#define tqs		_ywx()
#define tqt		_ywy()
#define tqp		_ywz()
#define tqq		_yww()
#define pss		_zxx()
#define pst		_zxy()
#define psp		_zxz()
#define psq		_zxw()
#define pts		_zyx()
#define ptt		_zyy()
#define ptp		_zyz()
#define ptq		_zyw()
#define pps		_zzx()
#define ppt		_zzy()
#define ppp		_zzz()
#define ppq		_zzw()
#define pqs		_zwx()
#define pqt		_zwy()
#define pqp		_zwz()
#define pqq		_zww()
#define qss		_wxx()
#define qst		_wxy()
#define qsp		_wxz()
#define qsq		_wxw()
#define qts		_wyx()
#define qtt		_wyy()
#define qtp		_wyz()
#define qtq		_wyw()
#define qps		_wzx()
#define qpt		_wzy()
#define qpp		_wzz()
#define qpq		_wzw()
#define qqs		_wwx()
#define qqt		_wwy()
#define qqp		_wwz()
#define qqq		_www()
#define ssss	_xxxx()
#define ssst	_xxxy()
#define sssp	_xxxz()
#define sssq	_xxxw()
#define ssts	_xxyx()
#define sstt	_xxyy()
#define sstp	_xxyz()
#define sstq	_xxyw()
#define ssps	_xxzx()
#define sspt	_xxzy()
#define sspp	_xxzz()
#define sspq	_xxzw()
#define ssqs	_xxwx()
#define ssqt	_xxwy()
#define ssqp	_xxwz()
#define ssqq	_xxww()
#define stss	_xyxx()
#define stst	_xyxy()
#define stsp	_xyxz()
#define stsq	_xyxw()
#define stts	_xyyx()
#define sttt	_xyyy()
#define sttp	_xyyz()
#define sttq	_xyyw()
#define stps	_xyzx()
#define stpt	_xyzy()
#define stpp	_xyzz()
#define stpq	_xyzw()
#define stqs	_xywx()
#define stqt	_xywy()
#define stqp	_xywz()
#define stqq	_xyww()
#define spss	_xzxx()
#define spst	_xzxy()
#define spsp	_xzxz()
#define spsq	_xzxw()
#define spts	_xzyx()
#define sptt	_xzyy()
#define sptp	_xzyz()
#define sptq	_xzyw()
#define spps	_xzzx()
#define sppt	_xzzy()
#define sppp	_xzzz()
#define sppq	_xzzw()
#define spqs	_xzwx()
#define spqt	_xzwy()
#define spqp	_xzwz()
#define spqq	_xzww()
#define sqss	_xwxx()
#define sqst	_xwxy()
#define sqsp	_xwxz()
#define sqsq	_xwxw()
#define sqts	_xwyx()
#define sqtt	_xwyy()
#define sqtp	_xwyz()
#define sqtq	_xwyw()
#define sqps	_xwzx()
#define sqpt	_xwzy()
#define sqpp	_xwzz()
#define sqpq	_xwzw()
#define sqqs	_xwwx()
#define sqqt	_xwwy()
#define sqqp	_xwwz()
#define sqqq	_xwww()
#define tsss	_yxxx()
#define tsst	_yxxy()
#define tssp	_yxxz()
#define tssq	_yxxw()
#define tsts	_yxyx()
#define tstt	_yxyy()
#define tstp	_yxyz()
#define tstq	_yxyw()
#define tsps	_yxzx()
#define tspt	_yxzy()
#define tspp	_yxzz()
#define tspq	_yxzw()
#define tsqs	_yxwx()
#define tsqt	_yxwy()
#define tsqp	_yxwz()
#define tsqq	_yxww()
#define ttss	_yyxx()
#define ttst	_yyxy()
#define ttsp	_yyxz()
#define ttsq	_yyxw()
#define ttts	_yyyx()
#define tttt	_yyyy()
#define tttp	_yyyz()
#define tttq	_yyyw()
#define ttps	_yyzx()
#define ttpt	_yyzy()
#define ttpp	_yyzz()
#define ttpq	_yyzw()
#define ttqs	_yywx()
#define ttqt	_yywy()
#define ttqp	_yywz()
#define ttqq	_yyww()
#define tpss	_yzxx()
#define tpst	_yzxy()
#define tpsp	_yzxz()
#define tpsq	_yzxw()
#define tpts	_yzyx()
#define tptt	_yzyy()
#define tptp	_yzyz()
#define tptq	_yzyw()
#define tpps	_yzzx()
#define tppt	_yzzy()
#define tppp	_yzzz()
#define tppq	_yzzw()
#define tpqs	_yzwx()
#define tpqt	_yzwy()
#define tpqp	_yzwz()
#define tpqq	_yzww()
#define tqss	_ywxx()
#define tqst	_ywxy()
#define tqsp	_ywxz()
#define tqsq	_ywxw()
#define tqts	_ywyx()
#define tqtt	_ywyy()
#define tqtp	_ywyz()
#define tqtq	_ywyw()
#define tqps	_ywzx()
#define tqpt	_ywzy()
#define tqpp	_ywzz()
#define tqpq	_ywzw()
#define tqqs	_ywwx()
#define tqqt	_ywwy()
#define tqqp	_ywwz()
#define tqqq	_ywww()
#define psss	_zxxx()
#define psst	_zxxy()
#define pssp	_zxxz()
#define pssq	_zxxw()
#define psts	_zxyx()
#define pstt	_zxyy()
#define pstp	_zxyz()
#define pstq	_zxyw()
#define psps	_zxzx()
#define pspt	_zxzy()
#define pspp	_zxzz()
#define pspq	_zxzw()
#define psqs	_zxwx()
#define psqt	_zxwy()
#define psqp	_zxwz()
#define psqq	_zxww()
#define ptss	_zyxx()
#define ptst	_zyxy()
#define ptsp	_zyxz()
#define ptsq	_zyxw()
#define ptts	_zyyx()
#define pttt	_zyyy()
#define pttp	_zyyz()
#define pttq	_zyyw()
#define ptps	_zyzx()
#define ptpt	_zyzy()
#define ptpp	_zyzz()
#define ptpq	_zyzw()
#define ptqs	_zywx()
#define ptqt	_zywy()
#define ptqp	_zywz()
#define ptqq	_zyww()
#define ppss	_zzxx()
#define ppst	_zzxy()
#define ppsp	_zzxz()
#define ppsq	_zzxw()
#define ppts	_zzyx()
#define pptt	_zzyy()
#define pptp	_zzyz()
#define pptq	_zzyw()
#define ppps	_zzzx()
#define pppt	_zzzy()
#define pppp	_zzzz()
#define pppq	_zzzw()
#define ppqs	_zzwx()
#define ppqt	_zzwy()
#define ppqp	_zzwz()
#define ppqq	_zzww()
#define pqss	_zwxx()
#define pqst	_zwxy()
#define pqsp	_zwxz()
#define pqsq	_zwxw()
#define pqts	_zwyx()
#define pqtt	_zwyy()
#define pqtp	_zwyz()
#define pqtq	_zwyw()
#define pqps	_zwzx()
#define pqpt	_zwzy()
#define pqpp	_zwzz()
#define pqpq	_zwzw()
#define pqqs	_zwwx()
#define pqqt	_zwwy()
#define pqqp	_zwwz()
#define pqqq	_zwww()
#define qsss	_wxxx()
#define qsst	_wxxy()
#define qssp	_wxxz()
#define qssq	_wxxw()
#define qsts	_wxyx()
#define qstt	_wxyy()
#define qstp	_wxyz()
#define qstq	_wxyw()
#define qsps	_wxzx()
#define qspt	_wxzy()
#define qspp	_wxzz()
#define qspq	_wxzw()
#define qsqs	_wxwx()
#define qsqt	_wxwy()
#define qsqp	_wxwz()
#define qsqq	_wxww()
#define qtss	_wyxx()
#define qtst	_wyxy()
#define qtsp	_wyxz()
#define qtsq	_wyxw()
#define qtts	_wyyx()
#define qttt	_wyyy()
#define qttp	_wyyz()
#define qttq	_wyyw()
#define qtps	_wyzx()
#define qtpt	_wyzy()
#define qtpp	_wyzz()
#define qtpq	_wyzw()
#define qtqs	_wywx()
#define qtqt	_wywy()
#define qtqp	_wywz()
#define qtqq	_wyww()
#define qpss	_wzxx()
#define qpst	_wzxy()
#define qpsp	_wzxz()
#define qpsq	_wzxw()
#define qpts	_wzyx()
#define qptt	_wzyy()
#define qptp	_wzyz()
#define qptq	_wzyw()
#define qpps	_wzzx()
#define qppt	_wzzy()
#define qppp	_wzzz()
#define qppq	_wzzw()
#define qpqs	_wzwx()
#define qpqt	_wzwy()
#define qpqp	_wzwz()
#define qpqq	_wzww()
#define qqss	_wwxx()
#define qqst	_wwxy()
#define qqsp	_wwxz()
#define qqsq	_wwxw()
#define qqts	_wwyx()
#define qqtt	_wwyy()
#define qqtp	_wwyz()
#define qqtq	_wwyw()
#define qqps	_wwzx()
#define qqpt	_wwzy()
#define qqpp	_wwzz()
#define qqpq	_wwzw()
#define qqqs	_wwwx()
#define qqqt	_wwwy()
#define qqqp	_wwwz()
#define qqqq	_wwww()


//-----------------------------------------------------------------------------

#pragma endregion
// IJK_SWIZZLE_MACRO_IMPL


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#endif	// !_IJK_VECTORSWIZZLE_INL_
#endif	// _IJK_VECTORSWIZZLE_H_ && _IJK_VECTOR_INL_