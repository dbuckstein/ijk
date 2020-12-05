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

#define __v2_1		{ +1, +1 }
#define __v2_0		{  0,  0 }
#define __v2_1n		{ -1, -1 }
#define __v2_x		{ +1,  0 }
#define __v2_y		{  0, +1 }
#define __v2_xn		{ -1,  0 }
#define __v2_yn		{  0, -1 }

#define __v3_1		{ +1, +1, +1 }
#define __v3_0		{  0,  0,  0 }
#define __v3_1n		{ -1, -1, -1 }
#define __v3_x		{ +1,  0,  0 }
#define __v3_y		{  0, +1,  0 }
#define __v3_z		{  0,  0, +1 }
#define __v3_xn		{ -1,  0,  0 }
#define __v3_yn		{  0, -1,  0 }
#define __v3_zn		{  0,  0, -1 }

#define __v4_1		{ +1, +1, +1, +1 }
#define __v4_0		{  0,  0,  0,  0 }
#define __v4_1n		{ -1, -1, -1, -1 }
#define __v4_x		{ +1,  0,  0,  0 }
#define __v4_y		{  0, +1,  0,  0 }
#define __v4_z		{  0,  0, +1,  0 }
#define __v4_w		{  0,  0,  0, +1 }
#define __v4_xn		{ -1,  0,  0,  0 }
#define __v4_yn		{  0, -1,  0,  0 }
#define __v4_zn		{  0,  0, -1,  0 }
#define __v4_wn		{  0,  0,  0, -1 }


//-----------------------------------------------------------------------------

bool2 const bool2_true = __v2_1;
bool2 const bool2_false = __v2_0;
bool2 const bool2_x = __v2_x;
bool2 const bool2_y = __v2_y;

bool3 const bool3_true = __v3_1;
bool3 const bool3_false = __v3_0;
bool3 const bool3_x = __v3_x;
bool3 const bool3_y = __v3_y;
bool3 const bool3_z = __v3_z;

bool4 const bool4_true = __v4_1;
bool4 const bool4_false = __v4_0;
bool4 const bool4_x = __v4_x;
bool4 const bool4_y = __v4_y;
bool4 const bool4_z = __v4_z;
bool4 const bool4_w = __v4_w;

int2 const int2_1 = __v2_1;
int2 const int2_0 = __v2_0;
int2 const int2_1n = __v2_1n;
int2 const int2_x = __v2_x;
int2 const int2_y = __v2_y;
int2 const int2_xn = __v2_xn;
int2 const int2_yn = __v2_yn;

int3 const int3_1 = __v3_1;
int3 const int3_0 = __v3_0;
int3 const int3_1n = __v3_1n;
int3 const int3_x = __v3_x;
int3 const int3_y = __v3_y;
int3 const int3_z = __v3_z;
int3 const int3_xn = __v3_xn;
int3 const int3_yn = __v3_yn;
int3 const int3_zn = __v3_zn;

int4 const int4_1 = __v4_1;
int4 const int4_0 = __v4_0;
int4 const int4_1n = __v4_1n;
int4 const int4_x = __v4_x;
int4 const int4_y = __v4_y;
int4 const int4_z = __v4_z;
int4 const int4_w = __v4_w;
int4 const int4_xn = __v4_xn;
int4 const int4_yn = __v4_yn;
int4 const int4_zn = __v4_zn;
int4 const int4_wn = __v4_wn;

intl2 const intl2_1 = __v2_1;
intl2 const intl2_0 = __v2_0;
intl2 const intl2_1n = __v2_1n;
intl2 const intl2_x = __v2_x;
intl2 const intl2_y = __v2_y;
intl2 const intl2_xn = __v2_xn;
intl2 const intl2_yn = __v2_yn;

intl3 const intl3_1 = __v3_1;
intl3 const intl3_0 = __v3_0;
intl3 const intl3_1n = __v3_1n;
intl3 const intl3_x = __v3_x;
intl3 const intl3_y = __v3_y;
intl3 const intl3_z = __v3_z;
intl3 const intl3_xn = __v3_xn;
intl3 const intl3_yn = __v3_yn;
intl3 const intl3_zn = __v3_zn;

