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

	ijk-math.c
	Default source for math library.
*/

#include <malloc.h>
#include <stdio.h>

#include "ijk/ijk-math/ijk-math.h"


//-----------------------------------------------------------------------------

void ijkMathTestReal()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;
	bool test_b = ijk_false;

	i32 const x0min_int = 100, x0max_int = 200, x1min_int = -100, x1max_int = -50, x_int = 160;
	flt const x0min_flt = 100.0f, x0max_flt = 200.0f, x1min_flt = -100.0f, x1max_flt = -50.0f, x_flt = 160.0f;
	dbl const x0min_dbl = 100.0, x0max_dbl = 200.0, x1min_dbl = -100.0, x1max_dbl = -50.0, x_dbl = 160.0;
	real const x0min = ijk_x2r(100), x0max = ijk_x2r(200), x1min = ijk_x2r(-100), x1max = ijk_x2r(-50), x = ijk_x2r(160);

	test_int = ijk_lerp(x0min_int, x0max_int, 6);	// 700
	test_int = ijk_lerp_inv(x0min_int, x0max_int, x_int);	// 0
	test_int = ijk_lerp_inv_safe(x0min_int, x0max_int, x_int);	// 0
	test_int = ijk_remap(x1min_int, x1max_int, x0min_int, x0max_int, x_int);	// -70
	test_int = ijk_remap_safe(x1min_int, x1max_int, x0min_int, x0max_int, x_int);	// -70
	test_int = ijk_divide(x_int, 4);	// 40
	test_int = ijk_sgn_int(+x_int);		// +1
	test_int = ijk_sgn_int(ijk_zero);	// 0
	test_int = ijk_sgn_int(-x_int);		// -1
	test_int = ijk_abs_int(+x_int);		// +160
	test_int = ijk_abs_int(ijk_zero);	// 0
	test_int = ijk_abs_int(-x_int);		// +160
	test_int = ijk_nrm2sym_int(ijk_zero);	// -1
	test_int = ijk_sym2nrm_int(ijk_zero);	// 0
	test_b = ijk_isnrm_int(-ijk_one);	// 0 (false)
	test_b = ijk_isnnrm_int(-ijk_one);	// 1 (true)
	test_b = ijk_issym_int(-ijk_one);	// 1 (true)
	test_b = ijk_isnsym_int(-ijk_one);	// 0 (false)
	test_b = ijk_iszero_int(ijk_zero);	// 1 (true)
	test_b = ijk_isnzero_int(ijk_zero);	// 0 (false)
	test_int = ijk_divide_safe_int(x_int, 4);	// 40

	test_flt = ijk_lerp(x0min_flt, x0max_flt, flt_3quarters);	// 175.0
	test_flt = ijk_lerp_inv(x0min_flt, x0max_flt, x_flt);	// 0.6
	test_flt = ijk_lerp_inv_safe(x0min_flt, x0max_flt, x_flt);	// 0.6
	test_flt = ijk_remap(x1min_flt, x1max_flt, x0min_flt, x0max_flt, x_flt);	// -70.0
	test_flt = ijk_remap_safe(x1min_flt, x1max_flt, x0min_flt, x0max_flt, x_flt);	// -70.0
	test_flt = ijk_divide(x_flt, flt_four);	// 40.0
	test_flt = ijk_sgn_flt(+x_flt);			// +1.0
	test_flt = ijk_sgn_flt(flt_zero);		// 0.0
	test_flt = ijk_sgn_flt(-x_flt);			// -1.0
	test_flt = ijk_abs_flt(+x_flt);			// +160.0
	test_flt = ijk_abs_flt(flt_zero);		// 0.0
	test_flt = ijk_abs_flt(-x_flt);			// +160.0
	test_flt = ijk_nrm2sym_flt(flt_zero);	// -1.0
	test_flt = ijk_sym2nrm_flt(flt_zero);	// 0.5
	test_b = ijk_isnrm_flt(-flt_one);		// 0 (false)
	test_b = ijk_isnnrm_flt(-flt_one);		// 1 (true)
	test_b = ijk_issym_flt(-flt_one);		// 1 (true)
	test_b = ijk_isnsym_flt(-flt_one);		// 0 (false)
	test_b = ijk_iszero_flt(flt_zero);		// 1 (true)
	test_b = ijk_isnzero_flt(flt_zero);		// 0 (false)
	test_flt = ijk_divide_safe_flt(x_flt, flt_four);	// 40.0
	test_flt = ijk_recip_flt(x_flt);		// 0.00625
	test_flt = ijk_recip_safe_flt(x_flt);	// 0.00625
	test_flt = ijk_deg2rad_flt(flt_180);	// 3.14159 (pi)
	test_flt = ijk_rad2deg_flt(flt_pi);		// 180.0

	test_dbl = ijk_lerp(x0min_dbl, x0max_dbl, dbl_3quarters);	// 175.0
	test_dbl = ijk_lerp_inv(x0min_dbl, x0max_dbl, x_dbl);	// 0.6
	test_dbl = ijk_lerp_inv_safe(x0min_dbl, x0max_dbl, x_dbl);	// 0.6
	test_dbl = ijk_remap(x1min_dbl, x1max_dbl, x0min_dbl, x0max_dbl, x_dbl);	// -70.0
	test_dbl = ijk_remap_safe(x1min_dbl, x1max_dbl, x0min_dbl, x0max_dbl, x_dbl);	// -70.0
	test_dbl = ijk_divide(x_dbl, dbl_four);	// 40.0
	test_dbl = ijk_sgn_dbl(+x_dbl);			// +1.0
	test_dbl = ijk_sgn_dbl(dbl_zero);		// 0.0
	test_dbl = ijk_sgn_dbl(-x_dbl);			// -1.0
	test_dbl = ijk_abs_dbl(+x_dbl);			// +160.0
	test_dbl = ijk_abs_dbl(dbl_zero);		// 0.0
	test_dbl = ijk_abs_dbl(-x_dbl);			// +160.0
	test_dbl = ijk_nrm2sym_dbl(dbl_zero);	// -1.0
	test_dbl = ijk_sym2nrm_dbl(dbl_zero);	// 0.5
	test_b = ijk_isnrm_dbl(-dbl_one);		// 0 (false)
	test_b = ijk_isnnrm_dbl(-dbl_one);		// 1 (true)
	test_b = ijk_issym_dbl(-dbl_one);		// 1 (true)
	test_b = ijk_isnsym_dbl(-dbl_one);		// 0 (false)
	test_b = ijk_iszero_dbl(dbl_zero);		// 1 (true)
	test_b = ijk_isnzero_dbl(dbl_zero);		// 0 (false)
	test_dbl = ijk_divide_safe_dbl(x_dbl, dbl_four);	// 40.0
	test_dbl = ijk_recip_dbl(x_dbl);		// 0.00625
	test_dbl = ijk_recip_safe_dbl(x_dbl);	// 0.00625
	test_dbl = ijk_deg2rad_dbl(dbl_180);	// 3.14159 (pi)
	test_dbl = ijk_rad2deg_dbl(dbl_pi);		// 180.0

	test = ijk_lerp(x0min, x0max, real_3quarters);	// 175.0
	test = ijk_lerp_inv(x0min, x0max, x);	// 0.6
	test = ijk_lerp_inv_safe(x0min, x0max, x);	// 0.6
	test = ijk_remap(x1min, x1max, x0min, x0max, x);	// -70.0
	test = ijk_remap_safe(x1min, x1max, x0min, x0max, x);	// -70.0
	test = ijk_divide(x, real_four);	// 40.0
	test = ijk_sgn(+x);					// +1.0
	test = ijk_sgn(real_zero);			// 0.0
	test = ijk_sgn(-x);					// -1.0
	test = ijk_abs(+x);					// +160.0
	test = ijk_abs(real_zero);			// 0.0
	test = ijk_abs(-x);					// +160.0
	test = ijk_nrm2sym(real_zero);		// -1.0
	test = ijk_sym2nrm(real_zero);		// 0.5
	test_b = ijk_isnrm(-real_one);		// 0 (false)
	test_b = ijk_isnnrm(-real_one);		// 1 (true)
	test_b = ijk_issym(-real_one);		// 1 (true)
	test_b = ijk_isnsym(-real_one);		// 0 (false)
	test_b = ijk_iszero(real_zero);		// 1 (true)
	test_b = ijk_isnzero(real_zero);	// 0 (false)
	test = ijk_divide_safe(x, real_four);	// 40.0
	test = ijk_recip(x);				// 0.00625
	test = ijk_recip_safe(x);			// 0.00625
	test = ijk_deg2rad(real_180);		// 3.14159 (pi)
	test = ijk_rad2deg(real_pi);		// 180.0
}


void ijkMathTestSqrt()
{
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;

	flt const x_flt = 16.0f;
	dbl const x_dbl = 16.0;
	real const x = ijk_x2r(16);

	test_flt = ijkSqrtInv0x_flt(x_flt);		// 0.25 (approx)
	test_flt = ijkSqrt0x_flt(x_flt);		// 4.0 (approx)
	test_flt = ijkSqrt_flt(x_flt);			// 4.0
	test_flt = ijkSqrtInv_flt(x_flt);		// 0.25
	test_flt = ijkSqrtInvSafe_flt(x_flt);	// 0.25

	test_dbl = ijkSqrtInv0x_dbl(x_dbl);		// 0.25 (approx)
	test_dbl = ijkSqrt0x_dbl(x_dbl);		// 4.0 (approx)
	test_dbl = ijkSqrt_dbl(x_dbl);			// 4.0
	test_dbl = ijkSqrtInv_dbl(x_dbl);		// 0.25
	test_dbl = ijkSqrtInvSafe_dbl(x_dbl);	// 0.25

	test = ijkSqrtInv0x(x);		// 0.25 (approx)
	test = ijkSqrt0x(x);		// 4.0 (approx)
	test = ijkSqrt(x);			// 4.0
	test = ijkSqrtInv(x);		// 0.25
	test = ijkSqrtInvSafe(x);	// 0.25
}


