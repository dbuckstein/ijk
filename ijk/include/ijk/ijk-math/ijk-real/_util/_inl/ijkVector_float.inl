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

	ijkVector_float.inl
	Inline definitions for 32-bit float vector functions.
*/

#ifdef _IJK_VECTOR_FLOAT_H_
#ifndef _IJK_VECTOR_FLOAT_INL_
#define _IJK_VECTOR_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl f32 ijkVecAbs1fs(f32 const s)
{
	return ijk_abs_flt(s);
}

ijk_inl f32 ijkVecSgn1fs(f32 const s)
{
	return ijk_sgn_flt(s);
}

ijk_inl f32 ijkVecDot1fs(f32 const s_lh, f32 const s_rh)
{
	return (s_lh * s_rh);
}

ijk_inl f32 ijkVecLengthSq1fs(f32 const s)
{
	return (s * s);
}

ijk_inl f32 ijkVecLength1fs(f32 const s)
{
	return ijk_abs_flt(s);
}

ijk_inl f32 ijkVecLengthSqInv1fs(f32 const s)
{
	f32 const lengthSq = (s * s);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl f32 ijkVecLengthInv1fs(f32 const s)
{
	f32 const length = ijk_abs_flt(s);
	return ijk_recip_safe_flt(length);
}

ijk_inl f32 ijkVecNormalize1fs(f32 const s)
{
	return ijk_sgn_flt(s);
}

ijk_inl f32 ijkVecNormalizeGetLength1fs(f32 const s, f32* const length_out)
{
	f32 const length = *length_out = ijk_abs_flt(s);
	return ijk_sgn_flt(s);
}

ijk_inl f32 ijkVecNormalizeGetLengthInv1fs(f32 const s, f32* const lengthInv_out)
{
	f32 const length = ijk_abs_flt(s);
	*lengthInv_out = ijk_recip_safe_flt(length);
	return ijk_sgn_flt(s);
}


//-----------------------------------------------------------------------------

ijk_inl floatv ijkVecPfv(floatv v_out)
{
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl floatv ijkVecInit2fv(float2 v_out)
{
	v_out[0] = v_out[1] = 0;
	return v_out;
}

ijk_inl floatv ijkVecInitElems2fv(float2 v_out, f32 const x, f32 const y)
{
	v_out[0] = x;
	v_out[1] = y;
	return v_out;
}

ijk_inl floatv ijkVecCopy2fv(float2 v_out, float2 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	return v_out;
}

ijk_inl floatv ijkVecNegate2fv(float2 v_out, float2 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	return v_out;
}

ijk_inl boolv ijkVecNot2fv(bool2 bv_out, float2 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	return bv_out;
}

ijk_inl floatv ijkVecAdd2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecSub2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecMul2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecDiv2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl floatv ijkVecMod2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_flt(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe2fv(float2 v_out, float2 const v_lh, float2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(v_lh[1], v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2fv(bool2 bv_out, float2 const v_lh, float2 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	return bv_out;
}

ijk_inl floatv ijkVecCopy2fvs(float2 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = +s_in;
	return v_out;
}

ijk_inl floatv ijkVecNegate2fvs(float2 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot2fvs(bool2 bv_out, f32 const s_in)
{
	bv_out[0] = bv_out[1] = !s_in;
	return bv_out;
}

ijk_inl floatv ijkVecAdd2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	return v_out;
}

ijk_inl floatv ijkVecSub2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	return v_out;
}

ijk_inl floatv ijkVecMul2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	return v_out;
}

ijk_inl floatv ijkVecDiv2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	return v_out;
}

ijk_inl floatv ijkVecDivSafe2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	return v_out;
}

ijk_inl floatv ijkVecMod2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
	return v_out;
}

ijk_inl floatv ijkVecModSafe2fvs(float2 v_out, float2 const v_lh, f32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
		return v_out;
	}
	return ijkVecCopy2fv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor2fvs(bool2 bv_out, float2 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	return bv_out;
}

ijk_inl floatv ijkVecAdd2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecSub2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecMul2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecDiv2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl floatv ijkVecMod2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = ijk_modulo_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_flt(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe2fsv(float2 v_out, f32 const s_lh, float2 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(s_lh, v_rh[1]);
	return v_out;
}

ijk_inl boolv ijkVecEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecLess2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNand2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecOr2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl boolv ijkVecNor2fsv(bool2 bv_out, f32 const s_lh, float2 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	return bv_out;
}

ijk_inl f32 ijkVecDot2fv(float2 const v_lh, float2 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1]);
}

ijk_inl f32 ijkVecCross2fv(float2 const v_lh, float2 const v_rh)
{
	return (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
}


//-----------------------------------------------------------------------------

ijk_inl floatv ijkVecInit3fv(float3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0;
	return v_out;
}

ijk_inl floatv ijkVecInitElems3fv(float3 v_out, f32 const x, f32 const y, f32 const z)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	return v_out;
}

ijk_inl floatv ijkVecCopy3fv(float3 v_out, float3 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	return v_out;
}

ijk_inl floatv ijkVecNegate3fv(float3 v_out, float3 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	return v_out;
}

ijk_inl boolv ijkVecNot3fv(bool3 bv_out, float3 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	return bv_out;
}

ijk_inl floatv ijkVecAdd3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecSub3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecMul3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecDiv3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_flt(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl floatv ijkVecMod3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_flt(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_flt(v_lh[2], v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3fv(bool3 bv_out, float3 const v_lh, float3 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	return bv_out;
}

ijk_inl floatv ijkVecCopy3fvz(float3 v_out, float2 const v_xy, f32 const z)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	return v_out;
}

ijk_inl floatv ijkVecCopy3fvs(float3 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = +s_in;
	return v_out;
}

ijk_inl floatv ijkVecNegate3fvs(float3 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot3fvs(bool3 bv_out, f32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = !s_in;
	return bv_out;
}

ijk_inl floatv ijkVecAdd3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	return v_out;
}

ijk_inl floatv ijkVecSub3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	return v_out;
}

ijk_inl floatv ijkVecMul3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	return v_out;
}

ijk_inl floatv ijkVecDiv3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	return v_out;
}

ijk_inl floatv ijkVecDivSafe3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	return v_out;
}

ijk_inl floatv ijkVecMod3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
	v_out[2] = ijk_modulo_flt(v_lh[2], s_rh);
	return v_out;
}

ijk_inl floatv ijkVecModSafe3fvs(float3 v_out, float3 const v_lh, f32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
		v_out[2] = ijk_modulo_flt(v_lh[2], s_rh);
		return v_out;
	}
	return ijkVecCopy3fv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor3fvs(bool3 bv_out, float3 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	return bv_out;
}

ijk_inl floatv ijkVecCopy3fxv(float3 v_out, f32 const x, float2 const v_yz)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	return v_out;
}

ijk_inl floatv ijkVecAdd3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecSub3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecMul3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecDiv3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_flt(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl floatv ijkVecMod3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = ijk_modulo_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_flt(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe3fsv(float3 v_out, f32 const s_lh, float3 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_flt(s_lh, v_rh[2]);
	return v_out;
}

ijk_inl boolv ijkVecEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecLess3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNand3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecOr3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl boolv ijkVecNor3fsv(bool3 bv_out, f32 const s_lh, float3 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	return bv_out;
}

ijk_inl f32 ijkVecDot3fv(float3 const v_lh, float3 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2]);
}

ijk_inl floatv ijkVecCross3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	float3 const c = {
		(v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]),
		(v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]),
		(v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]),
	};
	return ijkVecCopy3fv(v_out, c);
}


//-----------------------------------------------------------------------------

ijk_inl floatv ijkVecInit4fv(float4 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = 0;
	return v_out;
}

ijk_inl floatv ijkVecInitElems4fv(float4 v_out, f32 const x, f32 const y, f32 const z, f32 const w)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl floatv ijkVecCopy4fxvw(float4 v_out, f32 const x, float2 const v_yz, f32 const w)
{
	v_out[0] = x;
	v_out[1] = v_yz[0];
	v_out[2] = v_yz[1];
	v_out[3] = w;
	return v_out;
}

ijk_inl floatv ijkVecCopy4fv2(float4 v_out, float2 const v_xy, float2 const v_zw)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl floatv ijkVecCopy4fv(float4 v_out, float4 const v_in)
{
	v_out[0] = +v_in[0];
	v_out[1] = +v_in[1];
	v_out[2] = +v_in[2];
	v_out[3] = +v_in[3];
	return v_out;
}

ijk_inl floatv ijkVecNegate4fv(float4 v_out, float4 const v_in)
{
	v_out[0] = -v_in[0];
	v_out[1] = -v_in[1];
	v_out[2] = -v_in[2];
	v_out[3] = -v_in[3];
	return v_out;
}

ijk_inl boolv ijkVecNot4fv(bool4 bv_out, float4 const v_in)
{
	bv_out[0] = !v_in[0];
	bv_out[1] = !v_in[1];
	bv_out[2] = !v_in[2];
	bv_out[3] = !v_in[3];
	return bv_out;
}

ijk_inl floatv ijkVecAdd4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = v_lh[0] + v_rh[0];
	v_out[1] = v_lh[1] + v_rh[1];
	v_out[2] = v_lh[2] + v_rh[2];
	v_out[3] = v_lh[3] + v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecSub4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = v_lh[0] - v_rh[0];
	v_out[1] = v_lh[1] - v_rh[1];
	v_out[2] = v_lh[2] - v_rh[2];
	v_out[3] = v_lh[3] - v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecMul4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = v_lh[0] * v_rh[0];
	v_out[1] = v_lh[1] * v_rh[1];
	v_out[2] = v_lh[2] * v_rh[2];
	v_out[3] = v_lh[3] * v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecDiv4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = v_lh[0] / v_rh[0];
	v_out[1] = v_lh[1] / v_rh[1];
	v_out[2] = v_lh[2] / v_rh[2];
	v_out[3] = v_lh[3] / v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_divide_safe_flt(v_lh[2], v_rh[2]);
	v_out[3] = ijk_divide_safe_flt(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl floatv ijkVecMod4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_flt(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_flt(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(v_lh[0], v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(v_lh[1], v_rh[1]);
	v_out[2] = ijk_modulo_safe_flt(v_lh[2], v_rh[2]);
	v_out[3] = ijk_modulo_safe_flt(v_lh[3], v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] == v_rh[0]);
	bv_out[1] = (v_lh[1] == v_rh[1]);
	bv_out[2] = (v_lh[2] == v_rh[2]);
	bv_out[3] = (v_lh[3] == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] != v_rh[0]);
	bv_out[1] = (v_lh[1] != v_rh[1]);
	bv_out[2] = (v_lh[2] != v_rh[2]);
	bv_out[3] = (v_lh[3] != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] <= v_rh[0]);
	bv_out[1] = (v_lh[1] <= v_rh[1]);
	bv_out[2] = (v_lh[2] <= v_rh[2]);
	bv_out[3] = (v_lh[3] <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] >= v_rh[0]);
	bv_out[1] = (v_lh[1] >= v_rh[1]);
	bv_out[2] = (v_lh[2] >= v_rh[2]);
	bv_out[3] = (v_lh[3] >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] < v_rh[0]);
	bv_out[1] = (v_lh[1] < v_rh[1]);
	bv_out[2] = (v_lh[2] < v_rh[2]);
	bv_out[3] = (v_lh[3] < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] > v_rh[0]);
	bv_out[1] = (v_lh[1] > v_rh[1]);
	bv_out[2] = (v_lh[2] > v_rh[2]);
	bv_out[3] = (v_lh[3] > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] && v_rh[0]);
	bv_out[1] = (v_lh[1] && v_rh[1]);
	bv_out[2] = (v_lh[2] && v_rh[2]);
	bv_out[3] = (v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = !(v_lh[0] && v_rh[0]);
	bv_out[1] = !(v_lh[1] && v_rh[1]);
	bv_out[2] = !(v_lh[2] && v_rh[2]);
	bv_out[3] = !(v_lh[3] && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = (v_lh[0] || v_rh[0]);
	bv_out[1] = (v_lh[1] || v_rh[1]);
	bv_out[2] = (v_lh[2] || v_rh[2]);
	bv_out[3] = (v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4fv(bool4 bv_out, float4 const v_lh, float4 const v_rh)
{
	bv_out[0] = !(v_lh[0] || v_rh[0]);
	bv_out[1] = !(v_lh[1] || v_rh[1]);
	bv_out[2] = !(v_lh[2] || v_rh[2]);
	bv_out[3] = !(v_lh[3] || v_rh[3]);
	return bv_out;
}

ijk_inl floatv ijkVecCopy4fvzw(float4 v_out, float2 const v_xy, f32 const z, f32 const w)
{
	v_out[0] = v_xy[0];
	v_out[1] = v_xy[1];
	v_out[2] = z;
	v_out[3] = w;
	return v_out;
}

ijk_inl floatv ijkVecCopy4fvw(float4 v_out, float3 const v_xyz, f32 const w)
{
	v_out[0] = v_xyz[0];
	v_out[1] = v_xyz[1];
	v_out[2] = v_xyz[2];
	v_out[3] = w;
	return v_out;
}

ijk_inl floatv ijkVecCopy4fvs(float4 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = +s_in;
	return v_out;
}

ijk_inl floatv ijkVecNegate4fvs(float4 v_out, f32 const s_in)
{
	v_out[0] = v_out[1] = v_out[2] = v_out[3] = -s_in;
	return v_out;
}

ijk_inl boolv ijkVecNot4fvs(bool4 bv_out, f32 const s_in)
{
	bv_out[0] = bv_out[1] = bv_out[2] = bv_out[3] = !s_in;
	return bv_out;
}

ijk_inl floatv ijkVecAdd4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] + s_rh;
	v_out[1] = v_lh[1] + s_rh;
	v_out[2] = v_lh[2] + s_rh;
	v_out[3] = v_lh[3] + s_rh;
	return v_out;
}

ijk_inl floatv ijkVecSub4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] - s_rh;
	v_out[1] = v_lh[1] - s_rh;
	v_out[2] = v_lh[2] - s_rh;
	v_out[3] = v_lh[3] - s_rh;
	return v_out;
}

ijk_inl floatv ijkVecMul4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	v_out[0] = v_lh[0] * s_rh;
	v_out[1] = v_lh[1] * s_rh;
	v_out[2] = v_lh[2] * s_rh;
	v_out[3] = v_lh[3] * s_rh;
	return v_out;
}

ijk_inl floatv ijkVecDiv4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	v_out[3] = v_lh[3] * s;
	return v_out;
}

ijk_inl floatv ijkVecDivSafe4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	v_out[0] = v_lh[0] * s;
	v_out[1] = v_lh[1] * s;
	v_out[2] = v_lh[2] * s;
	v_out[3] = v_lh[3] * s;
	return v_out;
}

ijk_inl floatv ijkVecMod4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
	v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
	v_out[2] = ijk_modulo_flt(v_lh[2], s_rh);
	v_out[3] = ijk_modulo_flt(v_lh[3], s_rh);
	return v_out;
}

ijk_inl floatv ijkVecModSafe4fvs(float4 v_out, float4 const v_lh, f32 const s_rh)
{
	if (s_rh)
	{
		v_out[0] = ijk_modulo_flt(v_lh[0], s_rh);
		v_out[1] = ijk_modulo_flt(v_lh[1], s_rh);
		v_out[2] = ijk_modulo_flt(v_lh[2], s_rh);
		v_out[3] = ijk_modulo_flt(v_lh[3], s_rh);
		return v_out;
	}
	return ijkVecCopy4fv(v_out, v_lh);
}

