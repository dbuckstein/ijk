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

	ijkVector.h
	Vector types and functions.
*/

#ifndef _IJK_VECTOR_H_
#define _IJK_VECTOR_H_


#include "ijkTrigonometry.h"


#ifdef __cplusplus

//-----------------------------------------------------------------------------

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
#define IJK_SWIZZLE_DECL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl rtb##rts<type,tvec1,tvec2,tvec3,tvec4> _##x##y##z##w() cf

// IJK_SWIZZLE_DECL_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare and implement swizzling functions within target
//	template interface using template return types.
#define IJK_SWIZZLE_DECL_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)							inl rtb##rts<type,tvec1,tvec2,tvec3,tvec4> _##x##y##z##w() cf { return rtb##rts<type,tvec1,tvec2,tvec3,tvec4>(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_TEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface. Requires prior paired use of IJK_SWIZZLE_DECL within target
//	interface.
#define IJK_SWIZZLE_IMPL_TEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4> inl rtb##rts ot<type,tvec1,tvec2,tvec3,tvec4>::_##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface using template return types. Requires prior IJK_SWIZZLE_DECL or
//	IJK_SWIZZLE_DECL_RTEMP within target interface.
#define IJK_SWIZZLE_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4> inl rtb##rts<type,tvec1,tvec2,tvec3,tvec4> ot<type,tvec1,tvec2,tvec3,tvec4>::_##x##y##z##w() cf { return rtb##rts<type,tvec1,tvec2,tvec3,tvec4>(__VA_ARGS__); }


