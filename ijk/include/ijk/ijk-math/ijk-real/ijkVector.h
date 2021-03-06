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

	ijkVector.h
	Vector types and functions.
*/

#ifndef _IJK_VECTOR_H_
#define _IJK_VECTOR_H_


#include "ijkTrigonometry.h"
#include "ijkSqrt.h"


// IJK_SWIZZLE_VECTOR_DECL
#pragma region IJK_SWIZZLE_VECTOR_DECL

// Vector definition shortcuts (in lieu of templates in C).
///
#define IJK_VECS(t1,x,t2,y)				struct { t1 x; t2 y; }
#define IJK_VEC2(t1,t2,t3,t4,x,y,z,w)	{ t2 x##y; IJK_VECS(t1,x,t1,y); }
#define IJK_VEC3(t1,t2,t3,t4,x,y,z,w)	{ t3 x##y##z; t2 x##y; IJK_VECS(t1,x,union,IJK_VEC2(t1,t2,,,y,z,,)); }
#define IJK_VEC4(t1,t2,t3,t4,x,y,z,w)	{ t4 x##y##z##w; t3 x##y##z; t2 x##y; IJK_VECS(t1,x,union,IJK_VEC3(t1,t2,t3,,y,z,w,)); }
#define IJK_VECA2(t1,t2,t3,t4,x,y,z,w)	t1 x##y[2]; IJK_VECS(t1,x,t1,y)
#define IJK_VECA3(t1,t2,t3,t4,x,y,z,w)	t1 x##y##z[3]; t2 x##y; IJK_VECS(t1,x,union,IJK_VEC2(t1,t2,,,y,z,,))
#define IJK_VECA4(t1,t2,t3,t4,x,y,z,w)	t1 x##y##z##w[4]; t3 x##y##z; t2 x##y; IJK_VECS(t1,x,union,IJK_VEC3(t1,t2,t3,,y,z,w,))
#define IJK_VEC_DECL(decl,t1,t2,t3,t4)	decl(t1,t2,t3,t4,x,y,z,w); decl(t1,t2,t3,t4,r,g,b,a); decl(t1,t2,t3,t4,s,t,p,q)

// IJK_VEC_IMPL
//	Implements union vector of specified type in target interface.
//		param type: base type of vector (e.g. 'int' for integer vectors)
//		param tvec: vector type prefix (e.g. 'ivec' for integer vectors)
//		param sz: number of elements in vector (e.g. '2' for a 2D vector)
//		param sfx: suffix after elements (e.g. '<type>' for a template vector)
#define IJK_VEC_IMPL(type,tvec,sz,sfx)	type v[sz]; IJK_VEC_DECL(IJK_VECA##sz,type,tvec##2##sfx,tvec##3##sfx,tvec##4##sfx)

#pragma endregion
// IJK_SWIZZLE_VECTOR_DECL


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef enum ijkVecComp	ijkVecComp;
typedef union bvec2		bvec2;
typedef union bvec3		bvec3;
typedef union bvec4		bvec4;
typedef union ivec2		ivec2;
typedef union ivec3		ivec3;
typedef union ivec4		ivec4;
typedef union ilvec2	ilvec2;
typedef union ilvec3	ilvec3;
typedef union ilvec4	ilvec4;
typedef union uvec2		uvec2;
typedef union uvec3		uvec3;
typedef union uvec4		uvec4;
typedef union ulvec2	ulvec2;
typedef union ulvec3	ulvec3;
typedef union ulvec4	ulvec4;
typedef union fvec2		fvec2;
typedef union fvec3		fvec3;
typedef union fvec4		fvec4;
typedef union dvec2		dvec2;
typedef union dvec3		dvec3;
typedef union dvec4		dvec4;

// Built-in type overrides.
///
#define bool			byte	// sizeof(bool) = 1; does not align with GLSL
#define int				i32
#define intl			i64		// sizeof(intl) = 8; does not align with GLSL
#define uint			ui32
#define uintl			ui64	// sizeof(uintl) = 8; does not align with GLSL
#define float			f32
#define double			f64

// Convenience macros for declaring vector types.
///
#define IJK_BVEC_IMPL(sz)				IJK_VEC_IMPL(bool,bvec,sz,)
#define IJK_IVEC_IMPL(sz)				IJK_VEC_IMPL(int,ivec,sz,)
#define IJK_ILVEC_IMPL(sz)				IJK_VEC_IMPL(intl,ilvec,sz,)
#define IJK_UVEC_IMPL(sz)				IJK_VEC_IMPL(uint,uvec,sz,)
#define IJK_ULVEC_IMPL(sz)				IJK_VEC_IMPL(uintl,ulvec,sz,)
#define IJK_FVEC_IMPL(sz)				IJK_VEC_IMPL(float,fvec,sz,)
#define IJK_DVEC_IMPL(sz)				IJK_VEC_IMPL(double,dvec,sz,)

#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecComp
//	Named vector component index for user access.
enum ijkVecComp
{
	ijkVecX,
	ijkVecY,
	ijkVecZ,
	ijkVecW,
};


//-----------------------------------------------------------------------------

typedef byte const		* boolkv;	// Generic constant boolean/byte array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef byte			* boolv,	// Generic boolean/byte array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						bool2[2],	// 2D boolean array-based vector, always passed by pointer.
						bool3[3],	// 3D boolean array-based vector, always passed by pointer.
						bool4[4];	// 4D boolean array-based vector, always passed by pointer.

typedef i32 const		* intkv;	// Generic constant signed 32-bit integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef i32				* intv,		// Generic signed 32-bit integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						int2[2],	// 2D signed integer array-based vector, always passed by pointer.
						int3[3],	// 3D signed integer array-based vector, always passed by pointer.
						int4[4];	// 4D signed integer array-based vector, always passed by pointer.

typedef i64 const		* intlkv;	// Generic constant signed 64-bit integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef i64				* intlv,	// Generic signed 64-bit integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						intl2[2],	// 2D signed integer array-based vector, always passed by pointer.
						intl3[3],	// 3D signed integer array-based vector, always passed by pointer.
						intl4[4];	// 4D signed integer array-based vector, always passed by pointer.

typedef ui32 const		* uintkv;	// Generic constant unsigned 32-bit integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef ui32			* uintv,	// Generic unsigned 32-bit integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						uint2[2],	// 2D unsigned integer array-based vector, always passed by pointer.
						uint3[3],	// 3D unsigned integer array-based vector, always passed by pointer.
						uint4[4];	// 4D unsigned integer array-based vector, always passed by pointer.

