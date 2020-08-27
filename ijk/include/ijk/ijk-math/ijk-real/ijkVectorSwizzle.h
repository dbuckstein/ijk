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

	ijkVectorSwizzle.h
	Vector swizzling types and functions (built for C++).
*/

#if (defined _IJK_VECTOR_H_ && !defined _IJK_VECTOR_INL_)
#ifndef _IJK_VECTORSWIZZLE_H_
#define _IJK_VECTORSWIZZLE_H_


#include "ijk/ijk/ijk-typedefs.h"


#ifdef __cplusplus

// IJK_SWIZZLE_MACRO_DECL
#pragma region IJK_SWIZZLE_MACRO_DECL

// Internal swizzling implementation.
///
#define IJK_SWIZZLE_U1(swiz,inl,cf,ot,rtb,x,...)			swiz(inl,cf,ot,rtb,1,x,,,,x)	// unique 1
#define IJK_SWIZZLE_U2(swiz,inl,cf,ot,rtb,x,y,...)			swiz(inl,cf,ot,rtb,2,x,y,,,x,y)	// unique 2
#define IJK_SWIZZLE_U3(swiz,inl,cf,ot,rtb,x,y,z,...)		swiz(inl,cf,ot,rtb,3,x,y,z,,x,y,z)	// unique 3
#define IJK_SWIZZLE_U4(swiz,inl,cf,ot,rtb,x,y,z,w,...)		swiz(inl,cf,ot,rtb,4,x,y,z,w,x,y,z,w)	// unique 4
#define IJK_SWIZZLE_D1(swiz,inl,cf,ot,rtb,x,...)			swiz(inl,cf,ot,rtb,2,x,x,,,x,x); swiz(inl,cf,ot,rtb,3,x,x,x,,x,x,x); swiz(inl,cf,ot,rtb,4,x,x,x,x,x,x,x,x)	// duplicate 1
#define IJK_SWIZZLE_D2(swiz,inl,cf,ot,rtb,x,y,...)			swiz(inl,cf,ot,rtb,3,x,x,y,,x,x,y); swiz(inl,cf,ot,rtb,3,x,y,x,,x,y,x); swiz(inl,cf,ot,rtb,3,x,y,y,,x,y,y); swiz(inl,cf,ot,rtb,4,x,x,x,y,x,x,x,y); swiz(inl,cf,ot,rtb,4,x,x,y,x,x,x,y,x); swiz(inl,cf,ot,rtb,4,x,x,y,y,x,x,y,y); swiz(inl,cf,ot,rtb,4,x,y,x,x,x,y,x,x); swiz(inl,cf,ot,rtb,4,x,y,x,y,x,y,x,y); swiz(inl,cf,ot,rtb,4,x,y,y,x,x,y,y,x); swiz(inl,cf,ot,rtb,4,x,y,y,y,x,y,y,y)	// duplicate 2
#define IJK_SWIZZLE_D3(swiz,inl,cf,ot,rtb,x,y,z,...)		swiz(inl,cf,ot,rtb,4,x,x,y,z,x,x,y,z); swiz(inl,cf,ot,rtb,4,x,y,x,z,x,y,x,z); swiz(inl,cf,ot,rtb,4,x,y,y,z,x,y,y,z); swiz(inl,cf,ot,rtb,4,x,y,z,z,x,y,z,z); swiz(inl,cf,ot,rtb,4,x,y,z,y,x,y,z,y); swiz(inl,cf,ot,rtb,4,x,y,z,x,x,y,z,x)	// duplicate 3
#define IJK_SWIZZLE_D4(swiz,inl,cf,ot,rtb,x,y,z,w,...)		// duplicate 4	// empty set, no combos remaining
#define IJK_SWIZZLE_F1(swiz,inl,cf,ot,rtb,f1,...)			f1(swiz,inl,cf,ot,rtb,x,,,)
#define IJK_SWIZZLE_F2(swiz,inl,cf,ot,rtb,f1,f2,...)		IJK_SWIZZLE_F1(swiz,inl,cf,ot,rtb,f1); f1(swiz,inl,cf,ot,rtb,y,,,); f2(swiz,inl,cf,ot,rtb,x,y,,); f2(swiz,inl,cf,ot,rtb,y,x,,)
#define IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3,...)		IJK_SWIZZLE_F2(swiz,inl,cf,ot,rtb,f1,f2); f1(swiz,inl,cf,ot,rtb,z,,,); f2(swiz,inl,cf,ot,rtb,x,z,,); f2(swiz,inl,cf,ot,rtb,z,x,,); f2(swiz,inl,cf,ot,rtb,y,z,,); f2(swiz,inl,cf,ot,rtb,z,y,,); f3(swiz,inl,cf,ot,rtb,x,y,z,); f3(swiz,inl,cf,ot,rtb,y,z,x,); f3(swiz,inl,cf,ot,rtb,z,x,y,); f3(swiz,inl,cf,ot,rtb,y,x,z,); f3(swiz,inl,cf,ot,rtb,x,z,y,); f3(swiz,inl,cf,ot,rtb,z,y,x,)
#define IJK_SWIZZLE_F4(swiz,inl,cf,ot,rtb,f1,f2,f3,f4,...)	IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3); f1(swiz,inl,cf,ot,rtb,w,,,); f2(swiz,inl,cf,ot,rtb,x,w,,); f2(swiz,inl,cf,ot,rtb,w,x,,); f2(swiz,inl,cf,ot,rtb,y,w,,); f2(swiz,inl,cf,ot,rtb,w,y,,); f2(swiz,inl,cf,ot,rtb,z,w,,); f2(swiz,inl,cf,ot,rtb,w,z,,); f3(swiz,inl,cf,ot,rtb,x,y,w,); f3(swiz,inl,cf,ot,rtb,y,x,w,); f3(swiz,inl,cf,ot,rtb,x,z,w,); f3(swiz,inl,cf,ot,rtb,z,x,w,); f3(swiz,inl,cf,ot,rtb,x,w,y,); f3(swiz,inl,cf,ot,rtb,w,x,y,); f3(swiz,inl,cf,ot,rtb,y,z,w,); f3(swiz,inl,cf,ot,rtb,z,y,w,); f3(swiz,inl,cf,ot,rtb,y,w,x,); f3(swiz,inl,cf,ot,rtb,w,y,x,); f3(swiz,inl,cf,ot,rtb,x,w,z,); f3(swiz,inl,cf,ot,rtb,w,x,z,); f3(swiz,inl,cf,ot,rtb,y,w,z,); f3(swiz,inl,cf,ot,rtb,w,y,z,); f3(swiz,inl,cf,ot,rtb,z,w,x,); f3(swiz,inl,cf,ot,rtb,w,z,x,); f3(swiz,inl,cf,ot,rtb,z,w,y,); f3(swiz,inl,cf,ot,rtb,w,z,y,); f4(swiz,inl,cf,ot,rtb,x,y,z,w); f4(swiz,inl,cf,ot,rtb,x,y,w,z); f4(swiz,inl,cf,ot,rtb,x,z,y,w); f4(swiz,inl,cf,ot,rtb,x,z,w,y); f4(swiz,inl,cf,ot,rtb,x,w,y,z); f4(swiz,inl,cf,ot,rtb,x,w,z,y); f4(swiz,inl,cf,ot,rtb,y,x,z,w); f4(swiz,inl,cf,ot,rtb,y,x,w,z); f4(swiz,inl,cf,ot,rtb,y,z,x,w); f4(swiz,inl,cf,ot,rtb,y,z,w,x); f4(swiz,inl,cf,ot,rtb,y,w,x,z); f4(swiz,inl,cf,ot,rtb,y,w,z,x); f4(swiz,inl,cf,ot,rtb,z,x,y,w); f4(swiz,inl,cf,ot,rtb,z,x,w,y); f4(swiz,inl,cf,ot,rtb,z,y,x,w); f4(swiz,inl,cf,ot,rtb,z,y,w,x); f4(swiz,inl,cf,ot,rtb,z,w,x,y); f4(swiz,inl,cf,ot,rtb,z,w,y,x); f4(swiz,inl,cf,ot,rtb,w,x,y,z); f4(swiz,inl,cf,ot,rtb,w,x,z,y); f4(swiz,inl,cf,ot,rtb,w,y,x,z); f4(swiz,inl,cf,ot,rtb,w,y,z,x); f4(swiz,inl,cf,ot,rtb,w,z,x,y); f4(swiz,inl,cf,ot,rtb,w,z,y,x)
#define IJK_SWIZZLE(F,swiz,inl,cf,ot,rtb,f1,f2,f3,f4)		F(swiz,inl,cf,ot,rtb,f1,f2,f3,f4)

