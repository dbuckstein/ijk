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

	ijkQuaternion.h
	Quaternion types and functions.
*/

#ifndef _IJK_QUATERNION_H_
#define _IJK_QUATERNION_H_


#include "ijkMatrix.h"


#ifdef __cplusplus
extern "C" {
#else	// !__cplusplus
typedef union fquat		fquat;
typedef union fdualquat	fdualquat;
typedef union dquat		dquat;
typedef union ddualquat	ddualquat;
#endif	// __cplusplus


//-----------------------------------------------------------------------------

typedef f32				float8[8];		// 8-element single-precision array-based vector, always passed by pointer.
typedef float4			float2x4[2];	// 2x4 (2c x 4r) single-precision array-based quaternion, always passed by pointer.

typedef f64				double8[8];		// 8-element double-precision array-based vector, always passed by pointer.
typedef double4			double2x4[2];	// 2x4 (2c x 4r) double-precision array-based quaternion, always passed by pointer.


//-----------------------------------------------------------------------------

#ifdef __cplusplus

#else // !__cplusplus

// fquat
//	Data structure representing float quaternion.
//		member v: vector array-based data
//		members vec, re: vector and real components
//		members x, y, z, w: individual components
union fquat
{
	float4 v;
	struct { float3 vec; f32 re; };
	struct { f32 x, y, z, w; };
};

// dquat
//	Data structure representing double quaternion.
//		member v: vector array-based data
//		members vec, re: vector and real components
//		members x, y, z, w: individual components
union dquat
{
	double4 v;
	struct { double3 vec; f64 re; };
	struct { f64 x, y, z, w; };
};

// fdualquat
//	Data structure representing float dual quaternion.
//		member v: vector array-based data
//		member m: matrix array-based data
//		member q: quaternion components
//		members qr, qd: real and dual quaternion components
union fdualquat
{
	float8 v;
	float2x4 m;
	fquat q[2];
	struct { fquat qr, qd; };
};

// ddualquat
//	Data structure representing double dual quaternion.
//		member v: vector array-based data
//		member m: matrix array-based data
//		member q: quaternion components
//		members qr, qd: real and dual quaternion components
union ddualquat
{
	double8 v;
	double2x4 m;
	dquat q[2];
	struct { dquat qr, qd; };
};


#endif	// __cplusplus


//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_util/ijkQuaternionSwizzle.h"
#include "_util/ijkQuaternion_float.h"
#include "_util/ijkQuaternion_double.h"


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus


//-----------------------------------------------------------------------------
	
// Alternative names for float quaternion.
///
typedef fquat		quat;			// Alias for float quaternion.
typedef fdualquat	dualquat;		// Alias for float dual quaternion.

// Global constants for 32-bit float array-based quaternions and data structures.
///
ijk_ext float4 const float4q_id;		// (0, 0, 0, 1)
ijk_ext fquat const fquat_id;			// (0, 0, 0, 1)
ijk_ext quat const quat_id;				// (0, 0, 0, 1)

ijk_ext float2x4 const float2x4_id;		// (0, 0, 0, 1; 0, 0, 0, 0)
ijk_ext float8 const float8dq_id;		// (0, 0, 0, 1; 0, 0, 0, 0)
ijk_ext fdualquat const fdualquat_id;	// (0, 0, 0, 1; 0, 0, 0, 0)
ijk_ext dualquat const dualquat_id;		// (0, 0, 0, 1; 0, 0, 0, 0)


//-----------------------------------------------------------------------------

// Global constants for 64-bit float (double) array-based quaternions and data structures.
///
ijk_ext double4 const double4q_id;		// (0, 0, 0, 1)
ijk_ext dquat const dquat_id;			// (0, 0, 0, 1)

ijk_ext double2x4 const double2x4_id;	// (0, 0, 0, 1; 0, 0, 0, 0)
ijk_ext double8 const double8dq_id;		// (0, 0, 0, 1; 0, 0, 0, 0)
ijk_ext ddualquat const ddualquat_id;	// (0, 0, 0, 1; 0, 0, 0, 0)


//-----------------------------------------------------------------------------

// Select real quaternion types.
///
typedef real		real8[8];		// 8-element real array-based vector, always passed by pointer.
typedef real4		real2x4[4];		// 2x4 (2c x 4r) real array-based quaternion, always passed by pointer.

// Global constants for real array-based quaternions and data structures.
///
#ifdef IJK_REAL_DBL
typedef dquat		rquat;			// Real 3D quaternion data structure type is 3D double quaternion.
typedef ddualquat	rdualquat;		// Real 4D quaternion data structure type is 4D double quaternion.

#define real4q_id double4q_id		// (0, 0, 0, 1)
#define rquat_id dquat_id			// (0, 0, 0, 1)

#define real2x4_id double2x4_id		// (0, 0, 0, 1; 0, 0, 0, 0)
#define real8dq_id double8dq_id		// (0, 0, 0, 1; 0, 0, 0, 0)
#define rdualquat_id ddualquat_id	// (0, 0, 0, 1; 0, 0, 0, 0)

#else	// !IJK_REAL_DBL
typedef fquat		rquat;			// Real 3D quaternion data structure type is 3D float quaternion.
typedef fdualquat	rdualquat;		// Real 4D quaternion data structure type is 4D float quaternion.

#define real4q_id float4q_id		// (0, 0, 0, 1)
#define rquat_id fquat_id			// (0, 0, 0, 1)

#define real2x4_id float2x4_id		// (0, 0, 0, 1; 0, 0, 0, 0)
#define real8dq_id float8dq_id		// (0, 0, 0, 1; 0, 0, 0, 0)
#define rdualquat_id fdualquat_id	// (0, 0, 0, 1; 0, 0, 0, 0)

#endif	// IJK_REAL_DBL


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_util/ijkQuaternion_real.h"
#include "_inl/ijkQuaternion.inl"


#endif	// !_IJK_QUATERNION_H_