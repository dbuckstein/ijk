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

#define __ijk_random_mod		134456
#define __ijk_random_max		134455
#define __ijk_random_mod_inv	7.4373772832748259653715713690724e-6
#define __ijk_random_mod_2inv	1.4874754566549651930743142738145e-5


// ijk_random_seed
//	Random number generation seed.
i32 ijk_random_seed = 1235;

// ijk_random_mod
//	Modulus that yields maximum random number that can be generated.
i32 const ijk_random_mod = __ijk_random_mod;

// ijk_random_max
//	Maximum random number that can be generated.
i32 const ijk_random_max = __ijk_random_max;

// ijk_random_mod_inv_flt
//	Inverse of maximum random number as float.
flt const ijk_random_mod_inv_flt = (flt)__ijk_random_mod_inv;

// ijk_random_mod_2inv_flt
//	Inverse of maximum random number, times 2, as float.
flt const ijk_random_mod_2inv_flt = (flt)__ijk_random_mod_2inv;

// ijk_random_mod_inv_dbl
//	Inverse of maximum random number as double.
dbl const ijk_random_mod_inv_dbl = (dbl)__ijk_random_mod_inv;

// ijk_random_mod_2inv_dbl
//	Inverse of maximum random number, times 2, as double.
dbl const ijk_random_mod_2inv_dbl = (dbl)__ijk_random_mod_2inv;


//-----------------------------------------------------------------------------