// IJK_SWIZZLE_READONLY
//	Configure read-only (constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format (see options below)
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_READONLY(swizzleFormat,returnTypeBase,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_D1,IJK_SWIZZLE_D2,IJK_SWIZZLE_D3,IJK_SWIZZLE_D4); IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_WRITABLE
//	Configure writable (non-constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format (see options below)
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_WRITABLE(swizzleFormat,returnTypeBase,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_ALL
//	Configure swizzling in calling interface.
//		param swizzleFormat_readonly: swizzle function format for read-only functions (see options below)
//		param swizzleFormat_writable: swizzle function format for writable functions (see options below)
//		param returnTypeBase_readonly: return type, without size, of read-only swizzle results
//		param returnTypeBase_writable: return type, without size, of read-only swizzle results
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_ALL(swizzleFormat_readonly,swizzleFormat_writable,returnTypeBase_readonly,returnTypeBase_writable,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE_READONLY(swizzleFormat_readonly,returnTypeBase_readonly,ownerTypeBase,ownerTypeSize,__VA_ARGS__); IJK_SWIZZLE_WRITABLE(swizzleFormat_writable,returnTypeBase_writable,ownerTypeBase,ownerTypeSize,__VA_ARGS__)


// IJK_SWIZZLE_DECL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare swizzling functions within target interface.
//	Requires paired use of IJK_SWIZZLE_IMPL_TEMP, IJK_SWIZZLE_IMPL_RTEMP or
//	IJK_SWIZZLE_IMPL outside of target interface.
#define IJK_SWIZZLE_DECL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl rtb##rts _##x##y##z##w() cf

// IJK_SWIZZLE_DECL_IMPL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare and implement swizzling functions within
//	target interface.
#define IJK_SWIZZLE_DECL_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl rtb##rts _##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target
//	interface. Requires prior paired use of IJK_SWIZZLE_DECL within target
//	interface.
#define IJK_SWIZZLE_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl rtb##rts ot::_##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_DECL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare swizzling functions within target interface
//	using template return types. Requires paired use of IJK_SWIZZLE_IMPL_RTEMP
//	outside of target interface.
#define IJK_SWIZZLE_DECL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl rtb##rts<type> _##x##y##z##w() cf

// IJK_SWIZZLE_DECL_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare and implement swizzling functions within target
//	template interface using template return types.
#define IJK_SWIZZLE_DECL_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)							inl rtb##rts<type> _##x##y##z##w() cf { return rtb##rts<type>(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_TEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface. Requires prior paired use of IJK_SWIZZLE_DECL within target
//	interface.
#define IJK_SWIZZLE_IMPL_TEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type> inl rtb##rts ot<type>::_##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface using template return types. Requires prior IJK_SWIZZLE_DECL or
//	IJK_SWIZZLE_DECL_RTEMP within target interface.
#define IJK_SWIZZLE_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type> inl rtb##rts<type> ot<type>::_##x##y##z##w() cf { return rtb##rts<type>(__VA_ARGS__); }

#pragma endregion
// IJK_SWIZZLE_MACRO_DECL

//-----------------------------------------------------------------------------

template<typename type>
union ttvec1;
template<typename type>
union ttvec2;
template<typename type>
union ttvec3;
template<typename type>
union ttvec4;

template<typename type>
struct stvec1;
template<typename type>
struct stvec2;
template<typename type>
struct stvec3;
template<typename type>
struct stvec4;


//-----------------------------------------------------------------------------

// Template scalar type.
template<typename type>
union ttvec1
{
	ttvec1(type const& xc = 0);
	ttvec1& operator =(type const& xc);
	operator type () const;
	operator type& ();
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 1);
private:
	type x;
};
typedef ttvec1<ibool>	bvec1;	// bvec = ivec
typedef ttvec1<i32>		ivec1;	// bvec = ivec
typedef ttvec1<ui32>	uvec1;
typedef ttvec1<flt>		vec1;
typedef ttvec1<dbl>		dvec1;


//-----------------------------------------------------------------------------

// Built-in type overrides.
///
#define bool										bvec1
#define int											ivec1
#define uint										uvec1
#define float										vec1
#define double										dvec1

#else	// !__cplusplus

// Vector definition shortcuts (in lieu of templates in C).
///
#define IJK_VECS(t1,x,t2,y)				struct { t1 x; t2 y; }
#define IJK_VEC2(t1,t2,t3,t4,x,y,z,w)	t2 x##y; IJK_VECS(t1,x,t1,y)
#define IJK_VEC3(t1,t2,t3,t4,x,y,z,w)	t3 x##y##z; t2 x##y; IJK_VECS(t1,x,union,{ IJK_VEC2(t1,t2,,,y,z,,); })
#define IJK_VEC4(t1,t2,t3,t4,x,y,z,w)	t4 x##y##z##w; t3 x##y##z; t2 x##y; IJK_VECS(t1,x,union,{ IJK_VEC3(t1,t2,t3,,y,z,w,); })
#define IJK_VEC_DECL(decl,t1,t2,t3,t4)	decl(t1,t2,t3,t4,x,y,z,w); decl(t1,t2,t3,t4,r,g,b,a); decl(t1,t2,t3,t4,s,t,p,q)

// IJK_VEC
//	Implements union vector of specified type in target interface.
//		param vecType: base type of vector (e.g. 'int' for integer vectors)
//		param vecSize: number of elements in vector (e.g. '2' for a 2D vector)
#define IJK_VEC_IMPL(vecType,vecSize)	IJK_VEC_DECL(IJK_VEC##vecSize,vecType,vecType##2,vecType##3,vecType##4)
#define IJK_BVEC_IMPL(vecSize)			IJK_VEC_IMPL(bool,vecSize)
#define IJK_IVEC_IMPL(vecSize)			IJK_VEC_IMPL(int,vecSize)
#define IJK_UVEC_IMPL(vecSize)			IJK_VEC_IMPL(uint,vecSize)
#define IJK_FVEC_IMPL(vecSize)			IJK_VEC_IMPL(float,vecSize)
#define IJK_DVEC_IMPL(vecSize)			IJK_VEC_IMPL(double,vecSize)


//-----------------------------------------------------------------------------

// Built-in type overrides.
///
#define bool		ibool
#define int			i32
#define uint		ui32
#define float		flt
#define double		dbl

#endif	// __cplusplus

//-----------------------------------------------------------------------------

#ifdef __cplusplus

// Template 2D vector type.
template<typename type>
union ttvec2
{
	explicit ttvec2(type const& xy = 0);							// Construct vector with all elements set to single scalar.
	explicit ttvec2(type const& xc, type const& yc);				// Construct vector with elements set individually.
	//explicit ttvec2(bool const* xy);								// Construct vector given boolean array-based vector.
	explicit ttvec2(int const* xy);									// Construct vector given signed integer array-based vector.
	explicit ttvec2(uint const* xy);								// Construct vector given unsigned integer array-based vector.
	explicit ttvec2(float const* xy);								// Construct vector given float array-based vector.
	explicit ttvec2(double const* xy);								// Construct vector given double array-based vector.
	ttvec2(ttvec2 const& xy);										// Construct vector given another 2D vector.
	explicit ttvec2(ttvec3<type> const& xy);						// Construct vector given the first two elements of a 3D vector.
	explicit ttvec2(ttvec4<type> const& xy);						// Construct vector given the first two elements of a 4D vector.
	explicit ttvec2(stvec1<type> const& xy);						// Construct vector given swizzle scalar.
	ttvec2(stvec2<type> const& xy);									// Construct vector given 2D swizzle vector.
	explicit ttvec2(stvec3<type> const& xy);						// Construct vector given 3D swizzle vector.
	explicit ttvec2(stvec4<type> const& xy);						// Construct vector given 4D swizzle vector.

	ttvec2& operator =(ttvec2 const& v_rh);
	ttvec2& operator =(stvec2<type> const& v_rh);

	ttvec2 operator +() const;
	ttvec2 operator -() const;
	ttvec2 operator ~() const;
	ttvec2<bool> operator !() const;
	ttvec2 operator +(ttvec2 const& v_rh) const;
	ttvec2 operator -(ttvec2 const& v_rh) const;
	ttvec2 operator *(ttvec2 const& v_rh) const;
	ttvec2 operator /(ttvec2 const& v_rh) const;
	ttvec2 operator %(ttvec2 const& v_rh) const;
	ttvec2 operator &(ttvec2 const& v_rh) const;
	ttvec2 operator |(ttvec2 const& v_rh) const;
	ttvec2 operator ^(ttvec2 const& v_rh) const;
	ttvec2 operator <<(ttvec2 const& v_rh) const;
	ttvec2 operator >>(ttvec2 const& v_rh) const;
	ttvec2<bool> operator ==(ttvec2 const& v_rh) const;
	ttvec2<bool> operator !=(ttvec2 const& v_rh) const;
	ttvec2<bool> operator <=(ttvec2 const& v_rh) const;
	ttvec2<bool> operator >=(ttvec2 const& v_rh) const;
	ttvec2<bool> operator <(ttvec2 const& v_rh) const;
	ttvec2<bool> operator >(ttvec2 const& v_rh) const;
	ttvec2 operator +(type const& s_rh) const;
	ttvec2 operator -(type const& s_rh) const;
	ttvec2 operator *(type const& s_rh) const;
	ttvec2 operator /(type const& s_rh) const;
	ttvec2 operator %(type const& s_rh) const;
	ttvec2 operator &(type const& s_rh) const;
	ttvec2 operator |(type const& s_rh) const;
	ttvec2 operator ^(type const& s_rh) const;
	ttvec2 operator <<(type const& s_rh) const;
	ttvec2 operator >>(type const& s_rh) const;
	ttvec2<bool> operator ==(type const& s_rh) const;
	ttvec2<bool> operator !=(type const& s_rh) const;
	ttvec2<bool> operator <=(type const& s_rh) const;
	ttvec2<bool> operator >=(type const& s_rh) const;
	ttvec2<bool> operator <(type const& s_rh) const;
	ttvec2<bool> operator >(type const& s_rh) const;
	type operator [](index const i) const;
	operator type const* () const;

	ttvec2& operator +=(ttvec2 const& v_rh);
	ttvec2& operator -=(ttvec2 const& v_rh);
	ttvec2& operator *=(ttvec2 const& v_rh);
	ttvec2& operator /=(ttvec2 const& v_rh);
	ttvec2& operator %=(ttvec2 const& v_rh);
	ttvec2& operator &=(ttvec2 const& v_rh);
	ttvec2& operator |=(ttvec2 const& v_rh);
	ttvec2& operator ^=(ttvec2 const& v_rh);
	ttvec2& operator <<=(ttvec2 const& v_rh);
	ttvec2& operator >>=(ttvec2 const& v_rh);
	ttvec2& operator +=(type const& s_rh);
	ttvec2& operator -=(type const& s_rh);
	ttvec2& operator *=(type const& s_rh);
	ttvec2& operator /=(type const& s_rh);
	ttvec2& operator %=(type const& s_rh);
	ttvec2& operator &=(type const& s_rh);
	ttvec2& operator |=(type const& s_rh);
	ttvec2& operator ^=(type const& s_rh);
	ttvec2& operator <<=(type const& s_rh);
	ttvec2& operator >>=(type const& s_rh);
	type& operator [](index const i);
	operator type* ();

	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 2);
private:
	type xy[2];
	struct { type x, y; };
};