void ijkMathTestStats()
{
	size test_int = ijk_zero;
	flt test_flt = flt_zero, test2_flt[1] = { flt_zero };
	dbl test_dbl = dbl_zero, test2_dbl[1] = { dbl_zero };
	real test = real_zero, test2[1] = { real_zero };

	size const n = 8, k = 4;
	schomp const v_int[] = { -5, -1, 1, 2, 5, 8, 9, 16 };
	flt const v_flt[] = { -5.0f, -1.0f, 1.0f, 2.0f, 5.0f, 8.0f, 9.0f, 16.0f };
	dbl const v_dbl[] = { -5.0, -1.0, 1.0, 2.0, 5.0, 8.0, 9.0, 16.0 };
	real const v[] = { ijk_x2r(-5), ijk_x2r(-1), ijk_x2r(1), ijk_x2r(2), ijk_x2r(5), ijk_x2r(8), ijk_x2r(9), ijk_x2r(16) };

	test_int = ijkStatsGetFactorial(n);			// 40320
	test_int = ijkStatsGetPermutations(n, k);	// 1680
	test_int = ijkStatsGetCombinations(n, k);	// 70
	test_int = ijkStatsPascal(n, k);			// 70

	test_flt = ijkStatsGetMedianInt_flt(v_int, n);				// 3.5
	test_flt = ijkStatsGetMeanInt_flt(v_int, n);				// 4.375
	test_flt = ijkStatsGetVarianceInt_flt(v_int, n, test2_flt);	// 43.410714
	test_flt = ijkStatsGetStdDevInt_flt(v_int, n, test2_flt);	// 6.588681
	test_flt = ijkStatsGetMedian_flt(v_flt, n);					// 3.5
	test_flt = ijkStatsGetMean_flt(v_flt, n);					// 4.375
	test_flt = ijkStatsGetVariance_flt(v_flt, n, test2_flt);	// 43.410714
	test_flt = ijkStatsGetStdDev_flt(v_flt, n, test2_flt);		// 6.588681

	test_dbl = ijkStatsGetMedianInt_dbl(v_int, n);				// 3.5
	test_dbl = ijkStatsGetMeanInt_dbl(v_int, n);				// 4.375
	test_dbl = ijkStatsGetVarianceInt_dbl(v_int, n, test2_dbl);	// 43.410714
	test_dbl = ijkStatsGetStdDevInt_dbl(v_int, n, test2_dbl);	// 6.588681
	test_dbl = ijkStatsGetMedian_dbl(v_dbl, n);					// 3.5
	test_dbl = ijkStatsGetMean_dbl(v_dbl, n);					// 4.375
	test_dbl = ijkStatsGetVariance_dbl(v_dbl, n, test2_dbl);	// 43.410714
	test_dbl = ijkStatsGetStdDev_dbl(v_dbl, n, test2_dbl);		// 6.588681

	test = ijkStatsGetMedianInt(v_int, n);			// 3.5
	test = ijkStatsGetMeanInt(v_int, n);			// 4.375
	test = ijkStatsGetVarianceInt(v_int, n, test2);	// 43.410714
	test = ijkStatsGetStdDevInt(v_int, n, test2);	// 6.588681
	test = ijkStatsGetMedian(v, n);					// 3.5
	test = ijkStatsGetMean(v, n);					// 4.375
	test = ijkStatsGetVariance(v, n, test2);		// 43.410714
	test = ijkStatsGetStdDev(v, n, test2);			// 6.588681
}


void ijkMathTestRandom()
{
	i32 test_int = ijk_zero;
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;
	i32 seed = 0;

	test_int = ijkRandomGetMod();	// 134456
	test_int = ijkRandomGetMax();	// 134455
	test_int = ijkRandomGetSeed();	// 1235
	seed = ijkRandomSetSeed(127);	// 1235
	ijkRandomSetSeed(seed);			// 127

	ijkRandomSetSeed(seed);							// 1235
	test_int = ijkRandomNum_int();					// 108102 = (1235 * 8121 + 28411) % 134456
	test_int = ijkRandomNumMax_int(65536);			// 61529 = (61529 = (108102 * 8121 + 28411) % 134456) % 65536
	test_int = ijkRandomNumRange_int(256, 65536);	// 1900 = (66924 = (61529 * 8121 + 28411) % 134456) % (65536 - 256) + 256

	ijkRandomSetSeed(seed);								// 66924
	test_flt = ijkRandomNum_flt();						// 108102 = (1235 * 8121 + 28411) % 134456
	test_flt = ijkRandomNumMax_flt(65536.0f);			// 29990.2164574 = (61529 = (108102 * 8121 + 28411) % 134456) * 65536 / 134456
	test_flt = ijkRandomNumRange_flt(256.0f, 65536.0f);	// 32748.4043553 = (66924 = (61529 * 8121 + 28411) % 134456) * (65536 - 256) / 134456 + 256
	test_flt = ijkRandomNumUnitNrm_flt();				// 0.350025287 = (47063 = (66924 * 8121 + 28411) % 134456) / 134456
	test_flt = ijkRandomNumUnitSym_flt();				// 0.53331945 = (103082 = (47063 * 8121 + 28411) % 134456) * 2 / 134456 - 1

	ijkRandomSetSeed(seed);								// 103082
	test_dbl = ijkRandomNum_dbl();						// 108102 = (1235 * 8121 + 28411) % 134456
	test_dbl = ijkRandomNumMax_dbl(65536.0);			// 29990.2164574 = (61529 = (108102 * 8121 + 28411) % 134456) * 65536 / 134456
	test_dbl = ijkRandomNumRange_dbl(256.0, 65536.0);	// 32748.4043553 = (66924 = (61529 * 8121 + 28411) % 134456) * (65536 - 256) / 134456 + 256
	test_dbl = ijkRandomNumUnitNrm_dbl();				// 0.350025287 = (47063 = (66924 * 8121 + 28411) % 134456) / 134456
	test_dbl = ijkRandomNumUnitSym_dbl();				// 0.53331945 = (103082 = (47063 * 8121 + 28411) % 134456) * 2 / 134456 - 1

	ijkRandomSetSeed(seed);									// 103082
	test = ijkRandomNum();									// 108102 = (1235 * 8121 + 28411) % 134456
	test = ijkRandomNumMax(ijk_x2r(65536));					// 29990.2164574 = (61529 = (108102 * 8121 + 28411) % 134456) * 65536 / 134456
	test = ijkRandomNumRange(ijk_x2r(256), ijk_x2r(65536));	// 32748.4043553 = (66924 = (61529 * 8121 + 28411) % 134456) * (65536 - 256) / 134456 + 256
	test = ijkRandomNumUnitNrm();							// 0.350025287 = (47063 = (66924 * 8121 + 28411) % 134456) / 134456
	test = ijkRandomNumUnitSym();							// 0.53331945 = (103082 = (47063 * 8121 + 28411) % 134456) * 2 / 134456 - 1
}


