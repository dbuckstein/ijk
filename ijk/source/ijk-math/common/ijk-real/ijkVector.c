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

bool2 const bool2_true = __v2_one;
bool2 const bool2_false = __v2_zero;
bool2 const bool2_x = __v2_x;
bool2 const bool2_y = __v2_y;

bool3 const bool3_true = __v3_one;
bool3 const bool3_false = __v3_zero;
bool3 const bool3_x = __v3_x;
bool3 const bool3_y = __v3_y;
bool3 const bool3_z = __v3_z;

bool4 const bool4_true = __v4_one;
bool4 const bool4_false = __v4_zero;
bool4 const bool4_x = __v4_x;
bool4 const bool4_y = __v4_y;
bool4 const bool4_z = __v4_z;
bool4 const bool4_w = __v4_w;

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

int2 const intl2_one = __v2_one;
int2 const intl2_zero = __v2_zero;
int2 const intl2_one_n = __v2_one_n;
int2 const intl2_x = __v2_x;
int2 const intl2_y = __v2_y;
int2 const intl2_x_n = __v2_x_n;
int2 const intl2_y_n = __v2_y_n;

int3 const intl3_one = __v3_one;
int3 const intl3_zero = __v3_zero;
int3 const intl3_one_n = __v3_one_n;
int3 const intl3_x = __v3_x;
int3 const intl3_y = __v3_y;
int3 const intl3_z = __v3_z;
int3 const intl3_x_n = __v3_x_n;
int3 const intl3_y_n = __v3_y_n;
int3 const intl3_z_n = __v3_z_n;

int4 const intl4_one = __v4_one;
int4 const intl4_zero = __v4_zero;
int4 const intl4_one_n = __v4_one_n;
int4 const intl4_x = __v4_x;
int4 const intl4_y = __v4_y;
int4 const intl4_z = __v4_z;
int4 const intl4_w = __v4_w;
int4 const intl4_x_n = __v4_x_n;
int4 const intl4_y_n = __v4_y_n;
int4 const intl4_z_n = __v4_z_n;
int4 const intl4_w_n = __v4_w_n;

uint2 const uint2_one = __v2_one;
uint2 const uint2_zero = __v2_zero;
uint2 const uint2_one_n = __v2_one_n;
uint2 const uint2_x = __v2_x;
uint2 const uint2_y = __v2_y;
uint2 const uint2_x_n = __v2_x_n;
uint2 const uint2_y_n = __v2_y_n;

uint3 const uint3_one = __v3_one;
uint3 const uint3_zero = __v3_zero;
uint3 const uint3_one_n = __v3_one_n;
uint3 const uint3_x = __v3_x;
uint3 const uint3_y = __v3_y;
uint3 const uint3_z = __v3_z;
uint3 const uint3_x_n = __v3_x_n;
uint3 const uint3_y_n = __v3_y_n;
uint3 const uint3_z_n = __v3_z_n;

uint4 const uint4_one = __v4_one;
uint4 const uint4_zero = __v4_zero;
uint4 const uint4_one_n = __v4_one_n;
uint4 const uint4_x = __v4_x;
uint4 const uint4_y = __v4_y;
uint4 const uint4_z = __v4_z;
uint4 const uint4_w = __v4_w;
uint4 const uint4_x_n = __v4_x_n;
uint4 const uint4_y_n = __v4_y_n;
uint4 const uint4_z_n = __v4_z_n;
uint4 const uint4_w_n = __v4_w_n;

uint2 const uintl2_one = __v2_one;
uint2 const uintl2_zero = __v2_zero;
uint2 const uintl2_one_n = __v2_one_n;
uint2 const uintl2_x = __v2_x;
uint2 const uintl2_y = __v2_y;
uint2 const uintl2_x_n = __v2_x_n;
uint2 const uintl2_y_n = __v2_y_n;

uint3 const uintl3_one = __v3_one;
uint3 const uintl3_zero = __v3_zero;
uint3 const uintl3_one_n = __v3_one_n;
uint3 const uintl3_x = __v3_x;
uint3 const uintl3_y = __v3_y;
uint3 const uintl3_z = __v3_z;
uint3 const uintl3_x_n = __v3_x_n;
uint3 const uintl3_y_n = __v3_y_n;
uint3 const uintl3_z_n = __v3_z_n;

uint4 const uintl4_one = __v4_one;
uint4 const uintl4_zero = __v4_zero;
uint4 const uintl4_one_n = __v4_one_n;
uint4 const uintl4_x = __v4_x;
uint4 const uintl4_y = __v4_y;
uint4 const uintl4_z = __v4_z;
uint4 const uintl4_w = __v4_w;
uint4 const uintl4_x_n = __v4_x_n;
uint4 const uintl4_y_n = __v4_y_n;
uint4 const uintl4_z_n = __v4_z_n;
uint4 const uintl4_w_n = __v4_w_n;

