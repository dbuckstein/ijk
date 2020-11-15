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
typedef enum ijkRotationOrder	ijkRotationOrder;
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

typedef f64				double9[9],		// 9-element double-precision array-based vector, always passed by pointer.
						double16[16];	// 16-element double-precision array-based vector, always passed by pointer.
typedef double2 const	* double2km;	// Generic constant 2D double-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef double2			* double2m,		// Generic 2D double-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						double2x2[2];	// 2D double-precision array-based matrix, always passed by pointer.
typedef double3 const	* double3km;	// Generic constant 3D double-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef double3			* double3m,		// Generic 3D double-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						double3x3[3];	// 3D double-precision array-based matrix, always passed by pointer.
typedef double4 const	* double4km;	// Generic constant 4D double-precision array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef double4			* double4m,		// Generic 4D double-precision-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						double4x4[4];	// 4D double-precision array-based matrix, always passed by pointer.


//-----------------------------------------------------------------------------

// ijkRotationOrder
//	Tait-Bryan or "Euler" angles (Euler angles actually only use two axes with 
//	one repeated, e.g. 'XZX') written order when used to encode and decode 
//	rotations. Note that in right-handed systems, the order of operations is 
//	right-to-left (e.g. if the selected written order is XYZ, the individual 
//	rotations occur in the functional order Z then Y then X).
enum ijkRotationOrder
{
	ijkRotationXYZ,
	ijkRotationYZX,
	ijkRotationZXY,
	ijkRotationYXZ,
	ijkRotationXZY,
	ijkRotationZYX,
};


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
//		members v00, v01, v02, v03: array vector components
//		members m00, m01, m10, m11: array matrix components
union fmat2
{
	float4 v;
	float2x2 m;
	fvec2 c[2];
	struct { fvec2 c0, c1; };
	struct { float x0, y0, x1, y1; };
	struct { float v00, v01, v02, v03; };
	struct { float m00, m01, m10, m11; };
};

