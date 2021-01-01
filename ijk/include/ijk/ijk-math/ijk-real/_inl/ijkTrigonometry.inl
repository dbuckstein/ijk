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

	ijkTrigonometry.inl
	Inline definitions for fast trigonometry.
*/

#ifdef _IJK_TRIGONOMETRY_H_
#ifndef _IJK_TRIGONOMETRY_INL_
#define _IJK_TRIGONOMETRY_INL_


//-----------------------------------------------------------------------------

ijk_inl flt ijkTrigDeg2Rad_flt(flt const x)
{
	return ijk_deg2rad(x);
}


ijk_inl flt ijkTrigRad2Deg_flt(flt const x)
{
	return ijk_rad2deg(x);
}


ijk_inl flt ijkTrigValidateDegree_flt(flt x)
{
	ijk_clamp_loop(-360, +360, 720, x);
	return x;
}


ijk_inl flt ijkTrigValidateRadian_flt(flt x)
{
	ijk_clamp_loop(-flt_2pi, +flt_2pi, flt_4pi, x);
	return x;
}


ijk_inl flt ijkTrigValidateInverse_flt(flt x)
{
	x = ijk_clamp(-flt_one, +flt_one, x);
	return x;
}


ijk_inl flt ijkTrigValidateInverseRecip_flt(flt x)
{
	x = ijk_clamp_inv(-flt_one, +flt_one, flt_zero, x);
	return x;
}


ijk_inl flt ijkTrigSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	*sinx_out = ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return x;
}


ijk_inl flt ijkTrigTanSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	*sinx_out = s = ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = c = ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (s / c);
}


ijk_inl flt ijkTrigCotSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	*sinx_out = s = ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = c = ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (c / s);
}


ijk_inl flt ijkTrigSin_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt;
	index const i = (index)f;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	return ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[i + 1], f);
}


ijk_inl flt ijkTrigCos_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt;
	index const i = (index)f;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	return ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[i + 1], f);
}


ijk_inl flt ijkTrigTan_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	s = ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	c = ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (s / c);
}


ijk_inl flt ijkTrigCsc_deg_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigSin_deg_flt(x));
}


ijk_inl flt ijkTrigSec_deg_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigCos_deg_flt(x));
}


ijk_inl flt ijkTrigCot_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	s = ijkInterpLinear_flt(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	c = ijkInterpLinear_flt(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (c / s);
}


ijk_inl flt ijkTrigAsin_deg_flt(flt const x)
{
	ijk_ext flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt;
	ijk_ext index const* const ijkTrigTableIndexAsin_flt;
	return ijkInterpSampleTableInc_flt(ijkTrigTableSin_flt, ijkTrigTableParam_flt,
		*(ijkTrigTableIndexAsin_flt + (index)((x + 1.0) * 512.0)), 1, x);
}


ijk_inl flt ijkTrigAcos_deg_flt(flt const x)
{
	return (flt_90 - ijkTrigAsin_deg_flt(x));
}


ijk_inl flt ijkTrigAtan_deg_flt(flt const x)
{
	// sin(atan(x)) = x / sqrt(x^2 + 1)
	// atan(x) = asin(x / sqrt(x^2 + 1))
	ijk_ext flt ijkSqrtInv_flt(flt const x);
	return ijkTrigAsin_deg_flt(x * ijkSqrtInv_flt(x * x + flt_one));
}


ijk_inl flt ijkTrigAcsc_deg_flt(flt const x)
{
	// sin(acsc(x)) = 1 / x
	// acsc(x) = asin(1 / x)
	return ijkTrigAsin_deg_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAsec_deg_flt(flt const x)
{
	// cos(asec(x)) = 1 / x
	// asec(x) = acos(1 / x)
	return ijkTrigAcos_deg_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAcot_deg_flt(flt const x)
{
	// tan(acot(x)) = 1 / x
	// acot(x) = atan(1 / x)
	return ijkTrigAtan_deg_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAtan2_deg_flt(flt const y_sin, flt const x_cos)
{
	if (x_cos > flt_zero)
		return ijkTrigAtan_deg_flt(y_sin / x_cos);
	else if (x_cos < flt_zero)
		return ijkTrigAtan_deg_flt(y_sin / x_cos) + (y_sin >= flt_zero ? +flt_180 : -flt_180);
	else if (y_sin > flt_zero)
		return +flt_90;
	else if (y_sin < flt_zero)
		return -flt_90;
	return flt_zero;
}


ijk_inl flt ijkTrigSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijkTrigSinCos_deg_flt(ijk_rad2deg_flt(x), sinx_out, cosx_out);
	return x;
}


ijk_inl flt ijkTrigTanSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	return ijkTrigTanSinCos_deg_flt(ijk_rad2deg_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigCotSinCos_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	return ijkTrigCotSinCos_deg_flt(ijk_rad2deg_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigSin_rad_flt(flt const x)
{
	return ijkTrigSin_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCos_rad_flt(flt const x)
{
	return ijkTrigCos_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigTan_rad_flt(flt const x)
{
	return ijkTrigTan_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCsc_rad_flt(flt const x)
{
	return ijkTrigCsc_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigSec_rad_flt(flt const x)
{
	return ijkTrigSec_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCot_rad_flt(flt const x)
{
	return ijkTrigCot_deg_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigAsin_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAsin_deg_flt(x));
}


ijk_inl flt ijkTrigAcos_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcos_deg_flt(x));
}


ijk_inl flt ijkTrigAtan_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAtan_deg_flt(x));
}


ijk_inl flt ijkTrigAcsc_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcsc_deg_flt(x));
}


ijk_inl flt ijkTrigAsec_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAsec_deg_flt(x));
}


ijk_inl flt ijkTrigAcot_rad_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcot_deg_flt(x));
}


