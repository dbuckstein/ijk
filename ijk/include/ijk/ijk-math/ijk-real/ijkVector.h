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


#include "_util/ijkVectorSwizzle.h"
#include "ijkTrigonometry.h"


#ifdef __cplusplus
extern "C" {

typedef ttvec2<bool>	bvec2;		// 2D boolean/byte vector
typedef ttvec3<bool>	bvec3;		// 3D boolean/byte vector
typedef ttvec4<bool>	bvec4;		// 4D boolean/byte vector

typedef ttvec2<i32>		ivec2;		// 2D signed 32-bit integer vector
typedef ttvec3<i32>		ivec3;		// 3D signed 32-bit integer vector
typedef ttvec4<i32>		ivec4;		// 4D signed 32-bit integer vector

typedef ttvec2<i64>		ilvec2;		// 2D signed 64-bit integer vector
typedef ttvec3<i64>		ilvec3;		// 3D signed 64-bit integer vector
typedef ttvec4<i64>		ilvec4;		// 4D signed 64-bit integer vector

typedef ttvec2<ui32>	uvec2;		// 2D unsigned 32-bit integer vector
typedef ttvec3<ui32>	uvec3;		// 3D unsigned 32-bit integer vector
typedef ttvec4<ui32>	uvec4;		// 4D unsigned 32-bit integer vector

typedef ttvec2<ui64>	ulvec2;		// 2D unsigned 64-bit integer vector
typedef ttvec3<ui64>	ulvec3;		// 3D unsigned 64-bit integer vector
typedef ttvec4<ui64>	ulvec4;		// 4D unsigned 64-bit integer vector

typedef ttvec2<f32>		fvec2;		// 2D single-precision floating point vector
typedef ttvec3<f32>		fvec3;		// 3D single-precision floating point vector
typedef ttvec4<f32>		fvec4;		// 4D single-precision floating point vector

typedef ttvec2<f64>		dvec2;		// 2D double-precision floating point vector
typedef ttvec3<f64>		dvec3;		// 3D double-precision floating point vector
typedef ttvec4<f64>		dvec4;		// 4D double-precision floating point vector

// Built-in type overrides.
///
#define bool			ttvec1<bool>	// sizeof(bool) = 1; does not align with GLSL
#define int				ttvec1<i32>
#define intl			ttvec1<i64>		// sizeof(intl) = 8; does not align with GLSL
#define uint			ttvec1<ui32>
#define uintl			ttvec1<ui64>	// sizeof(uintl) = 8; does not align with GLSL
#define float			ttvec1<f32>
#define double			ttvec1<f64>

#else	// !__cplusplus
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
#define IJK_BVEC_IMPL(vecSize)			IJK_VEC_IMPL(bool,vecSize)
#define IJK_IVEC_IMPL(vecSize)			IJK_VEC_IMPL(int,vecSize)
#define IJK_ILVEC_IMPL(vecSize)			IJK_VEC_IMPL(intl,vecSize)
#define IJK_UVEC_IMPL(vecSize)			IJK_VEC_IMPL(uint,vecSize)
#define IJK_ULVEC_IMPL(vecSize)			IJK_VEC_IMPL(uintl,vecSize)
#define IJK_FVEC_IMPL(vecSize)			IJK_VEC_IMPL(float,vecSize)
#define IJK_DVEC_IMPL(vecSize)			IJK_VEC_IMPL(double,vecSize)

#endif	// __cplusplus


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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union bvec2
{
	IJK_BVEC_IMPL(2);
};

// bvec3
//	Data structure representing 3D boolean vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union bvec3
{
	IJK_BVEC_IMPL(3);
};

// bvec4
//	Data structure representing 4D boolean vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
	IJK_IVEC_IMPL(2);
};

// ivec3
//	Data structure representing 3D signed 32-bit integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ivec3
{
	IJK_IVEC_IMPL(3);
};

// ivec4
//	Data structure representing 4D signed 32-bit integer vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ilvec2
{
	IJK_ILVEC_IMPL(2);
};

// ilvec3
//	Data structure representing 3D signed 64-bit integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ilvec3
{
	IJK_ILVEC_IMPL(3);
};

// ilvec4
//	Data structure representing 4D signed 64-bit integer vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union uvec2
{
	IJK_UVEC_IMPL(2);
};

// uvec3
//	Data structure representing 3D unsigned 32-bit integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union uvec3
{
	IJK_UVEC_IMPL(3);
};