//-----------------------------------------------------------------------------

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec4;

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec3;

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec2;

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec1
{
	tvec1 operator =(tvec1 const v);
	tvec1 operator =(stvec1 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL_RTEMP, tvec, stvec, stvec, 1);
private:
	type& x;
	stvec1(type& xr);
	friend stvec2<type, tvec1, tvec2, tvec3, tvec4>;
	friend stvec3<type, tvec1, tvec2, tvec3, tvec4>;
	friend stvec4<type, tvec1, tvec2, tvec3, tvec4>;
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec2
{
	tvec2 operator =(tvec2 const v);
	tvec2 operator =(stvec2 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL_RTEMP, tvec, stvec, stvec, 2);
private:
	type& x, & y;
	stvec2(type& xr, type& yr);
	friend stvec3<type, tvec1, tvec2, tvec3, tvec4>;
	friend stvec4<type, tvec1, tvec2, tvec3, tvec4>;
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec3
{
	tvec3 operator =(tvec3 const v);
	tvec3 operator =(stvec3 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL_RTEMP, tvec, stvec, stvec, 3);
private:
	type& x, & y, & z;
	stvec3(type& xr, type& yr, type& zr);
	friend stvec4<type, tvec1, tvec2, tvec3, tvec4>;
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct stvec4
{
	tvec4 operator =(tvec4 const v);
	tvec4 operator =(stvec4 const& v);
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL_RTEMP, tvec, stvec, stvec, 4);
private:
	type& x, & y, & z, & w;
	stvec4(type& xr, type& yr, type& zr, type& wr);
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template<typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
union ttvec1
{
	ttvec1(type const xc = 0);
	ttvec1& operator =(type const xc);
	operator type () const;
	operator type& ();
	explicit operator type const* () const;
	explicit operator type* ();
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL_RTEMP, tvec, stvec, ttvec, 1);
private:
	type v[1];
	type x;
};


extern "C" {
	union bvec2;
	union bvec3;
	union bvec4;
	union ivec2;
	union ivec3;
	union ivec4;
	union uvec2;
	union uvec3;
	union uvec4;
	union vec2;
	union vec3;
	union vec4;
	union dvec2;
	union dvec3;
	union dvec4;
}

typedef ttvec1<ibool, void, bvec2, bvec3, bvec4>	bvec1;
typedef ttvec1<i32, void, ivec2, ivec3, ivec4>		ivec1;
typedef ttvec1<ui32, void, uvec2, uvec3, uvec4>		uvec1;
typedef ttvec1<flt, void, vec2, vec3, vec4>			vec1;
typedef ttvec1<dbl, void, dvec2, dvec3, dvec4>		dvec1;
#define bool										bvec1
#define int											ivec1
#define uint										uvec1
#define float										vec1
#define double										dvec1

typedef stvec1<bool, ivec1, ivec2, ivec3, ivec4>	sbvec1;
typedef stvec1<int, ivec1, ivec2, ivec3, ivec4>		sivec1;
typedef stvec1<uint, uvec1, uvec2, uvec3, uvec4>	suvec1;
typedef stvec1<float, vec1, vec2, vec3, vec4>		svec1;
typedef stvec1<double, dvec1, dvec2, dvec3, dvec4>	sdvec1;
typedef stvec2<bool, ivec1, ivec2, ivec3, ivec4>	sbvec2;
typedef stvec2<int, ivec1, ivec2, ivec3, ivec4>		sivec2;
typedef stvec2<uint, uvec1, uvec2, uvec3, uvec4>	suvec2;
typedef stvec2<float, vec1, vec2, vec3, vec4>		svec2;
typedef stvec2<double, dvec1, dvec2, dvec3, dvec4>	sdvec2;
typedef stvec3<bool, ivec1, ivec2, ivec3, ivec4>	sbvec3;
typedef stvec3<int, ivec1, ivec2, ivec3, ivec4>		sivec3;
typedef stvec3<uint, uvec1, uvec2, uvec3, uvec4>	suvec3;
typedef stvec3<float, vec1, vec2, vec3, vec4>		svec3;
typedef stvec3<double, dvec1, dvec2, dvec3, dvec4>	sdvec3;
typedef stvec4<bool, ivec1, ivec2, ivec3, ivec4>	sbvec4;
typedef stvec4<int, ivec1, ivec2, ivec3, ivec4>		sivec4;
typedef stvec4<uint, uvec1, uvec2, uvec3, uvec4>	suvec4;
typedef stvec4<float, vec1, vec2, vec3, vec4>		svec4;
typedef stvec4<double, dvec1, dvec2, dvec3, dvec4>	sdvec4;


#pragma endregion
// IJK_SWIZZLE_MACRO_DECL


//-----------------------------------------------------------------------------

extern "C" {
#else	// !__cplusplus
typedef union bvec2	bvec2;
typedef union bvec3	bvec3;
typedef union bvec4	bvec4;
typedef union ivec2	ivec2;
typedef union ivec3	ivec3;
typedef union ivec4	ivec4;
typedef union uvec2	uvec2;
typedef union uvec3	uvec3;
typedef union uvec4	uvec4;
typedef union vec2	vec2;
typedef union vec3	vec3;
typedef union vec4	vec4;
typedef union dvec2	dvec2;
typedef union dvec3	dvec3;
typedef union dvec4	dvec4;

#define bool		ibool
#define int			i32
#define uint		ui32
#define float		flt
#define double		dbl
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// Reusable array-based vector types.
///
typedef bool
	bool2[2],					// 2D boolean array-based vector, always passed by pointer.
	bool3[3],					// 3D boolean array-based vector, always passed by pointer.
	bool4[4],					// 4D boolean array-based vector, always passed by pointer.
	* boolv;					// Generic signed integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef int
	int2[2],					// 2D signed integer array-based vector, always passed by pointer.
	int3[3],					// 3D signed integer array-based vector, always passed by pointer.
	int4[4],					// 4D signed integer array-based vector, always passed by pointer.
	* intv;						// Generic signed integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef uint
	uint2[2],					// 2D unsigned integer array-based vector, always passed by pointer.
	uint3[3],					// 3D unsigned integer array-based vector, always passed by pointer.
	uint4[4],					// 4D unsigned integer array-based vector, always passed by pointer.
	* uintv;					// Generic unsigned integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef float
	float2[2],					// 2D single-precision array-based vector, always passed by pointer.
	float3[3],					// 3D single-precision array-based vector, always passed by pointer.
	float4[4],					// 4D single-precision array-based vector, always passed by pointer.
	* floatv;					// Generic float single-precision-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef double
	double2[2],					// 2D double-precision array-based vector, always passed by pointer.
	double3[3],					// 3D double-precision array-based vector, always passed by pointer.
	double4[4],					// 4D double-precision array-based vector, always passed by pointer.
	* doublev;					// Generic double-precision array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.

typedef bool const* boolkv;		// Generic constant boolean array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef int const* intkv;		// Generic constant signed integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef uint const* uintkv;		// Generic constant unsigned integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef float const* floatkv;	// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef double const* doublekv;	// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.


//-----------------------------------------------------------------------------

// bvec2
//	Data structure representing 2D boolean vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 2D vector of first three components, useful for direct assignment
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union bvec2
{
	bool2 v;
	struct { bool x, y; };
	struct { bool r, g; };
	struct { bool s, t; };

#ifdef __cplusplus
	explicit bvec2(bool const& xy = false);			// Construct vector with all elements set to single scalar.
	explicit bvec2(bool const& xc, bool const& yc);	// Construct vector with elements set individually.
#endif	// __cplusplus
};

// bvec3
//	Data structure representing 3D boolean vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union bvec3
{
	bool3 v;
	//bvec2 xy;
	struct { bool x, y, z; };
	struct { bool r, g, b; };
	struct { bool s, t, p; };

#ifdef __cplusplus
	explicit bvec3(bool const& xyz = false);								// Construct vector with all elements set to single scalar.
	explicit bvec3(bool const& xc, bool const& yc, bool const& zc = false);	// Construct vector with elements set individually.
#endif	// __cplusplus
};

// bvec4
//	Data structure representing 4D boolean vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union bvec4
{
	bool4 v;
	//bvec3 xyz;
	//bvec2 xy;
	struct { bool x, y, z, w; };
	struct { bool r, g, b, a; };
	struct { bool s, t, p, q; };

#ifdef __cplusplus
	explicit bvec4(bool const& xyzw = false);														// Construct vector with all elements set to single scalar.
	explicit bvec4(bool const& xc, bool const& yc, bool const& zc = false, bool const& wc = true);	// Construct vector with elements set individually.
#endif	// __cplusplus
};


//-----------------------------------------------------------------------------

// ivec2
//	Data structure representing 2D signed integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
	int2 v;
	struct { int x, y; };
	struct { int r, g; };
	struct { int s, t; };

#ifdef __cplusplus
	explicit ivec2(int const& xy = 0);				// Construct vector with all elements set to single scalar.
	explicit ivec2(int const& xc, int const& yc);	// Construct vector with elements set individually.
	ivec2(int2 const xy);							// Construct vector given signed integer array-based vector.
	explicit ivec2(uint2 const xy);					// Construct vector given unsigned integer array-based vector.
	explicit ivec2(float2 const xy);				// Construct vector given float array-based vector.
	explicit ivec2(double2 const xy);				// Construct vector given double array-based vector.
	explicit ivec2(bvec2 const& xy);				// Construct vector given a 2D unsigned boolean vector.
	explicit ivec2(bvec3 const& xy);				// Construct vector given the first two elements of a 3D boolean vector.
	explicit ivec2(bvec4 const& xy);				// Construct vector given the first two elements of a 4D boolean vector.
	ivec2(ivec2 const& xy);							// Construct vector given another 2D integer vector.
	explicit ivec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D signed integer vector.
	explicit ivec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D signed integer vector.
	explicit ivec2(uvec2 const& xy);				// Construct vector given a 2D unsigned integer vector.
	explicit ivec2(uvec3 const& xy);				// Construct vector given the first two elements of a 3D unsigned integer vector.
	explicit ivec2(uvec4 const& xy);				// Construct vector given the first two elements of a 4D unsigned integer vector.
	explicit ivec2(vec2 const& xy);					// Construct vector given a 2D float vector.
	explicit ivec2(vec3 const& xy);					// Construct vector given the first two elements of a 3D float vector.
	explicit ivec2(vec4 const& xy);					// Construct vector given the first two elements of a 4D float vector.
	explicit ivec2(dvec2 const& xy);				// Construct vector given a 2D double vector.
	explicit ivec2(dvec3 const& xy);				// Construct vector given the first two elements of a 3D double vector.
	explicit ivec2(dvec4 const& xy);				// Construct vector given the first two elements of a 4D double vector.
	ivec2(sivec2 const& xy);						// Construct vector given swizzle vector.

	ivec2& operator =(int2 const v_rh);
	ivec2& operator =(ivec2 const& v_rh);
	ivec2& operator =(sivec2 const& v_rh);

	ivec2 operator +() const;
	ivec2 operator -() const;
	ivec2 operator ~() const;
	ivec2 operator +(ivec2 const& v_rh) const;
	ivec2 operator -(ivec2 const& v_rh) const;
	ivec2 operator *(ivec2 const& v_rh) const;
	ivec2 operator /(ivec2 const& v_rh) const;
	ivec2 operator %(ivec2 const& v_rh) const;
	ivec2 operator &(ivec2 const& v_rh) const;
	ivec2 operator |(ivec2 const& v_rh) const;
	ivec2 operator ^(ivec2 const& v_rh) const;
	ivec2 operator <<(ivec2 const& v_rh) const;
	ivec2 operator >>(ivec2 const& v_rh) const;
	bvec2 operator ==(ivec2 const& v_rh) const;
	bvec2 operator !=(ivec2 const& v_rh) const;
	bvec2 operator <=(ivec2 const& v_rh) const;
	bvec2 operator >=(ivec2 const& v_rh) const;
	bvec2 operator <(ivec2 const& v_rh) const;
	bvec2 operator >(ivec2 const& v_rh) const;
	ivec2 operator +(int const& s_rh) const;
	ivec2 operator -(int const& s_rh) const;
	ivec2 operator *(int const& s_rh) const;
	ivec2 operator /(int const& s_rh) const;
	ivec2 operator %(int const& s_rh) const;
	ivec2 operator &(int const& s_rh) const;
	ivec2 operator |(int const& s_rh) const;
	ivec2 operator ^(int const& s_rh) const;
	ivec2 operator <<(int const& s_rh) const;
	ivec2 operator >>(int const& s_rh) const;
	bvec2 operator ==(int const& s_rh) const;
	bvec2 operator !=(int const& s_rh) const;
	bvec2 operator <=(int const& s_rh) const;
	bvec2 operator >=(int const& s_rh) const;
	bvec2 operator <(int const& s_rh) const;
	bvec2 operator >(int const& s_rh) const;
	int operator [](index const i) const;
	operator intkv () const;
	operator i32 const* () const;

	ivec2& operator +=(ivec2 const& v_rh);
	ivec2& operator -=(ivec2 const& v_rh);
	ivec2& operator *=(ivec2 const& v_rh);
	ivec2& operator /=(ivec2 const& v_rh);
	ivec2& operator %=(ivec2 const& v_rh);
	ivec2& operator &=(ivec2 const& v_rh);
	ivec2& operator |=(ivec2 const& v_rh);
	ivec2& operator ^=(ivec2 const& v_rh);
	ivec2& operator <<=(ivec2 const& v_rh);
	ivec2& operator >>=(ivec2 const& v_rh);
	ivec2& operator +=(int const& s_rh);
	ivec2& operator -=(int const& s_rh);
	ivec2& operator *=(int const& s_rh);
	ivec2& operator /=(int const& s_rh);
	ivec2& operator %=(int const& s_rh);
	ivec2& operator &=(int const& s_rh);
	ivec2& operator |=(int const& s_rh);
	ivec2& operator ^=(int const& s_rh);
	ivec2& operator <<=(int const& s_rh);
	ivec2& operator >>=(int const& s_rh);
	int& operator [](index const i);
	operator intv ();
	operator i32* ();

	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL, IJK_SWIZZLE_DECL, ivec, sivec, ivec, 2);
#endif	// __cplusplus
};

// ivec3
//	Data structure representing 3D signed integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ivec3
{
	int3 v;
	//ivec2 xy;
	struct { int x, y, z; };
	struct { int r, g, b; };
	struct { int s, t, p; };

#ifdef __cplusplus
	explicit ivec3(int const& xyz = 0);									// Construct vector with all elements set to single scalar.
	explicit ivec3(int const& xc, int const& yc, int const& zc = 0);	// Construct vector with elements set individually.
#endif	// __cplusplus
};

// ivec4
//	Data structure representing 4D signed integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union ivec4
{
	int4 v;
	//ivec3 xyz;
	//ivec2 xy;
	struct { int x, y, z, w; };
	struct { int r, g, b, a; };
	struct { int s, t, p, q; };

#ifdef __cplusplus
	explicit ivec4(int const& xyzw = 0);												// Construct vector with all elements set to single scalar.
	explicit ivec4(int const& xc, int const& yc, int const& zc = 0, int const& wc = 1);	// Construct vector with elements set individually.
#endif	// __cplusplus
};


// Global constants for signed integer array-based vectors and data structures.
///
ijk_ext int2 const int2_one;		// ( +1, +1 )
ijk_ext int2 const int2_zero;		// (  0,  0 )
ijk_ext int2 const int2_one_n;		// ( -1, -1 )
ijk_ext int2 const int2_x;			// ( +1,  0 )
ijk_ext int2 const int2_y;			// (  0, +1 )
ijk_ext int2 const int2_x_n;		// ( -1,  0 )
ijk_ext int2 const int2_y_n;		// (  0, -1 )

ijk_ext int3 const int3_one;		// ( +1, +1, +1 )
ijk_ext int3 const int3_zero;		// (  0,  0,  0 )
ijk_ext int3 const int3_one_n;		// ( -1, -1, -1 )
ijk_ext int3 const int3_x;			// ( +1,  0,  0 )
ijk_ext int3 const int3_y;			// (  0, +1,  0 )
ijk_ext int3 const int3_z;			// (  0,  0, +1 )
ijk_ext int3 const int3_x_n;		// ( -1,  0,  0 )
ijk_ext int3 const int3_y_n;		// (  0, -1,  0 )
ijk_ext int3 const int3_z_n;		// (  0,  0, -1 )

ijk_ext int4 const int4_one;		// ( +1, +1, +1, +1 )
ijk_ext int4 const int4_zero;		// (  0,  0,  0,  0 )
ijk_ext int4 const int4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext int4 const int4_x;			// ( +1,  0,  0,  0 )
ijk_ext int4 const int4_y;			// (  0, +1,  0,  0 )
ijk_ext int4 const int4_z;			// (  0,  0, +1,  0 )
ijk_ext int4 const int4_w;			// (  0,  0,  0, +1 )
ijk_ext int4 const int4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext int4 const int4_y_n;		// (  0, -1,  0,  0 )
ijk_ext int4 const int4_z_n;		// (  0,  0, -1,  0 )
ijk_ext int4 const int4_w_n;		// (  0,  0,  0, -1 )

ijk_ext ivec2 const ivec2_one;		// ( +1, +1 )
ijk_ext ivec2 const ivec2_zero;		// (  0,  0 )
ijk_ext ivec2 const ivec2_one_n;	// ( -1, -1 )
ijk_ext ivec2 const ivec2_x;		// ( +1,  0 )
ijk_ext ivec2 const ivec2_y;		// (  0, +1 )
ijk_ext ivec2 const ivec2_x_n;		// ( -1,  0 )
ijk_ext ivec2 const ivec2_y_n;		// (  0, -1 )

ijk_ext ivec3 const ivec3_one;		// ( +1, +1, +1 )
ijk_ext ivec3 const ivec3_zero;		// (  0,  0,  0 )
ijk_ext ivec3 const ivec3_one_n;	// ( -1, -1, -1 )
ijk_ext ivec3 const ivec3_x;		// ( +1,  0,  0 )
ijk_ext ivec3 const ivec3_y;		// (  0, +1,  0 )
ijk_ext ivec3 const ivec3_z;		// (  0,  0, +1 )
ijk_ext ivec3 const ivec3_x_n;		// ( -1,  0,  0 )
ijk_ext ivec3 const ivec3_y_n;		// (  0, -1,  0 )
ijk_ext ivec3 const ivec3_z_n;		// (  0,  0, -1 )

ijk_ext ivec4 const ivec4_one;		// ( +1, +1, +1, +1 )
ijk_ext ivec4 const ivec4_zero;		// (  0,  0,  0,  0 )
ijk_ext ivec4 const ivec4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext ivec4 const ivec4_x;		// ( +1,  0,  0,  0 )
ijk_ext ivec4 const ivec4_y;		// (  0, +1,  0,  0 )
ijk_ext ivec4 const ivec4_z;		// (  0,  0, +1,  0 )
ijk_ext ivec4 const ivec4_w;		// (  0,  0,  0, +1 )
ijk_ext ivec4 const ivec4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext ivec4 const ivec4_y_n;		// (  0, -1,  0,  0 )
ijk_ext ivec4 const ivec4_z_n;		// (  0,  0, -1,  0 )
ijk_ext ivec4 const ivec4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

// uvec2
//	Data structure representing 2D unsigned integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union uvec2
{
	uint2 v;
	struct { uint x, y, z, w; };
	struct { uint r, g, b, a; };
	struct { uint s, t, p, q; };
};

// uvec3
//	Data structure representing 3D unsigned integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union uvec3
{
	uint3 v;
	//uvec2 xy;
	struct { uint x, y, z; };
	struct { uint r, g, b; };
	struct { uint s, t, p; };
};

// uvec4
//	Data structure representing 4D unsigned integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union uvec4
{
	uint4 v;
	//uvec3 xyz;
	//uvec2 xy;
	struct { uint x, y, z, w; };
	struct { uint r, g, b, a; };
	struct { uint s, t, p, q; };
};


// Global constants for unsigned integer array-based vectors and data structures.
// Note: negatives are represented as maximum unsigned value.
///
ijk_ext uint2 const uint2_one;		// ( +1, +1 )
ijk_ext uint2 const uint2_zero;		// (  0,  0 )
ijk_ext uint2 const uint2_one_n;	// ( -1, -1 )
ijk_ext uint2 const uint2_x;		// ( +1,  0 )
ijk_ext uint2 const uint2_y;		// (  0, +1 )
ijk_ext uint2 const uint2_x_n;		// ( -1,  0 )
ijk_ext uint2 const uint2_y_n;		// (  0, -1 )

ijk_ext uint3 const uint3_one;		// ( +1, +1, +1 )
ijk_ext uint3 const uint3_zero;		// (  0,  0,  0 )
ijk_ext uint3 const uint3_one_n;	// ( -1, -1, -1 )
ijk_ext uint3 const uint3_x;		// ( +1,  0,  0 )
ijk_ext uint3 const uint3_y;		// (  0, +1,  0 )
ijk_ext uint3 const uint3_z;		// (  0,  0, +1 )
ijk_ext uint3 const uint3_x_n;		// ( -1,  0,  0 )
ijk_ext uint3 const uint3_y_n;		// (  0, -1,  0 )
ijk_ext uint3 const uint3_z_n;		// (  0,  0, -1 )

ijk_ext uint4 const uint4_one;		// ( +1, +1, +1, +1 )
ijk_ext uint4 const uint4_zero;		// (  0,  0,  0,  0 )
ijk_ext uint4 const uint4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext uint4 const uint4_x;		// ( +1,  0,  0,  0 )
ijk_ext uint4 const uint4_y;		// (  0, +1,  0,  0 )
ijk_ext uint4 const uint4_z;		// (  0,  0, +1,  0 )
ijk_ext uint4 const uint4_w;		// (  0,  0,  0, +1 )
ijk_ext uint4 const uint4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext uint4 const uint4_y_n;		// (  0, -1,  0,  0 )
ijk_ext uint4 const uint4_z_n;		// (  0,  0, -1,  0 )
ijk_ext uint4 const uint4_w_n;		// (  0,  0,  0, -1 )

ijk_ext uvec2 const uvec2_one;		// ( +1, +1 )
ijk_ext uvec2 const uvec2_zero;		// (  0,  0 )
ijk_ext uvec2 const uvec2_one_n;	// ( -1, -1 )
ijk_ext uvec2 const uvec2_x;		// ( +1,  0 )
ijk_ext uvec2 const uvec2_y;		// (  0, +1 )
ijk_ext uvec2 const uvec2_x_n;		// ( -1,  0 )
ijk_ext uvec2 const uvec2_y_n;		// (  0, -1 )

ijk_ext uvec3 const uvec3_one;		// ( +1, +1, +1 )
ijk_ext uvec3 const uvec3_zero;		// (  0,  0,  0 )
ijk_ext uvec3 const uvec3_one_n;	// ( -1, -1, -1 )
ijk_ext uvec3 const uvec3_x;		// ( +1,  0,  0 )
ijk_ext uvec3 const uvec3_y;		// (  0, +1,  0 )
ijk_ext uvec3 const uvec3_z;		// (  0,  0, +1 )
ijk_ext uvec3 const uvec3_x_n;		// ( -1,  0,  0 )
ijk_ext uvec3 const uvec3_y_n;		// (  0, -1,  0 )
ijk_ext uvec3 const uvec3_z_n;		// (  0,  0, -1 )

ijk_ext uvec4 const uvec4_one;		// ( +1, +1, +1, +1 )
ijk_ext uvec4 const uvec4_zero;		// (  0,  0,  0,  0 )
ijk_ext uvec4 const uvec4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext uvec4 const uvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext uvec4 const uvec4_y;		// (  0, +1,  0,  0 )
ijk_ext uvec4 const uvec4_z;		// (  0,  0, +1,  0 )
ijk_ext uvec4 const uvec4_w;		// (  0,  0,  0, +1 )
ijk_ext uvec4 const uvec4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext uvec4 const uvec4_y_n;		// (  0, -1,  0,  0 )
ijk_ext uvec4 const uvec4_z_n;		// (  0,  0, -1,  0 )
ijk_ext uvec4 const uvec4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

// vec2
//	Data structure representing 2D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union vec2
{
	float2 v;
	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float s, t, p, q; };
};

