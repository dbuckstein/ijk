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

	ijkMatrix.h
	Matrix types and functions.
*/

#ifndef _IJK_MATRIX_H_
#define _IJK_MATRIX_H_


#include "ijkVector.h"


// Reusable pointer-based matrix types.
typedef int2		int2x2[2], * pint2x2;
typedef int3		int3x3[3], * pint3x3;
typedef int4		int4x4[4], * pint4x4;
typedef flt2		flt2x2[2], * pflt2x2;
typedef flt3		flt3x3[3], * pflt3x3;
typedef flt4		flt4x4[4], * pflt4x4;
typedef dbl2		dbl2x2[2], * pdbl2x2;
typedef dbl3		dbl3x3[3], * pdbl3x3;
typedef dbl4		dbl4x4[4], * pdbl4x4;


#endif	// !_IJK_MATRIX_H_