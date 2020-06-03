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
	ibool test_b = ijk_false;

	test_int = ijk_lerp(100, 200, 6);
	test_int = ijk_unlerp(100, 200, 160);
	test_int = ijk_unlerp_safe(100, 200, 160);
	test_int = ijk_remap(-100, -50, 100, 200, 160);
	test_int = ijk_remap_safe(-100, -50, 100, 200, 160);
	test_int = ijk_divide(100, 4);
	test_int = ijk_sgn_int(+9001);
	test_int = ijk_sgn_int(ijk_zero);
	test_int = ijk_sgn_int(-9001);
	test_int = ijk_abs_int(+9001);
	test_int = ijk_abs_int(ijk_zero);
	test_int = ijk_abs_int(-9001);
	test_int = ijk_nrm2sym_int(0);
	test_int = ijk_sym2nrm_int(0);
	test_b = ijk_isnrm_int(-1);
	test_b = ijk_isnnrm_int(-1);
	test_b = ijk_issym_int(-1);
	test_b = ijk_isnsym_int(-1);
	test_b = ijk_iszero_int(0);
	test_b = ijk_isnzero_int(0);
	test_int = ijk_divide_safe_int(100, 4);

	test_flt = ijk_lerp(100.0f, 200.0f, 0.6f);
	test_flt = ijk_unlerp(100.0f, 200.0f, 160.0f);
	test_flt = ijk_unlerp_safe(100.0f, 200.0f, 160.0f);
	test_flt = ijk_remap(-100.0f, -50.0f, 100.0f, 200.0f, 160.0f);
	test_flt = ijk_remap_safe(-100.0f, -50.0f, 100.0f, 200.0f, 160.0f);
	test_flt = ijk_divide(100.0f, 4.0f);
	test_flt = ijk_sgn_flt(+9001.0f);
	test_flt = ijk_sgn_flt(flt_zero);
	test_flt = ijk_sgn_flt(-9001.0f);
	test_flt = ijk_abs_flt(+9001.0f);
	test_flt = ijk_abs_flt(flt_zero);
	test_flt = ijk_abs_flt(-9001.0f);
	test_flt = ijk_nrm2sym_flt(0.5f);
	test_flt = ijk_sym2nrm_flt(0.5f);
	test_b = ijk_isnrm_flt(-1.0f);
	test_b = ijk_isnnrm_flt(-1.0f);
	test_b = ijk_issym_flt(-1.0f);
	test_b = ijk_isnsym_flt(-1.0f);
	test_b = ijk_iszero_flt(flt_halfeps);
	test_b = ijk_isnzero_flt(flt_halfeps);
	test_flt = ijk_divide_safe_flt(100.0f, 4.0f);
	test_flt = ijk_recip_flt(100.0f);
	test_flt = ijk_recip_safe_flt(100.0f);
	test_flt = ijk_deg2rad_flt(flt_180);
	test_flt = ijk_rad2deg_flt(flt_pi);

	test_dbl = ijk_lerp(100.0, 200.0, 0.6);
	test_dbl = ijk_unlerp(100.0, 200.0, 160.0);
	test_dbl = ijk_unlerp_safe(100.0, 200.0, 160.0);
	test_dbl = ijk_remap(-100.0, -50.0, 100.0, 200.0, 160.0);
	test_dbl = ijk_remap_safe(-100.0, -50.0, 100.0, 200.0, 160.0);
	test_dbl = ijk_divide(100.0, 4.0);
	test_dbl = ijk_sgn_dbl(+9001.0);
	test_dbl = ijk_sgn_dbl(dbl_zero);
	test_dbl = ijk_sgn_dbl(-9001.0);
	test_dbl = ijk_abs_dbl(+9001.0);
	test_dbl = ijk_abs_dbl(dbl_zero);
	test_dbl = ijk_abs_dbl(-9001.0);
	test_dbl = ijk_nrm2sym_dbl(0.5);
	test_dbl = ijk_sym2nrm_dbl(0.5);
	test_b = ijk_isnrm_dbl(-1.0);
	test_b = ijk_isnnrm_dbl(-1.0);
	test_b = ijk_issym_dbl(-1.0);
	test_b = ijk_isnsym_dbl(-1.0);
	test_b = ijk_iszero_dbl(dbl_halfeps);
	test_b = ijk_isnzero_dbl(dbl_halfeps);
	test_dbl = ijk_divide_safe_dbl(100.0, 4.0);
	test_dbl = ijk_recip_dbl(100.0);
	test_dbl = ijk_recip_safe_dbl(100.0);
	test_dbl = ijk_deg2rad_dbl(dbl_180);
	test_dbl = ijk_rad2deg_dbl(dbl_pi);

	test = ijk_lerp(ijk_x2r(100), ijk_x2r(200), ijk_x2r(0.6));
	test = ijk_unlerp(ijk_x2r(100), ijk_x2r(200), ijk_x2r(160));
	test = ijk_unlerp_safe(ijk_x2r(100), ijk_x2r(200), ijk_x2r(160));
	test = ijk_remap(ijk_x2r(-100), ijk_x2r(-50), ijk_x2r(100), ijk_x2r(200), ijk_x2r(160));
	test = ijk_remap_safe(-ijk_x2r(100), ijk_x2r(-50), ijk_x2r(100), ijk_x2r(200), ijk_x2r(160));
	test = ijk_divide(ijk_x2r(100), ijk_x2r(4));
	test = ijk_abs(+ijk_x2r(9001));
	test = ijk_abs(real_zero);
	test = ijk_abs(-ijk_x2r(9001));
	test = ijk_sgn(+ijk_x2r(9001));
	test = ijk_sgn(real_zero);
	test = ijk_sgn(-ijk_x2r(9001));
	test = ijk_nrm2sym(ijk_x2r(0.5));
	test = ijk_sym2nrm(ijk_x2r(0.5));
	test_b = ijk_isnrm(ijk_x2r(-1.0));
	test_b = ijk_isnnrm(ijk_x2r(-1.0));
	test_b = ijk_issym(ijk_x2r(-1.0));
	test_b = ijk_isnsym(ijk_x2r(-1.0));
	test_b = ijk_iszero(real_halfeps);
	test_b = ijk_isnzero(real_halfeps);
	test = ijk_divide_safe(ijk_x2r(100), ijk_x2r(4));
	test = ijk_recip(ijk_x2r(100));
	test = ijk_recip_safe(ijk_x2r(100));
	test = ijk_deg2rad(real_180);
	test = ijk_rad2deg(real_pi);
}