// vec3
//	Data structure representing 3D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union vec3
{
	float3 v;
	//vec2 xy;
	struct { float x, y, z; };
	struct { float r, g, b; };
	struct { float s, t, p; };
};

// vec4
//	Data structure representing 4D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union vec4
{
	float4 v;
	//vec3 xyz;
	//vec2 xy;
	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float s, t, p, q; };
};


// Global constants for float array-based vectors and data structures.
///
ijk_ext float2 const float2_one;	// ( +1, +1 )
ijk_ext float2 const float2_zero;	// (  0,  0 )
ijk_ext float2 const float2_one_n;	// ( -1, -1 )
ijk_ext float2 const float2_x;		// ( +1,  0 )
ijk_ext float2 const float2_y;		// (  0, +1 )
ijk_ext float2 const float2_x_n;	// ( -1,  0 )
ijk_ext float2 const float2_y_n;	// (  0, -1 )

ijk_ext float3 const float3_one;	// ( +1, +1, +1 )
ijk_ext float3 const float3_zero;	// (  0,  0,  0 )
ijk_ext float3 const float3_one_n;	// ( -1, -1, -1 )
ijk_ext float3 const float3_x;		// ( +1,  0,  0 )
ijk_ext float3 const float3_y;		// (  0, +1,  0 )
ijk_ext float3 const float3_z;		// (  0,  0, +1 )
ijk_ext float3 const float3_x_n;	// ( -1,  0,  0 )
ijk_ext float3 const float3_y_n;	// (  0, -1,  0 )
ijk_ext float3 const float3_z_n;	// (  0,  0, -1 )

