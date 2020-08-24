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

	ijkVector.c
	Source definitions for vector types.
*/

#include "ijk/ijk-math/ijk-real/ijkVector.h"


//-----------------------------------------------------------------------------

#define __v2_one		{ +1, +1 }
#define __v2_zero		{  0,  0 }
#define __v2_one_n		{ -1, -1 }
#define __v2_x			{ +1,  0 }
#define __v2_y			{  0, +1 }
#define __v2_x_n		{ -1,  0 }
#define __v2_y_n		{  0, -1 }

#define __v3_one		{ +1, +1, +1 }
#define __v3_zero		{  0,  0,  0 }
#define __v3_one_n		{ -1, -1, -1 }
#define __v3_x			{ +1,  0,  0 }
#define __v3_y			{  0, +1,  0 }
#define __v3_z			{  0,  0, +1 }
#define __v3_x_n		{ -1,  0,  0 }
#define __v3_y_n		{  0, -1,  0 }
#define __v3_z_n		{  0,  0, -1 }

#define __v4_one		{ +1, +1, +1, +1 }
#define __v4_zero		{  0,  0,  0,  0 }
#define __v4_one_n		{ -1, -1, -1, -1 }
#define __v4_x			{ +1,  0,  0,  0 }
#define __v4_y			{  0, +1,  0,  0 }
#define __v4_z			{  0,  0, +1,  0 }
#define __v4_w			{  0,  0,  0, +1 }
#define __v4_x_n		{ -1,  0,  0,  0 }
#define __v4_y_n		{  0, -1,  0,  0 }
#define __v4_z_n		{  0,  0, -1,  0 }
#define __v4_w_n		{  0,  0,  0, -1 }


//-----------------------------------------------------------------------------

int2 const int2_one = __v2_one;
int2 const int2_zero = __v2_zero;
int2 const int2_one_n = __v2_one_n;
int2 const int2_x = __v2_x;
int2 const int2_y = __v2_y;
int2 const int2_x_n = __v2_x_n;
int2 const int2_y_n = __v2_y_n;

int3 const int3_one = __v3_one;
int3 const int3_zero = __v3_zero;
int3 const int3_one_n = __v3_one_n;
int3 const int3_x = __v3_x;
int3 const int3_y = __v3_y;
int3 const int3_z = __v3_z;
int3 const int3_x_n = __v3_x_n;
int3 const int3_y_n = __v3_y_n;
int3 const int3_z_n = __v3_z_n;

int4 const int4_one = __v4_one;
int4 const int4_zero = __v4_zero;
int4 const int4_one_n = __v4_one_n;
int4 const int4_x = __v4_x;
int4 const int4_y = __v4_y;
int4 const int4_z = __v4_z;
int4 const int4_w = __v4_w;
int4 const int4_x_n = __v4_x_n;
int4 const int4_y_n = __v4_y_n;
int4 const int4_z_n = __v4_z_n;
int4 const int4_w_n = __v4_w_n;

flt2 const flt2_one = __v2_one;
flt2 const flt2_zero = __v2_zero;
flt2 const flt2_one_n = __v2_one_n;
flt2 const flt2_x = __v2_x;
flt2 const flt2_y = __v2_y;
flt2 const flt2_x_n = __v2_x_n;
flt2 const flt2_y_n = __v2_y_n;

flt3 const flt3_one = __v3_one;
flt3 const flt3_zero = __v3_zero;
flt3 const flt3_one_n = __v3_one_n;
flt3 const flt3_x = __v3_x;
flt3 const flt3_y = __v3_y;
flt3 const flt3_z = __v3_z;
flt3 const flt3_x_n = __v3_x_n;
flt3 const flt3_y_n = __v3_y_n;
flt3 const flt3_z_n = __v3_z_n;

flt4 const flt4_one = __v4_one;
flt4 const flt4_zero = __v4_zero;
flt4 const flt4_one_n = __v4_one_n;
flt4 const flt4_x = __v4_x;
flt4 const flt4_y = __v4_y;
flt4 const flt4_z = __v4_z;
flt4 const flt4_w = __v4_w;
flt4 const flt4_x_n = __v4_x_n;
flt4 const flt4_y_n = __v4_y_n;
flt4 const flt4_z_n = __v4_z_n;
flt4 const flt4_w_n = __v4_w_n;

dbl2 const dbl2_one = __v2_one;
dbl2 const dbl2_zero = __v2_zero;
dbl2 const dbl2_one_n = __v2_one_n;
dbl2 const dbl2_x = __v2_x;
dbl2 const dbl2_y = __v2_y;
dbl2 const dbl2_x_n = __v2_x_n;
dbl2 const dbl2_y_n = __v2_y_n;

dbl3 const dbl3_one = __v3_one;
dbl3 const dbl3_zero = __v3_zero;
dbl3 const dbl3_one_n = __v3_one_n;
dbl3 const dbl3_x = __v3_x;
dbl3 const dbl3_y = __v3_y;
dbl3 const dbl3_z = __v3_z;
dbl3 const dbl3_x_n = __v3_x_n;
dbl3 const dbl3_y_n = __v3_y_n;
dbl3 const dbl3_z_n = __v3_z_n;