void ijkMathTestRandom()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;
	i32 seed = 0;

	test_int = ijkRandomGetMax();
	test_int = ijkRandomGetSeed();
	seed = ijkRandomSetSeed(127);
	ijkRandomSetSeed(seed);

	ijkRandomSetSeed(seed);
	test_int = ijkRandomNum_int();
	test_int = ijkRandomNumMax_int(65535);
	test_int = ijkRandomNumRange_int(256, 65535);

	ijkRandomSetSeed(seed);
	test_flt = ijkRandomNum_flt();
	test_flt = ijkRandomNumMax_flt(65535.0f);
	test_flt = ijkRandomNumRange_flt(256.0f, 65535.0f);
	test_flt = ijkRandomNumUnitNrm_flt();
	test_flt = ijkRandomNumUnitSym_flt();

	ijkRandomSetSeed(seed);
	test_dbl = ijkRandomNum_dbl();
	test_dbl = ijkRandomNumMax_dbl(65535.0);
	test_dbl = ijkRandomNumRange_dbl(256.0, 65535.0);
	test_dbl = ijkRandomNumUnitNrm_dbl();
	test_dbl = ijkRandomNumUnitSym_dbl();

	ijkRandomSetSeed(seed);
	test = ijkRandomNum();
	test = ijkRandomNumMax(ijk_x2r(65535));
	test = ijkRandomNumRange(ijk_x2r(256), ijk_x2r(65535));
	test = ijkRandomNumUnitNrm();
	test = ijkRandomNumUnitSym();
}


//-----------------------------------------------------------------------------

void ijkMathTest()
{
	ijkMathTestReal();
	ijkMathTestRandom();
}


//-----------------------------------------------------------------------------
