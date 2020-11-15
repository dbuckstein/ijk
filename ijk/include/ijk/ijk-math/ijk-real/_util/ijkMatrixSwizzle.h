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

	ijkMatrixSwizzle.h
	Matrix class types and functions (built for C++).
*/

#ifdef _IJK_MATRIX_H_
#ifndef _IJK_MATRIXSWIZZLE_H_
#define _IJK_MATRIXSWIZZLE_H_


#ifdef __cplusplus

//-----------------------------------------------------------------------------

template<typename type> struct ttmat2;	// Template 2D matrix base type
template<typename type> struct ttmat3;	// Template 3D matrix base type
template<typename type> struct ttmat4;	// Template 4D matrix base type


//-----------------------------------------------------------------------------

// Template 2D matrix type.
template<typename type>
struct ttmat2
{
	ttmat2(type const& diag = 1);									// Construct matrix with diagonal elements set to single scalar.
	ttmat2(type const& x0, type const& y0, type const& x1, type const& y1);	// Construct matrix with elements set individually.
	ttmat2(ttvec2<type> const& c0, ttvec2<type> const& c1);			// Construct matrix with columns set individually.
	ttmat2(ttmat2 const& mc);										// Construct matrix given another 2D matrix.
	explicit ttmat2(ttmat3<type> const& mc);						// Construct matrix given the upper-left part of a 3D matrix.
	explicit ttmat2(ttmat4<type> const& mc);						// Construct matrix given the upper-left part of a 4D matrix.

	explicit ttmat2(float2x2 const mc);								// Construct matrix given float array-based matrix.
	explicit ttmat2(double2x2 const mc);							// Construct matrix given double array-based matrix.
	explicit ttmat2(ttvec1<f32> const mc[2][2]);					// Construct matrix given float array-based matrix.
	explicit ttmat2(ttvec1<f64> const mc[2][2]);					// Construct matrix given double array-based matrix.

	ttmat2 const operator +() const;
	ttmat2 const operator +(ttmat2 const& m_rh) const;
	ttmat2 const operator -(ttmat2 const& m_rh) const;
	ttvec2<type> const operator *(ttvec2<type> const& m_rh) const;
	ttmat2 const operator *(ttmat2 const& m_rh) const;
	ttmat2 const operator *(type const& s_rh) const;
	ttmat2 const operator /(type const& s_rh) const;
	ttvec2<type> const operator [](index const i) const;
	operator type const* () const;

	ttmat2& operator =(ttmat2 const& m_rh);
	ttmat2& operator +=(ttmat2 const& m_rh);
	ttmat2& operator -=(ttmat2 const& m_rh);
	ttmat2& operator *=(ttmat2 const& m_rh);
	ttmat2& operator =(type const& s_rh);
	ttmat2& operator *=(type const& s_rh);
	ttmat2& operator /=(type const& s_rh);
	ttvec2<type>& operator [](index const i);
	operator type* ();

	union {
		type v[4];
		type m[2][2];
		ttvec2<type> c[2];
		struct { ttvec2<type> c0, c1; };
		struct { ttvec1<type> x0, y0, x1, y1; };
		struct { ttvec1<type> v00, v01, v02, v03; };
		struct { ttvec1<type> m00, m01, m10, m11; };
	};
	inline operator ttvec2<type> const* () const { return c; }
	inline operator ttvec2<type>* () { return c; }
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)v; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)v; }
};

template<typename type> ttmat2<type> const operator *(type const& s_lh, ttmat2<type> const& m_rh);
template<typename type> ttmat2<type> const operator /(type const& s_lh, ttmat2<type> const& m_rh);


//-----------------------------------------------------------------------------

// Template 3D matrix type.
template<typename type>
struct ttmat3
{
	ttmat3(type const& diag = 1);									// Construct matrix with diagonal elements set to single scalar.
	ttmat3(type const& x0, type const& y0, type const& z0, type const& x1, type const& y1, type const& z1, type const& x2, type const& y2, type const& z2);	// Construct matrix with elements set individually.
	ttmat3(ttvec3<type> const& c0, ttvec3<type> const& c1, ttvec3<type> const& c2);	// Construct matrix with columns set individually.
	explicit ttmat3(ttmat2<type> const& mc);						// Construct matrix given 2D matrix and remainder set to identity.
	ttmat3(ttmat3 const& mc);										// Construct matrix given another 3D matrix.
	explicit ttmat3(ttmat4<type> const& mc);						// Construct matrix given the upper-left part of a 4D matrix.

	explicit ttmat3(float3x3 const mc);								// Construct matrix given float array-based matrix.
	explicit ttmat3(double3x3 const mc);							// Construct matrix given double array-based matrix.
	explicit ttmat3(ttvec1<f32> const mc[3][3]);					// Construct matrix given float array-based matrix.
	explicit ttmat3(ttvec1<f64> const mc[3][3]);					// Construct matrix given double array-based matrix.

	ttmat3 const operator +() const;
	ttmat3 const operator +(ttmat3 const& m_rh) const;
	ttmat3 const operator -(ttmat3 const& m_rh) const;
	ttvec3<type> const operator *(ttvec3<type> const& m_rh) const;
	ttmat3 const operator *(ttmat3 const& m_rh) const;
	ttmat3 const operator *(type const& s_rh) const;
	ttmat3 const operator /(type const& s_rh) const;
	ttvec3<type> const operator [](index const i) const;
	operator type const* () const;