ijk_inl boolv ijkVecEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] == s_rh);
	bv_out[1] = (v_lh[1] == s_rh);
	bv_out[2] = (v_lh[2] == s_rh);
	bv_out[3] = (v_lh[3] == s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] != s_rh);
	bv_out[1] = (v_lh[1] != s_rh);
	bv_out[2] = (v_lh[2] != s_rh);
	bv_out[3] = (v_lh[3] != s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] <= s_rh);
	bv_out[1] = (v_lh[1] <= s_rh);
	bv_out[2] = (v_lh[2] <= s_rh);
	bv_out[3] = (v_lh[3] <= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] >= s_rh);
	bv_out[1] = (v_lh[1] >= s_rh);
	bv_out[2] = (v_lh[2] >= s_rh);
	bv_out[3] = (v_lh[3] >= s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecLess4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] < s_rh);
	bv_out[1] = (v_lh[1] < s_rh);
	bv_out[2] = (v_lh[2] < s_rh);
	bv_out[3] = (v_lh[3] < s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] > s_rh);
	bv_out[1] = (v_lh[1] > s_rh);
	bv_out[2] = (v_lh[2] > s_rh);
	bv_out[3] = (v_lh[3] > s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] && s_rh);
	bv_out[1] = (v_lh[1] && s_rh);
	bv_out[2] = (v_lh[2] && s_rh);
	bv_out[3] = (v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNand4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] && s_rh);
	bv_out[1] = !(v_lh[1] && s_rh);
	bv_out[2] = !(v_lh[2] && s_rh);
	bv_out[3] = !(v_lh[3] && s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecOr4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = (v_lh[0] || s_rh);
	bv_out[1] = (v_lh[1] || s_rh);
	bv_out[2] = (v_lh[2] || s_rh);
	bv_out[3] = (v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl boolv ijkVecNor4fvs(bool4 bv_out, float4 const v_lh, f32 const s_rh)
{
	bv_out[0] = !(v_lh[0] || s_rh);
	bv_out[1] = !(v_lh[1] || s_rh);
	bv_out[2] = !(v_lh[2] || s_rh);
	bv_out[3] = !(v_lh[3] || s_rh);
	return bv_out;
}

ijk_inl floatv ijkVecCopy4fxyv(float4 v_out, f32 const x, f32 const y, float2 const v_zw)
{
	v_out[0] = x;
	v_out[1] = y;
	v_out[2] = v_zw[0];
	v_out[3] = v_zw[1];
	return v_out;
}

ijk_inl floatv ijkVecCopy4fxv(float4 v_out, f32 const x, float3 const v_yzw)
{
	v_out[0] = x;
	v_out[1] = v_yzw[0];
	v_out[2] = v_yzw[1];
	v_out[3] = v_yzw[2];
	return v_out;
}

ijk_inl floatv ijkVecAdd4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = s_lh + v_rh[0];
	v_out[1] = s_lh + v_rh[1];
	v_out[2] = s_lh + v_rh[2];
	v_out[3] = s_lh + v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecSub4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = s_lh - v_rh[0];
	v_out[1] = s_lh - v_rh[1];
	v_out[2] = s_lh - v_rh[2];
	v_out[3] = s_lh - v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecMul4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = s_lh * v_rh[0];
	v_out[1] = s_lh * v_rh[1];
	v_out[2] = s_lh * v_rh[2];
	v_out[3] = s_lh * v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecDiv4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = s_lh / v_rh[0];
	v_out[1] = s_lh / v_rh[1];
	v_out[2] = s_lh / v_rh[2];
	v_out[3] = s_lh / v_rh[3];
	return v_out;
}

ijk_inl floatv ijkVecDivSafe4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = ijk_divide_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_divide_safe_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_divide_safe_flt(s_lh, v_rh[2]);
	v_out[3] = ijk_divide_safe_flt(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl floatv ijkVecMod4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = ijk_modulo_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_flt(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_flt(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl floatv ijkVecModSafe4fsv(float4 v_out, f32 const s_lh, float4 const v_rh)
{
	v_out[0] = ijk_modulo_safe_flt(s_lh, v_rh[0]);
	v_out[1] = ijk_modulo_safe_flt(s_lh, v_rh[1]);
	v_out[2] = ijk_modulo_safe_flt(s_lh, v_rh[2]);
	v_out[3] = ijk_modulo_safe_flt(s_lh, v_rh[3]);
	return v_out;
}

ijk_inl boolv ijkVecEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh == v_rh[0]);
	bv_out[1] = (s_lh == v_rh[1]);
	bv_out[2] = (s_lh == v_rh[2]);
	bv_out[3] = (s_lh == v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecInequal4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh != v_rh[0]);
	bv_out[1] = (s_lh != v_rh[1]);
	bv_out[2] = (s_lh != v_rh[2]);
	bv_out[3] = (s_lh != v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLessEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh <= v_rh[0]);
	bv_out[1] = (s_lh <= v_rh[1]);
	bv_out[2] = (s_lh <= v_rh[2]);
	bv_out[3] = (s_lh <= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreaterEqual4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh >= v_rh[0]);
	bv_out[1] = (s_lh >= v_rh[1]);
	bv_out[2] = (s_lh >= v_rh[2]);
	bv_out[3] = (s_lh >= v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecLess4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh < v_rh[0]);
	bv_out[1] = (s_lh < v_rh[1]);
	bv_out[2] = (s_lh < v_rh[2]);
	bv_out[3] = (s_lh < v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecGreater4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh > v_rh[0]);
	bv_out[1] = (s_lh > v_rh[1]);
	bv_out[2] = (s_lh > v_rh[2]);
	bv_out[3] = (s_lh > v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecAnd4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh && v_rh[0]);
	bv_out[1] = (s_lh && v_rh[1]);
	bv_out[2] = (s_lh && v_rh[2]);
	bv_out[3] = (s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNand4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = !(s_lh && v_rh[0]);
	bv_out[1] = !(s_lh && v_rh[1]);
	bv_out[2] = !(s_lh && v_rh[2]);
	bv_out[3] = !(s_lh && v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecOr4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = (s_lh || v_rh[0]);
	bv_out[1] = (s_lh || v_rh[1]);
	bv_out[2] = (s_lh || v_rh[2]);
	bv_out[3] = (s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl boolv ijkVecNor4fsv(bool4 bv_out, f32 const s_lh, float4 const v_rh)
{
	bv_out[0] = !(s_lh || v_rh[0]);
	bv_out[1] = !(s_lh || v_rh[1]);
	bv_out[2] = !(s_lh || v_rh[2]);
	bv_out[3] = !(s_lh || v_rh[3]);
	return bv_out;
}

ijk_inl f32 ijkVecDot4fv(float4 const v_lh, float4 const v_rh)
{
	return (v_lh[0] * v_rh[0] + v_lh[1] * v_rh[1] + v_lh[2] * v_rh[2] + v_lh[3] * v_rh[3]);
}

ijk_inl floatv ijkVecCross4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	v_out[3] = 0;
	return ijkVecCross3fv(v_out, v_lh, v_rh);
}


//-----------------------------------------------------------------------------

ijk_inl float ijkVecAbs1f(float const s)
{
	return ijkVecAbs1fs(s);
}

ijk_inl float ijkVecSgn1f(float const s)
{
	return ijkVecSgn1fs(s);
}

ijk_inl float ijkVecDot1f(float const s_lh, float const s_rh)
{
	return ijkVecDot1fs(s_lh, s_rh);
}

ijk_inl float ijkVecLengthSq1f(float const s)
{
	return ijkVecLengthSq1fs(s);
}

ijk_inl float ijkVecLength1f(float const s)
{
	return ijkVecLength1fs(s);
}

ijk_inl float ijkVecLengthSqInv1f(float const s)
{
	return ijkVecLengthSqInv1fs(s);
}

ijk_inl float ijkVecLengthInv1f(float const s)
{
	return ijkVecLengthInv1fs(s);
}

ijk_inl float ijkVecNormalize1f(float const s)
{
	return ijkVecNormalize1fs(s);
}

ijk_inl float ijkVecNormalizeGetLength1f(float const s, float* const length_out)
{
	return ijkVecNormalizeGetLength1fs(s, (f32*)length_out);
}

ijk_inl float ijkVecNormalizeGetLengthInv1f(float const s, float* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv1fs(s, (f32*)lengthInv_out);
}


//-----------------------------------------------------------------------------

ijk_inl fvec2 ijkVecInit2f()
{
	fvec2 const v_out = { 0, 0 };
	return v_out;
}

ijk_inl fvec2 ijkVecInitElems2f(float const x, float const y)
{
	fvec2 const v_out = { x, y };
	return v_out;
}

ijk_inl fvec2 ijkVecCopy2f(fvec2 const v_in)
{
	fvec2 const v_out = { +v_in.x, +v_in.y };
	return v_out;
}

ijk_inl fvec2 ijkVecNegate2f(fvec2 const v_in)
{
	fvec2 const v_out = { -v_in.x, -v_in.y };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2f(fvec2 const v_in)
{
	bvec2 const bv_out = { !v_in.x, !v_in.y };
	return bv_out;
}

ijk_inl fvec2 ijkVecAdd2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecSub2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMul2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDiv2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDivSafe2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_divide_safe_flt(v_lh.x, v_rh.x),
		ijk_divide_safe_flt(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMod2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_modulo_flt(v_lh.x, v_rh.x),
		ijk_modulo_flt(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecModSafe2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_modulo_safe_flt(v_lh.x, v_rh.x),
		ijk_modulo_safe_flt(v_lh.y, v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2f(fvec2 const v_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
	};
	return bv_out;
}

ijk_inl fvec2 ijkVecCopy2fs(float const s_in)
{
	fvec2 const v_out = { s_in, s_in };
	return v_out;
}

ijk_inl fvec2 ijkVecNegate2fs(float const s_in)
{
	float const s = -s_in;
	fvec2 const v_out = { s, s };
	return v_out;
}

ijk_inl bvec2 ijkVecNot2fs(float const s_in)
{
	bool const s = !s_in;
	bvec2 const bv_out = { s, s };
	return bv_out;
}

ijk_inl fvec2 ijkVecAdd2fs(fvec2 const v_lh, float const s_rh)
{
	fvec2 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecSub2fs(fvec2 const v_lh, float const s_rh)
{
	fvec2 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMul2fs(fvec2 const v_lh, float const s_rh)
{
	fvec2 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDiv2fs(fvec2 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	fvec2 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDivSafe2fs(fvec2 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	fvec2 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMod2fs(fvec2 const v_lh, float const s_rh)
{
	fvec2 const v_out = {
		ijk_modulo_flt(v_lh.x, s_rh),
		ijk_modulo_flt(v_lh.y, s_rh),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecModSafe2fs(fvec2 const v_lh, float const s_rh)
{
	if (s_rh)
	{
		fvec2 const v_out = {
			ijk_modulo_flt(v_lh.x, s_rh),
			ijk_modulo_flt(v_lh.y, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec2 ijkVecEqual2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2fs(fvec2 const v_lh, float const s_rh)
{
	bvec2 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
	};
	return bv_out;
}

ijk_inl fvec2 ijkVecAdd2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecSub2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMul2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDiv2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
	};
	return v_out;
}

ijk_inl fvec2 ijkVecDivSafe2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_divide_safe_flt(s_lh, v_rh.x),
		ijk_divide_safe_flt(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecMod2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_modulo_flt(s_lh, v_rh.x),
		ijk_modulo_flt(s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecModSafe2sf(float const s_lh, fvec2 const v_rh)
{
	fvec2 const v_out = {
		ijk_modulo_safe_flt((f32)s_lh, v_rh.x),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.y),
	};
	return v_out;
}

ijk_inl bvec2 ijkVecEqual2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecInequal2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLessEqual2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreaterEqual2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecLess2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecGreater2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecAnd2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNand2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecOr2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl bvec2 ijkVecNor2sf(float const s_lh, fvec2 const v_rh)
{
	bvec2 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
	};
	return bv_out;
}

ijk_inl float ijkVecDot2f(fvec2 const v_lh, fvec2 const v_rh)
{
	return ijkVecDot2fv(v_lh.xy, v_rh.xy);
}

ijk_inl float ijkVecCross2f(fvec2 const v_lh, fvec2 const v_rh)
{
	return ijkVecCross2fv(v_lh.xy, v_rh.xy);
}


//-----------------------------------------------------------------------------

ijk_inl fvec3 ijkVecInit3f()
{
	fvec3 const v_out = { 0, 0, 0 };
	return v_out;
}

ijk_inl fvec3 ijkVecInitElems3f(float const x, float const y, float const z)
{
	fvec3 const v_out = { x, y, z };
	return v_out;
}

ijk_inl fvec3 ijkVecCopy3f(fvec3 const v_in)
{
	fvec3 const v_out = { +v_in.x, +v_in.y, +v_in.z };
	return v_out;
}

ijk_inl fvec3 ijkVecNegate3f(fvec3 const v_in)
{
	fvec3 const v_out = { -v_in.x, -v_in.y, -v_in.z };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3f(fvec3 const v_in)
{
	bvec3 const bv_out = { !v_in.x, !v_in.y, !v_in.z };
	return bv_out;
}

ijk_inl fvec3 ijkVecAdd3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecSub3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMul3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDiv3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDivSafe3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_divide_safe_flt(v_lh.x, v_rh.x),
		ijk_divide_safe_flt(v_lh.y, v_rh.y),
		ijk_divide_safe_flt(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMod3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_modulo_flt(v_lh.x, v_rh.x),
		ijk_modulo_flt(v_lh.y, v_rh.y),
		ijk_modulo_flt(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecModSafe3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_modulo_safe_flt(v_lh.x, v_rh.x),
		ijk_modulo_safe_flt(v_lh.y, v_rh.y),
		ijk_modulo_safe_flt(v_lh.z, v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3f(fvec3 const v_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
	};
	return bv_out;
}

ijk_inl fvec3 ijkVecCopy3fz(fvec2 const v_xy, float const z)
{
	fvec3 const v_out = { v_xy.x, v_xy.y, z };
	return v_out;
}

ijk_inl fvec3 ijkVecCopy3fs(float const s_in)
{
	fvec3 const v_out = { s_in, s_in, s_in };
	return v_out;
}

ijk_inl fvec3 ijkVecNegate3fs(float const s_in)
{
	float const s = -s_in;
	fvec3 const v_out = { s, s, s };
	return v_out;
}

ijk_inl bvec3 ijkVecNot3fs(float const s_in)
{
	bool const s = !s_in;
	bvec3 const bv_out = { s, s, s };
	return bv_out;
}

ijk_inl fvec3 ijkVecAdd3fs(fvec3 const v_lh, float const s_rh)
{
	fvec3 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecSub3fs(fvec3 const v_lh, float const s_rh)
{
	fvec3 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMul3fs(fvec3 const v_lh, float const s_rh)
{
	fvec3 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDiv3fs(fvec3 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	fvec3 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDivSafe3fs(fvec3 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	fvec3 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMod3fs(fvec3 const v_lh, float const s_rh)
{
	fvec3 const v_out = {
		ijk_modulo_flt(v_lh.x, s_rh),
		ijk_modulo_flt(v_lh.y, s_rh),
		ijk_modulo_flt(v_lh.z, s_rh),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecModSafe3fs(fvec3 const v_lh, float const s_rh)
{
	if (s_rh)
	{
		fvec3 const v_out = {
			ijk_modulo_flt(v_lh.x, s_rh),
			ijk_modulo_flt(v_lh.y, s_rh),
			ijk_modulo_flt(v_lh.z, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec3 ijkVecEqual3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3fs(fvec3 const v_lh, float const s_rh)
{
	bvec3 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
	};
	return bv_out;
}

ijk_inl fvec3 ijkVecCopy3xf(float const x, fvec2 const v_yz)
{
	fvec3 const v_out = { x, v_yz.x, v_yz.y };
	return v_out;
}

ijk_inl fvec3 ijkVecAdd3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecSub3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMul3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDiv3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
	};
	return v_out;
}

ijk_inl fvec3 ijkVecDivSafe3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_divide_safe_flt(s_lh, v_rh.x),
		ijk_divide_safe_flt(s_lh, v_rh.y),
		ijk_divide_safe_flt(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecMod3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_modulo_flt(s_lh, v_rh.x),
		ijk_modulo_flt(s_lh, v_rh.y),
		ijk_modulo_flt(s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecModSafe3sf(float const s_lh, fvec3 const v_rh)
{
	fvec3 const v_out = {
		ijk_modulo_safe_flt((f32)s_lh, v_rh.x),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.y),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.z),
	};
	return v_out;
}

ijk_inl bvec3 ijkVecEqual3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecInequal3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLessEqual3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreaterEqual3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecLess3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecGreater3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecAnd3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNand3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecOr3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl bvec3 ijkVecNor3sf(float const s_lh, fvec3 const v_rh)
{
	bvec3 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
	};
	return bv_out;
}

ijk_inl float ijkVecDot3f(fvec3 const v_lh, fvec3 const v_rh)
{
	return ijkVecDot3fv(v_lh.xyz, v_rh.xyz);
}

ijk_inl fvec3 ijkVecCross3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 v_out;
	ijkVecCross3fv(v_out.xyz, v_lh.xyz, v_rh.xyz);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl fvec4 ijkVecInit4f()
{
	fvec4 const v_out = { 0, 0, 0, 0 };
	return v_out;
}

ijk_inl fvec4 ijkVecInitElems4f(float const x, float const y, float const z, float const w)
{
	fvec4 const v_out = { x, y, z, w };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4xfw(float const x, fvec2 const v_yz, float const w)
{
	fvec4 const v_out = { x, v_yz.x, v_yz.y, w };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4f2(fvec2 const v_xy, fvec2 const v_zw)
{
	fvec4 const v_out = { v_xy.x, v_xy.y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4f(fvec4 const v_in)
{
	fvec4 const v_out = { +v_in.x, +v_in.y, +v_in.z, +v_in.w };
	return v_out;
}

ijk_inl fvec4 ijkVecNegate4f(fvec4 const v_in)
{
	fvec4 const v_out = { -v_in.x, -v_in.y, -v_in.z, -v_in.w };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4f(fvec4 const v_in)
{
	bvec4 const bv_out = { !v_in.x, !v_in.y, !v_in.z, !v_in.w };
	return bv_out;
}

ijk_inl fvec4 ijkVecAdd4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		v_lh.x + v_rh.x,
		v_lh.y + v_rh.y,
		v_lh.z + v_rh.z,
		v_lh.w + v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecSub4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		v_lh.x - v_rh.x,
		v_lh.y - v_rh.y,
		v_lh.z - v_rh.z,
		v_lh.w - v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMul4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		v_lh.x * v_rh.x,
		v_lh.y * v_rh.y,
		v_lh.z * v_rh.z,
		v_lh.w * v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDiv4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		v_lh.x / v_rh.x,
		v_lh.y / v_rh.y,
		v_lh.z / v_rh.z,
		v_lh.w / v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDivSafe4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_divide_safe_flt(v_lh.x, v_rh.x),
		ijk_divide_safe_flt(v_lh.y, v_rh.y),
		ijk_divide_safe_flt(v_lh.z, v_rh.z),
		ijk_divide_safe_flt(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMod4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_modulo_flt(v_lh.x, v_rh.x),
		ijk_modulo_flt(v_lh.y, v_rh.y),
		ijk_modulo_flt(v_lh.z, v_rh.z),
		ijk_modulo_flt(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecModSafe4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_modulo_safe_flt(v_lh.x, v_rh.x),
		ijk_modulo_safe_flt(v_lh.y, v_rh.y),
		ijk_modulo_safe_flt(v_lh.z, v_rh.z),
		ijk_modulo_safe_flt(v_lh.w, v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == v_rh.x),
		(v_lh.y == v_rh.y),
		(v_lh.z == v_rh.z),
		(v_lh.w == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != v_rh.x),
		(v_lh.y != v_rh.y),
		(v_lh.z != v_rh.z),
		(v_lh.w != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= v_rh.x),
		(v_lh.y <= v_rh.y),
		(v_lh.z <= v_rh.z),
		(v_lh.w <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= v_rh.x),
		(v_lh.y >= v_rh.y),
		(v_lh.z >= v_rh.z),
		(v_lh.w >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < v_rh.x),
		(v_lh.y < v_rh.y),
		(v_lh.z < v_rh.z),
		(v_lh.w < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > v_rh.x),
		(v_lh.y > v_rh.y),
		(v_lh.z > v_rh.z),
		(v_lh.w > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && v_rh.x),
		(v_lh.y && v_rh.y),
		(v_lh.z && v_rh.z),
		(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && v_rh.x),
		!(v_lh.y && v_rh.y),
		!(v_lh.z && v_rh.z),
		!(v_lh.w && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || v_rh.x),
		(v_lh.y || v_rh.y),
		(v_lh.z || v_rh.z),
		(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4f(fvec4 const v_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || v_rh.x),
		!(v_lh.y || v_rh.y),
		!(v_lh.z || v_rh.z),
		!(v_lh.w || v_rh.w),
	};
	return bv_out;
}

ijk_inl fvec4 ijkVecCopy4fzw(fvec2 const v_xy, float const z, float const w)
{
	fvec4 const v_out = { v_xy.x, v_xy.y, z, w };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4fw(fvec3 const v_xyz, float const w)
{
	fvec4 const v_out = { v_xyz.x, v_xyz.y, v_xyz.z, w };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4fs(float const s_in)
{
	fvec4 const v_out = { s_in, s_in, s_in, s_in };
	return v_out;
}

ijk_inl fvec4 ijkVecNegate4fs(float const s_in)
{
	float const s = -s_in;
	fvec4 const v_out = { s, s, s, s };
	return v_out;
}

ijk_inl bvec4 ijkVecNot4fs(float const s_in)
{
	bool const s = !s_in;
	bvec4 const bv_out = { s, s, s, s };
	return bv_out;
}

ijk_inl fvec4 ijkVecAdd4fs(fvec4 const v_lh, float const s_rh)
{
	fvec4 const v_out = {
		v_lh.x + s_rh,
		v_lh.y + s_rh,
		v_lh.z + s_rh,
		v_lh.w + s_rh,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecSub4fs(fvec4 const v_lh, float const s_rh)
{
	fvec4 const v_out = {
		v_lh.x - s_rh,
		v_lh.y - s_rh,
		v_lh.z - s_rh,
		v_lh.w - s_rh,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMul4fs(fvec4 const v_lh, float const s_rh)
{
	fvec4 const v_out = {
		v_lh.x * s_rh,
		v_lh.y * s_rh,
		v_lh.z * s_rh,
		v_lh.w * s_rh,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDiv4fs(fvec4 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_flt(s_rh);
	fvec4 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
		v_lh.w * s,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDivSafe4fs(fvec4 const v_lh, float const s_rh)
{
	f32 const s = ijk_recip_safe_flt(s_rh);
	fvec4 const v_out = {
		v_lh.x * s,
		v_lh.y * s,
		v_lh.z * s,
		v_lh.w * s,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMod4fs(fvec4 const v_lh, float const s_rh)
{
	fvec4 const v_out = {
		ijk_modulo_flt(v_lh.x, s_rh),
		ijk_modulo_flt(v_lh.y, s_rh),
		ijk_modulo_flt(v_lh.z, s_rh),
		ijk_modulo_flt(v_lh.w, s_rh),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecModSafe4fs(fvec4 const v_lh, float const s_rh)
{
	if (s_rh)
	{
		fvec4 const v_out = {
			ijk_modulo_flt(v_lh.x, s_rh),
			ijk_modulo_flt(v_lh.y, s_rh),
			ijk_modulo_flt(v_lh.z, s_rh),
			ijk_modulo_flt(v_lh.w, s_rh),
		};
		return v_out;
	}
	return v_lh;
}

ijk_inl bvec4 ijkVecEqual4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x == s_rh),
		(v_lh.y == s_rh),
		(v_lh.z == s_rh),
		(v_lh.w == s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x != s_rh),
		(v_lh.y != s_rh),
		(v_lh.z != s_rh),
		(v_lh.w != s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x <= s_rh),
		(v_lh.y <= s_rh),
		(v_lh.z <= s_rh),
		(v_lh.w <= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x >= s_rh),
		(v_lh.y >= s_rh),
		(v_lh.z >= s_rh),
		(v_lh.w >= s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x < s_rh),
		(v_lh.y < s_rh),
		(v_lh.z < s_rh),
		(v_lh.w < s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x > s_rh),
		(v_lh.y > s_rh),
		(v_lh.z > s_rh),
		(v_lh.w > s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x && s_rh),
		(v_lh.y && s_rh),
		(v_lh.z && s_rh),
		(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x && s_rh),
		!(v_lh.y && s_rh),
		!(v_lh.z && s_rh),
		!(v_lh.w && s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		(v_lh.x || s_rh),
		(v_lh.y || s_rh),
		(v_lh.z || s_rh),
		(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4fs(fvec4 const v_lh, float const s_rh)
{
	bvec4 const bv_out = {
		!(v_lh.x || s_rh),
		!(v_lh.y || s_rh),
		!(v_lh.z || s_rh),
		!(v_lh.w || s_rh),
	};
	return bv_out;
}

ijk_inl fvec4 ijkVecCopy4xyf(float const x, float const y, fvec2 const v_zw)
{
	fvec4 const v_out = { x, y, v_zw.x, v_zw.y };
	return v_out;
}

ijk_inl fvec4 ijkVecCopy4xf(float const x, fvec3 const v_yzw)
{
	fvec4 const v_out = { x, v_yzw.x, v_yzw.y, v_yzw.z };
	return v_out;
}

ijk_inl fvec4 ijkVecAdd4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		s_lh + v_rh.x,
		s_lh + v_rh.y,
		s_lh + v_rh.z,
		s_lh + v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecSub4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		s_lh - v_rh.x,
		s_lh - v_rh.y,
		s_lh - v_rh.z,
		s_lh - v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMul4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		s_lh * v_rh.x,
		s_lh * v_rh.y,
		s_lh * v_rh.z,
		s_lh * v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDiv4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		s_lh / v_rh.x,
		s_lh / v_rh.y,
		s_lh / v_rh.z,
		s_lh / v_rh.w,
	};
	return v_out;
}

ijk_inl fvec4 ijkVecDivSafe4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_divide_safe_flt(s_lh, v_rh.x),
		ijk_divide_safe_flt(s_lh, v_rh.y),
		ijk_divide_safe_flt(s_lh, v_rh.z),
		ijk_divide_safe_flt(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecMod4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_modulo_flt(s_lh, v_rh.x),
		ijk_modulo_flt(s_lh, v_rh.y),
		ijk_modulo_flt(s_lh, v_rh.z),
		ijk_modulo_flt(s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecModSafe4sf(float const s_lh, fvec4 const v_rh)
{
	fvec4 const v_out = {
		ijk_modulo_safe_flt((f32)s_lh, v_rh.x),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.y),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.z),
		ijk_modulo_safe_flt((f32)s_lh, v_rh.w),
	};
	return v_out;
}

ijk_inl bvec4 ijkVecEqual4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh == v_rh.x),
		(s_lh == v_rh.y),
		(s_lh == v_rh.z),
		(s_lh == v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecInequal4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh != v_rh.x),
		(s_lh != v_rh.y),
		(s_lh != v_rh.z),
		(s_lh != v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLessEqual4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh <= v_rh.x),
		(s_lh <= v_rh.y),
		(s_lh <= v_rh.z),
		(s_lh <= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreaterEqual4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh >= v_rh.x),
		(s_lh >= v_rh.y),
		(s_lh >= v_rh.z),
		(s_lh >= v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecLess4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh < v_rh.x),
		(s_lh < v_rh.y),
		(s_lh < v_rh.z),
		(s_lh < v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecGreater4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh > v_rh.x),
		(s_lh > v_rh.y),
		(s_lh > v_rh.z),
		(s_lh > v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecAnd4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh && v_rh.x),
		(s_lh && v_rh.y),
		(s_lh && v_rh.z),
		(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNand4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh && v_rh.x),
		!(s_lh && v_rh.y),
		!(s_lh && v_rh.z),
		!(s_lh && v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecOr4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		(s_lh || v_rh.x),
		(s_lh || v_rh.y),
		(s_lh || v_rh.z),
		(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl bvec4 ijkVecNor4sf(float const s_lh, fvec4 const v_rh)
{
	bvec4 const bv_out = {
		!(s_lh || v_rh.x),
		!(s_lh || v_rh.y),
		!(s_lh || v_rh.z),
		!(s_lh || v_rh.w),
	};
	return bv_out;
}

ijk_inl float ijkVecDot4f(fvec4 const v_lh, fvec4 const v_rh)
{
	return ijkVecDot4fv(v_lh.xyzw, v_rh.xyzw);
}

ijk_inl fvec4 ijkVecCross4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 v_out;
	ijkVecCross4fv(v_out.xyzw, v_lh.xyzw, v_rh.xyzw);
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl f32 ijkVecLengthSq2fv(float2 const v_in)
{
	return ijkVecDot2fv(v_in, v_in);
}

ijk_inl f32 ijkVecLength2fv(float2 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq2fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInv2fv(float2 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq2fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInvSafe2fv(float2 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq2fv(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl f32 ijkVecLengthInv2fv(float2 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq2fv(v_in));
}

ijk_inl f32 ijkVecLengthInvSafe2fv(float2 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq2fv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl floatv ijkVecNormalize2fv(float2 v_out, float2 const v_in)
{
	return ijkVecMul2fvs(v_out, v_in, ijkVecLengthInv2fv(v_in));
}

ijk_inl floatv ijkVecNormalizeSafe2fv(float2 v_out, float2 const v_in)
{
	return ijkVecMul2fvs(v_out, v_in, ijkVecLengthInvSafe2fv(v_in));
}

ijk_inl floatv ijkVecNormalizeGetLength2fv(float2 v_out, float2 const v_in, f32* const length_out)
{
	return ijkVecDiv2fvs(v_out, v_in, (*length_out = ijkVecLength2fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLength2fv(float2 v_out, float2 const v_in, f32* const length_out)
{
	return ijkVecDivSafe2fvs(v_out, v_in, (*length_out = ijkVecLength2fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeGetLengthInv2fv(float2 v_out, float2 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul2fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv2fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLengthInv2fv(float2 v_out, float2 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul2fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe2fv(v_in)));
}

ijk_inl f32 ijkVecCrossNormalize2fv(float2 const v_lh, float2 const v_rh)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	return ijk_sgn_flt(cross);
}

ijk_inl f32 ijkVecCrossNormalizeSafe2fv(float2 const v_lh, float2 const v_rh)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	return ijk_sgn_flt(cross);
}

ijk_inl f32 ijkVecCrossNormalizeGetLength2fv(float2 const v_lh, float2 const v_rh, f32* const length_out)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	*length_out = ijk_abs_flt(cross);
	return ijk_sgn_flt(cross);
}

ijk_inl f32 ijkVecCrossNormalizeSafeGetLength2fv(float2 const v_lh, float2 const v_rh, f32* const length_out)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	*length_out = ijk_abs_flt(cross);
	return ijk_sgn_flt(cross);
}

ijk_inl f32 ijkVecCrossNormalizeGetLengthInv2fv(float2 const v_lh, float2 const v_rh, f32* const lengthInv_out)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	f32 const length = ijk_abs_flt(cross);
	*lengthInv_out = ijk_recip_flt(length);
	return ijk_sgn_flt(cross);
}

ijk_inl f32 ijkVecCrossNormalizeSafeGetLengthInv2fv(float2 const v_lh, float2 const v_rh, f32* const lengthInv_out)
{
	f32 const cross = ijkVecCross2fv(v_lh, v_rh);
	f32 const length = ijk_abs_flt(cross);
	*lengthInv_out = ijk_recip_safe_flt(length);
	return ijk_sgn_flt(cross);
}

ijk_inl floatv ijkVecLerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u)
{
	v_out[0] = ijkInterpLinear_flt(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_flt(v0[1], v1[1], u);
	return v_out;
}

ijk_inl floatv ijkVecLerpInv2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_flt(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_flt(v0[1], v1[1], v_lerp[1]);
	return v_out;
}

ijk_inl floatv ijkVecLerpRevInit2fv(float2 v0_out, float2 const v_lerp, float2 const v1, f32 const u)
{
	f32 const s = ijk_recip_flt(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	return v0_out;
}

ijk_inl floatv ijkVecLerpRevTerm2fv(float2 v1_out, float2 const v0, float2 const v_lerp, f32 const u)
{
	return ijkVecLerp2fv(v1_out, v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl f32 ijkVecProjRatio2fv(float2 const v_base, float2 const v_in)
{
	return (ijkVecDot2fv(v_base, v_in) / ijkVecLengthSq2fv(v_base));
}

ijk_inl floatv ijkVecProj2fv(float2 v_out, float2 const v_base, float2 const v_in)
{
	return ijkVecMul2fvs(v_out, v_base, ijkVecProjRatio2fv(v_base, v_in));
}

ijk_inl floatv ijkVecOrtho2fv(float2 v_out, float2 const v_base, float2 const v_in)
{
	float2 ortho;
	return ijkVecSub2fv(v_out, v_in, ijkVecProj2fv(ortho, v_base, v_in));
}

ijk_inl floatv ijkVecOrthoNorm2fv(float2 v_out, float2 const v_base, float2 const v_in, float2 v_base_norm_out)
{
	float2 ortho;
	ijkVecNormalize2fv(v_base_norm_out, v_base);
	ijkVecSub2fv(v_out, v_in, ijkVecMul2fvs(ortho, v_base_norm_out, ijkVecDot2fv(v_base_norm_out, v_in)));
	return ijkVecNormalize2fv(v_out, v_out);
}

ijk_inl float2* ijkVecOrthoList2fv(float2 vl_out[], float2 const v_base, float2 const vl_in[], size const n)
{
	float2 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj2fv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd2fv(orthoSum, orthoSum, ijkVecProj2fv(ortho, vl_out[j], vp_in));
		ijkVecSub2fv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl float2* ijkVecOrthoNormList2fv(float2 vl_out[], float2 const v_base, float2 const vl_in[], size const n, float2 v_base_norm_out)
{
	float2 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	ijkVecNormalize2fv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul2fvs(ortho, v_base_norm_out, ijkVecDot2fv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd2fv(orthoSum, orthoSum, ijkVecMul2fvs(ortho, vl_out[j], ijkVecDot2fv(vl_out[j], vp_in)));
		ijkVecSub2fv(vp_out, vp_in, orthoSum);
		ijkVecNormalize2fv(vp_out, vp_out);
	}
	return vl_out;
}

ijk_inl floatv ijkVecNlerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u)
{
	ijkVecLerp2fv(v_out, v0, v1, u);
	return ijkVecNormalize2fv(v_out, v_out);
}

ijk_inl floatv ijkVecSlerp2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u)
{
	// slerp[v0,v1](u) = (sin([1 - u]A)v0 + sin(uA)v1) / sin(A)
	//	A = acos(dot(v0,v1))

	//f32 const lenInv0 = ijkVecLengthInv2fv(v0), lenInv1 = ijkVecLengthInv2fv(v1);
	// check if vectors are far enough apart to have an effect
	f32 const dot = ijkVecDot2fv(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float2 tmp;
		f32 const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd2fv(v_out, ijkVecMul2fvs(v_out, v0, s0), ijkVecMul2fvs(tmp, v1, s1));
	}
	// vectors are parallel; just do lerp
	return ijkVecLerp2fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecReflectScale2fv(float2 v_out, float2 const v_in, float2 const v_nrm)
{
	// v' = v|n|^2 - 2dot(v, n)n
	f32 const d = flt_two * ijkVecDot2fv(v_in, v_nrm), lenSq = ijkVecLengthSq2fv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	return v_out;
}

ijk_inl floatv ijkVecUnitReflect2fv(float2 v_out, float2 const v_in, float2 const v_nrm)
{
	// v' = v - 2dot(v, n)n
	f32 const d = flt_two * ijkVecDot2fv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	return v_out;
}

ijk_inl floatv ijkVecReflect2fv(float2 v_out, float2 const v_in, float2 const v_nrm)
{
	// v' /= |n|^2
	//		= v - 2dot(v, n)n / |n|^2
	f32 const d = flt_two * ijkVecDot2fv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv2fv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	return v_out;
}

ijk_inl f32 ijkVecDistance2fv(float2 const v_lh, float2 const v_rh)
{
	float2 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
	};
	return ijkVecLength2fv(diff);
}

ijk_inl floatv ijkVecResize2fv(float2 v_out, float2 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInv2fv(v_in);
	return ijkVecMul2fvs(v_out, v_in, s);
}

ijk_inl floatv ijkVecResizeSafe2fv(float2 v_out, float2 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInvSafe2fv(v_in);
	return ijkVecMul2fvs(v_out, v_in, s);
}

ijk_inl f32 ijkVecCrossResize2fv(float2 const v_lh, float2 const v_rh, f32 const length)
{
	return (length * ijkVecCrossNormalize2fv(v_lh, v_rh));
}

ijk_inl f32 ijkVecCrossResizeSafe2fv(float2 const v_lh, float2 const v_rh, f32 const length)
{
	return (length * ijkVecCrossNormalizeSafe2fv(v_lh, v_rh));
}

ijk_inl floatv ijkVecNearest2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u)
{
	return ijkVecCopy2fv(v_out, (u < flt_half ? v0 : v1));
}

ijk_inl floatv ijkVecBinearest2fv(float2 v_out, float2 const v00, float2 const v01, float2 const v10, float2 const v11, f32 const u0, f32 const u1, f32 const u)
{
	return ijkVecCopy2fv(v_out, (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11));
}

ijk_inl floatv ijkVecRemap2fv(float2 v_out, float2 const v0_dst, float2 const v1_dst, float2 const v0_src, float2 const v1_src, float2 const v_src)
{
	v_out[0] = ijkInterpRemap_flt(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_flt(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	return v_out;
}

ijk_inl floatv ijkVecBezier0O2fv(float2 v_out, float2 const v0, f32 const u)
{
	return ijkVecCopy2fv(v_out, v0);
}

ijk_inl floatv ijkVecBezier1O2fv(float2 v_out, float2 const v0, float2 const v1, f32 const u)
{
	return ijkVecLerp2fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecBezier2O2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v2, f32 const u)
{
	float2 u0, u1;
	ijkVecBezier1O2fv(u0, v0, v1, u);
	ijkVecBezier1O2fv(u1, v1, v2, u);
	return ijkVecLerp2fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezier3O2fv(float2 v_out, float2 const v0, float2 const v1, float2 const v2, float2 const v3, f32 const u)
{
	float2 u0, u1;
	ijkVecBezier2O2fv(u0, v0, v1, v2, u);
	ijkVecBezier2O2fv(u1, v1, v2, v3, u);
	return ijkVecLerp2fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezierNO2fv(float2 v_out, float2 const v[], size const order, f32 const u)
{
	float2 u0, u1;
	if (order > 0)
		return ijkVecLerp2fv(v_out, ijkVecBezierNO2fv(u0, v + 0, order - 1, u), ijkVecBezierNO2fv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy2fv(v_out, *v);
}

ijk_inl floatv ijkVecCubicHermite2fv(float2 v_out, float2 const v0, float2 const dv0, float2 const v1, float2 const dv1, f32 const u)
{
	// v = [v0, dv0, v1, dv1] K (1, t, t2, t3)
	// K =	|  1  0 -3  2 |
	//		|  0  1 -2  1 |
	//		|  0  0  3 -2 |
	//		|  0  0 -1  1 |
	// K' =	| (1  0 -3  2).(1, t, t2, t3) |
	//		| (0  1 -2  1).(1, t, t2, t3) |
	//		| (0  0  3 -2).(1, t, t2, t3) |
	//		| (0  0 -1  1).(1, t, t2, t3) |
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	return v_out;
}

ijk_inl floatv ijkVecCubicHermiteHandles2fv(float2 v_out, float2 const v0, float2 const cv0, float2 const v1, float2 const cv1, f32 const u)
{
	// v = [v0, cv0, v1, cv1] K' (1, t, t2, t3)
	// K' =	|  1 -1 -1  1 |
	//		|  0  1 -2  1 |
	//		|  0  0  4 -3 |
	//		|  0  0 -1  1 |
	// K" =	| (1 -1 -1  1).(1, t, t2, t3) |
	//		| (0  1 -2  1).(1, t, t2, t3) |
	//		| (0  0  4 -3).(1, t, t2, t3) |
	//		| (0  0 -1  1).(1, t, t2, t3) |
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	return v_out;
}

ijk_inl floatv ijkVecCubicCatmullRom2fv(float2 v_out, float2 const vp, float2 const v0, float2 const v1, float2 const v2, f32 const u)
{
	// v = [vp, v0, v1, v2] K' (1, t, t2, t3)
	//		|  0 -1  2 -1 |
	// K' =	|  2  0 -5  3 |
	//		|  0  1  4 -3 |
	//		|  0  0 -1  1 | / 2
	//		| (0 -1  2 -1).(1/2, t/2, t2/2, t3/2) |
	// K' =	| (2  0 -5  3).(1/2, t/2, t2/2, t3/2) |
	//		| (0  1  4 -3).(1/2, t/2, t2/2, t3/2) |
	//		| (0  0 -1  1).(1/2, t/2, t2/2, t3/2) |
	f32 const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	float4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	return v_out;
}

ijk_inl floatv ijkVecBicubicCatmullRom2fv(float2 v_out, float2 const vpp, float2 const vp0, float2 const vp1, float2 const vp2, float2 const v0p, float2 const v00, float2 const v01, float2 const v02, float2 const v1p, float2 const v10, float2 const v11, float2 const v12, float2 const v2p, float2 const v20, float2 const v21, float2 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u)
{
	float2 vp, v0, v1, v2;
	ijkVecCubicCatmullRom2fv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom2fv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom2fv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom2fv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom2fv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f32 ijkVecReparamCubicHermite2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, bool const lNormalize, float2 const v0, float2 const dv0, float2 const v1, float2 const dv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite2fv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance2fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicHermiteHandles2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, bool const lNormalize, float2 const v0, float2 const cv0, float2 const v1, float2 const cv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles2fv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance2fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicCatmullRom2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, bool const lNormalize, float2 const vp, float2 const v0, float2 const v1, float2 const v2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom2fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamBicubicCatmullRom2fv(f32 uTable_out[], f32 lTable_out[], float2 vTable_out[], size const numDivisions, bool const lNormalize, float2 const vpp, float2 const vp0, float2 const vp1, float2 const vp2, float2 const v0p, float2 const v00, float2 const v01, float2 const v02, float2 const v1p, float2 const v10, float2 const v11, float2 const v12, float2 const v2p, float2 const v20, float2 const v21, float2 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		float2 vp, v0, v1, v2;
		ijkVecCubicCatmullRom2fv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom2fv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom2fv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom2fv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy2fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom2fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl floatv ijkVecSampleTableInc2fv(float2 v_out, f32 const uTable[], float2 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp2fv(v_out, v0, v1, uReparam);
}

ijk_inl floatv ijkVecSampleTableDec2fv(float2 v_out, f32 const uTable[], float2 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp2fv(v_out, v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl f32 ijkVecLengthSq3fv(float3 const v_in)
{
	return ijkVecDot3fv(v_in, v_in);
}

ijk_inl f32 ijkVecLength3fv(float3 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq3fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInv3fv(float3 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq3fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInvSafe3fv(float3 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq3fv(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl f32 ijkVecLengthInv3fv(float3 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq3fv(v_in));
}

ijk_inl f32 ijkVecLengthInvSafe3fv(float3 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq3fv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl floatv ijkVecNormalize3fv(float3 v_out, float3 const v_in)
{
	return ijkVecMul3fvs(v_out, v_in, ijkVecLengthInv3fv(v_in));
}

ijk_inl floatv ijkVecNormalizeSafe3fv(float3 v_out, float3 const v_in)
{
	return ijkVecMul3fvs(v_out, v_in, ijkVecLengthInvSafe3fv(v_in));
}

ijk_inl floatv ijkVecNormalizeGetLength3fv(float3 v_out, float3 const v_in, f32* const length_out)
{
	return ijkVecDiv3fvs(v_out, v_in, (*length_out = ijkVecLength3fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLength3fv(float3 v_out, float3 const v_in, f32* const length_out)
{
	return ijkVecDivSafe3fvs(v_out, v_in, (*length_out = ijkVecLength3fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeGetLengthInv3fv(float3 v_out, float3 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul3fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv3fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLengthInv3fv(float3 v_out, float3 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul3fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe3fv(v_in)));
}

ijk_inl floatv ijkVecCrossNormalize3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalize3fv(v_out, v_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafe3fv(v_out, v_out);
}

ijk_inl floatv ijkVecCrossNormalizeGetLength3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const length_out)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLength3fv(v_out, v_out, length_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafeGetLength3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const length_out)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLength3fv(v_out, v_out, length_out);
}

ijk_inl floatv ijkVecCrossNormalizeGetLengthInv3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const lengthInv_out)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLengthInv3fv(v_out, v_out, lengthInv_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafeGetLengthInv3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32* const lengthInv_out)
{
	ijkVecCross3fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLengthInv3fv(v_out, v_out, lengthInv_out);
}

ijk_inl floatv ijkVecLerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u)
{
	v_out[0] = ijkInterpLinear_flt(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_flt(v0[1], v1[1], u);
	v_out[2] = ijkInterpLinear_flt(v0[2], v1[2], u);
	return v_out;
}

ijk_inl floatv ijkVecLerpInv3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_flt(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_flt(v0[1], v1[1], v_lerp[1]);
	v_out[2] = ijkInterpLinearInv_flt(v0[2], v1[2], v_lerp[2]);
	return v_out;
}

ijk_inl floatv ijkVecLerpRevInit3fv(float3 v0_out, float3 const v_lerp, float3 const v1, f32 const u)
{
	f32 const s = ijk_recip_flt(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	v0_out[2] = (v_lerp[2] - v1[2] * u) * s;
	return v0_out;
}

ijk_inl floatv ijkVecLerpRevTerm3fv(float3 v1_out, float3 const v0, float3 const v_lerp, f32 const u)
{
	return ijkVecLerp3fv(v1_out, v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl f32 ijkVecProjRatio3fv(float3 const v_base, float3 const v_in)
{
	return (ijkVecDot3fv(v_base, v_in) / ijkVecLengthSq3fv(v_base));
}

ijk_inl floatv ijkVecProj3fv(float3 v_out, float3 const v_base, float3 const v_in)
{
	return ijkVecMul3fvs(v_out, v_base, ijkVecProjRatio3fv(v_base, v_in));
}

ijk_inl floatv ijkVecOrtho3fv(float3 v_out, float3 const v_base, float3 const v_in)
{
	float3 ortho;
	return ijkVecSub3fv(v_out, v_in, ijkVecProj3fv(ortho, v_base, v_in));
}

ijk_inl floatv ijkVecOrthoNorm3fv(float3 v_out, float3 const v_base, float3 const v_in, float3 v_base_norm_out)
{
	float3 ortho;
	ijkVecNormalize3fv(v_base_norm_out, v_base);
	ijkVecSub3fv(v_out, v_in, ijkVecMul3fvs(ortho, v_base_norm_out, ijkVecDot3fv(v_base_norm_out, v_in)));
	return ijkVecNormalize3fv(v_out, v_out);
}

ijk_inl float3* ijkVecOrthoList3fv(float3 vl_out[], float3 const v_base, float3 const vl_in[], size const n)
{
	float3 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj3fv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd3fv(orthoSum, orthoSum, ijkVecProj3fv(ortho, vl_out[j], vp_in));
		ijkVecSub3fv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl float3* ijkVecOrthoNormList3fv(float3 vl_out[], float3 const v_base, float3 const vl_in[], size const n, float3 v_base_norm_out)
{
	float3 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	ijkVecNormalize3fv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul3fvs(ortho, v_base_norm_out, ijkVecDot3fv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd3fv(orthoSum, orthoSum, ijkVecMul3fvs(ortho, vl_out[j], ijkVecDot3fv(vl_out[j], vp_in)));
		ijkVecSub3fv(vp_out, vp_in, orthoSum);
		ijkVecNormalize3fv(vp_out, vp_out);
	}
	return vl_out;
}

ijk_inl floatv ijkVecNlerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u)
{
	ijkVecLerp3fv(v_out, v0, v1, u);
	return ijkVecNormalize3fv(v_out, v_out);
}

ijk_inl floatv ijkVecSlerp3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u)
{
	f32 const dot = ijkVecDot3fv(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float3 tmp;
		f32 const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd3fv(v_out, ijkVecMul3fvs(v_out, v0, s0), ijkVecMul3fvs(tmp, v1, s1));
	}
	return ijkVecLerp3fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecReflectScale3fv(float3 v_out, float3 const v_in, float3 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot3fv(v_in, v_nrm), lenSq = ijkVecLengthSq3fv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	v_out[2] = v_in[2] * lenSq - d * v_nrm[2];
	return v_out;
}

ijk_inl floatv ijkVecUnitReflect3fv(float3 v_out, float3 const v_in, float3 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot3fv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	v_out[2] = v_in[2] - d * v_nrm[2];
	return v_out;
}

ijk_inl floatv ijkVecReflect3fv(float3 v_out, float3 const v_in, float3 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot3fv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv3fv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	v_out[2] = v_in[2] - lenSqInv * v_nrm[2];
	return v_out;
}

ijk_inl f32 ijkVecDistance3fv(float3 const v_lh, float3 const v_rh)
{
	float3 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
		(v_lh[2] - v_rh[2]),
	};
	return ijkVecLength3fv(diff);
}

ijk_inl floatv ijkVecResize3fv(float3 v_out, float3 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInv3fv(v_in);
	return ijkVecMul3fvs(v_out, v_in, s);
}

ijk_inl floatv ijkVecResizeSafe3fv(float3 v_out, float3 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInvSafe3fv(v_in);
	return ijkVecMul3fvs(v_out, v_in, s);
}

ijk_inl floatv ijkVecCrossResize3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32 const length)
{
	f32 const s = length * ijkVecLengthInv3fv(ijkVecCross3fv(v_out, v_lh, v_rh));
	return ijkVecMul3fvs(v_out, v_out, s);
}

ijk_inl floatv ijkVecCrossResizeSafe3fv(float3 v_out, float3 const v_lh, float3 const v_rh, f32 const length)
{
	f32 const s = length * ijkVecLengthInvSafe3fv(ijkVecCross3fv(v_out, v_lh, v_rh));
	return ijkVecMul3fvs(v_out, v_out, s);
}

ijk_inl floatv ijkVecNearest3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u)
{
	return ijkVecCopy3fv(v_out, (u < flt_half ? v0 : v1));
}

ijk_inl floatv ijkVecBinearest3fv(float3 v_out, float3 const v00, float3 const v01, float3 const v10, float3 const v11, f32 const u0, f32 const u1, f32 const u)
{
	return ijkVecCopy3fv(v_out, (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11));
}

ijk_inl floatv ijkVecRemap3fv(float3 v_out, float3 const v0_dst, float3 const v1_dst, float3 const v0_src, float3 const v1_src, float3 const v_src)
{
	v_out[0] = ijkInterpRemap_flt(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_flt(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	v_out[2] = ijkInterpRemap_flt(v0_dst[2], v1_dst[2], v0_src[2], v1_src[2], v_src[2]);
	return v_out;
}

ijk_inl floatv ijkVecBezier0O3fv(float3 v_out, float3 const v0, f32 const u)
{
	return ijkVecCopy3fv(v_out, v0);
}

ijk_inl floatv ijkVecBezier1O3fv(float3 v_out, float3 const v0, float3 const v1, f32 const u)
{
	return ijkVecLerp3fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecBezier2O3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v2, f32 const u)
{
	float3 u0, u1;
	ijkVecBezier1O3fv(u0, v0, v1, u);
	ijkVecBezier1O3fv(u1, v1, v2, u);
	return ijkVecLerp3fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezier3O3fv(float3 v_out, float3 const v0, float3 const v1, float3 const v2, float3 const v3, f32 const u)
{
	float3 u0, u1;
	ijkVecBezier2O3fv(u0, v0, v1, v2, u);
	ijkVecBezier2O3fv(u1, v1, v2, v3, u);
	return ijkVecLerp3fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezierNO3fv(float3 v_out, float3 const v[], size const order, f32 const u)
{
	float3 u0, u1;
	if (order > 0)
		return ijkVecLerp3fv(v_out, ijkVecBezierNO3fv(u0, v + 0, order - 1, u), ijkVecBezierNO3fv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy3fv(v_out, *v);
}

ijk_inl floatv ijkVecCubicHermite3fv(float3 v_out, float3 const v0, float3 const dv0, float3 const v1, float3 const dv1, f32 const u)
{
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * dv0[2] + k[2] * v1[2] + k[3] * dv1[2]);
	return v_out;
}

ijk_inl floatv ijkVecCubicHermiteHandles3fv(float3 v_out, float3 const v0, float3 const cv0, float3 const v1, float3 const cv1, f32 const u)
{
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * cv0[2] + k[2] * v1[2] + k[3] * cv1[2]);
	return v_out;
}

ijk_inl floatv ijkVecCubicCatmullRom3fv(float3 v_out, float3 const vp, float3 const v0, float3 const v1, float3 const v2, f32 const u)
{
	f32 const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	float4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	v_out[2] = (k[0] * vp[2] + k[1] * v0[2] + k[2] * v1[2] + k[3] * v2[2]);
	return v_out;
}

ijk_inl floatv ijkVecBicubicCatmullRom3fv(float3 v_out, float3 const vpp, float3 const vp0, float3 const vp1, float3 const vp2, float3 const v0p, float3 const v00, float3 const v01, float3 const v02, float3 const v1p, float3 const v10, float3 const v11, float3 const v12, float3 const v2p, float3 const v20, float3 const v21, float3 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u)
{
	float3 vp, v0, v1, v2;
	ijkVecCubicCatmullRom3fv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom3fv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom3fv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom3fv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom3fv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f32 ijkVecReparamCubicHermite3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, bool const lNormalize, float3 const v0, float3 const dv0, float3 const v1, float3 const dv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite3fv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance3fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicHermiteHandles3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, bool const lNormalize, float3 const v0, float3 const cv0, float3 const v1, float3 const cv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles3fv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance3fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicCatmullRom3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, bool const lNormalize, float3 const vp, float3 const v0, float3 const v1, float3 const v2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom3fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamBicubicCatmullRom3fv(f32 uTable_out[], f32 lTable_out[], float3 vTable_out[], size const numDivisions, bool const lNormalize, float3 const vpp, float3 const vp0, float3 const vp1, float3 const vp2, float3 const v0p, float3 const v00, float3 const v01, float3 const v02, float3 const v1p, float3 const v10, float3 const v11, float3 const v12, float3 const v2p, float3 const v20, float3 const v21, float3 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		float3 vp, v0, v1, v2;
		ijkVecCubicCatmullRom3fv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom3fv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom3fv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom3fv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy3fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom3fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl floatv ijkVecSampleTableInc3fv(float3 v_out, f32 const uTable[], float3 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp3fv(v_out, v0, v1, uReparam);
}

ijk_inl floatv ijkVecSampleTableDec3fv(float3 v_out, f32 const uTable[], float3 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp3fv(v_out, v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl f32 ijkVecLengthSq4fv(float4 const v_in)
{
	return ijkVecDot4fv(v_in, v_in);
}

ijk_inl f32 ijkVecLength4fv(float4 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq4fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInv4fv(float4 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq4fv(v_in));
}

ijk_inl f32 ijkVecLengthSqInvSafe4fv(float4 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq4fv(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl f32 ijkVecLengthInv4fv(float4 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq4fv(v_in));
}

ijk_inl f32 ijkVecLengthInvSafe4fv(float4 const v_in)
{
	f32 const lengthSq = ijkVecLengthSq4fv(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl floatv ijkVecNormalize4fv(float4 v_out, float4 const v_in)
{
	return ijkVecMul4fvs(v_out, v_in, ijkVecLengthInv4fv(v_in));
}

ijk_inl floatv ijkVecNormalizeSafe4fv(float4 v_out, float4 const v_in)
{
	return ijkVecMul4fvs(v_out, v_in, ijkVecLengthInvSafe4fv(v_in));
}

ijk_inl floatv ijkVecNormalizeGetLength4fv(float4 v_out, float4 const v_in, f32* const length_out)
{
	return ijkVecDiv4fvs(v_out, v_in, (*length_out = ijkVecLength4fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLength4fv(float4 v_out, float4 const v_in, f32* const length_out)
{
	return ijkVecDivSafe4fvs(v_out, v_in, (*length_out = ijkVecLength4fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeGetLengthInv4fv(float4 v_out, float4 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul4fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInv4fv(v_in)));
}

ijk_inl floatv ijkVecNormalizeSafeGetLengthInv4fv(float4 v_out, float4 const v_in, f32* const lengthInv_out)
{
	return ijkVecMul4fvs(v_out, v_in, (*lengthInv_out = ijkVecLengthInvSafe4fv(v_in)));
}

ijk_inl floatv ijkVecCrossNormalize4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalize3fv(v_out, v_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafe3fv(v_out, v_out);
}

ijk_inl floatv ijkVecCrossNormalizeGetLength4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const length_out)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLength3fv(v_out, v_out, length_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafeGetLength4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const length_out)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLength3fv(v_out, v_out, length_out);
}

ijk_inl floatv ijkVecCrossNormalizeGetLengthInv4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const lengthInv_out)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeGetLengthInv3fv(v_out, v_out, lengthInv_out);
}

ijk_inl floatv ijkVecCrossNormalizeSafeGetLengthInv4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32* const lengthInv_out)
{
	ijkVecCross4fv(v_out, v_lh, v_rh);
	return ijkVecNormalizeSafeGetLengthInv3fv(v_out, v_out, lengthInv_out);
}

ijk_inl floatv ijkVecLerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u)
{
	v_out[0] = ijkInterpLinear_flt(v0[0], v1[0], u);
	v_out[1] = ijkInterpLinear_flt(v0[1], v1[1], u);
	v_out[2] = ijkInterpLinear_flt(v0[2], v1[2], u);
	v_out[3] = ijkInterpLinear_flt(v0[3], v1[3], u);
	return v_out;
}

ijk_inl floatv ijkVecLerpInv4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v_lerp)
{
	v_out[0] = ijkInterpLinearInv_flt(v0[0], v1[0], v_lerp[0]);
	v_out[1] = ijkInterpLinearInv_flt(v0[1], v1[1], v_lerp[1]);
	v_out[2] = ijkInterpLinearInv_flt(v0[2], v1[2], v_lerp[2]);
	v_out[3] = ijkInterpLinearInv_flt(v0[3], v1[3], v_lerp[3]);
	return v_out;
}

ijk_inl floatv ijkVecLerpRevInit4fv(float4 v0_out, float4 const v_lerp, float4 const v1, f32 const u)
{
	f32 const s = ijk_recip_flt(flt_one - u);
	v0_out[0] = (v_lerp[0] - v1[0] * u) * s;
	v0_out[1] = (v_lerp[1] - v1[1] * u) * s;
	v0_out[2] = (v_lerp[2] - v1[2] * u) * s;
	v0_out[3] = (v_lerp[3] - v1[3] * u) * s;
	return v0_out;
}

ijk_inl floatv ijkVecLerpRevTerm4fv(float4 v1_out, float4 const v0, float4 const v_lerp, f32 const u)
{
	return ijkVecLerp4fv(v1_out, v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl f32 ijkVecProjRatio4fv(float4 const v_base, float4 const v_in)
{
	return (ijkVecDot4fv(v_base, v_in) / ijkVecLengthSq4fv(v_base));
}

ijk_inl floatv ijkVecProj4fv(float4 v_out, float4 const v_base, float4 const v_in)
{
	return ijkVecMul4fvs(v_out, v_base, ijkVecProjRatio4fv(v_base, v_in));
}

ijk_inl floatv ijkVecOrtho4fv(float4 v_out, float4 const v_base, float4 const v_in)
{
	float4 ortho;
	return ijkVecSub4fv(v_out, v_in, ijkVecProj4fv(ortho, v_base, v_in));
}

ijk_inl floatv ijkVecOrthoNorm4fv(float4 v_out, float4 const v_base, float4 const v_in, float4 v_base_norm_out)
{
	float4 ortho;
	ijkVecNormalize4fv(v_base_norm_out, v_base);
	ijkVecSub4fv(v_out, v_in, ijkVecMul4fvs(ortho, v_base_norm_out, ijkVecDot4fv(v_base_norm_out, v_in)));
	return ijkVecNormalize4fv(v_out, v_out);
}

ijk_inl float4* ijkVecOrthoList4fv(float4 vl_out[], float4 const v_base, float4 const vl_in[], size const n)
{
	float4 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecProj4fv(orthoSum, v_base, vp_in);
		for (j = 0; j < i; ++j)
			ijkVecAdd4fv(orthoSum, orthoSum, ijkVecProj4fv(ortho, vl_out[j], vp_in));
		ijkVecSub4fv(vp_out, vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl float4* ijkVecOrthoNormList4fv(float4 vl_out[], float4 const v_base, float4 const vl_in[], size const n, float4 v_base_norm_out)
{
	float4 ortho, orthoSum;
	floatv vp_out;
	floatkv vp_in;
	uindex i, j;
	ijkVecNormalize4fv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul4fvs(ortho, v_base_norm_out, ijkVecDot4fv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
			ijkVecAdd4fv(orthoSum, orthoSum, ijkVecMul4fvs(ortho, vl_out[j], ijkVecDot4fv(vl_out[j], vp_in)));
		ijkVecSub4fv(vp_out, vp_in, orthoSum);
		ijkVecNormalize4fv(vp_out, vp_out);
	}
	return vl_out;
}

ijk_inl floatv ijkVecNlerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u)
{
	ijkVecLerp4fv(v_out, v0, v1, u);
	return ijkVecNormalize4fv(v_out, v_out);
}

ijk_inl floatv ijkVecSlerp4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u)
{
	f32 const dot = ijkVecDot4fv(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float4 tmp;
		f32 const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd4fv(v_out, ijkVecMul4fvs(v_out, v0, s0), ijkVecMul4fvs(tmp, v1, s1));
	}
	return ijkVecLerp4fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecReflectScale4fv(float4 v_out, float4 const v_in, float4 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot4fv(v_in, v_nrm), lenSq = ijkVecLengthSq4fv(v_nrm);
	v_out[0] = v_in[0] * lenSq - d * v_nrm[0];
	v_out[1] = v_in[1] * lenSq - d * v_nrm[1];
	v_out[2] = v_in[2] * lenSq - d * v_nrm[2];
	v_out[3] = v_in[3] * lenSq - d * v_nrm[3];
	return v_out;
}

ijk_inl floatv ijkVecUnitReflect4fv(float4 v_out, float4 const v_in, float4 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot4fv(v_in, v_nrm);
	v_out[0] = v_in[0] - d * v_nrm[0];
	v_out[1] = v_in[1] - d * v_nrm[1];
	v_out[2] = v_in[2] - d * v_nrm[2];
	v_out[3] = v_in[3] - d * v_nrm[3];
	return v_out;
}

ijk_inl floatv ijkVecReflect4fv(float4 v_out, float4 const v_in, float4 const v_nrm)
{
	f32 const d = flt_two * ijkVecDot4fv(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv4fv(v_nrm);
	v_out[0] = v_in[0] - lenSqInv * v_nrm[0];
	v_out[1] = v_in[1] - lenSqInv * v_nrm[1];
	v_out[2] = v_in[2] - lenSqInv * v_nrm[2];
	v_out[3] = v_in[3] - lenSqInv * v_nrm[3];
	return v_out;
}

ijk_inl f32 ijkVecDistance4fv(float4 const v_lh, float4 const v_rh)
{
	float4 const diff = {
		(v_lh[0] - v_rh[0]),
		(v_lh[1] - v_rh[1]),
		(v_lh[2] - v_rh[2]),
		(v_lh[3] - v_rh[3]),
	};
	return ijkVecLength4fv(diff);
}

ijk_inl floatv ijkVecResize4fv(float4 v_out, float4 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInv4fv(v_in);
	return ijkVecMul4fvs(v_out, v_in, s);
}

ijk_inl floatv ijkVecResizeSafe4fv(float4 v_out, float4 const v_in, f32 const length)
{
	f32 const s = length * ijkVecLengthInvSafe4fv(v_in);
	return ijkVecMul4fvs(v_out, v_in, s);
}

ijk_inl floatv ijkVecCrossResize4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32 const length)
{
	f32 const s = length * ijkVecLengthInv3fv(ijkVecCross4fv(v_out, v_lh, v_rh));
	return ijkVecMul3fvs(v_out, v_out, s);
}

ijk_inl floatv ijkVecCrossResizeSafe4fv(float4 v_out, float4 const v_lh, float4 const v_rh, f32 const length)
{
	f32 const s = length * ijkVecLengthInvSafe3fv(ijkVecCross4fv(v_out, v_lh, v_rh));
	return ijkVecMul3fvs(v_out, v_out, s);
}

ijk_inl floatv ijkVecNearest4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u)
{
	return ijkVecCopy4fv(v_out, (u < flt_half ? v0 : v1));
}

ijk_inl floatv ijkVecBinearest4fv(float4 v_out, float4 const v00, float4 const v01, float4 const v10, float4 const v11, f32 const u0, f32 const u1, f32 const u)
{
	return ijkVecCopy4fv(v_out, (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11));
}

ijk_inl floatv ijkVecRemap4fv(float4 v_out, float4 const v0_dst, float4 const v1_dst, float4 const v0_src, float4 const v1_src, float4 const v_src)
{
	v_out[0] = ijkInterpRemap_flt(v0_dst[0], v1_dst[0], v0_src[0], v1_src[0], v_src[0]);
	v_out[1] = ijkInterpRemap_flt(v0_dst[1], v1_dst[1], v0_src[1], v1_src[1], v_src[1]);
	v_out[2] = ijkInterpRemap_flt(v0_dst[2], v1_dst[2], v0_src[2], v1_src[2], v_src[2]);
	v_out[3] = ijkInterpRemap_flt(v0_dst[3], v1_dst[3], v0_src[3], v1_src[3], v_src[3]);
	return v_out;
}

ijk_inl floatv ijkVecBezier0O4fv(float4 v_out, float4 const v0, f32 const u)
{
	return ijkVecCopy4fv(v_out, v0);
}

ijk_inl floatv ijkVecBezier1O4fv(float4 v_out, float4 const v0, float4 const v1, f32 const u)
{
	return ijkVecLerp4fv(v_out, v0, v1, u);
}

ijk_inl floatv ijkVecBezier2O4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v2, f32 const u)
{
	float4 u0, u1;
	ijkVecBezier1O4fv(u0, v0, v1, u);
	ijkVecBezier1O4fv(u1, v1, v2, u);
	return ijkVecLerp4fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezier3O4fv(float4 v_out, float4 const v0, float4 const v1, float4 const v2, float4 const v3, f32 const u)
{
	float4 u0, u1;
	ijkVecBezier2O4fv(u0, v0, v1, v2, u);
	ijkVecBezier2O4fv(u1, v1, v2, v3, u);
	return ijkVecLerp4fv(v_out, u0, u1, u);
}

ijk_inl floatv ijkVecBezierNO4fv(float4 v_out, float4 const v[], size const order, f32 const u)
{
	float4 u0, u1;
	if (order > 0)
		return ijkVecLerp4fv(v_out, ijkVecBezierNO4fv(u0, v + 0, order - 1, u), ijkVecBezierNO4fv(u1, v + 1, order - 1, u), u);
	return ijkVecCopy4fv(v_out, *v);
}

ijk_inl floatv ijkVecCubicHermite4fv(float4 v_out, float4 const v0, float4 const dv0, float4 const v1, float4 const dv1, f32 const u)
{
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * dv0[0] + k[2] * v1[0] + k[3] * dv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * dv0[1] + k[2] * v1[1] + k[3] * dv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * dv0[2] + k[2] * v1[2] + k[3] * dv1[2]);
	v_out[3] = (k[0] * v0[3] + k[1] * dv0[3] + k[2] * v1[3] + k[3] * dv1[3]);
	return v_out;
}

ijk_inl floatv ijkVecCubicHermiteHandles4fv(float4 v_out, float4 const v0, float4 const cv0, float4 const v1, float4 const cv1, f32 const u)
{
	f32 const u2 = u * u, u3 = u * u2;
	float4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	v_out[0] = (k[0] * v0[0] + k[1] * cv0[0] + k[2] * v1[0] + k[3] * cv1[0]);
	v_out[1] = (k[0] * v0[1] + k[1] * cv0[1] + k[2] * v1[1] + k[3] * cv1[1]);
	v_out[2] = (k[0] * v0[2] + k[1] * cv0[2] + k[2] * v1[2] + k[3] * cv1[2]);
	v_out[3] = (k[0] * v0[3] + k[1] * cv0[3] + k[2] * v1[3] + k[3] * cv1[3]);
	return v_out;
}

ijk_inl floatv ijkVecCubicCatmullRom4fv(float4 v_out, float4 const vp, float4 const v0, float4 const v1, float4 const v2, f32 const u)
{
	f32 const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	float4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	v_out[0] = (k[0] * vp[0] + k[1] * v0[0] + k[2] * v1[0] + k[3] * v2[0]);
	v_out[1] = (k[0] * vp[1] + k[1] * v0[1] + k[2] * v1[1] + k[3] * v2[1]);
	v_out[2] = (k[0] * vp[2] + k[1] * v0[2] + k[2] * v1[2] + k[3] * v2[2]);
	v_out[3] = (k[0] * vp[3] + k[1] * v0[3] + k[2] * v1[3] + k[3] * v2[3]);
	return v_out;
}

ijk_inl floatv ijkVecBicubicCatmullRom4fv(float4 v_out, float4 const vpp, float4 const vp0, float4 const vp1, float4 const vp2, float4 const v0p, float4 const v00, float4 const v01, float4 const v02, float4 const v1p, float4 const v10, float4 const v11, float4 const v12, float4 const v2p, float4 const v20, float4 const v21, float4 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2, f32 const u)
{
	float4 vp, v0, v1, v2;
	ijkVecCubicCatmullRom4fv(vp, vpp, vp0, vp1, vp2, up);
	ijkVecCubicCatmullRom4fv(v0, v0p, v00, v01, v02, u0);
	ijkVecCubicCatmullRom4fv(v1, v1p, v10, v11, v12, u1);
	ijkVecCubicCatmullRom4fv(v2, v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom4fv(v_out, vp, v0, v1, v2, u);
}

ijk_inl f32 ijkVecReparamCubicHermite4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, bool const lNormalize, float4 const v0, float4 const dv0, float4 const v1, float4 const dv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite4fv(*(++vTable_out), v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance4fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicHermiteHandles4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, bool const lNormalize, float4 const v0, float4 const cv0, float4 const v1, float4 const cv1)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles4fv(*(++vTable_out), v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance4fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamCubicCatmullRom4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, bool const lNormalize, float4 const vp, float4 const v0, float4 const v1, float4 const v2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom4fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl f32 ijkVecReparamBicubicCatmullRom4fv(f32 uTable_out[], f32 lTable_out[], float4 vTable_out[], size const numDivisions, bool const lNormalize, float4 const vpp, float4 const vp0, float4 const vp1, float4 const vp2, float4 const v0p, float4 const v00, float4 const v01, float4 const v02, float4 const v1p, float4 const v10, float4 const v11, float4 const v12, float4 const v2p, float4 const v20, float4 const v21, float4 const v22, f32 const up, f32 const u0, f32 const u1, f32 const u2)
{
	f32 u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	f32* lTable = lTable_out;
	uindex i;
	floatkv v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		float4 vp, v0, v1, v2;
		ijkVecCubicCatmullRom4fv(vp, vpp, vp0, vp1, vp2, up);
		ijkVecCubicCatmullRom4fv(v0, v0p, v00, v01, v02, u0);
		ijkVecCubicCatmullRom4fv(v1, v1p, v10, v11, v12, u1);
		ijkVecCubicCatmullRom4fv(v2, v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		vc = ijkVecCopy4fv(*vTable_out, v0);

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom4fv(*(++vTable_out), vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4fv(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl floatv ijkVecSampleTableInc4fv(float4 v_out, f32 const uTable[], float4 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp4fv(v_out, v0, v1, uReparam);
}

ijk_inl floatv ijkVecSampleTableDec4fv(float4 v_out, f32 const uTable[], float4 const vTable[], index i, index di, f32 const u)
{
	floatkv v0, v1;
	f32 uReparam;
	f32 u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp4fv(v_out, v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl float ijkVecLengthSq2f(fvec2 const v_in)
{
	return ijkVecDot2f(v_in, v_in);
}

ijk_inl float ijkVecLength2f(fvec2 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq2f(v_in));
}

ijk_inl float ijkVecLengthSqInv2f(fvec2 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq2f(v_in));
}

ijk_inl float ijkVecLengthSqInvSafe2f(fvec2 const v_in)
{
	float const lengthSq = ijkVecLengthSq2f(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl float ijkVecLengthInv2f(fvec2 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq2f(v_in));
}

ijk_inl float ijkVecLengthInvSafe2f(fvec2 const v_in)
{
	float const lengthSq = ijkVecLengthSq2f(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl fvec2 ijkVecNormalize2f(fvec2 const v_in)
{
	return ijkVecMul2fs(v_in, ijkVecLengthInv2f(v_in));
}

ijk_inl fvec2 ijkVecNormalizeSafe2f(fvec2 const v_in)
{
	return ijkVecMul2fs(v_in, ijkVecLengthInvSafe2f(v_in));
}

ijk_inl fvec2 ijkVecNormalizeGetLength2f(fvec2 const v_in, float* const length_out)
{
	return ijkVecDiv2fs(v_in, (*length_out = ijkVecLength2f(v_in)));
}

ijk_inl fvec2 ijkVecNormalizeSafeGetLength2f(fvec2 const v_in, float* const length_out)
{
	return ijkVecDivSafe2fs(v_in, (*length_out = ijkVecLength2f(v_in)));
}

ijk_inl fvec2 ijkVecNormalizeGetLengthInv2f(fvec2 const v_in, float* const lengthInv_out)
{
	return ijkVecMul2fs(v_in, (*lengthInv_out = ijkVecLengthInv2f(v_in)));
}

ijk_inl fvec2 ijkVecNormalizeSafeGetLengthInv2f(fvec2 const v_in, float* const lengthInv_out)
{
	return ijkVecMul2fs(v_in, (*lengthInv_out = ijkVecLengthInvSafe2f(v_in)));
}

ijk_inl float ijkVecCrossNormalize2f(fvec2 const v_lh, fvec2 const v_rh)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	return ijk_sgn_flt(cross);
}

ijk_inl float ijkVecCrossNormalizeSafe2f(fvec2 const v_lh, fvec2 const v_rh)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	return ijk_sgn_flt(cross);
}

ijk_inl float ijkVecCrossNormalizeGetLength2f(fvec2 const v_lh, fvec2 const v_rh, float* const length_out)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	*length_out = ijk_abs_flt(cross);
	return ijk_sgn_flt(cross);
}

ijk_inl float ijkVecCrossNormalizeSafeGetLength2f(fvec2 const v_lh, fvec2 const v_rh, float* const length_out)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	*length_out = ijk_abs_flt(cross);
	return ijk_sgn_flt(cross);
}

ijk_inl float ijkVecCrossNormalizeGetLengthInv2f(fvec2 const v_lh, fvec2 const v_rh, float* const lengthInv_out)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	float const length = ijk_abs_flt(cross);
	*lengthInv_out = ijk_recip_flt(length);
	return ijk_sgn_flt(cross);
}

ijk_inl float ijkVecCrossNormalizeSafeGetLengthInv2f(fvec2 const v_lh, fvec2 const v_rh, float* const lengthInv_out)
{
	float const cross = ijkVecCross2f(v_lh, v_rh);
	float const length = ijk_abs_flt(cross);
	*lengthInv_out = ijk_recip_safe_flt(length);
	return ijk_sgn_flt(cross);
}

ijk_inl fvec2 ijkVecLerp2f(fvec2 const v0, fvec2 const v1, float const u)
{
	fvec2 const v_out = {
		ijkInterpLinear_flt(v0.x, v1.x, u),
		ijkInterpLinear_flt(v0.y, v1.y, u),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecLerpInv2f(fvec2 const v0, fvec2 const v1, fvec2 const v_lerp)
{
	fvec2 const v_out = {
		ijkInterpLinearInv_flt(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_flt(v0.y, v1.y, v_lerp.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecLerpRevInit2f(fvec2 const v_lerp, fvec2 const v1, float const u)
{
	float const s = ijk_recip_flt(flt_one - u);
	fvec2 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u) * s,
	};
	return v0_out;
}

ijk_inl fvec2 ijkVecLerpRevTerm2f(fvec2 const v0, fvec2 const v_lerp, float const u)
{
	return ijkVecLerp2f(v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl float ijkVecProjRatio2f(fvec2 const v_base, fvec2 const v_in)
{
	return (ijkVecDot2f(v_base, v_in) / ijkVecLengthSq2f(v_base));
}

ijk_inl fvec2 ijkVecProj2f(fvec2 const v_base, fvec2 const v_in)
{
	return ijkVecMul2fs(v_base, ijkVecProjRatio2f(v_base, v_in));
}

ijk_inl fvec2 ijkVecOrtho2f(fvec2 const v_base, fvec2 const v_in)
{
	return ijkVecSub2f(v_in, ijkVecProj2f(v_base, v_in));
}

ijk_inl fvec2 ijkVecOrthoNorm2f(fvec2 const v_base, fvec2 const v_in, fvec2* const v_base_norm_out)
{
	fvec2 const v_base_norm = *v_base_norm_out = ijkVecNormalize2f(v_base);
	return ijkVecNormalize2f(ijkVecSub2f(v_in, ijkVecMul2fs(v_base_norm, ijkVecDot2f(v_base_norm, v_in))));
}

ijk_inl fvec2* ijkVecOrthoList2f(fvec2 vl_out[], fvec2 const v_base, fvec2 const vl_in[], size const n)
{
	fvec2 orthoSum;
	fvec2 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj2f(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd2f(orthoSum, ijkVecProj2f(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub2f(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl fvec2* ijkVecOrthoNormList2f(fvec2 vl_out[], fvec2 const v_base, fvec2 const vl_in[], size const n, fvec2* const v_base_norm_out)
{
	fvec2 orthoSum;
	fvec2 vp_in;
	uindex i, j;
	fvec2 const v_base_norm = *v_base_norm_out = ijkVecNormalize2f(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul2fs(v_base_norm, ijkVecDot2f(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd2f(orthoSum, ijkVecMul2fs(vl_out[j], ijkVecDot2f(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize2f(ijkVecSub2f(vp_in, orthoSum));
	}
	return vl_out;
}

ijk_inl fvec2 ijkVecNlerp2f(fvec2 const v0, fvec2 const v1, float const u)
{
	return ijkVecNormalize2f(ijkVecLerp2f(v0, v1, u));
}

ijk_inl fvec2 ijkVecSlerp2f(fvec2 const v0, fvec2 const v1, float const u)
{
	float const dot = ijkVecDot2f(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd2f(ijkVecMul2fs(v0, s0), ijkVecMul2fs(v1, s1));
	}
	return ijkVecLerp2f(v0, v1, u);
}

ijk_inl fvec2 ijkVecReflectScale2f(fvec2 const v_in, fvec2 const v_nrm)
{
	float const d = flt_two * ijkVecDot2f(v_in, v_nrm), lenSq = ijkVecLengthSq2f(v_nrm);
	fvec2 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecUnitReflect2f(fvec2 const v_in, fvec2 const v_nrm)
{
	float const d = flt_two * ijkVecDot2f(v_in, v_nrm);
	fvec2 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecReflect2f(fvec2 const v_in, fvec2 const v_nrm)
{
	float const d = flt_two * ijkVecDot2f(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv2f(v_nrm);
	fvec2 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
	};
	return v_out;
}

ijk_inl float ijkVecDistance2f(fvec2 const v_lh, fvec2 const v_rh)
{
	fvec2 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
	};
	return ijkVecLength2f(diff);
}

ijk_inl fvec2 ijkVecResize2f(fvec2 const v_in, float const length)
{
	float const s = length * ijkVecLengthInv2f(v_in);
	return ijkVecMul2fs(v_in, s);
}

ijk_inl fvec2 ijkVecResizeSafe2f(fvec2 const v_in, float const length)
{
	float const s = length * ijkVecLengthInvSafe2f(v_in);
	return ijkVecMul2fs(v_in, s);
}

ijk_inl float ijkVecCrossResize2f(fvec2 const v_lh, fvec2 const v_rh, float const length)
{
	return (length * ijkVecCrossNormalize2f(v_lh, v_rh));
}

ijk_inl float ijkVecCrossResizeSafe2f(fvec2 const v_lh, fvec2 const v_rh, float const length)
{
	return (length * ijkVecCrossNormalizeSafe2f(v_lh, v_rh));
}

ijk_inl fvec2 ijkVecNearest2f(fvec2 const v0, fvec2 const v1, float const u)
{
	return (u < flt_half ? v0 : v1);
}

ijk_inl fvec2 ijkVecBinearest2f(fvec2 const v00, fvec2 const v01, fvec2 const v10, fvec2 const v11, float const u0, float const u1, float const u)
{
	return (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11);
}

ijk_inl fvec2 ijkVecRemap2f(fvec2 const v0_dst, fvec2 const v1_dst, fvec2 const v0_src, fvec2 const v1_src, fvec2 const v_src)
{
	fvec2 const v_out = {
		ijkInterpRemap_flt(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_flt(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecBezier0O2f(fvec2 const v0, float const u)
{
	return v0;
}

ijk_inl fvec2 ijkVecBezier1O2f(fvec2 const v0, fvec2 const v1, float const u)
{
	return ijkVecLerp2f(v0, v1, u);
}

ijk_inl fvec2 ijkVecBezier2O2f(fvec2 const v0, fvec2 const v1, fvec2 const v2, float const u)
{
	fvec2 const u0 = ijkVecBezier1O2f(v0, v1, u), u1 = ijkVecBezier1O2f(v1, v2, u);
	return ijkVecLerp2f(u0, u1, u);
}

ijk_inl fvec2 ijkVecBezier3O2f(fvec2 const v0, fvec2 const v1, fvec2 const v2, fvec2 const v3, float const u)
{
	fvec2 const u0 = ijkVecBezier2O2f(v0, v1, v2, u), u1 = ijkVecBezier2O2f(v1, v2, v3, u);
	return ijkVecLerp2f(u0, u1, u);
}

ijk_inl fvec2 ijkVecBezierNO2f(fvec2 const v[], size const order, float const u)
{
	if (order > 0)
	{
		fvec2 const u0 = ijkVecBezierNO2f(v + 0, order - 1, u), u1 = ijkVecBezierNO2f(v + 1, order - 1, u);
		return ijkVecLerp2f(u0, u1, u);
	}
	return *v;
}

ijk_inl fvec2 ijkVecCubicHermite2f(fvec2 const v0, fvec2 const dv0, fvec2 const v1, fvec2 const dv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	fvec2 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecCubicHermiteHandles2f(fvec2 const v0, fvec2 const cv0, fvec2 const v1, fvec2 const cv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	fvec2 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecCubicCatmullRom2f(fvec2 const vp, fvec2 const v0, fvec2 const v1, fvec2 const v2, float const u)
{
	float const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	fvec4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	fvec2 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
	};
	return v_out;
}

ijk_inl fvec2 ijkVecBicubicCatmullRom2f(fvec2 const vpp, fvec2 const vp0, fvec2 const vp1, fvec2 const vp2, fvec2 const v0p, fvec2 const v00, fvec2 const v01, fvec2 const v02, fvec2 const v1p, fvec2 const v10, fvec2 const v11, fvec2 const v12, fvec2 const v2p, fvec2 const v20, fvec2 const v21, fvec2 const v22, float const up, float const u0, float const u1, float const u2, float const u)
{
	fvec2 const vp = ijkVecCubicCatmullRom2f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom2f(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom2f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom2f(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom2f(vp, v0, v1, v2, u);
}

ijk_inl float ijkVecReparamCubicHermite2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, bool const lNormalize, fvec2 const v0, fvec2 const dv0, fvec2 const v1, fvec2 const dv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite2f(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance2f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicHermiteHandles2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, bool const lNormalize, fvec2 const v0, fvec2 const cv0, fvec2 const v1, fvec2 const cv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles2f(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance2f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicCatmullRom2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, bool const lNormalize, fvec2 const vp, fvec2 const v0, fvec2 const v1, fvec2 const v2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom2f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamBicubicCatmullRom2f(float uTable_out[], float lTable_out[], fvec2 vTable_out[], size const numDivisions, bool const lNormalize, fvec2 const vpp, fvec2 const vp0, fvec2 const vp1, fvec2 const vp2, fvec2 const v0p, fvec2 const v00, fvec2 const v01, fvec2 const v02, fvec2 const v1p, fvec2 const v10, fvec2 const v11, fvec2 const v12, fvec2 const v2p, fvec2 const v20, fvec2 const v21, fvec2 const v22, float const up, float const u0, float const u1, float const u2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec2 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		fvec2 const vp = ijkVecCubicCatmullRom2f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom2f(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom2f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom2f(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom2f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance2f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl fvec2 ijkVecSampleTableInc2f(float const uTable[], fvec2 const vTable[], index i, index di, float const u)
{
	fvec2 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp2f(v0, v1, uReparam);
}

ijk_inl fvec2 ijkVecSampleTableDec2f(float const uTable[], fvec2 const vTable[], index i, index di, float const u)
{
	fvec2 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp2f(v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl float ijkVecLengthSq3f(fvec3 const v_in)
{
	return ijkVecDot3f(v_in, v_in);
}

ijk_inl float ijkVecLength3f(fvec3 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq3f(v_in));
}

ijk_inl float ijkVecLengthSqInv3f(fvec3 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq3f(v_in));
}

ijk_inl float ijkVecLengthSqInvSafe3f(fvec3 const v_in)
{
	float const lengthSq = ijkVecLengthSq3f(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl float ijkVecLengthInv3f(fvec3 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq3f(v_in));
}

ijk_inl float ijkVecLengthInvSafe3f(fvec3 const v_in)
{
	float const lengthSq = ijkVecLengthSq3f(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl fvec3 ijkVecNormalize3f(fvec3 const v_in)
{
	return ijkVecMul3fs(v_in, ijkVecLengthInv3f(v_in));
}

ijk_inl fvec3 ijkVecNormalizeSafe3f(fvec3 const v_in)
{
	return ijkVecMul3fs(v_in, ijkVecLengthInvSafe3f(v_in));
}

ijk_inl fvec3 ijkVecNormalizeGetLength3f(fvec3 const v_in, float* const length_out)
{
	return ijkVecDiv3fs(v_in, (*length_out = ijkVecLength3f(v_in)));
}

ijk_inl fvec3 ijkVecNormalizeSafeGetLength3f(fvec3 const v_in, float* const length_out)
{
	return ijkVecDivSafe3fs(v_in, (*length_out = ijkVecLength3f(v_in)));
}

ijk_inl fvec3 ijkVecNormalizeGetLengthInv3f(fvec3 const v_in, float* const lengthInv_out)
{
	return ijkVecMul3fs(v_in, (*lengthInv_out = ijkVecLengthInv3f(v_in)));
}

ijk_inl fvec3 ijkVecNormalizeSafeGetLengthInv3f(fvec3 const v_in, float* const lengthInv_out)
{
	return ijkVecMul3fs(v_in, (*lengthInv_out = ijkVecLengthInvSafe3f(v_in)));
}

ijk_inl fvec3 ijkVecCrossNormalize3f(fvec3 const v_lh, fvec3 const v_rh)
{
	return ijkVecNormalize3f(ijkVecCross3f(v_lh, v_rh));
}

ijk_inl fvec3 ijkVecCrossNormalizeSafe3f(fvec3 const v_lh, fvec3 const v_rh)
{
	return ijkVecNormalizeSafe3f(ijkVecCross3f(v_lh, v_rh));
}

ijk_inl fvec3 ijkVecCrossNormalizeGetLength3f(fvec3 const v_lh, fvec3 const v_rh, float* const length_out)
{
	return ijkVecNormalizeGetLength3f(ijkVecCross3f(v_lh, v_rh), length_out);
}

ijk_inl fvec3 ijkVecCrossNormalizeSafeGetLength3f(fvec3 const v_lh, fvec3 const v_rh, float* const length_out)
{
	return ijkVecNormalizeSafeGetLength3f(ijkVecCross3f(v_lh, v_rh), length_out);
}

ijk_inl fvec3 ijkVecCrossNormalizeGetLengthInv3f(fvec3 const v_lh, fvec3 const v_rh, float* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv3f(ijkVecCross3f(v_lh, v_rh), lengthInv_out);
}

ijk_inl fvec3 ijkVecCrossNormalizeSafeGetLengthInv3f(fvec3 const v_lh, fvec3 const v_rh, float* const lengthInv_out)
{
	return ijkVecNormalizeSafeGetLengthInv3f(ijkVecCross3f(v_lh, v_rh), lengthInv_out);
}

ijk_inl fvec3 ijkVecLerp3f(fvec3 const v0, fvec3 const v1, float const u)
{
	fvec3 const v_out = {
		ijkInterpLinear_flt(v0.x, v1.x, u),
		ijkInterpLinear_flt(v0.y, v1.y, u),
		ijkInterpLinear_flt(v0.z, v1.z, u),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecLerpInv3f(fvec3 const v0, fvec3 const v1, fvec3 const v_lerp)
{
	fvec3 const v_out = {
		ijkInterpLinearInv_flt(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_flt(v0.y, v1.y, v_lerp.y),
		ijkInterpLinearInv_flt(v0.z, v1.z, v_lerp.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecLerpRevInit3f(fvec3 const v_lerp, fvec3 const v1, float const u)
{
	float const s = ijk_recip_flt(flt_one - u);
	fvec3 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u)* s,
		(v_lerp.z - v1.z * u) * s,
	};
	return v0_out;
}

ijk_inl fvec3 ijkVecLerpRevTerm3f(fvec3 const v0, fvec3 const v_lerp, float const u)
{
	return ijkVecLerp3f(v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl float ijkVecProjRatio3f(fvec3 const v_base, fvec3 const v_in)
{
	return (ijkVecDot3f(v_base, v_in) / ijkVecLengthSq3f(v_base));
}

ijk_inl fvec3 ijkVecProj3f(fvec3 const v_base, fvec3 const v_in)
{
	return ijkVecMul3fs(v_base, ijkVecProjRatio3f(v_base, v_in));
}

ijk_inl fvec3 ijkVecOrtho3f(fvec3 const v_base, fvec3 const v_in)
{
	return ijkVecSub3f(v_in, ijkVecProj3f(v_base, v_in));
}

ijk_inl fvec3 ijkVecOrthoNorm3f(fvec3 const v_base, fvec3 const v_in, fvec3* const v_base_norm_out)
{
	fvec3 const v_base_norm = *v_base_norm_out = ijkVecNormalize3f(v_base);
	return ijkVecNormalize3f(ijkVecSub3f(v_in, ijkVecMul3fs(v_base_norm, ijkVecDot3f(v_base_norm, v_in))));
}

ijk_inl fvec3* ijkVecOrthoList3f(fvec3 vl_out[], fvec3 const v_base, fvec3 const vl_in[], size const n)
{
	fvec3 orthoSum;
	fvec3 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj3f(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd3f(orthoSum, ijkVecProj3f(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub3f(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl fvec3* ijkVecOrthoNormList3f(fvec3 vl_out[], fvec3 const v_base, fvec3 const vl_in[], size const n, fvec3* const v_base_norm_out)
{
	fvec3 orthoSum;
	fvec3 vp_in;
	uindex i, j;
	fvec3 const v_base_norm = *v_base_norm_out = ijkVecNormalize3f(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul3fs(v_base_norm, ijkVecDot3f(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd3f(orthoSum, ijkVecMul3fs(vl_out[j], ijkVecDot3f(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize3f(ijkVecSub3f(vp_in, orthoSum));
	}
	return vl_out;
}

ijk_inl fvec3 ijkVecNlerp3f(fvec3 const v0, fvec3 const v1, float const u)
{
	return ijkVecNormalize3f(ijkVecLerp3f(v0, v1, u));
}

ijk_inl fvec3 ijkVecSlerp3f(fvec3 const v0, fvec3 const v1, float const u)
{
	float const dot = ijkVecDot3f(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd3f(ijkVecMul3fs(v0, s0), ijkVecMul3fs(v1, s1));
	}
	return ijkVecLerp3f(v0, v1, u);
}

ijk_inl fvec3 ijkVecReflectScale3f(fvec3 const v_in, fvec3 const v_nrm)
{
	float const d = flt_two * ijkVecDot3f(v_in, v_nrm), lenSq = ijkVecLengthSq3f(v_nrm);
	fvec3 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
		(v_in.z * lenSq - d * v_nrm.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecUnitReflect3f(fvec3 const v_in, fvec3 const v_nrm)
{
	float const d = flt_two * ijkVecDot3f(v_in, v_nrm);
	fvec3 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
		(v_in.z - d * v_nrm.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecReflect3f(fvec3 const v_in, fvec3 const v_nrm)
{
	float const d = flt_two * ijkVecDot3f(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv3f(v_nrm);
	fvec3 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
		(v_in.z - lenSqInv * v_nrm.z),
	};
	return v_out;
}

ijk_inl float ijkVecDistance3f(fvec3 const v_lh, fvec3 const v_rh)
{
	fvec3 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
		(v_lh.z - v_rh.z),
	};
	return ijkVecLength3f(diff);
}

ijk_inl fvec3 ijkVecResize3f(fvec3 const v_in, float const length)
{
	float const s = length * ijkVecLengthInv3f(v_in);
	return ijkVecMul3fs(v_in, s);
}

ijk_inl fvec3 ijkVecResizeSafe3f(fvec3 const v_in, float const length)
{
	float const s = length * ijkVecLengthInvSafe3f(v_in);
	return ijkVecMul3fs(v_in, s);
}

ijk_inl fvec3 ijkVecCrossResize3f(fvec3 const v_lh, fvec3 const v_rh, float const length)
{
	fvec3 const c = ijkVecCrossNormalize3f(v_lh, v_rh);
	float const s = length * ijkVecLengthInv3f(c);
	return ijkVecMul3fs(c, s);
}

ijk_inl fvec3 ijkVecCrossResizeSafe3f(fvec3 const v_lh, fvec3 const v_rh, float const length)
{
	fvec3 const c = ijkVecCrossNormalize3f(v_lh, v_rh);
	float const s = length * ijkVecLengthInvSafe3f(c);
	return ijkVecMul3fs(c, s);
}

ijk_inl fvec3 ijkVecNearest3f(fvec3 const v0, fvec3 const v1, float const u)
{
	return (u < flt_half ? v0 : v1);
}

ijk_inl fvec3 ijkVecBinearest3f(fvec3 const v00, fvec3 const v01, fvec3 const v10, fvec3 const v11, float const u0, float const u1, float const u)
{
	return (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11);
}

ijk_inl fvec3 ijkVecRemap3f(fvec3 const v0_dst, fvec3 const v1_dst, fvec3 const v0_src, fvec3 const v1_src, fvec3 const v_src)
{
	fvec3 const v_out = {
		ijkInterpRemap_flt(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_flt(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
		ijkInterpRemap_flt(v0_dst.z, v1_dst.z, v0_src.z, v1_src.z, v_src.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecBezier0O3f(fvec3 const v0, float const u)
{
	return v0;
}

ijk_inl fvec3 ijkVecBezier1O3f(fvec3 const v0, fvec3 const v1, float const u)
{
	return ijkVecLerp3f(v0, v1, u);
}

ijk_inl fvec3 ijkVecBezier2O3f(fvec3 const v0, fvec3 const v1, fvec3 const v2, float const u)
{
	fvec3 const u0 = ijkVecBezier1O3f(v0, v1, u), u1 = ijkVecBezier1O3f(v1, v2, u);
	return ijkVecLerp3f(u0, u1, u);
}

ijk_inl fvec3 ijkVecBezier3O3f(fvec3 const v0, fvec3 const v1, fvec3 const v2, fvec3 const v3, float const u)
{
	fvec3 const u0 = ijkVecBezier2O3f(v0, v1, v2, u), u1 = ijkVecBezier2O3f(v1, v2, v3, u);
	return ijkVecLerp3f(u0, u1, u);
}

ijk_inl fvec3 ijkVecBezierNO3f(fvec3 const v[], size const order, float const u)
{
	if (order > 0)
	{
		fvec3 const u0 = ijkVecBezierNO3f(v + 0, order - 1, u), u1 = ijkVecBezierNO3f(v + 1, order - 1, u);
		return ijkVecLerp3f(u0, u1, u);
	}
	return *v;
}

ijk_inl fvec3 ijkVecCubicHermite3f(fvec3 const v0, fvec3 const dv0, fvec3 const v1, fvec3 const dv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	fvec3 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
		(k.x * v0.z + k.y * dv0.z + k.z * v1.z + k.w * dv1.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecCubicHermiteHandles3f(fvec3 const v0, fvec3 const cv0, fvec3 const v1, fvec3 const cv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	fvec3 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
		(k.x * v0.z + k.y * cv0.z + k.z * v1.z + k.w * cv1.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecCubicCatmullRom3f(fvec3 const vp, fvec3 const v0, fvec3 const v1, fvec3 const v2, float const u)
{
	float const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	fvec4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	fvec3 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
		(k.x * vp.z + k.y * v0.z + k.z * v1.z + k.w * v2.z),
	};
	return v_out;
}

ijk_inl fvec3 ijkVecBicubicCatmullRom3f(fvec3 const vpp, fvec3 const vp0, fvec3 const vp1, fvec3 const vp2, fvec3 const v0p, fvec3 const v00, fvec3 const v01, fvec3 const v02, fvec3 const v1p, fvec3 const v10, fvec3 const v11, fvec3 const v12, fvec3 const v2p, fvec3 const v20, fvec3 const v21, fvec3 const v22, float const up, float const u0, float const u1, float const u2, float const u)
{
	fvec3 const vp = ijkVecCubicCatmullRom3f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom3f(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom3f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom3f(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom3f(vp, v0, v1, v2, u);
}

ijk_inl float ijkVecReparamCubicHermite3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, bool const lNormalize, fvec3 const v0, fvec3 const dv0, fvec3 const v1, fvec3 const dv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite3f(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance3f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicHermiteHandles3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, bool const lNormalize, fvec3 const v0, fvec3 const cv0, fvec3 const v1, fvec3 const cv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles3f(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance3f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicCatmullRom3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, bool const lNormalize, fvec3 const vp, fvec3 const v0, fvec3 const v1, fvec3 const v2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom3f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamBicubicCatmullRom3f(float uTable_out[], float lTable_out[], fvec3 vTable_out[], size const numDivisions, bool const lNormalize, fvec3 const vpp, fvec3 const vp0, fvec3 const vp1, fvec3 const vp2, fvec3 const v0p, fvec3 const v00, fvec3 const v01, fvec3 const v02, fvec3 const v1p, fvec3 const v10, fvec3 const v11, fvec3 const v12, fvec3 const v2p, fvec3 const v20, fvec3 const v21, fvec3 const v22, float const up, float const u0, float const u1, float const u2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec3 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		fvec3 const vp = ijkVecCubicCatmullRom3f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom3f(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom3f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom3f(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom3f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance3f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl fvec3 ijkVecSampleTableInc3f(float const uTable[], fvec3 const vTable[], index i, index di, float const u)
{
	fvec3 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp3f(v0, v1, uReparam);
}

ijk_inl fvec3 ijkVecSampleTableDec3f(float const uTable[], fvec3 const vTable[], index i, index di, float const u)
{
	fvec3 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp3f(v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl float ijkVecLengthSq4f(fvec4 const v_in)
{
	return ijkVecDot4f(v_in, v_in);
}

ijk_inl float ijkVecLength4f(fvec4 const v_in)
{
	return ijkSqrt_flt(ijkVecLengthSq4f(v_in));
}

ijk_inl float ijkVecLengthSqInv4f(fvec4 const v_in)
{
	return ijk_recip_flt(ijkVecLengthSq4f(v_in));
}

ijk_inl float ijkVecLengthSqInvSafe4f(fvec4 const v_in)
{
	float const lengthSq = ijkVecLengthSq4f(v_in);
	return ijk_recip_safe_flt(lengthSq);
}

ijk_inl float ijkVecLengthInv4f(fvec4 const v_in)
{
	return ijkSqrtInv_flt(ijkVecLengthSq4f(v_in));
}

ijk_inl float ijkVecLengthInvSafe4f(fvec4 const v_in)
{
	float const lengthSq = ijkVecLengthSq4f(v_in);
	return (lengthSq > flt_zero ? ijkSqrtInv_flt(lengthSq) : flt_zero);
}

ijk_inl fvec4 ijkVecNormalize4f(fvec4 const v_in)
{
	return ijkVecMul4fs(v_in, ijkVecLengthInv4f(v_in));
}

ijk_inl fvec4 ijkVecNormalizeSafe4f(fvec4 const v_in)
{
	return ijkVecMul4fs(v_in, ijkVecLengthInvSafe4f(v_in));
}

ijk_inl fvec4 ijkVecNormalizeGetLength4f(fvec4 const v_in, float* const length_out)
{
	return ijkVecDiv4fs(v_in, (*length_out = ijkVecLength4f(v_in)));
}

ijk_inl fvec4 ijkVecNormalizeSafeGetLength4f(fvec4 const v_in, float* const length_out)
{
	return ijkVecDivSafe4fs(v_in, (*length_out = ijkVecLength4f(v_in)));
}

ijk_inl fvec4 ijkVecNormalizeGetLengthInv4f(fvec4 const v_in, float* const lengthInv_out)
{
	return ijkVecMul4fs(v_in, (*lengthInv_out = ijkVecLengthInv4f(v_in)));
}

ijk_inl fvec4 ijkVecNormalizeSafeGetLengthInv4f(fvec4 const v_in, float* const lengthInv_out)
{
	return ijkVecMul4fs(v_in, (*lengthInv_out = ijkVecLengthInvSafe4f(v_in)));
}

ijk_inl fvec4 ijkVecCrossNormalize4f(fvec4 const v_lh, fvec4 const v_rh)
{
	return ijkVecNormalize4f(ijkVecCross4f(v_lh, v_rh));
}

ijk_inl fvec4 ijkVecCrossNormalizeSafe4f(fvec4 const v_lh, fvec4 const v_rh)
{
	return ijkVecNormalizeSafe4f(ijkVecCross4f(v_lh, v_rh));
}

ijk_inl fvec4 ijkVecCrossNormalizeGetLength4f(fvec4 const v_lh, fvec4 const v_rh, float* const length_out)
{
	return ijkVecNormalizeGetLength4f(ijkVecCross4f(v_lh, v_rh), length_out);
}

ijk_inl fvec4 ijkVecCrossNormalizeSafeGetLength4f(fvec4 const v_lh, fvec4 const v_rh, float* const length_out)
{
	return ijkVecNormalizeSafeGetLength4f(ijkVecCross4f(v_lh, v_rh), length_out);
}

ijk_inl fvec4 ijkVecCrossNormalizeGetLengthInv4f(fvec4 const v_lh, fvec4 const v_rh, float* const lengthInv_out)
{
	return ijkVecNormalizeGetLengthInv4f(ijkVecCross4f(v_lh, v_rh), lengthInv_out);
}

ijk_inl fvec4 ijkVecCrossNormalizeSafeGetLengthInv4f(fvec4 const v_lh, fvec4 const v_rh, float* const lengthInv_out)
{
	return ijkVecNormalizeSafeGetLengthInv4f(ijkVecCross4f(v_lh, v_rh), lengthInv_out);
}

ijk_inl fvec4 ijkVecLerp4f(fvec4 const v0, fvec4 const v1, float const u)
{
	fvec4 const v_out = {
		ijkInterpLinear_flt(v0.x, v1.x, u),
		ijkInterpLinear_flt(v0.y, v1.y, u),
		ijkInterpLinear_flt(v0.z, v1.z, u),
		ijkInterpLinear_flt(v0.w, v1.w, u),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecLerpInv4f(fvec4 const v0, fvec4 const v1, fvec4 const v_lerp)
{
	fvec4 const v_out = {
		ijkInterpLinearInv_flt(v0.x, v1.x, v_lerp.x),
		ijkInterpLinearInv_flt(v0.y, v1.y, v_lerp.y),
		ijkInterpLinearInv_flt(v0.z, v1.z, v_lerp.z),
		ijkInterpLinearInv_flt(v0.w, v1.w, v_lerp.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecLerpRevInit4f(fvec4 const v_lerp, fvec4 const v1, float const u)
{
	float const s = ijk_recip_flt(flt_one - u);
	fvec4 const v0_out = {
		(v_lerp.x - v1.x * u) * s,
		(v_lerp.y - v1.y * u) * s,
		(v_lerp.z - v1.z * u)* s,
		(v_lerp.w - v1.w * u) * s,
	};
	return v0_out;
}

ijk_inl fvec4 ijkVecLerpRevTerm4f(fvec4 const v0, fvec4 const v_lerp, float const u)
{
	return ijkVecLerp4f(v0, v_lerp, ijk_recip_flt(u));
}

ijk_inl float ijkVecProjRatio4f(fvec4 const v_base, fvec4 const v_in)
{
	return (ijkVecDot4f(v_base, v_in) / ijkVecLengthSq4f(v_base));
}

ijk_inl fvec4 ijkVecProj4f(fvec4 const v_base, fvec4 const v_in)
{
	return ijkVecMul4fs(v_base, ijkVecProjRatio4f(v_base, v_in));
}

ijk_inl fvec4 ijkVecOrtho4f(fvec4 const v_base, fvec4 const v_in)
{
	return ijkVecSub4f(v_in, ijkVecProj4f(v_base, v_in));
}

ijk_inl fvec4 ijkVecOrthoNorm4f(fvec4 const v_base, fvec4 const v_in, fvec4* const v_base_norm_out)
{
	fvec4 const v_base_norm = *v_base_norm_out = ijkVecNormalize4f(v_base);
	return ijkVecNormalize4f(ijkVecSub4f(v_in, ijkVecMul4fs(v_base_norm, ijkVecDot4f(v_base_norm, v_in))));
}

ijk_inl fvec4* ijkVecOrthoList4f(fvec4 vl_out[], fvec4 const v_base, fvec4 const vl_in[], size const n)
{
	fvec4 orthoSum;
	fvec4 vp_in;
	uindex i, j;
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecProj4f(v_base, vp_in);
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd4f(orthoSum, ijkVecProj4f(vl_out[j], vp_in));
		vl_out[i] = ijkVecSub4f(vp_in, orthoSum);
	}
	return vl_out;
}

ijk_inl fvec4* ijkVecOrthoNormList4f(fvec4 vl_out[], fvec4 const v_base, fvec4 const vl_in[], size const n, fvec4* const v_base_norm_out)
{
	fvec4 orthoSum;
	fvec4 vp_in;
	uindex i, j;
	fvec4 const v_base_norm = *v_base_norm_out = ijkVecNormalize4f(v_base);
	for (i = 0; i < n; ++i)
	{
		vp_in = vl_in[i];
		orthoSum = ijkVecMul4fs(v_base_norm, ijkVecDot4f(v_base_norm, vp_in));
		for (j = 0; j < i; ++j)
			orthoSum = ijkVecAdd4f(orthoSum, ijkVecMul4fs(vl_out[j], ijkVecDot4f(vl_out[j], vp_in)));
		vl_out[i] = ijkVecNormalize4f(ijkVecSub4f(vp_in, orthoSum));
	}
	return vl_out;
}

ijk_inl fvec4 ijkVecNlerp4f(fvec4 const v0, fvec4 const v1, float const u)
{
	return ijkVecNormalize4f(ijkVecLerp4f(v0, v1, u));
}

ijk_inl fvec4 ijkVecSlerp4f(fvec4 const v0, fvec4 const v1, float const u)
{
	float const dot = ijkVecDot4f(v0, v1);
	if ((dot * dot) < flt_one)
	{
		float const angle = ijkTrigAcos_deg_flt(dot),
			sinInv = ijkTrigCsc_deg_flt(angle),
			s0 = sinInv * ijkTrigSin_deg_flt(angle * (flt_one - u)),
			s1 = sinInv * ijkTrigSin_deg_flt(angle * u);
		return ijkVecAdd4f(ijkVecMul4fs(v0, s0), ijkVecMul4fs(v1, s1));
	}
	return ijkVecLerp4f(v0, v1, u);
}

ijk_inl fvec4 ijkVecReflectScale4f(fvec4 const v_in, fvec4 const v_nrm)
{
	float const d = flt_two * ijkVecDot4f(v_in, v_nrm), lenSq = ijkVecLengthSq4f(v_nrm);
	fvec4 const v_out = {
		(v_in.x * lenSq - d * v_nrm.x),
		(v_in.y * lenSq - d * v_nrm.y),
		(v_in.z * lenSq - d * v_nrm.z),
		(v_in.w * lenSq - d * v_nrm.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecUnitReflect4f(fvec4 const v_in, fvec4 const v_nrm)
{
	float const d = flt_two * ijkVecDot4f(v_in, v_nrm);
	fvec4 const v_out = {
		(v_in.x - d * v_nrm.x),
		(v_in.y - d * v_nrm.y),
		(v_in.z - d * v_nrm.z),
		(v_in.w - d * v_nrm.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecReflect4f(fvec4 const v_in, fvec4 const v_nrm)
{
	float const d = flt_two * ijkVecDot4f(v_in, v_nrm), lenSqInv = d * ijkVecLengthSqInv4f(v_nrm);
	fvec4 const v_out = {
		(v_in.x - lenSqInv * v_nrm.x),
		(v_in.y - lenSqInv * v_nrm.y),
		(v_in.z - lenSqInv * v_nrm.z),
		(v_in.w - lenSqInv * v_nrm.w),
	};
	return v_out;
}

ijk_inl float ijkVecDistance4f(fvec4 const v_lh, fvec4 const v_rh)
{
	fvec4 const diff = {
		(v_lh.x - v_rh.x),
		(v_lh.y - v_rh.y),
		(v_lh.z - v_rh.z),
		(v_lh.w - v_rh.w),
	};
	return ijkVecLength4f(diff);
}

ijk_inl fvec4 ijkVecResize4f(fvec4 const v_in, float const length)
{
	float const s = length * ijkVecLengthInv4f(v_in);
	return ijkVecMul4fs(v_in, s);
}

ijk_inl fvec4 ijkVecResizeSafe4f(fvec4 const v_in, float const length)
{
	float const s = length * ijkVecLengthInvSafe4f(v_in);
	return ijkVecMul4fs(v_in, s);
}

ijk_inl fvec4 ijkVecCrossResize4f(fvec4 const v_lh, fvec4 const v_rh, float const length)
{
	fvec4 const c = ijkVecCrossNormalize4f(v_lh, v_rh);
	float const s = length * ijkVecLengthInv3f(c.xyz);
	return ijkVecMul4fs(c, s);
}

ijk_inl fvec4 ijkVecCrossResizeSafe4f(fvec4 const v_lh, fvec4 const v_rh, float const length)
{
	fvec4 const c = ijkVecCrossNormalize4f(v_lh, v_rh);
	float const s = length * ijkVecLengthInvSafe3f(c.xyz);
	return ijkVecMul4fs(c, s);
}

ijk_inl fvec4 ijkVecNearest4f(fvec4 const v0, fvec4 const v1, float const u)
{
	return (u < flt_half ? v0 : v1);
}

ijk_inl fvec4 ijkVecBinearest4f(fvec4 const v00, fvec4 const v01, fvec4 const v10, fvec4 const v11, float const u0, float const u1, float const u)
{
	return (u < flt_half ? u0 < flt_half ? v00 : v01 : u1 < flt_half ? v10 : v11);
}

ijk_inl fvec4 ijkVecRemap4f(fvec4 const v0_dst, fvec4 const v1_dst, fvec4 const v0_src, fvec4 const v1_src, fvec4 const v_src)
{
	fvec4 const v_out = {
		ijkInterpRemap_flt(v0_dst.x, v1_dst.x, v0_src.x, v1_src.x, v_src.x),
		ijkInterpRemap_flt(v0_dst.y, v1_dst.y, v0_src.y, v1_src.y, v_src.y),
		ijkInterpRemap_flt(v0_dst.z, v1_dst.z, v0_src.z, v1_src.z, v_src.z),
		ijkInterpRemap_flt(v0_dst.w, v1_dst.w, v0_src.w, v1_src.w, v_src.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecBezier0O4f(fvec4 const v0, float const u)
{
	return v0;
}

ijk_inl fvec4 ijkVecBezier1O4f(fvec4 const v0, fvec4 const v1, float const u)
{
	return ijkVecLerp4f(v0, v1, u);
}

ijk_inl fvec4 ijkVecBezier2O4f(fvec4 const v0, fvec4 const v1, fvec4 const v2, float const u)
{
	fvec4 const u0 = ijkVecBezier1O4f(v0, v1, u), u1 = ijkVecBezier1O4f(v1, v2, u);
	return ijkVecLerp4f(u0, u1, u);
}

ijk_inl fvec4 ijkVecBezier3O4f(fvec4 const v0, fvec4 const v1, fvec4 const v2, fvec4 const v3, float const u)
{
	fvec4 const u0 = ijkVecBezier2O4f(v0, v1, v2, u), u1 = ijkVecBezier2O4f(v1, v2, v3, u);
	return ijkVecLerp4f(u0, u1, u);
}

ijk_inl fvec4 ijkVecBezierNO4f(fvec4 const v[], size const order, float const u)
{
	if (order > 0)
	{
		fvec4 const u0 = ijkVecBezierNO4f(v + 0, order - 1, u), u1 = ijkVecBezierNO4f(v + 1, order - 1, u);
		return ijkVecLerp4f(u0, u1, u);
	}
	return *v;
}

ijk_inl fvec4 ijkVecCubicHermite4f(fvec4 const v0, fvec4 const dv0, fvec4 const v1, fvec4 const dv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - flt_three * u2 + flt_two * u3),
		(u - flt_two * u2 + u3),
		(flt_three * u2 - flt_two * u3),
		(u3 - u2),
	};
	fvec4 const v_out = {
		(k.x * v0.x + k.y * dv0.x + k.z * v1.x + k.w * dv1.x),
		(k.x * v0.y + k.y * dv0.y + k.z * v1.y + k.w * dv1.y),
		(k.x * v0.z + k.y * dv0.z + k.z * v1.z + k.w * dv1.z),
		(k.x * v0.w + k.y * dv0.w + k.z * v1.w + k.w * dv1.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecCubicHermiteHandles4f(fvec4 const v0, fvec4 const cv0, fvec4 const v1, fvec4 const cv1, float const u)
{
	float const u2 = u * u, u3 = u * u2;
	fvec4 const k = {
		(flt_one - u - u2 + u3),
		(u - flt_two * u2 + u3),
		(flt_four * u2 - flt_three * u3),
		(u3 - u2),
	};
	fvec4 const v_out = {
		(k.x * v0.x + k.y * cv0.x + k.z * v1.x + k.w * cv1.x),
		(k.x * v0.y + k.y * cv0.y + k.z * v1.y + k.w * cv1.y),
		(k.x * v0.z + k.y * cv0.z + k.z * v1.z + k.w * cv1.z),
		(k.x * v0.w + k.y * cv0.w + k.z * v1.w + k.w * cv1.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecCubicCatmullRom4f(fvec4 const vp, fvec4 const v0, fvec4 const v1, fvec4 const v2, float const u)
{
	float const uh = flt_half * u, u2h = u * uh, u3h = u * u2h;
	fvec4 const k = {
		(flt_two * u2h - uh - u3h),
		(flt_one - flt_five * u2h + flt_three * u3h),
		(uh + flt_four * u2h - flt_three * u3h),
		(u3h - u2h),
	};
	fvec4 const v_out = {
		(k.x * vp.x + k.y * v0.x + k.z * v1.x + k.w * v2.x),
		(k.x * vp.y + k.y * v0.y + k.z * v1.y + k.w * v2.y),
		(k.x * vp.z + k.y * v0.z + k.z * v1.z + k.w * v2.z),
		(k.x * vp.w + k.y * v0.w + k.z * v1.w + k.w * v2.w),
	};
	return v_out;
}

ijk_inl fvec4 ijkVecBicubicCatmullRom4f(fvec4 const vpp, fvec4 const vp0, fvec4 const vp1, fvec4 const vp2, fvec4 const v0p, fvec4 const v00, fvec4 const v01, fvec4 const v02, fvec4 const v1p, fvec4 const v10, fvec4 const v11, fvec4 const v12, fvec4 const v2p, fvec4 const v20, fvec4 const v21, fvec4 const v22, float const up, float const u0, float const u1, float const u2, float const u)
{
	fvec4 const vp = ijkVecCubicCatmullRom4f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom4f(v0p, v00, v01, v02, u0),
		v1 = ijkVecCubicCatmullRom4f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom4f(v2p, v20, v21, v22, u2);
	return ijkVecCubicCatmullRom4f(vp, v0, v1, v2, u);
}

ijk_inl float ijkVecReparamCubicHermite4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, bool const lNormalize, fvec4 const v0, fvec4 const dv0, fvec4 const v1, fvec4 const dv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermite4f(v0, dv0, v1, dv1, u);
			arcLength += ijkVecDistance4f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicHermiteHandles4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, bool const lNormalize, fvec4 const v0, fvec4 const cv0, fvec4 const v1, fvec4 const cv1)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicHermiteHandles4f(v0, cv0, v1, cv1, u);
			arcLength += ijkVecDistance4f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamCubicCatmullRom4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, bool const lNormalize, fvec4 const vp, fvec4 const v0, fvec4 const v1, fvec4 const v2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom4f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl float ijkVecReparamBicubicCatmullRom4f(float uTable_out[], float lTable_out[], fvec4 vTable_out[], size const numDivisions, bool const lNormalize, fvec4 const vpp, fvec4 const vp0, fvec4 const vp1, fvec4 const vp2, fvec4 const v0p, fvec4 const v00, fvec4 const v01, fvec4 const v02, fvec4 const v1p, fvec4 const v10, fvec4 const v11, fvec4 const v12, fvec4 const v2p, fvec4 const v20, fvec4 const v21, fvec4 const v22, float const up, float const u0, float const u1, float const u2)
{
	float u = flt_zero, du, arcLength = flt_zero, arcLengthInv;
	float* lTable = lTable_out;
	uindex i;
	fvec4 v, vc;

	if (uTable_out && lTable_out && vTable_out && numDivisions)
	{
		fvec4 const vp = ijkVecCubicCatmullRom4f(vpp, vp0, vp1, vp2, up), v0 = ijkVecCubicCatmullRom4f(v0p, v00, v01, v02, u0),
			v1 = ijkVecCubicCatmullRom4f(v1p, v10, v11, v12, u1), v2 = ijkVecCubicCatmullRom4f(v2p, v20, v21, v22, u2);

		*uTable_out = u;
		*lTable_out = arcLength;
		*vTable_out = vc = v0;

		for (i = 1, du = ijk_recip_flt((f32)numDivisions); i <= numDivisions; ++i)
		{
			u = (f32)i * du;
			v = ijkVecCubicCatmullRom4f(vp, v0, v1, v2, u);
			arcLength += ijkVecDistance4f(v, vc);
			*(++uTable_out) = u;
			*(++lTable_out) = arcLength;
			*(++vTable_out) = vc = v;
		}

		if (lNormalize)
			for (i = 1, arcLengthInv = ijk_recip_flt(arcLength); i <= numDivisions; ++i)
				*(++lTable) *= arcLengthInv;
	}
	return arcLength;
}

ijk_inl fvec4 ijkVecSampleTableInc4f(float const uTable[], fvec4 const vTable[], index i, index di, float const u)
{
	fvec4 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 < u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp4f(v0, v1, uReparam);
}

ijk_inl fvec4 ijkVecSampleTableDec4f(float const uTable[], fvec4 const vTable[], index i, index di, float const u)
{
	fvec4 v0, v1;
	float uReparam;
	float u0, u1 = *(uTable + (i += (di ? di : (di = 1))));

	while (u1 > u)
		u1 = *(uTable + (i += di));
	v1 = *(vTable + i);
	v0 = *(vTable + (i -= di));
	u0 = *(uTable + i);
	uReparam = ijkInterpLinearInv_flt(u0, u1, u);
	return ijkVecLerp4f(v0, v1, uReparam);
}


//-----------------------------------------------------------------------------

ijk_inl i8 ijkVecPack1fb(f32 const v_in)
{
	// pack signed float into signed byte: 7 bits + sign
	//	2^7-1 = 127
	return (i8)(v_in * 127.0f);
}

ijk_inl f32 ijkVecUnpack1fb(i8 const i_in)
{
	return ((f32)i_in / 127.0f);
}

ijk_inl i16 ijkVecPack1fs(f32 const v_in)
{
	// sign + 15 bits
	return (i16)(v_in * 32767.0f);
}

ijk_inl f32 ijkVecUnpack1fs(i16 const i_in)
{
	return ((f32)i_in / 32767.0f);
}

ijk_inl i16 ijkVecPack2fvs(float2 const v_in)
{
	// scale inputs, mask and shift
	return (i16)(
		((i16)(v_in[0] * 127.0f) & 0xff) |
		((i16)(v_in[1] * 127.0f) & 0xff) << 8);
}

ijk_inl floatv ijkVecUnpack2fvs(float2 v_out, i16 const i_in)
{
	// shift, mask and scale
	v_out[0] = ((f32)(i_in		 & 0xff) / 127.0f);
	v_out[1] = ((f32)(i_in >>  8 & 0xff) / 127.0f);
	return v_out;
}

ijk_inl i32 ijkVecPack2fvl(float2 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 32767.0f) & 0xffff) |
		((i32)(v_in[1] * 32767.0f) & 0xffff) << 16);
}

ijk_inl floatv ijkVecUnpack2fvl(float2 v_out, i32 const i_in)
{
	v_out[0] = ((f32)(i_in		 & 0xffff) / 32767.0f);
	v_out[1] = ((f32)(i_in >> 16 & 0xffff) / 32767.0f);
	return v_out;
}

ijk_inl i32 ijkVecPack3fvl(float3 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 511.0f) & 0x03ff) |
		((i32)(v_in[1] * 511.0f) & 0x03ff) << 10 |
		((i32)(v_in[2] * 511.0f) & 0x03ff) << 20);
}

ijk_inl floatv ijkVecUnpack3fvl(float3 v_out, i32 const i_in)
{
	v_out[0] = ((f32)(i_in		 & 0x03ff) / 511.0f);
	v_out[1] = ((f32)(i_in >> 10 & 0x03ff) / 511.0f);
	v_out[2] = ((f32)(i_in >> 20 & 0x03ff) / 511.0f);
	return v_out;
}

ijk_inl i32 ijkVecPack4fvl(float4 const v_in)
{
	return (i32)(
		((i32)(v_in[0] * 127.0f) & 0xff) |
		((i32)(v_in[1] * 127.0f) & 0xff) <<  8 |
		((i32)(v_in[2] * 127.0f) & 0xff) << 16 |
		((i32)(v_in[3] * 127.0f) & 0xff) << 24);
}

ijk_inl floatv ijkVecUnpack4fvl(float4 v_out, i32 const i_in)
{
	v_out[0] = ((f32)(i_in		 & 0xff) / 127.0f);
	v_out[1] = ((f32)(i_in >>  8 & 0xff) / 127.0f);
	v_out[2] = ((f32)(i_in >> 16 & 0xff) / 127.0f);
	v_out[3] = ((f32)(i_in >> 24 & 0xff) / 127.0f);
	return v_out;
}

ijk_inl i64 ijkVecPack4fvll(float4 const v_in)
{
	return (i64)(
		((i64)(v_in[0] * 32767.0f) & 0xffff) |
		((i64)(v_in[1] * 32767.0f) & 0xffff) << 16 |
		((i64)(v_in[2] * 32767.0f) & 0xffff) << 32 |
		((i64)(v_in[3] * 32767.0f) & 0xffff) << 48);
}

ijk_inl floatv ijkVecUnpack4fvll(float4 v_out, i64 const i_in)
{
	v_out[0] = ((f32)(i_in		 & 0xffff) / 32767.0f);
	v_out[1] = ((f32)(i_in >> 16 & 0xffff) / 32767.0f);
	v_out[2] = ((f32)(i_in >> 32 & 0xffff) / 32767.0f);
	v_out[3] = ((f32)(i_in >> 48 & 0xffff) / 32767.0f);
	return v_out;
}

ijk_inl i32 ijkVecPackUnitXYZ4fvl(float4 const v_in)
{
	// store first three elements and sign of fourth
	return (i32)(
		((i32)(v_in[0] * 511.0f) & 0x03ff) |
		((i32)(v_in[1] * 511.0f) & 0x03ff) << 10 |
		((i32)(v_in[2] * 511.0f) & 0x03ff) << 20 |
		(*(i32*)(v_in + 3) & 0x80000000));
}

ijk_inl floatv ijkVecUnpackUnitXYZ4fvl(float4 v_out, i32 const i_in)
{
	// extract first three elements, calculate fourth using magnitude and sign
	v_out[0] = ((f32)(i_in		 & 0x03ff) / 511.0f);
	v_out[1] = ((f32)(i_in >> 10 & 0x03ff) / 511.0f);
	v_out[2] = ((f32)(i_in >> 20 & 0x03ff) / 511.0f);
	v_out[3] = ((f32)(i_in >> 31) * ijkSqrt_flt(flt_one - ijkVecLengthSq3fv(v_out)));
	return v_out;
}

ijk_inl i32 ijkVecPackUnit3of4fvl(float4 const v_in, ui32 const excl)
{
	// entire vector scales by sign of excluded element
	// store all others and index of excluded
	ui32 const x = (excl % 4);
	f32 const f = (*(i32*)(v_in + x) & 0x80000000) ? -511.0f : +511.0f;
	return (i32)(
		((i32)(v_in[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl floatv ijkVecUnpackUnit3of4fvl(float4 v_out, i32 const i_in, ui32* const excl_out)
{
	// get index of excluded, extract others, calculate using magnitude
	ui32 const x = *excl_out = (i_in >> 30);
	f32 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f32)(i_in		& 0x03ff) / 511.0f);
	v_out[(x + 2) % 4] = v2 = ((f32)(i_in >> 10 & 0x03ff) / 511.0f);
	v_out[(x + 3) % 4] = v3 = ((f32)(i_in >> 20	& 0x03ff) / 511.0f);
	v_out[x] = ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i32 ijkVecPackQuant4fvl(float4 const v_in)
{
	// calculate index of component with greatest magnitude
	float4 const sq = { (v_in[0] * v_in[0]), (v_in[1] * v_in[1]), (v_in[2] * v_in[2]), (v_in[3] * v_in[3]) };
	ui32 const xy = (sq[1] >= sq[0]) + 0, zw = (sq[3] >= sq[2]) + 2, x = (sq[xy] >= sq[zw] ? xy : zw);
	f32 const f = (*(i32*)(v_in + x) & 0x80000000) ? -722.6631f : +722.6631f; // ~= 511 * sqrt(2)
	return (i32)(
		((i32)(v_in[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl floatv ijkVecUnpackQuant4fvl(float4 v_out, i32 const i_in)
{
	// get index of excluded, extract others, calculate using magnitude
	ui32 const x = (i_in >> 30);
	f32 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f32)(i_in		& 0x03ff) / 722.6631f);
	v_out[(x + 2) % 4] = v2 = ((f32)(i_in >> 10 & 0x03ff) / 722.6631f);
	v_out[(x + 3) % 4] = v3 = ((f32)(i_in >> 20	& 0x03ff) / 722.6631f);
	v_out[x] = ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i64 ijkVecPackUnitXYZ4fvll(float4 const v_in)
{
	// store first three elements and sign of fourth
	return (i64)(
		((i64)(v_in[0] * 1048575.0f) & 0x001fffff) << 00 |
		((i64)(v_in[1] * 1048575.0f) & 0x001fffff) << 21 |
		((i64)(v_in[2] * 1048575.0f) & 0x001fffff) << 42 |
		((i64)(*(i32*)(v_in + 3) & 0x80000000)) << 31);
}

ijk_inl floatv ijkVecUnpackUnitXYZ4fvll(float4 v_out, i64 const i_in)
{
	v_out[0] = ((f32)(i_in		 & 0x001fffff) / 1048575.0f);
	v_out[1] = ((f32)(i_in >> 21 & 0x001fffff) / 1048575.0f);
	v_out[2] = ((f32)(i_in >> 42 & 0x001fffff) / 1048575.0f);
	v_out[3] = ((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - ijkVecLengthSq3fv(v_out)));
	return v_out;
}

ijk_inl i64 ijkVecPackUnit3of4fvll(float4 const v_in, ui64 const excl)
{
	// this time store index and sign
	ui64 const x = (excl % 4);
	return (i64)(
		((i64)(v_in[(x + 1) % 4] * 524287.0f) & 0x000fffff) |
		((i64)(v_in[(x + 2) % 4] * 524287.0f) & 0x000fffff) << 10 |
		((i64)(v_in[(x + 3) % 4] * 524287.0f) & 0x000fffff) << 20 |
		((i64)(*(i32*)(v_in + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl floatv ijkVecUnpackUnit3of4fvll(float4 v_out, i64 const i_in, ui64* const excl_out)
{
	// get missing index without sign
	ui64 const x = (i_in >> 61 & 3);
	f32 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f32)(i_in		& 0x000fffff) / 524287.0f);
	v_out[(x + 2) % 4] = v2 = ((f32)(i_in >> 20 & 0x000fffff) / 524287.0f);
	v_out[(x + 3) % 4] = v3 = ((f32)(i_in >> 40 & 0x000fffff) / 524287.0f);
	v_out[x] = ((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}

ijk_inl i64 ijkVecPackQuant4fvll(float4 const v_in)
{
	float4 const sq = { (v_in[0] * v_in[0]), (v_in[1] * v_in[1]), (v_in[2] * v_in[2]), (v_in[3] * v_in[3]) };
	ui64 const xy = (sq[1] >= sq[0]) + 0, zw = (sq[3] >= sq[2]) + 2, x = (sq[xy] >= sq[zw] ? xy : zw);
	return (i64)(
		((i64)(v_in[(x + 1) % 4] * 23169.06079f) & 0x7fff) << 16 | // ~= 16383 * sqrt(2); << 16
		((i64)(v_in[(x + 2) % 4] * 23169.06079f) & 0x7fff) << 31 |	// << 15 << 16
		((i64)(v_in[(x + 3) % 4] * 23169.06079f) & 0x7fff) << 46 |	// << 30 << 16
		((i64)(*(i32*)(v_in + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl floatv ijkVecUnpackQuant4fvll(float4 v_out, i64 const i_in)
{
	ui64 const x = (i_in >> 61 & 3);
	f32 v1, v2, v3;
	v_out[(x + 1) % 4] = v1 = ((f32)(i_in >> 16 & 0x7fff) / 23169.06079f);
	v_out[(x + 2) % 4] = v2 = ((f32)(i_in >> 31 & 0x7fff) / 23169.06079f);
	v_out[(x + 3) % 4] = v3 = ((f32)(i_in >> 46 & 0x7fff) / 23169.06079f);
	v_out[x] = ((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}


//-----------------------------------------------------------------------------

ijk_inl i16 ijkVecPack2fs(fvec2 const v_in)
{
	return (i16)(
		((i16)(v_in.x * 127.0f) & 0xff) |
		((i16)(v_in.y * 127.0f) & 0xff) << 8);
}

ijk_inl fvec2 ijkVecUnpack2fs(i16 const i_in)
{
	fvec2 const v_out = {
		((f32)(i_in		 & 0xff) / 127.0f),
		((f32)(i_in >> 8 & 0xff) / 127.0f),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack2fl(fvec2 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 32767.0f) & 0xffff) |
		((i32)(v_in.y * 32767.0f) & 0xffff) << 16);
}

ijk_inl fvec2 ijkVecUnpack2fl(i32 const i_in)
{
	fvec2 const v_out = {
		((f32)(i_in		  & 0xffff) / 32767.0f),
		((f32)(i_in >> 16 & 0xffff) / 32767.0f),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack3fl(fvec3 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 511.0f) & 0x03ff) |
		((i32)(v_in.y * 511.0f) & 0x03ff) << 10 |
		((i32)(v_in.z * 511.0f) & 0x03ff) << 20);
}

ijk_inl fvec3 ijkVecUnpack3fl(i32 const i_in)
{
	fvec3 const v_out = {
		((f32)(i_in		  & 0x03ff) / 511.0f),
		((f32)(i_in >> 10 & 0x03ff) / 511.0f),
		((f32)(i_in >> 20 & 0x03ff) / 511.0f),
	};
	return v_out;
}

ijk_inl i32 ijkVecPack4fl(fvec4 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 127.0f) & 0xff) |
		((i32)(v_in.y * 127.0f) & 0xff) <<  8 |
		((i32)(v_in.z * 127.0f) & 0xff) << 16 |
		((i32)(v_in.w * 127.0f) & 0xff) << 24);
}

ijk_inl fvec4 ijkVecUnpack4fl(i32 const i_in)
{
	fvec4 const v_out = {
		((f32)(i_in		  & 0xff) / 127.0f),
		((f32)(i_in >>  8 & 0xff) / 127.0f),
		((f32)(i_in >> 16 & 0xff) / 127.0f),
		((f32)(i_in >> 24 & 0xff) / 127.0f),
	};
	return v_out;
}

ijk_inl i64 ijkVecPack4fll(fvec4 const v_in)
{
	return (i64)(
		((i64)(v_in.x * 32767.0f) & 0xffff) |
		((i64)(v_in.y * 32767.0f) & 0xffff) << 16 |
		((i64)(v_in.z * 32767.0f) & 0xffff) << 32 |
		((i64)(v_in.w * 32767.0f) & 0xffff) << 48);
}

ijk_inl fvec4 ijkVecUnpack4fll(i64 const i_in)
{
	fvec4 const v_out = {
		((f32)(i_in		  & 0xffff) / 32767.0f),
		((f32)(i_in >> 16 & 0xffff) / 32767.0f),
		((f32)(i_in >> 32 & 0xffff) / 32767.0f),
		((f32)(i_in >> 48 & 0xffff) / 32767.0f),
	};
	return v_out;
}

ijk_inl i32 ijkVecPackUnitXYZ4fl(fvec4 const v_in)
{
	return (i32)(
		((i32)(v_in.x * 511.0f) & 0x03ff) |
		((i32)(v_in.y * 511.0f) & 0x03ff) << 10 |
		((i32)(v_in.z * 511.0f) & 0x03ff) << 20 |
		(*(i32*)(v_in.v + 3) & 0x80000000));
}

ijk_inl fvec4 ijkVecUnpackUnitXYZ4fl(i32 const i_in)
{
	f32 x, y, z;
	fvec4 const v_out = {
		(x = (f32)(i_in		  & 0x03ff) / 511.0f),
		(y = (f32)(i_in >> 10 & 0x03ff) / 511.0f),
		(z = (f32)(i_in >> 20 & 0x03ff) / 511.0f),
		((f32)(i_in >> 31) * ijkSqrt_flt(flt_one - x * x - y * y - z * z)),
	};
	return v_out;
}

ijk_inl i32 ijkVecPackUnit3of4fl(fvec4 const v_in, ui32 const excl)
{
	ui32 const x = (excl % 4);
	f32 const f = (*(i32*)(v_in.v + x) & 0x80000000) ? -511.0f : +511.0f;
	return (i32)(
		((i32)(v_in.v[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in.v[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in.v[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl fvec4 ijkVecUnpackUnit3of4fl(i32 const i_in, ui32* const excl_out)
{
	ui32 const x = *excl_out = (i_in >> 30);
	f32 v1, v2, v3;
	fvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f32)(i_in			& 0x03ff) / 511.0f);
	v_out.v[(x + 2) % 4] = v2 = ((f32)(i_in >> 10	& 0x03ff) / 511.0f);
	v_out.v[(x + 3) % 4] = v3 = ((f32)(i_in >> 20	& 0x03ff) / 511.0f);
	v_out.v[x] = ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i32 ijkVecPackQuant4fl(fvec4 const v_in)
{
	fvec4 const sq = { (v_in.x * v_in.x), (v_in.y * v_in.y), (v_in.z * v_in.z), (v_in.w * v_in.w) };
	ui32 const xy = (sq.y >= sq.x) + 0, zw = (sq.w >= sq.z) + 2, x = (sq.v[xy] >= sq.v[zw] ? xy : zw);
	f32 const f = (*(i32*)(v_in.v + x) & 0x80000000) ? -722.6631f : +722.6631f; // ~= 511 * sqrt(2)
	return (i32)(
		((i32)(v_in.v[(x + 1) % 4] * f) & 0x03ff) |
		((i32)(v_in.v[(x + 2) % 4] * f) & 0x03ff) << 10 |
		((i32)(v_in.v[(x + 3) % 4] * f) & 0x03ff) << 20 |
		x << 30);
}

ijk_inl fvec4 ijkVecUnpackQuant4fl(i32 const i_in)
{
	ui32 const x = (i_in >> 30);
	f32 v1, v2, v3;
	fvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f32)(i_in		& 0x03ff) / 722.6631f);
	v_out.v[(x + 2) % 4] = v2 = ((f32)(i_in >> 10	& 0x03ff) / 722.6631f);
	v_out.v[(x + 3) % 4] = v3 = ((f32)(i_in >> 20	& 0x03ff) / 722.6631f);
	v_out.v[x] = ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3);
	return v_out;
}

ijk_inl i64 ijkVecPackUnitXYZ4fll(fvec4 const v_in)
{
	return (i64)(
		((i64)(v_in.x * 1048575.0f) & 0x001fffff) << 00 |
		((i64)(v_in.y * 1048575.0f) & 0x001fffff) << 21 |
		((i64)(v_in.z * 1048575.0f) & 0x001fffff) << 42 |
		((i64)(*(i32*)(v_in.v + 3) & 0x80000000)) << 31);
}

ijk_inl fvec4 ijkVecUnpackUnitXYZ4fll(i64 const i_in)
{
	f32 x, y, z;
	fvec4 const v_out = {
		(x = (f32)(i_in & 0x001fffff) / 1048575.0f),
		(y = (f32)(i_in >> 21 & 0x001fffff) / 1048575.0f),
		(z = (f32)(i_in >> 42 & 0x001fffff) / 1048575.0f),
		((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - x * x - y * y - z * z)),
	};
	return v_out;
}

ijk_inl i64 ijkVecPackUnit3of4fll(fvec4 const v_in, ui64 const excl)
{
	ui64 const x = (excl % 4);
	return (i64)(
		((i64)(v_in.v[(x + 1) % 4] * 524287.0f) & 0x000fffff) |
		((i64)(v_in.v[(x + 2) % 4] * 524287.0f) & 0x000fffff) << 10 |
		((i64)(v_in.v[(x + 3) % 4] * 524287.0f) & 0x000fffff) << 20 |
		((i64)(*(i32*)(v_in.v + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl fvec4 ijkVecUnpackUnit3of4fll(i64 const i_in, ui64* const excl_out)
{
	ui64 const x = (i_in >> 61 & 3);
	f32 v1, v2, v3;
	fvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f32)(i_in & 0x000fffff) / 524287.0f);
	v_out.v[(x + 2) % 4] = v2 = ((f32)(i_in >> 20 & 0x000fffff) / 524287.0f);
	v_out.v[(x + 3) % 4] = v3 = ((f32)(i_in >> 40 & 0x000fffff) / 524287.0f);
	v_out.v[x] = ((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}

ijk_inl i64 ijkVecPackQuant4fll(fvec4 const v_in)
{
	fvec4 const sq = { (v_in.x * v_in.x), (v_in.y * v_in.y), (v_in.z * v_in.z), (v_in.w * v_in.w) };
	ui64 const xy = (sq.y >= sq.x) + 0, zw = (sq.w >= sq.z) + 2, x = (sq.v[xy] >= sq.v[zw] ? xy : zw);
	return (i64)(
		((i64)(v_in.v[(x + 1) % 4] * 23169.06079f) & 0x7fff) << 16 | // ~= 16383 * sqrt(2); << 16
		((i64)(v_in.v[(x + 2) % 4] * 23169.06079f) & 0x7fff) << 31 |	// << 15 << 16
		((i64)(v_in.v[(x + 3) % 4] * 23169.06079f) & 0x7fff) << 46 |	// << 30 << 16
		((i64)(*(i32*)(v_in.v + x) & 0x80000000)) << 31 |
		x << 61);
}

ijk_inl fvec4 ijkVecUnpackQuant4fll(i64 const i_in)
{
	ui64 const x = (i_in >> 61 & 3);
	f32 v1, v2, v3;
	fvec4 v_out;
	v_out.v[(x + 1) % 4] = v1 = ((f32)(i_in >> 16 & 0x7fff) / 23169.06079f);
	v_out.v[(x + 2) % 4] = v2 = ((f32)(i_in >> 31 & 0x7fff) / 23169.06079f);
	v_out.v[(x + 3) % 4] = v3 = ((f32)(i_in >> 46 & 0x7fff) / 23169.06079f);
	v_out.v[x] = ((f32)(i_in >> 63) * ijkSqrt_flt(flt_one - v1 * v1 - v2 * v2 - v3 * v3));
	return v_out;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_FLOAT_INL_
#endif	// _IJK_VECTOR_FLOAT_H_