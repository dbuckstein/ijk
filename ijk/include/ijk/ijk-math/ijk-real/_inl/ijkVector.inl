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

	ijkVector.inl
	Inline definitions for vector types.
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTOR_INL_
#define _IJK_VECTOR_INL_


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


#ifdef __cplusplus

//-----------------------------------------------------------------------------



IJK_SWIZZLE_XY(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 2, 2, 2, i);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZ(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 3, 3, 3, i);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZW(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 4, 4, 4, i);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XY(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 2, 2, 2, f);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZ(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 3, 3, 3, f);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZW(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 4, 4, 4, f);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XY(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 2, 2, 2, d);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZ(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 3, 3, 3, d);


//-----------------------------------------------------------------------------



IJK_SWIZZLE_XYZW(IJK_SWIZZLE2, IJK_SWIZZLE3, IJK_SWIZZLE4, 4, 4, 4, d);


//-----------------------------------------------------------------------------


#endif	// __cplusplus


#endif	// !_IJK_VECTOR_INL_
#endif	// _IJK_VECTOR_H_