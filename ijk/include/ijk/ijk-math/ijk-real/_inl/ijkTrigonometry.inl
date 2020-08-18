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


ijk_inl flt ijkTrigSind_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	return ijkInterpSampleTableInc_flt(ijkTrigTableParam_flt, ijkTrigTableSin_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x);
}


ijk_inl flt ijkTrigCosd_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableCos_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	return ijkInterpSampleTableInc_flt(ijkTrigTableParam_flt, ijkTrigTableCos_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x);
}


ijk_inl flt ijkTrigTand_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	flt t;
	index i = ijkInterpSampleTableIncIndex_flt(&t, ijkTrigTableParam_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x);
	flt const s1 = *(ijkTrigTableSin_flt + i);
	flt const c1 = *(ijkTrigTableCos_flt + i);
	flt const s0 = *(ijkTrigTableSin_flt + (--i));
	flt const c0 = *(ijkTrigTableCos_flt + i);
	return (ijkInterpLinear(s0, s1, t) / ijkInterpLinear(c0, c1, t));
}


ijk_inl flt ijkTrigCscd_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	return ijk_recip_flt(ijkInterpSampleTableInc_flt(ijkTrigTableParam_flt, ijkTrigTableSin_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x));
}


ijk_inl flt ijkTrigSecd_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableCos_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	return ijk_recip_flt(ijkInterpSampleTableInc_flt(ijkTrigTableParam_flt, ijkTrigTableCos_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x));
}


ijk_inl flt ijkTrigCotd_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt, * const ijkTrigTableCos_flt;
	extern size const ijkTrigSubdivisionsPerDegree_flt;
	flt t;
	index i = ijkInterpSampleTableIncIndex_flt(&t, ijkTrigTableParam_flt,
		((index)x + 360) * ijkTrigSubdivisionsPerDegree_flt, 1, x);
	flt const s1 = *(ijkTrigTableSin_flt + i);
	flt const c1 = *(ijkTrigTableCos_flt + i);
	flt const s0 = *(ijkTrigTableSin_flt + (--i));
	flt const c0 = *(ijkTrigTableCos_flt + i);
	return (ijkInterpLinear(c0, c1, t) / ijkInterpLinear(s0, s1, t));
}


ijk_inl flt ijkTrigAsind_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableSin_flt;
	extern index const* const ijkTrigTableIndexAsin_flt;
	return +ijkInterpSampleTableInc_flt(ijkTrigTableSin_flt, ijkTrigTableParam_flt,
		*(ijkTrigTableIndexAsin_flt + 360 + (index)(x * 360)) , 1, x);
}


ijk_inl flt ijkTrigAcosd_flt(flt const x)
{
	extern flt const* const ijkTrigTableParam_flt, * const ijkTrigTableCos_flt;
	extern index const* const ijkTrigTableIndexAcos_flt;
	return -ijkInterpSampleTableInc_flt(ijkTrigTableCos_flt, ijkTrigTableParam_flt,
		*(ijkTrigTableIndexAcos_flt + 360 + (index)(x * 360)), 1, x);
}


ijk_inl flt ijkTrigAtand_flt(flt const x)
{
	// sin(atan(x)) = x / sqrt(x^2 + 1)
	// atan(x) = asin(x / sqrt(x^2 + 1))
	extern flt ijkSqrtInv_flt(flt const x);
	return ijkTrigAsind_flt(x * ijkSqrtInv_flt(x * x + flt_one));
}


ijk_inl flt ijkTrigAcscd_flt(flt const x)
{
	// sin(acsc(x)) = 1 / x
	// acsc(x) = asin(1 / x)
	return ijkTrigAsind_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAsecd_flt(flt const x)
{
	// cos(asec(x)) = 1 / x
	// asec(x) = acos(1 / x)
	return ijkTrigAcosd_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAcotd_flt(flt const x)
{
	// tan(acot(x)) = 1 / x
	// acot(x) = atan(1 / x)
	return ijkTrigAtand_flt(ijk_recip_flt(x));
}


ijk_inl flt ijkTrigAtan2d_flt(flt const y_sin, flt const x_cos)
{
	if (x_cos > flt_zero)
		return ijkTrigAtand_flt(y_sin / x_cos);
	else if (x_cos < flt_zero)
		return ijkTrigAtand_flt(y_sin / x_cos) + (y_sin >= flt_zero ? +flt_180 : -flt_180);
	else if (y_sin > flt_zero)
		return +flt_90;
	else if (y_sin < flt_zero)
		return -flt_90;
	return flt_zero;
}


ijk_inl flt ijkTrigSinr_flt(flt const x)
{
	return ijkTrigSind_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCosr_flt(flt const x)
{
	return ijkTrigCosd_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigTanr_flt(flt const x)
{
	return ijkTrigTand_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCscr_flt(flt const x)
{
	return ijkTrigCscd_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigSecr_flt(flt const x)
{
	return ijkTrigSecd_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigCotr_flt(flt const x)
{
	return ijkTrigCotd_flt(ijk_rad2deg_flt(x));
}


ijk_inl flt ijkTrigAsinr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAsind_flt(x));
}


ijk_inl flt ijkTrigAcosr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcosd_flt(x));
}


ijk_inl flt ijkTrigAtanr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAtand_flt(x));
}


ijk_inl flt ijkTrigAcscr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcscd_flt(x));
}


