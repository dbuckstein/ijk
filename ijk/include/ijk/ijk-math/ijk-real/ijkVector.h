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
	union ivec2;
	union ivec3;
	union ivec4;
	union fvec2;
	union fvec3;
	union fvec4;
	union dvec2;
	union dvec3;
	union dvec4;

// IJK_SWIZZLE_MACRO_DECL
#pragma region IJK_SWIZZLE_MACRO_DECL

#define IJK_SWIZZLE(n,t,x,y,z,w)						t##vec##n const	_##x##y##z##w() const													// Declare swizzle function.
#define IJK_SWIZZLE2(n,t,x,y,...)						inline t##vec2 const t##vec##n::_##x##y() const { return t##vec2(x, y); }				// Implement 2-element swizzle.
#define IJK_SWIZZLE3(n,t,x,y,z,...)						inline t##vec3 const t##vec##n::_##x##y##z() const { return t##vec3(x, y, z); }			// Implement 3-element swizzle.
#define IJK_SWIZZLE4(n,t,x,y,z,w)						inline t##vec4 const t##vec##n::_##x##y##z##w() const { return t##vec4(x, y, z, w); }	// Implement 4-element swizzle.

#define IJK_SWIZZLE_2X1(swiz,n,t,x,u,v)					swiz(n,t,x,x,u,v)				// Return 2 elements from 1 item: 1^2 = 1 combo
#define IJK_SWIZZLE_3X1(swiz,n,t,x,v)					IJK_SWIZZLE_2X1(swiz,n,t,x,x,v)	// Return 3 elements from 1 item: 1^3 = 1 combo
#define IJK_SWIZZLE_4X1(swiz,n,t,x)						IJK_SWIZZLE_3X1(swiz,n,t,x,x)	// Return 4 elements from 1 item: 1^4 = 1 combo
#define IJK_SWIZZLE_2X2(swiz,n,t,x,y,u,v)				IJK_SWIZZLE_2X1(swiz,n,t,x,u,v); swiz(n,t,x,y,u,v); swiz(n,t,y,x,u,v); swiz(n,t,y,y,u,v)	// Return 2 elements from 2 items: 2^2 = 4 combos
#define IJK_SWIZZLE_3X2(swiz,n,t,x,y,v)					IJK_SWIZZLE_2X2(swiz,n,t,x,y,x,v); IJK_SWIZZLE_2X2(swiz,n,t,x,y,y,v)						// Return 3 elements from 2 items: 2^3 = 8 combos
#define IJK_SWIZZLE_4X2(swiz,n,t,x,y)					IJK_SWIZZLE_3X2(swiz,n,t,x,y,x); IJK_SWIZZLE_3X2(swiz,n,t,x,y,y)							// Return 4 elements from 2 items: 2^4 = 16 combos
#define IJK_SWIZZLE_2X3(swiz,n,t,x,y,z,u,v)				IJK_SWIZZLE_2X2(swiz,n,t,x,y,u,v); swiz(n,t,x,z,u,v); swiz(n,t,y,z,u,v); swiz(n,t,z,x,u,v); swiz(n,t,z,y,u,v); swiz(n,t,z,z,u,v)	// Return 2 elements from 3 items: 3^2 = 9 combos = 4+5
#define IJK_SWIZZLE_3X3(swiz,n,t,x,y,z,v)				IJK_SWIZZLE_2X3(swiz,n,t,x,y,z,x,v); IJK_SWIZZLE_2X3(swiz,n,t,x,y,z,y,v); IJK_SWIZZLE_2X3(swiz,n,t,x,y,z,z,v)						// Return 3 elements from 3 items: 3^3 = 27 combos = 8+19
#define IJK_SWIZZLE_4X3(swiz,n,t,x,y,z)					IJK_SWIZZLE_3X3(swiz,n,t,x,y,z,x); IJK_SWIZZLE_3X3(swiz,n,t,x,y,z,y); IJK_SWIZZLE_3X3(swiz,n,t,x,y,z,z)								// Return 4 elements from 3 items: 3^4 = 81 combos = 16+65
#define IJK_SWIZZLE_2X4(swiz,n,t,x,y,z,w,u,v)			IJK_SWIZZLE_2X3(swiz,n,t,x,y,z,u,v); swiz(n,t,x,w,u,v); swiz(n,t,y,w,u,v); swiz(n,t,z,w,u,v); swiz(n,t,w,x,u,v); swiz(n,t,w,y,u,v); swiz(n,t,w,z,u,v); swiz(n,t,w,w,u,v)	// Return 2 elements from 4 items: 4^2 = 16 combos = 9+7
#define IJK_SWIZZLE_3X4(swiz,n,t,x,y,z,w,v)				IJK_SWIZZLE_2X4(swiz,n,t,x,y,z,w,x,v); IJK_SWIZZLE_2X4(swiz,n,t,x,y,z,w,y,v); IJK_SWIZZLE_2X4(swiz,n,t,x,y,z,w,z,v); IJK_SWIZZLE_2X4(swiz,n,t,x,y,z,w,w,v)					// Return 3 elements from 4 items: 4^3 = 64 combos = 27+37
#define IJK_SWIZZLE_4X4(swiz,n,t,x,y,z,w)				IJK_SWIZZLE_3X4(swiz,n,t,x,y,z,w,x); IJK_SWIZZLE_3X4(swiz,n,t,x,y,z,w,y); IJK_SWIZZLE_3X4(swiz,n,t,x,y,z,w,z); IJK_SWIZZLE_3X4(swiz,n,t,x,y,z,w,w)							// Return 4 elements from 4 items: 4^4 = 256 combos = 81+175

#define IJK_SWIZZLE_X(swiz2,swiz3,swiz4,n2,n3,n4,t)		IJK_SWIZZLE_2X1(swiz2,n2,t,x,,); IJK_SWIZZLE_3X1(swiz3,n3,t,x,); IJK_SWIZZLE_4X1(swiz4,n4,t,x)						// Declare all swizzle combos with 1 element.
#define IJK_SWIZZLE_XY(swiz2,swiz3,swiz4,n2,n3,n4,t)	IJK_SWIZZLE_2X2(swiz2,n2,t,x,y,,); IJK_SWIZZLE_3X2(swiz3,n3,t,x,y,); IJK_SWIZZLE_4X2(swiz4,n4,t,x,y)				// Declare all swizzle combos with 2 elements.
#define IJK_SWIZZLE_XYZ(swiz2,swiz3,swiz4,n2,n3,n4,t)	IJK_SWIZZLE_2X3(swiz2,n2,t,x,y,z,,); IJK_SWIZZLE_3X3(swiz3,n3,t,x,y,z,); IJK_SWIZZLE_4X3(swiz4,n4,t,x,y,z)			// Declare all swizzle combos with 3 elements.
#define IJK_SWIZZLE_XYZW(swiz2,swiz3,swiz4,n2,n3,n4,t)	IJK_SWIZZLE_2X4(swiz2,n2,t,x,y,z,w,,); IJK_SWIZZLE_3X4(swiz3,n3,t,x,y,z,w,); IJK_SWIZZLE_4X4(swiz4,n4,t,x,y,z,w)	// Declare all swizzle combos with 4 elements.

#pragma endregion
// IJK_SWIZZLE_MACRO_DECL

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