ijk_inl flt ijkTrigAtan2_rad_flt(flt const y_sin, flt const x_cos)
{
	return ijk_deg2rad(ijkTrigAtan2_deg_flt(y_sin, x_cos));
}


ijk_inl flt ijkTrigSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	dbl const xd = (dbl)x;
	dbl X = xd, F = dbl_one, degree = dbl_one, ssum = xd, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= xd;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= xd;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = (flt)ssum;
	*cosx_out = (flt)csum;

	// done, return param for reuse
	return x;
}


ijk_inl flt ijkTrigTanSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	dbl const xd = (dbl)x;
	dbl X = xd, F = dbl_one, degree = dbl_one, ssum = xd, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= xd;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= xd;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = (flt)ssum;
	*cosx_out = (flt)csum;

	// done, return tan(x)
	return (flt)(ssum / csum);
}


ijk_inl flt ijkTrigCotSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	dbl const xd = (dbl)x;
	dbl X = xd, F = dbl_one, degree = dbl_one, ssum = xd, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= xd;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= xd;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = (flt)ssum;
	*cosx_out = (flt)csum;

	// done, return cot(x)
	return (flt)(csum / ssum);
}


ijk_inl flt ijkTrigSinTaylor_rad_flt(flt const x)
{
	dbl const xd = (dbl)x, x2 = xd * xd;
	dbl X = x, F = dbl_one, degree = dbl_one, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= -(degree += dbl_one);
		F *= +(degree += dbl_one);
		X *= x2;
		sum0 = sum;
		sum += X / F;
	}
	return (flt)sum;
}


ijk_inl flt ijkTrigCosTaylor_rad_flt(flt const x)
{
	dbl const xd = (dbl)x, x2 = xd * xd;
	dbl X = dbl_one, F = dbl_one, degree = dbl_zero, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= -(degree += dbl_one);
		F *= +(degree += dbl_one);
		X *= x2;
		sum0 = sum;
		sum += X / F;
	}
	return (flt)sum;
}


ijk_inl flt ijkTrigTanTaylor_rad_flt(flt const x)
{
	flt sinx[1], cosx[1];
	return ijkTrigTanSinCosTaylor_rad_flt(x, sinx, cosx);
}


ijk_inl flt ijkTrigCscTaylor_rad_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigSinTaylor_rad_flt(x));
}


ijk_inl flt ijkTrigSecTaylor_rad_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigCosTaylor_rad_flt(x));
}


ijk_inl flt ijkTrigCotTaylor_rad_flt(flt const x)
{
	flt sinx[1], cosx[1];
	return ijkTrigCotSinCosTaylor_rad_flt(x, sinx, cosx);
}


ijk_inl flt ijkTrigSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijkTrigSinCosTaylor_rad_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
	return x;
}


