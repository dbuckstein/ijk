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

	ijkRandom.c
	Source definitions for random number generation.
*/

#include "ijk/ijk-math/ijk-real/ijkRandom.h"


//-----------------------------------------------------------------------------

// ijk_random_seed
//	Random number generation seed.
i32 ijk_random_seed = 1235;

// ijk_random_max
//	Maximum random number that can be generated.
#define __ijk_random_max 134456
i32 const ijk_random_max = __ijk_random_max;

// ijk_random_max_inv_dbl
//	Inverse of maximum random number as double.
#define __ijk_random_max_inv 7.4373772832748259653715713690724e-6
dbl const ijk_random_max_inv_dbl = (dbl)__ijk_random_max_inv;

// ijk_random_max_inv_flt
//	Inverse of maximum random number as float.
flt const ijk_random_max_inv_flt = (flt)__ijk_random_max_inv;


//-----------------------------------------------------------------------------

iret ijkRandomTest()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;

	return ijk_success;
}


//-----------------------------------------------------------------------------