intl4 const intl4_1 = __v4_1;
intl4 const intl4_0 = __v4_0;
intl4 const intl4_1n = __v4_1n;
intl4 const intl4_x = __v4_x;
intl4 const intl4_y = __v4_y;
intl4 const intl4_z = __v4_z;
intl4 const intl4_w = __v4_w;
intl4 const intl4_xn = __v4_xn;
intl4 const intl4_yn = __v4_yn;
intl4 const intl4_zn = __v4_zn;
intl4 const intl4_wn = __v4_wn;

uint2 const uint2_1 = __v2_1;
uint2 const uint2_0 = __v2_0;
uint2 const uint2_1n = __v2_1n;
uint2 const uint2_x = __v2_x;
uint2 const uint2_y = __v2_y;
uint2 const uint2_xn = __v2_xn;
uint2 const uint2_yn = __v2_yn;

uint3 const uint3_1 = __v3_1;
uint3 const uint3_0 = __v3_0;
uint3 const uint3_1n = __v3_1n;
uint3 const uint3_x = __v3_x;
uint3 const uint3_y = __v3_y;
uint3 const uint3_z = __v3_z;
uint3 const uint3_xn = __v3_xn;
uint3 const uint3_yn = __v3_yn;
uint3 const uint3_zn = __v3_zn;

uint4 const uint4_1 = __v4_1;
uint4 const uint4_0 = __v4_0;
uint4 const uint4_1n = __v4_1n;
uint4 const uint4_x = __v4_x;
uint4 const uint4_y = __v4_y;
uint4 const uint4_z = __v4_z;
uint4 const uint4_w = __v4_w;
uint4 const uint4_xn = __v4_xn;
uint4 const uint4_yn = __v4_yn;
uint4 const uint4_zn = __v4_zn;
uint4 const uint4_wn = __v4_wn;

uintl2 const uintl2_1 = __v2_1;
uintl2 const uintl2_0 = __v2_0;
uintl2 const uintl2_1n = __v2_1n;
uintl2 const uintl2_x = __v2_x;
uintl2 const uintl2_y = __v2_y;
uintl2 const uintl2_xn = __v2_xn;
uintl2 const uintl2_yn = __v2_yn;

uintl3 const uintl3_1 = __v3_1;
uintl3 const uintl3_0 = __v3_0;
uintl3 const uintl3_1n = __v3_1n;
uintl3 const uintl3_x = __v3_x;
uintl3 const uintl3_y = __v3_y;
uintl3 const uintl3_z = __v3_z;
uintl3 const uintl3_xn = __v3_xn;
uintl3 const uintl3_yn = __v3_yn;
uintl3 const uintl3_zn = __v3_zn;

uintl4 const uintl4_1 = __v4_1;
uintl4 const uintl4_0 = __v4_0;
uintl4 const uintl4_1n = __v4_1n;
uintl4 const uintl4_x = __v4_x;
uintl4 const uintl4_y = __v4_y;
uintl4 const uintl4_z = __v4_z;
uintl4 const uintl4_w = __v4_w;
uintl4 const uintl4_xn = __v4_xn;
uintl4 const uintl4_yn = __v4_yn;
uintl4 const uintl4_zn = __v4_zn;
uintl4 const uintl4_wn = __v4_wn;

float2 const float2_1 = __v2_1;
float2 const float2_0 = __v2_0;
float2 const float2_1n = __v2_1n;
float2 const float2_x = __v2_x;
float2 const float2_y = __v2_y;
float2 const float2_xn = __v2_xn;
float2 const float2_yn = __v2_yn;

float3 const float3_1 = __v3_1;
float3 const float3_0 = __v3_0;
float3 const float3_1n = __v3_1n;
float3 const float3_x = __v3_x;
float3 const float3_y = __v3_y;
float3 const float3_z = __v3_z;
float3 const float3_xn = __v3_xn;
float3 const float3_yn = __v3_yn;
float3 const float3_zn = __v3_zn;

