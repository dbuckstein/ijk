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


#include "ijkReal.h"


// Reusable pointer-based vector types.
typedef i32			int2[2], int3[3], int4[4], * pint2, * pint3, * pint4;
typedef flt			flt2[2], flt3[3], flt4[4], * pflt2, * pflt3, * pflt4;
typedef dbl			dbl2[2], dbl3[3], dbl4[4], * pdbl2, * pdbl3, * pdbl4;


#endif	// !_IJK_VECTOR_H_