typedef ui64 const		* uintlkv;	// Generic constant unsigned 64-bit integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef ui64			* uintlv,	// Generic unsigned 64-bit integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						uintl2[2],	// 2D unsigned integer array-based vector, always passed by pointer.
						uintl3[3],	// 3D unsigned integer array-based vector, always passed by pointer.
						uintl4[4];	// 4D unsigned integer array-based vector, always passed by pointer.

typedef f32 const		* floatkv;	// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef f32				* floatv,	// Generic float single-precision-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						float2[2],	// 2D single-precision array-based vector, always passed by pointer.
						float3[3],	// 3D single-precision array-based vector, always passed by pointer.
						float4[4];	// 4D single-precision array-based vector, always passed by pointer.

typedef f64 const		* doublekv;	// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef f64				* doublev,	// Generic double-precision array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						double2[2],	// 2D double-precision array-based vector, always passed by pointer.
						double3[3],	// 3D double-precision array-based vector, always passed by pointer.
						double4[4];	// 4D double-precision array-based vector, always passed by pointer.


//-----------------------------------------------------------------------------

#ifdef __cplusplus

#else // !__cplusplus

// bvec2
//	Data structure representing 2D boolean vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union bvec2
{
	IJK_BVEC_IMPL(2);
};

// bvec3
//	Data structure representing 3D boolean vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union bvec3
{
	IJK_BVEC_IMPL(3);
};

// bvec4
//	Data structure representing 4D boolean vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union bvec4
{
	IJK_BVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// ivec2
//	Data structure representing 2D signed 32-bit integer vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
	IJK_IVEC_IMPL(2);
};

// ivec3
//	Data structure representing 3D signed 32-bit integer vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ivec3
{
	IJK_IVEC_IMPL(3);
};

