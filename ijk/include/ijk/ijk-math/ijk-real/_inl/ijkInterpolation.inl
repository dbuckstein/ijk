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
	return (t < flt_half ? v0 : v1);
}


ijk_inl flt ijkInterpBinearest_flt(flt const v00, flt const v01, flt const v10, flt const v11, flt const t0, flt const t1, flt const t)
{
	return (t < flt_half ? t0 < flt_half ? v00 : v01 : t1 < flt_half ? v10 : v11);
}


ijk_inl flt ijkInterpLinear_flt(flt const v0, flt const v1, flt const t)
{
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
	return flt_zero;
}


ijk_inl flt ijkInterpCubicHermiteHandles_flt(flt const v0, flt const cv0, flt const v1, flt const cv1, flt const t)
{
	return flt_zero;
}


ijk_inl flt ijkInterpCubicCatmullRom_flt(flt const vp, flt const v0, flt const v1, flt const v2, flt const t)
{
	return flt_zero;
}


ijk_inl flt ijkInterpBicubicCatmullRom_flt(flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2, flt const t)
{
	return flt_zero;
}


ijk_inl flt ijkInterpReparamCubicHermite_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const dv0, flt const v1, flt const dv1)
{
	return flt_zero;
}


ijk_inl flt ijkInterpReparamCubicHermiteHandles_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const v0, flt const cv0, flt const v1, flt const cv1)
{
	return flt_zero;
}


ijk_inl flt ijkInterpReparamCubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vp, flt const v0, flt const v1, flt const v2)
{
	return flt_zero;
}


ijk_inl flt ijkInterpReparamBicubicCatmullRom_flt(flt tTable_out[], flt lTable_out[], flt vTable_out[], size const numDivisions, ibool const lNormalize, flt const vpp, flt const vp0, flt const vp1, flt const vp2, flt const v0p, flt const v00, flt const v01, flt const v02, flt const v1p, flt const v10, flt const v11, flt const v12, flt const v2p, flt const v20, flt const v21, flt const v22, flt const tp, flt const t0, flt const t1, flt const t2)
{
	return flt_zero;
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