// uvec4
//	Data structure representing 4D unsigned 32-bit integer vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ulvec2
{
	IJK_ULVEC_IMPL(2);
};

// ulvec3
//	Data structure representing 3D unsigned 64-bit integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ulvec3
{
	IJK_ULVEC_IMPL(3);
};

// ulvec4
//	Data structure representing 4D unsigned 64-bit integer vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union fvec2
{
	IJK_FVEC_IMPL(2);
};

// fvec3
//	Data structure representing 3D single-precision (float) vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union fvec3
{
	IJK_FVEC_IMPL(3);
};

// fvec4
//	Data structure representing 4D single-precision (float) vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union dvec2
{
	IJK_DVEC_IMPL(2);
};

// dvec3
//	Data structure representing 3D double-precision (double) vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union dvec3
{
	IJK_DVEC_IMPL(3);
};

// dvec4
//	Data structure representing 4D double-precision (double) vector.
//		members xyzw, rgba, stpq: array of elements, used as pointer argument to vector functions
//		members xyz, rgb, stp: partial swizzle of first three elements, used in same fashion as above
//		members yzw, gba, tpq: partial swizzle of last three elements, used in same fashion as above
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of middle two elements, used in same fashion as above
//		members zw, ba, pq: partial swizzle of last two elements, used in same fashion as above
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

// Alternative names for float vector.
///
typedef fvec2		vec2;
typedef fvec3		vec3;
typedef fvec4		vec4;

// Select real vector types.
///
typedef real const	* realkv;	// Generic constant real-type array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real		* realv,	// Generic real-type array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
					real2[2],	// 2D real-type array-based vector, always passed by pointer.
					real3[3],	// 3D real-type array-based vector, always passed by pointer.
					real4[4];	// 4D real-type array-based vector, always passed by pointer.

#ifdef IJK_REAL_DBL
typedef dvec2		rvec2;		// Real 2D vector data structure type is 2D double vector.
typedef dvec3		rvec3;		// Real 3D vector data structure type is 3D double vector.
typedef dvec4		rvec4;		// Real 4D vector data structure type is 4D double vector.
#else	// !IJK_REAL_DBL
typedef fvec2		rvec2;		// Real 2D vector data structure type is 2D float vector.
typedef fvec3		rvec3;		// Real 3D vector data structure type is 3D float vector.
typedef fvec4		rvec4;		// Real 4D vector data structure type is 4D float vector.
#endif	// IJK_REAL_DBL


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

// Global constants for signed 64-bit integer array-based vectors and data structures.
///
ijk_ext int2 const intl2_one;		// ( +1, +1 )
ijk_ext int2 const intl2_zero;		// (  0,  0 )
ijk_ext int2 const intl2_one_n;		// ( -1, -1 )
ijk_ext int2 const intl2_x;			// ( +1,  0 )
ijk_ext int2 const intl2_y;			// (  0, +1 )
ijk_ext int2 const intl2_x_n;		// ( -1,  0 )
ijk_ext int2 const intl2_y_n;		// (  0, -1 )

ijk_ext int3 const intl3_one;		// ( +1, +1, +1 )
ijk_ext int3 const intl3_zero;		// (  0,  0,  0 )
ijk_ext int3 const intl3_one_n;		// ( -1, -1, -1 )
ijk_ext int3 const intl3_x;			// ( +1,  0,  0 )
ijk_ext int3 const intl3_y;			// (  0, +1,  0 )
ijk_ext int3 const intl3_z;			// (  0,  0, +1 )
ijk_ext int3 const intl3_x_n;		// ( -1,  0,  0 )
ijk_ext int3 const intl3_y_n;		// (  0, -1,  0 )
ijk_ext int3 const intl3_z_n;		// (  0,  0, -1 )

ijk_ext int4 const intl4_one;		// ( +1, +1, +1, +1 )
ijk_ext int4 const intl4_zero;		// (  0,  0,  0,  0 )
ijk_ext int4 const intl4_one_n;		// ( -1, -1, -1, -1 )
ijk_ext int4 const intl4_x;			// ( +1,  0,  0,  0 )
ijk_ext int4 const intl4_y;			// (  0, +1,  0,  0 )
ijk_ext int4 const intl4_z;			// (  0,  0, +1,  0 )
ijk_ext int4 const intl4_w;			// (  0,  0,  0, +1 )
ijk_ext int4 const intl4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext int4 const intl4_y_n;		// (  0, -1,  0,  0 )
ijk_ext int4 const intl4_z_n;		// (  0,  0, -1,  0 )
ijk_ext int4 const intl4_w_n;		// (  0,  0,  0, -1 )

