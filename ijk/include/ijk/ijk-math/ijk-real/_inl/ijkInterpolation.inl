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

	ijkInterpolation.inl
	Inline definitions for interpolation.
*/

#ifdef _IJK_INTERPOLATION_H_
#ifndef _IJK_INTERPOLATION_INL_
#define _IJK_INTERPOLATION_INL_


//-----------------------------------------------------------------------------

ijk_inl flt ijkInterpNearest_flt(flt const v0, flt const v1, flt const t)
{
	// v = v0 if t < 0.5, v1 otherwise
	return (t < flt_half ? v0 : v1);
}


ijk_inl flt ijkInterpBinearest_flt(flt const v00, flt const v01, flt const v10, flt const v11, flt const t0, flt const t1, flt const t)
{
	// v = near(v00, v01, t0) if t < 0.5, near(v10, v11, t1) otherwise
	return (t < flt_half ? t0 < flt_half ? v00 : v01 : t1 < flt_half ? v10 : v11);
}


ijk_inl flt ijkInterpLinear_flt(flt const v0, flt const v1, flt const t)
{
	// v = lerp(v0, v1, t) = v0 + (v1 - v0) * t
	return (v0 + (v1 - v0) * t);
}


ijk_inl flt ijkInterpBilinear_flt(flt const v00, flt const v01, flt const v10, flt const v11, flt const t0, flt const t1, flt const t)
{
	// v0 = lerp(v00, v01, t0) = v00 + (v01 - v00) * t0
	// v1 = lerp(v10, v11, t1) = v10 + (v11 - v10) * t1
	// v = lerp(v0, v1, t) = v0 + (v1 - v0) * t
	flt const v0 = ijkInterpLinear_flt(v00, v01, t0);
	flt const v1 = ijkInterpLinear_flt(v10, v11, t1);
	return ijkInterpLinear_flt(v0, v1, t);
}


ijk_inl flt ijkInterpLinearInv_flt(flt const v0, flt const v1, flt const v)
{
	// v = v0 + (v1 - v0) * t
	// v - v0 = (v1 - v0) * t
	// t = (v - v0) / (v1 - v0)
	return ((v - v0) / (v1 - v0));
}


ijk_inl flt ijkInterpLinearInvSafe_flt(flt const v0, flt const v1, flt const v)
{
	return (v0 != v1 ? ijkInterpLinearInv_flt(v0, v1, v) : flt_zero);
}


ijk_inl flt ijkInterpRemap_flt(flt const v0_dst, flt const v1_dst, flt const v0_src, flt const v1_src, flt const v_src)
{
	// v_dst = lerp(v0_dst, v1_dst, t_dst)
	// t_dst = lerpInv(v0_src, v1_src, v_src)
	//		= (v_src - v0_src) / (v1_src - v0_src)
	// v_dst = v0_dst + (v1_dst - v0_dst) * (v_src - v0_src) / (v1_src - v0_src)
	return (v0_dst + (v1_dst - v0_dst) * (v_src - v0_src) / (v1_src - v0_src));
}


ijk_inl flt ijkInterpRemapSafe_flt(flt const v0_dst, flt const v1_dst, flt const v0_src, flt const v1_src, flt const v_src)
{
	return (v0_src != v1_src ? ijkInterpRemap_flt(v0_dst, v1_dst, v0_src, v1_src, v_src) : v0_dst);
}


ijk_inl flt ijkInterpBezier0_flt(flt const v0, flt const t)
{
	// base case: always return v0 regardless of parameter
	return (v0);
}


ijk_inl flt ijkInterpBezier1_flt(flt const v0, flt const v1, flt const t)
{
	// recursive case: interpolate results of lower degree
	return ijkInterpLinear_flt(v0, v1, t);
}


ijk_inl flt ijkInterpBezier2_flt(flt const v0, flt const v1, flt const v2, flt const t)
{
	// u0 = lerp(v0, v1, t) = v0 + (v1 - v0) * t
	// u1 = lerp(v1, v2, t) = v1 + (v2 - v1) * t
	// v = lerp(u0, u1, t)
	flt const u0 = ijkInterpLinear_flt(v0, v1, t);
	flt const u1 = ijkInterpLinear_flt(v1, v2, t);
	return ijkInterpLinear_flt(u0, u1, t);
}


