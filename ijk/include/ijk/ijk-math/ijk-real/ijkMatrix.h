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

	ijkMatrix.h
	Matrix types and functions.
*/

#ifndef _IJK_MATRIX_H_
#define _IJK_MATRIX_H_


#include "ijkVector.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef union fmat2		fmat2;
typedef union fmat3		fmat3;
typedef union fmat4		fmat4;
typedef union dmat2		dmat2;
typedef union dmat3		dmat3;
typedef union dmat4		dmat4;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

typedef f32				float9[9],		// 9-element single-precision array-based vector, always passed by pointer.
						float16[16];	// 16-element single-precision array-based vector, always passed by pointer.
typedef float2 const	* float2km;		// Generic constant 2D single-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef float2			* float2m,		// Generic 2D single-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						float2x2[2];	// 2D single-precision array-based matrix, always passed by pointer.
typedef float3 const	* float3km;		// Generic constant 3D single-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef float3			* float3m,		// Generic 3D single-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						float3x3[3];	// 3D single-precision array-based matrix, always passed by pointer.
typedef float4 const	* float4km;		// Generic constant 4D single-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef float4			* float4m,		// Generic 4D single-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						float4x4[4];	// 4D single-precision array-based matrix, always passed by pointer.


//-----------------------------------------------------------------------------

#ifdef __cplusplus

#else // !__cplusplus

// fmat2
//	Data structure representing 2D column-major float matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1: individual column vectors
//		members x0, y0, x1, y1: column vector components
//		members v0, v1, v2, v3: array vector components
//		members m00, m01, m10, m11: array matrix components
union fmat2
{
	float4 v;
	float2x2 m;
	fvec2 c[2];
	struct { fvec2 c0, c1; };
	struct { float x0, y0, x1, y1; };
	struct { float v0, v1, v2, v3; };
	struct { float m00, m01, m10, m11; };
};


#endif	// __cplusplus


//-----------------------------------------------------------------------------

// test C function
float2m ijkMatTest2fv(float2x2 m_out, float2x2 const m_in);
// test C function
float2m ijkMatTest2fvs(float2x2 m_out, float2x2 const m_lh, f32 const s_rh);

#ifdef __cplusplus
}
#endif	// __cplusplus





#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------
	
// Alternative names for float matrix.
///
typedef fmat2		mat2;
typedef fmat3		mat3;
typedef fmat4		mat4;

// Select real matrix types.
///


#ifdef IJK_REAL_DBL
typedef dmat2		rmat2;		// Real 2D matrix data structure type is 2D double matrix.
typedef dmat3		rmat3;		// Real 3D matrix data structure type is 3D double matrix.
typedef dmat4		rmat4;		// Real 4D matrix data structure type is 4D double matrix.
#else	// !IJK_REAL_DBL
typedef fmat2		rmat2;		// Real 2D matrix data structure type is 2D float matrix.
typedef fmat3		rmat3;		// Real 3D matrix data structure type is 3D float matrix.
typedef fmat4		rmat4;		// Real 4D matrix data structure type is 4D float matrix.
#endif	// IJK_REAL_DBL


//-----------------------------------------------------------------------------

// Global constants for 32-bit float array-based matrices and data structures.
///
ijk_ext float2x2 const float2x2_id;
ijk_ext float4 const float4_id;
ijk_ext fmat2 const fmat2_id;


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkMatrix.inl"


#endif	// !_IJK_MATRIX_H_