float4 const float4_1 = __v4_1;
float4 const float4_0 = __v4_0;
float4 const float4_1n = __v4_1n;
float4 const float4_x = __v4_x;
float4 const float4_y = __v4_y;
float4 const float4_z = __v4_z;
float4 const float4_w = __v4_w;
float4 const float4_xn = __v4_xn;
float4 const float4_yn = __v4_yn;
float4 const float4_zn = __v4_zn;
float4 const float4_wn = __v4_wn;

double2 const double2_1 = __v2_1;
double2 const double2_0 = __v2_0;
double2 const double2_1n = __v2_1n;
double2 const double2_x = __v2_x;
double2 const double2_y = __v2_y;
double2 const double2_xn = __v2_xn;
double2 const double2_yn = __v2_yn;

double3 const double3_1 = __v3_1;
double3 const double3_0 = __v3_0;
double3 const double3_1n = __v3_1n;
double3 const double3_x = __v3_x;
double3 const double3_y = __v3_y;
double3 const double3_z = __v3_z;
double3 const double3_xn = __v3_xn;
double3 const double3_yn = __v3_yn;
double3 const double3_zn = __v3_zn;

double4 const double4_1 = __v4_1;
double4 const double4_0 = __v4_0;
double4 const double4_1n = __v4_1n;
double4 const double4_x = __v4_x;
double4 const double4_y = __v4_y;
double4 const double4_z = __v4_z;
double4 const double4_w = __v4_w;
double4 const double4_xn = __v4_xn;
double4 const double4_yn = __v4_yn;
double4 const double4_zn = __v4_zn;
double4 const double4_wn = __v4_wn;


//-----------------------------------------------------------------------------

bvec2 const bvec2_true = __v2_1;
bvec2 const bvec2_false = __v2_0;
bvec2 const bvec2_x = __v2_x;
bvec2 const bvec2_y = __v2_y;

bvec3 const bvec3_true = __v3_1;
bvec3 const bvec3_false = __v3_0;
bvec3 const bvec3_x = __v3_x;
bvec3 const bvec3_y = __v3_y;
bvec3 const bvec3_z = __v3_z;

bvec4 const bvec4_true = __v4_1;
bvec4 const bvec4_false = __v4_0;
bvec4 const bvec4_x = __v4_x;
bvec4 const bvec4_y = __v4_y;
bvec4 const bvec4_z = __v4_z;
bvec4 const bvec4_w = __v4_w;

ivec2 const ivec2_1 = __v2_1;
ivec2 const ivec2_0 = __v2_0;
ivec2 const ivec2_1n = __v2_1n;
ivec2 const ivec2_x = __v2_x;
ivec2 const ivec2_y = __v2_y;
ivec2 const ivec2_xn = __v2_xn;
ivec2 const ivec2_yn = __v2_yn;

ivec3 const ivec3_1 = __v3_1;
ivec3 const ivec3_0 = __v3_0;
ivec3 const ivec3_1n = __v3_1n;
ivec3 const ivec3_x = __v3_x;
ivec3 const ivec3_y = __v3_y;
ivec3 const ivec3_z = __v3_z;
ivec3 const ivec3_xn = __v3_xn;
ivec3 const ivec3_yn = __v3_yn;
ivec3 const ivec3_zn = __v3_zn;

ivec4 const ivec4_1 = __v4_1;
ivec4 const ivec4_0 = __v4_0;
ivec4 const ivec4_1n = __v4_1n;
ivec4 const ivec4_x = __v4_x;
ivec4 const ivec4_y = __v4_y;
ivec4 const ivec4_z = __v4_z;
ivec4 const ivec4_w = __v4_w;
ivec4 const ivec4_xn = __v4_xn;
ivec4 const ivec4_yn = __v4_yn;
ivec4 const ivec4_zn = __v4_zn;
ivec4 const ivec4_wn = __v4_wn;

ilvec2 const ilvec2_1 = __v2_1;
ilvec2 const ilvec2_0 = __v2_0;
ilvec2 const ilvec2_1n = __v2_1n;
ilvec2 const ilvec2_x = __v2_x;
ilvec2 const ilvec2_y = __v2_y;
ilvec2 const ilvec2_xn = __v2_xn;
ilvec2 const ilvec2_yn = __v2_yn;

