/*
   Copyright 2020-2021 Daniel S. Buckstein

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

	ijkMatrixSwizzle.cpp
	C++ testing source definitions for matrix types.
*/

#include "ijk/ijk-math/ijk-real/ijkMatrix.h"


//-----------------------------------------------------------------------------

extern "C" {
	void ijkMathTestMatrixSwizzle();
}

void ijkMathTestMatrixSwizzle()
{
	typedef f32 base, * basev;
	typedef float type;
	typedef fvec2 tvec2;
	typedef fvec3 tvec3;
	typedef fvec4 tvec4;
	typedef fmat2 tmat2;
	typedef fmat3 tmat3;
	typedef fmat4 tmat4;
}