ijk_ext ivec2 const ivecl2_one;		// ( +1, +1 )
ijk_ext ivec2 const ivecl2_zero;	// (  0,  0 )
ijk_ext ivec2 const ivecl2_one_n;	// ( -1, -1 )
ijk_ext ivec2 const ivecl2_x;		// ( +1,  0 )
ijk_ext ivec2 const ivecl2_y;		// (  0, +1 )
ijk_ext ivec2 const ivecl2_x_n;		// ( -1,  0 )
ijk_ext ivec2 const ivecl2_y_n;		// (  0, -1 )

ijk_ext ivec3 const ivecl3_one;		// ( +1, +1, +1 )
ijk_ext ivec3 const ivecl3_zero;	// (  0,  0,  0 )
ijk_ext ivec3 const ivecl3_one_n;	// ( -1, -1, -1 )
ijk_ext ivec3 const ivecl3_x;		// ( +1,  0,  0 )
ijk_ext ivec3 const ivecl3_y;		// (  0, +1,  0 )
ijk_ext ivec3 const ivecl3_z;		// (  0,  0, +1 )
ijk_ext ivec3 const ivecl3_x_n;		// ( -1,  0,  0 )
ijk_ext ivec3 const ivecl3_y_n;		// (  0, -1,  0 )
ijk_ext ivec3 const ivecl3_z_n;		// (  0,  0, -1 )

ijk_ext ivec4 const ivecl4_one;		// ( +1, +1, +1, +1 )
ijk_ext ivec4 const ivecl4_zero;	// (  0,  0,  0,  0 )
ijk_ext ivec4 const ivecl4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext ivec4 const ivecl4_x;		// ( +1,  0,  0,  0 )
ijk_ext ivec4 const ivecl4_y;		// (  0, +1,  0,  0 )
ijk_ext ivec4 const ivecl4_z;		// (  0,  0, +1,  0 )
ijk_ext ivec4 const ivecl4_w;		// (  0,  0,  0, +1 )
ijk_ext ivec4 const ivecl4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext ivec4 const ivecl4_y_n;		// (  0, -1,  0,  0 )
ijk_ext ivec4 const ivecl4_z_n;		// (  0,  0, -1,  0 )
ijk_ext ivec4 const ivecl4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

// Global constants for unsigned 32-bit integer array-based vectors and data structures.
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

// Global constants for unsigned 64-bit integer array-based vectors and data structures.
// Note: negatives are represented as maximum unsigned value.
///
ijk_ext uint2 const uintl2_one;		// ( +1, +1 )
ijk_ext uint2 const uintl2_zero;	// (  0,  0 )
ijk_ext uint2 const uintl2_one_n;	// ( -1, -1 )
ijk_ext uint2 const uintl2_x;		// ( +1,  0 )
ijk_ext uint2 const uintl2_y;		// (  0, +1 )
ijk_ext uint2 const uintl2_x_n;		// ( -1,  0 )
ijk_ext uint2 const uintl2_y_n;		// (  0, -1 )

ijk_ext uint3 const uintl3_one;		// ( +1, +1, +1 )
ijk_ext uint3 const uintl3_zero;	// (  0,  0,  0 )
ijk_ext uint3 const uintl3_one_n;	// ( -1, -1, -1 )
ijk_ext uint3 const uintl3_x;		// ( +1,  0,  0 )
ijk_ext uint3 const uintl3_y;		// (  0, +1,  0 )
ijk_ext uint3 const uintl3_z;		// (  0,  0, +1 )
ijk_ext uint3 const uintl3_x_n;		// ( -1,  0,  0 )
ijk_ext uint3 const uintl3_y_n;		// (  0, -1,  0 )
ijk_ext uint3 const uintl3_z_n;		// (  0,  0, -1 )