ijk_inl flt ijkInterpBezier3_flt(flt const v0, flt const v1, flt const v2, flt const v3, flt const t)
{
	flt const u0 = ijkInterpBezier2_flt(v0, v1, v2, t);
	flt const u1 = ijkInterpBezier2_flt(v1, v2, v3, t);
	return ijkInterpLinear_flt(u0, u1, t);
}


ijk_inl flt ijkInterpBezierN_flt(flt const v[], size const order, flt const t)
{
	if (order > 0)
		return ijkInterpLinear_flt(ijkInterpBezierN_flt(v + 0, order - 1, t), ijkInterpBezierN_flt(v + 1, order - 1, t), t);
	return *v;
}


ijk_inl flt ijkInterpCubicHermite_flt(flt const v0, flt const dv0, flt const v1, flt const dv1, flt const t)
{
	// v = [v0, dv0, v1, dv1] K (1, t, t2, t3)
	// K =	|  1  0 -3  2 |
	//		|  0  1 -2  1 |
	//		|  0  0  3 -2 |
	//		|  0  0 -1  1 |
	// v = [v0, dv0, v1, dv1] ( 1 - 3t2 + 2t3 , t - 2t2 + t3 , 3t2 - 2t3 , t3 - t2 )
	//	= v0*(1 - 3t2 + 2t3) + dv0*(t - 2t2 + t3) + v1*(3t2 - 2t3) + dv1*(t3 - t2)
	//	= v0 + t * (dv0 + v0*(2t2 - 3t) + dv0*(t2 - 2t) + v1*(3t - 2t2) + dv1*(t2 - t))
	//	= v0 + t * (dv0 + t * (v0*(2t - 3) + dv0*(t - 2) + v1*(3 - 2t) + dv1*(t - 1)))
	//	= v0 + t * (dv0 + t * (2t*v0 - 3v0 + t*dv0 - 2dv0 + 3v1 - 2t*v1 + t*dv1 - dv1))
	// v = v0 + t * (dv0 + t * (3(v1 - v0) - dv1 - 2dv0 + t * (2(v0 - v1) + dv0 + dv1)))
	return (v0 + (dv0 + ((v1 - v0) * flt_three - dv1 - dv0 * flt_two + ((v0 - v1) * flt_two + dv0 + dv1) * t) * t) * t);
}


ijk_inl flt ijkInterpCubicHermiteHandles_flt(flt const v0, flt const cv0, flt const v1, flt const cv1, flt const t)
{
	// v = [v0, dv0, v1, dv1] K (1, t, t2, t3)
	//	= [v0, cv0 - v0, v1, cv1 - v1] K (1, t, t2, t3)
	// K =	|  1  0 -3  2 |
	//		|  0  1 -2  1 |
	//		|  0  0  3 -2 |
	//		|  0  0 -1  1 |
	// v = [v0, cv0 - v0, v1, cv1 - v1] ( 1 - 3t2 + 2t3 , t - 2t2 + t3 , 3t2 - 2t3 , t3 - t2 )
	//	= v0 + t * (cv0 - v0 + t * (3(v1 - v0) - (cv1 - v1) - 2(cv0 - v0) + t * (2(v0 - v1) + cv0 - v0 + cv1 - v1)))
	//	= v0 + t * (cv0 - v0 + t * (3v1 - 3v0 - cv1 + v1 - 2cv0 + 2v0 + t * (2v0 - 2v1 + cv0 - v0 + cv1 - v1)))
	//	= v0 + t * (cv0 - v0 + t * (4v1 - v0 - cv1 - 2cv0 + t * (v0 - 3v1 + cv0 + cv1)))
	// v = [v0, cv0, v1, cv1] K' (1, t, t2, t3)
	// K' =	|  1 -1 -1  1 |
	//		|  0  1 -2  1 |
	//		|  0  0  4 -3 |
	//		|  0  0 -1  1 |
	// v = v0 + t * (cv0 - v0 + t * (4v1 - cv1 - v0 - 2cv0 + t * (v0 + cv0 - 3v1 + cv1)))
	return (v0 + (cv0 - v0 + (v1 * flt_four - cv1 - v0 - cv0 * flt_two + (v0 + cv0 - v1 * flt_three + cv1) * t) * t) * t);
}