// ivec4
//	Data structure representing 4D signed 32-bit integer vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union ivec4
{
	IJK_IVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// ilvec2
//	Data structure representing 2D signed 64-bit integer vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ilvec2
{
	IJK_ILVEC_IMPL(2);
};

// ilvec3
//	Data structure representing 3D signed 64-bit integer vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ilvec3
{
	IJK_ILVEC_IMPL(3);
};

// ilvec4
//	Data structure representing 4D signed 64-bit integer vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union ilvec4
{
	IJK_ILVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// uvec2
//	Data structure representing 2D unsigned 32-bit integer vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union uvec2
{
	IJK_UVEC_IMPL(2);
};

// uvec3
//	Data structure representing 3D unsigned 32-bit integer vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union uvec3
{
	IJK_UVEC_IMPL(3);
};

// uvec4
//	Data structure representing 4D unsigned 32-bit integer vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union uvec4
{
	IJK_UVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// ulvec2
//	Data structure representing 2D unsigned 64-bit integer vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ulvec2
{
	IJK_ULVEC_IMPL(2);
};

// ulvec3
//	Data structure representing 3D unsigned 64-bit integer vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ulvec3
{
	IJK_ULVEC_IMPL(3);
};

// ulvec4
//	Data structure representing 4D unsigned 64-bit integer vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union ulvec4
{
	IJK_ULVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// fvec2
//	Data structure representing 2D single-precision (float) vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union fvec2
{
	IJK_FVEC_IMPL(2);
};

// fvec3
//	Data structure representing 3D single-precision (float) vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union fvec3
{
	IJK_FVEC_IMPL(3);
};

// fvec4
//	Data structure representing 4D single-precision (float) vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union fvec4
{
	IJK_FVEC_IMPL(4);
};


//-----------------------------------------------------------------------------

// dvec2
//	Data structure representing 2D double-precision (double) vector.
//		members v, xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union dvec2
{
	IJK_DVEC_IMPL(2);
};

// dvec3
//	Data structure representing 3D double-precision (double) vector.
//		members v, xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of last two elements
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union dvec3
{
	IJK_DVEC_IMPL(3);
};

// dvec4
//	Data structure representing 4D double-precision (double) vector.
//		members v, xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements
//		members yzw, gba, tpq: partial swizzle of last three elements
//		members xy, rg, st: partial swizzle of first two elements
//		members yz, gb, tp: partial swizzle of middle two elements
//		members zw, ba, pq: partial swizzle of last two elements
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union dvec4
{
	IJK_DVEC_IMPL(4);
};

#endif	// __cplusplus


//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_util/ijkVectorSwizzle.h"
#include "_util/ijkVector_bool.h"
#include "_util/ijkVector_int.h"
#include "_util/ijkVector_intl.h"
#include "_util/ijkVector_uint.h"
#include "_util/ijkVector_uintl.h"
#include "_util/ijkVector_float.h"
#include "_util/ijkVector_double.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// Global constants for boolean array-based vectors and data structures.
///
ijk_ext bool2 const bool2_true;		// (  true,  true )
ijk_ext bool2 const bool2_false;	// ( false, false )
ijk_ext bool2 const bool2_x;		// (  true, false )
ijk_ext bool2 const bool2_y;		// ( false,  true )

ijk_ext bool3 const bool3_true;		// (  true,  true,  true )
ijk_ext bool3 const bool3_false;	// ( false, false, false )
ijk_ext bool3 const bool3_x;		// (  true, false, false )
ijk_ext bool3 const bool3_y;		// ( false,  true, false )
ijk_ext bool3 const bool3_z;		// ( false, false,  true )

ijk_ext bool4 const bool4_true;		// (  true,  true,  true,  true )
ijk_ext bool4 const bool4_false;	// ( false, false, false, false )
ijk_ext bool4 const bool4_x;		// (  true, false, false, false )
ijk_ext bool4 const bool4_y;		// ( false,  true, false, false )
ijk_ext bool4 const bool4_z;		// ( false, false,  true, false )
ijk_ext bool4 const bool4_w;		// ( false, false, false,  true )

ijk_ext bvec2 const bvec2_true;		// (  true,  true )
ijk_ext bvec2 const bvec2_false;	// ( false, false )
ijk_ext bvec2 const bvec2_x;		// (  true, false )
ijk_ext bvec2 const bvec2_y;		// ( false,  true )

ijk_ext bvec3 const bvec3_true;		// (  true,  true,  true )
ijk_ext bvec3 const bvec3_false;	// ( false, false, false )
ijk_ext bvec3 const bvec3_x;		// (  true, false, false )
ijk_ext bvec3 const bvec3_y;		// ( false,  true, false )
ijk_ext bvec3 const bvec3_z;		// ( false, false,  true )

ijk_ext bvec4 const bvec4_true;		// (  true,  true,  true,  true )
ijk_ext bvec4 const bvec4_false;	// ( false, false, false, false )
ijk_ext bvec4 const bvec4_x;		// (  true, false, false, false )
ijk_ext bvec4 const bvec4_y;		// ( false,  true, false, false )
ijk_ext bvec4 const bvec4_z;		// ( false, false,  true, false )
ijk_ext bvec4 const bvec4_w;		// ( false, false, false,  true )


//-----------------------------------------------------------------------------

// Global constants for signed 32-bit integer array-based vectors and data structures.
///
ijk_ext int2 const int2_1;			// ( +1, +1 )
ijk_ext int2 const int2_0;			// (  0,  0 )
ijk_ext int2 const int2_1n;			// ( -1, -1 )
ijk_ext int2 const int2_x;			// ( +1,  0 )
ijk_ext int2 const int2_y;			// (  0, +1 )
ijk_ext int2 const int2_xn;			// ( -1,  0 )
ijk_ext int2 const int2_yn;			// (  0, -1 )

ijk_ext int3 const int3_1;			// ( +1, +1, +1 )
ijk_ext int3 const int3_0;			// (  0,  0,  0 )
ijk_ext int3 const int3_1n;			// ( -1, -1, -1 )
ijk_ext int3 const int3_x;			// ( +1,  0,  0 )
ijk_ext int3 const int3_y;			// (  0, +1,  0 )
ijk_ext int3 const int3_z;			// (  0,  0, +1 )
ijk_ext int3 const int3_xn;			// ( -1,  0,  0 )
ijk_ext int3 const int3_yn;			// (  0, -1,  0 )
ijk_ext int3 const int3_zn;			// (  0,  0, -1 )

ijk_ext int4 const int4_1;			// ( +1, +1, +1, +1 )
ijk_ext int4 const int4_0;			// (  0,  0,  0,  0 )
ijk_ext int4 const int4_1n;			// ( -1, -1, -1, -1 )
ijk_ext int4 const int4_x;			// ( +1,  0,  0,  0 )
ijk_ext int4 const int4_y;			// (  0, +1,  0,  0 )
ijk_ext int4 const int4_z;			// (  0,  0, +1,  0 )
ijk_ext int4 const int4_w;			// (  0,  0,  0, +1 )
ijk_ext int4 const int4_xn;			// ( -1,  0,  0,  0 )
ijk_ext int4 const int4_yn;			// (  0, -1,  0,  0 )
ijk_ext int4 const int4_zn;			// (  0,  0, -1,  0 )
ijk_ext int4 const int4_wn;			// (  0,  0,  0, -1 )

ijk_ext ivec2 const ivec2_1;		// ( +1, +1 )
ijk_ext ivec2 const ivec2_0;		// (  0,  0 )
ijk_ext ivec2 const ivec2_1n;		// ( -1, -1 )
ijk_ext ivec2 const ivec2_x;		// ( +1,  0 )
ijk_ext ivec2 const ivec2_y;		// (  0, +1 )
ijk_ext ivec2 const ivec2_xn;		// ( -1,  0 )
ijk_ext ivec2 const ivec2_yn;		// (  0, -1 )

ijk_ext ivec3 const ivec3_1;		// ( +1, +1, +1 )
ijk_ext ivec3 const ivec3_0;		// (  0,  0,  0 )
ijk_ext ivec3 const ivec3_1n;		// ( -1, -1, -1 )
ijk_ext ivec3 const ivec3_x;		// ( +1,  0,  0 )
ijk_ext ivec3 const ivec3_y;		// (  0, +1,  0 )
ijk_ext ivec3 const ivec3_z;		// (  0,  0, +1 )
ijk_ext ivec3 const ivec3_xn;		// ( -1,  0,  0 )
ijk_ext ivec3 const ivec3_yn;		// (  0, -1,  0 )
ijk_ext ivec3 const ivec3_zn;		// (  0,  0, -1 )

ijk_ext ivec4 const ivec4_1;		// ( +1, +1, +1, +1 )
ijk_ext ivec4 const ivec4_0;		// (  0,  0,  0,  0 )
ijk_ext ivec4 const ivec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext ivec4 const ivec4_x;		// ( +1,  0,  0,  0 )
ijk_ext ivec4 const ivec4_y;		// (  0, +1,  0,  0 )
ijk_ext ivec4 const ivec4_z;		// (  0,  0, +1,  0 )
ijk_ext ivec4 const ivec4_w;		// (  0,  0,  0, +1 )
ijk_ext ivec4 const ivec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext ivec4 const ivec4_yn;		// (  0, -1,  0,  0 )
ijk_ext ivec4 const ivec4_zn;		// (  0,  0, -1,  0 )
ijk_ext ivec4 const ivec4_wn;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Global constants for signed 64-bit integer array-based vectors and data structures.
///
ijk_ext intl2 const intl2_1;		// ( +1, +1 )
ijk_ext intl2 const intl2_0;		// (  0,  0 )
ijk_ext intl2 const intl2_1n;		// ( -1, -1 )
ijk_ext intl2 const intl2_x;		// ( +1,  0 )
ijk_ext intl2 const intl2_y;		// (  0, +1 )
ijk_ext intl2 const intl2_xn;		// ( -1,  0 )
ijk_ext intl2 const intl2_yn;		// (  0, -1 )

ijk_ext intl3 const intl3_1;		// ( +1, +1, +1 )
ijk_ext intl3 const intl3_0;		// (  0,  0,  0 )
ijk_ext intl3 const intl3_1n;		// ( -1, -1, -1 )
ijk_ext intl3 const intl3_x;		// ( +1,  0,  0 )
ijk_ext intl3 const intl3_y;		// (  0, +1,  0 )
ijk_ext intl3 const intl3_z;		// (  0,  0, +1 )
ijk_ext intl3 const intl3_xn;		// ( -1,  0,  0 )
ijk_ext intl3 const intl3_yn;		// (  0, -1,  0 )
ijk_ext intl3 const intl3_zn;		// (  0,  0, -1 )

ijk_ext intl4 const intl4_1;		// ( +1, +1, +1, +1 )
ijk_ext intl4 const intl4_0;		// (  0,  0,  0,  0 )
ijk_ext intl4 const intl4_1n;		// ( -1, -1, -1, -1 )
ijk_ext intl4 const intl4_x;		// ( +1,  0,  0,  0 )
ijk_ext intl4 const intl4_y;		// (  0, +1,  0,  0 )
ijk_ext intl4 const intl4_z;		// (  0,  0, +1,  0 )
ijk_ext intl4 const intl4_w;		// (  0,  0,  0, +1 )
ijk_ext intl4 const intl4_xn;		// ( -1,  0,  0,  0 )
ijk_ext intl4 const intl4_yn;		// (  0, -1,  0,  0 )
ijk_ext intl4 const intl4_zn;		// (  0,  0, -1,  0 )
ijk_ext intl4 const intl4_wn;		// (  0,  0,  0, -1 )

ijk_ext ilvec2 const ilvec2_1;		// ( +1, +1 )
ijk_ext ilvec2 const ilvec2_0;		// (  0,  0 )
ijk_ext ilvec2 const ilvec2_1n;		// ( -1, -1 )
ijk_ext ilvec2 const ilvec2_x;		// ( +1,  0 )
ijk_ext ilvec2 const ilvec2_y;		// (  0, +1 )
ijk_ext ilvec2 const ilvec2_xn;		// ( -1,  0 )
ijk_ext ilvec2 const ilvec2_yn;		// (  0, -1 )

ijk_ext ilvec3 const ilvec3_1;		// ( +1, +1, +1 )
ijk_ext ilvec3 const ilvec3_0;		// (  0,  0,  0 )
ijk_ext ilvec3 const ilvec3_1n;		// ( -1, -1, -1 )
ijk_ext ilvec3 const ilvec3_x;		// ( +1,  0,  0 )
ijk_ext ilvec3 const ilvec3_y;		// (  0, +1,  0 )
ijk_ext ilvec3 const ilvec3_z;		// (  0,  0, +1 )
ijk_ext ilvec3 const ilvec3_xn;		// ( -1,  0,  0 )
ijk_ext ilvec3 const ilvec3_yn;		// (  0, -1,  0 )
ijk_ext ilvec3 const ilvec3_zn;		// (  0,  0, -1 )

ijk_ext ilvec4 const ilvec4_1;		// ( +1, +1, +1, +1 )
ijk_ext ilvec4 const ilvec4_0;		// (  0,  0,  0,  0 )
ijk_ext ilvec4 const ilvec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext ilvec4 const ilvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext ilvec4 const ilvec4_y;		// (  0, +1,  0,  0 )
ijk_ext ilvec4 const ilvec4_z;		// (  0,  0, +1,  0 )
ijk_ext ilvec4 const ilvec4_w;		// (  0,  0,  0, +1 )
ijk_ext ilvec4 const ilvec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext ilvec4 const ilvec4_yn;		// (  0, -1,  0,  0 )
ijk_ext ilvec4 const ilvec4_zn;		// (  0,  0, -1,  0 )
ijk_ext ilvec4 const ilvec4_wn;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Global constants for unsigned 32-bit integer array-based vectors and data structures.
// Note: negatives are represented as maximum unsigned value.
///
ijk_ext uint2 const uint2_1;		// ( +1, +1 )
ijk_ext uint2 const uint2_0;		// (  0,  0 )
ijk_ext uint2 const uint2_1n;		// ( -1, -1 )
ijk_ext uint2 const uint2_x;		// ( +1,  0 )
ijk_ext uint2 const uint2_y;		// (  0, +1 )
ijk_ext uint2 const uint2_xn;		// ( -1,  0 )
ijk_ext uint2 const uint2_yn;		// (  0, -1 )

ijk_ext uint3 const uint3_1;		// ( +1, +1, +1 )
ijk_ext uint3 const uint3_0;		// (  0,  0,  0 )
ijk_ext uint3 const uint3_1n;		// ( -1, -1, -1 )
ijk_ext uint3 const uint3_x;		// ( +1,  0,  0 )
ijk_ext uint3 const uint3_y;		// (  0, +1,  0 )
ijk_ext uint3 const uint3_z;		// (  0,  0, +1 )
ijk_ext uint3 const uint3_xn;		// ( -1,  0,  0 )
ijk_ext uint3 const uint3_yn;		// (  0, -1,  0 )
ijk_ext uint3 const uint3_zn;		// (  0,  0, -1 )

ijk_ext uint4 const uint4_1;		// ( +1, +1, +1, +1 )
ijk_ext uint4 const uint4_0;		// (  0,  0,  0,  0 )
ijk_ext uint4 const uint4_1n;		// ( -1, -1, -1, -1 )
ijk_ext uint4 const uint4_x;		// ( +1,  0,  0,  0 )
ijk_ext uint4 const uint4_y;		// (  0, +1,  0,  0 )
ijk_ext uint4 const uint4_z;		// (  0,  0, +1,  0 )
ijk_ext uint4 const uint4_w;		// (  0,  0,  0, +1 )
ijk_ext uint4 const uint4_xn;		// ( -1,  0,  0,  0 )
ijk_ext uint4 const uint4_yn;		// (  0, -1,  0,  0 )
ijk_ext uint4 const uint4_zn;		// (  0,  0, -1,  0 )
ijk_ext uint4 const uint4_wn;		// (  0,  0,  0, -1 )

ijk_ext uvec2 const uvec2_1;		// ( +1, +1 )
ijk_ext uvec2 const uvec2_0;		// (  0,  0 )
ijk_ext uvec2 const uvec2_1n;		// ( -1, -1 )
ijk_ext uvec2 const uvec2_x;		// ( +1,  0 )
ijk_ext uvec2 const uvec2_y;		// (  0, +1 )
ijk_ext uvec2 const uvec2_xn;		// ( -1,  0 )
ijk_ext uvec2 const uvec2_yn;		// (  0, -1 )

ijk_ext uvec3 const uvec3_1;		// ( +1, +1, +1 )
ijk_ext uvec3 const uvec3_0;		// (  0,  0,  0 )
ijk_ext uvec3 const uvec3_1n;		// ( -1, -1, -1 )
ijk_ext uvec3 const uvec3_x;		// ( +1,  0,  0 )
ijk_ext uvec3 const uvec3_y;		// (  0, +1,  0 )
ijk_ext uvec3 const uvec3_z;		// (  0,  0, +1 )
ijk_ext uvec3 const uvec3_xn;		// ( -1,  0,  0 )
ijk_ext uvec3 const uvec3_yn;		// (  0, -1,  0 )
ijk_ext uvec3 const uvec3_zn;		// (  0,  0, -1 )

ijk_ext uvec4 const uvec4_1;		// ( +1, +1, +1, +1 )
ijk_ext uvec4 const uvec4_0;		// (  0,  0,  0,  0 )
ijk_ext uvec4 const uvec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext uvec4 const uvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext uvec4 const uvec4_y;		// (  0, +1,  0,  0 )
ijk_ext uvec4 const uvec4_z;		// (  0,  0, +1,  0 )
ijk_ext uvec4 const uvec4_w;		// (  0,  0,  0, +1 )
ijk_ext uvec4 const uvec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext uvec4 const uvec4_yn;		// (  0, -1,  0,  0 )
ijk_ext uvec4 const uvec4_zn;		// (  0,  0, -1,  0 )
ijk_ext uvec4 const uvec4_wn;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Global constants for unsigned 64-bit integer array-based vectors and data structures.
// Note: negatives are represented as maximum unsigned value.
///
ijk_ext uintl2 const uintl2_1;		// ( +1, +1 )
ijk_ext uintl2 const uintl2_0;		// (  0,  0 )
ijk_ext uintl2 const uintl2_1n;		// ( -1, -1 )
ijk_ext uintl2 const uintl2_x;		// ( +1,  0 )
ijk_ext uintl2 const uintl2_y;		// (  0, +1 )
ijk_ext uintl2 const uintl2_xn;		// ( -1,  0 )
ijk_ext uintl2 const uintl2_yn;		// (  0, -1 )

ijk_ext uintl3 const uintl3_1;		// ( +1, +1, +1 )
ijk_ext uintl3 const uintl3_0;		// (  0,  0,  0 )
ijk_ext uintl3 const uintl3_1n;		// ( -1, -1, -1 )
ijk_ext uintl3 const uintl3_x;		// ( +1,  0,  0 )
ijk_ext uintl3 const uintl3_y;		// (  0, +1,  0 )
ijk_ext uintl3 const uintl3_z;		// (  0,  0, +1 )
ijk_ext uintl3 const uintl3_xn;		// ( -1,  0,  0 )
ijk_ext uintl3 const uintl3_yn;		// (  0, -1,  0 )
ijk_ext uintl3 const uintl3_zn;		// (  0,  0, -1 )

ijk_ext uintl4 const uintl4_1;		// ( +1, +1, +1, +1 )
ijk_ext uintl4 const uintl4_0;		// (  0,  0,  0,  0 )
ijk_ext uintl4 const uintl4_1n;		// ( -1, -1, -1, -1 )
ijk_ext uintl4 const uintl4_x;		// ( +1,  0,  0,  0 )
ijk_ext uintl4 const uintl4_y;		// (  0, +1,  0,  0 )
ijk_ext uintl4 const uintl4_z;		// (  0,  0, +1,  0 )
ijk_ext uintl4 const uintl4_w;		// (  0,  0,  0, +1 )
ijk_ext uintl4 const uintl4_xn;		// ( -1,  0,  0,  0 )
ijk_ext uintl4 const uintl4_yn;		// (  0, -1,  0,  0 )
ijk_ext uintl4 const uintl4_zn;		// (  0,  0, -1,  0 )
ijk_ext uintl4 const uintl4_wn;		// (  0,  0,  0, -1 )

ijk_ext ulvec2 const ulvec2_1;		// ( +1, +1 )
ijk_ext ulvec2 const ulvec2_0;		// (  0,  0 )
ijk_ext ulvec2 const ulvec2_1n;		// ( -1, -1 )
ijk_ext ulvec2 const ulvec2_x;		// ( +1,  0 )
ijk_ext ulvec2 const ulvec2_y;		// (  0, +1 )
ijk_ext ulvec2 const ulvec2_xn;		// ( -1,  0 )
ijk_ext ulvec2 const ulvec2_yn;		// (  0, -1 )

ijk_ext ulvec3 const ulvec3_1;		// ( +1, +1, +1 )
ijk_ext ulvec3 const ulvec3_0;		// (  0,  0,  0 )
ijk_ext ulvec3 const ulvec3_1n;		// ( -1, -1, -1 )
ijk_ext ulvec3 const ulvec3_x;		// ( +1,  0,  0 )
ijk_ext ulvec3 const ulvec3_y;		// (  0, +1,  0 )
ijk_ext ulvec3 const ulvec3_z;		// (  0,  0, +1 )
ijk_ext ulvec3 const ulvec3_xn;		// ( -1,  0,  0 )
ijk_ext ulvec3 const ulvec3_yn;		// (  0, -1,  0 )
ijk_ext ulvec3 const ulvec3_zn;		// (  0,  0, -1 )

ijk_ext ulvec4 const ulvec4_1;		// ( +1, +1, +1, +1 )
ijk_ext ulvec4 const ulvec4_0;		// (  0,  0,  0,  0 )
ijk_ext ulvec4 const ulvec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext ulvec4 const ulvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext ulvec4 const ulvec4_y;		// (  0, +1,  0,  0 )
ijk_ext ulvec4 const ulvec4_z;		// (  0,  0, +1,  0 )
ijk_ext ulvec4 const ulvec4_w;		// (  0,  0,  0, +1 )
ijk_ext ulvec4 const ulvec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext ulvec4 const ulvec4_yn;		// (  0, -1,  0,  0 )
ijk_ext ulvec4 const ulvec4_zn;		// (  0,  0, -1,  0 )
ijk_ext ulvec4 const ulvec4_wn;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Alternative names for float vector.
///
typedef fvec2		vec2;		// Alias for 2D float vector.
typedef fvec3		vec3;		// Alias for 3D float vector.
typedef fvec4		vec4;		// Alias for 4D float vector.

// Global constants for float array-based vectors and data structures.
///
ijk_ext float2 const float2_1;		// ( +1, +1 )
ijk_ext float2 const float2_0;		// (  0,  0 )
ijk_ext float2 const float2_1n;		// ( -1, -1 )
ijk_ext float2 const float2_x;		// ( +1,  0 )
ijk_ext float2 const float2_y;		// (  0, +1 )
ijk_ext float2 const float2_xn;		// ( -1,  0 )
ijk_ext float2 const float2_yn;		// (  0, -1 )

ijk_ext float3 const float3_1;		// ( +1, +1, +1 )
ijk_ext float3 const float3_0;		// (  0,  0,  0 )
ijk_ext float3 const float3_1n;		// ( -1, -1, -1 )
ijk_ext float3 const float3_x;		// ( +1,  0,  0 )
ijk_ext float3 const float3_y;		// (  0, +1,  0 )
ijk_ext float3 const float3_z;		// (  0,  0, +1 )
ijk_ext float3 const float3_xn;		// ( -1,  0,  0 )
ijk_ext float3 const float3_yn;		// (  0, -1,  0 )
ijk_ext float3 const float3_zn;		// (  0,  0, -1 )

ijk_ext float4 const float4_1;		// ( +1, +1, +1, +1 )
ijk_ext float4 const float4_0;		// (  0,  0,  0,  0 )
ijk_ext float4 const float4_1n;		// ( -1, -1, -1, -1 )
ijk_ext float4 const float4_x;		// ( +1,  0,  0,  0 )
ijk_ext float4 const float4_y;		// (  0, +1,  0,  0 )
ijk_ext float4 const float4_z;		// (  0,  0, +1,  0 )
ijk_ext float4 const float4_w;		// (  0,  0,  0, +1 )
ijk_ext float4 const float4_xn;		// ( -1,  0,  0,  0 )
ijk_ext float4 const float4_yn;		// (  0, -1,  0,  0 )
ijk_ext float4 const float4_zn;		// (  0,  0, -1,  0 )
ijk_ext float4 const float4_wn;		// (  0,  0,  0, -1 )

ijk_ext fvec2 const fvec2_1;		// ( +1, +1 )
ijk_ext fvec2 const fvec2_0;		// (  0,  0 )
ijk_ext fvec2 const fvec2_1n;		// ( -1, -1 )
ijk_ext fvec2 const fvec2_x;		// ( +1,  0 )
ijk_ext fvec2 const fvec2_y;		// (  0, +1 )
ijk_ext fvec2 const fvec2_xn;		// ( -1,  0 )
ijk_ext fvec2 const fvec2_yn;		// (  0, -1 )

ijk_ext fvec3 const fvec3_1;		// ( +1, +1, +1 )
ijk_ext fvec3 const fvec3_0;		// (  0,  0,  0 )
ijk_ext fvec3 const fvec3_1n;		// ( -1, -1, -1 )
ijk_ext fvec3 const fvec3_x;		// ( +1,  0,  0 )
ijk_ext fvec3 const fvec3_y;		// (  0, +1,  0 )
ijk_ext fvec3 const fvec3_z;		// (  0,  0, +1 )
ijk_ext fvec3 const fvec3_xn;		// ( -1,  0,  0 )
ijk_ext fvec3 const fvec3_yn;		// (  0, -1,  0 )
ijk_ext fvec3 const fvec3_zn;		// (  0,  0, -1 )

ijk_ext fvec4 const fvec4_1;		// ( +1, +1, +1, +1 )
ijk_ext fvec4 const fvec4_0;		// (  0,  0,  0,  0 )
ijk_ext fvec4 const fvec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext fvec4 const fvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext fvec4 const fvec4_y;		// (  0, +1,  0,  0 )
ijk_ext fvec4 const fvec4_z;		// (  0,  0, +1,  0 )
ijk_ext fvec4 const fvec4_w;		// (  0,  0,  0, +1 )
ijk_ext fvec4 const fvec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext fvec4 const fvec4_yn;		// (  0, -1,  0,  0 )
ijk_ext fvec4 const fvec4_zn;		// (  0,  0, -1,  0 )
ijk_ext fvec4 const fvec4_wn;		// (  0,  0,  0, -1 )

ijk_ext vec2 const vec2_1;			// ( +1, +1 )
ijk_ext vec2 const vec2_0;			// (  0,  0 )
ijk_ext vec2 const vec2_1n;			// ( -1, -1 )
ijk_ext vec2 const vec2_x;			// ( +1,  0 )
ijk_ext vec2 const vec2_y;			// (  0, +1 )
ijk_ext vec2 const vec2_xn;			// ( -1,  0 )
ijk_ext vec2 const vec2_yn;			// (  0, -1 )

ijk_ext vec3 const vec3_1;			// ( +1, +1, +1 )
ijk_ext vec3 const vec3_0;			// (  0,  0,  0 )
ijk_ext vec3 const vec3_1n;			// ( -1, -1, -1 )
ijk_ext vec3 const vec3_x;			// ( +1,  0,  0 )
ijk_ext vec3 const vec3_y;			// (  0, +1,  0 )
ijk_ext vec3 const vec3_z;			// (  0,  0, +1 )
ijk_ext vec3 const vec3_xn;			// ( -1,  0,  0 )
ijk_ext vec3 const vec3_yn;			// (  0, -1,  0 )
ijk_ext vec3 const vec3_zn;			// (  0,  0, -1 )

ijk_ext vec4 const vec4_1;			// ( +1, +1, +1, +1 )
ijk_ext vec4 const vec4_0;			// (  0,  0,  0,  0 )
ijk_ext vec4 const vec4_1n;			// ( -1, -1, -1, -1 )
ijk_ext vec4 const vec4_x;			// ( +1,  0,  0,  0 )
ijk_ext vec4 const vec4_y;			// (  0, +1,  0,  0 )
ijk_ext vec4 const vec4_z;			// (  0,  0, +1,  0 )
ijk_ext vec4 const vec4_w;			// (  0,  0,  0, +1 )
ijk_ext vec4 const vec4_xn;			// ( -1,  0,  0,  0 )
ijk_ext vec4 const vec4_yn;			// (  0, -1,  0,  0 )
ijk_ext vec4 const vec4_zn;			// (  0,  0, -1,  0 )
ijk_ext vec4 const vec4_wn;			// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Global constants for double array-based vectors and data structures.
///
ijk_ext double2 const double2_1;	// ( +1, +1 )
ijk_ext double2 const double2_0;	// (  0,  0 )
ijk_ext double2 const double2_1n;	// ( -1, -1 )
ijk_ext double2 const double2_x;	// ( +1,  0 )
ijk_ext double2 const double2_y;	// (  0, +1 )
ijk_ext double2 const double2_xn;	// ( -1,  0 )
ijk_ext double2 const double2_yn;	// (  0, -1 )

ijk_ext double3 const double3_1;	// ( +1, +1, +1 )
ijk_ext double3 const double3_0;	// (  0,  0,  0 )
ijk_ext double3 const double3_1n;	// ( -1, -1, -1 )
ijk_ext double3 const double3_x;	// ( +1,  0,  0 )
ijk_ext double3 const double3_y;	// (  0, +1,  0 )
ijk_ext double3 const double3_z;	// (  0,  0, +1 )
ijk_ext double3 const double3_xn;	// ( -1,  0,  0 )
ijk_ext double3 const double3_yn;	// (  0, -1,  0 )
ijk_ext double3 const double3_zn;	// (  0,  0, -1 )

ijk_ext double4 const double4_1;	// ( +1, +1, +1, +1 )
ijk_ext double4 const double4_0;	// (  0,  0,  0,  0 )
ijk_ext double4 const double4_1n;	// ( -1, -1, -1, -1 )
ijk_ext double4 const double4_x;	// ( +1,  0,  0,  0 )
ijk_ext double4 const double4_y;	// (  0, +1,  0,  0 )
ijk_ext double4 const double4_z;	// (  0,  0, +1,  0 )
ijk_ext double4 const double4_w;	// (  0,  0,  0, +1 )
ijk_ext double4 const double4_xn;	// ( -1,  0,  0,  0 )
ijk_ext double4 const double4_yn;	// (  0, -1,  0,  0 )
ijk_ext double4 const double4_zn;	// (  0,  0, -1,  0 )
ijk_ext double4 const double4_wn;	// (  0,  0,  0, -1 )

ijk_ext dvec2 const dvec2_1;		// ( +1, +1 )
ijk_ext dvec2 const dvec2_0;		// (  0,  0 )
ijk_ext dvec2 const dvec2_1n;		// ( -1, -1 )
ijk_ext dvec2 const dvec2_x;		// ( +1,  0 )
ijk_ext dvec2 const dvec2_y;		// (  0, +1 )
ijk_ext dvec2 const dvec2_xn;		// ( -1,  0 )
ijk_ext dvec2 const dvec2_yn;		// (  0, -1 )

ijk_ext dvec3 const dvec3_1;		// ( +1, +1, +1 )
ijk_ext dvec3 const dvec3_0;		// (  0,  0,  0 )
ijk_ext dvec3 const dvec3_1n;		// ( -1, -1, -1 )
ijk_ext dvec3 const dvec3_x;		// ( +1,  0,  0 )
ijk_ext dvec3 const dvec3_y;		// (  0, +1,  0 )
ijk_ext dvec3 const dvec3_z;		// (  0,  0, +1 )
ijk_ext dvec3 const dvec3_xn;		// ( -1,  0,  0 )
ijk_ext dvec3 const dvec3_yn;		// (  0, -1,  0 )
ijk_ext dvec3 const dvec3_zn;		// (  0,  0, -1 )

ijk_ext dvec4 const dvec4_1;		// ( +1, +1, +1, +1 )
ijk_ext dvec4 const dvec4_0;		// (  0,  0,  0,  0 )
ijk_ext dvec4 const dvec4_1n;		// ( -1, -1, -1, -1 )
ijk_ext dvec4 const dvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_y;		// (  0, +1,  0,  0 )
ijk_ext dvec4 const dvec4_z;		// (  0,  0, +1,  0 )
ijk_ext dvec4 const dvec4_w;		// (  0,  0,  0, +1 )
ijk_ext dvec4 const dvec4_xn;		// ( -1,  0,  0,  0 )
ijk_ext dvec4 const dvec4_yn;		// (  0, -1,  0,  0 )
ijk_ext dvec4 const dvec4_zn;		// (  0,  0, -1,  0 )
ijk_ext dvec4 const dvec4_wn;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Select real vector types.
///
typedef real const	* realkv;	// Generic constant real-type array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real		* realv,	// Generic real-type array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
					real2[2],	// 2D real-type array-based vector, always passed by pointer.
					real3[3],	// 3D real-type array-based vector, always passed by pointer.
					real4[4];	// 4D real-type array-based vector, always passed by pointer.

// Global constants for real array-based vectors and data structures.
///
#ifdef IJK_REAL_DBL
typedef dvec2		rvec2;		// Real 2D vector data structure type is 2D double vector.
typedef dvec3		rvec3;		// Real 3D vector data structure type is 3D double vector.
typedef dvec4		rvec4;		// Real 4D vector data structure type is 4D double vector.

#define real2_1		double2_1	// ( +1, +1 )
#define real2_0		double2_0	// (  0,  0 )
#define real2_1n	double2_1n	// ( -1, -1 )
#define real2_x		double2_x	// ( +1,  0 )
#define real2_y		double2_y	// (  0, +1 )
#define real2_xn	double2_xn	// ( -1,  0 )
#define real2_yn	double2_yn	// (  0, -1 )

#define real3_1		double3_1	// ( +1, +1, +1 )
#define real3_0		double3_0	// (  0,  0,  0 )
#define real3_1n	double3_1n	// ( -1, -1, -1 )
#define real3_x		double3_x	// ( +1,  0,  0 )
#define real3_y		double3_y	// (  0, +1,  0 )
#define real3_z		double3_z	// (  0,  0, +1 )
#define real3_xn	double3_xn	// ( -1,  0,  0 )
#define real3_yn	double3_yn	// (  0, -1,  0 )
#define real3_zn	double3_zn	// (  0,  0, -1 )

#define real4_1		double4_1	// ( +1, +1, +1, +1 )
#define real4_0		double4_0	// (  0,  0,  0,  0 )
#define real4_1n	double4_1n	// ( -1, -1, -1, -1 )
#define real4_x		double4_x	// ( +1,  0,  0,  0 )
#define real4_y		double4_y	// (  0, +1,  0,  0 )
#define real4_z		double4_z	// (  0,  0, +1,  0 )
#define real4_w		double4_w	// (  0,  0,  0, +1 )
#define real4_xn	double4_xn	// ( -1,  0,  0,  0 )
#define real4_yn	double4_yn	// (  0, -1,  0,  0 )
#define real4_zn	double4_zn	// (  0,  0, -1,  0 )
#define real4_wn	double4_wn	// (  0,  0,  0, -1 )

#define rvec2_1		dvec2_1		// ( +1, +1 )
#define rvec2_0		dvec2_0		// (  0,  0 )
#define rvec2_1n	dvec2_1n	// ( -1, -1 )
#define rvec2_x		dvec2_x		// ( +1,  0 )
#define rvec2_y		dvec2_y		// (  0, +1 )
#define rvec2_xn	dvec2_xn	// ( -1,  0 )
#define rvec2_yn	dvec2_yn	// (  0, -1 )

#define rvec3_1		dvec3_1		// ( +1, +1, +1 )
#define rvec3_0		dvec3_0		// (  0,  0,  0 )
#define rvec3_1n	dvec3_1n	// ( -1, -1, -1 )
#define rvec3_x		dvec3_x		// ( +1,  0,  0 )
#define rvec3_y		dvec3_y		// (  0, +1,  0 )
#define rvec3_z		dvec3_z		// (  0,  0, +1 )
#define rvec3_xn	dvec3_xn	// ( -1,  0,  0 )
#define rvec3_yn	dvec3_yn	// (  0, -1,  0 )
#define rvec3_zn	dvec3_zn	// (  0,  0, -1 )

#define rvec4_1		dvec4_1		// ( +1, +1, +1, +1 )
#define rvec4_0		dvec4_0		// (  0,  0,  0,  0 )
#define rvec4_1n	dvec4_1n	// ( -1, -1, -1, -1 )
#define rvec4_x		dvec4_x		// ( +1,  0,  0,  0 )
#define rvec4_y		dvec4_y		// (  0, +1,  0,  0 )
#define rvec4_z		dvec4_z		// (  0,  0, +1,  0 )
#define rvec4_w		dvec4_w		// (  0,  0,  0, +1 )
#define rvec4_xn	dvec4_xn	// ( -1,  0,  0,  0 )
#define rvec4_yn	dvec4_yn	// (  0, -1,  0,  0 )
#define rvec4_zn	dvec4_zn	// (  0,  0, -1,  0 )
#define rvec4_wn	dvec4_wn	// (  0,  0,  0, -1 )

#else	// !IJK_REAL_DBL
typedef fvec2		rvec2;		// Real 2D vector data structure type is 2D float vector.
typedef fvec3		rvec3;		// Real 3D vector data structure type is 3D float vector.
typedef fvec4		rvec4;		// Real 4D vector data structure type is 4D float vector.

#define real2_1		float2_1	// ( +1, +1 )
#define real2_0		float2_0	// (  0,  0 )
#define real2_1n	float2_1n	// ( -1, -1 )
#define real2_x		float2_x	// ( +1,  0 )
#define real2_y		float2_y	// (  0, +1 )
#define real2_xn	float2_xn	// ( -1,  0 )
#define real2_yn	float2_yn	// (  0, -1 )

#define real3_1		float3_1	// ( +1, +1, +1 )
#define real3_0		float3_0	// (  0,  0,  0 )
#define real3_1n	float3_1n	// ( -1, -1, -1 )
#define real3_x		float3_x	// ( +1,  0,  0 )
#define real3_y		float3_y	// (  0, +1,  0 )
#define real3_z		float3_z	// (  0,  0, +1 )
#define real3_xn	float3_xn	// ( -1,  0,  0 )
#define real3_yn	float3_yn	// (  0, -1,  0 )
#define real3_zn	float3_zn	// (  0,  0, -1 )

#define real4_1		float4_1	// ( +1, +1, +1, +1 )
#define real4_0		float4_0	// (  0,  0,  0,  0 )
#define real4_1n	float4_1n	// ( -1, -1, -1, -1 )
#define real4_x		float4_x	// ( +1,  0,  0,  0 )
#define real4_y		float4_y	// (  0, +1,  0,  0 )
#define real4_z		float4_z	// (  0,  0, +1,  0 )
#define real4_w		float4_w	// (  0,  0,  0, +1 )
#define real4_xn	float4_xn	// ( -1,  0,  0,  0 )
#define real4_yn	float4_yn	// (  0, -1,  0,  0 )
#define real4_zn	float4_zn	// (  0,  0, -1,  0 )
#define real4_wn	float4_wn	// (  0,  0,  0, -1 )

#define rvec2_1		fvec2_1		// ( +1, +1 )
#define rvec2_0		fvec2_0		// (  0,  0 )
#define rvec2_1n	fvec2_1n	// ( -1, -1 )
#define rvec2_x		fvec2_x		// ( +1,  0 )
#define rvec2_y		fvec2_y		// (  0, +1 )
#define rvec2_xn	fvec2_xn	// ( -1,  0 )
#define rvec2_yn	fvec2_yn	// (  0, -1 )

#define rvec3_1		fvec3_1		// ( +1, +1, +1 )
#define rvec3_0		fvec3_0		// (  0,  0,  0 )
#define rvec3_1n	fvec3_1n	// ( -1, -1, -1 )
#define rvec3_x		fvec3_x		// ( +1,  0,  0 )
#define rvec3_y		fvec3_y		// (  0, +1,  0 )
#define rvec3_z		fvec3_z		// (  0,  0, +1 )
#define rvec3_xn	fvec3_xn	// ( -1,  0,  0 )
#define rvec3_yn	fvec3_yn	// (  0, -1,  0 )
#define rvec3_zn	fvec3_zn	// (  0,  0, -1 )

#define rvec4_1		fvec4_1		// ( +1, +1, +1, +1 )
#define rvec4_0		fvec4_0		// (  0,  0,  0,  0 )
#define rvec4_1n	fvec4_1n	// ( -1, -1, -1, -1 )
#define rvec4_x		fvec4_x		// ( +1,  0,  0,  0 )
#define rvec4_y		fvec4_y		// (  0, +1,  0,  0 )
#define rvec4_z		fvec4_z		// (  0,  0, +1,  0 )
#define rvec4_w		fvec4_w		// (  0,  0,  0, +1 )
#define rvec4_xn	fvec4_xn	// ( -1,  0,  0,  0 )
#define rvec4_yn	fvec4_yn	// (  0, -1,  0,  0 )
#define rvec4_zn	fvec4_zn	// (  0,  0, -1,  0 )
#define rvec4_wn	fvec4_wn	// (  0,  0,  0, -1 )

#endif	// IJK_REAL_DBL


//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_util/ijkVector_real.h"
#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_