float2 const float2_one = __v2_one;
float2 const float2_zero = __v2_zero;
float2 const float2_one_n = __v2_one_n;
float2 const float2_x = __v2_x;
float2 const float2_y = __v2_y;
float2 const float2_x_n = __v2_x_n;
float2 const float2_y_n = __v2_y_n;

float3 const float3_one = __v3_one;
float3 const float3_zero = __v3_zero;
float3 const float3_one_n = __v3_one_n;
float3 const float3_x = __v3_x;
float3 const float3_y = __v3_y;
float3 const float3_z = __v3_z;
float3 const float3_x_n = __v3_x_n;
float3 const float3_y_n = __v3_y_n;
float3 const float3_z_n = __v3_z_n;

float4 const float4_one = __v4_one;
float4 const float4_zero = __v4_zero;
float4 const float4_one_n = __v4_one_n;
float4 const float4_x = __v4_x;
float4 const float4_y = __v4_y;
float4 const float4_z = __v4_z;
float4 const float4_w = __v4_w;
float4 const float4_x_n = __v4_x_n;
float4 const float4_y_n = __v4_y_n;
float4 const float4_z_n = __v4_z_n;
float4 const float4_w_n = __v4_w_n;

double2 const double2_one = __v2_one;
double2 const double2_zero = __v2_zero;
double2 const double2_one_n = __v2_one_n;
double2 const double2_x = __v2_x;
double2 const double2_y = __v2_y;
double2 const double2_x_n = __v2_x_n;
double2 const double2_y_n = __v2_y_n;

double3 const double3_one = __v3_one;
double3 const double3_zero = __v3_zero;
double3 const double3_one_n = __v3_one_n;
double3 const double3_x = __v3_x;
double3 const double3_y = __v3_y;
double3 const double3_z = __v3_z;
double3 const double3_x_n = __v3_x_n;
double3 const double3_y_n = __v3_y_n;
double3 const double3_z_n = __v3_z_n;

double4 const double4_one = __v4_one;
double4 const double4_zero = __v4_zero;
double4 const double4_one_n = __v4_one_n;
double4 const double4_x = __v4_x;
double4 const double4_y = __v4_y;
double4 const double4_z = __v4_z;
double4 const double4_w = __v4_w;
double4 const double4_x_n = __v4_x_n;
double4 const double4_y_n = __v4_y_n;
double4 const double4_z_n = __v4_z_n;
double4 const double4_w_n = __v4_w_n;


//-----------------------------------------------------------------------------

bvec2 const bvec2_true = __v2_one;
bvec2 const bvec2_false = __v2_zero;
bvec2 const bvec2_x = __v2_x;
bvec2 const bvec2_y = __v2_y;

bvec3 const bvec3_true = __v3_one;
bvec3 const bvec3_false = __v3_zero;
bvec3 const bvec3_x = __v3_x;
bvec3 const bvec3_y = __v3_y;
bvec3 const bvec3_z = __v3_z;

bvec4 const bvec4_true = __v4_one;
bvec4 const bvec4_false = __v4_zero;
bvec4 const bvec4_x = __v4_x;
bvec4 const bvec4_y = __v4_y;
bvec4 const bvec4_z = __v4_z;
bvec4 const bvec4_w = __v4_w;

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

ivec2 const ivecl2_one = __v2_one;
ivec2 const ivecl2_zero = __v2_zero;
ivec2 const ivecl2_one_n = __v2_one_n;
ivec2 const ivecl2_x = __v2_x;
ivec2 const ivecl2_y = __v2_y;
ivec2 const ivecl2_x_n = __v2_x_n;
ivec2 const ivecl2_y_n = __v2_y_n;

ivec3 const ivecl3_one = __v3_one;
ivec3 const ivecl3_zero = __v3_zero;
ivec3 const ivecl3_one_n = __v3_one_n;
ivec3 const ivecl3_x = __v3_x;
ivec3 const ivecl3_y = __v3_y;
ivec3 const ivecl3_z = __v3_z;
ivec3 const ivecl3_x_n = __v3_x_n;
ivec3 const ivecl3_y_n = __v3_y_n;
ivec3 const ivecl3_z_n = __v3_z_n;

ivec4 const ivecl4_one = __v4_one;
ivec4 const ivecl4_zero = __v4_zero;
ivec4 const ivecl4_one_n = __v4_one_n;
ivec4 const ivecl4_x = __v4_x;
ivec4 const ivecl4_y = __v4_y;
ivec4 const ivecl4_z = __v4_z;
ivec4 const ivecl4_w = __v4_w;
ivec4 const ivecl4_x_n = __v4_x_n;
ivec4 const ivecl4_y_n = __v4_y_n;
ivec4 const ivecl4_z_n = __v4_z_n;
ivec4 const ivecl4_w_n = __v4_w_n;

