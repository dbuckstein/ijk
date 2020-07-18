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

	i32 const x0min_int = 100, x0max_int = 200, x1min_int = -100, x1max_int = -50, x_int = 160;
	flt const x0min_flt = 100.0f, x0max_flt = 200.0f, x1min_flt = -100.0f, x1max_flt = -50.0f, x_flt = 160.0f;
	dbl const x0min_dbl = 100.0, x0max_dbl = 200.0, x1min_dbl = -100.0, x1max_dbl = -50.0, x_dbl = 160.0;
	real const x0min = ijk_x2r(100), x0max = ijk_x2r(200), x1min = ijk_x2r(-100), x1max = ijk_x2r(-50), x = ijk_x2r(160);

	test_int = ijk_lerp(x0min_int, x0max_int, 6);
	test_int = ijk_unlerp(x0min_int, x0max_int, x_int);
	test_int = ijk_unlerp_safe(x0min_int, x0max_int, x_int);
	test_int = ijk_remap(x1min_int, x1max_int, x0min_int, x0max_int, x_int);
	test_int = ijk_remap_safe(x1min_int, x1max_int, x0min_int, x0max_int, x_int);
	test_int = ijk_divide(x_int, 4);
	test_int = ijk_sgn_int(+x_int);
	test_int = ijk_sgn_int(ijk_zero);
	test_int = ijk_sgn_int(-x_int);
	test_int = ijk_abs_int(+x_int);
	test_int = ijk_abs_int(ijk_zero);
	test_int = ijk_abs_int(-x_int);
	test_int = ijk_nrm2sym_int(ijk_zero);
	test_int = ijk_sym2nrm_int(ijk_zero);
	test_b = ijk_isnrm_int(-ijk_one);
	test_b = ijk_isnnrm_int(-ijk_one);
	test_b = ijk_issym_int(-ijk_one);
	test_b = ijk_isnsym_int(-ijk_one);
	test_b = ijk_iszero_int(ijk_zero);
	test_b = ijk_isnzero_int(ijk_zero);
	test_int = ijk_divide_safe_int(x_int, 4);

	test_flt = ijk_lerp(x0min_flt, x0max_flt, flt_3quarters);
	test_flt = ijk_unlerp(x0min_flt, x0max_flt, x_flt);
	test_flt = ijk_unlerp_safe(x0min_flt, x0max_flt, x_flt);
	test_flt = ijk_remap(x1min_flt, x1max_flt, x0min_flt, x0max_flt, x_flt);
	test_flt = ijk_remap_safe(x1min_flt, x1max_flt, x0min_flt, x0max_flt, x_flt);
	test_flt = ijk_divide(x_flt, flt_four);
	test_flt = ijk_sgn_flt(+x_flt);
	test_flt = ijk_sgn_flt(flt_zero);
	test_flt = ijk_sgn_flt(-x_flt);
	test_flt = ijk_abs_flt(+x_flt);
	test_flt = ijk_abs_flt(flt_zero);
	test_flt = ijk_abs_flt(-x_flt);
	test_flt = ijk_nrm2sym_flt(flt_zero);
	test_flt = ijk_sym2nrm_flt(flt_zero);
	test_b = ijk_isnrm_flt(-flt_one);
	test_b = ijk_isnnrm_flt(-flt_one);
	test_b = ijk_issym_flt(-flt_one);
	test_b = ijk_isnsym_flt(-flt_one);
	test_b = ijk_iszero_flt(flt_zero);
	test_b = ijk_isnzero_flt(flt_zero);
	test_flt = ijk_divide_safe_flt(x_flt, flt_four);
	test_flt = ijk_recip_flt(x_flt);
	test_flt = ijk_recip_safe_flt(x_flt);
	test_flt = ijk_deg2rad_flt(flt_180);
	test_flt = ijk_rad2deg_flt(flt_pi);

	test_dbl = ijk_lerp(x0min_dbl, x0max_dbl, dbl_3quarters);
	test_dbl = ijk_unlerp(x0min_dbl, x0max_dbl, x_dbl);
	test_dbl = ijk_unlerp_safe(x0min_dbl, x0max_dbl, x_dbl);
	test_dbl = ijk_remap(x1min_dbl, x1max_dbl, x0min_dbl, x0max_dbl, x_dbl);
	test_dbl = ijk_remap_safe(x1min_dbl, x1max_dbl, x0min_dbl, x0max_dbl, x_dbl);
	test_dbl = ijk_divide(x_dbl, dbl_four);
	test_dbl = ijk_sgn_dbl(+x_dbl);
	test_dbl = ijk_sgn_dbl(dbl_zero);
	test_dbl = ijk_sgn_dbl(-x_dbl);
	test_dbl = ijk_abs_dbl(+x_dbl);
	test_dbl = ijk_abs_dbl(dbl_zero);
	test_dbl = ijk_abs_dbl(-x_dbl);
	test_dbl = ijk_nrm2sym_dbl(dbl_zero);
	test_dbl = ijk_sym2nrm_dbl(dbl_zero);
	test_b = ijk_isnrm_dbl(-dbl_one);
	test_b = ijk_isnnrm_dbl(-dbl_one);
	test_b = ijk_issym_dbl(-dbl_one);
	test_b = ijk_isnsym_dbl(-dbl_one);
	test_b = ijk_iszero_dbl(dbl_zero);
	test_b = ijk_isnzero_dbl(dbl_zero);
	test_dbl = ijk_divide_safe_dbl(x_dbl, dbl_four);
	test_dbl = ijk_recip_dbl(x_dbl);
	test_dbl = ijk_recip_safe_dbl(x_dbl);
	test_dbl = ijk_deg2rad_dbl(dbl_180);
	test_dbl = ijk_rad2deg_dbl(dbl_pi);

	test = ijk_lerp(x0min, x0max, real_3quarters);
	test = ijk_unlerp(x0min, x0max, x);
	test = ijk_unlerp_safe(x0min, x0max, x);
	test = ijk_remap(x1min, x1max, x0min, x0max, x);
	test = ijk_remap_safe(x1min, x1max, x0min, x0max, x);
	test = ijk_divide(x, real_four);
	test = ijk_sgn(+x);
	test = ijk_sgn(real_zero);
	test = ijk_sgn(-x);
	test = ijk_abs(+x);
	test = ijk_abs(real_zero);
	test = ijk_abs(-x);
	test = ijk_nrm2sym(real_zero);
	test = ijk_sym2nrm(real_zero);
	test_b = ijk_isnrm(-real_one);
	test_b = ijk_isnnrm(-real_one);
	test_b = ijk_issym(-real_one);
	test_b = ijk_isnsym(-real_one);
	test_b = ijk_iszero(real_zero);
	test_b = ijk_isnzero(real_zero);
	test = ijk_divide_safe(x, real_four);
	test = ijk_recip(x);
	test = ijk_recip_safe(x);
	test = ijk_deg2rad(real_180);
	test = ijk_rad2deg(real_pi);
}


