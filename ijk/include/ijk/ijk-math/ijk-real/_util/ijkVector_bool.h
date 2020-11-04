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

	ijkVector_bool.h
	Declarations for boolean vector functions.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_BOOL_H_
#define _IJK_VECTOR_BOOL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkVecInitElems2bv
//	Initialize 2D boolean vector.
//		param v_out: output vector
//		params x, y: initialization values
//		return: v_out
boolv ijkVecInitElems2bv(bool2 v_out, bool const x, bool const y);

// ijkVecNot2bv
//	Logical 'not' for 2D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param v_in: input vector
//		return: v_out
boolv ijkVecNot2bv(bool2 v_out, bool2 const v_in);

// ijkVecEqual2bv
//	Equality comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecInequal2bv
//	Inequality comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecEqual2bvs
//	Equality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecEqual2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// ijkVecInequal2bvs
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecInequal2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// ijkVecEqual2bsv
//	Equality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);

// ijkVecInequal2bsv
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems3bv
//	Initialize 3D boolean vector.
//		param v_out: output vector
//		params x, y, z: initialization values
//		return: v_out
boolv ijkVecInitElems3bv(bool3 v_out, bool const x, bool const y, bool const z);

// ijkVecNot3bv
//	Logical 'not' for 3D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param v_in: input vector
//		return: v_out
boolv ijkVecNot3bv(bool3 v_out, bool3 const v_in);

// ijkVecEqual3bv
//	Equality comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecInequal3bv
//	Inequality comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecEqual3bvs
//	Equality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecEqual3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// ijkVecInequal3bvs
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecInequal3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// ijkVecEqual3bsv
//	Equality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);

// ijkVecInequal3bsv
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems4bv
//	Initialize 4D boolean vector.
//		param v_out: output vector
//		params x, y, z, w: initialization values
//		return: v_out
boolv ijkVecInitElems4bv(bool4 v_out, bool const x, bool const y, bool const z, bool const w);

// ijkVecNot4bv
//	Logical 'not' for 4D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param v_in: input vector
//		return: v_out
boolv ijkVecNot4bv(bool4 v_out, bool4 const v_in);

// ijkVecEqual4bv
//	Equality comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecInequal4bv
//	Inequality comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecEqual4bvs
//	Equality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecEqual4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// ijkVecInequal4bvs
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: v_out
boolv ijkVecInequal4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// ijkVecEqual4bsv
//	Equality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecEqual4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);

// ijkVecInequal4bsv
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecInequal4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);


//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkVecInitElems2b
//	Initialize 2D boolean vector.
//		params x, y: initialization values
//		return: output vector
bvec2 ijkVecInitElems2b(bool const x, bool const y);

// ijkVecNot2b
//	Logical 'not' for 2D boolean vector.
//		param v_in: input vector
//		return: vector logical 'not'
bvec2 ijkVecNot2b(bvec2 const v_in);

// ijkVecEqual2b
//	Equality comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecEqual2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecInequal2b
//	Inequality comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecInequal2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecEqual2sb
//	Equality comparison for 2D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec2 ijkVecEqual2bs(bvec2 const v_lh, bool const s_rh);

// ijkVecInequal2bs
//	Inequality comparison for 2D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec2 ijkVecInequal2bs(bvec2 const v_lh, bool const s_rh);

// ijkVecEqual2sb
//	Equality comparison for 2D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecEqual2sb(bool const s_lh, bvec2 const v_rh);

// ijkVecInequal2sb
//	Inequality comparison for 2D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecInequal2sb(bool const s_lh, bvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems3b
//	Initialize 3D boolean vector.
//		params x, y, z: initialization values
//		return: output vector
bvec3 ijkVecInitElems3b(bool const x, bool const y, bool const z);

// ijkVecNot3b
//	Logical 'not' for 3D boolean vector.
//		param v_in: input vector
//		return: vector logical 'not'
bvec3 ijkVecNot3b(bvec3 const v_in);

// ijkVecEqual3b
//	Equality comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecEqual3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecInequal3b
//	Inequality comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecInequal3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecEqual3sb
//	Equality comparison for 3D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec3 ijkVecEqual3bs(bvec3 const v_lh, bool const s_rh);

// ijkVecInequal3bs
//	Inequality comparison for 3D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec3 ijkVecInequal3bs(bvec3 const v_lh, bool const s_rh);

// ijkVecEqual3sb
//	Equality comparison for 3D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecEqual3sb(bool const s_lh, bvec3 const v_rh);

// ijkVecInequal3sb
//	Inequality comparison for 3D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecInequal3sb(bool const s_lh, bvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems4b
//	Initialize 4D boolean vector.
//		params x, y, z, w: initialization values
//		return: output vector
bvec4 ijkVecInitElems4b(bool const x, bool const y, bool const z, bool const w);

// ijkVecNot4b
//	Logical 'not' for 4D boolean vector.
//		param v_in: input vector
//		return: vector logical 'not'
bvec4 ijkVecNot4b(bvec4 const v_in);

// ijkVecEqual4b
//	Equality comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecEqual4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecInequal4b
//	Inequality comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecInequal4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecEqual4sb
//	Equality comparison for 4D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec4 ijkVecEqual4bs(bvec4 const v_lh, bool const s_rh);

// ijkVecInequal4bs
//	Inequality comparison for 4D boolean vector vs condition.
//		param v_lh: left-hand vector
//		param s_rh: right-hand condition
//		return: vector comparison
bvec4 ijkVecInequal4bs(bvec4 const v_lh, bool const s_rh);

// ijkVecEqual4sb
//	Equality comparison for 4D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecEqual4sb(bool const s_lh, bvec4 const v_rh);

// ijkVecInequal4sb
//	Inequality comparison for 4D boolean vector vs condition.
//		param s_lh: left-hand condition
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecInequal4sb(bool const s_lh, bvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_bool.inl"


#endif	// !_IJK_VECTOR_BOOL_H_
#endif	// _IJK_VECTOR_H_