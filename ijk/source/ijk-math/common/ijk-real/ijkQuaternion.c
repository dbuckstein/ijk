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

	ijkQuaternion.c
	Source definitions for quaternion types.
*/

#include "ijk/ijk-math/ijk-real/ijkQuaternion.h"


//-----------------------------------------------------------------------------

#define __q_id		{	+0, +0, +0, +1	}
#define __dq_id		{	+0, +0, +0, +1,		+0, +0, +0, +0	}


//-----------------------------------------------------------------------------

float4 const float4q_id = __q_id;
fquat const fquat_id = __q_id;
quat const quat_id = __q_id;

float2x4 const float2x4_id = __dq_id;
float8 const float8dq_id = __dq_id;
fdualquat const fdualquat_id = __dq_id;
dualquat const dualquat_id = __dq_id;


//-----------------------------------------------------------------------------

double4 const double4q_id = __q_id;
dquat const dquat_id = __q_id;

double2x4 const double2x4_id = __dq_id;
double8 const double8dq_id = __dq_id;
ddualquat const ddualquat_id = __dq_id;


//-----------------------------------------------------------------------------