ilvec3 const ilvec3_1 = __v3_1;
ilvec3 const ilvec3_0 = __v3_0;
ilvec3 const ilvec3_1n = __v3_1n;
ilvec3 const ilvec3_x = __v3_x;
ilvec3 const ilvec3_y = __v3_y;
ilvec3 const ilvec3_z = __v3_z;
ilvec3 const ilvec3_xn = __v3_xn;
ilvec3 const ilvec3_yn = __v3_yn;
ilvec3 const ilvec3_zn = __v3_zn;

ilvec4 const ilvec4_1 = __v4_1;
ilvec4 const ilvec4_0 = __v4_0;
ilvec4 const ilvec4_1n = __v4_1n;
ilvec4 const ilvec4_x = __v4_x;
ilvec4 const ilvec4_y = __v4_y;
ilvec4 const ilvec4_z = __v4_z;
ilvec4 const ilvec4_w = __v4_w;
ilvec4 const ilvec4_xn = __v4_xn;
ilvec4 const ilvec4_yn = __v4_yn;
ilvec4 const ilvec4_zn = __v4_zn;
ilvec4 const ilvec4_wn = __v4_wn;

uvec2 const uvec2_1 = __v2_1;
uvec2 const uvec2_0 = __v2_0;
uvec2 const uvec2_1n = __v2_1n;
uvec2 const uvec2_x = __v2_x;
uvec2 const uvec2_y = __v2_y;
uvec2 const uvec2_xn = __v2_xn;
uvec2 const uvec2_yn = __v2_yn;

uvec3 const uvec3_1 = __v3_1;
uvec3 const uvec3_0 = __v3_0;
uvec3 const uvec3_1n = __v3_1n;
uvec3 const uvec3_x = __v3_x;
uvec3 const uvec3_y = __v3_y;
uvec3 const uvec3_z = __v3_z;
uvec3 const uvec3_xn = __v3_xn;
uvec3 const uvec3_yn = __v3_yn;
uvec3 const uvec3_zn = __v3_zn;

uvec4 const uvec4_1 = __v4_1;
uvec4 const uvec4_0 = __v4_0;
uvec4 const uvec4_1n = __v4_1n;
uvec4 const uvec4_x = __v4_x;
uvec4 const uvec4_y = __v4_y;
uvec4 const uvec4_z = __v4_z;
uvec4 const uvec4_w = __v4_w;
uvec4 const uvec4_xn = __v4_xn;
uvec4 const uvec4_yn = __v4_yn;
uvec4 const uvec4_zn = __v4_zn;
uvec4 const uvec4_wn = __v4_wn;

ulvec2 const ulvec2_1 = __v2_1;
ulvec2 const ulvec2_0 = __v2_0;
ulvec2 const ulvec2_1n = __v2_1n;
ulvec2 const ulvec2_x = __v2_x;
ulvec2 const ulvec2_y = __v2_y;
ulvec2 const ulvec2_xn = __v2_xn;
ulvec2 const ulvec2_yn = __v2_yn;

ulvec3 const ulvec3_1 = __v3_1;
ulvec3 const ulvec3_0 = __v3_0;
ulvec3 const ulvec3_1n = __v3_1n;
ulvec3 const ulvec3_x = __v3_x;
ulvec3 const ulvec3_y = __v3_y;
ulvec3 const ulvec3_z = __v3_z;
ulvec3 const ulvec3_xn = __v3_xn;
ulvec3 const ulvec3_yn = __v3_yn;
ulvec3 const ulvec3_zn = __v3_zn;

ulvec4 const ulvec4_1 = __v4_1;
ulvec4 const ulvec4_0 = __v4_0;
ulvec4 const ulvec4_1n = __v4_1n;
ulvec4 const ulvec4_x = __v4_x;
ulvec4 const ulvec4_y = __v4_y;
ulvec4 const ulvec4_z = __v4_z;
ulvec4 const ulvec4_w = __v4_w;
ulvec4 const ulvec4_xn = __v4_xn;
ulvec4 const ulvec4_yn = __v4_yn;
ulvec4 const ulvec4_zn = __v4_zn;
ulvec4 const ulvec4_wn = __v4_wn;