ijk_inl flt ijkTrigTanSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	return ijkTrigTanSinCosTaylor_rad_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigCotSinCosTaylor_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	return ijkTrigCotSinCosTaylor_rad_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigSinTaylor_deg_flt(flt const x)
{
	return ijkTrigSinTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCosTaylor_deg_flt(flt const x)
{
	return ijkTrigCosTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigTanTaylor_deg_flt(flt const x)
{
	return ijkTrigTanTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCscTaylor_deg_flt(flt const x)
{
	return ijkTrigCscTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigSecTaylor_deg_flt(flt const x)
{
	return ijkTrigSecTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCotTaylor_deg_flt(flt const x)
{
	return ijkTrigCotTaylor_rad_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigPointToEdgeRatio_flt(flt const azimuth, size const numSlices)
{
	return ijkTrigCos_deg_flt(flt_half * azimuth / (flt)numSlices);
}


ijk_inl flt ijkTrigEdgeToPointRatio_flt(flt const azimuth, size const numSlices)
{
	return ijk_recip_flt(ijkTrigPointToEdgeRatio_flt(azimuth, numSlices));
}


ijk_inl flt ijkTrigPointToFaceRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks)
{
	return (ijkTrigPointToEdgeRatio_flt(azimuth, numSlices) * ijkTrigPointToEdgeRatio_flt(elevation, numStacks));
}


ijk_inl flt ijkTrigFaceToPointRatio_flt(flt const azimuth, flt const elevation, size const numSlices, size const numStacks)
{
	return ijk_recip_flt(ijkTrigPointToFaceRatio_flt(azimuth, elevation, numSlices, numStacks));
}


ijk_inl flt ijkTrigSmoothstepInv_flt(flt const v)
{
	// t = (0.5 - sin(asin(1 - 2v) / 3))
	return (flt_half - ijkTrigSin_deg_flt(ijkTrigAsin_deg_flt(flt_one - flt_two * v) * flt_third));
}


ijk_inl flt ijkTrigExp_flt(flt const x)
{
	// need faster way to do this
	dbl const xd = (dbl)x;
	dbl X = dbl_one, F = dbl_one, degree = dbl_zero, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= +(degree += dbl_one);
		X *= xd;
		sum0 = sum;
		sum += X / F;
	}
	return (flt)sum;
}


ijk_inl flt ijkTrigLn1p_flt(flt const x)
{
	// need faster way to do this (e.g. algebraic-geometric mean)
	dbl const xd = (dbl)x;
	dbl X = x, F = dbl_one, degree = dbl_one, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		degree += dbl_one;
		F = -F;
		X *= xd;
		sum0 = sum;
		sum += X * F / degree;
	}
	return (flt)sum;
}

ijk_inl flt ijkTrigPow_flt(flt const x, flt const y)
{
	// x^y = e^(y ln(x))
	return ijkTrigExp_flt(y * ijkTrigLn1p_flt(x - flt_one));
}


//-----------------------------------------------------------------------------

ijk_inl dbl ijkTrigDeg2Rad_dbl(dbl const x)
{
	return ijk_deg2rad(x);
}


ijk_inl dbl ijkTrigRad2Deg_dbl(dbl const x)
{
	return ijk_rad2deg(x);
}


ijk_inl dbl ijkTrigValidateDegree_dbl(dbl x)
{
	ijk_clamp_loop(-360, +360, 720, x);
	return x;
}


ijk_inl dbl ijkTrigValidateRadian_dbl(dbl x)
{
	ijk_clamp_loop(-dbl_2pi, +dbl_2pi, dbl_4pi, x);
	return x;
}


ijk_inl dbl ijkTrigValidateInverse_dbl(dbl x)
{
	x = ijk_clamp(-dbl_one, +dbl_one, x);
	return x;
}


ijk_inl dbl ijkTrigValidateInverseRecip_dbl(dbl x)
{
	x = ijk_clamp_inv(-dbl_one, +dbl_one, dbl_zero, x);
	return x;
}


ijk_inl dbl ijkTrigSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl;
	index const i = (index)f, j = i + 1;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	*sinx_out = ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[j], f);
	*cosx_out = ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[j], f);
	return x;
}


