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

	ijk-math.c
	Default source for math library.
*/

#include "ijk/ijk-math/ijk-math.h"


//-----------------------------------------------------------------------------

void ijkMathTestReal()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;

	test_int = ijk_sgn_int(+9001);
	test_int = ijk_sgn_int(ijk_zero);
	test_int = ijk_sgn_int(-9001);

	test_flt = ijk_sgn_flt(+9001.0f);
	test_flt = ijk_sgn_flt(flt_zero);
	test_flt = ijk_sgn_flt(-9001.0f);

	test_dbl = ijk_sgn_dbl(+9001.0);
	test_dbl = ijk_sgn_dbl(dbl_zero);
	test_dbl = ijk_sgn_dbl(-9001.0);

	test = ijk_sgn(+ijk_x2r(9001));
	test = ijk_sgn(real_zero);
	test = ijk_sgn(-ijk_x2r(9001));

	test_int = ijk_abs_int(+9001);
	test_int = ijk_abs_int(ijk_zero);
	test_int = ijk_abs_int(-9001);

	test_flt = ijk_abs_flt(+9001.0f);
	test_flt = ijk_abs_flt(flt_zero);
	test_flt = ijk_abs_flt(-9001.0f);

	test_dbl = ijk_abs_dbl(+9001.0);
	test_dbl = ijk_abs_dbl(dbl_zero);
	test_dbl = ijk_abs_dbl(-9001.0);

	test = ijk_abs(+ijk_x2r(9001));
	test = ijk_abs(real_zero);
	test = ijk_abs(-ijk_x2r(9001));
}


void ijkMathTestRandom()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;

}


//-----------------------------------------------------------------------------

void ijkMathTest()
{
	ijkMathTestReal();
	ijkMathTestRandom();
}


//-----------------------------------------------------------------------------
