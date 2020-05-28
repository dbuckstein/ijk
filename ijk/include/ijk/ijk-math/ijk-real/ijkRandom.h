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

	ijkRandom.h
	Simple random number generation.
*/

#ifndef _IJK_RANDOM_H_
#define _IJK_RANDOM_H_


#include "ijkReal.h"


//-----------------------------------------------------------------------------

// ijkRandomGetMax
//	Get maximum number that can be generated.
//		return: random max
i32 ijkRandomGetMax();

// ijkRandomGetSeed
//	Get random number generation seed.
//		return: random seed
i32 ijkRandomGetSeed();

// ijkRandomSetSeed
//	Set random number generation seed.
//		param seed: new seed
//		return: old random seed (before change)
i32 ijkRandomSetSeed(i32 const seed);

// ijkRandomNum_int
//	Generate random integer in [0, max).
//		return: random number
i32 ijkRandomNum_int();

// ijkRandomNum_flt
//	Generate random float in [0, max).
//		return: random number
flt ijkRandomNum_flt();

// ijkRandomNum_dbl
//	Generate random double in [0, max).
//		return: random number
dbl ijkRandomNum_dbl();


//-----------------------------------------------------------------------------


#include "_inl/ijkRandom.inl"


#endif	// !_IJK_RANDOM_H_