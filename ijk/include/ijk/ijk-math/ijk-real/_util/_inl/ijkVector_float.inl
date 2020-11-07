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
	v_out[0] = (v_lh[1] * v_rh[2] - v_lh[2] * v_rh[1]);
	v_out[1] = (v_lh[2] * v_rh[0] - v_lh[0] * v_rh[2]);
	v_out[2] = (v_lh[0] * v_rh[1] - v_lh[1] * v_rh[0]);
	return v_out;
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

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

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
	floatkv vp_in, vp_itr;
	uindex i, j;
	ijkVecNormalize2fv(v_base_norm_out, v_base);
	for (i = 0; i < n; ++i)
	{
		vp_out = vl_out[i];
		vp_in = vl_in[i];
		ijkVecMul2fvs(ortho, v_base_norm_out, ijkVecDot2fv(v_base_norm_out, vp_in));
		for (j = 0; j < i; ++j)
		{
			vp_itr = vl_out[j];
			ijkVecAdd2fv(orthoSum, orthoSum, ijkVecMul2fvs(ortho, vp_itr, ijkVecDot2fv(vp_itr, vp_in)));
		}
		ijkVecSub2fv(vp_out, vp_in, orthoSum);
		ijkVecNormalize2fv(vp_out, vp_out);
	}
	return vl_out;
}


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTOR_FLOAT_INL_
#endif	// _IJK_VECTOR_FLOAT_H_