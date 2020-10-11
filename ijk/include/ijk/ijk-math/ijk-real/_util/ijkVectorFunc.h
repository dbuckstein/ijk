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

#ifndef _IJK_VECTORFUNC_H_
#define _IJK_VECTORFUNC_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

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


#endif	// !_IJK_VECTORFUNC_H_