ijk_inl dbl ijkTrigTanSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	*sinx_out = s = ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[j], f);
	*cosx_out = c = ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[j], f);
	return (s / c);
}


ijk_inl dbl ijkTrigCotSinCos_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	*sinx_out = s = ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[j], f);
	*cosx_out = c = ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[j], f);
	return (c / s);
}


ijk_inl dbl ijkTrigSin_deg_dbl(dbl const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl;
	index const i = (index)f;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	return ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[i + 1], f);
}


ijk_inl dbl ijkTrigCos_deg_dbl(dbl const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl;
	index const i = (index)f;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	return ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[i + 1], f);
}


ijk_inl dbl ijkTrigTan_deg_dbl(dbl const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	s = ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[j], f);
	c = ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[j], f);
	return (s / c);
}


ijk_inl dbl ijkTrigCsc_deg_dbl(dbl const x)
{
	return ijk_recip_dbl(ijkTrigSin_deg_dbl(x));
}


ijk_inl dbl ijkTrigSec_deg_dbl(dbl const x)
{
	return ijk_recip_dbl(ijkTrigCos_deg_dbl(x));
}


ijk_inl dbl ijkTrigCot_deg_dbl(dbl const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_dbl;
	ijk_ext dbl const ijkTrigSubdivisionsPerDegreeInv_dbl, * const ijkTrigTableSin_dbl, * const ijkTrigTableCos_dbl;
	dbl f = (x + dbl_360) * (dbl)ijkTrigSubdivisionsPerDegree_dbl, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (dbl)i) * ijkTrigSubdivisionsPerDegreeInv_dbl;
	s = ijkInterpLinear_dbl(ijkTrigTableSin_dbl[i], ijkTrigTableSin_dbl[j], f);
	c = ijkInterpLinear_dbl(ijkTrigTableCos_dbl[i], ijkTrigTableCos_dbl[j], f);
	return (c / s);
}


ijk_inl dbl ijkTrigAsin_deg_dbl(dbl const x)
{
	ijk_ext dbl const* const ijkTrigTableParam_dbl, * const ijkTrigTableSin_dbl;
	ijk_ext index const* const ijkTrigTableIndexAsin_dbl;
	return ijkInterpSampleTableInc_dbl(ijkTrigTableSin_dbl, ijkTrigTableParam_dbl,
		*(ijkTrigTableIndexAsin_dbl + (index)((x + 1.0) * 1024.0)), 1, x);
}


ijk_inl dbl ijkTrigAcos_deg_dbl(dbl const x)
{
	return (dbl_90 - ijkTrigAsin_deg_dbl(x));
}


ijk_inl dbl ijkTrigAtan_deg_dbl(dbl const x)
{
	// sin(atan(x)) = x / sqrt(x^2 + 1)
	// atan(x) = asin(x / sqrt(x^2 + 1))
	ijk_ext dbl ijkSqrtInv_dbl(dbl const x);
	return ijkTrigAsin_deg_dbl(x * ijkSqrtInv_dbl(x * x + dbl_one));
}


ijk_inl dbl ijkTrigAcsc_deg_dbl(dbl const x)
{
	// sin(acsc(x)) = 1 / x
	// acsc(x) = asin(1 / x)
	return ijkTrigAsin_deg_dbl(ijk_recip_dbl(x));
}


ijk_inl dbl ijkTrigAsec_deg_dbl(dbl const x)
{
	// cos(asec(x)) = 1 / x
	// asec(x) = acos(1 / x)
	return ijkTrigAcos_deg_dbl(ijk_recip_dbl(x));
}


ijk_inl dbl ijkTrigAcot_deg_dbl(dbl const x)
{
	// tan(acot(x)) = 1 / x
	// acot(x) = atan(1 / x)
	return ijkTrigAtan_deg_dbl(ijk_recip_dbl(x));
}


ijk_inl dbl ijkTrigAtan2_deg_dbl(dbl const y_sin, dbl const x_cos)
{
	if (x_cos > dbl_zero)
		return ijkTrigAtan_deg_dbl(y_sin / x_cos);
	else if (x_cos < dbl_zero)
		return ijkTrigAtan_deg_dbl(y_sin / x_cos) + (y_sin >= dbl_zero ? +dbl_180 : -dbl_180);
	else if (y_sin > dbl_zero)
		return +dbl_90;
	else if (y_sin < dbl_zero)
		return -dbl_90;
	return dbl_zero;
}


