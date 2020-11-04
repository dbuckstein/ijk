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

// ijkVecCopy2bv
//	Initialize 2D boolean vector.
//		param v_out: output vector
//		params v_in: input vector
//		return: v_out
boolv ijkVecCopy2bv(bool2 v_out, bool2 const v_in);

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

// ijkVecAnd2bv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecNand2bv
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecOr2bv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecNor2bv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor2bv(bool2 v_out, bool2 const v_lh, bool2 const v_rh);

// ijkVecCopy2bvs
//	Initialize 2D boolean vector.
//		param v_out: output vector
//		params s_in: input scalar
//		return: v_out
boolv ijkVecCopy2bvs(bool2 v_out, bool const s_in);

// ijkVecNot2bvs
//	Logical 'not' for 2D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param s_in: input scalar
//		return: v_out
boolv ijkVecNot2bvs(bool2 v_out, bool const s_in);

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

// ijkVecAnd2bvs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecAnd2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// ijkVecNand2bvs
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNand2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// ijkVecOr2bvs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecOr2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

// ijkVecNor2bvs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNor2bvs(bool2 v_out, bool2 const v_lh, bool const s_rh);

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

// ijkVecAnd2bsv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);

// ijkVecNand2bsv
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);

// ijkVecOr2bsv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);

// ijkVecNor2bsv
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor2bsv(bool2 v_out, bool const s_lh, bool2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems3bv
//	Initialize 3D boolean vector.
//		param v_out: output vector
//		params x, y, z: initialization values
//		return: v_out
boolv ijkVecInitElems3bv(bool3 v_out, bool const x, bool const y, bool const z);

// ijkVecCopy3bv
//	Initialize 3D boolean vector.
//		param v_out: output vector
//		params v_in: input vector
//		return: v_out
boolv ijkVecCopy3bv(bool3 v_out, bool3 const v_in);

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

// ijkVecAnd3bv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecNand3bv
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecOr3bv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecNor3bv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor3bv(bool3 v_out, bool3 const v_lh, bool3 const v_rh);

// ijkVecCopy3bvs
//	Initialize 3D boolean vector.
//		param v_out: output vector
//		params s_in: input scalar
//		return: v_out
boolv ijkVecCopy3bvs(bool3 v_out, bool const s_in);

// ijkVecNot3bvs
//	Logical 'not' for 3D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param s_in: input scalar
//		return: v_out
boolv ijkVecNot3bvs(bool3 v_out, bool const s_in);

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

// ijkVecAnd3bvs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecAnd3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// ijkVecNand3bvs
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNand3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// ijkVecOr3bvs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecOr3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

// ijkVecNor3bvs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNor3bvs(bool3 v_out, bool3 const v_lh, bool const s_rh);

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

// ijkVecAnd3bsv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);

// ijkVecNand3bsv
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);

// ijkVecOr3bsv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);

// ijkVecNor3bsv
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor3bsv(bool3 v_out, bool const s_lh, bool3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems4bv
//	Initialize 4D boolean vector.
//		param v_out: output vector
//		params x, y, z, w: initialization values
//		return: v_out
boolv ijkVecInitElems4bv(bool4 v_out, bool const x, bool const y, bool const z, bool const w);

// ijkVecCopy4bv
//	Initialize 4D boolean vector.
//		param v_out: output vector
//		params v_in: input vector
//		return: v_out
boolv ijkVecCopy4bv(bool4 v_out, bool4 const v_in);

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

// ijkVecAnd4bv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecNand4bv
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecOr4bv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecNor4bv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor4bv(bool4 v_out, bool4 const v_lh, bool4 const v_rh);

// ijkVecCopy4bvs
//	Initialize 4D boolean vector.
//		param v_out: output vector
//		params s_in: input scalar
//		return: v_out
boolv ijkVecCopy4bvs(bool4 v_out, bool const s_in);

// ijkVecNot4bvs
//	Logical 'not' for 4D boolean vector.
//		param v_out: output vector holding boolean result of logical 'not'
//		param s_in: input scalar
//		return: v_out
boolv ijkVecNot4bvs(bool4 v_out, bool const s_in);

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

// ijkVecAnd4bvs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecAnd4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// ijkVecNand4bvs
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNand4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// ijkVecOr4bvs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecOr4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

// ijkVecNor4bvs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: v_out
boolv ijkVecNor4bvs(bool4 v_out, bool4 const v_lh, bool const s_rh);

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

// ijkVecAnd4bsv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecAnd4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);

// ijkVecNand4bsv
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNand4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);

// ijkVecOr4bsv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecOr4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);

// ijkVecNor4bsv
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_out: output vector holding boolean result of comparison
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: v_out
boolv ijkVecNor4bsv(bool4 v_out, bool const s_lh, bool4 const v_rh);


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

// ijkVecCopy2b
//	Initialize 2D boolean vector.
//		params v_in: input vector
//		return: vector comparison
bvec2 ijkVecCopy2b(bvec2 const v_in);

// ijkVecNot2b
//	Logical 'not' for 2D boolean vector.
//		param v_in: input vector
//		return: vector comparison
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

// ijkVecAnd2b
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecAnd2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecNand2b
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecNand2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecOr2b
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecOr2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecNor2b
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecNor2b(bvec2 const v_lh, bvec2 const v_rh);

// ijkVecCopy2bs
//	Initialize 2D boolean vector.
//		params s_in: input scalar
//		return: vector comparison
bvec2 ijkVecCopy2bs(bool const s_in);

// ijkVecNot2bs
//	Logical 'not' for 2D boolean vector.
//		param s_in: input scalar
//		return: vector comparison
bvec2 ijkVecNot2bs(bool const s_in);

// ijkVecEqual2bs
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