void ijkMathTestInterpolation()
{
	i32 const seedbase = 2048;
	i32 const vmin = -16, vmax = +16;

	/*
		[0][0] +0.75	[1][0] -0.25	[2][0] -3.25	[3][0] -0.25
		[0][1] +1.50	[1][1] -3.50	[2][1] +1.50	[3][1] +2.50
		[0][2] +2.25	[1][2] +1.25	[2][2] +0.25	[3][2] +3.25
		[0][3] +3.00	[1][3] -2.00	[2][3] +3.00	[3][3] -2.00
		
		tp = 0.375
		t0 = 0.750
		t1 = 0.125
		t2 = 0.500
		t = 0.875
	*/

	i32 const seed_flt = ijkRandomSetSeed(seedbase);
	flt const v_flt[][4] = { { flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax) }, { flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax) }, { flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax) }, { flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax), flt_quarter * (flt)ijkRandomNumRange_int(vmin, vmax) } };
	flt const tp_flt = flt_8th * (flt)ijkRandomNumMax_int(8), t0_flt = flt_8th * (flt)ijkRandomNumMax_int(8), t1_flt = flt_8th * (flt)ijkRandomNumMax_int(8), t2_flt = flt_8th * (flt)ijkRandomNumMax_int(8), t_flt = flt_8th * (flt)ijkRandomNumMax_int(8);
	
	i32 const seed_dbl = ijkRandomSetSeed(seedbase);
	dbl const v_dbl[][4] = { { dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax) }, { dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax) }, { dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax) }, { dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax), dbl_quarter * (dbl)ijkRandomNumRange_int(vmin, vmax) } };
	dbl const tp_dbl = dbl_8th * (dbl)ijkRandomNumMax_int(8), t0_dbl = dbl_8th * (dbl)ijkRandomNumMax_int(8), t1_dbl = dbl_8th * (dbl)ijkRandomNumMax_int(8), t2_dbl = dbl_8th * (dbl)ijkRandomNumMax_int(8), t_dbl = dbl_8th * (dbl)ijkRandomNumMax_int(8);

	i32 const seed = ijkRandomSetSeed(seedbase);
	real const v[][4] = { { real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax) }, { real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax) }, { real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax) }, { real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax), real_quarter * (real)ijkRandomNumRange_int(vmin, vmax) } };
	real const tp = real_8th * (real)ijkRandomNumMax_int(8), t0 = real_8th * (real)ijkRandomNumMax_int(8), t1 = real_8th * (real)ijkRandomNumMax_int(8), t2 = real_8th * (real)ijkRandomNumMax_int(8), t = real_8th * (real)ijkRandomNumMax_int(8);

	flt test_tTable_flt[33], test_lTable_flt[33], test_vTable_flt[33];
	dbl test_tTable_dbl[33], test_lTable_dbl[33], test_vTable_dbl[33];
	real test_tTable[33], test_lTable[33], test_vTable[33];
	size const numDivisions = (sizeof(test_tTable) - 1) / (sizeof(*test_tTable));
	size const order = 3;

	index test_index;
	flt test_flt;
	dbl test_dbl;
	real test;

	test_flt = ijkInterpNearest_flt(v_flt[0][0], v_flt[0][1], t_flt);	// 1.5
	test_flt = ijkInterpBinearest_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], t0_flt, t1_flt, t_flt);	// near(1.5, -0.25) = -0.25
	test_flt = ijkInterpLinear_flt(v_flt[0][0], v_flt[0][1], t_flt);	// 1.40625
	test_flt = ijkInterpBilinear_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], t0_flt, t1_flt, t_flt);	// lerp(1.3125, -0.65625) = -0.41015625
	test_flt = ijkInterpLinearInv_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2]);		// 2.0
	test_flt = ijkInterpLinearInvSafe_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2]);	// 2.0
	test_flt = ijkInterpLinearRev0_flt(1.40625f, v_flt[0][1], t_flt);	// v_flt[0][0]
	test_flt = ijkInterpLinearRev1_flt(v_flt[0][0], 1.40625f, t_flt);	// v_flt[0][1]
	test_flt = ijkInterpRemap_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], v_flt[1][2]);		// -0.4615384 -> 0.4038461
	test_flt = ijkInterpRemapSafe_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], v_flt[1][2]);	// -0.4615384 -> 0.4038461
	test_flt = ijkInterpBezier0_flt(v_flt[0][0], t_flt);	// 0.75
	test_flt = ijkInterpBezier1_flt(v_flt[0][0], v_flt[0][1], t_flt);	// 1.40625
	test_flt = ijkInterpBezier2_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2], t_flt);	// lerp(1.40625, lerp(1.5, 2.25) = 2.15625) = 2.0625
	test_flt = ijkInterpBezier3_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[0][3], t_flt);	// lerp(2.0625, lerp(2.15625, lerp(2.25, 3) = 2.90625) = 2.8125) = 2.71875
	test_flt = ijkInterpBezierN_flt(*v_flt, order, t_flt);	// 2.71875
	test_flt = ijkInterpSmoothstep_flt(flt_3quarters);	// 0.84375

	test_flt = ijkInterpCubicHermite_flt(v_flt[0][0], (v_flt[1][0] - v_flt[0][0]), v_flt[0][1], (v_flt[1][1] - v_flt[0][1]), t_flt);	// 1.9326171875
	test_flt = ijkInterpCubicHermiteHandles_flt(v_flt[0][0], v_flt[1][0], v_flt[0][1], v_flt[1][1], t_flt);	// 1.9326171875
	test_flt = ijkInterpCubicCatmullRom_flt(v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], t_flt);		// 1.3857421875
	test_flt = ijkInterpBicubicCatmullRom_flt(v_flt[3][3], v_flt[3][0], v_flt[3][1], v_flt[3][2], v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[1][3], v_flt[1][0], v_flt[1][1], v_flt[1][2], v_flt[2][3], v_flt[2][0], v_flt[2][1], v_flt[2][2], tp_flt, t0_flt, t1_flt, t2_flt, t_flt);	// CR(0.7958984375, 1.2421875, -0.4716796875, -1.1875) = -0.290437698364
	test_flt = ijkInterpReparamCubicHermite_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][0], (v_flt[1][0] - v_flt[0][0]), v_flt[0][1], (v_flt[1][1] - v_flt[0][1]));	// 1.88452148438
	test_flt = ijkInterpReparamCubicHermiteHandles_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][0], v_flt[1][0], v_flt[0][1], v_flt[1][1]);	// 1.88452148438
	test_flt = ijkInterpReparamCubicCatmullRom_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2]);	// 0.849609375
	test_flt = ijkInterpReparamBicubicCatmullRom_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[3][3], v_flt[3][0], v_flt[3][1], v_flt[3][2], v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[1][3], v_flt[1][0], v_flt[1][1], v_flt[1][2], v_flt[2][3], v_flt[2][0], v_flt[2][1], v_flt[2][2], tp_flt, t0_flt, t1_flt, t2_flt);	// 1.7138671875
	test_flt = ijkInterpSampleTableInc_flt(test_tTable_flt, test_vTable_flt, 0, 0, t_flt);	// -0.290437698364
	test_flt = ijkInterpSampleTableDec_flt(test_tTable_flt + numDivisions, test_vTable_flt + numDivisions, 0, -2, t_flt);	// -0.290437698364
	test_index = ijkInterpSampleTableIncIndex_flt(test_vTable_flt, test_tTable_flt, 0, 0, t_flt);	// 28 = 32 * 0.875
	test_index = ijkInterpSampleTableDecIndex_flt(test_vTable_flt, test_tTable_flt + numDivisions, 0, -2, t_flt);	// -4

	test_dbl = ijkInterpNearest_dbl(v_dbl[0][0], v_dbl[0][1], t_dbl);	// 1.5
	test_dbl = ijkInterpBinearest_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[1][0], v_dbl[1][1], t0_dbl, t1_dbl, t_dbl);	// near(1.5, -0.25) = -0.25
	test_dbl = ijkInterpLinear_dbl(v_dbl[0][0], v_dbl[0][1], t_dbl);	// 1.40625
	test_dbl = ijkInterpBilinear_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[1][0], v_dbl[1][1], t0_dbl, t1_dbl, t_dbl);	// lerp(1.3125, -0.65625) = -0.41015625
	test_dbl = ijkInterpLinearInv_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[0][2]);		// 2.0
	test_dbl = ijkInterpLinearInvSafe_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[0][2]);	// 2.0
	test_dbl = ijkInterpLinearRev0_dbl(1.40625, v_dbl[0][1], t_dbl);	// v_dbl[0][0]
	test_dbl = ijkInterpLinearRev1_dbl(v_dbl[0][0], 1.40625, t_dbl);	// v_dbl[0][1]
	test_dbl = ijkInterpRemap_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[1][0], v_dbl[1][1], v_dbl[1][2]);		// -0.4615384 -> 0.4038461
	test_dbl = ijkInterpRemapSafe_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[1][0], v_dbl[1][1], v_dbl[1][2]);	// -0.4615384 -> 0.4038461
	test_dbl = ijkInterpBezier0_dbl(v_dbl[0][0], t_dbl);	// 0.75
	test_dbl = ijkInterpBezier1_dbl(v_dbl[0][0], v_dbl[0][1], t_dbl);	// 1.40625
	test_dbl = ijkInterpBezier2_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[0][2], t_dbl);	// lerp(1.40625, lerp(1.5, 2.25) = 2.15625) = 2.0625
	test_dbl = ijkInterpBezier3_dbl(v_dbl[0][0], v_dbl[0][1], v_dbl[0][2], v_dbl[0][3], t_dbl);	// lerp(2.0625, lerp(2.15625, lerp(2.25, 3) = 2.90625) = 2.8125) = 2.71875
	test_dbl = ijkInterpBezierN_dbl(*v_dbl, order, t_dbl);	// 2.71875
	test_dbl = ijkInterpSmoothstep_dbl(dbl_3quarters);	// 0.84375

	test_dbl = ijkInterpCubicHermite_dbl(v_dbl[0][0], (v_dbl[1][0] - v_dbl[0][0]), v_dbl[0][1], (v_dbl[1][1] - v_dbl[0][1]), t_dbl);	// 1.9326171875
	test_dbl = ijkInterpCubicHermiteHandles_dbl(v_dbl[0][0], v_dbl[1][0], v_dbl[0][1], v_dbl[1][1], t_dbl);	// 1.9326171875
	test_dbl = ijkInterpCubicCatmullRom_dbl(v_dbl[0][3], v_dbl[0][0], v_dbl[0][1], v_dbl[0][2], t_dbl);		// 1.3857421875
	test_dbl = ijkInterpBicubicCatmullRom_dbl(v_dbl[3][3], v_dbl[3][0], v_dbl[3][1], v_dbl[3][2], v_dbl[0][3], v_dbl[0][0], v_dbl[0][1], v_dbl[0][2], v_dbl[1][3], v_dbl[1][0], v_dbl[1][1], v_dbl[1][2], v_dbl[2][3], v_dbl[2][0], v_dbl[2][1], v_dbl[2][2], tp_dbl, t0_dbl, t1_dbl, t2_dbl, t_dbl);	// CR(0.7958984375, 1.2421875, -0.4716796875, -1.1875) = -0.290437698364
	test_dbl = ijkInterpReparamCubicHermite_dbl(test_tTable_dbl, test_lTable_dbl, test_vTable_dbl, numDivisions, ijk_true, v_dbl[0][0], (v_dbl[1][0] - v_dbl[0][0]), v_dbl[0][1], (v_dbl[1][1] - v_dbl[0][1]));	// 1.88452148438
	test_dbl = ijkInterpReparamCubicHermiteHandles_dbl(test_tTable_dbl, test_lTable_dbl, test_vTable_dbl, numDivisions, ijk_true, v_dbl[0][0], v_dbl[1][0], v_dbl[0][1], v_dbl[1][1]);	// 1.88452148438
	test_dbl = ijkInterpReparamCubicCatmullRom_dbl(test_tTable_dbl, test_lTable_dbl, test_vTable_dbl, numDivisions, ijk_true, v_dbl[0][3], v_dbl[0][0], v_dbl[0][1], v_dbl[0][2]);	// 0.849609375
	test_dbl = ijkInterpReparamBicubicCatmullRom_dbl(test_tTable_dbl, test_lTable_dbl, test_vTable_dbl, numDivisions, ijk_true, v_dbl[3][3], v_dbl[3][0], v_dbl[3][1], v_dbl[3][2], v_dbl[0][3], v_dbl[0][0], v_dbl[0][1], v_dbl[0][2], v_dbl[1][3], v_dbl[1][0], v_dbl[1][1], v_dbl[1][2], v_dbl[2][3], v_dbl[2][0], v_dbl[2][1], v_dbl[2][2], tp_dbl, t0_dbl, t1_dbl, t2_dbl);	// 1.7138671875
	test_dbl = ijkInterpSampleTableInc_dbl(test_tTable_dbl, test_vTable_dbl, 0, 0, t_dbl);	// -0.290437698364
	test_dbl = ijkInterpSampleTableDec_dbl(test_tTable_dbl + numDivisions, test_vTable_dbl + numDivisions, 0, -2, t_dbl);	// -0.290437698364
	test_index = ijkInterpSampleTableIncIndex_dbl(test_vTable_dbl, test_tTable_dbl, 0, 0, t_dbl);	// 28 = 32 * 0.875
	test_index = ijkInterpSampleTableDecIndex_dbl(test_vTable_dbl, test_tTable_dbl + numDivisions, 0, -2, t_dbl);	// -4

	test = ijkInterpNearest(v[0][0], v[0][1], t);	// 1.5
	test = ijkInterpBinearest(v[0][0], v[0][1], v[1][0], v[1][1], t0, t1, t);	// near(1.5, -0.25) = -0.25
	test = ijkInterpLinear(v[0][0], v[0][1], t);	// 1.40625
	test = ijkInterpBilinear(v[0][0], v[0][1], v[1][0], v[1][1], t0, t1, t);	// lerp(1.3125, -0.65625) = -0.41015625
	test = ijkInterpLinearInv(v[0][0], v[0][1], v[0][2]);		// 2.0
	test = ijkInterpLinearInvSafe(v[0][0], v[0][1], v[0][2]);	// 2.0
	test = ijkInterpRemap(v[0][0], v[0][1], v[1][0], v[1][1], v[1][2]);		// -0.4615384 -> 0.4038461
	test = ijkInterpRemapSafe(v[0][0], v[0][1], v[1][0], v[1][1], v[1][2]);	// -0.4615384 -> 0.4038461
	test = ijkInterpBezier0(v[0][0], t);	// 0.75
	test = ijkInterpBezier1(v[0][0], v[0][1], t);	// 1.40625
	test = ijkInterpBezier2(v[0][0], v[0][1], v[0][2], t);	// lerp(1.40625, lerp(1.5, 2.25) = 2.15625) = 2.0625
	test = ijkInterpBezier3(v[0][0], v[0][1], v[0][2], v[0][3], t);	// lerp(2.0625, lerp(2.15625, lerp(2.25, 3) = 2.90625) = 2.8125) = 2.71875
	test = ijkInterpBezierN(*v, order, t);	// 2.71875

	test = ijkInterpCubicHermite(v[0][0], (v[1][0] - v[0][0]), v[0][1], (v[1][1] - v[0][1]), t);	// 1.9326171875
	test = ijkInterpCubicHermiteHandles(v[0][0], v[1][0], v[0][1], v[1][1], t);	// 1.9326171875
	test = ijkInterpCubicCatmullRom(v[0][3], v[0][0], v[0][1], v[0][2], t);		// 1.3857421875
	test = ijkInterpBicubicCatmullRom(v[3][3], v[3][0], v[3][1], v[3][2], v[0][3], v[0][0], v[0][1], v[0][2], v[1][3], v[1][0], v[1][1], v[1][2], v[2][3], v[2][0], v[2][1], v[2][2], tp, t0, t1, t2, t);	// CR(0.7958984375, 1.2421875, -0.4716796875, -1.1875) = -0.290437698364
	test = ijkInterpReparamCubicHermite(test_tTable, test_lTable, test_vTable, numDivisions, ijk_true, v[0][0], (v[1][0] - v[0][0]), v[0][1], (v[1][1] - v[0][1]));	// 1.88452148438
	test = ijkInterpReparamCubicHermiteHandles(test_tTable, test_lTable, test_vTable, numDivisions, ijk_true, v[0][0], v[1][0], v[0][1], v[1][1]);	// 1.88452148438
	test = ijkInterpReparamCubicCatmullRom(test_tTable, test_lTable, test_vTable, numDivisions, ijk_true, v[0][3], v[0][0], v[0][1], v[0][2]);	// 0.849609375
	test = ijkInterpReparamBicubicCatmullRom(test_tTable, test_lTable, test_vTable, numDivisions, ijk_true, v[3][3], v[3][0], v[3][1], v[3][2], v[0][3], v[0][0], v[0][1], v[0][2], v[1][3], v[1][0], v[1][1], v[1][2], v[2][3], v[2][0], v[2][1], v[2][2], tp, t0, t1, t2);	// 1.7138671875
	test = ijkInterpSampleTableInc(test_tTable, test_vTable, 0, 0, t);	// -0.290437698364
	test = ijkInterpSampleTableDec(test_tTable + numDivisions, test_vTable + numDivisions, 0, -2, t);	// -0.290437698364
	test_index = ijkInterpSampleTableIncIndex(test_vTable, test_tTable, 0, 0, t);	// 28 = 32 * 0.875
	test_index = ijkInterpSampleTableDecIndex(test_vTable, test_tTable + numDivisions, 0, -2, t);	// -4
}


