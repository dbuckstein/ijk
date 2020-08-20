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
	*sinx_out = ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return x;
}


ijk_inl flt ijkTrigTanSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	*sinx_out = s = ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = c = ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (s / c);
}


ijk_inl flt ijkTrigCotSinCos_deg_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	*sinx_out = s = ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	*cosx_out = c = ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (c / s);
}


ijk_inl flt ijkTrigSin_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt;
	index const i = (index)f;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	return ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[i + 1], f);
}


ijk_inl flt ijkTrigCos_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt;
	index const i = (index)f;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	return ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[i + 1], f);
}


ijk_inl flt ijkTrigTan_deg_flt(flt const x)
{
	ijk_ext size const ijkTrigSubdivisionsPerDegree_flt;
	ijk_ext flt const ijkTrigSubdivisionsPerDegreeInv_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	flt f = (x + flt_360) * (flt)ijkTrigSubdivisionsPerDegree_flt, s, c;
	index const i = (index)f, j = i + 1;
	f = (f - (flt)i) * ijkTrigSubdivisionsPerDegreeInv_flt;
	s = ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	c = ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
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
	s = ijkInterpLinear(ijkTrigTableSin_flt[i], ijkTrigTableSin_flt[j], f);
	c = ijkInterpLinear(ijkTrigTableCos_flt[i], ijkTrigTableCos_flt[j], f);
	return (c / s);
}


ijk_inl flt ijkTrigAsin_deg_flt(flt const x)
{
	ijk_ext flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt;
	ijk_ext index const* const ijkTrigTableIndexAsin_flt;
	return +ijkInterpSampleTableInc_flt(ijkTrigTableSin_flt, ijkTrigTableParam_flt,
		*(ijkTrigTableIndexAsin_flt + (index)((x + flt_one) * (flt)512)), 1, x);
}


ijk_inl flt ijkTrigAcos_deg_flt(flt const x)
{
	ijk_ext flt const* const ijkTrigTableParam_flt, * const ijkTrigTableCos_flt;
	ijk_ext index const* const ijkTrigTableIndexAcos_flt;
	return -ijkInterpSampleTableInc_flt(ijkTrigTableCos_flt, ijkTrigTableParam_flt,
		*(ijkTrigTableIndexAcos_flt + (index)((x + flt_one) * (flt)512)), 1, x);
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
	size const iterations = 16;
	flt x2 = x, ssum = x, csum = flt_one;
	flt degree = flt_one, f = flt_one;
	uindex i;
	for (i = iterations; i > 0; --i)
	{
		// do cos accumulation
		f *= -(degree += flt_one);
		x2 *= x;
		csum += x2 / f;

		// do sin accumulation
		f *= +(degree += flt_one);
		x2 *= x;
		ssum += x2 / f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return param for reuse
	return x;
}


ijk_inl flt ijkTrigTanSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	size const iterations = 16;
	flt x2 = x, ssum = x, csum = flt_one;
	flt degree = flt_one, f = flt_one;
	uindex i;
	for (i = iterations; i > 0; --i)
	{
		// do cos accumulation
		f *= -(degree += flt_one);
		x2 *= x;
		csum += x2 / f;

		// do sin accumulation
		f *= +(degree += flt_one);
		x2 *= x;
		ssum += x2 / f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return tan(x)
	return (ssum / csum);
}


ijk_inl flt ijkTrigCotSinCosTaylor_rad_flt(flt const x, flt* const sinx_out, flt* const cosx_out)
{
	size const iterations = 16;
	flt x2 = x, ssum = x, csum = flt_one;
	flt degree = flt_one, f = flt_one;
	uindex i;
	for (i = iterations; i > 0; --i)
	{
		// do cos accumulation
		f *= -(degree += flt_one);
		x2 *= x;
		csum += x2 / f;

		// do sin accumulation
		f *= +(degree += flt_one);
		x2 *= x;
		ssum += x2 / f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return cot(x)
	return (csum / ssum);
}


ijk_inl flt ijkTrigSinTaylor_rad_flt(flt const x)
{
	size const iterations = 16;
	flt x2 = x, ssum = x2;
	flt degree = flt_one, f = flt_one;
	uindex i;
	for (i = iterations; i > 0; --i)
	{
		f *= -(degree += flt_one);
		f *= +(degree += flt_one);
		x2 *= x * x;
		ssum += x2 / f;
	}
	return ssum;
}


ijk_inl flt ijkTrigCosTaylor_rad_flt(flt const x)
{
	size const iterations = 16;
	flt x2 = flt_one, csum = x2;
	flt degree = flt_zero, f = flt_one;
	uindex i;
	for (i = iterations; i > 0; --i)
	{
		// do cos accumulation
		f *= -(degree += flt_one);
		f *= +(degree += flt_one);
		x2 *= x * x;
		csum += x2 / f;
	}
	return csum;
}


ijk_inl flt ijkTrigTanTaylor_rad_flt(flt const x)
{
	flt sinx[1], cosx[1];
	return ijkTrigCotSinCosTaylor_rad_flt(x, sinx, cosx);
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


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_TRIGONOMETRY_INL_
#endif	// _IJK_TRIGONOMETRY_H_