ijk_inl dbl ijkTrigSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	ijkTrigSinCos_deg_dbl(ijk_rad2deg_dbl(x), sinx_out, cosx_out);
	return x;
}


ijk_inl dbl ijkTrigTanSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	return ijkTrigTanSinCos_deg_dbl(ijk_rad2deg_dbl(x), sinx_out, cosx_out);
}


ijk_inl dbl ijkTrigCotSinCos_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	return ijkTrigCotSinCos_deg_dbl(ijk_rad2deg_dbl(x), sinx_out, cosx_out);
}


ijk_inl dbl ijkTrigSin_rad_dbl(dbl const x)
{
	return ijkTrigSin_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigCos_rad_dbl(dbl const x)
{
	return ijkTrigCos_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigTan_rad_dbl(dbl const x)
{
	return ijkTrigTan_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigCsc_rad_dbl(dbl const x)
{
	return ijkTrigCsc_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigSec_rad_dbl(dbl const x)
{
	return ijkTrigSec_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigCot_rad_dbl(dbl const x)
{
	return ijkTrigCot_deg_dbl(ijk_rad2deg_dbl(x));
}


ijk_inl dbl ijkTrigAsin_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAsin_deg_dbl(x));
}


ijk_inl dbl ijkTrigAcos_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAcos_deg_dbl(x));
}


ijk_inl dbl ijkTrigAtan_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAtan_deg_dbl(x));
}


ijk_inl dbl ijkTrigAcsc_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAcsc_deg_dbl(x));
}


ijk_inl dbl ijkTrigAsec_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAsec_deg_dbl(x));
}


ijk_inl dbl ijkTrigAcot_rad_dbl(dbl const x)
{
	return ijk_deg2rad(ijkTrigAcot_deg_dbl(x));
}


ijk_inl dbl ijkTrigAtan2_rad_dbl(dbl const y_sin, dbl const x_cos)
{
	return ijk_deg2rad(ijkTrigAtan2_deg_dbl(y_sin, x_cos));
}


ijk_inl dbl ijkTrigSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	dbl X = x, F = dbl_one, degree = dbl_one, ssum = x, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= x;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= x;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return param for reuse
	return x;
}


ijk_inl dbl ijkTrigTanSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	dbl X = x, F = dbl_one, degree = dbl_one, ssum = x, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= x;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= x;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return tan(x)
	return (ssum / csum);
}


ijk_inl dbl ijkTrigCotSinCosTaylor_rad_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	dbl X = x, F = dbl_one, degree = dbl_one, ssum = x, csum = dbl_one, ssum0 = dbl_zero, csum0 = dbl_zero;
	while (ssum != ssum0 && csum != csum0)
	{
		// do cos accumulation
		F *= -(degree += dbl_one);
		X *= x;
		csum0 = csum;
		csum += X / F;

		// do sin accumulation
		F *= +(degree += dbl_one);
		X *= x;
		ssum0 = ssum;
		ssum += X / F;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return cot(x)
	return (csum / ssum);
}


ijk_inl dbl ijkTrigSinTaylor_rad_dbl(dbl const x)
{
	dbl const x2 = x * x;
	dbl X = x, F = dbl_one, degree = dbl_one, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= -(degree += dbl_one);
		F *= +(degree += dbl_one);
		X *= x2;
		sum0 = sum;
		sum += X / F;
	}
	return sum;
}


ijk_inl dbl ijkTrigCosTaylor_rad_dbl(dbl const x)
{
	dbl const x2 = x * x;
	dbl X = dbl_one, F = dbl_one, degree = dbl_zero, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= -(degree += dbl_one);
		F *= +(degree += dbl_one);
		X *= x2;
		sum0 = sum;
		sum += X / F;
	}
	return sum;
}


ijk_inl dbl ijkTrigTanTaylor_rad_dbl(dbl const x)
{
	dbl sinx[1], cosx[1];
	return ijkTrigTanSinCosTaylor_rad_dbl(x, sinx, cosx);
}


ijk_inl dbl ijkTrigCscTaylor_rad_dbl(dbl const x)
{
	return ijk_recip_dbl(ijkTrigSinTaylor_rad_dbl(x));
}