void ijkMathTestTrigonometry()
{
	typedef union {
		flt table[6144 + 256 * szindex];
		struct {
			// ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4)
			flt const table_param[(720 * 1) * 4 + 2];
			flt const table_value[(720 * 1 + 90 * 1) * 4 + 2];
			index const table_index[(1024 * 1) + 2];
		};
	} TABLE_FLT;

	typedef union {
		dbl table[6144 + 256 * szindex];
		struct {
			// ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4)
			dbl const table_param[(720 * 1) * 4 + 2];
			dbl const table_value[(720 * 1 + 90 * 1) * 4 + 2];
			index const table_index[(2048 * 1) + 4];
		};
	} TABLE_DBL;

	typedef union {
		real table[6144 + 256 * szindex];
		struct {
			// ((720 * 2 + 90 * 1) * subdivisionsPerDegree + 4)
			real const table_param[(720 * 1) * 4 + 2];
			real const table_value[(720 * 1 + 90 * 1) * 4 + 2];
			index const table_index[((1024 * 1) + 2) * szrealbr];
		};
	} TABLE;

	size tableSz;
	real y, y_sin, x_cos;
	real const x_deg = real_60, x_inv = real_half, x_invrcp = real_two;
	real const x_rad = real_pi_3;

	size tableSz_flt;
	flt y_flt, y_sin_flt, x_cos_flt;
	flt const x_deg_flt = flt_60, x_inv_flt = flt_half, x_invrcp_flt = flt_two;
	flt const x_rad_flt = flt_pi_3;

	size tableSz_dbl;
	dbl y_dbl, y_sin_dbl, x_cos_dbl;
	dbl const x_deg_dbl = dbl_60, x_inv_dbl = dbl_half, x_invrcp_dbl = dbl_two;
	dbl const x_rad_dbl = dbl_pi_3;

	size const subdivisionsPerDegree = 4;

	TABLE* t = (TABLE*)malloc(sizeof(TABLE) + sizeof(TABLE_FLT) + sizeof(TABLE_DBL));
	TABLE_FLT* t_flt = (TABLE_FLT*)(t + 1);
	TABLE_DBL* t_dbl = (TABLE_DBL*)(t_flt + 1);
	if (t)
	{
		tableSz_flt = ijkTrigGetTableSize_flt(subdivisionsPerDegree);
		tableSz_flt = ijkTrigSetTable_flt(t_flt->table, sizeof(t_flt->table), subdivisionsPerDegree);
		tableSz_flt = ijkTrigInit_flt(t_flt->table, sizeof(t_flt->table), subdivisionsPerDegree);

		tableSz_dbl = ijkTrigGetTableSize_dbl(subdivisionsPerDegree);
		tableSz_dbl = ijkTrigSetTable_dbl(t_dbl->table, sizeof(t_dbl->table), subdivisionsPerDegree);
		tableSz_dbl = ijkTrigInit_dbl(t_dbl->table, sizeof(t_dbl->table), subdivisionsPerDegree);

		tableSz = ijkTrigGetTableSize(subdivisionsPerDegree);
		tableSz = ijkTrigSetTable(t->table, sizeof(t->table), subdivisionsPerDegree);
		tableSz = ijkTrigInit(t->table, sizeof(t->table), subdivisionsPerDegree);

		y_flt = ijkTrigDeg2Rad_flt(+x_deg_flt);	// +1.047197 (pi/3)
		y_flt = ijkTrigDeg2Rad_flt(-x_deg_flt);	// -1.047197 (pi/3)
		y_flt = ijkTrigRad2Deg_flt(+x_rad_flt);	// +60
		y_flt = ijkTrigRad2Deg_flt(-x_rad_flt);	// -60
		y_flt = ijkTrigValidateDegree_flt(+(flt)780);	// +60
		y_flt = ijkTrigValidateDegree_flt(-(flt)780);	// -60
		y_flt = ijkTrigValidateRadian_flt(+flt_4pi + flt_pi_3);	// +1.047197 (pi/3)
		y_flt = ijkTrigValidateRadian_flt(-flt_4pi - flt_pi_3);	// -1.047197 (pi/3)
		y_flt = ijkTrigValidateInverse_flt(+x_invrcp_flt);	// +1
		y_flt = ijkTrigValidateInverse_flt(-x_invrcp_flt);	// -1
		y_flt = ijkTrigValidateInverseRecip_flt(+x_inv_flt);	// +1
		y_flt = ijkTrigValidateInverseRecip_flt(-x_inv_flt);	// -1

		y_flt = ijkTrigSinCos_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 60, 0.866, 0.5
		y_flt = ijkTrigTanSinCos_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 1.732, 0.866, 0.5
		y_flt = ijkTrigCotSinCos_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 0.577, 0.866, 0.5
		y_flt = ijkTrigSin_deg_flt(+x_deg_flt);	// +0.866
		y_flt = ijkTrigSin_deg_flt(-x_deg_flt);	// -0.866
		y_flt = ijkTrigCos_deg_flt(+x_deg_flt);	// +0.5
		y_flt = ijkTrigCos_deg_flt(-x_deg_flt);	// +0.5
		y_flt = ijkTrigTan_deg_flt(+x_deg_flt);	// +1.732
		y_flt = ijkTrigTan_deg_flt(-x_deg_flt);	// -1.732
		y_flt = ijkTrigCsc_deg_flt(+x_deg_flt);	// +1.1547
		y_flt = ijkTrigCsc_deg_flt(-x_deg_flt);	// -1.1547
		y_flt = ijkTrigSec_deg_flt(+x_deg_flt);	// +2
		y_flt = ijkTrigSec_deg_flt(-x_deg_flt);	// +2
		y_flt = ijkTrigCot_deg_flt(+x_deg_flt);	// +0.577
		y_flt = ijkTrigCot_deg_flt(-x_deg_flt);	// -0.577
		y_flt = ijkTrigAsin_deg_flt(+x_inv_flt);	// +30
		y_flt = ijkTrigAsin_deg_flt(-x_inv_flt);	// -30
		y_flt = ijkTrigAcos_deg_flt(+x_inv_flt);	// +60
		y_flt = ijkTrigAcos_deg_flt(-x_inv_flt);	// +120
		y_flt = ijkTrigAtan_deg_flt(+x_inv_flt);	// +26.565
		y_flt = ijkTrigAtan_deg_flt(-x_inv_flt);	// -26.565
		y_flt = ijkTrigAcsc_deg_flt(+x_invrcp_flt);	// +30
		y_flt = ijkTrigAcsc_deg_flt(-x_invrcp_flt);	// -30
		y_flt = ijkTrigAsec_deg_flt(+x_invrcp_flt);	// +60
		y_flt = ijkTrigAsec_deg_flt(-x_invrcp_flt);	// +120
		y_flt = ijkTrigAcot_deg_flt(+x_invrcp_flt);	// +26.565
		y_flt = ijkTrigAcot_deg_flt(-x_invrcp_flt);	// -26.565
		y_flt = ijkTrigAtan2_deg_flt(+x_inv_flt, +flt_one);	// +26.565
		y_flt = ijkTrigAtan2_deg_flt(-x_inv_flt, +flt_one);	// -26.565
		y_flt = ijkTrigAtan2_deg_flt(+x_inv_flt, -flt_one);	// +153.435
		y_flt = ijkTrigAtan2_deg_flt(-x_inv_flt, -flt_one);	// -153.435
		y_flt = ijkTrigAtan2_deg_flt(+x_inv_flt, flt_zero);	// +90
		y_flt = ijkTrigAtan2_deg_flt(-x_inv_flt, flt_zero);	// -90
		y_flt = ijkTrigAtan2_deg_flt(flt_zero, flt_zero);	// 0 (undef)

		y_flt = ijkTrigSinCosTaylor_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 1.047197 (pi/3), 0.866, 0.5
		y_flt = ijkTrigTanSinCosTaylor_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 1.732, 0.866, 0.5
		y_flt = ijkTrigCotSinCosTaylor_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 0.577, 0.866, 0.5
		y_flt = ijkTrigSinTaylor_rad_flt(+x_rad_flt);	// +0.866
		y_flt = ijkTrigSinTaylor_rad_flt(-x_rad_flt);	// -0.866
		y_flt = ijkTrigCosTaylor_rad_flt(+x_rad_flt);	// +0.5
		y_flt = ijkTrigCosTaylor_rad_flt(-x_rad_flt);	// +0.5
		y_flt = ijkTrigTanTaylor_rad_flt(+x_rad_flt);	// +1.732
		y_flt = ijkTrigTanTaylor_rad_flt(-x_rad_flt);	// -1.732
		y_flt = ijkTrigCscTaylor_rad_flt(+x_rad_flt);	// +1.1547
		y_flt = ijkTrigCscTaylor_rad_flt(-x_rad_flt);	// -1.1547
		y_flt = ijkTrigSecTaylor_rad_flt(+x_rad_flt);	// +2
		y_flt = ijkTrigSecTaylor_rad_flt(-x_rad_flt);	// +2
		y_flt = ijkTrigCotTaylor_rad_flt(+x_rad_flt);	// +0.577
		y_flt = ijkTrigCotTaylor_rad_flt(-x_rad_flt);	// -0.577

		y_flt = ijkTrigSinCos_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 1.047197 (pi/3), 0.866, 0.5
		y_flt = ijkTrigTanSinCos_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 1.732, 0.866, 0.5
		y_flt = ijkTrigCotSinCos_rad_flt(x_rad_flt, &y_sin_flt, &x_cos_flt);	// 0.577, 0.866, 0.5
		y_flt = ijkTrigSin_rad_flt(+x_rad_flt);	// +0.866
		y_flt = ijkTrigSin_rad_flt(-x_rad_flt);	// -0.866
		y_flt = ijkTrigCos_rad_flt(+x_rad_flt);	// +0.5
		y_flt = ijkTrigCos_rad_flt(-x_rad_flt);	// +0.5
		y_flt = ijkTrigTan_rad_flt(+x_rad_flt);	// +1.732
		y_flt = ijkTrigTan_rad_flt(-x_rad_flt);	// -1.732
		y_flt = ijkTrigCsc_rad_flt(+x_rad_flt);	// +1.1547
		y_flt = ijkTrigCsc_rad_flt(-x_rad_flt);	// -1.1547
		y_flt = ijkTrigSec_rad_flt(+x_rad_flt);	// +2
		y_flt = ijkTrigSec_rad_flt(-x_rad_flt);	// +2
		y_flt = ijkTrigCot_rad_flt(+x_rad_flt);	// +0.577
		y_flt = ijkTrigCot_rad_flt(-x_rad_flt);	// -0.577
		y_flt = ijkTrigAsin_rad_flt(+x_inv_flt);	// +0.523599 (pi/6)
		y_flt = ijkTrigAsin_rad_flt(-x_inv_flt);	// -0.523599 (pi/6)
		y_flt = ijkTrigAcos_rad_flt(+x_inv_flt);	// +1.047197 (pi/3)
		y_flt = ijkTrigAcos_rad_flt(-x_inv_flt);	// +2.094395 (2pi/3)
		y_flt = ijkTrigAtan_rad_flt(+x_inv_flt);	// +0.463647
		y_flt = ijkTrigAtan_rad_flt(-x_inv_flt);	// -0.463647
		y_flt = ijkTrigAcsc_rad_flt(+x_invrcp_flt);	// +0.523599 (pi/6)
		y_flt = ijkTrigAcsc_rad_flt(-x_invrcp_flt);	// -0.523599 (pi/6)
		y_flt = ijkTrigAsec_rad_flt(+x_invrcp_flt);	// +1.047197 (pi/3)
		y_flt = ijkTrigAsec_rad_flt(-x_invrcp_flt);	// +2.094395 (2pi/3)
		y_flt = ijkTrigAcot_rad_flt(+x_invrcp_flt);	// +0.463647
		y_flt = ijkTrigAcot_rad_flt(-x_invrcp_flt);	// -0.463647
		y_flt = ijkTrigAtan2_rad_flt(+x_inv_flt, +flt_one);	// +0.463647
		y_flt = ijkTrigAtan2_rad_flt(-x_inv_flt, +flt_one);	// -0.463647
		y_flt = ijkTrigAtan2_rad_flt(+x_inv_flt, -flt_one);	// +2.677946
		y_flt = ijkTrigAtan2_rad_flt(-x_inv_flt, -flt_one);	// -2.677946
		y_flt = ijkTrigAtan2_rad_flt(+x_inv_flt, flt_zero);	// +1.570796 (pi/2)
		y_flt = ijkTrigAtan2_rad_flt(-x_inv_flt, flt_zero);	// -1.570796 (pi/2)
		y_flt = ijkTrigAtan2_rad_flt(flt_zero, flt_zero);	// 0 (undef)

		y_flt = ijkTrigSinCosTaylor_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 60, 0.866, 0.5
		y_flt = ijkTrigTanSinCosTaylor_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 1.732, 0.866, 0.5
		y_flt = ijkTrigCotSinCosTaylor_deg_flt(x_deg_flt, &y_sin_flt, &x_cos_flt);	// 0.577, 0.866, 0.5
		y_flt = ijkTrigSinTaylor_deg_flt(+x_deg_flt);	// +0.866
		y_flt = ijkTrigSinTaylor_deg_flt(-x_deg_flt);	// -0.866
		y_flt = ijkTrigCosTaylor_deg_flt(+x_deg_flt);	// +0.5
		y_flt = ijkTrigCosTaylor_deg_flt(-x_deg_flt);	// +0.5
		y_flt = ijkTrigTanTaylor_deg_flt(+x_deg_flt);	// +1.732
		y_flt = ijkTrigTanTaylor_deg_flt(-x_deg_flt);	// -1.732
		y_flt = ijkTrigCscTaylor_deg_flt(+x_deg_flt);	// +1.1547
		y_flt = ijkTrigCscTaylor_deg_flt(-x_deg_flt);	// -1.1547
		y_flt = ijkTrigSecTaylor_deg_flt(+x_deg_flt);	// +2
		y_flt = ijkTrigSecTaylor_deg_flt(-x_deg_flt);	// +2
		y_flt = ijkTrigCotTaylor_deg_flt(+x_deg_flt);	// +0.577
		y_flt = ijkTrigCotTaylor_deg_flt(-x_deg_flt);	// -0.577

		y_flt = ijkTrigPointToEdgeRatio_flt(flt_360, 24);	// 0.991445
		y_flt = ijkTrigEdgeToPointRatio_flt(flt_360, 24);	// 1.008629
		y_flt = ijkTrigPointToFaceRatio_flt(flt_360, flt_180, 24, 18);	// 0.987672
		y_flt = ijkTrigFaceToPointRatio_flt(flt_360, flt_180, 24, 18);	// 1.012482
		y_flt = ijkTrigSmoothstepInv_flt(0.84375f);	// 0.75
		y_flt = ijkTrigExp_flt(flt_two);			// 7.389056098930650227230427460575
		y_flt = ijkTrigLn1p_flt(6.389056098930650227230427460575f);		// 2
		y_flt = ijkTrigPow_flt(flt_three, flt_four);	// 81

		y_dbl = ijkTrigDeg2Rad_dbl(+x_deg_dbl);	// +1.047197 (pi/3)
		y_dbl = ijkTrigDeg2Rad_dbl(-x_deg_dbl);	// -1.047197 (pi/3)
		y_dbl = ijkTrigRad2Deg_dbl(+x_rad_dbl);	// +60
		y_dbl = ijkTrigRad2Deg_dbl(-x_rad_dbl);	// -60
		y_dbl = ijkTrigValidateDegree_dbl(+(dbl)780);	// +60
		y_dbl = ijkTrigValidateDegree_dbl(-(dbl)780);	// -60
		y_dbl = ijkTrigValidateRadian_dbl(+dbl_4pi + dbl_pi_3);	// +1.047197 (pi/3)
		y_dbl = ijkTrigValidateRadian_dbl(-dbl_4pi - dbl_pi_3);	// -1.047197 (pi/3)
		y_dbl = ijkTrigValidateInverse_dbl(+x_invrcp_dbl);	// +1
		y_dbl = ijkTrigValidateInverse_dbl(-x_invrcp_dbl);	// -1
		y_dbl = ijkTrigValidateInverseRecip_dbl(+x_inv_dbl);	// +1
		y_dbl = ijkTrigValidateInverseRecip_dbl(-x_inv_dbl);	// -1

		y_dbl = ijkTrigSinCos_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 60, 0.866, 0.5
		y_dbl = ijkTrigTanSinCos_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.732, 0.866, 0.5
		y_dbl = ijkTrigCotSinCos_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 0.577, 0.866, 0.5
		y_dbl = ijkTrigSin_deg_dbl(+x_deg_dbl);	// +0.866
		y_dbl = ijkTrigSin_deg_dbl(-x_deg_dbl);	// -0.866
		y_dbl = ijkTrigCos_deg_dbl(+x_deg_dbl);	// +0.5
		y_dbl = ijkTrigCos_deg_dbl(-x_deg_dbl);	// +0.5
		y_dbl = ijkTrigTan_deg_dbl(+x_deg_dbl);	// +1.732
		y_dbl = ijkTrigTan_deg_dbl(-x_deg_dbl);	// -1.732
		y_dbl = ijkTrigCsc_deg_dbl(+x_deg_dbl);	// +1.1547
		y_dbl = ijkTrigCsc_deg_dbl(-x_deg_dbl);	// -1.1547
		y_dbl = ijkTrigSec_deg_dbl(+x_deg_dbl);	// +2
		y_dbl = ijkTrigSec_deg_dbl(-x_deg_dbl);	// +2
		y_dbl = ijkTrigCot_deg_dbl(+x_deg_dbl);	// +0.577
		y_dbl = ijkTrigCot_deg_dbl(-x_deg_dbl);	// -0.577
		y_dbl = ijkTrigAsin_deg_dbl(+x_inv_dbl);	// +30
		y_dbl = ijkTrigAsin_deg_dbl(-x_inv_dbl);	// -30
		y_dbl = ijkTrigAcos_deg_dbl(+x_inv_dbl);	// +60
		y_dbl = ijkTrigAcos_deg_dbl(-x_inv_dbl);	// +120
		y_dbl = ijkTrigAtan_deg_dbl(+x_inv_dbl);	// +26.565
		y_dbl = ijkTrigAtan_deg_dbl(-x_inv_dbl);	// -26.565
		y_dbl = ijkTrigAcsc_deg_dbl(+x_invrcp_dbl);	// +30
		y_dbl = ijkTrigAcsc_deg_dbl(-x_invrcp_dbl);	// -30
		y_dbl = ijkTrigAsec_deg_dbl(+x_invrcp_dbl);	// +60
		y_dbl = ijkTrigAsec_deg_dbl(-x_invrcp_dbl);	// +120
		y_dbl = ijkTrigAcot_deg_dbl(+x_invrcp_dbl);	// +26.565
		y_dbl = ijkTrigAcot_deg_dbl(-x_invrcp_dbl);	// -26.565
		y_dbl = ijkTrigAtan2_deg_dbl(+x_inv_dbl, +dbl_one);	// +26.565
		y_dbl = ijkTrigAtan2_deg_dbl(-x_inv_dbl, +dbl_one);	// -26.565
		y_dbl = ijkTrigAtan2_deg_dbl(+x_inv_dbl, -dbl_one);	// +153.435
		y_dbl = ijkTrigAtan2_deg_dbl(-x_inv_dbl, -dbl_one);	// -153.435
		y_dbl = ijkTrigAtan2_deg_dbl(+x_inv_dbl, dbl_zero);	// +90
		y_dbl = ijkTrigAtan2_deg_dbl(-x_inv_dbl, dbl_zero);	// -90
		y_dbl = ijkTrigAtan2_deg_dbl(dbl_zero, dbl_zero);	// 0 (undef)

		y_dbl = ijkTrigSinCosTaylor_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.047197 (pi/3), 0.866, 0.5
		y_dbl = ijkTrigTanSinCosTaylor_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.732, 0.866, 0.5
		y_dbl = ijkTrigCotSinCosTaylor_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 0.577, 0.866, 0.5
		y_dbl = ijkTrigSinTaylor_rad_dbl(+x_rad_dbl);	// +0.866
		y_dbl = ijkTrigSinTaylor_rad_dbl(-x_rad_dbl);	// -0.866
		y_dbl = ijkTrigCosTaylor_rad_dbl(+x_rad_dbl);	// +0.5
		y_dbl = ijkTrigCosTaylor_rad_dbl(-x_rad_dbl);	// +0.5
		y_dbl = ijkTrigTanTaylor_rad_dbl(+x_rad_dbl);	// +1.732
		y_dbl = ijkTrigTanTaylor_rad_dbl(-x_rad_dbl);	// -1.732
		y_dbl = ijkTrigCscTaylor_rad_dbl(+x_rad_dbl);	// +1.1547
		y_dbl = ijkTrigCscTaylor_rad_dbl(-x_rad_dbl);	// -1.1547
		y_dbl = ijkTrigSecTaylor_rad_dbl(+x_rad_dbl);	// +2
		y_dbl = ijkTrigSecTaylor_rad_dbl(-x_rad_dbl);	// +2
		y_dbl = ijkTrigCotTaylor_rad_dbl(+x_rad_dbl);	// +0.577
		y_dbl = ijkTrigCotTaylor_rad_dbl(-x_rad_dbl);	// -0.577

		y_dbl = ijkTrigSinCos_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.047197 (pi/3), 0.866, 0.5
		y_dbl = ijkTrigTanSinCos_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.732, 0.866, 0.5
		y_dbl = ijkTrigCotSinCos_rad_dbl(x_rad_dbl, &y_sin_dbl, &x_cos_dbl);	// 0.577, 0.866, 0.5
		y_dbl = ijkTrigSin_rad_dbl(+x_rad_dbl);	// +0.866
		y_dbl = ijkTrigSin_rad_dbl(-x_rad_dbl);	// -0.866
		y_dbl = ijkTrigCos_rad_dbl(+x_rad_dbl);	// +0.5
		y_dbl = ijkTrigCos_rad_dbl(-x_rad_dbl);	// +0.5
		y_dbl = ijkTrigTan_rad_dbl(+x_rad_dbl);	// +1.732
		y_dbl = ijkTrigTan_rad_dbl(-x_rad_dbl);	// -1.732
		y_dbl = ijkTrigCsc_rad_dbl(+x_rad_dbl);	// +1.1547
		y_dbl = ijkTrigCsc_rad_dbl(-x_rad_dbl);	// -1.1547
		y_dbl = ijkTrigSec_rad_dbl(+x_rad_dbl);	// +2
		y_dbl = ijkTrigSec_rad_dbl(-x_rad_dbl);	// +2
		y_dbl = ijkTrigCot_rad_dbl(+x_rad_dbl);	// +0.577
		y_dbl = ijkTrigCot_rad_dbl(-x_rad_dbl);	// -0.577
		y_dbl = ijkTrigAsin_rad_dbl(+x_inv_dbl);	// +0.523599 (pi/6)
		y_dbl = ijkTrigAsin_rad_dbl(-x_inv_dbl);	// -0.523599 (pi/6)
		y_dbl = ijkTrigAcos_rad_dbl(+x_inv_dbl);	// +1.047197 (pi/3)
		y_dbl = ijkTrigAcos_rad_dbl(-x_inv_dbl);	// +2.094395 (2pi/3)
		y_dbl = ijkTrigAtan_rad_dbl(+x_inv_dbl);	// +0.463647
		y_dbl = ijkTrigAtan_rad_dbl(-x_inv_dbl);	// -0.463647
		y_dbl = ijkTrigAcsc_rad_dbl(+x_invrcp_dbl);	// +0.523599 (pi/6)
		y_dbl = ijkTrigAcsc_rad_dbl(-x_invrcp_dbl);	// -0.523599 (pi/6)
		y_dbl = ijkTrigAsec_rad_dbl(+x_invrcp_dbl);	// +1.047197 (pi/3)
		y_dbl = ijkTrigAsec_rad_dbl(-x_invrcp_dbl);	// +2.094395 (2pi/3)
		y_dbl = ijkTrigAcot_rad_dbl(+x_invrcp_dbl);	// +0.463647
		y_dbl = ijkTrigAcot_rad_dbl(-x_invrcp_dbl);	// -0.463647
		y_dbl = ijkTrigAtan2_rad_dbl(+x_inv_dbl, +dbl_one);	// +0.463647
		y_dbl = ijkTrigAtan2_rad_dbl(-x_inv_dbl, +dbl_one);	// -0.463647
		y_dbl = ijkTrigAtan2_rad_dbl(+x_inv_dbl, -dbl_one);	// +2.677946
		y_dbl = ijkTrigAtan2_rad_dbl(-x_inv_dbl, -dbl_one);	// -2.677946
		y_dbl = ijkTrigAtan2_rad_dbl(+x_inv_dbl, dbl_zero);	// +1.570796 (pi/2)
		y_dbl = ijkTrigAtan2_rad_dbl(-x_inv_dbl, dbl_zero);	// -1.570796 (pi/2)
		y_dbl = ijkTrigAtan2_rad_dbl(dbl_zero, dbl_zero);	// 0 (undef)

		y_dbl = ijkTrigSinCosTaylor_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 60, 0.866, 0.5
		y_dbl = ijkTrigTanSinCosTaylor_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 1.732, 0.866, 0.5
		y_dbl = ijkTrigCotSinCosTaylor_deg_dbl(x_deg_dbl, &y_sin_dbl, &x_cos_dbl);	// 0.577, 0.866, 0.5
		y_dbl = ijkTrigSinTaylor_deg_dbl(+x_deg_dbl);	// +0.866
		y_dbl = ijkTrigSinTaylor_deg_dbl(-x_deg_dbl);	// -0.866
		y_dbl = ijkTrigCosTaylor_deg_dbl(+x_deg_dbl);	// +0.5
		y_dbl = ijkTrigCosTaylor_deg_dbl(-x_deg_dbl);	// +0.5
		y_dbl = ijkTrigTanTaylor_deg_dbl(+x_deg_dbl);	// +1.732
		y_dbl = ijkTrigTanTaylor_deg_dbl(-x_deg_dbl);	// -1.732
		y_dbl = ijkTrigCscTaylor_deg_dbl(+x_deg_dbl);	// +1.1547
		y_dbl = ijkTrigCscTaylor_deg_dbl(-x_deg_dbl);	// -1.1547
		y_dbl = ijkTrigSecTaylor_deg_dbl(+x_deg_dbl);	// +2
		y_dbl = ijkTrigSecTaylor_deg_dbl(-x_deg_dbl);	// +2
		y_dbl = ijkTrigCotTaylor_deg_dbl(+x_deg_dbl);	// +0.577
		y_dbl = ijkTrigCotTaylor_deg_dbl(-x_deg_dbl);	// -0.577

		y_dbl = ijkTrigPointToEdgeRatio_dbl(dbl_360, 24);	// 0.991445
		y_dbl = ijkTrigEdgeToPointRatio_dbl(dbl_360, 24);	// 1.008629
		y_dbl = ijkTrigPointToFaceRatio_dbl(dbl_360, dbl_180, 24, 18);	// 0.987672
		y_dbl = ijkTrigFaceToPointRatio_dbl(dbl_360, dbl_180, 24, 18);	// 1.012482
		y_dbl = ijkTrigSmoothstepInv_dbl(0.84375);	// 0.75
		y_dbl = ijkTrigExp_dbl(dbl_two);			// 7.389056098930650227230427460575
		y_dbl = ijkTrigLn1p_dbl(6.389056098930650227230427460575);		// 2
		y_dbl = ijkTrigPow_dbl(dbl_three, dbl_four);	// 81

		y = ijkTrigDeg2Rad(+x_deg);	// +1.047197 (pi/3)
		y = ijkTrigDeg2Rad(-x_deg);	// -1.047197 (pi/3)
		y = ijkTrigRad2Deg(+x_rad);	// +60
		y = ijkTrigRad2Deg(-x_rad);	// -60
		y = ijkTrigValidateDegree(+(real)780);	// +60
		y = ijkTrigValidateDegree(-(real)780);	// -60
		y = ijkTrigValidateRadian(+real_4pi + real_pi_3);	// +1.047197 (pi/3)
		y = ijkTrigValidateRadian(-real_4pi - real_pi_3);	// -1.047197 (pi/3)
		y = ijkTrigValidateInverse(+x_invrcp);	// +1
		y = ijkTrigValidateInverse(-x_invrcp);	// -1
		y = ijkTrigValidateInverseRecip(+x_inv);	// +1
		y = ijkTrigValidateInverseRecip(-x_inv);	// -1

		y = ijkTrigSinCos_deg(x_deg, &y_sin, &x_cos);	// 60, 0.866, 0.5
		y = ijkTrigTanSinCos_deg(x_deg, &y_sin, &x_cos);	// 1.732, 0.866, 0.5
		y = ijkTrigCotSinCos_deg(x_deg, &y_sin, &x_cos);	// 0.577, 0.866, 0.5
		y = ijkTrigSin_deg(+x_deg);	// +0.866
		y = ijkTrigSin_deg(-x_deg);	// -0.866
		y = ijkTrigCos_deg(+x_deg);	// +0.5
		y = ijkTrigCos_deg(-x_deg);	// +0.5
		y = ijkTrigTan_deg(+x_deg);	// +1.732
		y = ijkTrigTan_deg(-x_deg);	// -1.732
		y = ijkTrigCsc_deg(+x_deg);	// +1.1547
		y = ijkTrigCsc_deg(-x_deg);	// -1.1547
		y = ijkTrigSec_deg(+x_deg);	// +2
		y = ijkTrigSec_deg(-x_deg);	// +2
		y = ijkTrigCot_deg(+x_deg);	// +0.577
		y = ijkTrigCot_deg(-x_deg);	// -0.577
		y = ijkTrigAsin_deg(+x_inv);	// +30
		y = ijkTrigAsin_deg(-x_inv);	// -30
		y = ijkTrigAcos_deg(+x_inv);	// +60
		y = ijkTrigAcos_deg(-x_inv);	// +120
		y = ijkTrigAtan_deg(+x_inv);	// +26.565
		y = ijkTrigAtan_deg(-x_inv);	// -26.565
		y = ijkTrigAcsc_deg(+x_invrcp);	// +30
		y = ijkTrigAcsc_deg(-x_invrcp);	// -30
		y = ijkTrigAsec_deg(+x_invrcp);	// +60
		y = ijkTrigAsec_deg(-x_invrcp);	// +120
		y = ijkTrigAcot_deg(+x_invrcp);	// +26.565
		y = ijkTrigAcot_deg(-x_invrcp);	// -26.565
		y = ijkTrigAtan2_deg(+x_inv, +real_one);	// +26.565
		y = ijkTrigAtan2_deg(-x_inv, +real_one);	// -26.565
		y = ijkTrigAtan2_deg(+x_inv, -real_one);	// +153.435
		y = ijkTrigAtan2_deg(-x_inv, -real_one);	// -153.435
		y = ijkTrigAtan2_deg(+x_inv, real_zero);	// +90
		y = ijkTrigAtan2_deg(-x_inv, real_zero);	// -90
		y = ijkTrigAtan2_deg(real_zero, real_zero);	// 0 (undef)

		y = ijkTrigSinCosTaylor_rad(x_rad, &y_sin, &x_cos);	// 1.047197 (pi/3), 0.866, 0.5
		y = ijkTrigTanSinCosTaylor_rad(x_rad, &y_sin, &x_cos);	// 1.732, 0.866, 0.5
		y = ijkTrigCotSinCosTaylor_rad(x_rad, &y_sin, &x_cos);	// 0.577, 0.866, 0.5
		y = ijkTrigSinTaylor_rad(+x_rad);	// +0.866
		y = ijkTrigSinTaylor_rad(-x_rad);	// -0.866
		y = ijkTrigCosTaylor_rad(+x_rad);	// +0.5
		y = ijkTrigCosTaylor_rad(-x_rad);	// +0.5
		y = ijkTrigTanTaylor_rad(+x_rad);	// +1.732
		y = ijkTrigTanTaylor_rad(-x_rad);	// -1.732
		y = ijkTrigCscTaylor_rad(+x_rad);	// +1.1547
		y = ijkTrigCscTaylor_rad(-x_rad);	// -1.1547
		y = ijkTrigSecTaylor_rad(+x_rad);	// +2
		y = ijkTrigSecTaylor_rad(-x_rad);	// +2
		y = ijkTrigCotTaylor_rad(+x_rad);	// +0.577
		y = ijkTrigCotTaylor_rad(-x_rad);	// -0.577

		y = ijkTrigSinCos_rad(x_rad, &y_sin, &x_cos);	// 1.047197 (pi/3), 0.866, 0.5
		y = ijkTrigTanSinCos_rad(x_rad, &y_sin, &x_cos);	// 1.732, 0.866, 0.5
		y = ijkTrigCotSinCos_rad(x_rad, &y_sin, &x_cos);	// 0.577, 0.866, 0.5
		y = ijkTrigSin_rad(+x_rad);	// +0.866
		y = ijkTrigSin_rad(-x_rad);	// -0.866
		y = ijkTrigCos_rad(+x_rad);	// +0.5
		y = ijkTrigCos_rad(-x_rad);	// +0.5
		y = ijkTrigTan_rad(+x_rad);	// +1.732
		y = ijkTrigTan_rad(-x_rad);	// -1.732
		y = ijkTrigCsc_rad(+x_rad);	// +1.1547
		y = ijkTrigCsc_rad(-x_rad);	// -1.1547
		y = ijkTrigSec_rad(+x_rad);	// +2
		y = ijkTrigSec_rad(-x_rad);	// +2
		y = ijkTrigCot_rad(+x_rad);	// +0.577
		y = ijkTrigCot_rad(-x_rad);	// -0.577
		y = ijkTrigAsin_rad(+x_inv);	// +0.523599 (pi/6)
		y = ijkTrigAsin_rad(-x_inv);	// -0.523599 (pi/6)
		y = ijkTrigAcos_rad(+x_inv);	// +1.047197 (pi/3)
		y = ijkTrigAcos_rad(-x_inv);	// +2.094395 (2pi/3)
		y = ijkTrigAtan_rad(+x_inv);	// +0.463647
		y = ijkTrigAtan_rad(-x_inv);	// -0.463647
		y = ijkTrigAcsc_rad(+x_invrcp);	// +0.523599 (pi/6)
		y = ijkTrigAcsc_rad(-x_invrcp);	// -0.523599 (pi/6)
		y = ijkTrigAsec_rad(+x_invrcp);	// +1.047197 (pi/3)
		y = ijkTrigAsec_rad(-x_invrcp);	// +2.094395 (2pi/3)
		y = ijkTrigAcot_rad(+x_invrcp);	// +0.463647
		y = ijkTrigAcot_rad(-x_invrcp);	// -0.463647
		y = ijkTrigAtan2_rad(+x_inv, +real_one);	// +0.463647
		y = ijkTrigAtan2_rad(-x_inv, +real_one);	// -0.463647
		y = ijkTrigAtan2_rad(+x_inv, -real_one);	// +2.677946
		y = ijkTrigAtan2_rad(-x_inv, -real_one);	// -2.677946
		y = ijkTrigAtan2_rad(+x_inv, real_zero);	// +1.570796 (pi/2)
		y = ijkTrigAtan2_rad(-x_inv, real_zero);	// -1.570796 (pi/2)
		y = ijkTrigAtan2_rad(real_zero, real_zero);	// 0 (undef)

		y = ijkTrigSinCosTaylor_deg(x_deg, &y_sin, &x_cos);	// 60, 0.866, 0.5
		y = ijkTrigTanSinCosTaylor_deg(x_deg, &y_sin, &x_cos);	// 1.732, 0.866, 0.5
		y = ijkTrigCotSinCosTaylor_deg(x_deg, &y_sin, &x_cos);	// 0.577, 0.866, 0.5
		y = ijkTrigSinTaylor_deg(+x_deg);	// +0.866
		y = ijkTrigSinTaylor_deg(-x_deg);	// -0.866
		y = ijkTrigCosTaylor_deg(+x_deg);	// +0.5
		y = ijkTrigCosTaylor_deg(-x_deg);	// +0.5
		y = ijkTrigTanTaylor_deg(+x_deg);	// +1.732
		y = ijkTrigTanTaylor_deg(-x_deg);	// -1.732
		y = ijkTrigCscTaylor_deg(+x_deg);	// +1.1547
		y = ijkTrigCscTaylor_deg(-x_deg);	// -1.1547
		y = ijkTrigSecTaylor_deg(+x_deg);	// +2
		y = ijkTrigSecTaylor_deg(-x_deg);	// +2
		y = ijkTrigCotTaylor_deg(+x_deg);	// +0.577
		y = ijkTrigCotTaylor_deg(-x_deg);	// -0.577

		y = ijkTrigPointToEdgeRatio(real_360, 24);	// 0.991445
		y = ijkTrigEdgeToPointRatio(real_360, 24);	// 1.008629
		y = ijkTrigPointToFaceRatio(real_360, real_180, 24, 18);	// 0.987672
		y = ijkTrigFaceToPointRatio(real_360, real_180, 24, 18);	// 1.012482
		y = ijkTrigSmoothstepInv((real)0.84375);	// 0.75
		y = ijkTrigExp(real_two);			// 7.389056098930650227230427460575
		y = ijkTrigLn1p((real)6.389056098930650227230427460575);		// 2
		y = ijkTrigPow(real_three, real_four);	// 81

		// done
		free(t);
	}
}


