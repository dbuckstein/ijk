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
#else	// !__cplusplus
typedef union ivec2	ivec2;
typedef union ivec3	ivec3;
typedef union ivec4	ivec4;
typedef union fvec2	fvec2;
typedef union fvec3	fvec3;
typedef union fvec4	fvec4;
typedef union dvec2	dvec2;
typedef union dvec3	dvec3;
typedef union dvec4	dvec4;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// Reusable array-based vector types.
///
typedef i32
	int2[2],					// 2D integer array-based vector, always passed by pointer.
	int3[3],					// 3D integer array-based vector, always passed by pointer.
	int4[4],					// 4D integer array-based vector, always passed by pointer.
	* intv;						// Generic integer array-based vector, represented by pointer, used as vector return type since returning sized array is not allowed.
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

typedef i32 const* intkv;		// Generic constant integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef flt const* fltkv;		// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef dbl const* dblkv;		// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.


//-----------------------------------------------------------------------------

// Global constants for array-based vector types.
///


//-----------------------------------------------------------------------------

// ivec2
//	Data structure representing 2D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
union ivec2
{
	int2 v;
	struct { i32 x, y; };
};

// ivec3
//	Data structure representing 3D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
union ivec3
{
	int3 v;
	ivec2 xy;
	struct { i32 x, y, z; };
	struct { i32 r, g, b; };
};

// ivec4
//	Data structure representing 4D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
union ivec4
{
	int4 v;
	ivec3 xyz;
	ivec2 xy;
	struct { i32 x, y, z, w; };
	struct { i32 r, g, b, a; };
};


// fvec2
//	Data structure representing 2D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members s, t: individual named elements representing a parametric coordinate
union fvec2
{
	flt2 v;
	struct { flt x, y; };
	struct { flt s, t; };
};

// fvec3
//	Data structure representing 3D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z: individual named elements representing a spatial coordinate
//		members r, g, b: individual named elements representing a color
//		members s, t, p: individual named elements representing a parametric coordinate
union fvec3
{
	flt3 v;
	fvec2 xy;
	struct { flt x, y, z; };
	struct { flt r, g, b; };
	struct { flt s, t, p; };
};

// fvec4
//	Data structure representing 4D single-precision (float) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		member xyz: 3D vector of first three components, useful for direct assignment
//		member xy: 2D vector of first two components, useful for direct assignment
//		members x, y, z, w: individual named elements representing a spatial coordinate
//			note: vectors have w = 0, while points have w = 1
//		members r, g, b, a: individual named elements representing a color
//		members s, t, p, q: individual named elements representing a parametric coordinate
union fvec4
{
	flt4 v;
	fvec3 xyz;
	fvec2 xy;
	struct { flt x, y, z, w; };
	struct { flt r, g, b, a; };
	struct { flt s, t, p, q; };
};


// dvec2
//	Data structure representing 2D double-precision (double) vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
//		members s, t: individual named elements representing a parametric coordinate
union dvec2
{
	dbl2 v;
	struct { dbl x, y; };
	struct { dbl s, t; };
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
};


//-----------------------------------------------------------------------------

// Global constants for vector data structures.
///


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_