// fmat3
//	Data structure representing 3D column-major float matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1, c2: individual column vectors
//		members x0, y0, z0, x1, y1, z1, x2, y2, z2: column vector components
//		members v00, v01, v02, v03, v04, v05, v06, v07, v08: array vector components
//		members m00, m01, m02, m10, m11, m12, m20, m21, m22: array matrix components
union fmat3
{
	float9 v;
	float3x3 m;
	fvec3 c[3];
	struct { fvec3 c0, c1, c2; };
	struct { float x0, y0, z0, x1, y1, z1, x2, y2, z2; };
	struct { float v00, v01, v02, v03, v04, v05, v06, v07, v08; };
	struct { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
};

// fmat4
//	Data structure representing 4D column-major float matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1, c2: individual column vectors
//		members x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3: column vector components
//		members v00, v01, v02, v03, v04, v05, v06, v07, v08, v09, v10, v11, v12, v13, v14, v15: array vector components
//		members m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33: array matrix components
union fmat4
{
	float16 v;
	float4x4 m;
	fvec4 c[4];
	struct { fvec4 c0, c1, c2, c3; };
	struct { float x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3; };
	struct { float v00, v01, v02, v03, v04, v05, v06, v07, v08, v09, v10, v11, v12, v13, v14, v15; };
	struct { float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; };
};


//-----------------------------------------------------------------------------

// dmat2
//	Data structure representing 2D column-major double matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1: individual column vectors
//		members x0, y0, x1, y1: column vector components
//		members v00, v01, v02, v03: array vector components
//		members m00, m01, m10, m11: array matrix components
union dmat2
{
	double4 v;
	double2x2 m;
	dvec2 c[2];
	struct { dvec2 c0, c1; };
	struct { double x0, y0, x1, y1; };
	struct { double v00, v01, v02, v03; };
	struct { double m00, m01, m10, m11; };
};

// dmat3
//	Data structure representing 3D column-major double matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1, c2: individual column vectors
//		members x0, y0, z0, x1, y1, z1, x2, y2, z2: column vector components
//		members v00, v01, v02, v03, v04, v05, v06, v07, v08: array vector components
//		members m00, m01, m02, m10, m11, m12, m20, m21, m22: array matrix components
union dmat3
{
	double9 v;
	double3x3 m;
	dvec3 c[3];
	struct { dvec3 c0, c1, c2; };
	struct { double x0, y0, z0, x1, y1, z1, x2, y2, z2; };
	struct { double v00, v01, v02, v03, v04, v05, v06, v07, v08; };
	struct { double m00, m01, m02, m10, m11, m12, m20, m21, m22; };
};

// dmat4
//	Data structure representing 4D column-major double matrix.
//		member v: single-dimensional array of elements (vector format)
//		member m: multi-dimensional array of elements (matrix format)
//		member c: array of column vectors
//		members c0, c1, c2: individual column vectors
//		members x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3: column vector components
//		members v00, v01, v02, v03, v04, v05, v06, v07, v08, v09, v10, v11, v12, v13, v14, v15: array vector components
//		members m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33: array matrix components
union dmat4
{
	double16 v;
	double4x4 m;
	dvec4 c[4];
	struct { dvec4 c0, c1, c2, c3; };
	struct { double x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3; };
	struct { double v00, v01, v02, v03, v04, v05, v06, v07, v08, v09, v10, v11, v12, v13, v14, v15; };
	struct { double m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; };
};


#endif	// __cplusplus


//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_util/ijkMatrixSwizzle.h"
#include "_util/ijkMatrix_float.h"
#include "_util/ijkMatrix_double.h"


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
typedef real			real9[9],		// 9-element real array-based vector, always passed by pointer.
						real16[16];		// 16-element real array-based vector, always passed by pointer.
typedef real2 const		* real2km;		// Generic constant 2D real array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real2			* real2m,		// Generic 2D real-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						real2x2[2];		// 2D real array-based matrix, always passed by pointer.
typedef real3 const		* real3km;		// Generic constant 3D real array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real3			* real3m,		// Generic 3D real-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						real3x3[3];		// 3D real array-based matrix, always passed by pointer.
typedef real4 const		* real4km;		// Generic constant 4D real array-based matrix, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef real4			* real4m,		// Generic 4D real-based matrix, represented by pointer, used as vector return type since returning sized array is not allowed.
						real4x4[4];		// 4D real array-based matrix, always passed by pointer.

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
ijk_ext mat2 const mat2_id;

ijk_ext float3x3 const float3x3_id;
ijk_ext float9 const float9_id;
ijk_ext fmat3 const fmat3_id;
ijk_ext mat3 const mat3_id;

ijk_ext float4x4 const float4x4_id;
ijk_ext float16 const float16_id;
ijk_ext fmat4 const fmat4_id;
ijk_ext mat4 const mat4_id;


//-----------------------------------------------------------------------------

// Global constants for 64-bit float (double) array-based matrices and data structures.
///
ijk_ext double2x2 const double2x2_id;
ijk_ext double4 const double4_id;
ijk_ext dmat2 const dmat2_id;

ijk_ext double3x3 const double3x3_id;
ijk_ext double9 const double9_id;
ijk_ext dmat3 const dmat3_id;

ijk_ext double4x4 const double4x4_id;
ijk_ext double16 const double16_id;
ijk_ext dmat4 const dmat4_id;


//-----------------------------------------------------------------------------

// Global constants for real array-based matrices and data structures.
///
ijk_ext real2x2 const real2x2_id;
ijk_ext real4 const real4_id;
ijk_ext rmat2 const rmat2_id;

ijk_ext real3x3 const real3x3_id;
ijk_ext real9 const real9_id;
ijk_ext rmat3 const rmat3_id;

ijk_ext real4x4 const real4x4_id;
ijk_ext real16 const real16_id;
ijk_ext rmat4 const rmat4_id;


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkMatrix.inl"


#endif	// !_IJK_MATRIX_H_