ijk_inl flt ijkInterpCubicCatmullRom_flt(flt const vp, flt const v0, flt const v1, flt const v2, flt const t)
{
	// v = [v0, dv0, v1, dv1] K (1, t, t2, t3)
	//	= [v0, (v1 - vp)/2, v1, (v2 - v0)/2] K (1, t, t2, t3)
	//	K = |  1  0 -3  2 |
	//		|  0  1 -2  1 |
	//		|  0  0  3 -2 |
	//		|  0  0 -1  1 |
	// v = [v0, (v1 - vp)/2, v1, (v2 - v0)/2] ( 1 - 3t2 + 2t3 , t - 2t2 + t3 , 3t2 - 2t3 , t3 - t2 )
	//	= v0 + t * ((v1 - vp)/2 + t * (3(v1 - v0) - (v2 - v0)/2 - 2(v1 - vp)/2 + t * (2(v0 - v1) + (v1 - vp)/2 + (v2 - v0)/2)))
	//	= v0 + t * ((v1 - vp)/2 + t * ((6(v1 - v0) - (v2 - v0) - 2(v1 - vp))/2 + t/2 * (4(v0 - v1) + v1 - vp + v2 - v0)))
	//	= v0 + t * ((v1 - vp)/2 + t/2 * (6v1 - 6v0 - v2 + v0 - 2v1 + 2vp + t * (4v0 - 4v1 + v1 - vp + v2 - v0)))
	//	= 2v0/2 + t/2 * (v1 - vp + t * (4v1 - 5v0 - v2 + 2vp + t * (3v0 - 3v1 - vp + v2)))
	// v = [vp, v0, v1, v2] K' (1, t, t2, t3)
	//		|  0 -1  2 -1 |
	// K' =	|  2  0 -5  3 |
	//		|  0  1  4 -3 |
	//		|  0  0 -1  1 | / 2
	// v = v0 + t/2 * (v1 - vp + t * (2vp - 5v0 + 4v1 - v2 + t * (3(v0 - v1) + v2 - vp)))
	return (v0 + (v1 - vp + (vp * flt_two - v0 * flt_five + v1 * flt_four - v2 + ((v0 - v1) * flt_three + v2 - vp) * t) * t) * t * flt_half);
}


ijk_inl flt ijkInterpBicubicCatmullRom_flt(flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2, flt const t)
{
	// vp = CatmullRom(vpp, vp0, vp1, vp2, tp)
	// v0 = CatmullRom(v0p, v00, v01, v02, t0)
	// v1 = CatmullRom(v1p, v10, v11, v12, t1)
	// v2 = CatmullRom(v2p, v20, v21, v22, t2)
	// v = CatmullRom(vp, v0, v1, v2, t)
	flt const vp = ijkInterpCubicCatmullRom_flt(vpp, vp0, vp1, vp2, tp);
	flt const v0 = ijkInterpCubicCatmullRom_flt(v0p, v00, v01, v02, t0);
	flt const v1 = ijkInterpCubicCatmullRom_flt(v1p, v10, v11, v12, t1);
	flt const v2 = ijkInterpCubicCatmullRom_flt(v2p, v20, v21, v22, t2);
	return ijkInterpCubicCatmullRom_flt(vp, v0, v1, v2, t);
}


