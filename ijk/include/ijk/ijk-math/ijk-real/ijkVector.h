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
#else	// !__cplusplus

#endif	// __cplusplus


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

typedef i32 const* intkv;		// Generic constant integer array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef flt const* fltkv;		// Generic constant single-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.
typedef dbl const* dblkv;		// Generic constant double-precision array-based vector, represented by pointer, used as constant vector return type since returning sized array is not allowed.


#ifdef __cplusplus
}
#endif	// __cplusplus


#include "_inl/ijkVector.inl"


#endif	// !_IJK_VECTOR_H_