void ijkMathTestSqrt()
{
	flt test_flt = flt_zero;
	dbl test_dbl = dbl_zero;
	real test = real_zero;

	flt const x_flt = 16.0f;
	dbl const x_dbl = 16.0;
	real const x = ijk_x2r(16);

	test_flt = ijkSqrtInv0x_flt(x_flt);
	test_flt = ijkSqrt0x_flt(x_flt);
	test_flt = ijkSqrt_flt(x_flt);
	test_flt = ijkSqrtInv_flt(x_flt);
	test_flt = ijkSqrtInvSafe_flt(x_flt);

	test_dbl = ijkSqrtInv0x_dbl(x_dbl);
	test_dbl = ijkSqrt0x_dbl(x_dbl);
	test_dbl = ijkSqrt_dbl(x_dbl);
	test_dbl = ijkSqrtInv_dbl(x_dbl);
	test_dbl = ijkSqrtInvSafe_dbl(x_dbl);

	test = ijkSqrtInv0x(x);
	test = ijkSqrt0x(x);
	test = ijkSqrt(x);
	test = ijkSqrtInv(x);
	test = ijkSqrtInvSafe(x);
}


void ijkMathTestStats()
{
	size test_int = ijk_zero;
	flt test_flt = flt_zero, test2_flt[1] = { flt_zero };
	dbl test_dbl = dbl_zero, test2_dbl[1] = { dbl_zero };
	real test = real_zero, test2[1] = { real_zero };

	size const n = 8, k = 4;
	schomp const v_int[] = { 1, 2, -1, -5, 16, 9, 8, 5 };
	flt const v_flt[] = { 1.0f, 2.0f, -1.0f, -5.0f, 16.0f, 9.0f, 8.0f, 5.0f };
	dbl const v_dbl[] = { 1.0, 2.0, -1.0, -5.0, 16.0, 9.0, 8.0, 5.0 };
	real const v[] = { ijk_x2r(1), ijk_x2r(2), ijk_x2r(-1), ijk_x2r(-5), ijk_x2r(16), ijk_x2r(9), ijk_x2r(8), ijk_x2r(5) };

	test_int = ijkStatsGetFactorial(n);
	test_int = ijkStatsGetPermutations(n, k);
	test_int = ijkStatsGetCombinations(n, k);

	test_flt = ijkStatsGetMedianInt_flt(v_int, n);
	test_flt = ijkStatsGetMeanInt_flt(v_int, n);
	test_flt = ijkStatsGetVarianceInt_flt(v_int, n, test2_flt);
	test_flt = ijkStatsGetStdDevInt_flt(v_int, n, test2_flt);
	test_flt = ijkStatsGetMedian_flt(v_flt, n);
	test_flt = ijkStatsGetMean_flt(v_flt, n);
	test_flt = ijkStatsGetVariance_flt(v_flt, n, test2_flt);
	test_flt = ijkStatsGetStdDev_flt(v_flt, n, test2_flt);

	test_dbl = ijkStatsGetMedianInt_dbl(v_int, n);
	test_dbl = ijkStatsGetMeanInt_dbl(v_int, n);
	test_dbl = ijkStatsGetVarianceInt_dbl(v_int, n, test2_dbl);
	test_dbl = ijkStatsGetStdDevInt_dbl(v_int, n, test2_dbl);
	test_dbl = ijkStatsGetMedian_dbl(v_dbl, n);
	test_dbl = ijkStatsGetMean_dbl(v_dbl, n);
	test_dbl = ijkStatsGetVariance_dbl(v_dbl, n, test2_dbl);
	test_dbl = ijkStatsGetStdDev_dbl(v_dbl, n, test2_dbl);

	test = ijkStatsGetMedianInt(v_int, n);
	test = ijkStatsGetMeanInt(v_int, n);
	test = ijkStatsGetVarianceInt(v_int, n, test2);
	test = ijkStatsGetStdDevInt(v_int, n, test2);
	test = ijkStatsGetMedian(v, n);
	test = ijkStatsGetMean(v, n);
	test = ijkStatsGetVariance(v, n, test2);
	test = ijkStatsGetStdDev(v, n, test2);
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


void ijkMathTestInterpolation()
{
	i32 const seedbase = 2048;
	i32 const vmin = -16, vmax = +16;

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

	test_flt = ijkInterpNearest_flt(v_flt[0][0], v_flt[0][1], t_flt);
	test_flt = ijkInterpBinearest_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], t0_flt, t1_flt, t_flt);
	test_flt = ijkInterpLinear_flt(v_flt[0][0], v_flt[0][1], t_flt);
	test_flt = ijkInterpBilinear_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], t0_flt, t1_flt, t_flt);
	test_flt = ijkInterpLinearInv_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2]);
	test_flt = ijkInterpLinearInvSafe_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2]);
	test_flt = ijkInterpRemap_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], v_flt[1][2]);
	test_flt = ijkInterpRemapSafe_flt(v_flt[0][0], v_flt[0][1], v_flt[1][0], v_flt[1][1], v_flt[1][2]);
	test_flt = ijkInterpBezier0_flt(v_flt[0][0], t_flt);
	test_flt = ijkInterpBezier1_flt(v_flt[0][0], v_flt[0][1], t_flt);
	test_flt = ijkInterpBezier2_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2], t_flt);
	test_flt = ijkInterpBezier3_flt(v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[0][3], t_flt);
	test_flt = ijkInterpBezierN_flt(*v_flt, order, t_flt);
	test_flt = ijkInterpCubicHermite_flt(v_flt[0][0], (v_flt[1][0] - v_flt[0][0]), v_flt[0][1], (v_flt[1][1] - v_flt[0][1]), t_flt);
	test_flt = ijkInterpCubicHermiteHandles_flt(v_flt[0][0], v_flt[1][0], v_flt[0][1], v_flt[1][1], t_flt);
	test_flt = ijkInterpCubicCatmullRom_flt(v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], t_flt);
	test_flt = ijkInterpBicubicCatmullRom_flt(v_flt[3][3], v_flt[3][0], v_flt[3][1], v_flt[3][2], v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[1][3], v_flt[1][0], v_flt[1][1], v_flt[1][2], v_flt[2][3], v_flt[2][0], v_flt[2][1], v_flt[2][2], tp_flt, t0_flt, t1_flt, t2_flt, t_flt);
	test_flt = ijkInterpReparamCubicHermite_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][0], (v_flt[1][0] - v_flt[0][0]), v_flt[0][1], (v_flt[1][1] - v_flt[0][1]));
	test_flt = ijkInterpReparamCubicHermiteHandles_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][0], v_flt[1][0], v_flt[0][1], v_flt[1][1]);
	test_flt = ijkInterpReparamCubicCatmullRom_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2]);
	test_flt = ijkInterpReparamBicubicCatmullRom_flt(test_tTable_flt, test_lTable_flt, test_vTable_flt, numDivisions, ijk_true, v_flt[3][3], v_flt[3][0], v_flt[3][1], v_flt[3][2], v_flt[0][3], v_flt[0][0], v_flt[0][1], v_flt[0][2], v_flt[1][3], v_flt[1][0], v_flt[1][1], v_flt[1][2], v_flt[2][3], v_flt[2][0], v_flt[2][1], v_flt[2][2], tp_flt, t0_flt, t1_flt, t2_flt);
	test_flt = ijkInterpSampleTableInc_flt(test_tTable_flt, test_vTable_flt, 0, 0, t_flt);
	test_flt = ijkInterpSampleTableDec_flt(test_tTable_flt, test_vTable_flt, 0, 2, t_flt);
	test_index = ijkInterpSampleTableIncIndex_flt(test_vTable_flt, test_tTable_flt, 0, 0, t_flt);
	test_index = ijkInterpSampleTableDecIndex_flt(test_vTable_flt, test_tTable_flt, 0, 2, t_flt);

	test_dbl = *test_tTable_dbl = *test_lTable_dbl = *test_vTable_dbl = dbl_zero;
	test = *test_tTable = *test_lTable = *test_vTable = real_zero;
}


//-----------------------------------------------------------------------------

void ijkMathTest()
{
	ijkMathTestReal();
	ijkMathTestSqrt();
	ijkMathTestStats();
	ijkMathTestRandom();
	ijkMathTestInterpolation();
}


//-----------------------------------------------------------------------------
