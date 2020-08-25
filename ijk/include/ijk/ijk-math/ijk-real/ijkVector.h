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
extern "C" {
	union uvec2;
	union uvec3;
	union uvec4;
	union ivec2;
	union ivec3;
	union ivec4;
	union vec2;
	union vec3;
	union vec4;
	union dvec2;
	union dvec3;
	union dvec4;
}

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
#define IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3,...)		IJK_SWIZZLE_F2(swiz,inl,cf,ot,rtb,f1,f2); f1(swiz,inl,cf,ot,rtb,z,,,); f2(swiz,inl,cf,ot,rtb,x,z,,); f2(swiz,inl,cf,ot,rtb,z,x,,); f2(swiz,inl,cf,ot,rtb,y,z,,); f2(swiz,inl,cf,ot,rtb,z,x,,); f3(swiz,inl,cf,ot,rtb,x,y,z,); f3(swiz,inl,cf,ot,rtb,y,z,x,); f3(swiz,inl,cf,ot,rtb,z,x,y,); f3(swiz,inl,cf,ot,rtb,y,x,z,); f3(swiz,inl,cf,ot,rtb,x,z,y,); f3(swiz,inl,cf,ot,rtb,z,y,x,)
#define IJK_SWIZZLE_F4(swiz,inl,cf,ot,rtb,f1,f2,f3,f4,...)	IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3); f1(swiz,inl,cf,ot,rtb,w,,,); f2(swiz,inl,cf,ot,rtb,x,w,,); f2(swiz,inl,cf,ot,rtb,w,x,,); f2(swiz,inl,cf,ot,rtb,y,w,,); f2(swiz,inl,cf,ot,rtb,w,y,,); f2(swiz,inl,cf,ot,rtb,z,w,,); f2(swiz,inl,cf,ot,rtb,w,z,,); f3(swiz,inl,cf,ot,rtb,x,y,w,); f3(swiz,inl,cf,ot,rtb,y,x,w,); f3(swiz,inl,cf,ot,rtb,x,z,w,); f3(swiz,inl,cf,ot,rtb,z,x,w,); f3(swiz,inl,cf,ot,rtb,x,w,y,); f3(swiz,inl,cf,ot,rtb,w,x,y,); f3(swiz,inl,cf,ot,rtb,y,z,w,); f3(swiz,inl,cf,ot,rtb,z,y,w,); f3(swiz,inl,cf,ot,rtb,y,w,x,); f3(swiz,inl,cf,ot,rtb,w,y,x,); f3(swiz,inl,cf,ot,rtb,x,w,z,); f3(swiz,inl,cf,ot,rtb,w,x,z,); f3(swiz,inl,cf,ot,rtb,y,w,z,); f3(swiz,inl,cf,ot,rtb,w,y,z,); f3(swiz,inl,cf,ot,rtb,z,w,x,); f3(swiz,inl,cf,ot,rtb,w,z,x,); f3(swiz,inl,cf,ot,rtb,w,z,y,); f3(swiz,inl,cf,ot,rtb,z,w,y,); f4(swiz,inl,cf,ot,rtb,x,y,z,w); f4(swiz,inl,cf,ot,rtb,x,y,w,z); f4(swiz,inl,cf,ot,rtb,x,z,y,w); f4(swiz,inl,cf,ot,rtb,x,z,w,y); f4(swiz,inl,cf,ot,rtb,x,w,y,z); f4(swiz,inl,cf,ot,rtb,x,w,z,y); f4(swiz,inl,cf,ot,rtb,y,x,z,w); f4(swiz,inl,cf,ot,rtb,y,x,w,z); f4(swiz,inl,cf,ot,rtb,y,z,x,w); f4(swiz,inl,cf,ot,rtb,y,z,w,x); f4(swiz,inl,cf,ot,rtb,y,w,x,z); f4(swiz,inl,cf,ot,rtb,y,w,z,x); f4(swiz,inl,cf,ot,rtb,z,x,y,w); f4(swiz,inl,cf,ot,rtb,z,x,w,y); f4(swiz,inl,cf,ot,rtb,z,y,x,w); f4(swiz,inl,cf,ot,rtb,z,y,w,x); f4(swiz,inl,cf,ot,rtb,z,w,x,y); f4(swiz,inl,cf,ot,rtb,z,w,y,x); f4(swiz,inl,cf,ot,rtb,w,x,y,z); f4(swiz,inl,cf,ot,rtb,w,x,z,y); f4(swiz,inl,cf,ot,rtb,w,y,x,z); f4(swiz,inl,cf,ot,rtb,w,y,z,x); f4(swiz,inl,cf,ot,rtb,w,z,x,y); f4(swiz,inl,cf,ot,rtb,w,z,y,x)
#define IJK_SWIZZLE(F,swiz,inl,cf,ot,rtb,f1,f2,f3,f4)		F(swiz,inl,cf,ot,rtb,f1,f2,f3,f4)