ijk_ext float4 const float4_one;	// ( +1, +1, +1, +1 )
ijk_ext float4 const float4_zero;	// (  0,  0,  0,  0 )
ijk_ext float4 const float4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext float4 const float4_x;		// ( +1,  0,  0,  0 )
ijk_ext float4 const float4_y;		// (  0, +1,  0,  0 )
ijk_ext float4 const float4_z;		// (  0,  0, +1,  0 )
ijk_ext float4 const float4_w;		// (  0,  0,  0, +1 )
ijk_ext float4 const float4_x_n;	// ( -1,  0,  0,  0 )
ijk_ext float4 const float4_y_n;	// (  0, -1,  0,  0 )
ijk_ext float4 const float4_z_n;	// (  0,  0, -1,  0 )
ijk_ext float4 const float4_w_n;	// (  0,  0,  0, -1 )

ijk_ext vec2 const vec2_one;		// ( +1, +1 )
ijk_ext vec2 const vec2_zero;		// (  0,  0 )
ijk_ext vec2 const vec2_one_n;		// ( -1, -1 )
ijk_ext vec2 const vec2_x;			// ( +1,  0 )
ijk_ext vec2 const vec2_y;			// (  0, +1 )
ijk_ext vec2 const vec2_x_n;		// ( -1,  0 )
ijk_ext vec2 const vec2_y_n;		// (  0, -1 )