	ttmat3& operator =(ttmat3 const& m_rh);
	ttmat3& operator +=(ttmat3 const& m_rh);
	ttmat3& operator -=(ttmat3 const& m_rh);
	ttmat3& operator *=(ttmat3 const& m_rh);
	ttmat3& operator =(type const& s_rh);
	ttmat3& operator *=(type const& s_rh);
	ttmat3& operator /=(type const& s_rh);
	ttvec3<type>& operator [](index const i);
	operator type* ();

	union {
		type v[9];
		type m[3][3];
		ttvec3<type> c[3];
		struct { ttvec3<type> c0, c1, c2; };
		struct { ttvec1<type> x0, y0, z0, x1, y1, z1, x2, y2, z2; };
		struct { ttvec1<type> v00, v01, v02, v03, v04, v05, v06, v07, v08; };
		struct { ttvec1<type> m00, m01, m02, m10, m11, m12, m20, m21, m22; };
	};
	inline operator ttvec3<type> const* () const { return c; }
	inline operator ttvec3<type>* () { return c; }
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)v; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)v; }
};

template<typename type> ttmat3<type> const operator *(type const& s_lh, ttmat3<type> const& m_rh);
template<typename type> ttmat3<type> const operator /(type const& s_lh, ttmat3<type> const& m_rh);


//-----------------------------------------------------------------------------

// Template 4D matrix type.
template<typename type>
struct ttmat4
{
	ttmat4(type const& diag = 1);									// Construct matrix with diagonal elements set to single scalar.
	ttmat4(type const& x0, type const& y0, type const& z0, type const& w0, type const& x1, type const& y1, type const& z1, type const& w1, type const& x2, type const& y2, type const& z2, type const& w2, type const& x3, type const& y3, type const& z3, type const& w3);	// Construct matrix with elements set individually.
	ttmat4(ttvec4<type> const& c0, ttvec4<type> const& c1, ttvec4<type> const& c2, ttvec4<type> const& c3);	// Construct matrix with columns set individually.
	explicit ttmat4(ttmat2<type> const& mc);						// Construct matrix given 2D matrix and remainder set to identity.
	explicit ttmat4(ttmat3<type> const& mc);						// Construct matrix given 3D matrix and remainder set to identity.
	ttmat4(ttmat4 const& mc);										// Construct matrix given another 4D matrix.

	explicit ttmat4(float4x4 const mc);								// Construct matrix given float array-based matrix.
	explicit ttmat4(double4x4 const mc);							// Construct matrix given double array-based matrix.
	explicit ttmat4(ttvec1<f32> const mc[4][4]);					// Construct matrix given float array-based matrix.
	explicit ttmat4(ttvec1<f64> const mc[4][4]);					// Construct matrix given double array-based matrix.

	ttmat4 const operator +() const;
	ttmat4 const operator +(ttmat4 const& m_rh) const;
	ttmat4 const operator -(ttmat4 const& m_rh) const;
	ttvec4<type> const operator *(ttvec4<type> const& m_rh) const;
	ttmat4 const operator *(ttmat4 const& m_rh) const;
	ttmat4 const operator *(type const& s_rh) const;
	ttmat4 const operator /(type const& s_rh) const;
	ttvec4<type> const operator [](index const i) const;
	operator type const* () const;

	ttmat4& operator =(ttmat4 const& m_rh);
	ttmat4& operator +=(ttmat4 const& m_rh);
	ttmat4& operator -=(ttmat4 const& m_rh);
	ttmat4& operator *=(ttmat4 const& m_rh);
	ttmat4& operator =(type const& s_rh);
	ttmat4& operator *=(type const& s_rh);
	ttmat4& operator /=(type const& s_rh);
	ttvec4<type>& operator [](index const i);
	operator type* ();

	union {
		type v[16];
		type m[4][4];
		ttvec4<type> c[4];
		struct { ttvec4<type> c0, c1, c2, c3; };
		struct { ttvec1<type> x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3; };
		struct { ttvec1<type> v00, v01, v02, v03, v04, v05, v06, v07, v08, v09, v10, v11, v12, v13, v14, v15; };
		struct { ttvec1<type> m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; };
	};
	inline operator ttvec4<type> const* () const { return c; }
	inline operator ttvec4<type>* () { return c; }
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)v; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)v; }
};

template<typename type> ttmat4<type> const operator *(type const& s_lh, ttmat4<type> const& m_rh);
template<typename type> ttmat4<type> const operator /(type const& s_lh, ttmat4<type> const& m_rh);


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#include "_inl/ijkMatrixSwizzle.inl"


#ifdef __cplusplus

//-----------------------------------------------------------------------------

typedef ttmat2<f32>		fmat2;		// 2D single-precision floating point matrix
typedef ttmat3<f32>		fmat3;		// 3D single-precision floating point matrix
typedef ttmat4<f32>		fmat4;		// 4D single-precision floating point matrix

typedef ttmat2<f64>		dmat2;		// 2D double-precision floating point matrix
typedef ttmat3<f64>		dmat3;		// 3D double-precision floating point matrix
typedef ttmat4<f64>		dmat4;		// 4D double-precision floating point matrix


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#endif	// !_IJK_MATRIXSWIZZLE_H_
#endif	// _IJK_MATRIX_H_