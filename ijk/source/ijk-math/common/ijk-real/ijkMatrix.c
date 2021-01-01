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

	ijkMatrix.c
	Source definitions for matrix types.
*/

#include "ijk/ijk-math/ijk-real/ijkMatrix.h"


//-----------------------------------------------------------------------------

#define __m2_id		{	+1, +0,				+0, +1	}
#define __m3_id		{	+1, +0, +0,			+0, +1, +0,			+0, +0, +1 }
#define __m4_id		{	+1, +0, +0, +0,		+0, +1, +0, +0,		+0, +0, +1, +0,		+0, +0, +0, +1 }


//-----------------------------------------------------------------------------

float2x2 const float2x2_id = __m2_id;
float4 const float4m_id = __m2_id;
fmat2 const fmat2_id = __m2_id;
mat2 const mat2_id = __m2_id;

float3x3 const float3x3_id = __m3_id;
float9 const float9m_id = __m3_id;
fmat3 const fmat3_id = __m3_id;
mat3 const mat3_id = __m3_id;

float4x4 const float4x4_id = __m4_id;
float16 const float16m_id = __m4_id;
fmat4 const fmat4_id = __m4_id;
mat4 const mat4_id = __m4_id;


//-----------------------------------------------------------------------------

double2x2 const double2x2_id = __m2_id;
double4 const double4m_id = __m2_id;
dmat2 const dmat2_id = __m2_id;

double3x3 const double3x3_id = __m3_id;
double9 const double9m_id = __m3_id;
dmat3 const dmat3_id = __m3_id;

double4x4 const double4x4_id = __m4_id;
double16 const double16m_id = __m4_id;
dmat4 const dmat4_id = __m4_id;


//-----------------------------------------------------------------------------