ijk_ext vec3 const vec3_one;		// ( +1, +1, +1 )
ijk_ext vec3 const vec3_zero;		// (  0,  0,  0 )
ijk_ext vec3 const vec3_one_n;		// ( -1, -1, -1 )
ijk_ext vec3 const vec3_x;			// ( +1,  0,  0 )
ijk_ext vec3 const vec3_y;			// (  0, +1,  0 )
ijk_ext vec3 const vec3_z;			// (  0,  0, +1 )
ijk_ext vec3 const vec3_x_n;		// ( -1,  0,  0 )
ijk_ext vec3 const vec3_y_n;		// (  0, -1,  0 )
ijk_ext vec3 const vec3_z_n;		// (  0,  0, -1 )

ijk_ext vec4 const vec4_one;		// ( +1, +1, +1, +1 )
ijk_ext vec4 const vec4_zero;		// (  0,  0,  0,  0 )
ijk_ext vec4 const vec4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext vec4 const vec4_x;			// ( +1,  0,  0,  0 )
ijk_ext vec4 const vec4_y;			// (  0, +1,  0,  0 )
ijk_ext vec4 const vec4_z;			// (  0,  0, +1,  0 )
ijk_ext vec4 const vec4_w;			// (  0,  0,  0, +1 )
ijk_ext vec4 const vec4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext vec4 const vec4_y_n;		// (  0, -1,  0,  0 )
ijk_ext vec4 const vec4_z_n;		// (  0,  0, -1,  0 )
ijk_ext vec4 const vec4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