// IJK_SWIZZLE_READONLY
//	Configure read-only (constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format ('IJK_SWIZZLE_DECL' or 'IJK_SWIZZLE_IMPL' or 'IJK_SWIZZLE_DECL_IMPL')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of vec2)
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param __VA_ARGS__: optional: pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_READONLY(swizzleFormat,ownerTypeSize,ownerTypeBase,returnTypeBase,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_D1,IJK_SWIZZLE_D2,IJK_SWIZZLE_D3,IJK_SWIZZLE_D4); IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_WRITABLE
//	Configure writable (non-constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format ('IJK_SWIZZLE_DECL' or 'IJK_SWIZZLE_IMPL' or 'IJK_SWIZZLE_DECL_IMPL')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of vec2)
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param __VA_ARGS__: optional: pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_WRITABLE(swizzleFormat,ownerTypeSize,ownerTypeBase,returnTypeBase,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_DECL
//	Pass to IJK_SWIZZLE as 'swizzleMacro' to declare swizzling functions 
//	within interface. Follow with IJK_SWIZZLE_IMPL or IJK_SWIZZLE_IMPL_TEMP 
//	outside of the interface (in header or inline file).
#define IJK_SWIZZLE_DECL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl rtb##rts _##x##y##z##w() cf

// IJK_SWIZZLE_IMPL
//	Pass to IJK_SWIZZLE as 'swizzleMacro' to implement inline swizzling 
//	functions outside of target interface. Requires prior IJK_SWIZZLE_DECL 
//	within target interface.
#define IJK_SWIZZLE_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl rtb##rts ot::_##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_DECL_IMPL
//	Pass to IJK_SWIZZLE as 'swizzleMacro' to declare and implement swizzling 
//	functions within interface.
#define IJK_SWIZZLE_DECL_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl rtb##rts _##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_TEMP
//	Pass to IJK_SWIZZLE as 'swizzleMacro' to implement inline swizzling 
//	functions outside of target interface using template types. Requires 
//	prior IJK_SWIZZLE_DECL within target interface.
#define IJK_SWIZZLE_IMPL_TEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4> inl rtb##rts<type,tvec1,tvec2,tvec3,tvec4> ot::_##x##y##z##w() cf { return rtb##rts<type,tvec1,tvec2,tvec3,tvec4>(__VA_ARGS__); }

// IJK_SWIZZLE_DECL_IMPL_TEMP
//	Pass to IJK_SWIZZLE as 'swizzleMacro' to declare and implement swizzling 
//	functions within interface using template types.
#define IJK_SWIZZLE_DECL_IMPL_TEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)							inl rtb##rts<type,tvec1,tvec2,tvec3,tvec4> _##x##y##z##w() cf { return rtb##rts<type,tvec1,tvec2,tvec3,tvec4>(__VA_ARGS__); }


template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct tsvec1
{
	tvec1 operator=(tvec1 const v);
	tvec1 operator=(tsvec1 const& v);
private:
	type& x;
	tsvec1(type& xr);
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct tsvec2
{
	tvec2 operator=(tvec2 const v);
	tvec2 operator=(tsvec2 const& v);
private:
	type& x, & y;
	tsvec2(type& xr, type& yr);
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct tsvec3
{
	tvec3 operator=(tvec3 const v);
	tvec3 operator=(tsvec3 const& v);
private:
	type& x, & y, & z;
	tsvec3(type& xr, type& yr, type& zr);
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template <typename type, typename tvec1, typename tvec2, typename tvec3, typename tvec4>
struct tsvec4
{
	tvec4 operator=(tvec4 const v);
	tvec4 operator=(tsvec4 const& v);
private:
	type& x, & y, & z, & w;
	tsvec4(type& xr, type& yr, type& zr, type& wr);
	friend tvec1;
	friend tvec2;
	friend tvec3;
	friend tvec4;
};

template<typename type, typename tvec2, typename tvec3, typename tvec4>
union tvec1
{
	inline tvec1(type const xc = 0) : x(xc) {}
	inline tvec1& operator =(type const xc) { x = xc; return *this; }
	inline operator type& () { return x; }
	inline operator type const() const { return x; }

	IJK_SWIZZLE_READONLY(IJK_SWIZZLE_DECL_IMPL, 1, tvec, tvec);
	IJK_SWIZZLE_WRITABLE(IJK_SWIZZLE_DECL_IMPL_TEMP, 1, tvec, tsvec);
private:
	type x;
};

typedef tvec1<ui32, uvec2, uvec3, uvec4>			uvec1;
typedef tvec1<i32, ivec2, ivec3, ivec4>				ivec1;
typedef tvec1<flt, vec2, vec3, vec4>				vec1;
typedef tvec1<dbl, dvec2, dvec3, dvec4>				dvec1;
typedef tsvec1<ui32, uvec1, uvec2, uvec3, uvec4>	usvec1;
typedef tsvec1<i32, ivec1, ivec2, ivec3, ivec4>		isvec1;
typedef tsvec1<flt, vec1, vec2, vec3, vec4>			svec1;
typedef tsvec1<dbl, dvec1, dvec2, dvec3, dvec4>		dsvec1;
typedef tsvec2<ui32, uvec1, uvec2, uvec3, uvec4>	usvec2;
typedef tsvec2<i32, ivec1, ivec2, ivec3, ivec4>		isvec2;
typedef tsvec2<flt, vec1, vec2, vec3, vec4>			svec2;
typedef tsvec2<dbl, dvec1, dvec2, dvec3, dvec4>		dsvec2;
typedef tsvec3<ui32, uvec1, uvec2, uvec3, uvec4>	usvec3;
typedef tsvec3<i32, ivec1, ivec2, ivec3, ivec4>		isvec3;
typedef tsvec3<flt, vec1, vec2, vec3, vec4>			svec3;
typedef tsvec3<dbl, dvec1, dvec2, dvec3, dvec4>		dsvec3;
typedef tsvec4<ui32, uvec1, uvec2, uvec3, uvec4>	usvec4;
typedef tsvec4<i32, ivec1, ivec2, ivec3, ivec4>		isvec4;
typedef tsvec4<flt, vec1, vec2, vec3, vec4>			svec4;
typedef tsvec4<dbl, dvec1, dvec2, dvec3, dvec4>		dsvec4;
#define uint										uvec1
#define int											ivec1
#define float										vec1
#define double										dvec1


#pragma endregion
// IJK_SWIZZLE_MACRO_DECL


//-----------------------------------------------------------------------------

extern "C" {
#else	// !__cplusplus
typedef union uvec2	uvec2;
typedef union uvec3	uvec3;
typedef union uvec4	uvec4;
typedef union ivec2	ivec2;
typedef union ivec3	ivec3;
typedef union ivec4	ivec4;
typedef union vec2	vec2;
typedef union vec3	vec3;
typedef union vec4	vec4;
typedef union dvec2	dvec2;
typedef union dvec3	dvec3;
typedef union dvec4	dvec4;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// Reusable array-based vector types.
///
typedef ui32
	uint2[2],					// 2D signed integer array-based vector, always passed by pointer.
	uint3[3],					// 3D signed integer array-based vector, always passed by pointer.
	uint4[4],					// 4D signed integer array-based vector, always passed by pointer.
	* uintv;					// Generic signed integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef i32
	int2[2],					// 2D unsigned integer array-based vector, always passed by pointer.
	int3[3],					// 3D unsigned integer array-based vector, always passed by pointer.
	int4[4],					// 4D unsigned integer array-based vector, always passed by pointer.
	* intv;						// Generic unsigned integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef flt
	flt2[2],					// 2D single-precision array-based vector, always passed by pointer.
	flt3[3],					// 3D single-precision array-based vector, always passed by pointer.
	flt4[4],					// 4D single-precision array-based vector, always passed by pointer.
	* fltv;						// Generic float single-precision-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef dbl
	dbl2[2],					// 2D double-precision array-based vector, always passed by pointer.
	dbl3[3],					// 3D double-precision array-based vector, always passed by pointer.
	dbl4[4],					// 4D double-precision array-based vector, always passed by pointer.
	* dblv;						// Generic double-precision array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
typedef real
	real2[2],					// 2D real-type array-based vector, always passed by pointer.
	real3[3],					// 3D real-type array-based vector, always passed by pointer.
	real4[4],					// 4D real-type array-based vector, always passed by pointer.
	* realv;					// Generic real-type array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.

typedef ui32 const* uintkv;		// Generic constant unsigned integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef i32 const* intkv;		// Generic constant signed integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef flt const* fltkv;		// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef dbl const* dblkv;		// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real const* realkv;		// Generic constant real-type array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.


//-----------------------------------------------------------------------------

// ivec2
//	Data structure representing 2D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
	int2 v;
	struct { i32 x, y; };
	struct { i32 r, g; };
	struct { i32 s, t; };

#ifdef __cplusplus
	explicit ivec2(i32 const xy = 0);			// Construct vector with all elements set to single scalar.
	explicit ivec2(i32 const xc, i32 const yc);	// Construct vector with elements set individually.
	ivec2(isvec2 const& xy);
	explicit ivec2(int2 const xy);				// Construct vector given integer array-based vector.
	explicit ivec2(flt2 const xy);				// Construct vector given float array-based vector.
	explicit ivec2(dbl2 const xy);				// Construct vector given double array-based vector.
	ivec2(ivec2 const& xy);						// Construct vector given another 2D integer vector.
	explicit ivec2(ivec3 const& xy);			// Construct vector given the first two elements of a 3D integer vector.
	explicit ivec2(ivec4 const& xy);			// Construct vector given the first two elements of a 4D integer vector.
	explicit ivec2(vec2 const& xy);				// Construct vector given a 2D float vector.
	explicit ivec2(vec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	explicit ivec2(vec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
	explicit ivec2(dvec2 const& xy);			// Construct vector given a 2D double vector.
	explicit ivec2(dvec3 const& xy);			// Construct vector given the first two elements of a 3D double vector.
	explicit ivec2(dvec4 const& xy);			// Construct vector given the first two elements of a 4D double vector.

	ivec2& operator+();
	ivec2& operator =(int2 const xy);
	ivec2& operator =(ivec2 const& xy);
	ivec2& operator =(isvec2 const& xy);
	ivec2& operator +=(ivec2 const& v_rh);
	ivec2& operator -=(ivec2 const& v_rh);
	ivec2& operator *=(ivec2 const& v_rh);
	ivec2& operator /=(ivec2 const& v_rh);
	ivec2& operator +=(i32 const s_rh);
	ivec2& operator -=(i32 const s_rh);
	ivec2& operator *=(i32 const s_rh);
	ivec2& operator /=(i32 const s_rh);
	i32& operator[](index const i);
	operator intv();

	ivec2 const operator+() const;
	ivec2 const operator-() const;
	ivec2 const operator +(ivec2 const& v_rh) const;
	ivec2 const operator -(ivec2 const& v_rh) const;
	ivec2 const operator *(ivec2 const& v_rh) const;
	ivec2 const operator /(ivec2 const& v_rh) const;
	ivec2 const operator +(i32 const s_rh) const;
	ivec2 const operator -(i32 const s_rh) const;
	ivec2 const operator *(i32 const s_rh) const;
	ivec2 const operator /(i32 const s_rh) const;
	i32 operator[](index const i) const;
	operator intkv() const;
	bool operator ==(ivec2 const& v_rh) const;
	bool operator !=(ivec2 const& v_rh) const;

	//IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
	//isvec2 _xy();
	//isvec2 _yx();

	IJK_SWIZZLE_READONLY(IJK_SWIZZLE_DECL, 2, ivec, ivec);
	IJK_SWIZZLE_WRITABLE(IJK_SWIZZLE_DECL, 2, ivec, isvec);
#endif	// __cplusplus
};

// ivec3
//	Data structure representing 3D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ivec3
{
	int3 v;
	ivec2 xy;
	struct { i32 x, y, z; };
	struct { i32 r, g, b; };
	struct { i32 s, t, p; };

#ifdef __cplusplus
	explicit ivec3(i32 const xyz = 0);								// Construct vector with all elements set to single scalar.
	explicit ivec3(i32 const xc, i32 const yc, i32 const zc = 0);	// Construct vector with elements set individually.
	explicit ivec3(int3 const xyz);									// Construct vector given integer array-based vector.
	explicit ivec3(flt3 const xyz);									// Construct vector given float array-based vector.
	explicit ivec3(dbl3 const xyz);									// Construct vector given double array-based vector.
	explicit ivec3(ivec2 const& xy, i32 const z = 0);				// Construct vector given a 2D integer vector and the third element.
	ivec3(ivec3 const& xyz);										// Construct vector given another 3D integer vector.
	explicit ivec3(ivec4 const& xyz);								// Construct vector given the first three elements of a 4D integer vector.
	explicit ivec3(vec2 const& xy, i32 const z = 0);				// Construct vector given a 2D float vector and the third element.
	explicit ivec3(vec3 const& xyz);								// Construct vector given a 3D float vector.
	explicit ivec3(vec4 const& xyz);								// Construct vector given the first three elements of a 4D float vector.
	explicit ivec3(dvec2 const& xy, i32 const z = 0);				// Construct vector given a 2D double vector and the third element.
	explicit ivec3(dvec3 const& xyz);								// Construct vector given a 3D double vector.
	explicit ivec3(dvec4 const& xyz);								// Construct vector given the first three elements of a 4D double vector.

	ivec3& operator =(i32 const xyz);
	ivec3& operator =(int3 const xyz);
	ivec3& operator =(flt3 const xyz);
	ivec3& operator =(dbl3 const xyz);
	ivec3& operator =(ivec2 const& xy);
	ivec3& operator =(ivec3 const& xyz);
	ivec3& operator =(ivec4 const& xyz);
	ivec3& operator =(vec2 const& xy);
	ivec3& operator =(vec3 const& xyz);
	ivec3& operator =(vec4 const& xyz);
	ivec3& operator =(dvec2 const& xy);
	ivec3& operator =(dvec3 const& xyz);
	ivec3& operator =(dvec4 const& xyz);

	ivec3& operator+();
	ivec3& operator +=(i32 const s);
	ivec3& operator +=(ivec3 const& v);
	ivec3& operator -=(i32 const s);
	ivec3& operator -=(ivec3 const& v);
	ivec3& operator *=(i32 const s);
	ivec3& operator *=(ivec3 const& v);
	ivec3& operator /=(i32 const s);
	ivec3& operator /=(ivec3 const& v);
	i32& operator[](index const i);
	operator intv();

	ivec3 const operator+() const;
	ivec3 const operator-() const;
	ivec3 const operator +(i32 const s) const;
	ivec3 const operator +(ivec3 const& v) const;
	ivec3 const operator -(i32 const s) const;
	ivec3 const operator -(ivec3 const& v) const;
	ivec3 const operator *(i32 const s) const;
	ivec3 const operator *(ivec3 const& v) const;
	ivec3 const operator /(i32 const s) const;
	ivec3 const operator /(ivec3 const& v) const;
	i32 operator[](index const i) const;
	operator intkv() const;

	bool operator ==(ivec3 const& v) const;
	bool operator !=(ivec3 const& v) const;

	//IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
#endif	// __cplusplus
};

// ivec4
//	Data structure representing 4D integer vector.
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
	ivec3 xyz;
	ivec2 xy;
	struct { i32 x, y, z, w; };
	struct { i32 r, g, b, a; };
	struct { i32 s, t, p, q; };

#ifdef __cplusplus
	explicit ivec4(i32 const xyzw = 0);												// Construct vector with all elements set to single scalar.
	explicit ivec4(i32 const xc, i32 const yc, i32 const zc = 0, i32 const wc = 0);	// Construct vector with elements set individually.
	explicit ivec4(int4 const xyzw);												// Construct vector given integer array-based vector.
	explicit ivec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	explicit ivec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	explicit ivec4(ivec2 const& xy, i32 const z = 0, i32 const w = 0);				// Construct vector given a 2D integer vector and the third and fourth elements.
	explicit ivec4(ivec3 const& xyz, i32 const w = 0);								// Construct vector given a 3D integer vector and the fourth element.
	ivec4(ivec4 const& xyzw);														// Construct vector given another 4D integer vector.
	explicit ivec4(vec2 const& xy, i32 const z = 0, i32 const w = 0);				// Construct vector given a 2D float vector and the third and fourth elements.
	explicit ivec4(vec3 const& xyz, i32 const w = 0);								// Construct vector given a 3D float vector and the fourth element.
	explicit ivec4(vec4 const& xyzw);												// Construct vector given a 4D float vector.
	explicit ivec4(dvec2 const& xy, i32 const z = 0, i32 const w = 0);				// Construct vector given a 2D double vector and the third and fourth elements.
	explicit ivec4(dvec3 const& xyz, i32 const w = 0);								// Construct vector given a 3D double vector and the fourth element.
	explicit ivec4(dvec4 const& xyzw);												// Construct vector given a 4D double vector.

	ivec4& operator =(i32 const xyzw);
	ivec4& operator =(int4 const xyzw);
	ivec4& operator =(flt4 const xyzw);
	ivec4& operator =(dbl4 const xyzw);
	ivec4& operator =(ivec2 const& xy);
	ivec4& operator =(ivec3 const& xyz);
	ivec4& operator =(ivec4 const& xyzw);
	ivec4& operator =(vec2 const& xy);
	ivec4& operator =(vec3 const& xyz);
	ivec4& operator =(vec4 const& xyzw);
	ivec4& operator =(dvec2 const& xy);
	ivec4& operator =(dvec3 const& xyz);
	ivec4& operator =(dvec4 const& xyzw);

	ivec4& operator+();
	ivec4& operator +=(i32 const s);
	ivec4& operator +=(ivec4 const& v);
	ivec4& operator -=(i32 const s);
	ivec4& operator -=(ivec4 const& v);
	ivec4& operator *=(i32 const s);
	ivec4& operator *=(ivec4 const& v);
	ivec4& operator /=(i32 const s);
	ivec4& operator /=(ivec4 const& v);
	i32& operator[](index const i);
	operator intv();

	ivec4 const operator+() const;
	ivec4 const operator-() const;
	ivec4 const operator +(i32 const s) const;
	ivec4 const operator +(ivec4 const& v) const;
	ivec4 const operator -(i32 const s) const;
	ivec4 const operator -(ivec4 const& v) const;
	ivec4 const operator *(i32 const s) const;
	ivec4 const operator *(ivec4 const& v) const;
	ivec4 const operator /(i32 const s) const;
	ivec4 const operator /(ivec4 const& v) const;
	i32 operator[](index const i) const;
	operator intkv() const;

	bool operator ==(ivec3 const& v) const;
	bool operator !=(ivec3 const& v) const;

	//IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
#endif	// __cplusplus
};


// Global constants for integer array-based vectors and data structures.
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

// vec2
//	Data structure representing 2D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union vec2
{
	flt2 v;
	struct { flt x, y; };
	struct { flt r, g; };
	struct { flt s, t; };

#ifdef __cplusplus
	vec2(flt const xy = 0);			// Construct vector with all elements set to single scalar.
	vec2(flt const x, flt const y);	// Construct vector with elements set individually.
	vec2(int2 const xy);				// Construct vector given integer array-based vector.
	vec2(flt2 const xy);				// Construct vector given float array-based vector.
	vec2(dbl2 const xy);				// Construct vector given double array-based vector.
	vec2(ivec2 const& xy);				// Construct vector given a 2D integer vector.
	vec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D integer vector.
	vec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D integer vector.
	vec2(vec2 const& xy);				// Construct vector given another 2D float vector.
	vec2(vec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	vec2(vec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
	vec2(dvec2 const& xy);				// Construct vector given a 2D double vector.
	vec2(dvec3 const& xy);				// Construct vector given the first two elements of a 3D double vector.
	vec2(dvec4 const& xy);				// Construct vector given the first two elements of a 4D double vector.

	vec2& operator =(flt const xy);
	vec2& operator =(int2 const xy);
	vec2& operator =(flt2 const xy);
	vec2& operator =(dbl2 const xy);
	vec2& operator =(ivec2 const& xy);
	vec2& operator =(ivec3 const& xy);
	vec2& operator =(ivec4 const& xy);
	vec2& operator =(vec2 const& xy);
	vec2& operator =(vec3 const& xy);
	vec2& operator =(vec4 const& xy);
	vec2& operator =(dvec2 const& xy);
	vec2& operator =(dvec3 const& xy);
	vec2& operator =(dvec4 const& xy);

	vec2& operator+();
	vec2& operator +=(flt const s);
	vec2& operator +=(vec2 const& v);
	vec2& operator -=(flt const s);
	vec2& operator -=(vec2 const& v);
	vec2& operator *=(flt const s);
	vec2& operator *=(vec2 const& v);
	vec2& operator /=(flt const s);
	vec2& operator /=(vec2 const& v);
	flt& operator[](index const i);
	operator fltv();

	vec2 const operator+() const;
	vec2 const operator-() const;
	vec2 const operator +(flt const s) const;
	vec2 const operator +(vec2 const& v) const;
	vec2 const operator -(flt const s) const;
	vec2 const operator -(vec2 const& v) const;
	vec2 const operator *(flt const s) const;
	vec2 const operator *(vec2 const& v) const;
	vec2 const operator /(flt const s) const;
	vec2 const operator /(vec2 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(vec2 const& v) const;
	bool operator !=(vec2 const& v) const;

	//IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
#endif	// __cplusplus
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
	flt3 v;
	vec2 xy;
	struct { flt x, y, z; };
	struct { flt r, g, b; };
	struct { flt s, t, p; };

#ifdef __cplusplus
	vec3(flt const xyz = 0);							// Construct vector with all elements set to single scalar.
	vec3(flt const x, flt const y, flt const z = 0);	// Construct vector with elements set individually.
	vec3(int3 const xyz);								// Construct vector given integer array-based vector.
	vec3(flt3 const xyz);								// Construct vector given float array-based vector.
	vec3(dbl3 const xyz);								// Construct vector given double array-based vector.
	vec3(ivec2 const& xy, flt const z = 0);			// Construct vector given a 2D integer vector and the third element.
	vec3(ivec3 const& xyz);							// Construct vector given a 3D integer vector.
	vec3(ivec4 const& xyz);							// Construct vector given the first three elements of a 4D integer vector.
	vec3(vec2 const& xy, flt const z = 0);			// Construct vector given a 2D float vector and the third element.
	vec3(vec3 const& xyz);							// Construct vector given another 3D float vector.
	vec3(vec4 const& xyz);							// Construct vector given the first three elements of a 4D float vector.
	vec3(dvec2 const& xy, flt const z = 0);			// Construct vector given a 2D double vector and the third element.
	vec3(dvec3 const& xyz);							// Construct vector given a 3D double vector.
	vec3(dvec4 const& xyz);							// Construct vector given the first three elements of a 4D double vector.

	vec3& operator =(flt const xyz);
	vec3& operator =(int3 const xyz);
	vec3& operator =(flt3 const xyz);
	vec3& operator =(dbl3 const xyz);
	vec3& operator =(ivec2 const& xy);
	vec3& operator =(ivec3 const& xyz);
	vec3& operator =(ivec4 const& xyz);
	vec3& operator =(vec2 const& xy);
	vec3& operator =(vec3 const& xyz);
	vec3& operator =(vec4 const& xyz);
	vec3& operator =(dvec2 const& xy);
	vec3& operator =(dvec3 const& xyz);
	vec3& operator =(dvec4 const& xyz);

	vec3& operator+();
	vec3& operator +=(flt const s);
	vec3& operator +=(vec3 const& v);
	vec3& operator -=(flt const s);
	vec3& operator -=(vec3 const& v);
	vec3& operator *=(flt const s);
	vec3& operator *=(vec3 const& v);
	vec3& operator /=(flt const s);
	vec3& operator /=(vec3 const& v);
	flt& operator[](index const i);
	operator fltv();

	vec3 const operator+() const;
	vec3 const operator-() const;
	vec3 const operator +(flt const s) const;
	vec3 const operator +(vec3 const& v) const;
	vec3 const operator -(flt const s) const;
	vec3 const operator -(vec3 const& v) const;
	vec3 const operator *(flt const s) const;
	vec3 const operator *(vec3 const& v) const;
	vec3 const operator /(flt const s) const;
	vec3 const operator /(vec3 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(vec3 const& v) const;
	bool operator !=(vec3 const& v) const;

	//IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
#endif	// __cplusplus
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
	flt4 v;
	vec3 xyz;
	vec2 xy;
	struct { flt x, y, z, w; };
	struct { flt r, g, b, a; };
	struct { flt s, t, p, q; };

#ifdef __cplusplus
	vec4(flt const xyzw = 0);											// Construct vector with all elements set to single scalar.
	vec4(flt const x, flt const y, flt const z = 0, flt const w = 0);	// Construct vector with elements set individually.
	vec4(int4 const xyzw);												// Construct vector given integer array-based vector.
	vec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	vec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	vec4(ivec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D integer vector and the third and fourth elements.
	vec4(ivec3 const& xyz, flt const w = 0);							// Construct vector given a 3D integer vector and the fourth element.
	vec4(ivec4 const& xyzw);											// Construct vector given a 4D integer vector.
	vec4(vec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D float vector and the third and fourth elements.
	vec4(vec3 const& xyz, flt const w = 0);							// Construct vector given a 3D float vector and the fourth element.
	vec4(vec4 const& xyzw);											// Construct vector given another 4D float vector.
	vec4(dvec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D double vector and the third and fourth elements.
	vec4(dvec3 const& xyz, flt const w = 0);							// Construct vector given a 3D double vector and the fourth element.
	vec4(dvec4 const& xyzw);											// Construct vector given a 4D double vector.

	vec4& operator =(flt const xyzw);
	vec4& operator =(int4 const xyzw);
	vec4& operator =(flt4 const xyzw);
	vec4& operator =(dbl4 const xyzw);
	vec4& operator =(ivec2 const& xy);
	vec4& operator =(ivec3 const& xyz);
	vec4& operator =(ivec4 const& xyzw);
	vec4& operator =(vec2 const& xy);
	vec4& operator =(vec3 const& xyz);
	vec4& operator =(vec4 const& xyzw);
	vec4& operator =(dvec2 const& xy);
	vec4& operator =(dvec3 const& xyz);
	vec4& operator =(dvec4 const& xyzw);

	vec4& operator+();
	vec4& operator +=(flt const s);
	vec4& operator +=(vec4 const& v);
	vec4& operator -=(flt const s);
	vec4& operator -=(vec4 const& v);
	vec4& operator *=(flt const s);
	vec4& operator *=(vec4 const& v);
	vec4& operator /=(flt const s);
	vec4& operator /=(vec4 const& v);
	flt& operator[](index const i);
	operator fltv();

	vec4 const operator+() const;
	vec4 const operator-() const;
	vec4 const operator +(flt const s) const;
	vec4 const operator +(vec4 const& v) const;
	vec4 const operator -(flt const s) const;
	vec4 const operator -(vec4 const& v) const;
	vec4 const operator *(flt const s) const;
	vec4 const operator *(vec4 const& v) const;
	vec4 const operator /(flt const s) const;
	vec4 const operator /(vec4 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(vec3 const& v) const;
	bool operator !=(vec3 const& v) const;

	//IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
#endif	// __cplusplus
};


// Global constants for float array-based vectors and data structures.
///
ijk_ext flt2 const flt2_one;		// ( +1, +1 )
ijk_ext flt2 const flt2_zero;		// (  0,  0 )
ijk_ext flt2 const flt2_one_n;		// ( -1, -1 )
ijk_ext flt2 const flt2_x;			// ( +1,  0 )
ijk_ext flt2 const flt2_y;			// (  0, +1 )
ijk_ext flt2 const flt2_x_n;		// ( -1,  0 )
ijk_ext flt2 const flt2_y_n;		// (  0, -1 )

ijk_ext flt3 const flt3_one;		// ( +1, +1, +1 )
ijk_ext flt3 const flt3_zero;		// (  0,  0,  0 )
ijk_ext flt3 const flt3_one_n;		// ( -1, -1, -1 )
ijk_ext flt3 const flt3_x;			// ( +1,  0,  0 )
ijk_ext flt3 const flt3_y;			// (  0, +1,  0 )
ijk_ext flt3 const flt3_z;			// (  0,  0, +1 )
ijk_ext flt3 const flt3_x_n;		// ( -1,  0,  0 )
ijk_ext flt3 const flt3_y_n;		// (  0, -1,  0 )
ijk_ext flt3 const flt3_z_n;		// (  0,  0, -1 )

ijk_ext flt4 const flt4_one;		// ( +1, +1, +1, +1 )
ijk_ext flt4 const flt4_zero;		// (  0,  0,  0,  0 )
ijk_ext flt4 const flt4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext flt4 const flt4_x;			// ( +1,  0,  0,  0 )
ijk_ext flt4 const flt4_y;			// (  0, +1,  0,  0 )
ijk_ext flt4 const flt4_z;			// (  0,  0, +1,  0 )
ijk_ext flt4 const flt4_w;			// (  0,  0,  0, +1 )
ijk_ext flt4 const flt4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext flt4 const flt4_y_n;		// (  0, -1,  0,  0 )
ijk_ext flt4 const flt4_z_n;		// (  0,  0, -1,  0 )
ijk_ext flt4 const flt4_w_n;		// (  0,  0,  0, -1 )

ijk_ext vec2 const vec2_one;		// ( +1, +1 )
ijk_ext vec2 const vec2_zero;		// (  0,  0 )
ijk_ext vec2 const vec2_one_n;	// ( -1, -1 )
ijk_ext vec2 const vec2_x;		// ( +1,  0 )
ijk_ext vec2 const vec2_y;		// (  0, +1 )
ijk_ext vec2 const vec2_x_n;		// ( -1,  0 )
ijk_ext vec2 const vec2_y_n;		// (  0, -1 )

ijk_ext vec3 const vec3_one;		// ( +1, +1, +1 )
ijk_ext vec3 const vec3_zero;		// (  0,  0,  0 )
ijk_ext vec3 const vec3_one_n;	// ( -1, -1, -1 )
ijk_ext vec3 const vec3_x;		// ( +1,  0,  0 )
ijk_ext vec3 const vec3_y;		// (  0, +1,  0 )
ijk_ext vec3 const vec3_z;		// (  0,  0, +1 )
ijk_ext vec3 const vec3_x_n;		// ( -1,  0,  0 )
ijk_ext vec3 const vec3_y_n;		// (  0, -1,  0 )
ijk_ext vec3 const vec3_z_n;		// (  0,  0, -1 )

ijk_ext vec4 const vec4_one;		// ( +1, +1, +1, +1 )
ijk_ext vec4 const vec4_zero;		// (  0,  0,  0,  0 )
ijk_ext vec4 const vec4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext vec4 const vec4_x;		// ( +1,  0,  0,  0 )
ijk_ext vec4 const vec4_y;		// (  0, +1,  0,  0 )
ijk_ext vec4 const vec4_z;		// (  0,  0, +1,  0 )
ijk_ext vec4 const vec4_w;		// (  0,  0,  0, +1 )
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
	dbl2 v;
	struct { dbl x, y; };
	struct { dbl r, g; };
	struct { dbl s, t; };

#ifdef __cplusplus
	dvec2(dbl const xy = 0);			// Construct vector with all elements set to single scalar.
	dvec2(dbl const x, dbl const y);	// Construct vector with elements set individually.
	dvec2(int2 const xy);				// Construct vector given integer array-based vector.
	dvec2(flt2 const xy);				// Construct vector given float array-based vector.
	dvec2(dbl2 const xy);				// Construct vector given double array-based vector.
	dvec2(ivec2 const& xy);				// Construct vector given a 2D integer vector.
	dvec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D integer vector.
	dvec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D integer vector.
	dvec2(vec2 const& xy);				// Construct vector given a 2D float vector.
	dvec2(vec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	dvec2(vec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
	dvec2(dvec2 const& xy);				// Construct vector given another 2D double vector.
	dvec2(dvec3 const& xy);				// Construct vector given the first two elements of a 3D double vector.
	dvec2(dvec4 const& xy);				// Construct vector given the first two elements of a 4D double vector.

	dvec2& operator =(dbl const xy);
	dvec2& operator =(int2 const xy);
	dvec2& operator =(flt2 const xy);
	dvec2& operator =(dbl2 const xy);
	dvec2& operator =(ivec2 const& xy);
	dvec2& operator =(ivec3 const& xy);
	dvec2& operator =(ivec4 const& xy);
	dvec2& operator =(vec2 const& xy);
	dvec2& operator =(vec3 const& xy);
	dvec2& operator =(vec4 const& xy);
	dvec2& operator =(dvec2 const& xy);
	dvec2& operator =(dvec3 const& xy);
	dvec2& operator =(dvec4 const& xy);

	dvec2& operator+();
	dvec2& operator +=(dbl const s);
	dvec2& operator +=(dvec2 const& v);
	dvec2& operator -=(dbl const s);
	dvec2& operator -=(dvec2 const& v);
	dvec2& operator *=(dbl const s);
	dvec2& operator *=(dvec2 const& v);
	dvec2& operator /=(dbl const s);
	dvec2& operator /=(dvec2 const& v);
	dbl& operator[](index const i);
	operator dblv();

	dvec2 const operator+() const;
	dvec2 const operator-() const;
	dvec2 const operator +(dbl const s) const;
	dvec2 const operator +(dvec2 const& v) const;
	dvec2 const operator -(dbl const s) const;
	dvec2 const operator -(dvec2 const& v) const;
	dvec2 const operator *(dbl const s) const;
	dvec2 const operator *(dvec2 const& v) const;
	dvec2 const operator /(dbl const s) const;
	dvec2 const operator /(dvec2 const& v) const;
	dbl operator[](index const i) const;
	operator dblkv() const;

	bool operator ==(dvec2 const& v) const;
	bool operator !=(dvec2 const& v) const;

	//IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
#endif	// __cplusplus
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
	dbl3 v;
	dvec2 xy;
	struct { dbl x, y, z; };
	struct { dbl r, g, b; };
	struct { dbl s, t, p; };

#ifdef __cplusplus
	dvec3(dbl const xyz = 0);							// Construct vector with all elements set to single scalar.
	dvec3(dbl const x, dbl const y, dbl const z = 0);	// Construct vector with elements set individually.
	dvec3(int3 const xyz);								// Construct vector given integer array-based vector.
	dvec3(flt3 const xyz);								// Construct vector given float array-based vector.
	dvec3(dbl3 const xyz);								// Construct vector given double array-based vector.
	dvec3(ivec2 const& xy, dbl const z = 0);			// Construct vector given a 2D integer vector and the third element.
	dvec3(ivec3 const& xyz);							// Construct vector given a 3D integer vector.
	dvec3(ivec4 const& xyz);							// Construct vector given the first three elements of a 4D integer vector.
	dvec3(vec2 const& xy, dbl const z = 0);			// Construct vector given a 2D float vector and the third element.
	dvec3(vec3 const& xyz);							// Construct vector given a 3D float vector.
	dvec3(vec4 const& xyz);							// Construct vector given the first three elements of a 4D float vector.
	dvec3(dvec2 const& xy, dbl const z = 0);			// Construct vector given a 2D double vector and the third element.
	dvec3(dvec3 const& xyz);							// Construct vector given another 3D double vector.
	dvec3(dvec4 const& xyz);							// Construct vector given the first three elements of a 4D double vector.

	dvec3& operator =(dbl const xyz);
	dvec3& operator =(int3 const xyz);
	dvec3& operator =(flt3 const xyz);
	dvec3& operator =(dbl3 const xyz);
	dvec3& operator =(ivec2 const& xy);
	dvec3& operator =(ivec3 const& xyz);
	dvec3& operator =(ivec4 const& xyz);
	dvec3& operator =(vec2 const& xy);
	dvec3& operator =(vec3 const& xyz);
	dvec3& operator =(vec4 const& xyz);
	dvec3& operator =(dvec2 const& xy);
	dvec3& operator =(dvec3 const& xyz);
	dvec3& operator =(dvec4 const& xyz);

	dvec3& operator+();
	dvec3& operator +=(dbl const s);
	dvec3& operator +=(dvec3 const& v);
	dvec3& operator -=(dbl const s);
	dvec3& operator -=(dvec3 const& v);
	dvec3& operator *=(dbl const s);
	dvec3& operator *=(dvec3 const& v);
	dvec3& operator /=(dbl const s);
	dvec3& operator /=(dvec3 const& v);
	dbl& operator[](index const i);
	operator dblv();

	dvec3 const operator+() const;
	dvec3 const operator-() const;
	dvec3 const operator +(dbl const s) const;
	dvec3 const operator +(dvec3 const& v) const;
	dvec3 const operator -(dbl const s) const;
	dvec3 const operator -(dvec3 const& v) const;
	dvec3 const operator *(dbl const s) const;
	dvec3 const operator *(dvec3 const& v) const;
	dvec3 const operator /(dbl const s) const;
	dvec3 const operator /(dvec3 const& v) const;
	dbl operator[](index const i) const;
	operator dblkv() const;

	bool operator ==(dvec3 const& v) const;
	bool operator !=(dvec3 const& v) const;

	//IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
#endif	// __cplusplus
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
	dbl4 v;
	dvec3 xyz;
	dvec2 xy;
	struct { dbl x, y, z, w; };
	struct { dbl r, g, b, a; };
	struct { dbl s, t, p, q; };

#ifdef __cplusplus
	dvec4(dbl const xyzw = 0);											// Construct vector with all elements set to single scalar.
	dvec4(dbl const x, dbl const y, dbl const z = 0, dbl const w = 0);	// Construct vector with elements set individually.
	dvec4(int4 const xyzw);												// Construct vector given integer array-based vector.
	dvec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	dvec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	dvec4(ivec2 const& xy, dbl const z = 0, dbl const w = 0);			// Construct vector given a 2D integer vector and the third and fourth elements.
	dvec4(ivec3 const& xyz, dbl const w = 0);							// Construct vector given a 3D integer vector and the fourth element.
	dvec4(ivec4 const& xyzw);											// Construct vector given a 4D integer vector.
	dvec4(vec2 const& xy, dbl const z = 0, dbl const w = 0);			// Construct vector given a 2D float vector and the third and fourth elements.
	dvec4(vec3 const& xyz, dbl const w = 0);							// Construct vector given a 3D float vector and the fourth element.
	dvec4(vec4 const& xyzw);											// Construct vector given a 4D float vector.
	dvec4(dvec2 const& xy, dbl const z = 0, dbl const w = 0);			// Construct vector given a 2D double vector and the third and fourth elements.
	dvec4(dvec3 const& xyz, dbl const w = 0);							// Construct vector given a 3D double vector and the fourth element.
	dvec4(dvec4 const& xyzw);											// Construct vector given another 4D double vector.

	dvec4& operator =(dbl const xyzw);
	dvec4& operator =(int4 const xyzw);
	dvec4& operator =(flt4 const xyzw);
	dvec4& operator =(dbl4 const xyzw);
	dvec4& operator =(ivec2 const& xy);
	dvec4& operator =(ivec3 const& xyz);
	dvec4& operator =(ivec4 const& xyzw);
	dvec4& operator =(vec2 const& xy);
	dvec4& operator =(vec3 const& xyz);
	dvec4& operator =(vec4 const& xyzw);
	dvec4& operator =(dvec2 const& xy);
	dvec4& operator =(dvec3 const& xyz);
	dvec4& operator =(dvec4 const& xyzw);

	dvec4& operator+();
	dvec4& operator +=(dbl const s);
	dvec4& operator +=(dvec4 const& v);
	dvec4& operator -=(dbl const s);
	dvec4& operator -=(dvec4 const& v);
	dvec4& operator *=(dbl const s);
	dvec4& operator *=(dvec4 const& v);
	dvec4& operator /=(dbl const s);
	dvec4& operator /=(dvec4 const& v);
	dbl& operator[](index const i);
	operator dblv();

	dvec4 const operator+() const;
	dvec4 const operator-() const;
	dvec4 const operator +(dbl const s) const;
	dvec4 const operator +(dvec4 const& v) const;
	dvec4 const operator -(dbl const s) const;
	dvec4 const operator -(dvec4 const& v) const;
	dvec4 const operator *(dbl const s) const;
	dvec4 const operator *(dvec4 const& v) const;
	dvec4 const operator /(dbl const s) const;
	dvec4 const operator /(dvec4 const& v) const;
	dbl operator[](index const i) const;
	operator dblkv() const;

	bool operator ==(dvec3 const& v) const;
	bool operator !=(dvec3 const& v) const;

	//IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
#endif	// __cplusplus
};


// Global constants for double array-based vectors and data structures.
///
ijk_ext dbl2 const dbl2_one;		// ( +1, +1 )
ijk_ext dbl2 const dbl2_zero;		// (  0,  0 )
ijk_ext dbl2 const dbl2_one_n;		// ( -1, -1 )
ijk_ext dbl2 const dbl2_x;			// ( +1,  0 )
ijk_ext dbl2 const dbl2_y;			// (  0, +1 )
ijk_ext dbl2 const dbl2_x_n;		// ( -1,  0 )
ijk_ext dbl2 const dbl2_y_n;		// (  0, -1 )

ijk_ext dbl3 const dbl3_one;		// ( +1, +1, +1 )
ijk_ext dbl3 const dbl3_zero;		// (  0,  0,  0 )
ijk_ext dbl3 const dbl3_one_n;		// ( -1, -1, -1 )
ijk_ext dbl3 const dbl3_x;			// ( +1,  0,  0 )
ijk_ext dbl3 const dbl3_y;			// (  0, +1,  0 )
ijk_ext dbl3 const dbl3_z;			// (  0,  0, +1 )
ijk_ext dbl3 const dbl3_x_n;		// ( -1,  0,  0 )
ijk_ext dbl3 const dbl3_y_n;		// (  0, -1,  0 )
ijk_ext dbl3 const dbl3_z_n;		// (  0,  0, -1 )

ijk_ext dbl4 const dbl4_one;		// ( +1, +1, +1, +1 )
ijk_ext dbl4 const dbl4_zero;		// (  0,  0,  0,  0 )
ijk_ext dbl4 const dbl4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext dbl4 const dbl4_x;			// ( +1,  0,  0,  0 )
ijk_ext dbl4 const dbl4_y;			// (  0, +1,  0,  0 )
ijk_ext dbl4 const dbl4_z;			// (  0,  0, +1,  0 )
ijk_ext dbl4 const dbl4_w;			// (  0,  0,  0, +1 )
ijk_ext dbl4 const dbl4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext dbl4 const dbl4_y_n;		// (  0, -1,  0,  0 )
ijk_ext dbl4 const dbl4_z_n;		// (  0,  0, -1,  0 )
ijk_ext dbl4 const dbl4_w_n;		// (  0,  0,  0, -1 )

ijk_ext dvec2 const dvec2_one;		// ( +1, +1 )
ijk_ext dvec2 const dvec2_zero;		// (  0,  0 )
ijk_ext dvec2 const dvec2_one_n;	// ( -1, -1 )
ijk_ext dvec2 const dvec2_x;		// ( +1,  0 )
ijk_ext dvec2 const dvec2_y;		// (  0, +1 )
ijk_ext dvec2 const dvec2_x_n;		// ( -1,  0 )
ijk_ext dvec2 const dvec2_y_n;		// (  0, -1 )

ijk_ext dvec3 const dvec3_one;		// ( +1, +1, +1 )
ijk_ext dvec3 const dvec3_zero;		// (  0,  0,  0 )
ijk_ext dvec3 const dvec3_one_n;	// ( -1, -1, -1 )
ijk_ext dvec3 const dvec3_x;		// ( +1,  0,  0 )
ijk_ext dvec3 const dvec3_y;		// (  0, +1,  0 )
ijk_ext dvec3 const dvec3_z;		// (  0,  0, +1 )
ijk_ext dvec3 const dvec3_x_n;		// ( -1,  0,  0 )
ijk_ext dvec3 const dvec3_y_n;		// (  0, -1,  0 )
ijk_ext dvec3 const dvec3_z_n;		// (  0,  0, -1 )

ijk_ext dvec4 const dvec4_one;		// ( +1, +1, +1, +1 )
ijk_ext dvec4 const dvec4_zero;		// (  0,  0,  0,  0 )
ijk_ext dvec4 const dvec4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext dvec4 const dvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_y;		// (  0, +1,  0,  0 )
ijk_ext dvec4 const dvec4_z;		// (  0,  0, +1,  0 )
ijk_ext dvec4 const dvec4_w;		// (  0,  0,  0, +1 )
ijk_ext dvec4 const dvec4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_y_n;		// (  0, -1,  0,  0 )
ijk_ext dvec4 const dvec4_z_n;		// (  0,  0, -1,  0 )
ijk_ext dvec4 const dvec4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

// Select real vector types.
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