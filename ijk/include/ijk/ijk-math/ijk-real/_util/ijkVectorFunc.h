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

#if (defined IJK_VECTORFUNC_PREFIX && defined IJK_VECTORFUNC_TYPE && defined IJK_VECTORFUNC_TVEC)
#ifndef _IJK_VECTORFUNC_H_
#define _IJK_VECTORFUNC_H_ ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H)


#define t		IJK_VECTORFUNC_PREFIX
#define type	IJK_VECTORFUNC_TYPE
#define tvec	IJK_VECTORFUNC_TVEC
#define type2	__ijk_cfg_tokencat(tvec, 2)
#define type3	__ijk_cfg_tokencat(tvec, 3)
#define type4	__ijk_cfg_tokencat(tvec, 4)
#define tvec2	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##2)
#define tvec3	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##3)
#define tvec4	ijk_tokencat(IJK_VECTORFUNC_PREFIX, vec##4)


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// dot3iv
//	Dot product of two signed 32-bit integer 3D vectors.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: dot product
type ijk_tokencat(dot3, ijk_tokencat(t, v)) (type3 const v_lh, type3 const v_rh);

// cross3iv
//	Cross product of two signed 32-bit integer 3D vectors.
//		param v_out: output vector to hold cross product
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
type3 ijk_tokencat(cross3, ijk_tokencat(t, v)) (type3 v_out, type3 const v_lh, type3 const v_rh);

//i32 dot3iv(int3 const v_lh, int3 const v_rh);

//intv cross3iv(int3 v_out, int3 const v_lh, int3 const v_rh);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

//int dot3i(ivec3 const v_lh, ivec3 const v_rh);

//ivec3 cross3i(ivec3 const v_lh, ivec3 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVectorFunc.inl"


#undef t
#undef base
#undef type
#undef type2
#undef type3
#undef type4
#undef tvec2
#undef tvec3
#undef tvec4
#undef _IJK_VECTORFUNC_H_
#endif	// !_IJK_VECTORFUNC_H_
#endif	// (defined IJK_VECTORFUNC_PREFIX && defined IJK_VECTORFUNC_TYPE && defined IJK_VECTORFUNC_TVEC)