// dvec2
//	Data structure representing 2D double-precision (double) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union dvec2
{
	double2 v;
	struct { double x, y, z, w; };
	struct { double r, g, b, a; };
	struct { double s, t, p, q; };
};

// dvec3
//	Data structure representing 3D double-precision (double) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union dvec3
{
	double3 v;
	//dvec2 xy;
	struct { double x, y, z; };
	struct { double r, g, b; };
	struct { double s, t, p; };
};

// dvec4
//	Data structure representing 4D double-precision (double) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union dvec4
{
	double4 v;
	//dvec3 xyz;
	//dvec2 xy;
	struct { double x, y, z, w; };
	struct { double r, g, b, a; };
	struct { double s, t, p, q; };
};


// Global constants for double array-based vectors and data structures.
///
ijk_ext double2 const double2_one;		// ( +1, +1 )
ijk_ext double2 const double2_zero;		// (  0,  0 )
ijk_ext double2 const double2_one_n;	// ( -1, -1 )
ijk_ext double2 const double2_x;		// ( +1,  0 )
ijk_ext double2 const double2_y;		// (  0, +1 )
ijk_ext double2 const double2_x_n;		// ( -1,  0 )
ijk_ext double2 const double2_y_n;		// (  0, -1 )

ijk_ext double3 const double3_one;		// ( +1, +1, +1 )
ijk_ext double3 const double3_zero;		// (  0,  0,  0 )
ijk_ext double3 const double3_one_n;	// ( -1, -1, -1 )
ijk_ext double3 const double3_x;		// ( +1,  0,  0 )
ijk_ext double3 const double3_y;		// (  0, +1,  0 )
ijk_ext double3 const double3_z;		// (  0,  0, +1 )
ijk_ext double3 const double3_x_n;		// ( -1,  0,  0 )
ijk_ext double3 const double3_y_n;		// (  0, -1,  0 )
ijk_ext double3 const double3_z_n;		// (  0,  0, -1 )