ijk_ext uint4 const uintl4_one;		// ( +1, +1, +1, +1 )
ijk_ext uint4 const uintl4_zero;	// (  0,  0,  0,  0 )
ijk_ext uint4 const uintl4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext uint4 const uintl4_x;		// ( +1,  0,  0,  0 )
ijk_ext uint4 const uintl4_y;		// (  0, +1,  0,  0 )
ijk_ext uint4 const uintl4_z;		// (  0,  0, +1,  0 )
ijk_ext uint4 const uintl4_w;		// (  0,  0,  0, +1 )
ijk_ext uint4 const uintl4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext uint4 const uintl4_y_n;		// (  0, -1,  0,  0 )
ijk_ext uint4 const uintl4_z_n;		// (  0,  0, -1,  0 )
ijk_ext uint4 const uintl4_w_n;		// (  0,  0,  0, -1 )

ijk_ext uvec2 const uvecl2_one;		// ( +1, +1 )
ijk_ext uvec2 const uvecl2_zero;	// (  0,  0 )
ijk_ext uvec2 const uvecl2_one_n;	// ( -1, -1 )
ijk_ext uvec2 const uvecl2_x;		// ( +1,  0 )
ijk_ext uvec2 const uvecl2_y;		// (  0, +1 )
ijk_ext uvec2 const uvecl2_x_n;		// ( -1,  0 )
ijk_ext uvec2 const uvecl2_y_n;		// (  0, -1 )

ijk_ext uvec3 const uvecl3_one;		// ( +1, +1, +1 )
ijk_ext uvec3 const uvecl3_zero;	// (  0,  0,  0 )
ijk_ext uvec3 const uvecl3_one_n;	// ( -1, -1, -1 )
ijk_ext uvec3 const uvecl3_x;		// ( +1,  0,  0 )
ijk_ext uvec3 const uvecl3_y;		// (  0, +1,  0 )
ijk_ext uvec3 const uvecl3_z;		// (  0,  0, +1 )
ijk_ext uvec3 const uvecl3_x_n;		// ( -1,  0,  0 )
ijk_ext uvec3 const uvecl3_y_n;		// (  0, -1,  0 )
ijk_ext uvec3 const uvecl3_z_n;		// (  0,  0, -1 )

ijk_ext uvec4 const uvecl4_one;		// ( +1, +1, +1, +1 )
ijk_ext uvec4 const uvecl4_zero;	// (  0,  0,  0,  0 )
ijk_ext uvec4 const uvecl4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext uvec4 const uvecl4_x;		// ( +1,  0,  0,  0 )
ijk_ext uvec4 const uvecl4_y;		// (  0, +1,  0,  0 )
ijk_ext uvec4 const uvecl4_z;		// (  0,  0, +1,  0 )
ijk_ext uvec4 const uvecl4_w;		// (  0,  0,  0, +1 )
ijk_ext uvec4 const uvecl4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext uvec4 const uvecl4_y_n;		// (  0, -1,  0,  0 )
ijk_ext uvec4 const uvecl4_z_n;		// (  0,  0, -1,  0 )
ijk_ext uvec4 const uvecl4_w_n;		// (  0,  0,  0, -1 )


//-----------------------------------------------------------------------------

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

ijk_ext fvec2 const fvec2_one;		// ( +1, +1 )
ijk_ext fvec2 const fvec2_zero;		// (  0,  0 )
ijk_ext fvec2 const fvec2_one_n;	// ( -1, -1 )
ijk_ext fvec2 const fvec2_x;		// ( +1,  0 )
ijk_ext fvec2 const fvec2_y;		// (  0, +1 )
ijk_ext fvec2 const fvec2_x_n;		// ( -1,  0 )
ijk_ext fvec2 const fvec2_y_n;		// (  0, -1 )

ijk_ext fvec3 const fvec3_one;		// ( +1, +1, +1 )
ijk_ext fvec3 const fvec3_zero;		// (  0,  0,  0 )
ijk_ext fvec3 const fvec3_one_n;	// ( -1, -1, -1 )
ijk_ext fvec3 const fvec3_x;		// ( +1,  0,  0 )
ijk_ext fvec3 const fvec3_y;		// (  0, +1,  0 )
ijk_ext fvec3 const fvec3_z;		// (  0,  0, +1 )
ijk_ext fvec3 const fvec3_x_n;		// ( -1,  0,  0 )
ijk_ext fvec3 const fvec3_y_n;		// (  0, -1,  0 )
ijk_ext fvec3 const fvec3_z_n;		// (  0,  0, -1 )