void ijkMathTestVector()
{
	// test vector functions, namely for efficiency
	float3 va0f = { flt_zero }, va1f = { flt_zero }, va2f = { flt_zero };
	double3 va0d = { dbl_zero }, va1d = { dbl_zero }, va2d = { dbl_zero };
	fvec3 v0f = fvec3_0, v1f = v0f, v2f = v1f;
	dvec3 v0d = dvec3_0, v1d = v0d, v2d = v1d;
	i32 result;

	result = scanf("%f %f %f %f %f %f", va0f + 0, va0f + 1, va0f + 2, va1f + 0, va1f + 1, va1f + 2);
	result = scanf("%lf %lf %lf %lf %lf %lf", va0d + 0, va0d + 1, va0d + 2, va1d + 0, va1d + 1, va1d + 2);
	result = scanf("%f %f %f %f %f %f", v0f.v + 0, v0f.v + 1, v0f.v + 2, v1f.v + 0, v1f.v + 1, v1f.v + 2);
	result = scanf("%lf %lf %lf %lf %lf %lf", v0d.v + 0, v0d.v + 1, v0d.v + 2, v1d.v + 0, v1d.v + 1, v1d.v + 2);

	ijkVecAdd3fv(va2f, va0f, va1f);
	ijkVecAdd3dv(va2d, va0d, va1d);
	v2f = ijkVecAdd3f(v0f, v1f);
	v2d = ijkVecAdd3d(v0d, v1d);

	result = printf("%f %f %f %f %f %f", va0f[0], va0f[1], va0f[2], va1f[0], va1f[1], va1f[2]);
	result = printf("%lf %lf %lf %lf %lf %lf", va0d[0], va0d[1], va0d[2], va1d[0], va1d[1], va1d[2]);
	result = printf("%f %f %f %f %f %f", v0f.v[0], v0f.v[1], v0f.v[2], v1f.v[0], v1f.v[1], v1f.v[2]);
	result = printf("%lf %lf %lf %lf %lf %lf", v0d.v[0], v0d.v[1], v0d.v[2], v1d.v[0], v1d.v[1], v1d.v[2]);


#ifdef IJK_CPP_ENABLED
	if (IJK_CPP_ENABLED)
	{
		void ijkMathTestVectorSwizzle();
		ijkMathTestVectorSwizzle();
	}
#endif	// IJK_CPP_ENABLED
}


//-----------------------------------------------------------------------------

void ijkMathTest()
{
	ijkMathTestReal();
	ijkMathTestSqrt();
	ijkMathTestStats();
	ijkMathTestRandom();
	ijkMathTestInterpolation();
	ijkMathTestTrigonometry();
	ijkMathTestVector();
}


//-----------------------------------------------------------------------------