ijk_ext double4 const double4_one;		// ( +1, +1, +1, +1 )
ijk_ext double4 const double4_zero;		// (  0,  0,  0,  0 )
ijk_ext double4 const double4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext double4 const double4_x;		// ( +1,  0,  0,  0 )
ijk_ext double4 const double4_y;		// (  0, +1,  0,  0 )
ijk_ext double4 const double4_z;		// (  0,  0, +1,  0 )
ijk_ext double4 const double4_w;		// (  0,  0,  0, +1 )
ijk_ext double4 const double4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext double4 const double4_y_n;		// (  0, -1,  0,  0 )
ijk_ext double4 const double4_z_n;		// (  0,  0, -1,  0 )
ijk_ext double4 const double4_w_n;		// (  0,  0,  0, -1 )

ijk_ext dvec2 const dvec2_one;			// ( +1, +1 )
ijk_ext dvec2 const dvec2_zero;			// (  0,  0 )
ijk_ext dvec2 const dvec2_one_n;		// ( -1, -1 )
ijk_ext dvec2 const dvec2_x;			// ( +1,  0 )
ijk_ext dvec2 const dvec2_y;			// (  0, +1 )
ijk_ext dvec2 const dvec2_x_n;			// ( -1,  0 )
ijk_ext dvec2 const dvec2_y_n;			// (  0, -1 )

