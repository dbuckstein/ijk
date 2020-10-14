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

	ijkVectorFunc.h
	Vector function declarations, using "templates" for C.
	This file is an attempt to avoid writing 7 declarations for each vector 
		function, one per type, of which there are many.
*/

#if (defined IJK_VECTORFUNC_PREFIX && defined IJK_VECTORFUNC_TYPE && defined IJK_VECTORFUNC_TVEC && defined IJK_VECTORFUNC_TYPEKV && defined IJK_VECTORFUNC_TYPEV && defined IJK_VECTORFUNC_TYPE2 && defined IJK_VECTORFUNC_TYPE3 && defined IJK_VECTORFUNC_TYPE4)
#ifndef _IJK_VECTORFUNC_H_
#define _IJK_VECTORFUNC_H_ ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H)


#define type	IJK_VECTORFUNC_TYPE
#define tvec	IJK_VECTORFUNC_TVEC
#define typekv	IJK_VECTORFUNC_TYPEKV
#define typev	IJK_VECTORFUNC_TYPEV
#define type2	IJK_VECTORFUNC_TYPE2
#define type3	IJK_VECTORFUNC_TYPE3
#define type4	IJK_VECTORFUNC_TYPE4
#define tvec2	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##2)
#define tvec3	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##3)
#define tvec4	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##4)

#define tfunc(func, ...)					ijk_tokencat(func, IJK_VECTORFUNC_PREFIX)(__VA_ARGS__)
#define tfuncs(func, suffix, ...)			ijk_tokencat(func, ijk_tokencat(IJK_VECTORFUNC_PREFIX, suffix))(__VA_ARGS__)
#define tfuncp(func, prefix, ...)			ijk_tokencat(func, ijk_tokencat(prefix, IJK_VECTORFUNC_PREFIX))(__VA_ARGS__)
#define tfuncps(func, prefix, suffix, ...)	ijk_tokencat(func, ijk_tokencat(ijk_tokencat(prefix, IJK_VECTORFUNC_PREFIX), suffix))(__VA_ARGS__)


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// dot1*s
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
type tfuncs(dot1, s, type const s_lh, type const s_rh);


//-----------------------------------------------------------------------------

// dot2*v
//	Dot product of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot2, v, type2 const v_lh, type2 const v_rh);

// cross2*v
//	Cross product scalar of 2D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
type tfuncs(cross2, v, type2 const v_lh, type2 const v_rh);


//-----------------------------------------------------------------------------

// dot3*v
//	Dot product of 3D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot3, v, type3 const v_lh, type3 const v_rh);

// cross3*v
//	Cross product of 3D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
typev tfuncs(cross3, v, type3 v_out, type3 const v_lh, type3 const v_rh);


//-----------------------------------------------------------------------------

// dot4*v
//	Dot product of 4D array-based vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type tfuncs(dot4, v, type4 const v_lh, type4 const v_rh);

// cross4*v
//	Cross product of 4D array-based vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out (fourth element is zero)
typev tfuncs(cross4, v, type4 v_out, type4 const v_lh, type4 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// dot1*
//	Dot product of scalars, which is just their product.
//		param s_lh: left-hand scalar
//		param s_rh: right-hand scalar
//		return: product
tvec tfunc(dot1, tvec const s_lh, tvec const s_rh);


//-----------------------------------------------------------------------------

// dot2*
//	Dot product of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot2, tvec2 const v_lh, tvec2 const v_rh);

// cross2*
//	Cross product scalar of 2D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: scalar quantity of imaginary perpendicular axis
tvec tfunc(cross2, tvec2 const v_lh, tvec2 const v_rh);


//-----------------------------------------------------------------------------

// dot3*
//	Dot product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot3, tvec3 const v_lh, tvec3 const v_rh);

// cross3*
//	Cross product of 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product
tvec3 tfunc(cross3, tvec3 const v_lh, tvec3 const v_rh);


//-----------------------------------------------------------------------------

// dot4*
//	Dot product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
tvec tfunc(dot4, tvec4 const v_lh, tvec4 const v_rh);

// cross4*
//	Cross product of 4D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: cross product (fourth component is zero)
tvec4 tfunc(cross4, tvec4 const v_lh, tvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVectorFunc.inl"


#undef tfunc
#undef tfuncs
#undef tfuncp
#undef tfuncps

#undef type
#undef tvec
#undef typekv
#undef typev
#undef type2
#undef type3
#undef type4
#undef tvec2
#undef tvec3
#undef tvec4

#undef IJK_VECTORFUNC_PREFIX
#undef IJK_VECTORFUNC_TYPE
#undef IJK_VECTORFUNC_TVEC
#undef IJK_VECTORFUNC_TYPEKV
#undef IJK_VECTORFUNC_TYPEV
#undef IJK_VECTORFUNC_TYPE2
#undef IJK_VECTORFUNC_TYPE3
#undef IJK_VECTORFUNC_TYPE4

#undef _IJK_VECTORFUNC_H_
#endif	// !_IJK_VECTORFUNC_H_
#endif	// (defined IJK_VECTORFUNC_PREFIX && defined IJK_VECTORFUNC_TYPE && defined IJK_VECTORFUNC_TVEC && defined IJK_VECTORFUNC_TYPEKV && defined IJK_VECTORFUNC_TYPEV && defined IJK_VECTORFUNC_TYPE2 && defined IJK_VECTORFUNC_TYPE3 && defined IJK_VECTORFUNC_TYPE4)