dbl4 const dbl4_one = __v4_one;
dbl4 const dbl4_zero = __v4_zero;
dbl4 const dbl4_one_n = __v4_one_n;
dbl4 const dbl4_x = __v4_x;
dbl4 const dbl4_y = __v4_y;
dbl4 const dbl4_z = __v4_z;
dbl4 const dbl4_w = __v4_w;
dbl4 const dbl4_x_n = __v4_x_n;
dbl4 const dbl4_y_n = __v4_y_n;
dbl4 const dbl4_z_n = __v4_z_n;
dbl4 const dbl4_w_n = __v4_w_n;


//-----------------------------------------------------------------------------

ivec2 const ivec2_one = __v2_one;
ivec2 const ivec2_zero = __v2_zero;
ivec2 const ivec2_one_n = __v2_one_n;
ivec2 const ivec2_x = __v2_x;
ivec2 const ivec2_y = __v2_y;
ivec2 const ivec2_x_n = __v2_x_n;
ivec2 const ivec2_y_n = __v2_y_n;

ivec3 const ivec3_one = __v3_one;
ivec3 const ivec3_zero = __v3_zero;
ivec3 const ivec3_one_n = __v3_one_n;
ivec3 const ivec3_x = __v3_x;
ivec3 const ivec3_y = __v3_y;
ivec3 const ivec3_z = __v3_z;
ivec3 const ivec3_x_n = __v3_x_n;
ivec3 const ivec3_y_n = __v3_y_n;
ivec3 const ivec3_z_n = __v3_z_n;

ivec4 const ivec4_one = __v4_one;
ivec4 const ivec4_zero = __v4_zero;
ivec4 const ivec4_one_n = __v4_one_n;
ivec4 const ivec4_x = __v4_x;
ivec4 const ivec4_y = __v4_y;
ivec4 const ivec4_z = __v4_z;
ivec4 const ivec4_w = __v4_w;
ivec4 const ivec4_x_n = __v4_x_n;
ivec4 const ivec4_y_n = __v4_y_n;
ivec4 const ivec4_z_n = __v4_z_n;
ivec4 const ivec4_w_n = __v4_w_n;

vec2 const vec2_one = __v2_one;
vec2 const vec2_zero = __v2_zero;
vec2 const vec2_one_n = __v2_one_n;
vec2 const vec2_x = __v2_x;
vec2 const vec2_y = __v2_y;
vec2 const vec2_x_n = __v2_x_n;
vec2 const vec2_y_n = __v2_y_n;

vec3 const vec3_one = __v3_one;
vec3 const vec3_zero = __v3_zero;
vec3 const vec3_one_n = __v3_one_n;
vec3 const vec3_x = __v3_x;
vec3 const vec3_y = __v3_y;
vec3 const vec3_z = __v3_z;
vec3 const vec3_x_n = __v3_x_n;
vec3 const vec3_y_n = __v3_y_n;
vec3 const vec3_z_n = __v3_z_n;

vec4 const vec4_one = __v4_one;
vec4 const vec4_zero = __v4_zero;
vec4 const vec4_one_n = __v4_one_n;
vec4 const vec4_x = __v4_x;
vec4 const vec4_y = __v4_y;
vec4 const vec4_z = __v4_z;
vec4 const vec4_w = __v4_w;
vec4 const vec4_x_n = __v4_x_n;
vec4 const vec4_y_n = __v4_y_n;
vec4 const vec4_z_n = __v4_z_n;
vec4 const vec4_w_n = __v4_w_n;

dvec2 const dvec2_one = __v2_one;
dvec2 const dvec2_zero = __v2_zero;
dvec2 const dvec2_one_n = __v2_one_n;
dvec2 const dvec2_x = __v2_x;
dvec2 const dvec2_y = __v2_y;
dvec2 const dvec2_x_n = __v2_x_n;
dvec2 const dvec2_y_n = __v2_y_n;

dvec3 const dvec3_one = __v3_one;
dvec3 const dvec3_zero = __v3_zero;
dvec3 const dvec3_one_n = __v3_one_n;
dvec3 const dvec3_x = __v3_x;
dvec3 const dvec3_y = __v3_y;
dvec3 const dvec3_z = __v3_z;
dvec3 const dvec3_x_n = __v3_x_n;
dvec3 const dvec3_y_n = __v3_y_n;
dvec3 const dvec3_z_n = __v3_z_n;

dvec4 const dvec4_one = __v4_one;
dvec4 const dvec4_zero = __v4_zero;
dvec4 const dvec4_one_n = __v4_one_n;
dvec4 const dvec4_x = __v4_x;
dvec4 const dvec4_y = __v4_y;
dvec4 const dvec4_z = __v4_z;
dvec4 const dvec4_w = __v4_w;
dvec4 const dvec4_x_n = __v4_x_n;
dvec4 const dvec4_y_n = __v4_y_n;
dvec4 const dvec4_z_n = __v4_z_n;
dvec4 const dvec4_w_n = __v4_w_n;


//-----------------------------------------------------------------------------
