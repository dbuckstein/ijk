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

	ijkVectorFunc.inl
	Inline definitions for vector functions, using "templates" for C.
	This file is an attempt to avoid writing 7 implementations for each vector 
		function, one per type, of which there are many.
*/

#if (_IJK_VECTORFUNC_H_ == ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H))
#ifndef _IJK_VECTORFUNC_INL_
#define _IJK_VECTORFUNC_INL_ ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_INL)



#undef _IJK_VECTORFUNC_INL_
#endif	// !_IJK_VECTORFUNC_INL_
#endif	// (_IJK_VECTORFUNC_H_ == ijk_tokencat(IJK_VECTORFUNC_PREFIX, IJK_VECTORFUNC_H))