// ijkVecAnd2bs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec2 ijkVecAnd2bs(bvec2 const v_lh, bool const s_rh);

// ijkVecNand2bs
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec2 ijkVecNand2bs(bvec2 const v_lh, bool const s_rh);

// ijkVecOr2bs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec2 ijkVecOr2bs(bvec2 const v_lh, bool const s_rh);

// ijkVecNor2bs
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec2 ijkVecNor2bs(bvec2 const v_lh, bool const s_rh);

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

// ijkVecAnd2sb
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecAnd2sb(bool const s_lh, bvec2 const v_rh);

// ijkVecNand2sb
//	Component-wise logical 'nand' comparison for 2D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecNand2sb(bool const s_lh, bvec2 const v_rh);

// ijkVecOr2sb
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecOr2sb(bool const s_lh, bvec2 const v_rh);

// ijkVecNor2sb
//	Component-wise logical 'and' comparison for 2D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec2 ijkVecNor2sb(bool const s_lh, bvec2 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems3b
//	Initialize 3D boolean vector.
//		params x, y, z: initialization values
//		return: output vector
bvec3 ijkVecInitElems3b(bool const x, bool const y, bool const z);

// ijkVecCopy3b
//	Initialize 3D boolean vector.
//		params v_in: input vector
//		return: vector comparison
bvec3 ijkVecCopy3b(bvec3 const v_in);

// ijkVecNot3b
//	Logical 'not' for 3D boolean vector.
//		param v_in: input vector
//		return: vector comparison
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

// ijkVecAnd3b
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecAnd3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecNand3b
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecNand3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecOr3b
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecOr3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecNor3b
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecNor3b(bvec3 const v_lh, bvec3 const v_rh);

// ijkVecCopy3bs
//	Initialize 3D boolean vector.
//		params s_in: input scalar
//		return: vector comparison
bvec3 ijkVecCopy3bs(bool const s_in);

// ijkVecNot3bs
//	Logical 'not' for 3D boolean vector.
//		param s_in: input scalar
//		return: vector comparison
bvec3 ijkVecNot3bs(bool const s_in);

// ijkVecEqual3bs
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

// ijkVecAnd3bs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec3 ijkVecAnd3bs(bvec3 const v_lh, bool const s_rh);

// ijkVecNand3bs
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec3 ijkVecNand3bs(bvec3 const v_lh, bool const s_rh);

// ijkVecOr3bs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec3 ijkVecOr3bs(bvec3 const v_lh, bool const s_rh);

// ijkVecNor3bs
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec3 ijkVecNor3bs(bvec3 const v_lh, bool const s_rh);

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

// ijkVecAnd3sb
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecAnd3sb(bool const s_lh, bvec3 const v_rh);

// ijkVecNand3sb
//	Component-wise logical 'nand' comparison for 3D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecNand3sb(bool const s_lh, bvec3 const v_rh);

// ijkVecOr3sb
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecOr3sb(bool const s_lh, bvec3 const v_rh);

// ijkVecNor3sb
//	Component-wise logical 'and' comparison for 3D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec3 ijkVecNor3sb(bool const s_lh, bvec3 const v_rh);


//-----------------------------------------------------------------------------

// ijkVecInitElems4b
//	Initialize 4D boolean vector.
//		params x, y, z, w: initialization values
//		return: output vector
bvec4 ijkVecInitElems4b(bool const x, bool const y, bool const z, bool const w);

// ijkVecCopy4b
//	Initialize 4D boolean vector.
//		params v_in: input vector
//		return: vector comparison
bvec4 ijkVecCopy4b(bvec4 const v_in);

// ijkVecNot4b
//	Logical 'not' for 4D boolean vector.
//		param v_in: input vector
//		return: vector comparison
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

// ijkVecAnd4b
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecAnd4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecNand4b
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecNand4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecOr4b
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecOr4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecNor4b
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecNor4b(bvec4 const v_lh, bvec4 const v_rh);

// ijkVecCopy4bs
//	Initialize 4D boolean vector.
//		params s_in: input scalar
//		return: vector comparison
bvec4 ijkVecCopy4bs(bool const s_in);

// ijkVecNot4bs
//	Logical 'not' for 4D boolean vector.
//		param s_in: input scalar
//		return: vector comparison
bvec4 ijkVecNot4bs(bool const s_in);

// ijkVecEqual4bs
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

// ijkVecAnd4bs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec4 ijkVecAnd4bs(bvec4 const v_lh, bool const s_rh);

// ijkVecNand4bs
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec4 ijkVecNand4bs(bvec4 const v_lh, bool const s_rh);

// ijkVecOr4bs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec4 ijkVecOr4bs(bvec4 const v_lh, bool const s_rh);

// ijkVecNor4bs
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param v_lh: left-hand vector
//		param s_rh: right-hand scalar
//		return: vector comparison
bvec4 ijkVecNor4bs(bvec4 const v_lh, bool const s_rh);

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

// ijkVecAnd4sb
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecAnd4sb(bool const s_lh, bvec4 const v_rh);

// ijkVecNand4sb
//	Component-wise logical 'nand' comparison for 4D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecNand4sb(bool const s_lh, bvec4 const v_rh);

// ijkVecOr4sb
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecOr4sb(bool const s_lh, bvec4 const v_rh);

// ijkVecNor4sb
//	Component-wise logical 'and' comparison for 4D boolean vector.
//		param s_lh: left-hand scalar
//		param v_rh: right-hand vector
//		return: vector comparison
bvec4 ijkVecNor4sb(bool const s_lh, bvec4 const v_rh);


//-----------------------------------------------------------------------------


#include "_inl/ijkVector_bool.inl"


#endif	// !_IJK_VECTOR_BOOL_H_
#endif	// _IJK_VECTOR_H_