fvec2 const fvec2_1 = __v2_1;
fvec2 const fvec2_0 = __v2_0;
fvec2 const fvec2_1n = __v2_1n;
fvec2 const fvec2_x = __v2_x;
fvec2 const fvec2_y = __v2_y;
fvec2 const fvec2_xn = __v2_xn;
fvec2 const fvec2_yn = __v2_yn;

fvec3 const fvec3_1 = __v3_1;
fvec3 const fvec3_0 = __v3_0;
fvec3 const fvec3_1n = __v3_1n;
fvec3 const fvec3_x = __v3_x;
fvec3 const fvec3_y = __v3_y;
fvec3 const fvec3_z = __v3_z;
fvec3 const fvec3_xn = __v3_xn;
fvec3 const fvec3_yn = __v3_yn;
fvec3 const fvec3_zn = __v3_zn;

fvec4 const fvec4_1 = __v4_1;
fvec4 const fvec4_0 = __v4_0;
fvec4 const fvec4_1n = __v4_1n;
fvec4 const fvec4_x = __v4_x;
fvec4 const fvec4_y = __v4_y;
fvec4 const fvec4_z = __v4_z;
fvec4 const fvec4_w = __v4_w;
fvec4 const fvec4_xn = __v4_xn;
fvec4 const fvec4_yn = __v4_yn;
fvec4 const fvec4_zn = __v4_zn;
fvec4 const fvec4_wn = __v4_wn;

vec2 const vec2_1 = __v2_1;
vec2 const vec2_0 = __v2_0;
vec2 const vec2_1n = __v2_1n;
vec2 const vec2_x = __v2_x;
vec2 const vec2_y = __v2_y;
vec2 const vec2_xn = __v2_xn;
vec2 const vec2_yn = __v2_yn;

vec3 const vec3_1 = __v3_1;
vec3 const vec3_0 = __v3_0;
vec3 const vec3_1n = __v3_1n;
vec3 const vec3_x = __v3_x;
vec3 const vec3_y = __v3_y;
vec3 const vec3_z = __v3_z;
vec3 const vec3_xn = __v3_xn;
vec3 const vec3_yn = __v3_yn;
vec3 const vec3_zn = __v3_zn;

vec4 const vec4_1 = __v4_1;
vec4 const vec4_0 = __v4_0;
vec4 const vec4_1n = __v4_1n;
vec4 const vec4_x = __v4_x;
vec4 const vec4_y = __v4_y;
vec4 const vec4_z = __v4_z;
vec4 const vec4_w = __v4_w;
vec4 const vec4_xn = __v4_xn;
vec4 const vec4_yn = __v4_yn;
vec4 const vec4_zn = __v4_zn;
vec4 const vec4_wn = __v4_wn;

dvec2 const dvec2_1 = __v2_1;
dvec2 const dvec2_0 = __v2_0;
dvec2 const dvec2_1n = __v2_1n;
dvec2 const dvec2_x = __v2_x;
dvec2 const dvec2_y = __v2_y;
dvec2 const dvec2_xn = __v2_xn;
dvec2 const dvec2_yn = __v2_yn;

dvec3 const dvec3_1 = __v3_1;
dvec3 const dvec3_0 = __v3_0;
dvec3 const dvec3_1n = __v3_1n;
dvec3 const dvec3_x = __v3_x;
dvec3 const dvec3_y = __v3_y;
dvec3 const dvec3_z = __v3_z;
dvec3 const dvec3_xn = __v3_xn;
dvec3 const dvec3_yn = __v3_yn;
dvec3 const dvec3_zn = __v3_zn;

dvec4 const dvec4_1 = __v4_1;
dvec4 const dvec4_0 = __v4_0;
dvec4 const dvec4_1n = __v4_1n;
dvec4 const dvec4_x = __v4_x;
dvec4 const dvec4_y = __v4_y;
dvec4 const dvec4_z = __v4_z;
dvec4 const dvec4_w = __v4_w;
dvec4 const dvec4_xn = __v4_xn;
dvec4 const dvec4_yn = __v4_yn;
dvec4 const dvec4_zn = __v4_zn;
dvec4 const dvec4_wn = __v4_wn;


//-----------------------------------------------------------------------------