ijk_inl dbl ijkTrigSecTaylor_rad_dbl(dbl const x)
{
	return ijk_recip_dbl(ijkTrigCosTaylor_rad_dbl(x));
}


ijk_inl dbl ijkTrigCotTaylor_rad_dbl(dbl const x)
{
	dbl sinx[1], cosx[1];
	return ijkTrigCotSinCosTaylor_rad_dbl(x, sinx, cosx);
}


ijk_inl dbl ijkTrigSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	ijkTrigSinCosTaylor_rad_dbl(ijk_deg2rad_dbl(x), sinx_out, cosx_out);
	return x;
}


ijk_inl dbl ijkTrigTanSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	return ijkTrigTanSinCosTaylor_rad_dbl(ijk_deg2rad_dbl(x), sinx_out, cosx_out);
}


ijk_inl dbl ijkTrigCotSinCosTaylor_deg_dbl(dbl const x, dbl* const sinx_out, dbl* const cosx_out)
{
	return ijkTrigCotSinCosTaylor_rad_dbl(ijk_deg2rad_dbl(x), sinx_out, cosx_out);
}


ijk_inl dbl ijkTrigSinTaylor_deg_dbl(dbl const x)
{
	return ijkTrigSinTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigCosTaylor_deg_dbl(dbl const x)
{
	return ijkTrigCosTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigTanTaylor_deg_dbl(dbl const x)
{
	return ijkTrigTanTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigCscTaylor_deg_dbl(dbl const x)
{
	return ijkTrigCscTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigSecTaylor_deg_dbl(dbl const x)
{
	return ijkTrigSecTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigCotTaylor_deg_dbl(dbl const x)
{
	return ijkTrigCotTaylor_rad_dbl(ijk_deg2rad_dbl(x));
}


ijk_inl dbl ijkTrigPointToEdgeRatio_dbl(dbl const azimuth, size const numSlices)
{
	return ijkTrigCos_deg_dbl(dbl_half * azimuth / (dbl)numSlices);
}


ijk_inl dbl ijkTrigEdgeToPointRatio_dbl(dbl const azimuth, size const numSlices)
{
	return ijk_recip_dbl(ijkTrigPointToEdgeRatio_dbl(azimuth, numSlices));
}


ijk_inl dbl ijkTrigPointToFaceRatio_dbl(dbl const azimuth, dbl const elevation, size const numSlices, size const numStacks)
{
	return (ijkTrigPointToEdgeRatio_dbl(azimuth, numSlices) * ijkTrigPointToEdgeRatio_dbl(elevation, numStacks));
}


ijk_inl dbl ijkTrigFaceToPointRatio_dbl(dbl const azimuth, dbl const elevation, size const numSlices, size const numStacks)
{
	return ijk_recip_dbl(ijkTrigPointToFaceRatio_dbl(azimuth, elevation, numSlices, numStacks));
}


ijk_inl dbl ijkTrigSmoothstepInv_dbl(dbl const v)
{
	// t = (0.5 - sin(asin(1 - 2v) / 3))
	return (dbl_half - ijkTrigSin_deg_dbl(ijkTrigAsin_deg_dbl(dbl_one - dbl_two * v) * dbl_third));
}


ijk_inl dbl ijkTrigExp_dbl(dbl const x)
{
	// need faster way to do this
	dbl X = dbl_one, F = dbl_one, degree = dbl_zero, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		F *= +(degree += dbl_one);
		X *= x;
		sum0 = sum;
		sum += X / F;
	}
	return sum;
}


ijk_inl dbl ijkTrigLn1p_dbl(dbl const x)
{
	// need faster way to do this (e.g. algebraic-geometric mean)
	dbl X = x, F = dbl_one, degree = dbl_one, sum = X, sum0 = dbl_zero;
	while (sum != sum0)
	{
		degree += dbl_one;
		F = -F;
		X *= x;
		sum0 = sum;
		sum += X * F / degree;
	}
	return sum;
}

ijk_inl dbl ijkTrigPow_dbl(dbl const x, dbl const y)
{
	// x^y = e^(y ln(x))
	return ijkTrigExp_dbl(y * ijkTrigLn1p_dbl(x - dbl_one));
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_TRIGONOMETRY_INL_
#endif	// _IJK_TRIGONOMETRY_H_