ijk_inl flt ijkInterpReparamCubicHermite_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const dv0, flt const v1, flt const dv1)
{
	flt t = flt_zero, dt, arcLength = flt_zero, arcLengthDelta, arcLengthInv, u, u0;
	flt* lTable = lTable_out;
	uindex i;

	if (tTable_out && lTable_out && vTable_out && numDivisions)
	{
		*tTable_out = t;
		*lTable_out = arcLength;
		*vTable_out = u0 = v0;
		for (i = 1, dt = ijk_recip_flt((flt)numDivisions); i <= numDivisions; ++i)
		{
			t = (flt)i * dt;
			u = ijkInterpCubicHermite_flt(v0, dv0, v1, dv1, t);
			arcLengthDelta = u - u0;
			arcLength += ijk_abs_flt(arcLengthDelta);
			*(++tTable_out) = t;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = u0 = u;
		}
		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}


ijk_inl flt ijkInterpReparamCubicHermiteHandles_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const cv0, flt const v1, flt const cv1)
{
	flt t = flt_zero, dt, arcLength = flt_zero, arcLengthDelta, arcLengthInv, u, u0;
	flt* lTable = lTable_out;
	uindex i;

	if (tTable_out && lTable_out && vTable_out && numDivisions)
	{
		*tTable_out = t;
		*lTable_out = arcLength;
		*vTable_out = u0 = v0;
		for (i = 1, dt = ijk_recip_flt((flt)numDivisions); i <= numDivisions; ++i)
		{
			t = (flt)i * dt;
			u = ijkInterpCubicHermiteHandles_flt(v0, cv0, v1, cv1, t);
			arcLengthDelta = u - u0;
			arcLength += ijk_abs_flt(arcLengthDelta);
			*(++tTable_out) = t;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = u0 = u;
		}
		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}


ijk_inl flt ijkInterpReparamCubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vp, flt const v0, flt const v1, flt const v2)
{
	flt t = flt_zero, dt, arcLength = flt_zero, arcLengthDelta, arcLengthInv, u, u0;
	flt* lTable = lTable_out;
	uindex i;

	if (tTable_out && lTable_out && vTable_out && numDivisions)
	{
		*tTable_out = t;
		*lTable_out = arcLength;
		*vTable_out = u0 = v0;
		for (i = 1, dt = ijk_recip_flt((flt)numDivisions); i <= numDivisions; ++i)
		{
			t = (flt)i * dt;
			u = ijkInterpCubicCatmullRom_flt(vp, v0, v1, v2, t);
			arcLengthDelta = u - u0;
			arcLength += ijk_abs_flt(arcLengthDelta);
			*(++tTable_out) = t;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = u0 = u;
		}
		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}


ijk_inl flt ijkInterpReparamBicubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2)
{
	flt t = flt_zero, dt, arcLength = flt_zero, arcLengthDelta, arcLengthInv, u, u0;
	flt* lTable = lTable_out;
	uindex i;

	if (tTable_out && lTable_out && vTable_out && numDivisions)
	{
		flt const vp = ijkInterpCubicCatmullRom_flt(vpp, vp0, vp1, vp2, tp);
		flt const v0 = ijkInterpCubicCatmullRom_flt(v0p, v00, v01, v02, t0);
		flt const v1 = ijkInterpCubicCatmullRom_flt(v1p, v10, v11, v12, t1);
		flt const v2 = ijkInterpCubicCatmullRom_flt(v2p, v20, v21, v22, t2);

		*tTable_out = t;
		*lTable_out = arcLength;
		*vTable_out = u0 = v0;
		for (i = 1, dt = ijk_recip_flt((flt)numDivisions); i <= numDivisions; ++i)
		{
			t = (flt)i * dt;
			u = ijkInterpCubicCatmullRom_flt(vp, v0, v1, v2, t);
			arcLengthDelta = u - u0;
			arcLength += ijk_abs_flt(arcLengthDelta);
			*(++tTable_out) = t;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = u0 = u;
		}
		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}


ijk_inl flt ijkInterpSampleTableInc_flt(flt const tTable[], flt const vTable[], uindex i, uindex di, flt const t)
{
	return flt_zero;
}


ijk_inl flt ijkInterpSampleTableDec_flt(flt const tTable[], flt const vTable[], uindex i, uindex di, flt const t)
{
	return flt_zero;
}


ijk_inl index ijkInterpSampleTableIncIndex_flt(flt* const tReparam_out, flt const tTable[], uindex i, uindex di, flt const t)
{
	return ijk_zero;
}


ijk_inl index ijkInterpSampleTableDecIndex_flt(flt* const tReparam_out, flt const tTable[], uindex i, uindex di, flt const t)
{
	return ijk_zero;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_INTERPOLATION_INL_
#endif	// _IJK_INTERPOLATION_H_