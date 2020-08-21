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

	i32 operator[](uindex const i) const;
	i32& operator[](uindex const i);

	ivec2 const _xx() const;
	ivec2 const _xy() const;
	ivec2 const _yx() const;
	ivec2 const _yy() const;
	ivec3 const _xxx() const;
	ivec3 const _xxy() const;
	ivec3 const _xyx() const;
	ivec3 const _xyy() const;
	ivec3 const _yxx() const;
	ivec3 const _yxy() const;
	ivec3 const _yyx() const;
	ivec3 const _yyy() const;
	ivec4 const _xxxx() const;
	ivec4 const _xxxy() const;
	ivec4 const _xxyx() const;
	ivec4 const _xxyy() const;
	ivec4 const _xyxx() const;
	ivec4 const _xyxy() const;
	ivec4 const _xyyx() const;
	ivec4 const _xyyy() const;
	ivec4 const _yxxx() const;
	ivec4 const _yxxy() const;
	ivec4 const _yxyx() const;
	ivec4 const _yxyy() const;
	ivec4 const _yyxx() const;
	ivec4 const _yyxy() const;
	ivec4 const _yyyx() const;
	ivec4 const _yyyy() const;
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

	i32 operator[](uindex const i) const;
	i32& operator[](uindex const i);

	ivec2 const _xx() const;
	ivec2 const _xy() const;
	ivec2 const _xz() const;
	ivec2 const _yx() const;
	ivec2 const _yy() const;
	ivec2 const _yz() const;
	ivec2 const _zx() const;
	ivec2 const _zy() const;
	ivec2 const _zz() const;
	ivec3 const _xxx() const;
	ivec3 const _xxy() const;
	ivec3 const _xxz() const;
	ivec3 const _xyx() const;
	ivec3 const _xyy() const;
	ivec3 const _xyz() const;
	ivec3 const _xzx() const;
	ivec3 const _xzy() const;
	ivec3 const _xzz() const;
	ivec3 const _yxx() const;
	ivec3 const _yxy() const;
	ivec3 const _yxz() const;
	ivec3 const _yyx() const;
	ivec3 const _yyy() const;
	ivec3 const _yyz() const;
	ivec3 const _yzx() const;
	ivec3 const _yzy() const;
	ivec3 const _yzz() const;
	ivec3 const _zxx() const;
	ivec3 const _zxy() const;
	ivec3 const _zxz() const;
	ivec3 const _zyx() const;
	ivec3 const _zyy() const;
	ivec3 const _zyz() const;
	ivec3 const _zzx() const;
	ivec3 const _zzy() const;
	ivec3 const _zzz() const;
	ivec4 const _xxxx() const;
	ivec4 const _xxxy() const;
	ivec4 const _xxxz() const;
	ivec4 const _xxyx() const;
	ivec4 const _xxyy() const;
	ivec4 const _xxyz() const;
	ivec4 const _xxzx() const;
	ivec4 const _xxzy() const;
	ivec4 const _xxzz() const;
	ivec4 const _xyxx() const;
	ivec4 const _xyxy() const;
	ivec4 const _xyxz() const;
	ivec4 const _xyyx() const;
	ivec4 const _xyyy() const;
	ivec4 const _xyyz() const;
	ivec4 const _xyzx() const;
	ivec4 const _xyzy() const;
	ivec4 const _xyzz() const;
	ivec4 const _xzxx() const;
	ivec4 const _xzxy() const;
	ivec4 const _xzxz() const;
	ivec4 const _xzyx() const;
	ivec4 const _xzyy() const;
	ivec4 const _xzyz() const;
	ivec4 const _xzzx() const;
	ivec4 const _xzzy() const;
	ivec4 const _xzzz() const;
	ivec4 const _yxxx() const;
	ivec4 const _yxxy() const;
	ivec4 const _yxxz() const;
	ivec4 const _yxyx() const;
	ivec4 const _yxyy() const;
	ivec4 const _yxyz() const;
	ivec4 const _yxzx() const;
	ivec4 const _yxzy() const;
	ivec4 const _yxzz() const;
	ivec4 const _yyxx() const;
	ivec4 const _yyxy() const;
	ivec4 const _yyxz() const;
	ivec4 const _yyyx() const;
	ivec4 const _yyyy() const;
	ivec4 const _yyyz() const;
	ivec4 const _yyzx() const;
	ivec4 const _yyzy() const;
	ivec4 const _yyzz() const;
	ivec4 const _yzxx() const;
	ivec4 const _yzxy() const;
	ivec4 const _yzxz() const;
	ivec4 const _yzyx() const;
	ivec4 const _yzyy() const;
	ivec4 const _yzyz() const;
	ivec4 const _yzzx() const;
	ivec4 const _yzzy() const;
	ivec4 const _yzzz() const;
	ivec4 const _zxxx() const;
	ivec4 const _zxxy() const;
	ivec4 const _zxxz() const;
	ivec4 const _zxyx() const;
	ivec4 const _zxyy() const;
	ivec4 const _zxyz() const;
	ivec4 const _zxzx() const;
	ivec4 const _zxzy() const;
	ivec4 const _zxzz() const;
	ivec4 const _zyxx() const;
	ivec4 const _zyxy() const;
	ivec4 const _zyxz() const;
	ivec4 const _zyyx() const;
	ivec4 const _zyyy() const;
	ivec4 const _zyyz() const;
	ivec4 const _zyzx() const;
	ivec4 const _zyzy() const;
	ivec4 const _zyzz() const;
	ivec4 const _zzxx() const;
	ivec4 const _zzxy() const;
	ivec4 const _zzxz() const;
	ivec4 const _zzyx() const;
	ivec4 const _zzyy() const;
	ivec4 const _zzyz() const;
	ivec4 const _zzzx() const;
	ivec4 const _zzzy() const;
	ivec4 const _zzzz() const;
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

	i32 operator[](uindex const i) const;
	i32& operator[](uindex const i);

	ivec2 const _xx() const;
	ivec2 const _xy() const;
	ivec2 const _xz() const;
	ivec2 const _xw() const;
	ivec2 const _yx() const;
	ivec2 const _yy() const;
	ivec2 const _yz() const;
	ivec2 const _yw() const;
	ivec2 const _zx() const;
	ivec2 const _zy() const;
	ivec2 const _zz() const;
	ivec2 const _zw() const;
	ivec2 const _wx() const;
	ivec2 const _wy() const;
	ivec2 const _wz() const;
	ivec2 const _ww() const;
	ivec3 const _xxx() const;
	ivec3 const _xxy() const;
	ivec3 const _xxz() const;
	ivec3 const _xxw() const;
	ivec3 const _xyx() const;
	ivec3 const _xyy() const;
	ivec3 const _xyz() const;
	ivec3 const _xyw() const;
	ivec3 const _xzx() const;
	ivec3 const _xzy() const;
	ivec3 const _xzz() const;
	ivec3 const _xzw() const;
	ivec3 const _xwx() const;
	ivec3 const _xwy() const;
	ivec3 const _xwz() const;
	ivec3 const _xww() const;
	ivec3 const _yxx() const;
	ivec3 const _yxy() const;
	ivec3 const _yxz() const;
	ivec3 const _yxw() const;
	ivec3 const _yyx() const;
	ivec3 const _yyy() const;
	ivec3 const _yyz() const;
	ivec3 const _yyw() const;
	ivec3 const _yzx() const;
	ivec3 const _yzy() const;
	ivec3 const _yzz() const;
	ivec3 const _yzw() const;
	ivec3 const _ywx() const;
	ivec3 const _ywy() const;
	ivec3 const _ywz() const;
	ivec3 const _yww() const;
	ivec3 const _zxx() const;
	ivec3 const _zxy() const;
	ivec3 const _zxz() const;
	ivec3 const _zxw() const;
	ivec3 const _zyx() const;
	ivec3 const _zyy() const;
	ivec3 const _zyz() const;
	ivec3 const _zyw() const;
	ivec3 const _zzx() const;
	ivec3 const _zzy() const;
	ivec3 const _zzz() const;
	ivec3 const _zzw() const;
	ivec3 const _zwx() const;
	ivec3 const _zwy() const;
	ivec3 const _zwz() const;
	ivec3 const _zww() const;
	ivec3 const _wxx() const;
	ivec3 const _wxy() const;
	ivec3 const _wxz() const;
	ivec3 const _wxw() const;
	ivec3 const _wyx() const;
	ivec3 const _wyy() const;
	ivec3 const _wyz() const;
	ivec3 const _wyw() const;
	ivec3 const _wzx() const;
	ivec3 const _wzy() const;
	ivec3 const _wzz() const;
	ivec3 const _wzw() const;
	ivec3 const _wwx() const;
	ivec3 const _wwy() const;
	ivec3 const _wwz() const;
	ivec3 const _www() const;
	ivec4 const _xxxx() const;
	ivec4 const _xxxy() const;
	ivec4 const _xxxz() const;
	ivec4 const _xxxw() const;
	ivec4 const _xxyx() const;
	ivec4 const _xxyy() const;
	ivec4 const _xxyz() const;
	ivec4 const _xxyw() const;
	ivec4 const _xxzx() const;
	ivec4 const _xxzy() const;
	ivec4 const _xxzz() const;
	ivec4 const _xxzw() const;
	ivec4 const _xxwx() const;
	ivec4 const _xxwy() const;
	ivec4 const _xxwz() const;
	ivec4 const _xxww() const;
	ivec4 const _xyxx() const;
	ivec4 const _xyxy() const;
	ivec4 const _xyxz() const;
	ivec4 const _xyxw() const;
	ivec4 const _xyyx() const;
	ivec4 const _xyyy() const;
	ivec4 const _xyyz() const;
	ivec4 const _xyyw() const;
	ivec4 const _xyzx() const;
	ivec4 const _xyzy() const;
	ivec4 const _xyzz() const;
	ivec4 const _xyzw() const;
	ivec4 const _xywx() const;
	ivec4 const _xywy() const;
	ivec4 const _xywz() const;
	ivec4 const _xyww() const;
	ivec4 const _xzxx() const;
	ivec4 const _xzxy() const;
	ivec4 const _xzxz() const;
	ivec4 const _xzxw() const;
	ivec4 const _xzyx() const;
	ivec4 const _xzyy() const;
	ivec4 const _xzyz() const;
	ivec4 const _xzyw() const;
	ivec4 const _xzzx() const;
	ivec4 const _xzzy() const;
	ivec4 const _xzzz() const;
	ivec4 const _xzzw() const;
	ivec4 const _xzwx() const;
	ivec4 const _xzwy() const;
	ivec4 const _xzwz() const;
	ivec4 const _xzww() const;
	ivec4 const _xwxx() const;
	ivec4 const _xwxy() const;
	ivec4 const _xwxz() const;
	ivec4 const _xwxw() const;
	ivec4 const _xwyx() const;
	ivec4 const _xwyy() const;
	ivec4 const _xwyz() const;
	ivec4 const _xwyw() const;
	ivec4 const _xwzx() const;
	ivec4 const _xwzy() const;
	ivec4 const _xwzz() const;
	ivec4 const _xwzw() const;
	ivec4 const _xwwx() const;
	ivec4 const _xwwy() const;
	ivec4 const _xwwz() const;
	ivec4 const _xwww() const;
	ivec4 const _yxxx() const;
	ivec4 const _yxxy() const;
	ivec4 const _yxxz() const;
	ivec4 const _yxxw() const;
	ivec4 const _yxyx() const;
	ivec4 const _yxyy() const;
	ivec4 const _yxyz() const;
	ivec4 const _yxyw() const;
	ivec4 const _yxzx() const;
	ivec4 const _yxzy() const;
	ivec4 const _yxzz() const;
	ivec4 const _yxzw() const;
	ivec4 const _yxwx() const;
	ivec4 const _yxwy() const;
	ivec4 const _yxwz() const;
	ivec4 const _yxww() const;
	ivec4 const _yyxx() const;
	ivec4 const _yyxy() const;
	ivec4 const _yyxz() const;
	ivec4 const _yyxw() const;
	ivec4 const _yyyx() const;
	ivec4 const _yyyy() const;
	ivec4 const _yyyz() const;
	ivec4 const _yyyw() const;
	ivec4 const _yyzx() const;
	ivec4 const _yyzy() const;
	ivec4 const _yyzz() const;
	ivec4 const _yyzw() const;
	ivec4 const _yywx() const;
	ivec4 const _yywy() const;
	ivec4 const _yywz() const;
	ivec4 const _yyww() const;
	ivec4 const _yzxx() const;
	ivec4 const _yzxy() const;
	ivec4 const _yzxz() const;
	ivec4 const _yzxw() const;
	ivec4 const _yzyx() const;
	ivec4 const _yzyy() const;
	ivec4 const _yzyz() const;
	ivec4 const _yzyw() const;
	ivec4 const _yzzx() const;
	ivec4 const _yzzy() const;
	ivec4 const _yzzz() const;
	ivec4 const _yzzw() const;
	ivec4 const _yzwx() const;
	ivec4 const _yzwy() const;
	ivec4 const _yzwz() const;
	ivec4 const _yzww() const;
	ivec4 const _ywxx() const;
	ivec4 const _ywxy() const;
	ivec4 const _ywxz() const;
	ivec4 const _ywxw() const;
	ivec4 const _ywyx() const;
	ivec4 const _ywyy() const;
	ivec4 const _ywyz() const;
	ivec4 const _ywyw() const;
	ivec4 const _ywzx() const;
	ivec4 const _ywzy() const;
	ivec4 const _ywzz() const;
	ivec4 const _ywzw() const;
	ivec4 const _ywwx() const;
	ivec4 const _ywwy() const;
	ivec4 const _ywwz() const;
	ivec4 const _ywww() const;
	ivec4 const _zxxx() const;
	ivec4 const _zxxy() const;
	ivec4 const _zxxz() const;
	ivec4 const _zxxw() const;
	ivec4 const _zxyx() const;
	ivec4 const _zxyy() const;
	ivec4 const _zxyz() const;
	ivec4 const _zxyw() const;
	ivec4 const _zxzx() const;
	ivec4 const _zxzy() const;
	ivec4 const _zxzz() const;
	ivec4 const _zxzw() const;
	ivec4 const _zxwx() const;
	ivec4 const _zxwy() const;
	ivec4 const _zxwz() const;
	ivec4 const _zxww() const;
	ivec4 const _zyxx() const;
	ivec4 const _zyxy() const;
	ivec4 const _zyxz() const;
	ivec4 const _zyxw() const;
	ivec4 const _zyyx() const;
	ivec4 const _zyyy() const;
	ivec4 const _zyyz() const;
	ivec4 const _zyyw() const;
	ivec4 const _zyzx() const;
	ivec4 const _zyzy() const;
	ivec4 const _zyzz() const;
	ivec4 const _zyzw() const;
	ivec4 const _zywx() const;
	ivec4 const _zywy() const;
	ivec4 const _zywz() const;
	ivec4 const _zyww() const;
	ivec4 const _zzxx() const;
	ivec4 const _zzxy() const;
	ivec4 const _zzxz() const;
	ivec4 const _zzxw() const;
	ivec4 const _zzyx() const;
	ivec4 const _zzyy() const;
	ivec4 const _zzyz() const;
	ivec4 const _zzyw() const;
	ivec4 const _zzzx() const;
	ivec4 const _zzzy() const;
	ivec4 const _zzzz() const;
	ivec4 const _zzzw() const;
	ivec4 const _zzwx() const;
	ivec4 const _zzwy() const;
	ivec4 const _zzwz() const;
	ivec4 const _zzww() const;
	ivec4 const _zwxx() const;
	ivec4 const _zwxy() const;
	ivec4 const _zwxz() const;
	ivec4 const _zwxw() const;
	ivec4 const _zwyx() const;
	ivec4 const _zwyy() const;
	ivec4 const _zwyz() const;
	ivec4 const _zwyw() const;
	ivec4 const _zwzx() const;
	ivec4 const _zwzy() const;
	ivec4 const _zwzz() const;
	ivec4 const _zwzw() const;
	ivec4 const _zwwx() const;
	ivec4 const _zwwy() const;
	ivec4 const _zwwz() const;
	ivec4 const _zwww() const;
	ivec4 const _wxxx() const;
	ivec4 const _wxxy() const;
	ivec4 const _wxxz() const;
	ivec4 const _wxxw() const;
	ivec4 const _wxyx() const;
	ivec4 const _wxyy() const;
	ivec4 const _wxyz() const;
	ivec4 const _wxyw() const;
	ivec4 const _wxzx() const;
	ivec4 const _wxzy() const;
	ivec4 const _wxzz() const;
	ivec4 const _wxzw() const;
	ivec4 const _wxwx() const;
	ivec4 const _wxwy() const;
	ivec4 const _wxwz() const;
	ivec4 const _wxww() const;
	ivec4 const _wyxx() const;
	ivec4 const _wyxy() const;
	ivec4 const _wyxz() const;
	ivec4 const _wyxw() const;
	ivec4 const _wyyx() const;
	ivec4 const _wyyy() const;
	ivec4 const _wyyz() const;
	ivec4 const _wyyw() const;
	ivec4 const _wyzx() const;
	ivec4 const _wyzy() const;
	ivec4 const _wyzz() const;
	ivec4 const _wyzw() const;
	ivec4 const _wywx() const;
	ivec4 const _wywy() const;
	ivec4 const _wywz() const;
	ivec4 const _wyww() const;
	ivec4 const _wzxx() const;
	ivec4 const _wzxy() const;
	ivec4 const _wzxz() const;
	ivec4 const _wzxw() const;
	ivec4 const _wzyx() const;
	ivec4 const _wzyy() const;
	ivec4 const _wzyz() const;
	ivec4 const _wzyw() const;
	ivec4 const _wzzx() const;
	ivec4 const _wzzy() const;
	ivec4 const _wzzz() const;
	ivec4 const _wzzw() const;
	ivec4 const _wzwx() const;
	ivec4 const _wzwy() const;
	ivec4 const _wzwz() const;
	ivec4 const _wzww() const;
	ivec4 const _wwxx() const;
	ivec4 const _wwxy() const;
	ivec4 const _wwxz() const;
	ivec4 const _wwxw() const;
	ivec4 const _wwyx() const;
	ivec4 const _wwyy() const;
	ivec4 const _wwyz() const;
	ivec4 const _wwyw() const;
	ivec4 const _wwzx() const;
	ivec4 const _wwzy() const;
	ivec4 const _wwzz() const;
	ivec4 const _wwzw() const;
	ivec4 const _wwwx() const;
	ivec4 const _wwwy() const;
	ivec4 const _wwwz() const;
	ivec4 const _wwww() const;
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

	flt operator[](uindex const i) const;
	flt& operator[](uindex const i);

	fvec2 const _xx() const;
	fvec2 const _xy() const;
	fvec2 const _yx() const;
	fvec2 const _yy() const;
	fvec3 const _xxx() const;
	fvec3 const _xxy() const;
	fvec3 const _xyx() const;
	fvec3 const _xyy() const;
	fvec3 const _yxx() const;
	fvec3 const _yxy() const;
	fvec3 const _yyx() const;
	fvec3 const _yyy() const;
	fvec4 const _xxxx() const;
	fvec4 const _xxxy() const;
	fvec4 const _xxyx() const;
	fvec4 const _xxyy() const;
	fvec4 const _xyxx() const;
	fvec4 const _xyxy() const;
	fvec4 const _xyyx() const;
	fvec4 const _xyyy() const;
	fvec4 const _yxxx() const;
	fvec4 const _yxxy() const;
	fvec4 const _yxyx() const;
	fvec4 const _yxyy() const;
	fvec4 const _yyxx() const;
	fvec4 const _yyxy() const;
	fvec4 const _yyyx() const;
	fvec4 const _yyyy() const;
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

	flt operator[](uindex const i) const;
	flt& operator[](uindex const i);

	fvec2 const _xx() const;
	fvec2 const _xy() const;
	fvec2 const _xz() const;
	fvec2 const _yx() const;
	fvec2 const _yy() const;
	fvec2 const _yz() const;
	fvec2 const _zx() const;
	fvec2 const _zy() const;
	fvec2 const _zz() const;
	fvec3 const _xxx() const;
	fvec3 const _xxy() const;
	fvec3 const _xxz() const;
	fvec3 const _xyx() const;
	fvec3 const _xyy() const;
	fvec3 const _xyz() const;
	fvec3 const _xzx() const;
	fvec3 const _xzy() const;
	fvec3 const _xzz() const;
	fvec3 const _yxx() const;
	fvec3 const _yxy() const;
	fvec3 const _yxz() const;
	fvec3 const _yyx() const;
	fvec3 const _yyy() const;
	fvec3 const _yyz() const;
	fvec3 const _yzx() const;
	fvec3 const _yzy() const;
	fvec3 const _yzz() const;
	fvec3 const _zxx() const;
	fvec3 const _zxy() const;
	fvec3 const _zxz() const;
	fvec3 const _zyx() const;
	fvec3 const _zyy() const;
	fvec3 const _zyz() const;
	fvec3 const _zzx() const;
	fvec3 const _zzy() const;
	fvec3 const _zzz() const;
	fvec4 const _xxxx() const;
	fvec4 const _xxxy() const;
	fvec4 const _xxxz() const;
	fvec4 const _xxyx() const;
	fvec4 const _xxyy() const;
	fvec4 const _xxyz() const;
	fvec4 const _xxzx() const;
	fvec4 const _xxzy() const;
	fvec4 const _xxzz() const;
	fvec4 const _xyxx() const;
	fvec4 const _xyxy() const;
	fvec4 const _xyxz() const;
	fvec4 const _xyyx() const;
	fvec4 const _xyyy() const;
	fvec4 const _xyyz() const;
	fvec4 const _xyzx() const;
	fvec4 const _xyzy() const;
	fvec4 const _xyzz() const;
	fvec4 const _xzxx() const;
	fvec4 const _xzxy() const;
	fvec4 const _xzxz() const;
	fvec4 const _xzyx() const;
	fvec4 const _xzyy() const;
	fvec4 const _xzyz() const;
	fvec4 const _xzzx() const;
	fvec4 const _xzzy() const;
	fvec4 const _xzzz() const;
	fvec4 const _yxxx() const;
	fvec4 const _yxxy() const;
	fvec4 const _yxxz() const;
	fvec4 const _yxyx() const;
	fvec4 const _yxyy() const;
	fvec4 const _yxyz() const;
	fvec4 const _yxzx() const;
	fvec4 const _yxzy() const;
	fvec4 const _yxzz() const;
	fvec4 const _yyxx() const;
	fvec4 const _yyxy() const;
	fvec4 const _yyxz() const;
	fvec4 const _yyyx() const;
	fvec4 const _yyyy() const;
	fvec4 const _yyyz() const;
	fvec4 const _yyzx() const;
	fvec4 const _yyzy() const;
	fvec4 const _yyzz() const;
	fvec4 const _yzxx() const;
	fvec4 const _yzxy() const;
	fvec4 const _yzxz() const;
	fvec4 const _yzyx() const;
	fvec4 const _yzyy() const;
	fvec4 const _yzyz() const;
	fvec4 const _yzzx() const;
	fvec4 const _yzzy() const;
	fvec4 const _yzzz() const;
	fvec4 const _zxxx() const;
	fvec4 const _zxxy() const;
	fvec4 const _zxxz() const;
	fvec4 const _zxyx() const;
	fvec4 const _zxyy() const;
	fvec4 const _zxyz() const;
	fvec4 const _zxzx() const;
	fvec4 const _zxzy() const;
	fvec4 const _zxzz() const;
	fvec4 const _zyxx() const;
	fvec4 const _zyxy() const;
	fvec4 const _zyxz() const;
	fvec4 const _zyyx() const;
	fvec4 const _zyyy() const;
	fvec4 const _zyyz() const;
	fvec4 const _zyzx() const;
	fvec4 const _zyzy() const;
	fvec4 const _zyzz() const;
	fvec4 const _zzxx() const;
	fvec4 const _zzxy() const;
	fvec4 const _zzxz() const;
	fvec4 const _zzyx() const;
	fvec4 const _zzyy() const;
	fvec4 const _zzyz() const;
	fvec4 const _zzzx() const;
	fvec4 const _zzzy() const;
	fvec4 const _zzzz() const;
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

	flt operator[](uindex const i) const;
	flt& operator[](uindex const i);

	fvec2 const _xx() const;
	fvec2 const _xy() const;
	fvec2 const _xz() const;
	fvec2 const _xw() const;
	fvec2 const _yx() const;
	fvec2 const _yy() const;
	fvec2 const _yz() const;
	fvec2 const _yw() const;
	fvec2 const _zx() const;
	fvec2 const _zy() const;
	fvec2 const _zz() const;
	fvec2 const _zw() const;
	fvec2 const _wx() const;
	fvec2 const _wy() const;
	fvec2 const _wz() const;
	fvec2 const _ww() const;
	fvec3 const _xxx() const;
	fvec3 const _xxy() const;
	fvec3 const _xxz() const;
	fvec3 const _xxw() const;
	fvec3 const _xyx() const;
	fvec3 const _xyy() const;
	fvec3 const _xyz() const;
	fvec3 const _xyw() const;
	fvec3 const _xzx() const;
	fvec3 const _xzy() const;
	fvec3 const _xzz() const;
	fvec3 const _xzw() const;
	fvec3 const _xwx() const;
	fvec3 const _xwy() const;
	fvec3 const _xwz() const;
	fvec3 const _xww() const;
	fvec3 const _yxx() const;
	fvec3 const _yxy() const;
	fvec3 const _yxz() const;
	fvec3 const _yxw() const;
	fvec3 const _yyx() const;
	fvec3 const _yyy() const;
	fvec3 const _yyz() const;
	fvec3 const _yyw() const;
	fvec3 const _yzx() const;
	fvec3 const _yzy() const;
	fvec3 const _yzz() const;
	fvec3 const _yzw() const;
	fvec3 const _ywx() const;
	fvec3 const _ywy() const;
	fvec3 const _ywz() const;
	fvec3 const _yww() const;
	fvec3 const _zxx() const;
	fvec3 const _zxy() const;
	fvec3 const _zxz() const;
	fvec3 const _zxw() const;
	fvec3 const _zyx() const;
	fvec3 const _zyy() const;
	fvec3 const _zyz() const;
	fvec3 const _zyw() const;
	fvec3 const _zzx() const;
	fvec3 const _zzy() const;
	fvec3 const _zzz() const;
	fvec3 const _zzw() const;
	fvec3 const _zwx() const;
	fvec3 const _zwy() const;
	fvec3 const _zwz() const;
	fvec3 const _zww() const;
	fvec3 const _wxx() const;
	fvec3 const _wxy() const;
	fvec3 const _wxz() const;
	fvec3 const _wxw() const;
	fvec3 const _wyx() const;
	fvec3 const _wyy() const;
	fvec3 const _wyz() const;
	fvec3 const _wyw() const;
	fvec3 const _wzx() const;
	fvec3 const _wzy() const;
	fvec3 const _wzz() const;
	fvec3 const _wzw() const;
	fvec3 const _wwx() const;
	fvec3 const _wwy() const;
	fvec3 const _wwz() const;
	fvec3 const _www() const;
	fvec4 const _xxxx() const;
	fvec4 const _xxxy() const;
	fvec4 const _xxxz() const;
	fvec4 const _xxxw() const;
	fvec4 const _xxyx() const;
	fvec4 const _xxyy() const;
	fvec4 const _xxyz() const;
	fvec4 const _xxyw() const;
	fvec4 const _xxzx() const;
	fvec4 const _xxzy() const;
	fvec4 const _xxzz() const;
	fvec4 const _xxzw() const;
	fvec4 const _xxwx() const;
	fvec4 const _xxwy() const;
	fvec4 const _xxwz() const;
	fvec4 const _xxww() const;
	fvec4 const _xyxx() const;
	fvec4 const _xyxy() const;
	fvec4 const _xyxz() const;
	fvec4 const _xyxw() const;
	fvec4 const _xyyx() const;
	fvec4 const _xyyy() const;
	fvec4 const _xyyz() const;
	fvec4 const _xyyw() const;
	fvec4 const _xyzx() const;
	fvec4 const _xyzy() const;
	fvec4 const _xyzz() const;
	fvec4 const _xyzw() const;
	fvec4 const _xywx() const;
	fvec4 const _xywy() const;
	fvec4 const _xywz() const;
	fvec4 const _xyww() const;
	fvec4 const _xzxx() const;
	fvec4 const _xzxy() const;
	fvec4 const _xzxz() const;
	fvec4 const _xzxw() const;
	fvec4 const _xzyx() const;
	fvec4 const _xzyy() const;
	fvec4 const _xzyz() const;
	fvec4 const _xzyw() const;
	fvec4 const _xzzx() const;
	fvec4 const _xzzy() const;
	fvec4 const _xzzz() const;
	fvec4 const _xzzw() const;
	fvec4 const _xzwx() const;
	fvec4 const _xzwy() const;
	fvec4 const _xzwz() const;
	fvec4 const _xzww() const;
	fvec4 const _xwxx() const;
	fvec4 const _xwxy() const;
	fvec4 const _xwxz() const;
	fvec4 const _xwxw() const;
	fvec4 const _xwyx() const;
	fvec4 const _xwyy() const;
	fvec4 const _xwyz() const;
	fvec4 const _xwyw() const;
	fvec4 const _xwzx() const;
	fvec4 const _xwzy() const;
	fvec4 const _xwzz() const;
	fvec4 const _xwzw() const;
	fvec4 const _xwwx() const;
	fvec4 const _xwwy() const;
	fvec4 const _xwwz() const;
	fvec4 const _xwww() const;
	fvec4 const _yxxx() const;
	fvec4 const _yxxy() const;
	fvec4 const _yxxz() const;
	fvec4 const _yxxw() const;
	fvec4 const _yxyx() const;
	fvec4 const _yxyy() const;
	fvec4 const _yxyz() const;
	fvec4 const _yxyw() const;
	fvec4 const _yxzx() const;
	fvec4 const _yxzy() const;
	fvec4 const _yxzz() const;
	fvec4 const _yxzw() const;
	fvec4 const _yxwx() const;
	fvec4 const _yxwy() const;
	fvec4 const _yxwz() const;
	fvec4 const _yxww() const;
	fvec4 const _yyxx() const;
	fvec4 const _yyxy() const;
	fvec4 const _yyxz() const;
	fvec4 const _yyxw() const;
	fvec4 const _yyyx() const;
	fvec4 const _yyyy() const;
	fvec4 const _yyyz() const;
	fvec4 const _yyyw() const;
	fvec4 const _yyzx() const;
	fvec4 const _yyzy() const;
	fvec4 const _yyzz() const;
	fvec4 const _yyzw() const;
	fvec4 const _yywx() const;
	fvec4 const _yywy() const;
	fvec4 const _yywz() const;
	fvec4 const _yyww() const;
	fvec4 const _yzxx() const;
	fvec4 const _yzxy() const;
	fvec4 const _yzxz() const;
	fvec4 const _yzxw() const;
	fvec4 const _yzyx() const;
	fvec4 const _yzyy() const;
	fvec4 const _yzyz() const;
	fvec4 const _yzyw() const;
	fvec4 const _yzzx() const;
	fvec4 const _yzzy() const;
	fvec4 const _yzzz() const;
	fvec4 const _yzzw() const;
	fvec4 const _yzwx() const;
	fvec4 const _yzwy() const;
	fvec4 const _yzwz() const;
	fvec4 const _yzww() const;
	fvec4 const _ywxx() const;
	fvec4 const _ywxy() const;
	fvec4 const _ywxz() const;
	fvec4 const _ywxw() const;
	fvec4 const _ywyx() const;
	fvec4 const _ywyy() const;
	fvec4 const _ywyz() const;
	fvec4 const _ywyw() const;
	fvec4 const _ywzx() const;
	fvec4 const _ywzy() const;
	fvec4 const _ywzz() const;
	fvec4 const _ywzw() const;
	fvec4 const _ywwx() const;
	fvec4 const _ywwy() const;
	fvec4 const _ywwz() const;
	fvec4 const _ywww() const;
	fvec4 const _zxxx() const;
	fvec4 const _zxxy() const;
	fvec4 const _zxxz() const;
	fvec4 const _zxxw() const;
	fvec4 const _zxyx() const;
	fvec4 const _zxyy() const;
	fvec4 const _zxyz() const;
	fvec4 const _zxyw() const;
	fvec4 const _zxzx() const;
	fvec4 const _zxzy() const;
	fvec4 const _zxzz() const;
	fvec4 const _zxzw() const;
	fvec4 const _zxwx() const;
	fvec4 const _zxwy() const;
	fvec4 const _zxwz() const;
	fvec4 const _zxww() const;
	fvec4 const _zyxx() const;
	fvec4 const _zyxy() const;
	fvec4 const _zyxz() const;
	fvec4 const _zyxw() const;
	fvec4 const _zyyx() const;
	fvec4 const _zyyy() const;
	fvec4 const _zyyz() const;
	fvec4 const _zyyw() const;
	fvec4 const _zyzx() const;
	fvec4 const _zyzy() const;
	fvec4 const _zyzz() const;
	fvec4 const _zyzw() const;
	fvec4 const _zywx() const;
	fvec4 const _zywy() const;
	fvec4 const _zywz() const;
	fvec4 const _zyww() const;
	fvec4 const _zzxx() const;
	fvec4 const _zzxy() const;
	fvec4 const _zzxz() const;
	fvec4 const _zzxw() const;
	fvec4 const _zzyx() const;
	fvec4 const _zzyy() const;
	fvec4 const _zzyz() const;
	fvec4 const _zzyw() const;
	fvec4 const _zzzx() const;
	fvec4 const _zzzy() const;
	fvec4 const _zzzz() const;
	fvec4 const _zzzw() const;
	fvec4 const _zzwx() const;
	fvec4 const _zzwy() const;
	fvec4 const _zzwz() const;
	fvec4 const _zzww() const;
	fvec4 const _zwxx() const;
	fvec4 const _zwxy() const;
	fvec4 const _zwxz() const;
	fvec4 const _zwxw() const;
	fvec4 const _zwyx() const;
	fvec4 const _zwyy() const;
	fvec4 const _zwyz() const;
	fvec4 const _zwyw() const;
	fvec4 const _zwzx() const;
	fvec4 const _zwzy() const;
	fvec4 const _zwzz() const;
	fvec4 const _zwzw() const;
	fvec4 const _zwwx() const;
	fvec4 const _zwwy() const;
	fvec4 const _zwwz() const;
	fvec4 const _zwww() const;
	fvec4 const _wxxx() const;
	fvec4 const _wxxy() const;
	fvec4 const _wxxz() const;
	fvec4 const _wxxw() const;
	fvec4 const _wxyx() const;
	fvec4 const _wxyy() const;
	fvec4 const _wxyz() const;
	fvec4 const _wxyw() const;
	fvec4 const _wxzx() const;
	fvec4 const _wxzy() const;
	fvec4 const _wxzz() const;
	fvec4 const _wxzw() const;
	fvec4 const _wxwx() const;
	fvec4 const _wxwy() const;
	fvec4 const _wxwz() const;
	fvec4 const _wxww() const;
	fvec4 const _wyxx() const;
	fvec4 const _wyxy() const;
	fvec4 const _wyxz() const;
	fvec4 const _wyxw() const;
	fvec4 const _wyyx() const;
	fvec4 const _wyyy() const;
	fvec4 const _wyyz() const;
	fvec4 const _wyyw() const;
	fvec4 const _wyzx() const;
	fvec4 const _wyzy() const;
	fvec4 const _wyzz() const;
	fvec4 const _wyzw() const;
	fvec4 const _wywx() const;
	fvec4 const _wywy() const;
	fvec4 const _wywz() const;
	fvec4 const _wyww() const;
	fvec4 const _wzxx() const;
	fvec4 const _wzxy() const;
	fvec4 const _wzxz() const;
	fvec4 const _wzxw() const;
	fvec4 const _wzyx() const;
	fvec4 const _wzyy() const;
	fvec4 const _wzyz() const;
	fvec4 const _wzyw() const;
	fvec4 const _wzzx() const;
	fvec4 const _wzzy() const;
	fvec4 const _wzzz() const;
	fvec4 const _wzzw() const;
	fvec4 const _wzwx() const;
	fvec4 const _wzwy() const;
	fvec4 const _wzwz() const;
	fvec4 const _wzww() const;
	fvec4 const _wwxx() const;
	fvec4 const _wwxy() const;
	fvec4 const _wwxz() const;
	fvec4 const _wwxw() const;
	fvec4 const _wwyx() const;
	fvec4 const _wwyy() const;
	fvec4 const _wwyz() const;
	fvec4 const _wwyw() const;
	fvec4 const _wwzx() const;
	fvec4 const _wwzy() const;
	fvec4 const _wwzz() const;
	fvec4 const _wwzw() const;
	fvec4 const _wwwx() const;
	fvec4 const _wwwy() const;
	fvec4 const _wwwz() const;
	fvec4 const _wwww() const;
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

	dbl operator[](uindex const i) const;
	dbl& operator[](uindex const i);

	dvec2 const _xx() const;
	dvec2 const _xy() const;
	dvec2 const _yx() const;
	dvec2 const _yy() const;
	dvec3 const _xxx() const;
	dvec3 const _xxy() const;
	dvec3 const _xyx() const;
	dvec3 const _xyy() const;
	dvec3 const _yxx() const;
	dvec3 const _yxy() const;
	dvec3 const _yyx() const;
	dvec3 const _yyy() const;
	dvec4 const _xxxx() const;
	dvec4 const _xxxy() const;
	dvec4 const _xxyx() const;
	dvec4 const _xxyy() const;
	dvec4 const _xyxx() const;
	dvec4 const _xyxy() const;
	dvec4 const _xyyx() const;
	dvec4 const _xyyy() const;
	dvec4 const _yxxx() const;
	dvec4 const _yxxy() const;
	dvec4 const _yxyx() const;
	dvec4 const _yxyy() const;
	dvec4 const _yyxx() const;
	dvec4 const _yyxy() const;
	dvec4 const _yyyx() const;
	dvec4 const _yyyy() const;
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

	dbl operator[](uindex const i) const;
	dbl& operator[](uindex const i);

	dvec2 const _xx() const;
	dvec2 const _xy() const;
	dvec2 const _xz() const;
	dvec2 const _yx() const;
	dvec2 const _yy() const;
	dvec2 const _yz() const;
	dvec2 const _zx() const;
	dvec2 const _zy() const;
	dvec2 const _zz() const;
	dvec3 const _xxx() const;
	dvec3 const _xxy() const;
	dvec3 const _xxz() const;
	dvec3 const _xyx() const;
	dvec3 const _xyy() const;
	dvec3 const _xyz() const;
	dvec3 const _xzx() const;
	dvec3 const _xzy() const;
	dvec3 const _xzz() const;
	dvec3 const _yxx() const;
	dvec3 const _yxy() const;
	dvec3 const _yxz() const;
	dvec3 const _yyx() const;
	dvec3 const _yyy() const;
	dvec3 const _yyz() const;
	dvec3 const _yzx() const;
	dvec3 const _yzy() const;
	dvec3 const _yzz() const;
	dvec3 const _zxx() const;
	dvec3 const _zxy() const;
	dvec3 const _zxz() const;
	dvec3 const _zyx() const;
	dvec3 const _zyy() const;
	dvec3 const _zyz() const;
	dvec3 const _zzx() const;
	dvec3 const _zzy() const;
	dvec3 const _zzz() const;
	dvec4 const _xxxx() const;
	dvec4 const _xxxy() const;
	dvec4 const _xxxz() const;
	dvec4 const _xxyx() const;
	dvec4 const _xxyy() const;
	dvec4 const _xxyz() const;
	dvec4 const _xxzx() const;
	dvec4 const _xxzy() const;
	dvec4 const _xxzz() const;
	dvec4 const _xyxx() const;
	dvec4 const _xyxy() const;
	dvec4 const _xyxz() const;
	dvec4 const _xyyx() const;
	dvec4 const _xyyy() const;
	dvec4 const _xyyz() const;
	dvec4 const _xyzx() const;
	dvec4 const _xyzy() const;
	dvec4 const _xyzz() const;
	dvec4 const _xzxx() const;
	dvec4 const _xzxy() const;
	dvec4 const _xzxz() const;
	dvec4 const _xzyx() const;
	dvec4 const _xzyy() const;
	dvec4 const _xzyz() const;
	dvec4 const _xzzx() const;
	dvec4 const _xzzy() const;
	dvec4 const _xzzz() const;
	dvec4 const _yxxx() const;
	dvec4 const _yxxy() const;
	dvec4 const _yxxz() const;
	dvec4 const _yxyx() const;
	dvec4 const _yxyy() const;
	dvec4 const _yxyz() const;
	dvec4 const _yxzx() const;
	dvec4 const _yxzy() const;
	dvec4 const _yxzz() const;
	dvec4 const _yyxx() const;
	dvec4 const _yyxy() const;
	dvec4 const _yyxz() const;
	dvec4 const _yyyx() const;
	dvec4 const _yyyy() const;
	dvec4 const _yyyz() const;
	dvec4 const _yyzx() const;
	dvec4 const _yyzy() const;
	dvec4 const _yyzz() const;
	dvec4 const _yzxx() const;
	dvec4 const _yzxy() const;
	dvec4 const _yzxz() const;
	dvec4 const _yzyx() const;
	dvec4 const _yzyy() const;
	dvec4 const _yzyz() const;
	dvec4 const _yzzx() const;
	dvec4 const _yzzy() const;
	dvec4 const _yzzz() const;
	dvec4 const _zxxx() const;
	dvec4 const _zxxy() const;
	dvec4 const _zxxz() const;
	dvec4 const _zxyx() const;
	dvec4 const _zxyy() const;
	dvec4 const _zxyz() const;
	dvec4 const _zxzx() const;
	dvec4 const _zxzy() const;
	dvec4 const _zxzz() const;
	dvec4 const _zyxx() const;
	dvec4 const _zyxy() const;
	dvec4 const _zyxz() const;
	dvec4 const _zyyx() const;
	dvec4 const _zyyy() const;
	dvec4 const _zyyz() const;
	dvec4 const _zyzx() const;
	dvec4 const _zyzy() const;
	dvec4 const _zyzz() const;
	dvec4 const _zzxx() const;
	dvec4 const _zzxy() const;
	dvec4 const _zzxz() const;
	dvec4 const _zzyx() const;
	dvec4 const _zzyy() const;
	dvec4 const _zzyz() const;
	dvec4 const _zzzx() const;
	dvec4 const _zzzy() const;
	dvec4 const _zzzz() const;
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

	dbl operator[](uindex const i) const;
	dbl& operator[](uindex const i);

	dvec2 const _xx() const;
	dvec2 const _xy() const;
	dvec2 const _xz() const;
	dvec2 const _xw() const;
	dvec2 const _yx() const;
	dvec2 const _yy() const;
	dvec2 const _yz() const;
	dvec2 const _yw() const;
	dvec2 const _zx() const;
	dvec2 const _zy() const;
	dvec2 const _zz() const;
	dvec2 const _zw() const;
	dvec2 const _wx() const;
	dvec2 const _wy() const;
	dvec2 const _wz() const;
	dvec2 const _ww() const;
	dvec3 const _xxx() const;
	dvec3 const _xxy() const;
	dvec3 const _xxz() const;
	dvec3 const _xxw() const;
	dvec3 const _xyx() const;
	dvec3 const _xyy() const;
	dvec3 const _xyz() const;
	dvec3 const _xyw() const;
	dvec3 const _xzx() const;
	dvec3 const _xzy() const;
	dvec3 const _xzz() const;
	dvec3 const _xzw() const;
	dvec3 const _xwx() const;
	dvec3 const _xwy() const;
	dvec3 const _xwz() const;
	dvec3 const _xww() const;
	dvec3 const _yxx() const;
	dvec3 const _yxy() const;
	dvec3 const _yxz() const;
	dvec3 const _yxw() const;
	dvec3 const _yyx() const;
	dvec3 const _yyy() const;
	dvec3 const _yyz() const;
	dvec3 const _yyw() const;
	dvec3 const _yzx() const;
	dvec3 const _yzy() const;
	dvec3 const _yzz() const;
	dvec3 const _yzw() const;
	dvec3 const _ywx() const;
	dvec3 const _ywy() const;
	dvec3 const _ywz() const;
	dvec3 const _yww() const;
	dvec3 const _zxx() const;
	dvec3 const _zxy() const;
	dvec3 const _zxz() const;
	dvec3 const _zxw() const;
	dvec3 const _zyx() const;
	dvec3 const _zyy() const;
	dvec3 const _zyz() const;
	dvec3 const _zyw() const;
	dvec3 const _zzx() const;
	dvec3 const _zzy() const;
	dvec3 const _zzz() const;
	dvec3 const _zzw() const;
	dvec3 const _zwx() const;
	dvec3 const _zwy() const;
	dvec3 const _zwz() const;
	dvec3 const _zww() const;
	dvec3 const _wxx() const;
	dvec3 const _wxy() const;
	dvec3 const _wxz() const;
	dvec3 const _wxw() const;
	dvec3 const _wyx() const;
	dvec3 const _wyy() const;
	dvec3 const _wyz() const;
	dvec3 const _wyw() const;
	dvec3 const _wzx() const;
	dvec3 const _wzy() const;
	dvec3 const _wzz() const;
	dvec3 const _wzw() const;
	dvec3 const _wwx() const;
	dvec3 const _wwy() const;
	dvec3 const _wwz() const;
	dvec3 const _www() const;
	dvec4 const _xxxx() const;
	dvec4 const _xxxy() const;
	dvec4 const _xxxz() const;
	dvec4 const _xxxw() const;
	dvec4 const _xxyx() const;
	dvec4 const _xxyy() const;
	dvec4 const _xxyz() const;
	dvec4 const _xxyw() const;
	dvec4 const _xxzx() const;
	dvec4 const _xxzy() const;
	dvec4 const _xxzz() const;
	dvec4 const _xxzw() const;
	dvec4 const _xxwx() const;
	dvec4 const _xxwy() const;
	dvec4 const _xxwz() const;
	dvec4 const _xxww() const;
	dvec4 const _xyxx() const;
	dvec4 const _xyxy() const;
	dvec4 const _xyxz() const;
	dvec4 const _xyxw() const;
	dvec4 const _xyyx() const;
	dvec4 const _xyyy() const;
	dvec4 const _xyyz() const;
	dvec4 const _xyyw() const;
	dvec4 const _xyzx() const;
	dvec4 const _xyzy() const;
	dvec4 const _xyzz() const;
	dvec4 const _xyzw() const;
	dvec4 const _xywx() const;
	dvec4 const _xywy() const;
	dvec4 const _xywz() const;
	dvec4 const _xyww() const;
	dvec4 const _xzxx() const;
	dvec4 const _xzxy() const;
	dvec4 const _xzxz() const;
	dvec4 const _xzxw() const;
	dvec4 const _xzyx() const;
	dvec4 const _xzyy() const;
	dvec4 const _xzyz() const;
	dvec4 const _xzyw() const;
	dvec4 const _xzzx() const;
	dvec4 const _xzzy() const;
	dvec4 const _xzzz() const;
	dvec4 const _xzzw() const;
	dvec4 const _xzwx() const;
	dvec4 const _xzwy() const;
	dvec4 const _xzwz() const;
	dvec4 const _xzww() const;
	dvec4 const _xwxx() const;
	dvec4 const _xwxy() const;
	dvec4 const _xwxz() const;
	dvec4 const _xwxw() const;
	dvec4 const _xwyx() const;
	dvec4 const _xwyy() const;
	dvec4 const _xwyz() const;
	dvec4 const _xwyw() const;
	dvec4 const _xwzx() const;
	dvec4 const _xwzy() const;
	dvec4 const _xwzz() const;
	dvec4 const _xwzw() const;
	dvec4 const _xwwx() const;
	dvec4 const _xwwy() const;
	dvec4 const _xwwz() const;
	dvec4 const _xwww() const;
	dvec4 const _yxxx() const;
	dvec4 const _yxxy() const;
	dvec4 const _yxxz() const;
	dvec4 const _yxxw() const;
	dvec4 const _yxyx() const;
	dvec4 const _yxyy() const;
	dvec4 const _yxyz() const;
	dvec4 const _yxyw() const;
	dvec4 const _yxzx() const;
	dvec4 const _yxzy() const;
	dvec4 const _yxzz() const;
	dvec4 const _yxzw() const;
	dvec4 const _yxwx() const;
	dvec4 const _yxwy() const;
	dvec4 const _yxwz() const;
	dvec4 const _yxww() const;
	dvec4 const _yyxx() const;
	dvec4 const _yyxy() const;
	dvec4 const _yyxz() const;
	dvec4 const _yyxw() const;
	dvec4 const _yyyx() const;
	dvec4 const _yyyy() const;
	dvec4 const _yyyz() const;
	dvec4 const _yyyw() const;
	dvec4 const _yyzx() const;
	dvec4 const _yyzy() const;
	dvec4 const _yyzz() const;
	dvec4 const _yyzw() const;
	dvec4 const _yywx() const;
	dvec4 const _yywy() const;
	dvec4 const _yywz() const;
	dvec4 const _yyww() const;
	dvec4 const _yzxx() const;
	dvec4 const _yzxy() const;
	dvec4 const _yzxz() const;
	dvec4 const _yzxw() const;
	dvec4 const _yzyx() const;
	dvec4 const _yzyy() const;
	dvec4 const _yzyz() const;
	dvec4 const _yzyw() const;
	dvec4 const _yzzx() const;
	dvec4 const _yzzy() const;
	dvec4 const _yzzz() const;
	dvec4 const _yzzw() const;
	dvec4 const _yzwx() const;
	dvec4 const _yzwy() const;
	dvec4 const _yzwz() const;
	dvec4 const _yzww() const;
	dvec4 const _ywxx() const;
	dvec4 const _ywxy() const;
	dvec4 const _ywxz() const;
	dvec4 const _ywxw() const;
	dvec4 const _ywyx() const;
	dvec4 const _ywyy() const;
	dvec4 const _ywyz() const;
	dvec4 const _ywyw() const;
	dvec4 const _ywzx() const;
	dvec4 const _ywzy() const;
	dvec4 const _ywzz() const;
	dvec4 const _ywzw() const;
	dvec4 const _ywwx() const;
	dvec4 const _ywwy() const;
	dvec4 const _ywwz() const;
	dvec4 const _ywww() const;
	dvec4 const _zxxx() const;
	dvec4 const _zxxy() const;
	dvec4 const _zxxz() const;
	dvec4 const _zxxw() const;
	dvec4 const _zxyx() const;
	dvec4 const _zxyy() const;
	dvec4 const _zxyz() const;
	dvec4 const _zxyw() const;
	dvec4 const _zxzx() const;
	dvec4 const _zxzy() const;
	dvec4 const _zxzz() const;
	dvec4 const _zxzw() const;
	dvec4 const _zxwx() const;
	dvec4 const _zxwy() const;
	dvec4 const _zxwz() const;
	dvec4 const _zxww() const;
	dvec4 const _zyxx() const;
	dvec4 const _zyxy() const;
	dvec4 const _zyxz() const;
	dvec4 const _zyxw() const;
	dvec4 const _zyyx() const;
	dvec4 const _zyyy() const;
	dvec4 const _zyyz() const;
	dvec4 const _zyyw() const;
	dvec4 const _zyzx() const;
	dvec4 const _zyzy() const;
	dvec4 const _zyzz() const;
	dvec4 const _zyzw() const;
	dvec4 const _zywx() const;
	dvec4 const _zywy() const;
	dvec4 const _zywz() const;
	dvec4 const _zyww() const;
	dvec4 const _zzxx() const;
	dvec4 const _zzxy() const;
	dvec4 const _zzxz() const;
	dvec4 const _zzxw() const;
	dvec4 const _zzyx() const;
	dvec4 const _zzyy() const;
	dvec4 const _zzyz() const;
	dvec4 const _zzyw() const;
	dvec4 const _zzzx() const;
	dvec4 const _zzzy() const;
	dvec4 const _zzzz() const;
	dvec4 const _zzzw() const;
	dvec4 const _zzwx() const;
	dvec4 const _zzwy() const;
	dvec4 const _zzwz() const;
	dvec4 const _zzww() const;
	dvec4 const _zwxx() const;
	dvec4 const _zwxy() const;
	dvec4 const _zwxz() const;
	dvec4 const _zwxw() const;
	dvec4 const _zwyx() const;
	dvec4 const _zwyy() const;
	dvec4 const _zwyz() const;
	dvec4 const _zwyw() const;
	dvec4 const _zwzx() const;
	dvec4 const _zwzy() const;
	dvec4 const _zwzz() const;
	dvec4 const _zwzw() const;
	dvec4 const _zwwx() const;
	dvec4 const _zwwy() const;
	dvec4 const _zwwz() const;
	dvec4 const _zwww() const;
	dvec4 const _wxxx() const;
	dvec4 const _wxxy() const;
	dvec4 const _wxxz() const;
	dvec4 const _wxxw() const;
	dvec4 const _wxyx() const;
	dvec4 const _wxyy() const;
	dvec4 const _wxyz() const;
	dvec4 const _wxyw() const;
	dvec4 const _wxzx() const;
	dvec4 const _wxzy() const;
	dvec4 const _wxzz() const;
	dvec4 const _wxzw() const;
	dvec4 const _wxwx() const;
	dvec4 const _wxwy() const;
	dvec4 const _wxwz() const;
	dvec4 const _wxww() const;
	dvec4 const _wyxx() const;
	dvec4 const _wyxy() const;
	dvec4 const _wyxz() const;
	dvec4 const _wyxw() const;
	dvec4 const _wyyx() const;
	dvec4 const _wyyy() const;
	dvec4 const _wyyz() const;
	dvec4 const _wyyw() const;
	dvec4 const _wyzx() const;
	dvec4 const _wyzy() const;
	dvec4 const _wyzz() const;
	dvec4 const _wyzw() const;
	dvec4 const _wywx() const;
	dvec4 const _wywy() const;
	dvec4 const _wywz() const;
	dvec4 const _wyww() const;
	dvec4 const _wzxx() const;
	dvec4 const _wzxy() const;
	dvec4 const _wzxz() const;
	dvec4 const _wzxw() const;
	dvec4 const _wzyx() const;
	dvec4 const _wzyy() const;
	dvec4 const _wzyz() const;
	dvec4 const _wzyw() const;
	dvec4 const _wzzx() const;
	dvec4 const _wzzy() const;
	dvec4 const _wzzz() const;
	dvec4 const _wzzw() const;
	dvec4 const _wzwx() const;
	dvec4 const _wzwy() const;
	dvec4 const _wzwz() const;
	dvec4 const _wzww() const;
	dvec4 const _wwxx() const;
	dvec4 const _wwxy() const;
	dvec4 const _wwxz() const;
	dvec4 const _wwxw() const;
	dvec4 const _wwyx() const;
	dvec4 const _wwyy() const;
	dvec4 const _wwyz() const;
	dvec4 const _wwyw() const;
	dvec4 const _wwzx() const;
	dvec4 const _wwzy() const;
	dvec4 const _wwzz() const;
	dvec4 const _wwzw() const;
	dvec4 const _wwwx() const;
	dvec4 const _wwwy() const;
	dvec4 const _wwwz() const;
	dvec4 const _wwww() const;
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