ijk_ext fvec4 const fvec4_one;		// ( +1, +1, +1, +1 )
ijk_ext fvec4 const fvec4_zero;		// (  0,  0,  0,  0 )
ijk_ext fvec4 const fvec4_one_n;	// ( -1, -1, -1, -1 )
ijk_ext fvec4 const fvec4_x;		// ( +1,  0,  0,  0 )
ijk_ext fvec4 const fvec4_y;		// (  0, +1,  0,  0 )
ijk_ext fvec4 const fvec4_z;		// (  0,  0, +1,  0 )
ijk_ext fvec4 const fvec4_w;		// (  0,  0,  0, +1 )
ijk_ext fvec4 const fvec4_x_n;		// ( -1,  0,  0,  0 )
ijk_ext fvec4 const fvec4_y_n;		// (  0, -1,  0,  0 )
ijk_ext fvec4 const fvec4_z_n;		// (  0,  0, -1,  0 )
ijk_ext fvec4 const fvec4_w_n;		// (  0,  0,  0, -1 )

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

// bool2init
//	Initialize 2D boolean vector.
//		param v_out: output vector
//		params x, y: initialization values
//		return: v_out
boolv bool2init(bool2 v_out, bool const x, bool const y);

// isEqual2bv
//	Equality comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// isInequal2bv
//	Inequality comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// isEqual2bvs
//	Equality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isEqual2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// isInequal2bvs
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isInequal2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// isEqual2bsv
//	Equality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);

// isInequal2bsv
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);


//-----------------------------------------------------------------------------

// bool3init
//	Initialize 3D boolean vector.
//		param v_out: output vector
//		params x, y, z: initialization values
//		return: v_out
boolv bool3init(bool3 v_out, bool const x, bool const y, bool const z);

// isEqual3bv
//	Equality comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// isInequal3bv
//	Inequality comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// isEqual3bvs
//	Equality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isEqual3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// isInequal3bvs
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isInequal3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// isEqual3bsv
//	Equality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);

// isInequal3bsv
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);


//-----------------------------------------------------------------------------

// bool4init
//	Initialize 4D boolean vector.
//		param v_out: output vector
//		params x, y, z, w: initialization values
//		return: v_out
boolv bool4init(bool3 v_out, bool const x, bool const y, bool const z, bool const w);

// isEqual4bv
//	Equality comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// isInequal4bv
//	Inequality comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// isEqual4bvs
//	Equality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isEqual4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// isInequal4bvs
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv isInequal4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// isEqual4bsv
//	Equality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isEqual4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);

// isInequal4bsv
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv isInequal4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// bvec2new
//	Construct new 2D boolean vector.
//		params x, y: initialization values
//		return: output vector
bvec2 bvec2new(bool const x, bool const y);

// isEqual2b
//	Equality comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec2 isEqual2b(bvec2 const v_lh, bvec2 const v_rh);

// isInequal2b
//	Inequality comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec2 isInequal2b(bvec2 const v_lh, bvec2 const v_rh);

// isEqual2bvs
//	Equality comparison for 2D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec2 isEqual2bs(bvec2 const v_lh, bool const s_rh);

// isInequal2bvs
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec2 isInequal2bs(bvec2 const v_lh, bool const s_rh);

// isEqual2bsv
//	Equality comparison for 2D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec2 isEqual2sb(bool const s_lh, bvec2 const v_rh);

// isInequal2bsv
//	Inequality comparison for 2D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec2 isInequal2sb(bool const s_lh, bvec2 const v_rh);


//-----------------------------------------------------------------------------

// bvec3new
//	Construct new 3D boolean vector.
//		params x, y, z: initialization values
//		return: output vector
bvec3 bvec3new(bool const x, bool const y, bool const z);

// isEqual3b
//	Equality comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec3 isEqual3b(bvec3 const v_lh, bvec3 const v_rh);

// isInequal3b
//	Inequality comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec3 isInequal3b(bvec3 const v_lh, bvec3 const v_rh);

// isEqual3bvs
//	Equality comparison for 3D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec3 isEqual3bs(bvec3 const v_lh, bool const s_rh);

// isInequal3bvs
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec3 isInequal3bs(bvec3 const v_lh, bool const s_rh);

// isEqual3bsv
//	Equality comparison for 3D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec3 isEqual3sb(bool const s_lh, bvec3 const v_rh);

// isInequal3bsv
//	Inequality comparison for 3D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec3 isInequal3sb(bool const s_lh, bvec3 const v_rh);


//-----------------------------------------------------------------------------