ijk_ext dvec3 const dvec3_one;			// ( +1, +1, +1 )
ijk_ext dvec3 const dvec3_zero;			// (  0,  0,  0 )
ijk_ext dvec3 const dvec3_one_n;		// ( -1, -1, -1 )
ijk_ext dvec3 const dvec3_x;			// ( +1,  0,  0 )
ijk_ext dvec3 const dvec3_y;			// (  0, +1,  0 )
ijk_ext dvec3 const dvec3_z;			// (  0,  0, +1 )
ijk_ext dvec3 const dvec3_x_n;			// ( -1,  0,  0 )
ijk_ext dvec3 const dvec3_y_n;			// (  0, -1,  0 )
ijk_ext dvec3 const dvec3_z_n;			// (  0,  0, -1 )

ijk_ext dvec4 const dvec4_one;			// ( +1, +1, +1, +1 )
ijk_ext dvec4 const dvec4_zero;			// (  0,  0,  0,  0 )
ijk_ext dvec4 const dvec4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext dvec4 const dvec4_x;			// ( +1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_y;			// (  0, +1,  0,  0 )
ijk_ext dvec4 const dvec4_z;			// (  0,  0, +1,  0 )
ijk_ext dvec4 const dvec4_w;			// (  0,  0,  0, +1 )
ijk_ext dvec4 const dvec4_x_n;			// ( -1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_y_n;			// (  0, -1,  0,  0 )
ijk_ext dvec4 const dvec4_z_n;			// (  0,  0, -1,  0 )
ijk_ext dvec4 const dvec4_w_n;			// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

// Select real vector types.
///
typedef real
	real2[2],					// 2D real-type array-based vector, always passed by pointer.
	real3[3],					// 3D real-type array-based vector, always passed by pointer.
	real4[4],					// 4D real-type array-based vector, always passed by pointer.
	* realv;					// Generic real-type array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.

typedef real const* realkv;		// Generic constant real-type array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.

#ifdef IJK_REAL_DBL
typedef dvec2	rvec2;		// Real 2D vector data structure type is 2D double vector.
typedef dvec3	rvec3;		// Real 3D vector data structure type is 3D double vector.
typedef dvec4	rvec4;		// Real 4D vector data structure type is 4D double vector.
#else	// !IJK_REAL_DBL
typedef vec2	rvec2;		// Real 2D vector data structure type is 2D float vector.
typedef vec3	rvec3;		// Real 3D vector data structure type is 3D float vector.
typedef vec4	rvec4;		// Real 4D vector data structure type is 4D float vector.
#endif	// IJK_REAL_DBL


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}


//-----------------------------------------------------------------------------
/*
ivec2 const operator +(i32 const s, ivec2 const& v);
ivec2 const operator -(i32 const s, ivec2 const& v);
ivec2 const operator *(i32 const s, ivec2 const& v);
ivec2 const operator /(i32 const s, ivec2 const& v);

i32 dot(ivec2 const& v_lh, ivec2 const& v_rh);
i32 lengthSq(ivec2 const& v);
//i32 length(ivec2 const& v);
//i32 lengthSqInv(ivec2 const& v);
//i32 lengthInv(ivec2 const& v);
i32 cross(ivec2 const& v_lh, ivec2 const& v_rh);
i32 crossSgn(ivec2 const& v_lh, ivec2 const& v_rh);
//ivec2 const unit(ivec2 const& v);
//ivec2& unitSet(ivec2& v);
//ivec2 const proj(ivec2 const& v_base, ivec2 const& v);
//ivec2& projSet(ivec2 const& v_base, ivec2& v);
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


#endif	// __cplusplus


#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_