uvec2 const uvec2_one = __v2_one;
uvec2 const uvec2_zero = __v2_zero;
uvec2 const uvec2_one_n = __v2_one_n;
uvec2 const uvec2_x = __v2_x;
uvec2 const uvec2_y = __v2_y;
uvec2 const uvec2_x_n = __v2_x_n;
uvec2 const uvec2_y_n = __v2_y_n;

uvec3 const uvec3_one = __v3_one;
uvec3 const uvec3_zero = __v3_zero;
uvec3 const uvec3_one_n = __v3_one_n;
uvec3 const uvec3_x = __v3_x;
uvec3 const uvec3_y = __v3_y;
uvec3 const uvec3_z = __v3_z;
uvec3 const uvec3_x_n = __v3_x_n;
uvec3 const uvec3_y_n = __v3_y_n;
uvec3 const uvec3_z_n = __v3_z_n;

uvec4 const uvec4_one = __v4_one;
uvec4 const uvec4_zero = __v4_zero;
uvec4 const uvec4_one_n = __v4_one_n;
uvec4 const uvec4_x = __v4_x;
uvec4 const uvec4_y = __v4_y;
uvec4 const uvec4_z = __v4_z;
uvec4 const uvec4_w = __v4_w;
uvec4 const uvec4_x_n = __v4_x_n;
uvec4 const uvec4_y_n = __v4_y_n;
uvec4 const uvec4_z_n = __v4_z_n;
uvec4 const uvec4_w_n = __v4_w_n;

uvec2 const uvecl2_one = __v2_one;
uvec2 const uvecl2_zero = __v2_zero;
uvec2 const uvecl2_one_n = __v2_one_n;
uvec2 const uvecl2_x = __v2_x;
uvec2 const uvecl2_y = __v2_y;
uvec2 const uvecl2_x_n = __v2_x_n;
uvec2 const uvecl2_y_n = __v2_y_n;

uvec3 const uvecl3_one = __v3_one;
uvec3 const uvecl3_zero = __v3_zero;
uvec3 const uvecl3_one_n = __v3_one_n;
uvec3 const uvecl3_x = __v3_x;
uvec3 const uvecl3_y = __v3_y;
uvec3 const uvecl3_z = __v3_z;
uvec3 const uvecl3_x_n = __v3_x_n;
uvec3 const uvecl3_y_n = __v3_y_n;
uvec3 const uvecl3_z_n = __v3_z_n;

uvec4 const uvecl4_one = __v4_one;
uvec4 const uvecl4_zero = __v4_zero;
uvec4 const uvecl4_one_n = __v4_one_n;
uvec4 const uvecl4_x = __v4_x;
uvec4 const uvecl4_y = __v4_y;
uvec4 const uvecl4_z = __v4_z;
uvec4 const uvecl4_w = __v4_w;
uvec4 const uvecl4_x_n = __v4_x_n;
uvec4 const uvecl4_y_n = __v4_y_n;
uvec4 const uvecl4_z_n = __v4_z_n;
uvec4 const uvecl4_w_n = __v4_w_n;

fvec2 const fvec2_one = __v2_one;
fvec2 const fvec2_zero = __v2_zero;
fvec2 const fvec2_one_n = __v2_one_n;
fvec2 const fvec2_x = __v2_x;
fvec2 const fvec2_y = __v2_y;
fvec2 const fvec2_x_n = __v2_x_n;
fvec2 const fvec2_y_n = __v2_y_n;

fvec3 const fvec3_one = __v3_one;
fvec3 const fvec3_zero = __v3_zero;
fvec3 const fvec3_one_n = __v3_one_n;
fvec3 const fvec3_x = __v3_x;
fvec3 const fvec3_y = __v3_y;
fvec3 const fvec3_z = __v3_z;
fvec3 const fvec3_x_n = __v3_x_n;
fvec3 const fvec3_y_n = __v3_y_n;
fvec3 const fvec3_z_n = __v3_z_n;

fvec4 const fvec4_one = __v4_one;
fvec4 const fvec4_zero = __v4_zero;
fvec4 const fvec4_one_n = __v4_one_n;
fvec4 const fvec4_x = __v4_x;
fvec4 const fvec4_y = __v4_y;
fvec4 const fvec4_z = __v4_z;
fvec4 const fvec4_w = __v4_w;
fvec4 const fvec4_x_n = __v4_x_n;
fvec4 const fvec4_y_n = __v4_y_n;
fvec4 const fvec4_z_n = __v4_z_n;
fvec4 const fvec4_w_n = __v4_w_n;

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
