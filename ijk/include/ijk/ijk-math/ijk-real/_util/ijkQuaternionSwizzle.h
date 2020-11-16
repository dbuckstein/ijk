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

	ijkQuaternionSwizzle.h
	Quaternion class types and functions (built for C++).
*/

#ifdef _IJK_QUATERNION_H_
#ifndef _IJK_QUATERNIONSWIZZLE_H_
#define _IJK_QUATERNIONSWIZZLE_H_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template<typename type> struct ttquat;		// Template quaternion base type
template<typename type> struct ttdualquat;	// Template dual quaternion base type


//-----------------------------------------------------------------------------

// Template quaternion type.
template<typename type>
struct ttquat
{
	ttquat();																// Identity quaternion: zero vector, one real.
	ttquat(type const& xc, type const& yc, type const& zc, type const& wc);	// Initialize components.

	union
	{
		type v[4];
		struct { ttvec3<type> vec; ttvec1<type> re; };
		struct { type x, y, z, w; };
	};
};


//-----------------------------------------------------------------------------

// Template dual quaternion type.
template<typename type>
struct ttdualquat
{
	ttdualquat();															// Identity dual quaternion: zero vector, one real, zero dual.
	ttdualquat(ttquat<type> const& qr, ttquat<type> const& qd);				// Initialize components.
	
	union
	{
		type v[8];
		type m[2][4];
		ttquat<type> q[2];
		struct { ttquat<type> qr, qd; };
		struct { type xr, yr, zr, wr, xd, yd, zd, wd; };
	};
};


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#include "_inl/ijkQuaternionSwizzle.inl"


#ifdef __cplusplus

//-----------------------------------------------------------------------------

typedef ttquat<f32>		fquat;		// Single-precision floating point quaternion
typedef ttdualquat<f32>	fdualquat;	// Single-precision floating point dual quaternion

typedef ttquat<f64>		dquat;		// Double-precision floating point quaternion
typedef ttdualquat<f64>	ddualquat;	// Double-precision floating point dual quaternion


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#endif	// !_IJK_QUATERNIONSWIZZLE_H_
#endif	// _IJK_QUATERNION_H_