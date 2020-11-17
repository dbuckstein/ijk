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
	ttquat();																	// Identity quaternion: zero vector, one real.
	ttquat(type const& xc, type const& yc, type const& zc, type const& wc);		// Initialize components.
	ttquat(ttquat const& qc);													// Initialize given quaternion to copy.
	ttquat(ttmat3<type> const& m);												// Initialize by converting 3D matrix.
	ttquat(ttmat4<type> const& m);												// Initialize by converting 4D matrix (upper-left 3D part).

	ttquat const operator *(ttvec3<type> const& v_rh) const;
	ttquat const operator *(ttvec4<type> const& v_rh) const;
	ttquat const operator +() const;
	ttquat const operator -() const;
	ttquat const operator *() const;	// Conjugate.
	ttquat const operator +(ttquat const& q_rh) const;
	ttquat const operator -(ttquat const& q_rh) const;
	ttquat const operator *(ttquat const& q_rh) const;
	ttquat const operator *(type const& s_rh) const;
	ttquat const operator /(type const& s_rh) const;
	type const operator [](index const i) const;
	operator type const* () const;

	ttquat& operator =(ttquat const& q_rh);
	ttquat& operator *=(ttvec3<type> const& v_rh);
	ttquat& operator *=(ttvec4<type> const& v_rh);
	ttquat& operator +=(ttquat const& q_rh);
	ttquat& operator -=(ttquat const& q_rh);
	ttquat& operator *=(ttquat const& q_rh);
	ttquat& operator *=(type const& s_rh);
	ttquat& operator /=(type const& s_rh);
	type& operator [](index const i);
	operator type* ();

	union
	{
		type v[4];
		struct { type vec[3]; type re; };
		struct { type x, y, z, w; };
	};
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)v; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)v; }
	operator ttmat3<type> const () const;
	operator ttmat4<type> const () const;
};

template<typename type> ttquat<type> const operator *(ttvec3<type> const& v_lh, ttquat<type> const& q_rh);
template<typename type> ttquat<type> const operator *(ttvec4<type> const& v_lh, ttquat<type> const& q_rh);
template<typename type> ttquat<type> const operator *(type const& s_lh, ttquat<type> const& q_rh);
template<typename type> ttquat<type> const operator /(type const& s_lh, ttquat<type> const& q_rh);


//-----------------------------------------------------------------------------

// Template dual quaternion type.
template<typename type>
struct ttdualquat
{
	ttdualquat();																// Identity dual quaternion: zero vector, one real, zero dual.
	ttdualquat(ttquat<type> const& qr, ttquat<type> const& qd);					// Initialize real and dual components.
	ttdualquat(ttdualquat const& dqc);											// Initialize given dual quaternion to copy.
	ttdualquat(ttmat4<type> const& m);											// Initialize by converting 4D transformation matrix.

	ttdualquat const operator *(ttvec3<type> const& v_rh) const;
	ttdualquat const operator *(ttvec4<type> const& v_rh) const;
	ttdualquat const operator +() const;
	ttdualquat const operator -() const;
	ttdualquat const operator !() const;	// Conjugate of dual part.
	ttdualquat const operator *() const;	// Conjugate of quaternions.
	ttdualquat const operator ~() const;	// Conjugate of quaternions and dual part.
	ttdualquat const operator +(ttdualquat const& dq_rh) const;
	ttdualquat const operator -(ttdualquat const& dq_rh) const;
	ttdualquat const operator *(ttdualquat const& dq_rh) const;
	ttdualquat const operator *(type const& s_rh) const;
	ttdualquat const operator /(type const& s_rh) const;
	ttquat<type> const operator [](index const i) const;
	operator type const* () const;

	ttdualquat& operator =(ttdualquat const& dq_rh);
	ttdualquat& operator *=(ttvec3<type> const& v_rh);
	ttdualquat& operator *=(ttvec4<type> const& v_rh);
	ttdualquat& operator +=(ttdualquat const& dq_rh);
	ttdualquat& operator -=(ttdualquat const& dq_rh);
	ttdualquat& operator *=(ttdualquat const& dq_rh);
	ttdualquat& operator *=(type const& s_rh);
	ttdualquat& operator /=(type const& s_rh);
	ttquat<type>& operator [](index const i);
	operator type* ();

	union
	{
		type v[8];
		type m[2][4];
		ttquat<type> q[2];
		struct { ttquat<type> qr, qd; };
	};
	inline operator ttquat<type> const* () const { return q; }
	inline operator ttquat<type>* () { return q; }
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)v; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)v; }
	operator ttmat4<type> const () const;
};

template<typename type> ttdualquat<type> const operator *(ttvec3<type> const& v_lh, ttdualquat<type> const& q_rh);
template<typename type> ttdualquat<type> const operator *(ttvec4<type> const& v_lh, ttdualquat<type> const& q_rh);
template<typename type> ttdualquat<type> const operator *(type const& s_lh, ttdualquat<type> const& dq_rh);
template<typename type> ttdualquat<type> const operator /(type const& s_lh, ttdualquat<type> const& dq_rh);


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