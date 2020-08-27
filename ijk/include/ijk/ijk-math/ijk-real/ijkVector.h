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


#include "ijkVectorSwizzle.h"
#include "ijkTrigonometry.h"


#ifdef __cplusplus
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
#endif	// __cplusplus


//-----------------------------------------------------------------------------

typedef bool const		* boolkv;	// Generic constant boolean array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef bool			* boolv,	// Generic signed integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						bool2[2],	// 2D boolean array-based vector, always passed by pointer.
						bool3[3],	// 3D boolean array-based vector, always passed by pointer.
						bool4[4];	// 4D boolean array-based vector, always passed by pointer.

typedef int const		* intkv;	// Generic constant signed integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef int				* intv,		// Generic signed integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						int2[2],	// 2D signed integer array-based vector, always passed by pointer.
						int3[3],	// 3D signed integer array-based vector, always passed by pointer.
						int4[4];	// 4D signed integer array-based vector, always passed by pointer.


typedef uint const		* uintkv;	// Generic constant unsigned integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef uint			* uintv,	// Generic unsigned integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						uint2[2],	// 2D unsigned integer array-based vector, always passed by pointer.
						uint3[3],	// 3D unsigned integer array-based vector, always passed by pointer.
						uint4[4];	// 4D unsigned integer array-based vector, always passed by pointer.

typedef float const		* floatkv;	// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef float			* floatv,		// Generic float single-precision-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						float2[2],	// 2D single-precision array-based vector, always passed by pointer.
						float3[3],	// 3D single-precision array-based vector, always passed by pointer.
						float4[4];	// 4D single-precision array-based vector, always passed by pointer.

typedef double const	* doublekv;	// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef double			* doublev,	// Generic double-precision array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
						double2[2],	// 2D double-precision array-based vector, always passed by pointer.
						double3[3],	// 3D double-precision array-based vector, always passed by pointer.
						double4[4];	// 4D double-precision array-based vector, always passed by pointer.


//-----------------------------------------------------------------------------

// bvec2
//	Data structure representing 2D boolean vector.
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union bvec2
{
#ifdef __cplusplus
//	explicit bvec2(bool const& xy = false);			// Construct vector with all elements set to single scalar.
//	explicit bvec2(bool const& xc, bool const& yc);	// Construct vector with elements set individually.
#else // !__cplusplus
	IJK_BVEC_IMPL(2);
#endif	// __cplusplus
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
#ifdef __cplusplus
//	explicit bvec3(bool const& xyz = false);								// Construct vector with all elements set to single scalar.
//	explicit bvec3(bool const& xc, bool const& yc, bool const& zc = false);	// Construct vector with elements set individually.
#else // !__cplusplus
	IJK_BVEC_IMPL(3);
#endif	// __cplusplus
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
#ifdef __cplusplus
//	explicit bvec4(bool const& xyzw = false);														// Construct vector with all elements set to single scalar.
//	explicit bvec4(bool const& xc, bool const& yc, bool const& zc = false, bool const& wc = true);	// Construct vector with elements set individually.
#else // !__cplusplus
	IJK_BVEC_IMPL(4);
#endif	// __cplusplus
};


//-----------------------------------------------------------------------------

// ivec2
//	Data structure representing 2D signed integer vector.
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
#ifdef __cplusplus
/*	explicit ivec2(int const& xy = 0);				// Construct vector with all elements set to single scalar.
	explicit ivec2(int const& xc, int const& yc);	// Construct vector with elements set individually.
	explicit ivec2(int2 const xy);					// Construct vector given signed integer array-based vector.
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
*/
#else // !__cplusplus
	IJK_IVEC_IMPL(2);
#endif	// __cplusplus
};

// ivec3
//	Data structure representing 3D signed integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union ivec3
{
#ifdef __cplusplus
//	explicit ivec3(int const& xyz = 0);									// Construct vector with all elements set to single scalar.
//	explicit ivec3(int const& xc, int const& yc, int const& zc = 0);	// Construct vector with elements set individually.
#else // !__cplusplus
	IJK_IVEC_IMPL(3);
#endif	// __cplusplus
};

// ivec4
//	Data structure representing 4D signed integer vector.
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
#ifdef __cplusplus
//	explicit ivec4(int const& xyzw = 0);												// Construct vector with all elements set to single scalar.
//	explicit ivec4(int const& xc, int const& yc, int const& zc = 0, int const& wc = 1);	// Construct vector with elements set individually.
#else // !__cplusplus
	IJK_IVEC_IMPL(4);
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union uvec2
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_UVEC_IMPL(2);
#endif	// __cplusplus
};

// uvec3
//	Data structure representing 3D unsigned integer vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union uvec3
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_UVEC_IMPL(3);
#endif	// __cplusplus
};

// uvec4
//	Data structure representing 4D unsigned integer vector.
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
#ifdef __cplusplus

#else // !__cplusplus
	IJK_UVEC_IMPL(4);
#endif	// __cplusplus
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union vec2
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_FVEC_IMPL(2);
#endif	// __cplusplus
};

// vec3
//	Data structure representing 3D single-precision (float) vector.
//		members xyz, rgb, stp: array of elements, used as pointer argument to vector functions
//		members xy, rg, st: partial swizzle of first two elements, used in same fashion as above
//		members yz, gb, tp: partial swizzle of last two elements, used in same fashion as above
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union vec3
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_FVEC_IMPL(3);
#endif	// __cplusplus
};

// vec4
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
union vec4
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_FVEC_IMPL(4);
#endif	// __cplusplus
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
//		members xy, rg, st: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union dvec2
{
#ifdef __cplusplus

#else // !__cplusplus
	IJK_DVEC_IMPL(2);
#endif	// __cplusplus
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
#ifdef __cplusplus

#else // !__cplusplus
	IJK_DVEC_IMPL(3);
#endif	// __cplusplus
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
#ifdef __cplusplus

#else // !__cplusplus
	IJK_DVEC_IMPL(4);
#endif	// __cplusplus
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

// Alternative names for float vector.
///
typedef vec2 fvec2;
typedef vec3 fvec3;
typedef vec4 fvec4;

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