//-----------------------------------------------------------------------------

// Swizzle scalar type.
template<typename type>
struct stvec1
{
	ttvec1<type> operator =(ttvec1<type> const v);
	ttvec1<type> operator =(stvec1 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 1);
private:
	type& x;
	stvec1(type& xr);
	friend stvec2<type>;
	friend stvec3<type>;
	friend stvec4<type>;
	friend ttvec1<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 2D vector type.
template<typename type>
struct stvec2
{
	ttvec2<type> operator =(ttvec2<type> const v);
	ttvec2<type> operator =(stvec2 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 2);
private:
	type& x, & y;
	stvec2(type& xr, type& yr);
	friend stvec3<type>;
	friend stvec4<type>;
	friend ttvec1<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 3D vector type.
template<typename type>
struct stvec3
{
	ttvec3<type> operator =(ttvec3<type> const v);
	ttvec3<type> operator =(stvec3 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 3);
private:
	type& x, & y, & z;
	stvec3(type& xr, type& yr, type& zr);
	friend stvec4<type>;
	friend ttvec1<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 4D vector type.
template<typename type>
struct stvec4
{
	ttvec4<type> operator =(ttvec4<type> const v);
	ttvec4<type> operator =(stvec4 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, stvec, 4);
private:
	type& x, & y, & z, & w;
	stvec4(type& xr, type& yr, type& zr, type& wr);
	friend ttvec1<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};


#endif	// __cplusplus

//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTORSWIZZLE_H_
#endif	// _IJK_VECTOR_H_ && !_IJK_VECTOR_INL_