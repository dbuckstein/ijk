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

#define IJK_SWIZZLE_DECL(ownerType,returnType,constFunc,x,y,z,w)						returnType _##x##y##z##w() constFunc
#define IJK_SWIZZLE_IMPL(ownerType,returnType,constFunc,x,y,...)						inline returnType ownerType::_##x##y##z##w() constFunc { return returnType(x,y __VA_OPT__(,) __VA_ARGS__); }


//#define IJK_SWIZZLE1(swizzleMacro,ownerType,returnType2,returnType3,returnType4,...)	
//#define IJK_SWIZZLE2(swizzleMacro,ownerType,returnType2,returnType3,returnType4,...)	
//#define IJK_SWIZZLE3(swizzleMacro,ownerType,returnType2,returnType3,returnType4,...)	
//#define IJK_SWIZZLE4(swizzleMacro,ownerType,returnType2,returnType3,returnType4,...)	
	// __VA_ARGS__ is empty or 'const', appends to collector type (empty is unique only, const suffix gathers all)


#define IJK_SWIZZLE(n,t,x,y,z,w)						t##vec##n const _##x##y##z##w() const													// Declare swizzle function.
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
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union ivec2
{
	int2 v;
	struct { i32 x, y; };
	struct { i32 r, g; };
	struct { i32 s, t; };

#ifdef __cplusplus
	struct ivec2r
	{
		ivec2 operator=(ivec2 const v);			// Convert to vec2 (pass by const value, need copy).
		ivec2 operator=(ivec2r const& v);		// Convert to vec2 (calls former).
	private:
		i32& x, & y;							// References to values.
		ivec2r(i32& xr, i32& yr);				// Construct using individual values so they can be reordered.
		friend union ivec2;
		friend union ivec3;
		friend union ivec4;
	};

	explicit ivec2(i32 const xy = 0);			// Construct vector with all elements set to single scalar.
	explicit ivec2(i32 const xc, i32 const yc);	// Construct vector with elements set individually.
	ivec2(ivec2r const& xy);
	ivec2(int2 const xy);						// Construct vector given integer array-based vector.
	explicit ivec2(flt2 const xy);				// Construct vector given float array-based vector.
	explicit ivec2(dbl2 const xy);				// Construct vector given double array-based vector.
	ivec2(ivec2 const& xy);						// Construct vector given another 2D integer vector.
	explicit ivec2(ivec3 const& xy);			// Construct vector given the first two elements of a 3D integer vector.
	explicit ivec2(ivec4 const& xy);			// Construct vector given the first two elements of a 4D integer vector.
	explicit ivec2(fvec2 const& xy);			// Construct vector given a 2D float vector.
	explicit ivec2(fvec3 const& xy);			// Construct vector given the first two elements of a 3D float vector.
	explicit ivec2(fvec4 const& xy);			// Construct vector given the first two elements of a 4D float vector.
	explicit ivec2(dvec2 const& xy);			// Construct vector given a 2D double vector.
	explicit ivec2(dvec3 const& xy);			// Construct vector given the first two elements of a 3D double vector.
	explicit ivec2(dvec4 const& xy);			// Construct vector given the first two elements of a 4D double vector.

	ivec2& operator+();
	ivec2& operator =(int2 const xy);
	ivec2& operator =(ivec2 const& xy);
	ivec2& operator =(ivec2r const& xy);
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

	IJK_SWIZZLE_XY(IJK_SWIZZLE, IJK_SWIZZLE, IJK_SWIZZLE, 2, 3, 4, i);
	ivec2r _xy();
	ivec2r _yx();
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
	ivec3(int3 const xyz);											// Construct vector given integer array-based vector.
	explicit ivec3(flt3 const xyz);									// Construct vector given float array-based vector.
	explicit ivec3(dbl3 const xyz);									// Construct vector given double array-based vector.
	explicit ivec3(ivec2 const& xy, i32 const z = 0);				// Construct vector given a 2D integer vector and the third element.
	ivec3(ivec3 const& xyz);										// Construct vector given another 3D integer vector.
	explicit ivec3(ivec4 const& xyz);								// Construct vector given the first three elements of a 4D integer vector.
	explicit ivec3(fvec2 const& xy, i32 const z = 0);				// Construct vector given a 2D float vector and the third element.
	explicit ivec3(fvec3 const& xyz);								// Construct vector given a 3D float vector.
	explicit ivec3(fvec4 const& xyz);								// Construct vector given the first three elements of a 4D float vector.
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
	ivec3& operator =(fvec2 const& xy);
	ivec3& operator =(fvec3 const& xyz);
	ivec3& operator =(fvec4 const& xyz);
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
	ivec4(int4 const xyzw);															// Construct vector given integer array-based vector.
	explicit ivec4(flt4 const xyzw);												// Construct vector given float array-based vector.
	explicit ivec4(dbl4 const xyzw);												// Construct vector given double array-based vector.
	explicit ivec4(ivec2 const& xy, i32 const z = 0, i32 const w = 0);				// Construct vector given a 2D integer vector and the third and fourth elements.
	explicit ivec4(ivec3 const& xyz, i32 const w = 0);								// Construct vector given a 3D integer vector and the fourth element.
	ivec4(ivec4 const& xyzw);														// Construct vector given another 4D integer vector.
	explicit ivec4(fvec2 const& xy, i32 const z = 0, i32 const w = 0);				// Construct vector given a 2D float vector and the third and fourth elements.
	explicit ivec4(fvec3 const& xyz, i32 const w = 0);								// Construct vector given a 3D float vector and the fourth element.
	explicit ivec4(fvec4 const& xyzw);												// Construct vector given a 4D float vector.
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
	ivec4& operator =(fvec2 const& xy);
	ivec4& operator =(fvec3 const& xyz);
	ivec4& operator =(fvec4 const& xyzw);
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
//		members r, g: individual named elements representing a color
//		members s, t: individual named elements representing a parametric coordinate
union fvec2
{
	flt2 v;
	struct { flt x, y; };
	struct { flt r, g; };
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

	fvec2& operator+();
	fvec2& operator +=(flt const s);
	fvec2& operator +=(fvec2 const& v);
	fvec2& operator -=(flt const s);
	fvec2& operator -=(fvec2 const& v);
	fvec2& operator *=(flt const s);
	fvec2& operator *=(fvec2 const& v);
	fvec2& operator /=(flt const s);
	fvec2& operator /=(fvec2 const& v);
	flt& operator[](index const i);
	operator fltv();

	fvec2 const operator+() const;
	fvec2 const operator-() const;
	fvec2 const operator +(flt const s) const;
	fvec2 const operator +(fvec2 const& v) const;
	fvec2 const operator -(flt const s) const;
	fvec2 const operator -(fvec2 const& v) const;
	fvec2 const operator *(flt const s) const;
	fvec2 const operator *(fvec2 const& v) const;
	fvec2 const operator /(flt const s) const;
	fvec2 const operator /(fvec2 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(fvec2 const& v) const;
	bool operator !=(fvec2 const& v) const;

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

	fvec3& operator+();
	fvec3& operator +=(flt const s);
	fvec3& operator +=(fvec3 const& v);
	fvec3& operator -=(flt const s);
	fvec3& operator -=(fvec3 const& v);
	fvec3& operator *=(flt const s);
	fvec3& operator *=(fvec3 const& v);
	fvec3& operator /=(flt const s);
	fvec3& operator /=(fvec3 const& v);
	flt& operator[](index const i);
	operator fltv();

	fvec3 const operator+() const;
	fvec3 const operator-() const;
	fvec3 const operator +(flt const s) const;
	fvec3 const operator +(fvec3 const& v) const;
	fvec3 const operator -(flt const s) const;
	fvec3 const operator -(fvec3 const& v) const;
	fvec3 const operator *(flt const s) const;
	fvec3 const operator *(fvec3 const& v) const;
	fvec3 const operator /(flt const s) const;
	fvec3 const operator /(fvec3 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(fvec3 const& v) const;
	bool operator !=(fvec3 const& v) const;

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

	fvec4& operator+();
	fvec4& operator +=(flt const s);
	fvec4& operator +=(fvec4 const& v);
	fvec4& operator -=(flt const s);
	fvec4& operator -=(fvec4 const& v);
	fvec4& operator *=(flt const s);
	fvec4& operator *=(fvec4 const& v);
	fvec4& operator /=(flt const s);
	fvec4& operator /=(fvec4 const& v);
	flt& operator[](index const i);
	operator fltv();

	fvec4 const operator+() const;
	fvec4 const operator-() const;
	fvec4 const operator +(flt const s) const;
	fvec4 const operator +(fvec4 const& v) const;
	fvec4 const operator -(flt const s) const;
	fvec4 const operator -(fvec4 const& v) const;
	fvec4 const operator *(flt const s) const;
	fvec4 const operator *(fvec4 const& v) const;
	fvec4 const operator /(flt const s) const;
	fvec4 const operator /(fvec4 const& v) const;
	flt operator[](index const i) const;
	operator fltkv() const;

	bool operator ==(fvec3 const& v) const;
	bool operator !=(fvec3 const& v) const;

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

// Select real vector types.
#ifdef IJK_REAL_DBL
typedef dvec2	rvec2;		// Real 2D vector data structure type is 2D double vector.
typedef dvec3	rvec3;		// Real 3D vector data structure type is 3D double vector.
typedef dvec4	rvec4;		// Real 4D vector data structure type is 4D double vector.
#else	// !IJK_REAL_DBL
typedef fvec2	rvec2;		// Real 2D vector data structure type is 2D float vector.
typedef fvec3	rvec3;		// Real 3D vector data structure type is 3D float vector.
typedef fvec4	rvec4;		// Real 4D vector data structure type is 4D float vector.
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