ijk_inl flt ijkTrigAsecr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAsecd_flt(x));
}


ijk_inl flt ijkTrigAcotr_flt(flt const x)
{
	return ijk_deg2rad(ijkTrigAcotd_flt(x));
}


ijk_inl flt ijkTrigAtan2r_flt(flt const y_sin, flt const x_cos)
{
	return ijk_deg2rad(ijkTrigAtan2d_flt(y_sin, x_cos));
}


ijk_inl flt ijkTrigSinrCosrTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	size const iterations = 32;
	flt x2 = x, ssum = x, csum = flt_one;
	index degree = 1, f = 1;
	uindex i;
	for (i = 1; i <= iterations; ++i)
	{
		// do cos accumulation
		f *= -(++degree);
		x2 *= x;
		csum += x2 / (flt)f;

		// do sin accumulation
		f *= +(++degree);
		x2 *= x;
		ssum += x2 / (flt)f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return param for reuse
	return x;
}


ijk_inl flt ijkTrigTanrSinrCosrTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	size const iterations = 32;
	flt x2 = x, ssum = x, csum = flt_one;
	index degree = 1, f = 1;
	uindex i;
	for (i = 1; i <= iterations; ++i)
	{
		// do cos accumulation
		f *= -(++degree);
		x2 *= x;
		csum += x2 / (flt)f;

		// do sin accumulation
		f *= +(++degree);
		x2 *= x;
		ssum += x2 / (flt)f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return tan(x)
	return (ssum / csum);
}


ijk_inl flt ijkTrigCotrSinrCosrTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	size const iterations = 32;
	flt x2 = x, ssum = x, csum = flt_one;
	index degree = 1, f = 1;
	uindex i;
	for (i = 1; i <= iterations; ++i)
	{
		// do cos accumulation
		f *= -(++degree);
		x2 *= x;
		csum += x2 / (flt)f;

		// do sin accumulation
		f *= +(++degree);
		x2 *= x;
		ssum += x2 / (flt)f;
	}

	// copy results to outputs
	*sinx_out = ssum;
	*cosx_out = csum;

	// done, return cot(x)
	return (csum / ssum);
}


ijk_inl flt ijkTrigSinrTaylor_flt(flt const x)
{
	size const iterations = 32;
	flt x2 = x, ssum = x2;
	index degree = 1, f = 1;
	uindex i;
	for (i = 1; i <= iterations; ++i)
	{
		f *= -(++degree) * (++degree);
		x2 *= x * x;
		ssum += x2 / (flt)f;
	}
	return ssum;
}


ijk_inl flt ijkTrigCosrTaylor_flt(flt const x)
{
	size const iterations = 32;
	flt x2 = flt_one, csum = x2;
	index degree = 0, f = 1;
	uindex i;
	for (i = 1; i <= iterations; ++i)
	{
		// do cos accumulation
		f *= -(++degree) * (++degree);
		x2 *= x * x;
		csum += x2 / (flt)f;
	}
	return csum;
}


ijk_inl flt ijkTrigTanrTaylor_flt(flt const x)
{
	flt sinx[1], cosx[1];
	return ijkTrigCotrSinrCosrTaylor_flt(x, sinx, cosx);
}


ijk_inl flt ijkTrigCscrTaylor_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigSinrTaylor_flt(x));
}


ijk_inl flt ijkTrigSecrTaylor_flt(flt const x)
{
	return ijk_recip_flt(ijkTrigCosrTaylor_flt(x));
}


ijk_inl flt ijkTrigCotrTaylor_flt(flt const x)
{
	flt sinx[1], cosx[1];
	return ijkTrigCotrSinrCosrTaylor_flt(x, sinx, cosx);
}


ijk_inl flt ijkTrigSindCosdTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	ijkTrigSinrCosrTaylor_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
	return x;
}


ijk_inl flt ijkTrigTandSindCosdTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	return ijkTrigTanrSinrCosrTaylor_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigCotdSindCosdTaylor_flt(flt const x, flt* sinx_out, flt* cosx_out)
{
	return ijkTrigCotrSinrCosrTaylor_flt(ijk_deg2rad_flt(x), sinx_out, cosx_out);
}


ijk_inl flt ijkTrigSindTaylor_flt(flt const x)
{
	return ijkTrigSinrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCosdTaylor_flt(flt const x)
{
	return ijkTrigCosrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigTandTaylor_flt(flt const x)
{
	return ijkTrigTanrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCscdTaylor_flt(flt const x)
{
	return ijkTrigCscrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigSecdTaylor_flt(flt const x)
{
	return ijkTrigSecrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigCotdTaylor_flt(flt const x)
{
	return ijkTrigCotrTaylor_flt(ijk_deg2rad_flt(x));
}


ijk_inl flt ijkTrigPointToEdgeRatio_flt(flt const azimuth, size const numSlices)
{
	return ijkTrigCosd_flt(flt_half * azimuth / (flt)numSlices);
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