// ivec2
//	Data structure representing 2D integer vector.
//		member v: array of elements, used as pointer argument to vector functions
//		members x, y: individual named elements representing a spatial coordinate
union ivec2
{
	int2 v;
	struct { i32 x, y; };

#ifdef __cplusplus
	ivec2(i32 const xy = 0);			// Construct vector with all elements set to single scalar.
	ivec2(i32 const x, i32 const y);	// Construct vector with elements set individually.
	ivec2(int2 const xy);				// Construct vector given integer array-based vector.
	ivec2(flt2 const xy);				// Construct vector given float array-based vector.
	ivec2(dbl2 const xy);				// Construct vector given double array-based vector.
	ivec2(ivec2 const& xy);				// Construct vector given another 2D integer vector.
	ivec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D integer vector.
	ivec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D integer vector.
	ivec2(fvec2 const& xy);				// Construct vector given a 2D float vector.
	ivec2(fvec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	ivec2(fvec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
	ivec2(dvec2 const& xy);				// Construct vector given a 2D double vector.
	ivec2(dvec3 const& xy);				// Construct vector given the first two elements of a 3D double vector.
	ivec2(dvec4 const& xy);				// Construct vector given the first two elements of a 4D double vector.

	ivec2& operator =(i32 const xy);
	ivec2& operator =(int2 const xy);
	ivec2& operator =(flt2 const xy);
	ivec2& operator =(dbl2 const xy);
	ivec2& operator =(ivec2 const& xy);
	ivec2& operator =(ivec3 const& xy);
	ivec2& operator =(ivec4 const& xy);
	ivec2& operator =(fvec2 const& xy);
	ivec2& operator =(fvec3 const& xy);
	ivec2& operator =(fvec4 const& xy);
	ivec2& operator =(dvec2 const& xy);
	ivec2& operator =(dvec3 const& xy);
	ivec2& operator =(dvec4 const& xy);

	ivec2& operator +=(i32 const s);
	ivec2& operator +=(ivec2 const& v);
	ivec2& operator -=(i32 const s);
	ivec2& operator -=(ivec2 const& v);
	ivec2& operator *=(i32 const s);
	ivec2& operator *=(ivec2 const& v);
	ivec2& operator /=(i32 const s);
	ivec2& operator /=(ivec2 const& v);
	ivec2 const operator +(i32 const s) const;
	ivec2 const operator +(ivec2 const& v) const;
	ivec2 const operator -(i32 const s) const;
	ivec2 const operator -(ivec2 const& v) const;
	ivec2 const operator *(i32 const s) const;
	ivec2 const operator *(ivec2 const& v) const;
	ivec2 const operator /(i32 const s) const;
	ivec2 const operator /(ivec2 const& v) const;

	bool operator ==(ivec2 const& v) const;
	bool operator !=(ivec2 const& v) const;

	i32& operator[](uindex const i);
	i32 operator[](uindex const i) const;

	ivec2& operator+();
	ivec2 const operator+() const;
	ivec2 const operator-() const;

	IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
#endif	// __cplusplus
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

#ifdef __cplusplus
	ivec3(i32 const xyz = 0);							// Construct vector with all elements set to single scalar.
	ivec3(i32 const x, i32 const y, i32 const z = 0);	// Construct vector with elements set individually.
	ivec3(int3 const xyz);								// Construct vector given integer array-based vector.
	ivec3(flt3 const xyz);								// Construct vector given float array-based vector.
	ivec3(dbl3 const xyz);								// Construct vector given double array-based vector.
	ivec3(ivec2 const& xy, i32 const z = 0);			// Construct vector given a 2D integer vector and the third element.
	ivec3(ivec3 const& xyz);							// Construct vector given another 3D integer vector.
	ivec3(ivec4 const& xyz);							// Construct vector given the first three elements of a 4D integer vector.
	ivec3(fvec2 const& xy, i32 const z = 0);			// Construct vector given a 2D float vector and the third element.
	ivec3(fvec3 const& xyz);							// Construct vector given a 3D float vector.
	ivec3(fvec4 const& xyz);							// Construct vector given the first three elements of a 4D float vector.
	ivec3(dvec2 const& xy, i32 const z = 0);			// Construct vector given a 2D double vector and the third element.
	ivec3(dvec3 const& xyz);							// Construct vector given a 3D double vector.
	ivec3(dvec4 const& xyz);							// Construct vector given the first three elements of a 4D double vector.

	ivec3& operator =(i32 const xyz);
	ivec3& operator =(int3 const xyz);
	ivec3& operator =(flt3 const xyz);
	ivec3& operator =(dbl3 const xyz);
	ivec3& operator =(ivec2 const& xy);
	ivec3& operator =(ivec3 const& xyz);
	ivec3& operator =(ivec4 const& xyz);
	ivec3& operator =(fvec2 const& xy);
	ivec3& operator =(fvec3 const& xyz);
	ivec3& operator =(fvec4 const& xyz);
	ivec3& operator =(dvec2 const& xy);
	ivec3& operator =(dvec3 const& xyz);
	ivec3& operator =(dvec4 const& xyz);

	ivec3& operator +=(i32 const s);
	ivec3& operator +=(ivec3 const& v);
	ivec3& operator -=(i32 const s);
	ivec3& operator -=(ivec3 const& v);
	ivec3& operator *=(i32 const s);
	ivec3& operator *=(ivec3 const& v);
	ivec3& operator /=(i32 const s);
	ivec3& operator /=(ivec3 const& v);
	ivec3 const operator +(i32 const s) const;
	ivec3 const operator +(ivec3 const& v) const;
	ivec3 const operator -(i32 const s) const;
	ivec3 const operator -(ivec3 const& v) const;
	ivec3 const operator *(i32 const s) const;
	ivec3 const operator *(ivec3 const& v) const;
	ivec3 const operator /(i32 const s) const;
	ivec3 const operator /(ivec3 const& v) const;

	bool operator ==(ivec3 const& v) const;
	bool operator !=(ivec3 const& v) const;

	i32& operator[](uindex const i);
	i32 operator[](uindex const i) const;

	ivec3& operator+();
	ivec3 const operator+() const;
	ivec3 const operator-() const;

	IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
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
union ivec4
{
	int4 v;
	ivec3 xyz;
	ivec2 xy;
	struct { i32 x, y, z, w; };
	struct { i32 r, g, b, a; };

#ifdef __cplusplus
	ivec4(i32 const xyzw = 0);											// Construct vector with all elements set to single scalar.
	ivec4(i32 const x, i32 const y, i32 const z = 0, i32 const w = 0);	// Construct vector with elements set individually.
	ivec4(int4 const xyzw);												// Construct vector given integer array-based vector.
	ivec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	ivec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	ivec4(ivec2 const& xy, i32 const z = 0, i32 const w = 0);			// Construct vector given a 2D integer vector and the third and fourth elements.
	ivec4(ivec3 const& xyz, i32 const w = 0);							// Construct vector given a 3D integer vector and the fourth element.
	ivec4(ivec4 const& xyzw);											// Construct vector given another 4D integer vector.
	ivec4(fvec2 const& xy, i32 const z = 0, i32 const w = 0);			// Construct vector given a 2D float vector and the third and fourth elements.
	ivec4(fvec3 const& xyz, i32 const w = 0);							// Construct vector given a 3D float vector and the fourth element.
	ivec4(fvec4 const& xyzw);											// Construct vector given a 4D float vector.
	ivec4(dvec2 const& xy, i32 const z = 0, i32 const w = 0);			// Construct vector given a 2D double vector and the third and fourth elements.
	ivec4(dvec3 const& xyz, i32 const w = 0);							// Construct vector given a 3D double vector and the fourth element.
	ivec4(dvec4 const& xyzw);											// Construct vector given a 4D double vector.

	ivec4& operator =(i32 const xyzw);
	ivec4& operator =(int4 const xyzw);
	ivec4& operator =(flt4 const xyzw);
	ivec4& operator =(dbl4 const xyzw);
	ivec4& operator =(ivec2 const& xy);
	ivec4& operator =(ivec3 const& xyz);
	ivec4& operator =(ivec4 const& xyzw);
	ivec4& operator =(fvec2 const& xy);
	ivec4& operator =(fvec3 const& xyz);
	ivec4& operator =(fvec4 const& xyzw);
	ivec4& operator =(dvec2 const& xy);
	ivec4& operator =(dvec3 const& xyz);
	ivec4& operator =(dvec4 const& xyzw);

	ivec4& operator +=(i32 const s);
	ivec4& operator +=(ivec4 const& v);
	ivec4& operator -=(i32 const s);
	ivec4& operator -=(ivec4 const& v);
	ivec4& operator *=(i32 const s);
	ivec4& operator *=(ivec4 const& v);
	ivec4& operator /=(i32 const s);
	ivec4& operator /=(ivec4 const& v);
	ivec4 const operator +(i32 const s) const;
	ivec4 const operator +(ivec4 const& v) const;
	ivec4 const operator -(i32 const s) const;
	ivec4 const operator -(ivec4 const& v) const;
	ivec4 const operator *(i32 const s) const;
	ivec4 const operator *(ivec4 const& v) const;
	ivec4 const operator /(i32 const s) const;
	ivec4 const operator /(ivec4 const& v) const;

	bool operator ==(ivec3 const& v) const;
	bool operator !=(ivec3 const& v) const;

	i32& operator[](uindex const i);
	i32 operator[](uindex const i) const;

	ivec4& operator+();
	ivec4 const operator+() const;
	ivec4 const operator-() const;

	IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
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

#ifdef __cplusplus
	fvec2(flt const xy = 0);			// Construct vector with all elements set to single scalar.
	fvec2(flt const x, flt const y);	// Construct vector with elements set individually.
	fvec2(int2 const xy);				// Construct vector given integer array-based vector.
	fvec2(flt2 const xy);				// Construct vector given float array-based vector.
	fvec2(dbl2 const xy);				// Construct vector given double array-based vector.
	fvec2(ivec2 const& xy);				// Construct vector given a 2D integer vector.
	fvec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D integer vector.
	fvec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D integer vector.
	fvec2(fvec2 const& xy);				// Construct vector given another 2D float vector.
	fvec2(fvec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	fvec2(fvec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
	fvec2(dvec2 const& xy);				// Construct vector given a 2D double vector.
	fvec2(dvec3 const& xy);				// Construct vector given the first two elements of a 3D double vector.
	fvec2(dvec4 const& xy);				// Construct vector given the first two elements of a 4D double vector.

	fvec2& operator =(flt const xy);
	fvec2& operator =(int2 const xy);
	fvec2& operator =(flt2 const xy);
	fvec2& operator =(dbl2 const xy);
	fvec2& operator =(ivec2 const& xy);
	fvec2& operator =(ivec3 const& xy);
	fvec2& operator =(ivec4 const& xy);
	fvec2& operator =(fvec2 const& xy);
	fvec2& operator =(fvec3 const& xy);
	fvec2& operator =(fvec4 const& xy);
	fvec2& operator =(dvec2 const& xy);
	fvec2& operator =(dvec3 const& xy);
	fvec2& operator =(dvec4 const& xy);

	fvec2& operator +=(flt const s);
	fvec2& operator +=(fvec2 const& v);
	fvec2& operator -=(flt const s);
	fvec2& operator -=(fvec2 const& v);
	fvec2& operator *=(flt const s);
	fvec2& operator *=(fvec2 const& v);
	fvec2& operator /=(flt const s);
	fvec2& operator /=(fvec2 const& v);
	fvec2 const operator +(flt const s) const;
	fvec2 const operator +(fvec2 const& v) const;
	fvec2 const operator -(flt const s) const;
	fvec2 const operator -(fvec2 const& v) const;
	fvec2 const operator *(flt const s) const;
	fvec2 const operator *(fvec2 const& v) const;
	fvec2 const operator /(flt const s) const;
	fvec2 const operator /(fvec2 const& v) const;

	bool operator ==(fvec2 const& v) const;
	bool operator !=(fvec2 const& v) const;

	flt& operator[](uindex const i);
	flt operator[](uindex const i) const;

	fvec2& operator+();
	fvec2 const operator+() const;
	fvec2 const operator-() const;

	IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
#endif	// __cplusplus
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

#ifdef __cplusplus
	fvec3(flt const xyz = 0);							// Construct vector with all elements set to single scalar.
	fvec3(flt const x, flt const y, flt const z = 0);	// Construct vector with elements set individually.
	fvec3(int3 const xyz);								// Construct vector given integer array-based vector.
	fvec3(flt3 const xyz);								// Construct vector given float array-based vector.
	fvec3(dbl3 const xyz);								// Construct vector given double array-based vector.
	fvec3(ivec2 const& xy, flt const z = 0);			// Construct vector given a 2D integer vector and the third element.
	fvec3(ivec3 const& xyz);							// Construct vector given a 3D integer vector.
	fvec3(ivec4 const& xyz);							// Construct vector given the first three elements of a 4D integer vector.
	fvec3(fvec2 const& xy, flt const z = 0);			// Construct vector given a 2D float vector and the third element.
	fvec3(fvec3 const& xyz);							// Construct vector given another 3D float vector.
	fvec3(fvec4 const& xyz);							// Construct vector given the first three elements of a 4D float vector.
	fvec3(dvec2 const& xy, flt const z = 0);			// Construct vector given a 2D double vector and the third element.
	fvec3(dvec3 const& xyz);							// Construct vector given a 3D double vector.
	fvec3(dvec4 const& xyz);							// Construct vector given the first three elements of a 4D double vector.

	fvec3& operator =(flt const xyz);
	fvec3& operator =(int3 const xyz);
	fvec3& operator =(flt3 const xyz);
	fvec3& operator =(dbl3 const xyz);
	fvec3& operator =(ivec2 const& xy);
	fvec3& operator =(ivec3 const& xyz);
	fvec3& operator =(ivec4 const& xyz);
	fvec3& operator =(fvec2 const& xy);
	fvec3& operator =(fvec3 const& xyz);
	fvec3& operator =(fvec4 const& xyz);
	fvec3& operator =(dvec2 const& xy);
	fvec3& operator =(dvec3 const& xyz);
	fvec3& operator =(dvec4 const& xyz);

	fvec3& operator +=(flt const s);
	fvec3& operator +=(fvec3 const& v);
	fvec3& operator -=(flt const s);
	fvec3& operator -=(fvec3 const& v);
	fvec3& operator *=(flt const s);
	fvec3& operator *=(fvec3 const& v);
	fvec3& operator /=(flt const s);
	fvec3& operator /=(fvec3 const& v);
	fvec3 const operator +(flt const s) const;
	fvec3 const operator +(fvec3 const& v) const;
	fvec3 const operator -(flt const s) const;
	fvec3 const operator -(fvec3 const& v) const;
	fvec3 const operator *(flt const s) const;
	fvec3 const operator *(fvec3 const& v) const;
	fvec3 const operator /(flt const s) const;
	fvec3 const operator /(fvec3 const& v) const;

	bool operator ==(fvec3 const& v) const;
	bool operator !=(fvec3 const& v) const;

	flt& operator[](uindex const i);
	flt operator[](uindex const i) const;

	fvec3& operator+();
	fvec3 const operator+() const;
	fvec3 const operator-() const;

	IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
#endif	// __cplusplus
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

#ifdef __cplusplus
	fvec4(flt const xyzw = 0);											// Construct vector with all elements set to single scalar.
	fvec4(flt const x, flt const y, flt const z = 0, flt const w = 0);	// Construct vector with elements set individually.
	fvec4(int4 const xyzw);												// Construct vector given integer array-based vector.
	fvec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	fvec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	fvec4(ivec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D integer vector and the third and fourth elements.
	fvec4(ivec3 const& xyz, flt const w = 0);							// Construct vector given a 3D integer vector and the fourth element.
	fvec4(ivec4 const& xyzw);											// Construct vector given a 4D integer vector.
	fvec4(fvec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D float vector and the third and fourth elements.
	fvec4(fvec3 const& xyz, flt const w = 0);							// Construct vector given a 3D float vector and the fourth element.
	fvec4(fvec4 const& xyzw);											// Construct vector given another 4D float vector.
	fvec4(dvec2 const& xy, flt const z = 0, flt const w = 0);			// Construct vector given a 2D double vector and the third and fourth elements.
	fvec4(dvec3 const& xyz, flt const w = 0);							// Construct vector given a 3D double vector and the fourth element.
	fvec4(dvec4 const& xyzw);											// Construct vector given a 4D double vector.

	fvec4& operator =(flt const xyzw);
	fvec4& operator =(int4 const xyzw);
	fvec4& operator =(flt4 const xyzw);
	fvec4& operator =(dbl4 const xyzw);
	fvec4& operator =(ivec2 const& xy);
	fvec4& operator =(ivec3 const& xyz);
	fvec4& operator =(ivec4 const& xyzw);
	fvec4& operator =(fvec2 const& xy);
	fvec4& operator =(fvec3 const& xyz);
	fvec4& operator =(fvec4 const& xyzw);
	fvec4& operator =(dvec2 const& xy);
	fvec4& operator =(dvec3 const& xyz);
	fvec4& operator =(dvec4 const& xyzw);

	fvec4& operator +=(flt const s);
	fvec4& operator +=(fvec4 const& v);
	fvec4& operator -=(flt const s);
	fvec4& operator -=(fvec4 const& v);
	fvec4& operator *=(flt const s);
	fvec4& operator *=(fvec4 const& v);
	fvec4& operator /=(flt const s);
	fvec4& operator /=(fvec4 const& v);
	fvec4 const operator +(flt const s) const;
	fvec4 const operator +(fvec4 const& v) const;
	fvec4 const operator -(flt const s) const;
	fvec4 const operator -(fvec4 const& v) const;
	fvec4 const operator *(flt const s) const;
	fvec4 const operator *(fvec4 const& v) const;
	fvec4 const operator /(flt const s) const;
	fvec4 const operator /(fvec4 const& v) const;

	bool operator ==(fvec3 const& v) const;
	bool operator !=(fvec3 const& v) const;

	flt& operator[](uindex const i);
	flt operator[](uindex const i) const;

	fvec4& operator+();
	fvec4 const operator+() const;
	fvec4 const operator-() const;

	IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, f);
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


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

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

#ifdef __cplusplus
	dvec2(dbl const xy = 0);			// Construct vector with all elements set to single scalar.
	dvec2(dbl const x, dbl const y);	// Construct vector with elements set individually.
	dvec2(int2 const xy);				// Construct vector given integer array-based vector.
	dvec2(flt2 const xy);				// Construct vector given float array-based vector.
	dvec2(dbl2 const xy);				// Construct vector given double array-based vector.
	dvec2(ivec2 const& xy);				// Construct vector given a 2D integer vector.
	dvec2(ivec3 const& xy);				// Construct vector given the first two elements of a 3D integer vector.
	dvec2(ivec4 const& xy);				// Construct vector given the first two elements of a 4D integer vector.
	dvec2(fvec2 const& xy);				// Construct vector given a 2D float vector.
	dvec2(fvec3 const& xy);				// Construct vector given the first two elements of a 3D float vector.
	dvec2(fvec4 const& xy);				// Construct vector given the first two elements of a 4D float vector.
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
	dvec2& operator =(fvec2 const& xy);
	dvec2& operator =(fvec3 const& xy);
	dvec2& operator =(fvec4 const& xy);
	dvec2& operator =(dvec2 const& xy);
	dvec2& operator =(dvec3 const& xy);
	dvec2& operator =(dvec4 const& xy);

	dvec2& operator +=(dbl const s);
	dvec2& operator +=(dvec2 const& v);
	dvec2& operator -=(dbl const s);
	dvec2& operator -=(dvec2 const& v);
	dvec2& operator *=(dbl const s);
	dvec2& operator *=(dvec2 const& v);
	dvec2& operator /=(dbl const s);
	dvec2& operator /=(dvec2 const& v);
	dvec2 const operator +(dbl const s) const;
	dvec2 const operator +(dvec2 const& v) const;
	dvec2 const operator -(dbl const s) const;
	dvec2 const operator -(dvec2 const& v) const;
	dvec2 const operator *(dbl const s) const;
	dvec2 const operator *(dvec2 const& v) const;
	dvec2 const operator /(dbl const s) const;
	dvec2 const operator /(dvec2 const& v) const;

	bool operator ==(dvec2 const& v) const;
	bool operator !=(dvec2 const& v) const;

	dbl& operator[](uindex const i);
	dbl operator[](uindex const i) const;

	dvec2& operator+();
	dvec2 const operator+() const;
	dvec2 const operator-() const;

	IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
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
	dvec3(fvec2 const& xy, dbl const z = 0);			// Construct vector given a 2D float vector and the third element.
	dvec3(fvec3 const& xyz);							// Construct vector given a 3D float vector.
	dvec3(fvec4 const& xyz);							// Construct vector given the first three elements of a 4D float vector.
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
	dvec3& operator =(fvec2 const& xy);
	dvec3& operator =(fvec3 const& xyz);
	dvec3& operator =(fvec4 const& xyz);
	dvec3& operator =(dvec2 const& xy);
	dvec3& operator =(dvec3 const& xyz);
	dvec3& operator =(dvec4 const& xyz);

	dvec3& operator +=(dbl const s);
	dvec3& operator +=(dvec3 const& v);
	dvec3& operator -=(dbl const s);
	dvec3& operator -=(dvec3 const& v);
	dvec3& operator *=(dbl const s);
	dvec3& operator *=(dvec3 const& v);
	dvec3& operator /=(dbl const s);
	dvec3& operator /=(dvec3 const& v);
	dvec3 const operator +(dbl const s) const;
	dvec3 const operator +(dvec3 const& v) const;
	dvec3 const operator -(dbl const s) const;
	dvec3 const operator -(dvec3 const& v) const;
	dvec3 const operator *(dbl const s) const;
	dvec3 const operator *(dvec3 const& v) const;
	dvec3 const operator /(dbl const s) const;
	dvec3 const operator /(dvec3 const& v) const;

	bool operator ==(dvec3 const& v) const;
	bool operator !=(dvec3 const& v) const;

	dbl& operator[](uindex const i);
	dbl operator[](uindex const i) const;

	dvec3& operator+();
	dvec3 const operator+() const;
	dvec3 const operator-() const;

	IJK_SWIZZLE_XYZ(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
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
	dvec4(fvec2 const& xy, dbl const z = 0, dbl const w = 0);			// Construct vector given a 2D float vector and the third and fourth elements.
	dvec4(fvec3 const& xyz, dbl const w = 0);							// Construct vector given a 3D float vector and the fourth element.
	dvec4(fvec4 const& xyzw);											// Construct vector given a 4D float vector.
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
	dvec4& operator =(fvec2 const& xy);
	dvec4& operator =(fvec3 const& xyz);
	dvec4& operator =(fvec4 const& xyzw);
	dvec4& operator =(dvec2 const& xy);
	dvec4& operator =(dvec3 const& xyz);
	dvec4& operator =(dvec4 const& xyzw);

	dvec4& operator +=(dbl const s);
	dvec4& operator +=(dvec4 const& v);
	dvec4& operator -=(dbl const s);
	dvec4& operator -=(dvec4 const& v);
	dvec4& operator *=(dbl const s);
	dvec4& operator *=(dvec4 const& v);
	dvec4& operator /=(dbl const s);
	dvec4& operator /=(dvec4 const& v);
	dvec4 const operator +(dbl const s) const;
	dvec4 const operator +(dvec4 const& v) const;
	dvec4 const operator -(dbl const s) const;
	dvec4 const operator -(dvec4 const& v) const;
	dvec4 const operator *(dbl const s) const;
	dvec4 const operator *(dvec4 const& v) const;
	dvec4 const operator /(dbl const s) const;
	dvec4 const operator /(dvec4 const& v) const;

	bool operator ==(dvec3 const& v) const;
	bool operator !=(dvec3 const& v) const;

	dbl& operator[](uindex const i);
	dbl operator[](uindex const i) const;

	dvec4& operator+();
	dvec4 const operator+() const;
	dvec4 const operator-() const;

	IJK_SWIZZLE_XYZW(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, d);
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

// IJK_SWIZZLE_MACRO_IMPL
#pragma region IJK_SWIZZLE_MACRO_IMPL

#define xx		_xx()
#define xy		_xy()
#define xz		_xz()
#define xw		_xw()
#define yx		_yx()
#define yy		_yy()
#define yz		_yz()
#define yw		_yw()
#define zx		_zx()
#define zy		_zy()
#define zz		_zz()
#define zw		_zw()
#define wx		_wx()
#define wy		_wy()
#define wz		_wz()
#define ww		_ww()
#define xxx		_xxx()
#define xxy		_xxy()
#define xxz		_xxz()
#define xxw		_xxw()
#define xyx		_xyx()
#define xyy		_xyy()
#define xyz		_xyz()
#define xyw		_xyw()
#define xzx		_xzx()
#define xzy		_xzy()
#define xzz		_xzz()
#define xzw		_xzw()
#define xwx		_xwx()
#define xwy		_xwy()
#define xwz		_xwz()
#define xww		_xww()
#define yxx		_yxx()
#define yxy		_yxy()
#define yxz		_yxz()
#define yxw		_yxw()
#define yyx		_yyx()
#define yyy		_yyy()
#define yyz		_yyz()
#define yyw		_yyw()
#define yzx		_yzx()
#define yzy		_yzy()
#define yzz		_yzz()
#define yzw		_yzw()
#define ywx		_ywx()
#define ywy		_ywy()
#define ywz		_ywz()
#define yww		_yww()
#define zxx		_zxx()
#define zxy		_zxy()
#define zxz		_zxz()
#define zxw		_zxw()
#define zyx		_zyx()
#define zyy		_zyy()
#define zyz		_zyz()
#define zyw		_zyw()
#define zzx		_zzx()
#define zzy		_zzy()
#define zzz		_zzz()
#define zzw		_zzw()
#define zwx		_zwx()
#define zwy		_zwy()
#define zwz		_zwz()
#define zww		_zww()
#define wxx		_wxx()
#define wxy		_wxy()
#define wxz		_wxz()
#define wxw		_wxw()
#define wyx		_wyx()
#define wyy		_wyy()
#define wyz		_wyz()
#define wyw		_wyw()
#define wzx		_wzx()
#define wzy		_wzy()
#define wzz		_wzz()
#define wzw		_wzw()
#define wwx		_wwx()
#define wwy		_wwy()
#define wwz		_wwz()
#define www		_www()
#define xxxx	_xxxx()
#define xxxy	_xxxy()
#define xxxz	_xxxz()
#define xxxw	_xxxw()
#define xxyx	_xxyx()
#define xxyy	_xxyy()
#define xxyz	_xxyz()
#define xxyw	_xxyw()
#define xxzx	_xxzx()
#define xxzy	_xxzy()
#define xxzz	_xxzz()
#define xxzw	_xxzw()
#define xxwx	_xxwx()
#define xxwy	_xxwy()
#define xxwz	_xxwz()
#define xxww	_xxww()
#define xyxx	_xyxx()
#define xyxy	_xyxy()
#define xyxz	_xyxz()
#define xyxw	_xyxw()
#define xyyx	_xyyx()
#define xyyy	_xyyy()
#define xyyz	_xyyz()
#define xyyw	_xyyw()
#define xyzx	_xyzx()
#define xyzy	_xyzy()
#define xyzz	_xyzz()
#define xyzw	_xyzw()
#define xywx	_xywx()
#define xywy	_xywy()
#define xywz	_xywz()
#define xyww	_xyww()
#define xzxx	_xzxx()
#define xzxy	_xzxy()
#define xzxz	_xzxz()
#define xzxw	_xzxw()
#define xzyx	_xzyx()
#define xzyy	_xzyy()
#define xzyz	_xzyz()
#define xzyw	_xzyw()
#define xzzx	_xzzx()
#define xzzy	_xzzy()
#define xzzz	_xzzz()
#define xzzw	_xzzw()
#define xzwx	_xzwx()
#define xzwy	_xzwy()
#define xzwz	_xzwz()
#define xzww	_xzww()
#define xwxx	_xwxx()
#define xwxy	_xwxy()
#define xwxz	_xwxz()
#define xwxw	_xwxw()
#define xwyx	_xwyx()
#define xwyy	_xwyy()
#define xwyz	_xwyz()
#define xwyw	_xwyw()
#define xwzx	_xwzx()
#define xwzy	_xwzy()
#define xwzz	_xwzz()
#define xwzw	_xwzw()
#define xwwx	_xwwx()
#define xwwy	_xwwy()
#define xwwz	_xwwz()
#define xwww	_xwww()
#define yxxx	_yxxx()
#define yxxy	_yxxy()
#define yxxz	_yxxz()
#define yxxw	_yxxw()
#define yxyx	_yxyx()
#define yxyy	_yxyy()
#define yxyz	_yxyz()
#define yxyw	_yxyw()
#define yxzx	_yxzx()
#define yxzy	_yxzy()
#define yxzz	_yxzz()
#define yxzw	_yxzw()
#define yxwx	_yxwx()
#define yxwy	_yxwy()
#define yxwz	_yxwz()
#define yxww	_yxww()
#define yyxx	_yyxx()
#define yyxy	_yyxy()
#define yyxz	_yyxz()
#define yyxw	_yyxw()
#define yyyx	_yyyx()
#define yyyy	_yyyy()
#define yyyz	_yyyz()
#define yyyw	_yyyw()
#define yyzx	_yyzx()
#define yyzy	_yyzy()
#define yyzz	_yyzz()
#define yyzw	_yyzw()
#define yywx	_yywx()
#define yywy	_yywy()
#define yywz	_yywz()
#define yyww	_yyww()
#define yzxx	_yzxx()
#define yzxy	_yzxy()
#define yzxz	_yzxz()
#define yzxw	_yzxw()
#define yzyx	_yzyx()
#define yzyy	_yzyy()
#define yzyz	_yzyz()
#define yzyw	_yzyw()
#define yzzx	_yzzx()
#define yzzy	_yzzy()
#define yzzz	_yzzz()
#define yzzw	_yzzw()
#define yzwx	_yzwx()
#define yzwy	_yzwy()
#define yzwz	_yzwz()
#define yzww	_yzww()
#define ywxx	_ywxx()
#define ywxy	_ywxy()
#define ywxz	_ywxz()
#define ywxw	_ywxw()
#define ywyx	_ywyx()
#define ywyy	_ywyy()
#define ywyz	_ywyz()
#define ywyw	_ywyw()
#define ywzx	_ywzx()
#define ywzy	_ywzy()
#define ywzz	_ywzz()
#define ywzw	_ywzw()
#define ywwx	_ywwx()
#define ywwy	_ywwy()
#define ywwz	_ywwz()
#define ywww	_ywww()
#define zxxx	_zxxx()
#define zxxy	_zxxy()
#define zxxz	_zxxz()
#define zxxw	_zxxw()
#define zxyx	_zxyx()
#define zxyy	_zxyy()
#define zxyz	_zxyz()
#define zxyw	_zxyw()
#define zxzx	_zxzx()
#define zxzy	_zxzy()
#define zxzz	_zxzz()
#define zxzw	_zxzw()
#define zxwx	_zxwx()
#define zxwy	_zxwy()
#define zxwz	_zxwz()
#define zxww	_zxww()
#define zyxx	_zyxx()
#define zyxy	_zyxy()
#define zyxz	_zyxz()
#define zyxw	_zyxw()
#define zyyx	_zyyx()
#define zyyy	_zyyy()
#define zyyz	_zyyz()
#define zyyw	_zyyw()
#define zyzx	_zyzx()
#define zyzy	_zyzy()
#define zyzz	_zyzz()
#define zyzw	_zyzw()
#define zywx	_zywx()
#define zywy	_zywy()
#define zywz	_zywz()
#define zyww	_zyww()
#define zzxx	_zzxx()
#define zzxy	_zzxy()
#define zzxz	_zzxz()
#define zzxw	_zzxw()
#define zzyx	_zzyx()
#define zzyy	_zzyy()
#define zzyz	_zzyz()
#define zzyw	_zzyw()
#define zzzx	_zzzx()
#define zzzy	_zzzy()
#define zzzz	_zzzz()
#define zzzw	_zzzw()
#define zzwx	_zzwx()
#define zzwy	_zzwy()
#define zzwz	_zzwz()
#define zzww	_zzww()
#define zwxx	_zwxx()
#define zwxy	_zwxy()
#define zwxz	_zwxz()
#define zwxw	_zwxw()
#define zwyx	_zwyx()
#define zwyy	_zwyy()
#define zwyz	_zwyz()
#define zwyw	_zwyw()
#define zwzx	_zwzx()
#define zwzy	_zwzy()
#define zwzz	_zwzz()
#define zwzw	_zwzw()
#define zwwx	_zwwx()
#define zwwy	_zwwy()
#define zwwz	_zwwz()
#define zwww	_zwww()
#define wxxx	_wxxx()
#define wxxy	_wxxy()
#define wxxz	_wxxz()
#define wxxw	_wxxw()
#define wxyx	_wxyx()
#define wxyy	_wxyy()
#define wxyz	_wxyz()
#define wxyw	_wxyw()
#define wxzx	_wxzx()
#define wxzy	_wxzy()
#define wxzz	_wxzz()
#define wxzw	_wxzw()
#define wxwx	_wxwx()
#define wxwy	_wxwy()
#define wxwz	_wxwz()
#define wxww	_wxww()
#define wyxx	_wyxx()
#define wyxy	_wyxy()
#define wyxz	_wyxz()
#define wyxw	_wyxw()
#define wyyx	_wyyx()
#define wyyy	_wyyy()
#define wyyz	_wyyz()
#define wyyw	_wyyw()
#define wyzx	_wyzx()
#define wyzy	_wyzy()
#define wyzz	_wyzz()
#define wyzw	_wyzw()
#define wywx	_wywx()
#define wywy	_wywy()
#define wywz	_wywz()
#define wyww	_wyww()
#define wzxx	_wzxx()
#define wzxy	_wzxy()
#define wzxz	_wzxz()
#define wzxw	_wzxw()
#define wzyx	_wzyx()
#define wzyy	_wzyy()
#define wzyz	_wzyz()
#define wzyw	_wzyw()
#define wzzx	_wzzx()
#define wzzy	_wzzy()
#define wzzz	_wzzz()
#define wzzw	_wzzw()
#define wzwx	_wzwx()
#define wzwy	_wzwy()
#define wzwz	_wzwz()
#define wzww	_wzww()
#define wwxx	_wwxx()
#define wwxy	_wwxy()
#define wwxz	_wwxz()
#define wwxw	_wwxw()
#define wwyx	_wwyx()
#define wwyy	_wwyy()
#define wwyz	_wwyz()
#define wwyw	_wwyw()
#define wwzx	_wwzx()
#define wwzy	_wwzy()
#define wwzz	_wwzz()
#define wwzw	_wwzw()
#define wwwx	_wwwx()
#define wwwy	_wwwy()
#define wwwz	_wwwz()
#define wwww	_wwww()

#define rr		_xx()
#define rg		_xy()
#define rb		_xz()
#define ra		_xw()
#define gr		_yx()
#define gg		_yy()
#define gb		_yz()
#define ga		_yw()
#define br		_zx()
#define bg		_zy()
#define bb		_zz()
#define ba		_zw()
#define ar		_wx()
#define ag		_wy()
#define ab		_wz()
#define aa		_ww()
#define rrr		_xxx()
#define rrg		_xxy()
#define rrb		_xxz()
#define rra		_xxw()
#define rgr		_xyx()
#define rgg		_xyy()
#define rgb		_xyz()
#define rga		_xyw()
#define rbr		_xzx()
#define rbg		_xzy()
#define rbb		_xzz()
#define rba		_xzw()
#define rar		_xwx()
#define rag		_xwy()
#define rab		_xwz()
#define raa		_xww()
#define grr		_yxx()
#define grg		_yxy()
#define grb		_yxz()
#define gra		_yxw()
#define ggr		_yyx()
#define ggg		_yyy()
#define ggb		_yyz()
#define gga		_yyw()
#define gbr		_yzx()
#define gbg		_yzy()
#define gbb		_yzz()
#define gba		_yzw()
#define gar		_ywx()
#define gag		_ywy()
#define gab		_ywz()
#define gaa		_yww()
#define brr		_zxx()
#define brg		_zxy()
#define brb		_zxz()
#define bra		_zxw()
#define bgr		_zyx()
#define bgg		_zyy()
#define bgb		_zyz()
#define bga		_zyw()
#define bbr		_zzx()
#define bbg		_zzy()
#define bbb		_zzz()
#define bba		_zzw()
#define bar		_zwx()
#define bag		_zwy()
#define bab		_zwz()
#define baa		_zww()
#define arr		_wxx()
#define arg		_wxy()
#define arb		_wxz()
#define ara		_wxw()
#define agr		_wyx()
#define agg		_wyy()
#define agb		_wyz()
#define aga		_wyw()
#define abr		_wzx()
#define abg		_wzy()
#define abb		_wzz()
#define aba		_wzw()
#define aar		_wwx()
#define aag		_wwy()
#define aab		_wwz()
#define aaa		_www()
#define rrrr	_xxxx()
#define rrrg	_xxxy()
#define rrrb	_xxxz()
#define rrra	_xxxw()
#define rrgr	_xxyx()
#define rrgg	_xxyy()
#define rrgb	_xxyz()
#define rrga	_xxyw()
#define rrbr	_xxzx()
#define rrbg	_xxzy()
#define rrbb	_xxzz()
#define rrba	_xxzw()
#define rrar	_xxwx()
#define rrag	_xxwy()
#define rrab	_xxwz()
#define rraa	_xxww()
#define rgrr	_xyxx()
#define rgrg	_xyxy()
#define rgrb	_xyxz()
#define rgra	_xyxw()
#define rggr	_xyyx()
#define rggg	_xyyy()
#define rggb	_xyyz()
#define rgga	_xyyw()
#define rgbr	_xyzx()
#define rgbg	_xyzy()
#define rgbb	_xyzz()
#define rgba	_xyzw()
#define rgar	_xywx()
#define rgag	_xywy()
#define rgab	_xywz()
#define rgaa	_xyww()
#define rbrr	_xzxx()
#define rbrg	_xzxy()
#define rbrb	_xzxz()
#define rbra	_xzxw()
#define rbgr	_xzyx()
#define rbgg	_xzyy()
#define rbgb	_xzyz()
#define rbga	_xzyw()
#define rbbr	_xzzx()
#define rbbg	_xzzy()
#define rbbb	_xzzz()
#define rbba	_xzzw()
#define rbar	_xzwx()
#define rbag	_xzwy()
#define rbab	_xzwz()
#define rbaa	_xzww()
#define rarr	_xwxx()
#define rarg	_xwxy()
#define rarb	_xwxz()
#define rara	_xwxw()
#define ragr	_xwyx()
#define ragg	_xwyy()
#define ragb	_xwyz()
#define raga	_xwyw()
#define rabr	_xwzx()
#define rabg	_xwzy()
#define rabb	_xwzz()
#define raba	_xwzw()
#define raar	_xwwx()
#define raag	_xwwy()
#define raab	_xwwz()
#define raaa	_xwww()
#define grrr	_yxxx()
#define grrg	_yxxy()
#define grrb	_yxxz()
#define grra	_yxxw()
#define grgr	_yxyx()
#define grgg	_yxyy()
#define grgb	_yxyz()
#define grga	_yxyw()
#define grbr	_yxzx()
#define grbg	_yxzy()
#define grbb	_yxzz()
#define grba	_yxzw()
#define grar	_yxwx()
#define grag	_yxwy()
#define grab	_yxwz()
#define graa	_yxww()
#define ggrr	_yyxx()
#define ggrg	_yyxy()
#define ggrb	_yyxz()
#define ggra	_yyxw()
#define gggr	_yyyx()
#define gggg	_yyyy()
#define gggb	_yyyz()
#define ggga	_yyyw()
#define ggbr	_yyzx()
#define ggbg	_yyzy()
#define ggbb	_yyzz()
#define ggba	_yyzw()
#define ggar	_yywx()
#define ggag	_yywy()
#define ggab	_yywz()
#define ggaa	_yyww()
#define gbrr	_yzxx()
#define gbrg	_yzxy()
#define gbrb	_yzxz()
#define gbra	_yzxw()
#define gbgr	_yzyx()
#define gbgg	_yzyy()
#define gbgb	_yzyz()
#define gbga	_yzyw()
#define gbbr	_yzzx()
#define gbbg	_yzzy()
#define gbbb	_yzzz()
#define gbba	_yzzw()
#define gbar	_yzwx()
#define gbag	_yzwy()
#define gbab	_yzwz()
#define gbaa	_yzww()
#define garr	_ywxx()
#define garg	_ywxy()
#define garb	_ywxz()
#define gara	_ywxw()
#define gagr	_ywyx()
#define gagg	_ywyy()
#define gagb	_ywyz()
#define gaga	_ywyw()
#define gabr	_ywzx()
#define gabg	_ywzy()
#define gabb	_ywzz()
#define gaba	_ywzw()
#define gaar	_ywwx()
#define gaag	_ywwy()
#define gaab	_ywwz()
#define gaaa	_ywww()
#define brrr	_zxxx()
#define brrg	_zxxy()
#define brrb	_zxxz()
#define brra	_zxxw()
#define brgr	_zxyx()
#define brgg	_zxyy()
#define brgb	_zxyz()
#define brga	_zxyw()
#define brbr	_zxzx()
#define brbg	_zxzy()
#define brbb	_zxzz()
#define brba	_zxzw()
#define brar	_zxwx()
#define brag	_zxwy()
#define brab	_zxwz()
#define braa	_zxww()
#define bgrr	_zyxx()
#define bgrg	_zyxy()
#define bgrb	_zyxz()
#define bgra	_zyxw()
#define bggr	_zyyx()
#define bggg	_zyyy()
#define bggb	_zyyz()
#define bgga	_zyyw()
#define bgbr	_zyzx()
#define bgbg	_zyzy()
#define bgbb	_zyzz()
#define bgba	_zyzw()
#define bgar	_zywx()
#define bgag	_zywy()
#define bgab	_zywz()
#define bgaa	_zyww()
#define bbrr	_zzxx()
#define bbrg	_zzxy()
#define bbrb	_zzxz()
#define bbra	_zzxw()
#define bbgr	_zzyx()
#define bbgg	_zzyy()
#define bbgb	_zzyz()
#define bbga	_zzyw()
#define bbbr	_zzzx()
#define bbbg	_zzzy()
#define bbbb	_zzzz()
#define bbba	_zzzw()
#define bbar	_zzwx()
#define bbag	_zzwy()
#define bbab	_zzwz()
#define bbaa	_zzww()
#define barr	_zwxx()
#define barg	_zwxy()
#define barb	_zwxz()
#define bara	_zwxw()
#define bagr	_zwyx()
#define bagg	_zwyy()
#define bagb	_zwyz()
#define baga	_zwyw()
#define babr	_zwzx()
#define babg	_zwzy()
#define babb	_zwzz()
#define baba	_zwzw()
#define baar	_zwwx()
#define baag	_zwwy()
#define baab	_zwwz()
#define baaa	_zwww()
#define arrr	_wxxx()
#define arrg	_wxxy()
#define arrb	_wxxz()
#define arra	_wxxw()
#define argr	_wxyx()
#define argg	_wxyy()
#define argb	_wxyz()
#define arga	_wxyw()
#define arbr	_wxzx()
#define arbg	_wxzy()
#define arbb	_wxzz()
#define arba	_wxzw()
#define arar	_wxwx()
#define arag	_wxwy()
#define arab	_wxwz()
#define araa	_wxww()
#define agrr	_wyxx()
#define agrg	_wyxy()
#define agrb	_wyxz()
#define agra	_wyxw()
#define aggr	_wyyx()
#define aggg	_wyyy()
#define aggb	_wyyz()
#define agga	_wyyw()
#define agbr	_wyzx()
#define agbg	_wyzy()
#define agbb	_wyzz()
#define agba	_wyzw()
#define agar	_wywx()
#define agag	_wywy()
#define agab	_wywz()
#define agaa	_wyww()
#define abrr	_wzxx()
#define abrg	_wzxy()
#define abrb	_wzxz()
#define abra	_wzxw()
#define abgr	_wzyx()
#define abgg	_wzyy()
#define abgb	_wzyz()
#define abga	_wzyw()
#define abbr	_wzzx()
#define abbg	_wzzy()
#define abbb	_wzzz()
#define abba	_wzzw()
#define abar	_wzwx()
#define abag	_wzwy()
#define abab	_wzwz()
#define abaa	_wzww()
#define aarr	_wwxx()
#define aarg	_wwxy()
#define aarb	_wwxz()
#define aara	_wwxw()
#define aagr	_wwyx()
#define aagg	_wwyy()
#define aagb	_wwyz()
#define aaga	_wwyw()
#define aabr	_wwzx()
#define aabg	_wwzy()
#define aabb	_wwzz()
#define aaba	_wwzw()
#define aaar	_wwwx()
#define aaag	_wwwy()
#define aaab	_wwwz()
#define aaaa	_wwww()

#define ss		_xx()
#define st		_xy()
#define sp		_xz()
#define sq		_xw()
#define ts		_yx()
#define tt		_yy()
#define tp		_yz()
#define tq		_yw()
#define ps		_zx()
#define pt		_zy()
#define pp		_zz()
#define pq		_zw()
#define qs		_wx()
#define qt		_wy()
#define qp		_wz()
#define qq		_ww()
#define sss		_xxx()
#define sst		_xxy()
#define ssp		_xxz()
#define ssq		_xxw()
#define sts		_xyx()
#define stt		_xyy()
#define stp		_xyz()
#define stq		_xyw()
#define sps		_xzx()
#define spt		_xzy()
#define spp		_xzz()
#define spq		_xzw()
#define sqs		_xwx()
#define sqt		_xwy()
#define sqp		_xwz()
#define sqq		_xww()
#define tss		_yxx()
#define tst		_yxy()
#define tsp		_yxz()
#define tsq		_yxw()
#define tts		_yyx()
#define ttt		_yyy()
#define ttp		_yyz()
#define ttq		_yyw()
#define tps		_yzx()
#define tpt		_yzy()
#define tpp		_yzz()
#define tpq		_yzw()
#define tqs		_ywx()
#define tqt		_ywy()
#define tqp		_ywz()
#define tqq		_yww()
#define pss		_zxx()
#define pst		_zxy()
#define psp		_zxz()
#define psq		_zxw()
#define pts		_zyx()
#define ptt		_zyy()
#define ptp		_zyz()
#define ptq		_zyw()
#define pps		_zzx()
#define ppt		_zzy()
#define ppp		_zzz()
#define ppq		_zzw()
#define pqs		_zwx()
#define pqt		_zwy()
#define pqp		_zwz()
#define pqq		_zww()
#define qss		_wxx()
#define qst		_wxy()
#define qsp		_wxz()
#define qsq		_wxw()
#define qts		_wyx()
#define qtt		_wyy()
#define qtp		_wyz()
#define qtq		_wyw()
#define qps		_wzx()
#define qpt		_wzy()
#define qpp		_wzz()
#define qpq		_wzw()
#define qqs		_wwx()
#define qqt		_wwy()
#define qqp		_wwz()
#define qqq		_www()
#define ssss	_xxxx()
#define ssst	_xxxy()
#define sssp	_xxxz()
#define sssq	_xxxw()
#define ssts	_xxyx()
#define sstt	_xxyy()
#define sstp	_xxyz()
#define sstq	_xxyw()
#define ssps	_xxzx()
#define sspt	_xxzy()
#define sspp	_xxzz()
#define sspq	_xxzw()
#define ssqs	_xxwx()
#define ssqt	_xxwy()
#define ssqp	_xxwz()
#define ssqq	_xxww()
#define stss	_xyxx()
#define stst	_xyxy()
#define stsp	_xyxz()
#define stsq	_xyxw()
#define stts	_xyyx()
#define sttt	_xyyy()
#define sttp	_xyyz()
#define sttq	_xyyw()
#define stps	_xyzx()
#define stpt	_xyzy()
#define stpp	_xyzz()
#define stpq	_xyzw()
#define stqs	_xywx()
#define stqt	_xywy()
#define stqp	_xywz()
#define stqq	_xyww()
#define spss	_xzxx()
#define spst	_xzxy()
#define spsp	_xzxz()
#define spsq	_xzxw()
#define spts	_xzyx()
#define sptt	_xzyy()
#define sptp	_xzyz()
#define sptq	_xzyw()
#define spps	_xzzx()
#define sppt	_xzzy()
#define sppp	_xzzz()
#define sppq	_xzzw()
#define spqs	_xzwx()
#define spqt	_xzwy()
#define spqp	_xzwz()
#define spqq	_xzww()
#define sqss	_xwxx()
#define sqst	_xwxy()
#define sqsp	_xwxz()
#define sqsq	_xwxw()
#define sqts	_xwyx()
#define sqtt	_xwyy()
#define sqtp	_xwyz()
#define sqtq	_xwyw()
#define sqps	_xwzx()
#define sqpt	_xwzy()
#define sqpp	_xwzz()
#define sqpq	_xwzw()
#define sqqs	_xwwx()
#define sqqt	_xwwy()
#define sqqp	_xwwz()
#define sqqq	_xwww()
#define tsss	_yxxx()
#define tsst	_yxxy()
#define tssp	_yxxz()
#define tssq	_yxxw()
#define tsts	_yxyx()
#define tstt	_yxyy()
#define tstp	_yxyz()
#define tstq	_yxyw()
#define tsps	_yxzx()
#define tspt	_yxzy()
#define tspp	_yxzz()
#define tspq	_yxzw()
#define tsqs	_yxwx()
#define tsqt	_yxwy()
#define tsqp	_yxwz()
#define tsqq	_yxww()
#define ttss	_yyxx()
#define ttst	_yyxy()
#define ttsp	_yyxz()
#define ttsq	_yyxw()
#define ttts	_yyyx()
#define tttt	_yyyy()
#define tttp	_yyyz()
#define tttq	_yyyw()
#define ttps	_yyzx()
#define ttpt	_yyzy()
#define ttpp	_yyzz()
#define ttpq	_yyzw()
#define ttqs	_yywx()
#define ttqt	_yywy()
#define ttqp	_yywz()
#define ttqq	_yyww()
#define tpss	_yzxx()
#define tpst	_yzxy()
#define tpsp	_yzxz()
#define tpsq	_yzxw()
#define tpts	_yzyx()
#define tptt	_yzyy()
#define tptp	_yzyz()
#define tptq	_yzyw()
#define tpps	_yzzx()
#define tppt	_yzzy()
#define tppp	_yzzz()
#define tppq	_yzzw()
#define tpqs	_yzwx()
#define tpqt	_yzwy()
#define tpqp	_yzwz()
#define tpqq	_yzww()
#define tqss	_ywxx()
#define tqst	_ywxy()
#define tqsp	_ywxz()
#define tqsq	_ywxw()
#define tqts	_ywyx()
#define tqtt	_ywyy()
#define tqtp	_ywyz()
#define tqtq	_ywyw()
#define tqps	_ywzx()
#define tqpt	_ywzy()
#define tqpp	_ywzz()
#define tqpq	_ywzw()
#define tqqs	_ywwx()
#define tqqt	_ywwy()
#define tqqp	_ywwz()
#define tqqq	_ywww()
#define psss	_zxxx()
#define psst	_zxxy()
#define pssp	_zxxz()
#define pssq	_zxxw()
#define psts	_zxyx()
#define pstt	_zxyy()
#define pstp	_zxyz()
#define pstq	_zxyw()
#define psps	_zxzx()
#define pspt	_zxzy()
#define pspp	_zxzz()
#define pspq	_zxzw()
#define psqs	_zxwx()
#define psqt	_zxwy()
#define psqp	_zxwz()
#define psqq	_zxww()
#define ptss	_zyxx()
#define ptst	_zyxy()
#define ptsp	_zyxz()
#define ptsq	_zyxw()
#define ptts	_zyyx()
#define pttt	_zyyy()
#define pttp	_zyyz()
#define pttq	_zyyw()
#define ptps	_zyzx()
#define ptpt	_zyzy()
#define ptpp	_zyzz()
#define ptpq	_zyzw()
#define ptqs	_zywx()
#define ptqt	_zywy()
#define ptqp	_zywz()
#define ptqq	_zyww()
#define ppss	_zzxx()
#define ppst	_zzxy()
#define ppsp	_zzxz()
#define ppsq	_zzxw()
#define ppts	_zzyx()
#define pptt	_zzyy()
#define pptp	_zzyz()
#define pptq	_zzyw()
#define ppps	_zzzx()
#define pppt	_zzzy()
#define pppp	_zzzz()
#define pppq	_zzzw()
#define ppqs	_zzwx()
#define ppqt	_zzwy()
#define ppqp	_zzwz()
#define ppqq	_zzww()
#define pqss	_zwxx()
#define pqst	_zwxy()
#define pqsp	_zwxz()
#define pqsq	_zwxw()
#define pqts	_zwyx()
#define pqtt	_zwyy()
#define pqtp	_zwyz()
#define pqtq	_zwyw()
#define pqps	_zwzx()
#define pqpt	_zwzy()
#define pqpp	_zwzz()
#define pqpq	_zwzw()
#define pqqs	_zwwx()
#define pqqt	_zwwy()
#define pqqp	_zwwz()
#define pqqq	_zwww()
#define qsss	_wxxx()
#define qsst	_wxxy()
#define qssp	_wxxz()
#define qssq	_wxxw()
#define qsts	_wxyx()
#define qstt	_wxyy()
#define qstp	_wxyz()
#define qstq	_wxyw()
#define qsps	_wxzx()
#define qspt	_wxzy()
#define qspp	_wxzz()
#define qspq	_wxzw()
#define qsqs	_wxwx()
#define qsqt	_wxwy()
#define qsqp	_wxwz()
#define qsqq	_wxww()
#define qtss	_wyxx()
#define qtst	_wyxy()
#define qtsp	_wyxz()
#define qtsq	_wyxw()
#define qtts	_wyyx()
#define qttt	_wyyy()
#define qttp	_wyyz()
#define qttq	_wyyw()
#define qtps	_wyzx()
#define qtpt	_wyzy()
#define qtpp	_wyzz()
#define qtpq	_wyzw()
#define qtqs	_wywx()
#define qtqt	_wywy()
#define qtqp	_wywz()
#define qtqq	_wyww()
#define qpss	_wzxx()
#define qpst	_wzxy()
#define qpsp	_wzxz()
#define qpsq	_wzxw()
#define qpts	_wzyx()
#define qptt	_wzyy()
#define qptp	_wzyz()
#define qptq	_wzyw()
#define qpps	_wzzx()
#define qppt	_wzzy()
#define qppp	_wzzz()
#define qppq	_wzzw()
#define qpqs	_wzwx()
#define qpqt	_wzwy()
#define qpqp	_wzwz()
#define qpqq	_wzww()
#define qqss	_wwxx()
#define qqst	_wwxy()
#define qqsp	_wwxz()
#define qqsq	_wwxw()
#define qqts	_wwyx()
#define qqtt	_wwyy()
#define qqtp	_wwyz()
#define qqtq	_wwyw()
#define qqps	_wwzx()
#define qqpt	_wwzy()
#define qqpp	_wwzz()
#define qqpq	_wwzw()
#define qqqs	_wwwx()
#define qqqt	_wwwy()
#define qqqp	_wwwz()
#define qqqq	_wwww()

#pragma endregion
// IJK_SWIZZLE_MACRO_IMPL


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_