// bvec4new
//	Construct new 4D boolean vector.
//		params x, y, z, w: initialization values
//		return: output vector
bvec4 bvec4new(bool const x, bool const y, bool const z, bool const w);

// isEqual4b
//	Equality comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec4 isEqual4b(bvec4 const v_lh, bvec4 const v_rh);

// isInequal4b
//	Inequality comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec4 isInequal4b(bvec4 const v_lh, bvec4 const v_rh);

// isEqual4bvs
//	Equality comparison for 4D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec4 isEqual4bs(bvec4 const v_lh, bool const s_rh);

// isInequal4bvs
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: output vector holding boolean result of comparison
bvec4 isInequal4bs(bvec4 const v_lh, bool const s_rh);

// isEqual4bsv
//	Equality comparison for 4D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec4 isEqual4sb(bool const s_lh, bvec4 const v_rh);

// isInequal4bsv
//	Inequality comparison for 4D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: output vector holding boolean result of comparison
bvec4 isInequal4sb(bool const s_lh, bvec4 const v_rh);


//-----------------------------------------------------------------------------

#define IJK_VECTORFUNC_PREFIX	i
#define IJK_VECTORFUNC_TYPE		i32
#define IJK_VECTORFUNC_TVEC		int
#define IJK_VECTORFUNC_TYPEKV	intkv
#define IJK_VECTORFUNC_TYPEV	intv
#define IJK_VECTORFUNC_TYPE2	int2
#define IJK_VECTORFUNC_TYPE3	int3
#define IJK_VECTORFUNC_TYPE4	int4
#include "_util/ijkVectorFunc.h"

#define IJK_VECTORFUNC_PREFIX	il
#define IJK_VECTORFUNC_TYPE		i64
#define IJK_VECTORFUNC_TVEC		intl
#define IJK_VECTORFUNC_TYPEKV	intlkv
#define IJK_VECTORFUNC_TYPEV	intlv
#define IJK_VECTORFUNC_TYPE2	intl2
#define IJK_VECTORFUNC_TYPE3	intl3
#define IJK_VECTORFUNC_TYPE4	intl4
#include "_util/ijkVectorFunc.h"

#define IJK_VECTORFUNC_PREFIX	u
#define IJK_VECTORFUNC_TYPE		ui32
#define IJK_VECTORFUNC_TVEC		uint
#define IJK_VECTORFUNC_TYPEKV	uintkv
#define IJK_VECTORFUNC_TYPEV	uintv
#define IJK_VECTORFUNC_TYPE2	uint2
#define IJK_VECTORFUNC_TYPE3	uint3
#define IJK_VECTORFUNC_TYPE4	uint4
#include "_util/ijkVectorFunc.h"

#define IJK_VECTORFUNC_PREFIX	ul
#define IJK_VECTORFUNC_TYPE		ui64
#define IJK_VECTORFUNC_TVEC		uintl
#define IJK_VECTORFUNC_TYPEKV	uintlkv
#define IJK_VECTORFUNC_TYPEV	uintlv
#define IJK_VECTORFUNC_TYPE2	uintl2
#define IJK_VECTORFUNC_TYPE3	uintl3
#define IJK_VECTORFUNC_TYPE4	uintl4
#include "_util/ijkVectorFunc.h"

#define IJK_VECTORFUNC_PREFIX	f
#define IJK_VECTORFUNC_TYPE		f32
#define IJK_VECTORFUNC_TVEC		float
#define IJK_VECTORFUNC_TYPEKV	floatkv
#define IJK_VECTORFUNC_TYPEV	floatv
#define IJK_VECTORFUNC_TYPE2	float2
#define IJK_VECTORFUNC_TYPE3	float3
#define IJK_VECTORFUNC_TYPE4	float4
#include "_util/ijkVectorFunc.h"

#define IJK_VECTORFUNC_PREFIX	d
#define IJK_VECTORFUNC_TYPE		f64
#define IJK_VECTORFUNC_TVEC		double
#define IJK_VECTORFUNC_TYPEKV	doublekv
#define IJK_VECTORFUNC_TYPEV	doublev
#define IJK_VECTORFUNC_TYPE2	double2
#define IJK_VECTORFUNC_TYPE3	double3
#define IJK_VECTORFUNC_TYPE4	double4
#include "_util/ijkVectorFunc.h"


//-----------------------------------------------------------------------------


#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_