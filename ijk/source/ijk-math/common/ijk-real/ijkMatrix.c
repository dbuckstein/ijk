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

	ijkMatrix.c
	Source definitions for matrix types.
*/

#include "ijk/ijk-math/ijk-real/ijkMatrix.h"


//-----------------------------------------------------------------------------

#define __m2_id		{ +1, +0, +0, +1 }


//-----------------------------------------------------------------------------

float2x2 const float2x2_id = __m2_id;
float4 const float4_id = __m2_id;
fmat2 const fmat2_id = __m2_id;


//-----------------------------------------------------------------------------
